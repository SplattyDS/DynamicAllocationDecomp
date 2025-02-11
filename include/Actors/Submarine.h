#pragma once

struct Submarine : Platform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	Submarine();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~Submarine() override;
};