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
	u32  GetBit(u32 bit);
}

enum Events : u32
{
	EV_THI_WATER_DRAINED        = 0x0e,
	EV_SSL_PYRAMID_TOP_UNLOCKED = 0x0e,
	EV_REGULAR_STAR_GOT         = 0x1d, // no 100-coin star / vs star / silver star / star that let's you stay in level
	EV_STAR_GOT                 = 0x1e,
	EV_100_COIN_STAR_SPAWNED    = 0x1f,
};

enum TTC_Speeds : s8
{
	SLOW   = 0,
	FAST   = 1,
	RANDOM = 2,
	STOP   = 3,
	
	NUM_TTC_SPEEDS,
};

//used for keeping track of dead objects across level parts (e.g. THI big and small mountains)
struct ActorDeathTable
{
	u32 deadObjs[16]; //technically 512 booleans
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
	
	u64 GetTime();
};

enum ReturnState
{
	RS_NORMAL,
	RS_STAR_COLLECTED,
	RS_DIED,
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
	
	extern s32 PROCESS_STATE;
	extern u8 BASE_CREATION_STATE;
	extern s32 CURRENT_OBJECT_SPAWN_ID;
	extern ActorBase::ProcessingListNode* CURRENT_OBJECT_LIST_NODE;
	extern s32 NEXT_UNIQUE_ACTOR_ID;
	extern s32 LAST_USED_FILE_ID;
	extern u32* SAVED_REGISTER_VALUES;
	
	extern Matrix4x3 VIEW_MATRIX_ASR_3;
	extern Matrix4x3 INV_VIEW_MATRIX_ASR_3;
	extern Vector3_16* ROT_AT_SPAWN;
	extern Vector3* POS_AT_SPAWN;
	extern Actor::ListNode* FIRST_ACTOR_LIST_NODE;
	
	extern bool IMMUNE_TO_DAMAGE;
	
	extern s32 LOADED_LEVEL_OVL_ID;
	extern u8 LEVEL_SPECIFIC_SETTING; // TTC speed, WDW water level
	extern s8 AREA_ID;
	extern s8 LEVEL_ID;
	extern s8 NEXT_LEVEL_ID;
	extern s8 CHECKPOINT_LEVEL_ID;
	extern s8 RETURN_LEVEL_ID;
	extern s8 LEVEL_OF_LAST_COLLECTED_STAR;
	extern s8 STAR_ID;
	extern s8 NEXT_STAR_ID;
	extern s8 CHECKPOINT_STAR_ID;
	extern bool NEW_STAR_COLLECTED;
	extern s8 CUR_MINIMAP_ID;
	extern u8 STAR_OBTAINED;
	extern u8 STAR_OBTAINED_COPY;
	extern bool RETURN_TO_REC_ROOM;
	
	extern Area* AREAS;
	extern Camera* CAMERA;
	extern FaderWipe* WIPES;
	extern Actor* STAR_MARKERS[12];	
	extern u8 STAR_MARKER_TYPES[12]; // type 4 is red coin
	extern Actor* CASTLE_KEY_RABBIT;
	extern Actor* BOWSER_SPIKE_BOMBS[8];
	
	extern Fix12i WATER_HEIGHT;
	extern Fix12i STAR_CAP_MAX_POS_Y;
	extern Fix12i STAR_CAP_MIN_POS_Y;
	extern s32 EVENT_FIELD;
	extern s16 NEXT_DEATH_TABLE_ID;
	extern ActorDeathTable ACTOR_DEATH_TABLE_ARR[3]; // maximum three parts per level.
	
	extern Player* PLAYER_ARR[4];
	extern bool IS_PLAYER_ACTIVE[4];
	extern u8 NEXT_HAT_CHARACTER_ARR[4];
	extern s16 NUM_COINS[4];
	extern s8 NUM_RED_COINS[4];
	extern s16 HEALTH_ARR[4];
	extern s8 NUM_LIVES;
	extern u8 RENDERED_HEALTH;
	
