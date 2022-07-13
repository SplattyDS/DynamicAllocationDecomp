#ifndef SM64DS_MODEL_INCLUDED
#define SM64DS_MODEL_INCLUDED

#include "SM64DS_Common.h"

/*
	It is guaranteed that all structs with a vtable have all virtual functions defined. 
	To find the missing functions, start from the dtor and look for push instructions.
	Static functions can be easily found by testing r0 for an object's instance. If it's not, you have a static function.
	'done' denotes that all of the object's members have been found. However, they may not all have a trivial name.
*/


struct Model;
struct ModelAnim;
struct MaterialChanger;
struct TextureSequence;
struct ShadowModel;
extern "C"
{
	//Remember to have these loaded before spawning an object with them
	//They are as disorganized here as they are in memory.
	extern SharedFilePtr LUIGI_CAP_MODEL_PTR;
	extern SharedFilePtr RED_NUMBER_MODEL_PTR;
	extern SharedFilePtr POWER_FLOWER_OPEN_MODEL_PTR;
	extern SharedFilePtr COIN_YELLOW_POLY32_MODEL_PTR;
	extern SharedFilePtr WARIO_CAP_MODEL_PTR;
	extern SharedFilePtr COIN_BLUE_POLY32_MODEL_PTR;
	extern SharedFilePtr POWER_FLOWER_CLOSED_MODEL_PTR;
	extern SharedFilePtr ONE_UP_MUSHROOM_MODEL_PTR;
	extern SharedFilePtr BOB_OMB_MODEL_PTR;
	extern SharedFilePtr NUMBER_TEXSEQ_PTR;
	extern SharedFilePtr SNUFIT_BULLET_MODEL_PTR;
	extern SharedFilePtr COIN_RED_POLY32_MODEL_PTR;
	extern SharedFilePtr COIN_BLUE_POLY4_MODEL_PTR;
	extern SharedFilePtr SILVER_NUMBER_TEXSEQ_PTR;
	extern SharedFilePtr WATER_RING_MODEL_PTR;
	extern SharedFilePtr SHELL_GREEN_MODEL_PTR;
	extern SharedFilePtr SHELL_RED_MODEL_PTR;
	extern SharedFilePtr SILVER_NUMBER_MODEL_PTR;
	extern SharedFilePtr SUPER_MUSHROOM_MODEL_PTR;
	extern SharedFilePtr BUBBLE_MODEL_PTR;
	extern SharedFilePtr MARIO_CAP_MODEL_PTR;
	extern SharedFilePtr COIN_YELLOW_POLY4_MODEL_PTR;
	extern SharedFilePtr COIN_RED_POLY4_MODEL_PTR;
	extern SharedFilePtr FEATHER_MODEL_PTR;
	
	//Graphics ports
	//Do NOT read from the ports!
	extern volatile u32 GXPORT_MATRIX_MODE;
	extern volatile u32 GXPORT_MTX_LOAD_4x4;
	extern volatile u32 GXPORT_MTX_LOAD_4x3;
	extern volatile u32 GXPORT_LIGHT_VECTOR;
	extern volatile u32 GXPORT_LIGHT_COLOR;
	
	extern u16 CHANGE_CAP_TOON_COLORS[0x20];
}

namespace Vram
{
	void StartTexWrite();
	void LoadTex(u8* texelArr, u32 texVramOffset, u32 texelArrSize);
	void EndTexWrite();
	void StartPalWrite();
	void LoadPal(u16* palColArr, u32 palVramOffset, u32 palleteSize);
	void EndPalWrite();
};

namespace GXFIFO
{
	inline void LoadMatrix4x3(const Matrix4x3* matrix)
	{
		GXPORT_MTX_LOAD_4x3 = matrix->c0.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c0.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c0.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c1.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c1.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c1.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c2.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c2.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c2.z.val;
		GXPORT_MTX_LOAD_4x3 = matrix->c3.x.val;		GXPORT_MTX_LOAD_4x3 = matrix->c3.y.val;		GXPORT_MTX_LOAD_4x3 = matrix->c3.z.val;
	}

