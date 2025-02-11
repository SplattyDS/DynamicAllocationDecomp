#pragma once

namespace GX
{
	enum VRam : u16
	{
		VRAM_A   = 1 << 0,
		VRAM_B   = 1 << 1,
		VRAM_C   = 1 << 2,
		VRAM_D   = 1 << 3,
		VRAM_E   = 1 << 4,
		VRAM_F   = 1 << 5,
		VRAM_G   = 1 << 6,
		VRAM_H   = 1 << 7,
		VRAM_I   = 1 << 8,
		VRAM_ALL = 0x1ff,
	};
	
	enum VRamTex : u16
	{
		VRAM_TEX_NONE      = 0,
		VRAM_TEX_0_A       = VRAM_A,
		VRAM_TEX_0_B       = VRAM_B,
		VRAM_TEX_0_C       = VRAM_C,
		VRAM_TEX_0_D       = VRAM_D,
		VRAM_TEX_01_AB     = VRAM_A | VRAM_B,
		VRAM_TEX_01_BC     = VRAM_B | VRAM_C,
		VRAM_TEX_01_CD     = VRAM_C | VRAM_D,
		VRAM_TEX_012_ABC   = VRAM_A | VRAM_B | VRAM_C,
		VRAM_TEX_012_BCD   = VRAM_B | VRAM_C | VRAM_D,
		VRAM_TEX_0123_ABCD = VRAM_A | VRAM_B | VRAM_C | VRAM_D,
		
		// discontinuous on LCDC memory
		VRAM_TEX_01_AC     = VRAM_A | VRAM_C,
		VRAM_TEX_01_AD     = VRAM_A | VRAM_D,
		VRAM_TEX_01_BD     = VRAM_B | VRAM_D,
		VRAM_TEX_012_ABD   = VRAM_A | VRAM_B | VRAM_D,
		VRAM_TEX_012_ACD   = VRAM_A | VRAM_C | VRAM_D,
	};
	
	enum VRamTexPltt : u16
	{
		VRAM_TEXPLTT_NONE       = 0,
		VRAM_TEXPLTT_0_F        = VRAM_F,
		VRAM_TEXPLTT_0_G        = VRAM_G,
		VRAM_TEXPLTT_01_FG      = VRAM_F | VRAM_G,
		VRAM_TEXPLTT_0123_E     = VRAM_E,
		VRAM_TEXPLTT_01234_EF   = VRAM_E | VRAM_F,
		VRAM_TEXPLTT_012345_EFG = VRAM_E | VRAM_F | VRAM_G,
	};
	
	enum VRamBG : u16
	{
		VRAM_BG_NONE     = 0,
		VRAM_BG_16_F     = VRAM_F,
		VRAM_BG_16_G     = VRAM_G,
		VRAM_BG_32_FG    = VRAM_F | VRAM_G,
		VRAM_BG_64_E     = VRAM_E,
		VRAM_BG_80_EF    = VRAM_E | VRAM_F,
		VRAM_BG_96_EFG   = VRAM_E | VRAM_F | VRAM_G,
		VRAM_BG_128_A    = VRAM_A,
		VRAM_BG_128_B    = VRAM_B,
		VRAM_BG_128_C    = VRAM_C,
		VRAM_BG_128_D    = VRAM_D,
		VRAM_BG_256_AB   = VRAM_A | VRAM_B,
		VRAM_BG_256_BC   = VRAM_B | VRAM_C,
		VRAM_BG_256_CD   = VRAM_C | VRAM_D,
		VRAM_BG_384_ABC  = VRAM_A | VRAM_B | VRAM_C,
		VRAM_BG_384_BCD  = VRAM_B | VRAM_C | VRAM_D,
		VRAM_BG_512_ABCD = VRAM_A | VRAM_B | VRAM_C | VRAM_D,
	
