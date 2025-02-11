#pragma once

struct SwitchActivatedPlank : Platform
{
	// Model model;           // 0x320 (now uses Platform::model)
	// Matrix4x3 clsnNextMat; // 0x370 (now uses Platform::clsnNextMat)
	u16 stateTimer; // 0x3a0
	u8 state;       // 0x3a2
	bool visible;   // 0x3a3
	u8 eventID;     // 0x3a4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SwitchActivatedPlank();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SwitchActivatedPlank() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
};