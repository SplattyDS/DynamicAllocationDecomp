#include "SM64DS_2.h"
#include "Actors/BowserSkyPlatform.h"

extern "C"
{
	ActorBase* FUN_02118408(); // constructor
	
	// state function declarations for use below
	void FUN_021181b4(BowserSkyPlatform* bowserSkyPlatform);
	void FUN_021180e0(BowserSkyPlatform* bowserSkyPlatform);
	void FUN_02117db8(BowserSkyPlatform* bowserSkyPlatform);
	
	// undocumented globals not in ov60:
	// 0x02039348
	// 0x0208e738
	
	SharedFilePtr* MODEL_FILE_PTRS[10]  = // 0x02119514
	{
		&BowserSkyPlatform::modelFiles[0],
		&BowserSkyPlatform::modelFiles[1],
		&BowserSkyPlatform::modelFiles[2],
		&BowserSkyPlatform::modelFiles[3],
		&BowserSkyPlatform::modelFiles[4],
		&BowserSkyPlatform::modelFiles[5],
		&BowserSkyPlatform::modelFiles[6],
		&BowserSkyPlatform::modelFiles[7],
		&BowserSkyPlatform::modelFiles[8],
		&BowserSkyPlatform::modelFiles[9],
	};
	
	SharedFilePtr* CLSN_FILE_PTRS[10] = // 0x0211953c
	{
		&BowserSkyPlatform::clsnFiles[0],
		&BowserSkyPlatform::clsnFiles[1],
		&BowserSkyPlatform::clsnFiles[2],
		&BowserSkyPlatform::clsnFiles[3],
		&BowserSkyPlatform::clsnFiles[4],
		&BowserSkyPlatform::clsnFiles[5],
		&BowserSkyPlatform::clsnFiles[6],
		&BowserSkyPlatform::clsnFiles[7],
		&BowserSkyPlatform::clsnFiles[8],
		&BowserSkyPlatform::clsnFiles[9],
	};
	
	Vector3 UNK_02119564[10] = // 0x02119564
	{
		Vector3{ -0x00000302, -0x000003e8,  0x0000ae00 },
		Vector3{ -0x00000483,  0x00000181,  0x0000b800 },
		Vector3{ -0x00000483,  0x00000181,  0x0000e200 },
		Vector3{  0x00000000,  0x000004d0,  0x0000e800 },
		Vector3{  0x00000000,  0x000004d0,  0x00001800 },
		Vector3{  0x00000483,  0x00000181,  0x00001e00 },
		Vector3{  0x00000483,  0x00000181,  0x00004800 },
		Vector3{  0x00000302, -0x000003e8,  0x00005200 },
		Vector3{  0x00000302, -0x000003e8,  0x00008400 },
		Vector3{ -0x00000302, -0x000003e8,  0x00007c00 },
	};
	
	OldFixedSizeSPLC_Block<2> splcBlock1 =	// 0x021115bc
	{
		{'C', 'L', 'P', 'S'},
		0x0008,
		0x0001,
		{
			// low: 0x00000fc0, high: 0x000000ff
			// low: 0x00038fc4, high: 0x000000ff
			OldSPLC{ 0x00000fc0, 0x000000ff },
			OldSPLC{ 0x00038fc4, 0x000000ff },
        }
	};
	
	OldFixedSizeSPLC_Block<2> splcBlock2 =	// 0x021115bc
	{
		{'C', 'L', 'P', 'S'},
		0x0008,
		0x0001,
		{
			// low: 0x00038fc4, high: 0x000000ff
			// low: 0x00000fc0, high: 0x000000ff
			OldSPLC{ 0x00000fc0, 0x000000ff },
			OldSPLC{ 0x00038fc4, 0x000000ff },
        }
	};
	
	SPLC_Block* splcBlocks[10] = // 0x0211a980
	{
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock2,
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock2,
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock2,
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock1,
		(SPLC_Block*)&splcBlock2,
	};
	
	/*using splcBlock1 = StaticSPLC_Block<
		{  },
		{ .textureID = SPLC::TX_ROCK, .camBehavID = SPLC::CA_GO_BEHIND_7, }
	>;
	
	using splcBlock2 = StaticSPLC_Block<
		{ .textureID = SPLC::TX_ROCK, .camBehavID = SPLC::CA_GO_BEHIND_7, }, 
		{  } 
	>;*/
	
	using StateFunc = void(*)(BowserSkyPlatform*);
	
	struct State
	{
		StateFunc func;
		u32 unk04 = 0;
	};
	
	State states[3] = // 0x0211b1ac
	{
		{ &FUN_021181b4 },
		{ &FUN_021180e0 },
		{ &FUN_02117db8 },
	};
}

