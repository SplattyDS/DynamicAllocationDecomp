#pragma once

struct KoopaTheQuick : Enemy
{
	enum Animations : u8
	{
		JUMP_ED,
		WALK_ST,
		WALK_ED,
		WALK,
		JUMP_ST,
		WAIT1,
		WAIT2,
		
		NUM_ANIMS,
	};
	
	MovingCylinderClsn cylClsn;     // 0x110
	WithMeshClsn wmClsn;            // 0x144
	ModelAnim modelAnim;            // 0x300
	ShadowModel shadow;             // 0x364
	u32 state;                      // 0x38c
	u8 stateState;                  // 0x390
	// u8 unk391;                   // 0x391 (unused)
	// u16 unk392;                  // 0x392 (unused)
	u32 flagID;                     // 0x394
	Player* player;                 // 0x398
	Vector3 originalPos;            // 0x39c (doesn't get used after assignment)
	u16 targetDir;                  // 0x3a8
	// u16 unk3aa;                  // 0x3aa (gets assigned to 0 twice, in InitResources, and when you select go while talking to him, doesn't get used besides that)
	bool hasPlayerUsedCannon;       // 0x3ac
	u8 pathPtToJumpAt1;             // 0x3ad
	u8 pathPtToJumpAt2;             // 0x3ae
	bool hasPlayerWon;              // 0x3af
	s8 trackedStar;                 // 0x3b0
	u8 starID;                      // 0x3b1
	bool justSpawnedParticles;      // 0x3b2
	bool notTalkedToMarioAfterRace; // 0x3b3
	bool hasFinished;				// 0x3b4
	bool isRacing;					// 0x3b5
	bool isTalkingToMario;			// 0x3b6
	// u8 unk3b7;                   // 0x3b7 (unused)
	u32 numPathPts;                 // 0x3b8
	u32 curPathPt;                  // 0x3bc
	Vector3 curPathPos;             // 0x3c0
	Vector3 nextPathPos;            // 0x3cc
	PathPtr pathPtr;                // 0x3d8
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	KoopaTheQuick();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~KoopaTheQuick() override;
	
	void UpdateModelTransform();
	void Wait();
	void Talk();
	void Run();
	void SlowDown();
	void StopRunning();
	void WaitOrTalkAtFinish();
	s32 AdvancePathIfReached();
	void SpawnParticlesIfStepOnGround();
	s32 CheckIfIronBallNearby();
	void Jump();
};