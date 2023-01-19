#pragma once

#include "SM64DS_Common.h"
#include "File.h"
#include "SharedFilePtr.h"
#include "NDSCore.h"
#include "Model.h"
#include "Collision.h"
#include "PathPtr.h"
#include "Message.h"
#include "Actor.h"
#include "Particle.h"
#include "Sound.h"
#include "Input.h"
#include "Memory.h"
#include "Scene.h"
#include "OAM.h"
#include "Cutscene.h"
#include "GX.h"
#include "Enums.h"
#include "List.h"

extern "C"
{
	extern u16 OBJ_TO_ACTOR_ID_TABLE[640];
	extern SpawnInfo* ACTOR_SPAWN_TABLE[668];
}

namespace Event
{
	void ClearBit(u32 bit);
	void SetBit(u32 bit);
	s32  GetBit(u32 bit);
}

enum TTC_Speeds : s8
{
	SLOW = 0,
	FAST = 1,
	RANDOM = 2,
	STOP = 3,
};

//used for keeping track of dead objects across level parts (e.g. THI big and small mountains)
struct ActorDeathTable
{
	u8 deadObjs[64]; //technically 512 booleans
};

struct ArchiveInfo
{
	char* archive;
	char* heap;
	u16 firstFileID;
	u16 firstNotFileID; //1 + lastFileID
	char* name;
	char* fileName;
};

struct Archive
{
	char magic[4];
	Archive* next;
	Archive* prev; //if this is first, it points to the ROM.
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	u32 unk28;
	u32 unk2c;
	u32 unk30;
	u32 unk34;
	u32 unk38;
	u32 unk3c; //a function
	u32 unk40; //a function
	u32 unk44; //a function
	u32 unk48;
	u32 unk4c;
	char* header;
	char* fat;
	char* fileBlock;
	u32 unk5c;
	char data[];
};

struct ROM_Info
{
	char magic[4]; //"rom\0"
	Archive* firstArchive;
};

struct Timer
{
	u64 tickDifference;	// is the tick when the timer started running if isTimerRunning == true
	bool isTimerRunning;
	
	// should be used in this order:
	void ResetTimer();
	void StartTimer();
	void StopTimer();
};

enum ReturnState
{
	NORMAL,
	STAR_COLLECTED,
	DIED,
};

