/* leftover from v1
showDebugScreen                                                                   = 0x2014244;
OS_GetInitArenaLo                                                                 = 0x2058D80;
Player_PlaySoundEffect                                                            = 0x02011E28;
AreCannonsActivatedForCurrentLevel                                                = 0x0202A694;
SetCannonsToActivatedForCurrentLevel                                              = 0x0202A67C;
Player_WasLastAction                                                              = 0x020BEECC;
Player_DoesStateEqual                                                             = 0x020E308C;
OBJ_UpdateObjectXYZSpeedBasedOnForwardSpeedAndDirection                           = 0x02010C5C;
ObjectMessageIDToActualMessageID                                                  = 0x0201FC10;  */

/* nowhere

MultiStoreHalf                                                                    = 0x0205A448; MIi_CpuClear16
MultiCopyHalf                                                                     = 0x0205A460; MIi_CpuCopy16
MultiStore32Bytes                                                                 = 0x0205A4A8; MIi_CpuClearFast
MultiCopy32Bytes                                                                  = 0x0205A4F4; MIi_CpuCopyFast
Copy32Bytes                                                                       = 0x0205A52C; MI_Copy32B
Copy36Bytes                                                                       = 0x0205A548; MI_Copy36B
Copy48Bytes                                                                       = 0x0205A564; MI_Copy48B
Copy48BytesFixed                                                                  = 0x02056C1C; GX_SendFifo48B
Geometry_WriteFogTable                                                            = 0x0202B6F0; this is NOT the start of a function!!!
Geometry_MatrixMultiply3x3                                                        = 0x0205536C; G3_MultMtx33
Vram::Map                                                                         = 0x02054C80; GX_VRAMCNT_SetLCDC_

RENDER_DMA_CHANNEL                                                                = 0x02099FD0; GXi_DmaId

ACTOR_PARAM1                                                                      = 0x020A4B60;
ACTOR_ACTOR_ID                                                                    = 0x020A4B54;
ACTOR_UNKNOWN12_ID                                                                = 0x020A4B48;
ACTOR_SPAWN_INFO_TABLE_PTR                                                        = 0x020A4BB8;  */

/* new, new[] */
_Znwj                                                                             = 0x0203CC0C; /* thunk at 0x0203cbe4 */
_Znaj                                                                             = 0x0203CC0C; /* thunk at 0x0203cbe4 */

/* delete, delete[], delete(u32)? */
_ZdlPv                                                                            = 0x0203CBF0; /* thunk at 0x0203cbcc */
_ZdaPv                                                                            = 0x0203CBF0; /* thunk at 0x0203cbcc */
_ZdlPvj                                                                           = 0x0203CBF0; /* thunk at 0x0203cbcc */
_ZdaPvj                                                                           = 0x0203CBF0; /* thunk at 0x0203cbcc */

/* integer division */
__aeabi_idiv                                                                      = 0x01ffabe4;
__aeabi_idivmod                                                                   = 0x01ffabe4;
__aeabi_uidiv                                                                     = 0x01ffadf0;
__aeabi_uidivmod                                                                  = 0x01ffadf0;
__aeabi_uldiv                                                                     = 0x01ffa9dc;
__aeabi_ulmod                                                                     = 0x01ffa9e8;
__aeabi_uldivmod                                                                  = 0x01ffe684;

/* SM64DS_Common.h */
_ZN4cstd3divEii                                                                   = 0x02052f4c;
_ZN4cstd3modEii                                                                   = 0x02052ef4;
_ZN4cstd4fdivEii                                                                  = 0x02053258;
_ZN4cstd4ldivEii                                                                  = 0x0205321c;

nds_print                                                                         = 0x02014770;
nds_printf                                                                        = 0x0201470c;
nds_printt                                                                        = 0x02014620;
DecIfAbove0_Short                                                                 = 0x0203adbc;
DecIfAbove0_Byte                                                                  = 0x0203add4;
MultiStore16                                                                      = 0x0205a448;

_Z14ApproachLinearRsss                                                            = 0x0203adec;
_Z14ApproachLinearRiii                                                            = 0x0203ae58;
_Z15ApproachLinear2Rsss                                                           = 0x0203aed8;
_Z15ApproachLinear2Riii                                                           = 0x0203af34;

_Z11UpdateAngleRssis                                                              = 0x0203af90;

_ZN4cstd4fdivE5Fix12IiES1_                                                        = 0x02053258;
_ZN4cstd4finvEi                                                                   = 0x02008c34;
_ZN4cstd4sqrtEy                                                                   = 0x0203D744;

_ZN4cstd5atan2E5Fix12IiES1_                                                       = 0x0203B4DC;
_ZN4cstd3absEi                                                                    = 0x0206DF84;

_ZN4cstd6strcmpEPKcS1_                                                            = 0x02070508;
_ZN4cstd7strncpyEPcPKcj                                                           = 0x0207063C;
_ZN4cstd6strchrEPKcc                                                              = 0x020704CC;
_ZN4cstd6strlenEPKc                                                               = 0x02070788;

_Z14ApproachLinearR7Vector3RKS_5Fix12IiE                                          = 0x0203b89c;

POWERS_OF_TEN                                                                     = 0x0208ee64;
DIGIT_ENC_ARR                                                                     = 0x0208ee74;

UNUSED_RAM                                                                        = 0x023C4000;

RNG_STATE                                                                         = 0x0209e650;

MATRIX_SCRATCH_PAPER                                                              = 0x020a0e68;
FRAME_COUNTER                                                                     = 0x020a1040;

SINE_TABLE                                                                        = 0x02082214;
ATAN_TABLE                                                                        = 0x020994E0;

UnloadOverlay                                                                     = 0x02017f34;
LoadOverlay                                                                       = 0x02018028;
LoadFile                                                                          = 0x0201816c;
LoadFileAt                                                                        = 0x020182ac;
LoadCompressedFileAt                                                              = 0x02018100;
LoadTextNarcs                                                                     = 0x020187f4;
LoadArchive                                                                       = 0x020188a8;
UnloadArchive                                                                     = 0x02018864;
UnloadArchives                                                                    = 0x020187b0;

Crash                                                                             = 0x02019740;

ApproachAngle                                                                     = 0x0203B008;
AngleDiff                                                                         = 0x0203b0e8;
Vec3_RotateYAndTranslate                                                          = 0x0203b6a4;
Vec3_VertAngle                                                                    = 0x0203b770;
Vec3_HorzAngle                                                                    = 0x0203b7ac;
Vec3_ApproachHorz                                                                 = 0x0203b7dc;
RandomIntInternal                                                                 = 0x0203b990;
Matrix3x3_FromQuaternion                                                          = 0x020301e8;
Matrix4x3_FromTranslation                                                         = 0x0203bf44;
Matrix4x3_FromRotationZ                                                           = 0x0203bd28;
Matrix4x3_FromRotationY                                                           = 0x0203bd6c;
Matrix4x3_FromRotationX                                                           = 0x0203bdb0;
Matrix4x3_FromRotationZXYExt                                                      = 0x0203bdf4;
Matrix4x3_FromRotationXYZExt                                                      = 0x0203be9c;
Matrix4x3_FromQuaternion                                                          = 0x020301c4;
Matrix4x3_ApplyInPlaceToRotationZ                                                 = 0x0203bf90;
Matrix4x3_ApplyInPlaceToRotationY                                                 = 0x0203bfc0;
Matrix4x3_ApplyInPlaceToRotationX                                                 = 0x0203bff0;
Matrix4x3_ApplyInPlaceToRotationZXYExt                                            = 0x0203c020;
Matrix4x3_ApplyInPlaceToRotationXYZExt                                            = 0x0203c0b4;
Matrix4x3_ApplyInPlaceToTranslation                                               = 0x0203c184;
Matrix4x3_ApplyInPlaceToScale                                                     = 0x0203c148;

Quaternion_FromVector3                                                            = 0x0202fd4c;
Quaternion_Normalize                                                              = 0x02030450;
Quaternion_SLerp                                                                  = 0x0202fef8;

Vec3_HorzDist                                                                     = 0x0203cf40;
Vec3_HorzLen                                                                      = 0x0203cf78;
Vec3_Dist                                                                         = 0x0203cfdc;
Vec3_Equal                                                                        = 0x0203d064;
Vec3_LslInPlace                                                                   = 0x0203d0a0;
Vec3_Lsl                                                                          = 0x0203d0d0;
Vec3_AsrInPlace                                                                   = 0x0203d108;
Vec3_Asr                                                                          = 0x0203d138;
Vec3_DivScalarInPlace                                                             = 0x0203d170;
Vec3_MulScalarInPlace                                                             = 0x0203d224;
Vec3_MulScalar                                                                    = 0x0203d290;
Vec3_Sub                                                                          = 0x0203d2fc;
Vec3_Add                                                                          = 0x0203d340;

Matrix3x3_LoadIdentity                                                            = 0x020524f0;
MulVec3Mat3x3                                                                     = 0x020525a0;
MulMat3x3Mat3x3                                                                   = 0x02052624;
Matrix4x3_LoadIdentity                                                            = 0x020527c0;
Matrix4x3_FromScale                                                               = 0x020527e9; /* gcc fails to generate a blx instruction to call this; so it's one off. */
MulVec3Mat4x3                                                                     = 0x02052858;
MulMat4x3Mat4x3                                                                   = 0x02052914;
InvMat4x3                                                                         = 0x02052b34;
NormalizeVec3                                                                     = 0x020534ec;
NormalizeVec3IfNonZero                                                            = 0x0203ce2c;
CrossVec3                                                                         = 0x02053770;
AddVec3                                                                           = 0x02053884;
SubVec3                                                                           = 0x02053850;
LenVec3                                                                           = 0x020536e4;
DotVec3                                                                           = 0x0205380c;

Matrix3x3_SetRotationX                                                            = 0x02052551;
Matrix3x3_SetRotationY                                                            = 0x0205256D;
Matrix3x3_SetRotationZ                                                            = 0x02052588;

MultiStore_Int                                                                    = 0x0205a47c;
MultiCopy_Int                                                                     = 0x0205a490;

Color_Interp                                                                      = 0x020e6a08;

Math_Function_0203b14c                                                            = 0x0203b14c;
Math_Function_0203b0fc                                                            = 0x0203b0fc;

_ZN7Vector38IDENTITYE                                                             = 0x020a0ebc;
_ZN9Matrix3x38IDENTITYE                                                           = 0x02082128;
_ZN9Matrix4x38IDENTITYE                                                           = 0x02082128;

/* SharedFilePtr.h */
_ZN13SharedFilePtr9ConstructEj                                                    = 0x0201799c;
_ZN13SharedFilePtr7ReleaseEv                                                      = 0x02017b64;
_ZN13SharedFilePtr4LoadEv                                                         = 0x02017c54;
_ZN13SharedFilePtr8LoadFileEv                                                     = 0x02017bc4;
_ZN13SharedFilePtr19ReallocateModelFileEv                                         = 0x02017a8c;

LUIGI_CAP_MODEL_PTR                                                               = 0x0210d9a0;
RED_NUMBER_MODEL_PTR                                                              = 0x0210d9a8;
POWER_FLOWER_OPEN_MODEL_PTR                                                       = 0x0210d9b0;
COIN_YELLOW_POLY32_MODEL_PTR                                                      = 0x0210d9b8;
WARIO_CAP_MODEL_PTR                                                               = 0x0210d9c0;
COIN_BLUE_POLY32_MODEL_PTR                                                        = 0x0210d9c8;
POWER_FLOWER_CLOSED_MODEL_PTR                                                     = 0x0210d9d0;
ONE_UP_MUSHROOM_MODEL_PTR                                                         = 0x0210d9d8;
BOB_OMB_MODEL_PTR                                                                 = 0x0210d9e0;
NUMBER_TEXSEQ_PTR                                                                 = 0x0210d9e8;
SNUFIT_BULLET_MODEL_PTR                                                           = 0x0210d9f0;
COIN_RED_POLY32_MODEL_PTR                                                         = 0x0210d9f8;
COIN_BLUE_POLY4_MODEL_PTR                                                         = 0x0210da00;
SILVER_NUMBER_TEXSEQ_PTR                                                          = 0x0210da08;
WATER_RING_MODEL_PTR                                                              = 0x0210da10;
SHELL_MODEL_PTRS                                                                  = 0x0210da18;
SILVER_NUMBER_MODEL_PTR                                                           = 0x0210da28;
SUPER_MUSHROOM_MODEL_PTR                                                          = 0x0210da30;
BUBBLE_MODEL_PTR                                                                  = 0x0210da38;
MARIO_CAP_MODEL_PTR                                                               = 0x0210da40;
COIN_YELLOW_POLY4_MODEL_PTR                                                       = 0x0210da48;
COIN_RED_POLY4_MODEL_PTR                                                          = 0x0210da50;
FEATHER_MODEL_PTR                                                                 = 0x0210da58;
YOSHI_EGG_MODEL_PTR                                                               = 0x0210e7d8;
YOSHI_CUBE_EGG_MODEL_PTR                                                          = 0x0210e3a0;
POWER_STAR_MODEL_PTR                                                              = 0x0211094c;
TRANSPARENT_STAR_MODEL_PTR                                                        = 0x0211095c;

COIN_POLY4_MODEL_PTRS                                                             = 0x020ff060;
COIN_POLY32_MODEL_PTRS                                                            = 0x020ff06c;

BOWSER_KEY_MODEL_PTR                                                              = 0x02132c50;
KEY_MODEL_PTRS                                                                    = 0x02132894;

DOOR_OPEN_ANIM_PTR                                                                = 0x02148744;
REGULAR_DOOR_MODEL_PTR                                                            = 0x0214875c;
REGULAR_DOOR_1_MODEL_PTR                                                          = 0x02148774;
OLD_WOOD_DOOR_MODEL_PTR                                                           = 0x0214876c;
RUSTED_METAL_DOOR_MODEL_PTR                                                       = 0x0214874c;
HMC_STONE_DOOR_MODEL_PTR                                                          = 0x02148754;
BBH_HAUNTED_DOOR_MODEL_PTR                                                        = 0x02148734;
DOOR_STAR_0_MODEL_PTR                                                             = 0x0214873c;
DOOR_STAR_1_MODEL_PTR                                                             = 0x02148724;
DOOR_STAR_3_MODEL_PTR                                                             = 0x0214872c;
DOOR_STAR_8_MODEL_PTR                                                             = 0x02148764;
DOOR_KEY_HOLE_MODEL_PTR                                                           = 0x0214877c;

STAR_DOOR_MODEL_PTR                                                               = 0x02148934;

/* SM64DS_2.h */
OBJ_TO_ACTOR_ID_TABLE                                                             = 0x02004b00;
ACTOR_SPAWN_TABLE                                                                 = 0x02006590;

_ZN5Event8ClearBitEj                                                              = 0x02029ea4;
_ZN5Event6SetBitEj                                                                = 0x02029ec4;
_ZN5Event6GetBitEj                                                                = 0x02029ee0;

_ZN5Timer10ResetTimerEv                                                           = 0x02019638;
_ZN5Timer10StartTimerEv                                                           = 0x02019604;
_ZN5Timer9StopTimerEv                                                             = 0x020195c0;
_ZN5Timer7GetTimeEv                                                               = 0x02019584;

TIME_TIMER                                                                        = 0x0209d4c8;
DISPLAY_TIMER                                                                     = 0x02111184;

DL_PTR_ARR_PTR                                                                    = 0x02004ffc;

LEVEL_PART_TABLE                                                                  = 0x02075264;
SUBLEVEL_LEVEL_TABLE                                                              = 0x02075298;

ACTOR_BANK_OVL_MAP                                                                = 0x02075804;
LEVEL_OVL_MAP                                                                     = 0x020758c8;

MSG_GEN_TEXT_FUNCS                                                                = 0x0208ee80;

ACTOR_BANK_SETTINGS                                                               = 0x020922a4;

CAM_SPACE_CAM_POS_ASR_3                                                           = 0x02086ef0;

ARCHIVE_INFOS                                                                     = 0x0208ecf4;

PROCESS_STATE                                                                     = 0x02099f24;
BASE_CREATION_STATE                                                               = 0x020a4b4c;
CURRENT_OBJECT_SPAWN_ID                                                           = 0x020a4b50;
CURRENT_OBJECT_LIST_NODE                                                          = 0x020a4b68;
NEXT_UNIQUE_ACTOR_ID                                                              = 0x02099e70;
LAST_USED_FILE_ID                                                                 = 0x0209d3bc;
SAVED_REGISTER_VALUES                                                             = 0x0209cddc;

VIEW_MATRIX_ASR_3                                                                 = 0x0209b3ec;
INV_VIEW_MATRIX_ASR_3                                                             = 0x0209b41c;
ROT_AT_SPAWN                                                                      = 0x0209b45c;
POS_AT_SPAWN                                                                      = 0x0209b460;
FIRST_ACTOR_LIST_NODE                                                             = 0x0209b468;

IMMUNE_TO_DAMAGE                                                                  = 0x0209f0d8;

LOADED_LEVEL_OVL_ID                                                               = 0x02092130;
LEVEL_SPECIFIC_SETTING                                                            = 0x0209f2c0;
AREA_ID                                                                           = 0x02092120;
LEVEL_ID                                                                          = 0x0209f2f8;
NEXT_LEVEL_ID                                                                     = 0x02092110;
CHECKPOINT_LEVEL_ID                                                               = 0x02092118;
RETURN_LEVEL_ID                                                                   = 0x0209211c;
LEVEL_OF_LAST_COLLECTED_STAR                                                      = 0x02092124;
STAR_ID                                                                           = 0x0209f220;
NEXT_STAR_ID                                                                      = 0x0209f1f0;
CHECKPOINT_STAR_ID                                                                = 0x0209f270;
NEW_STAR_COLLECTED                                                                = 0x0209f2ac;
CUR_MINIMAP_ID                                                                    = 0x02111148;
STAR_OBTAINED                                                                     = 0x0209f228;
STAR_OBTAINED_COPY                                                                = 0x0209f224;
RETURN_TO_REC_ROOM                                                                = 0x0209f298;

AREAS                                                                             = 0x0209f314;
CAMERA                                                                            = 0x0209f318;
WIPES                                                                             = 0x0209f324;
STAR_MARKERS                                                                      = 0x0209f40c;
STAR_MARKER_TYPES                                                                 = 0x0209f37c;
CASTLE_KEY_RABBIT                                                                 = 0x0209f33c;
BOWSER_SPIKE_BOMBS                                                                = 0x0209f3a4;

WATER_HEIGHT                                                                      = 0x0209f32c;
STAR_CAP_MAX_POS_Y                                                                = 0x0209212c;
STAR_CAP_MIN_POS_Y                                                                = 0x02092138;
EVENT_FIELD                                                                       = 0x0209f34c;
NEXT_DEATH_TABLE_ID                                                               = 0x0211118c;
ACTOR_DEATH_TABLE_ARR                                                             = 0x0209f4f8;

PLAYER_ARR                                                                        = 0x0209f394;
IS_PLAYER_ACTIVE                                                                  = 0x0209fc5c;
NEXT_HAT_CHARACTER_ARR                                                            = 0x02092128;
NUM_COINS                                                                         = 0x0209f358;
NUM_RED_COINS                                                                     = 0x0209f30c;
HEALTH_ARR                                                                        = 0x02092144;
NUM_LIVES                                                                         = 0x0209f2f4;
RENDERED_HEALTH                                                                   = 0x0211117c;

NEXT_HAT_CHARACTER                                                                = 0x02092114;
UNK_YOSHI_EGG_RELATED                                                             = 0x0209f254;
LAST_ENTRANCE_ID                                                                  = 0x0209f264;
NEXT_ENTRANCE_ID                                                                  = 0x0209f268;
RETURN_ENTRANCE_ID                                                                = 0x0209f200;
CHECKPOINT_ENTRANCE_ID                                                            = 0x0209f24c;
RETURN_STATE                                                                      = 0x0209f26c;
PREV_RETURN_STATE                                                                 = 0x0209f2fc;

CAMERA_SAVED_LOOK_AT_RELATED                                                      = 0x0209f274;
CAMERA_PRESS_STATE                                                                = 0x0209f350;
ZOOM_CAMERA_BUTTON_ACTIVE_TIMER                                                   = 0x02111180;
NUM_PLAYERS                                                                       = 0x0209f21c;
NUM_PLAYERS_2                                                                     = 0x0209fc50;
PLAYER_TALKING                                                                    = 0x0209d660;
WATERFALL_SOUNDS_DISABLED                                                         = 0x02110aec;
ENDLESS_STAIRS_FOG_PTR                                                            = 0x02110af8;
ENDLESS_STAIRS_FOG_AREA_ID                                                        = 0x02110af0;
LIFE_STAR_COUNTER_STATE                                                           = 0x02111178;
BACKLIGHT_ENABLED                                                                 = 0x0208ee3c;
START_INTRO_MINIMAP_ZOOM                                                          = 0x02111144;
INTRO_MINIMAP_ZOOMING                                                             = 0x0211114c;
DISPLAY_RED_COINS_MINIMAP                                                         = 0x0209f288;
BUZZER_SOUND_JUST_PLAYED                                                          = 0x0209f27c;

