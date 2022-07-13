#ifndef SM64DS_2_H_INCLUDED
#define SM64DS_2_H_INCLUDED

#include "SM64DS_Common.h"
#include "NDSCore.h"
#include "Actor.h"
#include "Model.h"
#include "Collision.h"
#include "Level.h"
#include "Message.h"
#include "Particle.h"
#include "Sound.h"
#include "Save.h"
#include "Input.h"
#include "Memory.h"
#include "Scene.h"
#include "OAM.h"
#include "Enums.h"

#define OBJ_TO_ACTOR_ID_TABLE ((volatile u16*)0x02004b00)
#define ACTOR_SPAWN_TABLE     ((volatile u32*)0x02006590)

struct CapIcon
{
	enum Flags
	{
		ACTIVE = 1 << 1
	};
	
	u32* vTable;  // 0x0
	Actor* actor; // 0x4
	u32 objID;    // 0x8
	u32 unk0c;    // 0xc
	u32 unk10;    // 0x10
	u32 flags;    // 0x14
	u32 unk18;    // 0x18
};

static_assert(sizeof(CapIcon) == 0x1c, "CapIcon is wrong size");

struct Enemy : public Actor
{
	enum CoinType
	{
		CN_NONE   = 0,
		CN_YELLOW = 1,
		CN_RED    = 2,
		CN_BLUE   = 3
	};
	
	enum DefeatMethod
	{
		DF_NOT        = 0,
		DF_SQUASHED   = 1,
		DF_PUNCHED    = 2,
		DF_KICKED     = 3,
		DF_BURNED     = 4,
		DF_DIVED      = 5,
		DF_UNK_6      = 6,
		DF_HIT_REGURG = 7,
		DF_GIANT_CHAR = 8 //this is definitely the end of the list.
	};
	
	enum InvCharKillFlags
	{
		IK_SPAWN_COINS = 1 << 0,
		IK_KILL        = 1 << 1
	};
	
	enum UpdateYoshiEatReturn
	{
		UY_NOT      = 0,
		UY_EATING   = 1,
		UY_IN_MOUTH = 2,
		UY_SPITTING = 3
	};
	
	Vector3 floorNormal; // 0xd4
	Vector3 wallNormal;  // 0xe0
	Vector3_16 rotation; // 0xec
	Vector3_16 unk0f2;   // 0xf2 (ceiling?)
	u32 unk0f8;          // 0xf8
	u32 unk0fc;          // 0xfc
	u16 stateTimer;      // 0x100
	u16 deathTimer;      // 0x102
	u16 spitTimer;       // 0x104
	u8 isAtCliff;        // 0x106
	bool isBeingSpit;    // 0x107
	u8 coinType;         // 0x108
	u8 unk109;           // 0x109
	u8 numCoinsMinus1;   // 0x10a
	u8 unk10b;           // 0x10b
	u32 defeatMethod;    // 0x10c
	
	Enemy();
	virtual ~Enemy();
	
	u32 UpdateKillByInvincibleChar(WithMeshClsn& wmClsn, ModelAnim& rigMdl, u32 flags); //returns 0 with 0 side effects if N/A.
	void KillByInvincibleChar(const Vector3_16& newRotation, Player& player);
	void SpawnMegaCharParticles(Actor& attacker, char* arg2);
	bool SpawnParticlesIfHitOtherObj(CylinderClsn& cylClsn); //returns whether there was a collision with an object that isn't a coin
	u32 UpdateYoshiEat(WithMeshClsn& wmClsn);
	bool AngleAwayFromWallOrCliff(WithMeshClsn& wmClsn, s16& ang); // returns whether the angle was redirected (if hitting wall, reflect angle; if at cliff, set angle to the opposite one)
	bool UpdateDeath(WithMeshClsn& wmClsn); //returns whether the object is actually dying and the death function returned true
	bool IsGoingOffCliff(WithMeshClsn& wmClsn, Fix12i arg2, s32 arg3, u32 arg4, u32 arg5, Fix12i stepToleranceY);
	void KillByAttack(Actor& other, WithMeshClsn& wmc);
	void SpawnCoin();
	void UpdateWMClsn(WithMeshClsn& wmClsn, u32 arg2);
};

