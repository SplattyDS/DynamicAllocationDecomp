#pragma once

struct Snufit : Enemy
{
	struct State
	{
		using StateFunc = bool(Snufit::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Animations
	{
		WAIT,
		ATTACK,
		
		NUM_ANIMS,
	};
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	ModelAnim modelAnim;        // 0x300
	ShadowModel shadow;         // 0x364
	Matrix4x3 shadowMat;        // 0x38c
	State* state;               // 0x3bc
	Vector3 mouthPos;           // 0x3c0
	Vector3 originalPos;        // 0x3cc
	s32 hoverAngle;             // 0x3d8
	s32 numBulletsShot;         // 0x3dc
	s16 targetDir;              // 0x3e0
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static State ST_SHOOT;
	static State ST_BUMPED_UNDERNEATH;
	static State ST_WAIT;
	static State ST_TARGET_PLAYER;
	
	Snufit();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Snufit() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void GetHurtOrHurtPlayer();
	void KillAndSpawnCoins();
	
	bool St_Shoot_Init();
	bool St_Shoot_Main();
	bool St_BumpedUnderneath_Init();
	bool St_BumpedUnderneath_Main();
	bool St_Wait_Init();
	bool St_Wait_Main();
	bool St_TargetPlayer_Init();
	bool St_TargetPlayer_Main();
};