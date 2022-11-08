#include "HootTheOwl.h"

extern "C"
{
	ActorBase* FUN_02136798(); // constructor
	
	// state function declarations for use below
	void FUN_0213598c(HootTheOwl* hootTheOwl);
	void FUN_021358b4(HootTheOwl* hootTheOwl);
	void FUN_02136150(HootTheOwl* hootTheOwl);
	void FUN_02136024(HootTheOwl* hootTheOwl);
	void FUN_02135fe0(HootTheOwl* hootTheOwl);
	void FUN_02135ee0(HootTheOwl* hootTheOwl);
	void FUN_02135e64(HootTheOwl* hootTheOwl);
	void FUN_02135c28(HootTheOwl* hootTheOwl);
	void FUN_02135bd4(HootTheOwl* hootTheOwl);
	void FUN_021359d8(HootTheOwl* hootTheOwl);
	
	Vector3 UNK_02136a1c = Vector3{ 0_f, -0x20000_f, 0_f }; // 0x02136a1c
	
	using StateFunc = void(*)(HootTheOwl*);
	
	struct State
	{
		StateFunc func1;
		u32 unk04;
		StateFunc func2;
		u32 unk0c;
	};
	
	State states[5] = // 0x02126ffc
	{
		{ &FUN_0213598c, 0, &FUN_021358b4, 0 },
		{ &FUN_02136150, 0, &FUN_02136024, 0 },
		{ &FUN_02135fe0, 0, &FUN_02135ee0, 0 },
		{ &FUN_02135e64, 0, &FUN_02135c28, 0 },
		{ &FUN_02135bd4, 0, &FUN_021359d8, 0 },
	};
}

SharedFilePtr HootTheOwl::modelFile;
SharedFilePtr HootTheOwl::animFiles[3];

SpawnInfo HootTheOwl::spawnData = 
{
	&FUN_02136798,
	0x00ea,
	0x0059,
	0x00000000,
	0x00064000_f,
	0x000c8000_f,
	0x01000000_f,
	0x01000000_f,
};

