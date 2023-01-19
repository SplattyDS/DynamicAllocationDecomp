#pragma once

struct Wiggler : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFiles[5];         // 0x02114660, 0x02114688, 0x02114670, 0x021146f0, 0x02114700
	static SharedFilePtr texSeqFiles[5];        // 0x02114730, 0x02114708, 0x02114690, 0x021146c0, 0x02114720
	static SharedFilePtr waitAnimFiles[5];      // 0x02114710, 0x02114630, 0x02114698, 0x02114718, 0x02114638
	static SharedFilePtr walkAnimFiles[5];      // 0x021146b8, 0x02114728, 0x021146b0, 0x021146c8, 0x021146a0
	static SharedFilePtr walkStartAnimFiles[5]; // 0x021146d0, 0x02114648, 0x021146d8, 0x021146e0, 0x02114668
	static SharedFilePtr walkEndAnimFiles[5];   // 0x02114650, 0x02114678, 0x021146f8, 0x02114680, 0x02114628
	static SharedFilePtr damageAnimFiles[5];    // 0x02114620, 0x02114640, 0x021146a8, 0x02114658, 0x021146e8
	
	static SpawnInfo spawnData;
};