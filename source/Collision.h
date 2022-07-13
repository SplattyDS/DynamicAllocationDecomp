#ifndef SM64DS_CLSN_INCLUDED
#define SM64DS_CLSN_INCLUDED

#include "SM64DS_Common.h"
#include <array>

struct MovingCylinderClsn;
struct BgCh;
struct WithMeshClsn;
struct RaycastGround;
struct RaycastLine;
struct SphereClsn;
struct MeshColliderBase;
struct ClsnResult;

extern std::array<MeshColliderBase*, 0x18> ACTIVE_MESH_CLSNS;

struct CLPS
{
	enum _TextureID
	{
		TX_NORMAL              = 0x0,
		TX_PATH                = 0x1,
		TX_GRASS               = 0x2,
		TX_PUDDLE              = 0x3,
		TX_ROCK                = 0x4,
		TX_WOOD                = 0x5,
		TX_SNOW                = 0x6,
		TX_ICE                 = 0x7,
		TX_SAND                = 0x8,
		TX_FLOWERS             = 0x9,
		TX_MERRY_GO_ROUND_ROCK = 0xa,
		TX_MERRY_GO_ROUND_WOOD = 0xb,
		TX_GRATE               = 0xc,
		TX_SILENT_0            = 0xd,
		TX_SILENT_1            = 0xe,
		TX_SILENT_2            = 0xf
	};
		
	enum _TractionID
	{
		TR_NORMAL                  = 0x0,
		TR_UNSLIPPABLE             = 0x1,
		TR_UNSLIPPABLE_2           = 0x2,
		TR_SLIPPERY_SLOPE          = 0x3,
		TR_SLIPPERY                = 0x4,
		TR_SLIP_NO_WALL_JUMP_ABOVE = 0x5, // Prevents wall jumps when it's the players floorTracID
		TR_NO_CRAWL_SLOPES         = 0x6,
		TR_NO_CRAWL_SLOPES_2       = 0x7
	};
			
	enum _CamBehavID
	{
		CA_NO_CHANGE          = 0x0,
		CA_GO_BEHIND          = 0x1,
		CA_ZOOM_OUT_GO_BEHIND = 0x2,
		CA_GO_BEHIND_3        = 0x3,
		CA_GO_BEHIND_4        = 0x4,
		CA_UNK_5              = 0x5,
		CA_NORMAL             = 0x6,
		CA_GO_BEHIND_7        = 0x7,
		CA_GO_BEHIND_8        = 0x8,
		CA_EIGHT_DIRECTIONS   = 0x9,
		CA_NO_ROTATING        = 0xa,
		CA_ZOOM_REALLY_FAR_IN = 0xb,
		CA_GO_BEHIND_C        = 0xc,
		CA_GO_BEHIND_D        = 0xd,
		CA_GO_BEHIND_E        = 0xe,
		CA_GO_BEHIND_F        = 0xf
	};
			
	enum _BehaviorID
	{
		BH_NORMAL                 = 0x0,
		BH_LAVA                   = 0x1,
		BH_UNK_02                 = 0x2,
		BH_HANG_CEILING           = 0x3,
		BH_DEATH                  = 0x4,
		BH_DEATH_2                = 0x5,
		BH_LOW_JUMPS              = 0x6,
		BH_SLOW_SHALLOW_QUICKSAND = 0x7,
		BH_SLOW_DEEP_QUICKSAND    = 0x8,
		BH_INSTANT_QUICKSAND      = 0x9,
		BH_UNK_0A                 = 0xa,
		BH_WIND                   = 0xb,
		BH_UNK_0C                 = 0xc,
		BH_SWITCH_LEVEL_ENTRANCE  = 0xd,
		BH_NO_GETTING_STUCK       = 0xe,
		BH_RACE_START             = 0xf,
		BH_RACE_END               = 0x10,
		BH_VANISH_LUIGI_GRATE     = 0x11,
		BH_ENDLESS_STAIRS         = 0x12,
		BH_WIND_GUST              = 0x13,
		BH_CRAWL_THROUGH          = 0x14
	};
	
