#include "Eyerock.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[EYEROCK_OBJECT_ID] = EYEROCK_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[EYEROCK_ACTOR_ID] = (u32)&Eyerock::spawnData;
	
	Eyerock::modelFile.Construct(EYEROCK_MODEL_FILE_ID);
	Eyerock::clsnFile .Construct(EYEROCK_CLSN_FILE_ID);
	
	Eyerock::handModelFiles[0].Construct(EYEROCK_L_MODEL_FILE_ID);
	Eyerock::handModelFiles[1].Construct(EYEROCK_R_MODEL_FILE_ID);
	
	Eyerock::waitClsnFiles[0].Construct(EYEROCK_L_WAIT_CLSN_FILE_ID);
	Eyerock::waitClsnFiles[1].Construct(EYEROCK_R_WAIT_CLSN_FILE_ID);
	Eyerock::moveClsnFiles[0].Construct(EYEROCK_L_MOVE_CLSN_FILE_ID);
	Eyerock::moveClsnFiles[1].Construct(EYEROCK_R_MOVE_CLSN_FILE_ID);
	
	Eyerock::closeTexSeqFiles[0].Construct(EYEROCK_L_CLOSE_TEXSEQ_FILE_ID);
	Eyerock::closeTexSeqFiles[1].Construct(EYEROCK_R_CLOSE_TEXSEQ_FILE_ID);
	Eyerock::openTexSeqFiles[0] .Construct(EYEROCK_L_OPEN_TEXSEQ_FILE_ID);
	Eyerock::openTexSeqFiles[1] .Construct(EYEROCK_R_OPEN_TEXSEQ_FILE_ID);
	
	Eyerock::wakeUpAnimFiles[0] .Construct(EYEROCK_L_WAKE_UP_ANIM_FILE_ID);
	Eyerock::wakeUpAnimFiles[1] .Construct(EYEROCK_R_WAKE_UP_ANIM_FILE_ID);
	Eyerock::waitAnimFiles[0]   .Construct(EYEROCK_L_WAIT_ANIM_FILE_ID);
	Eyerock::waitAnimFiles[1]   .Construct(EYEROCK_R_WAIT_ANIM_FILE_ID);
	Eyerock::waitEndAnimFiles[0].Construct(EYEROCK_L_WAIT_END_ANIM_FILE_ID);
	Eyerock::waitEndAnimFiles[1].Construct(EYEROCK_R_WAIT_END_ANIM_FILE_ID);
	Eyerock::damageAnimFiles[0] .Construct(EYEROCK_L_DAMAGE_ANIM_FILE_ID);
	Eyerock::damageAnimFiles[1] .Construct(EYEROCK_R_DAMAGE_ANIM_FILE_ID);
	Eyerock::deadAnimFiles[0]   .Construct(EYEROCK_L_DEAD_ANIM_FILE_ID);
	Eyerock::deadAnimFiles[1]   .Construct(EYEROCK_R_DEAD_ANIM_FILE_ID);
}

void cleanup()
{
	
}