#pragma once

struct WaterSuction : Enemy
{
	struct State
	{
		using StateFunc = bool (WaterSuction::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	MovingCylinderClsnWithPos cylClsn; // 0x110
	WithMeshClsn wmClsn;               // 0x150
	State* state;                      // 0x30c
	u32 unk314;                        // 0x314
	
	static SpawnInfo spawnData;
	static State state0;
	
	WaterSuction();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~WaterSuction() override;
	
	void ChangeState(State& newState);
	void CheckCylClsn();
	void EmptyFunction();
	
	bool State0_Init();
	bool State0_Main();
};