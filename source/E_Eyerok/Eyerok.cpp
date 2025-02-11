#include "SM64DS_2.h"
#include "Actors/Eyerok.h"

extern "C"
{
	ActorBase* FUN_0211a370(); // constructor
	
	// state function declarations for use below
	void FUN_02118cb8(Eyerok* eyerok);
	void FUN_02118c00(Eyerok* eyerok);
	void FUN_02118be0(Eyerok* eyerok);
	void FUN_02118b28(Eyerok* eyerok);
	void FUN_02117bd0(Eyerok* eyerok);
	void FUN_021175e8(Eyerok* eyerok);
	void FUN_02118b08(Eyerok* eyerok);
	void FUN_02118a50(Eyerok* eyerok);
	void FUN_02118a30(Eyerok* eyerok);
	void FUN_021189c0(Eyerok* eyerok);
	void FUN_021175bc(Eyerok* eyerok);
	void FUN_021171b0(Eyerok* eyerok);
	void FUN_021189a0(Eyerok* eyerok);
	void FUN_02118954(Eyerok* eyerok);
	void FUN_02118934(Eyerok* eyerok);
	void FUN_021188b0(Eyerok* eyerok);
	void FUN_02117190(Eyerok* eyerok);
	void FUN_02116db0(Eyerok* eyerok);
	void FUN_021187c8(Eyerok* eyerok);
	void FUN_02118678(Eyerok* eyerok);
	void FUN_02118658(Eyerok* eyerok);
	void FUN_02118604(Eyerok* eyerok);
	void FUN_02116d14(Eyerok* eyerok);
	void FUN_02116c6c(Eyerok* eyerok);
	void FUN_021185e4(Eyerok* eyerok);
	void FUN_021184e0(Eyerok* eyerok);
	void FUN_0211944c(Eyerok* eyerok);
	void FUN_02119398(Eyerok* eyerok);
	void FUN_02119348(Eyerok* eyerok);
	void FUN_0211903c(Eyerok* eyerok);
	void FUN_021184c0(Eyerok* eyerok);
	void FUN_02118188(Eyerok* eyerok);
	void FUN_0211901c(Eyerok* eyerok);
	void FUN_02118e04(Eyerok* eyerok);
	void FUN_02118de0(Eyerok* eyerok);
	void FUN_02118cdc(Eyerok* eyerok);
	void FUN_02118168(Eyerok* eyerok);
	void FUN_02117bf0(Eyerok* eyerok);
	
	// undocumented globals not in ov66:
	// 0x020072c0
	// 0x02039348
	// 0x0203d384
	// 0x0210ae38 (ov2)
	// 0x02112c08 (ov2)
	// 0x02112c88 (ov2)
	// 0x02112ca8 (ov2)
	// 0x02112cc8 (ov2)
	// 0x02112d48 (ov2)
	
	u8 UNK_0211abe0 = 3; // 0x0211abe0
	s32 UNK_0211abe4 = 1; // 0x0211abe4
	Vector3 UNK_0211ad18 = { 0._f, 32._f, -16._f }; // 0x0211ad18
	u8 UNK_0211ae00 = 0; // 0x0211ae00
	u8 UNK_0211ae04 = 0; // 0x0211ae04
	u8 UNK_0211ae08 = 0; // 0x0211ae08
	u8 UNK_0211ae0c = 0; // 0x0211ae0c
	u8 UNK_0211ae10 = 0; // 0x0211ae10
	
	using StateFunc = void(*)(Eyerok*);
	
	struct State
	{
		StateFunc func1;
		u32 unk04;
		StateFunc func2;
		u32 unk0c;
	};
	
	State states[19] = // 0x0211afcc
	{
		{ &FUN_02118cb8, 0, &FUN_02118c00, 0, },
		{ &FUN_02118be0, 0, &FUN_02118b28, 0, },
		{ &FUN_02117bd0, 0, &FUN_021175e8, 0, },
		{ &FUN_02118b08, 0, &FUN_02118a50, 0, },
		{ &FUN_02118a30, 0, &FUN_021189c0, 0, },
		{ &FUN_021175bc, 0, &FUN_021171b0, 0, },
		{ &FUN_021189a0, 0, &FUN_02118954, 0, },
		{ &FUN_02118934, 0, &FUN_021188b0, 0, },
		{ &FUN_02117190, 0, &FUN_02116db0, 0, },
		{ &FUN_021187c8, 0, &FUN_02118678, 0, },
		{ &FUN_02118658, 0, &FUN_02118604, 0, },
		{ &FUN_02116d14, 0, &FUN_02116c6c, 0, },
		{ &FUN_021185e4, 0, &FUN_021184e0, 0, },
		{ &FUN_0211944c, 0, &FUN_02119398, 0, },
		{ &FUN_02119348, 0, &FUN_0211903c, 0, },
		{ &FUN_021184c0, 0, &FUN_02118188, 0, },
		{ &FUN_0211901c, 0, &FUN_02118e04, 0, },
		{ &FUN_02118de0, 0, &FUN_02118cdc, 0, },
		{ &FUN_02118168, 0, &FUN_02117bf0, 0, },
	};
}

SharedFilePtr Eyerok::modelFile;
SharedFilePtr Eyerok::clsnFile;

SharedFilePtr Eyerok::handModelFiles[2];

SharedFilePtr Eyerok::waitClsnFiles[2];
SharedFilePtr Eyerok::moveClsnFiles[2];

SharedFilePtr Eyerok::closeTexSeqFiles[2];
SharedFilePtr Eyerok::openTexSeqFiles[2];

SharedFilePtr Eyerok::wakeUpAnimFiles[2];
SharedFilePtr Eyerok::waitAnimFiles[2];
SharedFilePtr Eyerok::waitEndAnimFiles[2];
SharedFilePtr Eyerok::damageAnimFiles[2];
SharedFilePtr Eyerok::deadAnimFiles[2];

SpawnInfo Eyerok::spawnData = 
{
	&FUN_0211a370,
	0x00b0,
	0x0063,
	0,
	100._f,
	100._f,
	4096._f,
	3200._f,
};

asm(R"(
@ 0x0211ad64
VTable_Eyerok:
	.word FUN_02119ce8
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02119654
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02119838
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_021197a4
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word FUN_021197a0
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02115ee0
	.word FUN_02115f84
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
	.word FUN_0211a2dc
	.word _ZN5Actor25OnAimedAtWithEggReturnVecEv
	.word _ZN8Platform4KillEv
.ltorg)");

