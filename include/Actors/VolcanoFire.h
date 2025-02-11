#pragma once

struct VolcanoRing;

struct VolcanoFire : Actor
{
	MovingCylinderClsn cylClsn; // 0xd4
	u32 unk108;                 // 0x108
	VolcanoRing* spawner;       // 0x10c
	u16 killTimer;              // 0x110
	u32 particleID;             // 0x114
	Fix12i killPosY;            // 0x118
	
	static SpawnInfo spawnData;
	
	VolcanoFire();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~VolcanoFire() override;
	
	void HurtPlayer();
};