	//Do NOT set the light vector to <1, 0, 0>, <0, 1, 0>, or <0, 0, 1>. Instead, do <0x0.ff8, 0, 0>, for example.
	inline void SetLightVector(s32 lightID, Fix12i x, Fix12i y, Fix12i z) //Fixed Point 20.12
	{
		GXPORT_LIGHT_VECTOR = (((z.val >> 3 & 0x1ff) | (z.val >> 22 & 0x200)) << 10 |
								(y.val >> 3 & 0x1ff) | (y.val >> 22 & 0x200)) << 10 |
								(x.val >> 3 & 0x1ff) | (x.val >> 22 & 0x200) | lightID << 30;
	}
	
	inline void SetLightVector(int lightID, const Vector3& v)
	{
		SetLightVector(lightID, v.x, v.y, v.z);
	}
	
	inline void SetLightColor(s32 lightID, u8 r, u8 g, u8 b) //0x00 to 0xff
	{
		GXPORT_LIGHT_COLOR = (u32)b >> 3 << 10 |
							 (u32)g >> 3 <<  5 |
							 (u32)r >> 3 | lightID << 30;
	}
}

struct Command30
{
	unsigned diffuse : 15;
	unsigned ambient : 15;
	bool setsVertexColor : 1 = false;

	constexpr operator unsigned() const
	{
		return diffuse | setsVertexColor << 15 | ambient << 16;
	}
};

struct Command31
{
	unsigned specular : 15;
	unsigned emission : 15;
	bool usesShininessTable : 1 = false;

	constexpr operator unsigned() const
	{
		return specular | usesShininessTable << 15 | emission << 16;
	}
};

struct BMD_File
{
	struct Bone
	{
		enum Flags
		{
			BILLBOARD = 1 << 0
		};

		int boneID;
		char* name;
		short offsetToParent; // in bones, not in bytes
		short hasChildren;
		int offsetToNextSibling; // in bones, not in bytes
		Vector3 scale;
		Vector3_16 rotation;
		uint16_t unk22; // probably padding
		Vector3 translation;
		unsigned numDisplayListMaterialPairs;
		void* materialIDLis;
		void* diplayListIDList;
		unsigned flags;
	};

	static_assert(sizeof(Bone) == 0x40);

	struct Texture
	{
		char* name;
		char* data; // dangling after Model::LoadFile
		unsigned size;
		uint16_t width;
		uint16_t height;
		unsigned cmd2aPart1;
	};

	static_assert(sizeof(Texture) == 0x14);

	struct Palette
	{
		char* name;
		char* data; // dangling after Model::LoadFile
		unsigned size;
		unsigned vramOffset;
	};

	static_assert(sizeof(Palette) == 0x10);

	struct Material
	{
		char* name;
		int textureID; // -1 when no texture
		int paletteID; // -1 when no palette
		Vector2 scale;
		short rotation;
		Vector2 translation;
		unsigned cmd2aPart2;
		unsigned cmd29;
		unsigned cmd30;
		unsigned cmd31;
	};

	static_assert(sizeof(Material) == 0x30);

	unsigned scaleShift;
	unsigned numBones;
	Bone* bones;
	unsigned numDisplayLists;
	void* displayLists;
	unsigned numTextures;
	Texture* textures;
	unsigned numPalettes;
	Palette* palettes;
	unsigned numMaterials;
	Material* materials;
	void* TransformMap;
	unsigned unk30;
	unsigned unk34;
	unsigned ramSize;
};

static_assert(sizeof(BMD_File) == 0x3c);

struct MaterialProperties
{
	s16 materialID;
	s16 unk02; //probably just padding
	const char* materialName;
	
	char unk08; bool difRedAdv;     u16 difRedOffset;
	char unk0c; bool difGreenAdv;   u16 difGreenOffset;
	char unk10; bool difBlueAdv;    u16 difBlueOffset;
	char unk14; bool ambRedAdv;     u16 ambRedOffset;
	char unk18; bool ambGreenAdv;   u16 ambGreenOffset;
	char unk1c; bool ambBlueAdv;    u16 ambBlueOffset;
	char unk20; bool specRedAdv;    u16 specRedOffset;
	char unk24; bool specGreenAdv;  u16 specGreenOffset;
	char unk28; bool specBlueAdv;   u16 specBlueOffset;
	char unk2c; bool emitRedAdv;    u16 emitRedOffset;
	char unk30; bool emitGreenAdv;  u16 emitGreenOffset;
	char unk34; bool emitBlueAdv;   u16 emiBlueOffset;
	char unk38; bool alphaAdv;      u16 alphaOffset;
};

