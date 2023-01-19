#pragma once

struct DYLB_File
{
	u16 numPtrsToFix;
	u16 ptrsOffset;
	u16 initFunc;
	u16 cleanFunc;
};

static_assert(sizeof(DYLB_File) == 0x8);