#pragma once
#include "Actors/Snowman.h"

struct SnowmanBody : Actor
{
	struct State
	{
		using StateFunc = void(SnowmanBody::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	Model model;                // 0xd4
	ShadowModel shadow;         // 0x124
	MovingCylinderClsn cylClsn; // 0x14c
	WithMeshClsn wmClsn;        // 0x180
	Vector3 originalPos;        // 0x33c
	Vector3_16 originalAng;     // 0x348
	Matrix4x3 shadowMat;        // 0x350
	PathPtr pathPtr;            // 0x380
	u32 curPathNode;            // 0x388
	State* state;               // 0x38c
	Player* trackedPlayer;      // 0x390
	// u32 stateID;             // 0x394 (unused)
	Fix12i radius;              // 0x398
	u32 soundID;                // 0x39c
	u16 stateTimer;             // 0x3a0
	u8 stateState;              // 0x3a2
	bool checkpointActivated;   // 0x3a3
	// u8 unk3a4;               // 0x3a4 (always 90, unused)
	
	static SpawnInfo spawnData;
	
	static State ST_WAIT;
	static State ST_TALK;
	static State ST_ROLL;
	static State ST_JUMP_TO_END;
	static State ST_ROLL_OFF;
	static State ST_RESPAWN;
	
	SnowmanBody();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SnowmanBody() override;
	
	void ChangeState(State* newState);
	void CallState();
	void UpdateModelTransform();
	void DropShadow();
	bool FollowPath();
	bool CanSeePlayer();
	void Rotate();
	void UpdateWmClsn();
	bool CheckCylClsn();
	
	void St_Wait_Init();
	void St_Wait_Main();
	void St_Talk_Init();
	void St_Talk_Main();
	void St_Roll_Init();
	void St_Roll_Main();
	void St_JumpToEnd_Init();
	void St_JumpToEnd_Main();
	void St_RollOff_Init();
	void St_RollOff_Main();
	void St_Respawn_Init();
	void St_Respawn_Main();
};