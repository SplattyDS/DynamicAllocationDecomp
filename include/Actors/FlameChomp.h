#pragma once

struct FlameChomp : Actor
{
	struct State
	{
		using StateFunc = void(FlameChomp::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	struct ScaleAnimator
	{
		bool loop;
		Fix12i* values;
		u32 numFrames;
		u32 currFrame;
		
		void Init(Fix12i* values, u32 numFrames, bool loop);
		Fix12i Advance();
	};
	
	enum Animations
	{
		WAIT,
		FIRE,
		
		NUM_ANIMS,
	};
	
	ModelAnim modelAnim;               // 0xd4
	ShadowModel shadow;                // 0x138
	MovingCylinderClsnWithPos cylClsn; // 0x160
	WithMeshClsn wmClsn;               // 0x1a0
	Matrix4x3 shadowMat;               // 0x35c
	ScaleAnimator scaleAnim;           // 0x38c
	State* state;                      // 0x39c
	// u32 stateID;                    // 0x3a0
	Player* player;                    // 0x3a4
	Fix12i shadowDepth;                // 0x3a8
	u8 stateTimer;                     // 0x3ac
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static State ST_WAIT;
	static State ST_ATTACK;
	static State ST_EATEN;
	static State ST_DEATH;
	
	FlameChomp();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~FlameChomp() override;
	virtual u32 OnYoshiTryEat() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void CheckDistToPlayer();
	void CheckCylClsn();
	
	void St_Wait_Init();
	void St_Wait_Main();
	void St_Attack_Init();
	void St_Attack_Main();
	void St_Eaten_Init();
	void St_Eaten_Main();
	void St_Death_Init();
	void St_Death_Main();
};