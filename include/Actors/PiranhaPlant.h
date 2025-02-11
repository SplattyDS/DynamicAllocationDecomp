#pragma once

struct PiranhaPlant : Actor
{
	enum Animations
	{
		ATTACK,
		DEAD,
		SLEEP,
		SLEEP_LOOP,
		FIRE,
		FIRE_ED,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile; // 0x02130dfc
	static SharedFilePtr animFiles[NUM_ANIMS]; // 0x021302f4
	
	static SpawnInfo spawnData;
};

struct FirePiranhaPlant : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData;
	static SpawnInfo spawnDataBig;
	static SpawnInfo spawnDataSmall;
};