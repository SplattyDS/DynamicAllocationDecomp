#pragma once

struct MotherPenguin : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;      // 0x02113c00
	static SharedFilePtr animFiles[2];   // 0x02113bf0, 0x02113c08
	static SharedFilePtr texSeqFiles[2]; // 0x02113bf8, 0x02113be8
	
	static SpawnInfo spawnData;
};