#pragma once

struct PyramidTag : Actor
{
	MovingCylinderClsn cylClsn; // 0xd4
	u32 pyramidTopID;           // 0x108
	
	static SpawnInfo spawnData;
	
	PyramidTag();
	virtual s32 InitResources() override;
	virtual s32 Behavior() override;
	virtual ~PyramidTag() override;
};