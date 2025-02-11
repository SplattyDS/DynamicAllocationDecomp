#pragma once

struct Actor : public ActorBase				//internal name: dActor			
{
	enum Flags : s32
	{
		NO_BEHAVIOR_IF_OFF_SCREEN	= 1 << 0,
		NO_RENDER_IF_OFF_SCREEN		= 1 << 1, //offscreen can mean too far away.
		UNK_02						= 1 << 2,
		OFF_SCREEN					= 1 << 3,
		OFF_SHADOW_RANGE			= 1 << 4,
		WRONG_AREA					= 1 << 5,
		
		GRABBABLE					= 1 << 7,
		GRABBED						= 1 << 8,
		UNK_09						= 1 << 9,
		THROWN						= 1 << 10,
		UNK_11						= 1 << 11,
		UNK_12						= 1 << 12,
		DROPPED						= 1 << 13,
		IN_PLAYER_HAND				= 1 << 14,
		N_CARRY						= 1 << 15,
		UNK_16						= 1 << 16,
		GOING_TO_YOSHI_MOUTH		= 1 << 17,
		IN_YOSHI_MOUTH				= 1 << 18,
		BEING_SPIT					= 1 << 19,
		
		
		
		UPDATE_WHEN_READING_SIGN	= 1 << 23,
		CAN_NO_DAMAGE_SQUISH_PLAYER	= 1 << 24,
		CAN_SQUISH					= 1 << 25,
		UPDATE_DURING_STAR_CUTSCENE	= 1 << 26,
		SPAWN_EVEN_IF_KILLED_BEFORE	= 1 << 27,
		AIMABLE_BY_EGG				= 1 << 28,
		UPDATE_DURING_CUTSCENE		= 1 << 29,
		UPDATE_DURING_EXIT_COURSE	= 1 << 30,
		UPDATE_DURING_SAVE			= 1 << 31
	};
	
	struct ListNode
	{
		ListNode* prev;
		ListNode* next;
		Actor* actor;
	};
	
	enum OnYoshiEatReturnVal : s32
	{
		YE_DONT_EAT					= 0,
		YE_KEEP_IN_MOUTH			= 1,
		YE_SPIT_AND_GET_HURT		= 2,
		YE_SPIT						= 3,
		YE_SWALLOW					= 4,
		YE_GAIN_FIRE_BREATH			= 5,
		YE_KEEP_AND_CAN_MAKE_EGG	= 6,
		YE_UNK_7                    = 7,
	};
	
	ListNode listNode;		// 0x50
	Vector3 pos;			// 0x5c
	Vector3 prevPos;		// 0x68
	Vector3 camSpacePos;	// 0x74
	Vector3 scale;			// 0x80
	Vector3_16 ang;			// 0x8c
	Vector3_16 motionAng;	// 0x92
	Fix12i horzSpeed;		// 0x98
	Fix12i vertAccel;		// 0x9c
	Fix12i termVel;			// 0xa0
	Vector3 speed;			// 0xa4
	u32 flags;				// 0xb0
	Fix12i rangeOffsetY;	// 0xb4
	Fix12i rangeAsr3;		// 0xb8
	Fix12i drawDistAsr3;	// 0xbc
	Fix12i unkc0Asr3;		// 0xc0
	u32 unkc4;				// 0xc4
	u32 unkc8;				// 0xc8
	s8 areaID;				// 0xcc (it is signed)
	u8 unkcd;				// 0xcd
	s16 deathTableID;		// 0xce
	Player* eater;			// 0xd0
	
	Actor();
	virtual bool BeforeInitResources() override;
	virtual void AfterInitResources(u32 vfSuccess) override;
	virtual bool BeforeCleanupResources() override;
	virtual void AfterCleanupResources(u32 vfSuccess) override;
	virtual bool BeforeBehavior() override;
	virtual void AfterBehavior(u32 vfSuccess) override;
	virtual bool BeforeRender() override;
	virtual void AfterRender(u32 vfSuccess) override;
	virtual ~Actor() override;
	virtual u32 OnYoshiTryEat();
	virtual void OnTurnIntoEgg(Player& player);
	virtual bool Virtual50();
	virtual void OnGroundPounded(Actor& groundPounder);
	virtual void OnAttacked1(Actor& attacker);
	virtual void OnAttacked2(Actor& attacker);
	virtual void OnKicked(Actor& kicker);
	virtual void OnPushed(Actor& pusher);
	virtual void OnHitByCannonBlastedChar(Actor& blaster);
	virtual void OnHitByMegaChar(Player& megaChar);
	virtual void OnHitFromUnderneath(Actor& attacker);
	virtual Fix12i OnAimedAtWithEgg();
	virtual Vector3 OnAimedAtWithEggReturnVec();
	
	bool IsTooFarAwayFromPlayer(Fix12i tooFar);
	void MakeVanishLuigiWork(CylinderClsn& cylClsn);
	void SpawnSoundObj(u32 soundObjParam);
	
	void KillAndTrackInDeathTable();
	void TrackInDeathTable();
	void UntrackInDeathTable();
	bool GetBitInDeathTable();
	
