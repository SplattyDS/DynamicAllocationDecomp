#pragma once

struct BridgePenguin : Platform
{
	struct State
	{
		using StateFunc = bool (BridgePenguin::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Animations
	{
		WAIT1,
		WALK2,
		BACK,
		
		NUM_ANIMS,
	};
	
	enum States
	{
		ST_TURN,
		ST_MOVE,
		
		NUM_STATES,
	};
	
	ModelAnim modelAnim;        // 0x320
	TextureSequence texSeq;     // 0x384
	MovingCylinderClsn cylClsn; // 0x398
	State* state;               // 0x3cc
	// u32 unk3d0;              // 0x3d0 (set in state init functions, unused)
	Fix12i distToWalk;          // 0x3d4
	u8 waitTimer;               // 0x3d8
	u8 nodeID;                  // 0x3d9
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr texSeqFile;
	static SharedFilePtr clsnFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	BridgePenguin();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~BridgePenguin() override;
	
	void ChangeState(u32 newState);
	void CallState();
	void UpdateModelAndClsnTransform();
	
	bool St_Turn_Init();
	bool St_Turn_Main();
	bool St_Move_Init();
	bool St_Move_Main();
};