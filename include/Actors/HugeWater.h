#pragma once

struct HugeWater : Platform
{
	TextureTransformer texSRT; // 0x320
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	HugeWater();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~HugeWater() override;
};