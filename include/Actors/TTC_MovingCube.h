#pragma once

struct TTC_MovingCube : Platform
{
	enum Types : u8
	{
		CUBE_A,
		CUBE_B,
		
		NUM_TYPES,
	};
	
	Vector3 originalPos; // 0x320
	u16 waitTimer;       // 0x32c
	u8 direction;        // 0x32e (0 is up, 1 is down)
	u8 type;             // 0x32f
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static CLPS_Block* clpsBlocks[NUM_TYPES];
	
	TTC_MovingCube();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_MovingCube() override;
};