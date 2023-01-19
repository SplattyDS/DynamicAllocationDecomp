#include "SM64DS_2.h"
#include "Actors/SpikeBomb.h"

extern "C"
{
	ActorBase* FUN_02118cbc(); // constructor
	
	// state function declarations for use below
	void FUN_02118970(SpikeBomb* spikeBomb);
	void FUN_021188e8(SpikeBomb* spikeBomb);
	void FUN_02118834(SpikeBomb* spikeBomb);
	void FUN_02118728(SpikeBomb* spikeBomb);
	
	using StateFunc = void(*)(SpikeBomb*);
	
	struct State
	{
		StateFunc func;
		u32 unk04 = 0;
	};
	
	State spikeStates[4] = // 0x0211b1d8
	{
		{ &FUN_02118970 },
		{ &FUN_021188e8 },
		{ &FUN_02118834 },
		{ &FUN_02118728 },
	};
}

SharedFilePtr SpikeBomb::modelFile;

SpawnInfo SpikeBomb::spawnData = 
{
	&FUN_02118cbc,
	0x011c,
	0x0093,
	Actor::NO_RENDER_IF_OFF_SCREEN,
	0._f,
	400._f,
	24000._f,
	0._f,
};

asm(".global FUN_02118544");
asm(".global FUN_021185c4");

