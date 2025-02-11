#pragma once

struct Ship : Platform
{
	enum Type
	{
		UP,
		DOWN,
		
		NUM_TYPES,
	};
	
	u8 type;     // 0x31e
	u16 angAng;  // 0x320
	u32 soundID; // 0x324
	// u16 unk328; // 0x328 (unused, only set to 0 in InitResources)
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	
	Ship();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Ship() override;
	
	void UpdateModelTransform();
};