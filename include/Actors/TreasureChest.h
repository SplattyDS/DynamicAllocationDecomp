#pragma once

struct TreasureChest : Actor
{
	ModelAnim modelAnim;        // 0xd4
	MovingCylinderClsn cylClsn; // 0x138
	u32 state;                  // 0x16c
	u16 cooldown;               // 0x170
	u8 order;                   // 0x172
	bool spawnStar;             // 0x173
	u8 starID;                  // 0x174
	s8 trackedStarID;           // 0x175
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	TreasureChest();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~TreasureChest() override;
	
	void UpdateModelTransform();
	void ChangeState(u32 state);
	void CallState();
	
	void State0_Init();
	void State0_Main();
	void State1_Init();
	void State1_Main();
	void State2_Init();
	void State2_Main();
};