	u32  textureID       :  5 = TX_NORMAL;
	bool isWater         :  1 = false;
	u32  viewID          :  6 = 0x3f;
	u32  tractionID      :  3 = TR_NORMAL;
	u32  camBehavID      :  4 = CA_NO_CHANGE;
	u32  behaviorID      :  5 = BH_NORMAL;
	bool camGoesThru     :  1 = false;
	bool isToxic         :  1 = false;
	bool onlyCamCollides :  1 = false;
	u32  padding         :  5 = 0;
	u32  windID          :  8 = 0xff;
	u32  padding2        : 24 = 0;
};
	
struct CLPS_Header
{
	std::array<char, 4> magic = {'C', 'L', 'P', 'S'};
	u16 unk04 = 8;
	u16 size; // number of CLPSes
	
	constexpr CLPS_Header(u16 size) : size(size) {}
	
	CLPS_Header(const CLPS_Header&) = delete;
	CLPS_Header(CLPS_Header&&) = delete;
	
	CLPS_Header& operator=(const CLPS_Header&) = delete;
	CLPS_Header& operator=(CLPS_Header&&) = delete;
};

struct CLPS_Block : CLPS_Header
{
	CLPS clpses[]; // flexible arrays CAN be static-initialized
	
	constexpr       CLPS* begin()       { return &clpses[0]; }
	constexpr const CLPS* begin() const { return &clpses[0]; }
	constexpr       CLPS* end  ()       { return &clpses[size]; }
	constexpr const CLPS* end  () const { return &clpses[size]; }
	
	constexpr       CLPS& operator[](std::size_t i)       { return clpses[i]; }
	constexpr const CLPS& operator[](std::size_t i) const { return clpses[i]; }
};

template<CLPS... clpses>
struct StaticCLPS_Block
{
	template<auto...>
	static constinit inline CLPS_Block instance
	{
		sizeof...(clpses),
		{clpses...}
	};
};

namespace LevelFile
{
	extern "C" CLPS_Block* CLPS_BLOCK_PTR;
}

struct KCL_File
{
	struct Triangle
	{
		u32 length;
		u16 origin;
		u16 normal;
		u16 direction1;
		u16 direction2;
		u16 direction3;
		u16 collisionType;
	};
	
	Vector3* vertices;
	Vector3_16f* vectors;
	Triangle* triangles;
	void* octree;
	u32 unk10;
	Vector3 octreeOrigin;
	Vector3 octreeNegativeDimensions;
	u32 octreeBaseWidthLog2;
	u32 unk30;
	u32 unk34;
};

static_assert(sizeof(KCL_File) == 0x38);

struct SurfaceInfo
{
	CLPS clps;
	Vector3 normal;
};

struct MeshColliderBase // vtable at 0x02099388
{
	Actor* actor;
	u32 actorUniqueID;
	Fix12i range;
	Fix12i rangeOffsetY;
	u32 clsnID;
	
	void (*beforeClsnCallback) // called if there was a collision the previous frame.
	(
		MeshColliderBase& clsn,
		Actor*            clsnActor, // the mesh collider's actor for some reason
		ClsnResult&       wmClsnResult,
		Vector3&          posToUpdate,
		Vector3_16*       motionAngToUpdate,
		Vector3_16*       angToUpdate
	);
	
	void (*afterClsnCallback)
	(
		MeshColliderBase& clsn,
		Actor*            clsnActor,
		Actor*            otherActor
	);
	
