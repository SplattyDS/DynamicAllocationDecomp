#pragma once
#include "Actors/Ship.h"

struct SlidingBox : Platform
{
	Ship* ship;                // 0x320
	WithMeshClsn wmClsn;       // 0x324
	Vector3 originalPosOnShip; // 0x4e0
	Fix12i horzPos;            // 0x4ec
	u32 soundID;               // 0x4f0
	u8 state;                  // 0x4f4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SlidingBox();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SlidingBox() override;
	
	void UpdateModelTransform();
	void Fall(); // wasn't a separate function but there were annoying goto's to it
};