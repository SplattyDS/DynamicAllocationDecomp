#pragma once

struct MetalNetLift : Platform
{
	enum States
	{
		ST_WAIT,
		ST_MOVE_FORWARDS,
		ST_MOVE_BACKWARDS,
	};
	
	Fix12i sinkHeight;   // 0x320
	Fix12i wobbleHeight; // 0x324
	s16 wobbleAng;       // 0x328
	Vector3 originalPos; // 0x32c
	u16 stateTimer;      // 0x338
	bool hadClsn;        // 0x33a
	u8 state;            // 0x33b
	u8 startState;       // 0x33c
	u32 numNodes;        // 0x340
	u32 nextNode;        // 0x344
	Vector3 prevNodePos; // 0x348
	Vector3 nextNodePos; // 0x354
	PathPtr pathPtr;     // 0x360
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr clsnFile;
	
	MetalNetLift();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual ~MetalNetLift() override;
	
	void State0_Wait();
	void State1_MoveForwards();
	void State2_MoveBackwards();
	
	s32 Move(); // 0: moving to next node, 1: next node reached, -1: final node reached
	void UpdateMotionAng(const Vector3& start, const Vector3& dest);
	void AfterClsn(Actor& otherActor);
	
	static void AfterClsnCallback(MeshColliderBase& clsn, Actor& clsnActor, Actor& otherActor);
};