asm(R"(
FUN_02115ee0:
	push    { r4, r14 }
	ldr     r1, =#0x674
	mov     r4, r0
	ldr     r2, =VTable_Eyerok
	add     r0, r4, r1
	str     r2, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	ldr     r0, =#0x4dc
	ldr     r3, =#0x20072c0
	add     r0, r4, r0
	mov     r1, #0x14
	mov     r2, #0x0c
	bl      0x0207328c
	ldr     r0, =#0x448
	add     r0, r4, r0
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x420
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x3d0
	bl      _ZN5ModelD1Ev
	add     r0, r4, #0x360
	bl      _ZN14BlendModelAnimD1Ev
	add     r0, r4, #0x320
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	ldr     r1, =#0x210ae38
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
FUN_02115f84:
	push    { r4, r14 }
	ldr     r1, =#0x674
	mov     r4, r0
	ldr     r2, =VTable_Eyerok
	add     r0, r4, r1
	str     r2, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	ldr     r0, =#0x4dc
	ldr     r3, =#0x20072c0
	add     r0, r4, r0
	mov     r1, #0x14
	mov     r2, #0x0c
	bl      0x0207328c
	ldr     r0, =#0x448
	add     r0, r4, r0
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x420
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x3d0
	bl      _ZN5ModelD1Ev
	add     r0, r4, #0x360
	bl      _ZN14BlendModelAnimD1Ev
	add     r0, r4, #0x320
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	ldr     r1, =#0x210ae38
	add     r0, r4, #0x124
	str     r1, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN5ModelD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	ldr     r1, =_ZN6Memory11gameHeapPtrE
	ldr     r1, [r1]
	bl      _ZN6Memory10DeallocateEPvP4Heap
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211603c:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x8
	mov     r6, r0
	ldr     r0, [r6, #0x344]
	cmp     r0, #0x0
	beq     LAB_021162a4
	bl      _ZN5Actor10FindWithIDEj
	movs    r5, r0
	addeq   r13, r13, #0x8
	moveq   r0, #0x0
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r0, r6
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r1, r0
	ldrsh   r0, [r6, #0x8e]
	bl      AngleDiff
	cmp     r0, #0x4000
	addge   r13, r13, #0x8
	movge   r0, #0x0
	popge   { r4-r6, r14 }
	bxge    r14
	ldrh    r1, [r5, #0x0c]
	mov     r0, #0x0
	ldr     r4, [r6, #0x340]
	cmp     r1, #0x0bf
	moveq   r1, #0x1
	movne   r1, r0
	cmp     r1, #0x0
	beq     LAB_02116110
	ldrb    r1, [r5, #0x6f9]
	cmp     r1, #0x1
	bne     LAB_021160d8
	ldr     r1, =#0x4d8
	mov     r0, #0x1
	add     r2, r6, r1
	ldrsb   r1, [r2]
	sub     r1, r1, #0x1
	strb    r1, [r2]
LAB_021160d8:
	ands    r1, r4, #0x10
	beq     LAB_02116110
	ldr     r0, =#0x4d8
	add     r1, r6, #0x400
	add     r2, r6, r0
	ldrsb   r0, [r2]
	sub     r0, r0, #0x1
	strb    r0, [r2]
	ldrsb   r0, [r1, #0x0d8]
	cmp     r0, #0x0
	bgt     LAB_0211610c
	mov     r0, r5
	bl      _ZN6Player16IncMegaKillCountEv
LAB_0211610c:
	mov     r0, #0x1
LAB_02116110:
	cmp     r0, #0x0
	bne     LAB_02116170
	ldr     r1, =#0x427e0
	ands    r1, r4, r1
	beq     LAB_02116170
	ands    r0, r4, #0x40
	beq     LAB_02116148
	ldr     r0, [r5, #0x8]
	cmp     r0, #0x2
	ldreq   r0, =#0x4d8
	addeq   r1, r6, r0
	ldreqsb r0, [r1]
	subeq   r0, r0, #0x1
	streqb  r0, [r1]
LAB_02116148:
	ands    r0, r4, #0x40000
	addne   r0, r6, #0x400
	movne   r1, #0x1
	strneh  r1, [r0, #0x0d4]
	ldr     r1, =#0x4d8
	mov     r0, #0x1
	add     r2, r6, r1
	ldrsb   r1, [r2]
	sub     r1, r1, #0x1
	strb    r1, [r2]
LAB_02116170:
	cmp     r0, #0x0
	beq     LAB_021162a4
	add     r0, r6, #0x400
	ldrsb   r0, [r0, #0x0d8]
	cmp     r0, #0x0
	ble     LAB_0211624c
	ldr     r0, [r6, #0x49c]
	cmp     r0, #0x2
	bne     LAB_021161e4
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 0
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r6, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r6, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_02116230
LAB_021161e4:
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 8
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r6, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r6, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_02116230:
	ldr     r0, =#0x141
	add     r1, r6, #0x74
	bl      0x02012694
	add     r13, r13, #0x8
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
LAB_0211624c:
	ldr     r3, =UNK_0211ae08
	ldr     r4, =UNK_0211abe0
	ldrb    r0, [r3]
	ldrb    r5, [r4]
	ldr     r1, [r6, #0x49c]
	add     r12, r0, #0x1
	eor     r14, r5, r1
	ldr     r2, =UNK_0211abe4
	mvn     r5, #0x2
	ldr     r0, =#0x142
	add     r1, r6, #0x74
	strb    r14, [r4]
	strb    r12, [r3]
	str     r5, [r2]
	bl      0x02012694
	ldr     r1, =states + 0x0b0
	mov     r0, r6
	bl      FUN_02119454
	add     r13, r13, #0x8
	mov     r0, #0x2
	pop     { r4-r6, r14 }
	bx      r14
LAB_021162a4:
	mov     r0, #0x0
	add     r13, r13, #0x8
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021162e8:
	add     r3, r0, #0x338
	ldr     r2, [r3]
	mov     r1, #0x10000
	orr     r2, r2, #0x2
	str     r2, [r3]
	mov     r3, #0x64000
	str     r3, [r0, #0x324]
	ldr     r2, =UNK_0211ad18
	str     r3, [r0, #0x328]
	rsb     r0, r1, #0x0
	mov     r3, #0x0
	mov     r1, #0x20000
	str     r3, [r2]
	str     r1, [r2, #0x4]
	str     r0, [r2, #0x8]
	bx      r14
.ltorg)");

asm(R"(
FUN_0211632c:
	add     r3, r0, #0x338
	ldr     r2, [r3]
	mov     r1, #0x9c000
	bic     r2, r2, #0x2
	str     r2, [r3]
	str     r1, [r0, #0x324]
	mov     r1, #0x164000
	str     r1, [r0, #0x328]
	ldr     r0, [r0, #0x49c]
	cmp     r0, #0x2
	ldreq   r0, =UNK_0211ad18
	moveq   r1, #0x55000
	streq   r1, [r0]
	movne   r0, #0x55000
	ldrne   r1, =UNK_0211ad18
	rsbne   r0, r0, #0x0
	strne   r0, [r1]
	mov     r0, #0x0c0000
	rsb     r2, r0, #0x0
	ldr     r1, =UNK_0211ad18
	mov     r0, #0x80000
	str     r2, [r1, #0x4]
	str     r0, [r1, #0x8]
	bx      r14
.ltorg)");

asm(R"(
FUN_02116390:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	ldr     r1, =#0x66c
	mov     r4, r0
	add     r0, r4, r1
	bl      DecIfAbove0_Short
	add     r0, r4, #0x600
	ldrh    r0, [r0, #0x6c]
	cmp     r0, #0x0
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	ldrb    r0, [r4, #0x66e]
	cmp     r0, #0x0
	bne     LAB_02116448
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_02116400
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_02116424
LAB_02116400:
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_02116424:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x8
	and     r0, r0, #0x0f
	mov     r0, r0, lsl #0x1
	add     r1, r0, #0x32
	add     r0, r4, #0x600
	strh    r1, [r0, #0x6c]
	b       LAB_021164ac
LAB_02116448:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_0211647c
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_021164a0
LAB_0211647c:
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_021164a0:
	add     r0, r4, #0x600
	mov     r1, #0x8
	strh    r1, [r0, #0x6c]
LAB_021164ac:
	ldr     r0, =#0x66e
	add     r1, r4, r0
	ldrb    r0, [r1]
	eor     r0, r0, #0x1
	strb    r0, [r1]
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021164ec:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, [r4, #0x498]
	cmp     r0, #0x0
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	addne   r13, r13, #0x8
	popne   { r4, r14 }
	bxne    r14
	add     r3, r4, #0x33c
	ldr     r2, [r3]
	ldr     r0, =#0x427f0
	mov     r1, #0x10000000
	orr     r0, r2, r0
	str     r0, [r3]
	str     r1, [r4, #0x0b0]
	add     r1, r4, #0x338
	ldr     r0, [r1]
	orr     r0, r0, #0x2
	str     r0, [r1]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_02116588
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r3, #0x0
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	bl      0x020163e0
	b       LAB_021165ac
LAB_02116588:
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r3, #0x0
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	bl      0x020163e0
LAB_021165ac:
	mov     r0, #0x1
	str     r0, [r4, #0x498]
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021165cc:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_02116634
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 0
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_02116680
LAB_02116634:
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 8
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_02116680:
	mov     r0, #0x1000
	str     r0, [r4, #0x3bc]
	add     r3, r4, #0x33c
	ldr     r2, [r3]
	ldr     r0, =#0x0fffbd82f
	mov     r1, #0x0
	and     r0, r2, r0
	str     r0, [r3]
	str     r1, [r4, #0x0b0]
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021166c8:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_02116730
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 0
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_0211677c
LAB_02116730:
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 8
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_0211677c:
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_0211679c
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_0211679c:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_021167dc
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112cc8
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13waitClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	b       LAB_0211680c
LAB_021167dc:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c88
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13waitClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
LAB_0211680c:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	add     r0, r4, #0x3b0
	bl      _ZNK9Animation13GetFrameCountEv
	sub     r0, r0, #0x1
	mov     r0, r0, lsl #0x10
	mov     r1, r0, lsr #0x4
	mov     r0, #0x1000
	str     r1, [r4, #0x3b8]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x3bc]
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021168b0:
	ldr     r1, [r0, #0x4a0]
	cmp     r1, #0x0
	bne     LAB_021168e0
	ldr     r1, =UNK_0211ae0c
	ldrb    r2, [r1]
	cmp     r2, #0x3
	movne   r0, #0x0
	bxne    r14
	mov     r2, #0x1
	str     r2, [r0, #0x4a0]
	mov     r0, #0x0
	strb    r0, [r1]
LAB_021168e0:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021168ec:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r1, [r0, #0x9c]
	cmp     r1, #0x0
	addne   r13, r13, #0x4
	movne   r0, #0x0
	popne   { r14 }
	bxne    r14
	ldr     r1, =UNK_0211ae04
	ldrb    r3, [r1]
	cmp     r3, #0x3
	bne     LAB_02116940
	ldr     r2, [r0, #0x48c]
	ldr     r1, =states + 0x0a0
	cmp     r2, r1
	beq     LAB_02116940
	bl      FUN_02119454
	add     r13, r13, #0x4
	mov     r0, #0x3
	pop     { r14 }
	bx      r14
LAB_02116940:
	add     r1, r3, #0x0fc
	and     r1, r1, #0x0ff
	cmp     r1, #0x5
	bhi     LAB_02116a38
	ldr     r2, [r0, #0x48c]
	ldr     r1, =states + 0x0a0
	cmp     r2, r1
	bne     LAB_02116a38
	cmp     r3, #0x4
	bne     LAB_02116984
	ldr     r1, =states + 0x0c0
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_02116984:
	cmp     r3, #0x5
	bne     LAB_021169a8
	ldr     r1, =states + 0x0f0
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_021169a8:
	cmp     r3, #0x6
	bne     LAB_021169cc
	ldr     r1, =states + 0x120
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_021169cc:
	cmp     r3, #0x7
	bne     LAB_021169f0
	ldr     r1, =states + 0x020
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_021169f0:
	cmp     r3, #0x8
	bne     LAB_02116a14
	ldr     r1, =states + 0x050
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_02116a14:
	cmp     r3, #0x9
	bne     LAB_02116a38
	ldr     r1, =states + 0x080
	bl      FUN_02119454
	ldr     r0, =UNK_0211ae04
	add     r13, r13, #0x4
	ldrb    r0, [r0]
	pop     { r14 }
	bx      r14
LAB_02116a38:
	mov     r0, #0x0
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116a68:
	push    { r14 }
	sub     r13, r13, #0x0c
	bl      _ZN5Actor13ClosestPlayerEv
	ldr     r1, [r0, #0x64]
	ldr     r0, =#0x0ff3ae000
	cmp     r1, r0
	addlt   r13, r13, #0x0c
	poplt   { r14 }
	bxlt    r14
	mov     r0, #0x0b50000
	rsb     r0, r0, #0x0
	cmp     r1, r0
	addlt   r13, r13, #0x0c
	poplt   { r14 }
	bxlt    r14
	ldr     r0, =#0x0ff598000
	cmp     r1, r0
	movge   r0, #0x0
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116ac4:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	ldr     r2, =CAMERA
	mov     r4, r0
	ldr     r0, [r2]
	mov     r2, r1
	add     r1, r4, #0x5c
	bl      0x0200d8c8
	ldr     r0, [r4, #0x5c]
	add     r3, r4, #0x64
	str     r0, [r13]
	ldr     r0, [r4, #0x60]
	str     r0, [r13, #0x4]
	ldr     r0, [r4, #0x64]
	str     r0, [r13, #0x8]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	addeq   r1, r4, #0x5c
	ldreq   r0, [r1]
	subeq   r0, r0, #0x80000
	streq   r0, [r1]
	addne   r1, r4, #0x5c
	ldrne   r0, [r1]
	addne   r0, r0, #0x80000
	strne   r0, [r1]
	ldr     r1, [r3]
	mov     r0, r4
	add     r2, r1, #0x80000
	mov     r1, #0x1
	str     r2, [r3]
	bl      _ZN5Actor14BigLandingDustEb
	ldr     r0, =#0x143
	add     r1, r4, #0x74
	bl      0x02012694
	ldr     r0, [r13]
	str     r0, [r4, #0x5c]
	ldr     r0, [r13, #0x4]
	str     r0, [r4, #0x60]
	ldr     r0, [r13, #0x8]
	str     r0, [r4, #0x64]
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116b78:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r12, [r0, #0x49c]
	mov     r1, #0x320
	cmp     r12, #0x2
	rsb     r14, r1, #0x0
	moveq   r1, #0x384
	rsbeq   r14, r1, #0x0
	ldr     r1, =UNK_0211abe0
	ldr     r3, [r0, #0x5c]
	ldrb    r2, [r1]
	cmp     r2, #0x3
	subne   r14, r14, #0x50
	mov     r1, r14, lsl #0x0c
	cmp     r3, r1
	strlt   r1, [r0, #0x5c]
	movlt   r1, #0x0
	strlt   r1, [r0, #0x98]
	addlt   r13, r13, #0x4
	movlt   r0, #0x1
	poplt   { r14 }
	bxlt    r14
	mov     r1, #0x320
	cmp     r12, #0x1
	moveq   r1, #0x384
	cmp     r2, #0x3
	addne   r1, r1, #0x50
	mov     r1, r1, lsl #0x0c
	cmp     r3, r1
	strgt   r1, [r0, #0x5c]
	movgt   r1, #0x0
	strgt   r1, [r0, #0x98]
	addgt   r13, r13, #0x4
	movgt   r0, #0x1
	popgt   { r14 }
	bxgt    r14
	ldr     r3, [r0, #0x64]
	ldr     r1, =#0x0ff0ff000
	cmp     r3, r1
	strlt   r1, [r0, #0x64]
	movlt   r1, #0x0
	strlt   r1, [r0, #0x98]
	addlt   r13, r13, #0x4
	movlt   r0, #0x1
	poplt   { r14 }
	bxlt    r14
	ldr     r1, =#0x0ff8c6000
	cmp     r2, #0x3
	addne   r1, r1, #0x8c000
	cmp     r3, r1
	strgt   r1, [r0, #0x64]
	movgt   r1, #0x0
	strgt   r1, [r0, #0x98]
	movgt   r0, #0x1
	movle   r0, #0x0
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116c6c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x0c
	movhi   r0, #0x0
	strhi   r0, [r4, #0x98]
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02116d00
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x7c
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x60]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x7d
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r0, [r4, #0x5c]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r4, #0x60]
	mov     r0, r4
	str     r2, [r13, #0x4]
	ldr     r2, [r4, #0x64]
	str     r2, [r13, #0x8]
	bl      0x0200fd74
	ldr     r0, =#0x146
	add     r1, r4, #0x74
	bl      0x02012694
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02116d00:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116d14:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	mov     r1, #0x0a000
	str     r2, [r0, #0x4a0]
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x98]
	ldr     r1, [r0, #0x49c]
	cmp     r1, #0x2
	bne     LAB_02116d74
	mov     r1, #0x1000
	str     r1, [r13]
	ldr     r1, =_ZN6Eyerok13deadAnimFilesE + 0
	str     r2, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	b       LAB_02116d98
LAB_02116d74:
	mov     r1, #0x1000
	str     r1, [r13]
	ldr     r1, =_ZN6Eyerok13deadAnimFilesE + 8
	str     r2, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
LAB_02116d98:
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116db0:
	push    { r4, r14 }
	sub     r13, r13, #0x20
	mov     r4, r0
	ldr     r1, [r4, #0x4a0]
	cmp     r1, #0x5
	addls   r15, r15, r1, lsl #0x2
	b       LAB_02117140
	b       LAB_02116de4
	b       LAB_02116df4
	b       LAB_02117080
	b       LAB_02116f98
	b       LAB_021170a4
	b       LAB_02117128
LAB_02116de4:
	bl      FUN_021166c8
	mov     r0, #0x1
	str     r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_02116df4:
	ldr     r1, [r4, #0x498]
	cmp     r1, #0x0
	bne     LAB_02116f1c
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02116ea8
	add     r2, r0, #0x5c
	ldr     r0, [r2]
	ldr     r1, =#0x4bc
	str     r0, [r4, #0x4bc]
	ldr     r0, [r2, #0x4]
	mov     r3, #0x0
	str     r0, [r4, #0x4c0]
	ldr     r2, [r2, #0x8]
	add     r0, r4, #0x5c
	str     r2, [r4, #0x4c4]
	str     r3, [r13, #0x10]
	mov     r2, #0x3e8000
	add     r1, r4, r1
	str     r3, [r13, #0x8]
	str     r3, [r13, #0x0c]
	str     r3, [r13, #0x14]
	str     r3, [r13, #0x18]
	str     r3, [r13, #0x1c]
	str     r2, [r13, #0x10]
	bl      Vec3_HorzAngle
	mov     r1, r0
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x8
	add     r2, r13, #0x14
	bl      MulVec3Mat4x3
	ldr     r0, =#0x4bc
	ldr     r1, =#0x4c4
	add     r12, r4, r0
	ldr     r3, [r12]
	ldr     r0, [r13, #0x14]
	add     r2, r4, r1
	add     r0, r3, r0
	str     r0, [r12]
	ldr     r1, [r2]
	ldr     r0, [r13, #0x1c]
	add     r0, r1, r0
	str     r0, [r2]
LAB_02116ea8:
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_02116ec8
	add     r1, r4, #0x74
	mov     r0, #0x140
	bl      0x02012694
LAB_02116ec8:
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_02116ef0
	mov     r0, r4
	bl      FUN_021164ec
	add     r1, r4, #0x74
	mov     r0, #0x144
	bl      0x02012694
LAB_02116ef0:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzAngle
	mov     r1, r0
	mov     r12, #0x200
	add     r0, r4, #0x8e
	mov     r2, #0x2
	mov     r3, #0x400
	str     r12, [r13]
	bl      ApproachAngle
LAB_02116f1c:
	ldr     r0, [r4, #0x498]
	cmp     r0, #0x1
	bne     LAB_02117140
	mov     r0, r4
	bl      FUN_0211603c
	cmp     r0, #0x0
	beq     LAB_02116f48
	cmp     r0, #0x1
	moveq   r0, #0x2
	streq   r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_02116f48:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x37000
	bl      0x0203b7dc
	mov     r0, r4
	bl      FUN_02116b78
	cmp     r0, #0x1
	beq     LAB_02116f84
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x37000
	bgt     LAB_02117140
LAB_02116f84:
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x3
	str     r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_02116f98:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02117140
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02116fc8
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_02116fc8:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_02117008
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c08
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	b       LAB_02117038
LAB_02117008:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112d48
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
LAB_02117038:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	mov     r0, #0x4
	str     r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_02117080:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02117140
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x3
	str     r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_021170a4:
	bl      FUN_021162e8
	mov     r12, #0x200
	add     r0, r4, #0x8e
	mov     r1, #0x0
	mov     r2, #0x2
	mov     r3, #0x400
	str     r12, [r13]
	bl      ApproachAngle
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x37000
	bl      0x0203b7dc
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x37000
	bgt     LAB_02117140
	ldr     r1, [r4, #0x4a4]
	ldr     r0, =UNK_0211ae08
	str     r1, [r4, #0x5c]
	ldr     r1, [r4, #0x4a8]
	mov     r2, #0x2
	str     r1, [r4, #0x60]
	ldr     r3, [r4, #0x4ac]
	mov     r1, #0x0
	str     r3, [r4, #0x64]
	strb    r2, [r0]
	strh    r1, [r4, #0x8e]
	mov     r0, #0x5
	str     r0, [r4, #0x4a0]
	b       LAB_02117140
LAB_02117128:
	ldr     r1, =UNK_0211ae04
	ldrb    r1, [r1]
	cmp     r1, #0x9
	beq     LAB_02117140
	ldr     r1, =states + 0x0a0
	bl      FUN_02119454
LAB_02117140:
	mov     r0, #0x1
	add     r13, r13, #0x20
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117190:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021171b0:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, [r4, #0x4a0]
	cmp     r1, #0x5
	addls   r15, r15, r1, lsl #0x2
	b       LAB_0211757c
	b       LAB_021171e0
	b       LAB_021172d8
	b       LAB_02117394
	b       LAB_0211740c
	b       LAB_021174c0
	b       LAB_0211755c
LAB_021171e0:
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_0211757c
	add     r3, r0, #0x5c
	ldr     r1, [r3]
	ldr     r0, =#0x4c4
	str     r1, [r4, #0x4bc]
	ldr     r1, [r3, #0x4]
	add     r2, r4, r0
	str     r1, [r4, #0x4c0]
	ldr     r1, [r3, #0x8]
	ldr     r0, =#0x0ff3ae000
	str     r1, [r4, #0x4c4]
	ldr     r1, [r2]
	sub     r1, r1, #0x0c8000
	str     r1, [r2]
	ldr     r1, [r4, #0x4c4]
	cmp     r1, r0
	strlt   r0, [r4, #0x4c4]
	blt     LAB_0211723c
	ldr     r0, =#0x0ff8c6000
	cmp     r1, r0
	strgt   r0, [r4, #0x4c4]
LAB_0211723c:
	ldr     r0, =UNK_0211ae0c
	ldrb    r0, [r0]
	cmp     r0, #0x1
	bne     LAB_02117284
	mov     r0, #0x4000
	rsb     r0, r0, #0x0
	strh    r0, [r4, #0x94]
	mov     r0, #0x334000
	str     r0, [r4, #0x4bc]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_021172b0
	ldr     r0, =#0x4bc
	add     r1, r4, r0
	ldr     r0, [r1]
	sub     r0, r0, #0x0f2000
	str     r0, [r1]
	b       LAB_021172b0
LAB_02117284:
	mov     r1, #0x4000
	ldr     r0, =#0x0ffe8e000
	strh    r1, [r4, #0x94]
	str     r0, [r4, #0x4bc]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	ldreq   r0, =#0x4bc
	addeq   r1, r4, r0
	ldreq   r0, [r1]
	subeq   r0, r0, #0x0f2000
	streq   r0, [r1]
LAB_021172b0:
	add     r1, r4, #0x74
	mov     r0, #0x144
	bl      0x02012694
	ldr     r2, [r4, #0x4a8]
	ldr     r0, =#0x1c2000
	mov     r1, #0x1
	add     r0, r2, r0
	str     r0, [r4, #0x4c0]
	str     r1, [r4, #0x4a0]
	b       LAB_0211757c
LAB_021172d8:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b89c
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_Dist
	cmp     r0, #0x28000
	bgt     LAB_0211757c
	ldr     r1, [r4, #0x4bc]
	ldr     r0, =UNK_0211ae00
	str     r1, [r4, #0x5c]
	ldr     r1, [r4, #0x4c0]
	str     r1, [r4, #0x60]
	ldr     r1, [r4, #0x4c4]
	str     r1, [r4, #0x64]
	ldrb    r2, [r0]
	ldr     r1, [r4, #0x49c]
	orr     r1, r2, r1
	strb    r1, [r0]
	ldrb    r0, [r0]
	cmp     r0, #0x3
	bne     LAB_0211757c
	add     r0, r4, #0x400
	mov     r2, #0x0a
	ldr     r1, =UNK_0211ae0c
	strh    r2, [r0, #0x0d0]
	ldrb    r1, [r1]
	cmp     r1, #0x1
	bne     LAB_0211736c
	ldr     r1, [r4, #0x49c]
	cmp     r1, #0x2
	moveq   r1, #0x12
	streqh  r1, [r0, #0x0d0]
	b       LAB_0211737c
LAB_0211736c:
	ldr     r1, [r4, #0x49c]
	cmp     r1, #0x1
	moveq   r1, #0x12
	streqh  r1, [r0, #0x0d0]
LAB_0211737c:
	ldr     r1, [r4, #0x4a8]
	mov     r0, #0x2
	add     r1, r1, #0x1a000
	str     r1, [r4, #0x4c0]
	str     r0, [r4, #0x4a0]
	b       LAB_0211757c
LAB_02117394:
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	bne     LAB_0211757c
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x32000
	bl      0x0203b89c
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_Dist
	cmp     r0, #0x32000
	bgt     LAB_0211757c
	ldr     r1, [r4, #0x4bc]
	mov     r0, r4
	str     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x4c0]
	mov     r1, #0x7d0000
	str     r2, [r4, #0x60]
	ldr     r2, [r4, #0x4c4]
	str     r2, [r4, #0x64]
	bl      FUN_02116ac4
	add     r0, r4, #0x400
	mov     r1, #0x0f
	strh    r1, [r0, #0x0d0]
	mov     r0, #0x3
	str     r0, [r4, #0x4a0]
	b       LAB_0211757c
LAB_0211740c:
	add     r1, r4, #0x400
	ldrh    r1, [r1, #0x0d0]
	cmp     r1, #0x0
	beq     LAB_0211744c
	cmp     r1, #0x1
	bne     LAB_0211757c
	mov     r1, #0x7c000
	mov     r0, #0x14000
	str     r1, [r4, #0x0a8]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x1e000
	str     r0, [r4, #0x98]
	mov     r0, #0x2000000
	str     r0, [r4, #0x0b0]
	b       LAB_0211757c
LAB_0211744c:
	ldr     r1, [r4, #0x9c]
	cmp     r1, #0x0
	beq     LAB_0211757c
	ldr     r2, [r4, #0x4a8]
	ldr     r1, [r4, #0x60]
	cmp     r2, r1
	blt     LAB_0211757c
	str     r2, [r4, #0x60]
	mov     r2, #0x0
	str     r2, [r4, #0x0a8]
	str     r2, [r4, #0x9c]
	mov     r1, #0x7d0000
	str     r2, [r4, #0x98]
	bl      FUN_02116ac4
	ldr     r1, =#0x494
	add     r0, r4, #0x400
	mov     r2, #0x0f
	add     r1, r4, r1
	strh    r2, [r0, #0x0d0]
	ldr     r0, [r1]
	add     r0, r0, #0x1
	str     r0, [r1]
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x3
	movlt   r0, #0x3
	strlt   r0, [r4, #0x4a0]
	movge   r0, #0x4
	strge   r0, [r4, #0x4a0]
	b       LAB_0211757c
LAB_021174c0:
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x1
	ldreq   r0, =UNK_0211ae00
	ldreq   r1, [r4, #0x49c]
	ldreqb  r2, [r0]
	eoreq   r1, r2, r1
	streqb  r1, [r0]
	ldr     r0, =UNK_0211ae00
	ldrb    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_0211757c
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b7dc
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x28000
	bgt     LAB_0211757c
	ldr     r0, =UNK_0211ae0c
	mov     r1, #0x0
	strb    r1, [r0]
	ldr     r1, [r4, #0x4a4]
	ldr     r0, =UNK_0211ae08
	str     r1, [r4, #0x5c]
	ldr     r2, [r4, #0x4a8]
	mov     r1, #0x5
	str     r2, [r4, #0x60]
	ldr     r2, [r4, #0x4ac]
	str     r2, [r4, #0x64]
	ldrb    r2, [r0]
	add     r2, r2, #0x1
	strb    r2, [r0]
	str     r1, [r4, #0x4a0]
	b       LAB_0211757c
LAB_0211755c:
	ldr     r1, =UNK_0211ae04
	ldrb    r1, [r1]
	cmp     r1, #0x8
	beq     LAB_0211757c
	ldr     r1, =states + 0x0a0
	mov     r2, #0x0
	str     r2, [r4, #0x0b0]
	bl      FUN_02119454
LAB_0211757c:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021175bc:
	mov     r3, #0x0
	str     r3, [r0, #0x494]
	str     r3, [r0, #0x498]
	add     r1, r0, #0x400
	ldr     r2, =UNK_0211ae00
	strh    r3, [r1, #0x0d0]
	strb    r3, [r2]
	str     r3, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021175e8:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x14
	mov     r4, r0
	ldr     r1, [r4, #0x4a0]
	cmp     r1, #0x8
	addls   r15, r15, r1, lsl #0x2
	b       LAB_02117b68
	b       LAB_02117628
	b       LAB_02117714
	b       LAB_02117780
	b       LAB_02117888
	b       LAB_02117908
	b       LAB_02117988
	b       LAB_021179ac
	b       LAB_02117aac
	b       LAB_02117b48
LAB_02117628:
	ldr     r1, =UNK_0211ae0c
	ldr     r2, [r4, #0x49c]
	ldrb    r1, [r1]
	cmp     r1, r2
	bne     LAB_021176f4
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_021176cc
	add     r3, r0, #0x5c
	ldr     r1, [r3]
	ldr     r0, =#0x4c4
	str     r1, [r4, #0x4bc]
	ldr     r2, [r3, #0x4]
	add     r1, r4, r0
	str     r2, [r4, #0x4c0]
	ldr     r0, [r3, #0x8]
	str     r0, [r4, #0x4c4]
	ldr     r0, [r1]
	sub     r0, r0, #0x0c8000
	str     r0, [r1]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	ldrne   r0, =#0x4bc
	addne   r1, r4, r0
	ldrne   r0, [r1]
	subne   r0, r0, #0x58000
	strne   r0, [r1]
	bne     LAB_021176ac
	ldr     r0, =#0x4bc
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x58000
	str     r0, [r1]
LAB_021176ac:
	ldr     r1, [r4, #0x4c4]
	ldr     r0, =#0x0ff3ae000
	cmp     r1, r0
	strlt   r0, [r4, #0x4c4]
	blt     LAB_021176cc
	ldr     r0, =#0x0ff8c6000
	cmp     r1, r0
	strgt   r0, [r4, #0x4c4]
LAB_021176cc:
	add     r1, r4, #0x74
	mov     r0, #0x144
	bl      0x02012694
	ldr     r2, [r4, #0x4a8]
	ldr     r0, =#0x1c2000
	mov     r1, #0x1
	add     r0, r2, r0
	str     r0, [r4, #0x4c0]
	str     r1, [r4, #0x4a0]
	b       LAB_02117b68
LAB_021176f4:
	add     r1, r4, #0x400
	ldrh    r1, [r1, #0x0d0]
	cmp     r1, #0x0
	bne     LAB_02117b68
	bl      FUN_021166c8
	mov     r0, #0x4
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117714:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b89c
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_Dist
	cmp     r0, #0x28000
	bgt     LAB_02117b68
	add     r0, r4, #0x400
	mov     r1, #0x0a
	strh    r1, [r0, #0x0d0]
	mov     r0, #0x2000000
	str     r0, [r4, #0x0b0]
	ldr     r1, [r4, #0x4bc]
	mov     r0, #0x2
	str     r1, [r4, #0x5c]
	ldr     r1, [r4, #0x4c0]
	str     r1, [r4, #0x60]
	ldr     r1, [r4, #0x4c4]
	str     r1, [r4, #0x64]
	ldr     r1, [r4, #0x4a8]
	str     r1, [r4, #0x4c0]
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117780:
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	bne     LAB_021177a4
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x32000
	bl      0x0203b89c
LAB_021177a4:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_Dist
	cmp     r0, #0x32000
	bgt     LAB_02117b68
	mov     r0, r4
	mov     r1, #0x7d0000
	bl      FUN_02116ac4
	ldr     r0, [r4, #0x4bc]
	add     r1, r4, #0x400
	str     r0, [r4, #0x5c]
	ldr     r0, [r4, #0x4c0]
	mov     r2, #0x0a
	str     r0, [r4, #0x60]
	ldr     r3, [r4, #0x4c4]
	mov     r0, r4
	str     r3, [r4, #0x64]
	strh    r2, [r1, #0x0d0]
	mov     r1, #0x7
	str     r1, [r4, #0x4a0]
	bl      FUN_02116a68
	cmp     r0, #0x0
	bne     LAB_02117b68
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02117b68
	add     r3, r0, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x8
	str     r0, [r13, #0x8]
	ldr     r0, [r3, #0x4]
	add     r2, r4, #0x400
	str     r0, [r13, #0x0c]
	ldr     r3, [r3, #0x8]
	add     r0, r4, #0x5c
	str     r3, [r13, #0x10]
	mov     r3, #0x24
	strh    r3, [r2, #0x0d0]
	bl      Vec3_HorzDist
	cmp     r0, #0x400000
	bge     LAB_02117b68
	ldr     r1, [r13, #0x8]
	ldr     r0, [r4, #0x5c]
	cmp     r1, r0
	movlt   r0, #0x4000
	rsblt   r0, r0, #0x0
	strlth  r0, [r4, #0x94]
	movge   r0, #0x4000
	strgeh  r0, [r4, #0x94]
	mov     r0, #0x0
	str     r0, [r4, #0x4c8]
	str     r0, [r4, #0x98]
	mov     r0, #0x3
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117888:
	ldr     r1, [r4, #0x4c8]
	ldr     r0, =#0x2710
	cmp     r1, r0
	bge     LAB_021178d0
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	ldreq   r0, =#0x4c8
	addeq   r1, r4, r0
	ldreq   r0, [r1]
	addeq   r0, r0, #0x130
	streq   r0, [r1]
	beq     LAB_021178d0
	ldr     r0, =#0x4c8
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x1a
	str     r0, [r1]
LAB_021178d0:
	ldr     r2, [r4, #0x4c8]
	add     r0, r4, #0x98
	mov     r1, #0x258000
	bl      _Z14ApproachLinearRiii
	mov     r0, r4
	bl      FUN_02116b78
	cmp     r0, #0x1
	bne     LAB_02117b68
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	strh    r0, [r4, #0x94]
	mov     r0, #0x7
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117908:
	bl      FUN_021164ec
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_0211792c
	add     r1, r4, #0x74
	mov     r0, #0x140
	bl      0x02012694
LAB_0211792c:
	ldr     r0, [r4, #0x498]
	cmp     r0, #0x1
	bne     LAB_02117964
	mov     r0, r4
	bl      FUN_0211603c
	mov     r5, r0
	mov     r0, r4
	bl      FUN_02116390
	cmp     r5, #0x0
	beq     LAB_02117964
	cmp     r5, #0x1
	moveq   r0, #0x5
	streq   r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117964:
	ldr     r0, =UNK_0211ae08
	ldrb    r0, [r0]
	cmp     r0, #0x0
	beq     LAB_02117b68
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x6
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117988:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02117b68
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x6
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_021179ac:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02117b68
	mov     r0, r4
	bl      FUN_021162e8
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_021179e4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_021179e4:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_02117a24
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c08
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	b       LAB_02117a54
LAB_02117a24:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112d48
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
LAB_02117a54:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	ldr     r0, =UNK_0211ae08
	mov     r1, #0x8
	ldrb    r2, [r0]
	add     r2, r2, #0x1
	strb    r2, [r0]
	str     r1, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117aac:
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	bne     LAB_02117b68
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b7dc
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x28000
	bgt     LAB_02117b68
	ldr     r2, =UNK_0211ae0c
	ldr     r3, [r4, #0x49c]
	ldrb    r12, [r2]
	ldr     r1, =UNK_0211ae08
	ldr     r0, =UNK_0211abe0
	eor     r3, r12, r3
	strb    r3, [r2]
	ldr     r2, [r4, #0x4a4]
	str     r2, [r4, #0x5c]
	ldr     r2, [r4, #0x4a8]
	str     r2, [r4, #0x60]
	ldr     r2, [r4, #0x4ac]
	str     r2, [r4, #0x64]
	ldrb    r2, [r1]
	ldrb    r0, [r0]
	add     r2, r2, #0x1
	strb    r2, [r1]
	cmp     r0, #0x3
	ldrneb  r0, [r1]
	addne   r0, r0, #0x1
	strneb  r0, [r1]
	mov     r0, #0x8
	str     r0, [r4, #0x4a0]
	b       LAB_02117b68
LAB_02117b48:
	ldr     r1, =UNK_0211ae04
	ldrb    r1, [r1]
	cmp     r1, #0x7
	beq     LAB_02117b68
	ldr     r1, =states + 0x0a0
	mov     r2, #0x0
	str     r2, [r4, #0x0b0]
	bl      FUN_02119454
LAB_02117b68:
	mov     r0, #0x1
	add     r13, r13, #0x14
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117bd0:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02117bf0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x14
	mov     r4, r0
	ldr     r1, [r4, #0x4a0]
	cmp     r1, #0x7
	addls   r15, r15, r1, lsl #0x2
	b       LAB_021180fc
	b       LAB_02117c2c
	b       LAB_02117d6c
	b       LAB_02117e34
	b       LAB_02117eb4
	b       LAB_02117f34
	b       LAB_02117f58
	b       LAB_02118058
	b       LAB_021180e4
LAB_02117c2c:
	ldr     r1, =UNK_0211ae0c
	ldr     r2, [r4, #0x49c]
	ldrb    r1, [r1]
	cmp     r1, r2
	bne     LAB_02117d4c
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02117c9c
	add     r3, r0, #0x5c
	ldr     r1, [r3]
	ldr     r0, =#0x4c4
	str     r1, [r4, #0x4bc]
	ldr     r1, [r3, #0x4]
	add     r2, r4, r0
	str     r1, [r4, #0x4c0]
	ldr     r1, [r3, #0x8]
	ldr     r0, =#0x0ff3ae000
	str     r1, [r4, #0x4c4]
	ldr     r1, [r2]
	sub     r1, r1, #0x0c8000
	str     r1, [r2]
	ldr     r1, [r4, #0x4c4]
	cmp     r1, r0
	strlt   r0, [r4, #0x4c4]
	blt     LAB_02117c9c
	ldr     r0, =#0x0ff8c6000
	cmp     r1, r0
	strgt   r0, [r4, #0x4c4]
LAB_02117c9c:
	ldr     r1, [r4, #0x4c4]
	ldr     r0, =#0x0ff598000
	cmp     r1, r0
	ble     LAB_02117d34
	ldr     r0, [r4, #0x4bc]
	cmp     r0, #0x0
	bge     LAB_02117cf8
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_02117ce0
	ldr     r0, =#0x4bc
	ldr     r1, =#0x1c2000
	add     r2, r4, r0
	ldr     r0, [r2]
	add     r0, r0, r1
	str     r0, [r2]
	b       LAB_02117d34
LAB_02117ce0:
	ldr     r0, =#0x4bc
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x12c000
	str     r0, [r1]
	b       LAB_02117d34
LAB_02117cf8:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_02117d1c
	ldr     r0, =#0x4bc
	add     r1, r4, r0
	ldr     r0, [r1]
	sub     r0, r0, #0x12c000
	str     r0, [r1]
	b       LAB_02117d34
LAB_02117d1c:
	ldr     r0, =#0x4bc
	ldr     r1, =#0x1c2000
	add     r2, r4, r0
	ldr     r0, [r2]
	sub     r0, r0, r1
	str     r0, [r2]
LAB_02117d34:
	add     r1, r4, #0x74
	mov     r0, #0x144
	bl      0x02012694
	mov     r0, #0x1
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117d4c:
	add     r1, r4, #0x400
	ldrh    r1, [r1, #0x0d0]
	cmp     r1, #0x0
	bne     LAB_021180fc
	bl      FUN_021166c8
	mov     r0, #0x3
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117d6c:
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b7dc
	ldr     r1, =#0x4bc
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x28000
	bgt     LAB_021180fc
	mov     r1, #0x6
	mov     r0, r4
	str     r1, [r4, #0x4a0]
	bl      FUN_02116a68
	cmp     r0, #0x0
	bne     LAB_021180fc
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_021180fc
	add     r3, r0, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x8
	str     r0, [r13, #0x8]
	ldr     r0, [r3, #0x4]
	add     r2, r4, #0x400
	str     r0, [r13, #0x0c]
	ldr     r3, [r3, #0x8]
	add     r0, r4, #0x5c
	str     r3, [r13, #0x10]
	mov     r3, #0x24
	strh    r3, [r2, #0x0d0]
	bl      Vec3_HorzDist
	cmp     r0, #0x400000
	bge     LAB_021180fc
	ldr     r1, [r13, #0x8]
	ldr     r0, [r4, #0x5c]
	cmp     r1, r0
	movlt   r0, #0x4000
	rsblt   r0, r0, #0x0
	strlth  r0, [r4, #0x94]
	movge   r0, #0x4000
	strgeh  r0, [r4, #0x94]
	mov     r0, #0x0
	str     r0, [r4, #0x4c8]
	str     r0, [r4, #0x98]
	mov     r0, #0x2
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117e34:
	ldr     r1, [r4, #0x4c8]
	ldr     r0, =#0x2710
	cmp     r1, r0
	bge     LAB_02117e7c
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	ldreq   r0, =#0x4c8
	addeq   r1, r4, r0
	ldreq   r0, [r1]
	addeq   r0, r0, #0x130
	streq   r0, [r1]
	beq     LAB_02117e7c
	ldr     r0, =#0x4c8
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x1a
	str     r0, [r1]
LAB_02117e7c:
	ldr     r2, [r4, #0x4c8]
	add     r0, r4, #0x98
	mov     r1, #0x258000
	bl      _Z14ApproachLinearRiii
	mov     r0, r4
	bl      FUN_02116b78
	cmp     r0, #0x1
	bne     LAB_021180fc
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	strh    r0, [r4, #0x94]
	mov     r0, #0x6
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117eb4:
	bl      FUN_021164ec
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_02117ed8
	add     r1, r4, #0x74
	mov     r0, #0x140
	bl      0x02012694
LAB_02117ed8:
	ldr     r0, [r4, #0x498]
	cmp     r0, #0x1
	bne     LAB_02117f10
	mov     r0, r4
	bl      FUN_0211603c
	mov     r5, r0
	mov     r0, r4
	bl      FUN_02116390
	cmp     r5, #0x0
	beq     LAB_02117f10
	cmp     r5, #0x1
	moveq   r0, #0x4
	streq   r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117f10:
	ldr     r0, =UNK_0211ae08
	ldrb    r0, [r0]
	cmp     r0, #0x0
	beq     LAB_021180fc
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x5
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117f34:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_021180fc
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x5
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02117f58:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_021180fc
	mov     r0, r4
	bl      FUN_021162e8
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02117f90
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_02117f90:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_02117fd0
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c08
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	b       LAB_02118000
LAB_02117fd0:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112d48
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
LAB_02118000:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	ldr     r0, =UNK_0211ae08
	mov     r1, #0x7
	ldrb    r2, [r0]
	add     r2, r2, #0x1
	strb    r2, [r0]
	str     r1, [r4, #0x4a0]
	b       LAB_021180fc
LAB_02118058:
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x28000
	bl      0x0203b7dc
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x28000
	bgt     LAB_021180fc
	ldr     r2, =UNK_0211ae0c
	ldr     r3, [r4, #0x49c]
	ldrb    r12, [r2]
	ldr     r1, =UNK_0211ae08
	ldr     r0, =UNK_0211abe0
	eor     r3, r12, r3
	strb    r3, [r2]
	ldr     r2, [r4, #0x4a4]
	str     r2, [r4, #0x5c]
	ldr     r2, [r4, #0x4a8]
	str     r2, [r4, #0x60]
	ldr     r2, [r4, #0x4ac]
	str     r2, [r4, #0x64]
	ldrb    r2, [r1]
	ldrb    r0, [r0]
	add     r2, r2, #0x1
	strb    r2, [r1]
	cmp     r0, #0x3
	ldrneb  r0, [r1]
	addne   r0, r0, #0x1
	strneb  r0, [r1]
	mov     r0, #0x7
	str     r0, [r4, #0x4a0]
	b       LAB_021180fc
LAB_021180e4:
	ldr     r1, =UNK_0211ae04
	ldrb    r1, [r1]
	cmp     r1, #0x6
	beq     LAB_021180fc
	ldr     r1, =states + 0x0a0
	bl      FUN_02119454
LAB_021180fc:
	mov     r0, #0x1
	add     r13, r13, #0x14
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118168:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118188:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r1, [r4, #0x4a0]
	cmp     r1, #0x5
	addls   r15, r15, r1, lsl #0x2
	b       LAB_02118474
	b       LAB_021181bc
	b       LAB_02118218
	b       LAB_02118280
	b       LAB_02118330
	b       LAB_02118354
	b       LAB_02118454
LAB_021181bc:
	add     r1, r4, #0x400
	ldrh    r1, [r1, #0x0d0]
	cmp     r1, #0x0
	bne     LAB_02118474
	ldr     r1, =UNK_0211ae0c
	ldr     r2, [r4, #0x49c]
	ldrb    r1, [r1]
	cmp     r1, r2
	bne     LAB_02118208
	mov     r0, #0x0a000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x64000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x2000000
	str     r0, [r4, #0x0b0]
	mov     r0, #0x1
	str     r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118208:
	bl      FUN_021166c8
	mov     r0, #0x2
	str     r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118218:
	ldr     r1, [r4, #0x9c]
	cmp     r1, #0x0
	beq     LAB_02118474
	ldr     r2, [r4, #0x4a8]
	ldr     r1, [r4, #0x60]
	cmp     r2, r1
	blt     LAB_02118474
	str     r2, [r4, #0x60]
	mov     r2, #0x0
	str     r2, [r4, #0x0a8]
	mov     r1, #0x7d0000
	str     r2, [r4, #0x9c]
	bl      FUN_02116ac4
	ldr     r1, =UNK_0211ae08
	ldr     r0, =UNK_0211abe0
	ldrb    r2, [r1]
	ldrb    r0, [r0]
	add     r2, r2, #0x1
	strb    r2, [r1]
	cmp     r0, #0x3
	ldrneb  r0, [r1]
	addne   r0, r0, #0x1
	strneb  r0, [r1]
	mov     r0, #0x5
	str     r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118280:
	ldr     r1, [r4, #0x498]
	cmp     r1, #0x1
	bne     LAB_021182d4
	ldr     r1, =UNK_0211ae08
	ldrb    r1, [r1]
	cmp     r1, #0x0
	beq     LAB_021182d4
	ldr     r1, [r4, #0x494]
	cmp     r1, #0x14
	ble     LAB_021182c0
	mov     r1, #0x0
	str     r1, [r4, #0x494]
	bl      FUN_021165cc
	mov     r0, #0x4
	str     r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_021182c0:
	ldr     r0, =#0x494
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x1
	str     r0, [r1]
LAB_021182d4:
	ldr     r0, [r4, #0x3b8]
	mov     r0, r0, asr #0x0c
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_021182f4
	add     r1, r4, #0x74
	mov     r0, #0x140
	bl      0x02012694
LAB_021182f4:
	mov     r0, r4
	bl      FUN_021164ec
	ldr     r0, [r4, #0x498]
	cmp     r0, #0x1
	bne     LAB_02118474
	mov     r0, r4
	bl      FUN_02116390
	mov     r0, r4
	bl      FUN_0211603c
	cmp     r0, #0x0
	beq     LAB_02118474
	cmp     r0, #0x1
	moveq   r0, #0x3
	streq   r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118330:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02118474
	mov     r0, r4
	bl      FUN_021165cc
	mov     r0, #0x4
	str     r0, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118354:
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02118474
	mov     r0, r4
	bl      FUN_021162e8
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_0211838c
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_0211838c:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_021183cc
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c08
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	b       LAB_021183fc
LAB_021183cc:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112d48
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
LAB_021183fc:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	ldr     r0, =UNK_0211ae08
	mov     r1, #0x5
	ldrb    r2, [r0]
	add     r2, r2, #0x1
	strb    r2, [r0]
	str     r1, [r4, #0x4a0]
	b       LAB_02118474
LAB_02118454:
	ldr     r1, =UNK_0211ae04
	ldrb    r1, [r1]
	cmp     r1, #0x5
	beq     LAB_02118474
	ldr     r1, =states + 0x0a0
	mov     r2, #0x0
	str     r2, [r4, #0x0b0]
	bl      FUN_02119454
LAB_02118474:
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021184c0:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021184e0:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168ec
	cmp     r0, #0x0
	beq     LAB_02118520
	mov     r0, r4
	bl      FUN_021168ec
	cmp     r0, #0x4
	beq     LAB_02118520
	mov     r1, #0x0
	mov     r0, r4
	str     r1, [r4, #0x0b0]
	bl      FUN_021162e8
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02118520:
	mov     r0, r4
	bl      FUN_0211632c
	ldr     r0, [r4, #0x4a0]
	cmp     r0, #0x0
	beq     LAB_02118540
	cmp     r0, #0x1
	beq     LAB_0211857c
	b       LAB_021185d4
LAB_02118540:
	ldr     r0, =UNK_0211ae0c
	ldr     r1, [r4, #0x49c]
	ldrb    r0, [r0]
	cmp     r0, r1
	bne     LAB_021185d4
	mov     r0, #0x14000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x64000
	str     r0, [r4, #0x0a8]
	add     r1, r4, #0x4a0
	ldr     r0, [r1]
	add     r0, r0, #0x1
	str     r0, [r1]
	b       LAB_021185d4
LAB_0211857c:
	ldr     r0, [r4, #0x9c]
	cmp     r0, #0x0
	beq     LAB_021185d4
	ldr     r1, [r4, #0x4a8]
	ldr     r0, [r4, #0x60]
	cmp     r1, r0
	blt     LAB_021185d4
	str     r1, [r4, #0x60]
	mov     r2, #0x0
	str     r2, [r4, #0x0a8]
	mov     r0, r4
	mov     r1, #0x7d0000
	str     r2, [r4, #0x9c]
	bl      FUN_02116ac4
	ldr     r0, =UNK_0211ae0c
	ldr     r3, [r4, #0x49c]
	ldrb    r1, [r0]
	ands    r2, r1, r3
	eorne   r1, r1, r3
	strneb  r1, [r0]
	mov     r0, #0x0
	str     r0, [r4, #0x4a0]
LAB_021185d4:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021185e4:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118604:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168ec
	cmp     r0, #0x0
	beq     LAB_02118644
	ldr     r1, =UNK_0211ae0c
	ldr     r0, =UNK_0211abe0
	ldrb    r3, [r1]
	ldr     r2, [r4, #0x49c]
	ldrb    r0, [r0]
	eor     r2, r3, r2
	strb    r2, [r1]
	cmp     r0, #0x3
	ldrneb  r0, [r1]
	orrne   r0, r0, #0x3
	strneb  r0, [r1]
LAB_02118644:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118658:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118678:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	bne     LAB_021186f8
	ldr     r0, =UNK_0211ae04
	ldrb    r0, [r0]
	cmp     r0, #0x2
	bne     LAB_021186ec
	mov     r0, #0x1000
	str     r0, [r4, #0x3bc]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	movne   r1, #0x0a000
	movne   r0, #0x800
	strne   r1, [r4, #0x0a8]
	rsbne   r0, r0, #0x0
	strne   r0, [r4, #0x9c]
	bne     LAB_021186d8
	mov     r1, #0x2d000
	mov     r0, #0x2000
	str     r1, [r4, #0x0a8]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
LAB_021186d8:
	mov     r2, #0x1
	add     r1, r4, #0x74
	mov     r0, #0x144
	str     r2, [r4, #0x494]
	bl      0x02012694
LAB_021186ec:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_021186f8:
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	mov     r2, #0x14000
	bl      0x0203b7dc
	ldr     r0, [r4, #0x9c]
	cmp     r0, #0x0
	beq     LAB_02118744
	ldr     r1, [r4, #0x4a8]
	ldr     r0, [r4, #0x60]
	cmp     r1, r0
	blt     LAB_02118744
	str     r1, [r4, #0x60]
	mov     r2, #0x0
	str     r2, [r4, #0x0a8]
	mov     r0, r4
	mov     r1, #0x7d0000
	str     r2, [r4, #0x9c]
	bl      FUN_02116ac4
LAB_02118744:
	ldr     r0, [r4, #0x9c]
	cmp     r0, #0x0
	bne     LAB_021187a8
	ldr     r1, =#0x4a4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzDist
	cmp     r0, #0x14000
	bgt     LAB_021187a8
	add     r0, r4, #0x3b0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_021187a8
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	ldr     r2, =UNK_0211ae0c
	ldr     r3, [r4, #0x49c]
	ldrb    r12, [r2]
	ldr     r1, =states + 0x0a0
	mov     r0, r4
	orr     r3, r12, r3
	strb    r3, [r2]
	bl      FUN_02119454
LAB_021187a8:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021187c8:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	bne     LAB_02118830
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 0
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 0
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	b       LAB_0211887c
LAB_02118830:
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 8
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x360
	mov     r2, #0x4
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r2, #0x0
	ldr     r0, =#0x448
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 8
	str     r2, [r13]
	ldr     r1, [r1, #0x4]
	add     r0, r4, r0
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
LAB_0211887c:
	mov     r0, #0x0
	str     r0, [r4, #0x3bc]
	str     r0, [r4, #0x494]
	str     r0, [r4, #0x498]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021188b0:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r1, =UNK_0211abe0
	ldrb    r1, [r1]
	cmp     r1, #0x0
	bne     LAB_021188ec
	ldr     r1, =states + 0x0e0
	add     r2, r0, #0x400
	mov     r3, #0x64
	strh    r3, [r2, #0x0d2]
	bl      FUN_02119454
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r14 }
	bx      r14
LAB_021188ec:
	ldr     r1, =UNK_0211ae08
	ldrb    r1, [r1]
	cmp     r1, #0x2
	bcc     LAB_02118910
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x3
	ldr     r1, =states + 0x100
	strb    r3, [r2]
	bl      FUN_02119454
LAB_02118910:
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118934:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118954:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	mov     r3, #0x0
	ldr     r2, =UNK_0211ae10
	strb    r3, [r4, #0x4d9]
	ldr     r1, =states + 0x070
	mov     r0, r4
	strb    r3, [r2]
	bl      FUN_02119454
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021189a0:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021189c0:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x1f
	ands    r0, r0, #0x1
	ldreq   r0, =UNK_0211ae0c
	moveq   r1, #0x2
	streqb  r1, [r0]
	ldrne   r0, =UNK_0211ae0c
	movne   r1, #0x1
	strneb  r1, [r0]
	mov     r2, #0x0
	ldr     r1, =states + 0x070
	mov     r0, r4
	strb    r2, [r4, #0x4d9]
	bl      FUN_02119454
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118a30:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118a50:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =UNK_0211abe0
	ldrb    r1, [r0]
	cmp     r1, #0x3
	bne     LAB_02118aa4
	ldr     r0, =UNK_0211ae10
	ldrb    r0, [r0]
	ands    r0, r0, #0x1
	ldreq   r0, =UNK_0211ae0c
	moveq   r1, #0x2
	streqb  r1, [r0]
	ldrne   r0, =UNK_0211ae0c
	movne   r1, #0x1
	strneb  r1, [r0]
	b       LAB_02118aac
LAB_02118aa4:
	ldr     r0, =UNK_0211ae0c
	strb    r1, [r0]
LAB_02118aac:
	ldr     r0, =#0x4d9
	ldr     r2, =UNK_0211ae10
	add     r12, r4, r0
	ldrb    r3, [r12]
	ldr     r1, =states + 0x070
	mov     r0, r4
	add     r3, r3, #0x1
	strb    r3, [r12]
	ldrb    r3, [r2]
	add     r3, r3, #0x1
	strb    r3, [r2]
	ldrb    r3, [r2]
	and     r3, r3, #0x1
	strb    r3, [r2]
	bl      FUN_02119454
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118b08:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118b28:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =UNK_0211abe0
	ldrb    r1, [r0]
	cmp     r1, #0x3
	bne     LAB_02118b7c
	ldr     r0, =UNK_0211ae10
	ldrb    r0, [r0]
	ands    r0, r0, #0x1
	ldreq   r0, =UNK_0211ae0c
	moveq   r1, #0x2
	streqb  r1, [r0]
	ldrne   r0, =UNK_0211ae0c
	movne   r1, #0x1
	strneb  r1, [r0]
	b       LAB_02118b84
LAB_02118b7c:
	ldr     r0, =UNK_0211ae0c
	strb    r1, [r0]
LAB_02118b84:
	ldr     r0, =#0x4d9
	ldr     r2, =UNK_0211ae10
	add     r12, r4, r0
	ldrb    r3, [r12]
	ldr     r1, =states + 0x070
	mov     r0, r4
	add     r3, r3, #0x1
	strb    r3, [r12]
	ldrb    r3, [r2]
	add     r3, r3, #0x1
	strb    r3, [r2]
	ldrb    r3, [r2]
	and     r3, r3, #0x1
	strb    r3, [r2]
	bl      FUN_02119454
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118be0:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118c00:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =UNK_0211abe0
	ldrb    r1, [r0]
	cmp     r1, #0x3
	bne     LAB_02118c54
	ldr     r0, =UNK_0211ae10
	ldrb    r0, [r0]
	ands    r0, r0, #0x1
	ldreq   r0, =UNK_0211ae0c
	moveq   r1, #0x2
	streqb  r1, [r0]
	ldrne   r0, =UNK_0211ae0c
	movne   r1, #0x1
	strneb  r1, [r0]
	b       LAB_02118c5c
LAB_02118c54:
	ldr     r0, =UNK_0211ae0c
	strb    r1, [r0]
LAB_02118c5c:
	ldr     r0, =#0x4d9
	ldr     r2, =UNK_0211ae10
	add     r12, r4, r0
	ldrb    r3, [r12]
	ldr     r1, =states + 0x070
	mov     r0, r4
	add     r3, r3, #0x1
	strb    r3, [r12]
	ldrb    r3, [r2]
	add     r3, r3, #0x1
	strb    r3, [r2]
	ldrb    r3, [r2]
	and     r3, r3, #0x1
	strb    r3, [r2]
	bl      FUN_02119454
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118cb8:
	mov     r3, #0x0
	str     r3, [r0, #0x494]
	str     r3, [r0, #0x498]
	add     r1, r0, #0x400
	mov     r2, #0x1e
	strh    r2, [r1, #0x0d0]
	str     r3, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118cdc:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_021168b0
	cmp     r0, #0x0
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d0]
	cmp     r0, #0x0
	bne     LAB_02118d5c
	mov     r0, r4
	bl      FUN_02116a68
	ldr     r1, =#0x0ff3ae000
	cmp     r0, r1
	beq     LAB_02118d5c
	ldr     r0, =UNK_0211ae0c
	ldrb    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_02118d50
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x3
	ldr     r1, =states + 0x100
	mov     r0, r4
	strb    r3, [r2]
	add     r2, r4, #0x400
	mov     r3, #0x1e
	strh    r3, [r2, #0x0d2]
	bl      FUN_02119454
LAB_02118d50:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02118d5c:
	ldr     r1, =UNK_0211ae0c
	ldrb    r0, [r1]
	cmp     r0, #0x0
	bne     LAB_02118dbc
	ldr     r0, =UNK_0211abe0
	ldrb    r0, [r0]
	cmp     r0, #0x3
	bne     LAB_02118d98
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	moveq   r0, #0x1
	streqb  r0, [r1]
	movne   r0, #0x2
	strneb  r0, [r1]
	b       LAB_02118d9c
LAB_02118d98:
	strb    r0, [r1]
LAB_02118d9c:
	ldr     r0, =#0x494
	add     r1, r4, r0
	ldr     r0, [r1]
	add     r0, r0, #0x1
	str     r0, [r1]
	ldr     r0, [r1]
	and     r0, r0, #0x1
	str     r0, [r1]
LAB_02118dbc:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118de0:
	mov     r3, #0x0
	str     r3, [r0, #0x494]
	str     r3, [r0, #0x498]
	add     r1, r0, #0x400
	mov     r2, #0x1e
	strh    r2, [r1, #0x0d0]
	str     r3, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02118e04:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	bl      _ZN5Actor13ClosestPlayerEv
	ldr     r1, =UNK_0211abe0
	ldrb    r1, [r1]
	cmp     r1, #0x0
	bne     LAB_02118e4c
	ldr     r1, =states + 0x0e0
	mov     r0, r5
	add     r2, r5, #0x400
	mov     r3, #0x64
	strh    r3, [r2, #0x0d2]
	bl      FUN_02119454
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02118e4c:
	cmp     r0, #0x0
	beq     LAB_02118e64
	add     r0, r5, #0x400
	ldrh    r0, [r0, #0x0d2]
	cmp     r0, #0x0
	beq     LAB_02118e74
LAB_02118e64:
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02118e74:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r4, r0, lsr #0x1f
	ldr     r2, =UNK_0211ae08
	mov     r3, #0x0
	ldr     r1, =UNK_0211ae0c
	mov     r0, r5
	strb    r3, [r2]
	strb    r3, [r1]
	and     r4, r4, #0x1
	bl      FUN_02116a68
	ldr     r1, =#0x0ff3ae000
	cmp     r0, r1
	bne     LAB_02118ed4
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x4
	ldr     r1, =states + 0x110
	mov     r0, r5
	strb    r3, [r2]
	bl      FUN_02119454
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02118ed4:
	ldr     r3, =UNK_0211abe4
	ldrb    r2, [r5, #0x4d9]
	ldr     r1, [r3]
	add     r0, r1, #0x3
	cmp     r2, r0
	ble     LAB_02118f58
	ldr     r0, =UNK_0211abe0
	ldrb    r0, [r0]
	cmp     r0, #0x3
	bne     LAB_02118f28
	add     r12, r1, #0x1
	ldr     r2, =UNK_0211ae04
	mov     r4, #0x8
	ldr     r1, =states + 0x040
	mov     r0, r5
	str     r12, [r3]
	and     r5, r12, #0x1
	str     r5, [r3]
	strb    r4, [r2]
	bl      FUN_02119454
	b       LAB_02118f48
LAB_02118f28:
	ldr     r2, =UNK_0211ae04
	mvn     r12, #0x2
	mov     r4, #0x9
	ldr     r1, =states + 0x060
	mov     r0, r5
	str     r12, [r3]
	strb    r4, [r2]
	bl      FUN_02119454
LAB_02118f48:
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02118f58:
	mov     r0, r5
	bl      FUN_02116a68
	mov     r1, #0x0b50000
	rsb     r1, r1, #0x0
	cmp     r0, r1
	bne     LAB_02118f98
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x5
	ldr     r1, =states + 0x000
	mov     r0, r5
	strb    r3, [r2]
	bl      FUN_02119454
	add     r13, r13, #0x4
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02118f98:
	cmp     r4, #0x0
	bne     LAB_02118fbc
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x7
	ldr     r1, =states + 0x030
	mov     r0, r5
	strb    r3, [r2]
	bl      FUN_02119454
	b       LAB_02118fd4
LAB_02118fbc:
	ldr     r2, =UNK_0211ae04
	mov     r3, #0x6
	ldr     r1, =states + 0x010
	mov     r0, r5
	strb    r3, [r2]
	bl      FUN_02119454
LAB_02118fd4:
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211901c:
	mov     r2, #0x0
	str     r2, [r0, #0x494]
	str     r2, [r0, #0x498]
	add     r1, r0, #0x400
	strh    r2, [r1, #0x0d0]
	str     r2, [r0, #0x4a0]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_0211903c:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x48
	mov     r5, r0
	add     r0, r5, #0x400
	ldrh    r0, [r0, #0x0d2]
	cmp     r0, #0x0
	addne   r13, r13, #0x48
	movne   r0, #0x1
	popne   { r4-r6, r14 }
	bxne    r14
	ldr     r1, [r5, #0x4a0]
	ldr     r0, =CAMERA
	cmp     r1, #0x0
	ldr     r4, [r0]
	bne     LAB_021190b4
	mov     r0, r4
	bl      _ZN6Camera9SetFlag_3Ev
	mov     r0, r5
	bl      _ZN5Actor13ClosestPlayerEv
	str     r0, [r5, #0x490]
	ldr     r0, [r5, #0x490]
	cmp     r0, #0x0
	beq     LAB_021190a8
	mov     r1, #0x5
	mvn     r2, #0x0
	mov     r3, #0x0
	bl      0x020ca1b8
LAB_021190a8:
	mov     r0, #0x1
	str     r0, [r5, #0x4a0]
	b       LAB_02119128
LAB_021190b4:
	ldr     r0, [r5, #0x5c]
	ldr     r1, =#0x564000
	str     r0, [r13, #0x8]
	ldr     r6, [r5, #0x60]
	add     r2, r13, #0x8
	str     r6, [r13, #0x0c]
	ldr     r3, [r5, #0x64]
	mov     r0, r4
	str     r3, [r13, #0x10]
	ldr     r3, [r5, #0x5c]
	add     r6, r6, #0x100000
	str     r3, [r13, #0x14]
	ldr     r12, [r5, #0x60]
	add     r14, r3, #0x10000
	str     r12, [r13, #0x18]
	ldr     r3, [r5, #0x64]
	add     r12, r12, #0x100000
	str     r3, [r13, #0x1c]
	add     r3, r3, r1
	add     r1, r4, #0x80
	str     r6, [r13, #0x0c]
	str     r14, [r13, #0x14]
	str     r12, [r13, #0x18]
	str     r3, [r13, #0x1c]
	bl      0x020092c4
	add     r2, r13, #0x14
	mov     r0, r4
	add     r1, r4, #0x8c
	bl      0x020092c4
LAB_02119128:
	ldr     r0, =UNK_0211abe0
	ldrb    r0, [r0]
	cmp     r0, #0x3
	bne     LAB_02119154
	ldr     r0, =UNK_0211ae0c
	ldrb    r0, [r0]
	cmp     r0, #0x3
	addne   r13, r13, #0x48
	movne   r0, #0x1
	popne   { r4-r6, r14 }
	bxne    r14
LAB_02119154:
	ldr     r0, [r5, #0x498]
	cmp     r0, #0x0
	bne     LAB_0211925c
	ldr     r0, [r5, #0x490]
	cmp     r0, #0x0
	beq     LAB_02119308
	mov     r1, #0x0
	mov     r3, #0x32000
	str     r1, [r13, #0x24]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	str     r1, [r13, #0x28]
	rsb     r2, r3, #0x0
	str     r1, [r13, #0x20]
	str     r1, [r13, #0x2c]
	str     r1, [r13, #0x30]
	str     r1, [r13, #0x34]
	str     r3, [r13, #0x24]
	str     r2, [r13, #0x28]
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x20
	add     r2, r13, #0x2c
	bl      MulVec3Mat4x3
	ldr     r0, =UNK_0211abe0
	ldr     r2, [r13, #0x2c]
	ldr     r1, [r5, #0x5c]
	ldrb    r0, [r0]
	add     r1, r2, r1
	str     r1, [r13, #0x2c]
	ldr     r3, [r13, #0x30]
	ldr     r1, [r5, #0x60]
	ldr     r2, [r13, #0x34]
	add     r1, r3, r1
	str     r1, [r13, #0x30]
	ldr     r1, [r5, #0x64]
	cmp     r0, #0x0
	add     r0, r2, r1
	str     r0, [r13, #0x34]
	mov     r4, #0x0b8
	bne     LAB_02119204
	ldr     r1, =#0x15666
	mov     r0, #0x14
	mov     r4, #0x0b9
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
LAB_02119204:
	ldr     r1, [r5, #0x490]
	ldr     r0, =#0x6ce
	ldrh    r0, [r1, r0]!
	orr     r0, r0, #0x400
	strh    r0, [r1]
	bl      _ZN7Message11PrepareTalkEv
	mov     r0, #0x0
	str     r0, [r13]
	str     r0, [r13, #0x4]
	ldr     r0, [r5, #0x490]
	add     r3, r13, #0x2c
	mov     r1, r5
	mov     r2, r4
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x1
	bne     LAB_02119308
	ldr     r0, =#0x145
	mov     r2, #0x1
	add     r1, r5, #0x74
	str     r2, [r5, #0x498]
	bl      0x02012694
	b       LAB_02119308
LAB_0211925c:
	ldr     r0, [r5, #0x490]
	cmp     r0, #0x0
	beq     LAB_02119308
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	bge     LAB_02119308
	add     r1, r4, #0x154
	ldr     r0, [r1]
	bic     r0, r0, #0x8
	str     r0, [r1]
	bl      _ZN7Message7EndTalkEv
	ldr     r0, =UNK_0211abe0
	ldrb    r0, [r0]
	cmp     r0, #0x3
	bne     LAB_021192b4
	mov     r0, #0x2d
	bl      _ZN5Sound22LoadAndSetMusic_Layer3Ej
	bl      0x02011d2c
	ldr     r1, =states + 0x100
	mov     r0, r5
	bl      FUN_02119454
	b       LAB_02119308
LAB_021192b4:
	ldr     r1, =#0x15666
	mov     r0, #0x7f
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
	bl      _ZN5Sound22StopLoadedMusic_Layer3Ev
	bl      0x02011cfc
	mov     r1, #0x0
	ldr     r0, =#0x0ffa24000
	str     r1, [r13, #0x38]
	ldr     r1, =#0x0ff1b4000
	str     r0, [r13, #0x3c]
	str     r1, [r13, #0x40]
	mov     r0, #0x4
	str     r0, [r13]
	ldr     r1, =#0x673
	ldrb    r2, [r5, #0x672]
	mov     r0, r5
	add     r1, r5, r1
	add     r3, r13, #0x38
	bl      _ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j
	mov     r0, r5
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02119308:
	mov     r0, #0x1
	add     r13, r13, #0x48
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119348:
	push    { r4, r14 }
	ldr     r1, =#0x674
	mov     r4, r0
	add     r0, r4, r1
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02119370
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_02119370:
	mov     r1, #0x0
	str     r1, [r4, #0x494]
	str     r1, [r4, #0x498]
	add     r0, r4, #0x400
	strh    r1, [r0, #0x0d0]
	str     r1, [r4, #0x4a0]
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119398:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02119400
	add     r2, r0, #0x5c
	mov     r0, #0x300000
	ldr     r1, [r2, #0x4]
	rsb     r0, r0, #0x0
	cmp     r1, r0
	ldr     r1, [r2, #0x8]
	bge     LAB_02119400
	ldr     r0, [r4, #0x0b0]
	ands    r0, r0, #0x8
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	bne     LAB_02119400
	mov     r0, #0x0d70000
	rsb     r0, r0, #0x0
	cmp     r1, r0
	ldrlt   r0, =UNK_0211ae08
	ldrltb  r1, [r0]
	addlt   r1, r1, #0x1
	strltb  r1, [r0]
LAB_02119400:
	ldr     r3, =UNK_0211ae08
	ldrb    r0, [r3]
	cmp     r0, #0x2
	bls     LAB_02119430
	ldr     r2, =UNK_0211ae04
	mov     r14, #0x0
	mov     r12, #0x2
	ldr     r1, =states + 0x0e0
	mov     r0, r4
	strb    r14, [r3]
	strb    r12, [r2]
	bl      FUN_02119454
LAB_02119430:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211944c:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02119454:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x48c]
	ldr     r3, [r0, #0x48c]
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
FUN_021194a4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, =#0x83c
	ldrsh   r1, [r4, #0x8e]
	add     r0, r4, r0
	bl      Matrix4x3_FromRotationY
	ldr     r1, [r4, #0x5c]
	ldr     r0, =#0x674
	str     r1, [r4, #0x860]
	ldr     r2, [r4, #0x60]
	ldr     r1, =#0x83c
	str     r2, [r4, #0x864]
	ldr     r2, [r4, #0x64]
	add     r0, r4, r0
	str     r2, [r4, #0x868]
	ldrsh   r2, [r4, #0x8e]
	add     r1, r4, r1
	bl      _ZN18MovingMeshCollider9TransformERK9Matrix4x3s
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021194fc:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x14
	mov     r4, r0
	add     r0, r13, #0x8
	add     r1, r4, #0x5c
	mov     r2, #0x3
	bl      Vec3_Asr
	ldr     r1, [r13, #0x8]
	ldr     r2, [r13, #0x0c]
	ldr     r3, [r13, #0x10]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldrsh   r1, [r4, #0x8c]
	ldrsh   r2, [r4, #0x8e]
	ldrsh   r3, [r4, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      0x0203c0b4
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	bne     LAB_02119570
	ldr     r6, =MATRIX_SCRATCH_PAPER
	add     r5, r4, #0x3ec
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6, { r0-r3 }
	stmia   r5, { r0-r3 }
	b       LAB_02119590
LAB_02119570:
	ldr     r6, =MATRIX_SCRATCH_PAPER
	add     r5, r4, #0x37c
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6, { r0-r3 }
	stmia   r5, { r0-r3 }
LAB_02119590:
	ldr     r1, [r4, #0x49c]
	cmp     r1, #0x0
	addeq   r13, r13, #0x14
	popeq   { r4-r7, r14 }
	bxeq    r14
	ldr     r2, [r4, #0x60]
	ldr     r0, [r4, #0x4a8]
	cmp     r0, r2
	addge   r13, r13, #0x14
	popge   { r4-r7, r14 }
	bxge    r14
	cmp     r1, #0x2
	moveq   r3, #0x64000
	movne   r0, #0x64000
	rsbne   r3, r0, #0x0
	ldr     r1, [r4, #0x5c]
	sub     r2, r2, #0x8000
	add     r1, r1, r3
	ldr     r0, [r4, #0x64]
	mov     r1, r1, asr #0x3
	add     r3, r0, #0x0a0000
	ldr     r0, =MATRIX_SCRATCH_PAPER
	mov     r2, r2, asr #0x3
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	ldr     r0, =#0x45c
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r4, r0
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	mov     r14, #0x258000
	mov     r12, #0x0f
	str     r14, [r13]
	mov     r2, r5
	mov     r0, r4
	add     r1, r4, #0x420
	mov     r3, #0x140000
	str     r12, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r13, r13, #0x14
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119654:
	push    { r4, r14 }
	ldr     r1, =#0x674
	mov     r4, r0
	add     r0, r4, r1
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_0211967c
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase7DisableEv
LAB_0211967c:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	bne     LAB_02119738
	ldr     r0, =_ZN6Eyerok9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok16closeTexSeqFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15openTexSeqFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok16closeTexSeqFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15openTexSeqFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13deadAnimFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13deadAnimFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok8clsnFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13moveClsnFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13moveClsnFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13waitClsnFilesE + 0
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN6Eyerok13waitClsnFilesE + 8
	bl      _ZN13SharedFilePtr7ReleaseEv
LAB_02119738:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021197a0:
	bx      r14
.ltorg)");

asm(R"(
FUN_021197a4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	bne     LAB_021197e8
	ldr     r0, =UNK_0211ae04
	ldrb    r0, [r0]
	cmp     r0, #0x1
	bne     LAB_021197dc
	add     r0, r4, #0x3d0
	ldr     r2, [r0]
	mov     r1, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
LAB_021197dc:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_021197e8:
	ldr     r0, =UNK_0211ae04
	ldrb    r0, [r0]
	cmp     r0, #0x1
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x448
	add     r1, r4, #0x368
	add     r0, r4, r0
	bl      _ZN15TextureSequence6UpdateER15ModelComponents
	add     r0, r4, #0x360
	ldr     r2, [r0]
	mov     r1, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119838:
	push    { r4-r10, r14 }
	sub     r13, r13, #0x30
	mov     r4, r0
	add     r0, r4, #0x4d0
	bl      DecIfAbove0_Short
	ldr     r0, =#0x4d2
	add     r0, r4, r0
	bl      DecIfAbove0_Short
	ldr     r1, [r4, #0x48c]
	ldr     r0, [r1, #0x8]
	cmp     r0, #0x0
	beq     LAB_0211988c
	add     r3, r1, #0x8
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
LAB_0211988c:
	add     r0, r4, #0x400
	ldrh    r0, [r0, #0x0d4]
	cmp     r0, #0x0
	beq     LAB_02119bc8
	ands    r0, r0, #0x1
	bne     LAB_02119ad0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	add     r1, r4, #0x400
	ldrh    r3, [r1, #0x0d4]
	mov     r1, #0x0c
	ldr     r2, =#0x4dc
	mov     r3, r3, asr #0x1
	mul     r1, r3, r1
	add     r7, r4, r2
	ldr     r2, [r4, #0x5c]
	add     r5, r4, #0x4e0
	str     r2, [r7, r1]
	ldr     r3, [r4, #0x60]
	ldr     r2, =#0x4e4
	str     r3, [r5, r1]
	add     r6, r4, r2
	ldr     r3, [r4, #0x64]
	mov     r2, #0x0
	str     r3, [r6, r1]
	str     r2, [r13, #0x0c]
	str     r2, [r13, #0x10]
	str     r2, [r13, #0x14]
	str     r2, [r13, #0x18]
	str     r2, [r13, #0x1c]
	str     r2, [r13, #0x20]
	ldr     r3, [r4, #0x48c]
	ldr     r2, =states + 0x0b0
	add     r7, r7, r1
	cmp     r3, r2
	add     r5, r5, r1
	add     r6, r6, r1
	beq     LAB_02119a0c
	ldrsh   r1, [r4, #0x8e]
	cmp     r1, #0x0
	beq     LAB_02119994
	mov     r0, r0, asr #0x8
	and     r0, r0, #0x3f
	mov     r0, r0, lsl #0x2
	rsb     r0, r0, #0x7e
	mov     r0, r0, lsl #0x0c
	str     r0, [r13, #0x14]
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	sub     r1, r1, #0x4000
	mov     r1, r1, lsl #0x10
	mov     r1, r1, asr #0x10
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x0c
	add     r2, r13, #0x18
	bl      MulVec3Mat4x3
	ldr     r1, [r7]
	ldr     r0, [r13, #0x18]
	add     r0, r1, r0
	str     r0, [r7]
	ldr     r1, [r6]
	ldr     r0, [r13, #0x20]
	add     r0, r1, r0
	str     r0, [r6]
	b       LAB_021199e8
LAB_02119994:
	mov     r1, r0, asr #0x10
	ands    r1, r1, #0x1
	bne     LAB_021199c0
	mov     r0, r0, asr #0x8
	and     r1, r0, #0x3
	mov     r0, #0x28
	mul     r0, r1, r0
	ldr     r1, [r7]
	add     r0, r1, r0, lsl #0x0c
	str     r0, [r7]
	b       LAB_021199dc
LAB_021199c0:
	mov     r0, r0, asr #0x8
	and     r1, r0, #0x3
	mov     r0, #0x28
	mul     r0, r1, r0
	ldr     r1, [r7]
	sub     r0, r1, r0, lsl #0x0c
	str     r0, [r7]
LAB_021199dc:
	ldr     r0, [r6]
	add     r0, r0, #0x19000
	str     r0, [r6]
LAB_021199e8:
	add     r0, r4, #0x400
	ldrh    r1, [r0, #0x0d4]
	mov     r0, #0x0a
	ldr     r2, [r5]
	mul     r0, r1, r0
	add     r0, r0, #0x23
	add     r0, r2, r0, lsl #0x0c
	str     r0, [r5]
	b       LAB_02119ad0
LAB_02119a0c:
	ldrsh   r1, [r4, #0x8e]
	cmp     r1, #0x0
	beq     LAB_02119a7c
	mov     r0, r0, asr #0x8
	and     r0, r0, #0x3f
	mov     r0, r0, lsl #0x2
	rsb     r0, r0, #0x7e
	mov     r0, r0, lsl #0x0c
	str     r0, [r13, #0x14]
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	sub     r1, r1, #0x4000
	mov     r1, r1, lsl #0x10
	mov     r1, r1, asr #0x10
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x0c
	add     r2, r13, #0x18
	bl      MulVec3Mat4x3
	ldr     r1, [r7]
	ldr     r0, [r13, #0x18]
	add     r0, r1, r0
	str     r0, [r7]
	ldr     r1, [r6]
	ldr     r0, [r13, #0x20]
	add     r0, r1, r0
	str     r0, [r6]
	b       LAB_02119ac4
LAB_02119a7c:
	mov     r1, r0, asr #0x18
	and     r2, r1, #0x7
	mov     r1, #0x1e
	mul     r3, r2, r1
	ldr     r2, [r6]
	mov     r0, r0, asr #0x10
	sub     r2, r2, #0x64000
	and     r0, r0, #0x7
	str     r2, [r6]
	mul     r1, r0, r1
	ldr     r2, [r7]
	rsb     r0, r3, #0x69
	add     r0, r2, r0, lsl #0x0c
	str     r0, [r7]
	ldr     r2, [r6]
	rsb     r0, r1, #0x69
	add     r0, r2, r0, lsl #0x0c
	str     r0, [r6]
LAB_02119ac4:
	ldr     r0, [r5]
	add     r0, r0, #0x96000
	str     r0, [r5]
LAB_02119ad0:
	mov     r9, r4
	mov     r10, #0x0
	ldr     r7, =#0x13a
	ldr     r5, =#0x13b
	mov     r8, r10
	mov     r6, r10
LAB_02119ae8:
	ldr     r0, [r9, #0x4dc]
	cmp     r0, #0x0
	bne     LAB_02119b0c
	ldr     r0, [r9, #0x4e0]
	cmp     r0, #0x0
	bne     LAB_02119b0c
	ldr     r0, [r9, #0x4e4]
	cmp     r0, #0x0
	beq     LAB_02119b68
LAB_02119b0c:
	ldr     r1, [r9, #0x4e4]
	add     r0, r4, r10, lsl #0x2
	str     r1, [r13]
	str     r8, [r13, #0x4]
	str     r8, [r13, #0x8]
	ldr     r0, [r0, #0x5cc]
	ldr     r2, [r9, #0x4dc]
	ldr     r3, [r9, #0x4e0]
	mov     r1, r7
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	add     r2, r4, r10, lsl #0x2
	str     r0, [r2, #0x5cc]
	ldr     r0, [r9, #0x4e4]
	mov     r1, r5
	str     r0, [r13]
	str     r6, [r13, #0x4]
	str     r6, [r13, #0x8]
	ldr     r0, [r2, #0x61c]
	ldr     r2, [r9, #0x4dc]
	ldr     r3, [r9, #0x4e0]
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	add     r1, r4, r10, lsl #0x2
	str     r0, [r1, #0x61c]
LAB_02119b68:
	add     r10, r10, #0x1
	cmp     r10, #0x14
	add     r9, r9, #0x0c
	blt     LAB_02119ae8
	ldr     r0, =#0x4d4
	add     r1, r4, #0x400
	add     r2, r4, r0
	ldrh    r0, [r2]
	add     r0, r0, #0x1
	strh    r0, [r2]
	ldrh    r0, [r1, #0x0d4]
	cmp     r0, #0x26
	bls     LAB_02119bc8
	mov     r3, #0x0
	mov     r2, r4
	strh    r3, [r1, #0x0d4]
	mov     r0, r3
LAB_02119bac:
	str     r0, [r2, #0x4dc]
	str     r0, [r2, #0x4e0]
	add     r3, r3, #0x1
	str     r0, [r2, #0x4e4]
	cmp     r3, #0x14
	add     r2, r2, #0x0c
	blt     LAB_02119bac
LAB_02119bc8:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	bne     LAB_02119c08
	mov     r0, r4
	bl      FUN_021194fc
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02119bf8
	mov     r0, r4
	bl      FUN_021194a4
LAB_02119bf8:
	add     r13, r13, #0x30
	mov     r0, #0x1
	pop     { r4-r10, r14 }
	bx      r14
LAB_02119c08:
	ldr     r1, [r4, #0x4b4]
	mov     r0, r4
	add     r1, r1, #0x8000
	str     r1, [r4, #0x4a8]
	mov     r1, #0x0
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	ldr     r0, [r4, #0x5c]
	ldr     r2, =UNK_0211ad18
	str     r0, [r4, #0x354]
	ldr     r0, [r4, #0x60]
	add     r1, r13, #0x24
	str     r0, [r4, #0x358]
	ldr     r3, [r4, #0x64]
	add     r0, r4, #0x320
	str     r3, [r4, #0x35c]
	ldr     r5, [r2]
	ldr     r3, [r2, #0x4]
	ldr     r2, [r2, #0x8]
	str     r5, [r13, #0x24]
	str     r3, [r13, #0x28]
	str     r2, [r13, #0x2c]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	mov     r0, r4
	bl      FUN_021194fc
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02119c84
	mov     r0, r4
	bl      FUN_021194a4
LAB_02119c84:
	add     r0, r4, #0x320
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x320
	bl      _ZN12CylinderClsn6UpdateEv
	add     r0, r4, #0x360
	bl      0x0201647c
	ldr     r0, =#0x448
	add     r0, r4, r0
	bl      _ZN9Animation7AdvanceEv
	mov     r0, #0x1
	add     r13, r13, #0x30
	pop     { r4-r10, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119ce8:
	push    { r4-r9, r14 }
	sub     r13, r13, #0x24
	mov     r4, r0
	ldr     r0, [r4, #0x8]
	mov     r2, #0x2
	and     r0, r0, #0x0ff
	str     r0, [r4, #0x49c]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0ff
	moveq   r0, #0x0
	streq   r0, [r4, #0x49c]
	ldr     r1, [r4, #0x8]
	mov     r0, r4
	mov     r1, r1, lsr #0x0c
	and     r1, r1, #0x0f
	strb    r1, [r4, #0x672]
	ldrb    r1, [r4, #0x672]
	bl      _ZN5Actor9TrackStarEjj
	strb    r0, [r4, #0x673]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x2
	movgt   r0, #0x0
	strgt   r0, [r4, #0x49c]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	beq     LAB_02119d64
	cmp     r0, #0x1
	beq     LAB_02119e2c
	cmp     r0, #0x2
	beq     LAB_02119e84
	b       LAB_02119ed8
LAB_02119d64:
	ldr     r0, =_ZN6Eyerok9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x3d0
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 8
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 0
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok16closeTexSeqFilesE + 8
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15openTexSeqFilesE + 8
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok16closeTexSeqFilesE + 0
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15openTexSeqFilesE + 0
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15damageAnimFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13deadAnimFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13deadAnimFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok16waitEndAnimFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13waitAnimFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 0
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok15wakeUpAnimFilesE + 8
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok8clsnFileE
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13moveClsnFilesE + 0
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13moveClsnFilesE + 8
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13waitClsnFilesE + 0
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN6Eyerok13waitClsnFilesE + 8
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	b       LAB_02119ed8
LAB_02119e2c:
	ldr     r1, =_ZN6Eyerok14handModelFilesE + 8
	add     r0, r4, #0x360
	ldr     r1, [r1, #0x4]
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	cmp     r0, #0x0
	addeq   r13, r13, #0x24
	moveq   r0, #0x0
	popeq   { r4-r9, r14 }
	bxeq    r14
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 8
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 8
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 8
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 8
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	b       LAB_02119ed8
LAB_02119e84:
	ldr     r1, =_ZN6Eyerok14handModelFilesE + 0
	add     r0, r4, #0x360
	ldr     r1, [r1, #0x4]
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	cmp     r0, #0x0
	addeq   r13, r13, #0x24
	moveq   r0, #0x0
	popeq   { r4-r9, r14 }
	bxeq    r14
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 0
	ldr     r1, =_ZN6Eyerok16closeTexSeqFilesE + 0
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	ldr     r0, =_ZN6Eyerok14handModelFilesE + 0
	ldr     r1, =_ZN6Eyerok15openTexSeqFilesE + 0
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
LAB_02119ed8:
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	beq     LAB_02119f30
	add     r0, r4, #0x420
	bl      _ZN11ShadowModel12InitCylinderEv
	ldr     r0, =UNK_0211ad18
	mov     r3, #0x64000
	ldr     r2, [r0]
	ldr     r1, [r0, #0x4]
	ldr     r0, [r0, #0x8]
	str     r2, [r13, #0x18]
	str     r1, [r13, #0x1c]
	str     r0, [r13, #0x20]
	ldr     r0, =#0x200002
	str     r3, [r13]
	str     r0, [r13, #0x4]
	mov     r5, #0x0
	add     r2, r13, #0x18
	mov     r1, r4
	add     r0, r4, #0x320
	str     r5, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
LAB_02119f30:
	mov     r0, r4
	mov     r1, #0x0
	mov     r3, r1
LAB_02119f3c:
	str     r3, [r0, #0x4dc]
	str     r3, [r0, #0x4e0]
	add     r1, r1, #0x1
	str     r3, [r0, #0x4e4]
	cmp     r1, #0x14
	add     r0, r0, #0x0c
	blt     LAB_02119f3c
	mov     r0, #0x64000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x0a0]
	str     r3, [r4, #0x86c]
	str     r3, [r4, #0x870]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x0
	bne     LAB_0211a0e8
	add     r1, r4, #0x64
	ldr     r0, [r1]
	ldr     r12, =#0x193000
	sub     r0, r0, #0x7c000
	str     r0, [r1]
	ldr     r0, [r4, #0x5c]
	mvn     r5, #0x0
	str     r0, [r4, #0x4a4]
	ldr     r0, [r4, #0x60]
	add     r2, r13, #0x0c
	str     r0, [r4, #0x4a8]
	ldr     r1, [r4, #0x64]
	mov     r0, #0x0b0
	str     r1, [r4, #0x4ac]
	ldr     r6, [r4, #0x5c]
	mov     r1, #0x1
	str     r6, [r13, #0x0c]
	ldr     r7, [r4, #0x60]
	add     r6, r6, r12
	str     r7, [r13, #0x10]
	ldr     r7, [r4, #0x64]
	str     r7, [r13, #0x14]
	str     r6, [r13, #0x0c]
	ldrsb   r6, [r4, #0x0cc]
	str     r6, [r13]
	str     r5, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	cmp     r0, #0x0
	ldrne   r0, [r0, #0x4]
	mvn     r5, #0x0
	strne   r0, [r4, #0x86c]
	ldr     r0, [r4, #0x5c]
	add     r2, r13, #0x0c
	str     r0, [r13, #0x0c]
	sub     r0, r0, #0x18c000
	str     r0, [r13, #0x0c]
	ldrsb   r1, [r4, #0x0cc]
	mov     r0, #0x0b0
	mov     r3, #0x0
	str     r1, [r13]
	mov     r1, #0x2
	str     r5, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	cmp     r0, #0x0
	ldrne   r0, [r0, #0x4]
	ldr     r2, =#0x83c
	strne   r0, [r4, #0x870]
	ldr     r0, =#0x674
	ldr     r6, =UNK_0211ae10
	mov     r9, #0x0
	ldr     r14, =UNK_0211ae0c
	ldr     r5, =UNK_0211ae08
	ldr     r12, =UNK_0211abe4
	mov     r8, #0x1
	ldr     r3, =UNK_0211ae04
	ldr     r1, =UNK_0211abe0
	mov     r7, #0x3
	strb    r8, [r3]
	strb    r7, [r1]
	strb    r9, [r6]
	strb    r9, [r14]
	str     r8, [r12]
	strb    r9, [r5]
	ldrsh   r5, [r4, #0x8e]
	ldr     r3, =#0x2112ca8
	ldr     r1, =_ZN6Eyerok8clsnFileE
	str     r5, [r13]
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	mov     r1, r4
	add     r0, r4, r0
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	ldr     r1, =states + 0x0d0
	mov     r0, r4
	add     r2, r4, #0x400
	mov     r3, #0x64
	strh    r3, [r2, #0x0d2]
	bl      FUN_02119454
	b       LAB_0211a218
LAB_0211a0e8:
	ldr     r0, [r4, #0x5c]
	str     r0, [r4, #0x4a4]
	ldr     r0, [r4, #0x60]
	str     r0, [r4, #0x4a8]
	ldr     r0, [r4, #0x64]
	str     r0, [r4, #0x4ac]
	ldr     r0, [r4, #0x5c]
	str     r0, [r4, #0x4b0]
	ldr     r0, [r4, #0x60]
	str     r0, [r4, #0x4b4]
	ldr     r0, [r4, #0x64]
	str     r0, [r4, #0x4b8]
	ldr     r0, [r4, #0x49c]
	cmp     r0, #0x1
	bne     LAB_0211a170
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112c08
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 8
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	ldr     r0, =#0x4a4
	ldr     r1, =#0x31f000
	add     r2, r4, r0
	ldr     r0, [r2]
	sub     r0, r0, r1
	str     r0, [r2]
	b       LAB_0211a1b8
LAB_0211a170:
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =#0x674
	ldr     r3, =#0x2112d48
	str     r1, [r13]
	ldr     r2, =#0x83c
	ldr     r1, =_ZN6Eyerok13moveClsnFilesE + 0
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	ldr     r3, =#0x199
	add     r0, r4, r0
	add     r2, r4, r2
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	ldr     r0, =#0x4a4
	ldr     r1, =#0x31f000
	add     r2, r4, r0
	ldr     r0, [r2]
	add     r0, r0, r1
	str     r0, [r2]
LAB_0211a1b8:
	ldr     r0, =#0x674
	ldr     r1, =#0x2039348
	add     r0, r4, r0
	bl      0x020393d4
	ldr     r0, =#0x674
	ldr     r1, =FUN_0211a35c
	add     r0, r4, r0
	bl      0x020393c4
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      0x020398fc
	ldr     r0, =#0x4ac
	mov     r3, #0x3
	add     r1, r4, r0
	ldr     r0, [r1]
	ldr     r2, =UNK_0211ae00
	sub     r0, r0, #0x32000
	str     r0, [r1]
	ldr     r1, =states + 0x090
	mov     r0, r4
	strb    r3, [r4, #0x4d8]
	mov     r3, #0x0
	strb    r3, [r2]
	bl      FUN_02119454
LAB_0211a218:
	mov     r0, #0x1
	add     r13, r13, #0x24
	pop     { r4-r9, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211a2dc:
	mov     r0, #0x28000
	bx      r14
.ltorg)");

asm(R"(
FUN_0211a2e4:
	push    { r14 }
	sub     r13, r13, #0x0c
	ldr     r2, =UNK_0211ae04
	ldrb    r2, [r2]
	cmp     r2, #0x1
	addne   r13, r13, #0x0c
	popne   { r14 }
	bxne    r14
	cmp     r1, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r14 }
	bxeq    r14
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r14 }
	bxeq    r14
	ldr     r1, [r0, #0x64]
	ldr     r0, =#0x0ff387000
	cmp     r1, r0
	ldrlt   r0, =UNK_0211ae08
	ldrltb  r1, [r0]
	addlt   r1, r1, #0x1
	strltb  r1, [r0]
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211a35c:
	ldr     r12, =FUN_0211a2e4
	mov     r0, r1
	mov     r1, r2
	bx      r12
.ltorg)");

asm(R"(
FUN_0211a370:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	ldr     r0, =#0x874
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_0211a3ec
	bl      _ZN8PlatformC2Ev
	ldr     r1, =VTable_Eyerok
	add     r0, r4, #0x320
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
	add     r0, r4, #0x360
	bl      _ZN14BlendModelAnimC1Ev
	add     r0, r4, #0x3d0
	bl      _ZN5ModelC1Ev
	add     r0, r4, #0x420
	bl      _ZN11ShadowModelC1Ev
	ldr     r0, =#0x448
	add     r0, r4, r0
	bl      _ZN15TextureSequenceC1Ev
	ldr     r1, =#0x20072c0
	ldr     r0, =#0x4dc
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x14
	mov     r2, #0x0c
	ldr     r3, =#0x203d384
	bl      0x020733a8
	ldr     r0, =#0x674
	add     r0, r4, r0
	bl      _ZN18MovingMeshColliderC1Ev
LAB_0211a3ec:
	mov     r0, r4
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");