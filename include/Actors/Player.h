#pragma once

struct Player : Actor
{
	enum Characters : u8
	{
		CH_MARIO,
		CH_LUIGI,
		CH_WARIO,
		CH_YOSHI,
		
		NUM_CHARACTERS,
	};
	
	enum Animations : u32
	{
		ANIM_ED_KISS_WAIT,
		ANIM_ED_KISS_TO_POSE,
		ANIM_L_ED_AMAZED = ANIM_ED_KISS_TO_POSE,
		ANIM_W_ED_AMAZED_WAIR = ANIM_ED_KISS_TO_POSE,
		ANIM_Y_ED_SHY_WAIT = ANIM_ED_KISS_TO_POSE,
		ANIM_E_DOWN,
		ANIM_SHF_DIE,
		ANIM_S_DIE,
		ANIM_GAS_WAIT,
		ANIM_GAS_DIE,
		ANIM_FALL_DIE,
		ANIM_LIE_END,
		ANIM_LIE_WAIT,
		ANIM_SLEEP_TO_LIE,
		ANIM_SLEEP_END,
		ANIM_SLEEP_WAIT,
		ANIM_SLEEP_START,
		ANIM_DAMAGE_START,
		ANIM_DAMAGE_WAIT,
		ANIM_RETURN_DOWN,
		ANIM_E_SHOCK, // start of arc0.narc
		ANIM_SDOWN,
		ANIM_BKDWN,
		ANIM_SHFDN,
		ANIM_JFDWN,
		ANIM_FIREJMP,
		ANIM_FJPEND,
		ANIM_CARRY_LOST,
		ANIM_STAR_GET,
		ANIM_BROAD_JUMP,
		ANIM_BROAD_JUMP_END,
		ANIM_HANDSTAND_JUMP,
		ANIM_HANDSTAND_WAIT,
		ANIM_HANDSTAND_START,
		ANIM_HANDSTAND_END,
		ANIM_HANG_JUMP_UP,
		ANIM_HANG_WAIT,
		ANIM_HANG_START,
		ANIM_HANG_UP,
		ANIM_TREE_CLIMB,
		ANIM_TREE_POSE,
		ANIM_TREE_WAIT,
		ANIM_TREE_START,
		ANIM_WJMP,
		ANIM_WSLD,
		ANIM_BACK_JUMP,
		ANIM_BACK_JUMP_END,
		ANIM_SQUAT_WAIT,
		ANIM_SQUAT_START,
		ANIM_SQUAT_END,
		ANIM_CARRY_START,
		ANIM_CARRY_THROW,
		ANIM_CARRY_POSE,
		ANIM_CARRY_WALK,
		ANIM_CARRY_WAIT,
		ANIM_RIDE,
		ANIM_RIDE_START,
		ANIM_BRAKE,
		ANIM_BREND,
		ANIM_ATTACK_1,
		ANIM_ATTACK_2,
		ANIM_ATTACK_3,
		ANIM_HIPSR,
		ANIM_HIPAT,
		ANIM_HIPED,
		ANIM_LOST,
		ANIM_RUN,
		ANIM_SLDCT,
		ANIM_SLIP,
		ANIM_SLIPED,
		ANIM_SLPBK,
		ANIM_SLPLA,
		ANIM_TRNED,
		ANIM_TURN,
		ANIM_WAIT,
		ANIM_WALK,
		ANIM_FLY_POSE,
		ANIM_JUMP_TO_FLY,
		ANIM_ROLL_JUMP,
		ANIM_ROLL_JUMP_END,
		ANIM_TJMP1,
		ANIM_TJMP2,
		ANIM_2JMP1,
		ANIM_2JMP2,
		ANIM_2JMPED,
		ANIM_JMPED,
		ANIM_JUMP,
		ANIM_LAND,
		ANIM_LAEND,
		ANIM_ROLL,
		ANIM_MONKEY_WAIT_L,
		ANIM_MONKEY_WAIT_R,
		ANIM_MONKEY_L_TO_R,
		ANIM_MONKEY_R_TO_L,
		ANIM_MONKEY_START,
		ANIM_WALL_WALK_L,
		ANIM_WALL_WALK_R,
		ANIM_WALL_WAIT,
		ANIM_SPIN_JUMP,
		ANIM_SPIN_JUMP_END,
		ANIM_SOFT_STEP,
		ANIM_CRAWL_END,
		ANIM_CRAWL,
		ANIM_CRAWL_START,
		ANIM_PUSH,
		ANIM_SLIDING_KICK_END,
		ANIM_SLIDING_KICK,
		ANIM_ROLL_KICK,
		ANIM_SFBDN,
		ANIM_SFFDN,
		ANIM_PUTON_CAP,
		ANIM_Y_EAT,
		ANIM_W_GSWING_START = ANIM_Y_EAT,
		ANIM_Y_EAT_OUT,
		ANIM_W_GSWING_POSE = ANIM_Y_EAT_OUT,
		ANIM_Y_EAT_FAIL,
		ANIM_W_GSWING_THROW = ANIM_Y_EAT_FAIL,
		ANIM_Y_EAT_SUCCESS,
		ANIM_W_GSWING_END = ANIM_Y_EAT_SUCCESS,
		ANIM_Y_LAY_EGG,
		ANIM_STRUGGLE, // end of arc0.narc
		ANIM_SHOOT_TO_FLY,
		ANIM_SHOOT,
		ANIM_SDROP_LEG,
		ANIM_SDROP_LEG_WAIT,
		ANIM_SDROP_LEG_END,
		ANIM_SDROP_HIP_END,
		ANIM_SDROP_HIP,
		ANIM_SDROP_HIP_WAIT,
		ANIM_SDROP_HEAD_END,
		ANIM_SDROP_HEAD_WAIT,
		ANIM_SDROP_HEAD,
		ANIM_SDROP_WAIT,
		ANIM_SDROP_WALK,
		ANIM_P_KOOPA_THROW,
		ANIM_P_KOOPA_H_WAIT,
		ANIM_P_KOOPA_HOLD,
		ANIM_FALL_SAND,
		ANIM_SWIM_DIE,
		ANIM_DROWN_DIE,
		ANIM_RETURN_STAR,
		ANIM_N_CARRY_START,
		ANIM_N_CARRY_WAIT,
		ANIM_N_CARRY_WALK,
		ANIM_N_CARRY_POSE,
		ANIM_N_CARRY_PUT,
		ANIM_N_CARRY_LOST,
		ANIM_DOOR_PUSH,
		ANIM_DOOR_PULL,
		ANIM_H_CARRY_START,
		ANIM_H_CARRY_WALK,
		ANIM_H_CARRY_WAIT,
		ANIM_H_CARRY_THROW,
		ANIM_STAR_OPEN,
		ANIM_KEY_OPEN,
		ANIM_KEY_GET,
		ANIM_COLD_WAIT_START,
		ANIM_COLD_WAIT,
		ANIM_COLD_WAIT_END,
		ANIM_PUTON_T_CAP,
		ANIM_FIRST_CHANGE,
		ANIM_SCALE_UP,
		ANIM_SU_JUMP_END,
		ANIM_SU_JUMP,
		ANIM_SU_WALK_END,
		ANIM_SU_WALK,
		ANIM_SU_WALK_START,
		ANIM_SU_WAIT,
		ANIM_SU_HIPED,
		ANIM_SU_HIPAT,
		ANIM_SU_HIPSR,
		ANIM_SU_RUN,
		ANIM_RETURN_NOCAP,
		ANIM_SWIM,
		ANIM_SWIM_IN,
		ANIM_SWIM_WAIT,
		ANIM_PADDLE_1,
		ANIM_PADDLE_2,
		ANIM_PADDLE_END,
		ANIM_SWIM_STAR_GET,
		ANIM_SWIM_DAMAGE,
		ANIM_SWIM_ATTACK,
		ANIM_SWIM_CARRY,
		ANIM_PADDLE_CARRY,
		ANIM_SWIM_THROW,
		ANIM_OP_GO,
		ANIM_L_OP_NOD = ANIM_OP_GO,
		ANIM_W_OP_NOD = ANIM_OP_GO,
		ANIM_Y_OP_LIE_TO_SIT = ANIM_OP_GO,
		ANIM_OP_WAIT,
		ANIM_Y_OP_SIT_TO_STAND = ANIM_OP_WAIT,
		ANIM_Y_OP_SIT_WAIT,
		ANIM_L_OP_TURN = ANIM_Y_OP_SIT_WAIT,
		ANIM_W_OP_TURN = ANIM_Y_OP_SIT_WAIT,
		ANIM_Y_OP_STAND_WAIT,
		ANIM_L_OP_LOOK_WARIO = ANIM_Y_OP_STAND_WAIT,
		ANIM_L_OP_LOOK_LUIGI = ANIM_Y_OP_STAND_WAIT,
		ANIM_W_OP_POINT,
		ANIM_ED_WAIT,
		ANIM_ED_LOOK,
		ANIM_ED_LOOK_WAIT,
		ANIM_ED_LOOK_END,
		ANIM_ED_NOD,
		ANIM_ED_PUTUP_WAIT,
		ANIM_ED_LOOKUP_WAIT = ANIM_ED_PUTUP_WAIT,
		ANIM_ED_CAP_OFF,
		ANIM_ED_CAP_OFF_WAIT,
		ANIM_Y_ED_SHY_TO_WAIT = ANIM_ED_CAP_OFF_WAIT,
		ANIM_ED_WAVE,
		ANIM_ED_FLY_START,
		ANIM_Y_ED_LOOK_CAM = ANIM_ED_FLY_START,
		ANIM_ED_FLY,
		ANIM_Y_ED_TURN = ANIM_ED_FLY,
		
