#include "SM64DS_2.h"
#include "Actors/ChainChomp.h"
#include "Actors/ChainChompFence.h"

extern "C"
{
	ActorBase* FUN_02112d1c(); // constructor
	
	// state function declarations for use below
	void FUN_02111e74(ChainChomp* chainChomp);
	void FUN_02111e14(ChainChomp* chainChomp);
	void FUN_02111dc4(ChainChomp* chainChomp);
	void FUN_02111ca8(ChainChomp* chainChomp);
	void FUN_02111b70(ChainChomp* chainChomp);
	void FUN_02111af0(ChainChomp* chainChomp);
	void FUN_02111a6c(ChainChomp* chainChomp);
	void FUN_021115ec(ChainChomp* chainChomp);
	void FUN_021115c0(ChainChomp* chainChomp);
	void FUN_0211150c(ChainChomp* chainChomp);
	void FUN_021114d8(ChainChomp* chainChomp);
	void FUN_02111484(ChainChomp* chainChomp);
	
	// undocumented globals not in ov14:
	// 0x020072c0
	// 0x0203d384
	
	// undocumented functions not in ov14:
	// 0x0214ae1c (ov102, member function?)
	
	Vector3 CYLINDER_CLSN_OFFSET = { 0._f, -200._f, 0._f }; // 0x02114700
	
	using StateFunc = void(*)(ChainChomp*);
	
	struct State
	{
		StateFunc func1;
		u32 unk04 = 0;
		StateFunc func2;
		u32 unk0c = 0;
		char* stateName = nullptr; // why? "WAIT", "WALK", "ATTACK", "ESCAPE_DEMO", "BOMB_DAMAGE", "GIANT_DAMAGE"
	};
	
	State states[6] = // 0x0211476c
	{
		{ &FUN_02111e74, 0, &FUN_02111e14, 0 },
		{ &FUN_02111dc4, 0, &FUN_02111ca8, 0 },
		{ &FUN_02111b70, 0, &FUN_02111af0, 0 },
		{ &FUN_02111a6c, 0, &FUN_021115ec, 0 },
		{ &FUN_021115c0, 0, &FUN_0211150c, 0 },
		{ &FUN_021114d8, 0, &FUN_02111484, 0 },
	};
}

SharedFilePtr ChainChomp::modelFile;
SharedFilePtr ChainChomp::chainModelFile;
SharedFilePtr ChainChomp::animFiles[ChainChomp::NUM_ANIMS];

SpawnInfo ChainChomp::spawnData = 
{
	&FUN_02112d1c,
	0x00db,
	0x0043,
	Actor::NO_BEHAVIOR_IF_OFF_SCREEN | Actor::NO_RENDER_IF_OFF_SCREEN | Actor::AIMABLE_BY_EGG,
	288._f,
	1024._f,
	4096._f,
	4096._f,
};

