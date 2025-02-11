#pragma once

struct DockPole : Actor
{
	Model model;                       // 0xd4
	MovingCylinderClsnWithPos cylClsn; // 0x124
	PathPtr pathPtr;                   // 0x164
	u32 numPathNodes;                  // 0x16c
	s32 curPathNode;                   // 0x170
	s32 direction;                     // 0x180
	u16 waitTimer;                     // 0x184
	ShadowModel shadow;                // 0x188
	Matrix4x3 shadowMat;               // 0x1b0
	Fix12i floorPosY;                  // 0x1e0
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	
	DockPole();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~DockPole() override;
	
	void UpdateModelTransform();
	void DropShadow();
};