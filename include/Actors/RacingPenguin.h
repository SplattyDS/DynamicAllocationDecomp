#pragma once

struct RacingPenguin : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;      // 0x02113498
	static SharedFilePtr animFiles[7];   // 0x02113470, 0x021134a0, 0x02113478, 0x02113460, 0x02113480, 0x02113488, 0x02113490
	static SharedFilePtr texSeqFiles[3]; // 0x021134a8, 0x021134b0, 0x02113468
	
	static SpawnInfo spawnData;
};