		// discontinuous on LCDC memory
		VRAM_BG_80_EG    = VRAM_E | VRAM_G,
		VRAM_BG_256_AC   = VRAM_A | VRAM_C,
		VRAM_BG_256_AD   = VRAM_A | VRAM_D,
		VRAM_BG_256_BD   = VRAM_B | VRAM_D,
		VRAM_BG_384_ABD  = VRAM_A | VRAM_B | VRAM_D,
		VRAM_BG_384_ACD  = VRAM_A | VRAM_C | VRAM_D,
	};
	
	enum VRamOBJ : u16
	{
		VRAM_OBJ_NONE   = 0,
		VRAM_OBJ_16_F   = VRAM_F,
		VRAM_OBJ_16_G   = VRAM_G,
		VRAM_OBJ_32_FG  = VRAM_F | VRAM_G,
		VRAM_OBJ_64_E   = VRAM_E,
		VRAM_OBJ_80_EF  = VRAM_E | VRAM_F,
		VRAM_OBJ_80_EG  = VRAM_E | VRAM_G,
		VRAM_OBJ_96_EFG = VRAM_E | VRAM_F | VRAM_G,
		VRAM_OBJ_128_A  = VRAM_A,
		VRAM_OBJ_128_B  = VRAM_B,
		VRAM_OBJ_256_AB = VRAM_A | VRAM_B,
	};
	
	enum VRamSubBG : u16
	{
		VRAM_SUB_BG_NONE  = 0,
		VRAM_SUB_BG_128_C = VRAM_C,
		VRAM_SUB_BG_32_H  = VRAM_H,
		VRAM_SUB_BG_48_HI = VRAM_H | VRAM_I,
	};
	
	enum VRamSubBGExtPltt : u16
	{
		VRAM_SUB_BGEXTPLTT_NONE   = 0,
		VRAM_SUB_BGEXTPLTT_0123_H = VRAM_H,
	};
	
	enum VRamSubOBJ : u16
	{
		VRAM_SUB_OBJ_NONE  = 0,
		VRAM_SUB_OBJ_128_D = VRAM_D,
		VRAM_SUB_OBJ_16_I  = VRAM_I,
	};
	
	enum VRamSubOBJExtPltt : u16
	{
		VRAM_SUB_OBJEXTPLTT_NONE = 0,
		VRAM_SUB_OBJEXTPLTT_0_I  = VRAM_I,
	};
	
	void DisableAllBanks();
	void SetBankForTex(u16 tex);
	void SetBankForTexPltt(u16 texPltt);
	void SetBankForBG(u16 bg);
	void SetBankForOBJ(u16 obj);
	void SetBankForSubBG(u16 sub_bg);
	void SetBankForSubBGExtPltt(u16 sub_bgExtPltt);
	void SetBankForSubOBJ(u16 sub_obj);
	void SetBankForSubOBJExtPltt(u16 sub_objExtPltt);
	
	void SetGraphicsMode(s32 dispMode, s32 bgMode, s32 bg0_2d3d);
	void DispOn();
	
	void LoadBGPltt(const void* src, u32 offset, u32 size);
	void LoadOBJPltt(const void* src, u32 offset, u32 size);
	
	void BeginLoadTexPltt();
	void LoadTexPltt(const void* src, u32 destSlotAddr, u32 size);
	void EndLoadTexPltt();
	
	void BeginLoadTex();
	void LoadTex(const void* src, u32 destSlotAddr, u32 size);
	void EndLoadTex();
	
	void LoadBG0Char(const void* src, u32 offset, u32 size);
	void LoadBG1Char(const void* src, u32 offset, u32 size);
	void LoadOBJ(const void* src, u32 offset, u32 size);
}

namespace GXS
{
	void SetGraphicsMode(s32 bgMode);
	
	void LoadBGPltt(const void* src, u32 offset, u32 size);
	void BeginLoadBGExtPltt();
	void LoadBGExtPltt(const void* src, u32 destSlotAddr, u32 size);
	void EndLoadBGExtPltt();
	
	void LoadOBJPltt(const void* src, u32 offset, u32 size);
	void BeginLoadOBJExtPltt();
	void LoadOBJExtPltt(const void* src, u32 destSlotAddr, u32 size);
	void EndLoadOBJExtPltt();
	
