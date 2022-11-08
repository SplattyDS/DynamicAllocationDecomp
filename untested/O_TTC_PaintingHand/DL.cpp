#include "SwitchPillar.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[SWITCH_PILLAR_OBJECT_ID] = SWITCH_PILLAR_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[SWITCH_PILLAR_ACTOR_ID] = (u32)&SwitchPillar::spawnData;
	
	// construct shared file pointers
	SwitchPillar::modelFile.Construct(SWITCH_PILLAR_MODEL_FILE_ID);
	SwitchPillar::clsnFile.Construct(SWITCH_PILLAR_COLLISION_FILE_ID);
}

void cleanup()
{
	
}