#include "SM64DS_2.h"
#include "Actors/Goomba.h"
#include "Actors/Goomboss.h"

namespace
{
	using StateFuncPtr = void(Goomba::*)();

	char materialName[] = "kuribo_all";
	u8 aliveMatVals[] = {0x1f, 0x10, 0x00, 0x00};
	BMA_File::MaterialProperties aliveMatProps =
	{
		0xffff, 0,
		&materialName[0],
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0001 },
		{ 0x01, 0x00, 0x0001 },
		{ 0x01, 0x00, 0x0001 },  
		{ 0x01, 0x00, 0x0002 },
		{ 0x01, 0x00, 0x0002 },
		{ 0x01, 0x00, 0x0002 }, 
		{ 0x01, 0x00, 0x0002 },
		{ 0x01, 0x00, 0x0002 },
		{ 0x01, 0x00, 0x0002 }, 
		{ 0x01, 0x00, 0x0000 }, 
	};
	BMA_File aliveMat = {0x0002, 0x0000, &aliveMatVals[0], 1, &aliveMatProps};

	u8 regurgMatVals[] = {0x00, 0x03, 0x0c, 0x16, 0x1f, 0x1f, 0x1f, 0x1f,
							0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
							0x1f, 0x10, 0x00, 0x00};
	BMA_File::MaterialProperties regurgMatProps =
	{
		0xffff, 0,
		&materialName[0],
		{ 0x01, 0x01, 0x0000 },
		{ 0x01, 0x00, 0x0004 },
		{ 0x01, 0x00, 0x0004 },
		{ 0x01, 0x00, 0x0011 },
		{ 0x01, 0x00, 0x0011 },
		{ 0x01, 0x00, 0x0011 }, 
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0000 },
		{ 0x01, 0x00, 0x0004 }, 
	};
	BMA_File regurgMat = {0x0011, 0x0000, &regurgMatVals[0], 1, &regurgMatProps};
	
	constexpr StateFuncPtr stateFuncs[] =
	{
		&Goomba::State0,
		&Goomba::State1,
		&Goomba::State2,
		&Goomba::State3,
		&Goomba::State4
	};
	
	constexpr Fix12i SCALES[]          = { 0.3333_f,    1._f,  2.3333_f,    1._f}; // 0x02130258
	constexpr Fix12i HORZ_CLSN_SIZES[] = {    40._f,  100._f,    224._f,  100._f}; // 0x02130208
	constexpr Fix12i VERT_ACCELS[]     = {-0.6666_f,   -2._f, -5.6666_f,   -2._f}; // 0x02130238
	constexpr Fix12i WALK_SPEEDS[]     = { 0.6666_f,    2._f,  4.6666_f,    6._f}; // 0x02130228
	constexpr Fix12i RUN_SPEEDS[]      = {   10.5_f,   21._f,     21._f,   21._f}; // 0x02130268
	constexpr Fix12i JUMP_SPEEDS[]     = {     8._f,   16._f,     32._f,   16._f}; // 0x02130248
	constexpr u32 DAMAGES[] = { 0, 1, 2, 1 };	// 0x02130204
	
	constexpr SoundIDs DYING_SOUNDS[] =
	{
		"NCS_SE_SCT_SKB_DOWN"sfx,
		"NCS_SE_SCT_KRB_DOWN"sfx,
		"NCS_SE_SCT_LKB_DOWN"sfx,
		"NCS_SE_SCT_KRB_DOWN"sfx,
	};
	
	constexpr Vector3 CAP_OFFSET = { 0._f, 108._f, 0._f };
	
	constexpr u32 CYL_CLSN_VULNERABLE_FLAGS =
		CylinderClsn::HIT_BY_SPIN_OR_GROUND_POUND |
		CylinderClsn::HIT_BY_PUNCH |
		CylinderClsn::HIT_BY_KICK |
		CylinderClsn::HIT_BY_BREAKDANCE |
		CylinderClsn::HIT_BY_SLIDE_KICK |
		CylinderClsn::HIT_BY_DIVE |
		CylinderClsn::HIT_BY_UNK_11 |
		CylinderClsn::HIT_BY_EGG |
		CylinderClsn::HIT_BY_EXPLOSION |
		CylinderClsn::HIT_BY_YOSHI_TONGUE |
		CylinderClsn::HIT_BY_REGURG_GOOMBA |
		CylinderClsn::HIT_BY_FIRE |
		CylinderClsn::HIT_BY_ENEMY |
		CylinderClsn::HIT_BY_INTERACT_WITH_PLAYER;
}

SpawnInfo Goomba::spawnData[NUM_SIZES]
{
	{
		[]() -> ActorBase* { return new Goomba; },
		0x00c9,
		0x0019,
		Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UNK_02 | Actor::AIMABLE_BY_EGG,
		50._f,
		70._f,
		1700._f,
		2048._f,
	},
	{
		[]() -> ActorBase* { return new Goomba; },
		0x00c8,
		0x0018,
		Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UNK_02 | Actor::AIMABLE_BY_EGG,
		50._f,
		70._f,
		4096._f,
		4096._f,
	},
	{
		[]() -> ActorBase* { return new Goomba; },
		0x00ca,
		0x001a,
		Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UNK_02 | Actor::AIMABLE_BY_EGG,
		100._f,
		200._f,
		4096._f,
		4096._f,
	},
};

