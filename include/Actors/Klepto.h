#pragma once

struct Klepto : Actor
{
	enum Animations
	{
		FLY,
		DAMAGE,
		ATTACK,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static SpawnInfo spawnData;
};