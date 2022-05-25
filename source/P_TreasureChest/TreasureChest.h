#ifndef TREASURE_CHEST_INCLUDED
#define TREASURE_CHEST_INCLUDED

#include "../SM64DS_2.h"

// vtable at 0x0211c50c, size is 0x178, actor id is 0xd
struct TreasureChest : public Actor
{
	ModelAnim modelAnim;		// 0xd4
	MovingCylinderClsn cylClsn;	// 0x138
	unsigned state;				// 0x16c
	uint16_t cooldown;			// 0x170
	uint8_t order;				// 0x172
	bool spawnStar;				// 0x173
	uint8_t starID;				// 0x174
	uint8_t trackedStarID;		// 0x175
	
	void UpdateModelTransform();				// 0x0211a284
	void ChangeState(unsigned state);			// 0x0211a6ec
	void CallState();							// 0x0211a734
	void State0_Init();							// 0x0211a6e0
	void State0_Main();							// 0x0211a4c4
	void State1_Init();							// 0x0211a49c
	void State1_Main();							// 0x0211a39c
	void State2_Init();							// 0x0211a380
	void State2_Main();							// 0x0211a2c4
	
	//TreasureChest();							// 0x0211a8f0
	virtual int InitResources() override;		// 0x0211a814
	virtual int CleanupResources() override;	// 0x0211a77c
	virtual int Behavior() override;			// 0x0211a7ec
	virtual int Render() override;				// 0x0211a7c4
	//virtual ~TreasureChest() override;		// 0x0211a200
	//virtual ~TreasureChest() override;		// 0x0211a238
	
	static SharedFilePtr modelFile;				// 0x0211c96c
	static SharedFilePtr animFile;				// 0x0211c964
	static SpawnInfo spawnData;					// 0x0211c4e8
};

static_assert(sizeof(TreasureChest) == 0x178, "TreasureChest is wrong size");

#endif