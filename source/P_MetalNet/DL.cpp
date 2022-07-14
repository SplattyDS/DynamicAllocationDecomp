#include "MetalNet.h"

void init()
{
	// modify object id to actor id table
	OBJ_TO_ACTOR_ID_TABLE[METAL_NET_OBJECT_ID] = METAL_NET_ACTOR_ID;
	
	// modify actor spawn table
	ACTOR_SPAWN_TABLE[METAL_NET_ACTOR_ID] = (u32)&MetalNet::spawnData;
	
	// construct shared file pointers
	MetalNet::modelFile.Construct(METAL_NET_MODEL_FILE_ID);
	MetalNet::clsnFile.Construct(METAL_NET_COLLISION_FILE_ID);
}

void cleanup()
{
	
}