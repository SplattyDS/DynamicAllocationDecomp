#include "SM64DS_2.h"
#include "Actors/Goomba.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[GOOMBA_OBJECT_ID]       = GOOMBA_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[GOOMBA_SMALL_OBJECT_ID] = GOOMBA_SMALL_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[GOOMBA_LARGE_OBJECT_ID] = GOOMBA_LARGE_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[GOOMBA_ACTOR_ID]       = &Goomba::spawnData[Goomba::NORMAL];
	ACTOR_SPAWN_TABLE[GOOMBA_SMALL_ACTOR_ID] = &Goomba::spawnData[Goomba::SMALL];
	ACTOR_SPAWN_TABLE[GOOMBA_LARGE_ACTOR_ID] = &Goomba::spawnData[Goomba::BIG];
	
	Goomba::modelFile.Construct("data/enemy/kuribo/kuribo_model.bmd"ov0);
	Goomba::animFiles[Goomba::WALK     ].Construct("data/enemy/kuribo/kuribo_walk.bca"ov0);
	Goomba::animFiles[Goomba::ROLLING  ].Construct("data/enemy/kuribo/kuribo_rolling.bca"ov0);
	Goomba::animFiles[Goomba::STRETCH  ].Construct("data/enemy/kuribo/kuribo_stretch.bca"ov0);
	Goomba::animFiles[Goomba::UNBALANCE].Construct("data/enemy/kuribo/kuribo_unbalance.bca"ov0);
	Goomba::animFiles[Goomba::RECOVER  ].Construct("data/enemy/kuribo/kuribo_recover.bca"ov0);
	Goomba::animFiles[Goomba::WAIT     ].Construct("data/enemy/kuribo/kuribo_wait.bca"ov0);
	Goomba::animFiles[Goomba::RUN      ].Construct("data/enemy/kuribo/kuribo_run.bca"ov0);
}

void cleanup()
{
	
}