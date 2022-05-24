#ifndef SM64DS_PARTICLE_INCLUDED
#define SM64DS_PARTICLE_INCLUDED

#include "SM64DS_Common.h"

namespace Particle
{
	enum ParticleID
	{
		// credits to Josh65536 for putting together this list
		PTL_SPARKLES_GREEN = 0x00,
		PTL_BUBBLE_CLEAR = 0x01,
		PTS_BUBBLES_CLEAR = 0x02, //Not to be confused with 1 bubble, above
		PTS_TRIANGLES_GRAY_HIGH = 0x03,
		PTS_TRIANGLES_GRAY_FAST = 0x04,
		PTS_TRIANGLES_GRAY_SLOW = 0x05,
		PTS_TRIANGLES_GOLD = 0x06,
		PTS_DUST_LANDING = 0x07,
		PTS_SNOW_SPLASH = 0x08,
		PTS_STARS_PINK_BLUE_GREEN = 0x09,
		PTS_ROCKS_ORANGE_BRICK_BLOCK = 0x0a,
		PTS_DUST_POOF = 0x0b,
		PTS_STARS_RED = 0x0c,
		PTS_BLUE_LASERS_IN_ALL_DIRECTIONS = 0x0d, //???
		PTS_WOOD_PIECES = 0x0e,
		PTS_ROCKS_BLACK = 0x0f,
		PTS_STARS_YELLOW = 0x10,
		PTL_STEAM = 0x11,
		PTS_BIG_BULLY_BOIL = 0x12, //???
		PTL_TEARS = 0x13, //???
		PTS_EXPLOSION_STAR = 0x14,
		PTS_EXPLOSION_SMOKE = 0x15,
		PTS_EXPLOSION_LASERS = 0x16,
		PTS_EXPLOSION_BALLS = 0x17,
		PTS_EXPLOSION_SMOKE_LINGERING = 0x18,
		PTL_SMOKE_SMALL = 0x19,
		PTS_TRIANGLES_BLACK = 0x1a,
		PTS_DUST_LANDING_BIG = 0x1b,
		PTS_SMALL_SPREADING_WHITE_DOTS = 0x1c, //???
		PTS_EXPANDING_WHITE_DOTS = 0x1d, //???
		PTS_TRIANGLES_BIG_GRAY = 0x1e,
		PTS_DUST_POOF_HUGE_YELLOW = 0x1f,
		PTS_DUST_LANDING_BIG_YELLOW = 0x20,
		PTS_HUGE_BROWN_TRIANGLES = 0x21,
		PTS_HUGE_YELLOWISH_TRIANGLES = 0x22,
		PTL_ROCKS_FAR_ORANGE = 0x23, //For Eyerok?
		PTL_STEAM_SLOW = 0x24,
		PTS_LESS_WOOD_PIECES = 0x25, //in comparison to 0x0e
		PTS_LESS_WOOD_PIECES_2 = 0x26,
		PTL_SPARKLES_WHITE = 0x27,
		PTS_ROCKS_FAST_GRAY = 0x28,
		PTL_ROCKS_TAN = 0x29,
		PTS_ROCKS_TAN = 0x2a,
		PTS_POOF_DUST_TAN = 0x2b,
		PTL_LONG_WHITE_ELLIPSOID = 0x2c, //???
		PTL_STEAM_SPREAD = 0x2d,
		PTS_DUST_LANDING_BIG_SOFT = 0x2e,
		PTL_SPARKLES_YELLOW_WHITE = 0x2f,
		PTS_SPARKLES_FALLING_WHITE = 0x30,
		PTL_SPARKLES_HUGE_YELLOW_WHITE = 0x31,
		PTL_GLARE_YELLOW = 0x32,
		PTL_RAINBOW_RING = 0x33,
		PTL_SPARKLES_RAINBOW = 0x34,
		PTL_TINY_YELLOW_SQUARES = 0x35, //???
		PTL_SPARKLES_RISING_WHITE = 0x36,
		PTS_SPARKLES_WHITE = 0x37,
		PTL_SPARKLES_PURPLE = 0x38,
		PTL_SPARKLES_FAR_PURPLE = 0x39,
		//0x3a does nothing on normal ground.
		PTL_SPARKLES_PURPLE_2 = 0x3b,
		PTL_SPARKLES_FAR_PURPLE_2 = 0x3c,
		//0x3d does nothing on normal ground. Could it be related to 0x3a?
		PTL_SPARKLES_SMALL_WHITE = 0x3e,
		PTL_IMPACT_STAR = 0x3f,
		PTS_DUST_POOF_LESS = 0x40,
		PTS_TRIANGLES_GREEN = 0x41,
		PTS_TRIANGLES_WHITE = 0x42,
		PTS_IMPACT_STAR_INSTANT = 0x43,
		PTS_STARS_ORANGE_YELLOW = 0x44,
		PTS_EXPANDING_CYAN_DOTS = 0x45, //???
		PTL_BLUE_TWINKLING_STAR = 0x46, //???
		PTL_BLUE_TWINKLING_DOT = 0x47, //???
		PTS_ROCKS_GRAY = 0x48,
		PTS_ROCKS_YELLOW = 0x49,
		PTL_SPARKLES_LIGHT_BLUE = 0x4a,
		PTL_FIRE_BIG = 0x4b,
		PTL_FIRE_BIG_EMBERS = 0x4c,
		PTL_FIRE_BALL_BIG = 0x4d,
		PTL_FIRE_BALL_BIG_EMBERS = 0x4e,
		PTL_FIRE_BALL_BIGGER_BLUE = 0x4f,
		PTL_FIRE_BALL_BIGGER_EMBERS_BLUE = 0x50,
		PTL_FIRE_BALL_BIGGER = 0x51,
		PTL_FIRE_BALL_BIGGER_EMBERS = 0x52,
		PTS_PETALS = 0x53,
		PTS_WHITE_FIRE = 0x54, //???
		PTS_RIPPLE_BIG = 0x55,
		PTS_SPLASH = 0x56,
		PTS_STARS_RISING_YELLOW = 0x57,
		PTS_SPLASH_BIG = 0x58,
		PTS_DUST_LANDING_BIG_SOFT_LINGERING = 0x59,
		PTS_IMPACT_STAR_FLAT = 0x5a,
		PTS_DUST_LANDING_SOFT = 0x5b,
		PTS_DUST_LANDING_EXTRA_SOFT = 0x5c,
		PTS_GROWING_STARS_BIG = 0x5d,
		PTS_GROWING_STARS_MEDIUM = 0x5e,
		PTS_GROWING_STARS_SMALL = 0x5f,
		//0x60 does nothing on normal ground.
		PTL_DUST_LARGE = 0x61,
		PTS_SPLASH_SMALL = 0x62,
		PTS_DUST_LANDING_SMALL = 0x63,
		PTS_DUST_LANDING_SMALL_SOFT = 0x64,
		PTL_FLAT_CLOUD_TWINKLING = 0x65, //???
		PTL_FLAT_CLOUD = 0x66, //???
		PTS_ROCKS_LARGE_BROWN = 0x67,
		PTS_DUST_LANDING_GRAY = 0x68,
		PTS_STEAM_GRAY = 0x69,
		PTL_WET = 0x6a,
		PTL_STEAM_TRAIN_LESS = 0x6b, //but there are no trains in the game
		PTL_STEAM_TRAIN = 0x6c,
		PTS_QUESTION_SWITCH_STARS = 0x6d,
		PTS_QUESTION_SWITCH_STAR_EXPLOSION = 0x6e,
		PTS_QUESTION_SWITCH_GLARE = 0x6f,
		PTS_DUST_LANDING_HUGE = 0x70,
		PTL_STEAM_2 = 0x71,
		PTL_STEAM_SOFT = 0x72,
		PTL_WIND = 0x73,
		PTS_TRIANGLES_BLUE = 0x74,
		PTS_TRIANGLES_BLUE_2 = 0x75,
		PTS_FIREWORKS_BLUE = 0x76,
		PTL_STEAM_MORE = 0x77,
		PTL_BLUE_SPREADING_DOTS = 0x78, //???
		PTL_STEAM_LATERAL = 0x79,
		PTL_RIPPLE = 0x7a,
		PTL_SNOW_RISING = 0x7b, //???
		PTS_ROCKS_LARGE_YELLOW = 0x7c,
		PTS_ROCKS_SMOKING_YELLOW = 0x7d,
		PTS_FALLING_PURPLE_LEAVES = 0x7e, //???
		PTL_FIRE_SMALL = 0x7f,
		PTL_FIRE_SMALL_EMBERS = 0x80,
		PTL_SPARKLES_CLOSE_YELLOW_WHITE = 0x81,
		PTL_SPARKLES_SMALL_YELLOW_WHITE = 0x82,
		PTS_GLARE_SMALL_YELLOW = 0x83,
		PTS_TRIANGLES_LIGHT_BLUE = 0x84,
		PTS_ROCKS_BLUE = 0x85,
		PTL_SPREAD_WHITE_DOTS = 0x86, //???
		PTL_RAIN_ANGLED = 0x87,
		PTS_TRIANGLES_FAR_LIGHT_BLUE = 0x88,
		PTS_RIPPLE_BIG_BLUE = 0x89,
		PTS_SPREAD_PURPLE_PETALS = 0x8a, //???
		PTS_CLOUDS_FAR = 0x8b,
		PTS_SNOW_RISING_FAR = 0x8c,
		PTS_TRIANGLES_BIG_GRAY_2 = 0x8d,
		PTS_DUST_POOF_BIG = 0x8e,
		PTS_TRIANGLES_SMOKING_GRAY = 0x8f,
		PTL_CLOUD = 0x90,
		PTS_FAST_SPREAD_WHITE_DOTS = 0x91, //???
		PTS_DUST_POOF_BIG_REDDISH = 0x92,
		PTS_POOF_GHOST = 0x93,
		PTS_DUST_POOF_TURNS_BLUE = 0x94,
		PTL_FAINT_LARGE_BLUE_CIRCLE = 0x95, //???
		PTL_TWINKLING_LARGE_BLUE_CIRCLE = 0x96, //???
		PTL_LESS_FAINT_LARGE_BLUE_CIRCLE = 0x97, //???
		PTL_ON_AND_OFF_LARGE_BLUE_CIRCLE = 0x98, //???
		PTL_SMOKE_MORE_DARK_RED = 0x99,
		PTL_FIRE_BRIGHT_EMBERS = 0x9a,
		PTL_FIRE_BALL = 0x9b,
		PTL_FIRE_2 = 0x9c,
		PTL_FIRE_EMBERS_2 = 0x9d,
		PTL_FIRE_TINY = 0x9e,
		PTL_SMOKE_TINY = 0x9f,
		PTL_FIRE_3 = 0xa0,
		PTL_FIRE_EMBERS_3 = 0xa1,
		PTL_FIRE_4 = 0xa2,
		PTL_FIRE_EMBERS_4 = 0xa3,
		PTL_FIRE_NEGATIVE = 0xa4,
		PTL_FIRE_EMBERS_NEGATIVE = 0xa5,
		//0xa6 does nothing on normal ground.
		PTL_FIRE_BALL_NEGATIVE = 0xa7,
		PTS_HUGE_EXPLOSION_BALLS = 0xa8, //???
		PTS_SMOKE_HUGE_RED = 0xa9,
		PTS_GLARE_WHITE_YELLOW = 0xaa,
		PTS_FIRE_HUGE_EMBERS = 0xab,
		PTS_EXPLOSION_HUGE = 0xac,
		PTS_SPREAD_PURPLE_PETALS_2 = 0xad, //???
		PTS_DUST_POOF_PURPLE = 0xae,
		PTL_FIRE_BLUE = 0xaf,
		PTL_FIRE_BLUE_EMBERS = 0xb0,
		PTS_DUST_LANDING_SOFT_2 = 0xb1,
		PTS_DUST_LANDING_SMALL_EXTRA_SOFT = 0xb2,
		PTS_DUST_LANDING_TINY_SOFT = 0xb3,
		PTL_SPARKLES_FAR_YELLOW_WHITE = 0xb4,
		PTL_GLARE_SMALL_YELLOW = 0xb5,
		PTL_RAINBOW_RING_SMALL = 0xb6,
		PTL_BOILING_LAVA_BUBBLES = 0xb7,
		PTL_LEAVES_YELLOW_GREEN = 0xb8,
		PTL_LEAVES_GREEN = 0xb9,
		PTL_SNOW_KICKED = 0xba,
		PTS_TRIANGLES_YELLOW_GRAY = 0xbb,
		PTL_BUBBLES_UNDERWATER = 0xbc,
		PTL_FIRE_BALL_SMALL = 0xbd,
		PTL_SMOKE_SMALL_2 = 0xbe,
		PTS_FAST_SPREAD_PURPLE_PETALS = 0xbf,
		PTS_IMPACT_STAR = 0xc0,
		PTL_ELECTRICITY = 0xc1,
		PTL_ELECTRICITY_SCATTERED = 0xc2,
		PTL_TWINKLING_YELLOW_CIRCLE = 0xc3, //???
		PTL_BUBBLES_RISING = 0xc4,
		PTS_DUST_POOF_2 = 0xc5,
		PTS_DUST_POOF_3 = 0xc6,
		PTS_DUST_POOF_4 = 0xc7,
		PTS_STARS_LESS_YELLOW = 0xc8,
		PTS_STARS_THREE_ORANGE = 0xc9,
		PTS_IMPACT_STAR_RED = 0xca,
		PTS_STARS_TWO_ORANGE = 0xcb,
		PTS_IMPACT_STAR_RED_2 = 0xcc,
		PTS_BUBBLES_WHITE = 0xcd,
		PTS_INIT_SPLASH = 0xce,
		PTS_RIPPLE = 0xcf,
		PTL_THIN_LONG_WHITE_ELLIPSOID = 0xd0, //???
		PTL_DUST_FLYING = 0xd1,
		PTS_SPARKLES_LIGHT_YELLOW = 0xd2, //for a collected coin
		PTS_GROUND_POUND_STARS = 0xd3,
		PTS_GROUND_POUND_DUST = 0xd4,
		PTS_GROUND_POUND_IMPACT_STAR = 0xd5,
		PTL_STARS_DIZZY = 0xd6,
		PTS_DUST_LANDING_SOFT_3 = 0xd7,
		PTS_SPLASH_2 = 0xd8,
		PTS_FIREWORKS_YELLOW = 0xd9,
		PTL_DUST_RUNNING = 0xda,
		PTS_SPLASH_BIG_DROPLETS = 0xdb,
		PTS_DUST_LANDING_SMALL_2 = 0xdc,
		PTS_SPLASH_WHITER = 0xdd,
		PTS_SPLASH_TINY = 0xde,
		PTS_SPLASH_3 = 0xdf,
		PTL_SPARKLES_TINY_WHITE = 0xe0,
		PTL_FIRE_EMBERS_SPREAD = 0xe1,
		PTL_SPLASH = 0xe2,
		PTL_INIT_SPLASH = 0xe3,
		PTS_SPLASH_TINY_2 = 0xe4,
		PTS_SPLASH_SMALL_2 = 0xe5,
		PTS_LEAVES = 0xe6,
		PTL_WIND_BIG = 0xe7,
		PTL_RIPPLE_SMALL = 0xe8,
		PTL_RIPPLE_SMALL_2 = 0xe9,
		PTL_RIPPLE_SMALL_SOFT = 0xea,
		PTL_STEAM_SPREAD_2 = 0xeb,
		PTL_SNOW_RISING_2 = 0xec,
		PTS_DUST_FALLING = 0xed,
		PTS_EXPANDING_YELLOW_CONCENTRIC_CIRCLES = 0xee, //???
		PTS_SPARK_POOF = 0xef,
		PTL_STARS_FAR_RED_YELLOW_BLUE = 0xf0,
		PTS_DUST_SPREAD = 0xf1,
		PTS_DUST_CLOUD_SPREAD = 0xf2,
		PTS_STARS_SPREAD_YELLOW = 0xf3,
		PTS_IMPACT_STAR_SLOW = 0xf4,
		PTL_CLOUD_2 = 0xf5,
		PTS_SPREAD_PURPLE_PETALS_3 = 0xf6,
		PTL_STEAM_SMALL = 0xf7,
		PTS_BIG_BULLY_BOIL_2 = 0xf8, //???
		PTS_ONE_DUST_CLOUD = 0xf9,
		PTS_ROCKS_REDDISH_AND_WHITE = 0xfa,
		PTL_DOTS_PINK = 0xfb, //finite, but long because #frames == 0
		PTS_BUBBLES_LONGER = 0xfc,
		PTS_BUBBLES_WHITE_LONGER = 0xfd,
		PTS_IMPACT_STAR_SOFT = 0xfe,
		PTS_BUBBLES_SPREAD = 0xff,
		PTS_DUST_SPREAD_SOFT = 0x100,
		PTL_CLOUD_BIG = 0x101,
		PTS_SPARKLES_PINK_LIGHT_YELLOW = 0x102,
		PTL_SPARKLES_PINK_LIGHT_YELLOW = 0x103,
		PTL_SPARKLES_STEADY_PINK_LIGHT_YELLOW = 0x104,
		PTL_FIRE_TINY_2 = 0x105,
		PTL_FIRE_TINY_EMBERS_2 = 0x106,
		PTS_ROCKS_GRAY_2 = 0x107,
		PTL_SPARKLES_CLOSE_PINK_LIGHT_YELLOW = 0x108,
		PTS_RIPPLE_TINY = 0x109,
		PTS_ROCKS_GRAY_BLACK = 0x10a,
		PTS_BUBBLES_RISING = 0x10b,
		PTS_DUST_LANDING_BLUE = 0x10c,
		PTL_SPARKLES_LIGHT_BLUE_2 = 0x10d,
		PTL_SPARKLES_LIGHT_YELLOW = 0x10e,
		PTL_SNOW_KICKED_FARTHER = 0x10f,
		PTS_DUST_LANDING_3 = 0x110,
		PTL_CLOUD_FAINT = 0x111,
		PTL_SNOW = 0x112,
		PTL_SPARKLES_MORE_YELLOW_WHITE = 0x113,
		PTL_SPARKLES_MORE_YELLOW_WHITE_2 = 0x114,
		PTL_SPARKLES_POWER_STAR = 0x115,
		PTL_WHITE_AND_YELLOW_SQUARES = 0x116, //???
		PTL_FIRE_BLUE_2 = 0x117,
		PTL_FIRE_5 = 0x118,
		PTL_SPARKLES_PINK_LIGHT_YELLOW_2 = 0x119,
		PTS_SPLASH_WHITE_2 = 0x11a,
		PTS_DUST_LANDING_4 = 0x11b,
		PTS_SPLASH_SMALL_WHIET = 0x11c,
		PTL_SPLASH_WHITE = 0x11d,
		PTL_DUST_LATERAL_SPREAD = 0x11e,
		PTL_RAPIDLY_RISING_YELLOW_BROWN_DOTS = 0x11f, //???
		PTL_DUST_TORNADO = 0x120,
		PTS_ROCKS_BROWN = 0x121,
		PTS_DUST_POOF_5 = 0x122,
		PTS_DUST_POOF_6 = 0x123,
		PTS_DUST_POOF_SPREAD = 0x124,
		PTS_DUST_POOF_LATERAL_SPREAD = 0x125,
		PTS_DUST_POOF_LONGER = 0x126,
		PTS_DUST_POOF_SMALL = 0x127,
		PTS_DUST_POOF_LESS_2 = 0x128,
		PTL_FIRE_6 = 0x129,
		PTS_EXPANDING_BLUE_CONCENTRIC_CIRCLES = 0x12a, //???
		PTS_STARS_BLURRED_PINK_LIGHT_YELLOW = 0x12b,
		PTS_TRIANGLES_LIGHT_GRAY = 0x12c,
		PTS_TRIANGLES_FAR_LIGHT_GRAY = 0x12d,
		PTS_STARS_YELLOW_2 = 0x12e,
		PTS_SPREAD_PURPLE_PETALS_4 = 0x12f,
		PTS_DOTS_LIGHT_YELLOW = 0x130,
		PTS_IMPACT_STAR_2 = 0x131,
		PTL_SWIRL_CLOCKWISE_PINK_YELLOW_WHITE = 0x132,
		PTL_SWIRL_COUNTERCLOCKWISE_PINK_YELLOW_WHITE = 0x133,
		PTS_STARS_RISING_ORANGE_YELLOW = 0x134,
		PTS_DOTS_RISING_WHITE = 0x135,
		PTS_DUST_LANDING_BIG_2 = 0x136,
		PTS_IMPACT_STAR_FLAT_BIG = 0x137,
		PTL_FAST_RISING_SNOW = 0x138, //???
		PTL_WHIRLPOOL = 0x139,
		PTL_SMOKE = 0x13a,
		PTL_FIRE_SMALL_2 = 0x13b,
		PTL_FIRE_YOSHI_EMBERS = 0x13c,
		PTL_FIRE_YOSHI = 0x13d,
		PTS_SPLASH_TINY_3 = 0x13e,
		PTS_COLOR_CHANGING_DOT = 0x13f, //???
		PTL_TEARS_2 = 0x140, //end
	};
	
