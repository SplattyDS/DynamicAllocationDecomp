#pragma once

struct Number : Actor
{
	Model model;
	TextureSequence textureSequence;
	u32 unkActorUniqueID;
	Vector3 spawnPos;
	Fix12i unk148;
	u16 unk14c;
	u8 numTimesBounced;
	u8 unk14f;
};

static_assert(sizeof(Number) == 0x150, "Number is wrong size");