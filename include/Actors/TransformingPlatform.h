#pragma once

struct TransformingPlatformRes;

struct TransformingPlatform : Actor
{
	enum States
	{
		WAIT_FOR_ACTIVATION,
		ACTIVATING,
		WAIT_FOR_DEACTIVATION,
		DEACTIVATING,
	};
	
	enum ModelStates
	{
		ACTIVATE,
		ALMOST_ACTIVE,
		HALF_ACTIVE,
		ALMOST_INACTIVE,
		INACTIVE,
		
		NUM_MODEL_STATES,
	};
	
	// was a Platform but didn't use any Platform members
	Model model[NUM_MODEL_STATES];             // 0x320
	MovingMeshCollider clsn[NUM_MODEL_STATES]; // 0x4b0
	Matrix4x3 clsnNextMat;                     // 0xd98
	u8 modelState;                             // 0xdc8
	u8 stateTimer;                             // 0xdc9
	u8 state;                                  // 0xdca
	u8 eventID;                                // 0xdcb
	
	
	virtual s32 InitResources() = 0;
	virtual s32 CleanupResources() = 0;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TransformingPlatform() override;
	
	s32 BaseInitResources(TransformingPlatformRes& res);
	s32 BaseCleanupResources(TransformingPlatformRes& res);
};

struct TrickyTriangles : TransformingPlatform
{
	using TransformingPlatform::ModelStates;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFiles[NUM_MODEL_STATES];
	static SharedFilePtr clsnFiles[NUM_MODEL_STATES];
	static TransformingPlatformRes resources;
	
	TrickyTriangles();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~TrickyTriangles() override;
};

struct Stairs_BDW : TransformingPlatform
{
	using TransformingPlatform::ModelStates;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFiles[NUM_MODEL_STATES];
	static SharedFilePtr clsnFiles[NUM_MODEL_STATES];
	static TransformingPlatformRes resources;
	
	Stairs_BDW();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~Stairs_BDW() override;
};

struct Stairs_BS : TransformingPlatform
{
	using TransformingPlatform::ModelStates;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFiles[NUM_MODEL_STATES];
	static SharedFilePtr clsnFiles[NUM_MODEL_STATES];
	static TransformingPlatformRes resources;
	
	Stairs_BS();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual ~Stairs_BS() override;
};

struct TransformingPlatformRes
{
	PlatformRes res[TransformingPlatform::NUM_MODEL_STATES];
};