	enum Sprite
	{
		SP_LIGHTNING = 0x00,
		SP_LIGHTNING_1 = 0x01,
		SP_BUBBLE = 0x02,
		SP_BROWN_CLAM_THINGY = 0x03,
		SP_FIRE_ORANGE = 0x04,
		SP_FIRE_BLUE = 0x05,
		SP_FIRE_ANIM_BLUE_0 = 0x06,
		SP_FIRE_ANIM_BLUE_1 = 0x07,
		SP_FIRE_ANIM_BLUE_2 = 0x08,
		SP_FIRE_ANIM_BLUE_3 = 0x09,
		SP_FIRE_ANIM_BLUE_4 = 0x0a,
		SP_FIRE_ANIM_BLUE_5 = 0x0b,
		SP_FIRE_ANIM_BLUE_6 = 0x0c,
		SP_FIRE_ANIM_BLUE_7 = 0x0d,
		SP_FIRE_ANIM_ORANGE_0 = 0x0e,
		SP_FIRE_ANIM_ORANGE_1 = 0x0f,
		SP_FIRE_ANIM_ORANGE_2 = 0x10,
		SP_FIRE_ANIM_ORANGE_3 = 0x11,
		SP_FIRE_ANIM_ORANGE_4 = 0x12,
		SP_FIRE_ANIM_ORANGE_5 = 0x13,
		SP_FIRE_ANIM_ORANGE_6 = 0x14,
		SP_FIRE_ANIM_ORANGE_7 = 0x15,
		SP_CIRCLE = 0x16, //must be mirrored both ways
		SP_CIRCLE_ORANGE = 0x17, //must be mirrored both ways
		SP_CIRCLE_GRADIENT_SHARP = 0x18, //must be mirrored both ways
		SP_CIRCLE_GRADIENT_FADE = 0x19, //must be mirrored both ways
		SP_SPARK = 0x1a, //must be mirrored both ways
		SP_SPINDRIFT_PETAL = 0x1b, //must be mirrored horizontally
		SP_SPARKLE = 0x1c, //must be mirrored both ways
		SP_BUBBLE_WEIRD = 0x1d, //must be mirrored horizontally
		SP_WEIRD_SPIKY_THINGY = 0x1e, //must be mirrored horizontally
		SP_DOTS_PINK = 0x1f,
		SP_LEAF = 0x20, //must be mirrored horizontally
		SP_WIND_GUST = 0x21,
		SP_WIND_GUST_1 = 0x22,
		SP_WIND_GUST_2 = 0x23,
		SP_TRIANGLE = 0x24,
		SP_BUBBLE_1 = 0x25, //must be mirrored both ways
		SP_FLOWER_OUTLINE = 0x26, //must be mirrored both ways
		SP_STONE = 0x27,
		SP_CLOUD = 0x28,
		SP_SNOW = 0x29,
		SP_SNOW_WEIRD = 0x2a,
		SP_SNOW_1 = 0x2b, //must be mirrored horizontally
		SP_STAR = 0x2c, //must be mirrored horizontally
		SP_DOTS = 0x2d,
	};
	
