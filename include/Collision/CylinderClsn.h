#pragma once

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
		UNK_19                 = 1 << 19,
		COLLECTABLE            = 1 << 20,
		ENEMY                  = 1 << 21,
		PLAYER                 = 1 << 22,
		INTERACT_WITH_PLAYER   = 1 << 23,
		TREE                   = 1 << 24,
		HANDSTANDABLE          = 1 << 25,
		SIGN                   = 1 << 26,
		HIT_SIGN               = 1 << 27,
		UNK_28                 = 1 << 28,
	};
	
	enum HitFlags : u32
	{
		HIT_DISABLED                = 1 << 0, // DISABLED
		HIT_BY_CHAR_MOVE            = 1 << 1, // INTANGIBLE
		HIT_BY_CHAR_PROJ            = 1 << 2, // VERTICAL_PUSHBACK_ONLY
		HIT_BY_CHAR_BODY            = 1 << 3, // CLIMBABLE
		HIT_BY_MEGA_CHAR            = 1 << 4,
		HIT_BY_SPIN_OR_GROUND_POUND = 1 << 5,
		HIT_BY_PUNCH                = 1 << 6,
		HIT_BY_KICK                 = 1 << 7,
		HIT_BY_BREAKDANCE           = 1 << 8,
		HIT_BY_SLIDE_KICK           = 1 << 9,
		HIT_BY_DIVE                 = 1 << 10,
		HIT_BY_UNK_11               = 1 << 11,
		HIT_BY_GRAB                 = 1 << 12,
		HIT_BY_EGG                  = 1 << 13,
		HIT_BY_EXPLOSION            = 1 << 14,
		HIT_BY_YOSHI_TONGUE         = 1 << 15,
		HIT_BY_KNOCK_PLAYER_DIZZY   = 1 << 16,
		HIT_BY_REGURG_GOOMBA        = 1 << 17,
		HIT_BY_FIRE                 = 1 << 18,
		HIT_BY_UNK19                = 1 << 19,
		HIT_BY_COLLECTABLE          = 1 << 20,
		HIT_BY_ENEMY                = 1 << 21,
		HIT_BY_PLAYER               = 1 << 22,
		HIT_BY_INTERACT_WITH_PLAYER = 1 << 23,
		HIT_BY_TREE                 = 1 << 24,
		HIT_BY_HANDSTANDABLE        = 1 << 25,
		HIT_BY_SIGN                 = 1 << 26,
		HIT_BY_HIT_SIGN             = 1 << 27, // old HIT_BY_PLAYER
		HIT_BY_UNK28                = 1 << 28,
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

struct CylinderClsnWithPos : public CylinderClsn
{
	Vector3 pos; // 0x30
	
	CylinderClsnWithPos();
	virtual ~CylinderClsnWithPos();
	virtual Vector3& GetPos() override;
	virtual u32 GetOwnerID() override;
	
	void Init(const Vector3& pos, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags);
};

struct MovingCylinderClsn : public CylinderClsn
{
	Actor* owner; // 0x30
	
	MovingCylinderClsn();
	virtual ~MovingCylinderClsn();
	virtual Vector3& GetPos() override;
	virtual u32 GetOwnerID() override;
	
	void Init(Actor* actor, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags);
};

struct MovingCylinderClsnWithPos : public MovingCylinderClsn
{
	Vector3 pos; // 0x34
	
	MovingCylinderClsnWithPos();
	virtual ~MovingCylinderClsnWithPos();
	virtual Vector3& GetPos() override;
	
	void Init(Actor* actor, const Vector3& pos, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags); // calls SetPosRelativeToActor
	void SetPosRelativeToActor(const Vector3& pos); // pos is transformed by the object's Y angle
};

static_assert(sizeof(CylinderClsn) == 0x30);
static_assert(sizeof(CylinderClsnWithPos) == 0x3c);
static_assert(sizeof(MovingCylinderClsn) == 0x34);
static_assert(sizeof(MovingCylinderClsnWithPos) == 0x40);