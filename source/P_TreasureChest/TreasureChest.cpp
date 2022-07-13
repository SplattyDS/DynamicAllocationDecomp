#include "TreasureChest.h"

namespace
{
	struct State
	{
		using FuncPtr = void(TreasureChest::*)();
		
		FuncPtr init;
		FuncPtr main;
	};
	
	const State states[]
	{
		State{ &TreasureChest::State0_Init, &TreasureChest::State0_Main }, // closed
		State{ &TreasureChest::State1_Init, &TreasureChest::State1_Main }, // opening
		State{ &TreasureChest::State2_Init, &TreasureChest::State2_Main }, // opened
	};
}

SharedFilePtr TreasureChest::modelFile;
SharedFilePtr TreasureChest::animFile;

SpawnInfo TreasureChest::spawnData =
{
	[]() -> ActorBase* { return new TreasureChest; },
	0x000d,
	0x00a0,
	0x00000003,
	0x00064000_f,
	0x000c8000_f,
	0x01000000_f,
	0x00000000_f
};

s32 TreasureChest::InitResources()
{
	Model::LoadFile(RED_NUMBER_MODEL_PTR);
	Model::LoadFile(modelFile);
	modelAnim.SetFile(modelFile.filePtr, 1, -1);
	
	Animation::LoadFile(animFile);
	modelAnim.SetAnim(animFile.filePtr, Animation::NO_LOOP, 0x1000_f, 0);
	
	cylClsn.Init(this, 0x96000_f, 0x96000_f, 0x00200004, 0x00000000);
	
	UpdateModelTransform();
	
	order = param1 & 0xff;
	starID = param1 >> 8 & 0xff;
	if(starID < 8)
		trackedStarID = TrackStar(starID, 2);
	
	return 1;
}

s32 TreasureChest::CleanupResources()
{
	animFile.Release();
	modelFile.Release();
	RED_NUMBER_MODEL_PTR.Release();
	return 1;
}

s32 TreasureChest::Behavior()
{
	CallState();
	cylClsn.Clear();
	cylClsn.Update();
	return 1;
}

s32 TreasureChest::Render()
{
	modelAnim.Render();
	return 1;
}

void TreasureChest::UpdateModelTransform()
{
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
}

void TreasureChest::ChangeState(u32 newState)
{
	state = newState;
	(this->*states[state].init)();
}

void TreasureChest::CallState()
{
	(this->*states[state].main)();
}

void TreasureChest::State0_Init()
{
	modelAnim.currFrame = 0_f;
}

void TreasureChest::State0_Main()
{
	DecIfAbove0_Short(cooldown);
	if(cooldown == 0x58)
		Sound::PlayBank2_2D(0x0e);
	
	if(cylClsn.otherObjID == 0 || cooldown != 0)
		return;
	
	//is the player opening it from the wrong side?
	Actor* actor = Actor::FindWithID(cylClsn.otherObjID);
	if(!actor || actor->actorID != 0x00bf || AngleDiff(pos.HorzAngle(actor->pos), ang.y) >= 0x4000)
		return;
	Player* player = (Player*)actor;
	
	s32 numOpenChests = 0;
	s32 count = 0;
	TreasureChest* currChest = nullptr;
	while((currChest = (TreasureChest*)FindWithActorID(TREASURE_CHEST_ACTOR_ID, currChest)))
	{
		++count;
		if (currChest == this)
			continue;
		
		if (currChest->state == 1 || currChest->state == 2)
			++numOpenChests;
	}
	
	if (order == numOpenChests + 1)
	{
		if (order == count)
		{
			SpawnSoundObj(0);
			spawnStar = true;
		}
		else
			Sound::PlayBank2_2D(0x26);
		
		Sound::Play(3, player->isUnderwater ? 0x22 : 0x20, camSpacePos);
		ChangeState(1);
	}
	else
	{
		cooldown = 0x5a;
		player->Shock(!player->isMetalWario);
		
		currChest = nullptr;
		while ((currChest = (TreasureChest*)FindWithActorID(TREASURE_CHEST_ACTOR_ID, currChest)) != this)
			currChest->ChangeState(0);
	}
}

void TreasureChest::State1_Init()
{
	if (spawnStar)
		cooldown = 0x2d;
	flags &= ~Actor::NO_BEHAVIOR_IF_OFF_SCREEN;
}

void TreasureChest::State1_Main()
{
	modelAnim.Advance();
	if ((s32)modelAnim.currFrame == 0x14)
	{
		Player* player = ClosestPlayer();
		Vector3 spawnPos { pos.x, pos.y + 0xc8000_f, pos.z };
		if (!spawnStar)
			SpawnNumber(spawnPos, order, false, 0, 0);
		
		if (player->isUnderwater)
		{
			Bubble* bubble = (Bubble*)Actor::Spawn(BUBBLE_ACTOR_ID, 0x0000, spawnPos, nullptr, areaID, -1);
			bubble->speed = Vector3{ 0_f, 0x800_f, 0_f };
		}
	}
	
	if (modelAnim.Finished())
		ChangeState(2);
}

void TreasureChest::State2_Init()
{
	if (!spawnStar)
		flags |= Actor::NO_BEHAVIOR_IF_OFF_SCREEN;
}

void TreasureChest::State2_Main()
{
	if (!spawnStar || cooldown == 0 || DecIfAbove0_Short(cooldown) != 0)
		return;
	
	if (starID < 8)
		UntrackAndSpawnStar(trackedStarID, starID, Vector3{pos.x, pos.y + 0xc8000_f, pos.z}, 4);
	if (starID >= 0x10 && starID < 0x30)
		Event::SetBit(starID - 0x10);
	
	flags |= Actor::NO_BEHAVIOR_IF_OFF_SCREEN;
}