struct MaterialDef
{
	u16 numFrames;
	u16 unk02;
	char* values;
	s32 matPropCount;
	MaterialProperties* matProp;
};

struct TexSRTAnim
{
	u16 materialID;
	u16 unk02; //probably just padding
	const char* materialName;
	u16 numScaleXs;
	u16 scaleXOffset;
	u16 numScaleYs;
	u16 scaleYOffset;
	u16 numRots;
	u16 rotOffset;
	u16 numTransXs;
	u16 transXOffset;
	u16 numTransYs;
	u16 transYOffset;
	
};

struct TexSRTDef
{
	u32 numFrames;
	Fix12i* scales;
	s16* rots;
	Fix12i* transs;
	s32 texAnimCount;
	TexSRTAnim* texAnims;
};

struct Bone
{
	u32 unk00;
	u32 unk04;
	u32 unk08;
	Vector3 scale;
	u16 unk18;
	Vector3_16 rot;
	Vector3 pos;
	u32 unk2c;
	u32 unk30;
};

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
	
	virtual ~Animation();
	void Advance();
	bool Finished();

	Animation(const Animation&) = delete;
	Animation(Animation&&) = delete;

	s32 GetFlags();
	void SetFlags(s32 flags);
	u32 GetFrameCount();
	void SetAnimation(u16 frames, s32 flags, Fix12i speed = 0x1000_f, u16 startFrame = 0);
	void Copy(const Animation& anim);
	bool Func_02015A98(s32 arg0); //Does something like simulating an advance? Like checking if the next frame expires the animation...

	static char* LoadFile(SharedFilePtr& filePtr);
};

struct Material
{
	u32 unk00;
	u32 unk04;
	Fix12i texScaleX;
	Fix12i texScaleY;
	s16 texRot; //then alignment
	Fix12i texTransX;
	Fix12i texTransY;
	u32 teximageParam; //gx command 0x2a
	u32 paletteInfo;
	u32 polygonAttr; //gx command 0x29
	u32 difAmb; //gx command 0x30
	u32 speEmi; //gx command 0x31
};

struct ModelComponents
{
	BMD_File* modelFile;
	Material* materials;
	Bone* bones;
	Matrix4x3* transforms;
	char* unk10;
	
	void UpdateBones(char* animFile, s32 frame);
	void UpdateVertsUsingBones();
	void Render(Matrix4x3* mat, Vector3* scale);
};

struct MaterialChanger : Animation		//internal: AnmMaterial; done
{
	MaterialDef* material;

	MaterialChanger();
	virtual ~MaterialChanger();
    static void Prepare(char* modelFile, MaterialDef& matDef);
	void SetMaterial(MaterialDef& matDef, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);
};

struct TextureTransformer : Animation	//internal: AnmTexSRT; done
{
	TexSRTDef* texSRT;

	TextureTransformer();
	virtual ~TextureTransformer();
    static void Prepare(char* modelFile, TexSRTDef& texDef);
	void SetTexSRT(TexSRTDef& texDef, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);
};


struct TextureSequence : Animation		//internal: AnmTexPat; done
{
	char* texSequenceFile;

	TextureSequence();
	virtual ~TextureSequence();
    static void Prepare(char* modelFile, char* texSeqFile);
	void SetFile(char* texSeqFile, s32 flags, Fix12i speed, u32 startFrame);
	void Update(ModelComponents& modelData);	

	static char* LoadFile(SharedFilePtr& filePtr);
};

struct ModelBase	//internal: Model; done
{
	//vtable
	u32 unk04;			//Pointer that is freed in all dtors

	ModelBase();
	virtual ~ModelBase();

	ModelBase(const ModelBase&) = delete;
	ModelBase(ModelBase&&) = delete;

	bool SetFile(char* file, s32 arg1, s32 arg2);
	virtual bool DoSetFile(char* file, s32 arg1, s32 arg2) = 0;
};

struct Model : public ModelBase		//internal: SimpleModel
{
	ModelComponents data;
	Matrix4x3 mat4x3;
	Matrix4x3* unkMatPtr;
	
	Model();
	virtual ~Model();
	virtual bool DoSetFile(char* file, s32 arg1, s32 arg2) override;
	virtual void UpdateVerts();
	virtual void Virtual10(Matrix4x3& arg0);
	virtual void Render(const Vector3* scale = nullptr);
	
