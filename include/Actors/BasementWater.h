#pragma once

struct BasementWater : Platform
{
	TextureTransformer texSRT; // 0x320
	Fix12i drainedPosY;        // 0x334
	u32 soundID;               // 0x338
	u16 soundTimer;            // 0x33c
	bool wasJustDrained;       // 0x33e
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	BasementWater();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BasementWater() override;
};