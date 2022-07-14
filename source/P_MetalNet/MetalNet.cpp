#include "MetalNet.h"

namespace
{
	// 0x02112bf8
	using clpsBlock = StaticCLPS_Block<
		{  }								// low: 0x00000fc0, high: 0x000000ff
	>;
}

SharedFilePtr MetalNet::modelFile;	// 0x02113e90
SharedFilePtr MetalNet::clsnFile;	// 0x02113e88

SpawnInfo MetalNet::spawnData = // 0x02113abc
{
	[]() -> ActorBase* { return new MetalNet; }, // 0x02112048
	0x0153,
	0x0153,
	0x00000002,
	0x00000000_f,
	0x00500000_f,
	0x01000000_f,
	0x00000000_f
};

// 0x02111f40
s32 MetalNet::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.filePtr, 1, 0);
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.filePtr, clsnNextMat, 0x1000_f, ang.y, clpsBlock::instance<>);
	
	if ((param1 & 0xff) == 0xff)
	{
		// in the moat
		if (CURRENT_GAMEMODE != 1 && (SAVE_DATA.miscStates2 & 0x08) != 0)
			return 0;
	}
	else
	{
		// above the cannon
		if (CURRENT_GAMEMODE != 1 && 149 < NumStars())
			return 0;
	}
	
	return 1;
}

// 0x02111e60
s32 MetalNet::CleanupResources()
{
	if (clsn.IsEnabled())
		clsn.Disable();
	
	modelFile.Release();
	clsnFile.Release();
	
	return 1;
}

// 0x02111ed0
s32 MetalNet::Behavior()
{
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	if (CURRENT_GAMEMODE == 1)
	{
		if (!clsn.IsEnabled())
			clsn.Enable();
	}
	else
	{
		IsClsnInRange(0x0_f, 0x0_f);
	}
	
	return 1;
}

// 0x02111ea8
s32 MetalNet::Render()
{
	model.Render();
	return 1;
}

// 0x02111ea4
void MetalNet::OnPendingDestroy()
{
	return;
}