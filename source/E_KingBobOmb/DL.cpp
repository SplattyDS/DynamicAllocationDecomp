#include "KingBobOmb.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[KING_BOB_OMB_OBJECT_ID] = KING_BOB_OMB_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[KING_BOB_OMB_ACTOR_ID] = (u32)&KingBobOmb::spawnData;
	
	KingBobOmb::modelFile    .Construct(KING_BOB_OMB_MODEL_FILE_ID);
	KingBobOmb::animFiles[0] .Construct(KING_BOB_OMB_STRUGGLE_ANIM_FILE_ID);
	KingBobOmb::animFiles[1] .Construct(KING_BOB_OMB_WALK_1_ANIM_FILE_ID);
	KingBobOmb::animFiles[2] .Construct(KING_BOB_OMB_THROW_ANIM_FILE_ID);
	KingBobOmb::animFiles[3] .Construct(KING_BOB_OMB_START_ANIM_FILE_ID);
	KingBobOmb::animFiles[4] .Construct(KING_BOB_OMB_GETUP_ANIM_FILE_ID);
	KingBobOmb::animFiles[5] .Construct(KING_BOB_OMB_JUMPED_ANIM_FILE_ID);
	KingBobOmb::animFiles[6] .Construct(KING_BOB_OMB_JUMP_ANIM_FILE_ID);
	KingBobOmb::animFiles[7] .Construct(KING_BOB_OMB_LIFT_ANIM_FILE_ID);
	KingBobOmb::animFiles[8] .Construct(KING_BOB_OMB_DAMAGE_ANIM_FILE_ID);
	KingBobOmb::animFiles[9] .Construct(KING_BOB_OMB_WALK_2_ANIM_FILE_ID);
	KingBobOmb::animFiles[10].Construct(KING_BOB_OMB_WAIT_2_ANIM_FILE_ID);
	KingBobOmb::animFiles[11].Construct(KING_BOB_OMB_WAIT_1_ANIM_FILE_ID);
}

void cleanup()
{
	
}