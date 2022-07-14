#ifndef BIRD_INCLUDED
#define BIRD_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x02113954, size is 0x184, actor id is 0x157
struct Bird : Actor
{
	ModelAnim modelAnim;	// 0xd4
	ShadowModel shadow;		// 0x138
	Vector3 destination;	// 0x160
	Vector3_16 targetAng;	// 0x16c
	u16 unk172;				// 0x172 (unused)
	Fix12i speedMult;		// 0x174
	u32 leaderID;			// 0x178 (unique id of the bird that spawned the bird)
	u32 state;				// 0x17c
	bool isLeader;			// 0x180
	u8 unk181;				// 0x181 (unused)
	u16 unk182;				// 0x182 (unused)
	
	static SharedFilePtr modelFile;				// 0x02113c20
	static SharedFilePtr animFile;				// 0x02113c28
	static SpawnInfo spawnData;					// 0x02113934
	
	//Bird();									// 0x02111a30
	void SetLeader(u32 newLeaderID);			// 0x02111224
	void State0_Main();							// 0x021116ec
	void State1_Main();							// 0x021115d8
	void State2_Main();							// 0x0211145c
	void State3_Main();							// 0x02111234
	
	virtual s32 InitResources() override;		// 0x0211197c
	virtual s32 CleanupResources() override;	// 0x0211183c
	virtual s32 Behavior() override;			// 0x02111898
	virtual s32 Render() override;				// 0x02111870
	virtual void OnPendingDestroy() override;	// 0x0211186c
	//virtual void ~Bird() override;			// 0x021111a0
	//virtual void ~Bird() override;			// 0x021111d8
};

static_assert(sizeof(Bird) == 0x184, "Bird is wrong size");

#endif