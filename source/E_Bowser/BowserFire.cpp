#include "SM64DS_2.h"
#include "Actors/BowserFire.h"

extern "C"
{
	ActorBase* FUN_02117938(); // constructor
	
	// state function declarations for use below
	void FUN_021167c8(BowserFire* bowserFire);
	void FUN_02116b18(BowserFire* bowserFire);
	void FUN_02116c68(BowserFire* bowserFire);
	void FUN_021167c8(BowserFire* bowserFire);
	void FUN_021169b0(BowserFire* bowserFire);
	void FUN_02116f74(BowserFire* bowserFire);
	void FUN_0211722c(BowserFire* bowserFire);
	void FUN_021171e8(BowserFire* bowserFire);
	void FUN_0211747c(BowserFire* bowserFire);
	void FUN_021169f8(BowserFire* bowserFire);
	void FUN_02116b68(BowserFire* bowserFire);
	void FUN_021167ec(BowserFire* bowserFire);
	void FUN_021168c4(BowserFire* bowserFire);
	void FUN_02116d78(BowserFire* bowserFire);
	void FUN_02116f90(BowserFire* bowserFire);
	void FUN_02116f90(BowserFire* bowserFire);
	
	Fix12i TERMINAL_VELOCITY[3] = { -8._f, -6._f, -6._f }; // 0x0211934c
	u32 PARTICLE_IDS[3] = { Particle::PTL_FIRE_4, Particle::PTL_FIRE_NEGATIVE, Particle::PTL_FIRE_NEGATIVE }; // 0x02119358
	u16 UNK_02119364[43][5] = // 0x02119364 (info for the spawned flames?)
	{
		{ 0x0000, 0x00e5, 0x008b, 0xffff, 0x0803 },
		{ 0x0000, 0x00e0, 0x0090, 0xffff, 0x08c0 },
		{ 0x0000, 0x00de, 0x0093, 0xffff, 0x0928 },
		{ 0x0000, 0x00dd, 0x0094, 0xffff, 0x099d },
		{ 0x0000, 0x00dd, 0x0095, 0xffff, 0x0a16 },
		{ 0x0000, 0x00dd, 0x0096, 0xffff, 0x0a8d },
		{ 0x0000, 0x00dd, 0x0096, 0xffff, 0x0af6 },
		{ 0x0000, 0x00de, 0x0096, 0xffff, 0x0b4a },
		{ 0x0000, 0x00de, 0x0096, 0xffff, 0x0b84 },
		{ 0x0000, 0x00de, 0x0095, 0x020a, 0x0ba0 },
		{ 0x0000, 0x00df, 0x0095, 0x0524, 0x0b9e },
		{ 0x0000, 0x00e1, 0x0094, 0x07ec, 0x0b84 },
		{ 0x0000, 0x00e2, 0x0093, 0x0a3f, 0x0b57 },
		{ 0x0000, 0x00e3, 0x0091, 0x0bfb, 0x0b1f },
		{ 0x0000, 0x00e4, 0x0090, 0x0d00, 0x0ae5 },
		{ 0x0000, 0x00e6, 0x008e, 0x0d6f, 0x0aa0 },
		{ 0x0000, 0x00e8, 0x008c, 0x0d8b, 0x0a48 },
		{ 0x0000, 0x00e9, 0x008a, 0x0d5d, 0x09de },
		{ 0x0000, 0x00ec, 0x0088, 0x0ced, 0x096a },
		{ 0x0000, 0x00ee, 0x0086, 0x0c49, 0x08ea },
		{ 0x0000, 0x00ef, 0x0084, 0x0b76, 0x0863 },
		{ 0x0000, 0x00f1, 0x0082, 0x0a80, 0x07d9 },
		{ 0x0000, 0x00f4, 0x0080, 0x0970, 0x074e },
		{ 0x0000, 0x00f6, 0x007d, 0x084e, 0x06c7 },
		{ 0x0000, 0x00f8, 0x007a, 0x0723, 0x0649 },
		{ 0x0000, 0x00fb, 0x0078, 0x05f8, 0x05d7 },
		{ 0x0000, 0x00fd, 0x0075, 0x04d6, 0x0579 },
		{ 0x0000, 0x00fe, 0x0072, 0x03c3, 0x0532 },
		{ 0x0000, 0x0100, 0x006f, 0x02c9, 0x0509 },
		{ 0x0000, 0x0103, 0x006c, 0x01f0, 0x0504 },
		{ 0x0000, 0x0105, 0x0069, 0x0141, 0x0525 },
		{ 0x0000, 0x0106, 0x0067, 0x00c3, 0x0572 },
		{ 0x0000, 0x0108, 0x0064, 0x006e, 0x0619 },
		{ 0x0000, 0x010b, 0x0061, 0x0032, 0x0734 },
		{ 0x0000, 0x010c, 0x005f, 0x000c, 0x08af },
		{ 0x0000, 0x010d, 0x005d, 0xffff, 0x0a74 },
		{ 0x0000, 0x0110, 0x005a, 0xffff, 0x0c70 },
		{ 0x0000, 0x0111, 0x0058, 0xffff, 0x0e8e },
		{ 0x0000, 0x0112, 0x0056, 0x0014, 0x10b6 },
		{ 0x0000, 0x0113, 0x0054, 0x0032, 0x12da },
		{ 0x0000, 0x0114, 0x0052, 0x006e, 0x14b0 },
		{ 0x0000, 0x0116, 0x0050, 0x00c3, 0x1694 },
		{ 0x0000, 0x0118, 0x004e, 0x0111, 0x1870 },
	};
	
	using StateFunc = void(*)(BowserFire*);
	
	struct State
	{
		StateFunc func;
		u32 unk04 = 0;
	};
	
	State states1[8] = // 0x0211af74
	{
		{ &FUN_021167c8 },
		{ &FUN_02116b18 },
		{ &FUN_02116c68 },
		{ &FUN_021167c8 },
		{ &FUN_021169b0 },
		{ &FUN_02116f74 },
		{ &FUN_0211722c },
		{ &FUN_021171e8 },
	};
	
	State states2[8] = // 0x0211afb4
	{
		{ &FUN_0211747c },
		{ &FUN_021169f8 },
		{ &FUN_02116b68 },
		{ &FUN_021167ec },
		{ &FUN_021168c4 },
		{ &FUN_02116d78 },
		{ &FUN_02116f90 },
		{ &FUN_02116f90 },
	};
}

