#include "SM64DS_2.h"
#include "Actors/CastleWater.h"

namespace
{
	using clpsBlock = StaticCLPS_Block<
		{ .isWater = true }
	>;
	
	char waterMatName[] = "water_mat";
	
	Fix12i waterScales[] = {0x1000_f};
	s16 waterRots[] = {0};
	Fix12i waterTranss[] = {0x00000000_f, 0x0000002e_f, 0x0000005b_f, 0x00000089_f,
							0x000000b6_f, 0x000000e4_f, 0x00000111_f, 0x0000013f_f,
							0x0000016c_f, 0x0000019a_f, 0x000001c7_f, 0x000001f5_f,
							0x00000222_f, 0x00000250_f, 0x0000027d_f, 0x000002ab_f,
							0x000002d8_f, 0x00000306_f, 0x00000333_f, 0x00000361_f,
							0x0000038e_f, 0x000003bc_f, 0x000003e9_f, 0x00000417_f,
							0x00000444_f, 0x00000472_f, 0x0000049f_f, 0x000004cd_f,
							0x000004fa_f, 0x00000528_f, 0x00000555_f, 0x00000583_f,
							0x000005b0_f, 0x000005de_f, 0x0000060b_f, 0x00000639_f,
							0x00000666_f, 0x00000694_f, 0x000006c1_f, 0x000006ef_f,
							0x0000071c_f, 0x0000074a_f, 0x00000777_f, 0x000007a5_f,
							0x000007d2_f, 0x00000800_f, 0x0000082e_f, 0x0000085b_f,
							0x00000889_f, 0x000008b6_f, 0x000008e4_f, 0x00000911_f,
							0x0000093f_f, 0x0000096c_f, 0x0000099a_f, 0x000009c7_f,
							0x000009f5_f, 0x00000a22_f, 0x00000a50_f, 0x00000a7d_f,
							0x00000aab_f, 0x00000ad8_f, 0x00000b06_f, 0x00000b33_f,
							0x00000b61_f, 0x00000b8e_f, 0x00000bbc_f, 0x00000be9_f,
							0x00000c17_f, 0x00000c44_f, 0x00000c72_f, 0x00000c9f_f,
							0x00000ccd_f, 0x00000cfa_f, 0x00000d28_f, 0x00000d55_f,
							0x00000d83_f, 0x00000db0_f, 0x00000dde_f, 0x00000e0b_f,
							0x00000e39_f, 0x00000e66_f, 0x00000e94_f, 0x00000ec1_f,
							0x00000eef_f, 0x00000f1c_f, 0x00000f4a_f, 0x00000f77_f,
							0x00000fa5_f, 0x00000fd2_f, 0x00001000_f};
							
	BTA_File::Animation waterAnims[] =
	{
		BTA_File::Animation
		{
			0,
			0, //probably just padding
			&waterMatName[0],
			1, //numScaleXs
			0, //scaleXOffset
			1, //numScaleYs
			0, //scaleYOffset
			1, //numRots
			0, //rotOffset
			0x5b, //numTransXs
			0, //transXOffset
			0x5b, //numTransYs
			0  //transYOffset
		}
	};
	
	BTA_File waterSRTDef
	{
		0x5b,
		&waterScales[0],
		&waterRots[0],
		&waterTranss[0],
		1,
		&waterAnims[0]
	};
	
	constexpr s32 NUM_MIST_PARTICLES = 7;
	
	const Vector3 mistPosVS[] =
	{
		{ -5330._f, -1070._f, -2400._f },
		{ -5130._f, -1070._f, -2610._f },
		{ -4970._f, -1070._f, -2840._f },
		{ -4850._f, -1070._f, -3090._f },
		{ -4740._f, -1070._f, -3340._f },
		{ -4710._f, -1070._f, -3610._f },
		{ -4750._f, -1070._f, -3890._f }
	};
	
	const Vector3 mistPosRegular[] =
	{
		{ -5810._f, -90._f, -2550._f },
		{ -5600._f, -90._f, -2770._f },
		{ -5440._f, -90._f, -3010._f },
		{ -5290._f, -90._f, -3260._f },
		{ -5200._f, -90._f, -3530._f },
		{ -5150._f, -90._f, -3820._f },
		{ -5150._f, -90._f, -4110._f }
	};
	
	const Vector3 mistPosDrained[] =
	{
		{ -5420._f, -800._f, -2430._f },
		{ -5200._f, -800._f, -2630._f },
		{ -5030._f, -800._f, -2860._f },
		{ -4900._f, -800._f, -3120._f },
		{ -4780._f, -800._f, -3380._f },
		{ -4780._f, -800._f, -3490._f },
		{ -4760._f, -800._f, -3670._f }
	};
}

SpawnInfo CastleWater::spawnData =
{
	[]() -> ActorBase* { return new CastleWater; },
	0x0152,
	0x0152,
	0,
	0._f,
	800._f,
	8000._f,
	80._f,
};

SharedFilePtr CastleWater::modelFile;
SharedFilePtr CastleWater::clsnFile;

s32 CastleWater::InitResources()
{
	// the moat was drained and the player is not in VS mode
	if (CURRENT_GAMEMODE != 1 && (SAVE_DATA.miscStates2 & 0x08) != 0)
		pos.y = -700._f;
	
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.BMD(), 1, 20);
	
	TextureTransformer::Prepare(*modelFile.BMD(), waterSRTDef);
	texSRT.SetFile(waterSRTDef, Animation::LOOP, 1._f, 0);
	
	Platform::UpdateModelPosAndRotY();
	Platform::UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.KCL(), clsnNextMat, 1._f, ang.y, clpsBlock::instance<>);
	clsn.range = 13000._f;
	clsn.Enable(this);
	
	Fix12i waterHeight = pos.y - 100._f;
	if (waterHeight < WATER_HEIGHT)
		WATER_HEIGHT = waterHeight;
	
	SpawnMistParticles();
	
	return 1;
}

s32 CastleWater::CleanupResources()
{
	modelFile.Release();
	clsnFile.Release();
	clsn.DisableIfEnabled();
	return 1;
}

s32 CastleWater::Behavior()
{
	texSRT.speed = 1._f;
	texSRT.Advance();
	return 1;
}

s32 CastleWater::Render()
{
	texSRT.Update(model.data);
	model.Render();
	return 1;
}

void CastleWater::SpawnMistParticles()
{
	const Vector3* mistPos;
	
	// VS mode
	if (CURRENT_GAMEMODE == 1)
	{
		if (pos.x > 0._f)
			return;
		
		mistPos = &mistPosVS[0];
	}
	else
	{
		// moat not drained
		if ((SAVE_DATA.miscStates2 & 0x08) == 0)
			mistPos = &mistPosRegular[0];
		else
			mistPos = &mistPosDrained[0];
	}
	
	for (s32 i = 0; i < NUM_MIST_PARTICLES; i++)
		Actor::Spawn(WATERFALL_MIST_ACTOR_ID, 0, mistPos[i], nullptr, areaID, -1);
}

CastleWater::CastleWater() {}
CastleWater::~CastleWater() {}