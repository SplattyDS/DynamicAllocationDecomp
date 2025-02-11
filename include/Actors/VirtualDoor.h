#pragma once

struct VirtualDoor : Actor
{
	static SpawnInfo spawnData;
	
	VirtualDoor();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~VirtualDoor() override;
};