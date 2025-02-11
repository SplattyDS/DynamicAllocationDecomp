#pragma once

struct ThwompRes : PlatformRes
{
	SharedFilePtr* texSeqFile; // 0xc
	Fix12i width;              // 0x10
	Fix12i depth;              // 0x14
};

struct ThwompBase : Platform
{
	ThwompRes* res;         // 0x320
	TextureSequence texSeq; // 0x324
	ShadowModel shadow;     // 0x338
	Matrix4x3 shadowMat;    // 0x360
	Fix12i maxPosY;         // 0x390
	Fix12i minPosY;         // 0x394
	u32 state;              // 0x398
	s16 targetDir;          // 0x39c
	u8 waitTimer;           // 0x39e
	u8 timesJumped;         // 0x39f
	u16 stateTimer;         // 0x3a0
	bool unk3a2;            // 0x3a2 (if true, waits 3 seconds extra in states 3 and 4)
	
	virtual s32 CleanupResources() override;
	virtual s32 Render() override;
	virtual ~ThwompBase() override;
	
	s32 BaseInitResources();
	
	void DropShadow();
	bool IsYoshiEggInRange();
	
	void GoUp();
	void WaitUp();
	void HitGround();
	void WaitGround();
	void WaitGroundRand();
};

struct Thwomp : ThwompBase
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static SharedFilePtr texSeqFile;
	static ThwompRes resources;
	
	Thwomp();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~Thwomp() override;
	virtual void OnHitByMegaChar(Player& megaChar) override;
	virtual Fix12i OnAimedAtWithEgg() override;
};

struct Grindel : ThwompBase
{
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static ThwompRes resources;
	
	Grindel();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~Grindel() override;
	virtual Fix12i OnAimedAtWithEgg() override;
	
	void Jump();
	void JumpWait();
	void TurnAround();
};