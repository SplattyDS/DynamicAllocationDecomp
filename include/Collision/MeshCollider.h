#pragma once

struct MeshColliderBase // vtable at 0x02099388
{
	Actor* actor;
	u32 actorUniqueID;
	Fix12i range;
	Fix12i rangeOffsetY;
	u32 clsnID;
	void (*beforeClsnCallback) // called if there was a collision the previous frame.
	(
		MeshColliderBase& clsn,
		Actor*            clsnActor, // the mesh collider's actor for some reason
		ClsnResult&       wmClsnResult,
		Vector3&          posToUpdate,
		Vector3_16*       motionAngToUpdate,
		Vector3_16*       angToUpdate
	);
	void (*afterClsnCallback)
	(
		MeshColliderBase& clsn,
		Actor&            clsnActor,
		Actor&            otherActor
	);
	
	MeshColliderBase();
	virtual ~MeshColliderBase();
	virtual void Virtual08(); // all known implementations are bx lr
	virtual void GetSurfaceInfo(s16 triangleID, SurfaceInfo& res) = 0;
	virtual void GetNormal(s16 triangleID, Vector3& res) = 0;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) = 0;
	virtual bool DetectClsn(RaycastGround& ray);
	virtual bool DetectClsn(RaycastLine& ray);
	virtual bool DetectClsn(SphereClsn& sphere);
	virtual void BeforeClsn(ClsnResult& wmClsnResult, Actor* clsnActor, Vector3& posToUpdate, Vector3_16* motionAngToUpdate, Vector3_16* angToUpdate);
	virtual bool TransformPos(const Vector3& pos, Vector3& res); // returns true if vector was transformed
	virtual u16 GetAngularVelY();
	virtual void GetVelocity(Vector3& res);
	
	bool Disable();
	bool Enable(Actor* actor);
	bool IsEnabled();
	
	// beforeClsnCallback functions
	
	static void UpdatePosWithVelocity(MeshColliderBase& clsn, Actor* clsnActor, ClsnResult& wmClsnResult, Vector3& posToUpdate, Vector3_16* motionAngToUpdate, Vector3_16* angToUpdate);
	
	static void UpdatePosAndAngs(MeshColliderBase& clsn, Actor* clsnActor, ClsnResult& wmClsnResult, Vector3& posToUpdate, Vector3_16* motionAngToUpdate, Vector3_16* angToUpdate); // calls UpdatePosWithTransform and UpdateAngsWithAngularVelY
	
	static void UpdatePosWithTransform(MeshColliderBase& clsn, Actor* clsnActor, ClsnResult& wmClsnResult, Vector3& posToUpdate, Vector3_16* motionAngToUpdate, Vector3_16* angToUpdate);
	
	static void UpdateAngsWithAngularVelY(MeshColliderBase& clsn, Actor* clsnActor, ClsnResult& wmClsnResult, Vector3& posToUpdate, Vector3_16* motionAngToUpdate, Vector3_16* angToUpdate);
	
	[[gnu::always_inline]]
	inline void EnableIfDisabled(Actor* actor)
	{
		if (!IsEnabled())
			Enable(actor);
	}
	
	[[gnu::always_inline]]
	inline void DisableIfEnabled()
	{
		if (IsEnabled())
			Disable();
	}
	
	[[gnu::always_inline]]
	auto GetNormal(const s16& triangleID)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->GetNormal(triangleID, res);
		});
	}
	
	[[gnu::always_inline]]
	auto GetTriangleOrigin(const s16& triangleID)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->GetTriangleOrigin(triangleID, res);
		});
	}
	
	[[gnu::always_inline]]
	auto TransformPos(const Vector3& pos)
	{
		return Vector3::Proxy([&]<bool resMayAlias>[[gnu::always_inline]](Vector3& res)
		{
			this->TransformPos(pos, res);
		});
	}
};

struct MeshCollider : MeshColliderBase
{
	KCL_File* clsnFile;
	CLPS_Block* clpsBlock;
	u32 unk28;
	u32 unk2c;
	u32 unk30;
	u8 unk34;
	u8 unk35;
	u16 unk36;
	Vector3 unkVec38;
	Fix12i unk44;
	u32 unk48;
	u32 unk4c;
	
	MeshCollider();
	virtual ~MeshCollider() override;
	virtual void Virtual08() override;
	virtual void GetSurfaceInfo(s16 triangleID, SurfaceInfo& res) override;
	virtual void GetNormal(s16 triangleID, Vector3& res) override;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) override;
	virtual bool DetectClsn(RaycastGround& ray) override;
	virtual bool DetectClsn(RaycastLine&   ray) override;
	virtual bool DetectClsn(SphereClsn& sphere) override;
	
	void SetFile(KCL_File* clsnFile, CLPS_Block& clps);
	Fix12i GetOctreeOriginY() const;
	Fix12i GetUnkOctreeY() const;
	
	static KCL_File* LoadFile(SharedFilePtr& filePtr);
	static void UpdateFileOffsets(KCL_File& file);
	
	[[gnu::always_inline]]
	static inline KCL_File* LoadFile(GloballySharedFilePtr& filePtr) { return LoadFile(filePtr.Get()); }
};

struct MovingMeshCollider : public MeshCollider
{
	u32 unk50;                  // 0x50
	Matrix4x3 newTransform;     // 0x54
	Matrix4x3 invMat4x3_084;    // 0x84
	Matrix4x3 scMat4x3_0b4;     // 0xb4
	Matrix4x3 invMat4x3_0e4;    // 0xe4
	s16 angleY;					// 0xe8
	s16 angularVelY;			// 0xea
	Vector3 pos;				// 0x118
	Vector3 velocity;			// 0x124
	u32 unk130;                 // 0x130
	Matrix4x3 ledgeMat;         // 0x134
	u32 unk164;                 // 0x164
	Matrix4x3 clsnInvMat;       // 0x168
	Matrix4x3 sc2InvMat4x3_198; // 0x198
	
	MovingMeshCollider();
	virtual ~MovingMeshCollider() override;
	virtual void Virtual08() override;
	virtual void GetNormal(s16 triangleID, Vector3& res) override;
	virtual void GetTriangleOrigin(s16 triangleID, Vector3& res) override;
	virtual bool DetectClsn(RaycastGround& ray) override;
	virtual bool DetectClsn(RaycastLine&   ray) override;
	virtual bool DetectClsn(SphereClsn& sphere) override;
	virtual bool TransformPos(const Vector3& pos, Vector3& res) override;
	virtual u16 GetAngularVelY() override;
	virtual void GetVelocity(Vector3& res) override;
	
	void SetFile(KCL_File* clsnFile, const Matrix4x3& mat, Fix12i scale, s16 angleY, CLPS_Block& clps);
	void Transform(const Matrix4x3& mat, s16 rotY);
};

extern MeshColliderBase* ACTIVE_MESH_COLLIDERS[0x18];

static_assert(sizeof(MeshColliderBase) == 0x20);
static_assert(sizeof(MeshCollider) == 0x50);
static_assert(sizeof(MovingMeshCollider) == 0x1c8);