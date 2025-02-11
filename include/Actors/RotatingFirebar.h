#pragma once

struct RotatingFirebar : Platform
{
	static constexpr s32 NUM_FIRES = 8;
	
	u32 fireParticleIDs[NUM_FIRES];          // 0x320
	u32 emberParticleIDs[NUM_FIRES];         // 0x340
	CylinderClsnWithPos cylClsns[NUM_FIRES]; // 0x360
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	RotatingFirebar();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RotatingFirebar() override;
};