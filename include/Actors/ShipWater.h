#pragma once

struct ShipWater : Platform
{
	TextureTransformer texSRT; // 0x320
	Fix12i originalPosY;       // 0x334
	bool chestsOpen;           // 0x338
	u32 soundID;               // 0x33c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	ShipWater();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~ShipWater() override;
};