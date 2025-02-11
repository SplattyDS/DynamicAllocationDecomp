#pragma once

struct SlideDecoration : Actor
{
	enum Types : u8
	{
		SILVER_STAR,
		YELLOW_STAR,
		ORANGE_SMILEY,
		BLUE_SMILEY,
		
		NUM_TYPES,
	};
	
	Model model; // 0xd4
	u8 type;     // 0x124
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	
	SlideDecoration();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~SlideDecoration() override;
	
	void UpdateModelTransform();
};