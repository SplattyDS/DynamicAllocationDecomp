#pragma once

struct TinyWater : Platform
{
	TextureTransformer texSRT; // 0x320
	Fix12i minPosY;            // 0x334
	u32 soundID;               // 0x338
	u16 soundTimer;            // 0x33c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TinyWater();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TinyWater() override;
};