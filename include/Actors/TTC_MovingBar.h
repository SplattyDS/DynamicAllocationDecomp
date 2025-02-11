#pragma once

struct TTC_MovingBar : Platform
{
	Vector3 originalPos; // 0x320
	Fix12i horzPos;      // 0x32c
	Fix12i prevHorzPos;  // 0x330
	u16 waitTimer;       // 0x334
	u8 state;            // 0x336
	
	Fix12i floorPosY;    // 0x338
	ShadowModel shadow;  // 0x33c
	Matrix4x3 shadowMat; // 0x364
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TTC_MovingBar();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TTC_MovingBar() override;
	
	void DropShadow();
	void Reset();
};