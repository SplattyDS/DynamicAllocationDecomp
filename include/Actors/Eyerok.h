#pragma once

struct Eyerok : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile; // 0x0211ae6c
	static SharedFilePtr clsnFile;  // 0x0211ae24
	
	static SharedFilePtr handModelFiles[2];   // 0x0211aeb4, 0x0211ae4c
	
	static SharedFilePtr waitClsnFiles[2];    // 0x0211ae1c, 0x0211ae34
	static SharedFilePtr moveClsnFiles[2];    // 0x0211aeac, 0x0211ae14
	
	static SharedFilePtr closeTexSeqFiles[2]; // 0x0211ae3c, 0x0211aebc
	static SharedFilePtr openTexSeqFiles[2];  // 0x0211ae2c, 0x0211ae9c
	
	static SharedFilePtr wakeUpAnimFiles[2];  // 0x0211ae74, 0x0211ae7c
	static SharedFilePtr waitAnimFiles[2];    // 0x0211ae64, 0x0211ae44
	static SharedFilePtr waitEndAnimFiles[2]; // 0x0211ae54, 0x0211ae94
	static SharedFilePtr damageAnimFiles[2];  // 0x0211ae5c, 0x0211ae84
	static SharedFilePtr deadAnimFiles[2];    // 0x0211aea4, 0x0211ae8c
	
	static SpawnInfo spawnData;
};