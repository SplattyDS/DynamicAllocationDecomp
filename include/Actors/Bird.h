#pragma once

struct Bird : Actor
{
	ModelAnim modelAnim;  // 0xd4
	ShadowModel shadow;   // 0x138
	Vector3 destination;  // 0x160
	Vector3_16 targetAng; // 0x16c
	u16 unk172;           // 0x172 (unused)
	Fix12i speedMult;     // 0x174
	u32 leaderID;         // 0x178 (unique id of the bird that spawned the bird)
	u32 state;            // 0x17c
	bool isLeader;        // 0x180
	u8 unk181;            // 0x181 (unused)
	u16 unk182;           // 0x182 (unused)
	
	static SpawnInfo spawnData;
	static SharedFilePtr modelFile;
	static SharedFilePtr animFile;
	
	Bird();
	virtual s32 InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~Bird() override;
	
	void SetLeader(u32 newLeaderID);
	void State0_Main();
	void State1_Main();
	void State2_Main();
	void State3_Main();
};