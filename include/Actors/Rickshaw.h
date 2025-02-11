#pragma once

struct Rickshaw : Platform
{
	static constexpr s32 NUM_PLATFORMS = 4;
	
	u32 platformIDs[NUM_PLATFORMS]; // 0x320
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Rickshaw() override;
	
	s32 BaseInitResources(PlatformRes& res, u32 platformActorID);
	s32 BaseCleanupResources(PlatformRes& res);
	
	void UpdateModelTransform();
};

struct Rickshaw_BDW : Rickshaw
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	Rickshaw_BDW();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~Rickshaw_BDW() override;
};

struct Rickshaw_BS : Rickshaw
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	Rickshaw_BS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~Rickshaw_BS() override;
};