asm(R"(
@ 0x02136a58
VTable_HootTheOwl:
	.word FUN_02136634
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_021363e0
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02136478
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_0213642c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word FUN_02136428
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02135700
	.word FUN_02135748
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
FUN_02135700:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_HootTheOwl
	add     r0, r4, #0x370
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x30c
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x150
	bl      _ZN12WithMeshClsnD1Ev
	add     r0, r4, #0x110
	bl      _ZN19CylinderClsnWithPosD1Ev
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135748:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_HootTheOwl
	add     r0, r4, #0x370
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x30c
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x150
	bl      _ZN12WithMeshClsnD1Ev
	add     r0, r4, #0x110
	bl      _ZN19CylinderClsnWithPosD1Ev
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
FUN_021357a4:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	ldr     r1, =UNK_02136a1c
	mov     r4, r0
	ldr     r3, [r1]
	ldr     r2, [r1, #0x4]
	ldr     r0, [r1, #0x8]
	add     r1, r13, #0x0c
	str     r0, [r13, #0x14]
	str     r3, [r13, #0x0c]
	str     r2, [r13, #0x10]
	add     r0, r4, #0x110
	bl      _ZN19CylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	ldr     r0, [r4, #0x134]
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4, r14 }
	bxeq    r14
	ldrh    r1, [r0, #0x0c]
	cmp     r1, #0x0bf
	moveq   r1, #0x1
	movne   r1, #0x0
	cmp     r1, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r1, =LEVEL_ID
	str     r0, [r4, #0x3cc]
	ldrsb   r0, [r1]
	mov     r2, #0x0
	ldr     r1, =#0x1838000
	str     r2, [r13, #0x4]
	cmp     r0, #0x16
	str     r1, [r13, #0x4]
	ldreq   r0, =#0x1194000
	str     r2, [r13]
	str     r2, [r13, #0x8]
	streq   r0, [r13, #0x4]
	mov     r0, #0x0
	str     r0, [r4, #0x0a4]
	str     r0, [r4, #0x0a8]
	str     r0, [r4, #0x0ac]
	ldr     r0, [r4, #0x3cc]
	add     r2, r13, #0x0
	mov     r1, r4
	bl      0x020df840
	cmp     r0, #0x1
	movne   r0, #0x0
	addne   r13, r13, #0x18
	strne   r0, [r4, #0x3cc]
	popne   { r4, r14 }
	bxne    r14
	ldr     r1, =states + 0x40
	mov     r0, r4
	bl      FUN_02136188
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021358b4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x3e8]
	cmp     r0, #0x0
	bne     LAB_0213593c
	ldrb    r0, [r4, #0x3e4]
	cmp     r0, #0x0
	beq     LAB_021358f8
	add     r3, r4, #0x3e4
	ldrb    r2, [r3]
	mov     r1, #0x0
	mov     r0, #0x14000
	sub     r2, r2, #0x1
	strb    r2, [r3]
	strh    r1, [r4, #0x92]
	str     r0, [r4, #0x0a8]
	b       LAB_0213597c
LAB_021358f8:
	mov     r0, #0x1
	str     r0, [r4, #0x3e8]
	mov     r0, #0x0
	str     r0, [r4, #0x0a4]
	str     r0, [r4, #0x0a8]
	str     r0, [r4, #0x0ac]
	ldr     r0, [r4, #0x3d8]
	add     r1, r4, #0x60
	str     r0, [r4, #0x5c]
	ldr     r0, [r4, #0x3dc]
	str     r0, [r4, #0x60]
	ldr     r0, [r4, #0x3e0]
	str     r0, [r4, #0x64]
	ldr     r0, [r1]
	add     r0, r0, #0x64000
	str     r0, [r1]
	b       LAB_0213597c
LAB_0213593c:
	add     r0, r4, #0x5c
	add     r1, r4, #0x3d8
	mov     r2, #0x2000
	bl      0x0203b89c
	ldrb    r0, [r4, #0x3e4]
	cmp     r0, #0x1f
	addcc   r1, r4, #0x3e4
	ldrccb  r0, [r1]
	addcc   r0, r0, #0x1
	strccb  r0, [r1]
	bcc     LAB_0213597c
	ldr     r1, =states + 0x30
	mov     r2, #0x1f
	mov     r0, r4
	strb    r2, [r4, #0x3e4]
	bl      FUN_02136188
LAB_0213597c:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0213598c:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	str     r2, [r0, #0x3e8]
	add     r1, r0, #0x100
	strh    r2, [r1]
	mov     r1, #0x2000
	str     r1, [r0, #0x3f0]
	ldr     r1, =_ZN10HootTheOwl9animFilesE + 0x10
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021359d8:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	add     r0, r4, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x1
	bne     LAB_02135a18
	mov     r2, #0x0
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x00
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x1000
	str     r0, [r4, #0x3f0]
LAB_02135a18:
	add     r0, r4, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_02135a48
	mov     r0, #0x0
	str     r0, [r13]
	ldr     r0, [r4, #0x3f4]
	add     r3, r4, #0x74
	mov     r1, #0x3
	mov     r2, #0x18c
	bl      _ZN5Sound8PlayLongEjjjRK7Vector3j
	str     r0, [r4, #0x3f4]
LAB_02135a48:
	add     r0, r4, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x0
	beq     LAB_02135aa8
	ldr     r0, [r4, #0x3e8]
	cmp     r0, #0x0
	bne     LAB_02135a90
	ldr     r0, [r4, #0x364]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x2
	bhi     LAB_02135a90
	ldr     r0, =#0x139
	add     r1, r4, #0x74
	bl      0x02012694
	mov     r0, #0x1
	str     r0, [r4, #0x3e8]
	b       LAB_02135aa8
LAB_02135a90:
	ldr     r0, [r4, #0x364]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x2
	movhi   r0, #0x0
	strhi   r0, [r4, #0x3e8]
LAB_02135aa8:
	ldr     r0, [r4, #0x3cc]
	cmp     r0, #0x0
	beq     LAB_02135ae8
	bl      0x020df7f4
	cmp     r0, #0x1
	bne     LAB_02135ae8
	add     r0, r4, #0x100
	mov     r1, #0x0a
	strh    r1, [r0]
	mov     r2, #0x0
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x10
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
LAB_02135ae8:
	mov     r12, #0x100
	add     r0, r4, #0x92
	mov     r1, #0x0
	mov     r2, #0x0a
	mov     r3, #0x200
	str     r12, [r13]
	bl      ApproachAngle
	add     r0, r4, #0x150
	bl      _ZNK12WithMeshClsn8IsOnWallEv
	cmp     r0, #0x0
	bne     LAB_02135b24
	add     r0, r4, #0x150
	bl      0x02035638
	cmp     r0, #0x0
	beq     LAB_02135b74
LAB_02135b24:
	ldr     r0, [r4, #0x3cc]
	cmp     r0, #0x0
	beq     LAB_02135b74
	bl      0x020df7ac
	cmp     r0, #0x0
	beq     LAB_02135b74
	add     r0, r4, #0x150
	bl      _ZN12WithMeshClsn12Unk_0203589cEv
	mov     r3, #0x0
	str     r3, [r4, #0x3cc]
	ldr     r1, =states + 0x00
	mov     r0, r4
	str     r3, [r4, #0x3e8]
	add     r2, r4, #0x100
	strh    r3, [r2]
	bl      FUN_02136188
	add     r13, r13, #0x8
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02135b74:
	ldr     r0, [r4, #0x3cc]
	cmp     r0, #0x0
	beq     LAB_02135b94
	cmp     r0, #0x0
	beq     LAB_02135bb4
	bl      0x020df7f4
	cmp     r0, #0x0
	bge     LAB_02135bb4
LAB_02135b94:
	mov     r3, #0x0
	str     r3, [r4, #0x3cc]
	ldr     r1, =states + 0x00
	mov     r0, r4
	str     r3, [r4, #0x3e8]
	add     r2, r4, #0x100
	strh    r3, [r2]
	bl      FUN_02136188
LAB_02135bb4:
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135bd4:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	add     r0, r4, #0x100
	mov     r1, #0x1e
	strh    r1, [r0]
	mov     r2, #0x0
	str     r2, [r4, #0x3e8]
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x10
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x2000
	str     r0, [r4, #0x3f0]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135c28:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x24
	mov     r4, r0
	ldrb    r1, [r4, #0x3d4]
	cmp     r1, #0x0
	bne     LAB_02135cdc
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02135cdc
	ldr     r0, [r4, #0x3d0]
	cmp     r0, #0x0
	beq     LAB_02135cdc
	add     r1, r0, #0x600
	ldrh    r1, [r1, #0x0ce]
	and     r1, r1, #0x800
	mov     r1, r1, lsl #0x10
	movs    r1, r1, lsr #0x10
	bne     LAB_02135cdc
	mov     r1, r4
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_02135cdc
	mov     r0, #0x0
	str     r0, [r13]
	str     r0, [r13, #0x4]
	ldr     r0, [r4, #0x3d0]
	mov     r1, r4
	add     r3, r4, #0x5c
	mov     r2, #0x0a2
	bl      _ZN6Player11ShowMessageER9ActorBasejRK7Vector3jj
	cmp     r0, #0x1
	bne     LAB_02135cdc
	ldr     r0, =#0x176
	add     r1, r4, #0x74
	bl      0x02012694
	mov     r2, #0x1
	ldr     r1, =states + 0x20
	mov     r0, r4
	strb    r2, [r4, #0x3d4]
	bl      FUN_02136188
	add     r13, r13, #0x24
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02135cdc:
	add     r0, r4, #0x5c
	add     r1, r4, #0x3d8
	bl      Vec3_Dist
	cmp     r0, #0x190000
	ble     LAB_02135d14
	add     r2, r4, #0x100
	mov     r3, #0x32
	add     r0, r4, #0x5c
	add     r1, r4, #0x3d8
	strh    r3, [r2]
	bl      Vec3_HorzAngle
	add     r1, r4, #0x300
	strh    r0, [r1, #0x0ec]
	b       LAB_02135d58
LAB_02135d14:
	add     r0, r4, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_02135d58
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x8
	ldr     r0, =RNG_STATE
	mov     r2, r1, lsl #0x0c
	add     r1, r4, #0x300
	strh    r2, [r1, #0x0ec]
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x8
	and     r0, r0, #0x3f
	add     r1, r0, #0x32
	add     r0, r4, #0x100
	strh    r1, [r0]
LAB_02135d58:
	mov     r0, #0x100
	str     r0, [r13]
	add     r0, r4, #0x300
	ldrsh   r1, [r0, #0x0ec]
	add     r0, r4, #0x94
	mov     r2, #0x0a
	mov     r3, #0x200
	bl      ApproachAngle
	mov     r5, #0x100
	add     r0, r4, #0x92
	mov     r1, #0x0
	mov     r2, #0x0a
	mov     r3, #0x200
	str     r5, [r13]
	bl      ApproachAngle
	mov     r0, #0x0
	mov     r1, #0x5000
	str     r0, [r13, #0x8]
	str     r0, [r13, #0x0c]
	str     r0, [r13, #0x14]
	str     r0, [r13, #0x18]
	str     r0, [r13, #0x1c]
	add     r2, r4, #0x3e8
	str     r1, [r13, #0x10]
	ldr     r1, [r2]
	ldr     r3, =SINE_TABLE
	add     r1, r1, #0x200
	str     r1, [r2]
	ldr     r1, [r4, #0x3e8]
	mov     r2, #0x64000
	mov     r1, r1, lsl #0x10
	mov     r1, r1, asr #0x10
	mov     r1, r1, lsl #0x10
	mov     r1, r1, lsr #0x10
	mov     r1, r1, asr #0x4
	mov     r1, r1, lsl #0x2
	ldrsh   r3, [r3, r1]
	mov     r1, #0x800
	ldr     r5, [r4, #0x3dc]
	umull   r14, r12, r3, r2
	mla     r12, r3, r0, r12
	mov     r0, r3, asr #0x1f
	mla     r12, r0, r2, r12
	adds    r1, r14, r1
	adc     r0, r12, #0x0
	mov     r1, r1, lsr #0x0c
	orr     r1, r1, r0, lsl #0x14
	add     r0, r4, #0x60
	add     r1, r5, r1
	mov     r2, #0x3000
	bl      _Z14ApproachLinearRiii
	ldrsh   r1, [r4, #0x94]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r2, r4, #0x0a4
	add     r0, r13, #0x8
	bl      MulVec3Mat4x3
	mov     r0, #0x1
	add     r13, r13, #0x24
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135e64:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r2, #0x0
	ldr     r1, =_ZN10HootTheOwl9animFilesE + 0x08
	str     r2, [r13]
	mov     r4, r0
	ldr     r1, [r1, #0x4]
	add     r0, r4, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x8
	ldr     r0, =RNG_STATE
	mov     r2, r1, lsl #0x0c
	add     r1, r4, #0x300
	strh    r2, [r1, #0x0ec]
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x8
	and     r0, r0, #0x3f
	add     r1, r0, #0x32
	add     r0, r4, #0x100
	strh    r1, [r0]
	mov     r0, #0x1000
	str     r0, [r4, #0x3f0]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135ee0:
	push    { r4, r14 }
	sub     r13, r13, #0x28
	mov     r4, r0
	ldr     r1, [r4, #0x3d0]
	cmp     r1, #0x0
	bne     LAB_02135f10
	ldr     r1, =states + 0x30
	bl      FUN_02136188
	add     r13, r13, #0x28
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02135f10:
	add     r0, r1, #0x5c
	add     r3, r13, #0x4
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r12, [r13, #0x4]
	ldr     r3, [r13, #0x8]
	ldr     r2, [r13, #0x0c]
	add     r1, r13, #0x10
	add     r0, r4, #0x5c
	str     r12, [r13, #0x10]
	str     r3, [r13, #0x14]
	str     r2, [r13, #0x18]
	bl      Vec3_HorzAngle
	mov     r2, #0x100
	mov     r1, r0
	str     r2, [r13]
	add     r0, r4, #0x94
	mov     r2, #0x0a
	mov     r3, #0x200
	bl      ApproachAngle
	ldr     r0, [r13, #0x4]
	ldr     r1, [r13, #0x8]
	str     r0, [r13, #0x1c]
	add     r1, r1, #0x0c8000
	ldr     r0, [r13, #0x0c]
	str     r1, [r13, #0x8]
	str     r1, [r13, #0x20]
	str     r0, [r13, #0x24]
	add     r1, r13, #0x1c
	add     r0, r4, #0x5c
	bl      Vec3_VertAngle
	mov     r1, r0
	mov     r0, #0x100
	str     r0, [r13]
	add     r0, r4, #0x92
	mov     r2, #0x0a
	mov     r3, #0x200
	bl      ApproachAngle
	ldr     r0, [r4, #0x3d0]
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	bge     LAB_02135fcc
	ldr     r1, =states + 0x30
	mov     r2, #0x2
	mov     r0, r4
	strb    r2, [r4, #0x3d4]
	bl      FUN_02136188
LAB_02135fcc:
	mov     r0, #0x1
	add     r13, r13, #0x28
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02135fe0:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	str     r2, [r0, #0x0a4]
	str     r2, [r0, #0x0a8]
	str     r2, [r0, #0x0ac]
	ldr     r1, =_ZN10HootTheOwl9animFilesE + 0x08
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136024:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02136138
	ldr     r1, [r0, #0x37c]
	cmp     r1, #0x0
	beq     LAB_02136138
	add     r12, r0, #0x5c
	ldr     r1, [r12]
	add     r2, r13, #0x0
	str     r1, [r13]
	ldr     r3, [r12, #0x4]
	add     r1, r4, #0x5c
	str     r3, [r13, #0x4]
	ldr     r3, [r12, #0x8]
	str     r3, [r13, #0x8]
	ldr     r3, [r0, #0x644]
	add     r3, r3, #0x190000
	str     r3, [r4, #0x60]
	str     r0, [r4, #0x3d0]
	add     r0, r13, #0x0c
	bl      Vec3_Sub
	add     r0, r13, #0x0c
	bl      LenVec3
	cmp     r0, #0x28000
	bge     LAB_02136138
	ldr     r1, [r4, #0x5c]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	str     r1, [r13, #0x0c]
	ldr     r1, [r4, #0x60]
	mov     r3, #0x0
	str     r1, [r13, #0x10]
	ldr     r1, [r4, #0x64]
	mov     r2, #0x320000
	str     r1, [r13, #0x14]
	mov     r1, #0x4000
	str     r3, [r13, #0x0c]
	str     r3, [r13, #0x10]
	str     r2, [r13, #0x14]
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x0c
	add     r2, r4, #0x3d8
	bl      MulVec3Mat4x3
	add     r1, r4, #0x3d8
	ldr     r2, [r1]
	ldr     r0, [r4, #0x5c]
	add     r3, r4, #0x3dc
	add     r0, r2, r0
	str     r0, [r1]
	ldr     r2, [r3]
	ldr     r0, [r4, #0x60]
	add     r12, r4, #0x3e0
	add     r0, r2, r0
	str     r0, [r3]
	ldr     r3, [r12]
	ldr     r2, [r4, #0x64]
	add     r0, r4, #0x5c
	add     r2, r3, r2
	str     r2, [r12]
	bl      Vec3_HorzAngle
	strh    r0, [r4, #0x94]
	ldrsh   r2, [r4, #0x94]
	ldr     r1, =states + 0x30
	mov     r0, r4
	strh    r2, [r4, #0x8e]
	bl      FUN_02136188
LAB_02136138:
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136150:
	push    { r14 }
	sub     r13, r13, #0x4
	mov     r2, #0x0
	ldr     r1, =_ZN10HootTheOwl9animFilesE + 0x08
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x30c
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136188:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x3c8]
	ldr     r3, [r0, #0x3c8]
	ldr     r2, [r3]
	cmp     r2, #0x0
	addeq   r13, r13, #0x4
	moveq   r0, #0x1
	popeq   { r14 }
	bxeq    r14
	ldr     r1, [r3, #0x4]
	add     r0, r0, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r1, [r0]
	ldrne   r1, [r1, r2]
	ldreq   r1, [r3]
	blx     r1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021361d8:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x44
	mov     r4, r0
	add     r0, r13, #0x38
	add     r1, r4, #0x5c
	mov     r2, #0x3
	bl      Vec3_Asr
	ldr     r1, [r13, #0x38]
	ldr     r2, [r13, #0x3c]
	ldr     r3, [r13, #0x40]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldrsh   r1, [r4, #0x8c]
	ldrsh   r2, [r4, #0x8e]
	ldrsh   r3, [r4, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      0x0203c0b4
	ldrb    r1, [r4, #0x3e4]
	add     r0, r4, #0x30c
	mov     r2, #0x1
	bl      0x02016a9c
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r4, #0x328
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	ldr     r0, [r4, #0x320]
	mov     r1, r5
	add     r2, r13, #0x8
	add     r0, r0, #0x30
	bl      MulMat4x3Mat4x3
	ldr     r2, [r4, #0x60]
	ldr     r1, [r4, #0x5c]
	ldr     r3, [r4, #0x64]
	sub     r2, r2, #0x38000
	ldr     r0, =MATRIX_SCRATCH_PAPER
	mov     r1, r1, asr #0x3
	mov     r2, r2, asr #0x3
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r4, #0x398
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	mov     r14, #0x320000
	mov     r12, #0x0f
	str     r14, [r13]
	mov     r2, r5
	mov     r0, r4
	add     r1, r4, #0x370
	mov     r3, #0x64000
	str     r12, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r13, r13, #0x44
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021362e0:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldr     r0, [r4, #0x3cc]
	cmp     r0, #0x0
	addeq   r13, r13, #0x10
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r6, #0x0
	str     r6, [r13]
	str     r6, [r13, #0x4]
	str     r6, [r13, #0x8]
	ldr     r0, [r4, #0x3cc]
	ldr     r14, =MATRIX_SCRATCH_PAPER
	ldr     r5, [r0, #0x0c8]
	mov     r12, r14
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5, { r0-r3 }
	stmia   r14, { r0-r3 }
	mov     r0, r12
	mov     r1, #0x3000
	mov     r2, r6
	mov     r3, r6
	bl      Matrix4x3_ConcatPos
	mov     r1, #0x6000
	ldr     r0, =MATRIX_SCRATCH_PAPER
	rsb     r1, r1, #0x0
	mov     r2, #0x1000
	mov     r3, #0x4000
	bl      0x0203c0b4
	ldr     r14, =MATRIX_SCRATCH_PAPER
	mov     r0, r6
	ldr     r2, [r14, #0x24]
	ldr     r1, [r14, #0x28]
	str     r2, [r13]
	str     r1, [r13, #0x4]
	mov     r1, r2, lsl #0x3
	ldr     r2, [r14, #0x2c]
	add     r12, r4, #0x328
	str     r2, [r13, #0x8]
	str     r1, [r4, #0x5c]
	ldr     r1, [r13, #0x4]
	mov     r1, r1, lsl #0x3
	str     r1, [r4, #0x60]
	ldr     r1, [r13, #0x8]
	mov     r1, r1, lsl #0x3
	str     r1, [r4, #0x64]
	ldr     r1, [r4, #0x3cc]
	ldrsh   r1, [r1, #0x8e]
	strh    r1, [r4, #0x94]
	strh    r0, [r4, #0x92]
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	add     r13, r13, #0x10
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021363e0:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN10HootTheOwl9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x10
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x00
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x08
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136428:
	bx      r14
.ltorg)");

asm(R"(
FUN_0213642c:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r2, [r0, #0x3c8]
	ldr     r1, =states + 0x10
	cmp     r2, r1
	addeq   r13, r13, #0x4
	moveq   r0, #0x1
	popeq   { r14 }
	bxeq    r14
	add     r0, r0, #0x30c
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
FUN_02136478:
	mov r11, r11
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x100
	bl      DecIfAbove0_Short
	ldr     r1, [r4, #0x3c8]
	ldr     r0, [r1, #0x8]
	cmp     r0, #0x0
	beq     LAB_021364bc
	add     r3, r1, #0x8
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
LAB_021364bc:
	ldr     r1, [r4, #0x3c8]
	ldr     r0, =states + 0x10
	cmp     r1, r0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r1, [r4, #0x3f0]
	add     r0, r4, #0x35c
	str     r1, [r4, #0x368]
	bl      _ZN9Animation7AdvanceEv
	ldr     r1, [r4, #0x3c8]
	ldr     r0, =states + 0x20
	cmp     r1, r0
	beq     LAB_0213650c
	ldr     r0, =states + 0x30
	cmp     r1, r0
	beq     LAB_0213650c
	ldr     r0, =states + 0x00
	cmp     r1, r0
	bne     LAB_0213652c
LAB_0213650c:
	ldr     r0, [r4, #0x364]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_0213652c
	ldr     r0, =#0x139
	add     r1, r4, #0x74
	bl      0x02012694
LAB_0213652c:
	ldr     r1, [r4, #0x3c8]
	ldr     r0, =states + 0x40
	cmp     r1, r0
	bne     LAB_0213658c
	cmp     r1, r0
	bne     LAB_02136578
	mov     r0, r4
	bl      FUN_021362e0
	ldrsh   r2, [r4, #0x92]
	mov     r0, r4
	add     r1, r4, #0x150
	strh    r2, [r4, #0x8c]
	ldrsh   r3, [r4, #0x94]
	mov     r2, #0x0
	strh    r3, [r4, #0x8e]
	ldrsh   r3, [r4, #0x96]
	strh    r3, [r4, #0x90]
	bl      _ZN5Enemy12UpdateWMClsnER12WithMeshClsnj
	b       LAB_02136580
LAB_02136578:
	mov     r0, r4
	bl      FUN_021361d8
LAB_02136580:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_0213658c:
	ldr     r1, [r4, #0x0a8]
	ldr     r0, [r4, #0x9c]
	ldr     r2, [r4, #0x0a0]
	add     r0, r1, r0
	cmp     r0, r2
	movge   r2, r0
	ldr     r1, [r4, #0x0ac]
	mov     r0, r4
	str     r2, [r4, #0x0a8]
	str     r1, [r4, #0x0ac]
	add     r1, r4, #0x110
	bl      _ZN5Actor22UpdatePosWithOnlySpeedEP12CylinderClsn
	ldrsh   r1, [r4, #0x92]
	mov     r0, r4
	strh    r1, [r4, #0x8c]
	ldrsh   r1, [r4, #0x94]
	strh    r1, [r4, #0x8e]
	ldrsh   r1, [r4, #0x96]
	strh    r1, [r4, #0x90]
	bl      FUN_021361d8
	ldr     r1, [r4, #0x3c8]
	ldr     r0, =states + 0x30
	cmp     r1, r0
	bne     LAB_02136600
	ldrb    r0, [r4, #0x3d4]
	cmp     r0, #0x2
	bne     LAB_02136600
	mov     r0, r4
	bl      FUN_021357a4
LAB_02136600:
	add     r0, r4, #0x110
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x110
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136634:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldr     r0, =_ZN10HootTheOwl9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x30c
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEPcii
	add     r0, r4, #0x370
	bl      _ZN11ShadowModel12InitCylinderEv
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x10
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x00
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10HootTheOwl9animFilesE + 0x08
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =UNK_02136a1c
	mov     r3, #0x64000
	ldr     r1, [r0, #0x4]
	ldr     r2, [r0]
	str     r1, [r13, #0x10]
	ldr     r1, [r0, #0x8]
	str     r2, [r13, #0x0c]
	str     r1, [r13, #0x14]
	ldr     r0, =#0x800004
	str     r3, [r13]
	str     r0, [r13, #0x4]
	mov     r0, #0x0
	str     r0, [r13, #0x8]
	add     r0, r4, #0x110
	mov     r1, r4
	add     r2, r13, #0x0c
	bl      _ZN19CylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	mov     r3, #0x0
	mov     r0, #0x1e000
	str     r3, [r4, #0x3cc]
	add     r2, r4, #0x128
	ldr     r1, [r2]
	rsb     r0, r0, #0x0
	orr     r1, r1, #0x2
	str     r1, [r2]
	str     r0, [r4, #0x0a0]
	mov     r0, #0x1000
	str     r0, [r4, #0x3f0]
	mov     r0, #0x1f
	strb    r0, [r4, #0x3e4]
	str     r3, [r13]
	str     r3, [r13, #0x4]
	add     r0, r4, #0x150
	mov     r1, r4
	mov     r2, #0x50000
	mov     r3, #0x64000
	bl      _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_
	ldr     r1, =states + 0x10
	mov     r0, r4
	bl      FUN_02136188
	ldr     r0, =LEVEL_ID
	ldrsb   r0, [r0]
	cmp     r0, #0x7
	bne     LAB_02136764
	ldr     r0, =STAR_ID
	ldrb    r0, [r0]
	cmp     r0, #0x1
	beq     LAB_0213674c
	mov     r0, #0x1
	bl      StarCollectedInCurrLevel
	cmp     r0, #0x0
	bne     LAB_02136764
LAB_0213674c:
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	add     r13, r13, #0x18
	mov     r0, #0x0
	pop     { r4, r14 }
	bx      r14
LAB_02136764:
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02136798:
	push    { r4, r14 }
	mov     r0, #0x3f8
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_021367d8
	bl      _ZN5EnemyC2Ev
	ldr     r1, =VTable_HootTheOwl
	add     r0, r4, #0x110
	str     r1, [r4]
	bl      _ZN19CylinderClsnWithPosC1Ev
	add     r0, r4, #0x150
	bl      _ZN12WithMeshClsnC1Ev
	add     r0, r4, #0x30c
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x370
	bl      _ZN11ShadowModelC1Ev
LAB_021367d8:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");