	extern u8 NEXT_HAT_CHARACTER;
	extern u8 UNK_YOSHI_EGG_RELATED;
	extern u8 LAST_ENTRANCE_ID;
	extern u8 NEXT_ENTRANCE_ID;
	extern u8 RETURN_ENTRANCE_ID;
	extern u8 CHECKPOINT_ENTRANCE_ID;
	extern u8 RETURN_STATE;
	extern u8 PREV_RETURN_STATE;
	
	extern bool CAMERA_SAVED_LOOK_AT_RELATED;
	extern u8 CAMERA_PRESS_STATE[4];
	extern u8 ZOOM_CAMERA_BUTTON_ACTIVE_TIMER;
	extern u8 NUM_PLAYERS;
	extern u8 NUM_PLAYERS_2;
	extern bool PLAYER_TALKING;                // if true, input is used for scrolling / ending the text
	extern bool WATERFALL_SOUNDS_DISABLED;
	extern Fog* ENDLESS_STAIRS_FOG_PTR;
	extern s8 ENDLESS_STAIRS_FOG_AREA_ID;
	extern u8 LIFE_STAR_COUNTER_STATE;
	extern bool BACKLIGHT_ENABLED;
	extern bool START_INTRO_MINIMAP_ZOOM;
	extern bool INTRO_MINIMAP_ZOOMING;
	extern bool DISPLAY_RED_COINS_MINIMAP;
	extern bool BUZZER_SOUND_JUST_PLAYED;
	
	// used in pause / level clear / vs exit screens
	extern u8 GAME_PAUSED; // 0 = not paused, 1 = paused, 2 = unpausing
	extern bool PAUSED_WITH_SELECT;
	extern bool PAUSED_DURING_TIMER;
	extern u8 PAUSE_MENU_ID;
	extern u8 PAUSE_LEVEL_CLEAR_SAVE_MENU_ACTIVE;
	extern u8 LEVEL_CLEAR_SCREEN_STATE;
	extern u8 NUM_BIG_BUTTONS;
	extern u8 SELECTED_BUTTON;
	extern u16 BG1_BUTTON_TILE_OFFSETS[4];
	extern u8 PAUSE_MENU_TIMER;
	extern u8 MENU_CHANGE_TIMER;
	extern bool NEW_COIN_HIGH_SCORE;
	extern u8 LEVEL_CLEAR_COIN_COUNT;
	extern bool STOP_MUSIC_DURING_FADE;
	extern u8 SAVE_MENU_TIMER;
	extern u8 LEVEL_CLEAR_TIMER;
	extern u8 MENU_DISPLAYED_COURSE;
	extern u8 COURSE_ARROW_BUTTONS_INVISIBLE;
	extern u8 ARROW_TIMER;
	extern bool BACK_BUTTON_PRESSED;
	extern bool BACK_BUTTON_PRESSED_2;
	extern u8 SELECTED_ARROW;
	extern u8 BACKLIGHT_OPTION_TIMER;
	extern u8 TIMER_0209f23c;
	extern u8 NEXT_PAUSE_MENU_ID;
	extern u8 SELECTED_CONTROLLER_MODE;
	extern u8 SOUND_MODE_TIMER;
	extern u8 SELECTED_BUTTON_SMALL;
	extern u8 SOUND_OPTION;
	extern bool BACKLIGHT_OFF;
	extern bool OPTIONS_MENU_OPENED;
	
	extern u32 FRAME_TIMER;
	extern u16 STAGE_TIMER;
	extern s32 GAME_SPEED_RELATED;
	extern u8 CURRENT_GAMEMODE;                // 0 = adventure, 1 = VS, 2 = ending
	extern bool GAME_FROZEN;
	extern u32 ACTOR_UPDATE_FLAGS;
	extern u32 NEXT_ACTOR_UPDATE_FLAGS;
	
