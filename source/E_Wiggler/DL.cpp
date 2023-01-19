#include "SM64DS_2.h"
#include "Actors/Wiggler.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[WIGGLER_OBJECT_ID] = WIGGLER_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[WIGGLER_ACTOR_ID] = &Wiggler::spawnData;
	
	Wiggler::modelFiles[0].Construct("data/enemy/hanachan/hanachan_head.bmd"ov0);
	Wiggler::modelFiles[1].Construct("data/enemy/hanachan/hanachan_body01.bmd"ov0);
	Wiggler::modelFiles[2].Construct("data/enemy/hanachan/hanachan_body02.bmd"ov0);
	Wiggler::modelFiles[3].Construct("data/enemy/hanachan/hanachan_body03.bmd"ov0);
	Wiggler::modelFiles[4].Construct("data/enemy/hanachan/hanachan_body04.bmd"ov0);
	
	Wiggler::texSeqFiles[0].Construct("data/enemy/hanachan/hanachan_head.btp"ov0);
	Wiggler::texSeqFiles[1].Construct("data/enemy/hanachan/hanachan_body01.btp"ov0);
	Wiggler::texSeqFiles[2].Construct("data/enemy/hanachan/hanachan_body02.btp"ov0);
	Wiggler::texSeqFiles[3].Construct("data/enemy/hanachan/hanachan_body03.btp"ov0);
	Wiggler::texSeqFiles[4].Construct("data/enemy/hanachan/hanachan_body04.btp"ov0);
	
	Wiggler::waitAnimFiles[0].Construct("data/enemy/hanachan/hanachan_head_wait.bca"ov0);
	Wiggler::waitAnimFiles[1].Construct("data/enemy/hanachan/hanachan_body01_wait.bca"ov0);
	Wiggler::waitAnimFiles[2].Construct("data/enemy/hanachan/hanachan_body02_wait.bca"ov0);
	Wiggler::waitAnimFiles[3].Construct("data/enemy/hanachan/hanachan_body03_wait.bca"ov0);
	Wiggler::waitAnimFiles[4].Construct("data/enemy/hanachan/hanachan_body04_wait.bca"ov0);
	
	Wiggler::walkAnimFiles[0].Construct("data/enemy/hanachan/hanachan_head_walk.bca"ov0);
	Wiggler::walkAnimFiles[1].Construct("data/enemy/hanachan/hanachan_body01_walk.bca"ov0);
	Wiggler::walkAnimFiles[2].Construct("data/enemy/hanachan/hanachan_body02_walk.bca"ov0);
	Wiggler::walkAnimFiles[3].Construct("data/enemy/hanachan/hanachan_body03_walk.bca"ov0);
	Wiggler::walkAnimFiles[4].Construct("data/enemy/hanachan/hanachan_body04_walk.bca"ov0);
	
	Wiggler::walkStartAnimFiles[0].Construct("data/enemy/hanachan/hanachan_head_walk_start.bca"ov0);
	Wiggler::walkStartAnimFiles[1].Construct("data/enemy/hanachan/hanachan_body01_walk_start.bca"ov0);
	Wiggler::walkStartAnimFiles[2].Construct("data/enemy/hanachan/hanachan_body02_walk_start.bca"ov0);
	Wiggler::walkStartAnimFiles[3].Construct("data/enemy/hanachan/hanachan_body03_walk_start.bca"ov0);
	Wiggler::walkStartAnimFiles[4].Construct("data/enemy/hanachan/hanachan_body04_walk_start.bca"ov0);
	
	Wiggler::walkEndAnimFiles[0].Construct("data/enemy/hanachan/hanachan_head_walk_end.bca"ov0);
	Wiggler::walkEndAnimFiles[1].Construct("data/enemy/hanachan/hanachan_body01_walk_end.bca"ov0);
	Wiggler::walkEndAnimFiles[2].Construct("data/enemy/hanachan/hanachan_body02_walk_end.bca"ov0);
	Wiggler::walkEndAnimFiles[3].Construct("data/enemy/hanachan/hanachan_body03_walk_end.bca"ov0);
	Wiggler::walkEndAnimFiles[4].Construct("data/enemy/hanachan/hanachan_body04_walk_end.bca"ov0);
	
	Wiggler::damageAnimFiles[0].Construct("data/enemy/hanachan/hanachan_head_damage.bca"ov0);
	Wiggler::damageAnimFiles[1].Construct("data/enemy/hanachan/hanachan_body01_damage.bca"ov0);
	Wiggler::damageAnimFiles[2].Construct("data/enemy/hanachan/hanachan_body02_damage.bca"ov0);
	Wiggler::damageAnimFiles[3].Construct("data/enemy/hanachan/hanachan_body03_damage.bca"ov0);
	Wiggler::damageAnimFiles[4].Construct("data/enemy/hanachan/hanachan_body04_damage.bca"ov0);
}

void cleanup()
{
	
}