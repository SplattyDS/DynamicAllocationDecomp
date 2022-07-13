#ifndef EXPLOSION_GOOMBA_INCLUDED
#define EXPLOSION_GOOMBA_INCLUDED

#include "../SM64DS_2.h"
#include "../GloballySharedFilePtr.h"
#include "../E_Goomba/Goomba.h"

// originally used the same struct as Goomboss, it had ExplosionGoomba behavior when param1 was equal to 0x1111...
struct ExplosionGoomba : public Enemy
{
	ModelAnim modelAnim;	// 0x110
	ShadowModel shadow;		// 0x174
	Matrix4x3 shadowMat;	// 0x19c
	MaterialChanger matChg;	// 0x1cc
	WithMeshClsn wmClsn;	// 0x1e0
	u16 stateTimer;			// 0x39c
	u8 state;				// 0x39e
	bool shouldBehave;		// 0x39f
	bool shouldRender;		// 0x3a0
	
	static GloballySharedFilePtr modelFile;
	static GloballySharedFilePtr animFile;
	
	static SpawnInfo spawnData;					// forgot the address oops
	
	virtual s32 InitResources() override;		// 0x02122634
	virtual s32 CleanupResources() override;	// 0x0212229c
	virtual s32 Behavior() override;			// 0x021223bc
	virtual s32 Render() override;				// 0x021222e0
};

#endif