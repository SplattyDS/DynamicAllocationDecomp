#pragma once

struct WaterDiamond : Actor
{
	Model model;                // 0xd4
	MovingCylinderClsn cylClsn; // 0x124
	u32 waterID;                // 0x158
	u8 waterParam;              // 0x15c (0 or 1, up or town)
	bool active;                // 0x15d
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	WaterDiamond();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~WaterDiamond() override;
	
	void UpdateModelTransform();
	void CheckClsnWithPlayer();
	void SetWaterID();
};