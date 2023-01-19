#pragma once

struct BMA_File
{
	struct MaterialProperties
	{
		struct MaterialProperty
		{
			u8 unk00;     // always 1?
			bool advance; // true if has property
			u16 offset;   // in values
		};
		
		u16 ID;
		u16 unk02; // probably padding
		char* name;
		
		MaterialProperty difRed;
		MaterialProperty difGreen;
		MaterialProperty difBlue;
		MaterialProperty ambRed;
		MaterialProperty ambGreen;
		MaterialProperty ambBlue;
		MaterialProperty specRed;
		MaterialProperty specGreen;
		MaterialProperty specBlue;
		MaterialProperty emitRed;
		MaterialProperty emitGreen;
		MaterialProperty emitBlue;
		MaterialProperty alpha;
	};
	
	u16 numFrames;
	u16 unk02;
	u8* values;
	u32 numMatProps;
	MaterialProperties* matProps;
};

static_assert(sizeof(BMA_File) == 0x10);
static_assert(sizeof(BMA_File::MaterialProperties) == 0x3c);
static_assert(sizeof(BMA_File::MaterialProperties::MaterialProperty) == 0x4);