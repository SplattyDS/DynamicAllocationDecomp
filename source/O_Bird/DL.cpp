#include "Bird.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[BIRD_OBJECT_ID] = BIRD_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[BIRD_ACTOR_ID] = (u32)&Bird::spawnData;
	
	// construct shared file pointers
	Bird::modelFile.Construct(BIRD_MODEL_FILE_ID);
	Bird::animFile.Construct(BIRD_ANIMATION_FILE_ID);
}

void cleanup()
{
	
}