#pragma once

struct Clam : Actor
{
	enum Animations
	{
		OPEN,
		CLOSE,
		
		NUM_ANIMS,
	};
	
	ModelAnim modelAnim;        // 0xd4
	MovingCylinderClsn cylClsn; // 0x138
	bool isOpen;                // 0x16c
	u16 openCloseTimer;         // 0x16e
	// u16 unk170;              // 0x170 (set to 10 when player close, gets decremented, never used)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[NUM_ANIMS];
	
	Clam();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Clam() override;
	
	void UpdateModelTransform();
};