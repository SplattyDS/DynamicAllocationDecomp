#include "SM64DS_2.h"
#include "Actors/Eyerok.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[EYEROK_OBJECT_ID] = EYEROK_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[EYEROK_ACTOR_ID] = &Eyerok::spawnData;
	
	Eyerok::modelFile.Construct("data/enemy/iwante/iwante_dummy.bmd"ov0);
	Eyerok::clsnFile .Construct("data/enemy/iwante/iwante.kcl"ov0);
	
	Eyerok::handModelFiles[0].Construct("data/enemy/iwante/iwante_lhand.bmd"ov0);
	Eyerok::handModelFiles[1].Construct("data/enemy/iwante/iwante_rhand.bmd"ov0);
	
	Eyerok::waitClsnFiles[0].Construct("data/enemy/iwante/iwante_wait_l.kcl"ov0);
	Eyerok::waitClsnFiles[1].Construct("data/enemy/iwante/iwante_wait_r.kcl"ov0);
	Eyerok::moveClsnFiles[0].Construct("data/enemy/iwante/iwante_move_l.kcl"ov0);
	Eyerok::moveClsnFiles[1].Construct("data/enemy/iwante/iwante_move_r.kcl"ov0);
	
	Eyerok::closeTexSeqFiles[0].Construct("data/enemy/iwante/iwante_close_l.btp"ov0);
	Eyerok::closeTexSeqFiles[1].Construct("data/enemy/iwante/iwante_close_r.btp"ov0);
	Eyerok::openTexSeqFiles[0] .Construct("data/enemy/iwante/iwante_open_l.btp"ov0);
	Eyerok::openTexSeqFiles[1] .Construct("data/enemy/iwante/iwante_open_r.btp"ov0);
	
	Eyerok::wakeUpAnimFiles[0] .Construct("data/enemy/iwante/iwante_wake_up_l.bca"ov0);
	Eyerok::wakeUpAnimFiles[1] .Construct("data/enemy/iwante/iwante_wake_up_r.bca"ov0);
	Eyerok::waitAnimFiles[0]   .Construct("data/enemy/iwante/iwante_wait_l.bca"ov0);
	Eyerok::waitAnimFiles[1]   .Construct("data/enemy/iwante/iwante_wait_r.bca"ov0);
	Eyerok::waitEndAnimFiles[0].Construct("data/enemy/iwante/iwante_wait_end_l.bca"ov0);
	Eyerok::waitEndAnimFiles[1].Construct("data/enemy/iwante/iwante_wait_end_r.bca"ov0);
	Eyerok::damageAnimFiles[0] .Construct("data/enemy/iwante/iwante_damage_l.bca"ov0);
	Eyerok::damageAnimFiles[1] .Construct("data/enemy/iwante/iwante_damage_r.bca"ov0);
	Eyerok::deadAnimFiles[0]   .Construct("data/enemy/iwante/iwante_dead_l.bca"ov0);
	Eyerok::deadAnimFiles[1]   .Construct("data/enemy/iwante/iwante_dead_r.bca"ov0);
}

void cleanup()
{
	
}