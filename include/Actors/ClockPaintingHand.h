#pragma once

struct ClockPaintingHand : Actor
{
	enum Size
	{
		SHORT,
		LONG,
		
		NUM_SIZES,
	};
	
	Model model; // 0xd4
	u8 size;     // 0x124
	
	static SpawnInfo spawnData[NUM_SIZES];
	static SharedFilePtr modelFiles[NUM_SIZES];
	
	ClockPaintingHand();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ClockPaintingHand() override;
	
	void UpdateModelTransform();
};