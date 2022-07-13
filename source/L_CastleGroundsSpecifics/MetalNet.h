#ifndef METAL_NET_INCLUDED
#define METAL_NET_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02113ae0, size is 0x320, actor id is 0x153
struct MetalNet : Platform
{
	static SharedFilePtr modelFile;				// 0x02113e90
	static SharedFilePtr clsnFile;				// 0x02113e88
	static SpawnInfo spawnData;					// 0x02113abc
	
	//MetalNet();									// 0x02112048
	
	virtual s32 InitResources() override;		// 0x02111f40
	virtual s32 CleanupResources() override;	// 0x02111e60
	virtual s32 Behavior() override;			// 0x02111ed0
	virtual s32 Render() override;				// 0x02111ea8
	virtual void OnPendingDestroy() override;	// 0x02111ea4
	//virtual void ~MetalNet() override;			// 0x02111dc4
	//virtual void ~MetalNet() override;			// 0x02111e08
};

static_assert(sizeof(MetalNet) == 0x320, "MetalNet is wrong size");

#endif