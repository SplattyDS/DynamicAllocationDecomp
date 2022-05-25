#include "Flag.h"

SharedFilePtr Flag::modelFile;	// 0x02113eb8
SharedFilePtr Flag::animFile;	// 0x02113eb0

SpawnInfo Flag::spawnData =		// 0x02113b7c
{
	[]() -> ActorBase* { return new Flag; }, // 0x021121f0
	0x0156,
	0x0156,
	0x20000003,
	0x000c8000_f,
	0x000c8000_f,
	0x03000000_f,
	0x00000000_f
};

// 0x02112190
int Flag::InitResources()
{
	Model::LoadFile(modelFile);
	modelAnim.SetFile(modelFile.filePtr, 1, 0);
	
	Animation::LoadFile(animFile);
	modelAnim.SetAnim(animFile.filePtr, 0, 0x1000_f, 0);
	
	return 1;
}

// 0x021120ec
int Flag::CleanupResources()
{
	modelFile.Release();
	animFile.Release();
	return 1;
}

// 0x02112144
int Flag::Behavior()
{
	modelAnim.Advance();
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
	return 1;
}

// 0x0211211c
int Flag::Render()
{
	modelAnim.Render();
	return 1;
}
