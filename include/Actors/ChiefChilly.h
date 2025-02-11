#pragma once

struct ChiefChilly : Enemy
{
	struct State
	{
		using StateFunc = void(ChiefChilly::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	static constexpr s32 NUM_FEET = 2;
	
	enum Animations
	{
		DEAD,
		HIT,
		WALK,
		DAMAGE,
		JUMP_ED,
		JUMP_ST,
		WAIT,
		
		NUM_ANIMS,
	};
	
	MovingCylinderClsnWithPos cylClsn; // 0x110
	WithMeshClsn wmClsn;               // 0x150
	BlendModelAnim modelAnim;          // 0x30c
	State* state;                      // 0x37c
	ShadowModel shadow;                // 0x380
	Matrix4x3 shadowMat;               // 0x3a8
	Vector3 originalPos;               // 0x3d8
	Player* listener;                  // 0x3e4
	Vector3 bigIcePos[8];              // 0x3e8
	Vector3 smallIcePos[8];            // 0x448
	Vector3 wobblePos;                 // 0x4a8
	union                              // 0x4b4
	{
		u16 jumpWaitTimer;   // in ST_JUMP
		bool justSlowedDown; // in ST_CHASE_PLAYER
		s16 wobbleAng;       // in ST_WOBBLE_AT_CLIFF
		bool startedFalling; // in ST_FIRST_BOUNCE
	};
	u32 bounceCount;                   // 0x4b8
	u32 earthquakeFoot;                // 0x4bc
	u32 coinCount;                     // 0x4c0 (only increases if Wario is unlocked, spawns Mega Mushroom when at 30, then resets to 0)
	s8 targetIceID;                    // 0x4c4
	s8 currentIceID;                   // 0x4c5
	s16 targetAngY;                    // 0x4c6
	u8 stateState;                     // 0x4c8
	bool isGoingOffCliff;              // 0x4c9
	bool jumpFromWobble;               // 0x4ca
	u8 health;                         // 0x4cb
	u16 clsnTimer;                     // 0x4cc
	union                              // 0x4d0
	{
		Fix12i horzSpeedDecay; // in ST_CHASE_PLAYER
		s32 wobbleDir;         // in ST_WOBBLE_AT_CLIFF
	};
	Vector3 prevFootPos[NUM_FEET];     // 0x4d4
	Vector3 noCliffPos;                // 0x4ec
	u32 smokeParticleID;               // 0x4f8
	u32 meltParticleID;                // 0x4fc
	u32 soundID;                       // 0x500
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static State ST_BOUNCE;
	static State ST_INTRO_TALK_START;
	static State ST_JUMP;
	static State ST_INTRO_TALK;
	static State ST_CHASE_PLAYER;
	static State ST_MELT;
	static State ST_END_JUMP;
	static State ST_TURN_AT_CLIFF;
	static State ST_HURT;
	static State ST_DEFEAT;
	static State ST_FALL;
	static State ST_WOBBLE_AT_CLIFF;
	static State ST_DEFEAT_TALK_START;
	static State ST_FALL_DEATH;
	static State ST_FIRST_BOUNCE;
	static State ST_DEFEAT_TALK;
	
	ChiefChilly();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ChiefChilly() override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void ChangeState(State* newState);
	void CallState();
	void UpdateModelTransform();
	void DropShadow();
	bool GetHurtOrHurtPlayer();
	void SpawnHitParticles(Actor& other); // other is always *this
	void LandingEarthquake(Fix12i magnitude);
	void SpawnMeltingParticles();
	
	void St_Bounce_Init();
	void St_Bounce_Main();
	void St_IntroTalkStart_Init();
	void St_IntroTalkStart_Main();
	void St_Jump_Init();
	void St_Jump_Main();
	void St_IntroTalk_Init();
	void St_IntroTalk_Main();
	void St_ChasePlayer_Init();
	void St_ChasePlayer_Main();
	void St_Melt_Init();
	void St_Melt_Main();
	void St_EndJump_Init();
	void St_EndJump_Main();
	void St_TurnAtCliff_Init();
	void St_TurnAtCliff_Main();
	void St_Hurt_Init();
	void St_Hurt_Main();
	void St_Defeat_Init();
	void St_Defeat_Main();
	void St_Fall_Init();
	void St_Fall_Main();
	void St_WobbleAtCliff_Init();
	void St_WobbleAtCliff_Main();
	void St_DefeatTalkStart_Init();
	void St_DefeatTalkStart_Main();
	void St_FallDeath_Init();
	void St_FallDeath_Main();
	void St_FirstBounce_Init();
	void St_FirstBounce_Main();
	void St_DefeatTalk_Init();
	void St_DefeatTalk_Main();
};

static_assert(sizeof(ChiefChilly) == 0x504);