	struct MainInfo
	{
		enum Flags
		{
			MODE = 0x7 << 0,
				FROM_POINT = 0,
				FROM_PLANE = 1,
				FROM_PLANE_2 = 2,
				FROM_POINT_3 = 3,
				FROM_TORUS = 4,
				FROM_PLANE_5 = 5,
				
			MODE_3D = 0x3 << 4,
				BILLBOARD   = 0x0 << 4,
				VEL_STRETCH = 0x1 << 4,
				THREE_D     = 0x2 << 4,
				CRASH	    = 0x3 << 4,
			ROTATE_SPAWN_CIRCLE_HORZ = 1 << 6,
			ROTATE_SPAWN_CIRCLE_VERT = 1 << 7,
			
			HAS_SCALE_TRANS = 1 << 8,
			HAS_COLOR_TRANS = 1 << 9,
			HAS_ALPHA_TRANS = 1 << 10,
			HAS_TEX_SEQ     = 1 << 11,
			ROTATE = 1 << 12,
			FACE_CAMERA = 1 << 13, //???
			
			HAS_GLITTER = 1 << 16,
			ROTATE_AROUND_RANDOM_AXIS = 1 << 17, //???
			CRASH_18 = 1 << 18,
			HORZ_IF_3D = 1 << 19,
			
