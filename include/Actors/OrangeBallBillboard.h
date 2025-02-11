#pragma once

struct OrangeBallBillboard : Actor
{
	Model model; // 0xd4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	OrangeBallBillboard();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~OrangeBallBillboard() override;
	
	void UpdateModelTransform();
};