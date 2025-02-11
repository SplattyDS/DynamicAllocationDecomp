#pragma once

struct Enemy : Actor
{
	enum CoinType
	{
		CN_NONE   = 0,
		CN_YELLOW = 1,
		CN_RED    = 2,
		CN_BLUE   = 3
	};
	
	enum DefeatMethod
	{
		DF_NOT        = 0,
		DF_SQUASHED   = 1,
		DF_PUNCHED    = 2,
		DF_KICKED     = 3,
		DF_BURNED     = 4,
		DF_DIVED      = 5,
		DF_UNK_6      = 6,
		DF_HIT_REGURG = 7,
		DF_GIANT_CHAR = 8 //this is definitely the end of the list.
	};
	
	enum InvCharKillFlags
	{
		IK_SPAWN_COINS = 1 << 0,
		IK_KILL        = 1 << 1
	};
	
	enum UpdateYoshiEatReturn
	{
		UY_NOT      = 0,
		UY_EATING   = 1,
		UY_IN_MOUTH = 2,
		UY_SPITTING = 3
	};
	
	Vector3 floorNormal; // 0xd4
	Vector3 wallNormal;  // 0xe0
	Vector3_16 rotation; // 0xec
	Vector3_16 unk0f2;   // 0xf2 (ceiling?)
	u32 unk0f8;          // 0xf8
	u32 unk0fc;          // 0xfc
	u16 stateTimer;      // 0x100
	u16 deathTimer;      // 0x102
	u16 spitTimer;       // 0x104
	u8 isAtCliff;        // 0x106
	bool isBeingSpit;    // 0x107
	u8 coinType;         // 0x108
	u8 unk109;           // 0x109
	u8 numCoinsMinus1;   // 0x10a
	u8 unk10b;           // 0x10b
	u32 defeatMethod;    // 0x10c
	
	Enemy();
	virtual ~Enemy() override;
	
	u32 UpdateKillByInvincibleChar(WithMeshClsn& wmClsn, ModelAnim& rigMdl, u32 flags); //returns 0 with 0 side effects if N/A.
	void KillByInvincibleChar(const Vector3_16& newRotation, Player& player);
	void SpawnMegaCharParticles(Actor& attacker, char* arg2);
	bool SpawnParticlesIfHitOtherObj(CylinderClsn& cylClsn); //returns whether there was a collision with an object that isn't a coin
	u32 UpdateYoshiEat(WithMeshClsn& wmClsn);
	bool AngleAwayFromWallOrCliff(WithMeshClsn& wmClsn, s16& ang); // returns whether the angle was redirected (if hitting wall, reflect angle; if at cliff, set angle to the opposite one)
	bool UpdateDeath(WithMeshClsn& wmClsn); //returns whether the object is actually dying and the death function returned true
	bool IsGoingOffCliff(WithMeshClsn& wmClsn, Fix12i maxFallDist, s16 unkAngle, bool setRaycastFlag2, bool arg5, Fix12i raycastOffsetY);
	void KillByAttack(Actor& other);
	void SpawnCoin();
	void UpdateWMClsn(WithMeshClsn& wmClsn, u32 arg2);
};

using EnemyDeathFunc = bool(Enemy::*)(WithMeshClsn& wmClsn);
extern EnemyDeathFunc ENEMY_DEATH_FUNCS[8];

static_assert(sizeof(Enemy) == 0x110, "Enemy is wrong size");