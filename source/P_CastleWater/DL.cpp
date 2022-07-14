#include "CastleWater.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[CASTLE_WATER_OBJECT_ID] = CASTLE_WATER_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[CASTLE_WATER_ACTOR_ID] = (u32)&CastleWater::spawnData;
	
	// construct shared file pointers
	CastleWater::modelFile.Construct(CASTLE_WATER_MODEL_FILE_ID);
	CastleWater::clsnFile.Construct(CASTLE_WATER_COLLISION_FILE_ID);
}

void cleanup()
{
	
}