#pragma once

struct Koopa : Enemy
{
	enum Sizes
	{
		NORMAL,
		SMALL,
		
		NUM_SIZES,
	};
	
	enum Colors
	{
		GREEN,
		RED,
		
		NUM_COLORS,
	};
	
	enum Animations : u8
	{
		WALK_ST,
		WALK,
		WALK_ED,
		RUN,
		WAIT1,
		WAIT2, // only used by Koopa the Quick
		DIVE_ST,
		DIVE,
		DIVE_ED,
		
		NUM_ANIMS,
	};
	
	enum Materials
	{
		SKIN_MATERIAL_ID,
		SHIRT_MATERIAL_ID,
		SHELL_MATERIAL_ID,
		
		NUM_MATERIALS,
	};
	
	enum ShellState
	{
		IN_SHELL,
		OUT_SHELL,
		PERMANENT_IN_SHELL, // koopas with this die when jumped on instead of losing their shell, used for tiny koopas
	};
	
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	ModelAnim modelAnim;        // 0x300
	ShadowModel shadow;         // 0x364
	u32 state;                  // 0x38c
	u32 shellState;             // 0x390
	u32 color;                  // 0x394
	u8 animID;                  // 0x398
	u8 unk399;                  // 0x399 (unused)
	u16 unk39a;                 // 0x39a (unused)
	Vector3 originalPos;        // 0x39c
	Vector3 prevPos;            // 0x3a8
	Player* closestPlayer;      // 0x3b4
	Fix12i distToPlayer;        // 0x3b8
	Fix12i animSpeed;           // 0x3bc
	s16 targetDir;              // 0x3c0
	s16 targetDir2;             // 0x3c2
	u16 walkState;              // 0x3c4
	u16 walkTimer;              // 0x3c6
	u16 faceWallTimer;          // 0x3c8 (changes direction if facing a wall and the timer == 0)
	u16 invincibleTimer;        // 0x3ca
	bool needRedirect;          // 0x3cc
	bool steppedOnGround;       // 0x3cd
	u8 landingDustTimer;        // 0x3ce
	u8 unk3cf;                  // 0x3cf (unused)
	
	static SpawnInfo spawnData[NUM_SIZES];
	static SharedFilePtr modelFiles[NUM_COLORS];
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	Koopa();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Koopa() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void SpawnBlueCoin();
	void KillIfTouchWater();
	void UpdatePlayerDistance(Fix12i maxDist);
	void CallStateShell();
	void CallStateNoShell();
	void GetHurtOrHurtPlayer();
	void UpdateModelTransform();
	void WalkIfOnGround();
	void Wait();
	void Walk();
	void Run();
	void Dive();
	void RunWithoutShell();
	void DiveWithouthShell();
	void WalkWithoutShell();
	void ChangeAnimation(u8 animationID);
	void SpawnLandingDustParticles();
	void RunIfPlayerInRange();
	void StepOnGround(u16 minFrame1, u16 maxFrame1, u16 minFrame2, u16 maxFrame2);
	void StartWalking();
	void ContinueWalking();
	void StopWalking();
	Fix12i GetDistToPlayer();
	void SlowDownSliding(Fix12i speed);
	Actor* GetClosestShell();
	void GetOutOfShell();
	void BounceInPlace();
};