	MeshColliderBase();
	virtual ~MeshColliderBase();
	virtual void Virtual08(); // all known implementations are bx lr
	virtual void GetSurfaceInfo(s16 triangleID, SurfaceInfo& res) = 0;
	virtual void GetNormal(s16 triangleID, Vector3& res) = 0;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) = 0;
	virtual bool DetectClsn(RaycastGround& ray);
	virtual bool DetectClsn(RaycastLine& ray);
	virtual bool DetectClsn(SphereClsn& sphere);
	
	virtual void BeforeClsn (
		ClsnResult& wmClsnResult, // Yes, the first two parameters are in reversed order in the callback
		Actor*      clsnActor,
		Vector3&    posToUpdate,
		Vector3_16* motionAngToUpdate,
		Vector3_16* angToUpdate
	);
	
	// returns true if vector was transformed
	virtual bool TransformPos(const Vector3& pos, Vector3& res);
	virtual u16 GetAngularVelY();
	virtual void GetVelocity(Vector3& res);
	
	bool Disable();
	bool Enable(Actor* actor = nullptr);
	bool IsEnabled();
	
	[[gnu::always_inline]]
	auto GetNormal(const s16& triangleID)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->GetNormal(triangleID, res);
		});
	}
	
	[[gnu::always_inline]]
	auto GetTriangleOrigin(const s16& triangleID)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->GetTriangleOrigin(triangleID, res);
		});
	}
	
	[[gnu::always_inline]]
	auto TransformPos(const Vector3& pos)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->TransformPos(pos, res);
		});
	}
};

static_assert(sizeof(MeshColliderBase) == 0x20);

struct MeshCollider : public MeshColliderBase
{
	KCL_File* clsnFile;
	CLPS_Block* clpsBlock;
	Vector3 unkVec28;
	Vector3 unkVec34;
	u32 unk40;
	Fix12i unk44;
	u32 unk48;
	u32 unk4c;
	
	MeshCollider();
	virtual ~MeshCollider() override;
	virtual void Virtual08() override;
	
	virtual void GetSurfaceInfo(s16 triangleID, SurfaceInfo& res) override;
	virtual void GetNormal(s16 triangleID, Vector3& res) override;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) override;
	
	virtual bool DetectClsn(RaycastGround& ray) override;
	virtual bool DetectClsn(RaycastLine&   ray) override;
	virtual bool DetectClsn(SphereClsn& sphere) override;
	
	static char* LoadFile(SharedFilePtr& filePtr);
	void SetFile(char* clsnFile, CLPS_Block& clps);
	
	using MeshColliderBase::GetNormal, MeshColliderBase::GetTriangleOrigin, MeshColliderBase::TransformPos;
};

static_assert(sizeof(MeshCollider) == 0x50);

struct MovingMeshCollider : public MeshCollider
{
	u32 unk50;                  // 0x50
	Matrix4x3 newTransform;     // 0x54
	Matrix4x3 invMat4x3_084;    // 0x84
	Matrix4x3 scMat4x3_0b4;     // 0xb4
	Matrix4x3 invMat4x3_0e4;    // 0xe4
	s16 angleY;					// 0xe8
	s16 angularVelY;			// 0xea
	Vector3 pos;				// 0x118
	Vector3 velocity;			// 0x124
	u32 unk130;                 // 0x130
	Matrix4x3 ledgeMat;         // 0x134
	u32 unk164;                 // 0x164
	Matrix4x3 clsnInvMat;       // 0x168
	Matrix4x3 sc2InvMat4x3_198; // 0x198
	
	MovingMeshCollider();
	virtual ~MovingMeshCollider() override;
	virtual void Virtual08() override;
	
	virtual void GetNormal(s16 triangleID, Vector3& res) override;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) override;
	
	virtual bool DetectClsn(RaycastGround& ray) override;
	virtual bool DetectClsn(RaycastLine&   ray) override;
	virtual bool DetectClsn(SphereClsn& sphere) override;
	
	virtual bool TransformPos(const Vector3& pos, Vector3& res) override;
	virtual u16 GetAngularVelY() override;
	virtual void GetVelocity(Vector3& res) override;
	
	void SetFile(char* clsnFile, const Matrix4x3& mat, Fix12i scale, s16 angleY, CLPS_Block& clps);
	void Transform(const Matrix4x3& mat, s16 rotY);
	
	using MeshColliderBase::GetNormal, MeshColliderBase::GetTriangleOrigin, MeshColliderBase::TransformPos;
};

