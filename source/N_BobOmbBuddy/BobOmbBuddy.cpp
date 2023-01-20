#include "SM64DS_2.h"
#include "Actors/BobOmbBuddy.h"

extern "C"
{
	ActorBase* FUN_0212d200(); // constructor
	
	// state function declarations for use below
	void FUN_0212c92c(BobOmbBuddy* bobOmbBuddy);
	void FUN_0212c8b0(BobOmbBuddy* bobOmbBuddy);
	void FUN_0212c89c(BobOmbBuddy* bobOmbBuddy);
	void FUN_0212c508(BobOmbBuddy* bobOmbBuddy);
	void FUN_0212c4a0(BobOmbBuddy* bobOmbBuddy);
	void FUN_0212c1a0(BobOmbBuddy* bobOmbBuddy);
	
	// undocumented globals not in ov84:
	// 0x0209d6bc
	// 0x0209f284
	// 0x0209f288
	
	using StateFunc = void(*)(BobOmbBuddy*);
	
	struct State
	{
		StateFunc func1;
		u32 unk04 = 0;
		StateFunc func2;
		u32 unk0c = 0;
	};
	
	State states[3] = // 0x02130dc4
	{
		{ &FUN_0212c92c, 0, &FUN_0212c8b0, 0 },
		{ &FUN_0212c89c, 0, &FUN_0212c508, 0 },
		{ &FUN_0212c4a0, 0, &FUN_0212c1a0, 0 },
	};
}

SharedFilePtr BobOmbBuddy::modelFile;
SharedFilePtr BobOmbBuddy::animFile;

SpawnInfo BobOmbBuddy::spawnData = 
{
	&FUN_0212d200,
	0x00b5,
	0x002e,
	Actor::NO_BEHAVIOR_IF_OFF_SCREEN | Actor::NO_RENDER_IF_OFF_SCREEN,
	64._f,
	128._f,
	4096._f,
	4096._f,
};

