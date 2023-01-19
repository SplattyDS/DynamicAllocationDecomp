#pragma once

struct MetalNet : Platform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	MetalNet();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~MetalNet() override;
};