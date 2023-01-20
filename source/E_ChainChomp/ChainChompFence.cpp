#include "SM64DS_2.h"
#include "Actors/ChainChompFence.h"

namespace
{
	using clpsBlock = StaticCLPS_Block<
		{ .behaviorID = CLPS::BH_VANISH_LUIGI_GRATE, .camGoesThru = true, }
	>;
}

SpawnInfo ChainChompFence::spawnData =
{
	[]() -> ActorBase* { return new ChainChompFence; },
	0x0029,
	0x0044,
	Actor::NO_RENDER_IF_OFF_SCREEN,
	256._f,
	2048._f,
	8192._f,
	0._f,
};

SharedFilePtr ChainChompFence::modelFile;
SharedFilePtr ChainChompFence::clsnFile;

s32 ChainChompFence::InitResources()
{
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.BMD(), 1, -1);
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	MeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.KCL(), clsnNextMat, 1._f, ang.y, clpsBlock::instance<>);
	
	return 1;
}

s32 ChainChompFence::CleanupResources()
{
	clsn.DisableIfEnabled();
	modelFile.Release();
	clsnFile.Release();
	return 1;
}

s32 ChainChompFence::Behavior()
{
	if (!killed)
		IsClsnInRange(0._f, 0._f);
	
	return 1;
}

s32 ChainChompFence::Render()
{
	if (!killed)
		model.Render();
	
	return 1;
}

void ChainChompFence::KillByChainChomp()
{
	Sound::Play("NCS_SE_SCT_WALLCRASH"sfx, camSpacePos);
	
	Vector3 pPos = { pos.x, pos.y + 300._f, pos.z };
	Particle::System::NewSimple(0x1e, pPos.x, pPos.y, pPos.z);
	PoofDustAt(pPos);
	
	killed = true;
	
	clsn.DisableIfEnabled();
}

ChainChompFence::ChainChompFence() {}
ChainChompFence::~ChainChompFence() {}