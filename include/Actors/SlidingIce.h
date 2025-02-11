#pragma once

struct SlidingIce : Platform
{
	enum Types
	{
		SPAWNER,
		ICE,
		
		NUM_TYPES,
	};
	
	union           // 0x31e
	{
		u16 spawnTimer;    // for spawner (spawns ice when 0)
		u16 slowDownTimer; // for ice (slows down when 0)
	};
	u8 numToBigIce; // 0x320
	Fix12i minPosY; // 0x324
	u32 soundID;    // 0x328
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SlidingIce();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SlidingIce() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
};