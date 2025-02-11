#pragma once

struct FlyGuy : Enemy
{
	struct State
	{
		using StateFunc = void(FlyGuy::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Animations
	{
		FIRE_ATTACK,
		ATTACK_04,
		ATTACK_02,
		ATTACK_01,
		WAIT,
		ATTACK_03,
		
		NUM_ANIMS,
	};
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	ModelAnim modelAnim;        // 0x300
	ShadowModel shadow;         // 0x364
	Matrix4x3 shadowMat;        // 0x38c
	State* state;               // 0x3bc
	Vector3 returnPos;          // 0x3c0
	u16 waitTimer;              // 0x3cc
	u32 smokeParticleID;        // 0x3d0
	u32 fireParticleID;         // 0x3d4
	u32 stateState;             // 0x3d8
	bool hitPlayerWithAttack;   // 0x3dc
	bool canSpawnFire;          // 0x3e0
	s16 targetDir;              // 0x3e6
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static State ST_FIRE_ATTACK;
	static State ST_WAIT;
	static State ST_CHASE_PLAYER;
	static State ST_DEATH;
	static State ST_ATTACK;
	static State ST_RETREAT;
	
	FlyGuy();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~FlyGuy() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void GetHurtOrHurtPlayer();
	void KillAndSpawnCoins();
	
	void St_FireAttack_Init();
	void St_FireAttack_Main();
	void St_Wait_Init();
	void St_Wait_Main();
	void St_ChasePlayer_Init();
	void St_ChasePlayer_Main();
	void St_Death_Init();
	void St_Death_Main();
	void St_Attack_Init();
	void St_Attack_Main();
	void St_Retreat_Init();
	void St_Retreat_Main();
};