#include "SM64DS_2.h"
#include "Actors/Wiggler.h"

extern "C"
{
	ActorBase* FUN_021136a4(); // constructor
	
	// state function declarations for use below
	void FUN_02112484(Wiggler* wiggler);
	void FUN_02112348(Wiggler* wiggler);
	void FUN_02112330(Wiggler* wiggler);
	void FUN_02112284(Wiggler* wiggler);
	void FUN_02112270(Wiggler* wiggler);
	void FUN_021120ac(Wiggler* wiggler);
	void FUN_02112020(Wiggler* wiggler);
	void FUN_02111e68(Wiggler* wiggler);
	void FUN_02111e4c(Wiggler* wiggler);
	void FUN_02111c48(Wiggler* wiggler);
	void FUN_02111bb0(Wiggler* wiggler);
	void FUN_02111a64(Wiggler* wiggler);
	void FUN_02111a0c(Wiggler* wiggler);
	void FUN_021119ac(Wiggler* wiggler);
	void FUN_02111974(Wiggler* wiggler);
	void FUN_02111788(Wiggler* wiggler);
	void FUN_02111720(Wiggler* wiggler);
	void FUN_021115cc(Wiggler* wiggler);
	void FUN_021115c0(Wiggler* wiggler);
	void FUN_02111588(Wiggler* wiggler);
	void FUN_02111520(Wiggler* wiggler);
	void FUN_021113d4(Wiggler* wiggler);
	
	// undocumented globals not in ov34:
	// 0x020072c0
	// 0x02011508
	// 0x0201267c
	// 0x0203d384
	// 0x0203d73c
	
	u16 MESSAGE_IDS[4] = { 0xc6, 0xc7, 0xc8, 0xc9 }; // 0x02113820
	
	u32 PARTICLE_IDS[3] = { Particle::PTL_WET, Particle::PTL_STEAM_TRAIN_LESS, Particle::PTL_STEAM_TRAIN }; // 0x02113828
	
	Fix12i UNK_021138c4[5] = { 0._f, 87.698_f, 133.5491_f, 122.9802_f, 129.6621_f }; // 0x021138c4
	
	Fix12i CYLINDER_CLSN_RADIUS[5] = { 67.6_f, 62.4_f, 75.4_f, 62.4_f, 75.4_f }; // 0x021138d8
	
	u8 UNK_0211433c[5] = { 0x5e, 0x40, 0x22, 0x2e, 0x44 }; // 0x0211433c (the last byte is merged with a string?)
	
	Fix12i UNK_02114488[4] = { 16._f, 20._f, 24._f, 4._f }; // 0x02114488
	
	// remove these in decomp and use the SharedFilePtr arrays instead
	SharedFilePtr* MODEL_FILE_PTRS[5] = // 0x02113838
	{
		&Wiggler::modelFiles[0],
		&Wiggler::modelFiles[1],
		&Wiggler::modelFiles[2],
		&Wiggler::modelFiles[3],
		&Wiggler::modelFiles[4],
	};
	
	SharedFilePtr* TEX_SEQ_FILE_PTRS[5] = // 0x0211384c
	{
		&Wiggler::texSeqFiles[0],
		&Wiggler::texSeqFiles[1],
		&Wiggler::texSeqFiles[2],
		&Wiggler::texSeqFiles[3],
		&Wiggler::texSeqFiles[4],
	};
	
	SharedFilePtr* WAIT_ANIM_FILE_PTRS[5] = // 0x02113860
	{
		&Wiggler::waitAnimFiles[0],
		&Wiggler::waitAnimFiles[1],
		&Wiggler::waitAnimFiles[2],
		&Wiggler::waitAnimFiles[3],
		&Wiggler::waitAnimFiles[4],
	};
	
	SharedFilePtr* WALK_ANIM_FILE_PTRS[5] = // 0x02113874
	{
		&Wiggler::walkAnimFiles[0],
		&Wiggler::walkAnimFiles[1],
		&Wiggler::walkAnimFiles[2],
		&Wiggler::walkAnimFiles[3],
		&Wiggler::walkAnimFiles[4],
	};
	
	SharedFilePtr* WALK_START_ANIM_FILE_PTRS[5] = // 0x02113888
	{
		&Wiggler::walkStartAnimFiles[0],
		&Wiggler::walkStartAnimFiles[1],
		&Wiggler::walkStartAnimFiles[2],
		&Wiggler::walkStartAnimFiles[3],
		&Wiggler::walkStartAnimFiles[4],
	};
	
	SharedFilePtr* WALK_END_ANIM_FILE_PTRS[5] = // 0x0211389c
	{
		&Wiggler::walkEndAnimFiles[0],
		&Wiggler::walkEndAnimFiles[1],
		&Wiggler::walkEndAnimFiles[2],
		&Wiggler::walkEndAnimFiles[3],
		&Wiggler::walkEndAnimFiles[4],
	};
	
	SharedFilePtr* DAMAGE_ANIM_FILE_PTRS[5] = // 0x021138b0
	{
		&Wiggler::damageAnimFiles[0],
		&Wiggler::damageAnimFiles[1],
		&Wiggler::damageAnimFiles[2],
		&Wiggler::damageAnimFiles[3],
		&Wiggler::damageAnimFiles[4],
	};
	
	using StateFunc = void(*)(Wiggler*);
	
	struct State
	{
		StateFunc func1;
		u32 unk04;
		StateFunc func2;
		u32 unk0c;
		void* unk10 = nullptr; // string?
	};
	
	State states[11] = // 0x02114538
	{
		{ &FUN_02112484, 0, &FUN_02112348, 0 },
		{ &FUN_02112330, 0, &FUN_02112284, 0 },
		{ &FUN_02112270, 0, &FUN_021120ac, 0 },
		{ &FUN_02112020, 0, &FUN_02111e68, 0 },
		{ &FUN_02111e4c, 0, &FUN_02111c48, 0 },
		{ &FUN_02111bb0, 0, &FUN_02111a64, 0 },
		{ &FUN_02111a0c, 0, &FUN_021119ac, 0 },
		{ &FUN_02111974, 0, &FUN_02111788, 0 },
		{ &FUN_02111720, 0, &FUN_021115cc, 0 },
		{ &FUN_021115c0, 0, &FUN_02111588, 0 },
		{ &FUN_02111520, 0, &FUN_021113d4, 0 },
	};
}

SharedFilePtr Wiggler::modelFiles[5];
SharedFilePtr Wiggler::texSeqFiles[5];
SharedFilePtr Wiggler::waitAnimFiles[5];
SharedFilePtr Wiggler::walkAnimFiles[5];
SharedFilePtr Wiggler::walkStartAnimFiles[5];
SharedFilePtr Wiggler::walkEndAnimFiles[5];
SharedFilePtr Wiggler::damageAnimFiles[5];

SpawnInfo Wiggler::spawnData = 
{
	&FUN_021136a4,
	0x00f8,
	0x006a,
	Actor::NO_RENDER_IF_OFF_SCREEN | Actor::UNK_02,
	256._f,
	2048._f,
	4096._f,
	4096._f,
};