GAME_PAUSED                                                                       = 0x0209f2c4;
PAUSED_WITH_SELECT                                                                = 0x0209f218;
PAUSED_DURING_TIMER                                                               = 0x0209f2a0;
PAUSE_MENU_ID                                                                     = 0x0209f248;
PAUSE_LEVEL_CLEAR_SAVE_MENU_ACTIVE                                                = 0x0209f20c;
LEVEL_CLEAR_SCREEN_STATE                                                          = 0x0209f2d4;
NUM_BIG_BUTTONS                                                                   = 0x0209f2b4;
SELECTED_BUTTON                                                                   = 0x0209f2e0;
BG1_BUTTON_TILE_OFFSETS                                                           = 0x0209f360;
PAUSE_MENU_TIMER                                                                  = 0x0209f22c;
MENU_CHANGE_TIMER                                                                 = 0x0209f244;
NEW_COIN_HIGH_SCORE                                                               = 0x0209f2b0;
LEVEL_CLEAR_COIN_COUNT                                                            = 0x0209f260;
STOP_MUSIC_DURING_FADE                                                            = 0x0209f280;
SAVE_MENU_TIMER                                                                   = 0x0209f2b8;
LEVEL_CLEAR_TIMER                                                                 = 0x0209f2a8;
MENU_DISPLAYED_COURSE                                                             = 0x0209f2c8;
COURSE_ARROW_BUTTONS_INVISIBLE                                                    = 0x0209f2f0;
ARROW_TIMER                                                                       = 0x0209f210;
BACK_BUTTON_PRESSED                                                               = 0x0209f29c;
BACK_BUTTON_PRESSED_2                                                             = 0x0209f240;
SELECTED_ARROW                                                                    = 0x0209f238;
BACKLIGHT_OPTION_TIMER                                                            = 0x0209f2cc;
TIMER_0209f23c                                                                    = 0x0209f23c;
NEXT_PAUSE_MENU_ID                                                                = 0x0209f1ec;
SELECTED_CONTROLLER_MODE                                                          = 0x0209f2dc;
SOUND_MODE_TIMER                                                                  = 0x0209f2e4;
SELECTED_BUTTON_SMALL                                                             = 0x0209f2a4;
SOUND_OPTION                                                                      = 0x0209f234;
BACKLIGHT_OFF                                                                     = 0x0209f2ec;
OPTIONS_MENU_OPENED                                                               = 0x0209f1fc;

FRAME_TIMER                                                                       = 0x020a0db0;
STAGE_TIMER                                                                       = 0x0209f300;
GAME_SPEED_RELATED                                                                = 0x0208ee44;
CURRENT_GAMEMODE                                                                  = 0x0209f2d8;
GAME_FROZEN                                                                       = 0x0209f294;
ACTOR_UPDATE_FLAGS                                                                = 0x0209b464;
NEXT_ACTOR_UPDATE_FLAGS                                                           = 0x0209b454;

CURR_PLAYER_ID                                                                    = 0x0209f250;
DP_STATE                                                                          = 0x0209fc68;
CONNECTION_ERROR                                                                  = 0x0209fc9c;
NUM_VS_STARS_COLLECTED                                                            = 0x0209f208;
VS_STAR_SPAWN_ORDER                                                               = 0x0209f344;
VS_STAR_SPAWN_ORDERS                                                              = 0x02075720;
NUM_VS_STARS_OBTAINED_PLAYER                                                      = 0x0209f310;
VS_TIME_UP                                                                        = 0x0209f204;
VS_MODE_TIMER_TIMER                                                               = 0x02111188;
VS_MODE_EXIT_STATE                                                                = 0x0209f290;
VS_MODE_COUNTDOWN                                                                 = 0x0209f2bc;
VS_MODE_COUNTDOWN_TIMER                                                           = 0x0209f304;
VS_NEW_STAR_TIMER                                                                 = 0x0209f308;
VS_NEW_STAR_SOUND_PLAYED                                                          = 0x0209f1f4;
EXIT_COURSE_VS_MODE                                                               = 0x02111150;

ROOT_ACTOR_BASE                                                                   = 0x0209f5c0;
FIRST_BEHAVIOR_LIST_NODE                                                          = 0x020a4b78;
FIRST_RENDER_LIST_NODE                                                            = 0x020a4b98;

DAT_0209cef0                                                                      = 0x0209cef0;
DAT_02092778                                                                      = 0x02092778;

DAT_0209f1d0                                                                      = 0x0209f1d0;
DAT_0209f1d1                                                                      = 0x0209f1d1;
SELECTED_LINE                                                                     = 0x0209b2f4;
LINE_SCROLL_POSITION                                                              = 0x0209b2f8;

font_2D_ncg_bin                                                                   = 0x0208a178;
font_2D_ncl_bin                                                                   = 0x0208c178;
debug_level_select_arrow_ncg_bin                                                  = 0x0208c378;
build_time_file                                                                   = 0x020a0d90;

IsButtonInputValid                                                                = 0x02029654;

GetAngleToCamera                                                                  = 0x0203db24;

SublevelToLevel                                                                   = 0x02013558;
GetLevelPart                                                                      = 0x02013548;
NumStars                                                                          = 0x0201367c;

LoadKeyModels                                                                     = 0x02131114;
UnloadKeyModels                                                                   = 0x021310cc;
UnloadBlueCoinModel                                                               = 0x0200fe70;
LoadBlueCoinModel                                                                 = 0x0200fe9c;
UnloadSilverStarAndNumber                                                         = 0x020e717c;
LoadSilverStarAndNumber                                                           = 0x020e71a8;
LinkSilverStarAndStarMarker                                                       = 0x020e71d4;

ReadUnalignedShort                                                                = 0x0200e768;
ReadUnalignedUshort                                                               = 0x0200e780;
ReadUnalignedInt                                                                  = 0x0200e748;

IsPlayerWarping                                                                   = 0x02020414;
WarpPlayer                                                                        = 0x020203c4;

GetSceneOverlayID                                                                 = 0x0201a7dc;
IsMinigameActorID                                                                 = 0x0201a888;

GetSoundMode                                                                      = 0x02019574;
SetSoundMode                                                                      = 0x02019510;
TurnBacklightOn                                                                   = 0x02019698;
TurnBacklightOff                                                                  = 0x02019664;
SetNumPlayers                                                                     = 0x0200f450;
GetControllerMode                                                                 = 0x02020054;

UpdateMinimap                                                                     = 0x02029854;

StartEntranceFaderWipe                                                            = 0x020298a0;
StartExitCharacterWipe                                                            = 0x020298d8;
StartExitFaderWipe                                                                = 0x020298fc;
FUN_02029934                                                                      = 0x02029934;
FUN_02029980                                                                      = 0x02029980;
FUN_020299f4                                                                      = 0x020299f4;
FUN_02029a68                                                                      = 0x02029a68;
FUN_02029ab0                                                                      = 0x02029ab0;
EnterBigBoosHaunt                                                                 = 0x02029b04;
KillPlayer                                                                        = 0x02029b30;
HitDeathPlane                                                                     = 0x02029b84;
ExitLevel                                                                         = 0x02029bd4;
SetNextLevel                                                                      = 0x02029bf4;
SetNextStar                                                                       = 0x02029d1c;
FUN_0202a130                                                                      = 0x0202a130;
NumVsStarsObtained                                                                = 0x0202a55c;
GiveVsStars                                                                       = 0x0202a5ac;
ClearSpikeBomb                                                                    = 0x0202a608;
AddSpikeBomb                                                                      = 0x0202a628;
SetStarMarker                                                                     = 0x0202a660;

OpenCannon                                                                        = 0x02013834;
IsCannonOpen                                                                      = 0x02013850;
OpenCannonInLevel                                                                 = 0x020137fc;
IsCannonOpenInLevel                                                               = 0x02013818;
OpenCannonInCurLevel                                                              = 0x0202a67c;
IsCannonOpenInCurLevel                                                            = 0x0202a694;

CollectStar                                                                       = 0x020137a8;
IsStarCollected                                                                   = 0x020137e0;
CollectStarInLevel                                                                = 0x020136dc;
IsStarCollectedInLevel                                                            = 0x020136f8;
CollectStarInCurLevel                                                             = 0x0202a6ac;
IsStarCollectedInCurLevel                                                         = 0x0202a6c8;

NumRedCoins                                                                       = 0x0202a6e4;
GiveRedCoins                                                                      = 0x0202a734;
NumCoins                                                                          = 0x0202a770;
GiveCoins                                                                         = 0x0202a7b8;

GiveHealth                                                                        = 0x0202a814;

InitControllerMode                                                                = 0x0202a87c;
SetControllerMode                                                                 = 0x0202a8b0;

HideArea                                                                          = 0x0202aa2c;
ShowArea                                                                          = 0x0202aa4c;
IsAreaShowing                                                                     = 0x0202aa6c;
ChangeArea                                                                        = 0x0202aa88;

GiveLives                                                                         = 0x0202aac0;

LoadLevel                                                                         = 0x0202aaec;
LoadLevelNoReturn                                                                 = 0x0202acc0;

SetPlayerGlobals                                                                  = 0x0202acfc;
ExitMinigameMenu                                                                  = 0x0202ad78;
StartMinigameMenu                                                                 = 0x0202adf4;
PrepareVsMode                                                                     = 0x0202ae2c;
StartFile                                                                         = 0x0202ae88;

StartWithFarCamera                                                                = 0x0202af08;
GetStarCameraSetting                                                              = 0x0202af28;

GetMinimapScale                                                                   = 0x0202af48;
GetMinimapID                                                                      = 0x0202af9c;

GetTeleportDestObj                                                                = 0x0202b07c;
GetViewObj                                                                        = 0x0202b0ac;

CopyTexPalFromLevelModel                                                          = 0x0202b3d8;

SetTouchScreenDelay                                                               = 0x0202c8b8;
ResetInput                                                                        = 0x0202c8f8;

IsLevelTinyHugeIslandOutside                                                      = 0x0202ddd4;
IsLevelInsideCastle                                                               = 0x0202ddf4;
GetSoundGroupID                                                                   = 0x0202de24;

DeathTable_ClearBit                                                               = 0x02029dbc;
DeathTable_SetBit                                                                 = 0x02029e0c;
DeathTable_GetBit                                                                 = 0x02029e58;

GetOwnerLanguage                                                                  = 0x0203d880;
DecompressLZ16                                                                    = 0x0205a754;
Deallocate                                                                        = 0x02018144;

Enable3dEngines                                                                   = 0x02019070;
Initialise3dGraphics                                                              = 0x0200f558;
InitialiseVramGlobals                                                             = 0x02045d20;
LoadFont                                                                          = 0x0201fcd4;
LoadFont3D                                                                        = 0x02034954;
LoadDebugFont                                                                     = 0x0202341c;
LoadControllerModeText                                                            = 0x0201d0f8;
CountStarsCollectedInLevelToDisplay                                               = 0x02013714;

SetBg0Offset                                                                      = 0x02018ffc;
SetBg1Offset                                                                      = 0x02018fe0;
SetBg2Offset                                                                      = 0x02018fc4;
SetBg3Offset                                                                      = 0x02018fa8;
SetSubBg0Offset                                                                   = 0x02018f8c;
SetSubBg1Offset                                                                   = 0x02018f70;
SetSubBg2Offset                                                                   = 0x02018f54;
SetSubBg3Offset                                                                   = 0x02018f38;

InitCrashScreen                                                                   = 0x02014150;
ResetCrashScreen                                                                  = 0x02014214;
ShowCrashScreen                                                                   = 0x02014244;

/* NDSCore.h */
_ZN4CP1510EnableDTCMEv                                                            = 0x020593A8;
_ZN4CP1518GetDTCMBaseAddressEv                                                    = 0x020593B8;
_ZN4CP159EnableMPUEv                                                              = 0x020593CC;
_ZN4CP1510DisableMPUEv                                                            = 0x020593DC;
_ZN4CP1514MPUDataRegion1Ej                                                        = 0x020593EC;
_ZN4CP1514MPUDataRegion7Ej                                                        = 0x0206DAAC;
_ZN4CP1517MPUGetDataRegion7Ev                                                     = 0x0206DAA4;
_ZN4CP1514FlushDataCacheEv                                                        = 0x02058BB0;
_ZN4CP1527FlushAndInvalidateDataCacheEv                                           = 0x02058BDC;
_ZN4CP1514FlushDataCacheEjj                                                       = 0x02058C24;
_ZN4CP1519InvalidateDataCacheEjj                                                  = 0x02058C08;
_ZN4CP1526InvalidateInstructionCacheEjj                                           = 0x02058C68;
_ZN4CP1527FlushAndInvalidateDataCacheEjj                                          = 0x02058C40;
_ZN4CP1516DrainWriteBufferEv                                                      = 0x02058C5C;
_ZN4CP1516WaitForInterruptEv                                                      = 0x02059D80;
_ZN4CP1511SystemSetupEv                                                           = 0x020049F0;

_ZN3IRQ12IRQFunctionsE                                                            = 0x02099FE4;
_ZN3IRQ13DmaTimIndicesE                                                           = 0x02099FD4;
_ZN3IRQ15DmaTimFunctionsE                                                         = 0x020A60C4;
_ZN3IRQ12IRQCheckBitsE                                                            = 0x023C3FF8;
_ZN3IRQ14UserIRQAddressE                                                          = 0x023C3FFC;

_ZN3IRQ7DisableEv                                                                 = 0x02059D1C;
_ZN3IRQ6EnableEv                                                                  = 0x02059D08;
_ZN3IRQ7RestoreEj                                                                 = 0x02059D30;
_ZN3IRQ10DisableAllEv                                                             = 0x02059D48;
_ZN3IRQ10RestoreAllEj                                                             = 0x02059D5C;
_ZN3IRQ11SetIRQStateEb                                                            = 0x0206DA28;
_ZN3IRQ11SetFIQStateEb                                                            = 0x0206D9DC;
_ZN3IRQ15ClearInterruptsEj                                                        = 0x02056D64;
_ZN3IRQ11DisableIRQsEj                                                            = 0x02056D98;
_ZN3IRQ10EnableIRQsEj                                                             = 0x02056DE0;
_ZN3IRQ7SetIRQsEj                                                                 = 0x02056E18;
_ZN3IRQ13GetIRQHandlerEj                                                          = 0x02056EE4;
_ZN3IRQ13SetIRQHandlerEjPFvvE                                                     = 0x02056F70;

_ZN3IRQ13VBlankHandlerEv                                                          = 0x0201A534;
_ZN3IRQ12EmptyHandlerEv                                                           = 0x02056D60;
_ZN3IRQ19Tim0OverflowHandlerEv                                                    = 0x02056C70;
_ZN3IRQ19Tim1OverflowHandlerEv                                                    = 0x02056C60;
_ZN3IRQ19Tim2OverflowHandlerEv                                                    = 0x02056C50;
_ZN3IRQ19Tim3OverflowHandlerEv                                                    = 0x02056C40;
_ZN3IRQ11Dma0HandlerEv                                                            = 0x02056CB0;
_ZN3IRQ11Dma1HandlerEv                                                            = 0x02056CA0;
_ZN3IRQ11Dma2HandlerEv                                                            = 0x02056C90;
_ZN3IRQ11Dma3HandlerEv                                                            = 0x02056C80;
_ZN3IRQ24IPCRxFifoNotEmptyHandlerEv                                               = 0x0205B864;
_ZN3IRQ21GameCardIREQMCHandlerEv                                                  = 0x020610AC;
_ZN3IRQ13DmaTimHandlerEv                                                          = 0x02056CC0;
_ZN3IRQ20UserInterruptHandlerEv                                                   = 0x01FFD97C;

_ZN4cstd10fdiv_asyncE5Fix12IiE5Fix12IiE                                           = 0x02052FA4;
_ZN4cstd11fdiv_resultEv                                                           = 0x020530CC;
_ZN4cstd11ldiv_resultEv                                                           = 0x02053108;
_ZN4cstd16reciprocal_asyncE5Fix12IiE                                              = 0x02053090;

_start                                                                            = 0x02004800;
_ZN4cstd14__builtin_trapEv                                                        = 0x0206DABC;
_ZN4cstd8__assertEPKcPKcPKci                                                      = 0x0206CD44;

ARMProcessorMode                                                                  = 0x02059D74;
ARMSaveContext                                                                    = 0x020585CC;
ARMRestoreContext                                                                 = 0x02058618;

IPCSend                                                                           = 0x0205B988;
OSReadROMArea                                                                     = 0x01FFDBD8;
ROMCTRL_SETTINGS                                                                  = 0x027FFE60;

ARMMathSaveState                                                                  = 0x0205E988;
ARMMathLoadState                                                                  = 0x0205E91C;

DMAStartTransferFB                                                                = 0x01FFDE00;
DMAStartTransfer                                                                  = 0x01FFDE50;

DMASyncWordTransfer                                                               = 0x0205A160;
DMASyncHalfTransfer                                                               = 0x0205A10C;
DMASyncFillTransfer                                                               = 0x0205A1B4;

/* Model.h */
CHANGE_CAP_TOON_COLORS                                                            = 0x02110844;

/* Model/Vram.h */
VRAM_Pal_End                                                                      = 0x020a4bd8;
VRAM_Pal_Start                                                                    = 0x020a4bcc;
VRAM_Tex_Size                                                                     = 0x020a4be4;
VRAM_Tex_End                                                                      = 0x020a4bdc;
VRAM_Tex4x4_IndexData_Start                                                       = 0x020a4be0;
VRAM_Tex4x4_TexelData_Start                                                       = 0x020a4bc8;
VRAM_Tex4x4_MaxSize                                                               = 0x020a4be8;

/* Model/GXFIFO.h */
GXPORT_MATRIX_MODE                                                                = 0x04000440;
GXPORT_MTX_LOAD_4x4                                                               = 0x04000458;
GXPORT_MTX_LOAD_4x3                                                               = 0x0400045c;
GXPORT_LIGHT_VECTOR                                                               = 0x040004c8;
GXPORT_LIGHT_COLOR                                                                = 0x040004cc;

/* Model/Animation.h */
_ZTV9Animation                                                                    = 0x0208E7E4;
_ZN9AnimationC1Ev                                                                 = 0x02015CF8;
_ZN9AnimationC2Ev                                                                 = 0x02015D18;
_ZN9AnimationD0Ev                                                                 = 0x02015CC4;
_ZN9AnimationD1Ev                                                                 = 0x02015CE8;
_ZN9AnimationD2Ev                                                                 = 0x02015CB4;
_ZN9Animation7AdvanceEv                                                           = 0x02015c3c;
_ZN9Animation8FinishedEv                                                          = 0x02015bcc;
_ZN9Animation8GetFlagsEv                                                          = 0x02015BEC;
_ZN9Animation8SetFlagsEi                                                          = 0x02015BF8;
_ZNK9Animation13GetFrameCountEv                                                   = 0x02015C0C;
_ZN9Animation12SetAnimationEti5Fix12IiEt                                          = 0x02015C20;
_ZN9Animation4CopyERKS_                                                           = 0x02015A7C;
_ZNK9Animation12WillHitFrameEi                                                    = 0x02015A98;
_ZN9Animation8LoadFileER13SharedFilePtr                                           = 0x0201794c;
_ZN9Animation17UpdateFileOffsets_ZN9AnimationER8BCA_File                          = 0x020469ac;

_ZThn80_N9AnimationD0Ev                                                           = 0x02017168;
_ZThn80_N9AnimationD1Ev                                                           = 0x02017178;
_ZThn80_N9AnimationD0Ev                                                           = 0x02017188;
_ZThn80_N9AnimationD1Ev                                                           = 0x02017198;
_ZThn80_N9AnimationD0Ev                                                           = 0x020171A8;
_ZThn80_N9AnimationD1Ev                                                           = 0x020171B8;

_ZTV15MaterialChanger                                                             = 0x0208E7F4;
_ZN15MaterialChangerC1Ev                                                          = 0x02015850;
_ZN15MaterialChangerD0Ev                                                          = 0x02015800;
_ZN15MaterialChangerD1Ev                                                          = 0x0201582c;
_ZN15MaterialChanger7SetFileER8BMA_Filei5Fix12IiEj                                = 0x020157ac;
_ZN15MaterialChanger6UpdateER15ModelComponents                                    = 0x02015788;
_ZN15MaterialChanger7PrepareER8BMD_FileR8BMA_File                                 = 0x0201577c;

_ZTV18TextureTransformer                                                          = 0x0208E7C4;
_ZN18TextureTransformerC1Ev                                                       = 0x02015950;
_ZN18TextureTransformerD0Ev                                                       = 0x02015900;
_ZN18TextureTransformerD1Ev                                                       = 0x0201592c;
_ZN18TextureTransformer7SetFileER8BTA_Filei5Fix12IiEj                             = 0x020158ac;
_ZN18TextureTransformer6UpdateER15ModelComponents                                 = 0x02015888;
_ZN18TextureTransformer7PrepareER8BMD_FileR8BTA_File                              = 0x0201587c;

_ZTV15TextureSequence                                                             = 0x0208E7D4;
_ZN15TextureSequenceC1Ev                                                          = 0x02015a50;
_ZN15TextureSequenceD0Ev                                                          = 0x02015A00;
_ZN15TextureSequenceD1Ev                                                          = 0x02015a2c;
_ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj                                = 0x020159ac;
_ZN15TextureSequence6UpdateER15ModelComponents                                    = 0x02015988;
_ZN15TextureSequence8LoadFileER13SharedFilePtr                                    = 0x020178e4;
_ZN15TextureSequence17UpdateFileOffsetsER8BTP_File                                = 0x020468a0;
_ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File                                 = 0x0201597c;

/* Model/ModelComponents.h */
_ZN15ModelComponents11UpdateBonesEP8BCA_Filei                                     = 0x02045394;
_ZN15ModelComponents21UpdateVertsUsingBonesEv                                     = 0x0204504c;
_ZN15ModelComponents6RenderEP9Matrix4x3P7Vector3                                  = 0x020443c8;

