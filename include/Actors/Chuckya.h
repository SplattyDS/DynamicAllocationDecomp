#pragma once

struct Chuckya : Actor
{
	enum Animations
	{
		LIFT_LOOP,
		LIFT,
		WALK,
		STRUGGLE,
		THROW,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static SpawnInfo spawnData;
};