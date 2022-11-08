#ifndef ENUMS_INCLUDED
#define ENUMS_INCLUDED

enum FileIDs // in overlay 0
{
	GOOMBA_MODEL_FILE_ID               = 0x386,
	GOOMBA_RECOVER_ANIM_FILE_ID        = 0x387,
	GOOMBA_ROLLING_ANIM_FILE_ID        = 0x388,
	GOOMBA_RUN_ANIM_FILE_ID            = 0x389,
	GOOMBA_STRETCH_ANIM_FILE_ID        = 0x38a,
	GOOMBA_UNBALANCE_ANIM_FILE_ID      = 0x38b,
	GOOMBA_WAIT_ANIM_FILE_ID           = 0x38c,
	GOOMBA_WALK_ANIM_FILE_ID           = 0x38d,
	GOOMBOSS_ANGER_ANIM_FILE_ID        = 0x38f,
	GOOMBOSS_TEXANIM_FILE_ID           = 0x390,
	GOOMBOSS_DAMAGE_BACK_ANIM_FILE_ID  = 0x391,
	GOOMBOSS_DAMAGE_FRONT_ANIM_FILE_ID = 0x392,
	GOOMBOSS_DOWN_ANIM_FILE_ID         = 0x393,
	GOOMBOSS_DOWN_START_ANIM_FILE_ID   = 0x394,
	GOOMBOSS_MODEL_FILE_ID             = 0x395,
	GOOMBOSS_SERCH_WAIT_ANIM_FILE_ID   = 0x396,
	GOOMBOSS_SPAWN_ANIM_FILE_ID        = 0x397,
	GOOMBOSS_TURN_ANIM_FILE_ID         = 0x398,
	GOOMBOSS_WAIT_ANIM_FILE_ID         = 0x399,
	GOOMBOSS_WALK_ANIM_FILE_ID         = 0x39a,
	GOOMBOSS_WALK_START_ANIM_FILE_ID   = 0x39c,
	GOOMBOSS_WALK_END_ANIM_FILE_ID     = 0x39b,
	HOOT_THE_OWL_MODEL_FILE_ID         = 0x3cb,
	HOOT_THE_OWL_FLY_1_ANIM_FILE_ID    = 0x3cc,
	HOOT_THE_OWL_FLY_2_ANIM_FILE_ID    = 0x3cd,
	HOOT_THE_OWL_FLY_FREE_ANIM_FILE_ID = 0x3ce,
	BIRD_MODEL_FILE_ID                 = 0x438,
	BIRD_ANIMATION_FILE_ID             = 0x439,
	TREASURE_CHEST_MODEL_FILE_ID       = 0x4a6,
	TREASURE_CHEST_ANIMATION_FILE_ID   = 0x4a7,
	SWITCH_PILLAR_MODEL_FILE_ID        = 0x5a9,
	SWITCH_PILLAR_COLLISION_FILE_ID    = 0x5aa,
	BASEMENT_WATER_MODEL_FILE_ID       = 0x5ab,
	BASEMENT_WATER_COLLISION_FILE_ID   = 0x5ac,
	LIGHT_BEAM_MODEL_FILE_ID           = 0x5ad,
	TRAP_MODEL_FILE_ID                 = 0x5af,
	TRAP_COLLISION_FILE_ID             = 0x5b0,
	FLAG_MODEL_FILE_ID                 = 0x68d,
	FLAG_ANIMATION_FILE_ID             = 0x68e,
	METAL_NET_MODEL_FILE_ID            = 0x691,
	METAL_NET_COLLISION_FILE_ID        = 0x692,
	CASTLE_WATER_MODEL_FILE_ID         = 0x693,
	CASTLE_WATER_COLLISION_FILE_ID     = 0x694,
};