GloballySharedFilePtr Goomba::modelFile;
GloballySharedFilePtr Goomba::animFiles[NUM_ANIMS];

s32 Goomba::InitResources()
{
	spawnStar = param1 >> 4 & 0xf;
	starID = 0xff;
	
	spawnCapFlag = param1 >> 8 & 0xf;
	starID_VS = param1 >> 0xc & 0xf;
	
	if (spawnStar == 1)
	{
		starID = TrackStar(0xf, 1);
		LoadSilverStarAndNumber();
	}
		
	Model::LoadFile(modelFile);
	for(s32 i = 0; i < NUM_ANIMS; ++i)
		Animation::LoadFile(animFiles[i]);
		
	AddCap((u8)param1 & 0xf);
	if (capID < 6)
		param1 &= 0xf0ff; // invalid cap, so never spawn cap
	
	if (!DestroyIfCapNotNeeded())
		return 0;
	
	if (!modelAnim.SetFile(modelFile.BMD(), 1, -1))
		return 0;
	
	if (!shadow.InitCylinder())
		return 0;
	
	MaterialChanger::Prepare(*modelFile.BMD(), aliveMat);
	materialChg.SetFile(aliveMat, Animation::NO_LOOP, 1._f, 0);
	coinType = Enemy::CN_YELLOW;

	if (actorID == GOOMBA_SMALL_ACTOR_ID)
	{
		type = Type::SMALL;
	}
	else if (actorID == GOOMBA_ACTOR_ID)
	{
		if (param1 - 0xeeeeU < 2)
		{
			type = Type::GOOMBOSS_GOOMBA;
			flags &= ~Actor::NO_RENDER_IF_OFF_SCREEN;
			if (param1 == 0xeeee)
				coinType = Enemy::CN_NONE;
		}
		else
		{
			type = Type::NORMAL;
		}
	}
	else
	{
		type = Type::BIG;
		LoadBlueCoinModel();
	}
	
	scale.x = scale.y = scale.z = SCALES[type];
	
	cylClsn.Init(this, scale.x * 60, HORZ_CLSN_SIZES[type], CylinderClsn::ENEMY, CYL_CLSN_VULNERABLE_FLAGS);
	if (type == Type::BIG)
		cylClsn.vulnerableFlags &= ~CylinderClsn::HIT_BY_KNOCK_PLAYER_DIZZY;
		
	wmClsn.Init(this, scale.x * 60, scale.x * 60, nullptr, nullptr);
	wmClsn.SetFlag_2();
	
	flags468 = state = 0;
	defeatMethod = Enemy::DF_NOT;
	player = nullptr;
	distToPlayer = Fix12i::max;
	
	targetDir = motionAng.y;
	targetSpeed = WALK_SPEEDS[type];
	movementTimer = goombossID = changeDirTimer = stuckInSpotTimer = 0;
	backupPos = pos;
	
	UpdateMaxDist();
	
	originalPos = pos;
	
	vertAccel = VERT_ACCELS[type];
	termVel = -50._f;
	
	modelAnim.SetAnim(animFiles[WALK].BCA(), Animation::LOOP, 1._f, 0);
	
	recoverFlags = 0;
	
	return 1;
}

s32 Goomba::CleanupResources()
{
	if (type == Type::BIG)
		UnloadBlueCoinModel();
	
	modelFile.Release();
	for(s32 i = 0; i < NUM_ANIMS; ++i)
		animFiles[i].Release();
	
	if (spawnStar == 1)
		UnloadSilverStarAndNumber();
	
	UnloadCapModel();
	
	Goomboss* goomboss;
	if (type == Type::GOOMBOSS_GOOMBA && goombossID != 0 && (goomboss = (Goomboss*)Actor::FindWithID(goombossID), goomboss != nullptr))
		goomboss->numGoombasAlive--;
	
	return 1;
}

