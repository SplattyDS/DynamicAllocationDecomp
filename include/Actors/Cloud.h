#pragma once

struct Cloud : Actor
{
	Model model; // 0xd4
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	Cloud();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Cloud() override;
	
	void UpdateModelTransform();
};