asm(R"(
@ 0x021144bc
VTable_Wiggler:
	.word FUN_0211323c
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02112a5c
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02112b5c
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02112af4
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_021111a0
	.word FUN_021112b0
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
FUN_021111a0:
	push    { r4, r14 }
	ldr     r1, =#0x708
	mov     r4, r0
	ldr     r2, =VTable_Wiggler
	add     r0, r4, r1
	str     r2, [r4]
	bl      _ZN12WithMeshClsnD1Ev
	ldr     r0, =#0x5b8
	ldr     r3, =_ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	bl      0x0207328c
	ldr     r0, =#0x478
	ldr     r3, =_ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	bl      0x0207328c
	ldr     r0, =#0x444
	mov     r1, #0x5
	add     r0, r4, r0
	mov     r2, #0x6
	ldr     r3, =#0x2011508
	bl      0x0207328c
	ldr     r0, =#0x408
	mov     r1, #0x5
	add     r0, r4, r0
	mov     r2, #0x0c
	ldr     r3, =#0x20072c0
	bl      0x0207328c
	add     r0, r4, #0x3cc
	mov     r1, #0x5
	mov     r2, #0x0c
	ldr     r3, =#0x20072c0
	bl      0x0207328c
	add     r0, r4, #0x368
	mov     r1, #0x5
	mov     r2, #0x14
	ldr     r3, =_ZN15TextureSequenceD1Ev
	bl      0x0207328c
	add     r0, r4, #0x304
	mov     r1, #0x5
	mov     r2, #0x14
	ldr     r3, =_ZN15MaterialChangerD1Ev
	bl      0x0207328c
	add     r0, r4, #0x110
	mov     r1, #0x5
	mov     r2, #0x64
	ldr     r3, =_ZN9ModelAnimD1Ev
	bl      0x0207328c
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021112b0:
	push    { r4, r14 }
	ldr     r1, =#0x708
	mov     r4, r0
	ldr     r2, =VTable_Wiggler
	add     r0, r4, r1
	str     r2, [r4]
	bl      _ZN12WithMeshClsnD1Ev
	ldr     r0, =#0x5b8
	ldr     r3, =_ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	bl      0x0207328c
	ldr     r0, =#0x478
	ldr     r3, =_ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	bl      0x0207328c
	ldr     r0, =#0x444
	mov     r1, #0x5
	add     r0, r4, r0
	mov     r2, #0x6
	ldr     r3, =#0x2011508
	bl      0x0207328c
	ldr     r0, =#0x408
	mov     r1, #0x5
	add     r0, r4, r0
	mov     r2, #0x0c
	ldr     r3, =#0x20072c0
	bl      0x0207328c
	add     r0, r4, #0x3cc
	mov     r1, #0x5
	mov     r2, #0x0c
	ldr     r3, =#0x20072c0
	bl      0x0207328c
	add     r0, r4, #0x368
	mov     r1, #0x5
	mov     r2, #0x14
	ldr     r3, =_ZN15TextureSequenceD1Ev
	bl      0x0207328c
	add     r0, r4, #0x304
	mov     r1, #0x5
	mov     r2, #0x14
	ldr     r3, =_ZN15MaterialChangerD1Ev
	bl      0x0207328c
	add     r0, r4, #0x110
	mov     r1, #0x5
	mov     r2, #0x64
	ldr     r3, =_ZN9ModelAnimD1Ev
	bl      0x0207328c
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
FUN_021113d4:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x4
	mov     r10, r0
	add     r0, r10, #0x110
	add     r7, r0, #0x0c8
	mov     r9, #0x2
	mov     r8, #0x6
	ldr     r11, =WALK_START_ANIM_FILE_PTRS
	mov     r6, #0x0
	mov     r5, #0x40000000
	mov     r4, #0x1000
LAB_02111400:
	ldrb    r1, [r10, #0x8da]
	sub     r0, r8, #0x3
	cmp     r1, r0
	bne     LAB_0211142c
	str     r6, [r13]
	ldr     r1, [r11, r9, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_0211142c:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x3
	add     r7, r7, #0x64
	blt     LAB_02111400
	add     r7, r10, #0x160
	add     r6, r10, #0x110
	mov     r8, #0x0
	ldr     r4, =WALK_ANIM_FILE_PTRS
	mov     r5, r8
	mov     r9, #0x1000
LAB_02111458:
	mov     r0, r7
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02111484
	str     r5, [r13]
	ldr     r1, [r4, r8, lsl #0x2]
	mov     r0, r6
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r9
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_02111484:
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	add     r6, r6, #0x64
	blt     LAB_02111458
	mov     r4, r10
	mov     r6, #0x1
	mov     r5, #0x0
	ldr     r2, =WALK_ANIM_FILE_PTRS
	mov     r0, r5
LAB_021114ac:
	ldr     r1, [r2, r5, lsl #0x2]
	ldr     r3, [r4, #0x170]
	ldr     r1, [r1, #0x4]
	add     r5, r5, #0x1
	cmp     r3, r1
	movne   r6, r0
	cmp     r5, #0x5
	add     r4, r4, #0x64
	blt     LAB_021114ac
	cmp     r6, #0x1
	bne     LAB_021114e4
	mov     r0, r10
	mov     r1, #0x4
	bl      FUN_021125b8
LAB_021114e4:
	ldr     r0, =#0x8da
	add     r1, r10, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r10, #0x8da]
	cmp     r0, #0x0c
	movhi   r0, #0x0d
	strhib  r0, [r10, #0x8da]
	add     r13, r13, #0x4
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111520:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	mov     r1, #0x0
	strb    r1, [r4, #0x8da]
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0]
	add     r0, r4, #0x110
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r1, #0x0
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x174
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111588:
	push    { r4, r14 }
	ldr     r1, =#0x8da
	mov     r4, r0
	add     r0, r4, r1
	bl      DecIfAbove0_Byte
	cmp     r0, #0x0
	popne   { r4, r14 }
	bxne    r14
	mov     r0, r4
	mov     r1, #0x0a
	bl      FUN_021125b8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021115c0:
	mov     r1, #0x5a
	strb    r1, [r0, #0x8da]
	bx      r14
.ltorg)");

asm(R"(
FUN_021115cc:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x4
	mov     r10, r0
	add     r0, r10, #0x98
	mov     r1, #0x0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	add     r0, r10, #0x110
	add     r7, r0, #0x0c8
	mov     r9, #0x2
	mov     r8, #0x6
	ldr     r11, =WALK_END_ANIM_FILE_PTRS
	mov     r6, #0x0
	mov     r5, #0x40000000
	mov     r4, #0x1000
LAB_02111608:
	ldrb    r1, [r10, #0x8da]
	sub     r0, r8, #0x3
	cmp     r1, r0
	bne     LAB_02111634
	str     r6, [r13]
	ldr     r1, [r11, r9, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_02111634:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x3
	add     r7, r7, #0x64
	blt     LAB_02111608
	add     r0, r10, #0x2f0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02111698
	add     r7, r10, #0x110
	mov     r8, #0x0
	ldr     r5, =WAIT_ANIM_FILE_PTRS
	mov     r6, r8
	mov     r4, #0x1000
LAB_0211166c:
	str     r6, [r13]
	ldr     r1, [r5, r8, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r6
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	blt     LAB_0211166c
LAB_02111698:
	mov     r4, r10
	mov     r6, #0x1
	mov     r5, #0x0
	ldr     r2, =WAIT_ANIM_FILE_PTRS
	mov     r0, r5
LAB_021116ac:
	ldr     r1, [r2, r5, lsl #0x2]
	ldr     r3, [r4, #0x170]
	ldr     r1, [r1, #0x4]
	add     r5, r5, #0x1
	cmp     r3, r1
	movne   r6, r0
	cmp     r5, #0x5
	add     r4, r4, #0x64
	blt     LAB_021116ac
	cmp     r6, #0x1
	bne     LAB_021116e4
	mov     r0, r10
	mov     r1, #0x9
	bl      FUN_021125b8
LAB_021116e4:
	ldr     r0, =#0x8da
	add     r1, r10, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r10, #0x8da]
	cmp     r0, #0x0c
	movhi   r0, #0x0d
	strhib  r0, [r10, #0x8da]
	add     r13, r13, #0x4
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111720:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	mov     r1, #0x0
	strb    r1, [r4, #0x8da]
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0]
	add     r0, r4, #0x110
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r1, #0x0
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x174
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111788:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x2c
	ldr     r1, =#0x8da
	mov     r10, r0
	add     r0, r10, r1
	bl      DecIfAbove0_Byte
	cmp     r0, #0x0
	bne     LAB_02111804
	ldrb    r2, [r10, #0x8dd]
	cmp     r2, #0x5
	bcs     LAB_02111804
	mov     r0, #0x0c
	mul     r1, r2, r0
	add     r2, r10, #0x3cc
	ldr     r0, [r2, r1]
	add     r2, r2, r1
	str     r0, [r13, #0x1c]
	ldr     r0, [r2, #0x4]
	add     r1, r13, #0x1c
	str     r0, [r13, #0x20]
	ldr     r2, [r2, #0x8]
	mov     r0, r10
	str     r2, [r13, #0x24]
	bl      _ZN5Actor10PoofDustAtERK7Vector3
	ldr     r0, =#0x8dd
	mov     r1, #0x5
	add     r2, r10, r0
	ldrb    r0, [r2]
	add     r0, r0, #0x1
	strb    r0, [r2]
	strb    r1, [r10, #0x8da]
LAB_02111804:
	ldr     r0, =#0x464
	ldr     r1, =#0x408
	mov     r8, r10
	add     r7, r10, r0
	add     r6, r10, r1
	mov     r9, #0x0
	mov     r5, #0x200
	mov     r4, #0x800
	mov     r11, #0x20000
	mov     r0, #0x2000
	str     r0, [r13, #0x0c]
LAB_02111830:
	ldrb    r0, [r10, #0x8dd]
	cmp     r9, r0
	bgt     LAB_021118ac
	ldr     r1, [r8, #0x408]
	mov     r0, r7
	str     r1, [r8, #0x410]
	ldr     r1, [r8, #0x410]
	mov     r2, r4
	str     r1, [r8, #0x40c]
	ldr     r1, =UNK_021138c4
	str     r5, [r13]
	ldr     r1, [r1, r9, lsl #0x2]
	mov     r3, r11
	mov     r1, r1, asr #0x1
	bl      Math_Function_0203b14c
	and     r0, r0, #0x0ff
	str     r0, [r13, #0x4]
	ldr     r3, [r13, #0x0c]
	mov     r0, r6
	mov     r1, r4
	mov     r2, r4
	str     r5, [r13]
	bl      Math_Function_0203b14c
	and     r0, r0, #0x0ff
	add     r9, r9, #0x1
	str     r0, [r13, #0x8]
	add     r8, r8, #0x0c
	add     r7, r7, #0x4
	add     r6, r6, #0x0c
	cmp     r9, #0x5
	blt     LAB_02111830
LAB_021118ac:
	ldr     r0, [r13, #0x4]
	cmp     r0, #0x0
	addne   r13, r13, #0x2c
	popne   { r4-r11, r14 }
	bxne    r14
	ldr     r0, [r13, #0x8]
	cmp     r0, #0x0
	addne   r13, r13, #0x2c
	popne   { r4-r11, r14 }
	bxne    r14
	ldrb    r0, [r10, #0x8dc]
	cmp     r0, #0x5
	bcs     LAB_02111900
	ldr     r0, =#0x8dc
	add     r13, r13, #0x2c
	add     r1, r10, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4-r11, r14 }
	bx      r14
LAB_02111900:
	ldr     r1, [r10, #0x60]
	ldr     r3, [r10, #0x64]
	ldr     r0, [r10, #0x5c]
	add     r2, r1, #0x64000
	str     r0, [r13, #0x10]
	ldr     r1, =#0x8e3
	str     r2, [r13, #0x14]
	str     r3, [r13, #0x18]
	mov     r0, #0x4
	str     r0, [r13]
	ldrb    r2, [r10, #0x8e2]
	mov     r0, r10
	add     r1, r10, r1
	add     r3, r10, #0x5c
	bl      _ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j
	bl      _ZN5Sound22StopLoadedMusic_Layer3Ev
	mov     r0, r10
	mov     r1, #0x3
	bl      FUN_021125b8
	add     r13, r13, #0x2c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111974:
	mov     r3, r0
	mov     r0, #0x0
	strb    r0, [r3, #0x8dc]
	strb    r0, [r3, #0x8dd]
	mov     r1, #0x1
	strb    r1, [r3, #0x8e0]
	mov     r2, #0x5
	ldr     r12, =#0x201267c
	ldr     r0, =#0x11f
	add     r1, r3, #0x74
	strb    r2, [r3, #0x8da]
	bx      r12
.ltorg)");

asm(R"(
FUN_021119ac:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x98
	mov     r1, #0x0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	ldr     r0, [r4, #0x8c8]
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x2
	popne   { r4, r14 }
	bxne    r14
	ldrb    r0, [r4, #0x8db]
	cmp     r0, #0x1
	bls     LAB_021119f8
	mov     r0, r4
	mov     r1, #0x3
	bl      FUN_021125b8
	pop     { r4, r14 }
	bx      r14
LAB_021119f8:
	mov     r0, r4
	mov     r1, #0x7
	bl      FUN_021125b8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111a0c:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x8
	add     r7, r0, #0x110
	mov     r8, #0x0
	ldr     r5, =WAIT_ANIM_FILE_PTRS
	mov     r6, r8
	mov     r4, #0x1000
LAB_02111a28:
	str     r6, [r13]
	ldr     r1, [r5, r8, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r6
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	blt     LAB_02111a28
	add     r13, r13, #0x8
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111a64:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x14
	mov     r5, r0
	add     r0, r5, #0x98
	mov     r1, #0x0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	mov     r0, r5
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	add     r1, r5, #0x800
	strh    r0, [r1, #0x0d8]
	ldr     r4, [r5, #0x8c8]
	ldr     r1, [r5, #0x3cc]
	mov     r0, r4
	str     r1, [r13, #0x8]
	ldr     r2, [r5, #0x3d0]
	mov     r1, r5
	str     r2, [r13, #0x0c]
	ldr     r12, [r5, #0x3d4]
	add     r3, r2, #0x8c000
	mov     r2, #0x1
	str     r12, [r13, #0x10]
	str     r3, [r13, #0x0c]
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	addeq   r13, r13, #0x14
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, =CAMERA
	ldr     r0, [r0]
	bl      _ZN6Camera9SetFlag_3Ev
	mov     r0, #0x1
	strb    r0, [r5, #0x8e1]
	ldr     r1, [r5, #0x8c8]
	add     r0, r5, #0x3cc
	add     r1, r1, #0x5c
	bl      Vec3_HorzAngle
	ldr     r2, [r5, #0x8c8]
	mov     r1, r0
	add     r0, r2, #0x8e
	mov     r2, #0x100
	bl      _Z14ApproachLinearRsss
	add     r1, r13, #0x8
	mov     r0, r4
	bl      0x020c51d0
	add     r0, r5, #0x160
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x14
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldrb    r0, [r5, #0x8db]
	mov     r1, #0x0
	add     r3, r13, #0x8
	rsb     r0, r0, #0x4
	and     r2, r0, #0x0ff
	mov     r0, #0x1
	str     r0, [r13]
	cmp     r2, #0x4
	movcs   r2, #0x0
	str     r1, [r13, #0x4]
	ldr     r0, =MESSAGE_IDS
	mov     r1, r2, lsl #0x1
	ldrsh   r2, [r0, r1]
	mov     r0, r4
	mov     r1, r5
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	addeq   r13, r13, #0x14
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, =#0x11b
	add     r1, r5, #0x74
	bl      0x0201267c
	mov     r0, r5
	mov     r1, #0x6
	bl      FUN_021125b8
	add     r13, r13, #0x14
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111bb0:
	push    { r4-r10, r14 }
	sub     r13, r13, #0x8
	mov     r10, r0
	mov     r9, #0x0
	str     r9, [r10, #0x8e4]
	add     r8, r10, #0x110
	ldr     r6, =DAMAGE_ANIM_FILE_PTRS
	mov     r7, r9
	mov     r5, #0x40000000
	mov     r4, #0x1000
LAB_02111bd8:
	str     r7, [r13]
	ldr     r1, [r6, r9, lsl #0x2]
	mov     r0, r8
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r0, r10, r9, lsl #0x6
	add     r1, r0, #0x490
	ldr     r0, [r1]
	add     r9, r9, #0x1
	orr     r0, r0, #0x4
	str     r0, [r1]
	cmp     r9, #0x5
	add     r8, r8, #0x64
	blt     LAB_02111bd8
	ldrb    r0, [r10, #0x8db]
	cmp     r0, #0x1
	ldrhi   r0, =#0x8db
	addhi   r1, r10, r0
	ldrhib  r0, [r1]
	subhi   r0, r0, #0x1
	strhib  r0, [r1]
	add     r13, r13, #0x8
	pop     { r4-r10, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111c48:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x10
	ldr     r2, =#0x8cc
	mov     r6, r0
	add     r0, r13, #0x0
	add     r1, r6, #0x5c
	add     r2, r6, r2
	bl      Vec3_Sub
	add     r0, r13, #0x0
	bl      LenVec3
	ldrb    r1, [r6, #0x8e0]
	mov     r5, r0
	cmp     r1, #0x0
	beq     LAB_02111cd4
	ldrb    r0, [r6, #0x8df]
	cmp     r0, #0x0
	bne     LAB_02111cd4
	mov     r0, r6
	bl      _ZN5Actor13ClosestPlayerEv
	mov     r1, r0
	add     r0, r6, #0x5c
	add     r1, r1, #0x5c
	bl      Vec3_HorzDist
	cmp     r0, #0x0c8000
	bge     LAB_02111cd4
	mov     r2, #0x1
	mov     r0, #0x1000
	mov     r1, #0x3c000
	strb    r2, [r6, #0x8df]
	rsb     r0, r0, #0x0
	str     r0, [r6, #0x9c]
	rsb     r0, r1, #0x0
	str     r0, [r6, #0x0a0]
	mov     r0, #0x0
	str     r0, [r6, #0x0a8]
LAB_02111cd4:
	ldr     r0, =#0x8da
	add     r0, r6, r0
	bl      DecIfAbove0_Byte
	cmp     r0, #0x0
	bne     LAB_02111d68
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldrb    r1, [r6, #0x8db]
	mov     r4, r0
	cmp     r1, #0x3
	bls     LAB_02111d0c
	mov     r1, r4, lsr #0x1b
	ands    r0, r1, #0x1
	bne     LAB_02111d20
LAB_02111d0c:
	mov     r0, r6
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	add     r1, r6, #0x800
	strh    r0, [r1, #0x0d8]
	b       LAB_02111d30
LAB_02111d20:
	and     r0, r1, #0x0f
	mov     r1, r0, lsl #0x0c
	add     r0, r6, #0x800
	strh    r1, [r0, #0x0d8]
LAB_02111d30:
	add     r0, r4, #0x1e
	mov     r0, r0, lsr #0x1b
	strb    r0, [r6, #0x8da]
	ldrb    r1, [r6, #0x8db]
	mov     r0, #0x1e
	ldrb    r2, [r6, #0x8da]
	rsb     r1, r1, #0x4
	mul     r0, r1, r0
	sub     r0, r2, r0
	strb    r0, [r6, #0x8da]
	ldrb    r0, [r6, #0x8da]
	cmp     r0, #0x40
	movcs   r0, #0x0
	strcsb  r0, [r6, #0x8da]
LAB_02111d68:
	ldr     r0, =#0x708
	add     r0, r6, r0
	bl      _ZNK12WithMeshClsn8IsOnWallEv
	cmp     r0, #0x0
	bne     LAB_02111d88
	ldr     r0, =#0x5dc000
	cmp     r5, r0
	ble     LAB_02111de4
LAB_02111d88:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x8cc
	mov     r4, r0
	add     r0, r6, #0x5c
	add     r1, r6, r1
	bl      Vec3_HorzAngle
	add     r1, r6, #0x800
	add     r2, r4, #0x1e
	strh    r0, [r1, #0x0d8]
	mov     r0, r2, lsr #0x1b
	strb    r0, [r6, #0x8da]
	ldrb    r1, [r6, #0x8db]
	mov     r0, #0x1e
	ldrb    r2, [r6, #0x8da]
	rsb     r1, r1, #0x4
	mul     r0, r1, r0
	sub     r0, r2, r0
	strb    r0, [r6, #0x8da]
	ldrb    r0, [r6, #0x8da]
	cmp     r0, #0x40
	movcs   r0, #0x0
	strcsb  r0, [r6, #0x8da]
LAB_02111de4:
	ldrb    r0, [r6, #0x8db]
	ldr     r1, =UNK_02114488
	rsb     r0, r0, #0x4
	and     r2, r0, #0x0ff
	cmp     r2, #0x4
	movcs   r2, #0x0
	ldr     r1, [r1, r2, lsl #0x2]
	add     r0, r6, #0x98
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r6, #0x8e0]
	cmp     r0, #0x0
	addne   r13, r13, #0x10
	popne   { r4-r6, r14 }
	bxne    r14
	mov     r0, r6
	bl      FUN_02112688
	add     r13, r13, #0x10
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111e4c:
	mov     r1, #0x0
	str     r1, [r0, #0x8c8]
	ldrb    r1, [r0, #0x8e0]
	cmp     r1, #0x0
	movne   r1, #0x96
	strneb  r1, [r0, #0x8da]
	bx      r14
.ltorg)");

asm(R"(
FUN_02111e68:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x4
	mov     r10, r0
	add     r0, r10, #0x110
	add     r7, r0, #0x0c8
	mov     r9, #0x2
	mov     r8, #0x6
	ldr     r11, =WALK_START_ANIM_FILE_PTRS
	mov     r6, #0x0
	mov     r5, #0x40000000
	mov     r4, #0x1000
LAB_02111e94:
	ldrb    r1, [r10, #0x8da]
	sub     r0, r8, #0x3
	cmp     r1, r0
	bne     LAB_02111ec0
	str     r6, [r13]
	ldr     r1, [r11, r9, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_02111ec0:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x3
	add     r7, r7, #0x64
	blt     LAB_02111e94
	add     r7, r10, #0x160
	add     r6, r10, #0x110
	mov     r8, #0x0
	ldr     r4, =WALK_ANIM_FILE_PTRS
	mov     r5, r8
	mov     r9, #0x1000
LAB_02111eec:
	mov     r0, r7
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02111f18
	str     r5, [r13]
	ldr     r1, [r4, r8, lsl #0x2]
	mov     r0, r6
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r9
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_02111f18:
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	add     r6, r6, #0x64
	blt     LAB_02111eec
	ldr     r0, [r10, #0x8c8]
	mov     r5, r10
	mov     r7, #0x1
	mov     r6, #0x0
	ldr     r3, =WALK_ANIM_FILE_PTRS
	mov     r1, r6
LAB_02111f44:
	ldr     r2, [r3, r6, lsl #0x2]
	ldr     r4, [r5, #0x170]
	ldr     r2, [r2, #0x4]
	add     r6, r6, #0x1
	cmp     r4, r2
	movne   r7, r1
	cmp     r6, #0x5
	add     r5, r5, #0x64
	blt     LAB_02111f44
	cmp     r7, #0x1
	bne     LAB_02111fe0
	bl      _ZN6Player18HasFinishedTalkingEv
	cmp     r0, #0x0
	beq     LAB_02111fe0
	ldrb    r0, [r10, #0x8db]
	cmp     r0, #0x4
	bcs     LAB_02111fb4
	cmp     r0, #0x1
	bls     LAB_02111fb4
	sub     r1, r0, #0x2
	mov     r0, #0x0a
	mul     r0, r1, r0
	mov     r0, r0, lsl #0x0c
	rsb     r1, r0, #0x41000
	mov     r0, #0x4000
	str     r1, [r10, #0x0a8]
	rsb     r0, r0, #0x0
	str     r0, [r10, #0x9c]
LAB_02111fb4:
	ldr     r1, =CAMERA
	mov     r0, r10
	ldr     r1, [r1]
	mov     r2, #0x0
	add     r4, r1, #0x154
	ldr     r3, [r4]
	mov     r1, #0x4
	bic     r3, r3, #0x8
	str     r3, [r4]
	strb    r2, [r10, #0x8e1]
	bl      FUN_021125b8
LAB_02111fe0:
	ldr     r0, =#0x8da
	add     r1, r10, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r10, #0x8da]
	cmp     r0, #0x0c
	movhi   r0, #0x0d
	strhib  r0, [r10, #0x8da]
	add     r13, r13, #0x4
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112020:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	mov     r2, #0x0
LAB_02112030:
	add     r0, r4, r2, lsl #0x6
	add     r1, r0, #0x490
	ldr     r0, [r1]
	add     r2, r2, #0x1
	bic     r0, r0, #0x4
	str     r0, [r1]
	cmp     r2, #0x5
	blt     LAB_02112030
	mov     r1, #0x0
	strb    r1, [r4, #0x8da]
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0]
	add     r0, r4, #0x110
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r1, #0x0
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x174
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021120ac:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x4
	mov     r10, r0
	add     r0, r10, #0x98
	mov     r1, #0x0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	ldrb    r0, [r10, #0x8da]
	cmp     r0, #0x0
	bne     LAB_0211211c
	mov     r1, #0x0
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0]
	add     r0, r10, #0x110
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	mov     r1, #0x0
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r10, #0x174
	ldr     r1, [r1, #0x4]
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_0211211c:
	add     r0, r10, #0x110
	add     r7, r0, #0x0c8
	mov     r9, #0x2
	mov     r8, #0x6
	ldr     r11, =WALK_END_ANIM_FILE_PTRS
	mov     r6, #0x0
	mov     r5, #0x40000000
	mov     r4, #0x1000
LAB_0211213c:
	ldrb    r1, [r10, #0x8da]
	sub     r0, r8, #0x3
	cmp     r1, r0
	bne     LAB_02112168
	str     r6, [r13]
	ldr     r1, [r11, r9, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
LAB_02112168:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x3
	add     r7, r7, #0x64
	blt     LAB_0211213c
	add     r0, r10, #0x2f0
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_021121cc
	add     r7, r10, #0x110
	mov     r8, #0x0
	ldr     r5, =WAIT_ANIM_FILE_PTRS
	mov     r6, r8
	mov     r4, #0x1000
LAB_021121a0:
	str     r6, [r13]
	ldr     r1, [r5, r8, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r6
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	blt     LAB_021121a0
LAB_021121cc:
	ldr     r0, [r10, #0x8c8]
	mov     r5, r10
	mov     r7, #0x1
	mov     r6, #0x0
	ldr     r3, =WAIT_ANIM_FILE_PTRS
	mov     r1, r6
LAB_021121e4:
	ldr     r2, [r3, r6, lsl #0x2]
	ldr     r4, [r5, #0x170]
	ldr     r2, [r2, #0x4]
	add     r6, r6, #0x1
	cmp     r4, r2
	movne   r7, r1
	cmp     r6, #0x5
	add     r5, r5, #0x64
	blt     LAB_021121e4
	cmp     r7, #0x1
	bne     LAB_02112234
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x2
	bne     LAB_02112234
	mov     r0, #0x2d
	bl      _ZN5Sound22LoadAndSetMusic_Layer3Ej
	bl      _ZN7Message7EndTalkEv
	mov     r0, r10
	mov     r1, #0x3
	bl      FUN_021125b8
LAB_02112234:
	ldr     r0, =#0x8da
	add     r1, r10, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r10, #0x8da]
	cmp     r0, #0x0c
	movhi   r0, #0x0d
	strhib  r0, [r10, #0x8da]
	add     r13, r13, #0x4
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112270:
	mov     r1, #0x0
	strb    r1, [r0, #0x8da]
	mov     r1, #0x1
	strb    r1, [r0, #0x8de]
	bx      r14
.ltorg)");

asm(R"(
FUN_02112284:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldr     r0, [r4, #0x8c8]
	ldr     r2, [r4, #0x3cc]
	mov     r1, #0x1
	str     r2, [r13, #0x8]
	ldr     r3, [r4, #0x3d0]
	mov     r2, #0x0
	str     r3, [r13, #0x0c]
	ldr     r12, [r4, #0x3d4]
	add     r3, r3, #0x28000
	str     r3, [r13, #0x0c]
	str     r12, [r13, #0x10]
	str     r1, [r13]
	ldr     r1, =MESSAGE_IDS
	str     r2, [r13, #0x4]
	ldrsh   r2, [r1]
	add     r3, r13, #0x8
	mov     r1, r4
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4, r14 }
	bxeq    r14
	bl      _ZN7Message11PrepareTalkEv
	ldr     r0, =CAMERA
	ldr     r0, [r0]
	bl      _ZN6Camera9SetFlag_3Ev
	mov     r2, #0x1
	ldr     r0, =#0x11b
	add     r1, r4, #0x74
	strb    r2, [r4, #0x8e1]
	bl      0x0201267c
	mov     r0, r4
	mov     r1, #0x2
	bl      FUN_021125b8
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112330:
	push    { r4, r14 }
	mov     r4, r0
	bl      _ZN5Actor13ClosestPlayerEv
	str     r0, [r4, #0x8c8]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112348:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	ldr     r2, =#0x8cc
	mov     r5, r0
	add     r0, r13, #0x0
	add     r1, r5, #0x5c
	add     r2, r5, r2
	bl      Vec3_Sub
	add     r0, r13, #0x0
	bl      LenVec3
	mov     r4, r0
	mov     r0, r5
	bl      _ZN5Actor13ClosestPlayerEv
	ldr     r1, [r5, #0x60]
	ldr     r2, [r0, #0x60]
	add     r0, r1, #0x12c000
	cmp     r2, r0
	ble     LAB_021123a8
	mov     r0, r5
	mov     r1, #0x1
	bl      FUN_021125b8
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
LAB_021123a8:
	ldr     r0, =#0x8da
	add     r0, r5, r0
	bl      DecIfAbove0_Byte
	cmp     r0, #0x0
	bne     LAB_02112400
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r1, r0, lsr #0x1b
	ands    r0, r1, #0x1
	andne   r0, r1, #0x0f
	movne   r1, r0, lsl #0x0c
	addne   r0, r5, #0x800
	strneh  r1, [r0, #0x0d8]
	bne     LAB_021123f0
	mov     r0, r5
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	add     r1, r5, #0x800
	strh    r0, [r1, #0x0d8]
LAB_021123f0:
	ldrb    r1, [r5, #0x8db]
	ldr     r0, =UNK_0211433c
	ldrb    r0, [r0, r1]
	strb    r0, [r5, #0x8da]
LAB_02112400:
	ldr     r0, =#0x708
	add     r0, r5, r0
	bl      _ZNK12WithMeshClsn8IsOnWallEv
	cmp     r0, #0x0
	bne     LAB_02112420
	ldr     r0, =#0x5dc000
	cmp     r4, r0
	ble     LAB_02112448
LAB_02112420:
	ldr     r1, =#0x8cc
	add     r0, r5, #0x5c
	add     r1, r5, r1
	bl      Vec3_HorzAngle
	add     r1, r5, #0x800
	strh    r0, [r1, #0x0d8]
	ldrb    r1, [r5, #0x8db]
	ldr     r0, =UNK_0211433c
	ldrb    r0, [r0, r1]
	strb    r0, [r5, #0x8da]
LAB_02112448:
	ldr     r1, =UNK_02114488
	add     r0, r5, #0x98
	ldr     r1, [r1]
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112484:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x24
	mov     r10, r0
	mov     r9, #0x0
	ldr     r0, =UNK_02114488
	str     r9, [r10, #0x8c8]
	ldr     r0, [r0]
	mov     r8, r10
	mov     r7, r10
	str     r0, [r10, #0x98]
	ldr     r4, =MATRIX_SCRATCH_PAPER
	add     r11, r13, #0x0c
	mov     r5, r9
LAB_021124b8:
	cmp     r9, #0x0
	bne     LAB_021124f4
	ldr     r1, [r10, #0x5c]
	mov     r0, r10
	str     r1, [r8, #0x3cc]
	ldr     r1, [r10, #0x60]
	str     r1, [r8, #0x3d0]
	ldr     r1, [r10, #0x64]
	str     r1, [r8, #0x3d4]
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	add     r1, r7, #0x400
	strh    r0, [r1, #0x46]
	ldrsh   r0, [r1, #0x46]
	strh    r0, [r10, #0x94]
	b       LAB_02112590
LAB_021124f4:
	add     r0, r10, r9, lsl #0x2
	ldr     r1, [r0, #0x464]
	add     r0, r10, #0x400
	rsb     r1, r1, #0x0
	str     r5, [r13]
	str     r5, [r13, #0x4]
	str     r5, [r13, #0x0c]
	str     r5, [r13, #0x10]
	str     r5, [r13, #0x14]
	str     r1, [r13, #0x8]
	ldrsh   r1, [r0, #0x46]
	mov     r0, r4
	add     r1, r1, #0x200
	mov     r1, r1, lsl #0x10
	mov     r1, r1, asr #0x10
	bl      Matrix4x3_FromRotationY
	add     r0, r13, #0x0
	mov     r1, r4
	mov     r2, r11
	bl      MulVec3Mat4x3
	sub     r6, r9, #0x1
	add     r2, r10, #0x3cc
	mov     r1, #0x0c
	mla     r1, r6, r1, r2
	add     r0, r13, #0x18
	mov     r2, r11
	bl      Vec3_Add
	ldr     r1, [r13, #0x18]
	mov     r0, #0x6
	str     r1, [r8, #0x3cc]
	mla     r0, r6, r0, r10
	ldr     r2, [r13, #0x1c]
	add     r0, r0, #0x400
	str     r2, [r8, #0x3d0]
	ldr     r2, [r13, #0x20]
	add     r1, r7, #0x400
	str     r2, [r8, #0x3d4]
	ldrsh   r0, [r0, #0x46]
	strh    r0, [r1, #0x46]
LAB_02112590:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x0c
	add     r7, r7, #0x6
	blt     LAB_021124b8
	add     r13, r13, #0x24
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021125b8:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x8c4]
	ldr     r2, [r0, #0x8c4]
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
FUN_02112604:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r2, [r0, #0x8c4]
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
FUN_02112650:
	sub     r13, r13, #0x10
	ldr     r0, [r2, #0x0a8]
	ldr     r1, [r1, #0x10]
	cmp     r0, #0x0
	bge     LAB_0211267c
	cmp     r1, #0x0
	bge     LAB_0211267c
	cmp     r1, r0
	movgt   r0, #0x1
	addgt   r13, r13, #0x10
	bxgt    r14
LAB_0211267c:
	mov     r0, #0x0
	add     r13, r13, #0x10
	bx      r14
.ltorg)");

asm(R"(
FUN_02112688:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x3c
	ldr     r1, =#0x478
	mov     r10, r0
	add     r7, r10, r1
	mov     r9, #0x0
	str     r9, [r13, #0x0c]
	mov     r5, r9
	mov     r6, #0x1
	mov     r4, #0x2
	mov     r11, #0x0c000
	mov     r0, #0x8
	str     r0, [r13, #0x10]
LAB_021126bc:
	add     r0, r10, r9, lsl #0x6
	ldr     r0, [r0, #0x49c]
	cmp     r0, #0x0
	beq     LAB_021127c8
	bl      _ZN5Actor10FindWithIDEj
	movs    r8, r0
	beq     LAB_021127c8
	ldrh    r0, [r8, #0x0c]
	cmp     r0, #0x0bf
	moveq   r0, r6
	ldrne   r0, [r13, #0x0c]
	cmp     r0, #0x0
	beq     LAB_021127c8
	add     r3, r8, #0x5c
	ldr     r1, [r3]
	mov     r0, r10
	str     r1, [r13, #0x14]
	ldr     r2, [r3, #0x4]
	mov     r1, r7
	str     r2, [r13, #0x18]
	ldr     r3, [r3, #0x8]
	mov     r2, r8
	str     r3, [r13, #0x1c]
	bl      FUN_02112650
	cmp     r0, #0x0
	beq     LAB_0211277c
	mov     r0, r8
	mov     r1, #0x28000
	bl      _ZN6Player6BounceE5Fix12IiE
	add     r1, r10, #0x74
	mov     r0, #0x11c
	bl      0x0201267c
	cmp     r9, #0x1
	addhi   r0, r10, r9
	movhi   r1, #0x1e
	strhib  r1, [r0, #0x702]
	addhi   r13, r13, #0x3c
	pophi   { r4-r11, r14 }
	bxhi    r14
	mov     r0, #0x1e
	strb    r0, [r10, #0x702]
	mov     r0, r10
	mov     r1, #0x5
	str     r8, [r10, #0x8c8]
	bl      FUN_021125b8
	add     r13, r13, #0x3c
	pop     { r4-r11, r14 }
	bx      r14
LAB_0211277c:
	cmp     r9, #0x0
	bne     LAB_021127c8
	ldr     r1, [r10, #0x5c]
	mov     r0, r8
	str     r1, [r13, #0x20]
	ldr     r2, [r10, #0x60]
	add     r1, r13, #0x20
	str     r2, [r13, #0x24]
	ldr     r3, [r10, #0x64]
	mov     r2, r4
	str     r3, [r13, #0x28]
	str     r6, [r13]
	str     r5, [r13, #0x4]
	mov     r3, r11
	str     r6, [r13, #0x8]
	bl      _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj
	ldr     r1, [r13, #0x10]
	mov     r0, r10
	bl      FUN_021125b8
LAB_021127c8:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r7, r7, #0x40
	blt     LAB_021126bc
	mov     r6, #0x0
	add     r8, r13, #0x2c
	mov     r4, r6
	mov     r9, r6
	mov     r5, #0x1
	mov     r7, #0x5000
LAB_021127f0:
	add     r0, r10, r6, lsl #0x6
	ldr     r0, [r0, #0x5dc]
	cmp     r0, #0x0
	beq     LAB_02112858
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	beq     LAB_02112858
	ldrh    r1, [r0, #0x0c]
	cmp     r1, #0x0bf
	moveq   r1, r5
	movne   r1, r4
	cmp     r1, #0x0
	beq     LAB_02112858
	ldr     r2, [r10, #0x5c]
	mov     r1, r8
	str     r2, [r13, #0x2c]
	ldr     r3, [r10, #0x60]
	mov     r2, r9
	str     r3, [r13, #0x30]
	ldr     r11, [r10, #0x64]
	mov     r3, r7
	str     r11, [r13, #0x34]
	str     r5, [r13]
	str     r9, [r13, #0x4]
	str     r5, [r13, #0x8]
	bl      _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj
LAB_02112858:
	add     r6, r6, #0x1
	cmp     r6, #0x5
	blt     LAB_021127f0
	add     r13, r13, #0x3c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112874:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x7c
	mov     r10, r0
	add     r0, r10, #0x3cc
	add     r8, r0, #0x0c
	add     r7, r10, #0x6
	add     r6, r10, #0x0c
	mov     r9, #0x1
	add     r5, r13, #0x4
	add     r4, r13, #0x28
	mov     r0, #0x0
	str     r0, [r13]
LAB_021128a4:
	sub     r1, r9, #0x1
	mov     r0, #0x0c
	mul     r11, r1, r0
	add     r2, r10, #0x3cc
	mov     r0, r5
	mov     r1, r8
	add     r2, r2, r11
	bl      Vec3_Sub
	mov     r0, r5
	bl      0x0203ce2c
	cmp     r0, #0x0
	beq     LAB_021128e4
	add     r0, r10, r9, lsl #0x2
	ldr     r1, [r0, #0x464]
	mov     r0, r5
	bl      Vec3_MulScalarInPlace
LAB_021128e4:
	add     r0, r10, #0x3cc
	add     r11, r0, r11
	mov     r0, r8
	mov     r1, r11
	bl      Vec3_HorzAngle
	add     r2, r7, #0x400
	strh    r0, [r2, #0x46]
	mov     r1, r11
	add     r0, r13, #0x1c
	mov     r2, r5
	bl      Vec3_Add
	ldr     r0, [r13, #0x1c]
	add     r1, r10, r9, lsl #0x6
	str     r0, [r6, #0x3cc]
	ldr     r0, [r13, #0x20]
	str     r0, [r6, #0x3d0]
	ldr     r0, [r13, #0x24]
	str     r0, [r6, #0x3d4]
	ldr     r0, [r6, #0x3cc]
	str     r0, [r1, #0x4ac]
	ldr     r0, [r6, #0x3d0]
	str     r0, [r1, #0x4b0]
	ldr     r0, [r6, #0x3d4]
	str     r0, [r1, #0x4b4]
	ldr     r0, [r6, #0x3cc]
	str     r0, [r1, #0x5ec]
	ldr     r0, [r6, #0x3d0]
	str     r0, [r1, #0x5f0]
	ldr     r0, [r6, #0x3d4]
	str     r0, [r1, #0x5f4]
	ldrb    r0, [r10, #0x8df]
	cmp     r0, #0x0
	bne     LAB_021129c8
	mov     r0, r4
	bl      _ZN13RaycastGroundC1Ev
	ldr     r1, [r6, #0x3cc]
	mov     r0, r4
	str     r1, [r13, #0x10]
	ldr     r2, [r6, #0x3d0]
	add     r1, r13, #0x10
	str     r2, [r13, #0x14]
	add     r3, r2, #0x3c000
	ldr     r11, [r6, #0x3d4]
	ldr     r2, [r13]
	str     r11, [r13, #0x18]
	str     r3, [r13, #0x14]
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	mov     r0, r4
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	beq     LAB_021129c0
	ldr     r1, [r13, #0x6c]
	ldr     r0, [r6, #0x3d0]
	cmp     r0, r1
	strle   r1, [r6, #0x3d0]
LAB_021129c0:
	mov     r0, r4
	bl      _ZN13RaycastGroundD1Ev
LAB_021129c8:
	add     r9, r9, #0x1
	cmp     r9, #0x5
	add     r8, r8, #0x0c
	add     r7, r7, #0x6
	add     r6, r6, #0x0c
	blt     LAB_021128a4
	add     r13, r13, #0x7c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021129ec:
	push    { r4-r8, r14 }
	mov     r8, r0
	mov     r5, r8
	mov     r4, r8
	add     r6, r8, #0x110
	mov     r7, #0x0
LAB_02112a04:
	add     r0, r8, #0x400
	ldrsh   r1, [r0, #0x46]
	add     r0, r6, #0x1c
	bl      Matrix4x3_FromRotationY
	ldr     r0, [r5, #0x3cc]
	add     r7, r7, #0x1
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x150]
	ldr     r0, [r5, #0x3d0]
	cmp     r7, #0x5
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x154]
	ldr     r0, [r5, #0x3d4]
	add     r8, r8, #0x6
	mov     r0, r0, asr #0x3
	str     r0, [r4, #0x158]
	add     r6, r6, #0x64
	add     r5, r5, #0x0c
	add     r4, r4, #0x64
	blt     LAB_02112a04
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112a5c:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x4
	ldr     r9, =MODEL_FILE_PTRS
	ldr     r8, =TEX_SEQ_FILE_PTRS
	ldr     r7, =WAIT_ANIM_FILE_PTRS
	ldr     r6, =WALK_ANIM_FILE_PTRS
	ldr     r5, =WALK_START_ANIM_FILE_PTRS
	ldr     r4, =WALK_END_ANIM_FILE_PTRS
	ldr     r11, =DAMAGE_ANIM_FILE_PTRS
	mov     r10, #0x0
LAB_02112a84:
	ldr     r0, [r9, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r8, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r7, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r6, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r5, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r4, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, [r11, r10, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	add     r10, r10, #0x1
	cmp     r10, #0x5
	blt     LAB_02112a84
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112af4:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x4
	ldr     r1, =#0x408
	add     r6, r0, #0x110
	add     r5, r0, #0x368
	add     r4, r0, r1
	mov     r7, #0x0
LAB_02112b10:
	mov     r0, r5
	add     r1, r6, #0x8
	bl      _ZN15TextureSequence6UpdateER15ModelComponents
	mov     r0, r6
	ldr     r2, [r0]
	mov     r1, r4
	ldr     r2, [r2, #0x14]
	blx     r2
	add     r7, r7, #0x1
	cmp     r7, #0x5
	add     r6, r6, #0x64
	add     r5, r5, #0x14
	add     r4, r4, #0x0c
	blt     LAB_02112b10
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112b5c:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x74
	mov     r9, r0
	ldrb    r1, [r9, #0x8df]
	cmp     r1, #0x0
	beq     LAB_02112b94
	ldr     r3, [r9, #0x8d0]
	ldr     r2, [r9, #0x60]
	mov     r1, #0x1f4000
	add     r2, r3, r2
	rsb     r1, r1, #0x0
	cmp     r2, r1
	bge     LAB_02112b94
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02112b94:
	mov     r0, r9
	bl      FUN_02112604
	ldr     r0, [r9, #0x0a8]
	cmp     r0, #0x0
	bgt     LAB_02112bdc
	ldr     r2, [r9, #0x98]
	add     r1, r9, #0x800
	mov     r0, r2, asr #0x0b
	add     r0, r2, r0, lsr #0x14
	mov     r2, r0, asr #0x0c
	mov     r0, #0x1e
	mul     r3, r2, r0
	ldr     r0, =#0x446
	mov     r2, r3, lsl #0x10
	ldrsh   r1, [r1, #0x0d8]
	add     r0, r9, r0
	mov     r2, r2, asr #0x10
	bl      _Z14ApproachLinearRsss
LAB_02112bdc:
	ldr     r0, =#0x708
	add     r0, r9, r0
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	beq     LAB_02112c08
	mov     r0, #0x1000
	rsb     r2, r0, #0x0
	mov     r0, r9
	mov     r1, #0x1
	str     r2, [r9, #0x9c]
	bl      _ZN5Actor11LandingDustEb
LAB_02112c08:
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	ldr     r1, [r9, #0x170]
	ldr     r0, [r0]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	beq     LAB_02112c48
	ldr     r0, =WALK_ANIM_FILE_PTRS
	ldr     r0, [r0]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	beq     LAB_02112c48
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	ldr     r0, [r0]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02112cb4
LAB_02112c48:
	ldr     r0, =#0x708
	add     r0, r9, r0
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02112cb4
	ldr     r0, [r9, #0x168]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x6
	bne     LAB_02112c98
	ldrb    r0, [r9, #0x8db]
	cmp     r0, #0x2
	bne     LAB_02112c8c
	ldr     r0, =#0x10a
	add     r1, r9, #0x74
	bl      0x0201267c
	b       LAB_02112c98
LAB_02112c8c:
	ldr     r0, =#0x11d
	add     r1, r9, #0x74
	bl      0x0201267c
LAB_02112c98:
	ldrb    r0, [r9, #0x8db]
	cmp     r0, #0x2
	bne     LAB_02112cb4
	ldr     r0, [r9, #0x5c]
	ldr     r1, [r9, #0x60]
	ldr     r2, [r9, #0x64]
	bl      0x02022b58
LAB_02112cb4:
	ldr     r0, =DAMAGE_ANIM_FILE_PTRS
	ldr     r1, [r9, #0x170]
	ldr     r0, [r0]
	str     r0, [r13, #0x0c]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02112cf0
	ldr     r0, [r9, #0x168]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x0f
	bne     LAB_02112cf0
	ldr     r0, =#0x11e
	add     r1, r9, #0x74
	bl      0x0201267c
LAB_02112cf0:
	ldr     r0, =#0x40c
	mov     r7, r9
	mov     r5, r9
	add     r6, r9, #0x160
	add     r4, r9, r0
	mov     r8, #0x0
	str     r8, [r13, #0x10]
	str     r8, [r13, #0x14]
	mov     r11, #0x1
	mov     r0, #0x1000
	str     r0, [r13, #0x18]
LAB_02112d1c:
	ldrb    r0, [r9, #0x8db]
	rsb     r0, r0, #0x4
	mov     r0, r0, lsl #0x10
	mov     r1, r0, lsr #0x10
	cmp     r1, #0x3
	ldrcs   r1, [r13, #0x10]
	ldr     r0, [r13, #0x14]
	cmp     r1, #0x2
	movls   r0, r11
	cmp     r0, #0x0
	movne   r0, r1, lsl #0x0c
	strne   r0, [r7, #0x370]
	ldrb    r0, [r9, #0x8df]
	cmp     r0, #0x0
	bne     LAB_02112d60
	mov     r0, r6
	bl      _ZN9Animation7AdvanceEv
LAB_02112d60:
	ldrb    r0, [r9, #0x8e0]
	cmp     r0, #0x0
	bne     LAB_02112e18
	ldr     r0, =#0x702
	add     r0, r9, r0
	add     r0, r0, r8
	bl      DecIfAbove0_Byte
	cmp     r0, #0x0
	beq     LAB_02112e08
	ldr     r0, =#0x6f8
	add     r2, r9, r8, lsl #0x1
	add     r1, r2, r0
	ldrsh   r10, [r1]
	add     r3, r2, #0x600
	mov     r2, #0x0
	add     r10, r10, #0x1200
	strh    r10, [r1]
	ldrh    r3, [r3, #0x0f8]
	mov     r0, #0x3000
	mov     r1, #0x800
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x1
	add     r3, r3, #0x1
	mov     r10, r3, lsl #0x1
	ldr     r3, =SINE_TABLE
	ldrsh   r12, [r3, r10]
	umull   r10, r14, r12, r0
	mla     r14, r12, r2, r14
	mov     r3, r12, asr #0x1f
	adds    r1, r10, r1
	mla     r14, r3, r0, r14
	adc     r0, r14, #0x0
	mov     r1, r1, lsr #0x0c
	orr     r1, r1, r0, lsl #0x14
	ldr     r0, =#0x66666667
	add     r2, r1, #0x0c000
	smull   r1, r3, r0, r2
	mov     r0, r2, lsr #0x1f
	mov     r3, r3, asr #0x2
	add     r3, r0, r3
	str     r3, [r5, #0x40c]
	b       LAB_02112e18
LAB_02112e08:
	ldr     r1, [r13, #0x18]
	ldr     r2, =#0x199
	mov     r0, r4
	bl      _Z14ApproachLinearRiii
LAB_02112e18:
	add     r7, r7, #0x14
	add     r6, r6, #0x64
	add     r5, r5, #0x0c
	add     r4, r4, #0x0c
	add     r8, r8, #0x1
	cmp     r8, #0x5
	blt     LAB_02112d1c
	ldrb    r0, [r9, #0x8db]
	cmp     r0, #0x4
	bne     LAB_02112e58
	ldrb    r0, [r9, #0x8de]
	cmp     r0, #0x0
	movne   r0, #0x1000
	strne   r0, [r9, #0x370]
	moveq   r0, #0x0
	streq   r0, [r9, #0x370]
LAB_02112e58:
	add     r0, r9, #0x400
	ldrsh   r2, [r0, #0x46]
	mov     r0, r9
	mov     r1, #0x0
	strh    r2, [r9, #0x94]
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	ldrb    r0, [r9, #0x8df]
	cmp     r0, #0x0
	bne     LAB_02112e90
	ldr     r1, =#0x708
	mov     r0, r9
	add     r1, r9, r1
	mov     r2, #0x0
	bl      _ZN5Enemy12UpdateWMClsnER12WithMeshClsnj
LAB_02112e90:
	ldr     r1, [r9, #0x5c]
	mov     r0, r9
	str     r1, [r9, #0x3cc]
	ldr     r1, [r9, #0x60]
	str     r1, [r9, #0x3d0]
	ldr     r1, [r9, #0x64]
	str     r1, [r9, #0x3d4]
	bl      FUN_02112874
	ldr     r1, [r9, #0x3dc]
	add     r0, r9, #0x400
	add     r1, r1, #0x1000
	str     r1, [r9, #0x3d0]
	ldr     r3, [r9, #0x3cc]
	ldr     r8, =SINE_TABLE
	str     r3, [r13, #0x1c]
	ldr     r1, [r9, #0x3d0]
	mov     r2, #0x0
	str     r1, [r13, #0x20]
	ldr     r4, [r9, #0x3d4]
	mov     r5, #0x64000
	str     r4, [r13, #0x24]
	ldrh    r6, [r0, #0x46]
	mov     r1, #0x800
	mov     r6, r6, asr #0x4
	mov     r6, r6, lsl #0x2
	ldrsh   r6, [r8, r6]
	umull   r10, r7, r6, r5
	mla     r7, r6, r2, r7
	mov     r6, r6, asr #0x1f
	mla     r7, r6, r5, r7
	adds    r10, r10, r1
	adc     r6, r7, #0x0
	mov     r7, r10, lsr #0x0c
	orr     r7, r7, r6, lsl #0x14
	add     r3, r3, r7
	str     r3, [r13, #0x1c]
	ldrh    r6, [r0, #0x46]
	mov     r6, r6, asr #0x4
	mov     r6, r6, lsl #0x1
	add     r6, r6, #0x1
	mov     r6, r6, lsl #0x1
	ldrsh   r7, [r8, r6]
	umull   r6, r10, r7, r5
	adds    r6, r6, r1
	mov     r11, r6, lsr #0x0c
	mla     r10, r7, r2, r10
	mov     r6, r7, asr #0x1f
	mla     r10, r6, r5, r10
	adc     r5, r10, #0x0
	orr     r11, r11, r5, lsl #0x14
	add     r4, r4, r11
	str     r4, [r13, #0x24]
	str     r3, [r9, #0x4ac]
	ldr     r3, [r13, #0x20]
	str     r3, [r9, #0x4b0]
	ldr     r3, [r13, #0x24]
	str     r3, [r9, #0x4b4]
	ldr     r3, [r13, #0x1c]
	str     r3, [r9, #0x5ec]
	ldr     r3, [r13, #0x20]
	str     r3, [r9, #0x5f0]
	ldr     r3, [r13, #0x24]
	str     r3, [r9, #0x5f4]
	ldr     r3, [r13, #0x0c]
	ldr     r4, [r9, #0x170]
	ldr     r3, [r3, #0x4]
	cmp     r4, r3
	beq     LAB_02113098
	ldrb    r3, [r9, #0x8db]
	rsb     r3, r3, #0x4
	and     r10, r3, #0x0ff
	cmp     r10, #0x3
	bcs     LAB_02113098
	ldr     r7, [r9, #0x3cc]
	mov     r11, #0x23000
	str     r7, [r13, #0x28]
	ldr     r6, [r9, #0x3d0]
	str     r6, [r13, #0x2c]
	ldr     r5, [r9, #0x3d4]
	str     r5, [r13, #0x30]
	ldrh    r3, [r0, #0x46]
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x2
	ldrsh   r12, [r8, r3]
	umull   r4, r3, r12, r11
	mla     r3, r12, r2, r3
	mov     r12, r12, asr #0x1f
	adds    r4, r4, r1
	mla     r3, r12, r11, r3
	adc     r3, r3, r2
	mov     r4, r4, lsr #0x0c
	orr     r4, r4, r3, lsl #0x14
	add     r3, r7, r4
	str     r3, [r13, #0x28]
	ldrh    r0, [r0, #0x46]
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x1
	add     r0, r0, #0x1
	mov     r0, r0, lsl #0x1
	ldrsh   r0, [r8, r0]
	umull   r4, r3, r0, r11
	mla     r3, r0, r2, r3
	mov     r0, r0, asr #0x1f
	adds    r1, r4, r1
	mla     r3, r0, r11, r3
	adc     r0, r3, r2
	mov     r1, r1, lsr #0x0c
	orr     r1, r1, r0, lsl #0x14
	add     r0, r5, r1
	str     r0, [r13, #0x30]
	cmp     r10, #0x0
	addeq   r0, r6, #0x89000
	streq   r0, [r13, #0x2c]
	addne   r0, r6, #0x0b9000
	strne   r0, [r13, #0x2c]
	ldrb    r0, [r9, #0x8de]
	cmp     r0, #0x0
	beq     LAB_02113098
	ldr     r1, [r13, #0x30]
	mov     r0, #0x0
	str     r1, [r13]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	ldr     r1, =PARTICLE_IDS
	ldr     r0, [r9, #0x8e4]
	ldr     r1, [r1, r10, lsl #0x2]
	ldr     r2, [r13, #0x28]
	ldr     r3, [r13, #0x2c]
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r9, #0x8e4]
LAB_02113098:
	mov     r0, r9
	bl      FUN_021129ec
	ldr     r0, =#0x478
	ldr     r1, =#0x5b8
	add     r5, r9, r0
	add     r4, r9, r1
	mov     r6, #0x0
LAB_021130b4:
	mov     r0, r5
	bl      _ZN12CylinderClsn5ClearEv
	mov     r0, r5
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, r4
	bl      _ZN12CylinderClsn5ClearEv
	mov     r0, r4
	bl      _ZN12CylinderClsn6UpdateEv
	add     r6, r6, #0x1
	cmp     r6, #0x5
	add     r5, r5, #0x40
	add     r4, r4, #0x40
	blt     LAB_021130b4
	ldrb    r0, [r9, #0x8e1]
	cmp     r0, #0x0
	beq     LAB_021131dc
	mov     r3, #0x0
	mov     r1, #0x80000
	mov     r0, #0x1f4000
	str     r0, [r13, #0x48]
	ldr     r2, =CAMERA
	str     r3, [r13, #0x34]
	str     r3, [r13, #0x3c]
	str     r3, [r13, #0x40]
	str     r3, [r13, #0x4c]
	str     r3, [r13, #0x50]
	str     r3, [r13, #0x54]
	add     r0, r9, #0x400
	str     r1, [r13, #0x38]
	str     r1, [r13, #0x44]
	ldrsh   r1, [r0, #0x46]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	ldr     r4, [r2]
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x34
	add     r2, r13, #0x4c
	bl      MulVec3Mat4x3
	add     r0, r13, #0x58
	add     r2, r13, #0x4c
	add     r1, r9, #0x5c
	bl      Vec3_Add
	mov     r2, #0x0
	ldr     r1, [r13, #0x58]
	ldr     r0, [r13, #0x5c]
	str     r1, [r13, #0x34]
	ldr     r1, [r13, #0x60]
	str     r0, [r13, #0x38]
	str     r1, [r13, #0x3c]
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x40
	str     r2, [r13, #0x4c]
	str     r2, [r13, #0x50]
	str     r2, [r13, #0x54]
	add     r2, r13, #0x4c
	bl      MulVec3Mat4x3
	add     r1, r9, #0x5c
	add     r0, r13, #0x64
	add     r2, r13, #0x4c
	bl      Vec3_Add
	ldr     r1, [r13, #0x64]
	ldr     r0, [r13, #0x68]
	str     r1, [r13, #0x40]
	ldr     r1, [r13, #0x6c]
	str     r0, [r13, #0x44]
	str     r1, [r13, #0x48]
	mov     r0, r4
	add     r1, r4, #0x80
	add     r2, r13, #0x34
	bl      0x020092c4
	mov     r0, r4
	add     r1, r4, #0x8c
	add     r2, r13, #0x40
	bl      0x020092c4
LAB_021131dc:
	mov     r0, #0x1
	add     r13, r13, #0x74
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211323c:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x74
	mov     r10, r0
	ldr     r0, [r10, #0x8]
	mov     r2, #0x2
	strb    r0, [r10, #0x8e2]
	ldrb    r0, [r10, #0x8e2]
	cmp     r0, #0x0ff
	moveq   r0, #0x0
	streqb  r0, [r10, #0x8e2]
	ldrb    r1, [r10, #0x8e2]
	mov     r0, r10
	bl      _ZN5Actor9TrackStarEjj
	ldr     r1, =#0x478
	strb    r0, [r10, #0x8e3]
	add     r0, r10, r1
	mov     r9, #0x0
	ldr     r2, =#0x5b8
	str     r0, [r13, #0x10]
	add     r0, r10, r2
	str     r0, [r13, #0x14]
	mov     r0, #0x78000
	str     r0, [r13, #0x40]
	mov     r0, #0x200000
	str     r0, [r13, #0x44]
	mov     r0, #0x32000
	str     r0, [r13, #0x48]
	mov     r0, #0x1
	str     r0, [r13, #0x2c]
	mvn     r0, #0x0
	str     r10, [r13, #0x0c]
	mov     r7, r10
	mov     r6, r10
	add     r8, r10, #0x110
	add     r11, r10, #0x368
	add     r5, r10, #0x3cc
	mov     r4, #0x1000
	str     r0, [r13, #0x30]
	str     r9, [r13, #0x34]
	str     r9, [r13, #0x38]
	str     r9, [r13, #0x3c]
LAB_021132e0:
	ldr     r0, =UNK_021138c4
	ldr     r1, [r0, r9, lsl #0x2]
	add     r0, r10, r9, lsl #0x2
	str     r1, [r0, #0x464]
	ldr     r0, =MODEL_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	str     r0, [r13, #0x18]
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	ldr     r0, =TEX_SEQ_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	str     r0, [r13, #0x20]
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	ldr     r0, =WAIT_ANIM_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	str     r0, [r13, #0x1c]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =WALK_ANIM_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =WALK_START_ANIM_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =WALK_END_ANIM_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =DAMAGE_ANIM_FILE_PTRS
	ldr     r0, [r0, r9, lsl #0x2]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r1, [r13, #0x18]
	ldr     r2, [r13, #0x2c]
	ldr     r1, [r1, #0x4]
	ldr     r3, [r13, #0x30]
	mov     r0, r8
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	ldr     r0, [r13, #0x34]
	ldr     r2, [r13, #0x34]
	str     r0, [r13]
	ldr     r0, [r13, #0x1c]
	mov     r3, r4
	ldr     r1, [r0, #0x4]
	mov     r0, r8
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	ldr     r0, [r13, #0x18]
	ldr     r1, [r13, #0x20]
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	ldr     r0, [r13, #0x38]
	ldr     r2, [r13, #0x38]
	str     r0, [r13]
	ldr     r0, [r13, #0x20]
	mov     r3, r4
	ldr     r1, [r0, #0x4]
	mov     r0, r11
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	ldr     r1, [r13, #0x3c]
	ldr     r0, [r13, #0x0c]
	cmp     r9, #0x0
	str     r1, [r0, #0x374]
	bne     LAB_02113410
	ldr     r1, [r10, #0x5c]
	add     r0, r6, #0x400
	str     r1, [r7, #0x3cc]
	ldr     r1, [r10, #0x60]
	str     r1, [r7, #0x3d0]
	ldr     r1, [r10, #0x64]
	str     r1, [r7, #0x3d4]
	ldrsh   r1, [r10, #0x8c]
	strh    r1, [r0, #0x44]
	ldrsh   r1, [r10, #0x8e]
	strh    r1, [r0, #0x46]
	ldrsh   r1, [r10, #0x90]
	strh    r1, [r0, #0x48]
	ldrsh   r0, [r0, #0x46]
	strh    r0, [r10, #0x94]
	b       LAB_021134b0
LAB_02113410:
	add     r0, r10, r9, lsl #0x2
	ldr     r1, [r0, #0x464]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	rsb     r1, r1, #0x0
	str     r1, [r13, #0x54]
	ldr     r1, [r13, #0x3c]
	str     r1, [r13, #0x4c]
	str     r1, [r13, #0x50]
	str     r1, [r13, #0x58]
	str     r1, [r13, #0x5c]
	str     r1, [r13, #0x60]
	add     r1, r10, #0x400
	ldrsh   r1, [r1, #0x46]
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x4c
	add     r2, r13, #0x58
	bl      MulVec3Mat4x3
	sub     r0, r9, #0x1
	str     r0, [r13, #0x24]
	ldr     r2, [r13, #0x24]
	add     r3, r10, #0x3cc
	mov     r1, #0x0c
	mla     r1, r2, r1, r3
	add     r0, r13, #0x64
	add     r2, r13, #0x58
	bl      Vec3_Add
	ldr     r2, [r13, #0x64]
	ldr     r0, [r13, #0x24]
	mov     r1, #0x6
	mla     r1, r0, r1, r10
	str     r2, [r7, #0x3cc]
	ldr     r2, [r13, #0x68]
	add     r0, r1, #0x400
	str     r2, [r7, #0x3d0]
	ldr     r2, [r13, #0x6c]
	add     r1, r6, #0x400
	str     r2, [r7, #0x3d4]
	ldrsh   r0, [r0, #0x46]
	strh    r0, [r1, #0x46]
LAB_021134b0:
	str     r4, [r7, #0x408]
	str     r4, [r7, #0x40c]
	ldr     r0, =CYLINDER_CLSN_RADIUS
	str     r4, [r7, #0x410]
	ldr     r0, [r0, r9, lsl #0x2]
	ldr     r1, [r13, #0x40]
	str     r0, [r13, #0x28]
	str     r1, [r13]
	ldr     r1, [r13, #0x44]
	ldr     r3, [r13, #0x28]
	str     r1, [r13, #0x4]
	ldr     r1, =#0x26fe0
	ldr     r0, [r13, #0x10]
	str     r1, [r13, #0x8]
	mov     r1, r10
	mov     r2, r5
	add     r3, r3, #0x0a000
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	ldr     r0, [r13, #0x48]
	ldr     r3, [r13, #0x28]
	str     r0, [r13]
	ldr     r0, =#0x200004
	mov     r1, r10
	str     r0, [r13, #0x4]
	ldr     r0, =#0x26fe0
	mov     r2, r5
	str     r0, [r13, #0x8]
	ldr     r0, [r13, #0x14]
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	ldr     r0, [r13, #0x0c]
	add     r9, r9, #0x1
	add     r0, r0, #0x14
	str     r0, [r13, #0x0c]
	ldr     r0, [r13, #0x10]
	add     r8, r8, #0x64
	add     r0, r0, #0x40
	str     r0, [r13, #0x10]
	ldr     r0, [r13, #0x14]
	add     r11, r11, #0x14
	add     r0, r0, #0x40
	add     r7, r7, #0x0c
	add     r6, r6, #0x6
	add     r5, r5, #0x0c
	str     r0, [r13, #0x14]
	cmp     r9, #0x5
	blt     LAB_021132e0
	mov     r3, #0x1000
	rsb     r1, r3, #0x0
	mov     r0, #0x64000
	str     r1, [r10, #0x9c]
	rsb     r0, r0, #0x0
	str     r0, [r10, #0x0a0]
	mov     r1, #0x0c
	ldr     r0, =WALK_ANIM_FILE_PTRS
	str     r1, [r13]
	ldr     r1, [r0]
	add     r0, r10, #0x110
	ldr     r1, [r1, #0x4]
	mov     r2, #0x0
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r0, r10, #0x110
	add     r7, r0, #0x64
	mov     r8, #0x1
	ldr     r6, =WALK_ANIM_FILE_PTRS
	mov     r5, #0x0
	mov     r4, #0x1000
	mov     r9, #0x3
LAB_021135bc:
	rsb     r0, r8, #0x5
	mul     r1, r0, r9
	mov     r0, r1, lsl #0x10
	mov     r0, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	str     r0, [r13]
	ldr     r1, [r6, r8, lsl #0x2]
	mov     r0, r7
	ldr     r1, [r1, #0x4]
	mov     r2, r5
	mov     r3, r4
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	add     r8, r8, #0x1
	cmp     r8, #0x5
	add     r7, r7, #0x64
	blt     LAB_021135bc
	mov     r0, r10
	mov     r1, #0x0
	bl      FUN_021125b8
	ldr     r0, =#0x708
	mov     r4, #0x0
	mov     r2, #0x14000
	str     r4, [r13]
	mov     r1, r10
	mov     r3, r2
	add     r0, r10, r0
	str     r4, [r13, #0x4]
	bl      _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_
	mov     r1, #0x4
	mov     r0, r10
	strb    r1, [r10, #0x8db]
	bl      FUN_021129ec
	ldr     r1, [r10, #0x5c]
	mov     r0, #0x1
	str     r1, [r10, #0x8cc]
	ldr     r1, [r10, #0x60]
	str     r1, [r10, #0x8d0]
	ldr     r1, [r10, #0x64]
	str     r1, [r10, #0x8d4]
	add     r13, r13, #0x74
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021136a4:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	ldr     r0, =#0x8e8
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_021137c4
	bl      _ZN5EnemyC2Ev
	ldr     r0, =VTable_Wiggler
	ldr     r12, =_ZN9ModelAnimD1Ev
	str     r0, [r4]
	ldr     r3, =_ZN9ModelAnimC1Ev
	add     r0, r4, #0x110
	mov     r1, #0x5
	mov     r2, #0x64
	str     r12, [r13]
	bl      0x020733a8
	ldr     r12, =_ZN15MaterialChangerD1Ev
	ldr     r3, =_ZN15MaterialChangerC1Ev
	add     r0, r4, #0x304
	mov     r1, #0x5
	mov     r2, #0x14
	str     r12, [r13]
	bl      0x020733a8
	ldr     r1, =_ZN15TextureSequenceD1Ev
	add     r0, r4, #0x368
	str     r1, [r13]
	mov     r1, #0x5
	mov     r2, #0x14
	ldr     r3, =_ZN15TextureSequenceC1Ev
	bl      0x020733a8
	ldr     r1, =#0x20072c0
	add     r0, r4, #0x3cc
	str     r1, [r13]
	mov     r1, #0x5
	mov     r2, #0x0c
	ldr     r3, =#0x203d384
	bl      0x020733a8
	ldr     r1, =#0x20072c0
	ldr     r0, =#0x408
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x0c
	ldr     r3, =#0x203d384
	bl      0x020733a8
	ldr     r1, =#0x2011508
	ldr     r0, =#0x444
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x6
	ldr     r3, =#0x203d73c
	bl      0x020733a8
	ldr     r1, =_ZN25MovingCylinderClsnWithPosD1Ev
	ldr     r0, =#0x478
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	ldr     r3, =_ZN25MovingCylinderClsnWithPosC1Ev
	bl      0x020733a8
	ldr     r1, =_ZN25MovingCylinderClsnWithPosD1Ev
	ldr     r0, =#0x5b8
	str     r1, [r13]
	add     r0, r4, r0
	mov     r1, #0x5
	mov     r2, #0x40
	ldr     r3, =_ZN25MovingCylinderClsnWithPosC1Ev
	bl      0x020733a8
	ldr     r0, =#0x708
	add     r0, r4, r0
	bl      _ZN12WithMeshClsnC1Ev
LAB_021137c4:
	mov     r0, r4
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");