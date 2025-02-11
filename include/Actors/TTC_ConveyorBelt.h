#pragma once

struct TTC_ConveyorBelt : Platform
{
	enum Size : u8
	{
		LARGE,
		SMALL,
		
		NUM_SIZES,
	};
	
	TextureTransformer texSRT; // 0x320
	ShadowModel shadow;        // 0x334
	Matrix4x3 shadowMat;       // 0x35c
	Fix12i moveSpeed;          // 0x38c
	Fix12i targetSpeed;        // 0x390
	Fix12i floorPosY;          // 0x394
	u32 soundID;               // 0x398
	u16 randomTimer;           // 0x39c
	u8 size;                   // 0x39e
	
	static SpawnInfo spawnData[NUM_SIZES];
	static SharedFilePtr modelFiles[NUM_SIZES];
	static SharedFilePtr clsnFiles[NUM_SIZES];
	static CLPS_Block* clpsBlocks[NUM_SIZES];
	
	TTC_ConveyorBelt();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_ConveyorBelt() override;
	
	void DropShadow();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};