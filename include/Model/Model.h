#pragma once

struct ModelBase	// internal: Model; done
{
	// vtable
	u32 unk04;			// Pointer that is freed in all dtors
	
	ModelBase();
	virtual ~ModelBase();
	virtual bool DoSetFile(BMD_File* file, s32 arg1, s32 arg2) = 0;
	
	ModelBase(const ModelBase&) = delete;
	ModelBase(ModelBase&&) = delete;
	
	bool SetFile(BMD_File* file, s32 arg1, s32 arg2);
	void ApplyOpacity(u32 opacity);
};

struct Model : ModelBase		// internal: SimpleModel
{
	ModelComponents data;
	Matrix4x3 mat4x3;
	Matrix4x3* unkMatPtr;
	
	Model();
	virtual ~Model() override;
	virtual bool DoSetFile(BMD_File* file, s32 arg1, s32 arg2) override;
	virtual void UpdateVerts();
	virtual void Virtual10(Matrix4x3& arg0);
	virtual void Render(const Vector3* scale = nullptr);
	
	void SetPolygonID(s32 polygonID);
	void ShowMaterial(s32 boneID, s32 materialID);
	void HideMaterial(s32 boneID, s32 materialID);
	
	static BMD_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(BMD_File& file);
	static CommonModelData* AddToCommonModelDataArr(BMD_File& file);
	static void LoadTexAndPal(BMD_File& file);
	static u32 LoadTextureToVram(char* texData, u32 texSize); // returns vram offset
	static u32 GetVramOffset(u32 texSize); // of UNCOMPRESSED texture
	static u32 LoadCompressedTextureToVram(char* texData, u32 texSize, char* indexData); // returns vram offset
	
	[[gnu::always_inline]]
	static inline BMD_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};

struct ModelAnim : Model, Animation	// internal: ModelAnm
{
	// vtable
	// Animation data
	BCA_File* file;
	
	ModelAnim();
	virtual ~ModelAnim() override;
	virtual void UpdateVerts() override;
	virtual void Virtual10(Matrix4x3& arg0) override;
	virtual void Render(const Vector3* scale = nullptr) override; // Calls UpdateVerts and then Model::Render
	virtual void Virtual18(u32 arg0, const Vector3* scale);  // Calls Virtual10 and then Model::Render
	
	void SetAnim(BCA_File* animFile, s32 flags, Fix12i speed = 0x1000_f, u32 startFrame = 0);
	void Copy(const ModelAnim& anim, BCA_File* newFile);					// if newFile != nullptr, it gets copied instead of anim->file
};

struct ModelAnim2 : ModelAnim	// internal: ModelAnm2
{
	u32 unk64;
	Animation otherAnim;
	
	ModelAnim2();
	virtual ~ModelAnim2() override;
	
	// 2 funcs missing before
	void Copy(const ModelAnim2& anim, BCA_File* newFile, u32 newUnk64);	// copies anim to *this, otherAnim is set to anim's Animation base class
	void Func_020162C4(u32 newUnk64, s32 animFlags, Fix12i speed, u16 startFrame);				// always calls on otherAnim
};

struct ShadowModel : ModelBase	// internal: ShadowModel; done
{
	ModelComponents* modelDataPtr;
	Matrix4x3* matPtr;
	Vector3 scale;
	u8 opacity;
	u8 unk1d;
	u8 unk1e;
	u8 unk1f;
	ShadowModel* prev;
	ShadowModel* next;
	
	ShadowModel();
	virtual ~ShadowModel() override;
	virtual bool DoSetFile(BMD_File* file, s32 arg1, s32 arg2) override;
	
	bool InitCylinder();
	bool InitCuboid();
	void InitModel(Matrix4x3* transform, Fix12i scaleX, Fix12i scaleY, Fix12i scaleZ, u32 opacity); // opacity is from 0 to 30
	
	static void RenderAll();
	static void Func_02015E14();
};

struct CommonModel : ModelBase	// internal: CommonModel; done
{
	u32 unkPtr;
	
	CommonModel();
	virtual ~CommonModel() override;
	virtual bool DoSetFile(BMD_File* file, s32 arg1, s32 arg2) override;
	
	void Func_0201609C(u32 arg0);
	void Func_020160AC(u32 arg0);
	void Func_02016104(u32 arg0);
};

struct BlendModelAnim : ModelAnim	// internal: BlendAnmModel
{
	u32 unk64;
	u32 unk68;
	u32 unk6C;
	
	// 0x0208E94C vtable, 0x020166D4 ctor
	BlendModelAnim();
	virtual ~BlendModelAnim() override;
	virtual bool DoSetFile(BMD_File* file, s32 arg1, s32 arg2) override;
	virtual void UpdateVerts() override;
	virtual void Virtual10(Matrix4x3& arg0) override;
	virtual void Render(const Vector3* scale = nullptr) override;
	virtual void Virtual18(u32 arg0, const Vector3* scale) override;		// Calls Virtual10 and then Model::Render
	
	// 2 funcs missing
};