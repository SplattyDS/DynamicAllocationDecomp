#include "Wiggler.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[WIGGLER_OBJECT_ID] = WIGGLER_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[WIGGLER_ACTOR_ID] = (u32)&Wiggler::spawnData;
	
	Wiggler::modelFiles[0].Construct(WIGGLER_HEAD_MODEL_FILE);
	Wiggler::modelFiles[1].Construct(WIGGLER_BODY_1_MODEL_FILE);
	Wiggler::modelFiles[2].Construct(WIGGLER_BODY_2_MODEL_FILE);
	Wiggler::modelFiles[3].Construct(WIGGLER_BODY_3_MODEL_FILE);
	Wiggler::modelFiles[4].Construct(WIGGLER_BODY_4_MODEL_FILE);
	
	Wiggler::texSeqFiles[0].Construct(WIGGLER_HEAD_TEXSEQ_FILE);
	Wiggler::texSeqFiles[1].Construct(WIGGLER_BODY_1_TEXSEQ_FILE);
	Wiggler::texSeqFiles[2].Construct(WIGGLER_BODY_2_TEXSEQ_FILE);
	Wiggler::texSeqFiles[3].Construct(WIGGLER_BODY_3_TEXSEQ_FILE);
	Wiggler::texSeqFiles[4].Construct(WIGGLER_BODY_4_TEXSEQ_FILE);
	
	Wiggler::waitAnimFiles[0].Construct(WIGGLER_HEAD_WAIT_ANIM_FILE);
	Wiggler::waitAnimFiles[1].Construct(WIGGLER_BODY_1_WAIT_ANIM_FILE);
	Wiggler::waitAnimFiles[2].Construct(WIGGLER_BODY_2_WAIT_ANIM_FILE);
	Wiggler::waitAnimFiles[3].Construct(WIGGLER_BODY_3_WAIT_ANIM_FILE);
	Wiggler::waitAnimFiles[4].Construct(WIGGLER_BODY_4_WAIT_ANIM_FILE);
	
	Wiggler::walkAnimFiles[0].Construct(WIGGLER_HEAD_WALK_ANIM_FILE);
	Wiggler::walkAnimFiles[1].Construct(WIGGLER_BODY_1_WALK_ANIM_FILE);
	Wiggler::walkAnimFiles[2].Construct(WIGGLER_BODY_2_WALK_ANIM_FILE);
	Wiggler::walkAnimFiles[3].Construct(WIGGLER_BODY_3_WALK_ANIM_FILE);
	Wiggler::walkAnimFiles[4].Construct(WIGGLER_BODY_4_WALK_ANIM_FILE);
	
	Wiggler::walkStartAnimFiles[0].Construct(WIGGLER_HEAD_WALK_START_ANIM_FILE);
	Wiggler::walkStartAnimFiles[1].Construct(WIGGLER_BODY_1_WALK_START_ANIM_FILE);
	Wiggler::walkStartAnimFiles[2].Construct(WIGGLER_BODY_2_WALK_START_ANIM_FILE);
	Wiggler::walkStartAnimFiles[3].Construct(WIGGLER_BODY_3_WALK_START_ANIM_FILE);
	Wiggler::walkStartAnimFiles[4].Construct(WIGGLER_BODY_4_WALK_START_ANIM_FILE);
	
	Wiggler::walkEndAnimFiles[0].Construct(WIGGLER_HEAD_WALK_END_ANIM_FILE);
	Wiggler::walkEndAnimFiles[1].Construct(WIGGLER_BODY_1_WALK_END_ANIM_FILE);
	Wiggler::walkEndAnimFiles[2].Construct(WIGGLER_BODY_2_WALK_END_ANIM_FILE);
	Wiggler::walkEndAnimFiles[3].Construct(WIGGLER_BODY_3_WALK_END_ANIM_FILE);
	Wiggler::walkEndAnimFiles[4].Construct(WIGGLER_BODY_4_WALK_END_ANIM_FILE);
	
	Wiggler::damageAnimFiles[0].Construct(WIGGLER_HEAD_DAMAGE_ANIM_FILE);
	Wiggler::damageAnimFiles[1].Construct(WIGGLER_BODY_1_DAMAGE_ANIM_FILE);
	Wiggler::damageAnimFiles[2].Construct(WIGGLER_BODY_2_DAMAGE_ANIM_FILE);
	Wiggler::damageAnimFiles[3].Construct(WIGGLER_BODY_3_DAMAGE_ANIM_FILE);
	Wiggler::damageAnimFiles[4].Construct(WIGGLER_BODY_4_DAMAGE_ANIM_FILE);
}

void cleanup()
{
	
}