	void LoadBG0Char(const void* src, u32 offset, u32 size);
	void LoadBG1Char(const void* src, u32 offset, u32 size);
}

namespace G3X
{
	void SetClearColor(u16 rgb, s32 alpha, s32 depth, s32 polygonID, bool fog);
	void SetFog(bool enable, s32 fogMode, s32 fogSlope, s32 fogOffset);
	void SetFogTable(void* fogTable);
}

namespace G3i
{
	void PerspectiveW_(Fix12i fovySin, Fix12i fovyCos, Fix12i aspect, Fix12i n, Fix12i f, Fix12i scaleW, bool draw, Matrix4x3* mat);
	void LookAt_(const Vector3* camPos, const Vector3* camUp, const Vector3* target, bool draw , Matrix4x3* mat);
}

namespace G2
{
	char* GetBG0ScrPtr();
	char* GetBG1ScrPtr();
	char* GetBG2CharPtr();
	char* GetBG2ScrPtr();
}

namespace G2S
{
	char* GetBG0CharPtr();
	char* GetBG3CharPtr();
	char* GetBG0ScrPtr();
	char* GetBG1ScrPtr();
	char* GetBG2ScrPtr();
	char* GetBG3ScrPtr();
}

namespace G2x
{
	void SetBlendBrightness(volatile u16* reg,  u16 plane, s16 brightness);
	void SetBlendAlpha(volatile u16* reg, u16 plane1, u16 plane2, u16 ev1, u16 ev2);
	void SetBGyAffine(volatile u16* reg, Matrix2x2* bgMat, s32 bgCenterX, s32 bgCenterY, s32 bgX1, s32 bgY1);
}

// copies mat to VIEW_MATRIX_ASR_3, then inverts it to INV_VIEW_MATRIX_ASR_3
void CopyToViewMat(const Matrix4x3* mat);

extern "C"
{
	extern volatile u32 reg_GX_DISPCNT;     // 0x04000000
	extern volatile u16 reg_GX_DISPSTAT;    // 0x04000004
	extern volatile u16 reg_GX_VCOUNT;      // 0x04000006
	extern volatile u16 reg_G2_BG0CNT;      // 0x04000008
	extern volatile u16 reg_G2_BG1CNT;      // 0x0400000a
	extern volatile u16 reg_G2_BG2CNT;      // 0x0400000c
	extern volatile u16 reg_G2_BG3CNT;      // 0x0400000e
	extern volatile u32 reg_G2_BG0OFS;      // 0x04000010
	extern volatile u32 reg_G2_BG1OFS;      // 0x04000014
	extern volatile u32 reg_G2_BG2OFS;      // 0x04000018
	extern volatile u32 reg_G2_BG3OFS;      // 0x0400001c
	extern volatile u16 reg_G2_BG2PA;       // 0x04000020
	extern volatile u16 reg_G2_BG2PB;       // 0x04000022
	extern volatile u16 reg_G2_BG2PC;       // 0x04000024
	extern volatile u16 reg_G2_BG2PD;       // 0x04000026
	extern volatile u32 reg_G2_BG2X;        // 0x04000028
	extern volatile u32 reg_G2_BG2Y;        // 0x0400002c
	extern volatile u16 reg_G2_BG3PA;       // 0x04000030
	extern volatile u16 reg_G2_BG3PB;       // 0x04000032
	extern volatile u16 reg_G2_BG3PC;       // 0x04000034
	extern volatile u16 reg_G2_BG3PD;       // 0x04000036
	extern volatile u32 reg_G2_BG3X;        // 0x04000038
	extern volatile u32 reg_G2_BG3Y;        // 0x0400003c
	extern volatile u16 reg_GX_BLDCNT;      // 0x04000050
	// some window related stuff
	extern volatile u16 reg_G3X_DISP3DCNT;  // 0x04000060
	// display capture control register     // 0x04000064
	
	extern volatile u16 reg_KEYINPUT;       // 0x04000130
	extern volatile u32 reg_OS_IE;          // 0x04000210
	extern volatile u32 reg_OS_IF;          // 0x04000214
	extern volatile u16 reg_GX_POWCNT;		// 0x04000304
	extern volatile u32 reg_G3X_FOG_COLOR;  // 0x04000358
	extern volatile u32 reg_GXS_DB_DISPCNT;	// 0x04001000
	extern volatile u16 reg_G2S_DB_BG0CNT;  // 0x04001008
	extern volatile u16 reg_G2S_DB_BG1CNT;  // 0x0400100a
	extern volatile u16 reg_G2S_DB_BG2CNT;  // 0x0400100c
	extern volatile u16 reg_G2S_DB_BG3CNT;  // 0x0400100e
	extern volatile u16 reg_G2S_DB_BG3PA;   // 0x04001030
	extern volatile u16 reg_GXs_BLDCNT;		// 0x04001050
	
	extern u16 bgPalette[0x100];			// 0x05000000
	extern u16 objPalette[0x100];			// 0x05000200
	extern u16 bgPaletteSub[0x100];			// 0x05000400
	extern u16 objPaletteSub[0x100];		// 0x05000600
	
	extern char bgTiles[0x80000];			// 0x06000000
	extern char bgTilesSub[0x20000];		// 0x06200000
	extern char objTiles[0x40000];			// 0x06400000
	extern char objTilesSub[0x20000];		// 0x06600000
	
	extern u8 TOP_SCREEN_RELATED;
	extern u8 BOTTOM_SCREEN_RELATED;
}

