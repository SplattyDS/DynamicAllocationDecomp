#pragma once

struct Unagi : Actor
{
	enum Animations
	{
		SEARCH,
		SWIM_START,
		SWIM,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static SpawnInfo spawnData;
};