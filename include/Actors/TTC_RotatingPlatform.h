#pragma once

struct TTC_RotatingPlatform : Platform
{
	enum Types : u8
	{
		GEAR,
		TRIANGLE,
		
		NUM_TYPES,
	};
	
	u8 type;             // 0x31e
	Fix12i floorPosY;    // 0x320
	ShadowModel shadow;  // 0x324
	Matrix4x3 shadowMat; // 0x34c
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static CLPS_Block* clpsBlocks[NUM_TYPES];
	
	TTC_RotatingPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_RotatingPlatform() override;
	
	void DropShadow();
};