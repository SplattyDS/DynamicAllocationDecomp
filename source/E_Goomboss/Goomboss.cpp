#include "Goomboss.h"
#include "ExplosionGoomba.h"

namespace
{
	const char faceMatName[] = "mat_face";  // 0x021123a4
	const char lEyeMatName[] = "mat_eye_l"; // 0x021123b0
	const char rEyeMatName[] = "mat_eye_r"; // 0x021123bc
	
	char faceMatVals[] = { // 0x0211194c
		// difRed
		0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
		0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b,
		0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
		0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d,
		0x1d, 0x1d, 0x1d, 0x1d, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e,
		0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
		// difGreen
		0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0a, 0x0a,
		0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06,
		0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
		// difBlue
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// ambRed
		0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09,
		0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0d,
		0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x11, 0x11, 0x11, 0x11, 0x12, 0x12, 0x12, 0x12, 0x12, 0x13, 0x13, 0x13, 0x13, 0x13,
		0x14, 0x14, 0x14, 0x14, 0x14, 0x15, 0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x16, 0x16, 0x17, 0x17,
		0x17, 0x17, 0x17, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x19,
		// ambGreen
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05,
		0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// ambBlue
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05,
		0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	MaterialProperties faceMatProps = // 0x02111384
	{
		(s16)0xffff, 0,
		&faceMatName[0],
		0x01, true,  0x0000,    0x01, true,  0x005a,    0x01, true,  0x00b4, 
		0x01, true,  0x010e,    0x01, true,  0x0168,    0x01, true,  0x01c2,  
		0x01, false, 0x00b0,    0x01, false, 0x00b0,    0x01, false, 0x00b0, 
		0x01, false, 0x00b0,    0x01, false, 0x00b0,    0x01, false, 0x00b0, 
		0x01, false, 0x0052, 
	};
	MaterialDef unkMat = {0x005a, 0x0000, &faceMatVals[0], 1, &faceMatProps}; // 0x021123f4
	
	Fix12i texScales[7][1] = 
	{
		// 0x021111d8
		{ 0x1000_f },
		// 0x021111d0
		{ 0x1000_f },
		// 0x021111dc
		{ 0x1000_f },
		// 0x021111c8
		{ 0x1000_f },
		// 0x021111c0
		{ 0x1000_f },
		// 0x021111d4
		{ 0x1000_f },
		// 0x021111c4
		{ 0x1000_f }
	};
	
	s16 texRots[7][1] =
	{
		// 0x021111a4
		{ 0 },
		// 0x021111a8
		{ 0 },
		// 0x021111b0
		{ 0 },
		// 0x021111a0
		{ 0 },
		// 0x021111bc
		{ 0 },
		// 0x021111b8
		{ 0 },
		// 0x021111ac
		{ 0 }
	};
	
	// 0x02111b68
	Fix12i texTranss0[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000008f_f,
		 0x0000009e_f,  0x0000103e_f,  0x0000009e_f, -0x0000008f_f,
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000008f_f,
		 0x0000009e_f,  0x0000103e_f,  0x0000009e_f, -0x0000008f_f,
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000008f_f,
		 0x0000009e_f,  0x0000103e_f,  0x0000009e_f, -0x0000008f_f,
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000008f_f,
		 0x0000009e_f,  0x0000103e_f,  0x0000009e_f, -0x0000008f_f,
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000009e_f,
		-0x0000008f_f, -0x0000102f_f, -0x0000008f_f,  0x0000009e_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000009e_f,
		-0x0000008f_f, -0x0000102f_f, -0x0000008f_f,  0x0000009e_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000009e_f,
		-0x0000008f_f, -0x0000102f_f, -0x0000008f_f,  0x0000009e_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000009e_f,
		-0x0000008f_f, -0x0000102f_f, -0x0000008f_f,  0x0000009e_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f
	};
	
	// 0x021115ec
	Fix12i texTranss1[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x0000009e_f, -0x0000008f_f, -0x0000102f_f, -0x0000008f_f,
		 0x0000009e_f,  0x0000103e_f,  0x000010c4_f,  0x00000000_f,
		-0x000010b5_f, -0x0000102f_f, -0x000010e8_f, -0x000000e9_f,
		 0x000000f8_f,  0x000010f7_f,  0x0000103e_f,  0x000010ea_f,
		 0x00001042_f,  0x00000076_f, -0x00000067_f, -0x00001033_f,
		-0x000010db_f, -0x0000102f_f, -0x0000109c_f, -0x000010b5_f,
		-0x0000000c_f,  0x00000000_f,  0x0000001b_f,  0x000010c4_f,
		 0x000010ab_f,  0x0000103e_f,  0x0000108c_f,  0x000010f7_f,
		 0x00001031_f,  0x000000f8_f,  0x00000000_f, -0x000000e9_f,
		-0x00001022_f, -0x000010e8_f, -0x0000107d_f, -0x0000102f_f,
		
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x0000008f_f,  0x0000009e_f,  0x0000103e_f,  0x0000009e_f,
		-0x0000008f_f, -0x0000102f_f, -0x000010b5_f,  0x00000000_f,
		 0x000010c4_f,  0x0000103e_f,  0x000010f7_f,  0x000000f8_f,
		-0x000000e9_f, -0x000010e8_f, -0x0000102f_f, -0x000010db_f,
		-0x00001033_f, -0x00000067_f,  0x00000076_f,  0x00001042_f,
		 0x000010ea_f,  0x0000103e_f,  0x000010ab_f,  0x000010c4_f,
		 0x0000001b_f,  0x00000000_f, -0x0000000c_f, -0x000010b5_f,
		-0x0000109c_f, -0x0000102f_f, -0x0000107d_f, -0x000010e8_f,
		-0x00001022_f, -0x000000e9_f,  0x00000000_f,  0x000000f8_f,
		 0x00001031_f,  0x000010f7_f,  0x0000108c_f,  0x0000103e_f
	};
	
	// 0x02111750
	Fix12i texTranss2[] =
	{
		0x00000000_f,
		
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000102f_f, -0x0000102f_f,
		-0x0000102f_f, -0x0000102f_f, -0x0000008f_f,  0x0000009e_f,
		 0x0000103e_f,  0x0000009e_f, -0x0000008f_f, -0x0000102f_f,
		-0x000010b5_f,  0x00000010_f,  0x000010d4_f,  0x0000103e_f,
		 0x000010c4_f,  0x00000000_f, -0x000010b5_f, -0x0000102f_f,
		-0x000010ae_f, -0x0000101d_f, -0x000010ba_f, -0x00001087_f,
		-0x000010c3_f, -0x0000008f_f, -0x000000da_f, -0x000000f5_f,
		 0x00000000_f,  0x00000005_f,  0x000000e9_f,  0x0000009e_f,
		 0x000010d2_f,  0x00001096_f,  0x000010c9_f,  0x0000102c_f,
		 0x000010bd_f,  0x0000103e_f,  0x000010dd_f,  0x000010bc_f,
		 0x000010ea_f,  0x00001088_f,  0x00001095_f,  0x00001042_f,
		 0x0000009e_f,  0x000000aa_f,  0x00000076_f,  0x00000032_f,
		-0x00000013_f, -0x00000067_f, -0x0000008b_f, -0x0000008f_f,
		-0x00001033_f, -0x00001086_f, -0x00001069_f,
		
		-0x000010db_f, -0x000010ad_f, -0x000010ce_f, -0x0000102f_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000103e_f,  0x0000103e_f,
		 0x0000103e_f,  0x0000103e_f,  0x0000009e_f, -0x0000008f_f,
		-0x0000102f_f, -0x0000008f_f,  0x0000009e_f,  0x0000103e_f,
		 0x000010c4_f, -0x00000001_f, -0x000010c5_f, -0x0000102f_f,
		-0x000010b5_f,  0x00000000_f,  0x000010c4_f,  0x0000103e_f,
		 0x000010cd_f,  0x0000105c_f,  0x0000103a_f,  0x00001057_f,
		 0x000010e3_f,  0x000000ff_f,  0x000000ab_f,  0x00000027_f,
		 0x00000062_f, -0x00000053_f, -0x00000018_f, -0x0000009c_f,
		-0x000000f0_f, -0x000010d4_f, -0x00001048_f, -0x0000102b_f,
		-0x0000104d_f, -0x000010be_f, -0x0000102f_f, -0x000010be_f,
		-0x0000107d_f, -0x0000108b_f, -0x000010e8_f, -0x000010b5_f,
		-0x00001022_f, -0x0000002e_f, -0x000000e9_f, -0x00000079_f,
		 0x00000000_f,  0x00000084_f,  0x000000f8_f,  0x0000003d_f,
		 0x00001031_f,  0x000010c4_f,  0x000010f7_f,  0x0000109a_f,
		 0x0000108c_f,  0x000010cd_f,  0x0000103e_f
	};
	
	// 0x021113c0
	Fix12i texTranss3[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f,  0x000000eb_f,  0x00003006_f,  0x000000eb_f,
		-0x0000102f_f,  0x000000eb_f,  0x00003006_f,
		
		 0x000000eb_f,  0x000030b6_f,  0x00000097_f, -0x00002098_f,
		 0x00000097_f,  0x000030b6_f,  0x00000097_f
	};
	
	// 0x021114f8
	Fix12i texTranss4[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f, -0x00001066_f, -0x00000081_f,  0x00001068_f,
		 0x0000204d_f,  0x00003006_f,  0x00003051_f,  0x00002055_f,
		 0x000010e4_f,  0x000000f2_f, -0x0000007e_f, -0x0000108a_f,
		-0x0000102f_f, -0x0000108a_f, -0x0000007e_f,  0x00000003_f,
		 0x000010f4_f,  0x00002065_f,  0x00003061_f,  0x00003006_f,
		 0x00002010_f, -0x00000069_f, -0x0000102f_f, -0x00001066_f,
		-0x00000081_f,  0x00001068_f,  0x0000204d_f,  0x00003006_f,
		 0x00002030_f, -0x00000059_f,
		
		 0x000030b6_f,  0x000020ec_f,  0x00001085_f, -0x00000067_f,
		-0x000010ce_f, -0x00002098_f, -0x00002053_f, -0x000010e5_f,
		-0x00000073_f,  0x00001091_f,  0x00002004_f,  0x00003081_f,
		 0x000030b6_f,  0x00003081_f,  0x00002004_f,  0x00001091_f,
		-0x00000083_f, -0x000010f5_f, -0x00002063_f, -0x00002098_f,
		-0x000000ff_f,  0x0000105e_f,  0x000030b6_f,  0x000020ec_f,
		 0x00001085_f, -0x00000067_f, -0x000010ce_f, -0x00002098_f,
		-0x00000030_f,  0x0000104e_f
	};
	
	// 0x02112098
	Fix12i texTranss5[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f, -0x000010de_f, -0x000010dd_f, -0x0000103c_f,
		-0x0000100a_f, -0x00001077_f, -0x00001064_f, -0x00001001_f,
		-0x0000006d_f, -0x00000089_f, -0x00000075_f, -0x00000051_f,
		 0x000000c3_f,  0x000000e7_f,  0x000000fb_f,  0x000000df_f,
		 0x00001073_f,  0x000010d6_f,  0x000010d9_f,  0x0000107c_f,
		 0x0000109e_f,  0x00002030_f,  0x00002031_f,  0x00002091_f,
		 0x00002081_f,  0x00002051_f,  0x000020f0_f,  0x00002080_f,
		 0x000010ff_f,  0x0000104f_f,  0x0000108e_f,  0x000010ad_f,
		 0x000010ac_f,  0x0000109b_f,  0x0000107a_f,  0x00001039_f,
		 0x000010e7_f,  0x00001096_f,  0x00001025_f,  0x000010a3_f,
		 0x00001022_f,  0x00001090_f,  0x000000fe_f,  0x0000005d_f,
		 0x000000ab_f,  0x0000000a_f,  0x00000058_f,  0x00000096_f,
		 0x000000e4_f,  0x00000033_f,  0x00000081_f, -0x00000020_f,
		-0x000000d2_f, -0x00000074_f, -0x00000016_f, -0x000000a7_f,
		-0x00000029_f, -0x000000aa_f, -0x0000001c_f, -0x0000006d_f,
		-0x000000be_f, -0x000000ff_f, -0x00001011_f, -0x00001032_f,
		-0x00001023_f, -0x00001014_f, -0x000010f4_f, -0x000010d5_f,
		-0x000010a6_f, -0x00001067_f, -0x00001028_f, -0x000010d8_f,
		-0x00001079_f, -0x0000101a_f, -0x000010ba_f, -0x0000103b_f,
		-0x000010cb_f, -0x0000103c_f, -0x000010ac_f, -0x0000101d_f,
		-0x0000107d_f, -0x000010cd_f, -0x0000101e_f, -0x0000105e_f,
		-0x0000108e_f, -0x000010be_f, -0x000010ee_f, -0x0000100f_f,
		-0x0000101f_f, -0x0000102f_f,
		
		 0x0000103e_f,  0x000010ed_f,  0x000010ec_f,  0x0000104b_f,
		 0x00001019_f,  0x00001086_f,  0x00001073_f,  0x00001010_f,
		 0x0000007c_f,  0x00000098_f,  0x00000084_f,  0x00000060_f,
		-0x000000b4_f, -0x000000d8_f, -0x000000ec_f, -0x000000d0_f,
		-0x00001064_f, -0x000010c7_f, -0x000010ca_f, -0x0000106d_f,
		-0x0000108f_f, -0x00002021_f, -0x00002022_f, -0x00002082_f,
		-0x00002070_f, -0x00002042_f, -0x000020e1_f, -0x00002071_f,
		-0x000010f0_f, -0x00001040_f, -0x0000107f_f, -0x0000109e_f,
		-0x0000109d_f, -0x0000108c_f, -0x0000106b_f, -0x0000102a_f,
		-0x000010d8_f, -0x00001087_f, -0x00001016_f, -0x00001094_f,
		-0x00001013_f, -0x00001081_f, -0x000000ef_f, -0x0000004e_f,
		-0x0000009c_f, -0x000000fa_f, -0x00000049_f, -0x00000087_f,
		-0x000000d5_f, -0x00000024_f, -0x00000070_f,  0x00000030_f,
		 0x000000e1_f,  0x00000083_f,  0x00000025_f,  0x000000b6_f,
		 0x00000038_f,  0x000000b9_f,  0x0000002b_f,  0x0000007c_f,
		 0x000000cd_f,  0x0000000f_f,  0x00001020_f,  0x00001041_f,
		 0x00001032_f,  0x00001023_f,  0x00001004_f,  0x000010e4_f,
		 0x000010b5_f,  0x00001076_f,  0x00001037_f,  0x000010e7_f,
		 0x00001088_f,  0x00001029_f,  0x000010c9_f,  0x0000104a_f,
		 0x000010da_f,  0x0000104b_f,  0x000010bb_f,  0x0000102c_f,
		 0x0000108c_f,  0x000010dc_f,  0x0000102d_f,  0x0000106d_f,
		 0x0000109d_f,  0x000010cd_f,  0x000010fd_f,  0x0000101e_f,
		 0x0000102e_f,  0x0000103e_f
	};
	
	// 0x02111404
	Fix12i texTranss6[] =
	{
		 0x00000000_f,
		
		-0x0000102f_f, -0x0000101e_f, -0x0000101b_f, -0x00001086_f,
		-0x000000d0_f, -0x0000002a_f, -0x000000f2_f,  0x00000065_f,
		 0x0000008c_f,  0x00001033_f,  0x000010f8_f,  0x0000108d_f,
		 0x00002080_f,  0x00002091_f,  0x000020f0_f,  0x0000102f_f,
		 0x0000105c_f,  0x000010a8_f,  0x00001044_f,  0x0000005f_f,
		 0x0000000a_f,  0x00000084_f, -0x00000012_f, -0x000000a7_f,
		-0x000000fc_f, -0x000010d1_f, -0x00001036_f, -0x000010e9_f,
		-0x000010bc_f, -0x0000108e_f,
		
		 0x0000103e_f,  0x0000102d_f,  0x0000102a_f,  0x00001095_f,
		 0x000000df_f,  0x00000039_f,  0x00000002_f, -0x00000056_f,
		-0x0000007d_f, -0x00001024_f, -0x000010e9_f, -0x0000107e_f,
		-0x00002071_f, -0x00002082_f, -0x000020e1_f, -0x00001020_f,
		-0x0000104d_f, -0x00001099_f, -0x00001035_f, -0x00000050_f,
		-0x000000fa_f, -0x00000075_f,  0x00000021_f,  0x000000b6_f,
		 0x0000000c_f,  0x000010e0_f,  0x00001045_f,  0x000010f8_f,
		 0x000010cb_f,  0x0000109d_f
	};
	
	TexSRTAnim texAnims[7][2] =
	{
		{
			TexSRTAnim // 0x02111314
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1, //numScaleXs
				0, //scaleXOffset
				1, //numScaleYs
				0, //scaleYOffset
				1, //numRots
				0, //rotOffset
				1, //numTransXs
				0, //transXOffset
				0x4b, //numTransYs
				1  //transYOffset
			},
			TexSRTAnim // 0x02111330
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x4b,
				0x4c
			}
		},
		{
			TexSRTAnim // 0x02111234
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x2c,
				1
			},
			TexSRTAnim // 0x02111250
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x2c,
				0x2d
			}
		},
		{
			TexSRTAnim // 0x02111234
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x3f,
				1
			},
			TexSRTAnim // 0x02111234
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x3f,
				0x40
			}
		},
		{
			TexSRTAnim // 0x021112dc
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				8,
				1
			},
			TexSRTAnim // 0x021112f8
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				8,
				9
			}
		},
		{
			TexSRTAnim // 0x0211126c
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x1e,
				1
			},
			TexSRTAnim // 0x02111288
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x1e,
				0x1f
			}
		},
		{
			TexSRTAnim // 0x021111fc
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x5a,
				1
			},
			TexSRTAnim // 0x02111218
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x5a,
				0x5b
			}
		},
		{
			TexSRTAnim // 0x0211134c
			{
				0xffff,
				0,
				&lEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x1e,
				1
			},
			TexSRTAnim // 0x02111368
			{
				0xffff,
				0,
				&rEyeMatName[0],
				1,
				0,
				1,
				0,
				1,
				0,
				1,
				0,
				0x1e,
				0x1f
			}
		}
	};
	
	TexSRTDef texSRTDefs[] = 
	{
		TexSRTDef // 0x02112404
		{
			0x0000004b,
			&texScales[0][0], // 0x021111d8
			&texRots[0][0],   // 0x021111a4
			&texTranss0[0], // 0x02111b68
			0x00000002,
			&texAnims[0][0]   // 0x02111314
		},
		TexSRTDef // 0x0211244c
		{
			0x0000002c,
			&texScales[1][0], // 0x021111d0
			&texRots[1][0],   // 0x021111a8
			&texTranss1[0], // 0x021115ec
			0x00000002,
			&texAnims[1][0]   // 0x02111234
		},
		TexSRTDef // 0x02112494
		{
			0x0000003f,
			&texScales[2][0], // 0x021111dc
			&texRots[2][0],   // 0x021111b0
			&texTranss2[0], // 0x02111750
			0x00000002,
			&texAnims[2][0]   // 0x021112a4
		},
		TexSRTDef // 0x021124c4
		{
			0x00000008,
			&texScales[3][0], // 0x021111c8
			&texRots[3][0],   // 0x021111a0
			&texTranss3[0], // 0x021113c0
			0x00000002,
			&texAnims[3][0]   // 0x021112dc
		},
		TexSRTDef // 0x02112464
		{
			0x0000001e,
			&texScales[4][0], // 0x021111c0
			&texRots[4][0],   // 0x021111bc
			&texTranss4[0], // 0x021114f8
			0x00000002,
			&texAnims[4][0]   // 0x0211126c
		},
		TexSRTDef // 0x02112434
		{
			0x0000005a,
			&texScales[5][0], // 0x021111d4
			&texRots[5][0],   // 0x021111b8
			&texTranss5[0], // 0x02112098
			0x00000002,
			&texAnims[5][0]   // 0x021111fc
		},
		TexSRTDef // 0x021124ac
		{
			0x0000001e,
			&texScales[6][0], // 0x021111c4
			&texRots[6][0],   // 0x021111ac
			&texTranss6[0], // 0x02111404
			0x00000002,
			&texAnims[6][0]   // 0x0211134c
		}
	};
	
	
	/*TexSRTDef* texDefArr[] =
	{
		&texSRTDefs[0],// 0x02112404
		&texSRTDefs[0],// 0x0211244c
		&texSRTDefs[0],// 0x02112494
		&texSRTDefs[0],// 0x021124c4
		&texSRTDefs[0],// 0x02112464
		&texSRTDefs[0],// 0x02112434
		&texSRTDefs[0] // 0x021124ac
	};*/
	
	GoombossAnim animations[] = // 0x02122f34
	{
		GoombossAnim{ Goomboss::animFiles[Goomboss::ANGER],        texSRTDefs[0], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::DAMAGE_BACK],  texSRTDefs[1], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::DAMAGE_FRONT], texSRTDefs[1], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::DOWN_START],   texSRTDefs[4], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::DOWN],         texSRTDefs[3], Animation::LOOP    },
		GoombossAnim{ Goomboss::animFiles[Goomboss::SERCH_WAIT],   texSRTDefs[5], Animation::LOOP    },
		GoombossAnim{ Goomboss::animFiles[Goomboss::TURN],         texSRTDefs[6], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::WAIT],         texSRTDefs[6], Animation::LOOP    },
		GoombossAnim{ Goomboss::animFiles[Goomboss::WALK],         texSRTDefs[6], Animation::LOOP    },
		GoombossAnim{ Goomboss::animFiles[Goomboss::WALK_END],     texSRTDefs[6], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::WALK_START],   texSRTDefs[6], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::SPAWN],        texSRTDefs[0], Animation::NO_LOOP },
		GoombossAnim{ Goomboss::animFiles[Goomboss::WAIT],         texSRTDefs[6], Animation::NO_LOOP },
	};
	
	struct State
	{
		using FuncPtr = void(Goomboss::*)();
		
		FuncPtr init;
		FuncPtr main;
	};
	
	const State states[]
	{
		State{ &Goomboss::State0_Init, &Goomboss::State0_Main },
		State{ &Goomboss::State1_Init, &Goomboss::State1_Main },
		State{ &Goomboss::State2_Init, &Goomboss::State2_Main },
		State{ &Goomboss::State3_Init, &Goomboss::State3_Main },
		State{ &Goomboss::State4_Init, &Goomboss::State4_Main },
		State{ &Goomboss::State5_Init, &Goomboss::State5_Main },
		State{ &Goomboss::State6_Init, &Goomboss::State6_Main },
		State{ &Goomboss::State7_Init, &Goomboss::State7_Main },
		State{ &Goomboss::State8_Init, &Goomboss::State8_Main }
	};
	
	//const float GOOMBOSS_SCALES[] = { 12288.0f, 9557.0f, 6826.0f, 4096.0f };				// 0x02122e4c (why use floats Nintendo...)
	const Fix12i GOOMBOSS_SCALES[]        = { 0x3000_f, 0x2555_f, 0x1aaa_f, 0x1000_f };		// same as above, but converted to Fix12i
	const s16 MATERIAL_CHANGER_FRAMES[]   = { 0x0059,   0x003c,   0x001e,   0x0001 };		// 0x02122e04
	const s16 MAX_WALK_SPEEDS[]           = { 0x0000,   0x00d0,   0x0080,   0x0050 };		// 0x02122dfc
	const Fix12i EARTHQUAKE_MAGNITUDES[]  = { 0x0_f, 0x320000_f, 0x258000_f, 0x190000_f};	// 0x0212290c
	const Fix12i ANIM_SPEED_DENOMINATOR[] = { 0x0_f, 0x0_f,      0x70000_f,  0x0_f};		// 0x0212291c
	const u8 NUM_GOOMBAS_TO_SPAWN[]       = { 16, 9, 6, 3 };								// 0x02122d80
}

