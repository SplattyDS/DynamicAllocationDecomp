#ifndef SM64DS_LEVEL_INCLUDED
#define SM64DS_LEVEL_INCLUDED

#include "SM64DS_Common.h"


//Order for spawning: 2 3 4 b 1 6 7 8 9 c e a
//In other words:
/*
	Path Nodes
	Paths
	Views
	Minimap Tile File
	Level Entrances
	Teleport Source
	Teleport Dest
	Fog
	Doors
	Minimap Scale
	Star Cameras
	Level Exits
*/
//Not putting these in order in the file can result in drastic consequences
//such as 8-directional cameras suddenly getting angle 0x751c.

namespace LevelFile
{
	struct MapTile;
	struct View;
	struct Entrance;
	struct Path;
}

extern "C"
{
	extern LevelFile::MapTile (*MAP_TILE_ARR_PTR)[];
	extern LevelFile::View (*VIEW_ARR_PTR)[];
	extern LevelFile::Entrance (*ENTRANCE_ARR_PTR)[];
	extern LevelFile::Path (*PATH_ARR_PTR)[];

	extern u8 LAST_ENTRANCE_ID;
	extern u8 NUM_ENTRANCES;
	extern u8 NUM_VIEWS;
	extern u32 NUM_PATHS;
}

struct PathPtr
{
	const LevelFile::Path* ptr;

	// originally contains this second member, but none of the documented
	// functions use it so it's commented out for better performance

	// u32 unk04 = 0;
	
	PathPtr() : ptr(nullptr) {}
	PathPtr(const LevelFile::Path* path) : ptr(path) {}
	PathPtr(const LevelFile::Path& path) : ptr(&path) {}
	explicit PathPtr(u32 pathID) { FromID(pathID); }
	explicit PathPtr(s32 pathID) : PathPtr(static_cast<u32>(pathID)) {}
	
	void FromID(u32 pathID);
	void GetNode(Vector3& vF, u32 index) const;
	u32 NumNodes() const;

	[[gnu::always_inline, nodiscard]]
	auto GetNode(const u32& index) const
	{
		return Vector3::Proxy([this, &index]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			GetNode(res, index);
		});
	}
	
	[[gnu::always_inline, nodiscard]]
	auto operator[](const std::integral auto& index) const { return GetNode(index); }
	
	inline const LevelFile::Path& operator* () const { return *ptr; }
	inline const LevelFile::Path* operator->() const { return ptr; }
	
	inline explicit operator bool() const { return ptr != nullptr; }
	
	inline bool operator==(const PathPtr& other) const { return this->ptr == other.ptr; }
	
	inline operator const LevelFile::Path*      &()       { return ptr; }
	inline operator const LevelFile::Path* const&() const { return ptr; }
};

namespace LevelFile
{
	struct PathNode
	{
		Vector3_16 pos;
	};
	
	struct Path
	{
		u16 firstNodeID;
		u8 numNodes;
		u8 unk3; // always 0xff?
		u8 unk4; // inheritance?
		u8 unk5; // 0xff = loop, 0x7f = no loop?
	};
	
	struct View
	{
		enum Modes : u8
		{
			OUTSIDE_CYLINDER,
			INSIDE_CYLINDER,
			NORMAL_CAMERA,
			POINT_FOR_MULTIFOCUS_CAMERA,
			ROTATION_ONLY_CAMERA,
			SPIRALING_STAIRS, // ?
			PATH_FOLLOWING_CAMERA,
			PAUSE_CAMERA_CENTER_POINT
		};

		u8 mode;
		u8 param2; // ff: normal
		Vector3_16 pos;
		Vector3_16 rot;
		
		static LevelFile::View& Get(u32 viewID);
	};

	struct Entrance
	{
		u16 unk00; // just zero?
		Vector3_16 pos;
		Vector3_16 rot;
		u16 unk0e; // ???
	};
	
	struct MapTile
	{
		s16 ov0FileID;
	};
}

#endif