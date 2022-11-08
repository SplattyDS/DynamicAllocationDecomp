#ifndef SWITCH_PILLAR_INCLUDED
#define SWITCH_PILLAR_INCLUDED

#include "../SM64DS_2.h"

struct TTC_PaintingHand : Actor
{
	enum Size
	{
		SHORT,
		LONG,
		
		NUM_SIZES
	};
	
	Model model;	// 0xd4
	u8 size;		// 0x124
	
	static SharedFilePtr modelFiles[2];			// 0x021116b0
	static SpawnInfo spawnDataShort;			// 0x021121dc
	static SpawnInfo spawnDataLong;				// 0x021121c0
	
	//TTC_PaintingHand();						// 0x0211163c (ShortHand)
	//TTC_PaintingHand();						// 0x02111674 (LongHand)
	
	virtual s32 InitResources() override;		// 0x021115cc
	virtual s32 CleanupResources() override;	// 0x02111478
	virtual s32 Behavior() override;			// 0x021114cc
	virtual s32 Render() override;				// 0x021114a4
	//virtual void ~TTC_PaintingHand() override;	// 0x021113bc
	//virtual void ~TTC_PaintingHand() override;	// 0x021113ec
};

static_assert(sizeof(TTC_PaintingHand) == 0x128, "TTC_PaintingHand is wrong size");

#endif