	void HugeLandingDust(bool doRaycast);
	void HugeLandingDustAt(Vector3& vec, bool doRaycast);
	void BigLandingDust(bool doRaycast);
	void BigLandingDustAt(Vector3& vec, bool doRaycast);
	void LandingDust(bool doRaycast);
	void LandingDustAt(Vector3& vec, bool doRaycast);
	void DisappearPoofDustAt(const Vector3& vec);
	void SmallPoofDust();
	void PoofDustAt(const Vector3& vec);
	void PoofDust(); // calls the two above function
	void TriplePoofDust();
	void TriplePoofDustAt(const Vector3& pPos);
	
	void UntrackStar(s8& starID);
	Actor* UntrackAndSpawnStar(s8& trackStarID, u32 starID, const Vector3& spawnPos, u32 howToSpawnStar); // trackStarID seems to be an address
	s8 TrackStar(u32 starID, u32 starType); //starType=1: silver star, 2: star //returns star ID or -1 if starID != STAR_ID
	
	void Earthquake(const Vector3& source, Fix12i magnitude);
	s16 ReflectAngle(Fix12i normalX, Fix12i normalZ, s16 angToReflect);
	
	bool BumpedUnderneathByPlayer(Player& player); //assumes there is a collision in the first place
	bool JumpedOnByPlayer(CylinderClsn& cylClsn, Player& player);
	void GivePlayerCoins(Player& player, u8 numCoins, u32 coinType);
	
	Fix12i DistToCPlayer();
	Player* ClosestPlayer();
	Player* ClosestNonVanishPlayer();
	s16 HorzAngleToCPlayer();
	s16 HorzAngleToCPlayerOrAng();
	Player* FarthestPlayer();
	s16 HorzAngleToFPlayer();
	bool IsPlayerInRange(s32 maxDist); // yes it uses an int
	bool IsPlayerInRange(const Vector3& pos, s32 maxDist); // uses pos instead of this->pos
	bool IsPlayerInRange(Fix12i posX, Fix12i posY, Fix12i posZ, s32 maxDist); // uses params instead of this->pos
	
	// opacity is from 0 to 30
	void DropShadowScaleXYZ (ShadowModel& shadow, Matrix4x3& matrix, Fix12i scaleX, Fix12i scaleY, Fix12i scaleZ, u32 opacity);
	void DropShadowRadHeight(ShadowModel& shadow, Matrix4x3& matrix, Fix12i radius, Fix12i depth, u32 opacity);
	
	void UpdatePos(CylinderClsn* clsn); // applies motion direction, vertical acceleration, and terminal velocity.
	void UpdatePosWithOnlySpeed(CylinderClsn* clsn);
	void UpdatePosWithHorzSpeedAndAng();
	bool DetectRaycastClsn(Vector3& raycastPos, Vector3& pos, bool updatePos);
	
	Matrix4x3& UpdateCarry(Player& player, const Vector3& offset); // returns a reference to the transform mat (MATRIX_SCRATCH_PAPER)
	
	void SetRanges(Fix12i newRangeOffsetY, Fix12i newRange, Fix12i newDrawDist, Fix12i newUnkc0);
	
	s16 GetSubtraction(s16 arg1, s16 arg2); // returns arg2 - arg1 without overflow
	Fix12i GetWaterHeightWDW(); // if in WDW, returns the height of the water, else it returns pos.y
	
	void SpawnCoins(const Vector3& coinPos, u32 numCoins, Fix12i prevSpeed, s16 baseAng);
	Number* SpawnNumber(const Vector3& pos, u32 number, bool isSilver, u16 unk14c, Actor* unkActor = nullptr);
	void SpawnFireball(const Vector3& pos, const Vector3_16* rot, Fix12i horzSpeed, Fix12i unk35c, u32 param1);
	
	Actor* FindEgg(CylinderClsn& cylClsn);
	Actor* FindExplosionActor(CylinderClsn& cylClsn);
	
	static Actor* Spawn(u32 actorID, u32 param1, const Vector3& pos, const Vector3_16* rot, s32 areaID, s32 deathTableID);
	
	static Actor* Next(const Actor* actor); // next in the linked list, returns the 1st object if given a nullptr, returns a nullptr if given the last actor
	
	Actor* ClosestWithActorID(u32 actorID);
	static Actor* FindWithID(u32 id);
	static Actor* FindWithActorID(u32 actorID, Actor* searchStart); //searchStart is not included.
	static Actor* First() { return Next(nullptr); }
	static Actor* FirstWithActorID(u32 actorID) { return FindWithActorID(actorID, nullptr); }
	
	[[gnu::always_inline]]
	inline void UpdateVertSpeed()
	{
		if (speed.y + vertAccel >= termVel)
			speed.y += vertAccel;
		else
			speed.y = termVel;
	}
	
	[[gnu::always_inline]]
	inline void UpdateVertSpeedWithNormal(Vector3& normal)
	{
		if (normal.y != 0._f)
		{
			Fix12i surfaceSpeed = (normal.x * speed.x + normal.z * speed.z) / normal.y;
			speed.y = -(surfaceSpeed + 8._f);
		}
	}
};

static_assert(sizeof(Actor) == 0xd4);