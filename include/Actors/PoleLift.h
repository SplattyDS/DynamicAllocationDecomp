#pragma once

struct PoleLift : Platform
{
	MovingCylinderClsn cylClsn; // 0x320
	s16 heightAng;              // 0x354
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	PoleLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~PoleLift() override;
};