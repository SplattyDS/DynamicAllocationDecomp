#pragma once

struct CapIcon
{
	u32* vTable;    // 0x0 (0x020ad470)
	Actor* actor;   // 0x4
	u32 objID;      // 0x8
	CapIcon* next;  // 0xc
	CapIcon* prev;  // 0x10
	u32 arrayIndex; // 0x14 (index for DAT_0209f3e8)
	u8 character;   // 0x18 (index for CAP_ICON_ARR, DAT_020ad630)
	u8 unk19;       // 0x19
	u8 unk1a;       // 0x1a
	u8 unk1b;       // 0x1b
};

struct CapEnemy : Enemy
{
	u8 capParam;        // 0x110
	bool hasNotSpawned; // 0x111
	s8 spawnCapFlag;    // 0x112
	s8 capID;           // 0x113
	Model capModel;     // 0x114
	CapIcon capIcon;    // 0x164
	
	CapEnemy();
	virtual ~CapEnemy() override;
	
	void Unk_02005d94();
	bool DestroyIfCapNotNeeded(); //returns true if the cap is needed (player is different character than cap or 0x0209f2d8 has a 0)
	s32 GetCapState(); //returns 2 if obj+0x111 = 0, else 0 if dead or capID == player character, else 1
	CapEnemy* RespawnIfHasCap(); //nullptr if failed
	bool GetCapEatenOffIt(const Vector3& offset); //returns whether there was a cap and the cap is not the original object
	Actor* ReleaseCap(const Vector3& offset); //returns the ptr to the cap if cap was released, ptr to original obj else.
	void RenderCapModel(const Vector3* scale);
	void UpdateCapPos(const Vector3& offsetPos, const Vector3_16& rot);
	Actor* AddCap(u32 capID);
	void UnloadCapModel();
};

static_assert(sizeof(CapIcon) == 0x1c, "CapIcon is wrong size");
static_assert(sizeof(CapEnemy) == 0x180, "CapEnemy is wrong size");