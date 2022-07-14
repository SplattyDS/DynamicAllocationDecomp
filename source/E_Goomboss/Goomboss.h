#ifndef GOOMBOSS_INCLUDED
#define GOOMBOSS_INCLUDED

#include "../SM64DS_2.h"
#include "../GloballySharedFilePtr.h"
#include "../E_Goomba/Goomba.h"

// vtable at 0x02122eb8, size is 0x610, actor ids are 0xc6 and 0xc7
struct Goomboss : public Enemy
{
	enum States
	{
		ST_TALK,
		ST_STOP_TALK,
		ST_SPAWN,
		ST_WALK,
		ST_WAIT,
		ST_HURT,
		ST_GROW,
		ST_DEFEAT,
		ST_HIT_BY_MEGA
	};
	
	enum Animations
	{
		ANGER,
		DAMAGE_BACK,
		DAMAGE_FRONT,
		DOWN_START,
		DOWN,
		SERCH_WAIT,
		TURN,
		WAIT,
		WALK,
		WALK_END,
		WALK_START,
		SPAWN,
		WAIT_NO_LOOP,
		
		NUM_ANIMS = WAIT_NO_LOOP
	};
	
	CylinderClsnWithPos cylClsns[4];	// 0x110, 0x150, 0x190, 0x1d0 (0: ???, 1: face 2: left foot, 3: right foot)
	ModelAnim modelAnim;				// 0x210
	ShadowModel shadows[3];				// 0x274, 0x29c, 0x2c4
	Matrix4x3 shadowMats[3];			// 0x2ec, 0x31c, 0x34c
	Matrix4x3 cylClsnPosMulMat;			// 0x37c
	Vector3 cylClsnPos[3];				// 0x3ac, 0x3b8, 0x3c4 (for the last 3 cylClsns)
	MaterialChanger matChg;				// 0x3d0
	TextureSequence texSeq;				// 0x3e4
	TextureTransformer texSRT;			// 0x3f8
	WithMeshClsn wmClsn;				// 0x40c
	Player* listener;					// 0x5c8
	u32 state;							// 0x5cc
	Vector3 originalPos;				// 0x5d0
	u32 megaMushroomID;					// 0x5dc
	u32 unk5e0;							// 0x5e0 (unused)
	Fix12i currentScale;				// 0x5e4
	Fix12i goombaTargetSpeed;			// 0x5e8
	Fix12i nextScale;					// 0x5ec
	s32 direction;						// 0x5f0 (-1 or 1)
	
	// walkSpeed gets added to the walkAngle every frame, walkSpeed is a value between 0 and maxWalkSpeed (inclusive)
	s16 walkAngle;						// 0x5f4
	s16 walkSpeed;						// 0x5f6
	s16 maxWalkSpeed;					// 0x5f8
	
	s16 scaleAng;						// 0x5fa
	u16 stateTimer;						// 0x5fc
	bool leftFootSteppedOnGround;		// 0x5fe
	bool rightFootSteppedOnGround;		// 0x5ff
	bool leftFootCurrentlyOnGround;		// 0x600
	bool rightFootCurrentlyOnGround;	// 0x601
	u8 numGoombasAlive;					// 0x602
	u8 stateState;						// 0x603
	u8 health;							// 0x604
	u8 hurtTimer;						// 0x605
	u8 unk606;							// 0x606 (unused)
	u8 timesToGrow;						// 0x607
	bool shadowInvisible;				// 0x608
	bool shouldBehave;					// 0x609 (only used by Explosion Goombas)
	bool shouldRender;					// 0x60a
	bool allExplosionGoombasSpawned;	// 0x60b
	bool musicLoaded;					// 0x60c
	
