#ifndef BASEMENT_WATER_INCLUDED
#define BASEMENT_WATER_INCLUDED

#include "../SM64DS_2.h"

struct BasementWater : Platform
{
	TextureTransformer texSRT;	// 0x320
	Fix12i drainedPosY;			// 0x334
	u32 soundID;				// 0x338
	u16 soundTimer;				// 0x33c
	bool wasJustDrained;		// 0x33e
	
	static SharedFilePtr modelFile;				// 0x021124d0
	static SharedFilePtr clsnFile;				// 0x021124c8
	static SpawnInfo spawnData;					// 0x021123e4
	
	//BasementWater();							// 0x02111730
	
	virtual s32 InitResources() override;		// 0x0211164c
	virtual s32 CleanupResources() override;	// 0x021114fc
	virtual s32 Behavior() override;			// 0x02111574
	virtual s32 Render() override;				// 0x02111540
	//virtual void ~BasementWater() override;	// 0x02111450
	//virtual void ~BasementWater() override;	// 0x0211149c
};

static_assert(sizeof(BasementWater) == 0x340, "BasementWater is wrong size");

#endif