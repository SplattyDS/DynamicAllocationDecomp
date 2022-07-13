#ifndef CASTLE_WATER_INCLUDED
#define CASTLE_WATER_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02113a18, size is 0x338, actor id is 0x152
struct CastleWater : Platform
{
	TextureTransformer texSRT;	// 0x320
	unsigned unk334;			// 0x334 (unused)
	
	static SharedFilePtr modelFile;				// 0x02113c68
	static SharedFilePtr clsnFile;				// 0x02113c70
	static SpawnInfo spawnData;					// 0x021139f4
	
	//CastleWater();								// 0x02111d8c
	void SpawnMistParticles();					// 0x02111b1c
	
	virtual s32 InitResources() override;		// 0x02111c74
	virtual s32 CleanupResources() override;	// 0x02111bd4
	virtual s32 Behavior() override;			// 0x02111c4c
	virtual s32 Render() override;				// 0x02111c18
	//virtual void ~CastleWater() override;		// 0x02111a70
	//virtual void ~CastleWater() override;		// 0x02111abc
};

static_assert(sizeof(CastleWater) == 0x338, "CastleWater is wrong size");

#endif