#include "SM64DS_2.h"
#include "Actors/Bird.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[BIRD_OBJECT_ID] = BIRD_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[BIRD_ACTOR_ID] = &Bird::spawnData;
	
	Bird::modelFile.Construct("data/normal_obj/bird/bird.bmd"ov0);
	Bird::animFile.Construct("data/normal_obj/bird/bird_fly.bca"ov0);
}

void cleanup()
{
	
}