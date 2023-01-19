#include "SM64DS_2.h"
#include "Actors/KingBobOmb.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[KING_BOB_OMB_OBJECT_ID] = KING_BOB_OMB_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[KING_BOB_OMB_ACTOR_ID] = &KingBobOmb::spawnData;
	
	KingBobOmb::modelFile    .Construct("data/enemy/bombking/bomb_king.bmd"ov0);
	KingBobOmb::animFiles[0] .Construct("data/enemy/bombking/bombking_struggle.bca"ov0);
	KingBobOmb::animFiles[1] .Construct("data/enemy/bombking/bombking_walk1.bca"ov0);
	KingBobOmb::animFiles[2] .Construct("data/enemy/bombking/bombking_throw.bca"ov0);
	KingBobOmb::animFiles[3] .Construct("data/enemy/bombking/bombking_start.bca"ov0);
	KingBobOmb::animFiles[4] .Construct("data/enemy/bombking/bombking_getup.bca"ov0);
	KingBobOmb::animFiles[5] .Construct("data/enemy/bombking/bombking_jumped.bca"ov0);
	KingBobOmb::animFiles[6] .Construct("data/enemy/bombking/bombking_jump.bca"ov0);
	KingBobOmb::animFiles[7] .Construct("data/enemy/bombking/bombking_lift.bca"ov0);
	KingBobOmb::animFiles[8] .Construct("data/enemy/bombking/bombking_damage.bca"ov0);
	KingBobOmb::animFiles[9] .Construct("data/enemy/bombking/bombking_walk2.bca"ov0);
	KingBobOmb::animFiles[10].Construct("data/enemy/bombking/bombking_wait2.bca"ov0);
	KingBobOmb::animFiles[11].Construct("data/enemy/bombking/bombking_wait1.bca"ov0);
}

void cleanup()
{
	
}