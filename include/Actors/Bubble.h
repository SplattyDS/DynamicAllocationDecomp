#pragma once

struct Bubble : Actor
{
	MovingCylinderClsn cylClsn; // 0xd4
	Fix12i speedMultiplier;     // 0x108
	s16 horzSpeedArcSin;        // 0x10c
	u16 despawnTimer;           // 0x10e
	u32 particleUniqueID;       // 0x110
	
	static SpawnInfo spawnData;
	
	Bubble();
	virtual int InitResources() override;
	virtual int Behavior() override;
	virtual ~Bubble() override;
	
	void Kill();
	bool IsCloseToWaterSurface();
};