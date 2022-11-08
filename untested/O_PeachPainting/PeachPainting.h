#ifndef PEACH_PAINTING_INCLUDED
#define PEACH_PAINTING_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02112c68, size is 0x128, actor id is 0x26
struct PeachPainting : Actor
{
	Model model;	// 0xd4
	u32 opacity;	// 0x124
	
	static SharedFilePtr modelFile;				// 0x02112d64
	static SpawnInfo spawnData;					// 0x02112c44
	
	void UpdateModelTransform();				// 0x02111e84
	
	//PeachPainting();							// 0x02112004
	
	virtual s32 InitResources() override;		// 0x02111fc0
	virtual s32 CleanupResources() override;	// 0x02111ec4
	virtual s32 Behavior() override;			// 0x02111f28
	virtual s32 Render() override;				// 0x02111ee8
	//virtual void ~PeachPainting() override;	// 0x02111e10
	//virtual void ~PeachPainting() override;	// 0x02111e40
};

static_assert(sizeof(PeachPainting) == 0x128, "PeachPainting is wrong size");

#endif