	extern u8 CURR_PLAYER_ID;
	extern u8 DP_STATE;                        // state of dp? 0: no dp, 1: searching for players, 6: connection error(?)
	extern bool CONNECTION_ERROR;              // game softlocks if true
	extern u8 NUM_VS_STARS_COLLECTED;          // not counting the stars that have been lost
	extern u8* VS_STAR_SPAWN_ORDER;            // points to the current order to spawn the VS stars in
	extern u8 VS_STAR_SPAWN_ORDERS[6][12];
	extern u8 NUM_VS_STARS_OBTAINED_PLAYER[4]; // how many stars each player currently has
	extern bool VS_TIME_UP;                    // displays "times up" and the times up menu if true
	extern u16 VS_MODE_TIMER_TIMER;
	extern u8 VS_MODE_EXIT_STATE;
	extern u8 VS_MODE_COUNTDOWN;
	extern u16 VS_MODE_COUNTDOWN_TIMER;
	extern u16 VS_NEW_STAR_TIMER;
	extern bool VS_NEW_STAR_SOUND_PLAYED;
	extern bool EXIT_COURSE_VS_MODE;
	
	// this is the player id of the player that activated the pause menu (I think), always 0 in single player
	constexpr u32 DAT_020a0e40 = 0;
	
	extern ActorBase* ROOT_ACTOR_BASE;
	extern ActorBase::ProcessingListNode* FIRST_BEHAVIOR_LIST_NODE;
	extern ActorBase::ProcessingListNode* FIRST_RENDER_LIST_NODE;
	
	extern bool DAT_0209cef0; // set to false in CleanCommonModelDataArr, set to true in Stage::InitResources
	extern bool DAT_02092778; // no stars besides the first one spawn in VS mode if this is false before starting
	
	// used in DebugLevelSelect
	extern u8 DAT_0209f1d0;
	extern u8 DAT_0209f1d1;
	extern u32 SELECTED_LINE;
	extern s32 LINE_SCROLL_POSITION;
	
	extern char font_2D_ncg_bin[0x2000];
	extern char font_2D_ncl_bin[0x200];
	extern char debug_level_select_arrow_ncg_bin[0x2000];
	extern char build_time_file[0x20];
	
	bool IsButtonInputValid();
	
	s16 GetAngleToCamera(u32 playerID = 0);
	
	s8 SublevelToLevel(s8 levelID);
	s8 GetLevelPart(s8 levelID);
	u8 NumStars();
	
	void LoadKeyModels(u32 keyID);
	void UnloadKeyModels(u32 keyID);
	void UnloadBlueCoinModel();
	void LoadBlueCoinModel();
	void UnloadSilverStarAndNumber();
	void LoadSilverStarAndNumber();
	void LinkSilverStarAndStarMarker(Actor* starMarker, Actor* silverStar);
	
	s16 ReadUnalignedShort(const char* from);
	u16 ReadUnalignedUshort(const char* from);
	s32 ReadUnalignedInt(const char* from);
	
	bool IsPlayerWarping(u8 playerID);
	void WarpPlayer(u8 playerID, u8 warpDest);
	
	u32 GetSceneOverlayID(u32 actorID);
	bool IsMinigameActorID(u32 actorID);
	
	u8 GetSoundMode();
	void SetSoundMode(u8 newSoundMode);
	void TurnBacklightOn();
	void TurnBacklightOff();
	void SetNumPlayers(u32 numPlayers);
	u8 GetControllerMode(s32 playerID);
	
	void UpdateMinimap(Matrix2x2& bgMat, s32 centerX, s32 centerY, s32 x1, s32 y1);
	
	void StartEntranceFaderWipe(s32 wipeID);
	void StartExitCharacterWipe();
	void StartExitFaderWipe(s32 wipeID);
	void FUN_02029934();
	void FUN_02029980();
	void FUN_020299f4();
	void FUN_02029a68();
	void FUN_02029ab0();
	void EnterBigBoosHaunt();
	void KillPlayer();
	void HitDeathPlane(u8 returnState);
	void ExitLevel();
	void SetNextLevel(u8 returnState);
	void SetNextStar();
	void FUN_0202a130();
	s8 NumVsStarsObtained();
	void GiveVsStars(s32 playerID, s8 amount);
	void ClearSpikeBomb(s32 spikeBombID);
	s32 AddSpikeBomb(Actor* spikeBomb);
	void SetStarMarker(s32 id, Actor* starMarker, u8 type);
	
