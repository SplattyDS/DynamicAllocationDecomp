#pragma once

struct SkiLift : Platform
{
	Player* player;      // 0x320
	Vector3 originalPos; // 0x324
	bool moving;         // 0x330
	u8 moveTimer;        // 0x331
	// u16 unk332;
	u32 pathID;          // 0x334
	u32 numNodes;        // 0x338
	u32 nextNode;        // 0x33c
	// u32 unk340;
	// u32 unk344;
	// u32 unk348;
	s32 direction;       // 0x34c
	u32 soundID;         // 0x350
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SkiLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SkiLift() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	
	void UpdateModelTransform();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};