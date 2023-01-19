#include "SM64DS_2.h"
#include "Actors/HootTheOwl.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[HOOT_THE_OWL_OBJECT_ID] = HOOT_THE_OWL_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[HOOT_THE_OWL_ACTOR_ID] = &HootTheOwl::spawnData;
	
	HootTheOwl::modelFile   .Construct("data/enemy/owl/owl.bmd"ov0);
	HootTheOwl::animFiles[0].Construct("data/enemy/owl/owl_fly_2.bca"ov0);
	HootTheOwl::animFiles[1].Construct("data/enemy/owl/owl_fly_free.bca"ov0);
	HootTheOwl::animFiles[2].Construct("data/enemy/owl/owl_fly_1.bca"ov0);
}

void cleanup()
{
	
}