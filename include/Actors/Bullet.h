#pragma once

struct Bullet : Enemy
{
	MovingCylinderClsn cylClsn; // 0x110
	WithMeshClsn wmClsn;        // 0x144
	Model model;                // 0x300
	// State* state;            // 0x350
	bool hitMetalPlayer;        // 0x354
	// u32 unk358;              // 0x358 (1 if param1 == 1, 0 otherwise)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	Bullet();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Bullet() override;
	
	void UpdateModelTransform();
	void Update();
	void HurtPlayer();
};