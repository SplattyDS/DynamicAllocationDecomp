#pragma once

struct Stump : Platform
{
	u8 health;                 // 0x31e
	u8 hitTimer;               // 0x31f
	bool attachedToChainChomp; // 0x320 (not set in the Stump's code)
	s32 totalAngTraveled;      // 0x324
	s16 prevHorzAngToPlayer;   // 0x328
	Actor* tag;                // 0x32c (should be a MegaMushroomTag*)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	Stump();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Stump() override;
	virtual void OnGroundPounded(Actor& groundPounder) override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	
	void TakeHit(bool killInOneHit);
	void ActivateTags();
};

static_assert(sizeof(Stump) == 0x330);