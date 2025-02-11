#include "SM64DS_2.h"
#include "Actors/Bubble.h"

SpawnInfo Bubble::spawnData =
{
	[]() -> ActorBase* { return new Bubble; },
	0x0123,
	0x00a1,
	0,
	96._f,
	512._f,
	4096._f,
	0._f,
};

s32 Bubble::InitResources()
{
	cylClsn.Init(this, 150._f, 150._f, CylinderClsn::INTANGIBLE | CylinderClsn::COLLECTABLE, 0);
	despawnTimer = 300;
	
	return 1;
}

s32 Bubble::Behavior()
{
	horzSpeedArcSin += 5.625_deg;
	horzSpeed = speedMultiplier * Sin(horzSpeedArcSin);
	speedMultiplier.ApproachLinear(6._f, 0.1997_f);
	UpdatePos(nullptr);
	
	if (cylClsn.otherObjID != 0)
	{
		Player* player = (Player*)Actor::FindWithID(cylClsn.otherObjID);
		if (player != nullptr && player->actorID == PLAYER_ACTOR_ID)
		{
			player->Heal(0x300);
			Kill();
		}
	}
	
	if (DecIfAbove0_Short(despawnTimer) == 0 || IsCloseToWaterSurface())
		Kill();
	
	particleUniqueID = Particle::System::New(particleUniqueID, 1, pos.x, pos.y, pos.z, nullptr, nullptr);
	
	cylClsn.Clear();
	cylClsn.Update();
	
	return 1;
}

void Bubble::Kill()
{
	Sound::Play("NCS_SE_SCT_BIGBUBBLE"sfx, camSpacePos);
	Particle::System::NewSimple(0x2, pos.x, pos.y, pos.z);
	MarkForDestruction();
}

bool Bubble::IsCloseToWaterSurface()
{
	RaycastGround raycaster;
	raycaster.StartDetectingWater();
	raycaster.SetObjAndPos(Vector3{pos.x, pos.y + 500._f, pos.z}, this);
	
	if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.isWater)
		return true;
	
	return false;
}

Bubble::Bubble() {}
Bubble::~Bubble() {}