s32 Goomba::Behavior()
{
	TrackVsStarIfNecessary();
	UpdateMaxDist();
	
	s32 capState = GetCapState();
	if (capState == 0)
		return 1;
	
	if (capState == 1)
	{
		flags |= Actor::AIMABLE_BY_EGG;
		PoofDust();
	}
	
	if (type != Type::GOOMBOSS_GOOMBA && state != 3 && !isBeingSpit 
		&& defeatMethod == Enemy::DF_NOT && IsTooFarAwayFromPlayer(1500._f) != 0)
	{
		Unk_02005d94();
		return 1;
	}
	
	if (defeatMethod != Enemy::DF_NOT)
	{
		s32 res = UpdateKillByInvincibleChar(wmClsn, modelAnim, 3);
		if (res == 0) // not killed by mega char
		{
			if (!UpdateIfDying())
				UpdateModelTransform();
		}
		else if (res == 2)  // killed by mega char
		{
			Kill();
			
			ReleaseCap(CAP_OFFSET);
			pos = originalPos;
			ang.x = ang.y = ang.z = 0;
			
			RespawnIfHasCap();
			SpawnStarIfNecessary();
		}
		return 1;
	}
	
	if (UpdateIfEaten())
		return 1;
	
	if (state < 3 && (type != Type::GOOMBOSS_GOOMBA || modelAnim.file != animFiles[WAIT].BCA()))
	{
		modelAnim.speed = horzSpeed / (2 * scale.x);
		if (modelAnim.speed > 3._f)
			modelAnim.speed = 3._f;
	}
	else
		modelAnim.speed = 1._f;
	
	MakeVanishLuigiWork(cylClsn);
	
	if (state != 2)
	{
		PlayMovingSound();
		modelAnim.Advance();
	}
	
	u32 prevState = state;
	(this->*stateFuncs[state])();
	
	++stateTimer;
	if (prevState != state)
		stateTimer = 0;
	
	GetHurtOrHurtPlayer();
	
	if (capID < 6)
		UpdatePos(nullptr);
	else
		UpdatePos(&cylClsn);
	
	if (defeatMethod == Enemy::DF_NOT && state != 2 && state != 3)
	{
		if (!IsGoingOffCliff(wmClsn, 50._f, 43.9948_deg, false, true, 50._f))
			noCliffPos = pos;
		else
			pos = noCliffPos;
	}
	
	// in BOB and TTC
	UpdateWMClsn(wmClsn, type == Type::SMALL ? 0 : ((LEVEL_ID == 6 || LEVEL_ID == 27) && targetSpeed == WALK_SPEEDS[type] && defeatMethod != 7) ? 3 : 2);
	
	KillIfTouchedBadSurface();
	
	cylClsn.Clear();
	if (defeatMethod == Enemy::DF_NOT)
		cylClsn.Update();
	
	UpdateModelTransform();
	KillIfIntoxicated();
	
	if (state == 0 && (flags & OFF_SCREEN) == 0)
	{
		if (pos.Dist(backupPos) < 10._f)
		{
			++stuckInSpotTimer;
			if (capID < 6 && stuckInSpotTimer == 30)
			{
				Jump();
				noChargeTimer = 90;
			}
			if (stuckInSpotTimer >= 300 && noChargeTimer == 0)
			{
				SpawnStarIfNecessary();
				SpawnCoin();
				Kill();
				ReleaseCap(CAP_OFFSET);
				pos = originalPos;
				RespawnIfHasCap();
			}
		}
		else
		{
			stuckInSpotTimer = 0;
			backupPos = pos;
		}
	}
	else if (noChargeTimer == 0)
		stuckInSpotTimer = 0;
	
	return 1;
}

s32 Goomba::Render()
{
	if ((flags & Actor::IN_YOSHI_MOUTH) || hasNotSpawned)
		return 1;
	
	Vector3 oldScale = scale;
	
	if (defeatMethod == Enemy::DF_SQUASHED)
	{
		scale.x = SCALES[type] * scale.x;
		scale.y = SCALES[type] * scale.y;
		scale.z = SCALES[type] * scale.z;
	}
	
	modelAnim.Render(&scale);
	
	scale = oldScale;
	
	materialChg.Update(modelAnim.data);
	RenderCapModel(nullptr);
	
	return 1;
}

void Goomba::OnPendingDestroy()
{
	return;
}

u32 Goomba::OnYoshiTryEat()
{
	switch (actorID)
	{
		case GOOMBA_ACTOR_ID:
			return Actor::YE_KEEP_AND_CAN_MAKE_EGG;
		case GOOMBA_SMALL_ACTOR_ID:
			return Actor::YE_SWALLOW;
		// case GOOMBA_LARGE_ACTOR_ID:
		default:
			return Actor::YE_DONT_EAT;
	}
}

void Goomba::OnTurnIntoEgg(Player& player)
{
	if ((capID & 0xf) < 6 || spawnStar == 2)
	{
		pos = originalPos;
		RespawnIfHasCap();
	}
	
	u32 res = OnYoshiTryEat();
	if (res == Actor::YE_KEEP_AND_CAN_MAKE_EGG)
	{
		if (!player.IsCollectingCap())
		{
			bool starUntracked = false;
			if (spawnStar == 1)
			{
				UntrackStar(starID);
				starUntracked = true;
				Actor::Spawn(STAR_MARKER_ACTOR_ID, 0x0050, originalPos, nullptr, areaID, -1);
				param1 &= 0xff0f;
			}
			else if (spawnStar == 2 && starID_VS == VS_STAR_SPAWN_ORDER[NUM_VS_STARS_COLLECTED])
			{
				UntrackStar(starID);
				spawnStar = 3;
				starUntracked = true;
			}
			
			player.RegisterEggCoinCount(coinType == 1, starUntracked, false);
		}
		else
		{
			if (coinType == 1)
				Unk_0201061c(player, 1, 0);
			
			SpawnStarIfNecessary();
		}
	}
	else if (res == Actor::YE_SWALLOW && coinType == 1)
	{
		Unk_0201061c(player, 1, 0);
	}
	
	Kill();
}

Fix12i Goomba::OnAimedAtWithEgg()
{
	switch (actorID)
	{
		case GOOMBA_ACTOR_ID:
			return 65._f;
		case GOOMBA_SMALL_ACTOR_ID:
			return 20._f;
		// case GOOMBA_LARGE_ACTOR_ID:
		default:
			return 150._f;
	}
}

BMA_File* Goomba::vGetRegurgMaterialDef()
{
	return &regurgMat;
}

void Goomba::vSetOriginalPos(Vector3& newOriginalPos)
{
	SetOriginalPos(newOriginalPos);
}

