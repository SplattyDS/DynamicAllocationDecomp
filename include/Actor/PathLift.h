#pragma once

struct PathLift : Platform
{
	static constexpr s32 NUM_BULLET_MODELS = 3;
	
	Model bulletModels[NUM_BULLET_MODELS]; // 0x320
	Vector3 unk410;                        // 0x410
	Vector3_16 unk41c;                     // 0x41c
	Vector3_16 unk422;                     // 0x422
	u16 unk428;                            // 0x428
	u8 unk42a;                             // 0x42a
	u8 unk42b;                             // 0x42b
	u8 unk42c;                             // 0x42c (then alignment)
	PathPtr pathPtr;                       // 0x430
	s32 unk438;                            // 0x438
	s32 unk43c;                            // 0x43c
	Fix12i unk440;                         // 0x440 (unused in PathLift)
	Fix12i unk444;                         // 0x444
	u8 unk448;                             // 0x448
	u8 unk449;                             // 0x449
	s16 unk44a;                            // 0x44a
	u32 state;                             // 0x44c
	
	virtual ~PathLift() override;
	virtual void AfterClsn();
	
	void BaseInitResources();
	void BaseBehavior();
};

static_assert(sizeof(PathLift) == 0x450);