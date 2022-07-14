#include "Goomba.h"
#include "../E_Goomboss/Goomboss.h"

namespace
{
	using StateFuncPtr = void(Goomba::*)();

	const char materialName[] = "kuribo_all";
	char aliveMatVals[] = {0x1f, 0x10, 0x00, 0x00};
	MaterialProperties aliveMatProps =
	{
		(s16)0xffff, 0,
		&materialName[0],
		0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000, 
		0x01, 0x00, 0x0001,    0x01, 0x00, 0x0001,    0x01, 0x00, 0x0001,  
		0x01, 0x00, 0x0002,    0x01, 0x00, 0x0002,    0x01, 0x00, 0x0002, 
		0x01, 0x00, 0x0002,    0x01, 0x00, 0x0002,    0x01, 0x00, 0x0002, 
		0x01, 0x00, 0x0000, 
	};
	MaterialDef aliveMat = {0x0002, 0x0000, &aliveMatVals[0], 1, &aliveMatProps};

	char regurgMatVals[] = {0x00, 0x03, 0x0c, 0x16, 0x1f, 0x1f, 0x1f, 0x1f,
							0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
							0x1f, 0x10, 0x00, 0x00};
	MaterialProperties regurgMatProps =
	{
		(s16)0xffff, 0,
		&materialName[0],
		0x01, 0x01, 0x0000,    0x01, 0x00, 0x0004,    0x01, 0x00, 0x0004,
		0x01, 0x00, 0x0011,    0x01, 0x00, 0x0011,    0x01, 0x00, 0x0011, 
		0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000,
		0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000,    0x01, 0x00, 0x0000,
		0x01, 0x00, 0x0004, 
	};
	MaterialDef regurgMat = {0x0011, 0x0000, &regurgMatVals[0], 1, &regurgMatProps};

	const StateFuncPtr stateFuncs[] =
	{
		&Goomba::State0,
		&Goomba::State1,
		&Goomba::State2,
		&Goomba::State3,
		&Goomba::State4
	};

	const Fix12i SCALES[]          = { 0x00000555_f,  0x00001000_f,  0x00002555_f,  0x00001000_f}; // 0x02130258
	const Fix12i HORZ_CLSN_SIZES[] = { 0x00028000_f,  0x00064000_f,  0x000e0000_f,  0x00064000_f}; // 0x02130208
	const Fix12i VERT_ACCELS[]     = {-0x00000aaa_f, -0x00002000_f, -0x00005aaa_f, -0x00002000_f}; // 0x02130238
	const Fix12i WALK_SPEEDS[]     = { 0x00000aaa_f,  0x00002000_f,  0x00004aaa_f,  0x00006000_f}; // 0x02130228
	const Fix12i RUN_SPEEDS[]      = { 0x0000a800_f,  0x00015000_f,  0x00015000_f,  0x00015000_f}; // 0x02130268
	const Fix12i JUMP_SPEEDS[]     = { 0x00008000_f,  0x00010000_f,  0x00020000_f,  0x00010000_f}; // 0x02130248
	const u32 DAMAGES[] = { 0, 1, 2, 1 };	// 0x02130204
	const u32 DYING_SOUND_IDS[] = {0x00000110, 0x000000d6, 0x00000111};
	
	const Vector3 CAP_OFFSET = {0x00000_f, 0x6c000_f, 0x00000_f};
}

GloballySharedFilePtr Goomba::modelFile;
GloballySharedFilePtr Goomba::animFiles[NUM_ANIMS];

SpawnInfo Goomba::spawnData =
{
	[]() -> ActorBase* { return new Goomba; },
	0x00c8,
	0x0018,
	0x10000006,
	0x00032000_f,
	0x00046000_f,
	0x01000000_f,
	0x01000000_f
};

SpawnInfo Goomba::spawnDataSmall =
{
	[]() -> ActorBase* { return new Goomba; },
	0x00c9,
	0x0019,
	0x10000006,
	0x00032000_f,
	0x00046000_f,
	0x006a4000_f,
	0x00800000_f
};

