#include "PeachPainting.h"

SharedFilePtr PeachPainting::modelFile;

SpawnInfo PeachPainting::spawnData =
{
	[]() -> ActorBase* { return new PeachPainting; },
	0x0026,
	0x0145,
	0x00000000,
	0x00000000_f,
	0x00001000_f,
	0x00000000_f,
	0x00000000_f
};

int PeachPainting::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.filePtr, 1, -1);
	
	opacity = 0xff;
	UpdateModelTransform();
	
	return 1;
}

int PeachPainting::CleanupResources()
{
	modelFile.Release();
	return 1;
}

int PeachPainting::Behavior()
{
	Fix12i distToPlayer = DistToCPlayer();
	
	if (distToPlayer < 0xe10000_f)
	{
		if (distToPlayer < 0xbf4001_f)
			opacity = 0x0;
		else
			opacity = (distToPlayer - 0xbf4000_f / 0x21c000_f) * 0xff_f >> 3;
	}
	else
		opacity = 0xff;
	
	
	model.ApplyOpacity(opacity); // 0x02016a9c, has an unused second parameter?
	
	return 1;
}

int PeachPainting::Render()
{
	if (opacity != 0)
		model.Render(nullptr);
	
	return 1;
}

void PeachPainting::UpdateModelTransform()
{
	Matrix4x3_FromRotationY(model.mat4x3, ang.y);
	model.mat4x3.c3 = pos >> 3;
}