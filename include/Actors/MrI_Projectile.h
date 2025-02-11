#pragma once

struct MrI_Projectile : Actor
{
	ShadowModel shadow;                // 0xd4
	MovingCylinderClsnWithPos cylClsn; // 0xfc
	WithMeshClsn wmClsn;               // 0x13c
	Matrix4x3 shadowMat;               // 0x2f8
	u32 magicParticleID;               // 0x328
	u32 dustParticleID;                // 0x32c
	u16 deathTimer;                    // 0x330
	
	static SpawnInfo spawnData;
	
	MrI_Projectile();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~MrI_Projectile() override;
	virtual u32 OnYoshiTryEat() override;
	
	void DropShadow();
	void UpdateWmClsn();
	void CheckCylClsn();
	void Kill();
};