			HAS_EFFECT_ACCELERATION    = 1 << 24,
			HAS_EFFECT_JITTER          = 1 << 25,
			HAS_EFFECT_CONVERGE        = 1 << 26,
			HAS_EFFECT_TURN            = 1 << 27,
			HAS_EFFECT_LIMIT_PLANE     = 1 << 28,
			HAS_EFFECT_RADIUS_CONVERGE = 1 << 29
		};
		
		unsigned flags; //0x0c004345 for particle 0x00bc
		Fix12i rate; //in particles per frame
		Fix12i startHorzDist;
		Vector3_16f dir; //0x0c, ???
		uint16_t color;
		Fix12i horzSpeed; //restart system for effect
		Fix12i vertSpeed; //positive means go down, for some reason //restart system for effect
		Fix12i scale; //restart system for effect
		Fix12s horzScale; //milestone: 0x20
		uint16_t unk22; //0x00e7 for particle 0x00bc
		short minAngSpeed; //0x00000000 for particle 0x00bc
		short maxAngSpeed;
		uint16_t frames; //of the system, 0 = infinity
		uint16_t lifetime; //of the individual particles
		uint8_t scaleRand;
		uint8_t lifetimeRand;
		uint8_t speedRand;
		uint8_t unk2f; //0x00 for particle 0x00bc, probably padding
		uint8_t spawnPeriod; //number of frames between spawns (WARNING: DENOMINATOR)
		uint8_t alpha; //on a scale of 0x00 to 0x1f
		uint8_t speedFalloff; //higher means faster and for longer. Below 0x80: slow down, above 0x80: speed up
		uint8_t spriteID;
		uint8_t altLength; //0x01 for particle 0x00bc (WARNING: DENOMINATOR)
		Fix12s velStretchFactor; //respective flag must be enabled
		uint8_t texRepeatFlags; //1, 2, 3: horizontally x 2^n, 4, 8, 0xc: vertically x 2^(n/4)
	};

