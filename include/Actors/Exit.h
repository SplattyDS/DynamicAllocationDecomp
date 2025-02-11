#pragma once

struct Exit : Actor
{
	Matrix4x3 relativeTransformMat; // 0xd4
	
	static SpawnInfo spawnData;
	
	Exit();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Exit() override;
	
	void ExitLevel();
};