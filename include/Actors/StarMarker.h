#pragma once

struct StarMarker : public Actor
{
	MovingCylinderClsnWithPos cylClsn;
	Model model;
	ShadowModel shadowModel;
	u32 unk18c;
	u32 unk190;
	u32 unk194;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u32 unk1a4;
	u32 unk1a8;
	u32 unk1ac;
	u32 unk1b0;
	u32 unk1b4;
	u32 unk1b8;
	u32 unk1bc;
	u32 unk1c0;
	u32 unk1c4;
	u32 unk1c8;
	u32 unk1cc;
	u32 unk1d0;
	u32 unk1d4;
	u8  unk1d8;
	s8  starID;
	u8  unk1da;
	u8  unk1db;
};

static_assert(sizeof(StarMarker) == 0x1dc, "sizeof(StarMarker) is incorrect!");