numCommonModelData                                                                = 0x0209cef8;
commonModelDataArr                                                                = 0x0209cefc;
CleanCommonModelDataArr                                                           = 0x02016df8;

/* Model/Model.h */
_ZTV9ModelBase                                                                    = 0x0208E87C;
_ZN9ModelBaseC1Ev                                                                 = 0x02017150;
_ZN9ModelBaseD0Ev                                                                 = 0x020170E8;
_ZN9ModelBaseD1Ev                                                                 = 0x02017120;
_ZN9ModelBaseD2Ev                                                                 = 0x020170B8;
_ZN9ModelBase7SetFileEP8BMD_Fileii                                                = 0x02016fd4;
_ZN9ModelBase12ApplyOpacityEj                                                     = 0x02016a9c;

_ZTV5Model                                                                        = 0x0208e90c;
_ZN5ModelC1Ev                                                                     = 0x02016d58;
_ZN5ModelC2Ev                                                                     = 0x02016da8;
_ZN5ModelD0Ev                                                                     = 0x02016ce0;
_ZN5ModelD1Ev                                                                     = 0x02016d20;
_ZN5ModelD2Ev                                                                     = 0x02016ca8;
_ZN5Model9DoSetFileEPcii                                                          = 0x02016bf8;
_ZN5Model11UpdateVertsEv                                                          = 0x02016c98;
_ZN5Model9Virtual10ER9Matrix4x3                                                   = 0x02016bb8;
_ZN5Model6RenderEPK7Vector3                                                       = 0x02016b78;
_ZN5Model14LoadAndSetFileEtii                                                     = 0x02016f9c;
_ZN5Model12SetPolygonIDEi                                                         = 0x02016abc;
_ZN5Model14SetPolygonModeEi                                                       = 0x02016a8c;
_ZN5Model12ShowMaterialEii                                                        = 0x02016a24;
_ZN5Model12HideMaterialEii                                                        = 0x02016a58;
_ZN5Model8LoadFileER13SharedFilePtr                                               = 0x02017a3c;
_ZN5Model17UpdateFileOffsetsER8BMD_File                                           = 0x020465fc;
_ZN5Model23AddToCommonModelDataArrER8BMD_File                                     = 0x02016f08;
_ZN5Model13LoadTexAndPalER8BMD_File                                               = 0x020458e0;
_ZN5Model17LoadTextureToVramEPcj                                                  = 0x02045c10;
_ZN5Model13GetVramOffsetEj                                                        = 0x02045c60;
_ZN5Model27LoadCompressedTextureToVramEPcjPc                                      = 0x02045b58;

_ZTV9ModelAnim                                                                    = 0x0208E980;
/*_ZTV9Animation_ModelAnimThunk                                                   = 0x0208E9A4;*/
_ZN9ModelAnimC1Ev                                                                 = 0x02016958;
_ZN9ModelAnimC2Ev                                                                 = 0x02016998;
_ZN9ModelAnimD0Ev                                                                 = 0x020168d8;
_ZN9ModelAnimD1Ev                                                                 = 0x0201691c;
_ZN9ModelAnimD2Ev                                                                 = 0x0201689C;
_ZN9ModelAnim11UpdateVertsEv                                                      = 0x0201686c;
_ZN9ModelAnim9Virtual10ER9Matrix4x3                                               = 0x0201682c;
_ZN9ModelAnim6RenderEPK7Vector3                                                   = 0x020167f8;
_ZN9ModelAnim9Virtual18EjPK7Vector3                                               = 0x020167C4;
_ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj                                       = 0x02016748;
_ZN9ModelAnim4CopyERKS_Pc                                                         = 0x02016714;

_ZTV10ModelAnim2                                                                  = 0x0208E9B4;
/*_ZTV9Animation_ModelAnim2Thunk                                                  = 0x0208E9D8;*/
_ZN10ModelAnim2C1Ev                                                               = 0x020163A0;
_ZN10ModelAnim2D0Ev                                                               = 0x02016320;
_ZN10ModelAnim2D1Ev                                                               = 0x02016364;
_ZN10ModelAnim24CopyERKS_Pcj                                                      = 0x02016254;
_ZN10ModelAnim213Func_020162C4Eji5Fix12IiEt                                       = 0x020162C4;

_ZTV11ShadowModel                                                                 = 0x0208E868;
_ZN11ShadowModelC1Ev                                                              = 0x02016068;
_ZN11ShadowModelD0Ev                                                              = 0x02015F80;
_ZN11ShadowModelD1Ev                                                              = 0x02015ff8;
_ZN11ShadowModel9DoSetFileEPcii                                                   = 0x02015ef4;
_ZN11ShadowModel12InitCylinderEv                                                  = 0x02015ebc;
_ZN11ShadowModel10InitCuboidEv                                                    = 0x02015ed8;
_ZN11ShadowModel9InitModelEP9Matrix4x35Fix12IiES3_S3_j                            = 0x02015e64;
_ZN11ShadowModel9RenderAllEv                                                      = 0x02015d38;
_ZN11ShadowModel8CleanAllEv                                                       = 0x02015e14;

_ZTV11CommonModel                                                                 = 0x0208E8A4;
_ZN11CommonModelC1Ev                                                              = 0x02016204;
_ZN11CommonModelD0Ev                                                              = 0x020161B4;
_ZN11CommonModelD1Ev                                                              = 0x020161E0;
_ZN11CommonModel9DoSetFileEPcii                                                   = 0x02016144;
_ZN11CommonModel6RenderEPK7Vector3                                                = 0x02016104;
_ZN11CommonModel13Func_0201609CEj                                                 = 0x0201609C;
_ZN11CommonModel13Func_020160ACEj                                                 = 0x020160AC;

_ZTV14BlendModelAnim                                                              = 0x0208E94C;
/*_ZTV9Animation_BlendModelAnimThunk                                              = 0x0208E970;*/
_ZN14BlendModelAnimC1Ev                                                           = 0x020166D4;
_ZN14BlendModelAnimD0Ev                                                           = 0x02016644;
_ZN14BlendModelAnimD1Ev                                                           = 0x02016690;
_ZN14BlendModelAnim9DoSetFileEPcii                                                = 0x02016604;
_ZN14BlendModelAnim11UpdateVertsEv                                                = 0x02016578;
_ZN14BlendModelAnim9Virtual10ER9Matrix4x3                                         = 0x02016518;
_ZN14BlendModelAnim6RenderEPK7Vector3                                             = 0x020164E4;
_ZN14BlendModelAnim9Virtual18EjPK7Vector3                                         = 0x020164B0;
_ZN14BlendModelAnim7AdvanceEv                                                     = 0x0201647c;
_ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt                                = 0x020163e0;

/* Model/Fader.h */
_ZTV5Fader                                                                        = 0x0208eafc;
_ZN5FaderD0Ev                                                                     = 0x02017848;
_ZN5FaderD1Ev                                                                     = 0x0201786c;
_ZN5FaderD2Ev                                                                     = 0x0201786c;
_ZN5Fader13AdvanceInterpEv                                                        = 0x020175e8;

_ZTV15FaderBrightness                                                             = 0x0208eacc;
_ZN15FaderBrightnessD0Ev                                                          = 0x020177e8;
_ZN15FaderBrightnessD1Ev                                                          = 0x02017814;
_ZN15FaderBrightnessD2Ev                                                          = 0x02017814;
_ZN15FaderBrightness11AdvanceFadeEv                                               = 0x02017720;
_ZN15FaderBrightness14SetForwardTimeEj                                            = 0x02017698;
_ZN15FaderBrightness15SetBackwardTimeEj                                           = 0x020176d8;
_ZN15FaderBrightness9IsAtStartEv                                                  = 0x02017684;
_ZN15FaderBrightness7IsAtEndEv                                                    = 0x02017670;
_ZN15FaderBrightness20IsBetweenStartAndEndEv                                      = 0x02017628;
_ZN15FaderBrightness8SetToEndEv                                                   = 0x0201761c;
_ZN15FaderBrightness10SetToStartEv                                                = 0x02017610;

_ZTV10FaderColor                                                                  = 0x0208eb2C;
_ZN10FaderColorD0Ev                                                               = 0x02017598;
_ZN10FaderColorD1Ev                                                               = 0x020175c4;
_ZN10FaderColorD2Ev                                                               = 0x020175c4;
_ZN10FaderColor11AdvanceFadeEv                                                    = 0x020174e0;

_ZTV9FaderWipe                                                                    = 0x0208ea9c;
_ZN9FaderWipeC1Ev                                                                 = 0x02017480;
_ZN9FaderWipeC2Ev                                                                 = 0x02017480;
_ZN9FaderWipeD0Ev                                                                 = 0x02017418;
_ZN9FaderWipeD1Ev                                                                 = 0x02017450;
_ZN9FaderWipeD2Ev                                                                 = 0x02017450;
_ZN9FaderWipe11AdvanceFadeEv                                                      = 0x020172d8;
_ZN9FaderWipe14LoadAndSetFileEt                                                   = 0x020172c0;

GLOBAL_FADER                                                                      = 0x0209b294;

/* Collision/CLPS.h */
CLPS_BLOCK_PTR                                                                    = 0x0214eb00;

_ZNK11SurfaceInfo12CopyNormalToER7Vector3                                         = 0x02037dcc;

/* Collision/MeshCollider.h */
_ZTV16MeshColliderBase                                                            = 0x02099388;
_ZN16MeshColliderBaseC2Ev                                                         = 0x0203969c;
_ZN16MeshColliderBaseD2Ev                                                         = 0x0203968c;
_ZN16MeshColliderBaseD0Ev                                                         = 0x02039668;
_ZN16MeshColliderBase9Virtual08Ev                                                 = 0x02039620;
_ZN16MeshColliderBase10DetectClsnER13RaycastGround                                = 0x02039480;
_ZN16MeshColliderBase10DetectClsnER11RaycastLine                                  = 0x02039478;
_ZN16MeshColliderBase10DetectClsnER10SphereClsn                                   = 0x02039470;
_ZN16MeshColliderBase10BeforeClsnER10ClsnResultP5ActorR7Vector3P10Vector3_16S7_   = 0x02039438;
_ZN16MeshColliderBase12TransformPosERK7Vector3RS0_                                = 0x02039430;
_ZN16MeshColliderBase14GetAngularVelYEv                                           = 0x02039428;
_ZN16MeshColliderBase11GetVelocityER7Vector3                                      = 0x0203940c;
_ZN16MeshColliderBase7DisableEv                                                   = 0x02039140;
_ZN16MeshColliderBase6EnableEP5Actor                                              = 0x02039184;
_ZN16MeshColliderBase9IsEnabledEv                                                 = 0x020393dc;
_ZN16MeshColliderBase21UpdatePosWithVelocityERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_     = 0x0203923c;
_ZN16MeshColliderBase16UpdatePosAndAngsERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_          = 0x0203929c;
_ZN16MeshColliderBase22UpdatePosWithTransformERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_    = 0x02039348;
_ZN16MeshColliderBase25UpdateAngsWithAngularVelYERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_ = 0x020392f8;

_ZTV12MeshCollider                                                                = 0x020993dc;
_ZN12MeshColliderC1Ev                                                             = 0x02039894;
_ZN12MeshColliderC2Ev                                                             = 0x02039894;
_ZN12MeshColliderD0Ev                                                             = 0x0203982c;
_ZN12MeshColliderD1Ev                                                             = 0x02039864;
_ZN12MeshColliderD2Ev                                                             = 0x02039864;
_ZN12MeshCollider9Virtual08Ev                                                     = 0x020396d8;
_ZN12MeshCollider14GetSurfaceInfoEsR11SurfaceInfo                                 = 0x01ffd920;
_ZN12MeshCollider9GetNormalEsR7Vector3                                            = 0x01ffd8d8;
_ZN12MeshCollider17GetTriangleOriginEsR7Vector3                                   = 0x01ffd890;
_ZN12MeshCollider10DetectClsnER13RaycastGround                                    = 0x01ffd3f8;
_ZN12MeshCollider10DetectClsnER11RaycastLine                                      = 0x01ffb0fc;
_ZN12MeshCollider10DetectClsnER10SphereClsn                                       = 0x01ffb830;
_ZN12MeshCollider7SetFileEP8KCL_FileR10CLPS_Block                                 = 0x020396f0;
_ZNK12MeshCollider13GetUnkOctreeYEv                                               = 0x01ffb0d0;
_ZNK12MeshCollider16GetOctreeOriginYEv                                            = 0x01ffb0ec;
_ZN12MeshCollider8LoadFileER13SharedFilePtr                                       = 0x02017afc;
_ZN12MeshCollider17UpdateFileOffsetsER8KCL_File                                   = 0x02039760;

_ZTV18MovingMeshCollider                                                          = 0x02099434;
_ZN18MovingMeshColliderC1Ev                                                       = 0x0203a494;
_ZN18MovingMeshColliderC2Ev                                                       = 0x0203a494;
_ZN18MovingMeshColliderD0Ev                                                       = 0x0203a444;
_ZN18MovingMeshColliderD1Ev                                                       = 0x0203a470;
_ZN18MovingMeshColliderD2Ev                                                       = 0x0203a470;
_ZN18MovingMeshCollider9Virtual08Ev                                               = 0x0203a1dc;
_ZN18MovingMeshCollider9GetNormalEsR7Vector3                                      = 0x02039ec0;
_ZN18MovingMeshCollider17GetTriangleOriginEsR7Vector3                             = 0x02039e60;
_ZN18MovingMeshCollider10DetectClsnER13RaycastGround                              = 0x02039cb8;
_ZN18MovingMeshCollider10DetectClsnER11RaycastLine                                = 0x02039970;
_ZN18MovingMeshCollider10DetectClsnER10SphereClsn                                 = 0x02039a3c;
_ZN18MovingMeshCollider12TransformPosERK7Vector3RS0_                              = 0x02039930;
_ZN18MovingMeshCollider14GetAngularVelYEv                                         = 0x02039924;
_ZN18MovingMeshCollider11GetVelocityER7Vector3                                    = 0x02039908;
_ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block     = 0x0203a1e0;
_ZN18MovingMeshCollider9TransformERK9Matrix4x3s                                   = 0x02039f20;

_ZTV21ExtendingMeshCollider                                                       = 0x02099490;
_ZN21ExtendingMeshColliderC1Ev                                                    = 0x0203ab8c;
_ZN21ExtendingMeshColliderC2Ev                                                    = 0x0203ab8c;
_ZN21ExtendingMeshColliderD0Ev                                                    = 0x0203ab3c;
_ZN21ExtendingMeshColliderD1Ev                                                    = 0x0203ab68;
_ZN21ExtendingMeshColliderD2Ev                                                    = 0x0203ab68;
_ZN21ExtendingMeshCollider9Virtual08Ev                                            = 0x0203aa0c;
_ZN21ExtendingMeshCollider9GetNormalEsR7Vector3                                   = 0x0203a4dc;
_ZN21ExtendingMeshCollider10DetectClsnER13RaycastGround                           = 0x0203a8fc;
_ZN21ExtendingMeshCollider10DetectClsnER11RaycastLine                             = 0x0203a594;
_ZN21ExtendingMeshCollider10DetectClsnER10SphereClsn                              = 0x0203a660;
_ZN21ExtendingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block  = 0x0203ab04;
_ZN21ExtendingMeshCollider9SetScaleYE5Fix12IiE                                    = 0x0203aad8;

ACTIVE_MESH_COLLIDERS                                                             = 0x020a0c80;

/* Collision/CylinderClsn.h */
_ZTV12CylinderClsn                                                                = 0x0208e6ec;
_ZN12CylinderClsnC2Ev                                                             = 0x020150cc;
_ZN12CylinderClsnD0Ev                                                             = 0x0201507c;
_ZN12CylinderClsnD1Ev                                                             = 0x020150a8;
_ZN12CylinderClsnD2Ev                                                             = 0x02015058;
_ZN12CylinderClsn4InitE5Fix12IiES1_jj                                             = 0x02015040;
_ZN12CylinderClsn6UpdateEv                                                        = 0x02014ff0;
_ZN12CylinderClsn5ClearEv                                                         = 0x02015024;
_ZN12CylinderClsn7ProcessEv                                                       = 0x02014aa8;
_ZN12CylinderClsn4lastE                                                           = 0x0209cee8;

_ZTV19CylinderClsnWithPos                                                         = 0x0208e6bc;
_ZN19CylinderClsnWithPosC1Ev                                                      = 0x02014878;
_ZN19CylinderClsnWithPosD1Ev                                                      = 0x02014854;
_ZN19CylinderClsnWithPosD0Ev                                                      = 0x02014828;
_ZN19CylinderClsnWithPos6GetPosEv                                                 = 0x02014820;
_ZN19CylinderClsnWithPos10GetOwnerIDEv                                            = 0x02014818;
_ZN19CylinderClsnWithPos4InitERK7Vector35Fix12IiES4_jj                            = 0x020147d4;

_ZTV18MovingCylinderClsn                                                          = 0x0208e6d4;
_ZN18MovingCylinderClsnC1Ev                                                       = 0x020149c8;
_ZN18MovingCylinderClsnC2Ev                                                       = 0x020149f4;
_ZN18MovingCylinderClsnD0Ev                                                       = 0x02014978;
_ZN18MovingCylinderClsnD1Ev                                                       = 0x020149a4;
_ZN18MovingCylinderClsnD2Ev                                                       = 0x02014954;
_ZN18MovingCylinderClsn6GetPosEv                                                  = 0x02014948;
_ZN18MovingCylinderClsn10GetOwnerIDEv                                             = 0x0201493c;
_ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj                                = 0x0201490c;

_ZTV25MovingCylinderClsnWithPos                                                   = 0x0208e704;
_ZN25MovingCylinderClsnWithPosC1Ev                                                = 0x02014a84;
_ZN25MovingCylinderClsnWithPosD1Ev                                                = 0x02014a60;
_ZN25MovingCylinderClsnWithPosD0Ev                                                = 0x02014a34;
_ZN25MovingCylinderClsnWithPos6GetPosEv                                           = 0x02014a2c;
_ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj               = 0x020148c8;
_ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3                  = 0x0201489c;

/* Collision/WithMeshClsn.h */
_ZN10ClsnResultC1Ev                                                               = 0x0203816c;
_ZN10ClsnResultD1Ev                                                               = 0x02038144;
_ZN10ClsnResultaSERKS_                                                            = 0x02038018;
_ZN10ClsnResult5ResetEv                                                           = 0x0203816c;
_ZNK10ClsnResult6CopyToERS_                                                       = 0x0203806c;
_ZNK10ClsnResult9GetClsnIDEv                                                      = 0x02037f4c;

_ZN4BgCh19StartDetectingToxicEv                                                   = 0x02035448;
_ZN4BgCh19StartDetectingWaterEv                                                   = 0x0203549c;
_ZN4BgCh21StopDetectingOrdinaryEv                                                 = 0x020354bc;
_ZN4BgCh18StopDetectingWaterEv                                                    = 0x02035488;
_ZN4BgCh21ShouldPassThroughImplEPvRK4CLPSRKS_b                                    = 0x02039488;

_ZN13RaycastGroundC1Ev                                                            = 0x02037570;
_ZN13RaycastGroundD1Ev                                                            = 0x02037534;
_ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor                                = 0x0203748c;
_ZN13RaycastGround10DetectClsnEv                                                  = 0x02038f44;

_ZN11RaycastLineC1Ev                                                              = 0x020377b0;
_ZN11RaycastLineD1Ev                                                              = 0x02037764;
_ZN11RaycastLine10DetectClsnEv                                                    = 0x02038638;
_ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor                              = 0x02037670;
_ZN11RaycastLine10GetClsnPosEv                                                    = 0x020375d0;

_ZN11RaycastLine4Line3SetERK7Vector3S3_                                           = 0x020fea84;

_ZN10SphereClsnC1Ev                                                               = 0x02037d18;
_ZN10SphereClsnD1Ev                                                               = 0x02037cb0;
_ZN10SphereClsn15SetObjAndSphereERK7Vector35Fix12IiEP5Actor                       = 0x02037c00;
_ZN10SphereClsn10DetectClsnEv                                                     = 0x02038b78;
_ZN10SphereClsn14SetFloorResultERK10ClsnResult                                    = 0x020378e4;

