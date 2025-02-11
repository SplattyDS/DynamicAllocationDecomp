#pragma once

struct PyramidStep : Platform
{
	// Model model;           // 0x320 (now uses Platform::model)
	u16 stateTimer; // 0x370
	bool state;     // 0x372
	// Matrix4x3 clsnNextMat; // 0x374 (now uses Platform::clsnNextMat)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	PyramidStep();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~PyramidStep() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
};