#pragma once

struct Player : Actor
{
	enum Characters
	{
		CH_MARIO,
		CH_LUIGI,
		CH_WARIO,
		CH_YOSHI,
		
		NUM_CHARACTERS,
	};
	
	// this should NOT be an enum
    enum States
    {
		ST_LEDGE_GRAB         = 0x02110004,
		ST_CEILING_GRATE      = 0x0211001c,
		ST_YOSHI_POWER        = 0x02110034, //tongue, spitting, throwing egg, breathing fire
        ST_SWALLOW            = 0x0211004c,
		
		
		ST_HURT               = 0x02110094,
        ST_HURT_WATER         = 0x021100ac,
		ST_ELECTROCUTE        = 0x021100c4,
		ST_BURN_FIRE          = 0x021100dc,
		ST_BURN_LAVA          = 0x021100f4,
		ST_DEAD_HIT           = 0x0211010c,
		ST_DEAD_PIT           = 0x02110124,
        ST_WALK               = 0x0211013c,
        ST_WAIT               = 0x02110154,
		ST_GRABBED            = 0x0211016c,
		ST_TURN_AROUND        = 0x02110184,
		ST_JUMP               = 0x0211019c,
        ST_FALL               = 0x021101b4,
		ST_THROWN             = 0x021101cc,
		ST_SIDE_FLIP          = 0x021101e4,
		ST_SLIDE_KICK_RECOVER = 0x021101fc,
		ST_FLY                = 0x02110214,
		ST_NO_CONTROL         = 0x0211022c, //includes caps
		ST_OWL                = 0x02110244,
		
		ST_WIND_CARRY         = 0x02110274,
		ST_BALLOON            = 0x0211028c,
		ST_TELEPORT           = 0x021102a4,
		
		ST_CANNON             = 0x021102d4,
		ST_SQUISH             = 0x021102ec,
		ST_SHELL              = 0x02110304,
		ST_STOMACH_SLIDE      = 0x0211031c,
		ST_BUTT_SLIDE         = 0x02110334,
		ST_DIZZY_STARS        = 0x0211034c,
		ST_HOLD_LIGHT         = 0x02110364,
		ST_BONK               = 0x0211037c,
		ST_HOLD_HEAVY         = 0x02110394,
		ST_WALL_SLIDE         = 0x021103ac,
		
		ST_WALL_JUMP          = 0x021103dc,
		ST_SLOPE_JUMP         = 0x021103f4,
		ST_STUCK_IN_GROUND    = 0x0211040c,
        ST_LAND               = 0x02110424,
		ST_ON_WALL            = 0x0211043c,
		ST_SPIN               = 0x02110454,
		ST_TALK		          = 0x0211046c,
		ST_CRAZED_CRATE       = 0x02110484,
		
		ST_LEVEL_ENTER        = 0x021104b4,
		
		ST_CROUCH             = 0x021104e4,
		
		ST_CRAWL              = 0x02110514,
		ST_BACK_FLIP          = 0x0211052c,
		
		ST_LONG_JUMP          = 0x0211055c,
		ST_PUNCH_KICK         = 0x02110574,
		
		ST_GROUND_POUND       = 0x021105a4,
		ST_DIVE               = 0x021105bc,
		ST_THROW              = 0x021105d4,
		
		
		
		ST_SLIDE_KICK         = 0x02110634,
		
		
        ST_SWIM               = 0x0211067c,
		ST_WATER_JUMP         = 0x02110694,
		ST_METAL_WATER_GROUND = 0x021106ac,
		ST_METAL_WATER_WATER  = 0x021106c4,
		ST_CLIMB              = 0x021106dc,
		ST_HEADSTAND          = 0x021106f4,
		ST_POLE_JUMP          = 0x0211070c,
		ST_HEADSTAND_JUMP     = 0x02110724
    };
	
	enum TalkStates
	{
		TK_NOT     = -1,
		TK_START   =  0,
		TK_TALKING =  1, //+0x6e3 == anything but 3, 5, or 7
		TK_UNK2    =  2, //+0x6e3 == 3
		TK_UNK3    =  3  //+0x6e3 == 5 or 7
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
	ModelAnim2* bodyModels[5]; //the fifth one is the Metal Wario model, 0xdc, 0xe0, 0xe4, 0xe8, 0xec
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
	Vector3 unk540; //mirrors the player's position?
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
	u32 msgID;
	u32 unk68c;
	u32 unk690;
	u32 unk694;
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
	u32 unk6c8;
	u16 unk6cc;
	u16 flags2; //0x6ce && 0x6cf
	u16 megaDestroyCounter;
	s16 inputAngle;
	u32 unk6d4;
	u8 playerID; //always 0 in single player mode
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
	u16 unk70a;
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
	u32 unk764; //0x764
	
	static SharedFilePtr* ANIM_PTRS[0x308];
	
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
	bool IsInsideOfCannon();
	bool IsCollectingCap();
	void Unk_020c6a10(u32 arg0);
	bool Unk_020c4f40(u16 newUnk6a6);
	u32 GetBodyModelID(u32 character, bool checkMetalStateInsteadOfWhetherUsingModel) const;
	void SetAnim(u32 animID, s32 flags, Fix12i animSpeed, u32 startFrame);
	bool ShowMessage(ActorBase& speaker, u32 msgIndex, const Vector3& lookAt, u32 arg3, u32 arg4);
	bool StartTalk(ActorBase& speaker, bool noButtonNeeded); //true iff the talk actually started.
	s32 GetTalkState();
	bool HasFinishedTalking();
	bool IsOnShell(); //if not on shell, reset shell ptr
	bool IsEnteringLevel(); // entering entrance, not entering exit
	bool IsBeingShotOutOfCannon();
	void Burn();
	void Shock(u32 damage);
	void RegisterEggCoinCount(u32 numCoins, bool includeSilverStar, bool includeBlueCoin);
	//speed is multiplied by constant at 0x020ff128+charID*2 and divided by 50 (? could be 25, could be 100).
	void Hurt(const Vector3& source, u32 damage, Fix12i speed, u32 arg4, u32 presetHurt, u32 spawnOuchParticles);
	void Heal(s32 health);
	void Bounce(Fix12i bounceInitVel);
	bool ChangeState(Player::State& state);
	bool JumpIntoBooCage(Vector3& cagePos);
	bool EnterWhirlpool();
	void BlowAway(s16 dir);
	
	void InitWingFeathers(bool setPowerUpFlag);
	void InitBalloonMario();
	void InitVanishLuigi();
	void InitMetalWario();
	void InitFireYoshi();
	
	[[gnu::always_inline]]
	bool IsWarping() const
	{
		return (u32)currState == Player::ST_NO_CONTROL && stateState == 6;
	}
};

static_assert(sizeof(Player) == 0x768, "sizeof(Player) is incorrect!");