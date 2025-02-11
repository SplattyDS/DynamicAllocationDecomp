#pragma once

struct TiltingPlatform : Platform
{
	Quaternion quat;       // 0x320
	Quaternion targetQuat; // 0x330
	// u32 unk340;         // 0x340 (unused)
	// u32 unk344;         // 0x344 (unused)
	// u32 unk348;         // 0x348 (unused)
	// bool hadClsn;       // 0x34c (set to true and false, otherwise unused)
	u8 restoreQuatTimer;   // 0x34d
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TiltingPlatform() override;
	
	s32 BaseInitResources(PlatformRes& res);
	s32 BaseCleanupResources(PlatformRes& res);
	
	void UpdateModelTransform();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};

struct TiltingPlatform_LLL : TiltingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	TiltingPlatform_LLL();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~TiltingPlatform_LLL() override;
};

struct TiltingPlatform_BFS : TiltingPlatform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	TiltingPlatform_BFS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~TiltingPlatform_BFS() override;
};