	struct ScaleTransition
	{
		Fix12s scaleStart;
		Fix12s scaleMiddle;
		Fix12s scaleEnd;
		uint8_t trans1End; //from 0x00 to 0xff
		uint8_t trans2Start;
		uint16_t useAltLength; //least significant byte is 1 means that there is no transition. It will start at scaleEnd.
		uint16_t unk0a;
	};
	
	struct ColorTransition
	{
		uint16_t colorStart;
		uint16_t colorEnd; //colorMiddle is in the main info
		uint8_t trans1Start;
		uint8_t trans2Start;
		uint8_t trans2End;
		uint8_t unk07;
		uint8_t interpFlags;
		uint8_t unk09;
		uint16_t unk0a;
	};
	
	struct AlphaTransition
	{
		uint16_t alpha; //3 alphas 5 bits each
		uint8_t flicker;
		bool useAltLength; //???
		uint8_t alphaTrans1End;
		uint8_t alphaTrans2Start;
		uint16_t unk06;
	};
	
	struct TexSeq
	{
		uint8_t spriteID_0;
		uint8_t spriteID_1;
		uint8_t spriteID_2;
		uint8_t spriteID_3;
		uint8_t spriteID_4;
		uint8_t spriteID_5;
		uint8_t spriteID_6;
		uint8_t spriteID_7;
		uint8_t numSprites;
		uint8_t interval;
		uint8_t interpFlags;
		uint8_t unk0c;
	};
	
