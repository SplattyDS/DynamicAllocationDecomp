#pragma once

struct SwitchPillar : Platform
{
	bool groundPounded;
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	SwitchPillar();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~SwitchPillar() override;
	virtual void OnGroundPounded(Actor& groundPounder) override;
};