_ZN12WithMeshClsnC1Ev                                                             = 0x02037430;
_ZN12WithMeshClsnD1Ev                                                             = 0x020373f8;
_ZNK12WithMeshClsn16ShouldUpdatePosYEv                                            = 0x02035578;
_ZNK12WithMeshClsn15ShouldUpdatePosEv                                             = 0x02035564;
_ZNK12WithMeshClsn8IsOnWallEv                                                     = 0x0203562c;
_ZN12WithMeshClsn15ClearLimMovFlagEv                                              = 0x020356a0;
_ZN12WithMeshClsn13SetLimMovFlagEv                                                = 0x020356b4;
_ZNK12WithMeshClsn13GetLimMovFlagEv                                               = 0x02035694;
_ZNK12WithMeshClsn10IsOnGroundEv                                                  = 0x020356e8;
_ZN12WithMeshClsn15ClearGroundFlagEv                                              = 0x020356f4;
_ZN12WithMeshClsn13SetGroundFlagEv                                                = 0x02035708;
_ZNK12WithMeshClsn13JustHitGroundEv                                               = 0x0203571c;
_ZN12WithMeshClsn22ClearJustHitGroundFlagEv                                       = 0x02035728;
_ZN12WithMeshClsn19ClearAllGroundFlagsEv                                          = 0x02035750;
_ZN12WithMeshClsn19StartDetectingWaterEv                                          = 0x02035840;
_ZN12WithMeshClsn18StopDetectingWaterEv                                           = 0x02035820;
_ZN12WithMeshClsn12Unk_0203589cEv                                                 = 0x0203589c;
_ZNK12WithMeshClsn12TouchesWaterEv                                                = 0x02035610;
_ZNK12WithMeshClsn14GetResultFlag1Ev                                              = 0x02035620;
_ZNK12WithMeshClsn14GetFloorResultEv                                              = 0x0203566c;
_ZNK12WithMeshClsn13GetWallResultEv                                               = 0x0203565c;
_ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_                        = 0x02037388;
_ZN12WithMeshClsn16UpdateContinuousEv                                             = 0x020366b4;
_ZN12WithMeshClsn20UpdateExtraContinousEv                                         = 0x020358ac;
_ZN12WithMeshClsn22UpdateContinuousNoLavaEv                                       = 0x02036318;
_ZN12WithMeshClsn20UpdateDiscreteNoLavaEv                                         = 0x02037024;
_ZN12WithMeshClsn22UpdateDiscreteNoLava_2Ev                                       = 0x02036ee4;

/* PathPtr.h */
_ZN7PathPtrC1Ev                                                                   = 0x0203ad74;
_ZN7PathPtr6FromIDEj                                                              = 0x0203ac80;
_ZNK7PathPtr7GetNodeER7Vector3j                                                   = 0x0203acdc;
_ZNK7PathPtr8NumNodesEv                                                           = 0x0203ad60;
_ZNK7PathPtr5LoopsEv                                                              = 0x0203ad34;

/* Message.h */
_ZN7Message10LoadTextVSEv                                                         = 0x020349e0;
_ZN7Message16SetTextGlobalsVSEv                                                   = 0x02032f04;
_ZN7Message11PrepareTalkEv                                                        = 0x0201ab38;
_ZN7Message7EndTalkEv                                                             = 0x0201ab04;
_ZN7Message7AddCharEc                                                             = 0x0201b5a8;
_ZN7Message7DisplayEj                                                             = 0x0201e574;
_ZN7Message11DisplayTextEt                                                        = 0x0201e36c;
_ZN7Message13DisplaySavingEt                                                      = 0x0201eb94;
_ZN7Message21DisplaySaveStatusTextEt                                              = 0x0201ce10;
_ZN7Message21DisplayLevelClearTextEta                                             = 0x0201cf80;
_ZN7Message17DisplayVsExitTextEt                                                  = 0x020339c0;
_ZN7Message16DisplayPauseTextEth                                                  = 0x0201e044;
_ZN7Message18DisplayPauseTextVSEt                                                 = 0x02034358;
_ZN7Message25DisplayControllerModeTextEt                                          = 0x0201d304;
_ZN7Message22DisplayOptionsMenuTextEt                                             = 0x0201d018;
_ZN7Message19DisplaySaveMenuTextEt                                                = 0x0201e314;
_ZN7Message19DisplayDontSaveTextEt                                                = 0x0201e12c;
_ZN7Message30DisplayCourseNameForStarSelectEj                                     = 0x0201e81c;
_ZN7Message28DisplayStarNameForStarSelectEj                                       = 0x0201e6bc;
_ZN7Message12UpdateWindowEv                                                       = 0x0201bbc8;
_ZN7Message6UpdateEv                                                              = 0x0201c0b8;
_ZN7Message15ResetAllGlobalsEv                                                    = 0x0201fcac;

MSG_LINE_HEIGHT                                                                   = 0x0209d6a8;
CURR_MSG_ID                                                                       = 0x0209d6d4;
CURR_MSG_PTR                                                                      = 0x0209d6f0;
CURR_MSG_TEXT_CHAR                                                                = 0x0209d6f4;
MSG_ARR_PTR                                                                       = 0x0209d708;
MSG_FILE_PTR                                                                      = 0x0209d70c;
VS_MSG_FILE_PTR                                                                   = 0x0209fd14;
MSG_ID_CHAR_MAP                                                                   = 0x0208eeec;
UTF16_TO_FONT_TABLE                                                               = 0x02075d14;
TALK_FONT_CHAR_WIDTHS                                                             = 0x0208f074;

MESSAGE_RESULT                                                                    = 0x0209d684;
BOUNCING_MSG_ARROWS_VISIBLE                                                       = 0x0209f284;
IS_SAVING_MESSAGE_DISPLAYED                                                       = 0x0209d654;
SAVE_MESSAGE_TIMER                                                                = 0x0209d67c;
IS_MESSAGE_DISAPPEARING                                                           = 0x0209d670;

/* Actor/ActorBase.h */
_ZTV9ActorBase                                                                    = 0x02099edc;
_ZN9ActorBaseC1Ev                                                                 = 0x02043dec;
_ZN9ActorBaseC2Ev                                                                 = 0x02043dec;
_ZN9ActorBaseD0Ev                                                                 = 0x02043d78;
_ZN9ActorBaseD1Ev                                                                 = 0x02043D48;
_ZN9ActorBaseD2Ev                                                                 = 0x02043dbc;
_ZN9ActorBase13InitResourcesEv                                                    = 0x02043c80;
_ZN9ActorBase19BeforeInitResourcesEv                                              = 0x02043c78;
_ZN9ActorBase18AfterInitResourcesEj                                               = 0x02043bf8;
_ZN9ActorBase16CleanupResourcesEv                                                 = 0x02043bf0;
_ZN9ActorBase22BeforeCleanupResourcesEv                                           = 0x02043bac;
_ZN9ActorBase21AfterCleanupResourcesEj                                            = 0x02043b2c;
_ZN9ActorBase8BehaviorEv                                                          = 0x02043b24;
_ZN9ActorBase14BeforeBehaviorEv                                                   = 0x02043afc;
_ZN9ActorBase13AfterBehaviorEj                                                    = 0x02043af8;
_ZN9ActorBase6RenderEv                                                            = 0x02043af0;
_ZN9ActorBase12BeforeRenderEv                                                     = 0x02043ac8;
_ZN9ActorBase11AfterRenderEj                                                      = 0x02043ac4;
_ZN9ActorBase16OnPendingDestroyEv                                                 = 0x02043ac0;
_ZN9ActorBase9Virtual34Ejj                                                        = 0x0204357c;
_ZN9ActorBase9Virtual38Ejj                                                        = 0x0204349c;
_ZN9ActorBase13OnHeapCreatedEv                                                    = 0x02043494;
_ZN9ActorBasenwEj                                                                 = 0x02043444;
_ZN9ActorBase7ProcessEMS_FivEMS_FbvEMS_FvjE                                       = 0x02043c88;
_ZN9ActorBase18MarkForDestructionEv                                               = 0x02043824;

_ZN9ActorBase9SceneNodeC1Ev                                                       = 0x0203b4c4;
_ZN9ActorBase9SceneNode5ResetEv                                                   = 0x0203b4ac;

/* Actor/ActorDerived.h */
_ZTV12ActorDerived                                                                = 0x0208e4b8;
_ZN12ActorDerivedD0Ev                                                             = 0x02013ea4;
_ZN12ActorDerivedD1Ev                                                             = 0x02013e80;
_ZN12ActorDerivedD2Ev                                                             = 0x02013e80;
_ZN12ActorDerived18AfterInitResourcesEj                                           = 0x02013ef4;
_ZN12ActorDerived5SpawnEjP9ActorBaseii                                            = 0x02013ee8;

/* Actor/Actor.h */
_ZTV5Actor                                                                        = 0x0208E3A4;
_ZN5ActorC1Ev                                                                     = 0x020113c0;
_ZN5ActorC2Ev                                                                     = 0x0201150c;
_ZN5ActorD0Ev                                                                     = 0x02011314;
_ZN5ActorD1Ev                                                                     = 0x020112C8;
_ZN5ActorD2Ev                                                                     = 0x02011374;
_ZN5Actor19BeforeInitResourcesEv                                                  = 0x02011268;
_ZN5Actor18AfterInitResourcesEj                                                   = 0x02011244;
_ZN5Actor22BeforeCleanupResourcesEv                                               = 0x02011220;
_ZN5Actor21AfterCleanupResourcesEj                                                = 0x02011214;
_ZN5Actor14BeforeBehaviorEv                                                       = 0x02010fd4;
_ZN5Actor13AfterBehaviorEj                                                        = 0x02010fc8;
_ZN5Actor12BeforeRenderEv                                                         = 0x02010f78;
_ZN5Actor11AfterRenderEj                                                          = 0x02010f6c;
_ZN5Actor13OnYoshiTryEatEv                                                        = 0x02010160;
_ZN5Actor13OnTurnIntoEggER6Player                                                 = 0x02010154;
_ZN5Actor9Virtual50Ev                                                             = 0x0201014c;
_ZN5Actor15OnGroundPoundedERS_                                                    = 0x02010148;
_ZN5Actor11OnAttacked1ERS_                                                        = 0x02010144;
_ZN5Actor11OnAttacked2ERS_                                                        = 0x02010140;
_ZN5Actor8OnKickedERS_                                                            = 0x0201013c;
_ZN5Actor8OnPushedERS_                                                            = 0x02010138;
_ZN5Actor24OnHitByCannonBlastedCharERS_                                           = 0x02010134;
_ZN5Actor15OnHitByMegaCharER6Player                                               = 0x02010130;
_ZN5Actor19OnHitFromUnderneathERS_                                                = 0x0201012c;
_ZN5Actor16OnAimedAtWithEggEv                                                     = 0x02010124;
_ZN5Actor25OnAimedAtWithEggReturnVecEv                                            = 0x020100dc;
_ZN5Actor22IsTooFarAwayFromPlayerE5Fix12IiE                                       = 0x0200f70c;
_ZN5Actor19MakeVanishLuigiWorkER12CylinderClsn                                    = 0x0200f7a8;
_ZN5Actor13SpawnSoundObjEj                                                        = 0x0200f97c;
_ZN5Actor24KillAndTrackInDeathTableEv                                             = 0x0200f9b8;
_ZN5Actor17TrackInDeathTableEv                                                    = 0x0200f9e4;
_ZN5Actor19UntrackInDeathTableEv                                                  = 0x0200f9d4;
_ZN5Actor18GetBitInDeathTableEv                                                   = 0x0200f9f4;
_ZN5Actor15HugeLandingDustEb                                                      = 0x0200fb4c;
_ZN5Actor17HugeLandingDustAtER7Vector3b                                           = 0x0200fb84;
_ZN5Actor14BigLandingDustEb                                                       = 0x0200fb4c;
_ZN5Actor16BigLandingDustAtER7Vector3b                                            = 0x0200fb84;
_ZN5Actor11LandingDustEb                                                          = 0x0200fc0c;
_ZN5Actor13LandingDustAtER7Vector3b                                               = 0x0200fac4;
_ZN5Actor19DisappearPoofDustAtERK7Vector3                                         = 0x0200fd04;
_ZN5Actor13SmallPoofDustEv                                                        = 0x0200fd40;
_ZN5Actor10PoofDustAtERK7Vector3                                                  = 0x0200fdfc;
_ZN5Actor8PoofDustEv                                                              = 0x0200fe3c;
_ZN5Actor14TriplePoofDustEv                                                       = 0x0200fdc8;
_ZN5Actor16TriplePoofDustAtERK7Vector3                                            = 0x0200fd74;
_ZN5Actor11UntrackStarERa                                                         = 0x0200ff60;
_ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j                                     = 0x0200ff14;
_ZN5Actor9TrackStarEjj                                                            = 0x0200ff94;
_ZN5Actor10EarthquakeERK7Vector35Fix12IiE                                         = 0x02010168;
_ZN5Actor12ReflectAngleE5Fix12IiES1_s                                             = 0x02010428;
_ZN5Actor24BumpedUnderneathByPlayerER6Player                                      = 0x02010518;
_ZN5Actor16JumpedOnByPlayerER12CylinderClsnR6Player                               = 0x0201054c;
_ZN5Actor15GivePlayerCoinsER6Playerhj                                             = 0x0201061c;
_ZN5Actor13DistToCPlayerEv                                                        = 0x020109e4;
_ZN5Actor13ClosestPlayerEv                                                        = 0x02010ad8;
_ZN5Actor22ClosestNonVanishPlayerEv                                               = 0x02010a08;
_ZN5Actor18HorzAngleToCPlayerEv                                                   = 0x020109b8;
_ZN5Actor23HorzAngleToCPlayerOrAngEv                                              = 0x0201097c;
_ZN5Actor14FarthestPlayerEv                                                       = 0x02010958;
_ZN5Actor18HorzAngleToFPlayerEv                                                   = 0x0201092c;
_ZN5Actor15IsPlayerInRangeEi                                                      = 0x020104dc;
_ZN5Actor15IsPlayerInRangeERK7Vector3i                                            = 0x0201045c;
_ZN5Actor15IsPlayerInRangeE5Fix12IiES1_S1_i                                       = 0x02010498;
_ZN5Actor18DropShadowScaleXYZER11ShadowModelR9Matrix4x35Fix12IiES5_S5_j           = 0x02010b9c;
_ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j             = 0x02010be8;
_ZN5Actor9UpdatePosEP12CylinderClsn                                               = 0x02010c30;
_ZN5Actor22UpdatePosWithOnlySpeedEP12CylinderClsn                                 = 0x02010d40;
_ZN5Actor28UpdatePosWithHorzSpeedAndAngEv                                         = 0x02010c5c;
_ZN5Actor17DetectRaycastClsnER7Vector3S1_b                                        = 0x0200f658;
_ZN5Actor11UpdateCarryER6PlayerRK7Vector3                                         = 0x02010180;
_ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_                                            = 0x02010e08;
_ZN5Actor14GetSubtractionEss                                                      = 0x020103f4;
_ZN5Actor17GetWaterHeightWDWEv                                                    = 0x0200fec8;
_ZN5Actor10SpawnCoinsERK7Vector3j5Fix12IiEs                                       = 0x02010714;
_ZN5Actor11SpawnNumberERK7Vector3jbtPS_                                           = 0x02010044;
_ZN5Actor13SpawnFireballERK7Vector3PK10Vector3_165Fix12IiES7_j                    = 0x020102b0;
_ZN5Actor7FindEggER12CylinderClsn                                                 = 0x020103b4;
_ZN5Actor18FindExplosionActorER12CylinderClsn                                     = 0x02010374;
_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii                                      = 0x02010e2c;
_ZN5Actor4NextEPKS_                                                               = 0x02010ecc;
_ZN5Actor18ClosestWithActorIDEj                                                   = 0x020108c4;
_ZN5Actor15FindWithActorIDEjPS_                                                   = 0x02010ef0;
_ZN5Actor10FindWithIDEj                                                           = 0x02010f3c;

/* Actor/Enemy.h */
_ZN5EnemyC2Ev                                                                     = 0x020aed98;
_ZN5EnemyD0Ev                                                                     = 0x020aed3c;
_ZN5EnemyD2Ev                                                                     = 0x020aed74;
_ZN5Enemy26UpdateKillByInvincibleCharER12WithMeshClsnR9ModelAnimj                 = 0x020ad838;
_ZN5Enemy20KillByInvincibleCharERK10Vector3_16R6Player                            = 0x020ada40;
_ZN5Enemy22SpawnMegaCharParticlesER5ActorPc                                       = 0x020adb40;
_ZN5Enemy27SpawnParticlesIfHitOtherObjER12CylinderClsn                            = 0x020addc0;
_ZN5Enemy14UpdateYoshiEatER12WithMeshClsn                                         = 0x020ade78;
_ZN5Enemy24AngleAwayFromWallOrCliffER12WithMeshClsnRs                             = 0x020ae244;
_ZN5Enemy11UpdateDeathER12WithMeshClsn                                            = 0x020ae6a8;
_ZN5Enemy15IsGoingOffCliffER12WithMeshClsn5Fix12IiEsbbS3_                         = 0x020ae2b8;
_ZN5Enemy12KillByAttackER5Actor                                                   = 0x020aea30;
_ZN5Enemy9SpawnCoinEv                                                             = 0x020aeabc;
_ZN5Enemy12UpdateWMClsnER12WithMeshClsnj                                          = 0x020aebf8;

ENEMY_DEATH_FUNCS                                                                 = 0x0210dbc0;

/* Actor/CapEnemy.h */
_ZN8CapEnemyC2Ev                                                                  = 0x02006554;
_ZN8CapEnemyD0Ev                                                                  = 0x020aedf4;
_ZN8CapEnemyD2Ev                                                                  = 0x0200651c;
_ZN8CapEnemy12Unk_02005d94Ev                                                      = 0x02005d94;
_ZN8CapEnemy21DestroyIfCapNotNeededEv                                             = 0x02005f0c;
_ZN8CapEnemy11GetCapStateEv                                                       = 0x02005fa0;
_ZN8CapEnemy15RespawnIfHasCapEv                                                   = 0x02006054;
_ZN8CapEnemy16GetCapEatenOffItERK7Vector3                                         = 0x020060f4;
_ZN8CapEnemy10ReleaseCapERK7Vector3                                               = 0x020061b0;
_ZN8CapEnemy14RenderCapModelEPK7Vector3                                           = 0x02006280;
_ZN8CapEnemy12UpdateCapPosERK7Vector3RK10Vector3_16                               = 0x020062b8;
_ZN8CapEnemy6AddCapEj                                                             = 0x020063b0;
_ZN8CapEnemy14UnloadCapModelEv                                                    = 0x020064e0;

/* Actor/Platform.h */
_ZTV8Platform                                                                     = 0x0210ae38;
_ZN8PlatformC2Ev                                                                  = 0x020eea50;
_ZN8PlatformD0Ev                                                                  = 0x020ee464;
_ZN8PlatformD2Ev                                                                  = 0x020ee42c;
_ZN8Platform4KillEv                                                               = 0x020ee55c;
_ZN8Platform14KillByMegaCharER6Player                                             = 0x020ee4b0;
_ZN8Platform20UpdateKillByMegaCharEsss5Fix12IiE                                   = 0x020ee674;
_ZN8Platform19UpdateClsnPosAndRotEv                                               = 0x020ee7cc;
_ZN8Platform21UpdateModelPosAndRotYEv                                             = 0x020ee830;
_ZN8Platform13IsClsnInRangeE5Fix12IiES1_                                          = 0x020ee870;
_ZN8Platform21IsClsnInRangeOnScreenE5Fix12IiES1_                                  = 0x020ee934;

/* Actor/PathLift.h */
_ZTV8PathLift                                                                     = 0x0210af70;
_ZN8PathLiftD0Ev                                                                  = 0x020ef320;
_ZN8PathLiftD2Ev                                                                  = 0x020ef390;
_ZN8PathLift9AfterClsnEv                                                          = 0x020eff18;
_ZN8PathLift17BaseInitResourcesEv                                                 = 0x020efaf0;
_ZN8PathLift12BaseBehaviorEv                                                      = 0x020efaa0;

/* Actor/Camera.h */
_ZTV4View                                                                         = 0x02092720;
_ZN4ViewD0Ev                                                                      = 0x0202FCC8;
_ZN4ViewD1Ev                                                                      = 0x0202FC98;
_ZN4View6RenderEv                                                                 = 0x0202FD0C;

_ZTV7Clipper                                                                      = 0x0208E730;
_ZN7ClipperC1Ev                                                                   = 0x02015730;
_ZN7ClipperD0Ev                                                                   = 0x020156FC;
_ZN7ClipperD1Ev                                                                   = 0x02015720;
_ZN7Clipper13Func_020150E8ER7Vector35Fix12IiEPh                                   = 0x020150E8;
_ZN7Clipper13Func_02015560ER9Matrix4x3R7Vector35Fix12IiES3_                       = 0x02015560;
_ZN7Clipper13Func_0201559CEv                                                      = 0x0201559C;
_ZN7Clipper13Func_020156DCEv                                                      = 0x020156DC;

_ZTV6Camera                                                                       = 0x02086F84;
_ZN6CameraC1Ev                                                                    = 0x0200E444;
_ZN6CameraD0Ev                                                                    = 0x02007098;
_ZN6CameraD1Ev                                                                    = 0x0200705C;
_ZN6Camera13InitResourcesEv                                                       = 0x0200E338;
_ZN6Camera16CleanupResourcesEv                                                    = 0x0200D9D0;
_ZN6Camera8BehaviorEv                                                             = 0x0200DEBC;
_ZN6Camera6RenderEv                                                               = 0x0200DA04;
_ZN6Camera16OnPendingDestroyEv                                                    = 0x0200DA00;
_ZN6Camera25SaveCameraStateBeforeTalkEv                                           = 0x0200CC5C;
_ZN6Camera9SetFlag_3Ev                                                            = 0x0200d048;
_ZN6Camera9SetLookAtERK7Vector3                                                   = 0x0200ccc8;
_ZN6Camera6SetPosERK7Vector3                                                      = 0x0200ccac;
_ZNK6Camera12IsUnderwaterEv                                                       = 0x0200d890;
_ZN6Camera11ChangeStateEPNS_5StateE                                               = 0x0200cb70;
_ZN6Camera10LookAtExitER5Actor                                                    = 0x0200d184;
_ZN6Camera14GoBehindPlayerEj                                                      = 0x0200d304;

GLOBAL_CLIPPER                                                                    = 0x0209F43C;

