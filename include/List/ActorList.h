#pragma once

enum ActorIDs
{
	BOOT_SCENE_ACTOR_ID                            = 0,
	TITLE_SCREEN_ACTOR_ID                          = 1,
	DEBUG_LEVEL_SELECT_ACTOR_ID                    = 2,
	LEVEL_SCENE_ACTOR_ID                           = 3,
	STAR_SELECT_ACTOR_ID                           = 4,
	MINIGAME_SELECT_ACTOR_ID                       = 5,
	VS_MENU_ACTOR_ID                               = 6,
	UNKNOWN_VS_MENU_RELATED_ACTOR_ID               = 7,
	GAMEOVER_SCREEN_ACTOR_ID                       = 8,
	YOSHI_EGG_ACTOR_ID                             = 9,
	BC_SWITCH_ACTOR_ID                             = 10,
	HANSWITCH_ACTOR_ID                             = 11,
	STAR_SWITCH_ACTOR_ID                           = 12,
	TREASURE_CHEST_ACTOR_ID                        = 13,
	CANNON_SHUTTER_ACTOR_ID                        = 14,
	BLOCK_L_ACTOR_ID                               = 15,
	DP_BLOCK_L_ACTOR_ID                            = 16,
	BLOCK_LL_ACTOR_ID                              = 17,
	ICE_BLOCK_LL_ACTOR_ID                          = 18,
	SW_BLOCK_L_ACTOR_ID                            = 19,
	HATENA_BLOCK_ACTOR_ID                          = 20,
	ITEM_BLOCK_ACTOR_ID                            = 21,
	VS_ITEM_BLOCK_ACTOR_ID                         = 22,
	CAP_BLOCK_M_ACTOR_ID                           = 23,
	CAP_BLOCK_W_ACTOR_ID                           = 24,
	CAP_BLOCK_L_ACTOR_ID                           = 25,
	HATENA_SWITCH_ACTOR_ID                         = 26,
	PILE_ACTOR_ID                                  = 27,
	SEESAW_ACTOR_ID                                = 28,
	UPDOWN_LIFT_ACTOR_ID                           = 29,
	HS_UPDOWN_LIFT_ACTOR_ID                        = 30,
	PATH_LIFT_ACTOR_ID                             = 31,
	UDLIFT_TERESA_ACTOR_ID                         = 32,
	UDLIFT_ACTOR_ID                                = 33,
	SWITCH_PILLAR_ACTOR_ID                         = 34,
	BASEMENT_WATER_ACTOR_ID                        = 35,
	TRAP_ACTOR_ID                                  = 36,
	LIGHT_BEAM_ACTOR_ID                            = 37,
	PEACH_PAINTING_ACTOR_ID                        = 38,
	BOMB_SEESAW_ACTOR_ID                           = 39,
	SHUTTER_BOB_ACTOR_ID                           = 40,
	CHAIN_CHOMP_FENCE_ACTOR_ID                     = 41,
	POLE_BILLBOARD_ACTOR_ID                        = 42,
	BK_KILLER_DAI_ACTOR_ID                         = 43,
	KNOCK_DOWN_PLANK_ACTOR_ID                      = 44,
	FALL_BLOCK_WF_ACTOR_ID                         = 45,
	BK_FUTA_ACTOR_ID                               = 46,
	BK_KABE01_ACTOR_ID                             = 47,
	BK_KABE00_ACTOR_ID                             = 48,
	BK_TOWER_ACTOR_ID                              = 49,
	ROTATING_PLATFORM_WF_ACTOR_ID                  = 50,
	ROTATING_BRIDGE_ACTOR_ID                       = 51,
	TOWER_STEP_ACTOR_ID                            = 52,
	MOVING_BAR_BIG_ACTOR_ID                        = 53,
	MOVING_BAR_SMALL_ACTOR_ID                      = 54,
	BK_TRANSBAR_ACTOR_ID                           = 55,
	SHIP_DOWN_ACTOR_ID                             = 56,
	SHIP_UP_ACTOR_ID                               = 57,
	ROCK_PILLAR_ACTOR_ID                           = 58,
	ROCK_TRIANGLE_ACTOR_ID                         = 59,
	FLOAT_ON_WATER_PLATFORM_JRB_ACTOR_ID           = 60,
	KI_IWA_ACTOR_ID                                = 61,
	SHIP_WATER_ACTOR_ID                            = 62,
	SKI_LIFT_ACTOR_ID                              = 63,
	CASKET_ACTOR_ID                                = 64,
	MANSION_STEPS_ACTOR_ID                         = 65,
	FALL_BLOCK_BBH_ACTOR_ID                        = 66,
	SHUTTER_HMC_ACTOR_ID                           = 67,
	WORK_ELEVATOR_ACTOR_ID                         = 68,
	METAL_NET_LIFT_ACTOR_ID                        = 69,
	ROLLING_LOG_LLL_ACTOR_ID                       = 70,
	VOLCANO_RING_ACTOR_ID                          = 71,
	TILTING_PLATFORM_LLL_ACTOR_ID                  = 72,
	LAVA_BRIDGE_ACTOR_ID                           = 73,
	FLOAT_ON_LAVA_PLATFORM_ACTOR_ID                = 74,
	FLOATING_FLOOR_LLL_BIG_ACTOR_ID                = 75,
	FLOATING_FLOOR_LLL_SMALL_ACTOR_ID              = 76,
	LAVA_SEESAW_ACTOR_ID                           = 77,
	BOWSER_PUZZLE_PIECE_ACTOR_ID                   = 78,
	BOWSER_PUZZLE_MANAGER_ACTOR_ID                 = 79,
	ROTATING_PLATFORM_LLL_ACTOR_ID                 = 80,
	ROTATING_FIREBAR_ACTOR_ID                      = 81,
	LAVA_PLANK_ACTOR_ID                            = 82,
	FALL_BLOCK_LLL_ACTOR_ID                        = 83,
	SQUASHER_ACTOR_ID                              = 84,
	PYRAMID_TOP_ACTOR_ID                           = 85,
	PYRAMID_TAG_ACTOR_ID                           = 86,
	PYRAMID_STEP_ACTOR_ID                          = 87,
	PYRAMID_LIFT_ACTOR_ID                          = 88,
	DOCK_POLE_ACTOR_ID                             = 89,
	SUBMARINE_ACTOR_ID                             = 90,
	BOWSER_SHUTTER_ACTOR_ID                        = 91,
	SLIDING_ICE_SPAWNER_ACTOR_ID                   = 92,
	SLIDING_ICE_ACTOR_ID                           = 93,
	ROTATING_PLATFORM_WDW_ACTOR_ID                 = 94,
	FLOAT_ON_WATER_PLATFORM_WDW_SQUARE_ACTOR_ID    = 95,
	ARROW_LIFT_ACTOR_ID                            = 96,
	WATER_DIAMOND_ACTOR_ID                         = 97,
	SWITCH_ACTIVATED_PLANK_ACTOR_ID                = 98,
	CAGE_LIFT_ACTOR_ID                             = 99,
	FLOAT_ON_WATER_PLATFORM_WDW_RECTANGLE_ACTOR_ID = 100,
	WDW_WATER_ACTOR_ID                             = 101,
	ROLLING_LOG_TTM_ACTOR_ID                       = 102,
	HM_BASKET_ACTOR_ID                             = 103,
	TT_FUTA_ACTOR_ID                               = 104,
	TT_WATER_ACTOR_ID                              = 105,
	TD_FUTA_ACTOR_ID                               = 106,
	TD_WATER_ACTOR_ID                              = 107,
	CT_MECHA01_ACTOR_ID                            = 108,
	CT_MECHA02_ACTOR_ID                            = 109,
	CT_MECHA03_ACTOR_ID                            = 110,
	CT_MECHA04L_ACTOR_ID                           = 111,
	CT_MECHA04S_ACTOR_ID                           = 112,
	CT_MECHA05_ACTOR_ID                            = 113,
	CT_MECHA06_ACTOR_ID                            = 114,
	CT_MECHA07_ACTOR_ID                            = 115,
	CT_MECHA08A_ACTOR_ID                           = 116,
	CT_MECHA08B_ACTOR_ID                           = 117,
	CT_MECHA09_ACTOR_ID                            = 118,
	CT_MECHA10_ACTOR_ID                            = 119,
	CT_MECHA11_ACTOR_ID                            = 120,
	CT_MECHA12L_ACTOR_ID                           = 121,
	CT_MECHA12S_ACTOR_ID                           = 122,
	RC_DORIFU_ACTOR_ID                             = 123,
	RC_RIFT01_ACTOR_ID                             = 124,
	RC_HANE_ACTOR_ID                               = 125,
	RC_TIKUWA_ACTOR_ID                             = 126,
	RC_BURANKO_ACTOR_ID                            = 127,
	RC_SEESAW_ACTOR_ID                             = 128,
	ROTATING_PLATFORM_RR_ACTOR_ID                  = 129,
	RC_CARPET_ACTOR_ID                             = 130,
	RC_RIFT02_ACTOR_ID                             = 131,
	RC_GURUGURU_ACTOR_ID                           = 132,
	KM1_SEESAW_ACTOR_ID                            = 133,
	KM1_DORIFU_ACTOR_ID                            = 134,
	KM1_UKISHIMA_ACTOR_ID                          = 135,
	BITDW_PLATFORM_ACTOR_ID                        = 136,
	KM1_KURUMAJIKU_ACTOR_ID                        = 137,
	KM1_DERU_ACTOR_ID                              = 138,
	FALL_BLOCK_BFS_ACTOR_ID                        = 139,
	KM2_AGARU_ACTOR_ID                             = 140,
	TILTING_PLATFORM_BFS_ACTOR_ID                  = 141,
	KM2_AMI_BOU_ACTOR_ID                           = 142,
	KM2_YOKOSEESAW_ACTOR_ID                        = 143,
	KM2_SUSUMU_ACTOR_ID                            = 144,
	FLOATING_FLOOR_BFS_ACTOR_ID                    = 145,
	KM2_RIFUT02_ACTOR_ID                           = 146,
	KM2_RIFUT01_ACTOR_ID                           = 147,
	KM2_NOBIRU_ACTOR_ID                            = 148,
	KM3_SEESAW_ACTOR_ID                            = 149,
	KM3_YOKOSEESAW_ACTOR_ID                        = 150,
	BITS_PLATFORM_ACTOR_ID                         = 151,
	KM3_KURUMAJIKU_ACTOR_ID                        = 152,
	KM3_DORIFU_ACTOR_ID                            = 153,
	KM3_DERU01_ACTOR_ID                            = 154,
	KM3_DERU02_ACTOR_ID                            = 155,
	ROTATING_PLATFORM_BS_ACTOR_ID                  = 156,
	KM3_LIFT_ACTOR_ID                              = 157,
	BOOKSHELF_ACTOR_ID                             = 158,
	MERRY_GO_ROUND_ACTOR_ID                        = 159,
	TRAP_DOOR_ACTOR_ID                             = 160,
	THWOMP_ACTOR_ID                                = 161,
	GRINDEL_ACTOR_ID                               = 162,
	SPINDEL_ACTOR_ID                               = 163,
	BATAN_ACTOR_ID                                 = 164,
	BATANKING_ACTOR_ID                             = 165,
	BOWSER_FIRE_SEA_ARENA_ACTOR_ID                 = 166,
	BOWSER_SKY_PLATFORM_ACTOR_ID                   = 167,
	DOSSY_ACTOR_ID                                 = 168,
	DOSSY_CAP_ACTOR_ID                             = 169,
	EWB_ICE_A_ACTOR_ID                             = 170,
	EWB_ICE_B_ACTOR_ID                             = 171,
	EWB_ICE_C_ACTOR_ID                             = 172,
	EWM_ICE_BLOCK_ACTOR_ID                         = 173,
	EMM_LOG_ACTOR_ID                               = 174,
	EMM_YUKA_ACTOR_ID                              = 175,
	EYEROK_ACTOR_ID                                = 176,
	STAR_CAMERA_ACTOR_ID                           = 177,
	POWER_STAR_ACTOR_ID                            = 178,
	SILVER_STAR_ACTOR_ID                           = 179,
	STAR_MARKER_ACTOR_ID                           = 180,
	BOB_OMB_BUDDY_ACTOR_ID                         = 181,
	PL_CLOSET_ACTOR_ID                             = 182,
	KANBAN_ACTOR_ID                                = 183,
	TATEFUDA_ACTOR_ID                              = 184,
	KINOPIO_ACTOR_ID                               = 185,
	PEACH_PRINCESS_ACTOR_ID                        = 186,
	MIP_ACTOR_ID                                   = 187,
	KOOPA_THE_QUICK_ACTOR_ID                       = 188,
	KING_BOB_OMB_ACTOR_ID                          = 189,
	CHUCKYA_ACTOR_ID                               = 190,
	PLAYER_ACTOR_ID                                = 191,
	PUSHBLOCK_ACTOR_ID                             = 192,
	BATTA_BLOCK_ACTOR_ID                           = 193,
	BLOCK_S_ACTOR_ID                               = 194,
	LUIGI_ACTOR_ID                                 = 195,
	LAVA_ACTOR_ID                                  = 196,
	WATERFALL_MIST_ACTOR_ID                        = 197,
	GOOMBOSS_ACTOR_ID                              = 198,
	EXPLOSION_GOOMBA_ACTOR_ID                      = 199,
	GOOMBA_ACTOR_ID                                = 200,
	GOOMBA_SMALL_ACTOR_ID                          = 201,
	GOOMBA_LARGE_ACTOR_ID                          = 202,
	KOOPA_ACTOR_ID                                 = 203,
	KOOPA_SMALL_ACTOR_ID                           = 204,
	KOOPA_FLAG_ACTOR_ID                            = 205,
	BOMBHEI_ACTOR_ID                               = 206,
	CANNON_ACTOR_ID                                = 207,
	WATERBOMB_ACTOR_ID                             = 208,
	BOO_ACTOR_ID                                   = 209,
	BIG_BOO_ACTOR_ID                               = 210,
	BIG_BOO_ICON_ACTOR_ID                          = 211,
	BOO_CAGE_ACTOR_ID                              = 212,
	BOOK_SWITCH_ACTOR_ID                           = 213,
	LAVA_BUBBLE_ACTOR_ID                           = 214,
	BULLY_ACTOR_ID                                 = 215,
	BIG_BULLY_ACTOR_ID                             = 216,
	CHILL_BULLY_ACTOR_ID                           = 217,
	KING_DONKETU_ACTOR_ID                          = 218,
	CHAIN_CHOMP_ACTOR_ID                           = 219,
	ROLLING_IRON_BALL_ACTOR_ID                     = 220,
	ROLLING_ROCK_ACTOR_ID                          = 221,
	KILLER_ACTOR_ID                                = 222,
	SNOWMAN_ACTOR_ID                               = 223,
	SNOWBALL_ACTOR_ID                              = 224,
	SHARK_ACTOR_ID                                 = 225,
	MANTA_ACTOR_ID                                 = 226,
	PUKUPUKU_ACTOR_ID                              = 227,
	BAKUBAKU_ACTOR_ID                              = 228,
	OBJ_MIP_KEY_ACTOR_ID                           = 229,
	MENBO_ACTOR_ID                                 = 230,
	HYUHYU_ACTOR_ID                                = 231,
	PROPELLER_HEYHO_ACTOR_ID                       = 232,
	PROPELLER_HEYHO_FIRE_ACTOR_ID                  = 233,
	HOOT_THE_OWL_ACTOR_ID                          = 234,
	C_JUGEM_ACTOR_ID                               = 235,
	YUREI_MUCHO_ACTOR_ID                           = 236,
	BASABASA_ACTOR_ID                              = 237,
	POPOI_ACTOR_ID                                 = 238,
	KLEPTO_ACTOR_ID                                = 239,
	SANBO_ACTOR_ID                                 = 240,
	POKEY_SEGMENT_ACTOR_ID                         = 241,
	UNAGI_ACTOR_ID                                 = 242,
	VOLCANO_FIRE_ACTOR_ID                          = 243,
	WATER_RING_ACTOR_ID                            = 244,
	JET_STREAM_ACTOR_ID                            = 245,
	WHIRLPOOL_ACTOR_ID                             = 246,
	WATER_SUCTION_ACTOR_ID                         = 247,
	WIGGLER_ACTOR_ID                               = 248,
	MAD_PIANO_ACTOR_ID                             = 249,
	PIRANHA_PLANT_ACTOR_ID                         = 250,
	FIRE_PIRANHA_PLANT_BIG_ACTOR_ID                = 251,
	FIRE_PIRANHA_PLANT_SMALL_ACTOR_ID              = 252,
	FIRE_PIRANHA_PLANT_ACTOR_ID                    = 253,
	PIRANHA_PLANT_FIREBALL_ACTOR_ID                = 254,
	SPIDER_ACTOR_ID                                = 255,
	PENGUIN_BABY_ACTOR_ID                          = 256,
	MOTHER_PENGUIN_ACTOR_ID                        = 257,
	BRIDGE_PENGUIN_ACTOR_ID                        = 258,
	RACING_PENGUIN_ACTOR_ID                        = 259,
	TOGEZO_ACTOR_ID                                = 260,
	GAMAGUCHI_ACTOR_ID                             = 261,
	EYEKUN_ACTOR_ID                                = 262,
	EYEKUN_BOSS_ACTOR_ID                           = 263,
	MR_I_PROJECTILE_ACTOR_ID                       = 264,
	JUGEM_ACTOR_ID                                 = 265,
	BIRIKYU_ACTOR_ID                               = 266,
	MONKEY_THIEF_ACTOR_ID                          = 267,
	MONKEY_STAR_ACTOR_ID                           = 268,
	CAP_ACTOR_ID                                   = 269,
	KERONPA_ACTOR_ID                               = 270,
	FLAME_CHOMP_FIREBALL_ACTOR_ID                  = 271,
	BIG_SNOWMAN_ACTOR_ID                           = 272,
	BIG_SNOWMAN_HEAD_ACTOR_ID                      = 273,
	BIG_SNOWMAN_BODY_ACTOR_ID                      = 274,
	SNOWMAN_BREATH_ACTOR_ID                        = 275,
	ONE_UP_MUSHROOM_ACTOR_ID                       = 276,
	MEGA_MUSHROOM_ACTOR_ID                         = 277,
	BOWSER_TAIL_ACTOR_ID                           = 278,
	BOWSER_ACTOR_ID                                = 279,
	BOWSER_FIRE_ACTOR_ID                           = 280,
	BOWSER_SHOCKWAVES_ACTOR_ID                     = 281,
	KEY_ACTOR_ID                                   = 282,
	LAST_STAR_ACTOR_ID                             = 283,
	SPIKE_BOMB_ACTOR_ID                            = 284,
	KOOPA_SHELL_ACTOR_ID                           = 285,
	TREE_ACTOR_ID                                  = 286,
	INVISIBLE_POLE_ACTOR_ID                        = 287,
	COIN_ACTOR_ID                                  = 288,
	RED_COIN_ACTOR_ID                              = 289,
	BLUE_COIN_ACTOR_ID                             = 290,
	BUBBLE_ACTOR_ID                                = 291,
	CLOCK_PAINTING_HAND_SHORT_ACTOR_ID             = 292,
	CLOCK_PAINTING_HAND_LONG_ACTOR_ID              = 293,
	CLOCK_PAINTING_PENDULUM_ACTOR_ID               = 294,
	ICE_SHEET_ACTOR_ID                             = 295,
	WAKAME_ACTOR_ID                                = 296,
	HEART_ACTOR_ID                                 = 297,
	DOKAN_ACTOR_ID                                 = 298,
	YAJIRUSI_L_ACTOR_ID                            = 299,
	YAJIRUSI_R_ACTOR_ID                            = 300,
	KB1_BILLBOARD_ACTOR_ID                         = 301,
	HS_MOON_ACTOR_ID                               = 302,
	HS_STAR_ACTOR_ID                               = 303,
	HS_Y_STAR_ACTOR_ID                             = 304,
	HS_B_STAR_ACTOR_ID                             = 305,
	POWER_UP_ITEM_ACTOR_ID                         = 306,
	PICTURE_GATE_ACTOR_ID                          = 307,
	TORNADO_ACTOR_ID                               = 308,
	ONIMASU_ACTOR_ID                               = 309,
	CHOROPU_ACTOR_ID                               = 310,
	CHORO_ROCK_ACTOR_ID                            = 311,
	HUWAHUWA_ACTOR_ID                              = 312,
	SLIDING_BOX_ACTOR_ID                           = 313,
	CLOUD_ACTOR_ID                                 = 314,
	CLAM_ACTOR_ID                                  = 315,
	OBJ_RED_FIRE_ACTOR_ID                          = 316,
	OBJ_BLUE_FIRE_ACTOR_ID                         = 317,
	OBJ_FLAMETHROWER_ACTOR_ID                      = 318,
	KINOKO_CREATE_TAG_ACTOR_ID                     = 319,
	KINOKO_TAG_ACTOR_ID                            = 320,
	BLK_OKINOKO_TAG_ACTOR_ID                       = 321,
	BLK_SKINOKO_TAG_ACTOR_ID                       = 322,
	BLK_GNSHELL_TAG_ACTOR_ID                       = 323,
	BLK_SLVSTAR_TAG_ACTOR_ID                       = 324,
	BOOK_SHOT_ACTOR_ID                             = 325,
	HAUNTED_CHAIR_ACTOR_ID                         = 326,
	BOOKEND_ACTOR_ID                               = 327,
	BOOK_SHOT_SPAWNER_ACTOR_ID                     = 328,
	SECRET_COIN_ACTOR_ID                           = 329,
	OBJ_NUMBER_ACTOR_ID                            = 330,
	ONE_UP_LOGO_ACTOR_ID                           = 331,
	CAMERA_ACTOR_ID                                = 332,
	CAMERA_TAG_ACTOR_ID                            = 333,
	HUD_ACTOR_ID                                   = 334,
	MINIMAP_ACTOR_ID                               = 335,
	BUTTERFLY_ACTOR_ID                             = 336,
	WANWAN2_ACTOR_ID                               = 337,
	CASTLE_WATER_ACTOR_ID                          = 338,
	METAL_NET_ACTOR_ID                             = 339,
	MC_DODAI_ACTOR_ID                              = 340,
	MC_HAZAD_ACTOR_ID                              = 341,
	FLAG_ACTOR_ID                                  = 342,
	BIRD_ACTOR_ID                                  = 343,
	FISH_ACTOR_ID                                  = 344,
	WING_FEATHER_ACTOR_ID                          = 345,
	UNKNOWN_VS_ENTRY_ACTOR_ID                      = 346,
	WARP_ACTOR_ID                                  = 347,
	VIRTUAL_DOOR_ACTOR_ID                          = 348,
	EXIT_ACTOR_ID                                  = 349,
	SET_SE_ACTOR_ID                                = 350,
	MUGEN_BGM_ACTOR_ID                             = 351,
	DEMO_SIMPLE_MODEL_ACTOR_ID                     = 352,
	DOOR_ACTOR_ID                                  = 353,
	STAR_DOOR_ACTOR_ID                             = 354,
	POWER_STAR_CREATE_ACTOR_ID                     = 355,
	ICE_SLIDE_MANAGER_ACTOR_ID                     = 356,
	ENEMY_SWITCH_ACTOR_ID                          = 357,
	ENEMY_CREATE_ACTOR_ID                          = 358,
	SOUND_OBJ_ACTOR_ID                             = 359,
	MULTI_BOOT_SCENE_ACTOR_ID                      = 360,
	TOXBOXSHUFFLE_ACTOR_ID                         = 361,
	MEMORYMATCH_MEMORYMATCH_ACTOR_ID               = 362,
	MEMORYMASTER_MEMORYMASTER_ACTOR_ID             = 363,
	MARIOSLOT_SUPERMARIOSLOT_ACTOR_ID              = 364,
	MIXAMUG_MIXAMUG_ACTOR_ID                       = 365,
	WANTED_WANTED_ACTOR_ID                         = 366,
	BOOMBOX_BOOMBOX_ACTOR_ID                       = 367,
	BOBOMBSQUAD_ACTOR_ID                           = 368,
	LAKITULAUNCH_LAKITULAUNCH_ACTOR_ID             = 369,
	SORTORSPLODE_ACTOR_ID                          = 370,
	MARIOSSLIDES_CONNECTTHECHARACTERS_ACTOR_ID     = 371,
	BOUNCEANDPOUNCE_ACTOR_ID                       = 372,
	BOUNCEANDTROUNCE_ACTOR_ID                      = 373,
	SHUFFLESHELL_SHUFFLESHELL_ACTOR_ID             = 374,
	SHELLSMASH_SHELLSMASH_ACTOR_ID                 = 375,
	BINGOBALL_SLOTSSHOT_ACTOR_ID                   = 376,
	SNOWBALLSLALOM_GIANTSNOWBALLSLALOM_ACTOR_ID    = 377,
	COINCENTRATION_INTENSECOINCENTRATION_ACTOR_ID  = 378,
	PICTUREPOKER_PICTUREPOKER_ACTOR_ID             = 379,
	PUZZLEPANEL_PUZZLEPANIC_ACTOR_ID               = 380,
	PAIRAGONE_PAIRAGONE_ACTOR_ID                   = 381,
	PAIRAGONEANDON_PAIRAGONEANDON_ACTOR_ID         = 382,
	MUSHROOMROULETTE_MUSHROOMROULETTE_ACTOR_ID     = 383,
	TRAMPOLINETIME_TRAMPOLINETIME_ACTOR_ID         = 384,
	TRAMPOLINETERROR_TRAMPOLINETERROR_ACTOR_ID     = 385,
	WHICHWIGGLER_WHICHWIGGLER_ACTOR_ID             = 386,
	HIDEANDBOOSEEK_HIDEANDBOOSEEK_ACTOR_ID         = 387,
	LUCKYSTARS_LUCKYSTARS_ACTOR_ID                 = 388,
	PSYCHEOUT_PSYCHEOUT_ACTOR_ID                   = 389,
	LOVESME_LOVESME_ACTOR_ID                       = 390,
};