static_assert(sizeof(Enemy) == 0x110, "Enemy is wrong size");

struct CapEnemy : public Enemy
{
	u8 capParam;        // 0x110
	bool hasNotSpawned; // 0x111
	s8 spawnCapFlag;    // 0x112
	s8 capID;           // 0x113
	Model capModel;     // 0x114
	CapIcon capIcon;    // 0x164
	
	CapEnemy();
	virtual ~CapEnemy();
	
	void Unk_02005d94();
	bool DestroyIfCapNotNeeded(); //returns true if the cap is needed (player is different character than cap or 0x0209f2d8 has a 0)
	s32 GetCapState(); //returns 2 if obj+0x111 = 0, else 0 if dead or capID == player character, else 1
	CapEnemy* RespawnIfHasCap(); //nullptr if failed
	bool GetCapEatenOffIt(const Vector3& offset); //returns whether there was a cap and the cap is not the original object
	Actor* ReleaseCap(const Vector3& offset); //returns the ptr to the cap if cap was released, ptr to original obj else.
	void RenderCapModel(const Vector3* scale);
	void UpdateCapPos(const Vector3& offsetPos, const Vector3_16& rot);
	Actor* AddCap(u32 capID);
	void UnloadCapModel();
};

static_assert(sizeof(CapEnemy) == 0x180, "CapEnemy is wrong size");

struct Platform : public Actor
{
	Model model;             // 0xd4
	MovingMeshCollider clsn; // 0x124
	Matrix4x3 clsnNextMat;   // 0x2ec
	u32 unk31c;              // 0x31c
	
	Platform();
	virtual ~Platform();
	virtual void Kill();
	
	void KillByMegaChar(Player& player);
	bool UpdateKillByMegaChar(s16 rotSpeedX, s16 rotSpeedY, s16 rotSpeedZ, Fix12i speed); //true if killed by mega char
	void UpdateClsnPosAndRot(); //make sure the mesh collider is at 0x124 first! Also, call this after updating the model's matrix
	void UpdateModelPosAndRotY(); //make sure the model is at 0x0d4 first!
	bool IsClsnInRange(Fix12i clsnRange, Fix12i clsnRangeOffsetY); //both in fixed-point 20.12 //side effect: enables collision if and only if in range
	bool IsClsnInRangeOnScreen(Fix12i clsnRange, Fix12i clsnRangeOffsetY); //if offsetY is 0, it is loaded from +0xb4.
};

static_assert(sizeof(MovingMeshCollider) > 0xe4);

struct CameraDef
{
	static const u32 SIZE = 0x28;
	
	s32 unk00; //something to do with going behind the player...
	s32 unk04;
	s32 camVertAngIsh;
	u32 unk0c;
	s32 vertOffset;
	s32 offsetIsh; //???
	u32 jumpWithPlayerIsh;
	s32 dist0; //???
	s32 dist1;
	u16 fovOver2;
	u16 unk26;
};


//vtable at 0x02092720
struct View : public ActorDerived		//internal name: dView; done
{
	Matrix4x3 camMat;					//View Matrix to use when rendering

	virtual s32 Render() override;		//Sets the global view matrix to camMat and calculates the global inverse view matrix
	virtual ~View();
};


//vtable at 0x0208E730
struct Clipper
{
	Vector3 unk04;
	Vector3 unk10;
	Vector3 unk1c;
	Vector3 unk28;
	u32 unk34;
	u32 unk38;
	u32 unk3c;
	u32 unk40;
	u32 unk44;
	u32 unk48;
	Fix12i aspectRatio;					//Aspect ratio
	u32 unk50;
	u32 unk54;
	u16 unk58;

	void Func_020150E8();
	void Func_02015560();
	void Func_0201559C();	//noargs
	void Func_020156DC();

	Clipper();
	virtual ~Clipper();
};