	struct Glitter
	{
		uint16_t flags;
		uint16_t speedRand;
		Fix12s scale;
		uint16_t lifetime;
		uint8_t speedMult;
		uint8_t scaleMult;
		uint16_t color;
		uint8_t rate;
		uint8_t wait;
		uint8_t period;
		uint8_t spriteID;
		unsigned texRepeatFlags;
	};
	
	struct EffectData {};
	using EffectFuncPtr = void(*)(EffectData& data, char*, Vector3& velAsr4);
	struct Acceleration : public EffectData
	{
		Vector3_16f acceleration;
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
		constexpr Acceleration(const Vector3_16f& velAsr4) : acceleration(velAsr4) {}
	};
	struct Jitter : public EffectData
	{
		Vector3_16f magnitude;
		uint16_t period; //number of frames between velocity changes (WARNING: DENOMINATOR)
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
	};
	struct Converge : public EffectData
	{
		Vector3 offset;
		Fix12s magnitude;
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
	};
	struct Turn : public EffectData
	{
		short angleSpeed;
		short axis;
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
	};
	struct LimitPlane : public EffectData
	{
		Fix12i posY;
		Fix12s reverseSpeedMult;
		uint8_t behavior;
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
	};
	struct RadiusConverge : public EffectData
	{
		Vector3 offset;
		Fix12s magnitude;
		
