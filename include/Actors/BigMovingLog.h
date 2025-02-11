#pragma once

struct BigMovingLog : Platform
{
	s16 heightAng;       // 0x31e
	Fix12i originalPosY; // 0x320
	Fix12i maxPosY;      // 0x324
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	BigMovingLog();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BigMovingLog() override;
};