void Goomba::UpdateMaxDist()
{
	if (noChargeTimer != 0)
	{
		if (state == 1)
			noChargeTimer = 0;
		else
			--noChargeTimer;
	}
	else if (capID >= 6 && stuckInSpotTimer > 10)
	{
		maxDist = 500._f - ((stuckInSpotTimer - 10) * 20._f);
		if (maxDist < 10._f)
			maxDist = 10._f;
	}
	else
		maxDist = 500._f;
}

void Goomba::TrackVsStarIfNecessary()
{
	if (spawnStar == 2 && starID < 0 && starID_VS == VS_STAR_SPAWN_ORDER[NUM_VS_STARS_COLLECTED])
		starID = TrackStar(starID_VS, 1);
}

void Goomba::Kill()
{
	if ((capID & 0xf) >= 6)
		KillAndTrackInDeathTable();
	else
		MarkForDestruction();
}

void Goomba::SpawnStarIfNecessary()
{
	if (spawnStar == 1)
	{
		UntrackStar(starID);
		Actor* starMarker = Actor::Spawn(STAR_MARKER_ACTOR_ID, 0x0050, originalPos, nullptr, areaID, -1);
		Actor* silverStar = Actor::Spawn(SILVER_STAR_ACTOR_ID, 0x0010, pos,         nullptr, areaID, -1);
		
		if (starMarker && silverStar)
		{
			*(s32*)((char*)silverStar + 0x434) = starMarker->uniqueID;	// make this use the actual member of the Star Marker when it's decompiled
			LinkSilverStarAndStarMarker(starMarker, silverStar);
			SpawnSoundObj(1);
		}
		
		param1 &= 0xff0f; // rid the silver star part
	}
	else if (spawnStar == 2)
	{
		if (starID_VS == VS_STAR_SPAWN_ORDER[NUM_VS_STARS_COLLECTED])
		{
			UntrackStar(starID);
			Actor::Spawn(STAR_MARKER_ACTOR_ID, starID_VS | 0x0030, pos, nullptr, areaID, -1);
			Actor::Spawn(SILVER_STAR_ACTOR_ID, starID_VS | 0x0030, pos, nullptr, areaID, -1);
			spawnStar = 3;
			param1 &= 0xff0f;
			SpawnSoundObj(1);
		}
	}
}

bool Goomba::UpdateIfDying()
{
	bool dying = UpdateDeath(wmClsn);
	if (defeatMethod - 2 <= 4)
	{
		modelAnim.speed = 1._f;
		modelAnim.Advance();
		
		if (type == Type::GOOMBOSS_GOOMBA)
		{
			Actor* actor;
			if (cylClsn.otherObjID != 0 && (actor = Actor::FindWithID(cylClsn.otherObjID), actor != nullptr) && actor->actorID == GOOMBOSS_ACTOR_ID)
			{
				// the actor is Goomboss
				SpawnCoin();
				Kill();
			}
			cylClsn.flags1 |= CylinderClsn::SPIT_ACTOR;
			cylClsn.Clear();
			cylClsn.Update();
		}
	}
	
	if (dying)
	{
		Sound::Play(DYING_SOUNDS[type], camSpacePos);
		SpawnStarIfNecessary();
		if (capID < 6 || spawnStar == 2)
		{
			pos = originalPos;
			RespawnIfHasCap();
			if (capID < 6)
				UntrackInDeathTable();
		}
	}
	
	return dying;
}

void Goomba::RenderRegurgGoombaHelpless(Player* player)
{
	regurgTimer = 60;
	speed.y = (13._f - vertAccel) / floorNormal.y;
	horzSpeed = -speed.HorzLen();
	
	if (player)
		motionAng.y = pos.HorzAngle(player->pos);
	
	modelAnim.SetAnim(animFiles[UNBALANCE].BCA(), Animation::LOOP, 1._f, 0);
	state = 3;
	isBeingSpit = false;
	
	wmClsn.SetLimMovFlag();
	wmClsn.Unk_0203589c();
	wmClsn.ClearJustHitGroundFlag();
	wmClsn.ClearGroundFlag();
	
	regurgBounceCount = 0;
	
	Sound::Play("NCS_SE_SCT_KRB_BOUND"sfx, camSpacePos);
}

void Goomba::KillIfTouchedBadSurface()
{
	if (wmClsn.IsOnGround())
		return;
	
	if (wmClsn.sphere.floorResult.surfaceInfo.clps.isWater)
	{
		SpawnStarIfNecessary();
		SpawnCoin();
		Kill();
		ReleaseCap(CAP_OFFSET);
		pos = originalPos;
		RespawnIfHasCap();
		return;
	}
	
	ClsnResult& clsnRes = wmClsn.sphere.floorResult;
	CLPS& clps = clsnRes.surfaceInfo.clps;
	u32 behav = clps.behaviorID;
	
	if ((clps.textureID == CLPS::TX_SAND &&
		(behav == CLPS::BH_LOW_JUMPS || behav == CLPS::BH_SLOW_SHALLOW_QUICKSAND || behav == CLPS::BH_SLOW_DEEP_QUICKSAND || behav == CLPS::BH_INSTANT_QUICKSAND)) ||
		behav == CLPS::BH_WIND_GUST || behav == CLPS::BH_LAVA || behav == CLPS::BH_DEATH || behav == CLPS::BH_DEATH_2)
	{
		SpawnCoin();
		Kill();
		if ((capID & 0xf) < 6 || spawnStar == 2)
		{
			pos = originalPos;
			ReleaseCap(CAP_OFFSET);
			RespawnIfHasCap();
		}
	}
	
	clsnRes.Reset();
}

