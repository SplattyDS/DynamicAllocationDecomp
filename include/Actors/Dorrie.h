#pragma once

struct DorrieCap;

struct DorriePlatform
{
	Matrix4x3 clsnNextMat;   // 0x00
	MovingMeshCollider clsn; // 0x30
	Vector3_16 rot;          // 0x1f8
};

struct Dorrie : Actor
{
	enum Animations
	{
		HEAD_DOWN,
		HEAD_UP,
		SWIM,
		
		NUM_ANIMS,
	};
	
	enum Platforms
	{
		BODY,
		NECK,
		HEAD,
		ARM_L,
		ARM_R,
		LEG_L,
		LEG_R,
		
		NUM_PLATFORMS,
		NUM_PLATFORMS_WITH_CALLBACKS = HEAD + 1,
	};
	
	enum States
	{
		ST_SWIM,
		ST_HEAD_GO_DOWN,
		ST_HEAD_GO_UP,
	};
	
	enum ClsnStates
	{
		CS_NO_CLSN,
		CS_BODY_CLSN,
		CS_HEAD_CLSN,
	};
	
	DorrieCap* cap;                          // 0xd4
	Vector3 capPos;                          // 0xd8
	s16 headRotX;                            // 0xe4
	u16 unkTimer;                            // 0xe6 (always 0)
	bool hasCap;                             // 0xe8
	ModelAnim modelAnim;                     // 0xec
	DorriePlatform platforms[NUM_PLATFORMS]; // 0x150 (7 * 0x200)
	WithMeshClsn wmClsn;                     // 0xf50
	MovingCylinderClsn cylClsn1;             // 0x110c
	MovingCylinderClsnWithPos cylClsn2;      // 0x1140
	Vector3 headPos;                         // 0x1180
	Player* clsnPlayer;                      // 0x118c
	Player* rider;                           // 0x1190 (the player looking up after stepping on the head)
	Vector3 centerPos;                       // 0x1194
	Fix12i distToCenter;                     // 0x11a0
	s16 angToCenter;                         // 0x11a4
	s16 angVelY;                             // 0x11a6
	Fix12i pushDownHeight;                   // 0x11a8
	Fix12i sinkHeight;                       // 0x11ac
	u8 stateState;                           // 0x11b0
	// u8 unk11b1;                           // unused
	u16 stateTimer;                          // 0x11b2
	u8 state;                                // 0x11b4
	u8 clsnState;                            // 0x11b5
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	static SharedFilePtr clsnFiles[NUM_PLATFORMS];
	static CLPS_Block* clpsBlocks[NUM_PLATFORMS];
	
	Dorrie();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Dorrie() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransforms();
	bool DisableClsnIfOffScreen();
	void AfterHeadClsn(Actor& otherActor);
	void AfterBodyClsn(Actor& otherActor);
	
	void St_Swim();
	void St_HeadGoDown();
	void St_HeadGoUp();
	
	static void AfterHeadClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
	static void AfterBodyClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};

static_assert(sizeof(Dorrie) == 0x11b8);
static_assert(sizeof(DorriePlatform) == 0x200);