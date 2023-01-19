#pragma once

struct Flag : Actor
{
	ModelAnim modelAnim; // 0xd4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	Flag();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Flag() override;
};