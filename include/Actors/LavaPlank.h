#pragma once

struct LavaPlank : Platform
{
	s16 speedAng;        // 0x31e (was originally at 0x324 but that wastes 4 bytes)
	Fix12i originalPosY; // 0x320
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	LavaPlank();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~LavaPlank() override;
};