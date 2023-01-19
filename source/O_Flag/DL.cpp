#include "SM64DS_2.h"
#include "Actors/Flag.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[FLAG_OBJECT_ID] = FLAG_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[FLAG_ACTOR_ID] = &Flag::spawnData;
	
	Flag::modelFile.Construct("data/special_obj/mc_flag/mc_flag.bmd"ov0);
	Flag::animFile.Construct("data/special_obj/mc_flag/mc_flag_wait.bca"ov0);
}

void cleanup()
{
	
}