#pragma once

struct TowerStep : Platform
{
	enum Param
	{
		DONT_MOVE,
		MOVE_BACK_AND_FORTH,
		MOVE_UP_AFTER_CLSN,
	};
	
	ShadowModel shadow;   // 0x320
	Matrix4x3 shadowMat;  // 0x348
	Fix12i floorPosY;     // 0x378
	Fix12i minPosY;       // 0x37c
	Fix12i maxPosY;       // 0x380
	Fix12i shadowOffsetX; // 0x384
	Fix12i shadowOffsetY; // 0x388
	u32 soundID;          // 0x38c
	u8 moveTimer;         // 0x390
	bool justSteppedOn;   // 0x391
	bool move;            // 0x392
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	TowerStep();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TowerStep() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	virtual void Kill() override;
	
	void DropShadow();
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};