#pragma once

struct PyramidTop : Platform
{
	// Model model;           // 0x320 (now uses Platform::model)
	// Matrix4x3 clsnNextMat; // 0x370 (now uses Platform::clsnNextMat)
	Vector3 originalPos; // 0x3a0
	u32 spinParticleID;  // 0x3ac
	s16 angVelY;         // 0x3b0
	u16 stateTimer;      // 0x3b2
	u16 soundTimer;      // 0x3b4
	u8 numTagsTriggered; // 0x3b6
	u8 state;            // 0x3b7
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	PyramidTop();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~PyramidTop() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
	void Spin();
	void Kill();
};