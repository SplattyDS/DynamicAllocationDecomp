#pragma once

struct Snowman : Actor
{
	enum TexSeqs
	{
		CRY,
		SMILE,
		
		NUM_TEX_SEQS,
	};
	
	Model headModel;                   // 0xd4
	Model bodyModel;                   // 0x124
	TextureSequence texSeq;            // 0x174
	ShadowModel shadow;                // 0x188
	MovingCylinderClsnWithPos cylClsn; // 0x1b0
	
	static SpawnInfo spawnData;
	static SharedFilePtr headModelFile; // also used by SnowmanHead
	static SharedFilePtr bodyModelFile; // also used by SnowmanBody
	static SharedFilePtr texSeqFiles[NUM_TEX_SEQS]; // used by both, only used by SnowmanHead
	
	Snowman();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~Snowman() override;
	
	void UpdateModelTransform();
	void DropShadow();
};

static_assert(sizeof(Snowman) == 0x1f0);