		NUM_ANIMS,
	};
	
	enum TalkStates
	{
		TK_NOT     = -1,
		TK_START   =  0,
		TK_TALKING =  1, // +0x6e3 == anything but 3, 5, or 7
		TK_UNK2    =  2, // +0x6e3 == 3
		TK_UNK3    =  3  // +0x6e3 == 5 or 7
	};
	
	enum HurtStates
	{
		HT_NOT     = -1,
		HT_START   =  0,
		HT_TALKING =  1,
		HT_UNK2    =  2,
		HT_UNK3    =  3,
		HT_UNK4    =  4,
		HT_UNK5    =  5,
		HT_UNK6    =  6,
		HT_UNK7    =  7,
	};
	
	enum Flags2
	{
		
		
		F2_CAMERA_ZOOM_IN     = 1 << 2,
		F2_TELEPORT           = 1 << 3,
		
		
		
		F2_RESET_POSITION     = 1 << 7,
		
		
		F2_EXIT_LEVEL_IF_DEAD = 1 << 10,
		F2_NO_CONTROL         = 1 << 11,
		F2_START_FLOWER_POWER = 1 << 12
	};
	
    struct State
    {
        bool(Player::* init)();
		bool(Player::* main)();
		bool(Player::* cleanup)();
    };
	
