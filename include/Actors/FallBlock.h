#pragma once

struct FallBlock : Platform
{
	enum States : u8
	{
		ST_WAIT,
		ST_FALL_START,
		ST_FALL,
		ST_RESPAWN,
	};
	
	Vector3 originalPos;   // 0x320
	Fix12i floorPosY;      // 0x32c
	u32 starUniqueID;      // 0x330
	s16 angVelX;           // 0x334
	s16 angVelZ;           // 0x336
	u16 fallSpeedAng;      // 0x338
	u16 stateTimer;        // 0x33a
	u8 state;              // 0x33c
	// u8 unk33d;
	bool steppedOn;        // 0x33e
	u8 disableClsnTimer;   // 0x33f
	bool shouldRespawn;    // 0x340
	bool fallBlockPtrsSet; // 0x341
	bool invisible;        // 0x342
	// u8 unk343;
	FallBlock* other1;     // 0x344
	FallBlock* other2;     // 0x348
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~FallBlock() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	virtual void Kill() override;
	
	s32 BaseInitResources(PlatformRes& res);
	s32 BaseCleanupResources(PlatformRes& res);
	
	void SetStarUniqueID();
	void CheckIfStarSpawned();
	void SetFallBlockPtrs();
	void ResetBlock();
	void UpdateModelTransform();
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};

struct FallBlock_WF : FallBlock
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	FallBlock_WF();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FallBlock_WF() override;
};

struct FallBlock_BBH : FallBlock
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	FallBlock_BBH();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FallBlock_BBH() override;
};

struct FallBlock_LLL : FallBlock
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	FallBlock_LLL();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FallBlock_LLL() override;
};

struct FallBlock_BFS : FallBlock
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	FallBlock_BFS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FallBlock_BFS() override;
};