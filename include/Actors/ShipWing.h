#pragma once

struct ShipWing : Platform
{
	CommonModel model;      // 0xd4
	Vector3_16 originalAng; // 0x110
	u16 rowTimer;           // 0x116
	bool leftHanded;        // 0x118
	bool makesNoise;        // 0x119
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	ShipWing();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ShipWing() override;
	
	void UpdateModelTransform();
};