#pragma once

struct FlameChompFire : Actor
{
	struct State
	{
		using StateFunc = void(FlameChompFire::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	ShadowModel shadow;         // 0xd4
	MovingCylinderClsn cylClsn; // 0xfc
	WithMeshClsn wmClsn;        // 0x130
	Matrix4x3 shadowMat;        // 0x2ec
	State* state;               // 0x31c
	// u32 stateID;             // 0x320
	u32 fireParticleID;         // 0x324
	u32 emberParticleID;        // 0x328
	u8 stateTimer;              // 0x32c
	
	static SpawnInfo spawnData;
	
	static State ST_MOVE;
	static State ST_EATEN;
	
	FlameChompFire();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~FlameChompFire() override;
	virtual u32 OnYoshiTryEat() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void Kill();
	void CheckIfGoingOffCliff();
	void UpdateWmClsn();
	void CheckCylClsn();
	
	void St_Move_Init();
	void St_Move_Main();
	void St_Eaten_Init();
	void St_Eaten_Main();
};