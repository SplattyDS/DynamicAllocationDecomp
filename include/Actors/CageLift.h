#pragma once

struct CageLift : Platform
{
	Fix12i unk320;  // 0x320
	u32 soundID;    // 0x324
	u16 stateTimer; // 0x328
	bool hadClsn;   // 0x32a
	bool unk32b;    // 0x32b
	u8 state;       // 0x32c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	CageLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~CageLift() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};