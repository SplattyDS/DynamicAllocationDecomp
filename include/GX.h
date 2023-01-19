#pragma once

namespace GX
{
	void DisableAllBanks();
	void SetBankForTex(u16 tex);
	void SetBankForTexPltt(u16 texPltt);
	void SetBankForBG(u16 bg);
	void SetBankForOBJ(u16 obj);
	void SetBankForSubBG(u16 sub_bg);
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
}

namespace GXS
{
	void SetGraphicsMode(s32 bgMode);
	void LoadBGPltt(const void* src, u32 offset, u32 size);
	void LoadOBJPltt(const void* src, u32 offset, u32 size);
	void BeginLoadOBJExtPltt();
	void LoadOBJExtPltt(const void* src, u32 destSlotAddr, u32 size);
	void EndLoadOBJExtPltt();
}

namespace G3X
{
	void SetClearColor(u16 rgb, s32 alpha, s32 depth, s32 polygonID, bool fog);
	void SetFog(bool enable, s32 fogMode, s32 fogSlope, s32 fogOffset);
}

namespace G3i
{
	void PerspectiveW_(s32 fovySin, s32 fovyCos, s32 aspect, s32 n, s32 f, s32 scaleW, bool draw, Matrix4x3* mat);
	void LookAt_(const Vector3* camPos, const Vector3* camUp, const Vector3* target, bool draw , Matrix4x3* mat);
}

// copies mat to VIEW_MATRIX_ASR_3, then inverts it to INV_VIEW_MATRIX_ASR_3
void CopyToViewMat(const Matrix4x3* mat);

extern "C"
{
	extern volatile u32 reg_GX_DISPCNT;		// 0x04000000
	extern volatile u16 reg_GX_DISPSTAT;	// 0x04000004
	extern volatile u16 reg_GX_VCOUNT;		// 0x04000006
	extern volatile u16 reg_G2_BG0CNT;		// 0x04000008
	extern volatile u16 reg_G2_BG1CNT;		// 0x0400000a
	extern volatile u16 reg_G2_BG2CNT;		// 0x0400000c
	extern volatile u16 reg_G2_BG3CNT;		// 0x0400000e
	extern volatile u32 reg_G2_BG0OFS;		// 0x04000010
	extern volatile u32 reg_G2_BG1OFS;		// 0x04000014
	extern volatile u32 reg_G2_BG2OFS;		// 0x04000018
	extern volatile u32 reg_G2_BG3OFS;		// 0x0400001c
	extern volatile u16 reg_G2_BG2PA;		// 0x04000020
	extern volatile u16 reg_G2_BG2PB;		// 0x04000022
	extern volatile u16 reg_G2_BG2PC;		// 0x04000024
	extern volatile u16 reg_G2_BG2PD;		// 0x04000026
	extern volatile u32 reg_G2_BG2X;		// 0x04000028
	extern volatile u32 reg_G2_BG2Y;		// 0x0400002c
	extern volatile u16 reg_G2_BG3PA;		// 0x04000030
	extern volatile u16 reg_G2_BG3PB;		// 0x04000032
	extern volatile u16 reg_G2_BG3PC;		// 0x04000034
	extern volatile u16 reg_G2_BG3PD;		// 0x04000036
	extern volatile u32 reg_G2_BG3X;		// 0x04000038
	extern volatile u32 reg_G2_BG3Y;		// 0x0400003c
	extern volatile u16 reg_GX_BLDCNT;		// 0x04000050
	// some window related stuff
	extern volatile u16 reg_G3X_DISP3DCNT;	// 0x04000060
	// display capture control register		// 0x04000064
	
	extern volatile u16 reg_GX_POWCNT;		// 0x04000304
	extern volatile u32 reg_GXS_DB_DISPCNT;	// 0x04001000
	extern volatile u16 reg_GXs_BLDCNT;		// 0x04001050
	
	extern u16 bgPalette[256];				// 0x05000000
	extern u16 objPalette[256];				// 0x05000200
	extern u16 bgPaletteSub[256];			// 0x05000400
	extern u16 objPaletteSub[256];			// 0x05000600
	
	extern u8 objTiles;						// 0x06200000
	extern u8 objTilesSub;					// 0x06600000
}