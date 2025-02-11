#pragma once

struct SnowmanHead : Actor
{
	struct State
	{
		using StateFunc = void(SnowmanHead::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	Model model;                // 0xd4
	TextureSequence texSeq;     // 0x124
	MovingCylinderClsn cylClsn; // 0x138
	WithMeshClsn wmClsn;        // 0x16c
	State* state;               // 0x328
	Player* listener;           // 0x32c
	// u32 stateID;             // 0x330 (unused)
	u8 stateState;              // 0x334
	u8 stateTimer;              // 0x335
	bool hasBody;               // 0x336
	
	static SpawnInfo spawnData;
	
	static State ST_WAIT;
	static State ST_TALK;
	static State ST_JUMP;
	static State ST_GIVE_STAR;
	
	SnowmanHead();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SnowmanHead() override;
	
	void ChangeState(State* newState);
	void CallState();
	void UpdateModelTransform();
	
	void St_Wait_Init();
	void St_Wait_Main();
	void St_Talk_Init();
	void St_Talk_Main();
	void St_Jump_Init();
	void St_Jump_Main();
	void St_GiveStar_Init();
	void St_GiveStar_Main();
};