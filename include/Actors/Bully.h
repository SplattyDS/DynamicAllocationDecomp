#pragma once

struct BullyRes
{
	SharedFilePtr* modelFile;    // 0x0
	SharedFilePtr* deadAnimFile; // 0x4
	SharedFilePtr* hitAnimFile;  // 0x8
	SharedFilePtr* turnAnimFile; // 0xc
	SharedFilePtr* walkAnimFile; // 0x10
	Fix12i radius;               // 0x14
	Fix12i height;               // 0x18
	Fix12i hitSpeedDec;          // 0x1c
	Fix12i offsetY;              // 0x20
	Fix12i wmClsnRadius;         // 0x24
	Fix12i maxShadowRadius;      // 0x28
	Fix12i maxFallDist;          // 0x2c
	u32 dyingParticle;           // 0x30 (smoke particle id, melt particle id should be this + 1)
};

struct BullyBase : Enemy
{
	enum States
	{
		ST_WALK,
		ST_CHASE,
		ST_HIT,
		ST_AT_CLIFF,
		ST_DYING,
		ST_DEAD,
	};
	
	enum Animations
	{
		DEAD,
		HIT,
		TURN,
		WALK,
		
		NUM_ANIMS,
	};
	
	ModelAnim modelAnim;        // 0x110
	WithMeshClsn wmClsn;        // 0x174
	BullyRes* res;              // 0x330
	u32 smokeParticleID;        // 0x334
	u32 meltParticleID;         // 0x338
	MovingCylinderClsn cylClsn; // 0x33c
	ShadowModel shadow;         // 0x370
	u32 state;                  // 0x398
	Vector3 backupPos;          // 0x39c
	Vector3 deathPos;           // 0x3a8 (is originalPos if not dying)
	Matrix4x3 shadowMat;        // 0x3b4
	s16 targetDir;              // 0x3e4
	// 0x3e6
	Fix12i hitSpeedDec;         // 0x3e8
	Fix12i offsetY;             // 0x3ec
	Fix12i maxShadowRadius;     // 0x3f0
	Fix12i floorPosY;           // 0x3f4
	// 0x3f8
	u8 jumpCounter;             // 0x3f9
	
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~BullyBase() override;
	virtual Fix12i OnAimedAtWithEgg() override;
	virtual void OnUpdateChase();
	virtual void OnUpdateDying();
	virtual void OnMove();
	virtual void OnHitByPlayer();
	virtual void OnHitPlayer();
	virtual void OnTouchLava();
	
	s32 BaseInitResources();
	s32 BaseBehavior();
	
	void DropShadow(); // + UpdateModelTransform()
	void GetHurtOrHurtPlayer();
	void CheckIfTouchedBadSurface();
	void SpawnHitParticles(Actor& player);
	bool TurnToPlayer(s16 angVelY);
	bool UpdateDeath();
	bool ShouldChasePlayer();
	
	void Move();
	void UpdateChase();
	void UpdateHit();
	void UpdateAtCliff();
};

struct Bully : BullyBase
{
	u32 bigBullyID; // 0x3fc
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	static BullyRes resources;
	
	Bully();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~Bully() override;
	virtual void OnUpdateChase() override;
	virtual void OnUpdateDying() override;
	virtual void OnMove() override;
	virtual void OnHitByPlayer() override;
	virtual void OnHitPlayer() override;
	virtual void OnTouchLava() override;
};

struct BigBully : BullyBase
{
	u16 soundTimer;      // 0x3fa
	u8 starID;           // 0x3fc
	s8 trackStarID;      // 0x2fd
	u8 numBulliesKilled; // 0x3fe
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static BullyRes resources;
	
	BigBully();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BigBully() override;
	virtual void OnUpdateChase() override;
	virtual void OnUpdateDying() override;
};

struct ChillBully : BullyBase
{
	u8 starID;      // 0x3fa
	s8 trackStarID; // 0x3fb
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	static BullyRes resources;
	
	ChillBully();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~ChillBully() override;
	virtual void OnUpdateChase() override;
	virtual void OnUpdateDying() override;
};