//File ID 0x8zzz is file from archive 0 with id zzz
//020189f0: overlay 0 file ID to file ID and store
//020189f8: 00 10 b0 e1: movs r0, r1 (checks if file address is nullptr)
//02018a00: 0d 01 00 1b: blne 0x02018e3c
extern "C"
{
	extern Timer TIME_TIMER;
	extern bool DISPLAY_TIMER;
	
	extern char** DL_PTR_ARR_PTR;
	
	extern s8 LEVEL_PART_TABLE[NUM_LEVELS];
	extern s8 SUBLEVEL_LEVEL_TABLE[NUM_LEVELS];
	
	extern s32 ACTOR_BANK_OVL_MAP[7][7];
	extern s32 LEVEL_OVL_MAP[NUM_LEVELS];
	
	extern MsgGenTextFunc MSG_GEN_TEXT_FUNCS[3];
	
	extern s8 ACTOR_BANK_SETTINGS[7];
	
	extern Vector3 CAM_SPACE_CAM_POS_ASR_3; //constant <0.0, 64.0, -112.0>
	
	extern ArchiveInfo ARCHIVE_INFOS[13];
	
	extern s32 NEXT_UNIQUE_ACTOR_ID;
	
	extern Matrix4x3 VIEW_MATRIX_ASR_3;
	extern Matrix4x3 INV_VIEW_MATRIX_ASR_3;
	extern Vector3_16* ROT_AT_SPAWN;
	extern Vector3* POS_AT_SPAWN;
	extern Actor::ListNode* FIRST_ACTOR_LIST_NODE;
	
	extern bool IMMUNE_TO_DAMAGE;
	
	extern u8 LEVEL_SPECIFIC_SETTING; // TTC speed, WDW water level
	extern s8 AREA_ID;
	extern s8 LEVEL_ID;
	extern s8 NEXT_LEVEL_ID;
	extern s8 STAR_ID;
	extern s8 NUM_LIVES;
	extern Area* AREAS;
	extern Camera* CAMERA;
	extern Fix12i WATER_HEIGHT;
	extern s32 EVENT_FIELD;
	extern s16 NUM_COINS[4];
	extern u8 NUM_RED_COINS[4];
	extern Player* PLAYER_ARR[4];
	extern u8 LAST_ENTRANCE_ID;
	extern u8 RETURN_STATE;
	extern u8 PREV_RETURN_STATE;
	extern bool CAMERA_SAVED_LOOK_AT_RELATED;
	extern u8 NUM_PLAYERS;
	extern u8 NUM_PLAYERS_2;
	extern bool PLAYER_TALKING;                // if true, input is used for scrolling / ending the text
	extern bool PAUSED_DURING_TIMER;
	extern bool WATERFALL_SOUNDS_DISABLED;
	extern u8 MESSAGE_RESULT;
	
	extern u8 CURRENT_GAMEMODE;                // 0 = adventure, 1 = VS, 2 = ending
	extern u8 NUM_VS_STARS_COLLECTED;          // not counting the stars that have been lost
	extern u8* VS_STAR_SPAWN_ORDER;            // points to the current order to spawn the VS stars in
	extern u8 VS_STAR_SPAWN_ORDERS[6][8];
	extern u8 NUM_VS_STARS_OBTAINED_PLAYER[4]; // how many stars each player currently has
	extern bool VS_TIME_UP;                    // displays "times up" and the times up menu if true
	extern u8 DP_STATE;                        // state of dp? 0: no dp, 1: searching for players, 6: connection error(?)
	extern u16 VS_MODE_TIMER_TIMER;
	extern u8 VS_MODE_EXIT_STATE;
	extern bool CONNECTION_ERROR;              // game softlocks if true
	
	// this is the player id of the player that activated the pause menu (I think), always 0 in single player
	constexpr u32 DAT_020a0e40 = 0;
	
	extern Actor* SILVER_STARS[12];	
	extern ActorDeathTable ACTOR_DEATH_TABLE_ARR[3]; // maximum three parts per level.
	
	extern ActorBase* ROOT_ACTOR_BASE;
	
	extern ActorBase::ProcessingListNode* FIRST_BEHAVIOR_LIST_NODE;
	extern ActorBase::ProcessingListNode* FIRST_RENDER_LIST_NODE;
	
	extern u8 GAME_PAUSED; // 0 = not paused, 1 = paused, 2 = unpausing
	
	extern bool DAT_0209cef0; // set to false in CleanCommonModelDataArr, set to true in Stage::InitResources
	
	s16 GetAngleToCamera(u32 playerID = 0);
	
	s8 SublevelToLevel(s8 levelID);
	s32 NumStars();
	s32 IsStarCollected(s32 actID, s32 starID);
	
	s32 DeathTable_GetBit(s8 bit);
	
	s8 StarCollectedInCurrLevel(s32 starID);
	
	void UnloadBlueCoinModel();
	void LoadBlueCoinModel();
	void UnloadSilverStarAndNumber();
	void LoadSilverStarAndNumber();
	void LinkSilverStarAndStarMarker(Actor* starMarker, Actor* silverStar);
	
	s16 ReadUnalignedShort(const char* from);
	u16 ReadUnalignedUshort(const char* from);
	s32 ReadUnalignedInt(const char* from);
	
	void GiveLives(u8 amount);
	void GiveCoins(u8 playerID, u8 amount);
	void KillPlayer();
	
	u32 GetSceneOverlayID(u32 actorID);
	bool IsMinigameActorID(u32 actorID);
	
	void StartFile(s8 levelID, u8 entranceID);
	void SetPlayerGlobals();
	void LoadLevelNoReturn(s8 levelID, u8 entranceID, s8 starID, u8 returnState);
	void LoadLevel(s8 levelID, u8 entranceID, s8 starID, u8 returnState, s8 returnEntranceID);
	void ExitMinigameMenu();
	void StartVsMode();
	void PrepareVsMode();
	
	u32 GetOwnerLanguage();
	void DecompressLZ16(char* source, char* dest); // source is a pointer to a LZ16 compressed file
	void Deallocate(char* something); // doesn't deallocate something if it's nullptr
	
	void Enable3dEngines(); // swaps buffers first
	void Initialise3dGraphics(s32 clearAlpha);
	void InitialiseVramGlobals();
	void LoadFont(u32 mode); // mode: 0, 1 or 2
	u32 CountStarsCollectedInLevelToDisplay(u32 actSelectorID);
	void SetBg2Offset(s32 x, s32 y);
	void SetBg3Offset(s32 x, s32 y);
	
	bool JustTriedToEnterClosedDoor();
}

#include "Save.h"