/* Actor/Player.h */
_ZN6Player9ANIM_PTRSE                                                             = 0x020ff480;
_ZN6Player13ST_LEDGE_HANGE                                                        = 0x0210ffec;
_ZN6Player13ST_LEDGE_GRABE                                                        = 0x02110004;
_ZN6Player16ST_CEILING_GRATEE                                                     = 0x0211001c;
_ZN6Player14ST_YOSHI_POWERE                                                       = 0x02110034;
_ZN6Player10ST_SWALLOWE                                                           = 0x0211004c;
_ZN6Player17ST_IN_YOSHI_MOUTHE                                                    = 0x02110064;
_ZN6Player18ST_SMALL_LAUNCH_UPE                                                   = 0x0211007c;
_ZN6Player7ST_HURTE                                                               = 0x02110094;
_ZN6Player13ST_HURT_WATERE                                                        = 0x021100ac;
_ZN6Player14ST_ELECTROCUTEE                                                       = 0x021100c4;
_ZN6Player12ST_BURN_FIREE                                                         = 0x021100dc;
_ZN6Player12ST_BURN_LAVAE                                                         = 0x021100f4;
_ZN6Player11ST_DEAD_HITE                                                          = 0x0211010c;
_ZN6Player11ST_DEAD_PITE                                                          = 0x02110124;
_ZN6Player7ST_WALKE                                                               = 0x0211013c;
_ZN6Player7ST_WAITE                                                               = 0x02110154;
_ZN6Player10ST_GRABBEDE                                                           = 0x0211016c;
_ZN6Player14ST_TURN_AROUNDE                                                       = 0x02110184;
_ZN6Player7ST_JUMPE                                                               = 0x0211019c;
_ZN6Player7ST_FALLE                                                               = 0x021101b4;
_ZN6Player9ST_THROWNE                                                             = 0x021101cc;
_ZN6Player12ST_SIDE_FLIPE                                                         = 0x021101e4;
_ZN6Player21ST_SLIDE_KICK_RECOVERE                                                = 0x021101fc;
_ZN6Player6ST_FLYE                                                                = 0x02110214;
_ZN6Player13ST_NO_CONTROLE                                                        = 0x0211022c;
_ZN6Player6ST_OWLE                                                                = 0x02110244;
_ZN6Player12ST_DEBUG_FLYE                                                         = 0x0211025c;
_ZN6Player13ST_WIND_CARRYE                                                        = 0x02110274;
_ZN6Player10ST_BALLOONE                                                           = 0x0211028c;
_ZN6Player11ST_TELEPORTE                                                          = 0x021102a4;
_ZN6Player15ST_TORNADO_SPINE                                                      = 0x021102bc;
_ZN6Player9ST_CANNONE                                                             = 0x021102d4;
_ZN6Player9ST_SQUISHE                                                             = 0x021102ec;
_ZN6Player8ST_SHELLE                                                              = 0x02110304;
_ZN6Player16ST_STOMACH_SLIDEE                                                     = 0x0211031c;
_ZN6Player13ST_BUTT_SLIDEE                                                        = 0x02110334;
_ZN6Player14ST_DIZZY_STARSE                                                       = 0x0211034c;
_ZN6Player13ST_HOLD_LIGHTE                                                        = 0x02110364;
_ZN6Player7ST_BONKE                                                               = 0x0211037c;
_ZN6Player13ST_HOLD_HEAVYE                                                        = 0x02110394;
_ZN6Player13ST_WALL_SLIDEE                                                        = 0x021103ac;
_ZN6Player20ST_BOWSER_EARTHQUAKEE                                                 = 0x021103c4;
_ZN6Player12ST_WALL_JUMPE                                                         = 0x021103dc;
_ZN6Player13ST_SLOPE_JUMPE                                                        = 0x021103f4;
_ZN6Player18ST_STUCK_IN_GROUNDE                                                   = 0x0211040c;
_ZN6Player7ST_LANDE                                                               = 0x02110424;
_ZN6Player10ST_ON_WALLE                                                           = 0x0211043c;
_ZN6Player7ST_SPINE                                                               = 0x02110454;
_ZN6Player7ST_TALKE                                                               = 0x0211046c;
_ZN6Player15ST_CRAZED_CRATEE                                                      = 0x02110484;
_ZN6Player17ST_WAIT_QUICKSANDE                                                    = 0x0211049c;
_ZN6Player14ST_LEVEL_ENTERE                                                       = 0x021104b4;
_ZN6Player17ST_JUMP_QUICKSANDE                                                    = 0x021104cc;
_ZN6Player9ST_CROUCHE                                                             = 0x021104e4;
_ZN6Player10ST_RESPAWNE                                                           = 0x021104fc;
_ZN6Player8ST_CRAWLE                                                              = 0x02110514;
_ZN6Player12ST_BACK_FLIPE                                                         = 0x0211052c;
_ZN6Player18ST_OPENING_WAKE_UPE                                                   = 0x02110544;
_ZN6Player12ST_LONG_JUMPE                                                         = 0x0211055c;
_ZN6Player13ST_PUNCH_KICKE                                                        = 0x02110574;
_ZN6Player13ST_ENDING_FLYE                                                        = 0x0211058c;
_ZN6Player15ST_GROUND_POUNDE                                                      = 0x021105a4;
_ZN6Player7ST_DIVEE                                                               = 0x021105bc;
_ZN6Player8ST_THROWE                                                              = 0x021105d4;
_ZN6Player19ST_GRAB_BOWSER_TAILE                                                  = 0x021105ec;
_ZN6Player15ST_SWING_PLAYERE                                                      = 0x02110604;
_ZN6Player13ST_SWEEP_KICKE                                                        = 0x0211061c;
_ZN6Player13ST_SLIDE_KICKE                                                        = 0x02110634;
_ZN6Player14ST_CAMERA_ZOOME                                                       = 0x0211064c;
_ZN6Player7ST_NULLE                                                               = 0x02110664;
_ZN6Player7ST_SWIME                                                               = 0x0211067c;
_ZN6Player13ST_WATER_JUMPE                                                        = 0x02110694;
_ZN6Player21ST_METAL_WATER_GROUNDE                                                = 0x021106ac;
_ZN6Player20ST_METAL_WATER_WATERE                                                 = 0x021106c4;
_ZN6Player8ST_CLIMBE                                                              = 0x021106dc;
_ZN6Player12ST_HEADSTANDE                                                         = 0x021106f4;
_ZN6Player12ST_POLE_JUMPE                                                         = 0x0211070c;
_ZN6Player17ST_HEADSTAND_JUMPE                                                    = 0x02110724;
_ZTV6Player                                                                       = 0x0210A83C;
_ZN6PlayerC1Ev                                                                    = 0x020e68f4;
_ZN6PlayerC2Ev                                                                    = 0x020e68f4;
_ZN6PlayerC3Ev                                                                    = 0x020e6c0c;
_ZN6PlayerD0Ev                                                                    = 0x020e67a8;
_ZN6PlayerD2Ev                                                                    = 0x020e6858;
_ZN6Player13InitResourcesEv                                                       = 0x020e558c;
_ZN6Player16CleanupResourcesEv                                                    = 0x020e32d4;
_ZN6Player8BehaviorEv                                                             = 0x020e4d24;
_ZN6Player6RenderEv                                                               = 0x020e3a08;
_ZN6Player16OnPendingDestroyEv                                                    = 0x020e3a04;
_ZN6Player13OnYoshiTryEatEv                                                       = 0x020e69b8;
_ZN6Player16IncMegaKillCountEv                                                    = 0x020bdc58;
_ZN6Player18SetNewHatCharacterEjjb                                                = 0x020be0f8;
_ZN6Player16SetRealCharacterEj                                                    = 0x020be1e0;
_ZN6Player18TurnOffToonShadingEj                                                  = 0x020be324;
_ZN6Player7IsStateERNS_5StateE                                                    = 0x020e308c;
_ZN6Player8IsDivingEv                                                             = 0x020dd240;
_ZN6Player16IsInsideOfCannonEv                                                    = 0x020df288;
_ZN6Player15IsCollectingCapEv                                                     = 0x020bea94;
_ZN6Player8HasNoCapEv                                                             = 0x020bda98;
_ZN6Player12Unk_020c6a10Ej                                                        = 0x020c6a10;
_ZN6Player12Unk_020c4f40Et                                                        = 0x020c4f40;
_ZN6Player12Unk_020ca8f8Ev                                                        = 0x020ca8f8;
_ZN6Player12Unk_020c9e5cEh                                                        = 0x020c9e5c;
_ZN6Player12Unk_020ca488Ev                                                        = 0x020ca488;
_ZN6Player12Unk_020ca150Eh                                                        = 0x020ca150;
_ZNK6Player14GetBodyModelIDEjb                                                    = 0x020becc8;
_ZN6Player7SetAnimEji5Fix12IiEj                                                   = 0x020bef2c;
_ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj                                  = 0x020c4ec0;
_ZN6Player12ShowMessage2ER9ActorBasejPK7Vector3jj                                 = 0x020c4c60;
_ZN6Player9StartTalkER9ActorBaseb                                                 = 0x020c4fa0;
_ZN6Player12GetTalkStateEv                                                        = 0x020c524c;
_ZN6Player18HasFinishedTalkingEv                                                  = 0x020c4efc;
_ZN6Player12GetHurtStateEv                                                        = 0x020d9c44;
_ZN6Player9IsOnShellEv                                                            = 0x020cc140;
_ZN6Player15IsEnteringLevelEv                                                     = 0x020c7e84;
_ZN6Player22IsBeingShotOutOfCannonEv                                              = 0x020df2c4;
_ZN6Player8CanPauseEv                                                             = 0x020bd828;
_ZN6Player4BurnEv                                                                 = 0x020d57d8;
_ZN6Player5ShockEj                                                                = 0x020d5a1c;
_ZN6Player20RegisterEggCoinCountEjbb                                              = 0x020d6708;
_ZN6Player4HurtERK7Vector3j5Fix12IiEjjj                                           = 0x020d8e70;
_ZN6Player4HealEi                                                                 = 0x020bf4e4;
_ZN6Player9GetHealthEv                                                            = 0x020bf548;
_ZN6Player6BounceE5Fix12IiE                                                       = 0x020d932c;
_ZN6Player10SpinBounceE5Fix12IiE                                                  = 0x020e1020;
_ZN6Player11ChangeStateERNS_5StateE                                               = 0x020e30a0;
_ZN6Player15JumpIntoBooCageER7Vector3                                             = 0x020ca2ac;
_ZN6Player14EnterWhirlpoolEv                                                      = 0x020c5cc8;
_ZN6Player8BlowAwayEs                                                             = 0x020d4fe4;
_ZN6Player7IsInAirEv                                                              = 0x020c2f3c;
_ZN6Player7CanWarpEv                                                              = 0x020c2ef0;
_ZN6Player20IsStateEnteringLevelEv                                                = 0x020c7ed4;
_ZN6Player17SetNoControlStateEhih                                                 = 0x020ca1b8;
_ZN6Player16TryTalkToKeyDoorEv                                                    = 0x020ca410;
_ZN6Player13TryTalkToDoorEh                                                       = 0x020ca344;
_ZN6Player11OpenBigDoorEv                                                         = 0x020ca144;
_ZN6Player12CanEnterDoorEh                                                        = 0x020ca5cc;
_ZN6Player24TryExitWhiteDoorWithStarEv                                            = 0x020ca724;
_ZN6Player29TryExitCharacterDoorWithIntroEv                                       = 0x020ca78c;
_ZN6Player21IsOpeningDoorWithStarEv                                               = 0x020ca3d0;
_ZN6Player16TryEnterStarDoorER7Vector3s                                           = 0x020ca498;
_ZN6Player17PlayMammaMiaSoundEv                                                   = 0x020ca708;
_ZN6Player7TryGrabER5Actor                                                        = 0x020daba0;
_ZN6Player9DropActorEv                                                            = 0x020da7f4;
_ZN6Player12FinishedAnimEv                                                        = 0x020bed98;
_ZN6Player6IsAnimEj                                                               = 0x020beecc;
_ZN6Player14IsFrontSlidingEv                                                      = 0x020dd2b0;
_ZN6Player17LostGrabbedObjectEv                                                   = 0x020dd26c;
_ZN6Player16InitWingFeathersEb                                                    = 0x020e03b8;
_ZN6Player16InitBalloonMarioEv                                                    = 0x020dea00;
_ZN6Player15InitVanishLuigiEv                                                     = 0x020bdf4c;
_ZN6Player14InitMetalWarioEv                                                      = 0x020bde14;
_ZN6Player13InitFireYoshiEv                                                       = 0x020d8228;
_ZN6Player17St_LedgeHang_InitEv                                                   = 0x020d0c54;
_ZN6Player17St_LedgeHang_MainEv                                                   = 0x020d0a44;
_ZN6Player20St_LedgeHang_CleanupEv                                                = 0x020d092c;
_ZN6Player17St_LedgeGrab_InitEv                                                   = 0x020d08b0;
_ZN6Player17St_LedgeGrab_MainEv                                                   = 0x020d0824;
_ZN6Player20St_CeilingGrate_InitEv                                                = 0x020cf6bc;
_ZN6Player20St_CeilingGrate_MainEv                                                = 0x020cf398;
_ZN6Player18St_YoshiPower_InitEv                                                  = 0x020d7ed0;
_ZN6Player18St_YoshiPower_MainEv                                                  = 0x020d7504;
_ZN6Player21St_YoshiPower_CleanupEv                                               = 0x020d736c;
_ZN6Player15St_Swallow_InitEv                                                     = 0x020d666c;
_ZN6Player15St_Swallow_MainEv                                                     = 0x020d6474;
_ZN6Player20St_InYoshiMouth_InitEv                                                = 0x020d62f8;
_ZN6Player20St_InYoshiMouth_MainEv                                                = 0x020d60b8;
_ZN6Player23St_InYoshiMouth_CleanupEv                                             = 0x020d6084;
_ZN6Player21St_SmallLaunchUp_InitEv                                               = 0x020e0adc;
_ZN6Player21St_SmallLaunchUp_MainEv                                               = 0x020e0aa8;
_ZN6Player12St_Hurt_InitEv                                                        = 0x020d9b68;
_ZN6Player12St_Hurt_MainEv                                                        = 0x020d966c;
_ZN6Player15St_Hurt_CleanupEv                                                     = 0x020d9654;
_ZN6Player17St_HurtWater_InitEv                                                   = 0x020cc910;
_ZN6Player17St_HurtWater_MainEv                                                   = 0x020cc7d0;
_ZN6Player19St_Electrocute_InitEv                                                 = 0x020d59b0;
_ZN6Player19St_Electrocute_MainEv                                                 = 0x020d5834;
_ZN6Player16St_BurnFire_InitEv                                                    = 0x020d5750;
_ZN6Player16St_BurnFire_MainEv                                                    = 0x020d53ac;
_ZN6Player16St_BurnLava_InitEv                                                    = 0x020d529c;
_ZN6Player16St_BurnLava_MainEv                                                    = 0x020d5038;
_ZN6Player15St_DeadHit_InitEv                                                     = 0x020c6010;
_ZN6Player15St_DeadHit_MainEv                                                     = 0x020c5e34;
_ZN6Player15St_DeadPit_InitEv                                                     = 0x020c59c0;
_ZN6Player15St_DeadPit_MainEv                                                     = 0x020c5780;
_ZN6Player12St_Walk_InitEv                                                        = 0x020d4270;
_ZN6Player12St_Walk_MainEv                                                        = 0x020d38c0;
_ZN6Player12St_Wait_InitEv                                                        = 0x020d32bc;
_ZN6Player12St_Wait_MainEv                                                        = 0x020d2404;
_ZN6Player15St_Wait_CleanupEv                                                     = 0x020d2378;
_ZN6Player15St_Grabbed_InitEv                                                     = 0x020db4d8;
_ZN6Player15St_Grabbed_MainEv                                                     = 0x020db3bc;
_ZN6Player18St_Grabbed_CleanupEv                                                  = 0x020db368;
_ZN6Player18St_TurnAround_InitEv                                                  = 0x020d369c;
_ZN6Player18St_TurnAround_MainEv                                                  = 0x020d34bc;
_ZN6Player12St_Jump_InitEv                                                        = 0x020e22c0;
_ZN6Player12St_Jump_MainEv                                                        = 0x020e2118;
_ZN6Player12St_Fall_InitEv                                                        = 0x020e1b80;
_ZN6Player12St_Fall_MainEv                                                        = 0x020e1af8;
_ZN6Player14St_Thrown_InitEv                                                      = 0x020db2e8;
_ZN6Player14St_Thrown_MainEv                                                      = 0x020db0bc;
_ZN6Player17St_Thrown_CleanupEv                                                   = 0x020db0a4;
_ZN6Player16St_SideFlip_InitEv                                                    = 0x020e1a10;
_ZN6Player16St_SideFlip_MainEv                                                    = 0x020e13c0;
_ZN6Player24St_SlideKickRecover_InitEv                                            = 0x020e1990;
_ZN6Player24St_SlideKickRecover_MainEv                                            = 0x020e13c0;
_ZN6Player11St_Fly_InitEv                                                         = 0x020e027c;
_ZN6Player11St_Fly_MainEv                                                         = 0x020dfdf0;
_ZN6Player17St_NoControl_InitEv                                                   = 0x020c976c;
_ZN6Player17St_NoControl_MainEv                                                   = 0x020c816c;
_ZN6Player20St_NoControl_CleanupEv                                                = 0x020c8128;
_ZN6Player11St_Owl_InitEv                                                         = 0x020df740;
_ZN6Player11St_Owl_MainEv                                                         = 0x020df3ec;
_ZN6Player14St_Owl_CleanupEv                                                      = 0x020df3c8;
_ZN6Player16St_DebugFly_InitEv                                                    = 0x020ca8d0;
_ZN6Player16St_DebugFly_MainEv                                                    = 0x020ca7f4;
_ZN6Player17St_WindCarry_InitEv                                                   = 0x020dec0c;
_ZN6Player17St_WindCarry_MainEv                                                   = 0x020deab8;
_ZN6Player15St_Balloon_InitEv                                                     = 0x020de8ac;
_ZN6Player15St_Balloon_MainEv                                                     = 0x020de45c;
_ZN6Player18St_Balloon_CleanupEv                                                  = 0x020de3b4;
_ZN6Player16St_Teleport_InitEv                                                    = 0x020c6dc4;
_ZN6Player16St_Teleport_MainEv                                                    = 0x020c6b3c;
_ZN6Player19St_TornadoSpin_InitEv                                                 = 0x020de2a0;
_ZN6Player19St_TornadoSpin_MainEv                                                 = 0x020ddfdc;
_ZN6Player14St_Cannon_InitEv                                                      = 0x020df208;
_ZN6Player14St_Cannon_MainEv                                                      = 0x020def14;
_ZN6Player17St_Cannon_CleanupEv                                                   = 0x020deefc;
_ZN6Player14St_Squish_InitEv                                                      = 0x020c69a0;
_ZN6Player14St_Squish_MainEv                                                      = 0x020c662c;
_ZN6Player17St_Squish_CleanupEv                                                   = 0x020c65f8;
_ZN6Player13St_Shell_InitEv                                                       = 0x020cc780;
_ZN6Player13St_Shell_MainEv                                                       = 0x020cc27c;
_ZN6Player16St_Shell_CleanupEv                                                    = 0x020cc228;
_ZN6Player20St_StomachSlide_InitEv                                                = 0x020dd104;
_ZN6Player20St_StomachSlide_MainEv                                                = 0x020dcc28;
_ZN6Player17St_ButtSlide_InitEv                                                   = 0x020dca80;
_ZN6Player17St_ButtSlide_MainEv                                                   = 0x020dc740;
_ZN6Player18St_DizzyStars_InitEv                                                  = 0x020d82cc;
_ZN6Player18St_DizzyStars_MainEv                                                  = 0x020d828c;
_ZN6Player21St_DizzyStars_CleanupEv                                               = 0x020d8274;
_ZN6Player17St_HoldLight_InitEv                                                   = 0x020d1ea0;
_ZN6Player17St_HoldLight_MainEv                                                   = 0x020d1a1c;
_ZN6Player20St_HoldLight_CleanupEv                                                = 0x020d19fc;
_ZN6Player12St_Bonk_InitEv                                                        = 0x020d4f8c;
_ZN6Player12St_Bonk_MainEv                                                        = 0x020d4de8;
_ZN6Player17St_HoldHeavy_InitEv                                                   = 0x020d19a8;
_ZN6Player17St_HoldHeavy_MainEv                                                   = 0x020d16bc;
_ZN6Player17St_WallSlide_InitEv                                                   = 0x020d0e8c;
_ZN6Player17St_WallSlide_MainEv                                                   = 0x020d0d78;
_ZN6Player24St_BowserEarthquake_InitEv                                            = 0x020c568c;
_ZN6Player24St_BowserEarthquake_MainEv                                            = 0x020c5560;
_ZN6Player16St_WallJump_InitEv                                                    = 0x020e17f8;
_ZN6Player16St_WallJump_MainEv                                                    = 0x020e1714;
_ZN6Player17St_SlopeJump_InitEv                                                   = 0x020e0c04;
_ZN6Player17St_SlopeJump_MainEv                                                   = 0x020e0b50;
_ZN6Player21St_StuckInGround_InitEv                                               = 0x020c54e8;
_ZN6Player21St_StuckInGround_MainEv                                               = 0x020c52bc;
_ZN6Player12St_Land_InitEv                                                        = 0x020e088c;
_ZN6Player12St_Land_MainEv                                                        = 0x020e04ec;
_ZN6Player14St_OnWall_InitEv                                                      = 0x020cfa90;
_ZN6Player14St_OnWall_MainEv                                                      = 0x020cf714;
_ZN6Player12St_Spin_InitEv                                                        = 0x020e119c;
_ZN6Player12St_Spin_MainEv                                                        = 0x020e10ec;
_ZN6Player15St_Spin_CleanupEv                                                     = 0x020e10d4;
_ZN6Player12St_Talk_InitEv                                                        = 0x020c4bd8;
_ZN6Player12St_Talk_MainEv                                                        = 0x020c48e0;
_ZN6Player15St_Talk_CleanupEv                                                     = 0x020c4760;
_ZN6Player19St_CrazedCrate_InitEv                                                 = 0x020e0fac;
_ZN6Player19St_CrazedCrate_MainEv                                                 = 0x020e0d48;
_ZN6Player22St_CrazedCrate_CleanupEv                                              = 0x020e0d28;
_ZN6Player21St_WaitQuicksand_InitEv                                               = 0x020d2224;
_ZN6Player21St_WaitQuicksand_MainEv                                               = 0x020d2184;
_ZN6Player18St_LevelEnter_InitEv                                                  = 0x020c7838;
_ZN6Player18St_LevelEnter_MainEv                                                  = 0x020c6f3c;
_ZN6Player21St_LevelEnter_CleanupEv                                               = 0x020c6f34;
_ZN6Player21St_JumpQuicksand_InitEv                                               = 0x020deeac;
_ZN6Player21St_JumpQuicksand_MainEv                                               = 0x020dedf0;
_ZN6Player14St_Crouch_InitEv                                                      = 0x020d15e0;
_ZN6Player14St_Crouch_MainEv                                                      = 0x020d1354;
_ZN6Player15St_Respawn_InitEv                                                     = 0x020c4088;
_ZN6Player15St_Respawn_MainEv                                                     = 0x020c3f40;
_ZN6Player13St_Crawl_InitEv                                                       = 0x020d112c;
_ZN6Player13St_Crawl_MainEv                                                       = 0x020d0ee0;
_ZN6Player16St_BackFlip_InitEv                                                    = 0x020e18a8;
_ZN6Player16St_BackFlip_MainEv                                                    = 0x020e13c0;
_ZN6Player21St_OpeningWakeUp_InitEv                                               = 0x020c3ed8;
_ZN6Player21St_OpeningWakeUp_MainEv                                               = 0x020c3dd0;
_ZN6Player16St_LongJump_InitEv                                                    = 0x020e127c;
_ZN6Player16St_LongJump_MainEv                                                    = 0x020e1238;
_ZN6Player17St_PunchKick_InitEv                                                   = 0x020dd79c;
_ZN6Player17St_PunchKick_MainEv                                                   = 0x020dd3c4;
_ZN6Player17St_EndingFly_InitEv                                                   = 0x020c3d6c;
_ZN6Player17St_EndingFly_MainEv                                                   = 0x020c3d1c;
_ZN6Player19St_GroundPound_InitEv                                                 = 0x020dddf0;
_ZN6Player19St_GroundPound_MainEv                                                 = 0x020dd9f8;
_ZN6Player22St_GroundPound_CleanupEv                                              = 0x020dd9e0;
_ZN6Player12St_Dive_InitEv                                                        = 0x020dd17c;
_ZN6Player12St_Dive_MainEv                                                        = 0x020dcc28;
_ZN6Player13St_Throw_InitEv                                                       = 0x020dafd4;
_ZN6Player13St_Throw_MainEv                                                       = 0x020dae6c;
_ZN6Player22St_GrabBowserTail_InitEv                                              = 0x020da794;
_ZN6Player22St_GrabBowserTail_MainEv                                              = 0x020da438;
_ZN6Player25St_GrabBowserTail_CleanupEv                                           = 0x020da41c;
_ZN6Player19St_SwingPlayer_InitEv                                                 = 0x020da3b0;
_ZN6Player19St_SwingPlayer_MainEv                                                 = 0x020d9fec;
_ZN6Player22St_SwingPlayer_CleanupEv                                              = 0x020d9fc4;
_ZN6Player17St_SweepKick_InitEv                                                   = 0x020dc510;
_ZN6Player17St_SweepKick_MainEv                                                   = 0x020dc48c;
_ZN6Player17St_SlideKick_InitEv                                                   = 0x020dc3e0;
_ZN6Player17St_SlideKick_MainEv                                                   = 0x020dc1d0;
_ZN6Player18St_CameraZoom_InitEv                                                  = 0x020caef4;
_ZN6Player18St_CameraZoom_MainEv                                                  = 0x020cad10;
_ZN6Player21St_CameraZoom_CleanupEv                                               = 0x020cac38;
_ZN6Player12St_Null_InitEv                                                        = 0x020cac30;
_ZN6Player12St_Null_MainEv                                                        = 0x020cac28;
_ZN6Player15St_Null_CleanupEv                                                     = 0x020cac20;
_ZN6Player12St_Swim_InitEv                                                        = 0x020ce550;
_ZN6Player12St_Swim_MainEv                                                        = 0x020cd94c;
_ZN6Player15St_Swim_CleanupEv                                                     = 0x020cd1e4;
_ZN6Player17St_WaterJump_InitEv                                                   = 0x020e162c;
_ZN6Player17St_WaterJump_MainEv                                                   = 0x020e13c0;
_ZN6Player24St_MetalWaterGround_InitEv                                            = 0x020cd0d0;
_ZN6Player24St_MetalWaterGround_MainEv                                            = 0x020ccccc;
_ZN6Player27St_MetalWaterGround_CleanupEv                                         = 0x020cd1e4;
_ZN6Player23St_MetalWaterWater_InitEv                                             = 0x020ccc3c;
_ZN6Player23St_MetalWaterWater_MainEv                                             = 0x020cc9c0;
_ZN6Player26St_MetalWaterWater_CleanupEv                                          = 0x020cd1e4;
_ZN6Player13St_Climb_InitEv                                                       = 0x020cbd34;
_ZN6Player13St_Climb_MainEv                                                       = 0x020cb5bc;
_ZN6Player16St_Climb_CleanupEv                                                    = 0x020cb568;
_ZN6Player17St_Headstand_InitEv                                                   = 0x020cb2f0;
_ZN6Player17St_Headstand_MainEv                                                   = 0x020cb15c;
_ZN6Player20St_Headstand_CleanupEv                                                = 0x020cb568;
_ZN6Player16St_PoleJump_InitEv                                                    = 0x020e17f8;
_ZN6Player16St_PoleJump_MainEv                                                    = 0x020e1714;
_ZN6Player21St_HeadstandJump_InitEv                                               = 0x020e16a4;
_ZN6Player21St_HeadstandJump_MainEv                                               = 0x020e13c0;

