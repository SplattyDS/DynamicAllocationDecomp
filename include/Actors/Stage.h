#pragma once

struct MinimapChangeObject
{
	Fix12i posY;
	u8 param;
	MinimapChangeObject* prev;
	MinimapChangeObject* next;
};

struct Area
{
	TextureTransformer* texSRT;
	bool showing;
	u8 unk5;
	u16 unk6;
	MinimapChangeObject* minimapChanger;
};

struct Fog
{
	u8 table[32];
	bool enabled;
	u8 info;
	u16 offset;
	u16 color;
	u16 unk26; // unk992 / unk9ba
};

struct Stage : Scene
{
	Particle::SysTracker particleSysTracker;
	Model model;
	Area areas[8];
	MeshCollider clsn;
	Fog fog[2];
	Model* skyBox;
	u32 unk9c0;
	u32 unk9c4;
	
	Stage();
	virtual s32 InitResources() override;
	virtual bool BeforeInitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Stage() override;
};

extern "C"
{
	extern LVL_Overlay* LEVEL_FILE;
	extern BMD_File* LEVEL_MODEL_FILE;

	extern u8 NUM_ENTRANCES;
	extern u32 NUM_PATHS;
	extern u8 NUM_VIEWS;
	extern u8 NUM_TELEPORT_DEST_OBJS;
	extern u8 NUM_FOG_OBJS;
	extern u8 MAP_TILE_ARR_SIZE;
	extern u8 NUM_MINIMAP_SCALE_OBJS;
	
	extern LVL_Overlay::EntranceObj* ENTRANCE_ARR_PTR;
	extern LVL_Overlay::PathNodeObj* PATH_NODE_ARR_PTR;
	extern LVL_Overlay::PathObj* PATH_ARR_PTR;
	extern LVL_Overlay::ViewObj* VIEW_ARR_PTR;
	extern LVL_Overlay::TeleportDestObj* TELEPORT_DEST_OBJS_PTR;
	extern LVL_Overlay::FogObj* FOG_OBJS_PTR;
	extern LVL_Overlay::MinimapScreenObj* MAP_TILE_ARR_PTR;
	extern LVL_Overlay::MinimapScaleObj* MINIMAP_SCALE_OBJS_PTR;
	extern void* UNUSED_TYPE_13_OBJS_PTR;
	
	extern u32 STAR_CAMERA_SETTINGS;
}

bool IsAreaShowing(s8 areaID);