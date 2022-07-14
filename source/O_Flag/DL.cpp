#include "Flag.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[FLAG_OBJECT_ID] = FLAG_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[FLAG_ACTOR_ID] = (u32)&Flag::spawnData;
	
	// construct shared file pointers
	Flag::modelFile.Construct(FLAG_MODEL_FILE_ID);
	Flag::animFile.Construct(FLAG_ANIMATION_FILE_ID);
}

void cleanup()
{
	
}