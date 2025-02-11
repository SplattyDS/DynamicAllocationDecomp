#pragma once

struct SnowmanBreath : Actor
{
	struct BreathParticle
	{
		CylinderClsnWithPos cylClsn; // 0x0
		u32 particleID;              // 0x3c
		Vector3 pos;                 // 0x40
		// Vector3 unk4c;            // 0x4c
		Vector3_16 ang;              // 0x58
		u8 killTimer;                // 0x5e
		
		BreathParticle();
		~BreathParticle();
		
		bool Init(Player& player); // false if already active
		void Behavior();
		void Render();
		
		void UpdatePosWithRot();
		void CheckClsnWithPenguin();
		void CheckClsnWithPlayer();
	};
	
	static constexpr s32 NUM_BREATH_PARTICLES = 50;
	
	BreathParticle particles[NUM_BREATH_PARTICLES]; // 0xd4
	Matrix4x3 invTransformMat; // 0x1394
	Player* player;            // 0x13c4
	u32 unk13c8;               // 0x13c8
	u32 soundID;               // 0x13cc
	bool finishedTalking;      // 0x13d0
	// u8 unk13d1;             // 0x13d1 (unused)
	u8 talkState;              // 0x13d2
	u8 unk13d3;                // 0x13d3
	
	static SpawnInfo spawnData;
	
	SnowmanBreath();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~SnowmanBreath() override;
	
	bool IsPlayerOnBridge();
};