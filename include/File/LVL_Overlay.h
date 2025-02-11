#pragma once

struct CLPS_Block;

struct LVL_Overlay
{
	struct ObjSubTable
	{
		u8 objsInfo; // bit 0-4: object type, bit 5-7: star id (0 = all stars)
		u8 numObjs;
		u16 unk02; // always 0?
		void* objs;
	};
	
	struct ObjTable
	{
		u32 numSubTables;
		ObjSubTable* subTables;
	};
	
	struct Area
	{
		ObjTable* objs; // only type 0 and 5 objects (StandardObj and SimpleObj)
		BTA_File* texAnim;
		u8 minimapScreenIndex;
		u8 unk09;
		u16 unk0a;
	};
	
	struct StandardObj
	{
		// 16 bytes
		u16 objID;
		Vector3_16 pos;
		Vector3_16 ang;
		u16 param1;
	};
	
	struct EntranceObj
	{
		// 16 bytes
		u16 playerObjectID; // always 0 (Player)
		Vector3_16 pos;
		Vector3_16 ang;
		u16 param1;
	};
	
	struct PathNodeObj
	{
		// 6 bytes
		Vector3_16 pos;
	};
	
	struct PathObj
	{
		// 6 bytes
		u16 startNodeID;
		u8 numNodes;
		u8 param1;
		u8 param2;
		u8 param3;
	};
	
	struct ViewObj
	{
		// 14 bytes
		u16 param1;
		Vector3_16 pos;
		Vector3_16 ang;
	};
	
	struct SimpleObj
	{
		u16 objInfo; // bit 0-8: objID, bit 9-15: param1
		Vector3_16 pos;
	};
	
	struct TeleportSourceObj
	{
		// 8 bytes
		Vector3_16 pos;
		u16 param1;
	};
	
	struct TeleportDestObj
	{
		// 8 bytes
		Vector3_16 pos;
		u16 param1;
	};
	
	struct FogObj
	{
		// 8 bytes
		bool enableFog;
		u8 r;
		u8 g;
		u8 b;
		u16 startDist;
		u16 endDist;
	};
	
	struct DoorObj
	{
		// 12 bytes
		Vector3_16 pos;
		short angY;
		u16 param1; // bits 0-3: virtual door width, bits 4-7 virtual door height, bits 8-11: inside areaID, bits 12-15: outside areaID
		u8 doorType;
		u8 unk0b;
	};
	
	struct ExitObj
	{
		// 14 bytes
		Vector3_16 pos;
		short angX;
		short angY;
		u8 destLevelID;
		u8 destEntranceID;
		u8 returnEntranceID;
		u8 widthHeight; // unknown
	};
	
	struct MinimapScreenObj
	{
		// 2 bytes
		u16 fileID;
	};
	
	struct MinimapScaleObj
	{
		// 2 bytes
		Fix12s scale;
	};
	
	// this type of object is in none of the overlays, the only thing it does is set 0x0209f338 to a pointer to these objects, this pointer never gets read
	struct UnusedType13Object
	{
		u32 unk;
	};
	
	struct StarCameraObj
	{
		// 4 bytes
		u32 starCutsceneIDs; // use '& (1 << STAR_ID)' on this to get the cutscene ID
	};
	
	// static (de)initializer code
	CLPS_Block* clps;
	ObjTable* miscObjs;
	u16 modelFileID;
	u16 clsnFileID;
	u16 mGraphicFileID;
	u16 mPaletteFileID;
	Area* areas;
	u8 numAreas;
	bool startWithFarCamera;
	u16 minimapScaleFactor;
	u8 skyboxID; // upper 4 bits are skybox ID, lower 4 bits are unused (always 0xf)?
	u8 unk19; // always 0?
	u16 unk1a; // always 0?
	u8 sGroupID;
	u8 sBankID;
	u8 sSequenceID;
	u8 reserved1f;
	u32 reserved20;
	u32 reserved24;
	u32 reserved28;
	u32 reserved2c;
	u32 reserved30;
};