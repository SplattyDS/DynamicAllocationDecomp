#include "SM64DS_2.h"
#include "Actors/Flag.h"

SpawnInfo Flag::spawnData =
{
	[]() -> ActorBase* { return new Flag; },
	0x0156,
	0x0156,
	Actor::NO_BEHAVIOR_IF_OFF_SCREEN | Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UPDATE_DURING_CUTSCENE,
	200._f,
	200._f,
	12288._f,
	0._f,
};

SharedFilePtr Flag::modelFile;
SharedFilePtr Flag::animFile;

s32 Flag::InitResources()
{
	Model::LoadFile(modelFile);
	modelAnim.SetFile(modelFile.BMD(), 1, 0);
	
	Animation::LoadFile(animFile);
	modelAnim.SetAnim(animFile.BCA(), 0, 1._f, 0);
	
	return 1;
}

s32 Flag::CleanupResources()
{
	modelFile.Release();
	animFile.Release();
	return 1;
}

s32 Flag::Behavior()
{
	modelAnim.Advance();
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
	return 1;
}

s32 Flag::Render()
{
	modelAnim.Render();
	return 1;
}

Flag::Flag() {}
Flag::~Flag() {}