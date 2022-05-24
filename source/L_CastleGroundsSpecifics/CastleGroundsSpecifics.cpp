#include "CastleWater.h"
#include "MetalNet.h"
#include "Flag.h"
#include "Bird.h"

namespace
{
	enum fileIDs
	{
		CASTLE_WATER_MODEL_FILE_ID     = 0x693,
		CASTLE_WATER_COLLISION_FILE_ID = 0x694,
		METAL_NET_MODEL_FILE_ID        = 0x691,
		METAL_NET_COLLISION_FILE_ID    = 0x692,
		FLAG_MODEL_FILE_ID             = 0x68d,
		FLAG_ANIMATION_FILE_ID         = 0x68e,
		BIRD_MODEL_FILE_ID             = 0x438,
		BIRD_ANIMATION_FILE_ID         = 0x439
	};
	
	enum actorIDs
	{
		CASTLE_WATER_ACTOR_ID = 0x152,
		METAL_NET_ACTOR_ID    = 0x153,
		FLAG_ACTOR_ID         = 0x156,
		BIRD_ACTOR_ID         = 0x157
	};
	
	enum objectIDs
	{
		CASTLE_WATER_OBJECT_ID = 0x125,
		METAL_NET_OBJECT_ID    = 0x127,
		FLAG_OBJECT_ID         = 0x12a,
		BIRD_OBJECT_ID         = 0x35
	};
}

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[CASTLE_WATER_OBJECT_ID] = CASTLE_WATER_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[METAL_NET_OBJECT_ID]    = METAL_NET_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[FLAG_OBJECT_ID]         = FLAG_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BIRD_OBJECT_ID]         = BIRD_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[CASTLE_WATER_ACTOR_ID] = (unsigned)&CastleWater::spawnData;
	ACTOR_SPAWN_TABLE[METAL_NET_ACTOR_ID]    = (unsigned)&MetalNet::spawnData;
	ACTOR_SPAWN_TABLE[FLAG_ACTOR_ID]         = (unsigned)&Flag::spawnData;
	ACTOR_SPAWN_TABLE[BIRD_ACTOR_ID]         = (unsigned)&Bird::spawnData;
	
	// construct shared file pointers
	CastleWater::modelFile.Construct(CASTLE_WATER_MODEL_FILE_ID);
	CastleWater::clsnFile.Construct(CASTLE_WATER_COLLISION_FILE_ID);
	MetalNet::modelFile.Construct(METAL_NET_MODEL_FILE_ID);
	MetalNet::clsnFile.Construct(METAL_NET_COLLISION_FILE_ID);
	Flag::modelFile.Construct(FLAG_MODEL_FILE_ID);
	Flag::animFile.Construct(FLAG_ANIMATION_FILE_ID);
	Bird::modelFile.Construct(BIRD_MODEL_FILE_ID);
	Bird::animFile.Construct(BIRD_ANIMATION_FILE_ID);
}

void cleanup()
{
	
}