asm(R"(
@ 0x0211aa8c
VTable_SpikeBomb:
	.word FUN_02118bb4
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02118ab0
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02118b2c
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02118ad4
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02118438
	.word FUN_02118470
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
FUN_02118438:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_SpikeBomb
	add     r0, r4, #0x124
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN5ModelD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118470:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_SpikeBomb
	add     r0, r4, #0x124
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
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
FUN_021184bc:
	push    { r4-r6, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x1a8]
	bl      0x0202a608
	add     r2, r4, #0x13c
	ldr     r0, [r2]
	mov     r1, #0x0
	orr     r0, r0, #0x1
	str     r0, [r2]
	mov     r0, #0x3
	mov     r2, r1
	str     r0, [r4, #0x170]
	mov     r6, r1
LAB_021184f0:
	add     r0, r4, r2, lsl #0x2
	add     r2, r2, #0x1
	str     r6, [r0, #0x188]
	cmp     r2, #0x8
	blt     LAB_021184f0
	mov     r5, #0x11c
LAB_02118508:
	mov     r0, r5
	bl      _ZN5Actor15FindWithActorIDEjPS_
	movs    r1, r0
	popeq   { r4-r6, r14 }
	bxeq    r14
	cmp     r1, r4
	beq     LAB_02118508
	ldr     r2, [r1, #0x4]
	add     r0, r4, r6, lsl #0x2
	add     r6, r6, #0x1
	str     r2, [r0, #0x188]
	cmp     r6, #0x8
	bne     LAB_02118508
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118544:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	ldr     r0, [r5, #0x170]
	mov     r4, r1
	cmp     r0, #0x0
	addne   r13, r13, #0x4
	movne   r0, #0x0
	popne   { r4, r5, r14 }
	bxne    r14
	mov     r0, r4
	bl      Vec3_HorzLen
	ldr     r2, [r5, #0x180]
	sub     r1, r2, #0x12c000
	cmp     r0, r1
	blt     LAB_021185b4
	add     r1, r2, #0x12c000
	cmp     r0, r1
	bgt     LAB_021185b4
	mov     r1, r4
	add     r0, r5, #0x174
	bl      Vec3_Dist
	ldr     r1, [r5, #0x184]
	cmp     r0, r1
	addlt   r13, r13, #0x4
	movlt   r0, #0x1
	poplt   { r4, r5, r14 }
	bxlt    r14
LAB_021185b4:
	mov     r0, #0x0
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021185c4:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	mov     r0, #0x1
	str     r0, [r4, #0x170]
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0a8
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0a9
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0aa
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0ab
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0ac
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	mov     r0, #0x2f
	add     r1, r4, #0x74
	bl      0x02012694
	ldr     r1, [r4, #0x5c]
	mov     r0, r4
	str     r1, [r13]
	ldr     r2, [r4, #0x60]
	add     r1, r13, #0x0
	str     r2, [r13, #0x4]
	ldr     r3, [r4, #0x64]
	mov     r2, #0x7d0000
	str     r3, [r13, #0x8]
	bl      _ZN5Actor10EarthquakeERK7Vector35Fix12IiE
	mov     r1, #0x0
	add     r0, r4, #0x100
	strh    r1, [r0, #0x0ac]
	mov     r0, r4
	bl      FUN_021184bc
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118690:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	add     r0, r4, #0x0f0
	mov     r1, r1, asr #0x3
	mov     r2, r2, asr #0x3
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	ldrb    r1, [r4, #0x1ae]
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mov     r1, r1, asr #0x3
	and     r1, r1, #0x0ff
	bl      _ZN9ModelBase12ApplyOpacityEj
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021186d8:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x1000
	str     r1, [r4, #0x80]
	str     r1, [r4, #0x84]
	str     r1, [r4, #0x88]
	mov     r1, #0x0ff
	strb    r1, [r4, #0x1ae]
	mov     r12, #0x0
	str     r12, [r4, #0x170]
	add     r3, r4, #0x13c
	ldr     r2, [r3]
	add     r1, r4, #0x100
	bic     r2, r2, #0x1
	str     r2, [r3]
	strh    r12, [r1, #0x0ac]
	bl      0x0202a628
	str     r0, [r4, #0x1a8]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118728:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x0c
	mov     r10, r0
	bl      _ZN5Actor13ClosestPlayerEv
	ldr     r1, [r10, #0x0b0]
	ands    r1, r1, #0x8
	movne   r1, #0x1
	moveq   r1, #0x0
	cmp     r1, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r11, r14 }
	bxeq    r14
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r11, r14 }
	bxeq    r14
	add     r3, r0, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	add     r0, r10, #0x5c
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	bl      Vec3_Dist
	mov     r7, #0x0
	mov     r8, r0
	mov     r11, r10
	mov     r5, r7
	mov     r4, r7
	mov     r6, #0x1
LAB_021187a8:
	add     r0, r10, r7, lsl #0x2
	ldr     r0, [r0, #0x188]
	cmp     r0, #0x0
	beq     LAB_02118814
	bl      _ZN5Actor10FindWithIDEj
	movs    r9, r0
	beq     LAB_0211880c
	ldr     r0, [r9, #0x170]
	cmp     r0, #0x3
	addne   r13, r13, #0x0c
	popne   { r4-r11, r14 }
	bxne    r14
	ldr     r0, [r9, #0x0b0]
	ands    r0, r0, #0x8
	movne   r0, r6
	moveq   r0, r5
	cmp     r0, #0x0
	beq     LAB_02118814
	add     r0, r13, #0x0
	add     r1, r9, #0x5c
	bl      Vec3_Dist
	cmp     r0, r8
	movlt   r8, r0
	movlt   r11, r9
	b       LAB_02118814
LAB_0211880c:
	add     r0, r10, r7, lsl #0x2
	str     r4, [r0, #0x188]
LAB_02118814:
	add     r7, r7, #0x1
	cmp     r7, #0x8
	blt     LAB_021187a8
	mov     r0, r11
	bl      FUN_021186d8
	add     r13, r13, #0x0c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118834:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x100
	ldrh    r1, [r0, #0x0ac]
	mov     r0, #0x9
	ldr     r2, =#0x92492493
	mul     r12, r1, r0
	mov     r1, r12, lsl #0x0c
	mov     r0, r1, lsr #0x1f
	smull   r1, r14, r2, r1
	add     r14, r14, r12, lsl #0x0c
	mov     r14, r14, asr #0x3
	add     r14, r0, r14
	ldr     r3, =#0x1ae
	add     r0, r14, #0x1000
	str     r0, [r4, #0x80]
	str     r0, [r4, #0x84]
	add     r1, r4, r3
	str     r0, [r4, #0x88]
	ldrb    r0, [r1]
	add     r3, r4, #0x60
	sub     r0, r0, #0x0a
	strb    r0, [r1]
	ldrb    r0, [r4, #0x1ae]
	cmp     r0, #0x0a
	movcc   r0, #0x0
	strccb  r0, [r4, #0x1ae]
	ldr     r2, [r3]
	ldr     r1, [r4, #0x0a8]
	add     r0, r4, #0x100
	add     r1, r2, r1
	str     r1, [r3]
	ldrh    r0, [r0, #0x0ac]
	cmp     r0, #0x1c
	bne     LAB_021188c8
	mov     r0, r4
	bl      FUN_021184bc
LAB_021188c8:
	add     r1, r4, #0x1ac
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021188e8:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r4, r0
	add     r2, r4, #0x13c
	ldr     r1, [r2]
	add     r3, r4, #0x100
	orr     r1, r1, #0x1
	str     r1, [r2]
	ldrh    r12, [r3, #0x0ac]
	mov     r1, #0x9
	ldr     r2, =#0x92492493
	mul     r14, r12, r1
	mov     r12, r14, lsl #0x0c
	smull   r1, r5, r2, r12
	add     r5, r5, r14, lsl #0x0c
	mov     r5, r5, asr #0x3
	mov     r1, r12, lsr #0x1f
	add     r5, r1, r5
	add     r1, r5, #0x1000
	str     r1, [r4, #0x80]
	str     r1, [r4, #0x84]
	str     r1, [r4, #0x88]
	ldrh    r1, [r3, #0x0ac]
	cmp     r1, #0x1c
	bne     LAB_02118950
	bl      FUN_021184bc
LAB_02118950:
	add     r1, r4, #0x1ac
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118970:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x24
	mov     r4, r0
	ldr     r0, [r4, #0x148]
	cmp     r0, #0x0
	addeq   r13, r13, #0x24
	popeq   { r4, r5, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	movs    r5, r0
	addeq   r13, r13, #0x24
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldrh    r0, [r5, #0x0c]
	cmp     r0, #0x0bf
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	addeq   r13, r13, #0x24
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0a8
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0a9
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0aa
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0ab
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x0ac
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	mov     r0, #0x2f
	add     r1, r4, #0x74
	bl      0x02012694
	ldr     r1, [r4, #0x5c]
	mov     r0, r4
	str     r1, [r13, #0x0c]
	ldr     r2, [r4, #0x60]
	add     r1, r13, #0x0c
	str     r2, [r13, #0x10]
	ldr     r3, [r4, #0x64]
	mov     r2, #0x7d0000
	str     r3, [r13, #0x14]
	bl      _ZN5Actor10EarthquakeERK7Vector35Fix12IiE
	ldr     r1, [r4, #0x5c]
	mov     r3, #0x1
	str     r1, [r13, #0x18]
	ldr     r1, [r4, #0x60]
	mov     r2, #0x0
	str     r1, [r13, #0x1c]
	ldr     r12, [r4, #0x64]
	mov     r0, r5
	str     r12, [r13, #0x20]
	str     r3, [r13]
	str     r2, [r13, #0x4]
	str     r3, [r13, #0x8]
	add     r1, r13, #0x18
	mov     r2, #0x2
	mov     r3, #0x0c000
	bl      _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj
	mov     r0, r4
	bl      FUN_021184bc
	add     r13, r13, #0x24
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118ab0:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN9SpikeBomb9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118ad4:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r1, [r0, #0x170]
	cmp     r1, #0x0
	addne   r13, r13, #0x4
	movne   r0, #0x1
	popne   { r14 }
	bxne    r14
	ldrb    r1, [r0, #0x1ae]
	cmp     r1, #0x8
	addcc   r13, r13, #0x4
	movcc   r0, #0x1
	popcc   { r14 }
	bxcc    r14
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
FUN_02118b2c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldr     r0, [r4, #0x170]
	ldr     r1, =spikeStates
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
	bl      FUN_02118690
	add     r0, r4, #0x124
	bl      _ZN12CylinderClsn5ClearEv
	mov     r3, #0x0
	mov     r0, #0x96000
	rsb     r2, r0, #0x0
	add     r1, r13, #0x0
	add     r0, r4, #0x124
	str     r3, [r13]
	str     r2, [r13, #0x4]
	str     r3, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	add     r0, r4, #0x124
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118bb4:
	push    { r4, r14 }
	sub     r13, r13, #0x28
	mov     r4, r0
	ldr     r0, =_ZN9SpikeBomb9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	mov     r12, #0x0
	mov     r3, #0x96000
	rsb     r0, r3, #0x0
	str     r0, [r13, #0x10]
	str     r12, [r13, #0x0c]
	str     r12, [r13, #0x14]
	mov     r1, #0x12c000
	str     r1, [r13]
	ldr     r0, =#0x204004
	add     r2, r13, #0x0c
	str     r0, [r13, #0x4]
	mov     r1, r4
	add     r0, r4, #0x124
	str     r12, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	mov     r0, #0x1000
	str     r0, [r4, #0x80]
	str     r0, [r4, #0x84]
	str     r0, [r4, #0x88]
	mov     r1, #0x0ff
	strb    r1, [r4, #0x1ae]
	mov     r1, #0x0
	add     r0, r13, #0x18
	str     r1, [r13, #0x18]
	str     r1, [r13, #0x1c]
	str     r1, [r13, #0x20]
	add     r1, r4, #0x5c
	bl      Vec3_HorzAngle
	ldr     r0, =#0x2ee000
	add     r3, r4, #0x178
	str     r0, [r4, #0x184]
	ldr     r1, [r4, #0x5c]
	add     r0, r4, #0x5c
	str     r1, [r4, #0x174]
	ldr     r1, [r4, #0x60]
	str     r1, [r4, #0x178]
	ldr     r1, [r4, #0x64]
	str     r1, [r4, #0x17c]
	ldr     r2, [r3]
	ldr     r1, [r4, #0x184]
	add     r1, r2, r1, asr #0x3
	str     r1, [r3]
	bl      Vec3_HorzLen
	str     r0, [r4, #0x180]
	mov     r0, #0x0
	str     r0, [r4, #0x170]
	mov     r0, r4
	bl      0x0202a628
	str     r0, [r4, #0x1a8]
	mov     r0, #0x1
	add     r13, r13, #0x28
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118cbc:
	push    { r4, r14 }
	mov     r0, #0x1b0
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02118cec
	bl      _ZN5ActorC2Ev
	ldr     r1, =VTable_SpikeBomb
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN5ModelC1Ev
	add     r0, r4, #0x124
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
LAB_02118cec:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");