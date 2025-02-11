#pragma once

struct DebugLevelSelect : Scene
{
	u16 holdButtonTimer; // 0x50
	u16 unk52;           // unused
	
	static BaseSpawnInfo spawnData;
	
	DebugLevelSelect();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~DebugLevelSelect() override;
	
	void DisplayLines();
	
	static void DisplayLevel(s32 levelID, s32 y, s32 x);
	static void DisplayString(char* string, s32 y, s32 x);
};

struct LineInfo
{
	s8 levelID;
	u8 entranceID;
	const char* name;
};

static_assert(sizeof(DebugLevelSelect) == 0x54, "Size of DebugLevelSelect is incorrect.");