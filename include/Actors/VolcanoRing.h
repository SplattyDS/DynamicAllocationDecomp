#pragma once

struct VolcanoRing : Platform
{
	u8 state;          // 0x31e
	u8 fireSpawnTimer; // 0x31f
	bool hadCollision; // 0x320
	u16 stateTimer;    // 0x322
	u16 numFiresAlive; // 0x324
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	VolcanoRing();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~VolcanoRing() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};