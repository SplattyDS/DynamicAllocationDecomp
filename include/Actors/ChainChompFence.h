#pragma once

struct ChainChompFence : Platform
{
	bool killed;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	ChainChompFence();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ChainChompFence() override;
	
	void KillByChainChomp();
};