#pragma once

struct Door : Actor
{
	struct State
	{
		using StateFunc = bool(Door::*)(Player* player);
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Types
	{
		STANDARD        = 0,
		STAR_0          = 1,
		STAR_1_WF       = 2,
		STAR_1_REC_ROOM = 3,
		STAR_3_JRB      = 4,
		STAR_3_CCM      = 5,
		STAR_8          = 6,
		KEY_BASEMENT    = 7,
		KEY_FLOOR_2     = 8,
		KEY_MARIO       = 9,
		KEY_LUIGI       = 10,
		KEY_WARIO       = 11,
		KEY_CASTLE      = 12,
		KEY_WHITE       = 13,
		STANDARD_2      = 14, // ???
		OLD_WOOD        = 15,
		RUSTED_METAL    = 16,
		HMC_STONE       = 17,
		BBH_HAUNTED     = 18,
		
		NUM_TYPES,
	};
	
	ModelAnim modelAnim;             // 0xd4
	Model* extraModel;               // 0x138
	SharedFilePtr* keyStarModelFile; // 0x13c
	State* state;                    // 0x140
	s8 keyType;                      // 0x144
	u8 soundTimer;                   // 0x145
	
	static SpawnInfo spawnData;
	
	static State ST_UNLOCKING_CHARACTER_DOOR;
	static State ST_WAIT;
	static State ST_TALKING_TO_PLAYER;
	static State ST_UNLOCKING_STAR_DOOR;
	static State ST_UNLOCKING_KEY_DOOR;
	static State ST_OPENING;
	static State ST_OPENING_CHARACTER_DOOR;
	static State ST_OPEN_ENTRANCE;
	static State ST_STAY_CLOSED;
	
	Door();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Door() override;
	
	Player* CalculateRelativePlayerPos();
	void ChangeState(State* newState, Player* player);
	bool TryOpenDoor(State* newState, Player* player);
	bool IsInFrontOfPlayer(Player* player);
	void SetPlayerPosAndAng(Player* player, const Vector3& leftOffset, const Vector3& rightOffset);
	bool ExitingDoorAfterUnlock(Player* player);
	
	bool St_UnlockingCharacterDoor_Main(Player* player);
	bool St_Wait_Main(Player* player);
	bool St_TalkingToPlayer_Init(Player* player);
	bool St_TalkingToPlayer_Main(Player* player);
	bool St_UnlockingStarDoor_Init(Player* player);
	bool St_UnlockingStarDoor_Main(Player* player);
	bool St_UnlockingKeyDoor_Init(Player* player);
	bool St_UnlockingKeyDoor_Main(Player* player);
	bool St_Opening_Init(Player* player);
	bool St_Opening_Main(Player* player);
	bool St_OpeningCharacterDoor_Init(Player* player);
	bool St_OpeningCharacterDoor_Main(Player* player);
	bool St_OpenEntrance_Init(Player* player);
	bool St_StayClosed_Main(Player* player);
	
	static bool JustTriedToEnterClosedDoor();
	static bool StopBowserMessageSound();
	static bool ContinueBowserMessageSound();
	static void SetBowserMessageSoundTimer(u16 value);
};

struct DoorInfo
{
	SharedFilePtr* modelFile;      // 0x0
	SharedFilePtr* extraModelFile; // 0x4
	s8 numStars;                   // 0x8
	s8 obtainedSaveFlag;           // 0x9
	s8 saveFlag;                   // 0xa (key used / door open)
	u16 closedMsgID;               // 0xc
};