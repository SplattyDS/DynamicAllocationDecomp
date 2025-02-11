#pragma once

struct LavaBubble : Enemy
{
	struct State
	{
		using FuncPtr = s32(LavaBubble::*)();
		
		FuncPtr init;
		FuncPtr main;
	};
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	State* state;               // 0x300
	// Vector3 unk304;          // 0x304 (set to pos, unused)
	bool isBubble;              // 0x310
	u32 lavaParticleID;         // 0x314
	u32 emberParticleID;        // 0x318
	
	static SpawnInfo spawnData;
	
	LavaBubble();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~LavaBubble() override;
	virtual u32 OnYoshiTryEat() override;
	
	void ChangeState(State& newState);
	
	s32 St_Bubble_Init();
	s32 St_Bubble_Main();
	s32 St_Spawner_Init();
	s32 St_Spawner_Main();
};