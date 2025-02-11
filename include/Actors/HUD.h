#pragma once

struct HUD : ActorDerived
{
	enum MeterState : u8
	{
		ST_DONT_DISPLAY           = 0,
		ST_DISPLAY_NORMAL         = 1,
		ST_DISPLAY_WHILE_REVIVING = 2,
		ST_DISPLAY_AFTER_REVIVING = 3,
		ST_MOVE_UP                = 4,
		ST_MOVE_UP_STAR_GOT       = 5,
		ST_DONT_DISPLAY_STAR_GOT  = 6,
	};
	
	u32 unk50;              // unused
	u32 unk54;              // unused
	u32 unk58;              // unused
	u32 unk5c;              // unused
	u16 vsModeTimer;        // 0x60
	u16 unk62;              // 0x62 (set to 0 in InitResources, never used)
	u16 unk64;              // 0x64 (set to 180 in InitResources, never used)
	u16 vsModeTimerPosY;    // 0x66
	s16 meterPosY;          // 0x68
	u16 stateTimer;         // 0x6a
	u16 decHealthTimer;     // 0x6c
	s16 lifePosX;           // 0x6e
	s16 starPosX;           // 0x70
	u8 unk72;               // 0x72 (set to 0 in InitResources if RENDERED_HEALTH == 8, never used)
	u8 meterState;          // 0x73
	s8 calculatedDigits[3]; // 0x74
	u8 unk77;               // unused
	bool inIntroCutscene;   // 0x78
	u8 unk79;               // unused
	u16 unk7a;              // unused
	
	static BaseSpawnInfo spawnData;
	static u16* healthColorsPaletteFile;
	
	HUD();
	virtual s32	InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~HUD() override;
	
	void UpdateVsTimer();
	void UpdateHealthMeter();
	
	void RenderVsTimer();
	void RenderStarCount();
	void RenderCoinCount();
	void RenderCameraButtons();
	void RenderHealthMeter();
	void RenderRedCoins();
	void RenderSilverStars();
	void RenderTimeTimer();
	void RenderLifeCount();
	
	void CalculateDigits(u16 number);
};