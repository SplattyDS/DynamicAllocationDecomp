#include "SM64DS_2.h"
#include "Actors/MetalNet.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[METAL_NET_OBJECT_ID] = METAL_NET_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[METAL_NET_ACTOR_ID] = &MetalNet::spawnData;
	
	MetalNet::modelFile.Construct("data/special_obj/mc_metalnet/mc_metalnet.bmd"ov0);
	MetalNet::clsnFile.Construct("data/special_obj/mc_metalnet/mc_metalnet.kcl"ov0);
}

void cleanup()
{
	
}