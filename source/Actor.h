#ifndef SM64DS_ACTOR_INCLUDED
#define SM64DS_ACTOR_INCLUDED

#include "Memory.h"


struct Player;
struct CylinderClsn;
struct ShadowModel;
struct Number;

// vtable at 0x02099edc
struct ActorBase //internal name: fBase
{
	enum AliveState
	{
		ALIVE = 1,
		DEAD = 2
	};

	struct SceneNode
	{
		SceneNode* parent;
		SceneNode* firstChild;
		SceneNode* prevSibling;
		SceneNode* nextSibling;
		ActorBase* actor;

		SceneNode(); //Calls Reset
		void Reset();
	};

	struct ProcessingListNode
	{
		ProcessingListNode* prev;
		ProcessingListNode* next;
		ActorBase* actor;
		u16 priority;
		u16 priorityCopy;

		//void RemoveFromGlobal();	//at 0x020440E8 and 0x02044104, removes if at 0x020A4B68
	};

	enum VirtualFuncSuccess
	{
		VS_FAIL_BEFORE = 0,
		VS_FAIL = 1,
		VS_SUCCESS = 2,
		VS_RETURN_MINUS_1 = 3
	};

	void* operator new(size_t count); //actor bases have their own heap
	void operator delete(void* ptr) { Memory::Deallocate(ptr, Memory::gameHeapPtr); }

	virtual s32  InitResources();
	virtual bool BeforeInitResources();
	virtual void AfterInitResources(u32 vfSuccess);
	virtual s32  CleanupResources();
	virtual bool BeforeCleanupResources();
	virtual void AfterCleanupResources(u32 vfSuccess);
	virtual s32  Behavior();
	virtual bool BeforeBehavior();
	virtual void AfterBehavior(u32 vfSuccess);
	virtual s32  Render();
	virtual bool BeforeRender();
	virtual void AfterRender(u32 vfSuccess);
	virtual void OnPendingDestroy();
	virtual bool Virtual34(u32 arg0, u32 arg1);
	virtual bool Virtual38(u32 arg0, u32 arg1);
	virtual bool OnHeapCreated();
	virtual ~ActorBase();

	s32 Process(s32 (ActorBase::*callback)(), bool (ActorBase::*preCallback)(), void (ActorBase::*postCallback)(u32 vfSuccess));

	void MarkForDestruction();

	ActorBase(const ActorBase&) = delete;
	ActorBase(ActorBase&&) = delete;
	ActorBase& operator=(const ActorBase&) = delete;
	ActorBase& operator=(ActorBase&&) = delete;

	//vTable;
	u32 uniqueID;					// 0x4
	s32 param1;						// 0x8
	u16 actorID;					// 0xc
	u8 aliveState;					// 0xe
	bool shouldBeKilled;			// 0xf
	u8 unk10;						// 0x10
	u8 unk11;						// 0x11
	u8 unk12;						// 0x12
	u8 unk13;						// 0x13
	SceneNode sceneNode;			// 0x14
	ProcessingListNode behavNode;	// 0x28
	ProcessingListNode renderNode;	// 0x38
	u8 unk48;						// 0x48
	u8 unk49;						// 0x49
	u16 unk4a;						// 0x4a
	u32 unk4c;						// 0x4c
};

