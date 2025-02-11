#pragma once

struct PyramidLift : Platform
{
	static constexpr s32 NUM_BULLETS = 10;
	
	Model bulletModel;              // 0x320
	Vector3 originalPos;            // 0x370
	Vector3 bulletPos[NUM_BULLETS]; // 0x37c
	u16 stateTimer;                 // 0x3f4
	u8 state;                       // 0x3f6
	bool hadClsn;                   // 0x3f7
	u8 nextBullet;                  // 0x3f8
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	PyramidLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~PyramidLift() override;
	
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};