#include "Goomboss.h"
#include "ExplosionGoomba.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[GOOMBOSS_OBJECT_ID] = GOOMBOSS_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[GOOMBOSS_ACTOR_ID] = (unsigned)&Goomboss::spawnData;
	ACTOR_SPAWN_TABLE[EXPLOSION_GOOMBA_ACTOR_ID] = (unsigned)&ExplosionGoomba::spawnData;
	
	Goomboss::modelFile.Construct(GOOMBOSS_MODEL_FILE_ID);
	Goomboss::texSeqFile.Construct(GOOMBOSS_TEXANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::ANGER       ].Construct(GOOMBOSS_ANGER_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::DAMAGE_BACK ].Construct(GOOMBOSS_DAMAGE_BACK_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::DAMAGE_FRONT].Construct(GOOMBOSS_DAMAGE_FRONT_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::DOWN_START  ].Construct(GOOMBOSS_DOWN_START_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::DOWN        ].Construct(GOOMBOSS_DOWN_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::SERCH_WAIT  ].Construct(GOOMBOSS_SERCH_WAIT_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::TURN        ].Construct(GOOMBOSS_TURN_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::WAIT        ].Construct(GOOMBOSS_WAIT_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::WALK        ].Construct(GOOMBOSS_WALK_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::WALK_END    ].Construct(GOOMBOSS_WALK_END_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::WALK_START  ].Construct(GOOMBOSS_WALK_START_ANIM_FILE_ID);
	Goomboss::animFiles[Goomboss::SPAWN       ].Construct(GOOMBOSS_SPAWN_ANIM_FILE_ID);
	
	Goomboss::goombaModelFile.Construct(GOOMBA_MODEL_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::WALK     ].Construct(GOOMBA_WALK_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::ROLLING  ].Construct(GOOMBA_ROLLING_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::STRETCH  ].Construct(GOOMBA_STRETCH_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::UNBALANCE].Construct(GOOMBA_UNBALANCE_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::RECOVER  ].Construct(GOOMBA_RECOVER_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::WAIT     ].Construct(GOOMBA_WAIT_ANIM_FILE_ID);
	Goomboss::goombaAnimFiles[Goomba::RUN      ].Construct(GOOMBA_RUN_ANIM_FILE_ID);
	
	ExplosionGoomba::modelFile.Construct(GOOMBA_MODEL_FILE_ID);
	ExplosionGoomba::animFile.Construct(GOOMBA_UNBALANCE_ANIM_FILE_ID);
}

void cleanup()
{
	Goomboss::modelFile.Destroy();
	Goomboss::texSeqFile.Destroy();
	Goomboss::animFiles[Goomboss::ANGER       ].Destroy();
	Goomboss::animFiles[Goomboss::DAMAGE_BACK ].Destroy();
	Goomboss::animFiles[Goomboss::DAMAGE_FRONT].Destroy();
	Goomboss::animFiles[Goomboss::DOWN_START  ].Destroy();
	Goomboss::animFiles[Goomboss::DOWN        ].Destroy();
	Goomboss::animFiles[Goomboss::SERCH_WAIT  ].Destroy();
	Goomboss::animFiles[Goomboss::TURN        ].Destroy();
	Goomboss::animFiles[Goomboss::WAIT        ].Destroy();
	Goomboss::animFiles[Goomboss::WALK        ].Destroy();
	Goomboss::animFiles[Goomboss::WALK_START  ].Destroy();
	Goomboss::animFiles[Goomboss::WALK_END    ].Destroy();
	Goomboss::animFiles[Goomboss::SPAWN       ].Destroy();
	
	Goomboss::goombaModelFile.Destroy();
	Goomboss::goombaAnimFiles[Goomba::WALK     ].Destroy();
	Goomboss::goombaAnimFiles[Goomba::ROLLING  ].Destroy();
	Goomboss::goombaAnimFiles[Goomba::STRETCH  ].Destroy();
	Goomboss::goombaAnimFiles[Goomba::UNBALANCE].Destroy();
	Goomboss::goombaAnimFiles[Goomba::RECOVER  ].Destroy();
	Goomboss::goombaAnimFiles[Goomba::WAIT     ].Destroy();
	Goomboss::goombaAnimFiles[Goomba::RUN      ].Destroy();
	
	ExplosionGoomba::modelFile.Destroy();
	ExplosionGoomba::animFile.Destroy();
}