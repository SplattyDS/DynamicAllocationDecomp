#pragma once

struct TTC_RotatingBlock : Platform
{
	enum Types : u8
	{
		CUBE,
		PRISM,
		
		NUM_TYPES,
	};
	
	Model screwModel;         // 0x320
	Fix12i offsetY;           // 0x370
	u16 stateTimer;           // 0x374
	u8 state;                 // 0x376
	u8 type;                  // 0x377
	s16 targetAngZ;           // 0x378
	bool notAboveFlatSurface; // 0x37a
	Fix12i offsetFloorPosY;   // 0x37c
	ShadowModel shadow;       // 0x380
	Matrix4x3 shadowMat;      // 0x3a8
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr screwModelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static CLPS_Block* clpsBlocks[NUM_TYPES];
	
	TTC_RotatingBlock();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_RotatingBlock() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
	void DropShadow();
};