#pragma once

struct RotatingCog : Actor
{
	enum Types
	{
		BIG,
		SMALL,
		
		NUM_TYPES,
	};
	
	Model model;       // 0xd4
	u16 waitTimer;     // 0x31e
	u16 randomTimer;   // 0x320
	s16 targetAngY;    // 0x322
	s16 targetAngVelY; // 0x324
	// s16 unk326;     // 0x326 (same starting value as targetAngVelY, unused)
	// u32 unk328;     // 0x328
	u32 type;          // 0x32c
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	
	RotatingCog();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RotatingCog() override;
	
	void UpdateModelTransform();
};