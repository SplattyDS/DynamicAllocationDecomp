#ifndef BOWSER_INCLUDED
#define BOWSER_INCLUDED

#include "../SM64DS_2.h"

struct Bowser : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr texSeqFiles[6];
	static SharedFilePtr animFiles[28];
	
	static SpawnInfo spawnData;
};

struct BowserTail : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SpawnInfo spawnData;
};

#endif