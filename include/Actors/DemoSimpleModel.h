#pragma once

struct UnkModel : Model // 0x60
{
	Vector3 unk50;
	SharedFilePtr* modelFile;
	
	virtual ~UnkModel() override;
	
	bool SetFiles(SharedFilePtr* modelF, s32 polygonID);
};

struct AnimInfo // 0x4
{
	u8 animID;   // 0x0
	s8 texSeqID; // 0x1
	bool loop;   // 0x2
	s8 nextID;   // 0x3
};

struct UnkModelAnim : ModelAnim // 0x84
{
	Vector3 unk64;              // 0x64
	SharedFilePtr* modelFile;   // 0x70
	SharedFilePtr* animFiles;   // 0x74
	SharedFilePtr* texSeqFiles; // 0x78
	TextureSequence* texSeq;    // 0x7c
	u8 numAnims;                // 0x80
	u8 numTexSeqs;              // 0x81
	u8 animInfoID;              // 0x82
	u8 unk83;                   // 0x83
	
	virtual ~UnkModelAnim() override;
	
	// animF and texSeqF used to be SharedFilePtr**
	bool SetFiles(SharedFilePtr* modelF, u8 numAnim, SharedFilePtr* animF, u8 newUnk83, u8 numTexSeq, SharedFilePtr* texSeqF, s32 polygonID);
	
	void UpdateTexSeq();
	void AdvanceTexSeq();
	
	void AdvanceAnim(AnimInfo* animInfos); // if anim finished, sets the next anim (& texSeq)
	void SetNextAnims(AnimInfo* animInfos, u8 nextAnimInfoID);
};

struct IntroCloudManager
{
	constexpr s32 NUM_BORDERS = 2;    // one for the top, one for the bottom
	constexpr s32 NUM_BIG_CLOUDS = 2; // do not change this, it's baked into the BG layers
	constexpr s32 NUM_CLOUDS = 3;
	
	enum States
	{
		ST_SPAWN_BORDER               = 0,
		ST_SET_02111144               = 1,
		ST_MOVE_BG_SCROLL_BG_FADE_MAP = 2,
		ST_SCROLL_BG_FADE_MAP         = 3,
		ST_SCROLL_BG                  = 4,
			ST_STOP_SPAWNING_CLOUDS   = 5, // all states under this don't spawn new clouds, existing ones keep moving
		ST_MOVE_BG_UNDO_MAP_FADE      = 5,
		ST_END                        = 6,
	};
	
	s16 bgOffsetX[NUM_BIG_CLOUDS]; // 0x00, 0x02
	s16 bgOffsetY[NUM_BIG_CLOUDS]; // 0x04, 0x06
	s16 borderY[NUM_BORDERS];      // 0x08, 0x0a
	s16 x[NUM_CLOUDS];             // 0x0c, 0x0e, 0x10
	s16 y[NUM_CLOUDS];             // 0x14, 0x16, 0x18
	s16 direction[NUM_CLOUDS];     // 0x1c, 0x1e, 0x20 (-1 or 1)
	s16 respawnTimer[NUM_CLOUDS];  // 0x24, 0x26, 0x28
	u16 mapFadeTimer;              // 0x2c (counts up)
	u16 mapFadeOpacity;            // 0x2e
	bool alive[NUM_CLOUDS];        // 0x30, 0x31, 0x32
	u8 state;                      // 0x33
	
	// padding:
	// u16 unk12;
	// u16 unk1a;
	// u16 unk22;
	// u16 unk2a;
	
	void Behavior(u8 unk100);
	
	void MoveBigClouds();
	void FadeInMinimap();
	void RenderBorder();
	void SpawnClouds();
	void RenderClouds();
};

struct EndingManager
{
	struct Star // 0x4c
	{
		Vector2 pos;   // 0x00, 0x04
		Vector2 speed; // 0x08, 0x0c
		Fix12i unk10;  // 0x10
		u32 unk14;     // 0x14 (unused)
		u32 unk18;     // 0x18 (unused)
		Fix12i unk1c;  // 0x1c
		Fix12i unk20;  // 0x20
		u32 unk24;     // 0x24
		u32 unk28;     // 0x28
		u16 unk2c;     // 0x2c
		u16 unk2e:     // 0x2e
		u16 unk30;     // 0x30
		u16 unk32;     // 0x32
		u16 unk34;     // 0x34 (used in 0)
		u16 unk36;     // 0x36
		u16 unk38;     // 0x38
		u16 unk3a;     // 0x3a
		u16 unk3c;     // 0x3c
		u16 unk3e;     // 0x3e (used in 0)
		u16 unk42;     // 0x42
		bool exists;   // 0x44
		u8 unk45;      // 0x45
		u8 state;      // 0x46
		u8 stateState; // 0x47
		u8 unk48;      // 0x48
		u8 unk49;      // 0x49
		u8 unk4a;      // 0x4a
	};
	