//vtable at 0x02086F84, ctor at 0x0200E444
struct Camera : public View				//internal name: dCamera
{
	static constexpr u32 cameraDefTable = 0x02086FCC;
	static constexpr u32 settingBehaviourTableBase = 0x0209B008;
	/*
	0: Default
	1: Bottom camera, close (swimming on surface)
	2: Bottom camera, far (diving)
	3: Fly (feather, cannon shoot)
	4: Top view (owl)
	6: Air-driven (wind, Balloon Mario)
	7: Climbing
	8: Fixed back sliding
	9: First person
	B: Enter cannon
	C: Cannon view
	D: Talking
	E: Door enter
	F: Painting zoom
	11: Front zoom (character introduction)
	*/
	
	enum Flags
	{
		ZOOMED_OUT         = 1 << 2,
		BOSS_TALK          = 1 << 3,
		ROTATING_LEFT      = 1 << 5,
		ROTATING_RIGHT     = 1 << 6,
		ARROWS_ALLOWED     = 1 << 12,
		TALK               = 1 << 14,
		ZOOM_OUT_FROM_TALK = 1 << 15,
		ZOOMED_IN          = 1 << 19
	};
	
	struct State // Executes view specific camera behaviour
	{
		bool (Camera::* OnUpdate)();            // Nested call by Camera::Behaviour()
		bool (Camera::* OnPlayerChangeState)(); // Nested call by Player::ChangeState()
	};
	
	Vector3 lookAt;
	Vector3 pos;            // 0x8c
	Vector3 ownerPos;       // 0x98
	Vector3 unk0a4;
	Vector3 savedLookAt;    // Saved to at talk
	Vector3 savedPos;       // Saved to at talk
	Vector3 unk0c8;         // Player's front lookAt?
	Vector3 unk0d4;         // Player's front pos?
	Vector3 unk0e0;         // Raycast result save (when the player becomes invisible to the camera)
	Vector3 unk0ec;         // Raycast result save (when the player becomes invisible to the camera)
	Fix12i aspectRatio;     // Aspect ratio, default = 1.33 (4:3)
	u32 unk0fc;        // Clipper related (near+far)
	u32 unk100;        // Clipper related
	u32 unk104;        // Clipper related
	u32 unk108;        // Clipper related
	u8 viewportLeft;   // Viewport x for left border
	u8 viewportBottom; // Viewport y for bottom border
	u8 viewportRight;  // Viewport x for right border
	u8 viewportTop;    // Viewport y for top border
	Actor* owner;           // The player stalked by the camera
	Actor* unk114;          // Set at special camera scene? Set to King Bomb-Omb for example
	Actor* unk118;          // Another unknown actor
	u32 unk11c;        // Related to unk118, set to 0xDFE60 at 0x02009F3C
	Vector3 unk120;         // unk118's or (if unk118 == 0) unk114's position vector
	Fix12i unk12c;          // Distance to unk114?
	Fix12i unk130;          // Linear camera movement interpolator (only for unk114?) that (when entering a different camera view like at the top of BoB) interpolates from 0x0 to 0x100 and backwards when leaving. As a result, it also indicates whether the owner is in a special camera scene. unk114 is linked later during interpolation.
	Fix12i unk134;          // Ground pound camera jitter offset. Starts at 0xC000 and vibrates back and forth with alternating signs until it reaches 0.
	State* currState;       // Pointer to the current setting behaviour, which in turn sets the CameraDef's
	CameraDef* defaultCamDef;
	CameraDef* currCamDef;
	LevelFile::View* currView;
	Vector3* pausePos;
	u32 unk14c;
	u32 unk150;
	u32 flags;
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;
	u32 unk168;
	u32 unk16c;
	u32 unk170;
	u32 unk174;
	u16 unk178;
	Vector3_16 angle;
	s16 eightDirAngleY;
	s16 eightDirStartAngle;
	s16 eightDirDeltaAngle;
	s16 unk186;
	u32 unk188;
	u32 unk18c;
	u32 unk190;
	u16 unk194;
	u16 unk196;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u16 unk1a4;
	u16 unk1a6;

	Camera();
	virtual ~Camera();

	virtual s32  InitResources() override;
	virtual s32  CleanupResources() override;
	virtual s32  Behavior() override;
	virtual s32  Render() override;
	virtual void OnPendingDestroy() override;

