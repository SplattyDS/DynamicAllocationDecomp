#pragma once

struct RecRoomCupboard : Actor
{
	static constexpr s32 NUM_CYL_CLSNS = 5;
	
	MovingCylinderClsnWithPos cylClsns[NUM_CYL_CLSNS]; // 0xd4
	Player* listener;                                  // 0x214
	bool unk218;                                       // 0x218
	u16 messageID;                                     // 0x21a
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	RecRoomCupboard();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual ~RecRoomCupboard() override;
};