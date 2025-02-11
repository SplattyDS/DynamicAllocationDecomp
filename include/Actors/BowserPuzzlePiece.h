#pragma once

struct BowserPuzzlePiece : Platform
{
	static constexpr s32 NUM_PIECES = 14;
	
	u32 managerID;     // 0x320
	s8* stateInfo;     // 0x324
	u8 stateIndex;     // 0x328
	// u32 unk32c;     // 0x32c (unused)
	Fix12i offsetY;    // 0x330
	u16 moveTimer;     // 0x334
	u8 state;          // 0x336
	u8 type;           // 0x337
	bool hadClsn;      // 0x338
	bool freezeState;  // 0x339 (unused)
	bool canSpawnCoin; // 0x33a
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFiles[NUM_PIECES];
	static SharedFilePtr clsnFile;
	
	BowserPuzzlePiece();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BowserPuzzlePiece() override;
	
	void State0_Init();
	void State1_Wait();
	void State2_MoveLeft();
	void State3_MoveRight();
	void State4_MoveDown();
	void State5_MoveUp();
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
	void UpdateState();
	void Move(Fix12i moveX, Fix12i moveZ, u16 moveDelay);
	void SpawnCoin();
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};