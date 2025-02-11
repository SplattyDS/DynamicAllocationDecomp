#pragma once

struct IceSlideManager : Actor
{
	u16 stateTimer;
	u8 state;
	
	static SpawnInfo spawnData;
	
	IceSlideManager();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~IceSlideManager() override;
};