void Goomba::UpdateModelTransform()
{
	modelAnim.mat4x3 = modelAnim.mat4x3.RotationY(ang.y);
	modelAnim.mat4x3.c3 = pos >> 3;
	
	if (!(flags & Actor::IN_YOSHI_MOUTH))
		DropShadowRadHeight(shadow, modelAnim.mat4x3, scale.x * 80, wmClsn.IsOnGround() ? 30._f : 150._f, 0xf);
	
	UpdateCapPos(Vector3{ Sin(ang.y) * 10, CAP_OFFSET.y, Cos(ang.y) * 10 }, ang);
}

bool Goomba::UpdateIfEaten()
{
	u32 eatState = UpdateYoshiEat(wmClsn);
	if (eatState == 0)
		return false;
	else if (eatState == 1)
	{
		if (GetCapEatenOffIt(CAP_OFFSET))
		{
			RenderRegurgGoombaHelpless(eater);
			horzSpeed = -15._f;
			speed.y = 20._f;
			MaterialChanger::Prepare(*modelFile.BMD(), regurgMat);
			materialChg.SetFile(regurgMat, Animation::NO_LOOP, 1._f, 0);
			materialChg.currFrame = 0._f;
			cylClsn.Clear();
			return false;
		}
	}
	else if (eatState == 3)
	{
		if (wmClsn.IsOnGround())
			horzSpeed >>= 1;
	}
	
	if (SpawnParticlesIfHitOtherObj(cylClsn))
	{
		Actor* other = Actor::FindWithID(cylClsn.otherObjID); // guaranteed to exist by condition
		defeatMethod = Enemy::DF_HIT_REGURG;
		KillByAttack(*other, wmClsn);
		modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
		cylClsn.flags1 |= CylinderClsn::DISABLED;
		return true;
	}
	
	UpdateModelTransform();
	cylClsn.Clear();
	if (isBeingSpit)
	{
		KillIfTouchedBadSurface();
		if (spitTimer == 0)
			cylClsn.Update();
		else if (spitTimer == 5)
		{
			modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
			motionAng.y += 180._deg;
			horzSpeed = -horzSpeed;
			
			MaterialChanger::Prepare(*modelFile.BMD(), regurgMat);
			materialChg.SetFile(regurgMat, Animation::NO_LOOP, 1._f, 0);
			materialChg.currFrame = 0._f;
		}
		
		modelAnim.Advance();
		if (wmClsn.JustHitGround())
			RenderRegurgGoombaHelpless(nullptr);
	}
	
	return true;
}

void Goomba::PlayMovingSound()
{
	if (state != 0)
		return;
		
	if (!wmClsn.IsOnGround())
		return;
		
	u32 currFrameInt = (s32)modelAnim.currFrame;
	if ((modelAnim.file == animFiles[WALK].BCA() && (currFrameInt <= 4 || (currFrameInt >= 12 && currFrameInt <= 16))) ||
		(modelAnim.file == animFiles[RUN ].BCA() && (currFrameInt <= 3 || (currFrameInt >= 10 && currFrameInt <= 13))))
	{
		if (flags468 & 2)
			return;
			
		Sound::Play("NCS_SE_SCT_KRB_WALK"sfx, camSpacePos);
		flags468 |= 2;	
	}
	else
		flags468 = flags468 & ~2;
}