	u32 unk0d4;
	u32 unk0d8;
	ModelAnim2* bodyModels[5]; // the fifth one is the Metal Wario model, 0xdc, 0xe0, 0xe4, 0xe8, 0xec
	ModelAnim balloonModel;
	Model* headModels[4];      // Yoshi's is a ModelAnim
	Model* headNoCapModels[4]; // Yoshi's is the mouth-is-full model
	ModelAnim wings;           // 0x174
	u32 unk1d8;
	TextureSequence texSeq1dc;
	TextureSequence texSeq1f0;
	TextureSequence texSeq204;
	TextureSequence texSeq218;
	MaterialChanger matChg22c;
	MaterialChanger matChg240;
	TextureSequence texSeq254;
	TextureSequence texSeq268;
	char* unk27c[4];
	char* unk28c[4];
	char* unk29c[4];
	ShadowModel shadow;
	MovingCylinderClsnWithPos cylClsn;
	MovingCylinderClsnWithPos cylClsn2;
	Actor* shellPtr;
	Actor* actorInHands;
	u32 unk35c;
	Actor* actorInMouth;
	u32 unk364;
	ActorBase* speaker;
	u32 unk36c;
	State* currState;
	State* prevState;
	State* nextState;
	u32 unk37c;
	WithMeshClsn wmClsn;
	Vector3 unk53c;
	Vector3 unk540; // mirrors the player's position?
	u32 unk554;
	u32 unk558;
	u32 unk55c;
	u32 unk560;
	u32 unk564;
	u32 unk568;
	u32 unk56c;
	u32 unk570;
	u32 unk574;
	char* unk578;
	char* unk57c;
	u32 unk580;
	u32 unk584;
	char* unk588;
	u32 unk58c;
	u32 unk590;
	u32 unk594;
	u32 unk598;
	u32 unk59c;
	u32 unk5a0;
	u32 unk5a4;
	u32 unk5a8;
	u32 unk5ac;
	u32 unk5b0;
	u32 unk5b4;
	u32 unk5b8;
	Matrix4x3 unkMat5bc;
	Matrix4x3 unkMat5ec;
	u32 unk61c;
	u32 unk620;
	u32 unk624;
	u32 unk628;
	u32 unk62c;
	u32 unk630;
	u32 unk634;
	u32 unk638;
	u32 animID;
	Fix12i unk640;
	Fix12i floorY;
	u32 unk648;
	u32 unk64c;
	u32 unk650;
	u32 unk654;
	u32 floorTracID;
	u32 floorCamBehavID;
	u32 floorViewID;
	u32 floorBehavID;
	u32 unk668;
	u32 floorTexID;
	u32 floorWindID;
	u32 unk674;
	u32 unk678;
	u32 unk67c;
	u32 unk680;
	Fix12i jumpPeakHeight; // 0x684
	s32 msgID;
	Fix12i unk68c;
	Fix12i unk690;
	Fix12i unk694;
	u32 unk698;
	u32 unk69c;
	u16 visibilityCounter; // the player is visible when this is even (except when the player is electrocuted the second bit is checked instead)
	u16 unk6a2;
	union
	{
		u16 sleepTimer;
		u16 runChargeTimer;
	};
	u16 unk6a6;
	u16 unk6a8;
	u16 unk6aa;
	u16 unk6ac;
	u16 featherCapTimeRemaining; // 0x6AE
	u32 unk6b0;
	u32 unk6b4;
	u32 unk6b8;
	u16 unk6bc;
	u16 powerupTimer;
	u16 balloonTimer;
	u16 unk6c2;
	u32 unk6c4;
	u16 unk6c8;
	u16 unk6ca;
	u16 unk6cc;
	u16 flags2; // 0x6ce && 0x6cf
	u16 megaDestroyCounter;
	s16 inputAngle;
	u32 unk6d4;
	u8 playerID; // always 0 in single player mode
	u8 unk6d9;
	u8 unk6da;
	u8 renderedChar;
	u8 prevHatChar; // 0x6DC
	u8 currHatChar; // 0x6DD
	bool isInAir;
	u8 unk6df;
	u8 unk6e0;
	u8 currJumpNumber; // 0x6E1: 0 - first, 1 - second, 2 - triple jump, more?
	u8 unk6e2;
	u8 stateState; // 0x6E3: the current state of the current state. How meta.
	u8 unk6e4;
	u8 canFlutterJump;
	u8 unk6e6;
	u8 unk6e7;
	u8 unk6e8;
	u8 currClsnState; // 0x06E9: 0 - not colliding, 1 - standing on ground, 2 - colliding with wall in water, 3 - colliding with wall on land 
	u16 unk6ea;
	u32 unk6ec;
	u32 unk6f0;
	bool hasFireInMouth;
	bool opacity;
	u8 unk6f6;
	u8 unk6f7;
	bool isFireYoshi;       // 0x6f8
	bool isMetalWario;      // 0x6f9
	bool usesMetalModel;    // 0x6fa
	bool isVanishLuigi;     // 0x6fb
	bool usesVanishTexture; // 0x6fc
	bool isBalloonMario;    // 0x6fd
	bool usesBalloonModel;  // 0x6fe
	bool isWingMario;       // 0x6ff
	bool usesWingModel;     // 0x700
	u8 unk701;
	u8 unk702;
	bool isMega;
	u8 unk704;
	u8 unk705;
	bool isUnderwater;
	u8 unk707;
	u8 unk708;
	u8 unk709;
	u8 noControlState; // 0x70a
	u8 unk70b;
	u8 unk70c;
	u8 unk70d;
	u16 unk70e;
	u8 unk710;
	u8 unk711;
	u8 isInAirIsh; // 0x712
	bool isTangible;
	u8 unk714;
	u8 unk715;
	u8 isTangibleToMesh;
	u8 unk717;
	s16 unk718;
	u8 unk71a;
	u8 unk71b;
	u8 unk71c;
	u8 unk71d;
	s8 unk71e;
	u8 unk71f;
	u32 unk720;
	u32 unk724;
	u32 unk728;
	u32 unk72c;
	u32 unk730;
	u32 unk734;
	u32 unk738;
	u16 toonStateAndFlag; //8 possible states, 0x8000 is the invincible-and-can't-collect-caps flag (0x02191174)
	u16 unk73e;
	Fix12i toonIntensity;
	Vector3 unk744;
	u32 unk750;
	u32 unk754;
	u32 unk758;
	u16 unk75c;
	s16 spineAngleOffsY; // is added to bodyModels[GetBodyModelID(param1 & 0xff, false)]->data.bones[8].rot.y
	s16 spineAngleOffsZ; // is added to bodyModels[GetBodyModelID(param1 & 0xff, false)]->data.bones[8].rot.z
	u16 unk762;
	u32 unk764; // 0x764
	
