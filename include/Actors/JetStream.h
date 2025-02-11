#pragma once

struct WaterRing;

struct JetStream : Enemy
{
	struct State
	{
		using StateFunc = bool (JetStream::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	static constexpr s32 NUM_RING_IDS = 20;
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	State* state;               // 0x300
	u32 particleID;             // 0x304
	// u32 unk308;              // 0x308 (unused)
	u32 numRingsCollected;      // 0x30c
	u32 starSpawnTimer;         // 0x310
	u32 starID;                 // 0x314
	bool noRings;               // 0x318 (was a u32)
	WaterRing* collectedRing;   // 0x31c
	u32 ringIDs[NUM_RING_IDS];  // 0x320
	u32 spawnRingIndex;         // 0x370
	u32 collectRingIndex;       // 0x374
	
	static SpawnInfo spawnData;
	
	JetStream();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~JetStream() override;
	
	void ChangeState(State& newState);
	// void FUN_0211987c(); // empty
	
	bool St_Update_Init();
	bool St_Update_Main();
};