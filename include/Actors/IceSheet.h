#pragma once

struct IceSheet : Platform
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	IceSheet();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~IceSheet() override;
	virtual void OnGroundPounded(Actor& groundPounder) override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	virtual void Kill() override;
};