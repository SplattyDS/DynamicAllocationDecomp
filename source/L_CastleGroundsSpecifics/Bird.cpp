#include "Bird.h"

namespace
{
	struct State
	{
		using FuncPtr = void(Bird::*)();
		
		FuncPtr main;
	};
	
	const State states[]
	{
		State{ &Bird::State0_Main }, // makes the leader spawn the other birds
		State{ &Bird::State1_Main }, // wait for the player to come close
		State{ &Bird::State2_Main }, // the leader waits for the player to come close, then spawns other birds (unused?)
		State{ &Bird::State3_Main }  // fly to the destination
	};
	
	constexpr Fix12i INITIAL_SPEED_MULTIPLIER = 0x28000_f;
}

SharedFilePtr Bird::modelFile;	// 0x02113c20
SharedFilePtr Bird::animFile;	// 0x02113c28

SpawnInfo Bird::spawnData = // 0x02113934
{
	[]() -> ActorBase* { return new Bird; }, // 0x02111a30
	0x0157,
	0x0157,
	0x00010002,
	0x00000000_f,
	0x00028000_f,
	0x01000000_f,
	0x00320000_f
};

// 0x0211197c
int Bird::InitResources()
{
	Model::LoadFile(modelFile);
	modelAnim.SetFile(modelFile.filePtr, 1, 1);
	
	Animation::LoadFile(animFile);
	modelAnim.SetAnim(animFile.filePtr, 0, 0x1000_f, 0);
	
	shadow.InitCylinder();
	
	pos.y += 0xa000_f;
	vertAccel = 0;
	termVel = -0x32000_f;
	
	isLeader = true;
	leaderID = uniqueID;
	destination = pos;
	state = 0;
	
	return 1;
}

// 0x0211183c
int Bird::CleanupResources()
{
	modelFile.Release();
	animFile.Release();
	return 1;
}

// 0x02111898
int Bird::Behavior()
{
	(this->*states[state].main)();
	
	ang.y = motionAng.y;
	
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationZ(ang.z);
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
	
	DropShadowRadHeight(shadow, modelAnim.mat4x3, 0x1e000_f, 0x7d0000_f, 0xf);
	
	modelAnim.Advance();
	
	return 1;
}

// 0x02111870
int Bird::Render()
{
	modelAnim.Render();
	return 1;
}

// 0x0211186c
void Bird::OnPendingDestroy()
{
	return;
}

// 0x021116ec
void Bird::State0_Main()
{
	if (isLeader)
	{
		if (1 < param1 & 0xf)
		{
			Vector3_16 birdAng = motionAng;
			int numBirdsToSpawn = (param1 & 0xf) - 1;
			int numBirdsSpawned = 0;
			
			if (0 < numBirdsToSpawn)
			{
				do
				{
					Vector3 birdPos;
					birdPos.x = pos.x + (RandomIntInternal(&RNG_STATE) % 400 - 0xa0);
					birdPos.y = pos.y;
					birdPos.z = pos.z + (RandomIntInternal(&RNG_STATE) % 400 - 0xa0);
					
					birdAng.y += RandomIntInternal(&RNG_STATE);
					
					Bird* spawnedBird = (Bird*)Actor::Spawn(0x157, 0, birdPos, &birdAng, areaID, -1);
					if (spawnedBird != nullptr)
						spawnedBird->SetLeader(uniqueID);
					
					numBirdsSpawned++;
				} while (numBirdsSpawned < numBirdsToSpawn);
			}
		}
		
		destination.x = -0x014000_f;
		destination.z = -0xf96000_f;
	}
	
	state = 1;
}

// 0x021115d8
void Bird::State1_Main()
{
	if (!isLeader)
	{
		Bird* leaderBird = (Bird*)Actor::FindWithID(leaderID);
		if (leaderBird == nullptr)
		{
			Destroy();
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
			if (0x7d0000_f < Vec3_HorzLen(pos - player->pos))
				return;
		}
		Sound::Play(3, 0x6a, camSpacePos);
	}
	
	unsigned random = RandomIntInternal(&RNG_STATE);
	motionAng.x = 5000 - ((short)random + (short)((uint64_t)random * 0x10624dd3 >> 0x28) * -4000);
	
	speedMult = INITIAL_SPEED_MULTIPLIER;
	state = 3;
	flags &= 0xfffeffff;
}

// 0x0211145c
void Bird::State2_Main()
{
	if (isLeader)
	{
		Player* player = ClosestPlayer();
		if (player == nullptr)
			return;
		
		Vector3 playerDist = pos - player->pos;
		if (0x7d0000_f < playerDist.HorzLen())
			return;
		
		if (1 < (param1 & 0xf))
		{
			int numBirdsToSpawn = (param1 & 0xf) - 1;
			int numBirdsSpawned = 0;
			
			if (0 < numBirdsToSpawn)
			{
				do
				{
					Bird* spawnedBrd = (Bird*)Actor::Spawn(0x157, 0x10, pos, nullptr, areaID,-1);
					if (spawnedBrd != nullptr)
						spawnedBrd->SetLeader(uniqueID);
					
					numBirdsSpawned++;
				} while (numBirdsSpawned < numBirdsToSpawn);
			}
		}
		
		destination.x = -0x014000_f;
		destination.z = -0xf96000_f;
		Sound::Play(3, 0x6a, camSpacePos);
	}
	
	unsigned random = RandomIntInternal(&RNG_STATE);
	motionAng.x = 5000 - ((short)random + (short)(random / 4000) * -4000);
	motionAng.y = RandomIntInternal(&RNG_STATE);
	
	speedMult = INITIAL_SPEED_MULTIPLIER;
	state = 3;
	flags &= 0xfffeffff;
}

// 0x02111234
void Bird::State3_Main()
{
	UpdatePos(nullptr);
	
	Bird* leaderBird = (Bird*)Actor::FindWithID(leaderID);
	if (leaderBird != nullptr && pos.y < 0xbb8001_f)
	{
		if (!isLeader)
		{
			// follow the leader
			Vector3 difference = leaderBird->pos - pos;
			
			targetAng.x = cstd::atan2(difference.HorzLen(), -difference.y);
			targetAng.y = cstd::atan2(difference.z, difference.x);
			
			speedMult = (LenVec3(difference) / 0x19) + 0x14000_f;
		}
		else
		{
			Vector3 difference = destination - pos;
			
			targetAng.x = cstd::atan2(difference.HorzLen(), -0x02710000_f + pos.y);
			targetAng.y = cstd::atan2(difference.z, difference.x);
		}
		
		ApproachLinear(motionAng.x, targetAng.x, 0x8c);
		ApproachLinear(motionAng.y, targetAng.y, 800);
		
		short newTargetAngZ = (short)((((int)motionAng.y - (int)targetAng.y) * 0x10000) >> 0x10);
		if (newTargetAngZ < -0x3000)
			newTargetAngZ = -0x3000;
		else if (0x3000 < newTargetAngZ)
			newTargetAngZ = 0x3000;
		targetAng.z = newTargetAngZ;
		
		ApproachLinear(ang.z, targetAng.z, 600);
		
		horzSpeed = speedMult * Sin(motionAng.x + 1);
		speed.y = speedMult * Sin(motionAng.x);
		
		return;
	}
	
	Destroy();
}

// 0x02111224
void Bird::SetLeader(unsigned newLeaderID)
{
	isLeader = false;
	leaderID = newLeaderID;
}