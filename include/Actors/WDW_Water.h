#pragma once

struct WDW_Water : Platform
{
	TextureTransformer texSRT; // 0x320
	Fix12i targetPosY;         // 0x334
	u8 unk338;                 // 0x338
	u32 soundID;               // 0x33c
	s8 trueAreaID;             // 0x340
	s16 waterHeightAng;        // 0x342
	Fix12i waterHeight;        // 0x344
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	WDW_Water();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~WDW_Water() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
};