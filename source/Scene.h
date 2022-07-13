#ifndef SM64DS_SCENE_INCLUDED
#define SM64DS_SCENE_INCLUDED

#include "SM64DS_Common.h"

struct Scene : public ActorDerived		//internal name: dScene
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
	
	//void ResetFadersAndSound(); // also sets the scene as the root ActorBase in the scene tree (address unknown, Josh forgot to add it)
	
	static void SetAndStopColorFader();
	static void SetFaders(FaderBrightness* fader);
	static void SpawnIfNecessary(); // spawns a new scene if there is a scene to be spawned
	static void PrepareToSpawnBoot();
	
	void StartSceneFade(u32 actorID, u32 param, u16 fadeColor); // the actorID should be a scene actor ID, the only colors you can set are black and white.
	bool SetSceneToSpawn(u32 actorID, u32 param); // the actorID should be a scene actor ID, returns true if the scene is a new one
};

struct BootScene : public Scene			//internal name: dScBoot
{
	u32 unk50;
	u32 unk54;
};

// constructor at 0x020352B4
struct MultiBootScene : public Scene	//internal name: dScMB
{
	//size 0x68
	//ColorFader?
};

struct Area
{
	TextureTransformer* texSRT;
	bool showing;
	u8 unk5;
	u16 unk6;
	u32 unk8;
};

// constructor at 0x0202e088
struct Stage : public Scene				//internal name: dScStage, actorID = 0x003
{
	Stage();
	virtual int  InitResources();
	virtual bool BeforeInitResources();
	virtual int  CleanupResources();
	virtual int  Behavior();
	virtual int  Render();
	virtual void OnPendingDestroy();
	virtual ~Stage();
	
	Particle::SysTracker particleSysTracker;
	Model model;
	Area areas[0x08];
	MeshCollider clsn;
	u8 fogTable[0x20];
	bool enableFog;
	u8 fogInfo;
	u16 fogOffset;
	u16 fogColor;
	u16 unk992;
	u8 unk994[0x20];
	u32 unk9b4;
	u32 unk9b8;
	Model* skyBox;
	u32 unk9c0;
	u32 unk9c4;
};

#endif