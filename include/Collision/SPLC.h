#pragma once

struct SPLC
{
	enum _TextureID
	{
		TX_NORMAL              = 0x0,
		TX_PATH                = 0x1,
		TX_GRASS               = 0x2,
		TX_PUDDLE              = 0x3,
		TX_ROCK                = 0x4,
		TX_WOOD                = 0x5,
		TX_SNOW                = 0x6,
		TX_ICE                 = 0x7,
		TX_SAND                = 0x8,
		TX_FLOWERS             = 0x9,
		TX_MERRY_GO_ROUND_ROCK = 0xa,
		TX_MERRY_GO_ROUND_WOOD = 0xb,
		TX_GRATE               = 0xc,
		TX_SILENT_0            = 0xd,
		TX_SILENT_1            = 0xe,
		TX_SILENT_2            = 0xf
	};
		
	enum _TractionID
	{
		TR_NORMAL                  = 0x0,
		TR_UNSLIPPABLE             = 0x1,
		TR_UNSLIPPABLE_2           = 0x2,
		TR_SLIPPERY_SLOPE          = 0x3,
		TR_SLIPPERY                = 0x4,
		TR_SLIP_NO_WALL_JUMP_ABOVE = 0x5, // Prevents wall jumps when it's the players floorTracID
		TR_NO_CRAWL_SLOPES         = 0x6,
		TR_NO_CRAWL_SLOPES_2       = 0x7
	};
			
	enum _CamBehavID
	{
		CA_NO_CHANGE          = 0x0,
		CA_GO_BEHIND          = 0x1,
		CA_ZOOM_OUT_GO_BEHIND = 0x2,
		CA_GO_BEHIND_3        = 0x3,
		CA_GO_BEHIND_4        = 0x4,
		CA_UNK_5              = 0x5,
		CA_NORMAL             = 0x6,
		CA_GO_BEHIND_7        = 0x7,
		CA_GO_BEHIND_8        = 0x8,
		CA_EIGHT_DIRECTIONS   = 0x9,
		CA_NO_ROTATING        = 0xa,
		CA_ZOOM_REALLY_FAR_IN = 0xb,
		CA_GO_BEHIND_C        = 0xc,
		CA_GO_BEHIND_D        = 0xd,
		CA_GO_BEHIND_E        = 0xe,
		CA_GO_BEHIND_F        = 0xf
	};
			
	enum _BehaviorID
	{
		BH_NORMAL                 = 0x0,
		BH_LAVA                   = 0x1,
		BH_UNK_02                 = 0x2,
		BH_HANG_CEILING           = 0x3,
		BH_DEATH                  = 0x4,
		BH_DEATH_2                = 0x5,
		BH_LOW_JUMPS              = 0x6,
		BH_SLOW_SHALLOW_QUICKSAND = 0x7,
		BH_SLOW_DEEP_QUICKSAND    = 0x8,
		BH_INSTANT_QUICKSAND      = 0x9,
		BH_UNK_0A                 = 0xa,
		BH_WIND                   = 0xb,
		BH_UNK_0C                 = 0xc,
		BH_SWITCH_LEVEL_ENTRANCE  = 0xd,
		BH_NO_GETTING_STUCK       = 0xe,
		BH_RACE_START             = 0xf,
		BH_RACE_END               = 0x10,
		BH_VANISH_LUIGI_GRATE     = 0x11,
		BH_ENDLESS_STAIRS         = 0x12,
		BH_WIND_GUST              = 0x13,
		BH_CRAWL_THROUGH          = 0x14
	};
	
	u32  textureID       :  5 = TX_NORMAL;
	bool isWater         :  1 = false;
	u32  viewID          :  6 = 0x3f;
	u32  tractionID      :  3 = TR_NORMAL;
	u32  camBehavID      :  4 = CA_NO_CHANGE;
	u32  behaviorID      :  5 = BH_NORMAL;
	bool camGoesThru     :  1 = false;
	bool isToxic         :  1 = false;
	bool onlyCamCollides :  1 = false;
	u32  padding         :  5 = 0;
	u32  windID          :  8 = 0xff;
	u32  padding2        : 24 = 0;
};
	
struct SPLC_Header
{
	char magic[4] = {'C', 'L', 'P', 'S'};
	u16 unk04 = 8;
	u16 size; // number of SPLCes
	
	constexpr SPLC_Header(u16 size) : size(size) {}
	
	SPLC_Header(const SPLC_Header&) = delete;
	SPLC_Header(SPLC_Header&&) = delete;
	
	SPLC_Header& operator=(const SPLC_Header&) = delete;
	SPLC_Header& operator=(SPLC_Header&&) = delete;
};

struct SPLC_Block : SPLC_Header
{
	SPLC splces[]; // flexible arrays CAN be static-initialized
	
	constexpr       SPLC* begin()       { return &splces[0]; }
	constexpr const SPLC* begin() const { return &splces[0]; }
	constexpr       SPLC* end  ()       { return &splces[size]; }
	constexpr const SPLC* end  () const { return &splces[size]; }
	
	constexpr       SPLC& operator[](std::size_t i)       { return splces[i]; }
	constexpr const SPLC& operator[](std::size_t i) const { return splces[i]; }
};

template<SPLC... splces>
struct StaticSPLC_Block
{
	template<auto...>
	static constinit inline SPLC_Block instance
	{
		sizeof...(splces),
		{splces...}
	};
};

struct OldSPLC
{
	u32 low;
	u32 high;
};

template<s32 Size> struct OldFixedSizeSPLC_Block // flexible arrays SOMETIMES be static-initialized.
{
	char magic[4]; // = {'C', 'L', 'P', 'S'};
	u16 unk04;
	u16 num; // = Size;
	OldSPLC splces[Size];
};

// delete this later
namespace LevelFile
{
	extern "C" SPLC_Block* SPLC_BLOCK_PTR;
}

struct SurfaceInfo
{
	SPLC splc;
	Vector3 normal;
	
	void CopyNormalTo(Vector3& vec) const;
};