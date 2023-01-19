#pragma once

struct KCL_File
{
	struct Triangle
	{
		u32 length;
		u16 origin;
		u16 normal;
		u16 direction1;
		u16 direction2;
		u16 direction3;
		u16 collisionType;
	};
	
	Vector3* vertices;
	Vector3_16f* vectors;
	Triangle* triangles;
	void* octree;
	u32 unk10;
	Vector3 octreeOrigin;
	Vector3 octreeNegativeDimensions;
	u32 octreeBaseWidthLog2;
	u32 unk30;
	u32 unk34;
};

static_assert(sizeof(KCL_File) == 0x38);
static_assert(sizeof(KCL_File::Triangle) == 0x10);