#include "SM64DS_2.h"
#include "Actors/ChainChompFence.h"
#include "Actors/ChainChomp.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[CHAIN_CHOMP_FENCE_OBJECT_ID] = CHAIN_CHOMP_FENCE_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[CHAIN_CHOMP_OBJECT_ID]       = CHAIN_CHOMP_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[CHAIN_CHOMP_FENCE_ACTOR_ID] = &ChainChompFence::spawnData;
	ACTOR_SPAWN_TABLE[CHAIN_CHOMP_ACTOR_ID]       = &ChainChomp::spawnData;
	
	ChainChompFence::modelFile.Construct("data/special_obj/b_wan_shutter/b_wan_shutter.bmd"ov0);
	ChainChompFence::clsnFile .Construct("data/special_obj/b_wan_shutter/b_wan_shutter.kcl"ov0);
	
	ChainChomp::modelFile     .Construct(0x9c02);
	ChainChomp::chainModelFile.Construct(0x9c01);
	ChainChomp::animFiles[ChainChomp::ATTACK].Construct(0x9c03);
	ChainChomp::animFiles[ChainChomp::WAIT]  .Construct(0x9c04);
}

void cleanup()
{
	
}