#pragma once

#include "Goomba.h"

struct Goomboss : Enemy
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
		ST_HIT_BY_MEGA,
		
		NUM_STATES,
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
		
		NUM_ANIMS = WAIT_NO_LOOP,
		NUM_ANIM_INFOS,
	};
	
	enum TextureAnimations
	{
		TA_ANGER_SPAWN,
		TA_DAMAGE,
		TA_UNUSED,
		TA_DOWN,
		TA_DOWN_START,
		TA_SERCH_WAIT,
		TA_DEFAULT,
		
		NUM_TEX_ANIMS,
	};
	
	MovingCylinderClsnWithPos cylClsns[4]; // 0x110, 0x150, 0x190, 0x1d0 (0: ???, 1: face 2: left foot, 3: right foot)
	ModelAnim modelAnim;                   // 0x210
	ShadowModel shadows[3];                // 0x274, 0x29c, 0x2c4
	Matrix4x3 shadowMats[3];               // 0x2ec, 0x31c, 0x34c
	Matrix4x3 cylClsnMat;                  // 0x37c
	Vector3 cylClsnPos[3];                 // 0x3ac, 0x3b8, 0x3c4 (for the last 3 cylClsns)
	MaterialChanger matChg;                // 0x3d0
	TextureSequence texSeq;                // 0x3e4
	TextureTransformer texSRT;             // 0x3f8
	WithMeshClsn wmClsn;                   // 0x40c
	Player* listener;                      // 0x5c8
	u32 state;                             // 0x5cc
	Vector3 originalPos;                   // 0x5d0
	u32 megaMushroomID;                    // 0x5dc
	// u32 unk5e0;                         // 0x5e0 (unused)
	Fix12i currentScale;                   // 0x5e4
	Fix12i goombaTargetSpeed;              // 0x5e8
	Fix12i nextScale;                      // 0x5ec
	s32 direction;                         // 0x5f0 (-1 or 1)
	
	// walkSpeed gets added to the walkAngle every frame, walkSpeed is a value between 0 and maxWalkSpeed (inclusive)
	s16 walkAngle;                         // 0x5f4
	s16 walkSpeed;                         // 0x5f6
	s16 maxWalkSpeed;                      // 0x5f8
	
	s16 scaleAng;                          // 0x5fa
	u16 stateTimer;                        // 0x5fc
	bool leftFootSteppedOnGround;          // 0x5fe
	bool rightFootSteppedOnGround;         // 0x5ff
	bool leftFootCurrentlyOnGround;        // 0x600
	bool rightFootCurrentlyOnGround;       // 0x601
	u8 numGoombasAlive;                    // 0x602
	u8 stateState;                         // 0x603
	u8 health;                             // 0x604
	u8 hurtTimer;                          // 0x605
	u8 unk606;                             // 0x606 (unused)
	u8 timesToGrow;                        // 0x607
	bool shadowInvisible;                  // 0x608
	bool shouldBehave;                     // 0x609 (only used by Explosion Goombas)
	bool shouldRender;                     // 0x60a
	bool allExplosionGoombasSpawned;       // 0x60b
	bool musicLoaded;                      // 0x60c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr texSeqFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	static GloballySharedFilePtr goombaModelFile;
	static GloballySharedFilePtr goombaAnimFiles[Goomba::NUM_ANIMS];
	
	Goomboss();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Goomboss() override;
	virtual void vGetGoombaSpawnPos(Vector3& goombaPos, s32 numerator);
	
	void UpdateCylClsnMat();
	void UpdateModelTransform();
	void UpdateAnims();
	void CallState();
	void GetHurtOrHurtPlayer();
	void UpdateCylinderCollisions();
	void DropShadow();
	bool IsCurrentAnim(s32 animID);
	Fix12i GetAnimSpeed();
	void ChangeState(u32 newState);
	void SetAnim(s32 animID);
	void SpawnParticles(Player& player, CylinderClsn& cylClsn, bool spawnStarParticles);
	void TurnIfNotFacingPlayer();
	bool HasFinishedTurning(); // false if not turning
	bool ShouldSpawnOrWait(); // if not, sets anim to WALK_START, unless the player is behind Goomboss, in which case calls UpdatePosAndAngle()
	void GetGoombaSpawnPos(Vector3& goombaPos, s32 goombaID);
	void SetMaxWalkSpeed();
	void UpdatePosAndAngle();
	bool AdvanceMaterialChanger();
	bool GrowBigger(); // returns whether he finished growing
	void SetExplosionGoombasShouldRender(bool newShouldRender);
	void SetExplosionGoombaSpeeds();
	void SetBossCamera();
	bool SpawnExplosionGoomba();
	void GetCylClsnPos(Vector3& cylClsnPos, s32 transformIndex);
	
	void State0_Talk_Init();
	void State0_Talk_Main();
	void State1_StopTalk_Init();
	void State1_StopTalk_Main();
	void State2_Spawn_Init();
	void State2_Spawn_Main();
	void State3_Walk_Init();
	void State3_Walk_Main();
	void State4_Wait_Init();
	void State4_Wait_Main();
	void State5_Hurt_Init();
	void State5_Hurt_Main();
	void State6_Grow_Init();
	void State6_Grow_Main();
	void State7_Defeat_Init();
	void State7_Defeat_Main();
	void State8_HitByMega_Init();
	void State8_HitByMega_Main();
};

struct GoombossAnim
{
	SharedFilePtr& animFile;
	BTA_File& texAnim;
	s32 animFlags;
};