	struct Cake // 0x30
	{
		Fix12i unk130;        // 0x130
		Fix12i unk134;        // 0x134
		
		Fix12i unk140;        // 0x140
		Fix12i unk144;        // 0x144
		Fix12i unk148;        // 0x148
		Fix12i unk14c;        // 0x14c
		u32 unk150;           // 0x150
		u32 unk154;           // 0x154
		u16 unk158;           // 0x158
		// 0x15a
		
		u8 unk15c;            // 0x15c
		u8 state;             // 0x15d
		u8 stateState;        // 0x15e
		// 0x15f
	};
	
	struct Figure // 0x14
	{
		enum FigureType
		{
			0 = YOSHI,
			1 = YOSHI_COLOR,
			2 = MARIO,
			3 = MARIO_COLOR,
			4 = WARIO,
			5 = WARIO_COLOR,
			6 = LUIGI,
			7 = LUIGI_COLOR,
			8 = PEACH,
			9 = PEACH_COLOR,
		};
		
		Vector2 pos;   // 0x160, 0x164
		// 0x168
		
		u8 unk170;     // 0x170
		bool visible;  // 0x171
		u8 figureType; // 0x172
		u8 unk173;     // 0x173
	};
	
	struct TextFader // 0x8
	{
		u16 unk1c4;          // 0x1c4
		u16 unk1c6;          // 0x1c6
		u8 unk1c8;           // 0x1c8
		u8 unk1c9;           // 0x1c9
		u8 unk1ca;           // 0x1ca
		u8 creditsMessageID; // 0x1cb
	};
	
	struct StarParticle // 0xc
	{
		s16 x;
		s16 y;
		s16 unk04;
		u8 unk06;
		u8 unk07;
		u32 unk08;
	};
	
	struct UnkCallback : Particle::SimpleCallback
	{
		StarParticle stars[0x40]; // 0x208
		u32 unk508;               // 0x508 (unk28 of star that spawned particle)
		u16 unk50c;               // 0x50c (unk2c of star that spawned particle)
		
		UnkCallback();
		virtual void SpawnParticles(Particle::System&) override;
		virtual bool OnUpdate(Particle::System&, bool active) override;
	};
	
	Star stars[4];        // 0x00, 0x4c, 0x98, 0xe4
	Cake cake;            // 0x130 (array of size 1)
	Figure figures[5];    // 0x160, 0x174, 0x188, 0x19c, 0x1b0
	TextFader textFader;  // 0x1c4
	Vector2 theEndPos;    // 0x1cc, 0x1d0
	
	u8 unk1d8;            // 0x1d8
	u8 renderTheEnd;      // 0x1d9
	
	u32 unk1e4;           // 0x1e4
	u16 unk1e8;           // 0x1e8
	u16 unk1ea;           // 0x1ea
	u8 unk1ec;            // 0x1ec
	u8 unk1ed;            // 0x1ed
	
	u32 unk1f0;           // 0x1f0
	u32 unk1f4;           // 0x1f4
	u32 particleStarID;   // 0x1f8 (starID of the star that will spawn particles this frame)
	u32 particleUniqueID; // 0x1fc
	UnkCallback unkCallback; // 0x200
	
	u32* unk510;          // 0x510
	bool starsOnlyRotate; // 0x514
	
	EndingManager();
	
	s32 NumCharactersUnlocked();
	
	void Cleanup();
	void Behavior();
	void Render();
	
	void UpdateStars();
	void UpdateStarFade(s32 starID);
	void SpawnStarParticles(s32 x, s32 y, u32 param_4, u16 param_5);
	
	void StarState0(s32 starID);
	void StarState1(s32 starID);
	void StarState2(s32 starID);
	
	void StarState1_0(s32 starID);
	void StarState1_1(s32 starID);
	void StarState1_2(s32 starID);
	
	void StarState2_0(s32 starID);
	void StarState2_1(s32 starID);
	void StarState2_2(s32 starID);
	void StarState2_3(s32 starID);
	void StarState2_4(s32 starID);
	void StarState2_5(s32 starID);
	void StarState2_6(s32 starID);
	void StarState2_7(s32 starID);
	void StarState2_8(s32 starID);
	
