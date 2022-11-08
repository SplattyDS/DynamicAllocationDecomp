#include "PeachPainting.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[PEACH_PAINTING_OBJECT_ID] = PEACH_PAINTING_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[PEACH_PAINTING_ACTOR_ID] = (u32)&PeachPainting::spawnData;
	
	// construct shared file pointers
	PeachPainting::modelFile.Construct(LIGHT_BEAM_MODEL_FILE_ID);
}

void cleanup()
{
	
}