	void SaveCameraStateBeforeTalk();				//Saves the current camera state
	void SetFlag_3();
	void SetLookAt(const Vector3& lookAt);
	void SetPos(const Vector3& pos);

	//Func_0200D954
	//Func_0200D8C8
	//All funcs between Camera() and ~Camera() should belong to this object, but I couldn't prove it since they're never really called.
};

//vtable at 0x0210C2C8, ctor at 0x020FE154
struct HUD : public ActorDerived		//internal name: dMeter, ActorID = 0x14e
{
	u32 unk50;
	u32 unk54;
	u32 unk58;
	u32 unk5c;
	u32 unk60;
	u32 unk64;
	s16 meterYOffset;			//y-offset, counts downwards to 0x19, if 0x19 > yOffset or yOffset > 0x7FFF, then it is immediately set to 0x19
	u16 unk6a;				//unknown counter
	u16 unk6c;				//unknown counter
	u16 lifeXOffset;		//life counter xPos (default: 0x10)
	u16 starXOffset;		//star counter xPos (default: 0xF0)
	u8 unk72;				//unknown
	u8 meterState;			//health meter state (0-6: 0=stopAnim, 1=update, 2=locked?, 4=disappear), read and updated at 0x020FD218 before the branch table
	s8 currNumInDecimal[3];
	u8 unk77;
	u32 unk78;

	virtual s32	InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;

	HUD();
	virtual ~HUD();
};

//vtable at 0210c1c0, constructor at 020fb8bc, dtor at 0x020F975C
//Code address to init 256x256 map: 020fb568
//Code address to init 128x128 map: 020fb694
struct Minimap : public ActorDerived //ActorID = 0x14f
{
	enum ArrowType
	{
		AR_NONE = 0,
		AR_DONT_ROTATE_WITH_MINIMAP = 1,
		AR_ROTATE_WITH_MINIMAP = 2
	};
	
	u32 unk050;
	u32 unk054;
	u32 unk058;
	u32 unk05c;
	u32 unk060;
	u32 unk064;
	u32 unk068;
	u32 unk06c;
	u32 unk070;
	u32 unk074;
	u32 unk078;
	u32 unk07c;
	u32 unk080;
	u32 unk084;
	u32 unk088;
	u32 unk08c;
	u32 unk090;
	u32 unk094;
	u32 unk098;
	u32 unk09c;
	u32 unk0a0;
	u32 unk0a4;
	u32 unk0a8;
	u32 unk0ac;
	u32 unk0b0;
	u32 unk0b4;
	u32 unk0b8;
	u32 unk0bc;
	u32 unk0c0;
	u32 unk0c4;
	u32 unk0c8;
	u32 unk0cc;
	u32 unk0d0;
	u32 unk0d4;
	u32 unk0d8;
	u32 unk0dc;
	u32 unk0e0;
	u32 unk0e4;
	u32 unk0e8;
	u32 unk0ec;
	u32 unk0f0;
	u32 unk0f4;
	u32 unk0f8;
	u32 unk0fc;
	u32 unk100;
	u32 unk104;
	u32 unk108;
	u32 unk10c;
	u32 unk110;
	u32 unk114;
	u32 unk118;
	u32 unk11c;
	u32 unk120;
	u32 unk124;
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;
	u32 unk138;
	u32 unk13c;
	u32 unk140;
	u32 unk144;
	u32 unk148;
	u32 unk14c;
	u32 unk150;
	u32 unk154;
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;
	u32 unk168;
	u32 unk16c;
	u32 unk170;
	u32 unk174;
	u32 unk178;
	u32 unk17c;
	u32 unk180;
	u32 unk184;
	u32 unk188;
	u32 unk18c;
	u32 unk190;
	u32 unk194;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u32 unk1a4;
	u32 unk1a8;
	u32 unk1ac;
	u32 unk1b0;
	u32 unk1b4;
	u32 unk1b8;
	u32 unk1bc;
	u32 unk1c0;
	u32 unk1c4;
	u32 unk1c8;
	u32 unk1cc;
	u32 unk1d0;
	u32 unk1d4;
	u32 unk1d8;
	u32 unk1dc;
	u32 unk1e0;
	u32 unk1e4;
	u32 unk1e8;
	u32 unk1ec;
	u32 unk1f0;
	Vector3 center;
	Matrix2x2 arrowMat;
	u32 unk210;
	Fix12i targetInvScale;
	Fix12i invScale;
	s16 angle;
	s16 unk21e;
	u32 unk220;
	u32 unk224;
	u32 unk228;
	u32 unk22c;
	u32 unk230;
	u32 unk234;
	u32 unk238;
	u32 unk23c;
	u32 unk240;
	u32 unk244;
	u32 unk248;
	u32 unk24c;
	u8 unk250;
	u8 arrowType;
	u8 unk252;
	u8 unk253;
	u8 unk254; // some counter
	u8 unk255;
	u8 unk256;
	u8 unk257;
};

