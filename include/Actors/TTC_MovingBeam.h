#pragma once

struct TTC_MovingBeam : Platform
{
	Fix12i startPosY;    // 0x320
	Fix12i endPosY;      // 0x324
	s8 direction;        // 0x328
	u16 randomTimer;     // 0x32a
	u16 randomTime;      // 0x32c
	Fix12i unk330;       // 0x330
	ShadowModel shadow;  // 0x334
	Matrix4x3 shadowMat; // 0x35c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TTC_MovingBeam();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_MovingBeam() override;
};