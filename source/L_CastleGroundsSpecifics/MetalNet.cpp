#include "MetalNet.h"

namespace
{
	FixedSizeCLPS_Block<1> clpsBlock =	// 0x02112bf8
	{
		{'C', 'L', 'P', 'S'},
		0x0008,
		0x0001,
		{
			// low: 0x00000fc0, high: 0x000000ff
        	CLPS(0x0, 0, 0x3f, 0x0, 0x0, 0x0, 0, 0, 0, 0xff)
        }
	};
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
int MetalNet::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.filePtr, 1, 0);
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.filePtr, clsnNextMat, 0x1000_f, ang.y, (CLPS_Block&)clpsBlock);
	
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
int MetalNet::CleanupResources()
{
	if (clsn.IsEnabled())
		clsn.Disable();
	
	modelFile.Release();
	clsnFile.Release();
	
	return 1;
}

// 0x02111ed0
int MetalNet::Behavior()
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
int MetalNet::Render()
{
	model.Render();
	return 1;
}

// 0x02111ea4
void MetalNet::OnPendingDestroy()
{
	return;
}