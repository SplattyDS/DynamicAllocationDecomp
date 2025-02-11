#pragma once

struct Coffin : Platform
{
	struct State
	{
		using StateFunc = void(Coffin::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	State* state;   // 0x320
	u16 stateTimer; // 0x324
	s16 angVelX;    // 0x326
	u16 shakeTimer; // 0x328
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	static State ST_WAIT;
	static State ST_STAND_UP;
	
	Coffin();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Coffin() override;
	
	void UpdateModelTransform();
	void CallState();
	void ChangeState(State* newState);
	
	void St_Wait_Init();
	void St_Wait_Main();
	void St_StandUp_Init();
	void St_StandUp_Main();
};