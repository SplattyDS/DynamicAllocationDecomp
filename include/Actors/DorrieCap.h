#pragma once

struct Dorrie;

struct DorrieCap : Actor
{
	CapIcon capIcon;            // 0xd4
	Model model;                // 0xf0
	MovingCylinderClsn cylClsn; // 0x140
	Dorrie* owner;              // 0x174
	u32 unk178;
	u32 unk17c;
	u32 unk180;
	
	bool FUN_02119210();
};

static_assert(sizeof(DorrieCap) == 0x184);