#pragma once

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
	void CopyTo(ClsnResult& result) const;
	u32 GetClsnID() const;
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
	
	void SetFlag_8();
	void SetFlag_2();
	void ClearFlag_1();
	
	// Actually a member function of MeshColliderBase but the this-parameter is unused
	static bool ShouldPassThroughImpl(void* unused, const SPLC& splc, const BgCh& bgch, bool isWall);
	
	[[gnu::always_inline]]
	bool ShouldPassThrough(const SPLC& splc, bool isWall)
	{
		return ShouldPassThroughImpl(this, splc, *this, isWall);
	}
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
		Vector3 pos0; // 0x0
		Vector3 pos1; // 0xc
		
		Line& Set(const Vector3& pos0, const Vector3& pos1);
	};
	
	Line line; // 0x38
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
	
	// static void GetClsnPos(Vector3& res, RaycastLine& line); // why is this static?
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
	
	SphereClsn();
	~SphereClsn();
	
	void SetObjAndSphere(const Vector3& pos, Fix12i radius, Actor* obj);
	bool DetectClsn();
	ClsnResult& SetFloorResult(const ClsnResult& result);
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
	u32  GetLimMovFlag() const;
	s32  IsOnGround() const;
	void ClearGroundFlag();
	void SetGroundFlag();
	s32  JustHitGround() const;
	void ClearJustHitGroundFlag();
	void ClearAllGroundFlags();
	void SetFlag_2();
	void Unk_0203589c();
	s32  TouchesWater() const;
	ClsnResult& GetFloorResult() const;
	ClsnResult& GetWallResult() const;
	void Init(Actor* owner, Fix12i radius, Fix12i vertOffset, Vector3_16* motionDirPtr, Vector3_16* angPtr);
	
	void UpdateContinuous();
	void UpdateExtraContinous();
	void UpdateContinuousNoLava();
	void UpdateDiscreteNoLava();
	void UpdateDiscreteNoLava_2();
};