SharedFilePtr BowserSkyPlatform::modelFiles[10];
SharedFilePtr BowserSkyPlatform::clsnFiles[10];

SpawnInfo BowserSkyPlatform::spawnData = 
{
	&FUN_02118408,
	0x00a7,
	0x0092,
	0,
	400._f,
	400._f,
	4096._f,
	6400._f,
};

asm(R"(
@ 0x0211a9b0
VTable_BowserSkyPlatform:
	.word FUN_021182b0
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_021181e8
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02118254
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_0211822c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02117d1c
	.word FUN_02117d60
	.word _ZN5Actor13OnYoshiTryEatEv
	.word _ZN5Actor13OnTurnIntoEggER6Player
	.word _ZN5Actor9Virtual50Ev
	.word _ZN5Actor15OnGroundPoundedERS_
	.word _ZN5Actor11OnAttacked1ERS_
	.word _ZN5Actor11OnAttacked2ERS_
	.word _ZN5Actor8OnKickedERS_
	.word _ZN5Actor8OnPushedERS_
	.word _ZN5Actor24OnHitByCannonBlastedCharERS_
	.word _ZN5Actor15OnHitByMegaCharER6Player
	.word _ZN5Actor19OnHitFromUnderneathERS_
	.word _ZN5Actor16OnAimedAtWithEggEv
	.word _ZN5Actor25OnAimedAtWithEggReturnVecEv
	.word _ZN8Platform4KillEv
.ltorg)");

