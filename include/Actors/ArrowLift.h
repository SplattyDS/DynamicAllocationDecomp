#pragma once

struct ArrowLift : Platform
{
	Fix12i unk320;  // 0x320
	u16 stateTimer; // 0x324
	bool hadClsn;   // 0x326
	u8 state;       // 0x327
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	ArrowLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ArrowLift() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};