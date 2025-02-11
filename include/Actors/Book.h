#pragma once

struct Book : Enemy
{
	enum BookTypes
	{
		BOOK_SWITCH,
		BOOKEND,
		BOOK_SHOT,
		
		NUM_TYPES,
	};
	
	enum Models
	{
		NORMAL,
		MONSTER,
		
		NUM_MODELS,
	};
	
	enum Animations
	{
		ATTACK,
		ATTACK_LOOP,
		
		NUM_ANIMS,
	};
	
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData[NUM_TYPES];
	static SharedFilePtr modelFiles[NUM_MODELS];
	static SharedFilePtr animFiles[NUM_ANIMS];
};