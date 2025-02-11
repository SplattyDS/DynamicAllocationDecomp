#pragma once

struct KoopaFlag : Actor
{
	MovingCylinderClsn cylClsn; // 0xd4
	ModelAnim modelAnim;        // 0x108
	u16 soundTimer;             // 0x16c (inactive if 0)
	u8 hasTouchedFlag;          // 0x16e
	u8 unk16f;                  // 0x16f (unused)
	u32 unk170;                 // 0x170 (unused)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	KoopaFlag();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~KoopaFlag() override;
	
	void UpdateModelTransform();
};