#pragma once

struct Scene : ActorDerived		//internal name: dScene
{
	virtual bool BeforeInitResources();
	virtual void AfterInitResources(u32 vfSuccess);
	virtual bool BeforeCleanupResources();
	virtual void AfterCleanupResources(u32 vfSuccess);
	virtual bool BeforeBehavior();
	virtual void AfterBehavior(u32 vfSuccess);
	virtual bool BeforeRender();
	virtual void AfterRender(u32 vfSuccess);
	virtual ~Scene();
	
	bool ResetFadersAndSound(); // also sets the scene as the root ActorBase in the scene tree
	
	static void SetAndStopColorFader();
	static void SetFaders(FaderBrightness* fader);
	static void SpawnIfNecessary(); // spawns a new scene if there is a scene to be spawned
	static void PrepareToSpawnBoot();
	static void StartSceneFade(u32 actorID, u32 param, u16 fadeColor); // the actorID should be a scene actor ID, the only colors you can set are black and white.
	static void Initialise3dGraphics();
	static void ResetHardwareRegisters();
	static bool SetSceneToSpawn(u32 actorID, u32 param); // the actorID should be a scene actor ID, returns true if the scene is a new one
	
	static s32 GraphCallback0();
	static s32 GraphCallback1();
	static s32 GraphCallback2();
	static s32 GraphCallback3();
};

struct GraphCallbacks
{
	using GraphCallbackFunc = s32(*)();
	
	GraphCallbackFunc unk0; // called in FUN_02019390, which is called in Game::Loop (loopState = 2)
	GraphCallbackFunc unk1; // called in FUN_02019404, which is called in Game::Loop (loopState = 2)
	GraphCallbackFunc unk2; // called in FUN_02019144, which is called in VBlankHandler (when on a "render" frame)
	GraphCallbackFunc unk3; // called in FUN_02019100, which is called in VBlankHandler (when on a "lag" frame)
};

struct SceneRelated
{
	GraphCallbacks* graphCallbacks; // 0x00
	Matrix2x2 bgMat;                // 0x04
	s32 bgCenterX;                  // 0x14
	s32 bgCenterY;                  // 0x18
	s32 bgX1;                       // 0x1c
	s32 bgY1;                       // 0x20
	// unknown if there are more members
};

extern "C"
{
	extern SceneRelated* SCENE_RELATED;
	extern SceneRelated STAGE_SCENE_RELATED;
	extern FaderColor* SCENE_FADER;
	extern FaderColor DEFAULT_SCENE_FADER;
}