asm(R"(
@ 0x02130a38
VTable_BobOmbBuddy:
	.word FUN_0212d028
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_0212cf10
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_0212cf6c
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_0212cf40
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_0212c10c
	.word FUN_0212c14c
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
FUN_0212c10c:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BobOmbBuddy
	add     r0, r4, #0x16c
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x108
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN18MovingCylinderClsnD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c14c:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BobOmbBuddy
	add     r0, r4, #0x16c
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x108
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN18MovingCylinderClsnD1Ev
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
FUN_0212c1a0:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x0c
	mov     r6, r0
	ldr     r5, [r6, #0x194]
	ldr     r2, =CAMERA
	add     r4, r5, #0x5c
	ldr     r0, [r4]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r3, [r4, #0x4]
	add     r0, r6, #0x5c
	str     r3, [r13, #0x4]
	ldr     r3, [r4, #0x8]
	ldr     r4, [r2]
	str     r3, [r13, #0x8]
	bl      Vec3_HorzAngle
	ldrb    r1, [r6, #0x1e8]
	mov     r7, r0
	cmp     r1, #0x4
	addls   r15, r15, r1, lsl #0x2
	b       LAB_0212c484
	b       LAB_0212c208
	b       LAB_0212c338
	b       LAB_0212c39c
	b       LAB_0212c3d8
	b       LAB_0212c400
LAB_0212c208:
	mov     r0, r5
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	beq     LAB_0212c314
	cmp     r0, #0x0
	beq     LAB_0212c238
	cmp     r0, #0x2
	beq     LAB_0212c2a8
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c238:
	mov     r1, r7
	add     r0, r6, #0x8e
	mov     r2, #0x800
	bl      _Z14ApproachLinearRsss
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	ldr     r0, =LEVEL_ID
	ldrsb   r0, [r0]
	cmp     r0, #0x6
	moveq   r1, #0x8f
	ldr     r0, [r6, #0x198]
	ldrne   r1, =#0x14a
	cmp     r0, #0x0
	beq     LAB_0212c290
	mov     r0, r6
	mov     r2, #0x1
	bl      FUN_0212c9f0
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c290:
	mov     r0, r6
	mov     r2, #0x0
	bl      FUN_0212c9f0
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c2a8:
	add     r3, r4, #0x80
	ldr     r0, [r3]
	add     r2, r4, #0x8c
	str     r0, [r6, #0x1cc]
	ldr     r1, [r3, #0x4]
	mov     r0, r4
	str     r1, [r6, #0x1d0]
	ldr     r1, [r3, #0x8]
	str     r1, [r6, #0x1d4]
	ldr     r1, [r2]
	str     r1, [r6, #0x1d8]
	ldr     r1, [r2, #0x4]
	str     r1, [r6, #0x1dc]
	ldr     r1, [r2, #0x8]
	str     r1, [r6, #0x1e0]
	bl      _ZN6Camera9SetFlag_3Ev
	add     r2, r6, #0x0b0
	ldr     r0, [r2]
	add     r1, r6, #0x1e8
	bic     r0, r0, #0x1
	str     r0, [r2]
	ldrb    r0, [r1]
	add     r13, r13, #0x0c
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c314:
	bl      0x0202a67c
	mov     r2, #0x1
	mov     r0, r6
	mov     r1, #0x0
	strb    r2, [r6, #0x1ea]
	bl      FUN_0212c960
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c338:
	ldr     r0, [r6, #0x198]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	mov     r0, r6
	bl      FUN_0212cae0
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	ldr     r0, [r6, #0x198]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	bl      0x020bc990
	add     r1, r6, #0x1e8
	ldrb    r0, [r1]
	add     r13, r13, #0x0c
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c39c:
	ldr     r0, [r6, #0x198]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	ldrb    r0, [r0, #0x32e]
	add     r13, r13, #0x0c
	cmp     r0, #0x1
	addeq   r1, r6, #0x1e8
	ldreqb  r0, [r1]
	addeq   r0, r0, #0x1
	streqb  r0, [r1]
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c3d8:
	mov     r0, r6
	bl      FUN_0212ccb4
	cmp     r0, #0x0
	addne   r1, r6, #0x1e8
	ldrneb  r0, [r1]
	add     r13, r13, #0x0c
	addne   r0, r0, #0x1
	strneb  r0, [r1]
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c400:
	mov     r0, r5
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x1
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	cmp     r0, #0x2
	bne     LAB_0212c44c
	ldr     r0, =LEVEL_ID
	mov     r2, #0x0
	ldrsb   r0, [r0]
	cmp     r0, #0x6
	moveq   r1, #0x90
	ldrne   r1, =#0x14b
	mov     r0, r6
	bl      FUN_0212c9f0
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c44c:
	add     r1, r6, #0x0b0
	ldr     r0, [r1]
	orr     r0, r0, #0x1
	str     r0, [r1]
	bl      0x0202a67c
	mov     r0, #0x1
	strb    r0, [r6, #0x1ea]
	add     r3, r4, #0x154
	ldr     r1, [r3]
	mov     r0, r6
	bic     r2, r1, #0x8
	mov     r1, #0x0
	str     r2, [r3]
	bl      FUN_0212c960
LAB_0212c484:
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c4a0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	mov     r0, #0x0e
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	movs    r1, r0
	beq     LAB_0212c4f4
	mov     r4, #0x0e
LAB_0212c4c4:
	ldr     r0, [r1, #0x8]
	and     r0, r0, #0x0ff
	cmp     r0, #0x1
	bne     LAB_0212c4e4
	ldrb    r0, [r1, #0x32e]
	cmp     r0, #0x0
	ldreq   r0, [r1, #0x4]
	streq   r0, [r5, #0x198]
LAB_0212c4e4:
	mov     r0, r4
	bl      _ZN5Actor15FindWithActorIDEjPS_
	movs    r1, r0
	bne     LAB_0212c4c4
LAB_0212c4f4:
	mov     r0, #0x0
	strb    r0, [r5, #0x1e8]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c508:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x0c
	mov     r6, r0
	ldr     r5, [r6, #0x194]
	ldr     r1, [r6, #0x8]
	ldr     r0, =#0x0ffff
	mov     r4, #0x0
	cmp     r1, r0
	movne   r0, r1, lsl #0x10
	add     r3, r5, #0x5c
	movne   r4, r0, lsr #0x10
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	add     r0, r6, #0x5c
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzAngle
	mov     r7, r0
	mov     r0, r6
	bl      FUN_0212cac0
	cmp     r0, #0x0
	beq     LAB_0212c590
	bl      0x0202a694
	cmp     r0, #0x0
	bne     LAB_0212c590
	mov     r0, r6
	mov     r1, #0x2
	bl      FUN_0212c960
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
LAB_0212c590:
	mov     r0, r5
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	beq     LAB_0212c5ac
	cmp     r0, #0x1
	beq     LAB_0212c6e0
	b       LAB_0212c6d4
LAB_0212c5ac:
	mov     r1, r7
	add     r0, r6, #0x8e
	mov     r2, #0x800
	bl      _Z14ApproachLinearRsss
	cmp     r0, #0x0
	beq     LAB_0212c6e0
	mov     r0, r6
	bl      FUN_0212caa8
	cmp     r0, #0x0
	beq     LAB_0212c63c
	ldr     r0, =SAVE_DATA
	ldr     r1, [r0, #0x8]
	ands    r2, r1, #0x8000
	orreq   r1, r1, #0x8000
	streq   r1, [r0, #0x8]
	ldreq   r1, =#0x15b
	beq     LAB_0212c620
	bl      0x0202a6e4
	cmp     r0, #0x3
	movle   r1, #0x15c
	ble     LAB_0212c620
	bl      0x0202a6e4
	cmp     r0, #0x6
	ldrle   r1, =#0x15d
	ble     LAB_0212c620
	bl      0x0202a6e4
	cmp     r0, #0x7
	ldreq   r1, =#0x15e
	ldrne   r1, =#0x15f
LAB_0212c620:
	mov     r0, r6
	mov     r2, #0x0
	bl      FUN_0212c9f0
	ldr     r0, =#0x209f288
	mov     r1, #0x1
	strb    r1, [r0]
	b       LAB_0212c6e0
LAB_0212c63c:
	mov     r0, r6
	bl      FUN_0212cac0
	cmp     r0, #0x0
	beq     LAB_0212c6a8
	bl      0x0202a694
	cmp     r0, #0x0
	beq     LAB_0212c6a8
	ldrb    r0, [r6, #0x1ea]
	cmp     r0, #0x0
	bne     LAB_0212c67c
	ldr     r0, =LEVEL_ID
	ldrsb   r0, [r0]
	cmp     r0, #0x6
	moveq   r1, #0x8f
	ldrne   r1, =#0x14a
	b       LAB_0212c690
LAB_0212c67c:
	ldr     r0, =LEVEL_ID
	ldrsb   r0, [r0]
	cmp     r0, #0x6
	moveq   r1, #0x90
	ldrne   r1, =#0x14b
LAB_0212c690:
	mov     r3, #0x1
	mov     r0, r6
	mov     r2, #0x0
	strb    r3, [r6, #0x1ea]
	bl      FUN_0212c9f0
	b       LAB_0212c6e0
LAB_0212c6a8:
	mov     r0, r4, lsl #0x10
	mov     r0, r0, asr #0x10
	bl      0x0201fc10
	ldr     r1, [r5, #0x8]
	mov     r2, #0x0
	add     r0, r0, r1
	mov     r1, r0, lsl #0x10
	mov     r0, r6
	mov     r1, r1, lsr #0x10
	bl      FUN_0212c9f0
	b       LAB_0212c6e0
LAB_0212c6d4:
	mov     r0, r6
	mov     r1, #0x0
	bl      FUN_0212c960
LAB_0212c6e0:
	ldr     r0, =PLAYER_TALKING
	ldrb    r0, [r0]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4-r7, r14 }
	bxeq    r14
	ldr     r0, =#0x209d6bc
	ldrb    r0, [r0]
	cmp     r0, #0x9
	bne     LAB_0212c720
	mov     r0, r6
	bl      FUN_0212caa8
	cmp     r0, #0x0
	ldrne   r0, =#0x209f288
	movne   r1, #0x0
	strneb  r1, [r0]
LAB_0212c720:
	ldr     r1, =#0x209d6bc
	add     r0, r6, #0x100
	ldrb    r1, [r1]
	ldrh    r0, [r0, #0x0ec]
	cmp     r0, r1
	beq     LAB_0212c75c
	cmp     r1, #0x3
	beq     LAB_0212c748
	cmp     r1, #0x9
	bne     LAB_0212c75c
LAB_0212c748:
	ldr     r0, =#0x1eb
	add     r1, r6, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
LAB_0212c75c:
	ldr     r0, =CURR_MSG_ID
	ldrh    r4, [r0]
	cmp     r4, #0x15c
	beq     LAB_0212c788
	ldr     r0, =#0x15e
	cmp     r4, r0
	beq     LAB_0212c788
	mov     r0, r6
	bl      FUN_0212ca60
	cmp     r0, #0x0
	beq     LAB_0212c7a8
LAB_0212c788:
	ldrb    r0, [r6, #0x1eb]
	cmp     r0, #0x0
	ldreq   r0, =#0x209f284
	moveq   r1, #0x1
	streqb  r1, [r0]
	ldrne   r0, =#0x209f284
	movne   r1, #0x0
	strneb  r1, [r0]
LAB_0212c7a8:
	ldr     r0, =#0x15b
	cmp     r4, r0
	beq     LAB_0212c7c0
	ldr     r0, =#0x15d
	cmp     r4, r0
	bne     LAB_0212c7e0
LAB_0212c7c0:
	ldrb    r0, [r6, #0x1eb]
	cmp     r0, #0x1
	ldreq   r0, =#0x209f284
	moveq   r1, #0x1
	streqb  r1, [r0]
	ldrne   r0, =#0x209f284
	movne   r1, #0x0
	strneb  r1, [r0]
LAB_0212c7e0:
	cmp     r4, #0x8a
	bne     LAB_0212c814
	ldrb    r0, [r6, #0x1eb]
	cmp     r0, #0x1
	ldreq   r0, =#0x209f284
	moveq   r1, #0x1
	streqb  r1, [r0]
	ldr     r0, =#0x209d6bc
	ldrb    r0, [r0]
	cmp     r0, #0x9
	ldreq   r0, =#0x209f284
	moveq   r1, #0x0
	streqb  r1, [r0]
LAB_0212c814:
	ldr     r0, =#0x209f284
	ldrb    r1, [r6, #0x1ee]
	ldrb    r0, [r0]
	cmp     r1, r0
	beq     LAB_0212c838
	cmp     r0, #0x0
	beq     LAB_0212c838
	mov     r0, #0x24
	bl      _ZN5Sound16UnkPlaySoundFuncEj
LAB_0212c838:
	ldr     r0, =#0x209f284
	ldr     r1, =#0x209d6bc
	ldrb    r2, [r0]
	add     r0, r6, #0x100
	strb    r2, [r6, #0x1ee]
	ldrb    r1, [r1]
	strh    r1, [r0, #0x0ec]
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c89c:
	mov     r1, #0x0
	strb    r1, [r0, #0x1eb]
	add     r0, r0, #0x100
	strh    r1, [r0, #0x0ec]
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c8b0:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x0f4]
	ands    r0, r0, #0x8000000
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, [r4, #0x0f8]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldrh    r1, [r0, #0x0c]
	cmp     r1, #0x0bf
	moveq   r1, #0x1
	movne   r1, #0x0
	cmp     r1, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	str     r0, [r4, #0x194]
	ldr     r0, [r4, #0x194]
	mov     r1, r4
	mov     r2, #0x0
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_0212c960
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c92c:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	ldr     r1, =_ZN11BobOmbBuddy8animFileE
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x108
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c960:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x1e4]
	ldr     r1, [r0, #0x1e4]
	ldr     r2, =states
	add     r3, r2, r1, lsl #0x4
	ldr     r1, [r3, #0x4]
	add     r0, r0, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c9a8:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r1, [r0, #0x1e4]
	ldr     r2, =states
	add     r1, r2, r1, lsl #0x4
	add     r3, r1, #0x8
	ldr     r1, [r3, #0x4]
	add     r0, r0, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212c9f0:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x14
	mov     r7, r0
	ldr     r0, [r7, #0x60]
	ldr     r4, [r7, #0x194]
	mov     r6, r1
	add     r12, r0, #0x32000
	ldr     r14, [r7, #0x64]
	ldr     r3, [r7, #0x5c]
	add     r1, r7, #0x74
	mov     r0, #0x108
	mov     r5, r2
	str     r3, [r13, #0x8]
	str     r12, [r13, #0x0c]
	str     r14, [r13, #0x10]
	bl      0x02012694
	mov     r2, r6, lsl #0x10
	mov     r0, r4
	add     r3, r13, #0x8
	mov     r1, r7
	str     r5, [r13]
	mov     r4, #0x0
	mov     r2, r2, asr #0x10
	str     r4, [r13, #0x4]
	bl      _ZN6Player11ShowMessageER9ActorBasejRK7Vector3jj
	add     r13, r13, #0x14
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212ca60:
	ldr     r2, [r0, #0x8]
	ldr     r1, =#0x0b26
	mov     r0, #0x1
	mov     r3, r0
	cmp     r2, r1
	beq     LAB_0212ca84
	ldr     r1, =#0x0b27
	cmp     r2, r1
	movne   r3, #0x0
LAB_0212ca84:
	cmp     r3, #0x0
	bxne    r14
	ldr     r1, =#0x0b28
	cmp     r2, r1
	movne   r0, #0x0
	bx      r14
.ltorg)");

asm(R"(
FUN_0212caa8:
	ldrsh   r0, [r0, #0x8c]
	and     r0, r0, #0x0ff
	cmp     r0, #0x3
	moveq   r0, #0x1
	movne   r0, #0x0
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cac0:
	ldrsh   r1, [r0, #0x8c]
	mov     r0, #0x1
	and     r1, r1, #0x0ff
	cmp     r1, #0x1
	bxeq    r14
	cmp     r1, #0x2
	movne   r0, #0x0
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cae0:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x58
	mov     r8, r0
	ldr     r0, [r8, #0x198]
	ldr     r1, =CAMERA
	cmp     r0, #0x0
	ldr     r5, [r1]
	beq     LAB_0212cc80
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	beq     LAB_0212cc80
	mov     r0, #0x0a000
	mov     r6, #0x0
	rsb     r2, r0, #0x0
	mov     r3, #0x80000
	mov     r0, #0x0c8000
	mov     r1, #0x200000
	str     r0, [r13, #0x2c]
	str     r6, [r13, #0x18]
	str     r3, [r13, #0x1c]
	str     r2, [r13, #0x20]
	str     r6, [r13, #0x24]
	str     r6, [r13, #0x30]
	str     r6, [r13, #0x34]
	str     r6, [r13, #0x38]
	str     r1, [r13, #0x28]
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x18
	add     r2, r13, #0x30
	bl      MulVec3Mat4x3
	add     r0, r13, #0x3c
	add     r2, r13, #0x30
	add     r1, r4, #0x5c
	bl      Vec3_Add
	mov     r0, r6
	ldr     r1, [r13, #0x3c]
	str     r0, [r13, #0x30]
	str     r1, [r13, #0x18]
	ldr     r1, [r13, #0x40]
	str     r0, [r13, #0x34]
	str     r1, [r13, #0x1c]
	ldr     r1, [r13, #0x44]
	str     r0, [r13, #0x38]
	str     r1, [r13, #0x20]
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x24
	add     r2, r13, #0x30
	bl      MulVec3Mat4x3
	add     r1, r4, #0x5c
	add     r0, r13, #0x48
	add     r2, r13, #0x30
	bl      Vec3_Add
	ldr     r0, [r13, #0x4c]
	ldr     r1, [r13, #0x48]
	str     r0, [r13, #0x28]
	ldr     r0, [r13, #0x50]
	str     r1, [r13, #0x24]
	add     r2, r5, #0x80
	str     r0, [r13, #0x2c]
	ldr     r0, [r2]
	add     r4, r5, #0x8c
	str     r0, [r13]
	ldr     r1, [r2, #0x4]
	mov     r0, r8
	str     r1, [r13, #0x4]
	ldr     r2, [r2, #0x8]
	add     r1, r13, #0x0
	str     r2, [r13, #0x8]
	ldr     r3, [r4]
	add     r2, r13, #0x18
	str     r3, [r13, #0x0c]
	ldr     r3, [r4, #0x4]
	str     r3, [r13, #0x10]
	ldr     r3, [r4, #0x8]
	str     r3, [r13, #0x14]
	bl      FUN_0212cda0
	mov     r6, r0
	mov     r0, r8
	add     r1, r13, #0x0c
	add     r2, r13, #0x24
	bl      FUN_0212cda0
	mov     r7, r0
	ldrsh   r0, [r8, #0x8c]
	and     r0, r0, #0x0ff
	cmp     r0, #0x2
	bne     LAB_0212cc68
	mov     r6, #0x1
	add     r1, r13, #0x18
	mov     r0, r5
	mov     r7, r6
	bl      _ZN6Camera9SetLookAtERK7Vector3
	add     r1, r13, #0x24
	mov     r0, r5
	bl      _ZN6Camera6SetPosERK7Vector3
	b       LAB_0212cc80
LAB_0212cc68:
	add     r1, r13, #0x0
	mov     r0, r5
	bl      _ZN6Camera9SetLookAtERK7Vector3
	add     r1, r13, #0x0c
	mov     r0, r5
	bl      _ZN6Camera6SetPosERK7Vector3
LAB_0212cc80:
	cmp     r6, #0x0
	beq     LAB_0212cc9c
	cmp     r7, #0x0
	addne   r13, r13, #0x58
	movne   r0, #0x1
	popne   { r4-r8, r14 }
	bxne    r14
LAB_0212cc9c:
	mov     r0, #0x0
	add     r13, r13, #0x58
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212ccb4:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x1c
	ldr     r1, =CAMERA
	mov     r5, r0
	ldr     r4, [r1]
	add     r1, r13, #0x0
	add     r14, r4, #0x80
	ldr     r2, [r14]
	add     r12, r4, #0x8c
	str     r2, [r13]
	ldr     r3, [r14, #0x4]
	add     r2, r5, #0x1cc
	str     r3, [r13, #0x4]
	ldr     r3, [r14, #0x8]
	str     r3, [r13, #0x8]
	ldr     r3, [r12]
	str     r3, [r13, #0x0c]
	ldr     r3, [r12, #0x4]
	str     r3, [r13, #0x10]
	ldr     r3, [r12, #0x8]
	str     r3, [r13, #0x14]
	bl      FUN_0212cda0
	mov     r6, r0
	add     r1, r13, #0x0c
	mov     r0, r5
	add     r2, r5, #0x1d8
	bl      FUN_0212cda0
	ldrsh   r1, [r5, #0x8c]
	mov     r7, r0
	and     r0, r1, #0x0ff
	cmp     r0, #0x2
	bne     LAB_0212cd58
	mov     r6, #0x1
	mov     r0, r4
	add     r1, r5, #0x1cc
	mov     r7, r6
	bl      _ZN6Camera9SetLookAtERK7Vector3
	mov     r0, r4
	add     r1, r5, #0x1d8
	bl      _ZN6Camera6SetPosERK7Vector3
	b       LAB_0212cd70
LAB_0212cd58:
	add     r1, r13, #0x0
	mov     r0, r4
	bl      _ZN6Camera9SetLookAtERK7Vector3
	add     r1, r13, #0x0c
	mov     r0, r4
	bl      _ZN6Camera6SetPosERK7Vector3
LAB_0212cd70:
	cmp     r6, #0x0
	beq     LAB_0212cd8c
	cmp     r7, #0x0
	addne   r13, r13, #0x1c
	movne   r0, #0x1
	popne   { r4-r7, r14 }
	bxne    r14
LAB_0212cd8c:
	mov     r0, #0x0
	add     r13, r13, #0x1c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cda0:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x24
	add     r0, r13, #0x8
	mov     r4, r1
	mov     r7, r2
	bl      Vec3_Sub
	add     r0, r13, #0x8
	bl      LenVec3
	movs    r6, r0
	addeq   r13, r13, #0x24
	moveq   r0, #0x1
	popeq   { r4-r7, r14 }
	bxeq    r14
	str     r6, [r13, #0x4]
	mov     r1, #0x1000
	str     r1, [r13]
	add     r0, r13, #0x4
	mov     r1, #0x0
	mov     r2, #0x400
	mov     r3, #0x100000
	bl      Math_Function_0203b14c
	mov     r5, r0
	ldr     r0, [r13, #0x4]
	mov     r1, r6
	bl      _ZN4cstd4fdivEii
	mov     r1, r0
	add     r0, r13, #0x8
	bl      Vec3_MulScalarInPlace
	add     r0, r13, #0x14
	add     r2, r13, #0x8
	mov     r1, r7
	bl      Vec3_Add
	ldr     r0, [r13, #0x14]
	cmp     r5, #0x0
	str     r0, [r4]
	ldr     r0, [r13, #0x18]
	str     r0, [r4, #0x4]
	ldr     r0, [r13, #0x1c]
	str     r0, [r4, #0x8]
	moveq   r0, #0x1
	movne   r0, #0x0
	add     r13, r13, #0x24
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212ce50:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	ldrsh   r1, [r4, #0x8e]
	add     r0, r4, #0x124
	bl      Matrix4x3_FromRotationY
	ldr     r0, [r4, #0x5c]
	add     r6, r4, #0x19c
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x148]
	ldr     r0, [r4, #0x60]
	ldr     r7, =_ZN9Matrix3x38IDENTITYE
	add     r0, r0, #0x4000
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x14c]
	ldr     r0, [r4, #0x64]
	mov     r5, r6
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x150]
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	mov     r14, #0x32000
	mov     r12, #0x0f
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	mov     r2, r5
	ldr     r1, [r4, #0x5c]
	mov     r0, r4
	mov     r1, r1, asr #0x3
	str     r1, [r4, #0x1c0]
	ldr     r3, [r4, #0x60]
	add     r1, r4, #0x16c
	sub     r3, r3, #0x8000
	mov     r3, r3, asr #0x3
	str     r3, [r4, #0x1c4]
	ldr     r5, [r4, #0x64]
	mov     r3, #0x64000
	mov     r5, r5, asr #0x3
	str     r5, [r4, #0x1c8]
	str     r14, [r13]
	str     r12, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r13, r13, #0x0c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cf10:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN11BobOmbBuddy9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN11BobOmbBuddy8animFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cf40:
	push    { r14 }
	sub     r13, r13, #0x4
	add     r0, r0, #0x108
	ldr     r2, [r0]
	mov     r1, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212cf6c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	bl      FUN_0212c9a8
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_0212cfd8
	add     r3, r0, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	add     r0, r4, #0x5c
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzDist
	cmp     r0, #0x12c000
	bge     LAB_0212cfd8
	add     r1, r13, #0x0
	add     r0, r4, #0x5c
	bl      Vec3_HorzAngle
	mov     r1, r0
	add     r0, r4, #0x8e
	mov     r2, #0x100
	bl      _Z14ApproachLinearRsss
LAB_0212cfd8:
	add     r0, r4, #0x158
	bl      _ZN9Animation7AdvanceEv
	ldr     r0, [r4, #0x160]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_0212d000
	add     r1, r4, #0x74
	mov     r0, #0x0d7
	bl      0x02012694
LAB_0212d000:
	mov     r0, r4
	bl      FUN_0212ce50
	add     r0, r4, #0x0d4
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x0d4
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212d028:
	push    { r4, r14 }
	sub     r13, r13, #0x68
	mov     r4, r0
	ldr     r0, =_ZN11BobOmbBuddy9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x108
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	add     r0, r4, #0x16c
	bl      _ZN11ShadowModel12InitCylinderEv
	ldr     r0, =_ZN11BobOmbBuddy8animFileE
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r1, =#0x4200004
	mov     r2, #0x8c000
	str     r1, [r13]
	mov     r0, #0x0
	str     r0, [r13, #0x4]
	add     r0, r4, #0x0d4
	mov     r1, r4
	mov     r3, r2
	bl      _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj
	mov     r0, r4
	mov     r1, #0x0
	bl      FUN_0212c960
	mov     r0, #0x0
	str     r0, [r4, #0x198]
	ldr     r1, [r4, #0x60]
	ldr     r2, [r4, #0x64]
	ldr     r0, [r4, #0x5c]
	add     r1, r1, #0x64000
	str     r0, [r13, #0x8]
	add     r0, r13, #0x14
	str     r1, [r13, #0x0c]
	str     r2, [r13, #0x10]
	bl      _ZN13RaycastGroundC1Ev
	add     r0, r13, #0x14
	add     r1, r13, #0x8
	mov     r2, #0x0
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x14
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	ldrne   r0, [r13, #0x58]
	strne   r0, [r4, #0x60]
	mov     r0, r4
	bl      FUN_0212ca60
	cmp     r0, #0x0
	beq     LAB_0212d168
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	ldrb    r2, [r0, #0x6d9]
	cmp     r2, #0x0
	bne     LAB_0212d114
	ldr     r1, [r4, #0x8]
	ldr     r0, =#0x0b26
	cmp     r1, r0
	beq     LAB_0212d150
LAB_0212d114:
	cmp     r2, #0x1
	bne     LAB_0212d12c
	ldr     r1, [r4, #0x8]
	ldr     r0, =#0x0b27
	cmp     r1, r0
	beq     LAB_0212d150
LAB_0212d12c:
	cmp     r2, #0x2
	bne     LAB_0212d144
	ldr     r1, [r4, #0x8]
	ldr     r0, =#0x0b28
	cmp     r1, r0
	beq     LAB_0212d150
LAB_0212d144:
	bl      0x02013b18
	cmp     r0, #0x0
	beq     LAB_0212d168
LAB_0212d150:
	add     r0, r13, #0x14
	bl      _ZN13RaycastGroundD1Ev
	add     r13, r13, #0x68
	mov     r0, #0x0
	pop     { r4, r14 }
	bx      r14
LAB_0212d168:
	mov     r0, r4
	bl      FUN_0212cac0
	cmp     r0, #0x0
	beq     LAB_0212d1c8
	ldr     r0, =LEVEL_ID
	ldrsb   r0, [r0]
	cmp     r0, #0x8
	bne     LAB_0212d1c8
	ldr     r0, =STAR_ID
	ldrb    r0, [r0]
	cmp     r0, #0x1
	beq     LAB_0212d1b0
	mov     r0, #0x8
	bl      SublevelToLevel
	mov     r1, #0x1
	bl      IsStarCollected
	cmp     r0, #0x0
	bne     LAB_0212d1c8
LAB_0212d1b0:
	add     r0, r13, #0x14
	bl      _ZN13RaycastGroundD1Ev
	add     r13, r13, #0x68
	mov     r0, #0x0
	pop     { r4, r14 }
	bx      r14
LAB_0212d1c8:
	add     r0, r13, #0x14
	bl      _ZN13RaycastGroundD1Ev
	mov     r0, #0x1
	add     r13, r13, #0x68
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0212d200:
	push    { r4, r14 }
	mov     r0, #0x1f0
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_0212d238
	bl      _ZN5ActorC2Ev
	ldr     r1, =VTable_BobOmbBuddy
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN18MovingCylinderClsnC1Ev
	add     r0, r4, #0x108
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x16c
	bl      _ZN11ShadowModelC1Ev
LAB_0212d238:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");