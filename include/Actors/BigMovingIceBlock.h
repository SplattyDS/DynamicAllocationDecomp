#pragma once

struct BigMovingIceBlock : Platform
{
	PathPtr pathPtr; // 0x320
	s32 curNode;     // 0x328
	s32 direction;   // 0x32c
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	BigMovingIceBlock();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~BigMovingIceBlock() override;
};