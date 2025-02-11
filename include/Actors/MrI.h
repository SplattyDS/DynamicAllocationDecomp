#pragma once

struct MrI : Actor
{
	struct State
	{
		using StateFunc = void(MrI::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Types
	{
		NORMAL,
		BIG,
		
		NUM_TYPES,
	};
	
	enum TexSeqs
	{
		CLOSE,
		OPEN,
		
		NUM_TEX_SEQS,
	};
	
	ModelAnim modelAnim;               // 0xd4
	TextureSequence texSeq;            // 0x138
	ShadowModel shadow;                // 0x14c
	MovingCylinderClsnWithPos cylClsn; // 0x174
	Matrix4x3 shadowMat;               // 0x1b4
	State* state;                      // 0x1e4
	// u32 stateID;                    // 0x1e8
	Player* targetPlayer;              // 0x1ec
	Fix12i curScale;                   // 0x1f0
	s32 totalSpinRot;                  // 0x1f4
	Fix12i soundSpeed;                 // 0x1f8
	s32 eyeWobbleRange;                // 0x1fc
	Fix12i shadowDepth;                // 0x200
	u32 smokeParticleID;               // 0x204
	u32 fireParticleID;                // 0x208
	s16 prevAngY;                      // 0x20c
	s16 targetRotSpeed;                // 0x20e
	s16 eyeWobbleAng;                  // 0x210
	// u8 unk212;                      // 0x212 (set to 240 x3, never used)
	u8 blinkTimer;                     // 0x213
	u8 stateState;                     // 0x214
	u8 deathTimer;                     // 0x215
	u8 resetSpinRotTimer;              // 0x216
	s8 trackStarID;                    // 0x217
	s16 rotSpeed;                      // used to be horzSpeed but that was a Fix12i
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	static SharedFilePtr texSeqFiles[NUM_TEX_SEQS];
	
	static State ST_WAIT;
	static State ST_TARGET_PLAYER;
	static State ST_DEATH;
	
	MrI();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~MrI() override;
	
	void UpdateModelTransform();
	void DropShadow();
	void ChangeState(State* newState);
	void CallState();
	void ResetTexSeq();
	void SearchForPlayer();
	void GetHurtOrHurtPlayer();
	bool StartBlinking();
	bool BlinkAtPlayer();
	bool CheckSpinByPlayer();
	
	void St_Wait_Init();
	void St_Wait_Main();
	void St_TargetPlayer_Init();
	void St_TargetPlayer_Main();
	void St_Death_Init();
	void St_Death_Main();
};