enum ObjectIDs
{
	PLAYER_OBJECT_ID                                = 0,
	EWB_ICE_A_OBJECT_ID                             = 1,
	EWB_ICE_B_OBJECT_ID                             = 2,
	EWB_ICE_C_OBJECT_ID                             = 3,
	EWM_ICE_BLOCK_OBJECT_ID                         = 4,
	EMM_LOG_OBJECT_ID                               = 5,
	EMM_YUKA_OBJECT_ID                              = 6,
	UPDOWN_LIFT_OBJECT_ID                           = 7,
	HS_UPDOWN_LIFT_OBJECT_ID                        = 8,
	PATH_LIFT_OBJECT_ID                             = 9,
	CHAIN_CHOMP_OBJECT_ID                           = 10,
	CAMERA_TAG_OBJECT_ID                            = 11,
	SEESAW_OBJECT_ID                                = 12,
	ROLLING_IRON_BALL_OBJECT_ID                     = 13,
	ROLLING_ROCK_OBJECT_ID                          = 14,
	GOOMBA_OBJECT_ID                                = 15,
	GOOMBA_SMALL_OBJECT_ID                          = 16,
	GOOMBA_LARGE_OBJECT_ID                          = 17,
	GOOMBOSS_OBJECT_ID                              = 18,
	BOMBHEI_OBJECT_ID                               = 19,
	BOB_OMB_BUDDY_OBJECT_ID                         = 20,
	KOOPA_OBJECT_ID                                 = 21,
	KOOPA_SMALL_OBJECT_ID                           = 22,
	BLOCK_L_OBJECT_ID                               = 23,
	DP_BLOCK_L_OBJECT_ID                            = 24,
	SW_BLOCK_L_OBJECT_ID                            = 25,
	POWER_UP_ITEM_OBJECT_ID                         = 26,
	HATENA_SWITCH_OBJECT_ID                         = 27,
	BLOCK_S_OBJECT_ID                               = 28,
	CANNON_SHUTTER_OBJECT_ID                        = 29,
	HATENA_BLOCK_OBJECT_ID                          = 30,
	ITEM_BLOCK_OBJECT_ID                            = 31,
	VS_ITEM_BLOCK_OBJECT_ID                         = 32,
	CAP_BLOCK_M_OBJECT_ID                           = 33,
	CAP_BLOCK_W_OBJECT_ID                           = 34,
	CAP_BLOCK_L_OBJECT_ID                           = 35,
	PILE_OBJECT_ID                                  = 36,
	COIN_OBJECT_ID                                  = 37,
	RED_COIN_OBJECT_ID                              = 38,
	BLUE_COIN_OBJECT_ID                             = 39,
	BOWSER_OBJECT_ID                                = 40,
	TREE_OBJECT_ID                                  = 41,
	PICTURE_GATE_OBJECT_ID                          = 42,
	HANSWITCH_OBJECT_ID                             = 43,
	STAR_SWITCH_OBJECT_ID                           = 44,
	SHUTTER_BOB_OBJECT_ID                           = 45,
	SHUTTER_HMC_OBJECT_ID                           = 46,
	WORK_ELEVATOR_OBJECT_ID                         = 47,
	WANWAN2_OBJECT_ID                               = 48,
	ONE_UP_MUSHROOM_OBJECT_ID                       = 49,
	CANNON_OBJECT_ID                                = 50,
	CHAIN_CHOMP_FENCE_OBJECT_ID                     = 51,
	WATERBOMB_OBJECT_ID                             = 52,
	BIRD_OBJECT_ID                                  = 53,
	FISH_OBJECT_ID                                  = 54,
	BUTTERFLY_OBJECT_ID                             = 55,
	KING_BOB_OMB_OBJECT_ID                          = 56,
	SNOWMAN_OBJECT_ID                               = 57,
	MAD_PIANO_OBJECT_ID                             = 58,
	PIRANHA_PLANT_OBJECT_ID                         = 59,
	STAR_CAMERA_OBJECT_ID                           = 60,
	POWER_STAR_OBJECT_ID                            = 61,
	SILVER_STAR_OBJECT_ID                           = 62,
	STAR_MARKER_OBJECT_ID                           = 63,
	BATAN_OBJECT_ID                                 = 64,
	BATANKING_OBJECT_ID                             = 65,
	THWOMP_OBJECT_ID                                = 66,
	BOO_OBJECT_ID                                   = 67,
	BIG_BOO_OBJECT_ID                               = 68,
	BIG_BOO_ICON_OBJECT_ID                          = 69,
	MANSION_STEPS_OBJECT_ID                         = 70,
	BOOKSHELF_OBJECT_ID                             = 71,
	MERRY_GO_ROUND_OBJECT_ID                        = 72,
	TRAP_DOOR_OBJECT_ID                             = 73,
	PL_CLOSET_OBJECT_ID                             = 74,
	KANBAN_OBJECT_ID                                = 75,
	TATEFUDA_OBJECT_ID                              = 76,
	ICE_SHEET_OBJECT_ID                             = 77,
	WAKAME_OBJECT_ID                                = 78,
	HEART_OBJECT_ID                                 = 79,
	KINOPIO_OBJECT_ID                               = 80,
	PEACH_PRINCESS_OBJECT_ID                        = 81,
	BOWSER_FIRE_SEA_ARENA_OBJECT_ID                 = 82,
	BOWSER_SKY_PLATFORM_OBJECT_ID                   = 83,
	KOOPA_SHELL_OBJECT_ID                           = 84,
	SHARK_OBJECT_ID                                 = 85,
	CT_MECHA01_OBJECT_ID                            = 86,
	CT_MECHA02_OBJECT_ID                            = 87,
	CT_MECHA03_OBJECT_ID                            = 88,
	CT_MECHA04L_OBJECT_ID                           = 89,
	CT_MECHA04S_OBJECT_ID                           = 90,
	CT_MECHA05_OBJECT_ID                            = 91,
	CT_MECHA06_OBJECT_ID                            = 92,
	CT_MECHA07_OBJECT_ID                            = 93,
	CT_MECHA08A_OBJECT_ID                           = 94,
	CT_MECHA08B_OBJECT_ID                           = 95,
	CT_MECHA09_OBJECT_ID                            = 96,
	CT_MECHA10_OBJECT_ID                            = 97,
	CT_MECHA11_OBJECT_ID                            = 98,
	CT_MECHA12L_OBJECT_ID                           = 99,
	CT_MECHA12S_OBJECT_ID                           = 100,
	PYRAMID_STEP_OBJECT_ID                          = 101,
	PYRAMID_LIFT_OBJECT_ID                          = 102,
	PYRAMID_TOP_OBJECT_ID                           = 103,
	PYRAMID_TAG_OBJECT_ID                           = 104,
	DOCK_POLE_OBJECT_ID                             = 105,
	SUBMARINE_OBJECT_ID                             = 106,
	BOWSER_SHUTTER_OBJECT_ID                        = 107,
	RC_DORIFU_OBJECT_ID                             = 108,
	RC_RIFT01_OBJECT_ID                             = 109,
	RC_HANE_OBJECT_ID                               = 110,
	RC_TIKUWA_OBJECT_ID                             = 111,
	RC_BURANKO_OBJECT_ID                            = 112,
	RC_SEESAW_OBJECT_ID                             = 113,
	ROTATING_PLATFORM_RR_OBJECT_ID                  = 114,
	RC_GURUGURU_OBJECT_ID                           = 115,
	SLIDING_ICE_SPAWNER_OBJECT_ID                   = 116,
	ROLLING_LOG_TTM_OBJECT_ID                       = 117,
	TT_FUTA_OBJECT_ID                               = 118,
	TT_WATER_OBJECT_ID                              = 119,
	TD_FUTA_OBJECT_ID                               = 120,
	TD_WATER_OBJECT_ID                              = 121,
	ROTATING_PLATFORM_WDW_OBJECT_ID                 = 122,
	FLOAT_ON_WATER_PLATFORM_WDW_SQUARE_OBJECT_ID    = 123,
	ARROW_LIFT_OBJECT_ID                            = 124,
	WATER_DIAMOND_OBJECT_ID                         = 125,
	SWITCH_ACTIVATED_PLANK_OBJECT_ID                = 126,
	CAGE_LIFT_OBJECT_ID                             = 127,
	FLOAT_ON_WATER_PLATFORM_WDW_RECTANGLE_OBJECT_ID = 128,
	WDW_WATER_OBJECT_ID                             = 129,
	ROLLING_LOG_LLL_OBJECT_ID                       = 130,
	VOLCANO_RING_OBJECT_ID                          = 131,
	TILTING_PLATFORM_LLL_OBJECT_ID                  = 132,
	LAVA_BRIDGE_OBJECT_ID                           = 133,
	FLOAT_ON_LAVA_PLATFORM_OBJECT_ID                = 134,
	FLOATING_FLOOR_LLL_BIG_OBJECT_ID                = 135,
	FLOATING_FLOOR_LLL_SMALL_OBJECT_ID              = 136,
	LAVA_SEESAW_OBJECT_ID                           = 137,
	ROTATING_PLATFORM_LLL_OBJECT_ID                 = 138,
	ROTATING_FIREBAR_OBJECT_ID                      = 139,
	LAVA_PLANK_OBJECT_ID                            = 140,
	FALL_BLOCK_LLL_OBJECT_ID                        = 141,
	SQUASHER_OBJECT_ID                              = 142,
	LAVA_OBJECT_ID                                  = 143,
	WATERFALL_MIST_OBJECT_ID                        = 144,
	MANTA_OBJECT_ID                                 = 145,
	SPIDER_OBJECT_ID                                = 146,
	TOGEZO_OBJECT_ID                                = 147,
	JUGEM_OBJECT_ID                                 = 148,
	GAMAGUCHI_OBJECT_ID                             = 149,
	EYEKUN_OBJECT_ID                                = 150,
	EYEKUN_BOSS_OBJECT_ID                           = 151,
	BATTA_BLOCK_OBJECT_ID                           = 152,
	BIRIKYU_OBJECT_ID                               = 153,
	HM_BASKET_OBJECT_ID                             = 154,
	MONKEY_THIEF_OBJECT_ID                          = 155,
	MONKEY_STAR_OBJECT_ID                           = 156,
	PENGUIN_BABY_OBJECT_ID                          = 157,
	MOTHER_PENGUIN_OBJECT_ID                        = 158,
	BRIDGE_PENGUIN_OBJECT_ID                        = 159,
	RACING_PENGUIN_OBJECT_ID                        = 160,
	KERONPA_OBJECT_ID                               = 161,
	BIG_SNOWMAN_OBJECT_ID                           = 162,
	BIG_SNOWMAN_HEAD_OBJECT_ID                      = 163,
	BIG_SNOWMAN_BODY_OBJECT_ID                      = 164,
	SNOWMAN_BREATH_OBJECT_ID                        = 165,
	PUKUPUKU_OBJECT_ID                              = 166,
	CLOCK_PAINTING_HAND_SHORT_OBJECT_ID             = 167,
	CLOCK_PAINTING_HAND_LONG_OBJECT_ID              = 168,
	CLOCK_PAINTING_PENDULUM_OBJECT_ID               = 169,
	MENBO_OBJECT_ID                                 = 170,
	CASKET_OBJECT_ID                                = 171,
	HYUHYU_OBJECT_ID                                = 172,
	BOMB_SEESAW_OBJECT_ID                           = 173,
	KM1_SEESAW_OBJECT_ID                            = 174,
	KM1_DORIFU_OBJECT_ID                            = 175,
	KM1_UKISHIMA_OBJECT_ID                          = 176,
	KM1_KURUMAJIKU_OBJECT_ID                        = 177,
	KM1_DERU_OBJECT_ID                              = 178,
	SHIP_DOWN_OBJECT_ID                             = 179,
	SHIP_UP_OBJECT_ID                               = 180,
	ROCK_PILLAR_OBJECT_ID                           = 181,
	ROCK_TRIANGLE_OBJECT_ID                         = 182,
	FLOAT_ON_WATER_PLATFORM_JRB_OBJECT_ID           = 183,
	KI_IWA_OBJECT_ID                                = 184,
	SHIP_WATER_OBJECT_ID                            = 185,
	DOKAN_OBJECT_ID                                 = 186,
	YAJIRUSI_L_OBJECT_ID                            = 187,
	YAJIRUSI_R_OBJECT_ID                            = 188,
	PROPELLER_HEYHO_OBJECT_ID                       = 189,
	KILLER_OBJECT_ID                                = 190,
	KB1_BILLBOARD_OBJECT_ID                         = 191,
	HS_MOON_OBJECT_ID                               = 192,
	HS_STAR_OBJECT_ID                               = 193,
	HS_Y_STAR_OBJECT_ID                             = 194,
	HS_B_STAR_OBJECT_ID                             = 195,
	POLE_BILLBOARD_OBJECT_ID                        = 196,
	BK_KILLER_DAI_OBJECT_ID                         = 197,
	KNOCK_DOWN_PLANK_OBJECT_ID                      = 198,
	FALL_BLOCK_WF_OBJECT_ID                         = 199,
	BK_FUTA_OBJECT_ID                               = 200,
	BK_KABE01_OBJECT_ID                             = 201,
	BK_KABE00_OBJECT_ID                             = 202,
	BK_TOWER_OBJECT_ID                              = 203,
	ROTATING_PLATFORM_WF_OBJECT_ID                  = 204,
	ROTATING_BRIDGE_OBJECT_ID                       = 205,
	TOWER_STEP_OBJECT_ID                            = 206,
	MOVING_BAR_SMALL_OBJECT_ID                      = 207,
	MOVING_BAR_BIG_OBJECT_ID                        = 208,
	BK_TRANSBAR_OBJECT_ID                           = 209,
	FALL_BLOCK_BBH_OBJECT_ID                        = 210,
	FALL_BLOCK_BFS_OBJECT_ID                        = 211,
	KM2_AGARU_OBJECT_ID                             = 212,
	TILTING_PLATFORM_BFS_OBJECT_ID                  = 213,
	KM2_AMI_BOU_OBJECT_ID                           = 214,
	KM2_YOKOSEESAW_OBJECT_ID                        = 215,
	KM2_SUSUMU_OBJECT_ID                            = 216,
	FLOATING_FLOOR_BFS_OBJECT_ID                    = 217,
	KM2_RIFUT02_OBJECT_ID                           = 218,
	KM2_RIFUT01_OBJECT_ID                           = 219,
	KM2_NOBIRU_OBJECT_ID                            = 220,
	KM3_SEESAW_OBJECT_ID                            = 221,
	KM3_YOKOSEESAW_OBJECT_ID                        = 222,
	KM3_KURUMAJIKU_OBJECT_ID                        = 223,
	KM3_DORIFU_OBJECT_ID                            = 224,
	KM3_DERU01_OBJECT_ID                            = 225,
	KM3_DERU02_OBJECT_ID                            = 226,
	ROTATING_PLATFORM_BS_OBJECT_ID                  = 227,
	SWITCH_PILLAR_OBJECT_ID                         = 228,
	SKI_LIFT_OBJECT_ID                              = 229,
	PROPELLER_HEYHO_FIRE_OBJECT_ID                  = 230,
	UDLIFT_TERESA_OBJECT_ID                         = 231,
	UDLIFT_OBJECT_ID                                = 232,
	RC_RIFT02_OBJECT_ID                             = 233,
	BAKUBAKU_OBJECT_ID                              = 234,
	KM3_LIFT_OBJECT_ID                              = 235,
	SPIKE_BOMB_OBJECT_ID                            = 236,
	MIP_OBJECT_ID                                   = 237,
	OBJ_MIP_KEY_OBJECT_ID                           = 238,
	HOOT_THE_OWL_OBJECT_ID                          = 239,
	BULLY_OBJECT_ID                                 = 240,
	BIG_BULLY_OBJECT_ID                             = 241,
	ONIMASU_OBJECT_ID                               = 242,
	INVISIBLE_POLE_OBJECT_ID                        = 243,
	C_JUGEM_OBJECT_ID                               = 244,
	PUSHBLOCK_OBJECT_ID                             = 245,
	METAL_NET_LIFT_OBJECT_ID                        = 246,
	YUREI_MUCHO_OBJECT_ID                           = 247,
	CHOROPU_OBJECT_ID                               = 248,
	CHORO_ROCK_OBJECT_ID                            = 249,
	BASABASA_OBJECT_ID                              = 250,
	POPOI_OBJECT_ID                                 = 251,
	KLEPTO_OBJECT_ID                                = 252,
	SANBO_OBJECT_ID                                 = 253,
	CAP_OBJECT_ID                                   = 254,
	BOWSER_PUZZLE_PIECE_OBJECT_ID                   = 255,
	BOWSER_PUZZLE_MANAGER_OBJECT_ID                 = 256,
	DOSSY_OBJECT_ID                                 = 257,
	DOSSY_CAP_OBJECT_ID                             = 258,
	HUWAHUWA_OBJECT_ID                              = 259,
	SLIDING_BOX_OBJECT_ID                           = 260,
	UNAGI_OBJECT_ID                                 = 261,
	CLOUD_OBJECT_ID                                 = 262,
	CLAM_OBJECT_ID                                  = 263,
	OBJ_RED_FIRE_OBJECT_ID                          = 264,
	OBJ_BLUE_FIRE_OBJECT_ID                         = 265,
	OBJ_FLAMETHROWER_OBJECT_ID                      = 266,
	KINOKO_CREATE_TAG_OBJECT_ID                     = 267,
	KINOKO_TAG_OBJECT_ID                            = 268,
	BLK_OKINOKO_TAG_OBJECT_ID                       = 269,
	BLK_SKINOKO_TAG_OBJECT_ID                       = 270,
	BLK_GNSHELL_TAG_OBJECT_ID                       = 271,
	BLK_SLVSTAR_TAG_OBJECT_ID                       = 272,
	TRAP_OBJECT_ID                                  = 273,
	LIGHT_BEAM_OBJECT_ID                            = 274,
	PEACH_PAINTING_OBJECT_ID                        = 275,
	RC_CARPET_OBJECT_ID                             = 276,
	KEY_OBJECT_ID                                   = 277,
	LAST_STAR_OBJECT_ID                             = 278,
	EYEROK_OBJECT_ID                                = 279,
	WIGGLER_OBJECT_ID                               = 280,
	KOOPA_THE_QUICK_OBJECT_ID                       = 281,
	KOOPA_FLAG_OBJECT_ID                            = 282,
	BOO_CAGE_OBJECT_ID                              = 283,
	BLOCK_LL_OBJECT_ID                              = 284,
	ICE_BLOCK_LL_OBJECT_ID                          = 285,
	BOOK_SHOT_OBJECT_ID                             = 286,
	BOOKEND_OBJECT_ID                               = 287,
	BOOK_SHOT_SPAWNER_OBJECT_ID                     = 288,
	BOOK_SWITCH_OBJECT_ID                           = 289,
	CHILL_BULLY_OBJECT_ID                           = 290,
	KING_DONKETU_OBJECT_ID                          = 291,
	TREASURE_CHEST_OBJECT_ID                        = 292,
	CASTLE_WATER_OBJECT_ID                          = 293,
	HAUNTED_CHAIR_OBJECT_ID                         = 294,
	METAL_NET_OBJECT_ID                             = 295,
	MC_DODAI_OBJECT_ID                              = 296,
	MC_HAZAD_OBJECT_ID                              = 297,
	FLAG_OBJECT_ID                                  = 298,
	GRINDEL_OBJECT_ID                               = 299,
	SPINDEL_OBJECT_ID                               = 300,
	CHUCKYA_OBJECT_ID                               = 301,
	MEGA_MUSHROOM_OBJECT_ID                         = 302,
	BASEMENT_WATER_OBJECT_ID                        = 303,
	SECRET_COIN_OBJECT_ID                           = 304,
	BC_SWITCH_OBJECT_ID                             = 305,
	OBJ_NUMBER_OBJECT_ID                            = 306,
	LAVA_BUBBLE_OBJECT_ID                           = 307,
	POWER_STAR_CREATE_OBJECT_ID                     = 308,
	ICE_SLIDE_MANAGER_OBJECT_ID                     = 309,
	VOLCANO_FIRE_OBJECT_ID                          = 310,
	WATER_RING_OBJECT_ID                            = 311,
	FIRE_PIRANHA_PLANT_BIG_OBJECT_ID                = 312,
	FIRE_PIRANHA_PLANT_SMALL_OBJECT_ID              = 313,
	FIRE_PIRANHA_PLANT_OBJECT_ID                    = 314,
	ENEMY_SWITCH_OBJECT_ID                          = 315,
	ENEMY_CREATE_OBJECT_ID                          = 316,
	JET_STREAM_OBJECT_ID                            = 317,
	WHIRLPOOL_OBJECT_ID                             = 318,
	WATER_SUCTION_OBJECT_ID                         = 319,
	TORNADO_OBJECT_ID                               = 320,
	BOWSER_SHOCKWAVES_OBJECT_ID                     = 321,
	LUIGI_OBJECT_ID                                 = 322,
	SET_SE_OBJECT_ID                                = 323,
	MUGEN_BGM_OBJECT_ID                             = 324,
	SOUND_OBJ_OBJECT_ID                             = 325,
	MPCHANGE_OBJECT_ID                              = 511,
};