void Goomba::GetHurtOrHurtPlayer()
{
	if (cylClsn.otherObjID == 0)
		return;
	
	Player* player = (Player*)Actor::FindWithID(cylClsn.otherObjID);
	if (player == nullptr)
		return;
	
	hitFlags = cylClsn.hitFlags;
	bool rotate = false;
	
	Fix12i hurtSpeed = 12._f;
	if (type == Type::GOOMBOSS_GOOMBA)
		hurtSpeed = 5._f;
	
	if (actorID != GOOMBA_SMALL_ACTOR_ID && (hitFlags & CylinderClsn::HIT_BY_MEGA_CHAR) != 0)
	{
		ReleaseCap(CAP_OFFSET);
		s16 angX = actorID == GOOMBA_ACTOR_ID ? -45._deg : -33.75_deg;
		KillByInvincibleChar(Vector3_16{ angX, 0._deg, 0._deg }, *player);
		return;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_SPIN_OR_GROUND_POUND) != 0)
	{
		defeatMethod = Enemy::DF_SQUASHED;
		if (type == Type::BIG)
			coinType = Enemy::CN_BLUE;
		
		scale.x = scale.y = scale.z = 1._f;
		Sound::Play("NCS_SE_SCT_KRB_SMASH"sfx, camSpacePos);
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_FIRE) != 0)
	{
		rotate = true;
		modelAnim.SetAnim(animFiles[STRETCH].BCA(), Animation::NO_LOOP, 1._f, 0);
		defeatMethod = Enemy::DF_BURNED;
	}
	else if (actorID == GOOMBA_LARGE_ACTOR_ID)
	{
		if (player->actorID == PLAYER_ACTOR_ID)
		{
			// Vector3 playerPos = player->pos;
			if (JumpedOnByPlayer(cylClsn, *player))
			{
				player->Bounce(40._f);
				Sound::Play("NCS_SE_SCT_KRB_SMASH"sfx, camSpacePos);
				defeatMethod = Enemy::DF_SQUASHED;
				scale.x = scale.y = scale.z = 1._f;
			}
			else
			{
				if (player->isVanishLuigi)
					return;
				
				if (state == 0)
				{
					state = 1;
					if ((cylClsn.hitFlags & CylinderClsn::HIT_BY_PLAYER) != 0)
						player->Hurt(pos, DAMAGES[type], hurtSpeed, 1, 0, 1);
					
					return;
				}
			}
		}
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_REGURG_GOOMBA) != 0)
	{
		defeatMethod = Enemy::DF_HIT_REGURG;
		modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
		cylClsn.flags1 |= CylinderClsn::DISABLED;
	}
	else if ((hitFlags & (CylinderClsn::HIT_BY_DIVE | CylinderClsn::HIT_BY_EGG)) != 0)
	{
		defeatMethod = Enemy::DF_DIVED;
		modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_EXPLOSION) != 0)
	{
		defeatMethod = Enemy::DF_UNK_6;
		modelAnim.SetAnim(animFiles[STRETCH].BCA(), Animation::NO_LOOP, 1._f, 0);
	}
	else if ((hitFlags & (CylinderClsn::HIT_BY_KICK | CylinderClsn::HIT_BY_BREAKDANCE | CylinderClsn::HIT_BY_SLIDE_KICK)) != 0)
	{
		rotate = true;
		modelAnim.SetAnim(animFiles[STRETCH].BCA(), Animation::NO_LOOP, 1._f, 0);
		defeatMethod = Enemy::DF_KICKED;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_PUNCH) != 0)
	{
		modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
		defeatMethod = Enemy::DF_PUNCHED;
		rotate = true;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_YOSHI_TONGUE) == 0 && player->actorID == PLAYER_ACTOR_ID)
	{
		if (player->isMetalWario)
		{
			ReleaseCap(CAP_OFFSET);
			KillByInvincibleChar(Vector3_16{ 45._deg, 0._deg, 0._deg }, *player);
			return;
		}
		
		// Vector3 playerPos = player->pos;
		
		if (player->IsOnShell())
		{
			defeatMethod = Enemy::DF_DIVED;
			rotate = true;
			modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
		}
		else if (JumpedOnByPlayer(cylClsn, *player))
		{
			player->Bounce(40._f);
			Sound::Play("NCS_SE_SCT_KRB_SMASH"sfx, camSpacePos);
			defeatMethod = Enemy::DF_SQUASHED;
			scale.x = scale.y = scale.z = 1._f;
		}
		else if (player->isVanishLuigi)
			return;
		else if (state == 0)
		{
			if (type == Type::SMALL)
			{
				SmallPoofDust();
				player->Hurt(pos, 0, hurtSpeed, 1, 0, 1);
				Kill();
				Sound::Play("NCS_SE_SCT_SKB_DOWN"sfx, camSpacePos);
			}
			else if ((cylClsn.hitFlags & CylinderClsn::HIT_BY_PLAYER) != 0)
			{
				player->Hurt(pos, DAMAGES[type], hurtSpeed, 1, 0, 1);
				state = 1;
			}
			
			return;
		}
	}
	
	if (defeatMethod != Enemy::DF_NOT)
		ReleaseCap(CAP_OFFSET);
	
	KillByAttack(*player, wmClsn);
	
	if (rotate)
		ang.y = motionAng.y + 180._deg;
	
	if (type == Type::GOOMBOSS_GOOMBA)
	{
		if ((hitFlags & CylinderClsn::HIT_BY_PUNCH) != 0 ||
			(hitFlags & (CylinderClsn::HIT_BY_KICK | CylinderClsn::HIT_BY_BREAKDANCE | CylinderClsn::HIT_BY_SLIDE_KICK)) != 0)
		{
			horzSpeed += player->horzSpeed;
		}
		
		if ((hitFlags & CylinderClsn::HIT_BY_DIVE) != 0)
			horzSpeed += 0.0078_f;
	}
}

void Goomba::KillIfIntoxicated()
{
	if (wmClsn.IsOnGround())
		return;
		
	RaycastGround raycaster;
	raycaster.SetFlag_2();
	raycaster.SetFlag_8();
	raycaster.ClearFlag_1();
	
	raycaster.SetObjAndPos(Vector3{ pos.x, pos.y + 400._f, pos.z }, this);
	if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.isToxic &&
	   raycaster.clsnPosY != Fix12i::min && pos.y < raycaster.clsnPosY)
	{
		SpawnCoin();
		PoofDust();
		Kill();
		ReleaseCap(CAP_OFFSET);
		pos = originalPos;
		RespawnIfHasCap();
	}
}

void Goomba::Jump()
{
	Sound::Play("NCS_SE_SCT_KRB_JUMP"sfx, camSpacePos);
	state = 2;
	horzSpeed = 0._f;
	speed.y = JUMP_SPEEDS[type];
	wmClsn.ClearGroundFlag();
	cylClsn.flags1 |= 4;
}

