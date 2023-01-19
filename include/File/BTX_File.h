#pragma once

#include "BMD_File.h"

struct BTX_File
{
	u32 numTextures;
	BMD_File::Texture* textures;
	u32 numPalettes;
	BMD_File::Palette* palettes;
	u32 ramSize;
};

static_assert(sizeof(BTX_File) == 0x14);