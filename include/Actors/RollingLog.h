#pragma once

struct RollingLog : Platform
{
	Vector3 originalPos;   // 0x320
	Vector3 clsnPos;       // 0x32c	
	s32 originalAngleDiff; // 0x338
	s16 angVelX;           // 0x33c
	u8 moveBackwardsTimer; // 0x33e
	u16 soundTimer;        // 0x340
	bool hadClsn;          // 0x342
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() = 0;
	virtual s32 Render() override;
	virtual ~RollingLog() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	
	s32 BaseCleanupResources(PlatformRes& res);
	s32 BaseBehavior(Fix12i maxTravelDist);
	s32 BaseInitResources(PlatformRes& res);
	
	void UpdateModelTransform();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};

struct RollingLog_LLL : RollingLog
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RollingLog_LLL();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~RollingLog_LLL() override;
};

struct RollingLog_TTM : RollingLog
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	RollingLog_TTM();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~RollingLog_TTM() override;
};