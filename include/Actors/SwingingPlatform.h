#pragma once

struct SwingingPlatform : Platform
{
	s16 angVelZ; // 0x31e
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SwingingPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SwingingPlatform() override;
	
	void UpdateModelTransform();
};