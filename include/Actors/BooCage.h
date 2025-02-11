#pragma once

struct BooCage : Enemy
{
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	Model model;                // 0x300
	ShadowModel shadow;         // 0x350
	u32 particleID;             // 0x378
	u16 soundTimer;             // 0x37c
	u8 unk37e;                  // 0x37e (always 0?)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	BooCage();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BooCage() override;
	
	void UpdateModelTransform();
};