#ifndef LIGHT_BEAM_INCLUDED
#define LIGHT_BEAM_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02112ba8, size is 0x16c, actor id is 0x25
struct LightBeam : Actor
{
	Model model;					// 0xd4
	CylinderClsnWithPos cylClsn;	// 0x124
	Player* listener;				// 0x164
	u16 soundTimer;					// 0x168
	
	static SharedFilePtr modelFile;				// 0x02112d50
	static SpawnInfo spawnData;					// 0x02112b84
	
	void UpdateModelTransform();				// 0x02111a54
	
	//LightBeam();								// 0x02111dd0
	
	virtual s32 InitResources() override;		// 0x02111d20
	virtual s32 CleanupResources() override;	// 0x02111a94
	virtual s32 Behavior() override;			// 0x02111ae0
	virtual s32 Render() override;				// 0x02111ab8
	//virtual void ~LightBeam() override;		// 0x021119d0
	//virtual void ~LightBeam() override;		// 0x02111a08
};

static_assert(sizeof(LightBeam) == 0x16c, "LightBeam is wrong size");

#endif