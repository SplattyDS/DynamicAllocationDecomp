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
	
	// bool ResetFadersAndSound(); // also sets the scene as the root ActorBase in the scene tree (address unknown, Josh forgot to add it, found it, it's 0x0202e66c)
	
	static void SetAndStopColorFader();
	static void SetFaders(FaderBrightness* fader);
	static void SpawnIfNecessary(); // spawns a new scene if there is a scene to be spawned
	static void PrepareToSpawnBoot();
	
	void StartSceneFade(u32 actorID, u32 param, u16 fadeColor); // the actorID should be a scene actor ID, the only colors you can set are black and white.
	bool SetSceneToSpawn(u32 actorID, u32 param); // the actorID should be a scene actor ID, returns true if the scene is a new one
};

struct SceneCallback
{
	using SceneCallbackFunc = s32(*)();
	
	SceneCallbackFunc unkCallback0;
	SceneCallbackFunc unkCallback1;
	SceneCallbackFunc unkCallback2;
	SceneCallbackFunc unkCallback3;
};

extern "C"
{
	extern SceneCallback* SCENE_CALLBACK_FUNCS;
	extern SceneCallback EMPTY_SCENE_CALLBACKS; // they're all "return 1;"
	extern Fader* SCENE_FADER;
}