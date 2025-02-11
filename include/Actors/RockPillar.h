#pragma once

struct RockPillar : Platform
{
	u8 state;           // 0x31e
	u8 stateTimer;      // 0x31f
	s16 fallSpeed;      // 0x320
	s16 fallSpeedSpeed; // 0x322 (speed of fallSpeed)
	Player* player;     // 0x324
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	RockPillar();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~RockPillar() override;
	
	void UpdateModelTransform();
};