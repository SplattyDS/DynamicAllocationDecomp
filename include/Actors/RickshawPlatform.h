#pragma once

struct RickshawPlatform : Platform
{
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RickshawPlatform() override;
	
	s32 BaseInitResources(PlatformRes& res);
	s32 BaseCleanupResources(PlatformRes& res);
};

struct RickshawPlatform_BDW : RickshawPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RickshawPlatform_BDW();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RickshawPlatform_BDW() override;
};

struct RickshawPlatform_BS : RickshawPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RickshawPlatform_BS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RickshawPlatform_BS() override;
};