#pragma once

struct Shutter : Platform
{
	bool isRight;  // 0x31e
	u8 state;      // 0x31f
	u8 stateTimer; // 0x320
	u8 eventID;    // 0x321
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() = 0;
	virtual s32 Render() override;
	virtual ~Shutter() override;
	
	s32 BaseInitResources(PlatformRes& resources);
	s32 BaseCleanupResources(PlatformRes& resources);
	s32 BaseBehavior();
};

struct Shutter_BOB : Shutter
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	Shutter_BOB();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~Shutter_BOB() override;
};

struct Shutter_HMC : Shutter
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static PlatformRes resources;
	
	Shutter_HMC();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~Shutter_HMC() override;
};

static_assert(sizeof(Shutter) == 0x324, "Shutter is wrong size");