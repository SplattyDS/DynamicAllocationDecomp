#pragma once

struct Warp : Actor
{
	MovingCylinderClsn cylClsn; // 0xd4
	
	static SpawnInfo spawnData;
	
	Warp();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Warp() override;
};