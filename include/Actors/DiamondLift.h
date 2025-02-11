#pragma once

struct DiamondLift : Platform
{
	u8 changeDirTimer; // 0x31e
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	DiamondLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~DiamondLift() override;
};