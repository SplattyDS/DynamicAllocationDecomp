#ifndef SWITCH_PILLAR_INCLUDED
#define SWITCH_PILLAR_INCLUDED

#include "../SM64DS_2.h"

struct SwitchPillar : Platform
{
	static SharedFilePtr modelFile;				// 0x021124a8
	static SharedFilePtr clsnFile;				// 0x021124a0
	static SpawnInfo spawnData;					// 0x02112320
	
	//SwitchPillar();							// 0x02111420
	
	virtual s32 InitResources() override;		// 0x02111370
	virtual s32 CleanupResources() override;	// 0x021112ec
	virtual s32 Behavior() override;			// 0x0211134c
	virtual s32 Render() override;				// 0x02111324
	//virtual void ~SwitchPillar() override;	// 0x021111a0
	//virtual void ~SwitchPillar() override;	// 0x021111e4
	virtual void OnGroundPounded(Actor& groundPounder) override; // 0x0211123c
};

static_assert(sizeof(SwitchPillar) == 0x320, "SwitchPillar is wrong size");

#endif