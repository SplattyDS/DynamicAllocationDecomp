#pragma once

struct RotatingPlatform : Platform
{
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RotatingPlatform() override;
	
	s32 BaseInitResources(PlatformRes& res, s16 rotationSpeed);
	s32 BaseCleanupResources(PlatformRes& res);
};

struct RotatingPlatform_WF : RotatingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RotatingPlatform_WF();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RotatingPlatform_WF() override;
};

struct RotatingPlatform_LLL : RotatingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RotatingPlatform_LLL();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RotatingPlatform_LLL() override;
};

struct RotatingPlatform_WDW : RotatingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RotatingPlatform_WDW();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RotatingPlatform_WDW() override;
};

struct RotatingPlatform_RR : RotatingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RotatingPlatform_RR();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RotatingPlatform_RR() override;
};

struct RotatingPlatform_BS : RotatingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RotatingPlatform_BS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~RotatingPlatform_BS() override;
};