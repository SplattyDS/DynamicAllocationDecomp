#include "Trap.h"

namespace
{
	struct State
	{
		using FuncPtr = void(Trap::*)();
		
		FuncPtr main;
	};
	
	const State states[] // 0x02112d28
	{
		State{ &Trap::State0_Closed },
		State{ &Trap::State1_Opening },
		State{ &Trap::State2_Opened },
		State{ &Trap::State3_Closing },
		State{ &Trap::State4_ClosedPermanently }
	};
}

SharedFilePtr Trap::modelFile;
SharedFilePtr Trap::clsnFile;

SpawnInfo Trap::spawnData =
{
	[]() -> ActorBase* { return new Trap; },
	0x0024,
	0x0143,
	0x00000000,
	0x00000000_f,
	0x001f4000_f,
	0x00000000_f,
	0x00000000_f
};

s32 Trap::InitResources()
{
	trapActive = false;
	spawnerID = 0;
	
	if ((param1 & 0xff) == 0xff)
	{
		// this is the trap spawner
		isSpawner = true;
		playerDist = 0x0_f;
		
		Trap* trap;
		
		trap = (Trap*)Actor::Spawn(TRAP_ACTOR_ID, 0, Vector3{ pos.x + Cos(ang.y) * -0x15d, pos.y, pos.z + Sin(ang.y) * 0x15d }, &ang, areaID, -1);
		trap->spawnerID = uniqueID;
		
		trap = (Trap*)Actor::Spawn(TRAP_ACTOR_ID, 0, Vector3{ pos.x + Cos(ang.y) * 0x15d, pos.y, pos.z + Sin(ang.y) * -0x15d }, &ang, areaID, -1);
		trap->spawnerID = uniqueID;
		
		return 1;
	}
	
	isSpawner = false;
	
	Model::LoadFile(modelFile);
	model2.SetFile(modelFile.filePtr,1,-1);
	
	UpdateModelTransform();
	UpdateClsnTransform();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.filePtr, unkMat, 0x1000_f, ang.y, (CLPS_Block&)DAT_arm9_ov10__021122f8);
	clsn.afterClsnCallback = &OnFloorAfterClsn; // used to call function 0x020393c4 to set the callback
	clsn.Enable();
	
	angSubtractor = 0;
	state = ST_CLOSED;
	
	if ((param1 & 0xff) == 1)
		ang.y -= 0x8000;
	
	return 1;
}

int Trap::CleanupResources()
{
	if (clsn.IsEnabled())
		clsn.Disable();
	
	if ((param1 & 0xff) == 0xff)
		return 1;
	
	modelFile.Release();
	clsnFile.Release();
	
	return 1;
}

int Trap::Behavior()
{
	if (!isSpawner)
	{
		(this->*states[state].main)();
		UpdateModelTransform();
		UpdateClsnTransform();
	}
	else
		playerDist = DistToCPlayer();
	
	
	return 1;
}

int Trap::Render()
{
	if (!isSpawner)
		model.Render(nullptr);
	
	return 1;
}

void Trap::UpdateModelTransform()
{
	Matrix4x3_FromTranslation(MATRIX_SCRATCH_PAPER, (pos.x - (Sin(ang.z) * 5) * Cos(ang.y)) >> 3, pos.y >> 3, (pos.z + (Sin(ang.z) * 5) * Sin(ang.y)) >> 3);
	Matrix4x3_ApplyInPlaceToRotationY(MATRIX_SCRATCH_PAPER, ang.y);
	Matrix4x3_ApplyInPlaceToRotationZ(MATRIX_SCRATCH_PAPER, ang.z);
	
	model2.mat4x3 = MATRIX_SCRATCH_PAPER;
}

void Trap::UpdateClsnTransform()
{
	Matrix4x3_FromTranslation(MATRIX_SCRATCH_PAPER, pos.x, pos.y, pos.z);
	Matrix4x3_ApplyInPlaceToRotationY(MATRIX_SCRATCH_PAPER, ang.y);
	Matrix4x3_ApplyInPlaceToRotationZ(MATRIX_SCRATCH_PAPER, ang.z);
	
	unkMat = MATRIX_SCRATCH_PAPER;
	clsn.Transform(unkMat, ang.y);
}

void Trap::OnFloorAfterClsn(MeshCollider& clsn, Actor& clsnActor, Actor& otherActor)
{
	(Trap&)(arg2).UnkAfterCollision(otherActor);
}

void Trap::UnkAfterCollision(Actor& player)
{
	if (state != 0 || ang.z < -0x3000 || spawnerID == 0)
		return;
	
	Trap* trapSpawner = Actor::FindWithID(spawnerID);
	if (trapSpawner == nullptr)
		return;
	
	if (player.actorID != 0xbf)
		return;
	
	if (trapSpawner->pos.HorzDist(player.pos) * Sin((s16)(trapSpawner->pos.HorzAngle(player.pos) + trapSpawner->ang.y)) < 0x10e000_f)
		trapSpawner->trapActive = true;
}

int Trap::GetTrapSpawner()
{
	if (spawnerID == 0)
	{
		MarkForDestruction();
		return nullptr;
	}
	
	Trap* trapSpawner = (Trap*)Actor::FindWithID(spawnerID);
	if (trapSpawner == nullptr)
		MarkForDestruction();
	
	return trapSpawner;
}

void Trap::State0_Closed()
{
	Player* player = ClosestPlayer();
	if (player == nullptr)
		return;
	
	if (player->IsEnteringLevel())	// 0x020c7e84
	{
		state = ST_CLOSED_PERMANENTLY;
		return;
	}
	
	angSubtractor = 0x400;
	
	Trap* trapSpawner = GetTrapSpawner();
	if (trapSpawner == nullptr)
		return;
	
	if (trapSpawner->trapActive)
	{
		state = ST_OPENING;
		Sound::Play(3, 0xe, camSpacePos);
	}
}

void Trap::State1_Opening()
{
	Trap* trapSpawner = GetTrapSpawner();
	if (trapSpawner == nullptr)
		return;
	
	trapSpawner->trapActive = false;
	angSubtractor -= 0x100;
	ang.z += angSubtractor;
	
	if (ang.z < -0x3d00)
	{
		ang.z = -0x3c00;
		state = ST_OPENED;
	}
}

void Trap::State2_Opened()
{
	Trap* trapSpawner = GetTrapSpawner();
	if (trapSpawner != nullptr && !trapSpawner->trapActive)
		state = ST_CLOSING;
}

void Trap::State3_Closing()
{
	ang.z += 0x400;
	if (ang.z > 0)
	{
		ang.z = 0;
		state = ST_CLOSED;
	}
}

void Trap::State4_ClosedPermanently()
{
	ang.z = -0x3c00;
}