	void UpdateCakePicture();
	void MoveCakeFigures(Fix12i subX, Fix12i subY); // called in CakeState2_1
	
	void CakeState0(s32 zero);
	void CakeState1(s32 zero);
	void CakeState2(s32 zero);
	
	void CakeState1_0(s32 zero);
	void CakeState1_1(s32 zero);
	void CakeState1_2(s32 zero);
	
	void CakeState2_0(s32 zero);
	void CakeState2_1(s32 zero);
	
	void UpdateTextFader();
	
	void TextFaderState0(s32 zero);
	void TextFaderState1(s32 zero);
	void TextFaderState2(s32 zero);
	void TextFaderState3(s32 zero);
	void TextFaderState4(s32 zero);
	void TextFaderState5(s32 zero);
	
	void SpawnStarParticlesAtCenter();
	void StopSpawningStarParticlesAtCenter();
	
	void RenderStarParticles();
	void RenderStars();
	void RenderFigures();
	void RenderTheEnd();
	
	// LoadFiles calls Init, Init calls the rest and StopSpawningStarParticlesAtCenter
	void LoadFiles();
	void Init();
	void InitStars();
	void InitCake();
	void InitFigures();
	void InitTextFader();
	void InitTheEnd();
};

struct DemoSimpleModel : Actor // 0x104
{
	enum Objects
	{
		CAMERA_LAKITU   = 0x12,
		PEACH           = 0x13,
		PIPE_START      = 0x14,
			PIPE_MARIO  = 0x14,
			PIPE_LUIGI  = 0x15,
			PIPE_WARIO  = 0x16,
		PIPE_END        = 0x16,
		PEACH_LETTER    = 0x17,
		STAR            = 0x18,
		INTRO_CLOUDS    = 0x19,
		BIRD_START      = 0x1a,
			BIRD_0      = 0x1a,
			BIRD_1      = 0x1b,
			BIRD_2      = 0x1c,
			BIRD_3      = 0x1d,
			BIRD_4      = 0x1e,
			BIRD_5      = 0x1f,
			BIRD_6      = 0x20,
			BIRD_7      = 0x21,
			BIRD_8      = 0x22,
			BIRD_9      = 0x23,
			BIRD_10     = 0x24,
			BIRD_11     = 0x25,
			BIRD_12     = 0x26,
			BIRD_13     = 0x27,
			BIRD_14     = 0x28,
			BIRD_15     = 0x29,
			BIRD_16     = 0x2a,
			BIRD_17     = 0x2b,
			BIRD_18     = 0x2c,
			BIRD_19     = 0x2d,
		BIRD_END        = 0x2d,
		ENDING_MANAGER  = 0x2e,
		MINIMAP_CLOUDS  = 0x2f,
	};
	
	enum PeachAnimations
	{
		ENTER_WAIT,
		LANDING,
		WAIT,
		LOOK_ABOUT,
		NOTICE_MARIO,
		NOTICE_YOSHI,
		LOOKUP,
		LOOKUP_TO_WAIT,
		STEP_UP,
		KISS,
		TURN,
		WALK,
		WAVE,
	};
	
	IntroCloudManager* cloudManager;
	EndingManager* endingManager;
	UnkModel* model;
	UnkModelAnim* modelAnim;
	u32 unke4;
	u32 unke8;
	u32 unkec;
	u32 unkf0;
	Fix12i unkf4;
	Fix12i unkf8;
	u16 unkfc;
	u16 unkfe;
	union // 0x100
	{
		u8 cutsceneID;    // the current part cutscene (used during intro cutscene, during the level overviews of the ending cutscene)
		u8 instructionID; // of last executed ending instruction (used during start and end of ending cutscene)
	};
	u8 unk101;
	u8 opacity;
	u8 unk103; // |= 1 in behavior (flags?)
	
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	
	s32 IntroCloudsCleanupResources();
	s32 IntroCloudsBehavior();
	
	s32 EndingManagerCleanupResources();
	s32 EndingManagerBehavior();
	
	void CallObjectFunction(char* params, s16 minFrame, s16 maxFrame);
	
	s32 MoveLakituIntro(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 RotateLakituIntro(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 MoveLakituEnding(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 MovePeachIntro(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 UpdatePeachLetter(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 MoveWarpPipe(char* funcParams, s16 minFrame, s16 maxFrame);
	s32 UpdateBigStar(char* funcParams, s16 minFrame, s16 maxFrame);
};