void Goomba::UpdateTargetDirAndDist(Fix12i theMaxDist)
{
	player = ClosestPlayer();
	
	if (pos.Dist(originalPos) > theMaxDist || !player)
	{
		targetDir = pos.HorzAngle(originalPos);
		distToPlayer = 25000._f;
		return;
	}
	
	Vector3 playerPos = player->pos;
	
	if (originalPos.Dist(playerPos) > theMaxDist)
	{
		distToPlayer = 25000._f;
		return;
	}
	
	distToPlayer = pos.Dist(playerPos);
	targetDir = pos.HorzAngle(playerPos);
}

void Goomba::SetOriginalPos(Vector3& newOriginalPos)
{
	originalPos = newOriginalPos;
}

void Goomba::State0()
{
	if (type == Type::GOOMBOSS_GOOMBA)
		State0_GoombossGoomba();
	else
		State0_NormalGoomba();
	
	ang.y = motionAng.y;
}

void Goomba::State0_NormalGoomba()
{
	s16 angAccel = 2.8125_deg;
	UpdateTargetDirAndDist(1000._f);
	horzSpeed.ApproachLinear(targetSpeed, 0.3125_f);
	
	if (flags468 & 1)
	{
		if (ApproachLinear(motionAng.y, targetDir, angAccel) != 0)
			flags468 &= ~1;
		
		return;
	}
	
	if (noChargeTimer == 0)
	{
		if (distToPlayer > 25000._f)
		{
			targetDir2 = targetDir;
			movementTimer = 25;
		}
		
		bool redirected = AngleAwayFromWallOrCliff(wmClsn, targetDir2);
		flags468 = (flags468 & ~1) | ((u8)redirected & 1);
		
		if (!redirected)
		{
			if (distToPlayer < maxDist || (capID < 6 && pos.Dist(originalPos) > 1000._f))
			{
				if (WALK_SPEEDS[type] < targetSpeed)
					modelAnim.SetAnim(animFiles[RUN].BCA(), Animation::LOOP, 1._f, 0);
				else
					Jump();
				
				if (capID < 6 && noChargeTimer == 0)
					angAccel = 8.4375_deg;
				
				targetDir2 = targetDir;
				targetSpeed = RUN_SPEEDS[type];
			}
			else
			{
				targetSpeed = WALK_SPEEDS[type];
				modelAnim.SetAnim(animFiles[WALK].BCA(), Animation::LOOP, 1._f, 0);
				
				if (movementTimer == 0)
				{
					if (((RandomInt() >> 16) & 3) == 0)
					{
						targetDir2 = RandomInt();
						Jump();
					}
					else
					{
						RandomInt();
						targetDir2 = motionAng.y + RandomInt();
						movementTimer = 100;
					}
				}
				else
				{
					--movementTimer;
				}
			}
		}
		
		if (capID > 5 && stuckInSpotTimer > 30)
			noChargeTimer = stuckInSpotTimer;
		
		ApproachLinear(motionAng.y, targetDir2, angAccel);
		return;
	}
	
	if (capID < 6)
	{
		if (WALK_SPEEDS[type] < targetSpeed)
			modelAnim.SetAnim(animFiles[RUN].BCA(), Animation::LOOP, 1._f, 0);
		else
			Jump();
		
		angAccel = 11.25_deg;
		targetSpeed = RUN_SPEEDS[type];
		targetDir2 = targetDir;
	}
	else
	{
		targetSpeed = WALK_SPEEDS[type];
		modelAnim.SetAnim(animFiles[WALK].BCA(), Animation::LOOP, 1._f, 0);
		targetDir2 = pos.HorzAngle(originalPos);
		angAccel = 5.625_deg;
	}
	
	ApproachLinear(motionAng.y, targetDir2, angAccel);
	return;
}

void Goomba::State0_GoombossGoomba()
{
	Goomboss* goomboss;
	if (goombossID == 0 || (goomboss = (Goomboss*)Actor::FindWithID(goombossID), goomboss == nullptr))
	{
		type = Type::NORMAL;
		return;
	}
	
	if (targetSpeed == 0)
		modelAnim.SetAnim(animFiles[WAIT].BCA(), Animation::LOOP, 1._f, 0);
	else
		modelAnim.SetAnim(animFiles[WALK].BCA(), Animation::LOOP, 1._f, 0);
	
	Vector3 relativeSpawnPos;
	goomboss->vGetGoombaSpawnPos(relativeSpawnPos, goombaID);
	
	if (ApproachAngle(motionAng.y, targetDir, 4, 4096, 1024) == 0 && wmClsn.IsOnGround() != 0)
	{
		//pos.HorzDist(originalPos); // ???
		if ((goomboss->state == 4 && goomboss->walkSpeed == 0) || DecIfAbove0_Byte(followGoombossTimer) != 0 || 1000._f < pos.HorzDist(relativeSpawnPos))
		{
			bool isRunning = true;
			if ((DistToCPlayer() < 1000._f) && AngleDiff(HorzAngleToCPlayer(), ang.y) < 67.5_deg)
			{
				targetDir2 = targetDir = HorzAngleToCPlayer();
				
				if (targetSpeed == WALK_SPEEDS[type])
					targetSpeed = RUN_SPEEDS[type];
				
				isRunning = targetSpeed == RUN_SPEEDS[type];
				if (!isRunning)
				{
					speed.y = JUMP_SPEEDS[type];
					horzSpeed = 0._f;
					targetSpeed = RUN_SPEEDS[type];
				}
				
				if (wmClsn.JustHitGround() != 0)
					LandingDust(true);
			}
			else
			{
				if (DecIfAbove0_Short(changeDirTimer) == 0)
				{
					u32 random = RandomInt();
					changeDirTimer = (u16)((random >> 11) + 30);
					targetDir = (u16)random;
				}
				targetSpeed = 0._f;
			}
			
			if (isRunning)
				horzSpeed.ApproachLinear(targetSpeed, 0.3125_f);
		}
		else
		{
			targetDir = pos.HorzAngle(relativeSpawnPos);
			
			if (pos.HorzDist(relativeSpawnPos) < 50._f)
				targetSpeed = goomboss->goombaTargetSpeed >> 2;
			else if (pos.HorzDist(relativeSpawnPos) < 100._f)
				targetSpeed = goomboss->goombaTargetSpeed >> 1;
			else if (pos.HorzDist(relativeSpawnPos) < 150._f)
				targetSpeed = goomboss->goombaTargetSpeed;
			else
				targetSpeed = RUN_SPEEDS[type] + goomboss->goombaTargetSpeed;
			
			Math_Function_0203b14c(horzSpeed, targetSpeed, 0.5_f, 16._f, 0.001_f);
		}
	}
	
	if (pos.y < originalPos.y - 1000._f)
		MarkForDestruction();
	
	if (goomboss->state == 4 && goomboss->walkSpeed == 0)
		followGoombossTimer = 30;
}

