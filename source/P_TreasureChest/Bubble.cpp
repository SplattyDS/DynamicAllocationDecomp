#include "General.h"

SpawnInfo Bubble::spawnData =
{
	[]() -> ActorBase* { return new Bubble; },
	0x0123,
	0x00a1,
	0x00000000,
	0x00060000_f,
	0x00200000_f,
	0x01000000_f,
	0x00000000_f
};

int Bubble::InitResources()
{
	cylClsn.Init(this, 0x96000_f, 0x96000_f, 0x100002, 0);
	despawnTimer = 300;
	return 1;
}

int Bubble::Behavior()
{
	horzSpeedArcSin += 0x400;
	horzSpeed = speedMultiplier * Sin(horzSpeedArcSin);
	speedMultiplier.ApproachLinear(0x6000_f, 0x332_f);
	UpdatePos(nullptr);
	
	Player* player;
	if (cylClsn.otherObjID != 0 && (player = (Player*)Actor::FindWithID(cylClsn.otherObjID), player != nullptr) && player->actorID == 0xbf)
	{
		player->Heal(0x300);
		Despawn();
	}
	
	if (DecIfAbove0_Short(despawnTimer) == 0 || IsCloseToWaterSurface())
		Despawn();
	
	particleUniqueID = Particle::System::New(particleUniqueID, 1, pos.x, pos.y, pos.z, nullptr, nullptr);
	cylClsn.Clear();
	cylClsn.Update();
	return 1;
}

void Bubble::Despawn()
{
	Sound::Play(3, 0xb, camSpacePos);
	Particle::System::NewSimple(0x2, pos.x, pos.y, pos.z);
	Destroy();
	return;
}

bool Bubble::IsCloseToWaterSurface()
{
	RaycastGround raycaster;
	raycaster.SetFlag_2();
	raycaster.SetObjAndPos(Vector3{pos.x, pos.y + 0x1f4000_f, pos.z}, this);
	
	if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.IsWater())
		return true;
	
	return false;
}