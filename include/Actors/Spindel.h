#pragma once

struct Spindel : Platform
{
	Fix12i originalPosY; // 0x320
	s16 angVelX;         // 0x324
	u16 stateTimer;      // 0x326
	s8 moveTimer;        // 0x328 (when -1, waits 32 frames before moving)
	bool goingBack;      // 0x329
	u32 particleID[2];   // 0x32c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	Spindel();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Spindel() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
	bool IsYoshiEggInRange();
};