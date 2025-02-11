#pragma once

struct Whirlpool : Enemy
{
	struct State
	{
		using StateFunc = bool (Whirlpool::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	State* state;              // 0x110
	ModelAnim modelAnim;       // 0x114
	TextureTransformer texSRT; // 0x178
	bool killedPlayer;         // 0x18c (was a u32 for some reason)
	// u32 unk190;             // 0x190 (unused)
	Fix12i playerPosY;         // 0x194
	Fix12i distToPlayer;       // 0x198
	Vector3 nextPlayerPos;     // 0x19c
	Vector3 sourcePos;         // 0x1a8
	s16 playerAngY;            // 0x1b4
	s16 playerAngVelY;         // 0x1b6
	u32 particleID;            // 0x1b8
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	static State ST_SUCK_PLAYER;
	static State ST_KILL_PLAYER;
	
	Whirlpool();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Whirlpool() override;
	
	void ChangeState(State& newState);
	void UpdateModelTransform();
	
	bool St_SuckPlayer_Init();
	bool St_SuckPlayer_Main();
	bool St_KillPlayer_Init();
	bool St_KillPlayer_Main();
};