#pragma once

struct WaterRing : Enemy
{
	struct State
	{
		using StateFunc = bool (WaterRing::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	MovingCylinderClsnWithPos cylClsn; // 0x110
	WithMeshClsn wmClsn;               // 0x150
	Model model;                       // 0x30c
	TextureTransformer texSRT;         // 0x35c
	State* state;                      // 0x370
	s16 scaleAng;                      // 0x374 (was an s32, but it's used as an s16)
	u16 padding376;                    // remove when objects that spawn WaterRing are decompiled
	s16 motionAngXAng;                 // 0x378 (was an s32, but it's used as an s16)
	u16 padding37a;                    // remove when objects that spawn WaterRing are decompiled
	u32 param;                         // 0x37c
	u8 opacity;                        // 0x380
	Fix12i maxScale;                   // 0x384
	s16 horzAngToPlayer;               // 0x388
	Actor* spawner;                    // 0x38c
	
	static SpawnInfo spawnData;
	
	WaterRing();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~WaterRing() override;
	
	void ChangeState(State& newState);
	void UpdateModelTransform();
	void CheckIfCollected();
	
	bool St_Wait_Init();
	bool St_Wait_Main();
	bool St_Collected_Init();
	bool St_Collected_Main();
};