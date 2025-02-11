#pragma once

struct MovingBar : Platform
{
	enum Size
	{
		SMALL,
		BIG,
		
		NUM_SIZES,
	};
	
	Vector3 originalPos; // 0x320
	u32 size;            // 0x32c
	u32 state;           // 0x330
	u32 stateTimer;      // 0x334
	
	static SpawnInfo spawnData[NUM_SIZES];
	static SharedFilePtr modelFiles[NUM_SIZES];
	static SharedFilePtr clsnFiles[NUM_SIZES];
	
	MovingBar();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~MovingBar() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	virtual void Kill() override;
	
	void ChangeState(u32 newState);
	
	void State0_Init();
	void State0_Main();
	void State1_Init();
	void State1_Main();
	void State2_Init();
	void State2_Main();
	void State3_Init();
	void State3_Main();
	void State4_Init();
	void State4_Main();
	void State5_Init();
	void State5_Main();
	void State6_Init();
	void State6_Main();
};