/* Actors/PowerStar.h */
_ZN9PowerStar13AddStarMarkerEv                                                    = 0x020e8ca0;

/* Actors/StarMarker.h */
_ZN10StarMarker27SpawnRedCoinStarIfNecessaryEv                                    = 0x020e72d8;

/* Particle.h */
_ZN8Particle12Acceleration4FuncERNS_10EffectDataEPcR7Vector3                      = 0x0204d8b0;
_ZN8Particle6Jitter4FuncERNS_10EffectDataEPcR7Vector3                             = 0x0204d7ec;
_ZN8Particle8Converge4FuncERNS_10EffectDataEPcR7Vector3                           = 0x0204d758;
_ZN8Particle4Turn4FuncERNS_10EffectDataEPcR7Vector3                               = 0x0204d680;
_ZN8Particle10LimitPlane4FuncERNS_10EffectDataEPcR7Vector3                        = 0x0204d57c;
_ZN8Particle14RadiusConverge4FuncERNS_10EffectDataEPcR7Vector3                    = 0x0204d4d0;

_ZN8Particle7Texture12AllocTexVramEjb                                             = 0x02023134;
_ZN8Particle7Texture12AllocPalVramEjb                                             = 0x020230ec;

_ZTVN8Particle8CallbackE                                                          = 0x0208f3b4;
_ZN8Particle8Callback14SpawnParticlesERNS_6SystemE                                = 0x020226d0;
_ZN8Particle8Callback8OnUpdateERNS_6SystemEb                                      = 0x020226c8;

_ZTVN8Particle14SimpleCallbackE                                                   = 0x0208f3c4;
_ZN8Particle14SimpleCallbackC2Ev                                                  = 0x02022680;
_ZN8Particle14SimpleCallback14SpawnParticlesERNS_6SystemE                         = 0x02022640;
_ZN8Particle14SimpleCallback8OnUpdateERNS_6SystemEb                               = 0x02022630;

_ZTVN8Particle25EndingStarGlitterCallbackE                                        = 0x0208f3d4;
_ZN8Particle25EndingStarGlitterCallback14SpawnParticlesERNS_6SystemE              = 0x0202222c;
_ZN8Particle25EndingStarGlitterCallback8OnUpdateERNS_6SystemEb                    = 0x020221dc;

_ZTVN8Particle14BubbleCallbackE                                                   = 0x0208f3a4;
_ZN8Particle14BubbleCallback8OnUpdateERNS_6SystemEb                               = 0x02022464;

_ZTVN8Particle14SplashCallbackE                                                   = 0x0208f3e4;
_ZN8Particle14SplashCallback8OnUpdateERNS_6SystemEb                               = 0x020224fc;

_ZTVN8Particle18CheckWaterCallbackE                                               = 0x0208f3f4;
_ZN8Particle18CheckWaterCallback8OnUpdateERNS_6SystemEb                           = 0x02022160;

_ZTVN8Particle17CheckLavaCallbackE                                                = 0x0208f404;
_ZN8Particle17CheckLavaCallback14SpawnParticlesERNS_6SystemE                      = 0x02022328;
_ZN8Particle17CheckLavaCallback8OnUpdateERNS_6SystemEb                            = 0x020222f0;

_ZTVN8Particle13ScaleCallbackE                                                    = 0x0208f414;
_ZN8Particle13ScaleCallback14SpawnParticlesERNS_6SystemE                          = 0x020225d0;
_ZN8Particle13ScaleCallback8OnUpdateERNS_6SystemEb                                = 0x020225a8;

_ZTVN8Particle24CheckWaterRippleCallbackE                                         = 0x0208f424;
_ZN8Particle24CheckWaterRippleCallback8OnUpdateERNS_6SystemEb                     = 0x020220a4;

_ZTVN8Particle12ClipCallbackE                                                     = 0x0208f434;
_ZN8Particle12ClipCallback8OnUpdateERNS_6SystemEb                                 = 0x02021e70;

_ZTVN8Particle22FitWaterSimpleCallbackE                                           = 0x0208f444;
_ZN8Particle22FitWaterSimpleCallback8OnUpdateERNS_6SystemEb                       = 0x02022418;

_ZTVN8Particle16FitWaterCallbackE                                                 = 0x0208f454;
_ZN8Particle16FitWaterCallback8OnUpdateERNS_6SystemEb                             = 0x0202202c;

_ZTVN8Particle21CleanParticleCallbackE                                            = 0x0208f464;
_ZN8Particle21CleanParticleCallback8OnUpdateERNS_6SystemEb                        = 0x02021e40;

_ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE            = 0x02022d80;
_ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_                                    = 0x02022e98;
_ZN8Particle6System10NewWeatherEjj5Fix12IiES2_S2_PK11Vector3_16fj                 = 0x02022bf8;
_ZN8Particle6System9NewRippleE5Fix12IiES2_S2_                                     = 0x02022998;
_ZN8Particle6System12NewBigSplashE5Fix12IiES2_S2_                                 = 0x02022aa8;
_ZN8Particle6System17NewUnkCallback818Ejj5Fix12IiES2_S2_PK11Vector3_16f           = 0x02022bb4;
_ZN8Particle6System12FromUniqueIDEj                                               = 0x02022e68;

_ZN8Particle7Manager9AddSystemEiR7Vector3                                         = 0x02049e0c;

_ZN8Particle10SysTrackerC1Ev                                                      = 0x02023204;
_ZN8Particle10SysTrackerD1Ev                                                      = 0x02023194;
_ZN8Particle10SysTracker10InitialiseEv                                            = 0x02022f40;
_ZN8Particle10SysTracker6UpdateEv                                                 = 0x02022f20;

_ZNK8Particle10SysTracker8Contents8FindDataEj                                     = 0x02021b58;

_ZN8Particle20RunningSlidingDustAtE5Fix12IiES1_S1_                                = 0x02022b58;
_ZN8Particle19SetSelfDestructFlagEj                                               = 0x020226d4;
_ZN8Particle9RenderAllEv                                                          = 0x02022ee0;

PARTICLE_ROM_EMBEDDED_FILE                                                        = 0x02075f14;

PARTICLE_SPA_FILE                                                                 = 0x020230d8;
PARTICLE_SYS_TRACKER                                                              = 0x0209ee74;
PARTICLE_RNG_STATE                                                                = 0x020a4d30;

/* Sound.h */
_ZN5Sound17InfoSequenceEntry9GetWithIDEj                                          = 0x02050c78;
_ZN5Sound23InfoInstrumentBankEntry9GetWithIDEj                                    = 0x02050bb0;

_ZN5Sound8SDAT_RAM3PTRE                                                           = 0x020a5bb8;
_ZN5Sound7FileRef5PTR_0E                                                          = 0x0209b4a0;

_ZN5Sound6Player19SetPlayableSeqCountEii                                          = 0x0204fadc;

_ZN5Sound7PLAYERSE                                                                = 0x020a4d6c;

_ZN5Sound8PlayLongEjjjRK7Vector3j                                                 = 0x02012328;
_ZN5Sound13PlayCharVoiceEjjRK7Vector3                                             = 0x02012154;
_ZN5Sound4PlayEjjRK7Vector3                                                       = 0x02012590;
_ZN5Sound6Play2DEjj                                                               = 0x02012840;
_ZN5Sound7PlaySubEjjj5Fix12IiEb                                                   = 0x02012be0;
_ZN5Sound20PlaySmallSecretSoundEP5ActorPt                                         = 0x0200f874;
_ZN5Sound15PlaySecretSoundEP5ActorPt                                              = 0x0200f8f8;

_ZN5Sound19LoadGroupAndSetBankEii                                                 = 0x0201200c;
_ZN5Sound16LoadInitialGroupEi                                                     = 0x02011ffc;
_ZN5Sound21UnsetPlayerVoiceGroupEv                                                = 0x02011fe8;
_ZN5Sound21ResetPlayerVoiceGroupEv                                                = 0x02011f30;

_ZN5Sound22LoadAndSetMusic_Layer1Ei                                               = 0x0201320c;
_ZN5Sound22StopLoadedMusic_Layer1Ej                                               = 0x02013050;
_ZN5Sound22LoadAndSetMusic_Layer2Ej                                               = 0x02012940;
_ZN5Sound22StopLoadedMusic_Layer2Ev                                               = 0x020128c4;
_ZN5Sound22LoadAndSetMusic_Layer3Ej                                               = 0x02012bbc;
_ZN5Sound22StopLoadedMusic_Layer3Ev                                               = 0x02012af8;
_ZN5Sound8SetMusicEjj                                                             = 0x02012a68;
_ZN5Sound8EndMusicEjj                                                             = 0x02012998;
_ZN5Sound10PauseMusicEv                                                           = 0x02012f90;
_ZN5Sound12UnpauseMusicEv                                                         = 0x02012ee4;
_ZN5Sound17ChangeMusicVolumeEj5Fix12IiE                                           = 0x02012d2c;
_ZN5Sound13Func_02048eb4Ev                                                        = 0x02048eb4;
_ZN5Sound13Func_02048ec4Ev                                                        = 0x02048ec4;
_ZN5Sound13Func_02048ee4Ev                                                        = 0x02048ee4;

MUSIC_VOLUME_LSL_12                                                               = 0x0209b490;
MESSAGE_SOUND_VOLUME_LSL_12                                                       = 0x0209b49c;

JRB_SOUND_SPECIFICS                                                               = 0x0208e434;
SOUND_SPECIFICS                                                                   = 0x0208e438;

/* Save.h */
_ZN8SaveData15SaveCurrentFileEv                                                   = 0x02013b9c;
_ZN8SaveData8SaveFileEjP12FileSaveData                                            = 0x02013d14;
_ZN8SaveData13SaveMinigamesEP16MinigameSaveData                                   = 0x02013be0;
_ZN8SaveData14SaveDataToCartEPcjj                                                 = 0x02042c3c;
_ZN8SaveData16EraseAllSaveDataEv                                                  = 0x02013e0c;
_ZN8SaveData13EraseSaveFileEjPc                                                   = 0x02013cd4;
_ZN8SaveData16SetDefaultValuesEP12FileSaveData                                    = 0x02013dc4;
_ZN8SaveData18SetDefaultValuesMgEP16MinigameSaveData                              = 0x02013c5c;

_ZN8SaveData16ReadDataFromCartEPcjj                                               = 0x02042804;
_ZN8SaveData16ReadMinigameDataEP16MinigameSaveData                                = 0x02013c0c;
_ZN8SaveData12ReadFileDataEjP12FileSaveData                                       = 0x02013d54;

_ZN8SaveData26CountStarsCollectedInLevelEj                                        = 0x02013768;
_ZN8SaveData19IsCharacterUnlockedEj                                               = 0x0201392c;
_ZN8SaveData13GetCoinRecordEj                                                     = 0x0201366c;
_ZN8SaveData21SetCoinRecordIfHigherEah                                            = 0x02013650;
_ZN8SaveData22NumGlowingRabbitsFoundEv                                            = 0x02013984;
_ZN8SaveData17SetCharacterIntroEi                                                 = 0x02013910;

_ZN8SaveData16CanPlayerHaveCapEv                                                  = 0x02013b5c;
_ZN8SaveData16HasPlayerLostCapEv                                                  = 0x02013b18;
_ZN8SaveData13PlayerLoseCapEv                                                     = 0x02013ad4;

SAVE_DATA                                                                         = 0x0209caa0;

/* Input.h */
INPUT_ARR                                                                         = 0x0209f498;
CAMERA_INPUT_ARR                                                                  = 0x0209f368;
INPUT_RELATED_ARR                                                                 = 0x020a1158;
TOUCH_INPUT_ARR                                                                   = 0x020a0de8;
BUTTON_INPUT_ARR                                                                  = 0x020a0e58;

/* Memory.h */
_ZN18NestedHeapIteratorC1Ej                                                       = 0x0204DF20;
_ZN18NestedHeapIterator8PreviousEP13HeapAllocator                                 = 0x0204DCFC;
_ZN18NestedHeapIterator4NextEP13HeapAllocator                                     = 0x0204DD10;
_ZN18NestedHeapIterator10FindNestedEPv                                            = 0x0204DFE8;
_ZN18NestedHeapIterator19RecursiveFindNestedEPv                                   = 0x0204E014;
_ZN18NestedHeapIterator8AddFirstEP13HeapAllocator                                 = 0x0204DE0C;
_ZN18NestedHeapIterator7AddLastEP13HeapAllocator                                  = 0x0204DE74;
_ZN18NestedHeapIterator4InitEP13HeapAllocator                                     = 0x0204DEE0;
_ZN18NestedHeapIterator6RemoveEP13HeapAllocator                                   = 0x0204DD28;
_ZN18NestedHeapIterator5AddAtEP13HeapAllocatorS1_                                 = 0x0204DD98;

_ZN13HeapAllocatorC1EjPvPvj                                                       = 0x0204DF54;
_ZN13HeapAllocator6RemoveEv                                                       = 0x0204DF38;
_ZN13HeapAllocator7DestroyEv                                                      = 0x0204E3B4;

_ZN10MemoryNode6TargetC1EP10MemoryNode                                            = 0x0204E938;

_ZN22ExpandingHeapAllocatorC1EPvj                                                 = 0x0204E828;
_ZN22ExpandingHeapAllocator12AllocateNodeEP10MemoryNodeS1_Pvjj                    = 0x0204E690;
_ZN22ExpandingHeapAllocator8FreeNodeEP10MemoryNodePNS0_6TargetE                   = 0x0204E40C;
_ZN22ExpandingHeapAllocator8LinkNodeEP10MemoryNodeS1_S1_                          = 0x0204E8E0;
_ZN22ExpandingHeapAllocator10UnlinkNodeEP10MemoryNodeS1_                          = 0x0204E910;
_ZN22ExpandingHeapAllocator10CreateNodeEPN10MemoryNode6TargetEt                   = 0x0204E8B0;
_ZN22ExpandingHeapAllocator14SizeofInternalEPv                                    = 0x0204E084;
_ZN22ExpandingHeapAllocator16AllocateForwardsEjj                                  = 0x0204E5C8;
_ZN22ExpandingHeapAllocator17AllocateBackwardsEjj                                 = 0x0204E504;
_ZN22ExpandingHeapAllocator8AllocateEji                                           = 0x0204E370;
_ZN22ExpandingHeapAllocator10DeallocateEPv                                        = 0x0204E1A8;
_ZN22ExpandingHeapAllocator10ReallocateEPvj                                       = 0x0204E1E8;
_ZN22ExpandingHeapAllocator10MemoryLeftEv                                         = 0x0204E180;
_ZN22ExpandingHeapAllocator18MaxAllocatableSizeEi                                 = 0x0204E0F8;
_ZN22ExpandingHeapAllocator9SetNodeIDEj                                           = 0x0204E0E8;
_ZN22ExpandingHeapAllocator9GetNodeIDEv                                           = 0x0204E0E0;
_ZN22ExpandingHeapAllocator13DeallocateAllEPPFvPvPS_jEj                           = 0x0204E08C;
_ZN22ExpandingHeapAllocator16InvokeDeallocateEPvPS_j                              = 0x0203C4CC;

