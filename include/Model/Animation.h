#pragma once

struct ModelComponents;

struct Animation	//internal: FrameCtrl; done
{
	static constexpr s32 FLAG_MASK = 0xC0000000;
	
    enum Flags : s32
    {
		LOOP = 0x00000000,
		NO_LOOP = 0x40000000
    };
	
	//vtable
	Fix12i numFramesAndFlags;
	Fix12i currFrame;
	Fix12i speed;
	
	Animation();
	virtual ~Animation();
	
	Animation(const Animation&) = delete;
	Animation(Animation&&) = delete;
	
	void Advance();
	bool Finished();
	
	s32 GetFlags();
	void SetFlags(s32 flags);
	u16 GetFrameCount() const;
	void SetAnimation(u16 frames, s32 flags, Fix12i speed = 0x1000_f, u16 startFrame = 0);
	void Copy(const Animation& anim);
	bool WillHitFrame(s32 frameIndex) const;
	
	static BCA_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(BCA_File& file);
	
	[[gnu::always_inline]]
	bool WillHitLastFrame() const { return WillHitFrame((u16)(GetFrameCount() - 1)); }
	
	[[gnu::always_inline]]
	static inline BCA_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};

struct MaterialChanger : Animation		//internal: AnmMaterial; done
{
	BMA_File* file;
	
	MaterialChanger();
	virtual ~MaterialChanger();
	
	void SetFile(BMA_File& file, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);
	
	static BMA_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(BMA_File& file);
    static void Prepare(BMD_File& modelFile, BMA_File& matChgFile);
	
	[[gnu::always_inline]]
	static inline BMA_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};

struct TextureTransformer : Animation	//internal: AnmTexSRT; done
{
	BTA_File* file;
	
	TextureTransformer();
	virtual ~TextureTransformer();
	
	void SetFile(BTA_File& file, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);
	
	static BTA_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(BTA_File& file);
    static void Prepare(BMD_File& modelFile, BTA_File& texSrtFile);
	
	[[gnu::always_inline]]
	static inline BTA_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};

struct TextureSequence : Animation		//internal: AnmTexPat; done
{
	BTP_File* file;
	
	TextureSequence();
	virtual ~TextureSequence();
	
	void SetFile(BTP_File& file, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);	
	
	static BTP_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(BTP_File& file);
	static void Prepare(BMD_File& modelFile, BTP_File& texSeqFile);
	
	[[gnu::always_inline]]
	static inline BTP_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};