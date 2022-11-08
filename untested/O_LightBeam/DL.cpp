#include "LightBeam.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[LIGHT_BEAM_OBJECT_ID] = LIGHT_BEAM_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[LIGHT_BEAM_ACTOR_ID] = (u32)&LightBeam::spawnData;
	
	// construct shared file pointers
	LightBeam::modelFile.Construct(LIGHT_BEAM_MODEL_FILE_ID);
}

void cleanup()
{
	
}