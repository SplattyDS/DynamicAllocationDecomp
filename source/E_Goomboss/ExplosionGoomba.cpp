#include "SM64DS_2.h"
#include "Actors/ExplosionGoomba.h"
#include "Actors/Goomba.h"

SpawnInfo ExplosionGoomba::spawnData =
{
	[]() -> ActorBase* { return new ExplosionGoomba; },
	0x00c7,
	0x0017,
	Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UPDATE_WHEN_READING_SIGN | Actor::UPDATE_DURING_STAR_CUTSCENE | Actor::UPDATE_DURING_CUTSCENE,
	0._f,
	256._f,
	12288._f,
	12288._f,
};

GloballySharedFilePtr ExplosionGoomba::animFile;
GloballySharedFilePtr ExplosionGoomba::modelFile;

s32 ExplosionGoomba::InitResources()
{
	Goomba* goomba = (Goomba*)Actor::Spawn(GOOMBA_ACTOR_ID, 0xffff, pos, nullptr, 0, -1);
	if (goomba == nullptr)
		return 0;
	
	BMA_File& matDef = *goomba->vGetRegurgMaterialDef();
	goomba->MarkForDestruction();
	
	Model::LoadFile(modelFile);
	Animation::LoadFile(animFile);
	
	if (!modelAnim.SetFile(modelFile.BMD(), 1, 1))
		return 0;
	
	if (!shadow.InitCylinder())
		return 0;
	
	MaterialChanger::Prepare(*modelFile.BMD(), matDef);
	matChg.SetFile(matDef, Animation::NO_LOOP, 1._f, 0);
	
	modelAnim.SetAnim(animFile.BCA(), Animation::LOOP, 1._f, 0);
	
	motionAng = ang;
	termVel = -60._f;
	// megaMushroomID = 0;
	
	wmClsn.Init(this, 20._f, 20._f, nullptr, nullptr);
	
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
			if (!(flags & OFF_SCREEN))
			{
				if (state == 0)
					Sound::Play("NCS_SE_SCT_KRB_BOUND"sfx, camSpacePos);
				else
					Sound::Play("NCS_SE_SCT_KRB_BOUND_S"sfx, camSpacePos);
			}
			state++;
			speed.y = horzSpeed + 10._f;
		}
		
		RaycastGround raycaster;
		raycaster.SetFlag_2();
		raycaster.SetFlag_8();
		raycaster.ClearFlag_1();
		raycaster.SetObjAndPos(Vector3{ pos.x, pos.y + 400._f, pos.z }, this);
		
		if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.isToxic
			&& raycaster.clsnPosY != Fix12i::min && pos.y < raycaster.clsnPosY)
		{
			PoofDust();
			MarkForDestruction();
			return 1;
		}
		
		if (stateTimer < 96)
		{
			UpdatePos(nullptr);
			UpdateWMClsn(wmClsn, 0);
			ang.x += 33.75_deg;
		}
		
		shadowMat.c0.x = 1._f;
		shadowMat.c0.y = 0._f;
		shadowMat.c0.z = 0._f;
		shadowMat.c1.x = 0._f;
		shadowMat.c1.y = 1._f;
		shadowMat.c1.z = 0._f;
		shadowMat.c2.x = 0._f;
		shadowMat.c2.y = 0._f;
		shadowMat.c2.z = 1._f;
		//shadowMat.c3.x = 0._f;
		//shadowMat.c3.y = 0._f;
		//shadowMat.c3.z = 0._f;
		
		shadowMat.c3 = pos >> 3;
		
		DropShadowRadHeight(shadow, shadowMat, 140._f, 1000._f, 0xf);
		
		return 1;
	}
	
	if (!(flags & OFF_SCREEN))
		PoofDust();
	
	MarkForDestruction();
	
	return 1;
}

s32 ExplosionGoomba::Render()
{
	modelAnim.mat4x3 = Matrix4x3::Translation(pos >> 3);
	modelAnim.mat4x3.Translate(0._f, 6.25_f, 0._f);
	modelAnim.mat4x3.RotateZXY(ang.x, ang.y, ang.z);
	modelAnim.mat4x3.Translate(0._f, -6.25_f, 0._f);
	
	if (!shouldRender)
		return 1;
	
	modelAnim.Render();
	matChg.Update(modelAnim.data);
	
	return 1;
}

ExplosionGoomba::ExplosionGoomba() {}
ExplosionGoomba::~ExplosionGoomba() {}