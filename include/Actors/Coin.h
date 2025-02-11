#pragma once

struct StarMarker;

struct Coin : Actor
{
	enum Types
	{
		YELLOW_COIN = 0,
		RED_COIN    = 1,
		BLUE_COIN   = 2,
		
		NUM_TYPES,
	};
	
	enum Behaviors
	{
		BH_FALL_DOWN                     = 0,
		BH_STATIC_PERMANENT              = 1,
		BH_MOVE                          = 2,
		BH_BOUNCE_FROM_PLAYER            = 3,
		BH_STATIC                        = 4,
		BH_SLIDE                         = 5,
		BH_INTANGIBLE_BOUNCE_DISAPPEAR   = 6,
		BH_STATIC_PERMANENT_SMALL_HITBOX = 7,
		BH_INTANGIBLE_ABOVE_PLAYER       = 8,
		
		NUM_BEHAVIORS,
	};
	
	enum ShadowFlags
	{
		FIXED_SHADOW_DEPTH    = 0,
		VARIABLE_SHADOW_DEPTH = 1,
		NO_SHADOW             = 2,
		
		UPDATE_FLOOR_POS      = 7,
	};
	
	u32 puzzleManagerID;        // 0xd4
	CommonModel model;          // 0xd8
	CommonModel lowModel;       // 0x114
	ShadowModel shadow;         // 0x150
	MovingCylinderClsn cylClsn; // 0x178
	WithMeshClsn wmClsn;        // 0x1ac
	Matrix4x3 shadowMat;        // 0x368
	Fix12i floorPosY;           // 0x398
	Actor* swallower;           // 0x39c
	u32 type;                   // 0x3a0
	u32 behavior;               // 0x3a4
	u16 disappearTimer;         // 0x3a8
	u8 noClsnTimer;             // 0x3aa
	union                       // 0x3ab (eventID for )
	{
		u8 eventID; // BLUE_COIN (event ID of BlueCoinSwitch)
		u8 starID;  // RED_COIN
	};
	s8 trackStarID;             // 0x3ac
	u8 unk3ad;                  // unused
	// u8 someFlags;            // 0x3ae (now uses the bitfield below)
	bool visible : 1;
	bool playFlySfx : 1;
	u8 numBounces : 3;
	u8 shadowFlags : 3;
	bool searchedForBrickBlock; // 0x3af
	bool inBrickBlock;          // 0x3b0
	u8 unk3b1;                  // unused
	u16 unk3b2;                 // unused
	
	// static SpawnInfo spawnData[NUM_TYPES];
	static SpawnInfo spawnDataYellow;
	static SpawnInfo spawnDataRed;
	static SpawnInfo spawnDataBlue;
	
	Coin();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Coin() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	
	bool KillIfInDeathTable();
	bool IsInYoshiMouth();
	void DropShadow();
	void UpdateFloorPos();
	bool CheckClsnWithPlayer();
	void CollectRedCoin(Player& player);
	void CollectBlueCoin(Player& player);
	void CollectYellowCoin(Player& player);
	StarMarker* GetStarMarker();
	void UpdatePosAndWmClsn();
	void FindBrickBlock();
	void ReflectAngleFromWall();
	
	void Bh_FallDown();
	void Bh_StaticPermanent();
	void Bh_Move();
	void Bh_BounceFromPlayer();
	void Bh_Static();
	void Bh_Slide();
	void Bh_IntangibleAbovePlayer();
	
	static void Spawn100CoinStarIfNecessary(Player* player);
};

static_assert(sizeof(Coin) == 0x3b4, "Size of Coin is incorrect.");