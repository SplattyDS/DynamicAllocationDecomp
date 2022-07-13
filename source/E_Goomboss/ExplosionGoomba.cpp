#include "ExplosionGoomba.h"

GloballySharedFilePtr ExplosionGoomba::animFile;
GloballySharedFilePtr ExplosionGoomba::modelFile;

SpawnInfo ExplosionGoomba::spawnData =
{
	[]() -> ActorBase* { return new ExplosionGoomba; },
	0x00c7,
	0x0017,
	0x24800002,
	0x00000000_f,
	0x00100000_f,
	0x03000000_f,
	0x03000000_f
};

s32 ExplosionGoomba::InitResources()
{
	Goomba* goomba = (Goomba*)Actor::Spawn(GOOMBA_ACTOR_ID, 0xffff, pos, nullptr, 0, -1);
	if (goomba == nullptr) Crash();
	MaterialDef& matDef = *goomba->vGetRegurgMaterialDef();
	goomba->MarkForDestruction();
	
	if (!modelAnim.SetFile(modelFile.GetFilePtr(), 1, 1))
		return 0;
	
	if (!shadow.InitCylinder())
		return 0;
	
	MaterialChanger::Prepare(modelFile.GetFilePtr(), matDef);
	matChg.SetMaterial(matDef, Animation::NO_LOOP, 0x1000_f, 0);
	modelAnim.SetAnim(animFile.GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	motionAng = ang;
	termVel = -0x3c000_f;
	// megaMushroomID = 0;
	wmClsn.Init(this, 0x14000_f, 0x14000_f, nullptr, nullptr);
	return 1;
}

s32 ExplosionGoomba::CleanupResources()
{
	modelFile.Release();
	animFile.Release();
	return 1;
}

s32 ExplosionGoomba::Behavior()
{
	if (!shouldBehave)
		return 1;
	
	if (DecIfAbove0_Short(stateTimer) != 0 && state < 3)
	{
		if (wmClsn.JustHitGround() != 0)
		{
			if ((flags & OFF_SCREEN) == 0)
			{
				if (state == 0)
					Sound::Play(3, 0x13a, camSpacePos);
				else
					Sound::Play(3, 0x13b, camSpacePos);
			}
			state++;
			speed.y = horzSpeed + 0xa000_f;
		}
		
		RaycastGround raycaster;
		raycaster.SetFlag_2();
		raycaster.SetFlag_8();
		raycaster.ClearFlag_1();
		raycaster.SetObjAndPos(Vector3{pos.x, pos.y + 0x190000_f, pos.z}, this);
		
		if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.isToxic
			&& raycaster.clsnPosY != -0x80000000_f && pos.y < raycaster.clsnPosY)
		{
			PoofDust();
			MarkForDestruction();
			return 1;
		}
		
		if (stateTimer < 0x60)
		{
			UpdatePos(nullptr);
			UpdateWMClsn(wmClsn, 0);
			ang.x += 0x1800;
		}
		
		shadowMat.c0.x = 0x1000_f;
		shadowMat.c0.y = 0x0_f;
		shadowMat.c0.z = 0x0_f;
		shadowMat.c1.x = 0x0_f;
		shadowMat.c1.y = 0x1000_f;
		shadowMat.c1.z = 0x0_f;
		shadowMat.c2.x = 0x0_f;
		shadowMat.c2.y = 0x0_f;
		shadowMat.c2.z = 0x1000_f;
		//shadowMat.c3.x = 0x0_f;
		//shadowMat.c3.y = 0x0_f;
		//shadowMat.c3.z = 0x0_f;
		
		shadowMat.c3 = pos >> 3;
		
		DropShadowRadHeight(shadow, shadowMat, 0x8c000_f, 0x3e8000_f, 0xf);
		return 1;
	}
	
	if ((flags & OFF_SCREEN) == 0)
		PoofDust();
	
	MarkForDestruction();
	return 1;
}

s32 ExplosionGoomba::Render()
{
	Vector3 posAsr3 = pos >> 3;
	Matrix4x3_FromTranslation(MATRIX_SCRATCH_PAPER, posAsr3.x, posAsr3.y, posAsr3.z);
	Matrix4x3_ConcatPos(MATRIX_SCRATCH_PAPER, 0x0_f, 0x6400_f, 0x0_f);
	Matrix4x3_ConcatAng(MATRIX_SCRATCH_PAPER, ang.x, ang.y, ang.z);
	Matrix4x3_ConcatPos(MATRIX_SCRATCH_PAPER, 0x0_f, -0x6400_f, 0x0_f);
	modelAnim.mat4x3 = MATRIX_SCRATCH_PAPER;
	
	if (!shouldRender)
		return 1;
	
	modelAnim.Render();
	matChg.Update(modelAnim.data);
	return 1;
}