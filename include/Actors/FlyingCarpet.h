#pragma once

struct FlyingCarpet : PathLift
{
	ModelAnim modelAnim; // 0x450
	// u32 unk4b4;       // 0x4b4 (unused)
	// u32 unk4b8;       // 0x4b8 (unused)
	Fix12i offsetY;      // 0x4bc
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	static SharedFilePtr animFile;
	
	FlyingCarpet();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~FlyingCarpet() override;
	
	void UpdateModelTransform();
	void UpdateClsnTransform();
};