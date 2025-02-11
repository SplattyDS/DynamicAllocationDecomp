#pragma once

struct Minimap : ActorDerived
{
	enum ArrowType
	{
		AR_NONE = 0,
		AR_DONT_ROTATE_WITH_MINIMAP = 1,
		AR_ROTATE_WITH_MINIMAP = 2
	};
	
	Matrix2x2 minimapMat;  // 0x50
	s32 mapCenterX;        // 0x60
	s32 mapCenterY;        // 0x64
	u32 unk068;            // unused
	u32 unk06c;            // unused
	s32 playerIconX[4];    // 0x70
	s32 playerIconY[4];    // 0x80
	Matrix2x2 unk090;      // 0x90 (set to 0's, unused)
	s32 starIconX[12];     // 0xa0
	s32 starIconY[12];     // 0xd0
	s32 capIconX[9];       // 0x100
	s32 capIconY[9];       // 0x124
	u32 unk148[12];        // unused
	s32 starKeyIconX;      // 0x178
	s32 starKeyIconY;      // 0x17c
	s32 spikeBombIconX[8]; // 0x180
	s32 spikeBombIconY[8]; // 0x1a0
	u32 unk1c0[5];         // unused
	Fix12i scale;          // 0x1d4
	s32 mapWidth;          // 0x1d8
	s32 mapCenterOffset;   // 0x1dc
	Vector3 initialCenter; // 0x1e0
	u32 unk1ec;            // 0x1ec (set to 0, unused)
	Fix12i currentScale;   // 0x1f0
	Vector3 center;        // 0x1f4
	Matrix2x2 arrowMat;    // 0x200
	Fix12i arrowScale;     // 0x210
	Fix12i targetInvScale; // 0x214
	Fix12i invScale;       // 0x218
	s16 angle;             // 0x21c
	s8 playerMapIDs[4];    // 0x21e
	s8 starMapIDs[12];     // 0x222
	u8 starFadeTimers[12]; // 0x22e
	s8 capMapIDs[9];       // 0x23a
	u8 unk243[5];          // unused
	s8 starKeyMapID;       // 0x248
	s8 spikeBombMapIDs[8]; // 0x249
	u8 arrowType;          // 0x251
	u8 unk252[2];          // unused
	u8 touchCircleTimer;   // 0x254
	bool inIntroCutscene;  // 0x255
	u8 starKeyFadeTimer;   // 0x256
	u8 unk257;             // unused
	
	static BaseSpawnInfo spawnData;
	
	Minimap();
	virtual s32	InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Minimap() override;
	
	static void UpdateLevelSpecific();
	static void FixTHIPaintingRoomPos(Vector3& pos);
	static void GetPosOnMinimap(Vector3& pos, Vector3& center, Fix12i scale, s16 angle, Vector3& res);
	static void GetPosFromMinimapPos(Vector3& posOnMap, Vector3& mapCenter, Fix12i scale, s16 angle, Vector3& res);
};

static_assert(sizeof(Minimap) == 0x258, "Size of Minimap is incorrect.");