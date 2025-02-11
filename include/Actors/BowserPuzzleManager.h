#pragma once

struct BowserPuzzleManager : Actor
{
	u8 puzzleStateFlags; // 0xd4 (0x01: player is standing on piece, 0x02: puzzle just finished)
	u8 timesFinished;    // 0xd5
	u8 numCoinsSpawned;  // 0xd6
	
	static SpawnInfo spawnData;
	
	BowserPuzzleManager();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~BowserPuzzleManager() override;
};