#pragma once

struct ChainChomp : Actor
{
	enum Animations
	{
		ATTACK,
		WAIT,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr chainModelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
};