#include "SM64DS_2.h"
#include "Actors/Goomboss.h"
#include "Actors/ExplosionGoomba.h"

void init()
{
	OBJ_TO_ACTOR_ID_TABLE[GOOMBOSS_OBJECT_ID] = GOOMBOSS_ACTOR_ID;
	
	ACTOR_SPAWN_TABLE[GOOMBOSS_ACTOR_ID] = &Goomboss::spawnData;
	ACTOR_SPAWN_TABLE[EXPLOSION_GOOMBA_ACTOR_ID] = &ExplosionGoomba::spawnData;
	
	Goomboss::modelFile.Construct("data/enemy/kuriking/kuriking_model.bmd"ov0);
	Goomboss::texSeqFile.Construct("data/enemy/kuriking/kuriking_anger.btp"ov0);
	Goomboss::animFiles[Goomboss::ANGER       ].Construct("data/enemy/kuriking/kuriking_anger.bca"ov0);
	Goomboss::animFiles[Goomboss::DAMAGE_BACK ].Construct("data/enemy/kuriking/kuriking_damage_b.bca"ov0);
	Goomboss::animFiles[Goomboss::DAMAGE_FRONT].Construct("data/enemy/kuriking/kuriking_damage_f.bca"ov0);
	Goomboss::animFiles[Goomboss::DOWN_START  ].Construct("data/enemy/kuriking/kuriking_down_start.bca"ov0);
	Goomboss::animFiles[Goomboss::DOWN        ].Construct("data/enemy/kuriking/kuriking_down.bca"ov0);
	Goomboss::animFiles[Goomboss::SERCH_WAIT  ].Construct("data/enemy/kuriking/kuriking_serch_wait.bca"ov0);
	Goomboss::animFiles[Goomboss::TURN        ].Construct("data/enemy/kuriking/kuriking_turn.bca"ov0);
	Goomboss::animFiles[Goomboss::WAIT        ].Construct("data/enemy/kuriking/kuriking_wait.bca"ov0);
	Goomboss::animFiles[Goomboss::WALK        ].Construct("data/enemy/kuriking/kuriking_walk.bca"ov0);
	Goomboss::animFiles[Goomboss::WALK_END    ].Construct("data/enemy/kuriking/kuriking_walk_end.bca"ov0);
	Goomboss::animFiles[Goomboss::WALK_START  ].Construct("data/enemy/kuriking/kuriking_walk_start.bca"ov0);
	Goomboss::animFiles[Goomboss::SPAWN       ].Construct("data/enemy/kuriking/kuriking_spawn.bca"ov0);
	
	Goomboss::goombaModelFile.Construct("data/enemy/kuribo/kuribo_model.bmd"ov0);
	Goomboss::goombaAnimFiles[Goomba::WALK     ].Construct("data/enemy/kuribo/kuribo_walk.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::ROLLING  ].Construct("data/enemy/kuribo/kuribo_rolling.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::STRETCH  ].Construct("data/enemy/kuribo/kuribo_stretch.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::UNBALANCE].Construct("data/enemy/kuribo/kuribo_unbalance.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::RECOVER  ].Construct("data/enemy/kuribo/kuribo_recover.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::WAIT     ].Construct("data/enemy/kuribo/kuribo_wait.bca"ov0);
	Goomboss::goombaAnimFiles[Goomba::RUN      ].Construct("data/enemy/kuribo/kuribo_run.bca"ov0);
	
	ExplosionGoomba::modelFile.Construct("data/enemy/kuribo/kuribo_model.bmd"ov0);
	ExplosionGoomba::animFile.Construct("data/enemy/kuribo/kuribo_unbalance.bca"ov0);
}

void cleanup()
{
	
}