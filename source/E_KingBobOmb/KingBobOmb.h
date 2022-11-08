#ifndef KING_BOB_OMB_INCLUDED
#define KING_BOB_OMB_INCLUDED

#include "../SM64DS_2.h"

struct KingBobOmb : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[12];
	
	static SpawnInfo spawnData;
};

#endif