struct LaunchStar;

//allocating constructor: 020e6c0c, vtable: 0210a83c
struct Player : public Actor
{
	static constexpr u16 staticActorID = 0xbf;
	
	enum Characters
	{
		CH_MARIO,
		CH_LUIGI,
		CH_WARIO,
		CH_YOSHI
	};
	
    struct State
    {
        bool(Player::* init)();
		bool(Player::* main)();
		bool(Player::* cleanup)();
    };
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
		ST_HEADSTAND_JUMP     = 0x02110724,
		
		
		
		
		ST_LAUNCH_STAR        = 0x0211079c
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
	CylinderClsnWithPos cylClsn;
	CylinderClsnWithPos cylClsn2;
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
	u16 unk710;
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
	LaunchStar* lsPtr; //0x764
	
	static SharedFilePtr* ANIM_PTRS[0x308];

	Player();

	virtual s32  InitResources() override;
	virtual s32  CleanupResources() override;
	virtual s32  Behavior() override;
	virtual s32  Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Player() override;
	virtual u32  OnYoshiTryEat() override;

	//implemented in LaunchStar.cpp
	bool LS_Init();
	bool LS_Behavior();
	bool LS_Cleanup();
	
	void IncMegaKillCount();
	void SetNewHatCharacter(u32 character, u32 arg1, bool makeSfx);
	void SetRealCharacter(u32 character);
	void TurnOffToonShading(u32 character);
	
	bool Unk_020bea94();
	void Unk_020c6a10(u32 arg0);
	u32 GetBodyModelID(u32 character, bool checkMetalStateInsteadOfWhetherUsingModel) const;
	void SetAnim(u32 animID, s32 flags, Fix12i animSpeed, u32 startFrame);
	bool ShowMessage(ActorBase& speaker, u32 msgIndex, const Vector3& lookAt, u32 arg3, u32 arg4);
	bool StartTalk(ActorBase& speaker, bool noButtonNeeded); //true iff the talk actually started.
	s32 GetTalkState();
	bool HasFinishedTalking();
	bool IsOnShell(); //if not on shell, reset shell ptr
	void Burn();
	void Shock(u32 damage);
	void RegisterEggCoinCount(u32 numCoins, bool includeSilverStar, bool includeBlueCoin);
	//speed is multiplied by constant at 0x020ff128+charID*2 and divided by 50 (? could be 25, could be 100).
	void Hurt(const Vector3& source, u32 damage, Fix12i speed, u32 arg4, u32 presetHurt, u32 spawnOuchParticles);
	void Heal(s32 health);
	void Bounce(Fix12i bounceInitVel);
	bool ChangeState(Player::State& state);
	
	void InitWingFeathers(bool setPowerUpFlag);
	void InitBalloonMario();
	void InitVanishLuigi();
	void InitMetalWario();
	void InitFireYoshi();

	bool IsWarping() const
	{
		return reinterpret_cast<u32>(currState) == Player::ST_NO_CONTROL && stateState == 6;
	}
};

static_assert(sizeof(Player) == 0x768, "sizeof(Player) is incorrect!");

namespace Event
{
	void ClearBit(u32 bit);
	void SetBit(u32 bit);
	s32  GetBit(u32 bit);
}

enum class TTC_Speeds : s8
{
	SLOW = 0,
	FAST = 1,
	RANDOM = 2,
	STOP = 3
};