		static void Func(EffectData& data, char*, Vector3& velAsr4);
	};
	
	struct Effect
	{
		EffectFuncPtr func;
		EffectData* data;
	};

	struct SysDef
	{
		MainInfo* info;
		ScaleTransition* scaleTrans;
		ColorTransition* colorTrans;
		AlphaTransition* alphaTrans;
		TexSeq* texSeq;
		Glitter* glitter;
		Effect* effects;
		uint16_t numEffects;
	};
	
	enum TexFlags
	{
		FORMAT = 0x7 << 0,
			A3I5 = 0x1 << 0,
			COLOR_4 = 0x2 << 0,
			COLOR_16 = 0x3 << 0,
			COLOR_256 = 0x4 << 0,
			TEXEL_4x4 = 0x5 << 0,
			A5I3 = 0x6 << 0,
			DIRECT = 0x7 << 0,
		LOG_2_WIDTH_MINUS_3 = 0xf << 4, //right shift 4 before using this
		LOG_2_HEIGHT_MINUS_3 = 0xf << 8, //right shift 8 before using this
		REPEAT_S = 0x1 << 12,
		REPEAT_T = 0x1 << 13,
		FLIP_S = 0x1 << 14,
		FLIP_T = 0x1 << 15,
		FIRST_COLOR_TRANSP = 0x1 << 16
	};
	
	struct Texture
	{
		unsigned magic;
		TexFlags flags;
		unsigned texelArrSize;
		unsigned palleteOffset;
		unsigned palleteSize;
		unsigned unk14;
		unsigned unk18;
		unsigned totalSize;
		
		uint8_t* TexelArr()       { return (uint8_t*)((char*)this + 0x20); }
		uint16_t* PalleteColArr() { return (uint16_t*)((char*)this + palleteOffset); }
		
		unsigned Format() { return flags & FORMAT; }
		uint16_t Width()  { return 1 << (((flags & LOG_2_WIDTH_MINUS_3) >> 4) + 3); }
		uint16_t Height() { return 1 << (((flags & LOG_2_HEIGHT_MINUS_3) >> 8) + 3); }
		
		static unsigned AllocTexVram(unsigned size, bool isTexel4x4);
		static unsigned AllocPalVram(unsigned size, bool is4Color);
	};
	
	struct TexDef
	{
		Texture* texture;
		unsigned texVramOffset;
		unsigned palVramOffset;
		TexFlags flags;
		uint16_t width;
		uint16_t height;
	};
	
	struct Particle
	{
		enum Flags
		{
			ALPHA = 0x1f << 0
		};
		
		struct ListNode
		{
			Particle* next;
			Particle* prev;
		};
		ListNode node;
		Vector3 posAsr3;
		Vector3 offsetAsr3;
		Vector3 speedAsr3;
		uint16_t lifetime;
		uint16_t age;
		Fix12i scale;
		Fix12s unk34; //starts at 0x1000
		short ang;
		short angSpeed;
		uint16_t color;
		uint16_t unk3c;
		uint16_t lifetimeInv;
		unsigned flags;
	};
	struct List
	{
		Particle* first;
		unsigned num;

		struct Iterator
		{
			Particle* ptr;

			constexpr Particle& operator*() const { return *ptr; }
			constexpr Particle* operator->() const { return ptr; }
			constexpr Iterator& operator++() { ptr = ptr->node.next; return *this; }
			constexpr bool      operator==(const Iterator&) const = default;
		};

		constexpr Iterator begin() const { return {first}; }
		constexpr Iterator end  () const { return {nullptr}; }
	};
	
	struct System;
	struct Callback
	{
		unsigned unk04;
		unsigned id;
		
		virtual void SpawnParticles(System&);
		virtual bool OnUpdate(System&, bool active);
	};
	struct SimpleCallback : public Callback
	{
		SimpleCallback();
		virtual void SpawnParticles(System&);
		virtual bool OnUpdate(System&, bool active) override;
	};
	struct SplashCallback : public SimpleCallback
	{
		virtual bool OnUpdate(System&, bool active) override;
	};
	
	struct System
	{
		struct ListNode
		{
			System* prev;
			System* next;
		};
		ListNode node;
		List particleList;
		List particleList2;
		SysDef* sysDefPtr;
		unsigned unk1c;
		Vector3 posAsr3;
		unsigned unk2c;
		uint16_t unk30;
		uint8_t unk32;
		uint8_t unk33;
		unsigned unk34;
		uint16_t unk38;
		int16_t rateTracker;
		Vector3_16f dir;
		uint16_t unk42;
		Fix12i startHorzDist;
		Fix12i horzSpeed;
		Fix12i vertSpeed;
		Fix12i scale;
		uint16_t lifetime;
		uint16_t unk56;
		uint8_t spawnPeriod;
		uint8_t alpha;
		uint16_t unk5a;
		unsigned unk5c;
		unsigned unk60;
		unsigned unk64;
		unsigned unk68;
		unsigned unk6c;
		unsigned unk70;
		unsigned unk74;
		
