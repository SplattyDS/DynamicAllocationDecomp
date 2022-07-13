#ifndef BUBBLE_INCLUDED
#define BUBBLE_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02108964, size is 0x114, actor id is 0x123
struct Bubble : public Actor
{
	MovingCylinderClsn cylClsn;	// 0xd4
	Fix12i speedMultiplier;		// 0x108
	s16 horzSpeedArcSin;		// 0x10c
	u16 despawnTimer;			// 0x10e
	u32 particleUniqueID;		// 0x110
	
	void Despawn();								// 0x020b330c
	bool IsCloseToWaterSurface();				// 0x020b3344
	
	//Bubble();									// 0x020b3568
	virtual int InitResources() override;		// 0x020b3518
	virtual int Behavior() override;			// 0x020b33dc
	//virtual ~Bubble() override;				// 0x020b3298
	//virtual ~Bubble() override;				// 0x020b32c8
	
	static SpawnInfo spawnData;					// 0x02108940
};

static_assert(sizeof(Bubble) == 0x114, "Bubble is wrong size");

#endif