_ZN18SolidHeapAllocatorC1EPvj                                                     = 0x0204ED54;
_ZN18SolidHeapAllocator8AllocateEji                                               = 0x0204EB70;
_ZN18SolidHeapAllocator16AllocateForwardsEPvjj                                    = 0x0204ECD4;
_ZN18SolidHeapAllocator17AllocateBackwardsEPvjj                                   = 0x0204EC58;
_ZN18SolidHeapAllocator10ReallocateEPvj                                           = 0x0204E964;
_ZN18SolidHeapAllocator10MemoryLeftEi                                             = 0x0204EAF0;
_ZN18SolidHeapAllocator14TryResizeToFitEv                                         = 0x0204EA08;
_ZN18SolidHeapAllocator9SaveStateEj                                               = 0x0204EA98;
_ZN18SolidHeapAllocator9LoadStateEj                                               = 0x0204EA3C;
_ZN18SolidHeapAllocator5ResetEj                                                   = 0x0204EB30;
_ZN18SolidHeapAllocator10ResetStartEv                                             = 0x0204EC40;
_ZN18SolidHeapAllocator8ResetEndEv                                                = 0x0204EC10;

_ZTV4Heap                                                                         = 0x02099D90;
_ZN4Heap15CreateSolidHeapEjPS_i                                                   = 0x0203C7A0;
_ZN4Heap19CreateExpandingHeapEjPS_i                                               = 0x0203C844;
_ZN4Heap24CreateSolidHeapAllocatorEPvjj                                           = 0x0204EBC4;
_ZN4Heap28CreateExpandingHeapAllocatorEPvjj                                       = 0x0204E3C0;
_ZN4Heap14CreateRootHeapEPvj                                                      = 0x0203C8E8;
_ZN4Heap13SetupRootHeapEv                                                         = 0x0203CB04;
_ZN4Heap18InitializeRootHeapEv                                                    = 0x0203CAE8;
_ZN4Heap18InitializeGameHeapEjPS_                                                 = 0x0203C24C;
_ZN4Heap23SetupSolidHeapAsDefaultEjPS_i                                           = 0x0203C2E4;
_ZN4Heap28InitializeSolidHeapAsDefaultEjPS_i                                      = 0x0203C2D8;
_ZN4Heap20RestoreFromTemporaryEv                                                  = 0x0203C2A8;
_ZN4HeapC1EPvjP4Heap                                                              = 0x0203CAAC;
_ZN4HeapD0Ev                                                                      = 0x0203CA20;
_ZN4HeapD1Ev                                                                      = 0x0203CA44;
_ZN4HeapD2Ev                                                                      = 0x0203CA10;
_ZN4Heap8AllocateEji                                                              = 0x0203C6CC;
_ZN4Heap9_AllocateEji                                                             = 0x0203C29C;
_ZN4Heap8AllocateEj                                                               = 0x0203C28C;
_ZN4Heap10DeallocateEPv                                                           = 0x0203C538;
_ZN4Heap11_DeallocateEPv                                                          = 0x0203C280;
_ZN4Heap7DestroyEv                                                                = 0x0203C758;
_ZN4Heap8_DestroyEv                                                               = 0x0203C74c;
_ZN4Heap6SizeofEPv                                                                = 0x0203C454;
_ZN4Heap7_SizeofEPv                                                               = 0x0203C274;
_ZN4Heap11ResizeToFitEv                                                           = 0x0203C390;
_ZN4Heap10ReallocateEPvj                                                          = 0x0203C578;
_ZN4Heap21MaxAllocationUnitSizeEv                                                 = 0x0203C60C;
_ZN4Heap6IntactEv                                                                 = 0x0203C664;
_ZN4Heap9SetNodeIDEj                                                              = 0x0203C408;
_ZN4Heap6RescueEv                                                                 = 0x0203C634;
_ZN4Heap10SetDefaultEv                                                            = 0x0203C324;

_ZTV13ExpandingHeap                                                               = 0x02099DD8;
_ZN13ExpandingHeapC1EPvjP4HeapP22ExpandingHeapAllocator                           = 0x0203CA80;
_ZN13ExpandingHeapC2EPvjP4HeapP22ExpandingHeapAllocator                           = 0x0203CA80;
_ZN13ExpandingHeapD0Ev                                                            = 0x0203C9C0;
_ZN13ExpandingHeapD1Ev                                                            = 0x0203C9EC;
_ZN13ExpandingHeapD2Ev                                                            = 0x0203C9EC;
_ZN13ExpandingHeap8VDestroyEv                                                     = 0x0203C72C;
_ZN13ExpandingHeap9VAllocateEji                                                   = 0x0203C6BC;
_ZN13ExpandingHeap11VDeallocateEPv                                                = 0x0203C50C;
_ZN13ExpandingHeap14VDeallocateAllEv                                              = 0x0203C4B0;
_ZN13ExpandingHeap7VIntactEv                                                      = 0x0203C65C;
_ZN13ExpandingHeap7VRescueEv                                                      = 0x0203C630;
_ZN13ExpandingHeap11VReallocateEPvj                                               = 0x0203C568;
_ZN13ExpandingHeap7VSizeofEPv                                                     = 0x0203C444;
_ZN13ExpandingHeap22VMaxAllocationUnitSizeEv                                      = 0x0203C5F8;
_ZN13ExpandingHeap19VMaxAllocatableSizeEv                                         = 0x0203C5D0;
_ZN13ExpandingHeap11VMemoryLeftEv                                                 = 0x0203C5AC;
_ZN13ExpandingHeap10VSetNodeIDEj                                                  = 0x0203C3F8;
_ZN13ExpandingHeap10VGetNodeIDEv                                                  = 0x0203C3E0;
_ZN13ExpandingHeap12VResizeToFitEv                                                = 0x0203C388;

_ZTV9SolidHeap                                                                    = 0x02099D48;
_ZN9SolidHeapC1EPvjP4HeapP18SolidHeapAllocator                                    = 0x0203CA54;
_ZN9SolidHeapD0Ev                                                                 = 0x0203C970;
_ZN9SolidHeapD1Ev                                                                 = 0x0203C99C;
_ZN9SolidHeap8VDestroyEv                                                          = 0x0203C70C;
_ZN9SolidHeap9VAllocateEjj                                                        = 0x0203C6AC;
_ZN9SolidHeap11VDeallocateEPv                                                     = 0x0203C4E4;
_ZN9SolidHeap14VDeallocateAllEv                                                   = 0x0203C49C;
_ZN9SolidHeap7VIntactEv                                                           = 0x0203C654;
_ZN9SolidHeap7VRescueEv                                                           = 0x0203C62C;
_ZN9SolidHeap11VReallocateEPvj                                                    = 0x0203C558;
_ZN9SolidHeap7VSizeofEPv                                                          = 0x0203C428;
_ZN9SolidHeap22VMaxAllocationUnitSizeEv                                           = 0x0203C5E4;
_ZN9SolidHeap19VMaxAllocatableSizeEv                                              = 0x0203C5BC;
_ZN9SolidHeap11VMemoryLeftEv                                                      = 0x0203C598;
_ZN9SolidHeap10VSetNodeIDEj                                                       = 0x0203C3F0;
_ZN9SolidHeap10VGetNodeIDEv                                                       = 0x0203C3D8;
_ZN9SolidHeap12VResizeToFitEv                                                     = 0x0203C33C;

_ZN6Memory11heapDamagedE                                                          = 0x020A0E98;
_ZN6Memory11rootHeapPtrE                                                          = 0x020A0E9C;
_ZN6Memory14defaultHeapPtrE                                                       = 0x020A0EA0;
_ZN6Memory15rootParamOffsetE                                                      = 0x020A0EA4;
_ZN6Memory10tmpHeapPtrE                                                           = 0x020A0EA8;
_ZN6Memory11gameHeapPtrE                                                          = 0x020A0EAC;
_ZN6Memory25isRootHeapIterInitializedE                                            = 0x020A4D34;
_ZN6Memory16rootHeapIteratorE                                                     = 0x020A4D38;
_ZN6Memory17nextRootHeapStartE                                                    = 0x023FFDA0;
_ZN6Memory11rootHeapEndE                                                          = 0x023FFDC4;
_ZN6Memory8AllocateEjiP4Heap                                                      = 0x0203C210;
_ZN6Memory8AllocateEji                                                            = 0x0203C1D8;
_ZN6Memory8AllocateEj                                                             = 0x0203C1C4;
_ZN6Memory13operator_new2Ej                                                       = 0x0203CBD8;
_ZN6Memory10DeallocateEPvP4Heap                                                   = 0x0203C1E8;
_ZN6Memory10DeallocateEPv                                                         = 0x0203C1B4;
_ZN6Memory16operator_delete2EPv                                                   = 0x0203CBCC;
_ZN6Memory6mallocEj                                                               = 0x0203CC0C;
_ZN6Memory4freeEPv                                                                = 0x0203CBF0;

/* Actor/Scene.h */
_ZTV5Scene                                                                        = 0x02092680;
_ZN5SceneD0Ev                                                                     = 0x0202e170;
_ZN5SceneD1Ev                                                                     = 0x0202e140;
_ZN5SceneD2Ev                                                                     = 0x0202e140;
_ZN5Scene19BeforeInitResourcesEv                                                  = 0x0202e638;
_ZN5Scene18AfterInitResourcesEj                                                   = 0x0202e62c;
_ZN5Scene22BeforeCleanupResourcesEv                                               = 0x0202e5f0;
_ZN5Scene21AfterCleanupResourcesEj                                                = 0x0202e5d0;
_ZN5Scene14BeforeBehaviorEv                                                       = 0x0202e3d4;
_ZN5Scene13AfterBehaviorEj                                                        = 0x0202e3c8;
_ZN5Scene12BeforeRenderEv                                                         = 0x0202e3a4;
_ZN5Scene11AfterRenderEj                                                          = 0x0202e398;
_ZN5Scene19ResetFadersAndSoundEv                                                  = 0x0202e66c;
_ZN5Scene20SetAndStopColorFaderEv                                                 = 0x0202e1b4;
_ZN5Scene9SetFadersEP15FaderBrightness                                            = 0x0202e1e0;
_ZN5Scene16SpawnIfNecessaryEv                                                     = 0x0202e26c;
_ZN5Scene18PrepareToSpawnBootEv                                                   = 0x0202e300;
_ZN5Scene14StartSceneFadeEjjt                                                     = 0x0202e348;
_ZN5Scene20Initialise3dGraphicsEv                                                 = 0x0202e6c8;
_ZN5Scene22ResetHardwareRegistersEv                                               = 0x0202e7d4;
_ZN5Scene15SetSceneToSpawnEjj                                                     = 0x0202e36c;

_ZN5Scene14GraphCallback0Ev                                                       = 0x02018eb8;
_ZN5Scene14GraphCallback1Ev                                                       = 0x02018eb0;
_ZN5Scene14GraphCallback2Ev                                                       = 0x02018ea8;
_ZN5Scene14GraphCallback3Ev                                                       = 0x02018ea0;

SCENE_RELATED                                                                     = 0x0209d4a8;
STAGE_SCENE_RELATED                                                               = 0x0209f3c4;
SCENE_FADER                                                                       = 0x0209f5bc;
DEFAULT_SCENE_FADER                                                               = 0x0209f5e8;

/* Actors/BootScene.h */
_ZTV9BootScene                                                                    = 0x02091528;

/* Actors/MultiBootScene.h */
_ZTV14MultiBootScene                                                              = 0x020943C4;

/* Actors/Stage.h */
_ZN3Fog4InitEt5Fix12IiES1_                                                        = 0x0202c830;

_ZTV5Stage                                                                        = 0x020921c0;

_ZN5Stage9spawnDataE                                                              = 0x0209213c;

_ZN5StageC1Ev                                                                     = 0x0202e088;
_ZN5StageC2Ev                                                                     = 0x0202e088;
_ZN5Stage13InitResourcesEv                                                        = 0x0202cc0c;
_ZN5Stage19BeforeInitResourcesEv                                                  = 0x0202ddc8;
_ZN5Stage16CleanupResourcesEv                                                     = 0x0202c9a8;
_ZN5Stage8BehaviorEv                                                              = 0x0202bbbc;
_ZN5Stage6RenderEv                                                                = 0x0202b8a4;
_ZN5Stage16OnPendingDestroyEv                                                     = 0x0202b8a0;
_ZN5StageD2Ev                                                                     = 0x02023688;
_ZN5StageD1Ev                                                                     = 0x02023688;
_ZN5StageD0Ev                                                                     = 0x020236f0;

_ZN5Stage7LoadFogEv                                                               = 0x0202b710;
_ZN5Stage9LoadModelEv                                                             = 0x0202b5ec;
_ZN5Stage23LoadTextureTransformersEv                                              = 0x0202b534;
_ZN5Stage10LoadSkyboxEv                                                           = 0x0202b0fc;
_ZN5Stage9RenderFogEv                                                             = 0x0202b67c;
_ZN5Stage11RenderModelEv                                                          = 0x0202b268;
_ZN5Stage22RenderModelTransparentEv                                               = 0x0202b164;

_ZN5Stage12SetVramBanksEv                                                         = 0x0202e73c;
_ZN5Stage18ResetMeshCollidersEv                                                   = 0x020391f4;
_ZN5Stage18LoadClsnAndObjectsER11LVL_OverlayjR12MeshCollider                      = 0x020fe190;
_ZN5Stage14LoadGraphics2DEbi                                                      = 0x0202d690;

_ZN5Stage11GetSkyboxIDEv                                                          = 0x0202a93c;
_ZN5Stage8CanPauseEv                                                              = 0x0202b818;
_ZN5Stage15IsPauseDisabledEv                                                      = 0x0202a5c4;

_ZN5Stage16CheckCameraInputEv                                                     = 0x02024c70;
_ZN5Stage10CheckInputEv                                                           = 0x0202c2ac;
_ZN5Stage13UpdateMessageEv                                                        = 0x0201cb7c;

_ZN5Stage21RenderVsModeCountdownEv                                                = 0x0202a168;
_ZN5Stage19RenderVsModeNewStarEv                                                  = 0x02029ef8;
_ZN5Stage20RenderBouncingArrowsEv                                                 = 0x02023be0;
_ZN5Stage12RenderNumberEhiibi                                                     = 0x020250d0;

_ZN5Stage17UpdateMenuButtonsEb                                                    = 0x02026148;

_ZN5Stage9LC_UpdateEv                                                             = 0x020242c8;
_ZN5Stage9LC_RenderEv                                                             = 0x02023db8;

_ZN5Stage7VE_InitEv                                                               = 0x02023a80;
_ZN5Stage9VE_UpdateEv                                                             = 0x0202376c;

_ZN5Stage7PS_InitEv                                                               = 0x0202942c;
_ZN5Stage9PS_UpdateEv                                                             = 0x0202635c;
_ZN5Stage10PS_CleanupEv                                                           = 0x02026290;
_ZN5Stage9PS_RenderEv                                                             = 0x020251d0;
_ZN5Stage25PS_UpdateOkAndBackButtonsEb                                            = 0x02025d20;
_ZN5Stage20PS_UpdateOptionsMenuEv                                                 = 0x02025f60;
_ZN5Stage17PS_UpdateSaveMenuEb                                                    = 0x02025e74;

_ZN5Stage14GraphCallback1Ev                                                       = 0x02029838;
_ZN5Stage14GraphCallback2EP12SceneRelated                                         = 0x020297f4;

LEVEL_FILE                                                                        = 0x0209f340;
LEVEL_MODEL_DATA                                                                  = 0x0209f320;

NUM_ENTRANCES                                                                     = 0x0209f214;
NUM_PATHS                                                                         = 0x020a0d8c;
NUM_VIEWS                                                                         = 0x0209f1f8;
NUM_TELEPORT_DEST_OBJS                                                            = 0x0209f2d0;
NUM_FOG_OBJS                                                                      = 0x0209f258;
MAP_TILE_ARR_SIZE                                                                 = 0x0209f2e8;
NUM_MINIMAP_SCALE_OBJS                                                            = 0x0209f25c;

ENTRANCE_ARR_PTR                                                                  = 0x0209f328;
PATH_NODE_ARR_PTR                                                                 = 0x020a0d88;
PATH_ARR_PTR                                                                      = 0x020a0d84;
VIEW_ARR_PTR                                                                      = 0x0209f354;
TELEPORT_DEST_OBJS_PTR                                                            = 0x0209f330;
FOG_OBJS_PTR                                                                      = 0x0209f31c;
MAP_TILE_ARR_PTR                                                                  = 0x0209f334;
MINIMAP_SCALE_OBJS_PTR                                                            = 0x0209f348;
UNUSED_TYPE_13_OBJS_PTR                                                           = 0x0209f338;
	
STAR_CAMERA_SETTINGS                                                              = 0x02092134;

_Z11LoadObjectsRN11LVL_Overlay8ObjTableEij                                        = 0x020fe33c;

_Z19LoadStandardObjectsRN11LVL_Overlay11ObjSubTableEij                            = 0x020fe8ac;
_Z19LoadEntranceObjectsRN11LVL_Overlay11ObjSubTableEij                            = 0x020fe6c8;
_Z19LoadPathNodeObjectsRN11LVL_Overlay11ObjSubTableEij                            = 0x020fe6b8;
_Z15LoadPathObjectsRN11LVL_Overlay11ObjSubTableEij                                = 0x020fe6a4;
_Z15LoadViewObjectsRN11LVL_Overlay11ObjSubTableEij                                = 0x020fe690;
_Z17LoadSimpleObjectsRN11LVL_Overlay11ObjSubTableEij                              = 0x020fe960;
_Z25LoadTeleportSourceObjectsRN11LVL_Overlay11ObjSubTableEij                      = 0x020fe5f4;
_Z23LoadTeleportDestObjectsRN11LVL_Overlay11ObjSubTableEij                        = 0x020fe5e0;
_Z14LoadFogObjectsRN11LVL_Overlay11ObjSubTableEij                                 = 0x020fe5cc;
_Z15LoadDoorObjectsRN11LVL_Overlay11ObjSubTableEij                                = 0x020fe4f0;
_Z15LoadExitObjectsRN11LVL_Overlay11ObjSubTableEij                                = 0x020fe420;
_Z22LoadMinimapTileObjectsRN11LVL_Overlay11ObjSubTableEij                         = 0x020fe40c;
_Z23LoadMinimapScaleObjectsRN11LVL_Overlay11ObjSubTableEij                        = 0x020fe3f8;
_Z23LoadUnusedType13ObjectsRN11LVL_Overlay11ObjSubTableEij                        = 0x020fe3e4;
_Z21LoadStarCameraObjectsRN11LVL_Overlay11ObjSubTableEij                          = 0x020fe3cc;

_Z23LoadMinimapChangeObjecti5Fix12IiEh                                            = 0x0202a994;

_Z17LoadLevelOverlaysi                                                            = 0x0202ded4;
_Z19UnloadLevelOverlaysi                                                          = 0x0202de64;
_Z26LoadOrUnloadObjectOverlaysPFviEi                                              = 0x0202df70;

_Z6DLLoadi                                                                        = 0x02090864;
_Z21DLCleanAllUsedByLevelv                                                        = 0x02090900;
_Z20DLLoadAllUsedByLevelv                                                         = 0x0209098c;

/* OAM.h */
_ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2                                          = 0x020214a4;
_ZN3OAM6RenderEbP7OamAttriiii5Fix12IiEi                                           = 0x02021024;
_ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii                                       = 0x02020994;
_ZN3OAM11GetObjWidthEii                                                           = 0x02020980;
_ZN3OAM12GetObjHeightEii                                                          = 0x0202096c;
_ZN3OAM16LoadAffineParamsEP7OamAttrPiP9Matrix2x2                                  = 0x02020884;

_ZN3OAM9objHeightE                                                                = 0x020755ac;
_ZN3OAM8objWidthE                                                                 = 0x020755a0;
_ZN3OAM14subOAMDisabledE                                                          = 0x0209e660;
_ZN3OAM16curAffineSetMainE                                                        = 0x0209e668;
_ZN3OAM15curAffineSetSubE                                                         = 0x0209e66c;
_ZN3OAM12objCountMainE                                                            = 0x0209e664;
_ZN3OAM11objCountSubE                                                             = 0x0209e670;
_ZN3OAM10bufferMainE                                                              = 0x0209e674;
_ZN3OAM9bufferSubE                                                                = 0x0209e678;

_ZN3OAM5ResetEv                                                                   = 0x02021788;
_ZN3OAM5FlushEv                                                                   = 0x02021864;
_ZN3OAM4LoadEv                                                                    = 0x02021898;
_ZN3OAM9RenderSubEP7OamAttriiii                                                   = 0x0202199c;
_ZN3OAM9RenderSubEP7OamAttrii                                                     = 0x0202194c;
_ZN3OAM12EnableSubOAMEv                                                           = 0x020219f0;

_ZN3OAM4COINE                                                                     = 0x020abad8;
_ZN3OAM10POWER_STARE                                                              = 0x020abad0;
_ZN3OAM5TIMESE                                                                    = 0x020ab9c8;

_ZN3OAM7NUMBERSE                                                                  = 0x020aba70;
_ZN3OAM10LIFE_ICONSE                                                              = 0x020ab948;

