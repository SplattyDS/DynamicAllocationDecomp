#pragma once

struct ExtendingPlatform : Actor
{
	bool growing;               // 0xd4
	Model model;                // 0xd8
	Matrix4x3 clsnNextMat;      // 0x128
	ExtendingMeshCollider clsn; // 0x158
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	ExtendingPlatform();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~ExtendingPlatform() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
};