	void UpdateCylClsnPosMultMat();				// 0x02121300
	void UpdateModelTransform();				// 0x0212195c
	void UpdateAnims();							// 0x0212199c (updates the modelAnim and texSRT)
	void CallState();							// 0x0212042c
	void GetHurtOrHurtPlayer();					// 0x02120d74
	void UpdateCylinderCollisions();			// 0x02121380
	void DropShadow();							// 0x02121800
	bool IsCurrentAnim(s32 animID);				// 0x02121a20
	Fix12i GetAnimSpeed();						// 0x02120b24
	void ChangeState(u32 newState);				// 0x021203e4
	void SetAnim(s32 animID);					// 0x02121a4c
	void SpawnParticles(Player& player, CylinderClsn& cylClsn, bool spawnStarParticles); // 0x02120bb8
	void TurnIfNotFacingPlayer();				// 0x02120808
	bool HasFinishedTurning();					// 0x021207b8 (false if not turning)
	bool ShouldSpawnOrWait();					// 0x021206c8 (if not, sets anim to WALK_START, unless the player is behind Goomboss, in which case calls UpdatePosAndAngle())
	void GetGoombaSpawnPos(Vector3& goombaPos, s32 goombaID); // 0x0212087c
	void SetMaxWalkSpeed();						// 0x02120b90
	void UpdatePosAndAngle();					// 0x021216f4
	bool AdvanceMaterialChanger();				// 0x02120474 (returns whether matChg has reached its max frame)
	bool GrowBigger();							// 0x021204c0 (returns whether he finished growing)
	void SetExplosionGoombasShouldRender(bool newShouldRender); // 0x0211f344
	void SetExplosionGoombaSpeeds();			// 0x0211f244
	void SetBossCamera();						// 0x0211f154
	bool SpawnExplosionGoomba();				// 0x0211f38c
	void GetCylClsnPos(Vector3& cylClsnPos, s32 transformIndex); // 0x02121270
	
	void State0_Talk_Init();					// 0x021203e0 (empty)
	void State0_Talk_Main();					// 0x021201f0
	void State1_StopTalk_Init();				// 0x021201ec (empty)
	void State1_StopTalk_Main();				// 0x0212018c
	void State2_Spawn_Init();					// 0x0211ffac
	void State2_Spawn_Main();					// 0x0211fd74
	void State3_Walk_Init();					// 0x0212016c
	void State3_Walk_Main();					// 0x02120080
	void State4_Wait_Init();					// 0x0212007c (empty)
	void State4_Wait_Main();					// 0x0211ffcc
	void State5_Hurt_Init();					// 0x0211fd48
	void State5_Hurt_Main();					// 0x0211fc38
	void State6_Grow_Init();					// 0x0211fb84
	void State6_Grow_Main();					// 0x0211fa74
	void State7_Defeat_Init();					// 0x0211fa08
	void State7_Defeat_Main();					// 0x0211f5b8
	void State8_HitByMega_Init();				// 0x0211fc34 (empty)
	void State8_HitByMega_Main();				// 0x0211fbd0
	
	//Goomboss();								// 0x02122838
	//Goomboss();								// 0x02122764 (for the Explosion Goombas)
	virtual s32 InitResources() override;		// 0x02121e98
	virtual s32 CleanupResources() override;	// 0x02121abc
	virtual s32 Behavior() override;			// 0x02121bf0
	virtual s32 Render() override;				// 0x02121b70
	//virtual ~Goomboss() override;				// 0x0211f000
	//virtual ~Goomboss() override;				// 0x0211f0a0
	virtual void vGetGoombaSpawnPos(Vector3& goombaPos, s32 numerator);
	
	static GloballySharedFilePtr modelFile;				// 0x02123000
	static GloballySharedFilePtr texSeqFile;			// 0x02123040
	static GloballySharedFilePtr animFiles[NUM_ANIMS];	// 0x02122948
	
	static GloballySharedFilePtr goombaModelFile;
	static GloballySharedFilePtr goombaAnimFiles[Goomba::NUM_ANIMS];
	
	static SpawnInfo spawnData;					// 0x02122e78
};

struct GoombossAnim
{
	GloballySharedFilePtr& animFile;
	TexSRTDef& texAnim;
	s32 animFlags;
};

/* anim file id order:
0x38f	ANGER
0x391	DAMAGE_BACK
0x392	DAMAGE_FRONT
0x394	DOWN_START
0x393	DOWN
0x396	SERCH_WAIT
0x398	TURN
0x399	WAIT
0x39a	WALK
0x39b	WALK_START
0x39c	WALK_END
0x397	SPAWN
*/

#endif