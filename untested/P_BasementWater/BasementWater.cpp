#include "BasementWater.h"

namespace
{
	// 0x02112c38
	using clpsBlock = StaticCLPS_Block<
		{ .isWater = true }					// low: 0x00000fe0, high: 0x000000ff
	>;
	
	const char waterMatName[] = "water_mat";	// 0x02112b7c
	
	Fix12i waterScales[] = {0x1000_f}; // 0x02111770
	s16 waterRots[] = {0}; // 0x02111768
	Fix12i waterTranss[] = {0x00000000_f, 0x0000002e_f, 0x0000005b_f, 0x00000089_f, // 0x0211191c
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
							
	TexSRTAnim waterAnims[] = // 0x02111778
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
		
	TexSRTDef waterSRTDef // 0x02111c24
	{
		0x5b,
		&waterScales[0],
		&waterRots[0],
		&waterTranss[0],
		1,
		&waterAnims[0]
	};
}

SharedFilePtr BasementWater::modelFile;
SharedFilePtr BasementWater::clsnFile;

SpawnInfo BasementWater::spawnData =
{
	[]() -> ActorBase* { return new BasementWater; },
	0x0023,
	0x00e5,
	0x00000000,
	0x00000000_f,
	0x01000000_f,
	0x00000000_f,
	0x00000000_f
};

int BasementWater::InitResources()
{
	Model::LoadFile(modelFile);
	MovingMeshCollider::LoadFile(clsnFile);
	
	model.SetFile(modelFile.filePtr, 1, 0x14);
	TextureTransformer::Prepare(modelFile.filePtr, waterSRTDef);
	texSRT.SetTexSRT(waterSRTDef, 0, 0x1000_f, 0);
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	clsn.SetFile(clsnFile.filePtr, clsnNextMat, 0x1000_f, ang.y, clpsBlock::instance<>);
	clsn.Enable();
	
	drainedPosY = pos.y - 0x4b0000_f;
	
	if ((SAVE_DATA.miscStates2 & 0x08) != 0)
		pos.y = drainedPosY;
	
	return 1;
}

int BasementWater::CleanupResources()
{
	if (clsn.IsEnabled())
		clsn.Disable();
	
	modelFile.Release();
	clsnFile.Release();
	
	return 1;
}

int BasementWater::Behavior()
{
	if (wasJustDrained)
		PlaySecretSound(*this, soundTimer); // 0x0200f8f8 (returns whether finished playing sound)
	
	if (drainedPosY < pos.y)
	{
		if ((SAVE_DATA.miscStates2 & 0x08) != 0)
		{
			soundID = Sound::PlayLong(soundID, 3, 0x96, camSpacePos, 0);
			pos.y -= 0x5000_f;
			wasJustDrained = true;
			
			if (pos.y <= drainedPosY)
			{
				pos.y = drainedPosY;
				Minimap::UpdateLevelSpecific(); // 0x020f99a8 (static Minimap function)
			}
		}
	}
	else
		pos.y = drainedPosY;
	
	WATER_HEIGHT = pos.y;
	
	UpdateModelPosAndRotY();
	UpdateClsnPosAndRot();
	
	texSRT.speed = 0x1000_f;
	texSRT.Advance();
	
	return 1;
}

int BasementWater::Render()
{
	texSRT.Update(model.data);
	model.Render(nullptr);
	
	return 1;
}