		static unsigned NewWeather(unsigned uniqueID, unsigned effectID, Fix12i x, Fix12i y, Fix12i z, const Vector3_16f* dir, unsigned numWeatherEffectsNow);
		static unsigned NewRipple(Fix12i x, Fix12i y, Fix12i z);
		static unsigned New(unsigned uniqueID, unsigned effectID, Fix12i x, Fix12i y, Fix12i z, const Vector3_16f* dir, Callback* callback);
		static void NewSimple(unsigned particleID, Fix12i x, Fix12i y, Fix12i z);
	};
	
	struct ROMEmbeddedFile
	{
		uint64_t magic;
		uint16_t numSysDefs;
		uint8_t numTexs;
		uint8_t numBuiltInTexs;
		MainInfo firstSysDef;
		
		static MainInfo& NextSysDef(MainInfo& sysDef)
		{
			char* ptr = reinterpret_cast<char*>(&sysDef + 1);

			if (sysDef.flags & MainInfo::HAS_SCALE_TRANS)            ptr += sizeof(ScaleTransition);
			if (sysDef.flags & MainInfo::HAS_COLOR_TRANS)            ptr += sizeof(ColorTransition);
			if (sysDef.flags & MainInfo::HAS_ALPHA_TRANS)            ptr += sizeof(AlphaTransition);
			if (sysDef.flags & MainInfo::HAS_TEX_SEQ)                ptr += sizeof(TexSeq);
			if (sysDef.flags & MainInfo::HAS_GLITTER)                ptr += sizeof(Glitter);
			if (sysDef.flags & MainInfo::HAS_EFFECT_ACCELERATION)    ptr += sizeof(Acceleration);
			if (sysDef.flags & MainInfo::HAS_EFFECT_JITTER)          ptr += sizeof(Jitter);
			if (sysDef.flags & MainInfo::HAS_EFFECT_CONVERGE)        ptr += sizeof(Converge);
			if (sysDef.flags & MainInfo::HAS_EFFECT_TURN)            ptr += sizeof(Turn);
			if (sysDef.flags & MainInfo::HAS_EFFECT_LIMIT_PLANE)     ptr += sizeof(LimitPlane);
			if (sysDef.flags & MainInfo::HAS_EFFECT_RADIUS_CONVERGE) ptr += sizeof(RadiusConverge);
			
			return *reinterpret_cast<MainInfo*>(ptr);
		}
	};
	
	struct Manager
	{
		using AdvancePtrFunc = void*(*)(unsigned amount); //returns the pointer before the advancing, advances 0x0209ee78
		
		struct SysList
		{
			System* last;
			unsigned num;
		};		
		
		void*(*advancePtr)(unsigned amount);
		SysList usedSysList;
		SysList freeSysList;
		List freeParticleList; //???
		SysDef* sysDefArr;
		TexDef* texDefArr;
		uint16_t numSysDefs;
		uint8_t numTextures;
		uint8_t numBuiltInTexs;
		uint16_t unk2c;
		uint16_t unk2e;
		
		System* AddSystem(int particleID, Vector3& posAsr3);
		static bool LoadTex(unsigned fileID, unsigned newTexID);
		static void UnloadNewTexs();
	};
	
	struct SysTracker
	{
		struct Data
		{
			unsigned uniqueID; //1-indexed, not 0-indexed
			unsigned effectID;
			uint16_t frames;
			uint8_t unk0a;
			System* system;
			unsigned** unk10; // a vtable?
			Data* prevInLink;
			Data* nextInLink;
		};
		
		struct UnkStr2
		{
			unsigned* vTable;
			unsigned unk04;
			unsigned* vTable2;
			unsigned* unk0c;
		};
		
		struct Contents
		{
			unsigned numComplexSysSpawned;
			unsigned lastUsedSysSlotIndex;
			Data data[0x40];
			Data* usedSystems[0x10];
			unsigned unk750;
			Callback callbacks[0x08];
			UnkStr2 unkStr2s[0x04];
			unsigned* unk7f4;
			unsigned* unk7f8;
			Fix12i unk7fc;
			unsigned* unk800;
			Fix12i unk804;
			unsigned* unk808;
			unsigned unk80c;
			unsigned* unk810;
			unsigned unk814;
			unsigned* unk818;

			Data* FindData(unsigned uniqueID) const;
		};
		
		ROMEmbeddedFile* romFile;
		Manager* manager;
		Contents contents;
	};
}

extern "C"
{
	extern Particle::ROMEmbeddedFile PARTICLE_ROM_EMBEDDED_FILE;
	extern Particle::SysTracker* PARTICLE_SYS_TRACKER;
	extern unsigned PARTICLE_RNG_STATE; //x => x * 0x5eedf715 + 0x1b0cb173
}

#endif