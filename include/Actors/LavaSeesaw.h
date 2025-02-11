#pragma once

struct LavaSeesaw : Platform
{
	s16 angVelX;  // 0x31e
	u8 waitTimer; // 0x320
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	LavaSeesaw();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~LavaSeesaw() override;
	
	void UpdateModelTransform();
};