static_assert(sizeof(MovingMeshCollider) == 0x1c8);

struct CylinderClsn
{
	enum Flags1 : u32
	{
		DISABLED               = 1 << 0,
		INTANGIBLE             = 1 << 1,
		VERTICAL_PUSHBACK_ONLY = 1 << 2,
		CLIMBABLE              = 1 << 3,
		GIANT                  = 1 << 4,
		SPIN_OR_GROUND_POUND   = 1 << 5,
		PUNCH                  = 1 << 6,
		KICK                   = 1 << 7,
		ROUNDHOUSE_KICK        = 1 << 8,
		SLIDE_KICK             = 1 << 9,
		DIVE                   = 1 << 10,
		UNK_11                 = 1 << 11,
		GRAB                   = 1 << 12,
		PROJECTILE             = 1 << 13,
		EXPLOSION              = 1 << 14,
		YOSHI_TONGUE           = 1 << 15,
		KNOCK_PLAYER_DIZZY     = 1 << 16,
		SPIT_ACTOR             = 1 << 17,
		FIRE                   = 1 << 18,
		
		COLLECTABLE            = 1 << 20,
		ENEMY                  = 1 << 21,
		PLAYER                 = 1 << 22,
		INTERACT_WITH_PLAYER   = 1 << 23,
		TREE                   = 1 << 24,
		HANDSTANDABLE          = 1 << 25,
		SIGN                   = 1 << 26,
		HIT_SIGN               = 1 << 27,
		UNK_28                 = 1 << 28
	};
	
	enum HitFlags : u32
	{
		HIT_BY_CHAR_MOVE            = 1 << 1,
		HIT_BY_CHAR_PROJ            = 1 << 2,
		HIT_BY_CHAR_BODY            = 1 << 3,
		HIT_BY_MEGA_CHAR            = 1 << 4,
		HIT_BY_SPIN_OR_GROUND_POUND = 1 << 5,
		HIT_BY_PUNCH                = 1 << 6,
		HIT_BY_KICK                 = 1 << 7,
		HIT_BY_BREAKDANCE           = 1 << 8,
		HIT_BY_SLIDE_KICK           = 1 << 9,
		HIT_BY_DIVE                 = 1 << 10,
		HIT_BY_UNK_11               = 1 << 11,
		HIT_BY_UNK_12               = 1 << 12,
		HIT_BY_EGG                  = 1 << 13,
		HIT_BY_UNK_14               = 1 << 14,
		HIT_BY_UNK_15               = 1 << 15,
		HIT_BY_UNK_16               = 1 << 16,
		HIT_BY_REGURG_GOOMBA        = 1 << 17,
		HIT_BY_FIRE                 = 1 << 18,
		
		HIT_BY_SHELL                = 1 << 20,
		
		HIT_BY_UNK_22               = 1 << 22,
		
		HIT_BY_PLAYER               = 1 << 27
	};

	Fix12i radius;       // 0x4
	Fix12i height;       // 0x8
	Vector3 pushback;    // 0xc
	u32 flags1;          // 0x18 (aka attackFlags)
	u32 vulnerableFlags; // 0x1c
	u32 hitFlags;        // 0x20
	u32 otherObjID;      // 0x24
	CylinderClsn* prev;  // 0x28
	CylinderClsn* next;  // 0x2c
	
	CylinderClsn();
	virtual ~CylinderClsn();
	virtual Vector3& GetPos() = 0;
	virtual u32 GetOwnerID() = 0;

	CylinderClsn(const CylinderClsn&) = delete;
	CylinderClsn(CylinderClsn&&) = delete;
	CylinderClsn& operator=(const CylinderClsn&) = delete;
	CylinderClsn& operator=(CylinderClsn&&) = delete;

	void Init(Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags);
	
	void Update();
	void Clear();

