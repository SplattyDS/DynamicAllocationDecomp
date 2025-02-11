#pragma once

struct PoleBillboard : Actor
{
	Model model; // 0xd4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	PoleBillboard();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~PoleBillboard() override;
	
	void UpdateModelTransform();
};