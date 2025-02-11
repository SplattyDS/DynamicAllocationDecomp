#pragma once

struct LightBeam : Actor
{
	Model model;                       // 0xd4
	MovingCylinderClsnWithPos cylClsn; // 0x124
	Player* listener;                  // 0x164
	u16 soundTimer;                    // 0x168
	
	static SharedFilePtr modelFile;
	static SpawnInfo spawnData;
	
	LightBeam();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~LightBeam() override;
	
	void UpdateModelTransform();
};