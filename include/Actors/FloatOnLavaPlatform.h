#pragma once

struct FloatOnLavaPlatform : Platform
{
	Fix12i maxPosY; // 0x320
	bool hadClsn;   // 0x324
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	FloatOnLavaPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~FloatOnLavaPlatform() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};