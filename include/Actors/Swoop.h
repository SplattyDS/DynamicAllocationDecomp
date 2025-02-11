#pragma once

struct Swoop : Enemy
{
	struct State
	{
		using StateFunc = bool(Swoop::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	ModelAnim modelAnim;        // 0x300
	ModelAnim waitModelAnim;    // 0x364
	ShadowModel shadow;         // 0x3c8
	Matrix4x3 shadowMat;        // 0x3f0
	State* state;               // 0x420
	Vector3 originalPos;        // 0x424
	u32 numFramesOffScreen;     // 0x430
	s16 targetDir;              // 0x434
	u32 unk438;                 // 0x348 (unused)
	bool isFlying;              // 0x43c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr waitModelFile;
	static SharedFilePtr animFile;
	static SharedFilePtr waitAnimFile;
	
	static State ST_ATTACK;
	static State ST_FLY_AROUND;
	static State ST_WAIT;
	static State ST_SWOOP_DOWN;
	
	Swoop();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Swoop() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void GetHurtOrHurtPlayer();
	
	bool St_Attack_Init();
	bool St_Attack_Main();
	bool St_FlyAround_Init();
	bool St_FlyAround_Main();
	bool St_Wait_Init();
	bool St_Wait_Main();
	bool St_SwoopDown_Init();
	bool St_SwoopDown_Main();
};

static_assert(sizeof(Swoop) == 0x440);