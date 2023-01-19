#pragma once

extern "C"
{
	// graphics ports (do NOT read from the ports!)
	extern volatile u32 GXPORT_MATRIX_MODE;
	extern volatile u32 GXPORT_MTX_LOAD_4x4;
	extern volatile u32 GXPORT_MTX_LOAD_4x3;
	extern volatile u32 GXPORT_LIGHT_VECTOR;
	extern volatile u32 GXPORT_LIGHT_COLOR;
}

namespace GXFIFO
{
	[[gnu::always_inline]]
	inline void LoadMatrix4x3(const Matrix4x3* matrix)
	{
		GXPORT_MTX_LOAD_4x3 = matrix->c0.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c0.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c0.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c1.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c1.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c1.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c2.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c2.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c2.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c3.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c3.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c3.z.val;
	}
	
	[[gnu::always_inline]]
	//Do NOT set the light vector to <1, 0, 0>, <0, 1, 0>, or <0, 0, 1>. Instead, do <0x0.ff8, 0, 0>, for example.
	inline void SetLightVector(s32 lightID, Fix12i x, Fix12i y, Fix12i z) //Fixed Point 20.12
	{
		GXPORT_LIGHT_VECTOR = (((z.val >> 3 & 0x1ff) | (z.val >> 22 & 0x200)) << 10 |
								(y.val >> 3 & 0x1ff) | (y.val >> 22 & 0x200)) << 10 |
								(x.val >> 3 & 0x1ff) | (x.val >> 22 & 0x200) | lightID << 30;
	}
	
	[[gnu::always_inline]]
	inline void SetLightVector(int lightID, const Vector3& v)
	{
		SetLightVector(lightID, v.x, v.y, v.z);
	}
	
	[[gnu::always_inline]]
	inline void SetLightColor(s32 lightID, u8 r, u8 g, u8 b) //0x00 to 0xff
	{
		GXPORT_LIGHT_COLOR = (u32)b >> 3 << 10 |
							 (u32)g >> 3 <<  5 |
							 (u32)r >> 3 | lightID << 30;
	}
}