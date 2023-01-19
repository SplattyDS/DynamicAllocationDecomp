#include "SM64DS_2.h"
#include "Actors/Bowser.h"
#include "Actors/BowserFire.h"
#include "Actors/BowserShockwaves.h"
#include "Actors/BowserFireSeaArena.h"
#include "Actors/BowserSkyPlatform.h"
#include "Actors/SpikeBomb.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_OBJECT_ID] = BOWSER_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_SHOCKWAVES_OBJECT_ID] = BOWSER_SHOCKWAVES_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_FIRE_SEA_ARENA_OBJECT_ID] = BOWSER_FIRE_SEA_ARENA_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_SKY_PLATFORM_OBJECT_ID] = BOWSER_SKY_PLATFORM_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[SPIKE_BOMB_OBJECT_ID] = SPIKE_BOMB_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[BOWSER_ACTOR_ID] = &Bowser::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_TAIL_ACTOR_ID] = &BowserTail::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_FIRE_ACTOR_ID] = &BowserFire::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_SHOCKWAVES_ACTOR_ID] = &BowserShockwaves::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_FIRE_SEA_ARENA_ACTOR_ID] = &BowserFireSeaArena::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_SKY_PLATFORM_ACTOR_ID] = &BowserSkyPlatform::spawnData;
	ACTOR_SPAWN_TABLE[SPIKE_BOMB_ACTOR_ID] = &SpikeBomb::spawnData;
	
	Bowser::modelFile.Construct("data/enemy/koopa/koopa_model.bmd"ov0);
	
	Bowser::texSeqFiles[0].Construct("data/enemy/koopa/koopa_damage2_st.btp"ov0);
	Bowser::texSeqFiles[1].Construct("data/enemy/koopa/koopa_damage2_ed.btp"ov0);
	Bowser::texSeqFiles[2].Construct("data/enemy/koopa/koopa_dead.btp"ov0);
	Bowser::texSeqFiles[3].Construct("data/enemy/koopa/koopa_throw.btp"ov0);
	Bowser::texSeqFiles[4].Construct("data/enemy/koopa/koopa_wait.btp"ov0);
	Bowser::texSeqFiles[5].Construct("data/enemy/koopa/koopa_hold.btp"ov0);
	
	Bowser::animFiles[0] .Construct("data/enemy/koopa/koopa_damage.bca"ov0);
	Bowser::animFiles[1] .Construct("data/enemy/koopa/koopa_damage2_st.bca"ov0);
	Bowser::animFiles[2] .Construct("data/enemy/koopa/koopa_damage2_ed.bca"ov0);
	Bowser::animFiles[3] .Construct("data/enemy/koopa/koopa_dead.bca"ov0);
	Bowser::animFiles[4] .Construct("data/enemy/koopa/koopa_dead_ed.bca"ov0);
	Bowser::animFiles[5] .Construct("data/enemy/koopa/koopa_dead_st.bca"ov0);
	Bowser::animFiles[6] .Construct("data/enemy/koopa/koopa_fire.bca"ov0);
	Bowser::animFiles[7] .Construct("data/enemy/koopa/koopa_fire_ed.bca"ov0);
	Bowser::animFiles[8] .Construct("data/enemy/koopa/koopa_fire_st.bca"ov0);
	Bowser::animFiles[9] .Construct("data/enemy/koopa/koopa_hold.bca"ov0);
	Bowser::animFiles[10].Construct("data/enemy/koopa/koopa_hold_st.bca"ov0);
	Bowser::animFiles[11].Construct("data/enemy/koopa/koopa_jump1.bca"ov0);
	Bowser::animFiles[12].Construct("data/enemy/koopa/koopa_jump2.bca"ov0);
	Bowser::animFiles[13].Construct("data/enemy/koopa/koopa_stand_up.bca"ov0);
	Bowser::animFiles[14].Construct("data/enemy/koopa/koopa_throw.bca"ov0);
	Bowser::animFiles[15].Construct("data/enemy/koopa/koopa_vexing.bca"ov0);
	Bowser::animFiles[16].Construct("data/enemy/koopa/koopa_wait1.bca"ov0);
	Bowser::animFiles[17].Construct("data/enemy/koopa/koopa_walk.bca"ov0);
	Bowser::animFiles[18].Construct("data/enemy/koopa/koopa_walk_ed.bca"ov0);
	Bowser::animFiles[19].Construct("data/enemy/koopa/koopa_walk_st.bca"ov0);
	Bowser::animFiles[20].Construct("data/enemy/koopa/koopa_fire2.bca"ov0);
	Bowser::animFiles[21].Construct("data/enemy/koopa/koopa_fire3.bca"ov0);
	Bowser::animFiles[22].Construct("data/enemy/koopa/koopa_fire3_st.bca"ov0);
	Bowser::animFiles[23].Construct("data/enemy/koopa/koopa_fire3_ed.bca"ov0);
	Bowser::animFiles[24].Construct("data/enemy/koopa/koopa_dush_st.bca"ov0);
	Bowser::animFiles[25].Construct("data/enemy/koopa/koopa_dush.bca"ov0);
	Bowser::animFiles[26].Construct("data/enemy/koopa/koopa_dush_ed.bca"ov0);
	Bowser::animFiles[27].Construct("data/enemy/koopa/koopa_stretch.bca"ov0);
	
	BowserShockwaves::modelFile .Construct("data/enemy/kpa_shwave/kpa_shwave.bmd"ov0);
	BowserShockwaves::texSeqFile.Construct("data/enemy/kpa_shwave/kpa_shwave.btp"ov0);
	BowserShockwaves::animFile  .Construct("data/enemy/kpa_shwave/kpa_shwave.bca"ov0);
	
	BowserFireSeaArena::modelFile.Construct("data/special_obj/kb2_stage/kb2_stage.bmd"ov0);
	BowserFireSeaArena::clsnFile .Construct("data/special_obj/kb2_stage/kb2_stage.kcl"ov0);
	
	BowserSkyPlatform::modelFiles[0].Construct("data/special_obj/kb3_stage/kb3_a.bmd"ov0);
	BowserSkyPlatform::modelFiles[1].Construct("data/special_obj/kb3_stage/kb3_b.bmd"ov0);
	BowserSkyPlatform::modelFiles[2].Construct("data/special_obj/kb3_stage/kb3_c.bmd"ov0);
	BowserSkyPlatform::modelFiles[3].Construct("data/special_obj/kb3_stage/kb3_d.bmd"ov0);
	BowserSkyPlatform::modelFiles[4].Construct("data/special_obj/kb3_stage/kb3_e.bmd"ov0);
	BowserSkyPlatform::modelFiles[5].Construct("data/special_obj/kb3_stage/kb3_f.bmd"ov0);
	BowserSkyPlatform::modelFiles[6].Construct("data/special_obj/kb3_stage/kb3_g.bmd"ov0);
	BowserSkyPlatform::modelFiles[7].Construct("data/special_obj/kb3_stage/kb3_h.bmd"ov0);
	BowserSkyPlatform::modelFiles[8].Construct("data/special_obj/kb3_stage/kb3_i.bmd"ov0);
	BowserSkyPlatform::modelFiles[9].Construct("data/special_obj/kb3_stage/kb3_j.bmd"ov0);
	
	BowserSkyPlatform::clsnFiles[0].Construct("data/special_obj/kb3_stage/kb3_a.kcl"ov0);
	BowserSkyPlatform::clsnFiles[1].Construct("data/special_obj/kb3_stage/kb3_b.kcl"ov0);
	BowserSkyPlatform::clsnFiles[2].Construct("data/special_obj/kb3_stage/kb3_c.kcl"ov0);
	BowserSkyPlatform::clsnFiles[3].Construct("data/special_obj/kb3_stage/kb3_d.kcl"ov0);
	BowserSkyPlatform::clsnFiles[4].Construct("data/special_obj/kb3_stage/kb3_e.kcl"ov0);
	BowserSkyPlatform::clsnFiles[5].Construct("data/special_obj/kb3_stage/kb3_f.kcl"ov0);
	BowserSkyPlatform::clsnFiles[6].Construct("data/special_obj/kb3_stage/kb3_g.kcl"ov0);
	BowserSkyPlatform::clsnFiles[7].Construct("data/special_obj/kb3_stage/kb3_h.kcl"ov0);
	BowserSkyPlatform::clsnFiles[8].Construct("data/special_obj/kb3_stage/kb3_i.kcl"ov0);
	BowserSkyPlatform::clsnFiles[9].Construct("data/special_obj/kb3_stage/kb3_j.kcl"ov0);
	
	SpikeBomb::modelFile.Construct("data/enemy/koopa_bomb/koopa_bomb.bmd"ov0);
}

void cleanup()
{
	
}