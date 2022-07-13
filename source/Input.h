#ifndef SM64DS_INPUT_INCLUDED
#define SM64DS_INPUT_INCLUDED

#include "SM64DS_Common.h"


struct Input
{
	enum Buttons : u16
	{
		A = 1 << 0,
		B = 1 << 1,
		SELECT = 1 << 2,
		START = 1 << 3,
		RIGHT = 1 << 4,
		LEFT = 1 << 5,
		UP = 1 << 6,
		DOWN = 1 << 7,
		CAM_RIGHT = 1 << 8,
		CAM_LEFT = 1 << 9,
		R = 1 << 10,
		Y = 1 << 11,
		L = 1 << 14,
		X = 1 << 15
	};

	Fix12s magRelated0;
	Fix12s magRelated1;
	u16 buttonsHeld;
	u16 buttonsPressed;
	Fix12s magnitude;
	Fix12s dirX;
	Fix12s dirZ;
	s16 angle; //0x0000 is toward the camera, 0x4000 is right
	u8 touchscreenX; //0 is at the left
	u8 touchscreenY; //0 is at the top
	u8 touchscreenDelay;
	u8 touchOffDelay;
	bool touchscreenBeingUsed;
	u8 unk15;
	u16 unk16;
};

struct InputRelated
{
	u32 unk00;
	u32 unk04;
	u16 unk08;
	u16 buttonsHeld;
	s16 cameraAngleY;
	u16 unk0e;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
};

static_assert(sizeof(InputRelated) == 0x24);

extern "C"
{
	extern Input INPUT_ARR[4];

	extern InputRelated INPUT_RELATED_ARR[4];
}

#endif // SM64DS_INPUT_INCLUDED
