#pragma once

struct RotatingBridge : Platform
{
	u8 waitTimer;
	u32 soundID;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	RotatingBridge();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RotatingBridge() override;
};