SpawnInfo Goomba::spawnDataLarge =
{
	[]() -> ActorBase* { return new Goomba; },
	0x00ca,
	0x001a,
	0x10000006,
	0x00064000_f,
	0x000c8000_f,
	0x01000000_f,
	0x01000000_f
};

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
		
	Model::LoadFile(modelFile.Get());
	for(s32 i = 0; i < NUM_ANIMS; ++i)
		Animation::LoadFile(animFiles[i].Get());
		
	AddCap((u8)(param1 & 0xf));
	if (capID < 6)
		param1 &= 0xf0ff; // invalid cap, so never spawn cap
	
	if (!DestroyIfCapNotNeeded())
		return 0;
	
	if (!modelAnim.SetFile(modelFile.GetFilePtr(), 1, -1))
		return 0;
	
	if (!shadow.InitCylinder())
		return 0;
	
	MaterialChanger::Prepare(modelFile.GetFilePtr(), aliveMat);
	materialChg.SetMaterial(aliveMat, Animation::NO_LOOP, 0x1000_f, 0);
	coinType = Enemy::CN_YELLOW;

	if (actorID == 0xc9)
	{
		type = Type::SMALL;
	}
	else if (actorID == 0xc8)
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
	
	scale.x = SCALES[type];
	scale.y = SCALES[type];
	scale.z = SCALES[type];
	
	cylClsn.Init(this, scale.x * 0x3c, HORZ_CLSN_SIZES[type], 0x00200000, 0x00a6efe0);
	if (type == Type::BIG)
		cylClsn.vulnerableFlags &= ~CylinderClsn::HIT_BY_UNK_16;
		
	wmClsn.Init(this, scale.x * 0x3c, scale.x * 0x3c, nullptr, nullptr);
	wmClsn.SetFlag_2();
	
	flags468 = state = 0;
	defeatMethod = Enemy::DF_NOT;
	player = nullptr;
	distToPlayer = 0x7fffffff_f;
	
	targetDir = motionAng.y;
	targetSpeed = WALK_SPEEDS[type];
	movementTimer = goombossID = changeDirTimer = stuckInSpotTimer = 0;
	backupPos = pos;
	
	UpdateMaxDist();
	
	originalPos = pos;
	
	vertAccel = VERT_ACCELS[type];
	termVel = -0x32000_f;
	
	modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	
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
		&& defeatMethod == Enemy::DF_NOT && IsTooFarAwayFromPlayer(0x5dc000_f) != 0)
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
	
	if (state < 3 && (type != Type::GOOMBOSS_GOOMBA || modelAnim.file != animFiles[WAIT].GetFilePtr()))
	{
		modelAnim.speed = horzSpeed / (2 * scale.x);
		if (modelAnim.speed > 0x3000_f)
			modelAnim.speed = 0x3000_f;
	}
	else
		modelAnim.speed = 0x1000_f;
	
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
		if (!IsGoingOffCliff(wmClsn, 0x32000_f, 0x1f49, 0, 1, 0x32000_f))
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
		if (pos.Dist(backupPos) < 0xa000_f)
		{
			++stuckInSpotTimer;
			if (capID < 6 && stuckInSpotTimer == 0x1e)
			{
				Jump();
				noChargeTimer = 0x5a;
			}
			if (0x12b < stuckInSpotTimer && noChargeTimer == 0)
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
		case 0xc8:
			return Actor::YE_KEEP_AND_CAN_MAKE_EGG;
		case 0xc9:
			return Actor::YE_SWALLOW;
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
	if (res == 6)
	{
		if (player.Unk_020bea94() == 0)
		{
			bool starUntracked = false;
			if (spawnStar == 1)
			{
				UntrackStar(starID);
				starUntracked = true;
				Actor::Spawn(0xb4, 0x50, originalPos, nullptr, areaID, -1);
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
	else if (res == 4 && coinType == 1)
	{
		Unk_0201061c(player, 1, 0);
	}
	
	Kill();
	return;
}

Fix12i Goomba::OnAimedAtWithEgg()
{
	switch (actorID)
	{
		case 0xc8:
			return 0x41000_f;
		case 0xc9:
			return 0x14000_f;
		default:
			return 0x96000_f;
	}
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
		maxDist = 0x1f4000_f - ((stuckInSpotTimer - 10) * 0x14000_f);
		if (maxDist < 0xa000_f)
			maxDist = 0xa000_f;
	}
	else
		maxDist = 0x1f4000_f;
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
		Actor* starMarker = Actor::Spawn(0xb4, 0x50, originalPos, nullptr, areaID, -1);
		Actor* silverStar = Actor::Spawn(0xb3, 0x10, pos,         nullptr, areaID, -1);
		
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
			Actor::Spawn(0xb4, starID_VS | 0x30, pos, nullptr, areaID, -1);
			Actor::Spawn(0xb3, starID_VS | 0x30, pos, nullptr, areaID, -1);
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
		modelAnim.speed = 0x1000_f;
		modelAnim.Advance();
		
		if (type == Type::GOOMBOSS_GOOMBA)
		{
			Actor* actor;
			if (cylClsn.otherObjID != 0 && (actor = Actor::FindWithID(cylClsn.otherObjID), actor != nullptr) && actor->actorID == 0xc6)
			{
				// the actor is Goomboss
				SpawnCoin();
				Kill();
			}
			cylClsn.flags1 |= 0x20000;
			cylClsn.Clear();
			cylClsn.Update();
		}
	}
	
	if (dying)
	{
		Sound::Play(3, DYING_SOUND_IDS[type], camSpacePos);
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
	regurgTimer = 0x3c;
	speed.y = (0xd000_f - vertAccel) / floorNormal.y;
	horzSpeed = -speed.HorzLen();
	
	if (player)
		motionAng.y = pos.HorzAngle(player->pos);
	
	modelAnim.SetAnim(animFiles[UNBALANCE].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	state = 3;
	isBeingSpit = false;
	
	wmClsn.SetLimMovFlag();
	wmClsn.Unk_0203589c();
	wmClsn.ClearJustHitGroundFlag();
	wmClsn.ClearGroundFlag();
	
	regurgBounceCount = 0;
	
	Sound::Play(3, 0x13a, camSpacePos);
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
	
	if (!(flags & 0x40000))
		DropShadowRadHeight(shadow, modelAnim.mat4x3, scale.x * 0x50, wmClsn.IsOnGround() ? 0x1e000_f : 0x96000_f, 0xf);
	
	UpdateCapPos(Vector3{Sin(ang.y) * 0xa, CAP_OFFSET.y, Cos(ang.y) * 0xa}, ang);
}

bool Goomba::UpdateIfEaten()
{
	u32 eatState = UpdateYoshiEat(wmClsn); //r4
	if (eatState == 0) return false;
	else if (eatState == 1)
	{
		if (GetCapEatenOffIt(CAP_OFFSET))
		{
			RenderRegurgGoombaHelpless(eater);
			horzSpeed = -0xf000_f;
			speed.y = 0x14000_f;
			MaterialChanger::Prepare(modelFile.GetFilePtr(), regurgMat);
			materialChg.SetMaterial(regurgMat, Animation::NO_LOOP, 0x1000_f, 0);
			materialChg.currFrame = 0x0_f;
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
		modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
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
			modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
			motionAng.y += 0x8000;
			horzSpeed = -horzSpeed;
			
			MaterialChanger::Prepare(modelFile.GetFilePtr(), regurgMat);
			materialChg.SetMaterial(regurgMat, Animation::NO_LOOP, 0x1000_f, 0);
			materialChg.currFrame = 0x0_f;
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
	if ((modelAnim.file == animFiles[WALK].GetFilePtr() && (currFrameInt <= 4 || (currFrameInt >= 12 && currFrameInt <= 16))) ||
		(modelAnim.file == animFiles[RUN ].GetFilePtr() && (currFrameInt <= 3 || (currFrameInt >= 10 && currFrameInt <= 13))))
	{
		if (flags468 & 2)
			return;
			
		Sound::Play(3, 0xd0, camSpacePos);
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
	
	Fix12i hurtSpeed = 0xc000_f;
	if (type == Type::GOOMBOSS_GOOMBA)
		hurtSpeed = 0x5000_f;
	
	if (actorID != SMALL_GOOMBA_ACTOR_ID && (hitFlags & CylinderClsn::HIT_BY_MEGA_CHAR) != 0)
	{
		ReleaseCap(CAP_OFFSET);
		KillByInvincibleChar(Vector3_16{(s16)(actorID == GOOMBA_ACTOR_ID ? -0x2000 : -0x1800), 0, 0}, *player);
		return;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_SPIN_OR_GROUND_POUND) != 0)
	{
		defeatMethod = Enemy::DF_SQUASHED;
		if (type == Type::BIG)
			coinType = Enemy::CN_BLUE;
		
		scale.x = scale.y = scale.z = 0x1000_f;
		Sound::Play(3, 0xe0, camSpacePos);
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_FIRE) != 0)
	{
		rotate = true;
		modelAnim.SetAnim(animFiles[STRETCH].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		defeatMethod = Enemy::DF_BURNED;
	}
	else if (actorID == LARGE_GOOMBA_ACTOR_ID)
	{
		if (player->actorID == PLAYER_ACTOR_ID)
		{
			// Vector3 playerPos = player->pos;
			if (JumpedOnByPlayer(cylClsn, *player))
			{
				player->Bounce(0x28000_f);
				Sound::Play(3, 0xe0, camSpacePos);
				defeatMethod = Enemy::DF_SQUASHED;
				scale.x = scale.y = scale.z = 0x1000_f;
			}
			else
			{
				if (player->isVanishLuigi)
					return;
				
				if (state == 0)
				{
					state = 1;
					if ((cylClsn.hitFlags & CylinderClsn::HIT_BY_UNK_22) != 0)
						player->Hurt(pos, DAMAGES[type], hurtSpeed, 1, 0, 1);
					
					return;
				}
			}
		}
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_REGURG_GOOMBA) != 0)
	{
		defeatMethod = Enemy::DF_HIT_REGURG;
		modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		cylClsn.flags1 |= CylinderClsn::DISABLED;
	}
	else if ((hitFlags & (CylinderClsn::HIT_BY_DIVE | CylinderClsn::HIT_BY_EGG)) != 0)
	{
		defeatMethod = Enemy::DF_DIVED;
		modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_UNK_14) != 0)
	{
		defeatMethod = Enemy::DF_UNK_6;
		modelAnim.SetAnim(animFiles[STRETCH].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
	}
	else if ((hitFlags & (CylinderClsn::HIT_BY_KICK | CylinderClsn::HIT_BY_BREAKDANCE | CylinderClsn::HIT_BY_SLIDE_KICK)) != 0)
	{
		rotate = true;
		modelAnim.SetAnim(animFiles[STRETCH].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		defeatMethod = Enemy::DF_KICKED;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_PUNCH) != 0)
	{
		modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		defeatMethod = Enemy::DF_PUNCHED;
		rotate = true;
	}
	else if ((hitFlags & CylinderClsn::HIT_BY_UNK_15) == 0 && player->actorID == PLAYER_ACTOR_ID)
	{
		if (player->isMetalWario)
		{
			ReleaseCap(CAP_OFFSET);
			KillByInvincibleChar(Vector3_16{0x2000, 0, 0}, *player);
			return;
		}
		
		// Vector3 playerPos = player->pos;
		
		if (player->IsOnShell())
		{
			defeatMethod = Enemy::DF_DIVED;
			rotate = true;
			modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		}
		else if (JumpedOnByPlayer(cylClsn, *player))
		{
			player->Bounce(0x28000_f);
			Sound::Play(3, 0xe0, camSpacePos);
			defeatMethod = Enemy::DF_SQUASHED;
			scale.x = scale.y = scale.z = 0x1000_f;
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
				Sound::Play(3, 0x110, camSpacePos);
			}
			else if ((cylClsn.hitFlags & CylinderClsn::HIT_BY_UNK_22) != 0)
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
		ang.y = motionAng.y + 0x8000;
	
	if (type == Type::GOOMBOSS_GOOMBA)
	{
		if ((hitFlags & 0x40) != 0 || (hitFlags & 0x380) != 0)
			horzSpeed += horzSpeed;
		
		if ((hitFlags & 0x400) != 0)
			horzSpeed += 0x20;
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
	
	raycaster.SetObjAndPos(Vector3{pos.x, pos.y + 0x190000_f, pos.z}, this);
	if (raycaster.DetectClsn() && raycaster.result.surfaceInfo.clps.isToxic &&
	   raycaster.clsnPosY != 0x80000000_f && pos.y < raycaster.clsnPosY)
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
	Sound::Play(3, 0x118, camSpacePos);
	state = 2;
	horzSpeed = 0x0_f;
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
		distToPlayer = 0x061a8000_f;
		return;
	}
	
	Vector3 playerPos = player->pos;
	
	if (originalPos.Dist(playerPos) > theMaxDist)
	{
		distToPlayer = 0x061a8000_f;
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
	s16 angAccel = 0x200;
	UpdateTargetDirAndDist(0x3e8000_f);
	horzSpeed.ApproachLinear(targetSpeed, 0x500_f);
	
	if (flags468 & 1)
	{
		if (ApproachLinear(motionAng.y, targetDir, 0x200) != 0)
			flags468 &= ~1;
		
		return;
	}
	
	if (noChargeTimer == 0)
	{
		if (0x61a7fff_f < distToPlayer)
		{
			targetDir2 = targetDir;
			movementTimer = 0x19;
		}
		
		bool redirected = AngleAwayFromWallOrCliff(wmClsn, targetDir2);
		flags468 = (flags468 & ~1) | ((u8)redirected & 1);
		
		if (!redirected)
		{
			if (distToPlayer < maxDist || (capID < 6 && 0x3e8000_f < pos.Dist(originalPos)))
			{
				if (WALK_SPEEDS[type] < targetSpeed)
					modelAnim.SetAnim(animFiles[RUN].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
				else
					Jump();
				
				if (capID < 6 && noChargeTimer == 0)
					angAccel = 0x600;
				
				targetDir2 = targetDir;
				targetSpeed = RUN_SPEEDS[type];
			}
			else
			{
				targetSpeed = WALK_SPEEDS[type];
				modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
				
				if (movementTimer == 0)
				{
					if (((RandomIntInternal(&RNG_STATE) >> 0x10) & 3) == 0)
					{
						targetDir2 = RandomIntInternal(&RNG_STATE);
						Jump();
					}
					else
					{
						RandomIntInternal(&RNG_STATE);
						targetDir2 = motionAng.y + RandomIntInternal(&RNG_STATE);
						movementTimer = 100;
					}
				}
				else
				{
					--movementTimer;
				}
			}
		}
		
		if (5 < capID && (0x1e < stuckInSpotTimer))
			noChargeTimer = stuckInSpotTimer;
		
		ApproachLinear(motionAng.y, targetDir2, angAccel);
		return;
	}
	
	if (capID < 6)
	{
		if (WALK_SPEEDS[type] < targetSpeed)
			modelAnim.SetAnim(animFiles[RUN].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
		else
			Jump();
		
		angAccel = 0x800;
		targetSpeed = RUN_SPEEDS[type];
		targetDir2 = targetDir;
	}
	else
	{
		targetSpeed = WALK_SPEEDS[type];
		modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
		targetDir2 = pos.HorzAngle(originalPos);
		angAccel = 0x400;
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
		modelAnim.SetAnim(animFiles[WAIT].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	else
		modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
	
	Vector3 relativeSpawnPos;
	goomboss->vGetGoombaSpawnPos(relativeSpawnPos, goombaID);
	
	if (ApproachAngle(motionAng.y, targetDir, 4, 0x1000, 0x400) == 0 && wmClsn.IsOnGround() != 0)
	{
		//pos.HorzDist(originalPos); // ???
		if ((goomboss->state == 4 && goomboss->walkSpeed == 0) || DecIfAbove0_Byte(followGoombossTimer) != 0 || 0x3e8000_f < pos.HorzDist(relativeSpawnPos))
		{
			bool isRunning = true;
			if ((DistToCPlayer() < 0x3e8000_f) && AngleDiff(HorzAngleToCPlayer(), ang.y) < 0x3000)
			{
				targetDir2 = targetDir = HorzAngleToCPlayer();
				
				if (targetSpeed == WALK_SPEEDS[type])
					targetSpeed = RUN_SPEEDS[type];
				
				isRunning = targetSpeed == RUN_SPEEDS[type];
				if (!isRunning)
				{
					speed.y = JUMP_SPEEDS[type];
					horzSpeed = 0;
					targetSpeed = RUN_SPEEDS[type];
				}
				
				if (wmClsn.JustHitGround() != 0)
					LandingDust(true);
			}
			else
			{
				if (DecIfAbove0_Short(changeDirTimer) == 0)
				{
					u32 random = RandomIntInternal(&RNG_STATE);
					changeDirTimer = (u16)((random >> 0xb) + 0x1e);
					targetDir = (u16)random;
				}
				targetSpeed = 0;
			}
			
			if (isRunning)
				horzSpeed.ApproachLinear(targetSpeed, 0x500_f);
		}
		else
		{
			targetDir = pos.HorzAngle(relativeSpawnPos);
			
			if (pos.HorzDist(relativeSpawnPos) < 0x32000_f)
				targetSpeed = goomboss->goombaTargetSpeed >> 2;
			else if (pos.HorzDist(relativeSpawnPos) < 0x64000_f)
				targetSpeed = goomboss->goombaTargetSpeed >> 1;
			else if (pos.HorzDist(relativeSpawnPos) < 0x96000_f)
				targetSpeed = goomboss->goombaTargetSpeed;
			else
				targetSpeed = RUN_SPEEDS[type] + goomboss->goombaTargetSpeed;
			
			Math_Function_0203b14c(horzSpeed, targetSpeed, 0x800_f, 0x10000_f, 0x4_f);
		}
	}
	
	if (pos.y < originalPos.y - 0x3e8000_f)
		MarkForDestruction();
	
	if (goomboss->state == 4 && goomboss->walkSpeed == 0)
		followGoombossTimer = 0x1e;
}

void Goomba::State1()
{
	Jump();
	if (actorID == 0xca)
		speed.y *= 0x1800_f;
	
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
		ApproachLinear(motionAng.y, targetDir2, 0x800);
	
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
		modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), Animation::LOOP, 0x1000_f, 0);
		targetSpeed = WALK_SPEEDS[type];
		wmClsn.ClearLimMovFlag();
		motionAng.y = ang.y;
		cylClsn.flags1 &= ~0x00020000;
		MaterialChanger::Prepare(modelFile.GetFilePtr(), aliveMat);
		materialChg.SetMaterial(aliveMat, Animation::NO_LOOP, 0x1000_f, 0);
		materialChg.currFrame = 0x0_f;
		return;
	}
	
	if (regurgTimer < 0x3d && --regurgTimer == 0)
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
			speed.y = horzSpeed = 0x0_f;
			
			if (0x3c < regurgTimer)
				regurgTimer = 0x1e;
		}
	}
	else
	{
		if (0x3c < regurgTimer)
			regurgTimer = 0x1e;
		
		if (Abs(speed.y) <= 0x500_f * regurgTimer)
			speed.y = regurgTimer * 0x400_f - vertAccel;
		else
			speed.y = -0x50 * speed.y / (0x64 * floorNormal.y);
		
		horzSpeed >>= 1;
		
		if (Abs(horzSpeed) < 0x5000_f)
		{
			if (horzSpeed < 0_f)
				horzSpeed = -0x5000_f;
			else
				horzSpeed = 0x5000_f;
		}
		
		if (regurgBounceCount == 0)
			Sound::Play(3, 0x13a, camSpacePos);
		else if (regurgBounceCount < 3)
			Sound::Play(3, 0x13b, camSpacePos);
		
		++regurgBounceCount;
	}
	
	isBeingSpit = true;
	if (SpawnParticlesIfHitOtherObj(cylClsn))
	{
		defeatMethod = Enemy::DF_HIT_REGURG;
		KillByAttack(*Actor::FindWithID(cylClsn.otherObjID), wmClsn);
		modelAnim.SetAnim(animFiles[ROLLING].GetFilePtr(), Animation::NO_LOOP, 0x1000_f, 0);
		cylClsn.flags1 |= 1;
	}
	isBeingSpit = false;
	
	return;
}

void Goomba::State4()
{
	horzSpeed = 0x0_f;
	if (changeDirTimer == 0 || --changeDirTimer != 0)
		return;
	
	state = 0;
	modelAnim.SetAnim(animFiles[WALK].GetFilePtr(), 0, 0x1000_f, 0);
}

MaterialDef* Goomba::vGetRegurgMaterialDef()
{
	return &regurgMat;
}

void Goomba::vSetOriginalPos(Vector3& newOriginalPos)
{
	SetOriginalPos(newOriginalPos);
}