//used for keeping track of dead objects across level parts (e.g. THI big and small mountains)
struct ActorDeathTable
{
	std::byte deadObjs[64]; //technically 512 booleans
};

struct Number : public Actor
{
	static constexpr u16 staticActorID = 0x14a;
	
	Model model;
	TextureSequence textureSequence;
	u32 unkActorUniqueID;
	Vector3  spawnPos;
	Fix12i   unk148;
	u16 unk14c;
	u8  numTimesBounced;
	u8  unk14f;
};

static_assert(sizeof(Number) == 0x150, "sizeof(Number) is incorrect!");

struct PowerStar : public Enemy
{
	static constexpr u16 staticActorID = 0xb2;
	
	CylinderClsnWithPos cylClsn;
	WithMeshClsn wmClsn;
	ModelAnim modelAnim1;
	ModelAnim modelAnim2;
	ShadowModel shadowModel;
	u32 unk3fc;
	u32 unk400;
	u32 unk404;
	u32 unk408;
	u32 unk40c;
	u32 unk410;
	u32 unk414;
	u32 unk418;
	u32 unk41c;
	u32 unk420;
	u32 unk424;
	u32 unk428;
	u32 unk42c;
	u32 unk430;
	u32 unk434;
	u32 unk438;
	u32 unk43c;
	u32 unk440;
	u32 unk444;
	u32 unk448;
	u32 unk44c;
	u32 unk450;
	u32 unk454;
	u32 unk458;
	u32 unk45c;
	Vector3 unkVec460;
	Vector3 unkVec46c;
	u32 unk478;
	u32 unk47c;
	u32 unk480;
	u32 unk484;
	u32 unk488;
	u32 unk48c;
	u32 unk490;
	u16 unk494;
	s16 spawnFrameCounter;
	u32 unk498;
	u32 unk49c;
	u32 unk4a0;
	u32 unk4a4;
	u32 unk4a8;
	u32 unk4ac;
	u32 unk4b0;
	u32 unk4b4;
	u32 unk4b8;
	u32 unk4bc;
	u32 unk4c0;
};

static_assert(sizeof(PowerStar) == 0x4c4, "sizeof(PowerStar) is incorrect!");

// actor ID 0xb4
struct StarMarker : public Actor
{
	static constexpr u16 staticActorID = 0xb4;
	
	CylinderClsnWithPos cylClsn;
	Model model;
	ShadowModel shadowModel;
	u32 unk18c;
	u32 unk190;
	u32 unk194;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u32 unk1a4;
	u32 unk1a8;
	u32 unk1ac;
	u32 unk1b0;
	u32 unk1b4;
	u32 unk1b8;
	u32 unk1bc;
	u32 unk1c0;
	u32 unk1c4;
	u32 unk1c8;
	u32 unk1cc;
	u32 unk1d0;
	u32 unk1d4;
	u8  unk1d8;
	s8  starID;
	u8  unk1da;
	u8  unk1db;
};

static_assert(sizeof(StarMarker) == 0x1dc, "sizeof(StarMarker) is incorrect!");

struct ArchiveInfo
{
	char* archive;
	char* heap;
	u16 firstFileID;
	u16 firstNotFileID; //1 + lastFileID
	char* name;
	char* fileName;
};

struct Archive
{
	char magic[4];
	Archive* next;
	Archive* prev; //if this is first, it points to the ROM.
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	u32 unk28;
	u32 unk2c;
	u32 unk30;
	u32 unk34;
	u32 unk38;
	u32 unk3c; //a function
	u32 unk40; //a function
	u32 unk44; //a function
	u32 unk48;
	u32 unk4c;
	char* header;
	char* fat;
	char* fileBlock;
	u32 unk5c;
	char data[];
};

struct ROM_Info
{
	char magic[4]; //"rom\0"
	Archive* firstArchive;
};

using EnemyDeathFunc = bool(Enemy::*)(WithMeshClsn& wmClsn);