	static SharedFilePtr* ANIM_PTRS[NUM_ANIMS * NUM_CHARACTERS];
	
	// 0x0211073c is the start of some function pointer table
	
	static State ST_LEDGE_HANG;
	static State ST_LEDGE_GRAB;
	static State ST_CEILING_GRATE;
	static State ST_YOSHI_POWER; // tongue, spitting, throwing egg, breathing fire
	static State ST_SWALLOW;
	static State ST_IN_YOSHI_MOUTH;
	static State ST_SMALL_LAUNCH_UP; // never set? (1 call)
	static State ST_HURT;
	static State ST_HURT_WATER;
	static State ST_ELECTROCUTE;
	static State ST_BURN_FIRE;
	static State ST_BURN_LAVA;
	static State ST_DEAD_HIT;
	static State ST_DEAD_PIT;
	static State ST_WALK;
	static State ST_WAIT;
	static State ST_GRABBED;
	static State ST_TURN_AROUND;
	static State ST_JUMP;
	static State ST_FALL;
	static State ST_THROWN;
	static State ST_SIDE_FLIP;
	static State ST_SLIDE_KICK_RECOVER;
	static State ST_FLY;
	static State ST_NO_CONTROL; // includes caps
	static State ST_OWL;
	static State ST_DEBUG_FLY;
	static State ST_WIND_CARRY;
	static State ST_BALLOON;
	static State ST_TELEPORT;
	static State ST_TORNADO_SPIN;
	static State ST_CANNON;
	static State ST_SQUISH;
	static State ST_SHELL;
	static State ST_STOMACH_SLIDE;
	static State ST_BUTT_SLIDE;
	static State ST_DIZZY_STARS;
	static State ST_HOLD_LIGHT;
	static State ST_BONK;
	static State ST_HOLD_HEAVY;
	static State ST_WALL_SLIDE;
	static State ST_BOWSER_EARTHQUAKE;
	static State ST_WALL_JUMP;
	static State ST_SLOPE_JUMP;
	static State ST_STUCK_IN_GROUND;
	static State ST_LAND;
	static State ST_ON_WALL;
	static State ST_SPIN;
	static State ST_TALK;
	static State ST_CRAZED_CRATE;
	static State ST_WAIT_QUICKSAND;
	static State ST_LEVEL_ENTER;
	static State ST_JUMP_QUICKSAND;
	static State ST_CROUCH;
	static State ST_RESPAWN;
	static State ST_CRAWL;
	static State ST_BACK_FLIP;
	static State ST_OPENING_WAKE_UP;
	static State ST_LONG_JUMP;
	static State ST_PUNCH_KICK;
	static State ST_ENDING_FLY;
	static State ST_GROUND_POUND;
	static State ST_DIVE;
	static State ST_THROW;
	static State ST_GRAB_BOWSER_TAIL;
	static State ST_SWING_PLAYER;
	static State ST_SWEEP_KICK;
	static State ST_SLIDE_KICK;
	static State ST_CAMERA_ZOOM;
	static State ST_NULL; // all its functions are "return 1;"
	static State ST_SWIM;
	static State ST_WATER_JUMP;
	static State ST_METAL_WATER_GROUND;
	static State ST_METAL_WATER_WATER;
	static State ST_CLIMB;
	static State ST_HEADSTAND;
	static State ST_POLE_JUMP;
	static State ST_HEADSTAND_JUMP;
	
