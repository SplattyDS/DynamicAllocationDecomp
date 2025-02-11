#pragma once

struct KnockDownPlank : Platform
{
	ShadowModel shadow;  // 0x320
	Matrix4x3 shadowMat; // 0x348
	Vector3 backPos;     // 0x378
	Fix12i frontFloorY;  // 0x384
	Fix12i originalPosY; // 0x388
	Fix12i jumpSpeed;    // 0x38c
	u16 wobbleAng;       // 0x390
	s16 fallAngVel;      // 0x392
	s16 wobbleTimer;     // 0x394
	s8 knockDir;         // 0x396 (1: front, -1: back)
	u8 state;            // 0x397
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	KnockDownPlank();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~KnockDownPlank() override;
	virtual void OnAttacked2(Actor& attacker) override;
	virtual void OnKicked(Actor& kicker) override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	
	void UpdateModelTransform();
	void DropShadow();
	void OnAttacked(Actor& attacker);
};