#pragma once

struct BabyPenguin : Actor
{
	struct State
	{
		using StateFunc = void(BabyPenguin::*)();
		
		StateFunc init;
		StateFunc main;
	};
	
	enum Animations
	{
		WAIT,
		WALK,
		DIVE,
		SLIDER,
		STAND_UP,
		
		NUM_ANIMS,
	};
	
	ModelAnim modelAnim;        // 0xd4
	ShadowModel shadow;         // 0x138
	MovingCylinderClsn cylClsn; // 0x160
	WithMeshClsn wmClsn;        // 0x194
	Vector3 originalPos;        // 0x350
	State* state;               // 0x35c
	Player* carrier;            // 0x360
	Actor* mother;              // 0x364
	u16 respawnTimer;           // 0x36c
	u8 stateState;              // 0x36e
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	static State ST_WALK;
	static State ST_DIVE;
	static State ST_GRABBED;
	static State ST_WALK_AROUND_MOTHER;
	static State ST_EATEN;
	static State ST_SPIT;
	
	BabyPenguin();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BabyPenguin() override;
	virtual u32 OnYoshiTryEat() override;
	virtual void OnTurnIntoEgg(Player& player) override;
	
	void ChangeState(State* newState);
	void CallState();
	void UpdateModelTransform();
	void DropShadow();
	void RespawnIfPossible();
	void DiveIfPlayerDives();
	void CheckIfNearMother();
	void UpdateWmClsn();
	bool IsGoingOffCliff();
	bool CheckCylClsn();
	
	void St_Walk_Init();
	void St_Walk_Main();
	void St_Dive_Init();
	void St_Dive_Main();
	void St_Grabbed_Init();
	void St_Grabbed_Main();
	void St_WalkAroundMother_Init();
	void St_WalkAroundMother_Main();
	void St_Eaten_Init();
	void St_Eaten_Main();
	void St_Spit_Init();
	void St_Spit_Main();
};