void Goomba::State1()
{
	Jump();
	if (actorID == GOOMBA_LARGE_ACTOR_ID)
		speed.y *= 1.5_f;
	
	targetDir2 = targetDir;
	flags468 &= ~1;
	ang.y = motionAng.y;
}

void Goomba::State2()
{
	if (wmClsn.JustHitGround())
	{
		if (type == Type::NORMAL)
			LandingDust(true);
		else if (type == Type::BIG)
			BigLandingDust(true);
	}
	
	if (wmClsn.IsOnGround())
	{
		state = 0;
		cylClsn.flags1 &= ~4;
	}
	else
		ApproachLinear(motionAng.y, targetDir2, 11.25_deg);
	
	ang.y = motionAng.y;
}

void Goomba::State3()
{
	if (regurgTimer == 0) // never gets executed
	{
		materialChg.Advance();
		if (!modelAnim.Finished())
			return;
		
		flags = recoverFlags;
		state = 0;
		modelAnim.SetAnim(animFiles[WALK].BCA(), Animation::LOOP, 1._f, 0);
		targetSpeed = WALK_SPEEDS[type];
		wmClsn.ClearLimMovFlag();
		motionAng.y = ang.y;
		cylClsn.flags1 &= ~CylinderClsn::SPIT_ACTOR;
		MaterialChanger::Prepare(*modelFile.BMD(), aliveMat);
		materialChg.SetFile(aliveMat, Animation::NO_LOOP, 1._f, 0);
		materialChg.currFrame = 0._f;
		return;
	}
	
	if (regurgTimer <= 60 && --regurgTimer == 0)
	{
		SpawnStarIfNecessary();
		SpawnCoin();
		Kill();
		ReleaseCap(CAP_OFFSET);
		pos = originalPos;
		RespawnIfHasCap();
	}
	
	if (wmClsn.JustHitGround() == 0)
	{
		if (wmClsn.IsOnGround() != 0)
		{
			wmClsn.ClearLimMovFlag();
			speed.y = horzSpeed = 0._f;
			
			if (regurgTimer > 60)
				regurgTimer = 30;
		}
	}
	else
	{
		if (regurgTimer > 60)
			regurgTimer = 30;
		
		if (Abs(speed.y) <= 0.3125_f * regurgTimer)
			speed.y = regurgTimer * 0.25_f - vertAccel;
		else
			speed.y = -80 * speed.y / (100 * floorNormal.y);
		
		horzSpeed >>= 1;
		
		if (Abs(horzSpeed) < 5._f)
		{
			if (horzSpeed < 0._f)
				horzSpeed = -5._f;
			else
				horzSpeed = 5._f;
		}
		
		if (regurgBounceCount == 0)
			Sound::Play("NCS_SE_SCT_KRB_BOUND"sfx, camSpacePos);
		else if (regurgBounceCount < 3)
			Sound::Play("NCS_SE_SCT_KRB_BOUND_S"sfx, camSpacePos);
		
		++regurgBounceCount;
	}
	
	isBeingSpit = true;
	if (SpawnParticlesIfHitOtherObj(cylClsn))
	{
		defeatMethod = Enemy::DF_HIT_REGURG;
		KillByAttack(*Actor::FindWithID(cylClsn.otherObjID), wmClsn);
		modelAnim.SetAnim(animFiles[ROLLING].BCA(), Animation::NO_LOOP, 1._f, 0);
		cylClsn.flags1 |= 1;
	}
	isBeingSpit = false;
	
	return;
}

void Goomba::State4()
{
	horzSpeed = 0._f;
	if (changeDirTimer == 0 || --changeDirTimer != 0)
		return;
	
	state = 0;
	modelAnim.SetAnim(animFiles[WALK].BCA(), 0, 1._f, 0);
}

Goomba::Goomba() {}
Goomba::~Goomba() {}