asm(R"(
@ 0x021147ec
VTable_ChainChomp:
	.word FUN_02112b14
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_0211294c
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_021129ec
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02112994
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02111308
	.word FUN_021113bc
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
FUN_02111308:
	push    { r4, r14 }
	ldr     r1, =#0x578
	mov     r4, r0
	ldr     r12, =VTable_ChainChomp
	ldr     r3, =#0x20072c0
	add     r0, r4, r1
	mov     r1, #0x7
	mov     r2, #0x0c
	str     r12, [r4]
	bl      0x0207328c
	ldr     r0, =#0x524
	ldr     r3, =#0x20072c0
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x0c
	bl      0x0207328c
	ldr     r0, =#0x40c
	ldr     r3, =_ZN11ShadowModelD1Ev
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x28
	bl      0x0207328c
	add     r0, r4, #0x1dc
	mov     r1, #0x7
	mov     r2, #0x50
	ldr     r3, =_ZN5ModelD1Ev
	bl      0x0207328c
	add     r0, r4, #0x1b4
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x150
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x110
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021113bc:
	push    { r4, r14 }
	ldr     r1, =#0x578
	mov     r4, r0
	ldr     r12, =VTable_ChainChomp
	ldr     r3, =#0x20072c0
	add     r0, r4, r1
	mov     r1, #0x7
	mov     r2, #0x0c
	str     r12, [r4]
	bl      0x0207328c
	ldr     r0, =#0x524
	ldr     r3, =#0x20072c0
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x0c
	bl      0x0207328c
	ldr     r0, =#0x40c
	ldr     r3, =_ZN11ShadowModelD1Ev
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x28
	bl      0x0207328c
	add     r0, r4, #0x1dc
	mov     r1, #0x7
	mov     r2, #0x50
	ldr     r3, =_ZN5ModelD1Ev
	bl      0x0207328c
	add     r0, r4, #0x1b4
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x150
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x110
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	ldr     r1, =_ZN6Memory11gameHeapPtrE
	ldr     r1, [r1]
	bl      _ZN6Memory10DeallocateEPvP4Heap
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111484:
	push    { r4, r14 }
	ldr     r1, =#0x5fc
	mov     r4, r0
	add     r0, r4, r1
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	bne     LAB_021114ac
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_02111ebc
LAB_021114ac:
	ldrb    r0, [r4, #0x61c]
	mov     r1, #0x0
	mov     r2, #0x2000
	cmp     r0, #0x0
	ldrne   r0, [r4, #0x98]
	strne   r0, [r4, #0x0a8]
	add     r0, r4, #0x98
	bl      _Z14ApproachLinearRiii
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021114d8:
	ldrsh   r3, [r0, #0x94]
	mov     r2, #0x0a000
	add     r1, r0, #0x500
	strh    r3, [r0, #0x8e]
	mov     r3, #0x3c
	strh    r3, [r1, #0x0fc]
	mov     r1, #0x64000
	str     r1, [r0, #0x98]
	mov     r1, #0x0c8000
	str     r1, [r0, #0x0a8]
	rsb     r1, r2, #0x0
	str     r1, [r0, #0x9c]
	bx      r14
.ltorg)");

asm(R"(
FUN_0211150c:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	add     r0, r4, #0x80
	mov     r1, #0x1000
	mov     r2, #0x500
	bl      _Z14ApproachLinearRiii
	ldr     r0, [r4, #0x80]
	mov     r1, #0x4000
	str     r0, [r4, #0x88]
	ldr     r2, [r4, #0x88]
	add     r0, r4, #0x8c
	str     r2, [r4, #0x84]
	mov     r12, #0x400
	rsb     r1, r1, #0x0
	mov     r2, #0x4
	mov     r3, #0x1000
	str     r12, [r13]
	bl      ApproachAngle
	ldr     r0, =#0x5f8
	mov     r2, #0x800
	add     r0, r4, r0
	mov     r1, #0x64000
	mov     r3, #0x10000
	str     r2, [r13]
	bl      Math_Function_0203b14c
	cmp     r0, #0x0
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	ldr     r0, =#0x5fc
	add     r0, r4, r0
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_02111ebc
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021115c0:
	push    { r4, r14 }
	mov     r4, r0
	add     r1, r4, #0x74
	mov     r0, #0x3a
	bl      0x0201267c
	mov     r0, #0x12c000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x0
	str     r0, [r4, #0x9c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021115ec:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x20
	ldr     r1, =#0x5fe
	mov     r5, r0
	add     r1, r5, r1
	bl      _ZN5Sound15PlaySecretSoundEP5ActorPt
	ldr     r0, [r5, #0x60c]
	bl      _ZN5Actor10FindWithIDEj
	mov     r4, r0
	add     r2, r4, #0x5c
	ldr     r1, [r2]
	mov     r3, #0x80
	str     r1, [r13, #0x4]
	ldr     r1, [r2, #0x4]
	add     r0, r5, #0x8c
	str     r1, [r13, #0x8]
	ldr     r2, [r2, #0x8]
	mov     r1, #0x0
	str     r2, [r13, #0x0c]
	str     r3, [r13]
	mov     r2, #0x4
	mov     r3, #0x200
	bl      ApproachAngle
	ldr     r1, =CAMERA
	mov     r0, r5
	ldr     r8, [r1]
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	ldr     r1, =#0x5ec
	mov     r7, r0
	add     r0, r5, #0x5c
	add     r1, r5, r1
	bl      Vec3_HorzAngle
	mov     r6, r0
	ldrb    r0, [r5, #0x604]
	cmp     r0, #0x9
	addls   r15, r15, r0, lsl #0x2
	b       LAB_02111a34
	b       LAB_021116a8
	b       LAB_021116f4
	b       LAB_021116f4
	b       LAB_021116f4
	b       LAB_021116f4
	b       LAB_0211174c
	b       LAB_021117b0
	b       LAB_02111914
	b       LAB_021119a8
	b       LAB_02111a18
LAB_021116a8:
	mov     r1, r7
	add     r0, r5, #0x8e
	mov     r2, #0x320
	str     r5, [r8, #0x118]
	bl      _Z14ApproachLinearRsss
	cmp     r0, #0x0
	beq     LAB_021116e8
	ldr     r0, =#0x5fc
	add     r0, r5, r0
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	ldreq   r0, =#0x604
	addeq   r1, r5, r0
	ldreqb  r0, [r1]
	addeq   r0, r0, #0x1
	streqb  r0, [r1]
LAB_021116e8:
	ldrsh   r0, [r5, #0x8e]
	strh    r0, [r5, #0x94]
	b       LAB_02111a34
LAB_021116f4:
	str     r5, [r8, #0x118]
	add     r0, r5, #0x98
	mov     r1, #0x0
	mov     r2, #0x400
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r5, #0x61c]
	cmp     r0, #0x0
	beq     LAB_02111a34
	add     r0, r6, #0x2000
	strh    r0, [r5, #0x94]
	ldrsh   r2, [r5, #0x94]
	ldr     r0, =#0x604
	mov     r1, #0x32000
	strh    r2, [r5, #0x8e]
	str     r1, [r5, #0x0a8]
	mov     r1, #0x1e000
	str     r1, [r5, #0x98]
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02111a34
LAB_0211174c:
	str     r5, [r8, #0x118]
	add     r0, r5, #0x98
	mov     r1, #0x0
	mov     r2, #0x400
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r5, #0x61c]
	cmp     r0, #0x0
	beq     LAB_02111a34
	strh    r6, [r5, #0x94]
	ldrsh   r2, [r5, #0x94]
	ldr     r0, =#0x604
	mov     r1, #0x32000
	strh    r2, [r5, #0x8e]
	str     r1, [r5, #0x0a8]
	mov     r1, #0x1e000
	str     r1, [r5, #0x98]
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r4, #0x31e]
	cmp     r0, #0x0
	movne   r0, #0x7
	strneb  r0, [r5, #0x604]
	b       LAB_02111a34
LAB_021117b0:
	ldr     r0, =#0x618
	str     r5, [r8, #0x118]
	add     r0, r5, r0
	mov     r1, #0x1000
	mov     r2, #0x400
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r5, #0x61c]
	cmp     r0, #0x0
	beq     LAB_02111818
	mov     r2, #0x0
	ldr     r0, =_ZN10ChainChomp9animFilesE + 0
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r5, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r1, r13, #0x4
	add     r0, r5, #0x5c
	bl      Vec3_HorzAngle
	strh    r0, [r5, #0x8e]
	ldrsh   r2, [r5, #0x8e]
	mov     r1, #0x14000
	mov     r0, #0x64000
	strh    r2, [r5, #0x94]
	str     r1, [r5, #0x0a8]
	str     r0, [r5, #0x618]
LAB_02111818:
	ldr     r0, [r13, #0x4]
	ldr     r3, [r13, #0x0c]
	ldr     r1, [r13, #0x8]
	str     r0, [r13, #0x10]
	str     r3, [r13, #0x18]
	str     r1, [r13, #0x14]
	ldrh    r1, [r4, #0x8e]
	ldr     r2, =SINE_TABLE
	mov     r8, #0x0
	mov     r1, r1, asr #0x4
	mov     r1, r1, lsl #0x2
	ldrsh   r1, [r2, r1]
	mov     r6, #0x96000
	mov     r7, #0x800
	umull   r14, r12, r1, r6
	mla     r12, r1, r8, r12
	mov     r1, r1, asr #0x1f
	mla     r12, r1, r6, r12
	adds    r14, r14, r7
	adc     r1, r12, #0x0
	mov     r12, r14, lsr #0x0c
	orr     r12, r12, r1, lsl #0x14
	add     r0, r0, r12
	str     r0, [r13, #0x10]
	ldrh    r12, [r4, #0x8e]
	add     r1, r13, #0x10
	add     r0, r5, #0x5c
	mov     r12, r12, asr #0x4
	mov     r12, r12, lsl #0x1
	add     r12, r12, #0x1
	mov     r12, r12, lsl #0x1
	ldrsh   r2, [r2, r12]
	umull   r14, r12, r2, r6
	mla     r12, r2, r8, r12
	mov     r2, r2, asr #0x1f
	mla     r12, r2, r6, r12
	adds    r7, r14, r7
	adc     r2, r12, #0x0
	mov     r6, r7, lsr #0x0c
	orr     r6, r6, r2, lsl #0x14
	add     r2, r3, r6
	str     r2, [r13, #0x18]
	ldr     r2, [r5, #0x618]
	bl      0x0203b7dc
	cmp     r0, #0x0
	beq     LAB_02111a34
	ldr     r0, =#0x604
	add     r1, r13, #0x4
	add     r3, r5, r0
	ldrb    r2, [r3]
	add     r0, r5, #0x5c
	add     r2, r2, #0x1
	strb    r2, [r3]
	bl      Vec3_HorzAngle
	add     r0, r0, #0x8000
	strh    r0, [r5, #0x94]
	mov     r1, #0x28000
	str     r1, [r5, #0x98]
	mov     r1, #0x0a000
	mov     r0, r4
	str     r1, [r5, #0x0a8]
	bl      _ZN15ChainChompFence16KillByChainChompEv
	b       LAB_02111a34
LAB_02111914:
	ldrb    r0, [r5, #0x61c]
	cmp     r0, #0x0
	beq     LAB_02111a34
	mov     r2, #0x0
	ldr     r0, =_ZN10ChainChomp9animFilesE + 8
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r5, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r1, r13, #0x4
	add     r0, r5, #0x5c
	bl      Vec3_HorzAngle
	strh    r0, [r5, #0x94]
	add     r0, r5, #0x500
	mov     r1, #0x3c
	strh    r1, [r0, #0x0fc]
	ldrsh   r0, [r5, #0x94]
	strh    r0, [r5, #0x8e]
	ldrb    r0, [r4, #0x31e]
	cmp     r0, #0x0
	movne   r0, #0x28000
	strne   r0, [r5, #0x98]
	movne   r0, #0x5a000
	strne   r0, [r5, #0x0a8]
	moveq   r0, #0x1e000
	streq   r0, [r5, #0x98]
	moveq   r0, #0x50000
	streq   r0, [r5, #0x0a8]
	mov     r0, r8
	bl      _ZN6Camera9SetFlag_3Ev
	ldr     r0, =#0x604
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02111a34
LAB_021119a8:
	ldr     r0, =#0x5fc
	add     r0, r5, r0
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	bne     LAB_02111a08
	add     r2, r8, #0x154
	ldr     r1, [r2]
	mov     r0, r5
	bic     r1, r1, #0x8
	str     r1, [r2]
	bl      _ZN5Actor13ClosestPlayerEv
	mov     r1, #0x4
	bl      0x020ca150
	cmp     r0, #0x0
	beq     LAB_02111a34
	ldr     r0, =#0x604
	add     r1, r5, #0x500
	add     r3, r5, r0
	ldrb    r2, [r3]
	mov     r0, #0x3c
	add     r2, r2, #0x1
	strb    r2, [r3]
	strh    r0, [r1, #0x0fc]
	b       LAB_02111a34
LAB_02111a08:
	mov     r0, r8
	add     r1, r5, #0x5c
	bl      _ZN6Camera9SetLookAtERK7Vector3
	b       LAB_02111a34
LAB_02111a18:
	ldr     r0, =#0x5fc
	add     r0, r5, r0
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	bne     LAB_02111a34
	mov     r0, r5
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02111a34:
	add     r0, r5, #0x1a0
	bl      _ZN9Animation7AdvanceEv
	add     r13, r13, #0x20
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111a6c:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r2, #0x0
	ldr     r1, =_ZN10ChainChomp9animFilesE + 8
	str     r2, [r13]
	mov     r4, r0
	ldr     r1, [r1, #0x4]
	add     r0, r4, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r1, #0x0
	str     r1, [r4, #0x0a8]
	mov     r0, #0x2000
	str     r1, [r4, #0x98]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	strb    r1, [r4, #0x604]
	add     r0, r4, #0x600
	strh    r1, [r0]
	add     r0, r4, #0x500
	mov     r1, #0x3c
	strh    r1, [r0, #0x0fc]
	add     r1, r4, #0x0b0
	ldr     r0, [r1]
	bic     r0, r0, #0x3
	str     r0, [r1]
	ldr     r0, [r4, #0x5f0]
	add     r0, r0, #0x0c8000
	str     r0, [r4, #0x60]
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111af0:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	bl      FUN_02111f54
	cmp     r0, #0x0
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	ldr     r0, =#0x5f8
	mov     r2, #0x800
	add     r0, r4, r0
	mov     r1, #0x64000
	mov     r3, #0x10000
	str     r2, [r13]
	bl      Math_Function_0203b14c
	cmp     r0, #0x0
	bne     LAB_02111b54
	ldr     r0, =#0x5fc
	add     r0, r4, r0
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	bne     LAB_02111b54
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_02111ebc
LAB_02111b54:
	add     r0, r4, #0x1a0
	bl      _ZN9Animation7AdvanceEv
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111b70:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	mov     r2, #0x0
	add     r1, r4, #0x74
	mov     r0, #0x3a
	str     r2, [r4, #0x9c]
	bl      0x0201267c
	mov     r2, #0x0
	ldr     r0, =_ZN10ChainChomp9animFilesE + 0
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	ldr     r1, [r0, #0x60]
	ldr     r3, [r0, #0x64]
	ldr     r0, [r0, #0x5c]
	add     r2, r1, #0x50000
	str     r0, [r13, #0x4]
	add     r1, r13, #0x4
	add     r0, r4, #0x5c
	str     r2, [r13, #0x8]
	str     r3, [r13, #0x0c]
	bl      Vec3_VertAngle
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x1
	ldr     r1, =SINE_TABLE
	mov     r2, r0, lsl #0x1
	ldrsh   r14, [r1, r2]
	mov     r1, #0x8c000
	mov     r3, #0x0
	umull   r6, r5, r14, r1
	mov     r2, #0x800
	adds    r2, r6, r2
	mla     r5, r14, r3, r5
	mov     r12, r14, asr #0x1f
	mla     r5, r12, r1, r5
	adc     r1, r5, #0x0
	mov     r2, r2, lsr #0x0c
	orr     r2, r2, r1, lsl #0x14
	rsb     r1, r2, #0x0
	str     r1, [r4, #0x0a8]
	ldr     r2, [r4, #0x0a8]
	cmp     r2, #0x5000
	movlt   r2, #0x5000
	blt     LAB_02111c44
	cmp     r2, #0x2d000
	movgt   r2, #0x2d000
LAB_02111c44:
	add     r1, r0, #0x1
	ldr     r0, =SINE_TABLE
	str     r2, [r4, #0x0a8]
	mov     r1, r1, lsl #0x1
	ldrsh   r2, [r0, r1]
	mov     r0, #0x8c000
	mov     r1, #0x0
	umull   r12, r3, r2, r0
	mla     r3, r2, r1, r3
	mov     r2, r2, asr #0x1f
	mov     r1, #0x800
	adds    r1, r12, r1
	mla     r3, r2, r0, r3
	adc     r0, r3, #0x0
	mov     r1, r1, lsr #0x0c
	orr     r1, r1, r0, lsl #0x14
	str     r1, [r4, #0x98]
	add     r0, r4, #0x500
	mov     r1, #0x3c
	strh    r1, [r0, #0x0fc]
	add     r13, r13, #0x10
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111ca8:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r4, r0
	bl      FUN_02111f54
	cmp     r0, #0x0
	addne   r13, r13, #0x4
	popne   { r4, r5, r14 }
	bxne    r14
	mov     r5, #0x80
	add     r0, r4, #0x8c
	mov     r1, #0x0
	mov     r2, #0x4
	mov     r3, #0x200
	str     r5, [r13]
	bl      ApproachAngle
	ldr     r0, =#0x5fc
	add     r0, r4, r0
	bl      DecIfAbove0_Short
	ldr     r0, =#0x5f8
	mov     r1, #0x50000
	add     r0, r4, r0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	add     r0, r4, #0x600
	ldrsh   r1, [r0, #0x2]
	add     r0, r4, #0x8e
	mov     r2, #0x190
	bl      _Z14ApproachLinearRsss
	add     r0, r4, #0x98
	mov     r1, #0x0
	mov     r2, #0x400
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r4, #0x61c]
	cmp     r0, #0x0
	beq     LAB_02111da8
	mov     r0, r4
	bl      _ZN5Actor13DistToCPlayerEv
	mov     r5, r0
	mov     r0, r4
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	add     r1, r4, #0x600
	strh    r0, [r1, #0x2]
	ldrsh   r3, [r4, #0x8e]
	mov     r2, #0x0a000
	mov     r0, #0x14000
	strh    r3, [r4, #0x94]
	str     r2, [r4, #0x98]
	str     r0, [r4, #0x0a8]
	mov     r0, #0x0
	strh    r0, [r1]
	cmp     r5, #0x500000
	bge     LAB_02111da8
	ldrsh   r0, [r1, #0x2]
	ldrsh   r1, [r4, #0x8e]
	bl      AngleDiff
	cmp     r0, #0x800
	bge     LAB_02111da8
	add     r0, r4, #0x500
	ldrh    r0, [r0, #0x0fc]
	cmp     r0, #0x0
	bne     LAB_02111da8
	mov     r0, r4
	mov     r1, #0x2
	bl      FUN_02111ebc
LAB_02111da8:
	add     r0, r4, #0x1a0
	bl      _ZN9Animation7AdvanceEv
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111dc4:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	mov     r1, #0x2000
	str     r2, [r0, #0x0a8]
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x9c]
	add     r1, r0, #0x500
	mov     r3, #0x78
	strh    r3, [r1, #0x0fc]
	ldr     r1, =_ZN10ChainChomp9animFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111e14:
	push    { r4, r14 }
	mov     r4, r0
	mov     r0, #0x0
	str     r0, [r4, #0x0a8]
	add     r0, r4, #0x80
	mov     r1, #0x1000
	mov     r2, #0x500
	bl      _Z14ApproachLinearRiii
	ldr     r1, [r4, #0x80]
	ldr     r0, =#0x5fc
	str     r1, [r4, #0x88]
	ldr     r1, [r4, #0x88]
	add     r0, r4, r0
	str     r1, [r4, #0x84]
	bl      DecIfAbove0_Short
	cmp     r0, #0x0
	popne   { r4, r14 }
	bxne    r14
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_02111ebc
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111e74:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	str     r2, [r0, #0x0a8]
	str     r2, [r0, #0x98]
	add     r1, r0, #0x500
	mov     r3, #0x78
	strh    r3, [r1, #0x0fc]
	ldr     r1, =_ZN10ChainChomp9animFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x150
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111ebc:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x610]
	ldr     r2, [r0, #0x610]
	ldr     r3, =states
	mov     r1, #0x14
	mla     r3, r2, r1, r3
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
FUN_02111f08:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r2, [r0, #0x610]
	ldr     r3, =states
	mov     r1, #0x14
	mla     r1, r2, r1, r3
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
FUN_02111f54:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x608]
	bl      _ZN5Actor10FindWithIDEj
	ldrb    r0, [r0, #0x31e]
	cmp     r0, #0x0
	bne     LAB_02111fac
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	mov     r1, #0x4
	mvn     r2, #0x0
	mov     r3, #0x0
	bl      0x020ca1b8
	cmp     r0, #0x0
	beq     LAB_02111fac
	mov     r0, r4
	mov     r1, #0x3
	bl      FUN_02111ebc
	mov     r0, #0x1
	strb    r0, [r4, #0x605]
	pop     { r4, r14 }
	bx      r14
LAB_02111fac:
	mov     r0, #0x0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111fb8:
	push    { r4, r14 }
	mov     r4, r0
	add     r1, r4, #0x74
	mov     r0, #0x39
	bl      0x0201267c
	mov     r0, r4
	mov     r1, #0x1
	bl      _ZN5Actor14BigLandingDustEb
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111fe0:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x18
	ldr     r2, =#0x5ec
	mov     r6, r0
	add     r0, r13, #0x0
	add     r1, r6, #0x5c
	add     r2, r6, r2
	bl      Vec3_Sub
	add     r0, r13, #0x0
	bl      LenVec3
	ldr     r2, [r6, #0x5f8]
	mov     r1, #0x7
	mul     r1, r2, r1
	mov     r4, r0
	add     r5, r1, #0x0c8000
	cmp     r4, r5
	addle   r13, r13, #0x18
	pople   { r4-r6, r14 }
	bxle    r14
	mov     r0, r5
	mov     r1, r4
	bl      _ZN4cstd4fdivEii
	ldr     r2, [r13]
	mov     r1, #0x800
	smull   r3, r0, r2, r0
	adds    r1, r3, r1
	mov     r2, r1, lsr #0x0c
	adc     r0, r0, #0x0
	orr     r2, r2, r0, lsl #0x14
	mov     r0, r5
	mov     r1, r4
	str     r2, [r13]
	bl      _ZN4cstd4fdivEii
	ldr     r2, [r13, #0x4]
	mov     r1, #0x800
	smull   r3, r0, r2, r0
	adds    r1, r3, r1
	mov     r2, r1, lsr #0x0c
	adc     r0, r0, #0x0
	orr     r2, r2, r0, lsl #0x14
	mov     r0, r5
	mov     r1, r4
	str     r2, [r13, #0x4]
	bl      _ZN4cstd4fdivEii
	ldr     r2, [r13, #0x8]
	ldr     r1, =#0x5ec
	smull   r4, r3, r2, r0
	mov     r0, #0x800
	adds    r2, r4, r0
	adc     r0, r3, #0x0
	mov     r2, r2, lsr #0x0c
	orr     r2, r2, r0, lsl #0x14
	str     r2, [r13, #0x8]
	add     r1, r6, r1
	add     r0, r13, #0x0c
	add     r2, r13, #0x0
	bl      Vec3_Add
	ldr     r0, [r13, #0x0c]
	str     r0, [r6, #0x5c]
	ldr     r0, [r13, #0x10]
	str     r0, [r6, #0x60]
	ldr     r0, [r13, #0x14]
	str     r0, [r6, #0x64]
	ldr     r0, [r6, #0x610]
	cmp     r0, #0x2
	addne   r13, r13, #0x18
	popne   { r4-r6, r14 }
	bxne    r14
	ldr     r0, [r6, #0x5f8]
	cmp     r0, #0x64000
	moveq   r0, #0x0
	streq   r0, [r6, #0x98]
	streq   r0, [r6, #0x0a8]
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112114:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x18
	mov     r5, r0
	ldr     r0, [r5, #0x610]
	sub     r0, r0, #0x3
	cmp     r0, #0x1
	addls   r13, r13, #0x18
	popls   { r4-r6, r14 }
	bxls    r14
	ldr     r0, [r5, #0x134]
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4-r6, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	addeq   r13, r13, #0x18
	popeq   { r4-r6, r14 }
	bxeq    r14
	ldrh    r1, [r4, #0x0c]
	cmp     r1, #0x9
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_021121b4
	ldr     r0, [r5, #0x130]
	ands    r0, r0, #0x2000
	beq     LAB_021121b4
	mov     r0, #0x2000
	str     r0, [r5, #0x80]
	ldr     r1, [r5, #0x80]
	mov     r0, r5
	str     r1, [r5, #0x84]
	ldr     r2, [r5, #0x84]
	mov     r1, #0x0
	str     r2, [r5, #0x88]
	bl      FUN_02111ebc
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
LAB_021121b4:
	ldr     r0, [r5, #0x130]
	ands    r0, r0, #0x4000
	beq     LAB_021121f0
	mov     r0, #0x2000
	str     r0, [r5, #0x80]
	ldr     r1, [r5, #0x80]
	mov     r0, r5
	str     r1, [r5, #0x84]
	ldr     r2, [r5, #0x84]
	mov     r1, #0x4
	str     r2, [r5, #0x88]
	bl      FUN_02111ebc
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
LAB_021121f0:
	cmp     r1, #0x0bf
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02112288
	add     r0, r5, #0x5c
	add     r1, r4, #0x5c
	bl      Vec3_HorzAngle
	ldr     r1, [r5, #0x130]
	mov     r6, r0
	ands    r0, r1, #0x10
	beq     LAB_02112234
	mov     r0, r5
	mov     r1, #0x5
	bl      FUN_02111ebc
	ldrsh   r0, [r4, #0x8e]
	strh    r0, [r5, #0x94]
LAB_02112234:
	ldrsh   r1, [r5, #0x8e]
	mov     r0, r6
	bl      AngleDiff
	cmp     r0, #0x4000
	bge     LAB_02112288
	ldr     r0, [r5, #0x5c]
	mov     r12, #0x1
	str     r0, [r13, #0x0c]
	ldr     r1, [r5, #0x60]
	mov     r0, #0x0
	str     r1, [r13, #0x10]
	ldr     r2, [r5, #0x64]
	add     r1, r13, #0x0c
	str     r2, [r13, #0x14]
	str     r12, [r13]
	str     r0, [r13, #0x4]
	mov     r0, r4
	mov     r2, #0x3
	mov     r3, #0x0c000
	str     r12, [r13, #0x8]
	bl      _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj
LAB_02112288:
	ldr     r0, [r5, #0x610]
	cmp     r0, #0x4
	addeq   r13, r13, #0x18
	popeq   { r4-r6, r14 }
	bxeq    r14
	ldrh    r0, [r4, #0x0c]
	cmp     r0, #0x0ce
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r0, r4
	bl      0x0214ae1c
	mov     r0, r5
	mov     r1, #0x4
	bl      FUN_02111ebc
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021122dc:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x18
	ldr     r2, =#0x524
	mov     r4, r0
	add     r0, r13, #0x0
	add     r1, r4, #0x5c
	add     r2, r4, r2
	bl      Vec3_Sub
	ldr     r0, =#0x524
	ldr     r8, =#0x92492493
	add     r7, r4, r0
	mov     r6, #0x0
	add     r5, r13, #0x0c
	add     r4, r13, #0x0
LAB_02112314:
	rsb     r1, r6, #0x7
	smull   r0, r2, r8, r1
	add     r2, r1, r2
	mov     r2, r2, asr #0x2
	mov     r3, r1, lsr #0x1f
	mov     r0, r5
	mov     r1, r4
	add     r2, r3, r2
	bl      Vec3_MulScalar
	mov     r0, r7
	mov     r1, r5
	mov     r2, r7
	bl      AddVec3
	add     r6, r6, #0x1
	cmp     r6, #0x7
	add     r7, r7, #0x0c
	blt     LAB_02112314
	add     r13, r13, #0x18
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211236c:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x6c
	ldr     r1, [r0, #0x5f8]
	mov     r5, #0x0
	str     r5, [r13, #0x0c]
	str     r5, [r13, #0x10]
	str     r1, [r13, #0x14]
	str     r5, [r13, #0x18]
	str     r5, [r13, #0x1c]
	str     r5, [r13, #0x20]
	ldr     r2, [r0, #0x5ec]
	ldr     r1, =#0x56c
	str     r2, [r13, #0x30]
	ldr     r3, [r0, #0x5f0]
	add     r4, r0, r1
	str     r3, [r13, #0x34]
	ldr     r2, [r0, #0x5f4]
	add     r1, r3, #0x1e000
	str     r2, [r13, #0x38]
	str     r1, [r13, #0x34]
	ldr     r0, [r0, #0x5f8]
	mov     r10, #0x6
	str     r5, [r13, #0x0c]
	str     r5, [r13, #0x10]
	str     r0, [r13, #0x14]
	str     r5, [r13, #0x18]
	str     r5, [r13, #0x1c]
	str     r5, [r13, #0x20]
	add     r11, r13, #0x30
	ldr     r8, =MATRIX_SCRATCH_PAPER
	add     r7, r13, #0x18
	add     r6, r13, #0x54
LAB_021123ec:
	cmp     r10, #0x6
	moveq   r5, r11
	addne   r5, r4, #0x0c
	add     r0, r13, #0x3c
	mov     r1, r4
	mov     r2, r5
	bl      Vec3_Sub
	ldr     r1, [r13, #0x40]
	ldr     r0, [r13, #0x3c]
	str     r1, [r13, #0x4]
	ldr     r1, [r13, #0x44]
	str     r0, [r13]
	str     r1, [r13, #0x8]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	mov     r9, r0
	add     r0, r13, #0x0
	bl      Vec3_HorzLen
	mov     r1, r0
	ldr     r0, [r13, #0x4]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	rsb     r0, r0, #0x0
	mov     r0, r0, lsl #0x10
	mov     r1, r9
	mov     r9, r0, asr #0x10
	mov     r0, r8
	bl      Matrix4x3_FromRotationY
	mov     r1, r9
	mov     r0, r8
	bl      Matrix4x3_ApplyInPlaceToRotationX
	add     r0, r13, #0x0c
	mov     r1, r8
	mov     r2, r7
	bl      MulVec3Mat4x3
	ldr     r2, [r4]
	mov     r1, r5
	str     r2, [r13, #0x24]
	ldr     r3, [r4, #0x4]
	add     r0, r13, #0x48
	str     r3, [r13, #0x28]
	ldr     r3, [r4, #0x8]
	mov     r2, r7
	str     r3, [r13, #0x2c]
	bl      Vec3_Add
	ldr     r1, [r13, #0x48]
	mov     r0, r6
	str     r1, [r4]
	ldr     r2, [r13, #0x4c]
	mov     r1, r4
	str     r2, [r4, #0x4]
	ldr     r3, [r13, #0x50]
	add     r2, r13, #0x24
	str     r3, [r4, #0x8]
	bl      Vec3_Sub
	ldr     r2, =#0x0b68
	add     r0, r13, #0x60
	mov     r1, r6
	bl      Vec3_MulScalar
	ldr     r0, [r13, #0x64]
	ldr     r1, [r13, #0x60]
	str     r0, [r13, #0x28]
	ldr     r0, [r13, #0x68]
	str     r1, [r13, #0x24]
	subs    r10, r10, #0x1
	str     r0, [r13, #0x2c]
	sub     r4, r4, #0x0c
	bpl     LAB_021123ec
	add     r13, r13, #0x6c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211250c:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x64
	mov     r3, #0x0
	mov     r8, r0
	mov     r1, #0x0c8000
	rsb     r2, r1, #0x0
	ldr     r0, =#0x584
	str     r3, [r13, #0x10]
	str     r3, [r13, #0x14]
	str     r3, [r13, #0x1c]
	str     r3, [r13, #0x20]
	str     r3, [r13, #0x24]
	str     r2, [r13, #0x18]
	ldr     r2, [r8, #0x610]
	mov     r1, #0x5000
	add     r5, r8, r0
	rsb     r0, r1, #0x0
	add     r6, r8, #0x530
	cmp     r2, #0x2
	add     r4, r8, #0x5d0
	str     r0, [r13]
	ldr     r11, =#0x0b68
	beq     LAB_02112570
	cmp     r2, #0x4
	bne     LAB_02112588
LAB_02112570:
	ldrb    r0, [r8, #0x605]
	cmp     r0, #0x0
	addeq   r11, r11, #0x7800
	moveq   r0, #0x0
	streq   r0, [r13]
	addne   r11, r11, #0x190
LAB_02112588:
	ldrsh   r1, [r8, #0x8c]
	ldrsh   r2, [r8, #0x8e]
	ldrsh   r3, [r8, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationXYZExt
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x10
	add     r2, r13, #0x1c
	bl      MulVec3Mat4x3
	add     r0, r13, #0x34
	add     r2, r13, #0x1c
	add     r1, r8, #0x5c
	bl      Vec3_Add
	ldr     r2, [r13, #0x34]
	ldr     r0, [r13, #0x38]
	ldr     r1, [r13, #0x3c]
	str     r0, [r13, #0x2c]
	str     r2, [r13, #0x28]
	str     r1, [r13, #0x30]
	str     r2, [r8, #0x524]
	ldr     r1, [r13, #0x2c]
	mov     r0, #0x0
	str     r1, [r8, #0x528]
	ldr     r1, [r13, #0x30]
	mov     r10, #0x1
	str     r1, [r8, #0x52c]
	ldr     r1, [r8, #0x5f8]
	str     r1, [r13, #0x18]
	str     r0, [r13, #0x10]
	str     r0, [r13, #0x14]
	str     r0, [r13, #0x1c]
	str     r0, [r13, #0x20]
	str     r0, [r13, #0x24]
LAB_0211260c:
	cmp     r10, #0x0
	addeq   r7, r13, #0x28
	subne   r7, r6, #0x0c
	ldr     r1, [r6]
	ldr     r0, [r7]
	ldr     r2, [r5]
	sub     r0, r1, r0
	add     r0, r2, r0
	str     r0, [r13, #0x4]
	ldr     r1, [r6, #0x8]
	ldr     r0, [r7, #0x8]
	ldr     r2, [r5, #0x8]
	sub     r0, r1, r0
	add     r0, r2, r0
	str     r0, [r13, #0x0c]
	ldr     r2, [r6, #0x4]
	ldr     r0, [r5, #0x4]
	ldr     r1, [r4]
	add     r2, r2, r0
	ldr     r0, [r13]
	add     r2, r0, r2
	cmp     r2, r1
	movle   r2, r1
	ldr     r1, [r7, #0x4]
	ldr     r0, [r13, #0x4]
	sub     r1, r2, r1
	str     r1, [r13, #0x8]
	ldr     r1, [r13, #0x0c]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	mov     r9, r0
	add     r0, r13, #0x4
	bl      Vec3_HorzLen
	mov     r1, r0
	ldr     r0, [r13, #0x8]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	rsb     r0, r0, #0x0
	mov     r0, r0, lsl #0x10
	mov     r1, r9
	mov     r9, r0, asr #0x10
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	ldr     r0, =MATRIX_SCRATCH_PAPER
	mov     r1, r9
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x10
	add     r2, r13, #0x1c
	bl      MulVec3Mat4x3
	ldr     r2, [r6]
	mov     r1, r7
	str     r2, [r5]
	ldr     r3, [r6, #0x4]
	add     r0, r13, #0x40
	str     r3, [r5, #0x4]
	ldr     r3, [r6, #0x8]
	add     r2, r13, #0x1c
	str     r3, [r5, #0x8]
	bl      Vec3_Add
	ldr     r1, [r13, #0x40]
	add     r0, r13, #0x4c
	str     r1, [r6]
	ldr     r2, [r13, #0x44]
	mov     r1, r6
	str     r2, [r6, #0x4]
	ldr     r3, [r13, #0x48]
	mov     r2, r5
	str     r3, [r6, #0x8]
	bl      Vec3_Sub
	add     r0, r13, #0x58
	add     r1, r13, #0x4c
	mov     r2, r11
	bl      Vec3_MulScalar
	ldr     r0, [r13, #0x58]
	add     r10, r10, #0x1
	str     r0, [r5]
	ldr     r0, [r13, #0x5c]
	add     r6, r6, #0x0c
	str     r0, [r5, #0x4]
	ldr     r0, [r13, #0x60]
	str     r0, [r5, #0x8]
	ldr     r1, [r8, #0x5f0]
	ldr     r0, [r4]
	add     r5, r5, #0x0c
	cmp     r0, r1
	addle   r0, r1, #0x28000
	strle   r0, [r4]
	cmp     r10, #0x7
	add     r4, r4, #0x4
	blt     LAB_0211260c
	add     r13, r13, #0x64
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112788:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x3c
	mov     r9, r0
	ldrsh   r1, [r9, #0x8c]
	ldrsh   r2, [r9, #0x8e]
	ldrsh   r3, [r9, #0x90]
	add     r0, r9, #0x16c
	bl      Matrix4x3_FromRotationXYZExt
	ldr     r0, [r9, #0x5c]
	mov     r0, r0, asr #0x3
	str     r0, [r9, #0x190]
	ldr     r0, [r9, #0x60]
	mov     r0, r0, asr #0x3
	str     r0, [r9, #0x194]
	ldr     r0, [r9, #0x64]
	mov     r0, r0, asr #0x3
	str     r0, [r9, #0x198]
	ldr     r1, [r9, #0x60]
	ldr     r0, [r9, #0x5f0]
	sub     r5, r1, r0
	cmp     r5, #0x1000
	movle   r5, #0x1000
	mov     r0, #0x180
	mov     r1, #0x0
	umull   r4, r3, r5, r0
	mla     r3, r5, r1, r3
	mov     r2, r5, asr #0x1f
	mla     r3, r2, r0, r3
	add     r2, r5, #0x28000
	mov     r1, #0x800
	adds    r1, r4, r1
	adc     r0, r3, #0x0
	mov     r4, r1, lsr #0x0c
	orr     r4, r4, r0, lsl #0x14
	ldr     r3, =#0x15e000
	str     r2, [r13]
	mov     r5, #0x0f
	mov     r0, r9
	add     r1, r9, #0x1b4
	add     r2, r9, #0x16c
	sub     r3, r3, r4
	str     r5, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	ldr     r11, =_ZN9Matrix3x38IDENTITYE
	ldr     r4, =#0x40c
	add     r10, r13, #0x8
	ldmia   r11!, { r0-r3 }
	stmia   r10!, { r0-r3 }
	ldmia   r11!, { r0-r3 }
	stmia   r10!, { r0-r3 }
	ldmia   r11, { r0-r3 }
	stmia   r10, { r0-r3 }
	add     r4, r9, r4
	mov     r8, #0x0
	add     r7, r9, #0x1dc
	mov     r6, r9
	mov     r5, r9
	mov     r11, #0x1000
	mov     r10, #0x0f
LAB_02112874:
	add     r14, r13, #0x8
	add     r12, r7, #0x1c
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	ldr     r0, [r6, #0x524]
	mov     r3, #0x180
	mov     r0, r0, asr #0x3
	str     r0, [r5, #0x21c]
	ldr     r0, [r6, #0x528]
	mov     r12, #0x0
	mov     r0, r0, asr #0x3
	str     r0, [r5, #0x220]
	ldr     r0, [r6, #0x52c]
	mov     r0, r0, asr #0x3
	str     r0, [r5, #0x224]
	ldr     r1, [r6, #0x528]
	ldr     r0, [r9, #0x5f0]
	sub     r2, r1, r0
	cmp     r2, #0x1000
	movle   r2, r11
	umull   r1, r0, r2, r3
	mla     r0, r2, r12, r0
	mov     r12, r2, asr #0x1f
	mla     r0, r12, r3, r0
	mov     r3, #0x800
	adds    r1, r1, r3
	add     r2, r2, #0x28000
	str     r2, [r13]
	mov     r2, r1, lsr #0x0c
	adc     r0, r0, #0x0
	orr     r2, r2, r0, lsl #0x14
	rsb     r3, r2, #0x78000
	mov     r0, r9
	mov     r1, r4
	add     r2, r7, #0x1c
	str     r10, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r8, r8, #0x1
	cmp     r8, #0x7
	add     r7, r7, #0x50
	add     r6, r6, #0x0c
	add     r5, r5, #0x50
	add     r4, r4, #0x28
	blt     LAB_02112874
	add     r13, r13, #0x3c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211294c:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN10ChainChomp9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10ChainChomp14chainModelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10ChainChomp9animFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10ChainChomp9animFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112994:
	push    { r4-r6, r14 }
	mov     r4, r0
	add     r0, r4, #0x150
	ldr     r2, [r0]
	add     r1, r4, #0x80
	ldr     r2, [r2, #0x14]
	blx     r2
	add     r5, r4, #0x1dc
	mov     r6, #0x0
	mov     r4, r6
LAB_021129bc:
	mov     r0, r5
	ldr     r2, [r0]
	mov     r1, r4
	ldr     r2, [r2, #0x14]
	blx     r2
	add     r6, r6, #0x1
	cmp     r6, #0x7
	add     r5, r5, #0x50
	blt     LAB_021129bc
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021129ec:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	mov     r1, #0x0
	strb    r1, [r4, #0x61c]
	ldr     r2, [r4, #0x5f0]
	ldr     r1, [r4, #0x60]
	add     r2, r2, #0x0c8000
	cmp     r1, r2
	bgt     LAB_02112a30
	str     r2, [r4, #0x60]
	ldrb    r1, [r4, #0x61d]
	cmp     r1, #0x0
	bne     LAB_02112a28
	bl      FUN_02111fb8
LAB_02112a28:
	mov     r0, #0x1
	strb    r0, [r4, #0x61c]
LAB_02112a30:
	ldrb    r0, [r4, #0x61c]
	strb    r0, [r4, #0x61d]
	ldr     r0, [r4, #0x60c]
	cmp     r0, #0x0
	bne     LAB_02112a58
	mov     r0, #0x29
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	ldr     r0, [r0, #0x4]
	str     r0, [r4, #0x60c]
LAB_02112a58:
	mov     r0, r4
	bl      FUN_02111f08
	mov     r0, r4
	add     r1, r4, #0x110
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	mov     r0, r4
	bl      FUN_02112114
	ldrb    r0, [r4, #0x605]
	cmp     r0, #0x0
	bne     LAB_02112a88
	mov     r0, r4
	bl      FUN_02111fe0
LAB_02112a88:
	mov     r0, r4
	bl      FUN_0211250c
	ldrb    r0, [r4, #0x605]
	cmp     r0, #0x0
	bne     LAB_02112aac
	mov     r0, r4
	bl      FUN_0211236c
	mov     r0, r4
	bl      FUN_021122dc
LAB_02112aac:
	mov     r0, r4
	bl      FUN_02112788
	ldr     r0, =CYLINDER_CLSN_OFFSET
	add     r1, r13, #0x0
	ldr     r12, [r0]
	ldr     r3, [r0, #0x4]
	ldr     r2, [r0, #0x8]
	add     r0, r4, #0x110
	str     r12, [r13]
	str     r3, [r13, #0x4]
	str     r2, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	add     r0, r4, #0x110
	bl      _ZN12CylinderClsn5ClearEv
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	ldrb    r0, [r0, #0x6fb]
	cmp     r0, #0x0
	bne     LAB_02112b00
	add     r0, r4, #0x110
	bl      _ZN12CylinderClsn6UpdateEv
LAB_02112b00:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112b14:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldr     r0, =_ZN10ChainChomp9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r2, #0x1
	mov     r1, r0
	mov     r3, r2
	add     r0, r4, #0x150
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	ldr     r0, =_ZN10ChainChomp14chainModelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10ChainChomp9animFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10ChainChomp9animFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	add     r7, r4, #0x1dc
	mov     r8, #0x0
	ldr     r5, =_ZN10ChainChomp14chainModelFileE
	mov     r6, #0x1
LAB_02112b64:
	ldr     r1, [r5, #0x4]
	mov     r0, r7
	mov     r2, r6
	mov     r3, r6
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	add     r8, r8, #0x1
	cmp     r8, #0x7
	add     r7, r7, #0x50
	blt     LAB_02112b64
	add     r0, r4, #0x1b4
	bl      _ZN11ShadowModel12InitCylinderEv
	ldr     r0, =#0x40c
	mov     r6, #0x0
	add     r5, r4, r0
LAB_02112b9c:
	mov     r0, r5
	bl      _ZN11ShadowModel12InitCylinderEv
	add     r6, r6, #0x1
	cmp     r6, #0x7
	add     r5, r5, #0x28
	blt     LAB_02112b9c
	mov     r0, #0x2000
	rsb     r1, r0, #0x0
	mov     r0, #0x3c000
	str     r1, [r4, #0x9c]
	rsb     r1, r0, #0x0
	ldr     r0, =CYLINDER_CLSN_OFFSET
	str     r1, [r4, #0x0a0]
	ldr     r2, [r0]
	ldr     r1, [r0, #0x4]
	ldr     r0, [r0, #0x8]
	str     r2, [r13, #0x0c]
	str     r1, [r13, #0x10]
	str     r0, [r13, #0x14]
	mov     r1, #0x12c000
	str     r1, [r13]
	ldr     r0, =#0x200004
	ldr     r5, =#0x26ff0
	str     r0, [r13, #0x4]
	add     r2, r13, #0x0c
	mov     r1, r4
	add     r0, r4, #0x110
	mov     r3, #0x96000
	str     r5, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	mov     r0, r4
	mov     r1, #0x1
	bl      FUN_02111ebc
	mov     r1, r4
	mov     r2, #0x0
LAB_02112c28:
	ldr     r0, [r4, #0x5c]
	add     r2, r2, #0x1
	str     r0, [r1, #0x524]
	ldr     r0, [r4, #0x60]
	cmp     r2, #0x7
	str     r0, [r1, #0x528]
	ldr     r0, [r4, #0x64]
	str     r0, [r1, #0x52c]
	add     r1, r1, #0x0c
	blt     LAB_02112c28
	ldr     r0, [r4, #0x5c]
	mvn     r5, #0x0
	str     r0, [r4, #0x5ec]
	ldr     r0, [r4, #0x60]
	add     r2, r4, #0x5c
	str     r0, [r4, #0x5f0]
	ldr     r1, [r4, #0x64]
	mov     r0, #0x1b
	str     r1, [r4, #0x5f4]
	ldrsb   r12, [r4, #0x0cc]
	mov     r1, #0x11
	mov     r3, #0x0
	str     r12, [r13]
	str     r5, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	ldr     r2, [r0, #0x4]
	mov     r1, #0x1
	str     r2, [r4, #0x608]
	strb    r1, [r0, #0x320]
	mov     r0, #0x0
	str     r0, [r4, #0x60c]
	add     r3, r4, #0x5c
	ldr     r0, [r3]
	add     r2, r4, #0x60
	add     r0, r0, #0x0c8000
	str     r0, [r3]
	ldr     r0, [r2]
	add     r3, r4, #0x64
	add     r0, r0, #0x0c8000
	str     r0, [r2]
	ldr     r2, [r3]
	mov     r0, #0x50000
	add     r2, r2, #0x0c8000
	str     r2, [r3]
	str     r0, [r4, #0x5f8]
	mov     r2, #0x1000
	str     r2, [r4, #0x80]
	str     r2, [r4, #0x84]
	mov     r0, r1
	str     r2, [r4, #0x88]
	add     r13, r13, #0x18
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112d1c:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r0, #0x620
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02112dd4
	bl      _ZN5EnemyC2Ev
	ldr     r1, =VTable_ChainChomp
	add     r0, r4, #0x110
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
	add     r0, r4, #0x150
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x1b4
	bl      _ZN11ShadowModelC1Ev
	ldr     r1, =_ZN5ModelD1Ev
	add     r0, r4, #0x1dc
	str     r1, [r13]
	mov     r1, #0x7
	mov     r2, #0x50
	ldr     r3, =_ZN5ModelC1Ev
	bl      0x020733a8
	ldr     r1, =_ZN11ShadowModelD1Ev
	ldr     r0, =#0x40c
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x28
	ldr     r3, =_ZN11ShadowModelC1Ev
	bl      0x020733a8
	ldr     r1, =#0x20072c0
	ldr     r0, =#0x524
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x0c
	ldr     r3, =#0x203d384
	bl      0x020733a8
	ldr     r1, =#0x20072c0
	ldr     r0, =#0x578
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x7
	mov     r2, #0x0c
	ldr     r3, =#0x203d384
	bl      0x020733a8
LAB_02112dd4:
	mov     r0, r4
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");