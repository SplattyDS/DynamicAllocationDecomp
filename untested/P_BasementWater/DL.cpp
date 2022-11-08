#include "BasementWater.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[BASEMENT_WATER_OBJECT_ID] = BASEMENT_WATER_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[BASEMENT_WATER_ACTOR_ID] = (u32)&BasementWater::spawnData;
	
	// construct shared file pointers
	BasementWater::modelFile.Construct(BASEMENT_WATER_MODEL_FILE_ID);
	BasementWater::clsnFile.Construct(BASEMENT_WATER_COLLISION_FILE_ID);
}

void cleanup()
{
	
}