#pragma once

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
		X = 1 << 15,
		
		NUM_BUTTONS
	};
	
	Fix12s magRelated0;        // 0x00
	Fix12s magRelated1;        // 0x02
	u16 buttonsHeld;           // 0x04
	u16 buttonsPressed;        // 0x06
	Fix12s magnitude;          // 0x08
	Fix12s dirX;               // 0x0a
	Fix12s dirZ;               // 0x0c
	s16 angle;                 // 0x0e, 0x0000 is toward the camera, 0x4000 is right
	u8 touchscreenX;           // 0x10, 0 is at the left
	u8 touchscreenY;           // 0x11, 0 is at the top
	u8 touchscreenDelay;       // 0x12
	u8 touchOffDelay;          // 0x13
	bool touchscreenBeingUsed; // 0x14
	u8 unk15;                  // 0x15
	u8 controllerMode;         // 0x16
	u8 unk17;                  // 0x17
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

struct TouchInput
{
	bool touching;
	u8 unk01;
	u8 x; // from 0x01 to 0xfe (254)
	u8 y; // from 0x01 to 0xbe (190)
	
	// x1 < x2
	// x1 inclusive, x2 exclusive
	inline bool IsBetweenX(u8 x1, u8 x2)
	{
		return (u8)(x - x1) < (x2 - x1);
		// return IsInRangeX(x1, x2 - x1);
	}
	
	// y1 < y2
	// y1 inclusive, y2 exclusive
	inline bool IsBetweenY(u8 y1, u8 y2)
	{
		return (u8)(y - y1) < (y2 - y1);
		// return IsInRangeX(y1, y2 - y1);
	}
	
	// x1 < x2
	// if x is equal to x1 / x2, returns false (aka counts as between)
	inline bool NotBetweenX(u8 x1, u8 x2)
	{
		return (u8)(x - x1) > (x2 - x1);
	}
	
	// y1 < y2
	// if y is equal to y1 / y2, returns false (aka counts as between)
	inline bool NotBetweenY(u8 y1, u8 y2)
	{
		return (u8)(y - y1) > (y2 - y1);
	}
	
	// x1 inclusive
	inline bool IsInRangeX(u8 x1, u8 len)
	{
		return (u8)(x - x1) < len;
		// return IsBetweenX(x1, x1 + len);
	}
	
	// y1 inclusive
	inline bool IsInRangeY(u8 y1, u8 len)
	{
		return (u8)(y - y1) < len;
		// return IsBetweenX(y1, y1 + len);
	}
};

// IsBetweenX(0xd8, 0xf8) == IsInRangeX(0xd8, 0xf8 - 0xd8) == IsInRangeX(0xd8, 0x20);

// (u8)(TOUCH_INPUT_ARR[DAT_020a0e40].x + 0x28) < 0x20
// (u8)(TOUCH_INPUT_ARR[DAT_020a0e40].y + 0x68) < 0x20

// 0x0:     0 + 0x28 = 0x28    => false
// 0xff: 0xff + 0x28 = 0x(1)27 => false
// 0xf0: 0xf0 + 0x28 = 0x(1)18 => true
// x + 0x28 > 0x20: between 0xd8 (in) and 0xf8 (ex)
// 0xf8 - 0xd8 = 0x20

struct ButtonInput
{
	enum Buttons : u16
	{
		A      = 1 << 0,
		B      = 1 << 1,
		SELECT = 1 << 2,
		START  = 1 << 3,
		RIGHT  = 1 << 4,
		LEFT   = 1 << 5,
		UP     = 1 << 6,
		DOWN   = 1 << 7,
		R      = 1 << 8,
		L      = 1 << 9,
		X      = 1 << 10,
		Y      = 1 << 11
	};
	
	u16 buttonsHeld;
	u16 buttonsPressed;
};

static_assert(sizeof(InputRelated) == 0x24);

extern "C"
{
	extern Input INPUT_ARR[4];
	extern InputRelated INPUT_RELATED_ARR[4];
	extern TouchInput TOUCH_INPUT_ARR[4]; // 0x020a0de8
	extern ButtonInput BUTTON_INPUT_ARR[4]; // 0x020a0e58
}