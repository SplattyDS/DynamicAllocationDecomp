#pragma once

struct Trap : Platform
{
	enum States
	{
		ST_CLOSED,
		ST_OPENING,
		ST_OPENED,
		ST_CLOSING,
		ST_CLOSED_PERMANENTLY,
	};
	
	// Model model2;           // 0x320 (why did Nintendo not use Platform::model...)
	// Matrix4x3 clsnNextMat2; // 0x370 (same for Platform::clsnNextMat...)
	
	u32 state;         // 0x3a0
	Fix12i playerDist; // 0x3a4 (only set for spawners, not used by Trap functions)
	s16 openSpeed;     // 0x3a8
	u8 trapActive;     // 0x3aa (used by spawner)
	bool isSpawner;    // 0x3ab
	u32 spawnerID;     // 0x3ac
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	Trap();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Trap() override;
	
	void UpdateClsnTransform();
	void UpdateModelTransform();
	void AfterCollision(Actor& player);
	Trap* GetTrapSpawner();
	
	void State0_Closed();
	void State1_Opening();
	void State2_Opened();
	void State3_Closing();
	void State4_ClosedPermanently();
	
	static void OnFloorAfterClsn(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};