_ZN3OAM8RED_COINE                                                                 = 0x0210c6b8;
_ZN3OAM11SILVER_STARE                                                             = 0x020abac8;
_ZN3OAM14BOUNCING_ARROWE                                                          = 0x020abd88;
_ZN3OAM4TIMEE                                                                     = 0x0210c6d0;
_ZN3OAM7MINUTESE                                                                  = 0x0210c6c8;
_ZN3OAM7SECONDSE                                                                  = 0x0210c6c0;
_ZN3OAM15HEALTH_METER_BGE                                                         = 0x0210c690;

_ZN3OAM12CAM_BUTTON_LE                                                            = 0x0210c528;
_ZN3OAM20CAM_BUTTON_L_PRESSEDE                                                    = 0x0210c448;
_ZN3OAM12CAM_BUTTON_RE                                                            = 0x0210c4e8;
_ZN3OAM20CAM_BUTTON_R_PRESSEDE                                                    = 0x0210c4a8;
_ZN3OAM15CAM_ZOOM_BUTTONE                                                         = 0x0210c3e8;
_ZN3OAM23CAM_ZOOM_BUTTON_PRESSEDE                                                 = 0x0210c400;
_ZN3OAM14S_CAM_BUTTON_LE                                                          = 0x0210c468;
_ZN3OAM22S_CAM_BUTTON_L_PRESSEDE                                                  = 0x0210c488;
_ZN3OAM14S_CAM_BUTTON_RE                                                          = 0x0210c4c8;
_ZN3OAM22S_CAM_BUTTON_R_PRESSEDE                                                  = 0x0210c508;
_ZN3OAM17S_CAM_ZOOM_BUTTONE                                                       = 0x0210c430;
_ZN3OAM25S_CAM_ZOOM_BUTTON_PRESSEDE                                               = 0x0210c418;

_ZN3OAM13HEALTH_METERSE                                                           = 0x0210c230;
_ZN3OAM14HEALTH_METER_0E                                                          = 0x0210c648;
_ZN3OAM14HEALTH_METER_1E                                                          = 0x0210c618;
_ZN3OAM14HEALTH_METER_2E                                                          = 0x0210c608;
_ZN3OAM14HEALTH_METER_3E                                                          = 0x0210c678;
_ZN3OAM14HEALTH_METER_4E                                                          = 0x0210c5e8;
_ZN3OAM14HEALTH_METER_5E                                                          = 0x0210c630;
_ZN3OAM14HEALTH_METER_6E                                                          = 0x0210c5d8;
_ZN3OAM14HEALTH_METER_7E                                                          = 0x0210c660;
_ZN3OAM14HEALTH_METER_8E                                                          = 0x0210c5f8;

_ZN3OAM8MM_ARROWE                                                                 = 0x0210c710;
_ZN3OAM11MM_RED_COINE                                                             = 0x0210c6d8;
_ZN3OAM13MM_SPIKE_BOMBE                                                           = 0x0210caec;

_ZN3OAM18MM_VS_PLAYER_ICONSE                                                      = 0x0210c894;
_ZN3OAM22MM_VS_YOSHI_M_CAP_ICONE                                                  = 0x0210c87c;
_ZN3OAM22MM_VS_YOSHI_L_CAP_ICONE                                                  = 0x0210c804;
_ZN3OAM22MM_VS_YOSHI_W_CAP_ICONE                                                  = 0x0210c84c;
_ZN3OAM16MM_VS_YOSHI_ICONE                                                        = 0x0210c754;
_ZN3OAM26MM_VS_RED_YOSHI_M_CAP_ICONE                                              = 0x0210c81c;
_ZN3OAM26MM_VS_RED_YOSHI_L_CAP_ICONE                                              = 0x0210c774;
_ZN3OAM26MM_VS_RED_YOSHI_W_CAP_ICONE                                              = 0x0210c7ec;
_ZN3OAM20MM_VS_RED_YOSHI_ICONE                                                    = 0x0210c76c;
_ZN3OAM27MM_VS_BLUE_YOSHI_M_CAP_ICONE                                             = 0x0210c7d4;
_ZN3OAM27MM_VS_BLUE_YOSHI_L_CAP_ICONE                                             = 0x0210c834;
_ZN3OAM27MM_VS_BLUE_YOSHI_W_CAP_ICONE                                             = 0x0210c78c;
_ZN3OAM21MM_VS_BLUE_YOSHI_ICONE                                                   = 0x0210c764;
_ZN3OAM29MM_VS_YELLOW_YOSHI_M_CAP_ICONE                                           = 0x0210c7bc;
_ZN3OAM29MM_VS_YELLOW_YOSHI_L_CAP_ICONE                                           = 0x0210c864;
_ZN3OAM29MM_VS_YELLOW_YOSHI_W_CAP_ICONE                                           = 0x0210c7a4;
_ZN3OAM23MM_VS_YELLOW_YOSHI_ICONE                                                 = 0x0210c75c;

_ZN3OAM20MM_VS_PLAYER_ICONS_SE                                                    = 0x0210c9b4;
_ZN3OAM24MM_VS_YOSHI_M_CAP_ICON_SE                                                = 0x0210c9a4;
_ZN3OAM24MM_VS_YOSHI_L_CAP_ICON_SE                                                = 0x0210c954;
_ZN3OAM24MM_VS_YOSHI_W_CAP_ICON_SE                                                = 0x0210c984;
_ZN3OAM18MM_VS_YOSHI_ICON_SE                                                      = 0x0210c8d4;
_ZN3OAM28MM_VS_RED_YOSHI_M_CAP_ICON_SE                                            = 0x0210c964;
_ZN3OAM28MM_VS_RED_YOSHI_L_CAP_ICON_SE                                            = 0x0210c8f4;
_ZN3OAM28MM_VS_RED_YOSHI_W_CAP_ICON_SE                                            = 0x0210c944;
_ZN3OAM22MM_VS_RED_YOSHI_ICON_SE                                                  = 0x0210c8ec;
_ZN3OAM29MM_VS_BLUE_YOSHI_M_CAP_ICON_SE                                           = 0x0210c934;
_ZN3OAM29MM_VS_BLUE_YOSHI_L_CAP_ICON_SE                                           = 0x0210c974;
_ZN3OAM29MM_VS_BLUE_YOSHI_W_CAP_ICON_SE                                           = 0x0210c904;
_ZN3OAM23MM_VS_BLUE_YOSHI_ICON_SE                                                 = 0x0210c8e4;
_ZN3OAM31MM_VS_YELLOW_YOSHI_M_CAP_ICON_SE                                         = 0x0210c924;
_ZN3OAM31MM_VS_YELLOW_YOSHI_L_CAP_ICON_SE                                         = 0x0210c994;
_ZN3OAM31MM_VS_YELLOW_YOSHI_W_CAP_ICON_SE                                         = 0x0210c914;
_ZN3OAM25MM_VS_YELLOW_YOSHI_ICON_SE                                               = 0x0210c8dc;

_ZN3OAM15MM_PLAYER_ICONSE                                                         = 0x0210c174;
_ZN3OAM13MM_MARIO_ICONE                                                           = 0x020ab800;
_ZN3OAM19MM_MARIO_L_CAP_ICONE                                                     = 0x020ab820;
_ZN3OAM19MM_MARIO_W_CAP_ICONE                                                     = 0x020ab808;
_ZN3OAM20MM_MARIO_NO_CAP_ICONE                                                    = 0x020ab838;
_ZN3OAM19MM_LUIGI_M_CAP_ICONE                                                     = 0x020ab870;
_ZN3OAM13MM_LUIGI_ICONE                                                           = 0x020ab850;
_ZN3OAM19MM_LUIGI_W_CAP_ICONE                                                     = 0x020ab858;
_ZN3OAM20MM_LUIGI_NO_CAP_ICONE                                                    = 0x020ab888;
_ZN3OAM19MM_WARIO_M_CAP_ICONE                                                     = 0x020ab8d0;
_ZN3OAM19MM_WARIO_L_CAP_ICONE                                                     = 0x020ab8b8;
_ZN3OAM13MM_WARIO_ICONE                                                           = 0x020ab8a0;
_ZN3OAM20MM_WARIO_NO_CAP_ICONE                                                    = 0x020ab8a8;
_ZN3OAM19MM_YOSHI_M_CAP_ICONE                                                     = 0x020ab908;
_ZN3OAM19MM_YOSHI_L_CAP_ICONE                                                     = 0x020ab8f0;
_ZN3OAM19MM_YOSHI_W_CAP_ICONE                                                     = 0x020ab920;
_ZN3OAM13MM_YOSHI_ICONE                                                           = 0x020ab8e8;

_ZN3OAM15MM_STAR_MARKERSE                                                         = 0x0210c5b8;
_ZN3OAM13MM_SMALL_STARE                                                           = 0x0210c548;
_ZN3OAM19MM_SMALL_STAR_FADEDE                                                     = 0x0210c550;
_ZN3OAM14MM_SILVER_STARE                                                          = 0x0210c570;
_ZN3OAM20MM_SILVER_STAR_FADEDE                                                    = 0x0210c568;
_ZN3OAM7MM_STARE                                                                  = 0x0210c560;
_ZN3OAM13MM_STAR_FADEDE                                                           = 0x0210c558;
_ZN3OAM19MM_TRANSPARENT_STARE                                                     = 0x0210c578;
_ZN3OAM26MM_TRANSPARENT_STAR_BRIGHTE                                              = 0x0210c598;

_ZN3OAM12MM_STAR_KEYSE                                                            = 0x0210cae4;
_ZN3OAM11MM_STAR_KEYE                                                             = 0x0210cadc;
_ZN3OAM18MM_STAR_KEY_BRIGHTE                                                      = 0x0210cad4;

_ZN3OAM18LC_CONGRATULATIONSE                                                      = 0x0210cb14;
_ZN3OAM13LC_HIGH_SCOREE                                                           = 0x0210caf4;

_ZN3OAM5PAUSEE                                                                    = 0x0210c6e0;
_ZN3OAM8VS_PAUSEE                                                                 = 0x0210cb4c;
_ZN3OAM19ARROW_POINTING_LEFTE                                                     = 0x0210c6f0;
_ZN3OAM20ARROW_POINTING_RIGHTE                                                    = 0x0210c700;
_ZN3OAM16SMALL_STAR_EMPTYE                                                        = 0x020abac0;
_ZN3OAM9TINY_STARE                                                                = 0x0210c718;
_ZN3OAM25SMALL_ARROW_POINTING_LEFTE                                               = 0x0210c728;
_ZN3OAM26SMALL_ARROW_POINTING_RIGHTE                                              = 0x0210c720;

_ZN3OAM21CONTROLLER_MODE_TEXTSE                                                   = 0x020ad04c;
_ZN3OAM18STANDARD_MODE_TEXTE                                                      = 0x020ad188;
_ZN3OAM15TOUCH_MODE_TEXTE                                                         = 0x020ad058;
_ZN3OAM19DUAL_HAND_MODE_TEXTE                                                     = 0x020ad2d0;

_ZN3OAM15VS_GET_THE_STARE                                                         = 0x0210d210;
_ZN3OAM5VS_GOE                                                                    = 0x0210d420;
_ZN3OAM20VS_NEW_STAR_APPEAREDE                                                    = 0x0210d250;
_ZN3OAM7VS_TIMEE                                                                  = 0x0210ca18;
_ZN3OAM10VS_TIME_UPE                                                              = 0x0210ca20;

_ZN3OAM17VS_YELLOW_NUMBERSE                                                       = 0x0210ca88;
_ZN3OAM18VS_YELLOW_NUMBER_0E                                                      = 0x0210ca80;
_ZN3OAM18VS_YELLOW_NUMBER_1E                                                      = 0x0210ca78;
_ZN3OAM18VS_YELLOW_NUMBER_2E                                                      = 0x0210ca70;
_ZN3OAM18VS_YELLOW_NUMBER_3E                                                      = 0x0210ca68;
_ZN3OAM18VS_YELLOW_NUMBER_4E                                                      = 0x0210ca60;
_ZN3OAM18VS_YELLOW_NUMBER_5E                                                      = 0x0210ca58;
_ZN3OAM18VS_YELLOW_NUMBER_6E                                                      = 0x0210ca50;
_ZN3OAM18VS_YELLOW_NUMBER_7E                                                      = 0x0210ca48;
_ZN3OAM18VS_YELLOW_NUMBER_8E                                                      = 0x0210ca40;
_ZN3OAM18VS_YELLOW_NUMBER_9E                                                      = 0x0210ca38;

_ZN3OAM14VS_RED_NUMBERSE                                                          = 0x0210ca0c;
_ZN3OAM15VS_RED_NUMBER_3E                                                         = 0x0210ca04;
_ZN3OAM15VS_RED_NUMBER_2E                                                         = 0x0210c9fc;
_ZN3OAM15VS_RED_NUMBER_1E                                                         = 0x0210c9f4;

/* Cutscene.h */
RunKuppaScript                                                                    = 0x0200ef04;
ProcessKuppaScript                                                                = 0x0200e8d4;
EndKuppaScript                                                                    = 0x0200e798;
ResetKuppaScript                                                                  = 0x0200f04c;
ContinueKuppaScriptIfNecessary                                                    = 0x0200ef80;

StartIntroCutscene                                                                = 0x0200eedc;
DisableSoundPlayersForCredits                                                     = 0x02011cc8;

KS_CAMERA_FUNCTIONS                                                               = 0x0209b138;
KS_PLAYER_IDS                                                                     = 0x0209b284;
CUTSCENE_OBJECT_IDS                                                               = 0x0209b2a4;
KS_FRAME_COUNTER                                                                  = 0x0209b274;
KS_NUM_PLAYERS                                                                    = 0x0209b270;
KS_FADER                                                                          = 0x0209d4b0;

RUNNING_KUPPA_SCRIPT                                                              = 0x0209fc48;
SAVED_KUPPA_SCRIPT                                                                = 0x0209fc4c;

INTRO_CUTSCENE                                                                    = 0x020890a0;
FALL_IN_FRONT_OF_CASTLE_CUTSCENE                                                  = 0x02089608;
BOB_CREDITS_CUTSCENE                                                              = 0x02087c00;

/* GX.h */
_ZN2GX15DisableAllBanksEv                                                         = 0x0202e78c;
_ZN2GX13SetBankForTexEt                                                           = 0x02054544;
_ZN2GX17SetBankForTexPlttEt                                                       = 0x02054450;
_ZN2GX12SetBankForBGEt                                                            = 0x020549c8;
_ZN2GX13SetBankForOBJEt                                                           = 0x0205485c;
_ZN2GX15SetBankForSubBGEt                                                         = 0x02054384;
_ZN2GX22SetBankForSubBGExtPlttEt                                                  = 0x0205427c;
_ZN2GX16SetBankForSubOBJEt                                                        = 0x02054308;
_ZN2GX23SetBankForSubOBJExtPlttEt                                                 = 0x020541f0;

_ZN2GX15SetGraphicsModeEiii                                                       = 0x02053ad8;
_ZN2GX6DispOnEv                                                                   = 0x02053b4c;

_ZN2GX10LoadBGPlttEPKvjj                                                          = 0x02056870;
_ZN2GX11LoadOBJPlttEPKvjj                                                         = 0x020567a0;

_ZN2GX16BeginLoadTexPlttEv                                                        = 0x02056998;
_ZN2GX11LoadTexPlttEPKvjj                                                         = 0x02056924;
_ZN2GX14EndLoadTexPlttEv                                                          = 0x020568cc;

_ZN2GX12BeginLoadTexEv                                                            = 0x02056b9c;
_ZN2GX7LoadTexEPKvjj                                                              = 0x02056a50;
_ZN2GX10EndLoadTexEv                                                              = 0x020569e0;

_ZN2GX11LoadBG0CharEPKvjj                                                         = 0x02056254;
_ZN2GX11LoadBG1CharEPKvjj                                                         = 0x02056194;
_ZN2GX7LoadOBJEPKvjj                                                              = 0x02056614;

_ZN3GXS15SetGraphicsModeEi                                                        = 0x02053abc;

_ZN3GXS10LoadBGPlttEPKvjj                                                         = 0x02056808;
_ZN3GXS18BeginLoadBGExtPlttEv                                                     = 0x02055f90;
_ZN3GXS13LoadBGExtPlttEPKvjj                                                      = 0x02055f1c;
_ZN3GXS16EndLoadBGExtPlttEv                                                       = 0x02055ed0;

_ZN3GXS11LoadOBJPlttEPKvjj                                                        = 0x02056738;
_ZN3GXS19BeginLoadOBJExtPlttEv                                                    = 0x02055eac;
_ZN3GXS14LoadOBJExtPlttEPKvjj                                                     = 0x02055e38;
_ZN3GXS17EndLoadOBJExtPlttEv                                                      = 0x02055dec;

_ZN3GXS11LoadBG0CharEPKvjj                                                        = 0x020561f4;
_ZN3GXS11LoadBG1CharEPKvjj                                                        = 0x02056134;

_ZN3G3X13SetClearColorEtiiib                                                      = 0x02055574;
_ZN3G3X6SetFogEbiii                                                               = 0x020555d0;
_ZN3G3X11SetFogTableEPv                                                           = 0x020555bc;

_ZN3G3i13PerspectiveW_E5Fix12IiES1_S1_S1_S1_S1_bP9Matrix4x3                       = 0x02055bfc;
_ZN3G3i7LookAt_EPK7Vector3S2_S2_bP9Matrix4x3                                      = 0x02055a64;

_ZN2G212GetBG0ScrPtrEv                                                            = 0x020551bc;
_ZN2G212GetBG1ScrPtrEv                                                            = 0x02055168;
_ZN2G213GetBG2CharPtrEv                                                           = 0x02054e30;
_ZN2G212GetBG2ScrPtrEv                                                            = 0x020550bc;

_ZN3G2S13GetBG0CharPtrEv                                                          = 0x02054edc;
_ZN3G2S13GetBG3CharPtrEv                                                          = 0x02054d38;
_ZN3G2S12GetBG0ScrPtrEv                                                           = 0x0205519c;
_ZN3G2S12GetBG1ScrPtrEv                                                           = 0x02055148;
_ZN3G2S12GetBG2ScrPtrEv                                                           = 0x0205503c;
_ZN3G2S12GetBG3ScrPtrEv                                                           = 0x02054f30;

_ZN3G2x18SetBlendBrightnessEPVtts                                                 = 0x02055238;
_ZN3G2x13SetBlendAlphaEPVttttt                                                    = 0x0205525c;
_ZN3G2x12SetBGyAffineEPVtP9Matrix2x2iiii                                          = 0x02055278;

_Z13CopyToViewMatPK9Matrix4x3                                                     = 0x0200f470;

reg_GX_DISPCNT                                                                    = 0x04000000;
reg_GX_DISPSTAT                                                                   = 0x04000004;
reg_GX_VCOUNT                                                                     = 0x04000006;
reg_G2_BG0CNT                                                                     = 0x04000008;
reg_G2_BG1CNT                                                                     = 0x0400000a;
reg_G2_BG2CNT                                                                     = 0x0400000c;
reg_G2_BG3CNT                                                                     = 0x0400000e;
reg_G2_BG0OFS                                                                     = 0x04000010;
reg_G2_BG1OFS                                                                     = 0x04000014;
reg_G2_BG2OFS                                                                     = 0x04000018;
reg_G2_BG3OFS                                                                     = 0x0400001c;
reg_G2_BG2PA                                                                      = 0x04000020;
reg_G2_BG2PB                                                                      = 0x04000022;
reg_G2_BG2PC                                                                      = 0x04000024;
reg_G2_BG2PD                                                                      = 0x04000026;
reg_G2_BG2X                                                                       = 0x04000028;
reg_G2_BG2Y                                                                       = 0x0400002c;
reg_G2_BG3PA                                                                      = 0x04000030;
reg_G2_BG3PB                                                                      = 0x04000032;
reg_G2_BG3PC                                                                      = 0x04000034;
reg_G2_BG3PD                                                                      = 0x04000036;
reg_G2_BG3X                                                                       = 0x04000038;
reg_G2_BG3Y                                                                       = 0x0400003c;
reg_GX_BLDCNT                                                                     = 0x04000050;
reg_G3X_DISP3DCNT                                                                 = 0x04000060;
reg_KEYINPUT                                                                      = 0x04000130;
reg_OS_IE                                                                         = 0x04000210;
reg_OS_IF                                                                         = 0x04000214;
reg_GX_POWCNT                                                                     = 0x04000304;
reg_G3X_FOG_COLOR                                                                 = 0x04000358;
reg_GXS_DB_DISPCNT                                                                = 0x04001000;
reg_G2S_DB_BG0CNT                                                                 = 0x04001008;
reg_G2S_DB_BG1CNT                                                                 = 0x0400100a;
reg_G2S_DB_BG2CNT                                                                 = 0x0400100c;
reg_G2S_DB_BG3CNT                                                                 = 0x0400100e;
reg_G2S_DB_BG3PA                                                                  = 0x04001030;
reg_GXs_BLDCNT                                                                    = 0x04001050;

bgPalette                                                                         = 0x05000000;
objPalette                                                                        = 0x05000200;
bgPaletteSub                                                                      = 0x05000400;
objPaletteSub                                                                     = 0x05000600;

bgTiles                                                                           = 0x06000000;
bgTilesSub                                                                        = 0x06200000;
objTiles                                                                          = 0x06400000;
objTilesSub                                                                       = 0x06600000;

TOP_SCREEN_RELATED                                                                = 0x0209d45c;
BOTTOM_SCREEN_RELATED                                                             = 0x0209d454;