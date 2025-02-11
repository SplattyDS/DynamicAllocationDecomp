#pragma once

struct ClockPaintingPendulum : Actor
{
	Model model;  // 0xd4
	s16 angSpeed; // 0x124
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	ClockPaintingPendulum();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ClockPaintingPendulum() override;
	
	void UpdateModelTransform();
};