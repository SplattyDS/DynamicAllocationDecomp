#pragma once

struct BBH_Platform : Actor
{
	enum Types
	{
		MANSION_STEPS,
		TRAP_DOOR,
		BOOKSHELF,
		MERRY_GO_ROUND,
		
		NUM_TYPES,
	};
	
	Model model;             // 0xd4
	Player* player;          // 0x124
	u32 spawnerID;           // 0x128 (for MANSION_STEPS)
	Vector3 originalPos;     // 0x12c
	s16 turnSpeed;           // 0x138 (for TRAP_DOOR)
	s16 rotationSpeed;       // 0x13a (for MERRY_GO_ROUND)
	u16 unk13c;              // 0x13c (unused?)
	u32 type;                // 0x140
	s32 offsetY;             // 0x144 (for MANSION_STEPS)
	u32 soundID;             // 0x148
	u16 stateTimer;          // 0x14c
	u16 soundTimer;          // 0x14e
	u8 state;                // 0x150
	u8 stepID;               // 0x151
	bool unk152;             // 0x152 (for MERRY_GO_ROUND, Boo related)
	bool unk153;             // 0x153 (for MERRY_GO_ROUND, Boo related)
	u8 unk154;               // 0x154 (unused?)
	bool activated;          // 0x155 (for MANSION_STEPS)
	bool visible;            // 0x156
	u8 openingFlags;         // 0x157 (for BOOKSHELF)
	s8 trueAreaID;           // 0x158 (for BOOKSHELF)
	MovingMeshCollider clsn; // 0x15c
	Matrix4x3 clsnNextMat;   // 0x324
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_TYPES];
	static SharedFilePtr clsnFiles[NUM_TYPES];
	static CLPS_Block* clpsBlocks[NUM_TYPES];
	
	BBH_Platform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~BBH_Platform() override;
	virtual void vPressBookshelfSwitch(u8 switchFlag);
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
	bool MoveStepsUp(u16 stepTimer);
	void CheckIfBoosCanSpawn();
	void PressBookshelfSwitch(u8 switchFlag);
	void AfterClsn(Actor& otherActor);
	
	void MansionStepsBehavior();
	void TrapDoorBehavior();
	void BookshelfBehavior();
	void MerryGoRoundBehavior();
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};