asm(R"(
FUN_02117d1c:
	push    { r4, r14 }
	ldr     r2, =VTable_BowserSkyPlatform
	mov     r4, r0
	ldr     r1, =_ZTV8Platform
	str     r2, [r4]
	add     r0, r4, #0x124
	str     r1, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN5ModelD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117d60:
	push    { r4, r14 }
	ldr     r2, =VTable_BowserSkyPlatform
	mov     r4, r0
	ldr     r1, =_ZTV8Platform
	str     r2, [r4]
	add     r0, r4, #0x124
	str     r1, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN5ModelD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	ldr     r1, =_ZN6Memory11gameHeapPtrE
	mov     r0, r4
	ldr     r1, [r1]
	bl      _ZN6Memory10DeallocateEPvP4Heap
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117db8:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x48
	mov     r8, r0
	add     r0, r8, #0x300
	ldrh    r0, [r0, #0x26]
	cmp     r0, #0x0
	beq     LAB_02117ddc
	cmp     r0, #0x16
	bne     LAB_02117ebc
LAB_02117ddc:
	ldr     r0, [r8, #0x74]
	mov     r2, #0x0c
	str     r0, [r13]
	ldr     r0, [r8, #0x78]
	ldr     r6, =UNK_02119564 + 8
	str     r0, [r13, #0x4]
	ldr     r0, [r8, #0x7c]
	mov     r1, #0x12c000
	str     r0, [r13, #0x8]
	ldr     r0, [r8, #0x5c]
	ldr     r7, =SINE_TABLE
	str     r0, [r13, #0x0c]
	ldr     r0, [r8, #0x60]
	ldr     r4, =UNK_02119564 + 0
	str     r0, [r13, #0x10]
	ldr     r0, [r8, #0x64]
	ldr     r3, =#0x366
	str     r0, [r13, #0x14]
	ldrb    r12, [r8, #0x329]
	ldr     r5, =UNK_02119564 + 4
	add     r0, r13, #0x0c
	mul     r14, r12, r2
	ldrh    r12, [r6, r14]
	str     r1, [r13, #0x10]
	ldr     r6, [r4, r14]
	mov     r1, r12, asr #0x4
	mov     r12, r1, lsl #0x1
	mov     r1, r12, lsl #0x1
	ldrsh   r4, [r7, r1]
	add     r1, r12, #0x1
	mov     r1, r1, lsl #0x1
	smulbb  r4, r4, r3
	add     r4, r4, r6, lsl #0x0c
	str     r4, [r13, #0x0c]
	ldrsh   r4, [r7, r1]
	ldrb    r6, [r8, #0x329]
	mov     r1, #0x3
	mul     r7, r6, r2
	smulbb  r2, r4, r3
	ldr     r3, [r5, r7]
	add     r2, r2, r3, lsl #0x0c
	str     r2, [r13, #0x14]
	bl      Vec3_AsrInPlace
	ldr     r1, =VIEW_MATRIX_ASR_3
	add     r0, r13, #0x0c
	add     r2, r8, #0x74
	bl      MulVec3Mat4x3
	add     r1, r8, #0x74
	mov     r0, #0x0bc
	bl      0x02012694
	ldr     r0, [r13]
	str     r0, [r8, #0x74]
	ldr     r0, [r13, #0x4]
	str     r0, [r8, #0x78]
	ldr     r0, [r13, #0x8]
	str     r0, [r8, #0x7c]
LAB_02117ebc:
	add     r0, r8, #0x300
	ldrh    r0, [r0, #0x26]
	cmp     r0, #0x16
	movcs   r0, #0x4000
	rsbcs   r0, r0, #0x0
	strcs   r0, [r8, #0x9c]
	bcs     LAB_02117f10
	ldr     r0, [r8, #0x5c]
	add     r1, r13, #0x24
	str     r0, [r13, #0x24]
	ldr     r2, [r8, #0x60]
	mov     r0, r8
	str     r2, [r13, #0x28]
	ldr     r3, [r8, #0x64]
	mov     r2, #0x7d0000
	str     r3, [r13, #0x2c]
	bl      _ZN5Actor10EarthquakeERK7Vector35Fix12IiE
	mov     r0, #0x8000
	str     r0, [r8, #0x0a8]
	mov     r0, #0x0
	str     r0, [r8, #0x9c]
LAB_02117f10:
	add     r0, r8, #0x300
	ldrh    r5, [r0, #0x26]
	mov     r1, r5, lsr #0x1f
	rsb     r0, r1, r5, lsl #0x1f
	adds    r0, r1, r0, ror #0x1f
	bne     LAB_02118044
	cmp     r5, #0x0e
	bcs     LAB_02118044
	ldrb    r1, [r8, #0x329]
	ldr     r2, =#0x133000
	mov     r0, #0x0c
	mul     r4, r1, r0
	ldr     r0, =UNK_02119564 + 8
	ldr     r3, =#0x14b0
	ldrsh   r6, [r0, r4]
	mov     r0, r5, asr #0x1
	rsb     r0, r0, #0x6
	add     r3, r6, r3
	mov     r3, r3, lsl #0x10
	mov     r3, r3, asr #0x10
	mov     r3, r3, lsl #0x10
	mov     r3, r3, lsr #0x10
	mov     r3, r3, asr #0x4
	mov     r14, r3, lsl #0x1
	ldr     r3, =#0x122
	add     r5, r14, #0x1
	mul     r7, r0, r3
	ldr     r12, =SINE_TABLE
	mov     r14, r14, lsl #0x1
	mov     r3, r5, lsl #0x1
	ldrsh   r14, [r12, r14]
	ldrsh   r12, [r12, r3]
	ldr     r1, =UNK_02119564 + 0
	ldr     r0, =UNK_02119564 + 4
	ldr     r5, [r1, r4]
	mul     r1, r7, r14
	add     r3, r1, r5, lsl #0x0c
	ldr     r4, [r0, r4]
	mul     r12, r7, r12
	add     r12, r12, r4, lsl #0x0c
	add     r1, r13, #0x30
	mov     r0, r8
	str     r3, [r13, #0x18]
	str     r2, [r13, #0x1c]
	str     r12, [r13, #0x20]
	str     r3, [r13, #0x30]
	str     r2, [r13, #0x34]
	str     r12, [r13, #0x38]
	bl      _ZN5Actor10PoofDustAtERK7Vector3
	ldr     r2, =#0x133000
	ldr     r0, =#0x0ffffeb50
	ldr     r1, =SINE_TABLE
	add     r0, r6, r0
	mov     r0, r0, lsl #0x10
	mov     r0, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r3, r0, lsl #0x1
	add     r0, r3, #0x1
	mov     r3, r3, lsl #0x1
	mov     r0, r0, lsl #0x1
	ldrsh   r3, [r1, r3]
	ldrsh   r0, [r1, r0]
	add     r1, r13, #0x3c
	mul     r3, r7, r3
	add     r5, r3, r5, lsl #0x0c
	mul     r0, r7, r0
	add     r3, r0, r4, lsl #0x0c
	mov     r0, r8
	str     r5, [r13, #0x18]
	str     r2, [r13, #0x1c]
	str     r3, [r13, #0x20]
	str     r5, [r13, #0x3c]
	str     r2, [r13, #0x40]
	str     r3, [r13, #0x44]
	bl      _ZN5Actor10PoofDustAtERK7Vector3
LAB_02118044:
	add     r2, r8, #0x0a8
	ldr     r1, [r2]
	ldr     r0, [r8, #0x9c]
	add     r3, r8, #0x60
	add     r0, r1, r0
	str     r0, [r2]
	ldr     r1, [r8, #0x0a0]
	ldr     r0, [r8, #0x0a8]
	cmp     r0, r1
	strle   r1, [r8, #0x0a8]
	ldr     r2, [r3]
	ldr     r1, [r8, #0x0a8]
	add     r0, r8, #0x300
	add     r1, r2, r1
	str     r1, [r3]
	ldrh    r0, [r0, #0x26]
	cmp     r0, #0x12c
	bls     LAB_02118094
	mov     r0, r8
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02118094:
	ldr     r0, =#0x326
	add     r1, r8, r0
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	add     r13, r13, #0x48
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021180e0:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x320]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	bne     LAB_02118108
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	pop     { r4, r14 }
	bx      r14
LAB_02118108:
	ldrb    r1, [r4, #0x32b]
	cmp     r1, #0x0
	beq     LAB_02118130
	ldr     r1, [r0, #0x40c]
	cmp     r1, #0x0d
	bne     LAB_02118130
	ldr     r1, [r0, #0x418]
	ands    r1, r1, #0x10000
	movne   r1, #0x2
	strneb  r1, [r4, #0x328]
LAB_02118130:
	add     r1, r0, #0x400
	ldrsb   r1, [r1, #0x1e]
	cmp     r1, #0x1
	bne     LAB_02118160
	ldr     r1, [r0, #0x40c]
	cmp     r1, #0x3
	beq     LAB_02118158
	ldr     r0, [r0, #0x410]
	cmp     r0, #0x0
	beq     LAB_02118160
LAB_02118158:
	mov     r0, #0x1
	strb    r0, [r4, #0x32a]
LAB_02118160:
	ldrb    r0, [r4, #0x32a]
	cmp     r0, #0x0
	addeq   r0, r4, #0x300
	moveq   r1, #0x0
	streqh  r1, [r0, #0x24]
	popeq   { r4, r14 }
	bxeq    r14
	ldrb    r2, [r4, #0x329]
	mov     r0, #0x14
	add     r1, r4, #0x300
	mul     r3, r2, r0
	ldrh    r0, [r1, #0x24]
	add     r1, r4, #0x324
	cmp     r3, r0
	movlt   r0, #0x2
	strltb  r0, [r4, #0x328]
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021181b4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, =#0x117
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	cmp     r0, #0x0
	ldrne   r1, [r0, #0x4]
	movne   r0, #0x1
	strne   r1, [r4, #0x320]
	strneb  r0, [r4, #0x328]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021181e8:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x124
	bl      _ZN16MeshColliderBase7DisableEv
	ldrb    r1, [r4, #0x329]
	ldr     r0, =MODEL_FILE_PTRS
	ldr     r0, [r0, r1, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldrb    r1, [r4, #0x329]
	ldr     r0, =CLSN_FILE_PTRS
	ldr     r0, [r0, r1, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211822c:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r2, [r0, #0x0d4]!
	mov     r1, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118254:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r0, [r4, #0x328]
	ldr     r1, =states
	add     r3, r1, r0, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	mov     r0, r4
	bl      _ZN8Platform21UpdateModelPosAndRotYEv
	mov     r0, r4
	bl      _ZN8Platform19UpdateClsnPosAndRotEv
	mov     r0, #0x0
	strb    r0, [r4, #0x32b]
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021182b0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	ldr     r1, [r4, #0x8]
	ldr     r0, =#0x208e738
	and     r1, r1, #0x0f
	strb    r1, [r4, #0x329]
	mov     r1, #0x0
	str     r1, [r0]
	ldrb    r1, [r4, #0x329]
	ldr     r0, =MODEL_FILE_PTRS
	ldr     r0, [r0, r1, lsl #0x2]
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	add     r0, r4, #0x0dc
	bl      0x0202b3d8
	mov     r2, #0x1
	ldr     r1, =#0x208e738
	mov     r0, r4
	str     r2, [r1]
	bl      _ZN8Platform19UpdateClsnPosAndRotEv
	ldrb    r5, [r4, #0x329]
	ldr     r0, =CLSN_FILE_PTRS
	ldr     r0, [r0, r5, lsl #0x2]
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	mov     r1, r0
	ldrsh   r3, [r4, #0x8e]
	ldr     r2, =splcBlocks
	add     r0, r4, #0x124
	str     r3, [r13]
	ldr     r3, [r2, r5, lsl #0x2]
	add     r2, r4, #0x2ec
	str     r3, [r13, #0x4]
	mov     r3, #0x1000
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10SPLC_Block
	add     r0, r4, #0x124
	ldr     r1, =#0x2039348
	bl      0x020393d4
	add     r0, r4, #0x124
	ldr     r1, =FUN_021183f4
	bl      0x020393c4
	add     r0, r4, #0x124
	mov     r1, r4
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	mov     r3, #0x0
	str     r3, [r4, #0x320]
	strb    r3, [r4, #0x32b]
	strb    r3, [r4, #0x328]
	strb    r3, [r4, #0x32a]
	add     r0, r4, #0x300
	strh    r3, [r0, #0x26]
	ldrh    r2, [r0, #0x26]
	mov     r1, #0x1e000
	rsb     r1, r1, #0x0
	strh    r2, [r0, #0x24]
	str     r3, [r4, #0x9c]
	str     r1, [r4, #0x0a0]
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021183cc:
	ldrh    r2, [r1, #0x0c]
	ldr     r1, =#0x117
	cmp     r2, r1
	moveq   r1, #0x1
	movne   r1, #0x0
	cmp     r1, #0x0
	movne   r1, #0x1
	strneb  r1, [r0, #0x32b]
	bx      r14
.ltorg)");

asm(R"(
FUN_021183f4:
	ldr     r12, =FUN_021183cc
	mov     r0, r1
	mov     r1, r2
	bx      r12
.ltorg)");

asm(R"(
FUN_02118408:
	push    { r4, r14 }
	mov     r0, #0x32c
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02118428
	bl      _ZN8PlatformC2Ev
	ldr     r0, =VTable_BowserSkyPlatform
	str     r0, [r4]
LAB_02118428:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");