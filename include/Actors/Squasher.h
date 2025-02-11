#pragma once

struct Squasher : Platform
{
	s16 angVelX;         // 0x31e
	u16 stateTimer;      // 0x320
	u8 state;            // 0x322
	ShadowModel shadow;  // 0x324
	Matrix4x3 shadowMat; // 0x34c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	Squasher();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Squasher() override;
	
	void UpdateModelTransform();
	void DropShadow();
};