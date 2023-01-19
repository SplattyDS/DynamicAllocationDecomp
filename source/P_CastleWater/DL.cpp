#include "SM64DS_2.h"
#include "Actors/CastleWater.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[CASTLE_WATER_OBJECT_ID] = CASTLE_WATER_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[CASTLE_WATER_ACTOR_ID] = &CastleWater::spawnData;
	
	CastleWater::modelFile.Construct("data/special_obj/mc_water/mc_water.bmd"ov0);
	CastleWater::clsnFile.Construct("data/special_obj/mc_water/mc_water.kcl"ov0);
}

void cleanup()
{
	
}