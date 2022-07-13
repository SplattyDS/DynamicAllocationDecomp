#ifndef SM64DS_OAM_INCLUDED
#define SM64DS_OAM_INCLUDED

#include "SM64DS_Common.h"

struct GXOamAttr
{
	// more GXOamAttr documentation here: https://problemkaputt.de/gbatek.htm#lcdobjoamattributes
	
	enum Attr0 : u16
	{
		Y_COORDINATE        = 0xff << 0,
		ROTATION_SCALE_FLAG = 0x1  << 8,  // 0: off, 1: on
		DOUBLE_SIZE_FLAG    = 0x1  << 9,  // 0: normal, 1: double        (when ROTATION_SCALE_FLAG == 1)
		OBJ_DISABLE         = 0x1  << 9,  // 0: normal, 1: not displayed (when ROTATION_SCALE_FLAG == 0)
		OBJ_MODE            = 0x3  << 10, // 0: normal, 1: semi-transparent, 2: obj window, 3: prohibited
		OBJ_MOSAIC          = 0x1  << 12, // 0: off, 1: on
		PALETTES_MODE       = 0x1  << 13, // 0: 16/16, 1: 256/1
		OBJ_SHAPE           = 0x3  << 14  // 0: square, 1: horizontal, 2: vertical, 3: prohibited
	};
	
	enum Attr1 : u16
	{
		X_COORDINATE               = 0x1ff << 0,
		ROTATION_SCALING_PARAMETER = 0x1f  << 9,  // when ROTATION_SCALE_FLAG == 1
		HORIZONTAL_FLIP            = 0x1   << 12, // when ROTATION_SCALE_FLAG == 0
		VERTICAL_FLIP              = 0x1   << 13, // when ROTATION_SCALE_FLAG == 0
		OBJ_SIZE                   = 0x3   << 14  // depends on OBJ_SHAPE:
		/* 	OBJ_SIZE	square	horizontal	vertical
			0			8x8		16x8		8x16
			1			16x16	32x8		8x32
			2			32x32	32x16		16x32
			3			64x64	64x32		32x64
		*/
	};
	
	enum Attr2 : u16
	{
		TILE_NUMBER    = 0x1ff << 0,
		PRIORITY       = 0x3   << 10, // relative to BG (0 = highest)
		PALETTE_NUMBER = 0xf   << 12  // not used in 256/1 mode
	};
	
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 attr3;
};

namespace OAM
{
	// internal functions
	void Render(bool sub, GXOamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Matrix2x2* affineMtx);
	void Render(bool sub, GXOamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Fix12i scale, s32 rotation);
	void Render(bool sub, GXOamAttr* data, s32 x, s32 y, s32 palette, s32 priority, Fix12i scaleX, Fix12i scaleY, s32 rotation, s32 mode);
	u8 GetObjWidth(s32 shape, s32 size);
	u8 GetObjHeight(s32 shape, s32 size);
	void LoadAffineParams(GXOamAttr* data, s32* affineSet, Matrix2x2* affineMtx);
	
	// indexing: [shape][size] (shape 4 is prohibited)
	extern u8 objWidth[3][4];
	extern u8 objHeight[3][4];
	extern bool subOAMDisabled;
	extern s32 curAffineSetMain;
	extern s32 curAffineSetSub;
	extern s32 objCountMain;
	extern s32 objCountSub;
	extern GXOamAttr bufferMain[128];
	extern GXOamAttr bufferSub[128];
	
	// public functions
	void Reset(); // Resets the internal buffer
	void Flush(); // Flushes the cache on the internal buffer
	void Load();  // Loads the internal buffer to the OAM
	void Render(GXOamAttr* data, s32 x, s32 y); // Inserts an object in the internal buffer
	void Render(GXOamAttr* data, s32 x, s32 y, s32 palette, s32 priority); // Inserts an object in the internal buffer
	void EnableSubOAM(); // Enables the sub engine OAM
	
	// Disables the sub engine OAM
	inline void DisableSubOAM()
	{
		subOAMDisabled = true;
	}
	
	// Returns the internal buffer for the main engine
	inline GXOamAttr* GetMainBuffer()
	{
		return bufferMain;
	}
	
	// Returns the internal buffer for the sub engine
	inline GXOamAttr* GetSubBuffer()
	{
		return bufferSub;
	}
	
	// Returns the number of used objects for the main engine
	inline s32 GetObjCountMain()
	{
		return objCountMain;
	}
	
	// Returns the number of used objects for the sub engine
	inline s32 GetObjCountSub()
	{
		return objCountSub;
	}
	
	// Returns the current affine set for the main engine
	inline s32 GetCurrentAffineSetMain()
	{
		return curAffineSetMain;
	}
	
	// Returns the current affine set for the sub engine
	inline s32 GetCurrentAffineSetSub()
	{
		return curAffineSetSub;
	}
}

#endif