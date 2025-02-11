#pragma once

struct BigBooIcon : Actor
{
	s8 trackStarID;
	u8 starID;
	
	static SpawnInfo spawnData;
	
	BigBooIcon();
	virtual s32 InitResources() override;
	virtual ~BigBooIcon() override;
};