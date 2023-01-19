#pragma once

#include "SM64DS_Common.h"

struct OamAttr
{
	// more OamAttr documentation here: https://problemkaputt.de/gbatek.htm#lcdobjoamattributes
	
	enum Attr0 : u16
	{
		Y_COORDINATE         = 0xff << 0,
		ROTATION_SCALE_FLAG  = 0x1  << 8,  // 0: off, 1: on
		DOUBLE_SIZE_FLAG     = 0x1  << 9,  // 0: normal, 1: double        (when ROTATION_SCALE_FLAG == 1)
		OBJ_DISABLE          = 0x1  << 9,  // 0: normal, 1: not displayed (when ROTATION_SCALE_FLAG == 0)
		OBJ_MODE             = 0x3  << 10, // 3: prohibited
			NORMAL           = 0x0  << 10,
			SEMI_TRANSPARENT = 0x1  << 10,
			OBJ_WINDOW       = 0x2  << 10,
		OBJ_MOSAIC           = 0x1  << 12, // 0: off, 1: on
		USES_256_PALETTE     = 0x1  << 13, // 0: 16/16, 1: 256/1
		OBJ_SHAPE            = 0x3  << 14, // 3: prohibited
			SQUARE           = 0x0  << 14,
			HORIZONTAL       = 0x1  << 14,
			VERTICAL         = 0x2  << 14,
	};
	
	enum Attr1 : u16
	{
		X_COORDINATE               = 0x1ff << 0,
		ROTATION_SCALING_PARAMETER = 0x1f  << 9,  // when ROTATION_SCALE_FLAG == 1
		HORIZONTAL_FLIP            = 0x1   << 12, // when ROTATION_SCALE_FLAG == 0
		VERTICAL_FLIP              = 0x1   << 13, // when ROTATION_SCALE_FLAG == 0
		OBJ_SIZE                   = 0x3   << 14, // depends on OBJ_SHAPE:	SQUARE	HORIZONTAL	VERTICAL
			OBJ_SIZE_0             = 0x0   << 14, //						8x8		16x8		8x16
			OBJ_SIZE_1             = 0x1   << 14, //						16x16	32x8		8x32
			OBJ_SIZE_2             = 0x2   << 14, //						32x32	32x16		16x32
			OBJ_SIZE_3             = 0x3   << 14, //						64x64	64x32		32x64
	};
	
	enum Attr2 : u16
	{
		TILE_NUMBER    = 0x1ff << 0,
		PRIORITY       = 0x3   << 10, // relative to BG (0 = highest)
		PALETTE_NUMBER = 0xf   << 12, // not used in 256/1 mode
	};
	
	enum Attr3 : u16
	{
		LAST = 0xffff,
	};
	
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 attr3 = 0;
};

namespace OAM
{
	// internal functions
	void Render(bool sub, OamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Matrix2x2* affineMtx);
	void Render(bool sub, OamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Fix12i scale, s32 rotation);
	void Render(bool sub, OamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Fix12i scaleX, Fix12i scaleY, s32 rotation, s32 mode);
	u8 GetObjWidth(s32 shape, s32 size);
	u8 GetObjHeight(s32 shape, s32 size);
	void LoadAffineParams(OamAttr* data, s32* affineSet, Matrix2x2* affineMtx);
	
	// indexing: [shape][size] (shape 4 is prohibited)
	extern u8 objWidth[3][4];
	extern u8 objHeight[3][4];
	extern bool subOAMDisabled;
	extern s32 curAffineSetMain;
	extern s32 curAffineSetSub;
	extern s32 objCountMain;
	extern s32 objCountSub;
	extern OamAttr bufferMain[128];
	extern OamAttr bufferSub[128];
	
	// public functions
	void Reset(); // Resets the internal buffer
	void Flush(); // Flushes the cache on the internal buffer
	void Load();  // Loads the internal buffer to the OAM
	void Render(OamAttr* data, s32 x, s32 y); // Inserts an object in the internal buffer
	void Render(OamAttr* data, s32 x, s32 y, s32 palette, s32 priority); // Inserts an object in the internal buffer
	void RenderSub(OamAttr* data, s32 x, s32 y, s32 palette, s32 priority);
	void EnableSubOAM(); // Enables the sub engine OAM
	
	// Disables the sub engine OAM
	[[gnu::always_inline]]
	inline void DisableSubOAM()
	{
		subOAMDisabled = true;
	}
	
	extern OamAttr COIN;
	extern OamAttr* NUMBER_PTRS[20]; //first 10 are gold versions of 0-9, last 10 are red versions of 0-9
	extern OamAttr TIMES;
	extern OamAttr BOUNCING_ARROW;
}