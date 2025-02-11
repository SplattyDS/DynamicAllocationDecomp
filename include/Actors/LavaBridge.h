#pragma once

struct LavaBridge : Platform
{
	u8 waitTimer;    // 0x31e
	bool movingDown; // 0x31f
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	LavaBridge();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~LavaBridge() override;
	
	void UpdateModelTransform();
};