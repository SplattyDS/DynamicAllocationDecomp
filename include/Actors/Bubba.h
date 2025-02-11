#pragma once

struct Bubba : Enemy
{
	enum Animations
	{
		ATTACK,
		SWIM,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
};