//File ID 0x8zzz is file from archive 0 with id zzz
//020189f0: overlay 0 file ID to file ID and store
//020189f8: 00 10 b0 e1: movs r0, r1 (checks if file address is nullptr)
//02018a00: 0d 01 00 1b: blne 0x02018e3c
extern "C"
{
	extern char** DL_PTR_ARR_PTR;
	
	extern s8 LEVEL_PART_TABLE[NUM_LEVELS];
	extern s8 SUBLEVEL_LEVEL_TABLE[NUM_LEVELS];
	
	extern s32 ACTOR_BANK_OVL_MAP[7][7];
	extern s32 LEVEL_OVL_MAP[NUM_LEVELS];
	
	extern MsgGenTextFunc MSG_GEN_TEXT_FUNCS[3];
	
	extern s8 ACTOR_BANK_SETTINGS[7];
	
	extern Vector3 CAM_SPACE_CAM_POS_ASR_3; //constant <0.0, 64.0, -112.0>
	
	extern ArchiveInfo ARCHIVE_INFOS[13];
	
	extern s32 NEXT_UNIQUE_ACTOR_ID;
	
	extern Matrix4x3 VIEW_MATRIX_ASR_3;
	extern Matrix4x3 INV_VIEW_MATRIX_ASR_3;
	extern Vector3_16* ROT_AT_SPAWN;
	extern Vector3* POS_AT_SPAWN;
	extern Actor::ListNode* FIRST_ACTOR_LIST_NODE;
	
	extern bool IMMUNE_TO_DAMAGE;
	
	extern TTC_Speeds TTC_CLOCK_SETTING;
	extern s8 LEVEL_ID;
	extern s8 NEXT_LEVEL_ID;
	extern s8 STAR_ID;
	extern u8 MAP_TILE_ARR_SIZE;
	extern s8 NUM_LIVES;
	extern Area* AREAS;
	extern Camera* CAMERA;
	extern Fix12i WATER_HEIGHT;
	extern s32 EVENT_FIELD;
	extern s16 NUM_COINS[2];
	extern Player* PLAYER_ARR[4];
	extern Input INPUT_ARR[4];
	extern u16 HEALTH_ARR[4];
	
	extern u8 CURRENT_GAMEMODE;			// 0 = adventure, 1 = VS, 2 = ???
	extern u8 NUM_VS_STARS_COLLECTED;	// not counting the stars that have been lost
	extern u8* VS_STAR_SPAWN_ORDER;		// points to the current order to spawn the VS stars in
	
	extern Actor* SILVER_STARS[12];	
	extern ActorDeathTable ACTOR_DEATH_TABLE_ARR[3]; //maximum three parts per level.
	
	extern ActorBase* ROOT_ACTOR_BASE;
	
	extern u16* DEATH_BY_GIANT_SPAWN_TABLE;
	
	extern ActorBase::ProcessingListNode* FIRST_BEHAVIOR_LIST_NODE;
	extern ActorBase::ProcessingListNode* FIRST_RENDER_LIST_NODE;
	extern EnemyDeathFunc ENEMY_DEATH_FUNCS[8];

	extern u8 GAME_PAUSED; // 0 = not paused, 1 = paused, 2 = unpausing

	struct
	{
		// the return value is usually 1
		s32 (*func)(Camera& cam, char* params, u16 minFrame, u16 maxFrame);
		u32 unk04;
	}
	extern KS_CAMERA_FUNCTIONS[39];
	extern u32 KS_FRAME_COUNTER;
	extern char* RUNNING_KUPPA_SCRIPT; // nullptr if no script is running

	s16 GetAngleToCamera(u32 playerID = 0);
	
	bool LoadArchive(s32 archiveID);
	
	s8 SublevelToLevel(s8 levelID);
	s32 NumStars();
	s32 IsStarCollected(s32 actID, s32 starID);
	
	s32 DeathTable_GetBit(s8 bit);
	
	s8 StarCollectedInCurrLevel(s32 starID);
	
	void UnloadBlueCoinModel();
	void LoadBlueCoinModel();
	void UnloadSilverStarAndNumber();
	void LoadSilverStarAndNumber();
	void LinkSilverStarAndStarMarker(Actor* starMarker, Actor* silverStar);
	
	s16 ReadUnalignedShort(const char* from);
	bool RunKuppaScript(char* address);
	void EndKuppaScript();
}

#endif