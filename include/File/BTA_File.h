#pragma once

struct BTA_File
{
	struct Animation
	{
		u16 materialID;
		u16 unk02; // probably padding
		char* materialName;
		u16 numScaleXs;
		u16 scaleXOffset;
		u16 numScaleYs;
		u16 scaleYOffset;
		u16 numRots;
		u16 rotOffset;
		u16 numTransXs;
		u16 transXOffset;
		u16 numTransYs;
		u16 transYOffset;
	};
	
	u32 numFrames;
	Fix12i* scales;
	s16* rots;
	Fix12i* transs;
	s32 numAnims;
	Animation* anims;
};

static_assert(sizeof(BTA_File) == 0x18);
static_assert(sizeof(BTA_File::Animation) == 0x1c);