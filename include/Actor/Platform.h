#pragma once

struct Platform : public Actor
{
	Model model;             // 0xd4
	MovingMeshCollider clsn; // 0x124
	Matrix4x3 clsnNextMat;   // 0x2ec
	u16 unk31c;              // 0x31c
	
	Platform();
	virtual ~Platform() override;
	virtual void Kill();
	
	void KillByMegaChar(Player& player);
	bool UpdateKillByMegaChar(s16 rotSpeedX, s16 rotSpeedY, s16 rotSpeedZ, Fix12i speed); //true if killed by mega char
	void UpdateClsnPosAndRot(); //make sure the mesh collider is at 0x124 first! Also, call this after updating the model's matrix
	void UpdateModelPosAndRotY(); //make sure the model is at 0x0d4 first!
	bool IsClsnInRange(Fix12i clsnRange, Fix12i clsnRangeOffsetY); //both in fixed-point 20.12 //side effect: enables collision if and only if in range
	bool IsClsnInRangeOnScreen(Fix12i clsnRange, Fix12i clsnRangeOffsetY); //if offsetY is 0, it is loaded from +0xb4.
};

struct PlatformRes
{
	SharedFilePtr* modelFile;
	SharedFilePtr* clsnFile;
	SPLC_Block* splcBlock;
};

static_assert(sizeof(Platform) == 0x320);