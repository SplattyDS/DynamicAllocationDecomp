#include "HootTheOwl.h"

void init()
{
	asm("mov r11, r11");
	OBJ_TO_ACTOR_ID_TABLE[HOOT_THE_OWL_OBJECT_ID] = HOOT_THE_OWL_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[HOOT_THE_OWL_ACTOR_ID] = (u32)&HootTheOwl::spawnData;
	
	HootTheOwl::modelFile   .Construct(HOOT_THE_OWL_MODEL_FILE_ID);
	HootTheOwl::animFiles[0].Construct(HOOT_THE_OWL_FLY_2_ANIM_FILE_ID);
	HootTheOwl::animFiles[1].Construct(HOOT_THE_OWL_FLY_FREE_ANIM_FILE_ID);
	HootTheOwl::animFiles[2].Construct(HOOT_THE_OWL_FLY_1_ANIM_FILE_ID);
}

void cleanup()
{
	
}