	static char* LoadFile(SharedFilePtr& filePtr);
};

struct ModelAnim : public Model, Animation	//internal: ModelAnm
{
	//vtable
	//Animation data
	char* file;

	ModelAnim();
	virtual ~ModelAnim();
	virtual void UpdateVerts() override;
	virtual void Virtual10(Matrix4x3& arg0) override;
	virtual void Render(const Vector3* scale = nullptr) override; // Calls UpdateVerts and then Model::Render
	virtual void Virtual18(u32 arg0, const Vector3* scale);  // Calls Virtual10 and then Model::Render
	
	void SetAnim(char* animFile, s32 flags, Fix12i speed = 0x1000_f, u32 startFrame = 0);

	void Copy(const ModelAnim& anim, char* newFile);					//if newFile != nullptr, it gets copied instead of anim->file
};

struct ModelAnim2 : public ModelAnim	//internal: ModelAnm2
{
	u32 unk64;
	Animation otherAnim;
	
	void Copy(const ModelAnim2& anim, char* newFile, u32 newUnk64);	//copies anim to *this, otherAnim is set to anim's Animation base class

	ModelAnim2();
	virtual ~ModelAnim2();

	//2 funcs missing before
	void Func_020162C4(u32 newUnk64, s32 animFlags, Fix12i speed, u16 startFrame);				//Always calls on otherAnim
};

struct ShadowModel : public ModelBase	//internal: ShadowModel; done
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
	virtual ~ShadowModel();
	bool InitCylinder();
	bool InitCuboid();

	// May only have 2 params, but then it wouldn't match ModelBase's declaration
	virtual bool DoSetFile(char* file, s32 arg1, s32 arg2) override;

	// The opacity is from 0 to 30
	void InitModel(Matrix4x3* transform, Fix12i scaleX, Fix12i scaleY, Fix12i scaleZ, u32 opacity);

	static void RenderAll();
	static void Func_02015E14();
};

struct CommonModel : public ModelBase	//internal: CommonModel; done
{
	u32 unkPtr;

	CommonModel();
	virtual ~CommonModel();
	virtual bool DoSetFile(char* file, s32 arg1, s32 arg2) override;

	void Func_0201609C(u32 arg0);
	void Func_020160AC(u32 arg0);
	void Func_02016104(u32 arg0);
};

struct BlendModelAnim : public ModelAnim	//internal: BlendAnmModel
{
	u32 unk64;
	u32 unk68;
	u32 unk6C;

	//0x0208E94C vtable, 0x020166D4 ctor
	BlendModelAnim();
	virtual ~BlendModelAnim();

	virtual bool DoSetFile(char* file, s32 arg1, s32 arg2) override;
	virtual void UpdateVerts() override;
	virtual void Virtual10(Matrix4x3& arg0) override;
	virtual void Render(const Vector3* scale = nullptr) override;
	virtual void Virtual18(u32 arg0, const Vector3* scale) override;		//Calls Virtual10 and then Model::Render

	//2 funcs missing
};

//vtable at 0x0208EAFC
struct Fader		//internal name: dFader
{
	Fix12i currInterp; // 0x4
	Fix12i speed;      // 0x8
	
	virtual ~Fader();
	
	void AdvanceInterp();
};

//vtable at 0x0208EACC
struct FaderBrightness : public Fader		//internal name: dFdBrightness
{
	virtual ~FaderBrightness();
	virtual void AdvanceFade();
	virtual bool SetBackwardTime(u32 frames); // sets the speed so that the fader goes from end to start in `frames` frames
	virtual bool SetForwardTime(u32 frames);  // sets the speed so that the fader goes from start to end in `frames` frames
	virtual bool IsAtStart();
	virtual bool IsAtEnd();
	virtual bool IsBetweenStartAndEnd();
	virtual void SetToEnd();
	virtual void SetToStart();
};

//vtable at 0x0208EA40
struct FaderColor : public FaderBrightness	//internal name: dFdColor
{
	u16 color; // 0xc (only black and white work)
	
	virtual ~FaderColor();
	virtual void AdvanceFade() override;
};

//vtable at 0x0208EA9C
struct FaderWipe : public FaderColor		//internal name: dFdWipe
{
	u16 unk0e; // 0xe
	Model model;    // 0x10
	
	FaderWipe();
	virtual ~FaderWipe();
	virtual void AdvanceFade() override;
};

#endif