SpawnInfo BowserFire::spawnData = 
{
	&FUN_02117938,
	0x0118,
	0x0090,
	Actor::NO_RENDER_IF_OFF_SCREEN,
	80._f,
	80._f,
	4096._f,
	2048._f,
};

asm(R"(
@ 0x0211a7f4
VTable_BowserFire:
	.word FUN_02117790
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_021176c4
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_021176d4
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_021176cc
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02116484
	.word FUN_021164c4
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
.ltorg)");

asm(R"(
FUN_02116484:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserFire
	add     r0, r4, #0x304
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x2d0
	bl      _ZN18MovingCylinderClsnD1Ev
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsnD1Ev
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021164c4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserFire
	add     r0, r4, #0x304
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x2d0
	bl      _ZN18MovingCylinderClsnD1Ev
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsnD1Ev
	mov     r0, r4
	bl      0x020aed18
	ldr     r1, =_ZN6Memory11gameHeapPtrE
	mov     r0, r4
	ldr     r1, [r1]
	bl      _ZN6Memory10DeallocateEPvP4Heap
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116518:
	push    { r4-r9, r14 }
	sub     r13, r13, #0x0c
	mov     r6, r1
	mov     r7, r0
	mov     r5, r2
	mov     r4, r3
	cmp     r6, #0x0a2
	beq     LAB_02116540
	cmp     r6, #0x0a4
	bne     LAB_02116570
LAB_02116540:
	ldr     r1, [r7, #0x64]
	mov     r0, #0x0
	str     r1, [r13]
	str     r0, [r13, #0x4]
	ldr     r3, [r7, #0x60]
	ldr     r0, [r7, #0x37c]
	ldr     r2, [r7, #0x5c]
	mov     r1, r6
	add     r3, r3, r4
	bl      _ZN8Particle6System17NewUnkCallback818Ejj5Fix12IiES2_S2_PK11Vector3_16f
	str     r0, [r7, #0x37c]
	b       LAB_0211659c
LAB_02116570:
	ldr     r2, [r7, #0x64]
	mov     r0, #0x0
	str     r2, [r13]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	ldr     r3, [r7, #0x60]
	ldr     r0, [r7, #0x37c]
	ldr     r2, [r7, #0x5c]
	add     r3, r3, r4
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r7, #0x37c]
LAB_0211659c:
	ldr     r0, [r7, #0x37c]
	cmp     r0, #0x0
	beq     LAB_02116640
	cmp     r5, #0x0
	beq     LAB_02116640
	bl      0x02022e68
	ldr     r1, [r7, #0x360]
	cmp     r1, #0x8000
	ldrge   r1, =#0x7fff
	strge   r1, [r0, #0x50]
	movlt   r1, r1, lsl #0x10
	movlt   r1, r1, asr #0x10
	strlt   r1, [r0, #0x50]
	cmp     r6, #0x9a
	bne     LAB_02116640
	ldr     r2, [r7, #0x360]
	mov     r1, #0x2800
	mov     r3, #0x0
	umull   r12, r9, r2, r1
	mla     r9, r2, r3, r9
	mov     r8, r2, asr #0x1f
	mov     r2, #0x800
	adds    r12, r12, r2
	mla     r9, r8, r1, r9
	adc     r1, r9, #0x0
	mov     r8, r12, lsr #0x0c
	orr     r8, r8, r1, lsl #0x14
	str     r8, [r0, #0x44]
	ldr     r14, [r7, #0x360]
	ldr     r1, =#0x0a66
	mov     r12, r14, asr #0x1f
	umull   r9, r8, r14, r1
	mla     r8, r14, r3, r8
	mla     r8, r12, r1, r8
	adds    r2, r9, r2
	adc     r1, r8, #0x0
	mov     r2, r2, lsr #0x0c
	orr     r2, r2, r1, lsl #0x14
	mov     r1, r2, lsl #0x10
	mov     r1, r1, asr #0x10
	str     r1, [r0, #0x4c]
LAB_02116640:
	ldr     r1, [r7, #0x64]
	mov     r0, #0x0
	str     r1, [r13]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	ldr     r3, [r7, #0x60]
	ldr     r0, [r7, #0x380]
	ldr     r2, [r7, #0x5c]
	add     r1, r6, #0x1
	add     r3, r3, r4
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r7, #0x380]
	ldr     r0, [r7, #0x380]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r9, r14 }
	bxeq    r14
	cmp     r5, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r9, r14 }
	bxeq    r14
	bl      0x02022e68
	ldr     r1, [r7, #0x360]
	cmp     r1, #0x8000
	ldrge   r1, =#0x7fff
	strge   r1, [r0, #0x50]
	movlt   r1, r1, lsl #0x10
	movlt   r1, r1, asr #0x10
	strlt   r1, [r0, #0x50]
	cmp     r6, #0x9a
	addne   r13, r13, #0x0c
	popne   { r4-r9, r14 }
	bxne    r14
	ldr     r2, [r7, #0x360]
	mov     r1, #0x2800
	mov     r3, #0x0
	umull   r6, r5, r2, r1
	mla     r5, r2, r3, r5
	mov     r4, r2, asr #0x1f
	mov     r2, #0x800
	adds    r6, r6, r2
	mla     r5, r4, r1, r5
	adc     r1, r5, #0x0
	mov     r4, r6, lsr #0x0c
	orr     r4, r4, r1, lsl #0x14
	str     r4, [r0, #0x44]
	ldr     r5, [r7, #0x360]
	ldr     r1, =#0x0a66
	mov     r4, r5, asr #0x1f
	umull   r7, r6, r5, r1
	mla     r6, r5, r3, r6
	adds    r2, r7, r2
	mla     r6, r4, r1, r6
	adc     r1, r6, #0x0
	mov     r2, r2, lsr #0x0c
	orr     r2, r2, r1, lsl #0x14
	mov     r1, r2, lsl #0x10
	mov     r1, r1, asr #0x10
	str     r1, [r0, #0x4c]
	add     r13, r13, #0x0c
	pop     { r4-r9, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116740:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, [r0, #0x2f4]
	cmp     r0, #0x0
	addeq   r13, r13, #0x4
	popeq   { r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r13, r13, #0x4
	popeq   { r14 }
	bxeq    r14
	ldrh    r1, [r0, #0x0c]
	cmp     r1, #0x0bf
	moveq   r1, #0x1
	movne   r1, #0x0
	cmp     r1, #0x0
	addeq   r13, r13, #0x4
	popeq   { r14 }
	bxeq    r14
	ldrb    r1, [r0, #0x6f9]
	cmp     r1, #0x0
	addne   r13, r13, #0x4
	popne   { r14 }
	bxne    r14
	ldrb    r1, [r0, #0x6fb]
	cmp     r1, #0x0
	addne   r13, r13, #0x4
	popne   { r14 }
	bxne    r14
	bl      _ZN6Player4BurnEv
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021167c8:
	add     r3, r0, #0x2e8
	ldr     r2, [r3]
	mov     r1, #0x2000
	orr     r2, r2, #0x1
	str     r2, [r3]
	str     r1, [r0, #0x360]
	mov     r1, #0x10
	str     r1, [r0, #0x368]
	bx      r14
.ltorg)");

asm(R"(
FUN_021167ec:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x0c
	mov     r10, r0
	add     r1, r10, #0x300
	ldrh    r1, [r1, #0x74]
	cmp     r1, #0x0
	addne   r13, r13, #0x0c
	popne   { r4-r11, r14 }
	bxne    r14
	bl      _ZN5Actor13ClosestPlayerEv
	movs    r1, r0
	addeq   r13, r13, #0x0c
	popeq   { r4-r11, r14 }
	bxeq    r14
	add     r0, r10, #0x5c
	add     r1, r1, #0x5c
	bl      Vec3_HorzAngle
	mov     r9, #0x0
	strh    r0, [r10, #0x94]
	mov     r0, #0x5000
	mov     r8, r9
	str     r0, [r10, #0x360]
	str     r9, [r13, #0x8]
	mov     r4, r9
	add     r11, r10, #0x5c
	mvn     r7, #0x0
	mov     r6, #0x118
	mov     r5, #0x4
LAB_0211685c:
	ldrsb   r2, [r10, #0x0cc]
	ldr     r3, [r13, #0x8]
	mov     r0, r6
	str     r2, [r13]
	mov     r1, r5
	mov     r2, r11
	str     r7, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	ldrsh   r1, [r10, #0x94]
	add     r9, r9, #0x1
	cmp     r9, #0x3
	add     r1, r1, r8
	strh    r4, [r0, #0x92]
	strh    r1, [r0, #0x94]
	strh    r4, [r0, #0x96]
	ldr     r2, [r10, #0x360]
	ldr     r1, =#0x5555
	str     r2, [r0, #0x360]
	add     r8, r8, r1
	blt     LAB_0211685c
	mov     r0, r10
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x0c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021168c4:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	add     r0, r5, #0x300
	ldrh    r0, [r0, #0x74]
	cmp     r0, #0x0
	bne     LAB_021168fc
	ldr     r0, =#0x117
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	mov     r4, r0
	ldr     r0, [r4, #0x4]
	str     r0, [r5, #0x2cc]
	b       LAB_02116908
LAB_021168fc:
	ldr     r0, [r5, #0x2cc]
	bl      _ZN5Actor10FindWithIDEj
	mov     r4, r0
LAB_02116908:
	add     r0, r5, #0x110
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	movne   r0, #0x1e000
	strne   r0, [r5, #0x0a8]
	mov     r0, r5
	mov     r1, #0x0
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	mov     r0, r5
	mov     r1, #0x0a6
	mov     r2, #0x0
	mov     r3, #0x32000
	bl      FUN_02116518
	mov     r0, r5
	mov     r1, #0x96
	bl      FUN_021172c8
	cmp     r0, #0x0
	beq     LAB_02116958
	mov     r0, r5
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02116958:
	cmp     r4, #0x0
	addeq   r13, r13, #0x4
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, [r4, #0x410]
	cmp     r0, #0x0
	addne   r13, r13, #0x4
	popne   { r4, r5, r14 }
	bxne    r14
	add     r0, r5, #0x5c
	add     r1, r4, #0x5c
	bl      Vec3_HorzDist
	cmp     r0, #0x96000
	addge   r13, r13, #0x4
	popge   { r4, r5, r14 }
	bxge    r14
	mov     r0, r5
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021169b0:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x1e000
	ldr     r0, =RNG_STATE
	str     r1, [r4, #0x0a8]
	mov     r1, #0x0f000
	str     r1, [r4, #0x98]
	bl      RandomIntInternal
	mov     r2, r0, lsr #0x10
	add     r1, r4, #0x300
	add     r0, r4, #0x110
	strh    r2, [r1, #0x76]
	bl      _ZN12WithMeshClsn13SetLimMovFlagEv
	mov     r0, #0x10
	str     r0, [r4, #0x368]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021169f8:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x0c
	mov     r10, r0
	ldr     r0, [r10, #0x360]
	cmp     r0, #0x5000
	addlt   r1, r10, #0x360
	ldrlt   r0, [r1]
	addlt   r0, r0, #0x200
	strlt   r0, [r1]
	mov     r0, r10
	mov     r1, #0x0
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	mov     r0, r10
	mov     r1, #0x9a
	mov     r2, #0x1
	mov     r3, #0x78000
	bl      FUN_02116518
	add     r0, r10, #0x300
	ldrh    r0, [r0, #0x74]
	cmp     r0, #0x14
	addls   r13, r13, #0x0c
	popls   { r4-r11, r14 }
	bxls    r14
	ldrb    r0, [r10, #0x378]
	cmp     r0, #0x0
	bne     LAB_02116ab0
	mov     r9, #0x0
	add     r5, r10, #0x5c
	add     r11, r10, #0x92
	mvn     r8, #0x0
	mov     r7, #0x118
	mov     r6, #0x2
	mov     r4, #0x5000
LAB_02116a7c:
	ldrsb   r2, [r10, #0x0cc]
	mov     r0, r7
	mov     r1, r6
	str     r2, [r13]
	mov     r2, r5
	mov     r3, r11
	str     r8, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	add     r9, r9, #0x1
	str     r4, [r0, #0x360]
	cmp     r9, #0x3
	blt     LAB_02116a7c
	b       LAB_02116b04
LAB_02116ab0:
	ldrsb   r0, [r10, #0x0cc]
	add     r2, r10, #0x5c
	add     r3, r10, #0x92
	str     r0, [r13]
	mvn     r4, #0x0
	mov     r0, #0x118
	mov     r1, #0x12
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	mov     r1, #0x8000
	str     r1, [r0, #0x360]
	ldrsb   r0, [r10, #0x0cc]
	add     r2, r10, #0x5c
	add     r3, r10, #0x92
	str     r0, [r13]
	mov     r0, #0x118
	mov     r1, #0x22
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	mov     r1, #0x8000
	str     r1, [r0, #0x360]
LAB_02116b04:
	mov     r0, r10
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x0c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116b18:
	push    { r4, r14 }
	mov     r4, r0
	mov     r0, #0x7000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x11800
	str     r0, [r4, #0x98]
	mov     r1, #0x2000
	ldr     r0, =RNG_STATE
	str     r1, [r4, #0x360]
	mov     r1, #0x1000
	str     r1, [r4, #0x9c]
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x10
	add     r0, r4, #0x300
	strh    r1, [r0, #0x76]
	mov     r0, #0x10
	str     r0, [r4, #0x368]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116b68:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldrb    r3, [r4, #0x378]
	ldr     r1, =PARTICLE_IDS
	mov     r2, #0x0
	ldr     r1, [r1, r3, lsl #0x2]
	mov     r3, #0x46000
	bl      FUN_02116518
	mov     r0, r4
	bl      FUN_0211712c
	ldr     r1, =#0x1c2
	mov     r0, r4
	bl      FUN_021172c8
	cmp     r0, #0x0
	beq     LAB_02116bb0
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02116bb0:
	mov     r0, r4
	mov     r1, #0x0
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02116c38
	ldrb    r0, [r4, #0x378]
	cmp     r0, #0x0
	bne     LAB_02116c00
	ldrsb   r0, [r4, #0x0cc]
	add     r2, r4, #0x5c
	mvn     r12, #0x0
	str     r0, [r13]
	mov     r0, #0x118
	mov     r1, #0x7
	mov     r3, #0x0
	str     r12, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	b       LAB_02116c24
LAB_02116c00:
	ldrsb   r0, [r4, #0x0cc]
	add     r2, r4, #0x5c
	mvn     r12, #0x0
	str     r0, [r13]
	mov     r0, #0x118
	mov     r1, #0x3
	mov     r3, #0x0
	str     r12, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
LAB_02116c24:
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
LAB_02116c38:
	ldr     r0, [r4, #0x60]
	cmp     r0, #0x0
	addge   r13, r13, #0x8
	popge   { r4, r14 }
	bxge    r14
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116c68:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x10
	strh    r0, [r4, #0x94]
	ldrb    r0, [r4, #0x378]
	cmp     r0, #0x0
	beq     LAB_02116cc0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	mov     r0, r1, lsl #0x0c
	mov     r0, r0, asr #0x1
	str     r0, [r4, #0x98]
	b       LAB_02116cf4
LAB_02116cc0:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	mov     r0, #0x7000
	mul     r0, r1, r0
	mov     r0, r0, asr #0x1
	str     r0, [r4, #0x98]
LAB_02116cf4:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r3, r0, lsr #0x10
	ldr     r0, =#0x0cccccccd
	ldr     r2, =#0x0a
	umull   r0, r1, r3, r0
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	mov     r2, r1, lsl #0x0c
	mov     r1, #0x1000
	ldr     r0, =RNG_STATE
	str     r2, [r4, #0x0a8]
	rsb     r1, r1, #0x0
	str     r1, [r4, #0x9c]
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x10
	add     r0, r4, #0x300
	strh    r1, [r0, #0x76]
	ldrb    r2, [r4, #0x378]
	ldr     r0, =TERMINAL_VELOCITY
	mov     r1, #0x2000
	ldr     r2, [r0, r2, lsl #0x2]
	mov     r0, #0x10
	str     r2, [r4, #0x0a0]
	str     r1, [r4, #0x360]
	str     r0, [r4, #0x368]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116d78:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, [r4, #0x360]
	add     r12, r4, #0x60
	cmp     r0, #0x5000
	addlt   r2, r4, #0x360
	ldrlt   r1, [r2]
	ldrlt   r0, =#0x255
	add     r14, r4, #0x64
	addlt   r0, r1, r0
	strlt   r0, [r2]
	ldrsh   r0, [r4, #0x92]
	cmp     r0, #0x800
	addgt   r1, r4, #0x92
	ldrgtsh r0, [r1]
	subgt   r0, r0, #0x200
	strgth  r0, [r1]
	ldrh    r0, [r4, #0x92]
	ldrh    r3, [r4, #0x94]
	ldr     r1, =SINE_TABLE
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x2
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x1
	add     r3, r3, #0x1
	ldrsh   r0, [r1, r0]
	ldr     r2, [r4, #0x98]
	mov     r3, r3, lsl #0x1
	mul     r5, r2, r0
	ldrsh   r2, [r1, r3]
	ldr     r3, =#0x92492493
	add     r0, r4, #0x5c
	mul     r5, r2, r5
	smull   r2, r6, r3, r5
	add     r6, r5, r6
	mov     r6, r6, asr #0x9
	mov     r2, r5, lsr #0x1f
	add     r6, r2, r6
	str     r6, [r4, #0x0a4]
	ldrh    r2, [r4, #0x92]
	ldr     r5, [r4, #0x98]
	mov     r2, r2, asr #0x4
	mov     r2, r2, lsl #0x2
	ldrsh   r2, [r1, r2]
	rsb     r5, r5, #0x0
	mul     r2, r5, r2
	str     r2, [r4, #0x0a8]
	ldrh    r2, [r4, #0x92]
	ldrh    r6, [r4, #0x94]
	ldr     r5, [r4, #0x98]
	mov     r2, r2, asr #0x4
	mov     r2, r2, lsl #0x2
	mov     r6, r6, asr #0x4
	mov     r6, r6, lsl #0x2
	ldrsh   r2, [r1, r2]
	rsb     r5, r5, #0x0
	ldrsh   r6, [r1, r6]
	mul     r1, r5, r2
	mul     r2, r6, r1
	smull   r1, r5, r3, r2
	add     r5, r2, r5
	mov     r5, r5, asr #0x9
	mov     r1, r2, lsr #0x1f
	add     r5, r1, r5
	str     r5, [r4, #0x0ac]
	ldr     r2, [r0]
	ldr     r1, [r4, #0x0a4]
	mov     r3, #0x0c
	add     r1, r2, r1
	str     r1, [r0]
	ldr     r2, [r12]
	ldr     r1, [r4, #0x0a8]
	mov     r0, r4
	add     r1, r2, r1
	str     r1, [r12]
	ldr     r12, [r14]
	ldr     r2, [r4, #0x0ac]
	mov     r1, #0x9a
	add     r2, r12, r2
	str     r2, [r14]
	ldr     r12, [r4, #0x360]
	mov     r2, #0x1
	mul     r3, r12, r3
	bl      FUN_02116518
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02116f30
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0f0f0f0f1
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x11
	mov     r1, r1, lsr #0x4
	umull   r0, r1, r2, r1
	subs    r1, r3, r0
	beq     LAB_02116f28
	ldrsb   r0, [r4, #0x0cc]
	add     r2, r4, #0x5c
	mvn     r12, #0x0
	str     r0, [r13]
	mov     r0, #0x118
	mov     r1, #0x6
	mov     r3, #0x0
	str     r12, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
LAB_02116f28:
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02116f30:
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x74]
	cmp     r0, #0x3c
	addcc   r13, r13, #0x8
	popcc   { r4-r6, r14 }
	bxcc    r14
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x8
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116f74:
	mov     r1, #0x1e
	str     r1, [r0, #0x98]
	mov     r1, #0x2000
	str     r1, [r0, #0x360]
	mov     r1, #0x10
	str     r1, [r0, #0x368]
	bx      r14
.ltorg)");

asm(R"(
FUN_02116f90:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	mov     r1, #0x0
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	mov     r0, #0x4000
	ldr     r1, [r4, #0x0a8]
	rsb     r0, r0, #0x0
	cmp     r1, r0
	strlt   r0, [r4, #0x0a8]
	ldr     r0, [r4, #0x36c]
	cmp     r0, #0x0
	bne     LAB_02117078
	ldr     r1, [r4, #0x64]
	mov     r0, #0x0
	str     r1, [r13]
	str     r0, [r13, #0x4]
	ldr     r1, [r4, #0x60]
	ldr     r0, [r4, #0x37c]
	ldr     r2, [r4, #0x5c]
	add     r3, r1, #0x37000
	mov     r1, #0x9e
	bl      _ZN8Particle6System17NewUnkCallback818Ejj5Fix12IiES2_S2_PK11Vector3_16f
	str     r0, [r4, #0x37c]
	add     r2, r4, #0x2e8
	ldr     r1, [r2]
	mov     r0, r4
	orr     r1, r1, #0x1
	str     r1, [r2]
	bl      FUN_0211712c
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_021170f8
	add     r1, r4, #0x36c
	ldr     r0, [r1]
	add     r0, r0, #0x1
	str     r0, [r1]
	ldr     r0, [r4, #0x35c]
	cmp     r0, #0x7
	moveq   r0, #0x6000
	streq   r0, [r4, #0x360]
	beq     LAB_02117058
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0fff
	and     r0, r1, r0, lsr #0x10
	mov     r0, r0, lsl #0x1
	add     r0, r0, #0x6000
	str     r0, [r4, #0x360]
LAB_02117058:
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	str     r0, [r4, #0x0a8]
	str     r0, [r4, #0x9c]
	str     r0, [r4, #0x380]
	ldr     r0, [r4, #0x380]
	str     r0, [r4, #0x37c]
	b       LAB_021170f8
LAB_02117078:
	ldr     r1, [r4, #0x360]
	mov     r0, #0x0c
	mul     r3, r1, r0
	mov     r0, r4
	mov     r1, #0x9c
	mov     r2, #0x1
	bl      FUN_02116518
	add     r2, r4, #0x2e8
	ldr     r0, [r2]
	mov     r1, #0x0a
	bic     r0, r0, #0x1
	str     r0, [r2]
	ldr     r2, [r4, #0x360]
	add     r0, r4, #0x300
	mul     r3, r2, r1
	mov     r1, r3, asr #0x0b
	add     r1, r3, r1, lsr #0x14
	mov     r1, r1, asr #0x0c
	ldrh    r2, [r0, #0x74]
	add     r0, r1, #0x5
	cmp     r2, r0
	ble     LAB_021170f8
	add     r2, r4, #0x360
	ldr     r1, [r2]
	ldr     r0, =#0x266
	sub     r0, r1, r0
	str     r0, [r2]
	ldr     r0, [r4, #0x360]
	cmp     r0, #0x0
	bgt     LAB_021170f8
	mov     r0, r4
	bl      FUN_021172e0
LAB_021170f8:
	ldr     r0, [r4, #0x60]
	cmp     r0, #0x0
	addge   r13, r13, #0x8
	popge   { r4, r14 }
	bxge    r14
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211712c:
	push    { r4, r14 }
	add     r1, r0, #0x300
	ldrh    r1, [r1, #0x76]
	ldr     r2, [r0, #0x370]
	ldrh    r3, [r0, #0x94]
	add     r1, r2, r1
	and     r1, r1, #0x3f
	mov     r1, r1, lsl #0x1a
	mov     r1, r1, asr #0x10
	mov     r1, r1, lsl #0x10
	mov     r1, r1, lsr #0x10
	mov     r1, r1, asr #0x4
	mov     r2, r1, lsl #0x1
	mov     r3, r3, asr #0x4
	ldr     r1, =SINE_TABLE
	mov     r12, r3, lsl #0x2
	mov     r3, r2, lsl #0x1
	ldrsh   r12, [r1, r12]
	ldrsh   r3, [r1, r3]
	add     r4, r0, #0x5c
	ldr     r14, [r4]
	smulbb  r3, r12, r3
	mov     r12, r3, lsl #0x2
	mov     r3, r12, asr #0x0b
	add     r3, r12, r3, lsr #0x14
	add     r3, r14, r3, asr #0x0c
	str     r3, [r4]
	ldrh    r3, [r0, #0x94]
	add     r2, r2, #0x1
	mov     r2, r2, lsl #0x1
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x1
	add     r3, r3, #0x1
	mov     r3, r3, lsl #0x1
	ldrsh   r3, [r1, r3]
	ldrsh   r1, [r1, r2]
	add     r12, r0, #0x64
	ldr     r2, [r12]
	smulbb  r0, r3, r1
	mov     r1, r0, lsl #0x2
	mov     r0, r1, asr #0x0b
	add     r0, r1, r0, lsr #0x14
	add     r0, r2, r0, asr #0x0c
	str     r0, [r12]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021171e8:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x10
	strh    r0, [r4, #0x94]
	mov     r0, #0x0a000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	mov     r0, #0x6000
	str     r0, [r4, #0x360]
	mov     r0, #0x10
	str     r0, [r4, #0x368]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211722c:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x10
	ldr     r0, =RNG_STATE
	strh    r1, [r4, #0x94]
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x2
	movcc   r0, #0x1e000
	strcc   r0, [r4, #0x0a8]
	movcs   r0, #0x0a000
	strcs   r0, [r4, #0x0a8]
	mov     r2, #0x5000
	mov     r1, #0x1000
	ldr     r0, =RNG_STATE
	str     r2, [r4, #0x98]
	rsb     r1, r1, #0x0
	str     r1, [r4, #0x9c]
	bl      RandomIntInternal
	ldr     r1, =#0x0fff
	mov     r2, #0x10
	and     r0, r1, r0, lsr #0x10
	add     r0, r0, #0x1000
	str     r0, [r4, #0x360]
	str     r2, [r4, #0x368]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021172c8:
	add     r0, r0, #0x300
	ldrh    r0, [r0, #0x74]
	cmp     r0, r1
	movhi   r0, #0x1
	movls   r0, #0x0
	bx      r14
.ltorg)");

asm(R"(
FUN_021172e0:
	push    { r4-r10, r14 }
	sub     r13, r13, #0x8
	mov     r10, r0
	ldr     r1, [r10, #0x5c]
	ldr     r2, [r10, #0x60]
	ldr     r3, [r10, #0x64]
	mov     r0, #0x9f
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	mov     r0, r10
	bl      _ZN9ActorBase18MarkForDestructionEv
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x2
	addcs   r13, r13, #0x8
	popcs   { r4-r10, r14 }
	bxcs    r14
	mov     r0, r10
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_0211741c
	ldr     r0, [r0, #0x8]
	cmp     r0, #0x3
	bne     LAB_0211741c
	ldr     r0, =#0x117
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	movs    r9, r0
	beq     LAB_0211741c
	ldrb    r0, [r9, #0x42b]
	cmp     r0, #0x0
	bne     LAB_0211741c
	mov     r8, #0x0
	mov     r5, r8
	mov     r4, #0x1
LAB_02117384:
	mov     r0, r5
	bl      _ZN8SaveData19IsCharacterUnlockedEj
	cmp     r0, #0x0
	orrne   r0, r8, r4, lsl r5
	add     r5, r5, #0x1
	andne   r8, r0, #0x0ff
	cmp     r5, #0x3
	blt     LAB_02117384
	ldr     r7, =RNG_STATE
	mov     r6, #0x1
	ldr     r5, =#0x0aaaaaaab
	ldr     r4, =#0x3
LAB_021173b4:
	mov     r0, r7
	bl      RandomIntInternal
	mov     r2, r0, lsr #0x10
	umull   r0, r1, r2, r5
	mov     r1, r1, lsr #0x1
	umull   r0, r1, r4, r1
	sub     r1, r2, r0
	mov     r0, r6, lsl r1
	ands    r0, r8, r0
	beq     LAB_021173b4
	ldrsb   r2, [r10, #0x0cc]
	mov     r1, r1, lsl #0x8
	ldr     r0, =#0x10d
	str     r2, [r13]
	mvn     r4, #0x0
	orr     r1, r1, #0x0b
	add     r2, r10, #0x5c
	add     r3, r10, #0x8c
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	cmp     r0, #0x0
	movne   r0, #0x1
	add     r13, r13, #0x8
	strneb  r0, [r9, #0x42b]
	pop     { r4-r10, r14 }
	bx      r14
LAB_0211741c:
	ldrsb   r0, [r10, #0x0cc]
	mov     r1, #0x0
	mov     r3, r1
	str     r0, [r13]
	mvn     r4, #0x0
	add     r2, r10, #0x5c
	mov     r0, #0x120
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	cmp     r0, #0x0
	movne   r1, #0x0
	strne   r1, [r0, #0x0a4]
	strne   r1, [r0, #0x0a8]
	strne   r1, [r0, #0x0ac]
	add     r13, r13, #0x8
	pop     { r4-r10, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211747c:
	push    { r4-r9, r14 }
	sub     r13, r13, #0x14
	mov     r9, r0
	ldr     r0, [r9, #0x2cc]
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	bne     LAB_021174ac
	mov     r0, r9
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x14
	pop     { r4-r9, r14 }
	bx      r14
LAB_021174ac:
	ldr     r1, [r4, #0x40c]
	cmp     r1, #0x0f
	addne   r13, r13, #0x14
	popne   { r4-r9, r14 }
	bxne    r14
	bl      FUN_02111c68
	movs    r8, r0
	addmi   r13, r13, #0x14
	popmi   { r4-r9, r14 }
	bxmi    r14
	add     r1, r4, #0x5c
	ldrh    r7, [r4, #0x8e]
	ldr     r0, [r1]
	ldr     r3, =SINE_TABLE
	str     r0, [r13, #0x8]
	ldr     r0, [r1, #0x4]
	mov     r2, r7, asr #0x4
	str     r0, [r13, #0x0c]
	mov     r2, r2, lsl #0x1
	add     r0, r2, #0x1
	mov     r5, r0, lsl #0x1
	ldr     r1, [r1, #0x8]
	mov     r2, r2, lsl #0x1
	add     r0, r4, #0x124
	str     r1, [r13, #0x10]
	ldrsh   r5, [r3, r5]
	ldrsh   r4, [r3, r2]
	ldr     r6, =UNK_02119364
	bl      _ZNK9Animation13GetFrameCountEv
	cmp     r8, r0
	moveq   r8, #0x0
	mov     r0, #0x5
	mul     r1, r8, r0
	ldr     r0, [r9, #0x388]
	add     r6, r6, r1, lsl #0x1
	cmp     r0, #0x180
	movne   r0, #0x0
	strne   r0, [r9, #0x384]
	mov     r0, #0x180
	str     r0, [r9, #0x388]
	mov     r0, #0x0
	str     r0, [r13]
	ldr     r0, [r9, #0x384]
	ldr     r2, [r9, #0x388]
	add     r3, r9, #0x74
	mov     r1, #0x3
	bl      _ZN5Sound8PlayLongEjjjRK7Vector3j
	str     r0, [r9, #0x384]
	ldrh    r1, [r6]
	ldrh    r0, [r6, #0x4]
	ldr     r3, [r13, #0x8]
	mul     r2, r1, r5
	add     r0, r0, #0x14
	mla     r2, r0, r4, r2
	add     r2, r3, r2
	str     r2, [r9, #0x5c]
	mul     r2, r0, r5
	mul     r0, r1, r4
	ldrh    r3, [r6, #0x2]
	ldr     r4, [r13, #0x0c]
	sub     r0, r2, r0
	sub     r1, r3, #0x5a
	add     r1, r4, r1, lsl #0x0c
	str     r1, [r9, #0x60]
	ldr     r1, [r13, #0x10]
	add     r0, r1, r0
	str     r0, [r9, #0x64]
	ands    r1, r8, #0x1
	ldrh    r2, [r6, #0x8]
	ldr     r0, =#0x818
	addne   r13, r13, #0x14
	add     r0, r2, r0
	strh    r0, [r9, #0x92]
	ldrh    r0, [r6, #0x6]
	add     r0, r0, r7
	sub     r0, r0, #0x4700
	strh    r0, [r9, #0x94]
	popne   { r4-r9, r14 }
	bxne    r14
	ldrsb   r0, [r9, #0x0cc]
	add     r2, r9, #0x5c
	add     r3, r9, #0x92
	str     r0, [r13]
	mvn     r4, #0x0
	mov     r0, #0x118
	mov     r1, #0x5
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	add     r13, r13, #0x14
	pop     { r4-r9, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117624:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	ldrb    r0, [r4, #0x379]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x364]
	ldr     r3, [r4, #0x64]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	mov     r1, r1, asr #0x3
	mov     r2, r2, asr #0x3
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r4, #0x32c
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	mov     r14, #0x1e000
	mov     r12, #0x0f
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	str     r14, [r13]
	str     r12, [r13, #0x4]
	mov     r2, r5
	mov     r0, r4
	add     r1, r4, #0x304
	ldr     r12, [r4, #0x368]
	ldr     r3, [r4, #0x360]
	mul     r3, r12, r3
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021176c4:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021176cc:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021176d4:
	push    { r4, r14 }
	mov     r4, r0
	add     r2, r4, #0x370
	ldr     r0, [r2]
	ldr     r1, =states2
	add     r0, r0, #0x1
	str     r0, [r2]
	ldr     r0, [r4, #0x35c]
	add     r3, r1, r0, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	add     r1, r4, #0x374
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	ldr     r0, [r4, #0x9c]
	cmp     r0, #0x0
	beq     LAB_02117760
	add     r0, r4, #0x110
	bl      0x02038420
	ldr     r0, [r4, #0x35c]
	cmp     r0, #0x4
	beq     LAB_02117760
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x0a8]
	strne   r0, [r4, #0x9c]
LAB_02117760:
	mov     r0, r4
	bl      FUN_02116740
	mov     r0, r4
	bl      FUN_02117624
	add     r0, r4, #0x2d0
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x2d0
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117790:
	push    { r4, r14 }
	sub     r13, r13, #0x68
	mov     r4, r0
	add     r0, r4, #0x304
	bl      _ZN11ShadowModel12InitCylinderEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x68
	moveq   r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x200002
	mov     r1, r4
	str     r0, [r13]
	mov     r12, #0x0
	add     r0, r4, #0x2d0
	mov     r2, #0x28000
	mov     r3, #0x50000
	str     r12, [r13, #0x4]
	bl      _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj
	mov     r12, #0x0
	mov     r2, #0x32000
	str     r12, [r13]
	mov     r1, r4
	mov     r3, r2
	add     r0, r4, #0x110
	str     r12, [r13, #0x4]
	bl      _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_
	mov     r0, #0x4000
	rsb     r1, r0, #0x0
	mov     r0, #0x1e000
	str     r1, [r4, #0x9c]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x0a0]
	ldr     r1, [r4, #0x8]
	add     r0, r4, #0x300
	and     r1, r1, #0x7
	str     r1, [r4, #0x35c]
	mov     r1, #0x0
	strh    r1, [r0, #0x74]
	ldr     r0, [r4, #0x35c]
	mov     r2, #0x0
	cmp     r0, #0x0
	streqb  r1, [r4, #0x379]
	movne   r0, #0x1
	strneb  r0, [r4, #0x379]
	mov     r0, #0x0
	str     r0, [r4, #0x36c]
	ldr     r0, [r4, #0x8]
	mov     r0, r0, lsr #0x4
	and     r0, r0, #0x3
	strb    r0, [r4, #0x378]
	ldr     r0, [r4, #0x35c]
	cmp     r0, #0x0
	addeq   r1, r4, #0x2e8
	ldreq   r0, [r1]
	orreq   r0, r0, #0x1
	streq   r0, [r1]
	mov     r0, #0x2000
	str     r0, [r4, #0x360]
	str     r2, [r4, #0x380]
	ldr     r1, [r4, #0x380]
	add     r0, r13, #0x14
	str     r1, [r4, #0x37c]
	str     r2, [r4, #0x2cc]
	bl      _ZN13RaycastGroundC1Ev
	ldr     r1, [r4, #0x5c]
	add     r0, r13, #0x14
	str     r1, [r13, #0x8]
	ldr     r2, [r4, #0x60]
	add     r1, r13, #0x8
	str     r2, [r13, #0x0c]
	ldr     r12, [r4, #0x64]
	add     r3, r2, #0x32000
	mov     r2, #0x0
	str     r12, [r13, #0x10]
	str     r3, [r13, #0x0c]
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x14
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	ldrne   r0, [r13, #0x58]
	ldr     r1, =states1
	strne   r0, [r4, #0x364]
	ldreq   r0, [r4, #0x60]
	streq   r0, [r4, #0x364]
	ldr     r0, [r4, #0x35c]
	add     r3, r1, r0, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	mov     r1, #0x0
	str     r1, [r4, #0x384]
	add     r0, r13, #0x14
	str     r1, [r4, #0x388]
	bl      _ZN13RaycastGroundD1Ev
	mov     r0, #0x1
	add     r13, r13, #0x68
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117938:
	push    { r4, r14 }
	mov     r0, #0x38c
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02117970
	bl      _ZN5EnemyC2Ev
	ldr     r1, =VTable_BowserFire
	add     r0, r4, #0x110
	str     r1, [r4]
	bl      _ZN12WithMeshClsnC1Ev
	add     r0, r4, #0x2d0
	bl      _ZN18MovingCylinderClsnC1Ev
	add     r0, r4, #0x304
	bl      _ZN11ShadowModelC1Ev
LAB_02117970:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");