enum ActorIDs
{
	TITLE_SCREEN_ACTOR_ID            = 0x1,
	TREASURE_CHEST_ACTOR_ID          = 0xd,
	SWITCH_PILLAR_ACTOR_ID           = 0x22,
	BASEMENT_WATER_ACTOR_ID          = 0x23,
	TRAP_ACTOR_ID                    = 0x24,
	LIGHT_BEAM_ACTOR_ID              = 0x25,
	PEACH_PAINTING_ACTOR_ID          = 0x26,
	BOWSER_FIRE_SEA_ARENA_ACTOR_ID   = 0xa6,
	BOWSER_SKY_PLATFORM_ACTOR_ID     = 0xa7,
	EYEROCK_ACTOR_ID                 = 0xb0,
	KING_BOB_OMB_ACTOR_ID            = 0xbd,
	PLAYER_ACTOR_ID                  = 0xbf,
	GOOMBOSS_ACTOR_ID                = 0xc6,
	EXPLOSION_GOOMBA_ACTOR_ID        = 0xc7,
	GOOMBA_ACTOR_ID                  = 0xc8,
	SMALL_GOOMBA_ACTOR_ID            = 0xc9,
	LARGE_GOOMBA_ACTOR_ID            = 0xca,
	HOOT_THE_OWL_ACTOR_ID            = 0xea,
	WIGGLER_ACTOR_ID                 = 0xf8,
	ONE_UP_MUSHROOM_ACTOR_ID         = 0x114,
	MEGA_MUSHROOM_ACTOR_ID           = 0x115,
	BOWSER_TAIL_ACTOR_ID             = 0x116,
	BOWSER_ACTOR_ID                  = 0x117,
	BOWSER_FIRE_ACTOR_ID             = 0x118,
	BOWSER_SHOCKWAVES_ACTOR_ID       = 0x119,
	KEY_ACTOR_ID                     = 0x11a,
	SPIKE_BOMB_ACTOR_ID              = 0x11c,
	INVISIBLE_POLE_ACTOR_ID          = 0x11f,
	BUBBLE_ACTOR_ID                  = 0x123,
	TTC_PAINTING_SHORT_HAND_ACTOR_ID = 0x124,
	TTC_PAINTING_LONG_HAND_ACTOR_ID  = 0x125,
	TTC_PAINTING_PENDULUM_ACTOR_ID   = 0x126,
	ONE_UP_LOGO_ACTOR_ID             = 0x14b,
	CASTLE_WATER_ACTOR_ID            = 0x152,
	METAL_NET_ACTOR_ID               = 0x153,
	FLAG_ACTOR_ID                    = 0x156,
	BIRD_ACTOR_ID                    = 0x157,
	MUGEN_BGM_ACTOR_ID               = 0x15f,
};

enum ObjectIDs
{
	GOOMBA_OBJECT_ID                  = 0xf,
	SMALL_GOOMBA_OBJECT_ID            = 0x10,
	LARGE_GOOMBA_OBJECT_ID            = 0x11,
	GOOMBOSS_OBJECT_ID                = 0x12,
	BOWSER_OBJECT_ID                  = 0x28,
	BIRD_OBJECT_ID                    = 0x35,
	KING_BOB_OMB_OBJECT_ID            = 0x38,
	BOWSER_FIRE_SEA_ARENA_OBJECT_ID   = 0x52,
	BOWSER_SKY_PLATFORM_OBJECT_ID     = 0x53,
	TTC_PAINTING_SHORT_HAND_OBJECT_ID = 0xa7,
	TTC_PAINTING_LONG_HAND_OBJECT_ID  = 0xa8,
	TTC_PAINTING_PENDULUM_OBJECT_ID   = 0xa9,
	SWITCH_PILLAR_OBJECT_ID           = 0xe4,
	SPIKE_BOMB_OBJECT_ID              = 0xec,
	HOOT_THE_OWL_OBJECT_ID            = 0xef,
	INVISIBLE_POLE_OBJECT_ID          = 0xf3,
	TRAP_OBJECT_ID                    = 0x111,
	LIGHT_BEAM_OBJECT_ID              = 0x112,
	PEACH_PAINTING_OBJECT_ID          = 0x113,
	EYEROCK_OBJECT_ID                 = 0x117,
	WIGGLER_OBJECT_ID                 = 0x118,
	TREASURE_CHEST_OBJECT_ID          = 0x124,
	CASTLE_WATER_OBJECT_ID            = 0x125,
	METAL_NET_OBJECT_ID               = 0x127,
	FLAG_OBJECT_ID                    = 0x12a,
	BASEMENT_WATER_OBJECT_ID          = 0x12f,
	BOWSER_SHOCKWAVES_OBJECT_ID       = 0x141,
	MUGEN_BGM_OBJECT_ID               = 0x144,
};

enum ActorParams
{
	MARIO_KEY_PARAMETER = 0x0002,
};

