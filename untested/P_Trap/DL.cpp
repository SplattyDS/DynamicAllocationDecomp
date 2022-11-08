#include "Trap.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[TRAP_OBJECT_ID] = TRAP_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[TRAP_ACTOR_ID] = (u32)&Trap::spawnData;
	
	// construct shared file pointers
	Trap::modelFile.Construct(TRAP_MODEL_FILE_ID);
	Trap::clsnFile.Construct(TRAP_COLLISION_FILE_ID);
}

void cleanup()
{
	
}