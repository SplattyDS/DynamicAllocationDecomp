#pragma once

struct ArmedRotatingPlatform : Platform
{
	s16 angVelY; // 0x31e
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	ArmedRotatingPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ArmedRotatingPlatform() override;
	
	void UpdateModelTransform();
};