	Player();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Player() override;
	virtual u32  OnYoshiTryEat() override;
	
	void IncMegaKillCount();
	void SetNewHatCharacter(u32 character, u32 arg1, bool makeSfx);
	void SetRealCharacter(u32 character);
	void TurnOffToonShading(u32 character);
	
	bool IsState(State& state);
	bool IsDiving();
	bool IsInsideOfCannon();
	bool IsCollectingCap();
	bool HasNoCap();
	void Unk_020c6a10(u32 arg0);
	bool Unk_020c4f40(u16 newUnk6a6);
	s32 Unk_020ca8f8();
	bool Unk_020c9e5c(u8 arg0);
	bool Unk_020ca488(); // calls Unk_020c9e5c(0xb);
	bool Unk_020ca150(u8 arg0);
	u32 GetBodyModelID(u32 character, bool checkMetalStateInsteadOfMetalModel) const;
	void SetAnim(u32 animID, s32 flags, Fix12i animSpeed, u32 startFrame);
	bool ShowMessage(ActorBase& speaker, u32 msgIndex, const Vector3* lookAt, u32 arg3, u32 arg4);
	bool ShowMessage2(ActorBase& speaker, u32 msgIndex, const Vector3* lookAt, u32 arg3, u32 arg4);
	bool StartTalk(ActorBase& speaker, bool noButtonNeeded); //true if the talk actually started.
	s32 GetTalkState();
	bool HasFinishedTalking();
	s32 GetHurtState();
	bool IsOnShell(); // if not on shell, reset shell ptr
	bool IsEnteringLevel(); // entering entrance, not entering exit
	bool IsBeingShotOutOfCannon();
	bool CanPause();
	void Burn();
	void Shock(u32 damage);
	void RegisterEggCoinCount(u32 numCoins, bool includeSilverStar, bool includeBlueCoin);
	void Hurt(const Vector3& source, u32 damage, Fix12i speed, u32 arg4, u32 presetHurt, u32 spawnOuchParticles); // speed is multiplied by constant at 0x020ff128+charID*2 and divided by 50 (? could be 25, could be 100).
	void Heal(s32 health);
	s32 GetHealth();
	void Bounce(Fix12i bounceInitVel);
	void SpinBounce(Fix12i bounceInitVel);
	bool ChangeState(Player::State& state);
	bool JumpIntoBooCage(Vector3& cagePos);
	bool EnterWhirlpool();
	void BlowAway(s16 dir);
	bool IsInAir();
	bool CanWarp();
	bool IsStateEnteringLevel();
	bool SetNoControlState(u8 arg0, s32 messageID, u8 arg2);
	bool TryTalkToKeyDoor();
	bool TryTalkToDoor(u8 arg0);
	void OpenBigDoor();
	bool CanEnterDoor(u8 newStateState);
	bool TryExitWhiteDoorWithStar();
	bool TryExitCharacterDoorWithIntro();
	bool IsOpeningDoorWithStar();
	bool TryEnterStarDoor(Vector3& doorPos, s16 doorAng);
	void PlayMammaMiaSound();
	bool TryGrab(Actor& actor);
	bool DropActor();
	bool FinishedAnim();
	
