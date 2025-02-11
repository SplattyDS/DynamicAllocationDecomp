#pragma once

struct PeachPainting : Actor
{
	Model model; // 0xd4
	u32 opacity; // 0x124
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	PeachPainting();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~PeachPainting() override;
	
	void UpdateModelTransform();
};