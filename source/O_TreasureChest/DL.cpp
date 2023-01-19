#include "SM64DS_2.h"
#include "Actors/TreasureChest.h"
#include "Actors/Bubble.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[TREASURE_CHEST_OBJECT_ID] = TREASURE_CHEST_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[TREASURE_CHEST_ACTOR_ID] = &TreasureChest::spawnData;
	ACTOR_SPAWN_TABLE[BUBBLE_ACTOR_ID]         = &Bubble::spawnData;
	
	TreasureChest::modelFile.Construct("data/normal_obj/t_box/t_box.bmd"ov0);
	TreasureChest::animFile.Construct("data/normal_obj/t_box/t_box_open.bca"ov0);
}

void cleanup()
{
	
}