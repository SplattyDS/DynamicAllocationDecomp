#ifndef TRAP_INCLUDED
#define TRAP_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02112ae4, size is 0x3b0, actor id is 0x24
struct Trap : Platform
{
	enum States
	{
		ST_CLOSED,
		ST_OPENING,
		ST_OPENED,
		ST_CLOSING,
		ST_CLOSED_PERMANENTLY
	};
	
	Model model2;			// 0x320 (why did Nintendo not use Platform::model...)
	Matrix4x3 clsnNextMat2;	// 0x370 (same for Platform::clsnNextMat...)
	u32 state;				// 0x3a0
	Fix12i playerDist;		// 0x3a4 (only set for spawners, not used by Trap functions)
	s16 angSubtractor;		// 0x3a8
	u8 trapActive;			// 0x3aa (used by spawner)
	bool isSpawner;			// 0x3ab
	u32 spawnerID;			// 0x3ac
	
	static SharedFilePtr modelFile;				// 0x02112d08
	static SharedFilePtr clsnFile;				// 0x02112d00
	static SpawnInfo spawnData;					// 0x02112ac0
	
	Trap* GetTrapSpawner();						// 0x0211139c
	void UpdateClsnTransform();					// 0x021113f0
	void UpdateModelTransform();				// 0x0211146c
	void UnkAfterCollision(Actor& player);		// 0x0211184c
	static void OnFloorAfterClsn(MeshCollider& clsn, Actor& clsnActor, Actor& otherActor); // 0x02111984 (calls UnkAfterCollision)
	
	void State0_Closed();						// 0x02111320
	void State1_Opening();						// 0x021112b4
	void State2_Opened();						// 0x02111284
	void State3_Closing();						// 0x0211125c
	void State4_ClosedPermanently();			// 0x0211124c
	
	//Trap();									// 0x02111998
	
	virtual s32 InitResources() override;		// 0x02111654
	virtual s32 CleanupResources() override;	// 0x02111554
	virtual s32 Behavior() override;			// 0x021115e0
	virtual s32 Render() override;				// 0x021115a8
	//virtual void ~Trap() override;			// 0x021111a0
	//virtual void ~Trap() override;			// 0x021111ec
};

static_assert(sizeof(Trap) == 0x3b0, "Trap is wrong size");

#endif