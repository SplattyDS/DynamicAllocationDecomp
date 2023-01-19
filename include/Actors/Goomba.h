#pragma once

struct Goomba : public CapEnemy
{
	enum Type
	{
		SMALL,
		NORMAL,
		BIG,
		GOOMBOSS_GOOMBA,
		
		NUM_SIZES = GOOMBOSS_GOOMBA,
	};
	
	enum Animations
	{
		WALK,
		ROLLING,
		STRETCH,
		UNBALANCE,
		RECOVER,
		WAIT,
		RUN,
		
		NUM_ANIMS,
	};
	
	MovingCylinderClsn cylClsn;  // 0x180
	WithMeshClsn wmClsn;         // 0x1b4
	ModelAnim modelAnim;         // 0x370
	ShadowModel shadow;          // 0x3d4
	MaterialChanger materialChg; // 0x3fc
	Vector3 noCliffPos;          // 0x410
	Vector3 originalPos;         // 0x41c
	Vector3 backupPos;           // 0x428
	u32 state;                   // 0x434
	Player* player;              // 0x438
	u32 goombossID;              // 0x43c
	Fix12i distToPlayer;         // 0x440 (capped at 0x001a8000, and actually 0x061a8000 when it hits the cap)
	Fix12i targetSpeed;          // 0x444
	Fix12i maxDist;              // 0x448
	u32 recoverFlags;            // 0x44c (flags the Goomba would've used if it could recover from being spit out, always 0)
	u16 movementTimer;           // 0x450
	u16 regurgTimer;             // 0x452
	u16 changeDirTimer;          // 0x454 (only used by Goomboss Goombas, would've also been used by regular Goombas if they could recover)
	u16 stuckInSpotTimer;        // 0x456
	u16 noChargeTimer;           // 0x458
	s16 targetDir;               // 0x45a
	s16 targetDir2;              // 0x45c
	// u16 unk45e;               // 0x45e (unused)
	u32 type;                    // 0x460
	u8 spawnStar;                // 0x464 (0: no star, 1: silver star, 2: VS mode star)
	s8 starID;                   // 0x465 (it is signed)
	u8 starID_VS;                // 0x466
	u8 regurgBounceCount;        // 0x467
	u8 flags468;                 // 0x468
	// u8 unk469;                // 0x469 (unused)
	// u16 unk46a;               // 0x46a (unused)
	u32 hitFlags;                // 0x46c
	// u32 unk470;               // 0x470 (unused)
	u8 goombaID;                 // 0x474 (only used by Goomboss Goombas, set by Goomboss)
	u8 followGoombossTimer;      // 0x475 (when the timer hits 0, the Goomba will stop going after / looking for the player and will try to go back to following Goomboss)
	// u16 unk476;               // 0x476 (unused)
	
	static SpawnInfo spawnData[NUM_SIZES];
	static GloballySharedFilePtr modelFile;
	static GloballySharedFilePtr animFiles[NUM_ANIMS];
	
	Goomba();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Goomba() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	virtual BMA_File* vGetRegurgMaterialDef();
	virtual void vSetOriginalPos(Vector3& newOriginalPos);
	
	void UpdateMaxDist();
	void TrackVsStarIfNecessary();
	void Kill();
	void SpawnStarIfNecessary();
	bool UpdateIfDying();
	void RenderRegurgGoombaHelpless(Player* player);
	void KillIfTouchedBadSurface();
	void UpdateModelTransform();
	bool UpdateIfEaten();
	void PlayMovingSound();
	void GetHurtOrHurtPlayer();
	void KillIfIntoxicated();
	void Jump();
	void UpdateTargetDirAndDist(Fix12i theMaxDist);
	void SetOriginalPos(Vector3& newOriginalPos);
	
	void State0();
	void State0_NormalGoomba();
	void State0_GoombossGoomba();
	void State1();
	void State2();
	void State3();
	void State4();
};