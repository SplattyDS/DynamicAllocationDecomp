#pragma once

struct Boo : CapEnemy
{
	enum Types
	{
		NORMAL,
		BIG,
		
		NUM_TYPES,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	static SharedFilePtr kingModelFile;
	static SharedFilePtr kingAnimFiles[3];
};