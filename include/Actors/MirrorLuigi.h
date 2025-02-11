#pragma once

struct MirrorLuigi : Actor
{
	struct State
	{
		using StateFunc = bool (MirrorLuigi::*)(Player& player);
		
		StateFunc init;
		StateFunc main;
	};
	
	ModelAnim bodyModel;        // 0xd4
	Model headModel;            // 0x138
	ShadowModel shadow;         // 0x188
	TextureSequence bodyTexSeq; // 0x1b0
	TextureSequence headTexSeq; // 0x1c4
	State* state;               // 0x1d8
	Matrix4x3 shadowMat;        // 0x1dc
	
	static SpawnInfo spawnData;
	
	MirrorLuigi();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~MirrorLuigi() override;
	
	void ChangeState(State& newState, Player& player);
	
	bool St_UpdatePos_Init();
	bool St_UpdatePos_Main(Player& player);
	
	static void PlayTransformationSound();
};