// replace this when the keys have been decompiled
asm("LoadKeyModels = 0x02131114");
asm("UnloadKeyModels = 0x021310cc");
extern "C" void LoadKeyModels(u32 keyID);
extern "C" void UnloadKeyModels(u32 keyID);

GloballySharedFilePtr Goomboss::modelFile;
GloballySharedFilePtr Goomboss::texSeqFile;
GloballySharedFilePtr Goomboss::animFiles[NUM_ANIMS];
GloballySharedFilePtr Goomboss::goombaModelFile;
GloballySharedFilePtr Goomboss::goombaAnimFiles[Goomba::NUM_ANIMS];

SpawnInfo Goomboss::spawnData =
{
	[]() -> ActorBase* { return new Goomboss; },
	0x00c6,
	0x0016,
	0x34800000,
	0x00000000_f,
	0x00100000_f,
	0x03000000_f,
	0x03000000_f
};

s32 Goomboss::InitResources()
{
	Model::LoadFile(SUPER_MUSHROOM_MODEL_PTR);
	
	LoadKeyModels(2);
	
	Model::LoadFile(goombaModelFile.Get());
	
	for (s32 i = 0; i < Goomba::NUM_ANIMS; i++)
		Animation::LoadFile(goombaAnimFiles[i].Get());
	
	for (s32 i = 0; i < NUM_ANIMS; i++)
		Animation::LoadFile(animFiles[i].Get());
	
	TextureSequence::LoadFile(texSeqFile.Get());
	Model::LoadFile(modelFile.Get());
	modelAnim.SetFile(modelFile.GetFilePtr(), 1, -1);
	
	for (s32 i = 0; i < 3; i++)
		shadows[i].InitCylinder();
	
	health = 3;
	scale.x = scale.y = scale.z = GOOMBOSS_SCALES[health];
	
	vertAccel = -0xa000_f;
	termVel = -0x3c000_f;
	originalPos = pos;
	
	for (s32 i = 0; i < 4; i++)
		cylClsns[i].Init(this, pos, scale.x * 10, scale.y * 10, 0x200004, 0x26fe0);
	
	modelAnim.SetAnim(animFiles[WAIT].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	TextureSequence::Prepare(modelFile.GetFilePtr(), texSeqFile.GetFilePtr());
	MaterialChanger::Prepare(modelFile.GetFilePtr(), unkMat);
	
	for (s32 i = 0; i < 7; i++)
		TextureTransformer::Prepare(modelFile.GetFilePtr(), texSRTDefs[i]);
	
	texSeq.SetFile(texSeqFile.GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	matChg.SetMaterial(unkMat, Animation::NO_LOOP, 0x1000_f, 0);
	texSRT.SetTexSRT(texSRTDefs[6], Animation::LOOP, 0x1000_f, 0);
	
	texSeq.speed = 0x0_f;
	matChg.currFrame = (Fix12i)MATERIAL_CHANGER_FRAMES[health];
	
	wmClsn.Init(this, 0x14000_f, 0x14000_f, nullptr, nullptr);
	
	direction = -1;
	maxWalkSpeed = (s16)direction * MAX_WALK_SPEEDS[health];
	walkSpeed = 0;
	walkAngle = 0x1000 + walkSpeed; // ???
	
	pos.x = Sin(walkAngle) * 0x546000_f;
	pos.z = Cos(walkAngle) * 0x546000_f;
	
	RaycastGround raycaster;
	raycaster.SetObjAndPos(Vector3{pos.x, pos.y + 0x64000_f, pos.z}, nullptr);
	
	if (raycaster.DetectClsn())
		pos.y = raycaster.clsnPosY;
	
	UpdateCylClsnPosMultMat();
	UpdateModelTransform();
	
	megaMushroomID = 0;
	shouldRender = true;
	currentScale = 0x1000_f;
	
	return 1;
}

s32 Goomboss::CleanupResources()
{
	SUPER_MUSHROOM_MODEL_PTR.Release();
	
	UnloadKeyModels(2);
	
	goombaModelFile.Release();
	
	for (s32 i = 0; i < Goomba::NUM_ANIMS; i++)
		goombaAnimFiles[i].Release();
	
	modelFile.Release();
	
	for (s32 i = 0; i < NUM_ANIMS; i++)
		animFiles[i].Release();
	
	texSeqFile.Release();
	
	return 1;
}

s32 Goomboss::Behavior()
{
	Fix12i newGoombaTargetSpeed = (Fix12s(walkSpeed, as_raw) * 0x646_f) * 0x546000_f;
	if (newGoombaTargetSpeed < 0x0_f)
		newGoombaTargetSpeed = -newGoombaTargetSpeed;
	goombaTargetSpeed = newGoombaTargetSpeed;
	
	if (state != 7)
		CAMERA->unk114 = this;
	
	UpdateAnims();
	CallState();
	UpdatePos(nullptr);
	UpdateWMClsn(wmClsn, 0);
	GetHurtOrHurtPlayer();
	UpdateCylinderCollisions();
	
	for (s32 i = 0; i < 4; i++)
	{
		cylClsns[i].Clear();
		cylClsns[i].Update();
	}
	
	if (state != 1 && state != 0)
	{
		Fix12i magnitude = EARTHQUAKE_MAGNITUDES[health];
		Vector3 dustPos;
		
		if (leftFootSteppedOnGround)
		{
			dustPos = Vector3{cylClsnPos[2].x, cylClsnPos[2].y, cylClsnPos[2].z};
			if (health < 2)
				LandingDustAt(dustPos, true);
			else
				BigLandingDustAt(dustPos, true);
			
			Sound::Play(3, 0x15e, camSpacePos);
			Earthquake(Vector3{cylClsnPos[2].x, cylClsnPos[2].y, cylClsnPos[2].z}, magnitude);
		}
		
		if (rightFootSteppedOnGround)
		{
			dustPos = Vector3{cylClsnPos[1].x, cylClsnPos[1].y, cylClsnPos[1].z};
			if (health < 2)
				LandingDustAt(dustPos, true);
			else
				BigLandingDustAt(dustPos, true);
			
			Sound::Play(3, 0x15e, camSpacePos);
			Earthquake(Vector3{cylClsnPos[1].x, cylClsnPos[1].y, cylClsnPos[1].z}, magnitude);
		}
	}
	
	UpdateCylClsnPosMultMat();
	UpdateModelTransform();
	DropShadow();
	
	return 1;
}

s32 Goomboss::Render()
{
	if (!shouldRender)
		return 1;
	
	modelAnim.Render(&scale);
	
	texSeq.Update(modelAnim.data);
	matChg.Update(modelAnim.data);
	texSRT.Update(modelAnim.data);
	
	return 1;
}

void Goomboss::UpdateCylClsnPosMultMat()
{
	Vector3 posAsr3 = pos >> 3;
	
	Matrix4x3_FromTranslation(MATRIX_SCRATCH_PAPER, posAsr3.x, posAsr3.y, posAsr3.z);
	Matrix4x3_ApplyInPlaceToRotationY(MATRIX_SCRATCH_PAPER, ang.y);
	Matrix4x3_ConcatScale(MATRIX_SCRATCH_PAPER, scale.x, scale.y, scale.z);
	
	cylClsnPosMulMat = MATRIX_SCRATCH_PAPER;
}

void Goomboss::UpdateModelTransform()
{
	Matrix4x3_FromRotationY(modelAnim.mat4x3, ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
}

void Goomboss::UpdateAnims()
{
	if (!IsCurrentAnim(WALK))
	{
		if (!IsCurrentAnim(WAIT_NO_LOOP))
			modelAnim.speed = 0x1000_f;
		else if ((s32)modelAnim.speed == 8)
			Sound::Play(3, 0x15d, camSpacePos);
	}
	else
		modelAnim.speed = GetAnimSpeed();
	
	modelAnim.Advance();
	texSRT.Advance();
}

void Goomboss::CallState()
{
	(this->*states[state].main)();
}

void Goomboss::GetHurtOrHurtPlayer()
{
	DecIfAbove0_Byte(hurtTimer);
	
	if (state == 1 || state == 2 || state - 5 < 4)
		return;
	
	Actor* otherActor = nullptr;
	CylinderClsnWithPos* cylClsn;
	
	for (s32 i = 0; i < 4; i++)
	{
		if (cylClsns[i].otherObjID != 0)
		{
			otherActor = Actor::FindWithID(cylClsns[i].otherObjID);
			cylClsn = &cylClsns[i];
		}
		if (otherActor != nullptr) break;
	}
	
	if (otherActor == nullptr)
		return;
	
	u32 hitflags = cylClsn->hitFlags;
	bool hitByPlayer = (hitflags & CylinderClsn::HIT_BY_EGG) != 0;
	
	if (!hitByPlayer)
	{
		if (otherActor->actorID == 0xbf || hitByPlayer)
		{
			Player* player = (Player*)otherActor;
			if (hurtTimer == 0)
			{
				if (((hitflags & (CylinderClsn::HIT_BY_SPIN_OR_GROUND_POUND         | CylinderClsn::HIT_BY_PUNCH
					| CylinderClsn::HIT_BY_KICK   | CylinderClsn::HIT_BY_BREAKDANCE | CylinderClsn::HIT_BY_SLIDE_KICK
					| CylinderClsn::HIT_BY_DIVE   | CylinderClsn::HIT_BY_UNK_11     | CylinderClsn::HIT_BY_UNK_12
					| CylinderClsn::HIT_BY_UNK_14 | CylinderClsn::HIT_BY_REGURG_GOOMBA)) == 0)
					&& player->unk708 == 0)
				{
					if (cylClsn == &cylClsns[3])
					{
						if (walkSpeed == 0)
							player->Hurt(Vector3{pos.x, pos.y, pos.z}, 1, 0x5000_f, 1, 0, 1);
						else
						{
							player->Unk_020c6a10(2);
							hurtTimer = 0x1e;
						}
					}
					else if (cylClsn == &cylClsns[4])
					{
						if (walkSpeed == 0)
							player->Hurt(Vector3{pos.x, pos.y, pos.z}, 1, 0x5000_f, 1, 0, 1);
						else
						{
							player->Unk_020c6a10(2);
							hurtTimer = 0x1e;
						}
					}
					else
					{
						player->Hurt(Vector3{pos.x, pos.y, pos.z}, 1, 0x5000_f, 1, 0, 1);
						hurtTimer = 0x10;
					}
				}
				
				if (!player->isMega)
				{
					if (cylClsn == &cylClsns[1] && (cylClsn->hitFlags & CylinderClsn::HIT_BY_KICK) != 0)
					{
						if (state == 4)
							ChangeState(2);
						else
							ChangeState(4);
						
						if (player->param1 == 0)
						{
							Vector3 mushroomPos = {pos.x, pos.y, pos.z};
							
							if (megaMushroomID == 0 && Actor::FindWithID(0) == nullptr)
							{
								// iVar1 = (s32)((direction * (((((s32)(scale.x + ((u32)(scale.x >> 0xb) >> 0x14)) >> 0xc) * 0x350 + 0x500) * 0x10000 >> 0x10) + 0x600) + (s32)walkAngle + (s32)maxWalkSpeed) * 0x10000 >> 0x10 & 0xffffU) >> 4;
								u16 arcSin = (u16)((direction * scale.x) + walkAngle + maxWalkSpeed).val;
								
								mushroomPos.y += 0x32000_f;
								mushroomPos.x = Sin(arcSin) * 0x546000_f;
								mushroomPos.z = Cos(arcSin) * 0x546000_f;
								
								Actor* megaMushroom = Actor::Spawn(MEGA_MUSHROOM_ACTOR_ID, 0x0000, mushroomPos, nullptr, areaID, -1);
								megaMushroomID = megaMushroom->uniqueID;
							}
						}
					}
				}
				else
				{
					if ((cylClsn->hitFlags & (CylinderClsn::HIT_BY_PUNCH | CylinderClsn::HIT_BY_KICK
						| CylinderClsn::HIT_BY_BREAKDANCE | CylinderClsn::HIT_BY_SLIDE_KICK)) == 0)
					{
						s32 multiplier = 1;
						if (0x4000 < AngleDiff(pos.HorzAngle(player->pos), ang.y))
							multiplier = -1;
						
						SetAnim(WAIT);
						ChangeState(8);
						SpawnParticles(*player, *cylClsn, 0);
						Sound::Play(3, 0x15a, camSpacePos);
						walkSpeed = multiplier * (s16)direction * -200;
					}
					else
						hitByPlayer = true;
				}
			}
		}
		else
		{
			if (otherActor->actorID == GOOMBA_ACTOR_ID &&
			(hitflags & (CylinderClsn::HIT_BY_EGG | CylinderClsn::HIT_BY_REGURG_GOOMBA)) != 0)
			{
				hitByPlayer = true;
			}
		}
	}
	
	if (!hitByPlayer)
		return;
	
	Sound::Play(3, 0x15b, camSpacePos);
	
	s32 multiplier = 1;
	
	if (AngleDiff(pos.HorzAngle(otherActor->pos), ang.y) < 0x4001)
		SetAnim(DAMAGE_FRONT);
	else
	{
		SetAnim(DAMAGE_BACK);
		multiplier = -1;
	}
	
	walkSpeed = multiplier * (s16)direction * -400;
	ChangeState(5);
	SpawnParticles((Player&)*otherActor, *cylClsn, 1);
}

void Goomboss::UpdateCylinderCollisions()
{
	s32 transformIndexes[3] = {1, 8, 10};
	Fix12i cylClsnOffsetsY[3];
	Fix12i cylClsnRadius[3];
	Fix12i cylClsnHeights[3];
	
	cylClsnHeights[1]  = cylClsnHeights[2]  = scale.y *  0x40000_f;
	cylClsnRadius[1]   = cylClsnRadius[2]   = scale.x *  0x50000_f;
	cylClsnOffsetsY[1] = cylClsnOffsetsY[2] = scale.y * -0x10000_f;
	
	cylClsnOffsetsY[0] = scale.y * 0x14000_f;
	cylClsnRadius[0]   = scale.x * 0xb4000_f;
	cylClsnHeights[0]  = scale.y * 0x104000_f;
	
	for (s32 i = 0; i < 3; i++)
	{
		Vector3 newCylClsnPos;
		GetCylClsnPos(newCylClsnPos, transformIndexes[i]);
		cylClsnPos[i] = newCylClsnPos;
		
		s32 j = i + 1;
		cylClsns[j].radius = cylClsnRadius[i];
		cylClsns[j].height = cylClsnHeights[i];
		cylClsns[j].pos.x = cylClsnPos[i].x;
		cylClsns[j].pos.y = cylClsnPos[i].y + cylClsnOffsetsY[i];
		cylClsns[j].pos.z = cylClsnPos[i].z;
	}
	
	cylClsns[0].radius = scale.x * 0x5a000_f;
	cylClsns[0].height = scale.y * 0x96000_f;
	cylClsns[0].pos.x = pos.x;
	cylClsns[0].pos.y = pos.y + (scale.y *  0x40000_f);
	cylClsns[0].pos.z = pos.z;
	
	Fix12i unkMultRes = scale.y * -0x4a000_f;
	
	if (cylClsnPos[2].y + unkMultRes < pos.y)
	{
		leftFootSteppedOnGround = !leftFootCurrentlyOnGround;
		leftFootCurrentlyOnGround = true;
	}
	else
	{
		leftFootSteppedOnGround = false;
		leftFootCurrentlyOnGround = false;
	}
	
	if (cylClsnPos[1].y + unkMultRes < pos.y)
	{
		rightFootSteppedOnGround = !rightFootCurrentlyOnGround;
		rightFootCurrentlyOnGround = true;
	}
	else
	{
		rightFootSteppedOnGround = false;
		rightFootCurrentlyOnGround = false;
	}
	
	if (!rightFootCurrentlyOnGround)
		cylClsns[2].flags1 |= 0x20;
	else
		cylClsns[2].flags1 &= ~0x20;
	
	if (!leftFootCurrentlyOnGround)
		cylClsns[3].flags1 |= 0x20;
	else
		cylClsns[3].flags1 &= ~0x20;
}

void Goomboss::DropShadow()
{
	if (shadowInvisible)
		return;
	
	for (s32 i = 0; i < 3; i++)
	{
		shadowMats[i].c0.x = 0x1000_f;
		shadowMats[i].c0.y = 0x0_f;
		shadowMats[i].c0.z = 0x0_f;
		shadowMats[i].c1.x = 0x0_f;
		shadowMats[i].c1.y = 0x1000_f;
		shadowMats[i].c1.z = 0x0_f;
		shadowMats[i].c2.x = 0x0_f;
		shadowMats[i].c2.y = 0x0_f;
		shadowMats[i].c2.z = 0x1000_f;
		//shadowMats[i].c3.x = 0x0_f;
		//shadowMats[i].c3.y = 0x0_f;
		//shadowMats[i].c3.z = 0x0_f;
		
		Fix12i depth = pos.y - originalPos.y;
		if (depth < 0x1001_f)
			depth = 0x1000_f;
		
		Fix12i radius = (cylClsns[i + 1].radius * 2) - (depth * 0x180_f);
		if (radius < 0xa000_f)
			radius = 0xa000_f;
		
		shadowMats[i].c3.x = cylClsnPos[i].x >> 3;
		shadowMats[i].c3.y = pos.y >> 3;
		shadowMats[i].c3.z = cylClsnPos[i].z >> 3;
		
		DropShadowRadHeight(shadows[i], shadowMats[i], radius, depth + 0x28000_f, 0xf);
	}
}

bool Goomboss::IsCurrentAnim(s32 animID)
{
	return modelAnim.file == animations[animID].animFile.GetFilePtr();
}

Fix12i Goomboss::GetAnimSpeed()
{
	Fix12i animSpeed = (Fix12i)walkSpeed;
	if (animSpeed < 0x0_f)
		animSpeed = (Fix12i)-walkSpeed;
	
	animSpeed /= (ANIM_SPEED_DENOMINATOR[health] + 0x50001_f);
	
	if (0xfff_f < animSpeed)
	{
		if (0x3000_f < animSpeed)
			animSpeed = 0x3000_f;
		return animSpeed;
	}
	
	return 0x1000_f;
}

void Goomboss::ChangeState(u32 newState)
{
	state = newState;
	(this->*states[state].init)();
}

void Goomboss::SetAnim(s32 animID)
{
	modelAnim.SetAnim(animations[animID].animFile.GetFilePtr(), animations[animID].animFlags, 0x1000_f, 0);
	texSRT.SetTexSRT(animations[animID].texAnim, Animation::LOOP, 0x1000_f, 0);
}

void Goomboss::SpawnParticles(Player& player, CylinderClsn& cylClsn, bool spawnStarParticles)
{
	Vector3 particlePos = Vector3{pos.x, pos.y + cylClsn.height, pos.z};
	Vector3 playerPos = Vector3{player.pos.x, player.pos.y + 0x46000_f, player.pos.z};
	Vector3 subVec = playerPos - particlePos;
	
	s16 atanX = cstd::atan2(subVec.x, subVec.z) & 0xffff;
	s16 atanY = cstd::atan2(subVec.y, subVec.HorzLen()) & 0xffff;
	
	Fix12i multiplier = cylClsn.radius * Cos(atanX);
	
	particlePos.x += multiplier * Sin(atanY);
	particlePos.y += cylClsn.radius * Sin(atanX);
	particlePos.z += multiplier * Cos(atanY);
	
	if (!spawnStarParticles)
	{
		Particle::System::NewSimple(Particle::PTS_SPREAD_PURPLE_PETALS_3, particlePos.x, particlePos.y, particlePos.z);
	}
	else
	{
		Particle::System::NewSimple(Particle::PTS_IMPACT_STAR_INSTANT, particlePos.x, particlePos.y, particlePos.z);
		Particle::System::NewSimple(Particle::PTS_STARS_ORANGE_YELLOW, particlePos.x, particlePos.y, particlePos.z);
	}
}

void Goomboss::TurnIfNotFacingPlayer()
{
	if (0x4000 < AngleDiff(((direction * 0x4500 + (s32)walkAngle) * 0x10000) >> 0x10, HorzAngleToCPlayer()))
	{
		SetAnim(TURN);
		direction = -direction;
	}
}

bool Goomboss::HasFinishedTurning()
{
	if (IsCurrentAnim(TURN) && modelAnim.Finished())
	{
		ang.y -= 0x8000;
		return true;
	}
	return false;
}

bool Goomboss::ShouldSpawnOrWait()
{
	if (!IsCurrentAnim(WALK))
	{
		if (!IsCurrentAnim(WALK_START))
		{
			if (!IsCurrentAnim(WALK_END))
				return true;
			else if (modelAnim.Finished())
				return true;
		}
		else
			SetAnim(WALK_END);
	}
	else
	{
		if (ApproachAngle(walkSpeed, 0, 0x1e, 0x20, 1) == 0)
		{
			if (((u16)(s32)modelAnim.currFrame) == 0)
				SetAnim(WALK_END);
		}
		else
			UpdatePosAndAngle(); // player is behind Goomboss
	}
	return false;
}

// was originally "void GetGoombaSpawnPos(Vector3* vector, Goomboss* goomboss, s32 goombaID)"
// but I made it a member function for simplicity
void Goomboss::GetGoombaSpawnPos(Vector3& goombaPos, s32 goombaID)
{
	goombaPos = pos;
	
	if (ClosestPlayer()->param1 != 3)
	{
		s32 goombasPerRow = 3;
		if (health == 1)
			goombasPerRow = 5;
		
		s32 direction2; // front or back
		s32 col;
		if (goombaID < goombasPerRow)
		{
			direction2 = -1;
			col = goombaID % goombasPerRow;
		}
		else
		{
			direction2 = 1;
			col = goombaID % goombasPerRow;
		}
		
		Fix12i multiplier = col * 0x64000_f + 0x4e2000_f;
		
		s16 angle = (s16)(walkAngle + walkSpeed - direction2 * direction *
			((s16)((s32)scale.x * 0x350 + 0x250) + 0x600));
		
		
		goombaPos.x = multiplier * Sin(angle);
		goombaPos.y += 0x32000_f;
		goombaPos.z = multiplier * Cos(angle);
	}
	else // the player is Yoshi
	{
		Fix12i multiplier;
		if (health == 3)
			multiplier = 0x546000_f;
		else if (health == 2)
			multiplier = Fix12i((goombaID / 3) * 0xb4) + 0x4ec000_f;
		else
			multiplier = Fix12i((goombaID / 3) * 0xb4) + 0x438000_f;
		
		s16 angle = (s16)(walkAngle + maxWalkSpeed - direction *
			((s16)((s32)scale.x * 0x350 + 0x500) + (goombaID % 3 * 0x6000000 >> 0x10)));
		
		goombaPos.x = multiplier * Sin(angle);
		goombaPos.y += 0x32000_f;
		goombaPos.z = multiplier * Cos(angle);
	}
}

void Goomboss::SetMaxWalkSpeed()
{
	maxWalkSpeed = (s16)direction * MAX_WALK_SPEEDS[health];
}

void Goomboss::UpdatePosAndAngle()
{
	if (wmClsn.IsOnGround() != 0)
	{
		walkAngle += walkSpeed;
		pos.x = Sin(walkAngle) * 0x546000_f;
		pos.z = Cos(walkAngle) * 0x546000_f;
	}
	ApproachAngle(ang.y, (s16)(direction * 0x4500 + (s32)walkAngle), 10, 0x800, 0x10);
}

bool Goomboss::AdvanceMaterialChanger()
{
	matChg.Advance();
	
	s32 maxFrame = MATERIAL_CHANGER_FRAMES[health];
	bool reachedEndOfAnim = maxFrame <= (s32)matChg.currFrame;
	
	if (reachedEndOfAnim)
		matChg.currFrame = (Fix12i)maxFrame;
	
	return reachedEndOfAnim;
}

bool Goomboss::GrowBigger()
{
	nextScale = GOOMBOSS_SCALES[health + 1] + ((GOOMBOSS_SCALES[health] - GOOMBOSS_SCALES[health + 1]) / Fix12i(timesToGrow << 0xc, as_raw));
	
	if (Math_Function_0203b14c(currentScale, nextScale, 0x78_f, 0x100_f, 0x20_f) == 0x0_f)
	{
		if (scaleArcSinCos == 0)
			scale.x = scale.y = scale.z = currentScale;
		
		if (timesToGrow < 2)
			return true;
		
		timesToGrow--;
		
		if (state == 6)
			Particle::System::NewSimple(Particle::PTS_DUST_LANDING_SOFT_2, pos.x, pos.y + (currentScale * 0x190000_f), pos.z);
	}
	
	Fix12i multiplier = (nextScale - currentScale) + 0x11e_f;
	
	scale.y = currentScale + (multiplier * Sin(scaleArcSinCos));
	scale.x = scale.z = currentScale + (multiplier * Cos(scaleArcSinCos));
	
	scaleArcSinCos += 0x1230;
	
	return false;
}

void Goomboss::SetExplosionGoombasShouldRender(bool newShouldRender)
{
	ExplosionGoomba* explosionGoomba = (ExplosionGoomba*)Actor::FindWithActorID(0xc7, nullptr);
	if (explosionGoomba == nullptr)
		return;
	
	do
	{
		explosionGoomba->shouldRender = newShouldRender;
		explosionGoomba = (ExplosionGoomba*)Actor::FindWithActorID(0xc7, explosionGoomba);
	} while (explosionGoomba != nullptr);
}

void Goomboss::SetExplosionGoombaSpeeds()
{
	ExplosionGoomba* explosionGoomba = (ExplosionGoomba*)Actor::FindWithActorID(0xc7, nullptr);
	if (explosionGoomba == nullptr)
		return;
	
	do
	{
		explosionGoomba->vertAccel = -0xa000_f;
		u32 random = RandomIntInternal(&RNG_STATE);
		explosionGoomba->stateTimer = 0x30;
		explosionGoomba->horzSpeed = Fix12i((random >> 8 & 0xf) * 0x1000, as_raw) + 0x16000_f;
		explosionGoomba->speed.x = 0;
		explosionGoomba->speed.y = Fix12i((random >> 8 & 0x1f) * 0x1000, as_raw) + 0x60000_f;
		explosionGoomba->speed.z = 0;
		
		//explosionGoomba->motionAng.x = explosionGoomba->motionAng.x;
		explosionGoomba->motionAng.y += ((u16)(random >> 8) & 0x1000);
		//explosionGoomba->motionAng.z = explosionGoomba->motionAng.z;
		explosionGoomba->ang.x = explosionGoomba->motionAng.x;
		explosionGoomba->ang.y = explosionGoomba->motionAng.y + ((u16)(random >> 8) & 0x1000);
		explosionGoomba->ang.z = explosionGoomba->motionAng.z;
		
		explosionGoomba->shouldBehave = true;
		
		explosionGoomba = (ExplosionGoomba*)Actor::FindWithActorID(0xc7, explosionGoomba);
	} while (explosionGoomba != nullptr);
}

void Goomboss::SetBossCamera()
{
	CAMERA->SetFlag_3();
	
	Matrix4x3 cameraMat = Matrix4x3
	{
		Vector3{pos.x, pos.y + 0x1a0000_f, pos.z},
		Vector3{pos.x, pos.y, pos.z},
		Vector3{0x0_f, 0x0_f, 0x59c000_f},
		Vector3{0x0_f, 0x0_f, 0x0_f}
	};
	
	Matrix4x3_FromRotationY(MATRIX_SCRATCH_PAPER, ang.y);
	MulVec3Mat4x3(cameraMat.c2, MATRIX_SCRATCH_PAPER, cameraMat.c3);
	
	cameraMat.c1.y += 0x300000_f;
	cameraMat.c1.x += cameraMat.c3.x;
	cameraMat.c1.z += cameraMat.c3.z;
	
	CAMERA->SetLookAt(cameraMat.c0);
	CAMERA->SetPos(cameraMat.c1);
}

bool Goomboss::SpawnExplosionGoomba()
{
	Vector3_16 spawnAng = Vector3_16{0, ang.y, 0}; // local_30, local_2e, local_2c
	Vector3 spawnPos = Vector3{pos.x, pos.y + 0xe4000_f, pos.z}; // local_28, local_24, local_20
	Vector3 originalSpawnPos = spawnPos; // local_1c, local_18, local_14
	
	if (DecIfAbove0_Short(stateTimer) == 0)
	{
		Fix12i multiplier;
		if (numGoombasAlive < 7)
		{
			multiplier = 0x18c000_f;
			spawnAng.y += numGoombasAlive * 0x2492;
		}
		else if (numGoombasAlive < 12)
		{
			spawnPos.y += 0xc4000_f;
			multiplier = 0x108000_f;
			spawnAng.y += (numGoombasAlive - 7) * 0x3333;
		}
		else if (numGoombasAlive < 15)
		{
			spawnPos.y += 0x188000_f;
			multiplier = 0x84000_f;
			spawnAng.y += (numGoombasAlive - 12) * 0x5555;
		}
		else
		{
			multiplier = 0x0_f;
			spawnPos.y += 0x24c000_f;
		}
		
		spawnPos.x += multiplier * Sin(spawnAng.y);
		spawnPos.z += multiplier * Cos(spawnAng.y);
		
		spawnAng.x = originalSpawnPos.VertAngle(spawnPos);
		Actor::Spawn(0xc7, 0x1111, spawnPos, &spawnAng, areaID, -1);
		numGoombasAlive++;
		stateTimer = 2;
	}
	
	u8 numGoombasToSpawn = NUM_GOOMBAS_TO_SPAWN[health];
	
	if (health == 1 && ClosestPlayer()->param1 != 3)
		numGoombasToSpawn++;
	
	return numGoombasToSpawn <= numGoombasAlive;
}

// was originally "GetCylClsnPos(Vector3* cylClsnPos, Goomboss* goomboss, s32 transformIndex)"
// but I made it a member function for simplicity
void Goomboss::GetCylClsnPos(Vector3& cylClsnPos, s32 transformIndex)
{
	cylClsnPos = Vector3{0x0_f, 0x0_f, 0x0_f};
	MATRIX_SCRATCH_PAPER = cylClsnPosMulMat;
	MulMat4x3Mat4x3(modelAnim.data.transforms[transformIndex], MATRIX_SCRATCH_PAPER, MATRIX_SCRATCH_PAPER);
	cylClsnPos = MATRIX_SCRATCH_PAPER.c3;
	cylClsnPos <<= 3;
}

void Goomboss::State0_Init()
{
	return;
}

void Goomboss::State0_Main()
{
	Player* player = ClosestPlayer();
	
	CAMERA->SetFlag_3();
	CAMERA->SetLookAt(Vector3{pos.x + 0x130000_f, 0x1cd000_f, pos.z - 0x2a0000_f});
	CAMERA->SetPos(Vector3{pos.x - 0x2f0000_f, pos.y + 0x20000_f, pos.z + 0x254000_f});
	
	//Vector3 unusedVec = player->pos;
	
	player->ang = Vector3_16{ang.x, (short)-ang.y, ang.z};
	ang.y = (s16)direction * 0x4500 + walkAngle;
	listener = player;
	
	if (!player->StartTalk(*this, true))
		return;
	
	Message::PrepareTalk();
	if (!musicLoaded)
	{
		Sound::LoadAndSetMusic_Layer3(0x2c);
		musicLoaded = true;
	}
	
	if (player->ShowMessage(*this, (s16)player->param1 + 0xd3, Vector3{pos.x, pos.y + 0x78000_f, pos.z}, 0, 2))
	{
		Sound::Play(3, 0x15a, camSpacePos);
		ChangeState(1);
	}
}

void Goomboss::State1_Init()
{
	return;
}

void Goomboss::State1_Main()
{
	if (listener->GetTalkState() != Player::TK_NOT)
		return;
	
	CAMERA->flags &= ~(Camera::BOSS_TALK);
	Sound::LoadAndSetMusic_Layer3(0x2d);
	Sound::Func_02048ee4();
	Message::EndTalk();
	ChangeState(2);
}

void Goomboss::State2_Init()
{
	TurnIfNotFacingPlayer();
	stateTimer = 0;
}

void Goomboss::State2_Main()
{
	if (IsCurrentAnim(TURN))
	{
		if (HasFinishedTurning())
			SetAnim(SPAWN);
		return;
	}
	else if (!IsCurrentAnim(SPAWN))
	{
		if (ShouldSpawnOrWait())
			SetAnim(SPAWN);
		return;
	}
	
	u8 numGoombasToSpawn = NUM_GOOMBAS_TO_SPAWN[health];
	
	bool playerNotYoshi = ClosestPlayer()->param1 != 3;
	if (health == 1 && playerNotYoshi)
		numGoombasToSpawn++;
	
	if (!modelAnim.Finished())
		return;
	
	if (DecIfAbove0_Short(stateTimer) != 0)
		return;
	
	Vector3 goombaPos;
	GetGoombaSpawnPos(goombaPos, numGoombasAlive);
	DisappearPoofDustAt(goombaPos);
	
	u32 goombaParam = 0xeeee;
	if (playerNotYoshi && -1 < (s32)(numGoombasAlive * -0x80000000))
		goombaParam = 0xeeef;
	
	Goomba* goomba = (Goomba*)Actor::Spawn(GOOMBA_ACTOR_ID, goombaParam, goombaPos, &ang, areaID, -1);
	goomba->goombossID = uniqueID;
	goomba->vSetOriginalPos(originalPos);
	goomba->goombaID = numGoombasAlive;
	
	numGoombasAlive++;
	stateTimer = 2;
	
	s32 numerator = 3;
	if (playerNotYoshi && health == 1)
		numerator = 5;
	
	if (numGoombasAlive % numerator == 0)
		modelAnim.currFrame = 0x0_f;
	
	if (numGoombasToSpawn <= numGoombasAlive)
		ChangeState(3);
}

void Goomboss::State3_Init()
{
	SetAnim(WALK_START);
	SetMaxWalkSpeed();
}

void Goomboss::State3_Main()
{
	if (numGoombasAlive == 0)
	{
		ChangeState(2);
		return;
	}
	else if (IsCurrentAnim(WALK_START))
	{
		if (modelAnim.Finished())
			SetAnim(WALK);
		return;
	}
	ApproachAngle(walkSpeed, maxWalkSpeed, 10, 0x20, 1);
	UpdatePosAndAngle();
	if (0x4affff_f < DistToCPlayer())
		return;
	
	if (0x4000 < AngleDiff(HorzAngleToCPlayer(), ang.y))
		ChangeState(4);
}

void Goomboss::State4_Init()
{
	return;
}

void Goomboss::State4_Main()
{
	if (!IsCurrentAnim(SERCH_WAIT))
	{
		if (ShouldSpawnOrWait())
			SetAnim(SERCH_WAIT);
		return;
	}
	
	if (DistToCPlayer() < 0x4b0000_f)
	{
		if (AngleDiff(HorzAngleToCPlayer(), ang.y) < 0x3000)
		{
			ChangeState(3);
			return;
		}
	}
	else
		ChangeState(3);
	
	if (numGoombasAlive == 0)
		ChangeState(2);
}

void Goomboss::State5_Init()
{
	health--;
	if (5 < health)
		health = 5;
}

void Goomboss::State5_Main()
{
	if (ApproachAngle(walkSpeed, 0, 10, 0x100, 1) != 0)
	{
		UpdatePosAndAngle();
		return;
	}
	
	if (!modelAnim.Finished())
		return;
	
	if (health != 0)
	{
		ChangeState(6);
		return;
	}
	
	Player* player = ClosestPlayer();
	if (player->StartTalk(*this, true))
	{
		Message::PrepareTalk();
		if (!IsCurrentAnim(DAMAGE_BACK) && !IsCurrentAnim(DAMAGE_FRONT))
		{
			ChangeState(7);
			listener = player;
			return;
		}
		SetAnim(WAIT_NO_LOOP);
	}
}

void Goomboss::State6_Init()
{
	TurnIfNotFacingPlayer();
	scaleArcSinCos = 0;
	stateState = 0;
	
	u16 texSeqFrame = 3 - health & 0xffff;
	if (2 < texSeqFrame)
		texSeqFrame = 2;
	texSeq.currFrame = (Fix12i)texSeqFrame;
	
	timesToGrow = 3;
}

void Goomboss::State6_Main()
{
	if (stateState == 0)
	{
		if (!IsCurrentAnim(TURN) || HasFinishedTurning())
		{
			stateState++;
			SetAnim(ANGER);
			Sound::Play(3, 0x15c, camSpacePos);
		}
		return;
	}
	
	if (stateState != 1)
		return;
	
	bool finishedMatAnim = AdvanceMaterialChanger();
	if (GrowBigger() && finishedMatAnim)
		ChangeState(2);
}

void Goomboss::State7_Init()
{
	health = 0;
	scale.x = scale.y = scale.z = GOOMBOSS_SCALES[1];
	texSeq.currFrame = 0x2000_f;
	matChg.currFrame = 0x3c000_f;
	stateState = 0;
	SetAnim(DOWN_START);
	timesToGrow = 3;
}

void Goomboss::State7_Main()
{
	if (modelAnim.Finished())
		SetAnim(DOWN);
	
	switch(stateState)
	{
		case 0:
			break;
		case 1:
			Goomba* goomba;
			if (DecIfAbove0_Short(stateTimer) == 0)
			{
				goomba = (Goomba*)Actor::FindWithActorID(GOOMBA_ACTOR_ID, nullptr);
				while (goomba != nullptr)
				{
					if ((goomba->flags & Actor::IN_YOSHI_MOUTH) == 0)
					{
						PoofDustAt(goomba->pos);
						goomba->MarkForDestruction();
						stateTimer = 2;
						return;
					}
					goomba = (Goomba*)Actor::FindWithActorID(GOOMBA_ACTOR_ID, goomba);
				}
			}
			
			if ((numGoombasAlive == 1 && (goomba = (Goomba*)Actor::FindWithActorID(GOOMBA_ACTOR_ID, nullptr), goomba != nullptr)) && (goomba->flags & Actor::IN_YOSHI_MOUTH) != 0)
				numGoombasAlive--;
			
			if (numGoombasAlive == 0)
			{
				Sound::Play(3, 0x15c, camSpacePos);
				stateState++;
				numGoombasAlive = 0;
			}
			return;
		case 2:
			if (!allExplosionGoombasSpawned && SpawnExplosionGoomba())
				allExplosionGoombasSpawned = true;
			
			if (GrowBigger() && AdvanceMaterialChanger())
			{
				numGoombasAlive = 0;
				stateState++;
			}
			return;
		case 3:
			if (listener->HasFinishedTalking())
			{
				shouldRender = false;
				Particle::System::NewSimple(Particle::PTS_FAST_SPREAD_WHITE_DOTS, pos.x, pos.y + 0x190000_f, pos.z);
				Particle::System::NewSimple(Particle::PTS_DUST_POOF_BIG_REDDISH, pos.x, pos.y + 0x190000_f, pos.z);
				Sound::Play(3, 0x15f, camSpacePos);
				SetExplosionGoombasShouldRender(true);
				SetExplosionGoombaSpeeds();
				CAMERA->flags &= ~(Camera::BOSS_TALK);
				Message::EndTalk();
				Sound::StopLoadedMusic_Layer3();
				Sound::Func_02048eb4();
				Sound::ChangeMusicVolume(0x7f, 0x15666);
				shadowInvisible = true;
				stateTimer = 0xf;
				stateState++;
			}
			return;
		case 4:
			Actor::Spawn(KEY_ACTOR_ID, MARIO_KEY_PARAMETER, Vector3{pos.x, pos.y + 0x12c000_f, pos.z}, nullptr, areaID,-1); // Key
			Sound::Play(3, 0xbb, camSpacePos);
			MarkForDestruction();
		default:
			return;
	}
	
	SetBossCamera();
	if (listener->GetTalkState() == Player::TK_START)
	{
		if (listener->ShowMessage(*this, (s16)listener->param1 + 0xd7, Vector3{pos.x, pos.y + 0x78000_f, pos.z}, 1, 2))
			Sound::Func_0201277c(0x15a);
	}
	else if (listener->GetTalkState() == Player::TK_UNK2)
		stateState++;
}

void Goomboss::State8_Init()
{
	return;
}

void Goomboss::State8_Main()
{
	if (ApproachAngle(walkSpeed, 0, 10, 0x100, 1) == 0)
		ChangeState(3);
	else
		UpdatePosAndAngle();
}

void Goomboss::vGetGoombaSpawnPos(Vector3& goombaPos, s32 numerator)
{
	GetGoombaSpawnPos(goombaPos, numerator);
}