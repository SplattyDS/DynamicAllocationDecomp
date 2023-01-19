#pragma once

// originally used the same struct as Goomboss, it had ExplosionGoomba behavior when param1 was equal to 0x1111...
struct ExplosionGoomba : Enemy
{
	ModelAnim modelAnim;    // 0x110
	ShadowModel shadow;     // 0x174
	Matrix4x3 shadowMat;    // 0x19c
	MaterialChanger matChg; // 0x1cc
	WithMeshClsn wmClsn;    // 0x1e0
	u16 stateTimer;         // 0x39c
	u8 state;               // 0x39e
	bool shouldBehave;      // 0x39f
	bool shouldRender;      // 0x3a0
	
	static SpawnInfo spawnData;
	static GloballySharedFilePtr modelFile;
	static GloballySharedFilePtr animFile;
	
	ExplosionGoomba();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ExplosionGoomba() override;
};