#pragma once

struct StarDoor : Actor
{
	struct State
	{
		using StateFunc = bool(StarDoor::*)(Player* player);
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Types
	{
		BOWSER_DARK_WORLD_DOOR = 0,
		BOWSER_FIRE_SEA_DOOR   = 1,
		CASTLE_FLOOR_2_DOOR    = 2,
		BOWSER_SKY_DOOR        = 3,
		
		NUM_TYPES,
	};
	
	CommonModel model; // 0xd4
	State* state;      // 0x110
	u8 closeDoorTimer; // 0x114
	
	static SpawnInfo spawnData;
	
	static State ST_OPEN_CLOSE;
	static State ST_STAY_CLOSED;
	static State ST_WAIT;
	static State ST_TALKING_TO_PLAYER;
	static State ST_UNLOCKING;
	
	StarDoor();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~StarDoor() override;
	
	void ChangeState(State* newState, Player* player);
	Player* CalculateRelativePlayerPos();
	bool IsInFrontOfPlayer(Player* player);
	void TryOpenDoor(Player* player);
	
	bool St_OpenClose_Init(Player* player);
	bool St_OpenClose_Main(Player* player);
	bool St_StayClosed_Main(Player* player);
	bool St_Wait_Main(Player* player);
	bool St_TalkingToPlayer_Init(Player* player);
	bool St_TalkingToPlayer_Main(Player* player);
	bool St_Unlocking_Init(Player* player);
	bool St_Unlocking_Main(Player* player);
};

struct StarDoorInfo
{
	s8 numStars;             // 0x0
	s8 saveFlag;             // 0x1
	u16 notEnoughStarsMsgID; // 0x2
	u16 notMarioMsgID;       // 0x4
};

static_assert(sizeof(StarDoor) == 0x118, "Size of StarDoor is incorrect.");