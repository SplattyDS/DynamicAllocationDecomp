#include "Bowser.h"
#include "BowserFire.h"
#include "BowserShockwaves.h"
#include "BowserFireSeaArena.h"
#include "BowserSkyPlatform.h"
#include "SpikeBomb.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_OBJECT_ID] = BOWSER_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_SHOCKWAVES_OBJECT_ID] = BOWSER_SHOCKWAVES_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_FIRE_SEA_ARENA_OBJECT_ID] = BOWSER_FIRE_SEA_ARENA_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[BOWSER_SKY_PLATFORM_OBJECT_ID] = BOWSER_SKY_PLATFORM_ACTOR_ID;
	OBJ_TO_ACTOR_ID_TABLE[SPIKE_BOMB_OBJECT_ID] = SPIKE_BOMB_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[BOWSER_ACTOR_ID] = (u32)&Bowser::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_TAIL_ACTOR_ID] = (u32)&BowserTail::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_FIRE_ACTOR_ID] = (u32)&BowserFire::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_SHOCKWAVES_ACTOR_ID] = (u32)&BowserShockwaves::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_FIRE_SEA_ARENA_ACTOR_ID] = (u32)&BowserFireSeaArena::spawnData;
	ACTOR_SPAWN_TABLE[BOWSER_SKY_PLATFORM_ACTOR_ID] = (u32)&BowserSkyPlatform::spawnData;
	ACTOR_SPAWN_TABLE[SPIKE_BOMB_ACTOR_ID] = (u32)&SpikeBomb::spawnData;
	
	Bowser::modelFile.Construct(BOWSER_MODEL_FILE_ID);
	
	Bowser::texSeqFiles[0].Construct(BOWSER_DAMAGE_2_ST_TEXSEQ_FILE_ID);
	Bowser::texSeqFiles[1].Construct(BOWSER_DAMAGE_2_ED_TEXSEQ_FILE_ID);
	Bowser::texSeqFiles[2].Construct(BOWSER_DEAD_TEXSEQ_FILE_ID);
	Bowser::texSeqFiles[3].Construct(BOWSER_THROW_TEXSEQ_FILE_ID);
	Bowser::texSeqFiles[4].Construct(BOWSER_WAIT_TEXSEQ_FILE_ID);
	Bowser::texSeqFiles[5].Construct(BOWSER_HOLD_TEXSEQ_FILE_ID);
	
	Bowser::animFiles[0] .Construct(BOWSER_DAMAGE_ANIM_FILE_ID);
	Bowser::animFiles[1] .Construct(BOWSER_DAMAGE_2_ST_ANIM_FILE_ID);
	Bowser::animFiles[2] .Construct(BOWSER_DAMAGE_2_ED_ANIM_FILE_ID);
	Bowser::animFiles[3] .Construct(BOWSER_DEAD_ANIM_FILE_ID);
	Bowser::animFiles[4] .Construct(BOWSER_DEAD_ED_ANIM_FILE_ID);
	Bowser::animFiles[5] .Construct(BOWSER_DEAD_ST_ANIM_FILE_ID);
	Bowser::animFiles[6] .Construct(BOWSER_FIRE_ANIM_FILE_ID);
	Bowser::animFiles[7] .Construct(BOWSER_FIRE_ED_ANIM_FILE_ID);
	Bowser::animFiles[8] .Construct(BOWSER_FIRE_ST_ANIM_FILE_ID);
	Bowser::animFiles[9] .Construct(BOWSER_HOLD_ANIM_FILE_ID);
	Bowser::animFiles[10].Construct(BOWSER_HOLD_ST_ANIM_FILE_ID);
	Bowser::animFiles[11].Construct(BOWSER_JUMP_1_ANIM_FILE_ID);
	Bowser::animFiles[12].Construct(BOWSER_JUMP_2_ANIM_FILE_ID);
	Bowser::animFiles[13].Construct(BOWSER_STAND_UP_ANIM_FILE_ID);
	Bowser::animFiles[14].Construct(BOWSER_THROW_ANIM_FILE_ID);
	Bowser::animFiles[15].Construct(BOWSER_VEXING_ANIM_FILE_ID);
	Bowser::animFiles[16].Construct(BOWSER_WAIT_1_ANIM_FILE_ID);
	Bowser::animFiles[17].Construct(BOWSER_WALK_ANIM_FILE_ID);
	Bowser::animFiles[18].Construct(BOWSER_WALK_ED_ANIM_FILE_ID);
	Bowser::animFiles[19].Construct(BOWSER_WALK_ST_ANIM_FILE_ID);
	Bowser::animFiles[20].Construct(BOWSER_FIRE_2_ANIM_FILE_ID);
	Bowser::animFiles[21].Construct(BOWSER_FIRE_3_ANIM_FILE_ID);
	Bowser::animFiles[22].Construct(BOWSER_FIRE_3_ST_ANIM_FILE_ID);
	Bowser::animFiles[23].Construct(BOWSER_FIRE_3_ED_ANIM_FILE_ID);
	Bowser::animFiles[24].Construct(BOWSER_DUSH_ST_ANIM_FILE_ID);
	Bowser::animFiles[25].Construct(BOWSER_DUSH_ANIM_FILE_ID);
	Bowser::animFiles[26].Construct(BOWSER_DUSH_ED_ANIM_FILE_ID);
	Bowser::animFiles[27].Construct(BOWSER_STRETCH_ANIM_FILE_ID);
	
	BowserShockwaves::modelFile .Construct(BOWSER_SHOCKWAVE_MODEL_FILE_ID);
	BowserShockwaves::texSeqFile.Construct(BOWSER_SHOCKWAVE_TEXSEQ_FILE_ID);
	BowserShockwaves::animFile  .Construct(BOWSER_SHOCKWAVE_ANIM_FILE_ID);
	
	BowserFireSeaArena::modelFile.Construct(BOWSER_FIRE_SEA_ARENA_MODEL_FILE_ID);
	BowserFireSeaArena::clsnFile .Construct(BOWSER_FIRE_SEA_ARENA_CLSN_FILE_ID);
	
	BowserSkyPlatform::modelFiles[0].Construct(BOWSER_SKY_PLATFORM_A_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[1].Construct(BOWSER_SKY_PLATFORM_B_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[2].Construct(BOWSER_SKY_PLATFORM_C_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[3].Construct(BOWSER_SKY_PLATFORM_D_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[4].Construct(BOWSER_SKY_PLATFORM_E_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[5].Construct(BOWSER_SKY_PLATFORM_F_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[6].Construct(BOWSER_SKY_PLATFORM_G_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[7].Construct(BOWSER_SKY_PLATFORM_H_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[8].Construct(BOWSER_SKY_PLATFORM_I_MODEL_FILE_ID);
	BowserSkyPlatform::modelFiles[9].Construct(BOWSER_SKY_PLATFORM_J_MODEL_FILE_ID);
	
	BowserSkyPlatform::clsnFiles[0].Construct(BOWSER_SKY_PLATFORM_A_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[1].Construct(BOWSER_SKY_PLATFORM_B_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[2].Construct(BOWSER_SKY_PLATFORM_C_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[3].Construct(BOWSER_SKY_PLATFORM_D_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[4].Construct(BOWSER_SKY_PLATFORM_E_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[5].Construct(BOWSER_SKY_PLATFORM_F_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[6].Construct(BOWSER_SKY_PLATFORM_G_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[7].Construct(BOWSER_SKY_PLATFORM_H_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[8].Construct(BOWSER_SKY_PLATFORM_I_CLSN_FILE_ID);
	BowserSkyPlatform::clsnFiles[9].Construct(BOWSER_SKY_PLATFORM_J_CLSN_FILE_ID);
	
	SpikeBomb::modelFile.Construct(SPIKE_BOMB_MODEL_FILE_ID);
}

void cleanup()
{
	
}