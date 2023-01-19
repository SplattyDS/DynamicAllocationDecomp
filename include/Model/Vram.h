#pragma once

extern "C"
{
	extern u32 VRAM_Pal_End;				// 0x020a4bd8 (starts at the end   of palette vram, gets decremented when a 16 byte palette is loaded)
	extern u32 VRAM_Pal_Start;				// 0x020a4bcc (starts at the start of palette vram, gets incremented when a 8 byte palette is loaded)
	extern u32 VRAM_Tex_Size;				// 0x020a4be4 (starts at the start of texture vram, gets incremented when a compressed texture is loaded)
	extern u32 VRAM_Tex_End;				// 0x020a4bdc
	extern u32 VRAM_Tex4x4_IndexData_Start;	// 0x020a4be0
	extern u32 VRAM_Tex4x4_TexelData_Start;	// 0x020a4bc8
	extern u32 VRAM_Tex4x4_MaxSize;			// 0x020a4be8
}