#pragma once

struct MugenBgm : Actor
{
	static SpawnInfo spawnData;
	static s8 endlessStairsFogAreaID;
	static Fog* endlessStairsFog;
	static s16 endlessStairsFogAngY;
	
	MugenBgm();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~MugenBgm() override;
	virtual Fog* GetEndlessStairsFog(); // was a static member function, but made it virtual because DL
};