#pragma once

struct FloatOnWaterPlatform : Platform
{
	// Fix12i originalPosX;     // 0x320 (only set once, unused)
	Fix12i waterHeight;         // 0x324 (starts at pos.y)
	// Fix12i originalPosZ;     // 0x328 (only set once, unused)
	PlatformRes* res;           // 0x32c
	Fix12i sinkHeight;          // 0x330
	Fix12i wobbleHeight;        // 0x334
	s16 wobbleAng;              // 0x338
	Player* player;             // 0x33c
	// u8 unk340;               // 0x340 (only set once, unused)
	u16 noClsnTimer;            // 0x342 (resets player if 0)
	Fix12i originalWaterHeight; // 0x344
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~FloatOnWaterPlatform() override;
	
	s32 BaseInitResources(PlatformRes& pRes);
	
	bool SetWaterHeight();
	void UpdateModelTransform();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};

struct FloatOnWaterPlatform_JRB : FloatOnWaterPlatform
{
	FloatOnWaterPlatform_JRB();
	virtual s32 InitResources() override;
	virtual ~FloatOnWaterPlatform_JRB() override;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
};

// these were 2 separate structs with the only difference being different static members (the InitResources function was identical)
struct FloatOnWaterPlatform_WDW : FloatOnWaterPlatform
{
	enum Types
	{
		SQUARE,
		RECTANGLE,
		
		NUM_TYPES,
	};
	
	FloatOnWaterPlatform_WDW();
	virtual s32 InitResources() override;
	virtual ~FloatOnWaterPlatform_WDW() override;
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static PlatformRes resources[NUM_TYPES];
};