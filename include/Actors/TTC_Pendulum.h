#pragma once

struct TTC_Pendulum : Platform
{
	s16 direction;       // 0x31e
	s16 angVelIncZ;      // 0x320
	s16 nextAngZ;        // 0x322
	s16 angVelZ;         // 0x324
	u16 soundTimer;      // 0x326
	u16 moveTimer;       // 0x328
	Fix12i floorPosY;    // 0x32c
	ShadowModel shadow;  // 0x330
	Matrix4x3 shadowMat; // 0x358
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TTC_Pendulum();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_Pendulum() override;
	
	void UpdateModelTransform();
	void DropShadow();
};