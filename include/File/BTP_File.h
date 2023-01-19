#pragma once

struct BTP_File
{
	struct Texture
	{
		s16 index; // always -1 in ROM
		u16 unk02; // always 0, probably padding
		char* name;
	};
	
	struct Palette
	{
		s16 index; // always -1 in ROM
		u16 unk02; // always 0, probably padding
		char* name;
	};
	
	struct Material
	{
		s16 index; // always -1 in ROM
		u16 unk02; // always 0, probably padding
		char* name;
		u16 numIds;
		u16 idsOffset;
	};
	
	u16 numFrames;
	u16 numTextures;
	Texture* textures;
	u16 numPalettes;
	u16 unk0a; // probably padding
	Palette* palettes;
	u16* frameChanges;
	u16* textureIDs;
	u16* paletteIDs;
	u16 numMaterials; // 0 or 1, anything else causes a crash?
	u16 unk1e; //probably padding
	Material* materials;
};

static_assert(sizeof(BTP_File) == 0x24);
static_assert(sizeof(BTP_File::Texture) == 0x8);
static_assert(sizeof(BTP_File::Palette) == 0x8);
static_assert(sizeof(BTP_File::Material) == 0xc);