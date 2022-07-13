#ifndef GOOMBA_INCLUDED
#define GOOMBA_INCLUDED

#include "../SM64DS_2.h"
#include "../GloballySharedFilePtr.h"

// vtable at 0x02130948, size is 0x478, actor ids are 0xc8, 0xc9 and 0xca
struct Goomba : public CapEnemy
{
	enum Type
	{
		SMALL = 0,
		NORMAL = 1,
		BIG = 2,
		GOOMBOSS_GOOMBA = 3
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
		
		NUM_ANIMS
	};
	
	MovingCylinderClsn cylClsn;		// 0x180
	WithMeshClsn wmClsn;			// 0x1b4
	ModelAnim modelAnim;			// 0x370
	ShadowModel shadow;				// 0x3d4
	MaterialChanger materialChg;	// 0x3fc
	Vector3 noCliffPos;				// 0x410
	Vector3 originalPos;			// 0x41c
	Vector3 backupPos;				// 0x428
	u32 state;						// 0x434
	Player* player;					// 0x438
	u32 goombossID;					// 0x43c
	Fix12i distToPlayer;			// 0x440 (capped at 0x001a8000, and actually 0x061a8000 when it hits the cap)
	Fix12i targetSpeed;				// 0x444
	Fix12i maxDist;					// 0x448
	u32 recoverFlags;				// 0x44c (flags the Goomba would've used if it could recover from being spit out, always 0)
	u16 movementTimer;				// 0x450
	u16 regurgTimer;				// 0x452
	u16 changeDirTimer;				// 0x454 (only used by Goomboss Goombas, would've also been used by regular Goombas if they could recover)
	u16 stuckInSpotTimer;			// 0x456
	u16 noChargeTimer;				// 0x458
	s16 targetDir;					// 0x45a
	s16 targetDir2;					// 0x45c
	u16 unk45e;						// 0x45e (unused)
	u32 type;						// 0x460
	u8 spawnStar;					// 0x464 (0: no star, 1: silver star, 2: VS mode star)
	s8 starID;						// 0x465 (it is signed)
	u8 starID_VS;					// 0x466
	u8 regurgBounceCount;			// 0x467
	u8 flags468;					// 0x468
	u8 unk469;						// 0x469 (unused)
	u16 unk46a;						// 0x46a (unused)
	u32 hitFlags;					// 0x46c
	u32 unk470;						// 0x470 (unused)
	u8 goombaID;					// 0x474 (only used by Goomboss Goombas, set by Goomboss)
	u8 followGoombossTimer;			// 0x475 (when the timer hits 0, the Goomba will stop going after / looking for the player and will try to go back to following Goomboss)
	u16 unk476;						// 0x476 (unused)
	
	void State0();											// 0x0212b2dc, walking, running...
	void State0_NormalGoomba();								// 0x0212abd4
	void State0_GoombossGoomba();							// 0x0212af74
	void State1();											// 0x0212ab48, just hit player
	void State2();											// 0x0212aab0, jumping
	void State3();											// 0x0212a774, bouncing after being spit out
	void State4();											// 0x0212a6f8
	void UpdateMaxDist();									// 0x021290d4
	void TrackVsStarIfNecessary();							// 0x02129864
	void Kill();											// 0x02129498
	void SpawnStarIfNecessary();							// 0x021296cc
	bool UpdateIfDying();									// 0x021298d0
	void RenderRegurgGoombaHelpless(Player* player);		// 0x02129168
	void KillIfTouchedBadSurface();							// 0x021294d0
	void UpdateModelTransform();							// 0x0212a580
	bool UpdateIfEaten();									// 0x02129a00
	void PlayMovingSound();									// 0x0212934c
	void GetHurtOrHurtPlayer();								// 0x02129ed4
	void KillIfIntoxicated();								// 0x02129238
	void Jump();											// 0x02129c9c
	void UpdateTargetDirAndDist(Fix12i theMaxDist);			// 0x02129cf4 (check this)
	void SetOriginalPos(Vector3& newOriginalPos);			// 0x021296b0 (not used by the Goomba itself)
	
	//Goomba();												// 0x0212c0b0 (normal), 0x0212c054 (small), 0x0212bff8 (big)
	virtual s32 InitResources() override;					// 0x0212bc30
	virtual s32 CleanupResources() override;				// 0x0212b510
	virtual s32 Behavior() override;						// 0x0212b6ec
	virtual s32 Render() override;							// 0x0212b5bc
	virtual void OnPendingDestroy() override;				// 0x0212b5b8
	//virtual ~Goomba() override;							// 0x02129020
	//virtual ~Goomba() override;							// 0x02129070
	virtual u32 OnYoshiTryEat() override;				// 0x0212bfc0
	virtual void OnTurnIntoEgg(Player& player) override;	// 0x0212b344
	virtual Fix12i OnAimedAtWithEgg() override;				// 0x0212b30c
	virtual MaterialDef* vGetRegurgMaterialDef();			// used by ExplosionGoomba
	virtual void vSetOriginalPos(Vector3& newOriginalPos);	// used by Goomboss
	
	static GloballySharedFilePtr modelFile;				// 0x02130cf8
	static GloballySharedFilePtr animFiles[NUM_ANIMS];	// 0x02130278
	
	static SpawnInfo spawnData;					// 0x021308ec
	static SpawnInfo spawnDataSmall;			// 0x02130908
	static SpawnInfo spawnDataLarge;			// 0x02130924
};

#endif