#pragma once

struct StarSelect : Scene
{
	enum CharacterIcons
	{
		CAP_ICON_1,
		CAP_ICON_2,
		CAP_ICON_3,
		HEAD_ICON,
		
		NUM_CAP_ICONS = HEAD_ICON,
		NUM_CHAR_ICONS,
		NUM_CAP_CONFIGURATIONS = NUM_CHAR_ICONS,
	};
	
	enum Models
	{
		POWER_STAR_MODEL,
		TRANSPARENT_STAR_MODEL,
		
		NUM_MODELS,
	};
	
	enum SelectionRow
	{
		SR_STAR,
		SR_CAP,
		SR_HEAD,
	};
	
	enum ArrowState
	{
		AS_INVISIBLE,
		AS_NOT_MOVED,
		AS_MOVED,
	};
	
	enum TouchMeBounceState
	{
		BS_INIT,
		BS_BOUNCE_UP,
		BS_BOUNCE_DOWN,
		BS_WAIT,
	};
	
	enum CharacterHeadState
	{
		HS_SHRINK,
		HS_GROW,
		HS_SLOW_GROW_UNTIL_FADE,
		HS_ROTATE_AND_SHRINK,
	};
	
	enum SelectionState
	{
		SS_SELECTING,
		SS_HEAD_SELECTED,
		SS_CAP_SELECTED,
	};
	
	Vector2 charHeadScale;              // 0x50
	Vector2 selectedCapIconScale;       // 0x58
	Fix12i capIconScale;                // 0x60
	Model starModels[NUM_MODELS];       // 0x64
	u16 starArrowTimer;                 // 0x104
	u16 charArrowTimer;                 // 0x106
	u16 tmBounceWaitTimer;              // 0x108
	s16 tmBounceHeightLsl8;             // 0x10a
	s16 tmBounceSpeed;                  // 0x10c
	s16 tmBounceNextSpeed;              // 0x10e
	u16 charHeadAng;                    // 0x110
	s16 capIconScaleAng;                // 0x112
	u8 numStars;                        // 0x114
	u8 selectedStar;                    // 0x115
	u8 lifeIconChar;                    // 0x116
	u8 unk117;                          // 0x117 (was set but didn't do anything)
	u8 unk118;                          // 0x118 (was set but didn't do anything)
	u8 startFadeTimer;                  // 0x119
	u8 starPosX[7];                     // 0x11a
	s8 calculatedDigits[3];             // 0x121
	u8 charIconPosX[NUM_CHAR_ICONS];    // 0x124 (does nothing for HEAD_ICON)
	u8 charIconPosY[NUM_CHAR_ICONS];    // 0x128
	u8 capBubbleIDs[NUM_CHAR_ICONS];    // 0x12c (does nothing for HEAD_ICON)
	u8 numCharacters;                   // 0x130
	u8 unlockedStars;                   // 0x131
	u8 selectedCapChar;                 // 0x132
	u8 selectionRow;                    // 0x133
	u8 selectedCap;                     // 0x134
	u8 arrowState;                      // 0x135
	u8 tmBounceState;                   // 0x136
	u8 charHeadState;                   // 0x137
	u8 unk138;                          // unused
	u8 selectionState;                  // 0x139
	u8 capFrontVisible;                 // 0x13a (when SS_CAP_SELECTED)
	u8 unk13b;                          // unused
	
	static BaseSpawnInfo spawnData;
	
	StarSelect();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~StarSelect() override;
	
	void UpdateCharacterIconSelection();
	u8 GetSelectedCapChar();
	void RenderLifeCounter();
	void RenderStarCounter();
	void RenderCoinCounter();
	u8 GetCapFromChar(u8 character);
	void CalculateDigits(u16 number);
};

static_assert(sizeof(StarSelect) == 0x13c, "Size of StarSelect is incorrect.");