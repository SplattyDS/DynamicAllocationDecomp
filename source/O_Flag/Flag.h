#ifndef FLAG_INCLUDED
#define FLAG_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02113ba0, size is 0x138, actor id is 0x156
struct Flag : Actor
{
	ModelAnim modelAnim;	// 0xd4
	
	static SharedFilePtr modelFile;				// 0x02113eb8
	static SharedFilePtr animFile;				// 0x02113eb0
	static SpawnInfo spawnData;					// 0x02113b7c
	
	//Flag();									// 0x021121f0
	
	virtual s32 InitResources() override;		// 0x02112190
	virtual s32 CleanupResources() override;	// 0x021120ec
	virtual s32 Behavior() override;			// 0x02112144
	virtual s32 Render() override;				// 0x0211211c
	//virtual void ~Flag() override;			// 0x02112078
	//virtual void ~Flag() override;			// 0x021120a8
};

static_assert(sizeof(Flag) == 0x138, "Flag is wrong size");

#endif