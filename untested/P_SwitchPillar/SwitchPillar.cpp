#include "SwitchPillar.h"

namespace
{
	// 0x02111cd0
	using clpsBlock = StaticCLPS_Block<
		{ .textureID = CLPS::TX_ROCK }					// low: 0x00000fc4, high: 0x000000ff
	>;
}

SharedFilePtr SwitchPillar::modelFile;
SharedFilePtr SwitchPillar::clsnFile;

SpawnInfo SwitchPillar::spawnData =
{
	[]() -> ActorBase* { return new SwitchPillar; },
	0x0022,
	0x00e4,
	0x00000002,
	0x00060000_f,
	0x00250000_f,
	0x01000000_f,
	0x00000000_f
};

int SwitchPillar::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.filePtr, 1, -1);
	
	if ((SAVE_DATA.miscStates2 & 0x08) != 0)
	{
		pos.y -= 0x64000_f;
		unk31e = true;
	}
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.filePtr, clsnNextMat, 0x199_f, ang.y, clpsBlock::instance<>);
	
	return 1;
}

int SwitchPillar::CleanupResources()
{
	clsn.Disable();
	modelFile.Release();
	clsnFile.Release();
	
	return 1;
}

int SwitchPillar::Behavior()
{
	IsClsnInRange(0x0_f);
	
	return 1;
}

int SwitchPillar::Render()
{
	model.Render(nullptr);
	
	return 1;
}

void SwitchPillar::OnGroundPounded(Actor& groundPounder)
{
	if (unk31e)
		return;
	
	pos.y -= 0x64000;
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	unk31e = true;
	
	SwitchPillar* otherPillar = (SwitchPillar*)Actor::FindWithActorID(SWITCH_PILLAR_ACTOR_ID, nullptr);
	if (otherPillar == nullptr)
		return;
	
	do
	{
		if (otherPillar != this)
		{
			if (otherPillar->unk31e) // both pillars need to be ground pounded to drain the moat
				SAVE_DATA.miscStates2 |= 0x08;
			
			return;
		}
		
		otherPillar = (SwitchPillar*)Actor::FindWithActorID(SWITCH_PILLAR_ACTOR_ID, otherPillar);
		
	} while (otherPillar != nullptr);
}