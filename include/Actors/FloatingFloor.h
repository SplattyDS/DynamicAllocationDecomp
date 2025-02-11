#pragma once

struct FloatingFloor : Platform
{
	Fix12i originalPosY;    // 0x320
	Fix12i speedMultiplier; // 0x324
	s16 heigthAng;          // 0x328
	u16 waitTimer;          // 0x32a
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~FloatingFloor() override;
	
	s32 BaseInitResources(PlatformRes& res, Fix12i speedMult);
	s32 BaseCleanupResources(PlatformRes& res);
};

struct FloatingFloor_LLL : FloatingFloor
{
	enum Types : u8
	{
		BIG,
		SMALL,
		
		NUM_TYPES,
	};
	
	u8 type; // 0x32c
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static PlatformRes resources[NUM_TYPES];
	
	FloatingFloor_LLL();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FloatingFloor_LLL() override;
};

struct FloatingFloor_BFS : FloatingFloor
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	FloatingFloor_BFS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~FloatingFloor_BFS() override;
};