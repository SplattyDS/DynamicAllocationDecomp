#pragma once

struct CastleWater : Platform
{
	TextureTransformer texSRT; // 0x320
	// u32 unk334;             // 0x334 (unused)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	CastleWater();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~CastleWater() override;
	
	void SpawnMistParticles();
};