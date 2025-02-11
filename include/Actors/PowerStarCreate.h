#pragma once

struct PowerStarCreate : Actor
{
	PowerStarCreate();
	virtual s32 Behavior() override;
	virtual ~PowerStarCreate() override;
	
	static SpawnInfo spawnData;
};