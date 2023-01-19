#include "SM64DS_2.h"
#include "Actors/Bird.h"

namespace
{
	struct State
	{
		using FuncPtr = void(Bird::*)();
		
		FuncPtr main;
	};
	
	constexpr State states[]
	{
		{ &Bird::State0_Main }, // makes the leader spawn the other birds
		{ &Bird::State1_Main }, // wait for the player to come close
		{ &Bird::State2_Main }, // the leader waits for the player to come close, then spawns other birds (unused?)
		{ &Bird::State3_Main }, // fly to the destination
	};
	
	constexpr Fix12i INITIAL_SPEED_MULTIPLIER = 40._f;
}

SpawnInfo Bird::spawnData =
{
	[]() -> ActorBase* { return new Bird; },
	0x0157,
	0x0157,
	Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UNK_16,
	0._f,
	40._f,
	4096._f,
	800._f,
};

SharedFilePtr Bird::modelFile;
SharedFilePtr Bird::animFile;

s32 Bird::InitResources()
{
	Model::LoadFile(modelFile);
	modelAnim.SetFile(modelFile.BMD(), 1, 1);
	
	Animation::LoadFile(animFile);
	modelAnim.SetAnim(animFile.BCA(), 0, 1._f, 0);
	
	shadow.InitCylinder();
	
	pos.y += 10._f;
	vertAccel = 0;
	termVel = -50._f;
	
	isLeader = true;
	leaderID = uniqueID;
	destination = pos;
	state = 0;
	
	return 1;
}

s32 Bird::CleanupResources()
{
	modelFile.Release();
	animFile.Release();
	return 1;
}

s32 Bird::Behavior()
{
	(this->*states[state].main)();
	
	ang.y = motionAng.y;
	
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationZ(ang.z);
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
	
	DropShadowRadHeight(shadow, modelAnim.mat4x3, 30._f, 2000._f, 0xf);
	
	modelAnim.Advance();
	
	return 1;
}

s32 Bird::Render()
{
	modelAnim.Render();
	return 1;
}

void Bird::OnPendingDestroy()
{
	return;
}

void Bird::SetLeader(u32 newLeaderID)
{
	isLeader = false;
	leaderID = newLeaderID;
}

void Bird::State0_Main()
{
	if (isLeader)
	{
		if (param1 & 0xf > 1)
		{
			Vector3_16 birdAng = motionAng;
			s32 numBirdsToSpawn = (param1 & 0xf) - 1;
			s32 numBirdsSpawned = 0;
			
			if (0 < numBirdsToSpawn)
			{
				do
				{
					Vector3 birdPos;
					birdPos.x = pos.x + (RandomInt() % 400 - 160);
					birdPos.y = pos.y;
					birdPos.z = pos.z + (RandomInt() % 400 - 160);
					
					birdAng.y += RandomInt();
					
					Bird* spawnedBird = (Bird*)Actor::Spawn(BIRD_ACTOR_ID, 0x0000, birdPos, &birdAng, areaID, -1);
					if (spawnedBird != nullptr)
						spawnedBird->SetLeader(uniqueID);
					
					numBirdsSpawned++;
				} while (numBirdsSpawned < numBirdsToSpawn);
			}
		}
		
		destination.x = -20._f;
		destination.z = -3990._f;
	}
	
	state = 1;
}

void Bird::State1_Main()
{
	if (!isLeader)
	{
		Bird* leaderBird = (Bird*)Actor::FindWithID(leaderID);
		if (leaderBird == nullptr)
		{
			MarkForDestruction();
			return;
		}
		if (leaderBird->state != 3)
			return;
	}
	else
	{
		Player* player = ClosestPlayer();
		if (player != nullptr)
		{
			// bird not in range
			if (Vec3_HorzLen(pos - player->pos) > 2000._f)
				return;
		}
		Sound::Play("NCS_SE_SCT_BIRD_FLY"sfx, camSpacePos);
	}
	
	u32 random = RandomInt();
	motionAng.x = 5000 - ((s16)random + (s16)((u64)random * 0x10624dd3 >> 40) * -4000);
	
	speedMult = INITIAL_SPEED_MULTIPLIER;
	state = 3;
	flags &= ~Actor::UNK_16;
}

void Bird::State2_Main()
{
	if (isLeader)
	{
		Player* player = ClosestPlayer();
		if (player == nullptr)
			return;
		
		Vector3 playerDist = pos - player->pos;
		if (playerDist.HorzLen() > 2000._f)
			return;
		
		if (1 < (param1 & 0xf))
		{
			s32 numBirdsToSpawn = (param1 & 0xf) - 1;
			s32 numBirdsSpawned = 0;
			
			if (0 < numBirdsToSpawn)
			{
				do
				{
					Bird* spawnedBrd = (Bird*)Actor::Spawn(BIRD_ACTOR_ID, 0x0010, pos, nullptr, areaID,-1);
					if (spawnedBrd != nullptr)
						spawnedBrd->SetLeader(uniqueID);
					
					numBirdsSpawned++;
				} while (numBirdsSpawned < numBirdsToSpawn);
			}
		}
		
		destination.x = -20._f;
		destination.z = -3990._f;
		Sound::Play("NCS_SE_SCT_BIRD_FLY"sfx, camSpacePos);
	}
	
	u32 random = RandomInt();
	motionAng.x = 5000 - ((s16)random + (s16)(random / 4000) * -4000);
	motionAng.y = RandomInt();
	
	speedMult = INITIAL_SPEED_MULTIPLIER;
	state = 3;
	flags &= ~Actor::UNK_16;
}

void Bird::State3_Main()
{
	UpdatePos(nullptr);
	
	Bird* leaderBird = (Bird*)Actor::FindWithID(leaderID);
	if (leaderBird != nullptr && pos.y <= 3000._f)
	{
		if (!isLeader)
		{
			// follow the leader
			Vector3 difference = leaderBird->pos - pos;
			
			targetAng.x = cstd::atan2(difference.HorzLen(), -difference.y);
			targetAng.y = cstd::atan2(difference.z, difference.x);
			
			speedMult = (LenVec3(difference) / 25) + 20._f;
		}
		else
		{
			Vector3 difference = destination - pos;
			
			targetAng.x = cstd::atan2(difference.HorzLen(), pos.y - 10000._f);
			targetAng.y = cstd::atan2(difference.z, difference.x);
		}
		
		ApproachLinear(motionAng.x, targetAng.x, 0.769_deg);
		ApproachLinear(motionAng.y, targetAng.y, 4.3945_deg);
		
		s16 newTargetAngZ = (s16)((((s32)motionAng.y - (s32)targetAng.y) * 0x10000) >> 16);
		
		if (newTargetAngZ < -67.5_deg)
			newTargetAngZ = -67.5_deg;
		else if (newTargetAngZ > 67.5_deg)
			newTargetAngZ = 67.5_deg;
		
		targetAng.z = newTargetAngZ;
		
		ApproachLinear(ang.z, targetAng.z, 3.2959_deg);
		
		horzSpeed = speedMult * Sin(motionAng.x + 1);
		speed.y = speedMult * Sin(motionAng.x);
		
		return;
	}
	
	MarkForDestruction();
}

Bird::Bird() {}
Bird::~Bird() {}