#pragma once

struct Amp : Actor
{
	struct State
	{
		using StateFunc = void(Amp::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Animations
	{
		ELEC,
		ELEC_STOP,
		
		NUM_ANIMS,
	};
	
	ModelAnim modelAnim;               // 0xd4
	Model electricModel;               // 0x138
	TextureSequence texSeq;            // 0x188
	TextureTransformer texSRT;         // 0x19c
	ShadowModel shadow;                // 0x1b0
	MovingCylinderClsnWithPos cylClsn; // 0x1d8
	WithMeshClsn wmClsn;               // 0x218
	Matrix4x3 shadowMat;               // 0x3d4
	Vector3 actualPos;                 // 0x404
	Vector3 offset;                    // 0x410
	State* state;                      // 0x41c
	// u32 stateID;                    // 0x420 (used to be the state id)
	s32 angVelY;                       // 0x424
	u32 soundID;                       // 0x428
	s16 heightAng;                     // 0x42c
	s16 scaleAng;                      // 0x42e
	u8 stateTimer;                     // 0x430
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	static SharedFilePtr electricModelFile;
	static SharedFilePtr electricTexSeqFile;
	
	static State ST_SHOCK;
	static State ST_MOVE;
	static State ST_DEATH;
	
	Amp();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Amp() override;
	
	void ChangeState(State* newState);
	void DropShadow();
	void GetHurtOrHurtPlayer();
	
	void St_Shock_Init();
	void St_Shock_Main();
	void St_Move_Init();
	void St_Move_Main();
	void St_Death_Init();
	void St_Death_Main();
};