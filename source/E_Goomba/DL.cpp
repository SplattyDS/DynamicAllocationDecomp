#include "Goomba.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[GOOMBA_OBJECT_ID]       = GOOMBA_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[SMALL_GOOMBA_OBJECT_ID] = SMALL_GOOMBA_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[LARGE_GOOMBA_OBJECT_ID] = LARGE_GOOMBA_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[GOOMBA_ACTOR_ID]       = (u32)&Goomba::spawnData;
	ACTOR_SPAWN_TABLE[SMALL_GOOMBA_ACTOR_ID] = (u32)&Goomba::spawnDataSmall;
	ACTOR_SPAWN_TABLE[LARGE_GOOMBA_ACTOR_ID] = (u32)&Goomba::spawnDataLarge;
	
	Goomba::modelFile.Construct(GOOMBA_MODEL_FILE_ID);
	Goomba::animFiles[Goomba::WALK     ].Construct(GOOMBA_WALK_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::ROLLING  ].Construct(GOOMBA_ROLLING_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::STRETCH  ].Construct(GOOMBA_STRETCH_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::UNBALANCE].Construct(GOOMBA_UNBALANCE_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::RECOVER  ].Construct(GOOMBA_RECOVER_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::WAIT     ].Construct(GOOMBA_WAIT_ANIM_FILE_ID);
	Goomba::animFiles[Goomba::RUN      ].Construct(GOOMBA_RUN_ANIM_FILE_ID);
}

void cleanup()
{
	
}