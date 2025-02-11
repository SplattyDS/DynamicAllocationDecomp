#pragma once

struct Scuttlebug : Actor
{
	struct State
	{
		using StateFunc = void(Scuttlebug::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	ModelAnim modelAnim;        // 0xd4
	ShadowModel shadow;         // 0x138
	MovingCylinderClsn cylClsn; // 0x160
	WithMeshClsn wmClsn;        // 0x194
	Matrix4x3 shadowMat;        // 0x350
	State* state;               // 0x380
	Vector3 spawnPos;           // 0x384
	Vector3 returnPos;          // 0x390
	// u32 stateID;             // 0x39c
	Fix12i distToTarget;        // 0x3a0
	s16 angToTarget;            // 0x3a4
	s16 spawnAngY;              // 0x3a6
	u16 stateTimer;             // 0x3a8
	u8 numCoins;                // 0x3aa
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	static State ST_WAIT_TO_SPAWN;
	static State ST_SPAWN_JUMP;
	static State ST_WALK;
	static State ST_CHASE_PLAYER;
	static State ST_ATTACK;
	static State ST_RETREAT;
	static State ST_EATEN;
	static State ST_SPIT;
	static State ST_HIT_BY_MEGA;
	
	Scuttlebug();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Scuttlebug() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void UpdateModelTransform();
	void DropShadow();
	void ChangeState(State* newState);
	void CallState();
	void Kill();
	void GetHurtOrHurtPlayer();
	void CheckForPlayer();
	void UpdateWmClsn();
	
	void St_WaitToSpawn_Init();
	void St_WaitToSpawn_Main();
	void St_SpawnJump_Init();
	void St_SpawnJump_Main();
	void St_Walk_Init();
	void St_Walk_Main();
	void St_ChasePlayer_Init();
	void St_ChasePlayer_Main();
	void St_Attack_Init();
	void St_Attack_Main();
	void St_Retreat_Init();
	void St_Retreat_Main();
	void St_Eaten_Init();
	void St_Eaten_Main();
	void St_Spit_Init();
	void St_Spit_Main();
	void St_HitByMega_Init();
	void St_HitByMega_Main();
};