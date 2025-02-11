#pragma once

struct DonutBlock : Platform
{
	WithMeshClsn wmClsn; // 0x320
	Vector3 originalPos; // 0x4dc
	bool hadClsn;        // 0x4e8
	u8 clsnTimer;        // 0x4e9
	u8 state;            // 0x4ea
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	DonutBlock();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~DonutBlock() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};