	static CylinderClsn* last;
};

static_assert(sizeof(CylinderClsn) == 0x30);

struct MovingCylinderClsn : public CylinderClsn
{
	Actor* owner; // 0x30
	
	MovingCylinderClsn();
	virtual ~MovingCylinderClsn();
	virtual Vector3& GetPos() override;
	virtual u32 GetOwnerID() override;
	
	void Init(Actor* actor, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags);
};

static_assert(sizeof(MovingCylinderClsn) == 0x34);

struct CylinderClsnWithPos : public MovingCylinderClsn
{
	Vector3 pos; // 0x34
	
	CylinderClsnWithPos();
	virtual ~CylinderClsnWithPos();
	virtual Vector3& GetPos() override;
	
	void Init(Actor* actor, const Vector3& pos, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags); // calls SetPosRelativeToActor
	void SetPosRelativeToActor(const Vector3& pos); // pos is transformed by the object's Y angle
};

static_assert(sizeof(CylinderClsnWithPos) == 0x40);

struct ClsnResult
{
	u32* vTable;                  // 0x0
	SurfaceInfo surfaceInfo;      // 0x4
	s16 triangleID;               // 0x18 (0xffff if in air)
	s16 clsnID;                   // 0x1a (not constant per object, 0x18 if in air (only 24 mesh colliders can be active at a time))
	u32 objID;                    // 0x1c
	Actor* obj;                   // 0x20
	MovingMeshCollider* meshClsn; // 0x24
	
	ClsnResult();
	~ClsnResult();
	ClsnResult& operator=(const ClsnResult&);
	
	void Reset();
};

struct BgCh //That's the internal name, and I didn't know what else to call it since I already used WithMeshClsn
{	
	enum Flags : u32
	{
		DETECT_ORDINARY   = 1 << 0, // Detect all faces with no special gimmicks related to their detectionability
		DETECT_WATER      = 1 << 1,
		BELONGS_TO_CAMERA = 1 << 2,
		DETECT_TOXIC      = 1 << 3,
		NO_DETECT_GRATE   = 1 << 5,
		IS_CRAWLING       = 1 << 6
	};
	
	// offset (<value on construction>, notes)
	u32* vTable;       // 0x0  (0x02099264)
	u32 flags;         // 0x4  (1,  probably a flag field)
	u32 objID;         // 0x8  (-1, id of game object)
	Actor* objPtr;     // 0xc  (0,  pointer to game object)
	ClsnResult result; // 0x10
	
	// Actually a member function of MeshColliderBase but the this-parameter is unused
	static bool ShouldPassThroughImpl(void* unused, const CLPS& clps, const BgCh& bgch, bool isWall);

	bool ShouldPassThrough(const CLPS& clps, bool isWall)
	{
		return ShouldPassThroughImpl(this, clps, *this, isWall);
	}
	
	void SetFlag_8();
	void SetFlag_2();
	void ClearFlag_1();
};

static_assert(sizeof(BgCh) == 0x38);

struct RaycastGround : public BgCh
{
	Vector3 pos;       // 0x38
	Fix12i clsnPosY;   // 0x44
	bool hadCollision; // 0x48
	Fix12i unk4c;      // 0x4c
	
	RaycastGround();
	~RaycastGround();
	void SetObjAndPos(const Vector3& pos, Actor* obj);
	bool DetectClsn();
};

struct RaycastLine : public BgCh
{
	struct Line
	{
		Vector3 pos0; // 0x38
		Vector3 pos1; // 0x44

		Line& Set(const Vector3& pos0, const Vector3& pos1);
	}
	line;

	bool hadCollision; // 0x50
	Vector3 clsnPos; // set to pos1 before collision
	Fix12i length; // of line
	u32* vTable3;
	Vector3 average;
	Fix12i halfLength;
	
	RaycastLine();
	~RaycastLine();
	void SetObjAndLine(const Vector3& pos0, const Vector3& pos1, Actor* obj);
	bool DetectClsn();
	/* WARNING: This function definition is wrong, it seems to be static, void and takes two args
	Vector3 GetClsnPos();
	*/
};

