#pragma once

struct BMD_File
{
	struct Bone
	{
		enum Flags
		{
			BILLBOARD = 1 << 0
		};
		
		s32 boneID;
		char* name;
		s16 offsetToParent; // in bones, not in bytes
		s16 hasChildren;
		s32 offsetToNextSibling; // in bones, not in bytes
		Vector3 scale;
		Vector3_16 rotation;
		u16 unk22; // probably padding
		Vector3 translation;
		u32 numDisplayListMaterialPairs;
		u8* materialIDList;
		u8* diplayListIDList;
		u32 flags;
	};
	
	struct DisplayList
	{
		u32 numTransforms;
		u32* transforms;
		u32 dataSize;
		u32* data;
	};
	
	struct DisplayListHeader
	{
		u32 numLists; // usually 1
		DisplayList* list;
	};
	
	struct Texture
	{
		char* name;
		char* data; // dangling after Model::LoadFile
		u32 size;
		u16 width;
		u16 height;
		u32 cmd2aPart1;
	};
	
	struct Palette
	{
		char* name;
		char* data; // dangling after Model::LoadFile
		u32 size;
		u32 vramOffset;
	};
	
	struct Material
	{
		char* name;
		s32 textureID; // -1 when no texture, when higher than 0x02000000 it's a pointer
		s32 paletteID; // -1 when no palette, when higher than 0x02000000 it's a pointer
		Vector2 scale;
		s16 rotation;
		Vector2 translation;
		u32 cmd2aPart2;
		u32 cmd29;
		u32 cmd30;
		u32 cmd31;
	};
	
	struct Unknown
	{
		void* unk00;
		void* unk04;
		void* unk08;
		void* unk0c;
	};
	
	u32 scaleShift;
	u32 numBones;
	Bone* bones;
	u32 numDisplayLists;
	DisplayListHeader* displayLists;
	u32 numTextures;
	Texture* textures;
	u32 numPalettes;
	Palette* palettes;
	u32 numMaterials;
	Material* materials;
	void* TransformMap;
	u32 hasUnknown;
	Unknown* unknown;
	u32 ramSize;
};

static_assert(sizeof(BMD_File) == 0x3c);
static_assert(sizeof(BMD_File::Bone) == 0x40);
static_assert(sizeof(BMD_File::Texture) == 0x14);
static_assert(sizeof(BMD_File::Palette) == 0x10);
static_assert(sizeof(BMD_File::Material) == 0x30);