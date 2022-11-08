#ifndef HOOT_THE_OWL_INCLUDED
#define HOOT_THE_OWL_INCLUDED

struct HootTheOwl : Actor
{
	u32 membersNotDocumented;
	
	// functions not documented
	
	static SharedFilePtr modelFile;
	static SharedFilePtr animFiles[3];
	
	static SpawnInfo spawnData;
};

#endif