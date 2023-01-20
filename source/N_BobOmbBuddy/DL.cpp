#include "SM64DS_2.h"
#include "Actors/BobOmbBuddy.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[BOB_OMB_BUDDY_OBJECT_ID] = BOB_OMB_BUDDY_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[BOB_OMB_BUDDY_ACTOR_ID] = &BobOmbBuddy::spawnData;
	
	BobOmbBuddy::modelFile.Construct("data/enemy/bombhei/red_bombhei.bmd"ov0);
	BobOmbBuddy::animFile .Construct("data/enemy/bombhei/red_wait.bca"ov0);
}

void cleanup()
{
	
}