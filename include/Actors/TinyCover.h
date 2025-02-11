#pragma once

struct TinyCover : Platform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TinyCover();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TinyCover() override;
	virtual void OnGroundPounded(Actor& groundPounder) override;
};