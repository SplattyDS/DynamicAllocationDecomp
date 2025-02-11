#pragma once

struct SpinningPlatform : Platform
{
	s8 randDirection;    // 0x31e
	u16 randTimer;       // 0x320
	u16 randFrames;      // 0x322
	Fix12i floorPosY;    // 0x324
	ShadowModel shadow;  // 0x328
	Matrix4x3 shadowMat; // 0x350
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SpinningPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SpinningPlatform() override;
	
	void UpdateModelTransform();
	void DropShadow();
};