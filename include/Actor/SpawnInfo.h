#pragma once

struct BaseSpawnInfo
{
	ActorBase* (*spawnFunc)();
	s16 behavPriority;
	s16 renderPriority;
};

struct SpawnInfo : BaseSpawnInfo
{
	u32 flags;
	Fix12i rangeOffsetY;
	Fix12i range;
	Fix12i drawDist;
	Fix12i unk18;
};

static_assert(sizeof(BaseSpawnInfo) == 0x8);
static_assert(sizeof(SpawnInfo) == 0x1c);