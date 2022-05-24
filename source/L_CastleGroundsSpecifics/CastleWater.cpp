#include "CastleWater.h"

namespace
{
	FixedSizeCLPS_Block<1> clpsBlock =	// 0x02112c38
	{
		{'C', 'L', 'P', 'S'},
		0x0008,
		0x0001,
		{
			// low: 0x00000fe0, high: 0x000000ff
        	CLPS(0x0, 1, 0x3f, 0x0, 0x0, 0x0, 0, 0, 0, 0xff)
        }
	};
	
	const char waterMatName[] = "water_mat";	// 0x02112b7c
	
	Fix12i waterScales[] = {0x1000_f};	// 0x02112234
	short waterRots[] = {0};			// 0x0211222c
	Fix12i waterTranss[] = {0x00000000_f, 0x0000002e_f, 0x0000005b_f, 0x00000089_f, // 0x021122ec
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
							
	TexSRTAnim waterAnims[] =	// 0x02112238
	{
		TexSRTAnim
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
		
	TexSRTDef waterSRTDef // 0x02112bc4
	{
		0x5b,
		&waterScales[0],
		&waterRots[0],
		&waterTranss[0],
		1,
		&waterAnims[0]
	};
	
	constexpr int NUM_MIST_PARTICLES = 7;
	
	static Vector3 mistPosVS[] =		// 0x02113de0
	{
		Vector3{-0x014d2000_f, -0x0042e000_f, -0x00960000_f},
		Vector3{-0x0140a000_f, -0x0042e000_f, -0x00a32000_f},
		Vector3{-0x0136a000_f, -0x0042e000_f, -0x00b18000_f},
		Vector3{-0x012f2000_f, -0x0042e000_f, -0x00c12000_f},
		Vector3{-0x01284000_f, -0x0042e000_f, -0x00d0c000_f},
		Vector3{-0x01266000_f, -0x0042e000_f, -0x00e1a000_f},
		Vector3{-0x0128e000_f, -0x0042e000_f, -0x00f32000_f}
	};
	
	static Vector3 mistPosRegular[] =	// 0x02113d8c
	{
		Vector3{-0x016b2000_f, -0x0005a000_f, -0x009f6000_f},
		Vector3{-0x015e0000_f, -0x0005a000_f, -0x00ad2000_f},
		Vector3{-0x01540000_f, -0x0005a000_f, -0x00bc2000_f},
		Vector3{-0x014aa000_f, -0x0005a000_f, -0x00cbc000_f},
		Vector3{-0x01450000_f, -0x0005a000_f, -0x00dca000_f},
		Vector3{-0x0141e000_f, -0x0005a000_f, -0x00eec000_f},
		Vector3{-0x0141e000_f, -0x0005a000_f, -0x0100e000_f}
	};
	
	static Vector3 mistPosDrained[] =	// 0x02113e34
	{
		Vector3{-0x0152c000_f, -0x00320000_f, -0x0097e000_f},
		Vector3{-0x01450000_f, -0x00320000_f, -0x00a46000_f},
		Vector3{-0x013a6000_f, -0x00320000_f, -0x00b2c000_f},
		Vector3{-0x01324000_f, -0x00320000_f, -0x00c30000_f},
		Vector3{-0x012ac000_f, -0x00320000_f, -0x00d34000_f},
		Vector3{-0x012ac000_f, -0x00320000_f, -0x00da2000_f},
		Vector3{-0x01298000_f, -0x00320000_f, -0x00e56000_f}
	};
}

SharedFilePtr CastleWater::modelFile; // 0x02113c68
SharedFilePtr CastleWater::clsnFile; // 0x02113c70

SpawnInfo CastleWater::spawnData = // 0x021139f4
{
	[]() -> ActorBase* { return new CastleWater; }, // 0x02111d8c
	0x0152,
	0x0152,
	0x00000000,
	0x00000000_f,
	0x00320000_f,
	0x01f40000_f,
	0x00050000_f
};

// 0x02111c74
int CastleWater::InitResources()
{
	// the moat was drained and the player is not in VS mode
	if (CURRENT_GAMEMODE != 1 && (SAVE_DATA.miscStates2 & 0x08) != 0)
		pos.y = -0x2bc000_f;
	
	Model::LoadFile(modelFile);
	model.SetFile(modelFile.filePtr, 1, 0x14);
	
	TextureTransformer::Prepare(modelFile.filePtr, waterSRTDef);
	texSRT.SetTexSRT(waterSRTDef, Animation::LOOP, 0x1000_f, 0);
	
	Platform::UpdateModelPosAndRotY();
	Platform::UpdateClsnPosAndRot();
	
	MovingMeshCollider::LoadFile(clsnFile);
	clsn.SetFile(clsnFile.filePtr, clsnNextMat, 0x1000_f, ang.y, (CLPS_Block&)clpsBlock);
	clsn.Enable();
	
	Fix12i waterHeight = pos.y - 0x64000_f;
	if (waterHeight < WATER_HEIGHT)
		WATER_HEIGHT = waterHeight;
	
	SpawnMistParticles();
	return 1;
}

// 0x02111bd4
int CastleWater::CleanupResources()
{
	modelFile.Release();
	clsnFile.Release();
	
	if (clsn.IsEnabled())
		clsn.Disable();
	
	return 1;
}

// 0x02111c4c
int CastleWater::Behavior()
{
	texSRT.speed = 0x1000_f;
	texSRT.Advance();
	return 1;
}

// 0x02111c18
int CastleWater::Render()
{
	texSRT.Update(model.data);
	model.Render(nullptr);
	return 1;
}

// 0x02111b1c
void CastleWater::SpawnMistParticles()
{
	Vector3* mistPos;
	
	// VS mode
	if (CURRENT_GAMEMODE == 1)
	{
		if (0 < pos.x)
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
	
	for (int i = 0; i < NUM_MIST_PARTICLES; i++)
		Actor::Spawn(0xc5, 0, mistPos[i], nullptr, areaID, -1);
	
	return;
}