struct SphereClsn : public BgCh
{
	enum ResultFlags
	{
		COLLISION_EXISTS = 1 << 0,
		
		ON_GROUND        = 1 << 2,
		ON_WALL          = 1 << 3,
		
		MOVING_UP        = 1 << 5
	};
	
	SphereClsn();
	~SphereClsn();
	void SetObjAndSphere(const Vector3& pos, Fix12i radius, Actor* obj);
	bool DetectClsn();
	ClsnResult& SetFloorResult(const ClsnResult& result);
	
	u32* sphVTable;         // 0x40
	Vector3 pos;            // 0x44
	Fix12i radius;          // 0x48
	Vector3 pushback;       // 0x4c
	Vector3 pushback0;      // 0x58
	Vector3 pushback1;      // 0x64
	u32 resultFlags;        // 0x70
	ClsnResult floorResult; // 0x74
	ClsnResult wallResult;  // 0x9c
	ClsnResult unkResult;   // 0xc4
	Fix12i unk0ec;          // 0xec
	u32 unk0f0;             // 0xf0
	u32 unk0f4;             // 0xf4
	u32 unk0f8;             // 0xf8
	Vector3 storedNormal;   // 0xfc
	Fix12i unk108;          // 0x108
};

static_assert(sizeof(SphereClsn) == 0x10c);

struct WithMeshClsn
{
	enum UpdateMode
	{
		CONTINUOUS         = 0,
		CONTINUOUS_NO_LAVA = 1,
		DISCRETE_NO_LAVA   = 2,
		DISCRETE_NO_LAVA_2 = 3
	};
	
	enum Flags : s32
	{
		ON_GROUND        = 1 << 4,
		JUST_HIT_GROUND  = 1 << 5,
		JUST_LEFT_GROUND = 1 << 6,
		LIMITED_MOVEMENT = 1 << 7, //does not set speed.y to 0 if hit ground. The historical reason for the name is that not doing so disables a Goomba's horz. movement
		
		NO_UPDATE_POS_Y  = 1 << 12, //assuming this is a state flag as well.
		NO_UPDATE_POS    = 1 << 13 //this is a state flag. It will not work if you set it.
	};
	
	u32* vTable;              // 0x0
	u32 unk04;                // 0x4
	u32 unk08;                // 0x8
	u32 unk0c;                // 0xc
	u32 flags;                // 0x10
	Actor* actor;             // 0x14
	Fix12i radius;            // 0x18
	Fix12i vertOffset;        // 0x1c
	SphereClsn sphere;        // 0x20
	Vector3_16* motionDirPtr; // 0x12c
	Vector3_16* angPtr;       // 0x130
	RaycastLine line;         // 0x134
	u32 unk1ac;               // 0x1ac
	Fix12i unk1b0;            // 0x1b0
	u32 unk1b4;               // 0x1b4
	Fix12i unk1b8;            // 0x1b8
	
	WithMeshClsn();
	~WithMeshClsn();
	s32  ShouldUpdatePosY() const;
	s32  ShouldUpdatePos() const;
	s32  IsOnWall() const;
	void ClearLimMovFlag();
	void SetLimMovFlag();
	s32  IsOnGround() const;
	void ClearGroundFlag();
	void SetGroundFlag();
	s32  JustHitGround() const;
	void ClearJustHitGroundFlag();
	void ClearAllGroundFlags();
	void SetFlag_2();
	void Unk_0203589c();
	s32 TouchesWater() const;
	void Init(Actor* owner, Fix12i radius, Fix12i vertOffset, Vector3_16* motionDirPtr, Vector3_16* angPtr);
	
	void UpdateContinuous();
	void UpdateExtraContinous();
	void UpdateContinuousNoLava();
	void UpdateDiscreteNoLava();
	void UpdateDiscreteNoLava_2();
};

#endif