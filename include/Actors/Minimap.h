#pragma once

//vtable at 0210c1c0, constructor at 020fb8bc, dtor at 0x020F975C
//Code address to init 256x256 map: 020fb568
//Code address to init 128x128 map: 020fb694
struct Minimap : ActorDerived //ActorID = 0x14f
{
	enum ArrowType
	{
		AR_NONE = 0,
		AR_DONT_ROTATE_WITH_MINIMAP = 1,
		AR_ROTATE_WITH_MINIMAP = 2
	};
	
	u32 unk050;
	u32 unk054;
	u32 unk058;
	u32 unk05c;
	u32 unk060;
	u32 unk064;
	u32 unk068;
	u32 unk06c;
	u32 unk070;
	u32 unk074;
	u32 unk078;
	u32 unk07c;
	u32 unk080;
	u32 unk084;
	u32 unk088;
	u32 unk08c;
	u32 unk090;
	u32 unk094;
	u32 unk098;
	u32 unk09c;
	u32 unk0a0;
	u32 unk0a4;
	u32 unk0a8;
	u32 unk0ac;
	u32 unk0b0;
	u32 unk0b4;
	u32 unk0b8;
	u32 unk0bc;
	u32 unk0c0;
	u32 unk0c4;
	u32 unk0c8;
	u32 unk0cc;
	u32 unk0d0;
	u32 unk0d4;
	u32 unk0d8;
	u32 unk0dc;
	u32 unk0e0;
	u32 unk0e4;
	u32 unk0e8;
	u32 unk0ec;
	u32 unk0f0;
	u32 unk0f4;
	u32 unk0f8;
	u32 unk0fc;
	u32 unk100;
	u32 unk104;
	u32 unk108;
	u32 unk10c;
	u32 unk110;
	u32 unk114;
	u32 unk118;
	u32 unk11c;
	u32 unk120;
	u32 unk124;
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;
	u32 unk138;
	u32 unk13c;
	u32 unk140;
	u32 unk144;
	u32 unk148;
	u32 unk14c;
	u32 unk150;
	u32 unk154;
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;
	u32 unk168;
	u32 unk16c;
	u32 unk170;
	u32 unk174;
	u32 unk178;
	u32 unk17c;
	u32 unk180;
	u32 unk184;
	u32 unk188;
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
	u32 unk1d8;
	u32 unk1dc;
	u32 unk1e0;
	u32 unk1e4;
	u32 unk1e8;
	u32 unk1ec;
	u32 unk1f0;
	Vector3 center;
	Matrix2x2 arrowMat;
	u32 unk210;
	Fix12i targetInvScale;
	Fix12i invScale;
	s16 angle;
	s16 unk21e;
	u32 unk220;
	u32 unk224;
	u32 unk228;
	u32 unk22c;
	u32 unk230;
	u32 unk234;
	u32 unk238;
	u32 unk23c;
	u32 unk240;
	u32 unk244;
	u32 unk248;
	u32 unk24c;
	u8 unk250;
	u8 arrowType;
	u8 unk252;
	u8 unk253;
	u8 unk254; // some counter
	u8 unk255;
	u8 unk256;
	u8 unk257;
	
	static void UpdateLevelSpecific();
};