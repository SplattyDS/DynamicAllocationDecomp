#pragma once

struct CCC_ArenaIce : Platform
{
	struct State
	{
		using StateFunc = void(CCC_ArenaIce::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Types
	{
		ARENA,
		BIG_ICE,
		SMALL_ICE,
		
		NUM_TYPES,
	};
	
	State* state;         // 0x320
	// u32 unk324;        // 0x324 (unused)
	// s32 unk328;        // 0x328 (always set to 5.625_deg before only use, set to 0 after only use)
	u8 type;              // 0x32c
	s8 platformID;        // 0x32d
	// u16 unk32e;        // 0x32e (unused)
	u16 stateTimer;       // 0x330
	s16 wobbleAng;        // 0x332
	// u32 chiefChillyID; // 0x334 (for ARENA, set to Chief Chilly's uniqueID, unused)
	// u32 unk338;        // 0x338 (set to 0, unused)
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static PlatformRes resources[NUM_TYPES];
	
	static s8 nextBigIceID;
	static s8 nextSmallIceID;
	
	static State ST_ARENA_FALLEN;
	static State ST_WAIT_FOR_CLSN;
	static State ST_FALL;
	static State ST_ARENA_FALL;
	
	CCC_ArenaIce();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~CCC_ArenaIce() override;
	virtual void Kill() override;
	
	void ChangeState(State* newState);
	void CallState();
	void UpdateModelTransform();
	void AfterClsn(Actor& otherActor);
	
	void St_ArenaFallen_Init();
	void St_ArenaFallen_Main();
	void St_WaitForClsn_Init();
	void St_WaitForClsn_Main();
	void St_Fall_Init();
	void St_Fall_Main();
	void St_ArenaFall_Init();
	void St_ArenaFall_Main();
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};