struct ActorDerived : public ActorBase //internal name: dBase
{
	virtual void AfterInitResources(u32 vfSuccess) override; //Destroys Actor (ActorBase::Destroy) on vfunc failure, then calls ActorBase::AfterInitResources(u32)
	virtual ~ActorDerived() override;
};

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
	virtual ~Actor();
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
	void UntrackInDeathTable();
	bool GetBitInDeathTable();

	void BigLandingDust(bool doRaycast);
	void BigLandingDustAt(Vector3& vec, bool doRaycast);
	void LandingDust(bool doRaycast);
	void LandingDustAt(Vector3& vec, bool doRaycast);
	void DisappearPoofDustAt(const Vector3& vec);
	void SmallPoofDust();
	void PoofDustAt(const Vector3& vec);
	void PoofDust(); //calls the two above function
	
	void UntrackStar(s8& starID);
	
	// trackStarID seems to be an address
	Actor* UntrackAndSpawnStar(u32 trackStarID, u32 starID, const Vector3& spawnPos, u32 howToSpawnStar);
	u32 TrackStar(u32 starID, u32 starType); //starType=1: silver star, 2: star //returns star ID or 0xff if starID != STAR_ID

	void Earthquake(const Vector3& source, Fix12i magnitude);
	s16 ReflectAngle(Fix12i normalX, Fix12i normalZ, s16 angToReflect);

	bool BumpedUnderneathByPlayer(Player& player); //assumes there is a collision in the first place
	bool JumpedOnByPlayer(CylinderClsn& cylClsn, Player& player);
	void Unk_0201061c(Player& player, u32 numCoins, u32 coinType);

	Fix12i DistToCPlayer();
	Player* ClosestPlayer();
	s16 HorzAngleToCPlayer();
	s16 HorzAngleToCPlayerOrAng(s16 ang);
	Player* FarthestPlayer();
	Fix12i DistToFPlayer();

	// The opacity is from 0 to 30
	void DropShadowScaleXYZ (ShadowModel& shadow, Matrix4x3& matrix, Fix12i scaleX, Fix12i scaleY, Fix12i scaleZ, u32 opacity);
	void DropShadowRadHeight(ShadowModel& shadow, Matrix4x3& matrix, Fix12i radius, Fix12i depth, u32 opacity);

	void UpdatePos(CylinderClsn* clsn); //Applies motion direction, vertical acceleration, and terminal velocity.
	void UpdatePosWithOnlySpeed(CylinderClsn* clsn);//IMPORTANT!: When spawning a Super Mushroom, make sure to already have the model loaded before the player goes super!
	//You cannot afford to spawn a Super Mushroom if there are 0 uses of the model's SharedFilePtr and the player already went super.
	//If you do, particle color glitches will happen!

	Number* SpawnNumber(const Vector3& pos, u32 number, bool isSilver, u16 unk14c, Actor* unkActor = nullptr);
	static Actor* Spawn(u32 actorID, u32 param1, const Vector3& pos, const Vector3_16* rot, s32 areaID, s32 deathTableID);
	static Actor* Next(const Actor* actor); //next in the linked list. Returns the 1st object if given a nullptr. Returns a nullptr if given the last actor
	static Actor* FindWithID(u32 id);
	static Actor* FindWithActorID(u32 actorID, Actor* searchStart); //searchStart is not included.

	static Actor* First() { return Next(nullptr); }
	static Actor* FirstWithActorID(u32 actorID) { return FindWithActorID(actorID, nullptr); }
	
	[[deprecated("Use Actor::Iterate instead")]]
	static void ForEach(auto&& f)
	{
		Actor* actor = nullptr;
		while ((actor = Next(actor)) != nullptr)
			f(*actor);
	}
	
	[[deprecated("Use Actor::Iterate instead")]]
	static void ForEach(u16 actorID, auto&& f)
	{
		Actor* actor = nullptr;
		while ((actor = FindWithActorID(actorID, actor)) != nullptr)
			f(*actor);
	}
	
	template<std::derived_from<Actor> T, u16 actorID>
	struct Alias
	{
		static constexpr u16 staticActorID = actorID;
	};
	
	template<class T>
	struct ResolveAlias { using Type = T; };
	
	template<std::derived_from<Actor> T, u16 actorID>
	struct ResolveAlias<Alias<T, actorID>> { using Type = T; };
	
	template<class T>
	static auto* Spawn(unsigned param1, const Vector3& pos, auto... args)
	{
		return static_cast<ResolveAlias<T>::Type*>(Spawn(T::staticActorID, param1, pos, args...));
	}
	
	template<class T>
	static ResolveAlias<T>::Type* Find()
	{
		return static_cast<ResolveAlias<T>::Type*>(FindWithActorID(T::staticActorID));
	}
	
	template<class T>
	ResolveAlias<T>::Type* FindClosest() const
	{
		return static_cast<ResolveAlias<T>::Type*>(FindClosestWithActorID(T::staticActorID));
	}
	
	template<class T = Actor>
	static consteval auto Iterate()
	{
		struct Sentinel {};
		
		using A = ResolveAlias<T>::Type;
		
		struct Iterator
		{
			A* ptr;

			consteval void operator++() {} // no-op
			constexpr A& operator*() const { return *ptr; }

			bool operator==(Sentinel) // actually increments the iterator
			{
				if constexpr (std::same_as<T, Actor>)
					ptr = Next(ptr);
				else
					ptr = static_cast<A*>(FindWithActorID(T::staticActorID, ptr));

				return ptr == nullptr;
			}
		};
		
		// Warning: For performance reasons, the iterators of this range don't
		// behave normally and should only be used for range-based for loops
		struct Range
		{
			constexpr Iterator begin() const { return {}; }
			constexpr Sentinel end  () const { return {}; }
		};
		
		return Range {};
	}
};

static_assert(sizeof(Actor) == 0xd4);

struct BaseSpawnInfo
{
	ActorBase* (*spawnFunc)();
	s16 behavPriority;
	s16 renderPriority;
};

// the player actually uses this one, but i'm not sure if behavPriority and renderPriority are named correctly
struct SpawnInfo : BaseSpawnInfo
{
	u32 flags;
	Fix12i rangeOffsetY;
	Fix12i range;
	Fix12i drawDist;
	Fix12i unkc0;
};

extern BaseSpawnInfo* (*ACTOR_SPAWN_INFO_TABLE_PTR)[];

// the pointer to Player's SpawnInfo2 is only read  in Actor::Actor after the first time

// Player's SpawnInfo2 is at 0x0210a704
// struct SpawnInfo2
// {
// 	ActorBase* (*spawnFunc)();
// 	u16 actorID;
// 	u16 unk06;
// 	u32 flags;      // 08
// 	Fix12i rangeOffsetY; // 0c
// 	Fix12i range;        // 10
// 	Fix12i drawDist;     // 14
// 	Fix12i unkc0;        // 18
// };


#endif