[[gnu::always_inline]]
inline void DisableBG0()
{
	TOP_SCREEN_RELATED &= 0xfe;
}

[[gnu::always_inline]]
inline void DisableBG1()
{
	TOP_SCREEN_RELATED &= 0xfd;
}

[[gnu::always_inline]]
inline void DisableBG2()
{
	TOP_SCREEN_RELATED &= 0xfb;
}

[[gnu::always_inline]]
inline void DisableBG3()
{
	TOP_SCREEN_RELATED &= 0xf7;
}

[[gnu::always_inline]]
inline void DisableOBJ()
{
	TOP_SCREEN_RELATED &= 0xef;
}

[[gnu::always_inline]]
inline void DisableSubBG0()
{
	BOTTOM_SCREEN_RELATED &= 0xfe;
}

[[gnu::always_inline]]
inline void DisableSubBG1()
{
	BOTTOM_SCREEN_RELATED &= 0xfd;
}

[[gnu::always_inline]]
inline void DisableSubBG2()
{
	BOTTOM_SCREEN_RELATED &= 0xfb;
}

[[gnu::always_inline]]
inline void DisableSubBG3()
{
	BOTTOM_SCREEN_RELATED &= 0xf7;
}

[[gnu::always_inline]]
inline void DisableSubOBJ()
{
	BOTTOM_SCREEN_RELATED &= 0xef;
}

[[gnu::always_inline]]
inline void EnableBG0()
{
	TOP_SCREEN_RELATED |= 0x01;
}

[[gnu::always_inline]]
inline void EnableBG1()
{
	TOP_SCREEN_RELATED |= 0x02;
}

[[gnu::always_inline]]
inline void EnableBG2()
{
	TOP_SCREEN_RELATED |= 0x04;
}

[[gnu::always_inline]]
inline void EnableBG3()
{
	TOP_SCREEN_RELATED |= 0x08;
}

[[gnu::always_inline]]
inline void EnableOBJ()
{
	TOP_SCREEN_RELATED |= 0x10;
}

[[gnu::always_inline]]
inline void EnableSubBG0()
{
	BOTTOM_SCREEN_RELATED |= 0x01;
}

[[gnu::always_inline]]
inline void EnableSubBG1()
{
	BOTTOM_SCREEN_RELATED |= 0x02;
}

[[gnu::always_inline]]
inline void EnableSubBG2()
{
	BOTTOM_SCREEN_RELATED |= 0x04;
}

[[gnu::always_inline]]
inline void EnableSubBG3()
{
	BOTTOM_SCREEN_RELATED |= 0x08;
}

[[gnu::always_inline]]
inline void EnableSubOBJ()
{
	BOTTOM_SCREEN_RELATED |= 0x10;
}