	bool IsAnim(u32 animID);
	bool IsFrontSliding();
	bool LostGrabbedObject();
	
	void InitWingFeathers(bool setPowerUpFlag);
	void InitBalloonMario();
	void InitVanishLuigi();
	void InitMetalWario();
	void InitFireYoshi();
	
	s32 St_LedgeHang_Init();
	s32 St_LedgeHang_Main();
	s32 St_LedgeHang_Cleanup();
	s32 St_LedgeGrab_Init();
	s32 St_LedgeGrab_Main();
	s32 St_CeilingGrate_Init();
	s32 St_CeilingGrate_Main();
	s32 St_YoshiPower_Init();
	s32 St_YoshiPower_Main();
	s32 St_YoshiPower_Cleanup();
	s32 St_Swallow_Init();
	s32 St_Swallow_Main();
	s32 St_InYoshiMouth_Init();
	s32 St_InYoshiMouth_Main();
	s32 St_InYoshiMouth_Cleanup();
	s32 St_SmallLaunchUp_Init();
	s32 St_SmallLaunchUp_Main();
	s32 St_Hurt_Init();
	s32 St_Hurt_Main();
	s32 St_Hurt_Cleanup();
	s32 St_HurtWater_Init();
	s32 St_HurtWater_Main();
	s32 St_Electrocute_Init();
	s32 St_Electrocute_Main();
	s32 St_BurnFire_Init();
	s32 St_BurnFire_Main();
	s32 St_BurnLava_Init();
	s32 St_BurnLava_Main();
	s32 St_DeadHit_Init();
	s32 St_DeadHit_Main();
	s32 St_DeadPit_Init();
	s32 St_DeadPit_Main();
	s32 St_Walk_Init();
	s32 St_Walk_Main();
	s32 St_Wait_Init();
	s32 St_Wait_Main();
	s32 St_Wait_Cleanup();
	s32 St_Grabbed_Init();
	s32 St_Grabbed_Main();
	s32 St_Grabbed_Cleanup();
	s32 St_TurnAround_Init();
	s32 St_TurnAround_Main();
	s32 St_Jump_Init();
	s32 St_Jump_Main();
	s32 St_Fall_Init();
	s32 St_Fall_Main();
	s32 St_Thrown_Init();
	s32 St_Thrown_Main();
	s32 St_Thrown_Cleanup();
	s32 St_SideFlip_Init();
	s32 St_SideFlip_Main();
	s32 St_SlideKickRecover_Init();
	s32 St_SlideKickRecover_Main();
	s32 St_Fly_Init();
	s32 St_Fly_Main();
	s32 St_NoControl_Init();
	s32 St_NoControl_Main();
	s32 St_NoControl_Cleanup();
	s32 St_Owl_Init();
	s32 St_Owl_Main();
	s32 St_Owl_Cleanup();
	s32 St_DebugFly_Init();
	s32 St_DebugFly_Main();
	s32 St_WindCarry_Init();
	s32 St_WindCarry_Main();
	s32 St_Balloon_Init();
	s32 St_Balloon_Main();
	s32 St_Balloon_Cleanup();
	s32 St_Teleport_Init();
	s32 St_Teleport_Main();
	s32 St_TornadoSpin_Init();
	s32 St_TornadoSpin_Main();
	s32 St_Cannon_Init();
	s32 St_Cannon_Main();
	s32 St_Cannon_Cleanup();
	s32 St_Squish_Init();
	s32 St_Squish_Main();
	s32 St_Squish_Cleanup();
	s32 St_Shell_Init();
	s32 St_Shell_Main();
	s32 St_Shell_Cleanup();
	s32 St_StomachSlide_Init();
	s32 St_StomachSlide_Main();
	s32 St_ButtSlide_Init();
	s32 St_ButtSlide_Main();
	s32 St_DizzyStars_Init();
	s32 St_DizzyStars_Main();
	s32 St_DizzyStars_Cleanup();
	s32 St_HoldLight_Init();
	s32 St_HoldLight_Main();
	s32 St_HoldLight_Cleanup();
	s32 St_Bonk_Init();
	s32 St_Bonk_Main();
	s32 St_HoldHeavy_Init();
	s32 St_HoldHeavy_Main();
	s32 St_WallSlide_Init();
	s32 St_WallSlide_Main();
	s32 St_BowserEarthquake_Init();
	s32 St_BowserEarthquake_Main();
	s32 St_WallJump_Init();
	s32 St_WallJump_Main();
	s32 St_SlopeJump_Init();
	s32 St_SlopeJump_Main();
	s32 St_StuckInGround_Init();
	s32 St_StuckInGround_Main();
	s32 St_Land_Init();
	s32 St_Land_Main();
	s32 St_OnWall_Init();
	s32 St_OnWall_Main();
	s32 St_Spin_Init();
	s32 St_Spin_Main();
	s32 St_Spin_Cleanup();
	s32 St_Talk_Init();
	s32 St_Talk_Main();
	s32 St_Talk_Cleanup();
	s32 St_CrazedCrate_Init();
	s32 St_CrazedCrate_Main();
	s32 St_CrazedCrate_Cleanup();
	s32 St_WaitQuicksand_Init();
	s32 St_WaitQuicksand_Main();
	s32 St_LevelEnter_Init();
	s32 St_LevelEnter_Main();
	s32 St_LevelEnter_Cleanup();
	s32 St_JumpQuicksand_Init();
	s32 St_JumpQuicksand_Main();
	s32 St_Crouch_Init();
	s32 St_Crouch_Main();
	s32 St_Respawn_Init();
	s32 St_Respawn_Main();
	s32 St_Crawl_Init();
	s32 St_Crawl_Main();
	s32 St_BackFlip_Init();
	s32 St_BackFlip_Main();
	s32 St_OpeningWakeUp_Init();
	s32 St_OpeningWakeUp_Main();
	s32 St_LongJump_Init();
	s32 St_LongJump_Main();
	s32 St_PunchKick_Init();
	s32 St_PunchKick_Main();
	s32 St_EndingFly_Init();
	s32 St_EndingFly_Main();
	s32 St_GroundPound_Init();
	s32 St_GroundPound_Main();
	s32 St_GroundPound_Cleanup();
	s32 St_Dive_Init();
	s32 St_Dive_Main();
	s32 St_Throw_Init();
	s32 St_Throw_Main();
	s32 St_GrabBowserTail_Init();
	s32 St_GrabBowserTail_Main();
	s32 St_GrabBowserTail_Cleanup();
	s32 St_SwingPlayer_Init();
	s32 St_SwingPlayer_Main();
	s32 St_SwingPlayer_Cleanup();
	s32 St_SweepKick_Init();
	s32 St_SweepKick_Main();
	s32 St_SlideKick_Init();
	s32 St_SlideKick_Main();
	s32 St_CameraZoom_Init();
	s32 St_CameraZoom_Main();
	s32 St_CameraZoom_Cleanup();
	s32 St_Null_Init();
	s32 St_Null_Main();
	s32 St_Null_Cleanup();
	s32 St_Swim_Init();
	s32 St_Swim_Main();
	s32 St_Swim_Cleanup();
	s32 St_WaterJump_Init();
	s32 St_WaterJump_Main();
	s32 St_MetalWaterGround_Init();
	s32 St_MetalWaterGround_Main();
	s32 St_MetalWaterGround_Cleanup();
	s32 St_MetalWaterWater_Init();
	s32 St_MetalWaterWater_Main();
	s32 St_MetalWaterWater_Cleanup();
	s32 St_Climb_Init();
	s32 St_Climb_Main();
	s32 St_Climb_Cleanup();
	s32 St_Headstand_Init();
	s32 St_Headstand_Main();
	s32 St_Headstand_Cleanup();
	s32 St_PoleJump_Init();
	s32 St_PoleJump_Main();
	s32 St_HeadstandJump_Init();
	s32 St_HeadstandJump_Main();
	
	[[gnu::always_inline]]
	bool IsWarping() const
	{
		return currState == &Player::ST_NO_CONTROL && stateState == 6;
	}
};

static_assert(sizeof(Player) == 0x768, "sizeof(Player) is incorrect!");
static_assert(Player::NUM_ANIMS == 194, "Player::NUM_ANIMS is incorrect!");
static_assert(Player::NUM_CHARACTERS == 4, "Player::NUM_CHARACTERS is incorrect!");