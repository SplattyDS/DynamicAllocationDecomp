#pragma once

struct RotatingClockHand : Platform
{
	u16 waitTimer;     // 0x31e
	u16 randomTimer;   // 0x320
	s16 targetAngY;    // 0x322
	s16 targetAngVelY; // 0x324
	// s16 unk326;     // 0x326 (same starting value as targetAngVelY, unused)
	// u32 unk328;     // 0x328
	// u32 type;       // 0x32c (RotatingCog is now separate)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	RotatingClockHand();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RotatingClockHand() override;
};