enum SoundBank0
{
	// NCS_SE_PT_
	WALK_N              = 0x0000,
	JUMP_N              = 0x0001,
	WARIO_NECK          = 0x0002,
	WARIO_SHOULDER      = 0x0003,
	WARIO_TAPWAIST      = 0x0004,
	HIPATTACK           = 0x0005,
	ROLL                = 0x0006,
	PUNCH_SWING         = 0x0007,
	KICK_SWING          = 0x0008,
	HIT_S               = 0x0009,
	HIT_H               = 0x000a,
	DUMMY_7             = 0x000b,
	FLY_TR              = 0x000c,
	TREE_UP             = 0x000d,
	DUMMY_8             = 0x000e,
	ROLL_SWING          = 0x000f,
	RUN                 = 0x0010,
	SIDE_JUMP_ROLL      = 0x0011,
	PRESSED_PLAYER      = 0x0012,
	WALL_HIT            = 0x0013,
	SWIM_HAND           = 0x0014,
	SWIM_FOOT           = 0x0015,
	DIVE_WATER          = 0x0016,
	FACE_UP             = 0x0017,
	JUMP_FROM_WATER     = 0x0018,
	WARP                = 0x0019,
	KAGO                = 0x001a,
	WARIO_SWING         = 0x001b,
	WARIO_SWING_LV      = 0x001c,
	DUMMY_4             = 0x001d,
	DUMMY_5             = 0x001e,
	DUMMY_6             = 0x001f,
	WALK_NOCODE         = 0x0020,
	WALK_GROUND         = 0x0021,
	WALK_GRASS          = 0x0022,
	WALK_WATER          = 0x0023,
	WALK_ROCK           = 0x0024,
	WALK_WOOD           = 0x0025,
	WALK_SNOW           = 0x0026,
	WALK_ICE            = 0x0027,
	WALK_SAND           = 0x0028,
	WALK_FLOWER         = 0x0029,
	WALK_LOW            = 0x002a,
	WALK_HIGH           = 0x002b,
	WALK_WIRE           = 0x002c,
	WALK_DUMMY_04       = 0x002d,
	WALK_DUMMY_05       = 0x002e,
	WALK_DUMMY_06       = 0x002f,
	JUMP_NOCODE         = 0x0030,
	JUMP_GROUND         = 0x0031,
	JUMP_GRASS          = 0x0032,
	JUMP_WATER          = 0x0033,
	JUMP_ROCK           = 0x0034,
	JUMP_WOOD           = 0x0035,
	JUMP_SNOW           = 0x0036,
	JUMP_ICE            = 0x0037,
	JUMP_SAND           = 0x0038,
	JUMP_FLOWER         = 0x0039,
	JUMP_DUMMY_12       = 0x003a,
	JUMP_DUMMY_13       = 0x003b,
	JUMP_WIRE           = 0x003c,
	JUMP_DUMMY_14       = 0x003d,
	JUMP_DUMMY_15       = 0x003e,
	JUMP_DUMMY_16       = 0x003f,
	LAND_NOCODE         = 0x0040,
	LAND_GROUND         = 0x0041,
	LAND_GRASS          = 0x0042,
	LAND_WATER          = 0x0043,
	LAND_ROCK           = 0x0044,
	LAND_WOOD           = 0x0045,
	LAND_SNOW           = 0x0046,
	LAND_ICE            = 0x0047,
	LAND_SAND           = 0x0048,
	LAND_FLOWER         = 0x0049,
	LAND_DUMMY_22       = 0x004a,
	LAND_DUMMY_23       = 0x004b,
	LAND_WIRE           = 0x004c,
	LAND_DUMMY_24       = 0x004d,
	LAND_DUMMY_25       = 0x004e,
	LAND_DUMMY_26       = 0x004f,
	BOUND_NOCODE        = 0x0050,
	BOUND_GROUND        = 0x0051,
	BOUND_GRASS         = 0x0052,
	BOUND_WATER         = 0x0053,
	BOUND_ROCK          = 0x0054,
	BOUND_WOOD          = 0x0055,
	BOUND_SNOW          = 0x0056,
	BOUND_ICE           = 0x0057,
	BOUND_SAND          = 0x0058,
	BOUND_FLOWER        = 0x0059,
	BOUND_DUMMY_32      = 0x005a,
	BOUND_DUMMY_33      = 0x005b,
	BOUND_WIRE          = 0x005c,
	BOUND_DUMMY_34      = 0x005d,
	BOUND_DUMMY_35      = 0x005e,
	BOUND_DUMMY_36      = 0x005f,
	DOWN_NOCODE         = 0x0060,
	DOWN_GROUND         = 0x0061,
	DOWN_GRASS          = 0x0062,
	DOWN_WATER          = 0x0063,
	DOWN_ROCK           = 0x0064,
	DOWN_WOOD           = 0x0065,
	DOWN_SNOW           = 0x0066,
	DOWN_ICE            = 0x0067,
	DOWN_SAND           = 0x0068,
	DOWN_FLOWER         = 0x0069,
	DOWN_DUMMY_42       = 0x006a,
	DOWN_DUMMY_43       = 0x006b,
	DOWN_WIRE           = 0x006c,
	DOWN_DUMMY_44       = 0x006d,
	DOWN_DUMMY_45       = 0x006e,
	DOWN_DUMMY_46       = 0x006f,
	SLOWWALK_NOCODE     = 0x0070,
	SLOWWALK_GROUND     = 0x0071,
	SLOWWALK_GRASS      = 0x0072,
	SLOWWALK_WATER      = 0x0073,
	SLOWWALK_ROCK       = 0x0074,
	SLOWWALK_WOOD       = 0x0075,
	SLOWWALK_SNOW       = 0x0076,
	SLOWWALK_ICE        = 0x0077,
	SLOWWALK_SAND       = 0x0078,
	SLOWWALK_FLOWER     = 0x0079,
	SLOWWALK_DUMMY_52   = 0x007a,
	SLOWWALK_DUMMY_53   = 0x007b,
	SLOWWALK_WIRE       = 0x007c,
	SLOWWALK_DUMMY_54   = 0x007d,
	SLOWWALK_DUMMY_55   = 0x007e,
	SLOWWALK_DUMMY_56   = 0x007f,
	SINK_NOCODE         = 0x0080,
	SINK_GROUND         = 0x0081,
	SINK_GRASS          = 0x0082,
	SINK_WATER          = 0x0083,
	SINK_ROCK           = 0x0084,
	SINK_WOOD           = 0x0085,
	SINK_SNOW           = 0x0086,
	SINK_ICE            = 0x0087,
	SINK_SAND           = 0x0088,
	SINK_FLOWER         = 0x0089,
	SINK_DUMMY_62       = 0x008a,
	SINK_DUMMY_63       = 0x008b,
	SINK_WIRE           = 0x008c,
	SINK_DUMMY_64       = 0x008d,
	SINK_DUMMY_65       = 0x008e,
	SINK_DUMMY_66       = 0x008f,
	HIPATTACK_NOCODE    = 0x0090,
	HIPATTACK_GROUND    = 0x0091,
	HIPATTACK_GRASS     = 0x0092,
	HIPATTACK_WATER     = 0x0093,
	HIPATTACK_ROCK      = 0x0094,
	HIPATTACK_WOOD      = 0x0095,
	HIPATTACK_SNOW      = 0x0096,
	HIPATTACK_ICE       = 0x0097,
	HIPATTACK_SAND      = 0x0098,
	HIPATTACK_FLOWER    = 0x0099,
	HIPATTACK_DUMMY_72  = 0x009a,
	HIPATTACK_DUMMY_73  = 0x009b,
	HIPATTACK_WIRE      = 0x009c,
	HIPATTACK_DUMMY_74  = 0x009d,
	HIPATTACK_DUMMY_75  = 0x009e,
	HIPATTACK_DUMMY_76  = 0x009f,
	METAL_JUMP          = 0x00a0,
	METAL_LAND          = 0x00a1,
	METAL_WALK          = 0x00a2,
	METAL_DOWN          = 0x00a3,
	METAL_SLOWWALK      = 0x00a4,
	METAL_REBOUND       = 0x00a5,
	METAL_HIP_ATTACK    = 0x00a6,
	METAL_HIT_WALL      = 0x00a7,
	METAL_JUMP_W        = 0x00a8,
	METAL_LAND_W        = 0x00a9,
	METAL_WALK_W        = 0x00aa,
	METAL_DOWN_W        = 0x00ab,
	METAL_SLOWWALK_W    = 0x00ac,
	DUMMY_C             = 0x00ad,
	DUMMY_D             = 0x00ae,
	DUMMY_E             = 0x00af,
	POLE_UP             = 0x00b0,
	HANDRUB             = 0x00b1,
	UNTEI               = 0x00b2,
	DEEPSANDWALK        = 0x00b3,
	OUT_OF_GROUND       = 0x00b4,
	ENEMY_HIT           = 0x00b5,
	STEP_HIT            = 0x00b6,
	PUT_KEY             = 0x00b7,
	DOKAN_JUMP          = 0x00b8,
	GO_UP               = 0x00b9,
	JUGEM_SPUP_0        = 0x00ba,
	JUGEM_SPUP_1        = 0x00bb,
	YOSSY_BUBBLE        = 0x00bc,
	BALOON_BOUND        = 0x00bd,
	BALOON_JUMP         = 0x00be,
	DUMMY_8A            = 0x00bf,
	CRAWL_NOCODE        = 0x00c0,
	CRAWL_GROUND        = 0x00c1,
	CRAWL_GRASS         = 0x00c2,
	CRAWL_WATER         = 0x00c3,
	CRAWL_ROCK          = 0x00c4,
	CRAWL_WOOD          = 0x00c5,
	CRAWL_SNOW          = 0x00c6,
	CRAWL_ICE           = 0x00c7,
	CRAWL_SAND          = 0x00c8,
	CRAWL_FLOWER        = 0x00c9,
	CRAWL_DUMMY_52      = 0x00ca,
	CRAWL_DUMMY_53      = 0x00cb,
	CRAWL_WIRE          = 0x00cc,
	CRAWL_DUMMY_54      = 0x00cd,
	CRAWL_DUMMY_55      = 0x00ce,
	CRAWL_DUMMY_56      = 0x00cf,
	BIG_WALK            = 0x00d0,
	BIG_JUMP            = 0x00d1,
	BIG_LAND            = 0x00d2,
	BIG_HIPATTACK       = 0x00d3,
	BIG_DIVE            = 0x00d4,
	BIG_PUNCHKICK       = 0x00d5,
	BIG_WALLHIT         = 0x00d6,
	BALOON_CHG          = 0x00d7,
	BALOON_RET          = 0x00d8,
	DEBUT_MARIO         = 0x00d9,
	DEBUT_LUIGI         = 0x00da,
	DEBUT_WARIO         = 0x00db,
	OP_LETSGO_M         = 0x00dc,
	OP_STAMP_L          = 0x00dd,
	OP_STAMP_W          = 0x00de,
	OP_HIT_H            = 0x00df,
	OP_PUNCH_W          = 0x00e0,
	OP_CASTLE_W         = 0x00e1,
	// NCS_SE_PL_
	SLIP_NOCODE         = 0x00e2,
	SLIP_GROUND         = 0x00e3,
	SLIP_GRASS          = 0x00e4,
	SLIP_WATER          = 0x00e5,
	SLIP_ROCK           = 0x00e6,
	SLIP_WOOD           = 0x00e7,
	SLIP_SNOW           = 0x00e8,
	SLIP_ICE            = 0x00e9,
	SLIP_SAND           = 0x00ea,
	SLIP_FLOWER         = 0x00eb,
	SLIP_DUMMY_02       = 0x00ec,
	SLIP_DUMMY_03       = 0x00ed,
	SLIP_WIRE           = 0x00ee,
	SLIP_DUMMY_04       = 0x00ef,
	SLIP_DUMMY_05       = 0x00f0,
	SLIP_DUMMY_06       = 0x00f1,
	KOURA_SLIP_NOCODE   = 0x00f2,
	KOURA_SLIP_GROUND   = 0x00f3,
	KOURA_SLIP_GRASS    = 0x00f4,
	KOURA_SLIP_WATER    = 0x00f5,
	KOURA_SLIP_ROCK     = 0x00f6,
	KOURA_SLIP_WOOD     = 0x00f7,
	KOURA_SLIP_SNOW     = 0x00f8,
	KOURA_SLIP_ICE      = 0x00f9,
	KOURA_SLIP_SAND     = 0x00fa,
	KOURA_SLIP_FLOWER   = 0x00fb,
	KOURA_SLIP_DUMMY_12 = 0x00fc,
	KOURA_SLIP_DUMMY_13 = 0x00fd,
	KOURA_SLIP_WIRE     = 0x00fe,
	KOURA_SLIP_DUMMY_14 = 0x00ff,
	KOURA_SLIP_DUMMY_15 = 0x0100,
	KOURA_SLIP_DUMMY_16 = 0x0101,
	KOURA_SLIP_MAGMA    = 0x0102,
	SLIP_N              = 0x0103,
	FLY_LV              = 0x0104,
	TREE_DOWN           = 0x0105,
	SMOKE               = 0x0106,
	POLEDOWN            = 0x0107,
	DUMMY_0             = 0x0108,
	DUMMY_1             = 0x0109,
	SANDSINK            = 0x010a,
	SPARK               = 0x010b,
	PL_DUMMY_2          = 0x010c,
	PL_DUMMY_3          = 0x010d,
	PL_DUMMY_4          = 0x010e,
	PL_DUMMY_5          = 0x010f,
	PL_DUMMY_6          = 0x0110,
	PL_DUMMY_7          = 0x0111,
};

enum SoundBank3
{
	
};

#endif