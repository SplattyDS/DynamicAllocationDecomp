#pragma once

struct Ukiki : Actor
{
	enum Animations
	{
		HOLD,
		JUMP_ST,
		JUMP_ED,
		RUN_ST,
		RUN,
		RUN_ED,
		WAIT1,
		WAIT2,
		WAIT3,
		WAIT4,
		
		NUM_ANIMS,
	};
	
	enum Types
	{
		THIEF,
		STAR,
		
		NUM_TYPES,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
};