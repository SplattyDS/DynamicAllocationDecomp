#include "SM64DS_2.h"
#include "Actors/MetalNet.h"

namespace
{
	using clpsBlock = StaticCLPS_Block<
		{  }
	>;
}

SpawnInfo MetalNet::spawnData =
{
	[]() -> ActorBase* { return new MetalNet; },
	0x0153,
	0x0153,
	Actor::NO_RENDER_IF_OFF_SCREEN,
	0._f,
	1280._f,
	4096._f,
	0._f,
};

SharedFilePtr MetalNet::modelFile;
SharedFilePtr MetalNet::clsnFile;

s32 MetalNet::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.BMD(), 1, 0);
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.KCL(), clsnNextMat, 1._f, ang.y, clpsBlock::instance<>);
	
	if ((param1 & 0xff) == 0xff)
	{
		// in the moat
		if (CURRENT_GAMEMODE != 1 && (SAVE_DATA.flags2 & 0x00080000) != 0)
			return 0;
	}
	else
	{
		// above the cannon
		if (CURRENT_GAMEMODE != 1 && NumStars() >+ 150)
			return 0;
	}
	
	return 1;
}

s32 MetalNet::CleanupResources()
{
	clsn.DisableIfEnabled();
	modelFile.Release();
	clsnFile.Release();
	return 1;
}

s32 MetalNet::Behavior()
{
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	if (CURRENT_GAMEMODE == 1)
		clsn.EnableIfDisabled(this);
	else
		IsClsnInRange(0._f, 0._f);
	
	return 1;
}

s32 MetalNet::Render()
{
	model.Render();
	return 1;
}

void MetalNet::OnPendingDestroy()
{
	return;
}

MetalNet::MetalNet() {}
MetalNet::~MetalNet() {}