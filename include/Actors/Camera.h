#pragma once

struct CameraDef
{
	s32 unk00; //something to do with going behind the player...
	s32 unk04;
	s32 camVertAngIsh;
	u32 unk0c;
	s32 vertOffset;
	s32 offsetIsh; //???
	u32 jumpWithPlayerIsh;
	s32 dist0; //???
	s32 dist1;
	u16 fovOver2;
	u16 unk26;
};

//vtable at 0x02092720
struct View : ActorDerived		//internal name: dView; done
{
	Matrix4x3 camMat;					//View Matrix to use when rendering
	
	virtual s32 Render() override;		//Sets the global view matrix to camMat and calculates the global inverse view matrix
	virtual ~View() override;
};

//vtable at 0x0208E730
struct Clipper
{
	Vector3 unk04[4]; // 0x4, 0x10, 0x1c, 0x28
	u32 unk34;
	u32 unk38;
	u32 unk3c;
	u32 unk40;
	u32 unk44;
	u32 unk48;
	Fix12i aspectRatio;					//Aspect ratio
	Fix12i unk50;
	Fix12i unk54;
	u16 unk58;
	
	Clipper();
	virtual ~Clipper();
	
	Fix12i Func_020150E8(Vector3& arg1, Fix12i arg2, u8* arg3);
	Fix12i Func_02015560(Matrix4x3& arg1, Vector3& arg2, Fix12i arg3, Vector3& arg4);
	void Func_0201559C();	//noargs
	void Func_020156DC();
};

//vtable at 0x02086F84, ctor at 0x0200E444
struct Camera : View				//internal name: dCamera
{
	static constexpr u32 cameraDefTable = 0x02086FCC;
	static constexpr u32 settingBehaviourTableBase = 0x0209B008;
	/*
	0: Default
	1: Bottom camera, close (swimming on surface)
	2: Bottom camera, far (diving)
	3: Fly (feather, cannon shoot)
	4: Top view (owl)
	6: Air-driven (wind, Balloon Mario)
	7: Climbing
	8: Fixed back sliding
	9: First person
	B: Enter cannon
	C: Cannon view
	D: Talking
	E: Door enter
	F: Painting zoom
	11: Front zoom (character introduction)
	*/
	
	enum Flags
	{
		IS_UNDERWATER      = 1 << 0,
		
		ZOOMED_OUT         = 1 << 2,
		BOSS_TALK          = 1 << 3,
		STATE_LOCKED       = 1 << 4,
		ROTATING_LEFT      = 1 << 5,
		ROTATING_RIGHT     = 1 << 6,
		
		
		
		UNK_10             = 1 << 10,
		UNK_11             = 1 << 11,
		ARROWS_ALLOWED     = 1 << 12,
		
		TALK               = 1 << 14,
		ZOOM_OUT_FROM_TALK = 1 << 15,
		
		
		
		ZOOMED_IN          = 1 << 19
	};
	
	struct State // Executes view specific camera behaviour
	{
		bool (Camera::* OnUpdate)();            // Nested call by Camera::Behaviour()
		bool (Camera::* OnPlayerChangeState)(); // Nested call by Player::ChangeState()
	};
	
	Vector3 lookAt;
	Vector3 pos;            // 0x8c
	Vector3 ownerPos;       // 0x98
	Vector3 unk0a4;
	Vector3 savedLookAt;    // Saved to at talk
	Vector3 savedPos;       // Saved to at talk
	Vector3 unk0c8;         // Player's front lookAt?
	Vector3 unk0d4;         // Player's front pos?
	Vector3 unk0e0;         // Raycast result save (when the player becomes invisible to the camera)
	Vector3 unk0ec;         // Raycast result save (when the player becomes invisible to the camera)
	Fix12i aspectRatio;     // Aspect ratio, default = 1.33 (4:3)
	u32 unk0fc;        // Clipper related (near+far)
	u32 unk100;        // Clipper related
	u32 unk104;        // Clipper related
	u32 unk108;        // Clipper related
	u8 viewportLeft;   // Viewport x for left border
	u8 viewportBottom; // Viewport y for bottom border
	u8 viewportRight;  // Viewport x for right border
	u8 viewportTop;    // Viewport y for top border
	Actor* owner;           // The player stalked by the camera
	Actor* unk114;          // Set at special camera scene? Set to King Bomb-Omb for example
	Actor* unk118;          // Another unknown actor
	Vector3* unk11c;        // Related to unk118, set to 0xDFE60 at 0x02009F3C
	Vector3 unk120;         // unk118's or (if unk118 == 0) unk114's position vector
	Fix12i unk12c;          // Distance to unk114?
	Fix12i unk130;          // Linear camera movement interpolator (only for unk114?) that (when entering a different camera view like at the top of BoB) interpolates from 0x0 to 0x100 and backwards when leaving. As a result, it also indicates whether the owner is in a special camera scene. unk114 is linked later during interpolation.
	Fix12i unk134;          // Ground pound camera jitter offset. Starts at 0xC000 and vibrates back and forth with alternating signs until it reaches 0.
	State* currState;       // Pointer to the current setting behaviour, which in turn sets the CameraDef's
	CameraDef* defaultCamDef;
	CameraDef* currCamDef;
	LVL_Overlay::ViewObj* currView;
	Vector3* pausePos;
	u32 unk14c;
	u32 unk150;
	u32 flags;
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;
	u32 unk168;
	u32 unk16c;
	u32 unk170;
	u32 unk174;
	u16 unk178;
	s16 fov;
	s16 angY; // ?
	s16 unk17e;
	s16 eightDirAngleY;
	s16 eightDirStartAngle;
	s16 eightDirDeltaAngle;
	s16 unk186;
	u32 unk188;
	u32 unk18c;
	u32 unk190;
	u16 unk194;
	u16 unk196;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u16 unk1a4;
	u8 unk1a6;
	u8 unk1a7;
	
	Camera();
	virtual ~Camera() override;
	virtual s32  InitResources() override;
	virtual s32  CleanupResources() override;
	virtual s32  Behavior() override;
	virtual s32  Render() override;
	virtual void OnPendingDestroy() override;
	
	void SaveCameraStateBeforeTalk();				//Saves the current camera state
	void SetFlag_3();
	void SetLookAt(const Vector3& lookAt);
	void SetPos(const Vector3& pos);
	bool IsUnderwater() const;
	s32 ChangeState(State* newState);
	void LookAtExit(Actor& exit);
	void GoBehindPlayer(u32 playerID);
	
	//Func_0200D954
	//Func_0200D8C8
	//All funcs between Camera() and ~Camera() should belong to this object, but I couldn't prove it since they're never really called.
};

extern "C"
{
	extern Clipper GLOBAL_CLIPPER;
}