	void OpenCannon(s8 courseID);
	bool IsCannonOpen(s8 courseID);
	void OpenCannonInLevel(s8 levelID);
	bool IsCannonOpenInLevel(s8 levelID);
	void OpenCannonInCurLevel();
	bool IsCannonOpenInCurLevel();
	
	void CollectStar(s8 courseID, s32 starID);
	bool IsStarCollected(s8 courseID, s32 starID);
	void CollectStarInLevel(s8 levelID, s32 starID);
	bool IsStarCollectedInLevel(s8 levelID, s32 starID);
	void CollectStarInCurLevel(s32 starID);
	bool IsStarCollectedInCurLevel(s32 starID);
	
	s8 NumRedCoins();
	void GiveRedCoins(u8 playerID, s8 amount);
	s16 NumCoins();
	void GiveCoins(u8 playerID, s16 amount);
	
	void GiveHealth(u8 playerID, s16 amount);
	
	void InitControllerMode(u8 playerID, u8 newControllerMode);
	void SetControllerMode(u8 newControllerMode);
	
	void HideArea(s8 areaID);
	void ShowArea(s8 areaID);
	bool IsAreaShowing(s8 areaID);
	void ChangeArea(s8 newAreaID);
	
	void GiveLives(s8 amount);
	
	void LoadLevel(s8 levelID, u8 entranceID, s8 starID, u8 returnState, s8 returnEntranceID);
	void LoadLevelNoReturn(s8 levelID, u8 entranceID, s8 starID, u8 returnState);
	
	void SetPlayerGlobals();
	void ExitMinigameMenu();
	void StartMinigameMenu(bool returnToRecRoom);
	void PrepareVsMode();
	void StartFile(s8 levelID, u8 entranceID);
	
	bool StartWithFarCamera();
	u8 GetStarCameraSetting(s32 index);
	
	Fix12i GetMinimapScale(s8 index);
	s8 GetMinimapID(Actor& actor, s32 curMinimapID);
	
	LVL_Overlay::TeleportDestObj& GetTeleportDestObj(s32 index);
	LVL_Overlay::ViewObj& GetViewObj(s32 index);
	
	bool CopyTexPalFromLevelModel(ModelComponents& modelData);
	
	void SetTouchScreenDelay();
	void ResetInput();
	
	bool IsLevelTinyHugeIslandOutside(s8 levelID);
	bool IsLevelInsideCastle(s8 levelID);
	u8 GetSoundGroupID(s8 levelID, s8 starID);
	
	void DeathTable_ClearBit(s8 bit);
	void DeathTable_SetBit(s8 bit);
	u32 DeathTable_GetBit(s8 bit);
	
	u32 GetOwnerLanguage();
	void DecompressLZ16(void* source, void* dest); // source is a pointer to a LZ16 compressed file
	void Deallocate(void* something); // doesn't deallocate something if it's nullptr
	
	void Enable3dEngines(); // swaps buffers first
	void Initialise3dGraphics(s32 clearAlpha);
	void InitialiseVramGlobals();
	void LoadFont(u32 mode); // mode: 0, 1 or 2
	void LoadFont3D();
	void LoadDebugFont();
	void LoadControllerModeText(u16 firstMsgID);
	u32 CountStarsCollectedInLevelToDisplay(u32 courseID);
	
	void SetBg0Offset(s32 x, s32 y);
	void SetBg1Offset(s32 x, s32 y);
	void SetBg2Offset(s32 x, s32 y);
	void SetBg3Offset(s32 x, s32 y);
	void SetSubBg0Offset(s32 x, s32 y);
	void SetSubBg1Offset(s32 x, s32 y);
	void SetSubBg2Offset(s32 x, s32 y);
	void SetSubBg3Offset(s32 x, s32 y);
	
	void InitCrashScreen();
	void ResetCrashScreen();
	void ShowCrashScreen();
}

#include "Save.h"