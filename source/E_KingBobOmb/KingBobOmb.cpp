#include "SM64DS_2.h"
#include "Actors/KingBobOmb.h"

extern "C"
{
	ActorBase* FUN_021265fc(); // constructor
	
	// state function declarations for use below
	void FUN_021243c0(KingBobOmb* kingBobOmb);
	void FUN_021240a0(KingBobOmb* kingBobOmb);
	void FUN_021259e4(KingBobOmb* kingBobOmb);
	void FUN_02125950(KingBobOmb* kingBobOmb);
	void FUN_021258e4(KingBobOmb* kingBobOmb);
	void FUN_02125790(KingBobOmb* kingBobOmb);
	void FUN_02124060(KingBobOmb* kingBobOmb);
	void FUN_02124000(KingBobOmb* kingBobOmb);
	void FUN_02125734(KingBobOmb* kingBobOmb);
	void FUN_02125448(KingBobOmb* kingBobOmb);
	void FUN_02125350(KingBobOmb* kingBobOmb);
	void FUN_021250f8(KingBobOmb* kingBobOmb);
	void FUN_02123a3c(KingBobOmb* kingBobOmb);
	void FUN_021238ac(KingBobOmb* kingBobOmb);
	void FUN_02123fb4(KingBobOmb* kingBobOmb);
	void FUN_02123f1c(KingBobOmb* kingBobOmb);
	void FUN_021250d0(KingBobOmb* kingBobOmb);
	void FUN_02124f28(KingBobOmb* kingBobOmb);
	void FUN_02124e9c(KingBobOmb* kingBobOmb);
	void FUN_02124cf4(KingBobOmb* kingBobOmb);
	void FUN_02123eb8(KingBobOmb* kingBobOmb);
	void FUN_02123d3c(KingBobOmb* kingBobOmb);
	void FUN_02124c94(KingBobOmb* kingBobOmb);
	void FUN_02124bc4(KingBobOmb* kingBobOmb);
	void FUN_02124b40(KingBobOmb* kingBobOmb);
	void FUN_021247bc(KingBobOmb* kingBobOmb);
	void FUN_02123cf0(KingBobOmb* kingBobOmb);
	void FUN_02123c20(KingBobOmb* kingBobOmb);
	void FUN_02124778(KingBobOmb* kingBobOmb);
	void FUN_02124520(KingBobOmb* kingBobOmb);
	void FUN_021244d0(KingBobOmb* kingBobOmb);
	void FUN_02124470(KingBobOmb* kingBobOmb);
	void FUN_02123bc4(KingBobOmb* kingBobOmb);
	void FUN_02123aa0(KingBobOmb* kingBobOmb);
	void FUN_02125bc8(KingBobOmb* kingBobOmb);
	void FUN_021259ec(KingBobOmb* kingBobOmb);
	
	// undocumented globals not in ov78:
	// 0x0200d8c8
	// 0x02092138
	
	// undocumented functions not in ov78:
	// 0x0214ae1c (ov102)
	// 0x0214ad14 (ov102)
	
	// 0x02126e00
	Vector3 UNK_02126e00 = Vector3{ 0._f, 60._f, 0._f };
	
	using StateFunc = void(*)(KingBobOmb*);
	
	struct State
	{
		StateFunc func;
		void* unk04 = nullptr;
	};
	
	State states[18][2] = // 0x02126ffc
	{
		{ { &FUN_021243c0 }, { &FUN_021240a0 } },
		{ { &FUN_021259e4 }, { &FUN_02125950 } },
		{ { &FUN_021258e4 }, { &FUN_02125790 } },
		{ { &FUN_02124060 }, { &FUN_02124000 } },
		{ { &FUN_02125734 }, { &FUN_02125448 } },
		{ { &FUN_02125350 }, { &FUN_021250f8 } },
		{ { &FUN_02123a3c }, { &FUN_021238ac } },
		{ { &FUN_02123fb4 }, { &FUN_02123f1c } },
		{ { &FUN_021250d0 }, { &FUN_02124f28 } },
		{ { &FUN_02124e9c }, { &FUN_02124cf4 } },
		{ { &FUN_02123eb8 }, { &FUN_02123d3c } },
		{ { &FUN_02124c94 }, { &FUN_02124bc4 } },
		{ { &FUN_02124b40 }, { &FUN_021247bc } },
		{ { &FUN_02123cf0 }, { &FUN_02123c20 } },
		{ { &FUN_02124778 }, { &FUN_02124520 } },
		{ { &FUN_021244d0 }, { &FUN_02124470 } },
		{ { &FUN_02123bc4 }, { &FUN_02123aa0 } },
		{ { &FUN_02125bc8 }, { &FUN_021259ec } },
	};
	
	Vector3 CARRY_POSITION_OFFSET[2] = // 0x0212711c (relative to player)
	{
		Vector3{ 44._f, -25._f, 52._f }, // anyone else
		Vector3{ 68._f, -25._f, 52._f }, // wario
	};
}

SharedFilePtr KingBobOmb::modelFile;
SharedFilePtr KingBobOmb::animFiles[12];

SpawnInfo KingBobOmb::spawnData = 
{
	&FUN_021265fc,
	0x00bd,
	0x002c,
	Actor::NO_BEHAVIOR_IF_OFF_SCREEN | Actor::NO_RENDER_IF_OFF_SCREEN | Actor::AIMABLE_BY_EGG,
	0._f,
	400._f,
	8096._f,
	8096._f,
};

asm(R"(
@ 0x02126e4c
VTable_KingBobOmb:
	.word FUN_02126368
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02125ff4
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02126104
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_021260ac
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word FUN_021260a8
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02123740
	.word FUN_02123798
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
	.word FUN_021265f4
	.word _ZN5Actor25OnAimedAtWithEggReturnVecEv
.ltorg)");

asm(R"(
FUN_02123740:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_KingBobOmb
	add     r0, r4, #0x3f8
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x3bc
	bl      _ZN11CommonModelD1Ev
	add     r0, r4, #0x37c
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x33c
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x2cc
	bl      _ZN14BlendModelAnimD1Ev
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsnD1Ev
	mov     r0, r4
	bl      0x020aed18
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123798:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_KingBobOmb
	add     r0, r4, #0x3f8
	str     r1, [r4]
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x3bc
	bl      _ZN11CommonModelD1Ev
	add     r0, r4, #0x37c
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x33c
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x2cc
	bl      _ZN14BlendModelAnimD1Ev
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsnD1Ev
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
FUN_02123804:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x3a0]
	cmp     r0, #0x0
	moveq   r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	moveq   r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, [r4, #0x39c]
	ands    r0, r0, #0x4000
	moveq   r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r1, =states + 0x000
	mov     r0, r4
	bl      FUN_02125c48
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123864:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x4
	mov     r7, r0
	mov     r6, #0x0
	mov     r5, r6
	mov     r4, #0x1
LAB_0212387c:
	add     r0, r7, r6, lsl #0x2
	ldr     r0, [r0, #0x424]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	strne   r5, [r0, #0x3e0]
	add     r6, r6, #0x1
	strneb  r4, [r0, #0x3f6]
	cmp     r6, #0x2
	blt     LAB_0212387c
	add     r13, r13, #0x4
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021238ac:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x2c
	mov     r4, r0
	ldr     r1, =CAMERA
	ldr     r0, [r4, #0x430]
	ldr     r5, [r1]
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	beq     LAB_021238ec
	mov     r0, r5
	bl      _ZN6Camera9SetFlag_3Ev
	add     r13, r13, #0x2c
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_021238ec:
	add     r1, r5, #0x154
	ldr     r0, [r1]
	ldr     r14, =MATRIX_SCRATCH_PAPER
	bic     r0, r0, #0x8
	str     r0, [r1]
	mov     r0, #0x0
	add     r5, r4, #0x2e8
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	str     r0, [r13, #0x0c]
	mov     r12, r14
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5, { r0-r3 }
	stmia   r14, { r0-r3 }
	ldr     r0, [r4, #0x2e0]
	mov     r1, r12
	add     r0, r0, #0x30
	mov     r2, r12
	bl      MulMat4x3Mat4x3
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x10
	ldr     r2, [r1, #0x28]
	ldr     r3, [r1, #0x24]
	str     r2, [r13, #0x8]
	ldr     r2, [r1, #0x2c]
	add     r1, r13, #0x4
	str     r2, [r13, #0x0c]
	mov     r2, #0x3
	str     r3, [r13, #0x4]
	bl      Vec3_Lsl
	ldr     r1, [r13, #0x10]
	ldr     r0, [r13, #0x14]
	str     r1, [r13, #0x4]
	ldr     r1, [r13, #0x18]
	str     r0, [r13, #0x8]
	str     r1, [r13, #0x0c]
	mov     r0, #0x130
	add     r1, r4, #0x74
	bl      0x02012694
	mov     r0, #0x4
	str     r0, [r13]
	ldr     r1, =#0x507
	ldrb    r2, [r4, #0x509]
	mov     r0, r4
	add     r1, r4, r1
	add     r3, r13, #0x4
	bl      _ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j
	ldr     r1, [r13, #0x4]
	ldr     r2, [r13, #0x8]
	ldr     r3, [r13, #0x0c]
	mov     r0, #0x1a
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r13, #0x4]
	ldr     r0, [r13, #0x8]
	str     r1, [r13, #0x1c]
	ldr     r1, [r13, #0x0c]
	str     r0, [r13, #0x20]
	str     r1, [r13, #0x24]
	mov     r0, r4
	add     r1, r13, #0x1c
	bl      0x0200fd74
	ldrb    r0, [r4, #0x506]
	cmp     r0, #0x1
	bne     LAB_02123a14
	mov     r0, #0x0
	strb    r0, [r4, #0x506]
	bl      _ZN5Sound22StopLoadedMusic_Layer3Ev
	bl      0x02011cfc
	ldr     r1, =#0x15666
	mov     r0, #0x7f
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
LAB_02123a14:
	mov     r0, r4
	bl      _ZN9ActorBase18MarkForDestructionEv
	mov     r0, #0x1
	add     r13, r13, #0x2c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123a3c:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	mov     r1, #0x2
	str     r1, [r4, #0x4fc]
	mov     r1, #0x0
	str     r1, [r4, #0x98]
	add     r1, r4, #0x100
	mov     r2, #0x32
	strh    r2, [r1]
	bl      FUN_02123864
	mov     r0, #0x1000
	mov     r2, #0x0
	str     r0, [r13]
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123aa0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x14
	mov     r5, r0
	add     r0, r5, #0x5c
	add     r1, r5, #0x4e0
	bl      Vec3_HorzAngle
	mov     r4, r0
	mov     r0, r5
	bl      FUN_02123804
	cmp     r0, #0x1
	addeq   r13, r13, #0x14
	moveq   r0, #0x1
	popeq   { r4, r5, r14 }
	bxeq    r14
	mov     r0, r5
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02123b40
	add     r0, r0, #0x5c
	add     r3, r13, #0x4
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r0, =#0x4d4
	mov     r1, r3
	add     r0, r5, r0
	bl      Vec3_Dist
	cmp     r0, #0x640000
	bge     LAB_02123b40
	ldr     r1, [r5, #0x4d8]
	ldr     r0, [r13, #0x8]
	sub     r1, r1, #0x64000
	cmp     r1, r0
	bge     LAB_02123b40
	ldr     r1, =states + 0x040
	mov     r0, r5
	bl      FUN_02125c48
	add     r13, r13, #0x14
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02123b40:
	ldrb    r0, [r5, #0x505]
	cmp     r0, #0x0
	bne     LAB_02123b60
	ldr     r0, =#0x12d
	add     r1, r5, #0x74
	bl      0x02012694
	mov     r0, #0x5
	strb    r0, [r5, #0x505]
LAB_02123b60:
	mov     r0, #0x100
	mov     r1, r4
	str     r0, [r13]
	add     r0, r5, #0x94
	mov     r2, #0x5
	mov     r3, #0x1000
	bl      ApproachAngle
	ldrsh   r2, [r5, #0x94]
	add     r0, r5, #0x5c
	add     r1, r5, #0x4e0
	strh    r2, [r5, #0x8e]
	bl      Vec3_Dist
	cmp     r0, #0x32000
	bge     LAB_02123ba4
	ldr     r1, =states + 0x110
	mov     r0, r5
	bl      FUN_02125c48
LAB_02123ba4:
	mov     r0, #0x1
	add     r13, r13, #0x14
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123bc4:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r1, #0x2000
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x9c]
	mov     r1, #0x2
	str     r1, [r0, #0x4fc]
	mov     r1, #0x0a000
	str     r1, [r0, #0x98]
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r3, #0x0
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x08
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r2, #0x4
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123c20:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_02123804
	cmp     r0, #0x1
	bne     LAB_02123c74
	mov     r0, r4
	bl      FUN_02123864
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_02123c68
	ldrsh   r3, [r4, #0x8e]
	mov     r1, #0x0
	mov     r2, #0x50000
	bl      0x020db54c
	ldr     r1, [r4, #0x494]
	mov     r0, #0x0
	str     r1, [r4, #0x430]
	str     r0, [r4, #0x494]
LAB_02123c68:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02123c74:
	add     r0, r4, #0x31c
	mov     r1, #0x14
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_02123cc0
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_02123cc0
	ldrsh   r3, [r4, #0x8e]
	mov     r1, #0x28000
	mov     r2, #0x50000
	bl      0x020db54c
	ldr     r1, [r4, #0x494]
	ldr     r0, =#0x131
	str     r1, [r4, #0x430]
	mov     r2, #0x0
	add     r1, r4, #0x74
	str     r2, [r4, #0x494]
	bl      0x02012694
LAB_02123cc0:
	add     r0, r4, #0x31c
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02123cdc
	ldr     r1, =states + 0x100
	mov     r0, r4
	bl      FUN_02125c48
LAB_02123cdc:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123cf0:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r2, #0x0
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x10
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123d3c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	bl      FUN_02123804
	cmp     r0, #0x1
	bne     LAB_02123d98
	mov     r0, r4
	bl      FUN_02123864
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_02123d88
	ldrsh   r3, [r4, #0x8e]
	mov     r1, #0x0
	mov     r2, #0x50000
	bl      0x020db54c
	ldr     r1, [r4, #0x494]
	mov     r0, #0x0
	str     r1, [r4, #0x430]
	str     r0, [r4, #0x494]
LAB_02123d88:
	add     r13, r13, #0x10
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02123d98:
	ldr     r1, [r4, #0x4d4]
	ldr     r0, =STAR_ID
	str     r1, [r13, #0x4]
	ldr     r1, [r4, #0x4d8]
	ldrb    r0, [r0]
	str     r1, [r13, #0x8]
	ldr     r1, [r4, #0x4dc]
	cmp     r0, #0x1
	str     r1, [r13, #0x0c]
	beq     LAB_02123df4
	ldr     r0, [r4, #0x5c]
	add     r2, r4, #0x94
	str     r0, [r13, #0x4]
	ldr     r1, [r4, #0x60]
	mov     r0, #0x0
	str     r1, [r13, #0x8]
	ldr     r1, [r4, #0x64]
	str     r1, [r13, #0x0c]
	ldrsh   r1, [r2]
	add     r1, r1, #0x1000
	strh    r1, [r2]
	str     r0, [r4, #0x98]
	b       LAB_02123e1c
LAB_02123df4:
	add     r1, r13, #0x4
	add     r0, r4, #0x5c
	bl      Vec3_HorzAngle
	mov     r1, r0
	mov     r12, #0x100
	add     r0, r4, #0x94
	mov     r2, #0x5
	mov     r3, #0x1000
	str     r12, [r13]
	bl      ApproachAngle
LAB_02123e1c:
	ldrsh   r2, [r4, #0x94]
	add     r1, r13, #0x4
	add     r0, r4, #0x5c
	strh    r2, [r4, #0x8e]
	bl      Vec3_Dist
	cmp     r0, #0x1e000
	ble     LAB_02123e5c
	ldrb    r0, [r4, #0x505]
	cmp     r0, #0x0
	bne     LAB_02123e7c
	ldr     r0, =#0x12d
	add     r1, r4, #0x74
	bl      0x02012694
	mov     r0, #0x0f
	strb    r0, [r4, #0x505]
	b       LAB_02123e7c
LAB_02123e5c:
	ldrb    r0, [r4, #0x505]
	cmp     r0, #0x0
	bne     LAB_02123e7c
	ldr     r0, =#0x12f
	mov     r2, #0x14
	add     r1, r4, #0x74
	strb    r2, [r4, #0x505]
	bl      0x02012694
LAB_02123e7c:
	add     r0, r4, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_02123e98
	ldr     r1, =states + 0x0d0
	mov     r0, r4
	bl      FUN_02125c48
LAB_02123e98:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123eb8:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x2000
	mov     r4, r0
	rsb     r0, r1, #0x0
	mov     r2, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x1000
	str     r0, [r13]
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x48
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	add     r0, r4, #0x100
	mov     r1, #0x32
	strh    r1, [r0]
	mov     r0, #0x0a000
	str     r0, [r4, #0x98]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123f1c:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_02123804
	cmp     r0, #0x1
	beq     LAB_02123f48
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_02123f88
	bl      0x020bf548
	cmp     r0, #0x0
	bne     LAB_02123f88
LAB_02123f48:
	mov     r0, r4
	bl      FUN_02123864
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_02123f7c
	ldrsh   r3, [r4, #0x8e]
	mov     r1, #0x0
	mov     r2, #0x50000
	bl      0x020db54c
	ldr     r1, [r4, #0x494]
	mov     r0, #0x0
	str     r1, [r4, #0x430]
	str     r0, [r4, #0x494]
LAB_02123f7c:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02123f88:
	add     r0, r4, #0x31c
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02123fa4
	ldr     r1, =states + 0x0a0
	mov     r0, r4
	bl      FUN_02125c48
LAB_02123fa4:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02123fb4:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r1, #0x2000
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x9c]
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r2, #0x0
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x38
	str     r2, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124000:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r3, #0x500
	mov     r1, r0
	str     r3, [r13]
	add     r0, r4, #0x94
	mov     r2, #0x1
	bl      ApproachAngle
	ldrsh   r1, [r4, #0x94]
	add     r0, r4, #0x31c
	strh    r1, [r4, #0x8e]
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_0212404c
	ldr     r1, =states + 0x040
	mov     r0, r4
	bl      FUN_02125c48
LAB_0212404c:
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124060:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r2, #0x0
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x20
	str     r2, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021240a0:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x18
	mov     r5, r0
	add     r0, r5, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02124300
	ldr     r0, [r5, #0x500]
	cmp     r0, #0x0
	bgt     LAB_021241fc
	ldr     r0, [r5, #0x98]
	cmp     r0, #0x0
	beq     LAB_021240e8
	mov     r2, #0x0
	mov     r0, r5
	mov     r1, #0x7d0000
	str     r2, [r5, #0x98]
	bl      FUN_02125c24
LAB_021240e8:
	ldr     r0, [r5, #0x430]
	add     r0, r0, #0x600
	ldrh    r0, [r0, #0x0ce]
	and     r0, r0, #0x800
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	addne   r13, r13, #0x18
	movne   r0, #0x1
	popne   { r4-r6, r14 }
	bxne    r14
	mov     r0, r5
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r2, #0x200
	mov     r1, r0
	str     r2, [r13]
	add     r0, r5, #0x94
	mov     r2, #0x5
	mov     r3, #0x1000
	bl      ApproachAngle
	ldrsh   r1, [r5, #0x94]
	mov     r0, r5
	strh    r1, [r5, #0x8e]
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	ldrsh   r1, [r5, #0x8e]
	bl      AngleDiff
	cmp     r0, #0x1000
	bge     LAB_021241ec
	ldr     r4, [r5, #0x430]
	mov     r1, r5
	mov     r0, r4
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_021241ec
	ldr     r0, =STAR_ID
	mov     r1, #0x0
	ldrb    r0, [r0]
	cmp     r0, #0x1
	movne   r6, #0x95
	bne     LAB_021241a0
	ldr     r0, [r4, #0x8]
	add     r0, r0, #0x9a
	mov     r0, r0, lsl #0x10
	add     r0, r1, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r6, r0, asr #0x10
LAB_021241a0:
	ldr     r1, =#0x15666
	mov     r0, #0x14
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
	mov     r12, #0x0
	str     r12, [r13]
	mov     r0, r4
	mov     r1, r5
	mov     r2, r6
	add     r3, r5, #0x5c
	str     r12, [r13, #0x4]
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_021241ec
	ldr     r0, =#0x12a
	add     r1, r5, #0x74
	bl      0x02012694
	ldr     r1, =states + 0x060
	mov     r0, r5
	bl      FUN_02125c48
LAB_021241ec:
	add     r13, r13, #0x18
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
LAB_021241fc:
	ldrb    r0, [r5, #0x499]
	cmp     r0, #0x0
	bne     LAB_02124234
	add     r1, r5, #0x74
	mov     r0, #0x128
	bl      0x02012694
	mov     r0, r5
	mov     r1, #0x7d0000
	bl      FUN_02125c24
	mov     r0, r5
	mov     r1, #0x1
	bl      _ZN5Actor14BigLandingDustEb
	mov     r0, #0x1
	strb    r0, [r5, #0x499]
LAB_02124234:
	add     r0, r5, #0x100
	ldrh    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_02124268
	ldr     r1, =states + 0x030
	mov     r2, #0x0
	mov     r0, r5
	str     r2, [r5, #0x49c]
	bl      FUN_02125c48
	add     r13, r13, #0x18
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
LAB_02124268:
	ldr     r0, =#0x4d4
	add     r1, r5, #0x5c
	add     r0, r5, r0
	bl      Vec3_Dist
	cmp     r0, #0x258000
	bge     LAB_021242cc
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x8
	and     r0, r0, #0x0f
	mov     r0, r0, lsl #0x1c
	mov     r1, #0x4000
	mov     r2, r0, asr #0x10
	rsb     r0, r1, #0x0
	cmp     r2, r0
	movlt   r2, r0
	blt     LAB_021242b4
	cmp     r2, #0x4000
	movgt   r2, r1
LAB_021242b4:
	ldr     r0, =#0x4fa
	add     r1, r5, r0
	ldrsh   r0, [r1]
	add     r0, r0, r2
	strh    r0, [r1]
	b       LAB_021242e4
LAB_021242cc:
	ldr     r1, =#0x4d4
	add     r0, r5, #0x5c
	add     r1, r5, r1
	bl      Vec3_HorzAngle
	add     r1, r5, #0x400
	strh    r0, [r1, #0x0fa]
LAB_021242e4:
	mov     r0, #0x0
	strb    r0, [r5, #0x499]
	mov     r0, #0x1e000
	str     r0, [r5, #0x0a8]
	mov     r0, #0x0a000
	str     r0, [r5, #0x98]
	b       LAB_02124368
LAB_02124300:
	ldr     r0, [r5, #0x0a8]
	cmp     r0, #0x0
	bge     LAB_02124368
	ldr     r0, [r5, #0x360]
	cmp     r0, #0x0
	beq     LAB_02124368
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	beq     LAB_02124368
	ldrh    r0, [r4, #0x0c]
	cmp     r0, #0x0bf
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02124368
	add     r0, r4, #0x5c
	add     r3, r13, #0x8
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r1, [r5, #0x60]
	ldr     r0, [r13, #0x0c]
	cmp     r1, r0
	ble     LAB_02124368
	mov     r0, r4
	mov     r1, #0x1
	bl      _ZN6Player12Unk_020c6a10Ej
LAB_02124368:
	ldrsh   r2, [r5, #0x94]
	mov     r1, #0x200
	add     r0, r5, #0x400
	strh    r2, [r5, #0x8e]
	str     r1, [r13]
	ldrsh   r1, [r0, #0x0fa]
	add     r0, r5, #0x94
	mov     r2, #0x5
	mov     r3, #0x1000
	bl      ApproachAngle
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021243c0:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x1000
	mov     r2, #0x0
	str     r1, [r13]
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	ldr     r1, =#0x4d4
	add     r2, r4, #0x100
	mov     r3, #0x0c8
	add     r0, r4, #0x5c
	add     r1, r4, r1
	strh    r3, [r2]
	bl      Vec3_HorzAngle
	add     r1, r4, #0x400
	strh    r0, [r1, #0x0fa]
	add     r2, r4, #0x500
	ldr     r1, [r2]
	mov     r0, #0x0
	sub     r1, r1, #0x1
	str     r1, [r2]
	strb    r0, [r4, #0x499]
	mov     r0, #0x28000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x5000
	str     r0, [r4, #0x98]
	ldr     r0, [r4, #0x500]
	cmp     r0, #0x0
	movle   r0, #0x10000000
	strle   r0, [r4, #0x0b0]
	mov     r0, #0x2000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124470:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r3, #0x500
	mov     r1, r0
	str     r3, [r13]
	add     r0, r4, #0x94
	mov     r2, #0x1
	bl      ApproachAngle
	ldrsh   r1, [r4, #0x94]
	add     r0, r4, #0x100
	strh    r1, [r4, #0x8e]
	ldrh    r0, [r0]
	cmp     r0, #0x0
	bne     LAB_021244bc
	ldr     r1, =states + 0x030
	mov     r0, r4
	bl      FUN_02125c48
LAB_021244bc:
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021244d0:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x1000
	mov     r2, #0x0
	str     r1, [r13]
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	add     r0, r4, #0x100
	mov     r1, #0x32
	strh    r1, [r0]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124520:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x60
	mov     r6, r0
	ldr     r2, =CAMERA
	add     r0, r6, #0x31c
	mov     r1, #0x46
	ldr     r5, [r2]
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_02124608
	mov     r0, r6
	mov     r1, #0x7d0000
	bl      FUN_02125c24
	add     r1, r6, #0x74
	mov     r0, #0x12c
	bl      0x02012694
	mov     r0, #0x0
	ldr     r12, =MATRIX_SCRATCH_PAPER
	add     r14, r6, #0x2e8
	str     r0, [r13]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	mov     r4, r12
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	ldr     r0, [r6, #0x2e0]
	mov     r1, r4
	add     r0, r0, #0x120
	mov     r2, r4
	bl      MulMat4x3Mat4x3
	mov     r1, r4
	ldr     r2, [r1, #0x28]
	ldr     r3, [r1, #0x24]
	str     r2, [r13, #0x4]
	ldr     r2, [r1, #0x2c]
	add     r0, r13, #0x48
	str     r2, [r13, #0x8]
	add     r1, r13, #0x0
	mov     r2, #0x3
	str     r3, [r13]
	bl      Vec3_Lsl
	ldr     r1, [r13, #0x48]
	ldr     r0, [r13, #0x4c]
	str     r1, [r13]
	str     r1, [r13, #0x54]
	ldr     r1, [r13, #0x50]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x58]
	mov     r0, r6
	str     r1, [r13, #0x8]
	str     r1, [r13, #0x5c]
	add     r1, r13, #0x54
	mov     r2, #0x1
	bl      _ZN5Actor16BigLandingDustAtER7Vector3b
LAB_02124608:
	ldr     r4, [r6, #0x430]
	mov     r0, r4
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	beq     LAB_02124730
	mov     r0, #0x0
	add     r3, r4, #0x5c
	str     r0, [r13, #0x24]
	str     r0, [r13, #0x28]
	str     r0, [r13, #0x2c]
	str     r0, [r13, #0x30]
	str     r0, [r13, #0x34]
	str     r0, [r13, #0x38]
	ldr     r0, [r3]
	add     r1, r13, #0x3c
	str     r0, [r13, #0x3c]
	ldr     r2, [r3, #0x4]
	add     r0, r6, #0x5c
	str     r2, [r13, #0x40]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x44]
	bl      Vec3_HorzAngle
	ldr     r1, [r6, #0x5c]
	mov     r4, r0
	str     r1, [r13, #0x0c]
	ldr     r3, [r6, #0x60]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	str     r3, [r13, #0x10]
	ldr     r2, [r6, #0x64]
	mov     r1, r4
	str     r2, [r13, #0x14]
	ldr     r2, [r6, #0x5c]
	add     r3, r3, #0x100000
	str     r2, [r13, #0x18]
	ldr     r12, [r6, #0x60]
	mov     r2, #0x800000
	str     r12, [r13, #0x1c]
	ldr     r12, [r6, #0x64]
	str     r12, [r13, #0x20]
	str     r3, [r13, #0x10]
	str     r2, [r13, #0x2c]
	bl      Matrix4x3_FromRotationY
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x24
	add     r2, r13, #0x30
	bl      MulVec3Mat4x3
	ldr     r0, [r13, #0x1c]
	ldr     r1, [r13, #0x18]
	add     r0, r0, #0x100000
	str     r0, [r13, #0x1c]
	ldr     r0, [r13, #0x30]
	ldr     r2, [r13, #0x20]
	add     r0, r1, r0
	ldr     r1, [r13, #0x38]
	str     r0, [r13, #0x18]
	add     r1, r2, r1
	str     r1, [r13, #0x20]
	mov     r0, r5
	add     r1, r13, #0x0c
	bl      _ZN6Camera9SetLookAtERK7Vector3
	mov     r0, r5
	add     r1, r13, #0x18
	bl      _ZN6Camera6SetPosERK7Vector3
	mov     r1, r4
	add     r0, r6, #0x8e
	mov     r2, #0x800
	bl      _Z14ApproachLinearRsss
	ldrsh   r1, [r6, #0x8e]
	add     r13, r13, #0x60
	mov     r0, #0x1
	strh    r1, [r6, #0x94]
	pop     { r4-r6, r14 }
	bx      r14
LAB_02124730:
	add     r2, r5, #0x154
	ldr     r1, [r2]
	add     r0, r6, #0x31c
	bic     r1, r1, #0x8
	str     r1, [r2]
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_0212475c
	ldr     r1, =states + 0x040
	mov     r0, r6
	bl      FUN_02125c48
LAB_0212475c:
	mov     r0, #0x1
	add     r13, r13, #0x60
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124778:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r2, #0x0
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x18
	str     r2, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r2, #0x8
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021247bc:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x48
	mov     r4, r0
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x2
	beq     LAB_02124968
	ldr     r1, =#0x4d4
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_HorzAngle
	ldr     r1, =#0x4d4
	mov     r6, r0
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_VertAngle
	ldr     r1, =#0x4d4
	mov     r5, r0
	add     r0, r4, #0x5c
	add     r1, r4, r1
	bl      Vec3_Dist
	mov     r0, #0x0
	str     r0, [r13, #0x8]
	str     r0, [r13, #0x0c]
	str     r0, [r13, #0x10]
	mov     r0, #0x300
	str     r0, [r13]
	mov     r1, r5
	add     r0, r4, #0x92
	mov     r2, #0x5
	mov     r3, #0x1000
	bl      ApproachAngle
	mov     r0, #0x300
	str     r0, [r13]
	mov     r1, r6
	add     r0, r4, #0x94
	mov     r2, #0x5
	mov     r3, #0x1000
	bl      ApproachAngle
	ldrsh   r1, [r4, #0x94]
	add     r0, r4, #0x31c
	strh    r1, [r4, #0x8e]
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x48
	moveq   r0, #0x1
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r2, #0x0
	mov     r0, #0x28000
	mov     r1, #0x3c000
	str     r0, [r13, #0x1c]
	str     r2, [r13, #0x14]
	str     r2, [r13, #0x20]
	str     r2, [r13, #0x24]
	str     r2, [r13, #0x28]
	str     r1, [r13, #0x18]
	ldrsh   r1, [r4, #0x94]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	ldrsh   r1, [r4, #0x92]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x14
	add     r2, r13, #0x20
	bl      MulVec3Mat4x3
	ldr     r0, [r13, #0x20]
	str     r0, [r4, #0x0a4]
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x0
	bne     LAB_02124900
	ldr     r0, [r13, #0x24]
	str     r0, [r4, #0x0a8]
	ldr     r0, [r4, #0x0a8]
	cmp     r0, #0x3c000
	movgt   r0, #0x3c000
	strgt   r0, [r4, #0x0a8]
	bgt     LAB_02124900
	cmp     r0, #0x1e000
	movlt   r0, #0x1e000
	strlt   r0, [r4, #0x0a8]
LAB_02124900:
	ldr     r0, [r13, #0x28]
	ldr     r1, =#0x4d4
	str     r0, [r4, #0x0ac]
	add     r12, r4, #0x0a8
	ldr     r3, [r12]
	ldr     r2, [r4, #0x9c]
	add     r0, r13, #0x8
	add     r2, r3, r2
	str     r2, [r12]
	ldr     r2, [r4, #0x5c]
	add     r1, r4, r1
	str     r2, [r13, #0x8]
	ldr     r2, [r4, #0x60]
	str     r2, [r13, #0x0c]
	ldr     r2, [r4, #0x64]
	str     r2, [r13, #0x10]
	ldr     r2, [r4, #0x4d8]
	str     r2, [r13, #0x0c]
	bl      Vec3_Dist
	cmp     r0, #0x640000
	addgt   r13, r13, #0x48
	movgt   r0, #0x1
	popgt   { r4-r6, r14 }
	bxgt    r14
	mov     r0, #0x1
	strb    r0, [r4, #0x499]
LAB_02124968:
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02124b14
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_021249f0
	add     r0, r0, #0x5c
	add     r3, r13, #0x2c
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r0, =#0x4d4
	mov     r1, r3
	add     r0, r4, r0
	bl      Vec3_Dist
	cmp     r0, #0x640000
	bgt     LAB_021249c4
	ldr     r1, [r4, #0x4d8]
	ldr     r0, [r13, #0x30]
	sub     r1, r1, #0x64000
	cmp     r1, r0
	ble     LAB_021249f0
LAB_021249c4:
	mov     r2, #0x0
	str     r2, [r4, #0x0a4]
	str     r2, [r4, #0x0a8]
	ldr     r1, =states + 0x100
	mov     r0, r4
	str     r2, [r4, #0x0ac]
	bl      FUN_02125c48
	add     r13, r13, #0x48
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
LAB_021249f0:
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x1
	bne     LAB_02124a80
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r2, #0x0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x28
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r0, #0x2000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r2, #0x10000002
	add     r1, r4, #0x74
	mov     r0, #0x12c
	str     r2, [r4, #0x0b0]
	bl      0x02012694
	mov     r0, r4
	mov     r1, #0x0fa0000
	bl      FUN_02125c24
	mov     r0, r4
	mov     r1, #0x1
	bl      0x0200fa8c
	mov     r0, #0x2
	strb    r0, [r4, #0x499]
	mov     r0, #0x0
	str     r0, [r4, #0x0a4]
	str     r0, [r4, #0x0a8]
	str     r0, [r4, #0x0ac]
	add     r13, r13, #0x48
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
LAB_02124a80:
	add     r0, r4, #0x31c
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02124b14
	ldr     r0, [r4, #0x430]
	ldr     r2, [r4, #0x5c]
	add     r1, r0, #0x600
	str     r2, [r13, #0x38]
	ldr     r2, [r4, #0x60]
	str     r2, [r13, #0x3c]
	ldr     r3, [r4, #0x64]
	add     r2, r2, #0x0c8000
	str     r3, [r13, #0x40]
	str     r2, [r13, #0x3c]
	ldrh    r1, [r1, #0x0ce]
	and     r1, r1, #0x800
	mov     r1, r1, lsl #0x10
	movs    r1, r1, lsr #0x10
	bne     LAB_02124b14
	mov     r12, #0x0
	str     r12, [r13]
	add     r3, r13, #0x38
	mov     r1, r4
	mov     r2, #0x94
	str     r12, [r13, #0x4]
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_02124b14
	ldr     r0, =CAMERA
	ldr     r0, [r0]
	bl      _ZN6Camera9SetFlag_3Ev
	ldr     r0, =#0x12a
	add     r1, r4, #0x74
	bl      0x02012694
	ldr     r1, =states + 0x0e0
	mov     r0, r4
	bl      FUN_02125c48
LAB_02124b14:
	mov     r0, #0x1
	add     r13, r13, #0x48
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124b40:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r2, #0x0
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x30
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	ldr     r0, =#0x129
	add     r1, r4, #0x74
	bl      0x02012694
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsn15ClearGroundFlagEv
	mov     r1, #0x0
	strh    r1, [r4, #0x92]
	str     r1, [r4, #0x98]
	str     r1, [r4, #0x0a4]
	str     r1, [r4, #0x0a8]
	str     r1, [r4, #0x0ac]
	mov     r0, #0x6000
	strb    r1, [r4, #0x499]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124bc4:
	push    { r4, r14 }
	mov     r4, r0
	add     r1, r4, #0x100
	ldrh    r1, [r1]
	cmp     r1, #0x0
	movne   r0, #0x1
	popne   { r4, r14 }
	bxne    r14
	ldr     r1, =#0x2092138
	ldr     r2, [r4, #0x60]
	ldr     r1, [r1]
	cmp     r1, r2
	ble     LAB_02124c0c
	ldr     r1, =states + 0x0c0
	bl      FUN_02125c48
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02124c0c:
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02124c80
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x0
	bne     LAB_02124c74
	mov     r0, r4
	mov     r1, #0x7d0000
	bl      FUN_02125c24
	mov     r0, r4
	mov     r1, #0x1
	bl      0x0200fa8c
	add     r1, r4, #0x74
	mov     r0, #0x128
	bl      0x02012694
	add     r0, r4, #0x100
	mov     r1, #0x5
	strh    r1, [r0]
	mov     r0, #0x14000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x0a000
	str     r0, [r4, #0x98]
	mov     r0, #0x1
	strb    r0, [r4, #0x499]
	b       LAB_02124c80
LAB_02124c74:
	ldr     r1, =states + 0x0c0
	mov     r0, r4
	bl      FUN_02125c48
LAB_02124c80:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124c94:
	push    { r4, r14 }
	mov     r1, #0x2000
	mov     r4, r0
	rsb     r1, r1, #0x0
	str     r1, [r4, #0x9c]
	mov     r1, #0x1e000
	str     r1, [r4, #0x0a8]
	mov     r1, #0x14000
	str     r1, [r4, #0x98]
	mov     r1, #0x0
	strb    r1, [r4, #0x499]
	add     r1, r4, #0x100
	mov     r2, #0x5
	strh    r2, [r1]
	mov     r2, #0x10000000
	mov     r1, #0x0fa0000
	str     r2, [r4, #0x0b0]
	bl      FUN_02125c24
	mov     r0, r4
	mov     r1, #0x1
	bl      0x0200fa8c
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124cf4:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x8
	mov     r6, r0
	add     r0, r6, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02124e70
	mov     r0, #0x0
	str     r0, [r6, #0x98]
	ldr     r1, [r6, #0x4d8]
	ldr     r0, [r6, #0x60]
	sub     r1, r1, #0x28000
	cmp     r1, r0
	ble     LAB_02124d48
	add     r1, r6, #0x74
	mov     r0, #0x128
	bl      0x02012694
	ldr     r1, =states + 0x0b0
	mov     r0, r6
	bl      FUN_02125c48
	b       LAB_02124e70
LAB_02124d48:
	ldrb    r0, [r6, #0x499]
	cmp     r0, #0x0
	bne     LAB_02124d9c
	add     r1, r6, #0x74
	mov     r0, #0x128
	bl      0x02012694
	ldr     r0, =#0x12b
	add     r1, r6, #0x74
	bl      0x02012694
	mov     r0, r6
	mov     r1, #0x7d0000
	bl      FUN_02125c24
	mov     r0, r6
	mov     r1, #0x1
	bl      0x0200fa8c
	mov     r0, #0x1
	strb    r0, [r6, #0x499]
	add     r1, r6, #0x500
	ldr     r0, [r1]
	sub     r0, r0, #0x1
	str     r0, [r1]
LAB_02124d9c:
	ldr     r0, [r6, #0x500]
	cmp     r0, #0x0
	ble     LAB_02124db8
	ldr     r1, =states + 0x0f0
	mov     r0, r6
	bl      FUN_02125c48
	b       LAB_02124e70
LAB_02124db8:
	ldr     r5, [r6, #0x430]
	cmp     r5, #0x0
	beq     LAB_02124e70
	add     r0, r5, #0x600
	ldrh    r0, [r0, #0x0ce]
	and     r0, r0, #0x800
	mov     r0, r0, lsl #0x10
	movs    r0, r0, lsr #0x10
	bne     LAB_02124e70
	mov     r0, r5
	mov     r1, r6
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_02124e70
	ldr     r1, =#0x15666
	mov     r0, #0x14
	mov     r4, #0x0
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
	ldr     r0, =STAR_ID
	ldrb    r0, [r0]
	cmp     r0, #0x1
	movne   r4, #0x95
	bne     LAB_02124e30
	ldr     r0, [r5, #0x8]
	add     r0, r0, #0x9a
	mov     r0, r0, lsl #0x10
	add     r0, r4, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r4, r0, asr #0x10
LAB_02124e30:
	mov     r12, #0x0
	str     r12, [r13]
	mov     r0, r5
	mov     r1, r6
	mov     r2, r4
	add     r3, r6, #0x5c
	str     r12, [r13, #0x4]
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_02124e70
	ldr     r0, =#0x12a
	add     r1, r6, #0x74
	bl      0x02012694
	ldr     r1, =states + 0x060
	mov     r0, r6
	bl      FUN_02125c48
LAB_02124e70:
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124e9c:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x1000
	mov     r2, #0x0
	str     r1, [r13]
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	ldr     r0, [r4, #0x500]
	cmp     r0, #0x0
	movle   r0, #0x10000000
	strle   r0, [r4, #0x0b0]
	add     r0, r4, #0x110
	bl      _ZN12WithMeshClsn15ClearGroundFlagEv
	mov     r2, #0x0
	mov     r0, #0x2000
	strb    r2, [r4, #0x499]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x28000
	str     r0, [r4, #0x0a8]
	mov     r0, #0x14000
	mov     r1, #0x3c000
	str     r0, [r4, #0x98]
	rsb     r0, r1, #0x0
	str     r0, [r4, #0x0a0]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02124f28:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x0
	bne     LAB_02124f84
	ldr     r0, [r4, #0x0b0]
	ands    r0, r0, #0x4000
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02124f84
	mov     r0, #0x1000
	mov     r2, #0x0
	str     r0, [r13]
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x00
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      0x020163e0
	mov     r0, #0x1
	strb    r0, [r4, #0x499]
LAB_02124f84:
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	bne     LAB_02124fac
	ldr     r1, =states + 0x090
	mov     r0, r4
	bl      FUN_02125c48
	add     r13, r13, #0x18
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02124fac:
	add     r0, r0, #0x5c
	add     r3, r13, #0x8
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r0, =#0x4d4
	mov     r1, r3
	add     r0, r4, r0
	bl      Vec3_Dist
	cmp     r0, #0x640000
	bgt     LAB_02124fe8
	ldr     r1, [r4, #0x4d8]
	ldr     r0, [r13, #0x0c]
	sub     r1, r1, #0x0a000
	cmp     r1, r0
	ble     LAB_02125014
LAB_02124fe8:
	ldr     r0, [r4, #0x494]
	bl      0x020da7f4
	mov     r2, #0x0
	ldr     r1, =states + 0x090
	mov     r0, r4
	str     r2, [r4, #0x494]
	bl      FUN_02125c48
	add     r13, r13, #0x18
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02125014:
	ldr     r1, [r4, #0x0b0]
	ands    r0, r1, #0x400
	movne   r2, #0x1
	moveq   r2, #0x0
	cmp     r2, #0x0
	bne     LAB_02125054
	ands    r0, r1, #0x2000
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	bne     LAB_02125054
	ands    r0, r1, #0x100
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	bne     LAB_021250b4
LAB_02125054:
	cmp     r2, #0x0
	ldrne   r0, [r4, #0x494]
	add     r3, r4, #0x354
	ldrnesh r0, [r0, #0x8e]
	ldr     r1, =states + 0x090
	strneh  r0, [r4, #0x94]
	ldrsh   r0, [r4, #0x94]
	strh    r0, [r4, #0x8e]
	ldr     r2, [r3]
	mov     r0, r4
	bic     r2, r2, #0x2
	str     r2, [r3]
	bl      FUN_02125c48
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	beq     LAB_021250ac
	ldr     r0, [r0, #0x8]
	cmp     r0, #0x2
	moveq   r0, #0x32000
	streq   r0, [r4, #0x0a8]
	moveq   r0, #0x1e000
	streq   r0, [r4, #0x98]
LAB_021250ac:
	mov     r0, #0x0
	str     r0, [r4, #0x494]
LAB_021250b4:
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021250d0:
	add     r3, r0, #0x354
	ldr     r2, [r3]
	mov     r1, #0x0
	orr     r2, r2, #0x2
	str     r2, [r3]
	str     r1, [r0, #0x9c]
	str     r1, [r0, #0x98]
	strb    r1, [r0, #0x499]
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021250f8:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x34
	mov     r5, r0
	bl      FUN_02123804
	cmp     r0, #0x1
	bne     LAB_02125128
	mov     r0, r5
	bl      FUN_02123864
	add     r13, r13, #0x34
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02125128:
	ldr     r1, [r5, #0x49c]
	add     r0, r5, r1
	ldrb    r0, [r0, #0x42c]
	cmp     r0, #0x0
	bne     LAB_021252e0
	add     r0, r5, r1, lsl #0x2
	ldr     r0, [r0, #0x424]
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	beq     LAB_021252fc
	ldr     r2, [r5, #0x4ec]
	mov     r1, #0x78
	str     r2, [r4, #0x5c]
	ldr     r2, [r5, #0x4f0]
	str     r2, [r4, #0x60]
	ldr     r2, [r5, #0x4f4]
	str     r2, [r4, #0x64]
	ldrsh   r2, [r5, #0x92]
	strh    r2, [r4, #0x92]
	ldrsh   r2, [r5, #0x94]
	strh    r2, [r4, #0x94]
	ldrsh   r2, [r5, #0x96]
	strh    r2, [r4, #0x96]
	ldrsh   r2, [r5, #0x8c]
	strh    r2, [r4, #0x8c]
	ldrsh   r2, [r5, #0x8e]
	strh    r2, [r4, #0x8e]
	ldrsh   r2, [r5, #0x90]
	strh    r2, [r4, #0x90]
	bl      0x0214b384
	add     r0, r5, #0x31c
	mov     r1, #0x13
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	bne     LAB_021251c4
	mov     r0, r5
	bl      FUN_02123804
	cmp     r0, #0x1
	bne     LAB_021252fc
LAB_021251c4:
	mov     r2, #0x0
	mov     r1, #0x28000
	mov     r0, r5
	str     r2, [r13]
	str     r2, [r13, #0x4]
	str     r1, [r13, #0x8]
	str     r2, [r13, #0x0c]
	str     r2, [r13, #0x10]
	str     r2, [r13, #0x14]
	str     r2, [r13, #0x18]
	str     r2, [r13, #0x1c]
	str     r2, [r13, #0x20]
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_021252c4
	ldr     r1, [r0, #0x5c]!
	str     r1, [r13, #0x24]
	ldr     r3, [r0, #0x4]
	str     r3, [r13, #0x28]
	ldr     r2, [r0, #0x8]
	str     r2, [r13, #0x2c]
	ldr     r0, [r5, #0x4ec]
	sub     r0, r1, r0
	str     r0, [r13, #0x18]
	ldr     r1, [r5, #0x4f0]
	sub     r1, r3, r1
	str     r1, [r13, #0x1c]
	ldr     r1, [r5, #0x4f4]
	sub     r1, r2, r1
	str     r1, [r13, #0x20]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	mov     r1, r0
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromRotationY
	add     r0, r13, #0x18
	bl      Vec3_HorzLen
	mov     r1, r0
	ldr     r0, [r13, #0x1c]
	bl      _ZN4cstd5atan2E5Fix12IiES1_
	rsb     r0, r0, #0x0
	mov     r0, r0, lsl #0x10
	mov     r1, r0, asr #0x10
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldr     r1, [r13, #0x10]
	mov     r0, r4
	add     r1, r1, #0x14000
	str     r1, [r13, #0x10]
	bl      0x0214ad14
	ldr     r0, [r13, #0x0c]
	mov     r2, #0x14000
	str     r0, [r4, #0x0a4]
	ldr     r1, [r13, #0x10]
	mov     r0, #0x2000
	str     r1, [r4, #0x0a8]
	ldr     r3, [r13, #0x14]
	rsb     r1, r0, #0x0
	str     r3, [r4, #0x0ac]
	str     r2, [r4, #0x98]
	str     r1, [r4, #0x9c]
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x0
	add     r2, r13, #0x0c
	bl      MulVec3Mat4x3
LAB_021252c4:
	ldr     r0, [r5, #0x49c]
	mov     r1, #0x1
	add     r0, r5, r0
	strb    r1, [r0, #0x42c]
	mov     r0, #0x0
	str     r0, [r4, #0x0c8]
	b       LAB_021252fc
LAB_021252e0:
	mov     r0, r5
	bl      FUN_02123804
	cmp     r0, #0x1
	addeq   r13, r13, #0x34
	moveq   r0, #0x1
	popeq   { r4, r5, r14 }
	bxeq    r14
LAB_021252fc:
	add     r0, r5, #0x31c
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02125338
	mov     r0, r5
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_0212532c
	ldr     r0, [r0, #0x8]
	cmp     r0, #0x3
	movne   r0, #0x64
	strneb  r0, [r5, #0x504]
LAB_0212532c:
	ldr     r1, =states + 0x040
	mov     r0, r5
	bl      FUN_02125c48
LAB_02125338:
	mov     r0, #0x1
	add     r13, r13, #0x34
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125350:
	push    { r4-r10, r14 }
	sub     r13, r13, #0x8
	mov     r10, r0
	mov     r1, #0x1
	mov     r0, #0x2000
	str     r1, [r10, #0x4fc]
	rsb     r0, r0, #0x0
	str     r0, [r10, #0x9c]
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r2, #0x0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x10
	str     r2, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r10, #0x2cc
	mov     r3, #0x40000000
	bl      0x020163e0
	mov     r9, #0x0
	str     r9, [r10, #0x98]
	ldr     r0, [r10, #0x4a0]
	cmp     r0, #0x0
	ble     LAB_02125428
	ldr     r0, =#0x4ec
	mov     r4, r9
	add     r5, r10, r0
	mvn     r8, #0x0
	mov     r7, #0x0ce
	mov     r6, #0x2
LAB_021253c0:
	add     r0, r10, r9, lsl #0x2
	ldr     r0, [r0, #0x424]
	cmp     r0, #0x0
	bne     LAB_02125418
	ldrsb   r2, [r10, #0x0cc]
	mov     r0, r7
	mov     r1, r6
	str     r2, [r13]
	mov     r2, r5
	mov     r3, r4
	str     r8, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	cmp     r0, #0x0
	beq     LAB_02125418
	ldr     r1, [r0, #0x4]
	add     r0, r10, r9, lsl #0x2
	str     r1, [r0, #0x424]
	add     r13, r13, #0x8
	str     r9, [r10, #0x49c]
	mov     r0, #0x1
	pop     { r4-r10, r14 }
	bx      r14
LAB_02125418:
	ldr     r0, [r10, #0x4a0]
	add     r9, r9, #0x1
	cmp     r9, r0
	blt     LAB_021253c0
LAB_02125428:
	mov     r0, #0x0
	strb    r0, [r10, #0x499]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4-r10, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125448:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x10
	mov     r7, r0
	ldrb    r0, [r7, #0x505]
	cmp     r0, #0x0
	bne     LAB_02125474
	ldr     r0, =#0x12d
	add     r1, r7, #0x74
	bl      0x02012694
	mov     r0, #0x0f
	strb    r0, [r7, #0x505]
LAB_02125474:
	mov     r0, r7
	bl      FUN_02123804
	cmp     r0, #0x1
	bne     LAB_0212549c
	mov     r0, r7
	bl      FUN_02123864
	add     r13, r13, #0x10
	mov     r0, #0x1
	pop     { r4-r8, r14 }
	bx      r14
LAB_0212549c:
	mov     r0, r7
	bl      _ZN5Actor13ClosestPlayerEv
	cmp     r0, #0x0
	beq     LAB_02125708
	add     r0, r0, #0x5c
	add     r3, r13, #0x4
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldr     r0, =#0x4d4
	mov     r1, r3
	add     r0, r7, r0
	bl      Vec3_Dist
	cmp     r0, #0x640000
	bgt     LAB_021254e8
	ldr     r1, [r7, #0x4d8]
	ldr     r0, [r13, #0x8]
	sub     r1, r1, #0x0a000
	cmp     r1, r0
	ble     LAB_0212550c
LAB_021254e8:
	ldr     r1, =states + 0x100
	mov     r2, #0x0
	mov     r0, r7
	str     r2, [r7, #0x98]
	bl      FUN_02125c48
	add     r13, r13, #0x10
	mov     r0, #0x1
	pop     { r4-r8, r14 }
	bx      r14
LAB_0212550c:
	mov     r0, r7
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r2, #0x100
	mov     r1, r0
	str     r2, [r13]
	add     r0, r7, #0x94
	mov     r2, #0x0a
	mov     r3, #0x200
	bl      ApproachAngle
	ldrsh   r0, [r7, #0x94]
	add     r1, r7, #0x0b0
	strh    r0, [r7, #0x8e]
	ldr     r0, [r1]
	bic     r0, r0, #0x80
	str     r0, [r1]
	ldr     r0, [r7, #0x3a0]
	cmp     r0, #0x0
	beq     LAB_02125618
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	beq     LAB_02125608
	ldrh    r0, [r4, #0x0c]
	cmp     r0, #0x0bf
	moveq   r0, #0x1
	movne   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02125608
	mov     r0, r7
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	ldrsh   r1, [r7, #0x8e]
	bl      AngleDiff
	cmp     r0, #0x2800
	ble     LAB_021255dc
	ldr     r0, [r7, #0x39c]
	ands    r0, r0, #0x1000
	beq     LAB_02125608
	add     r3, r7, #0x0b0
	ldr     r1, [r3]
	mov     r0, r4
	orr     r2, r1, #0x80
	mov     r1, r7
	str     r2, [r3]
	bl      0x020daba0
	cmp     r0, #0x0
	beq     LAB_02125608
	ldr     r1, =states + 0x080
	mov     r0, r7
	str     r4, [r7, #0x494]
	mov     r2, #0x0
	str     r2, [r7, #0x98]
	bl      FUN_02125c48
	b       LAB_02125608
LAB_021255dc:
	mov     r0, r4
	mov     r1, r7
	bl      0x020db5f4
	cmp     r0, #0x0
	beq     LAB_02125608
	ldr     r1, =states + 0x070
	mov     r0, r7
	str     r4, [r7, #0x494]
	mov     r2, #0x0
	str     r2, [r7, #0x98]
	bl      FUN_02125c48
LAB_02125608:
	add     r13, r13, #0x10
	mov     r0, #0x1
	pop     { r4-r8, r14 }
	bx      r14
LAB_02125618:
	ldrb    r0, [r7, #0x504]
	cmp     r0, #0x0
	bne     LAB_02125708
	ldr     r0, =STAR_ID
	ldrb    r0, [r0]
	cmp     r0, #0x1
	bne     LAB_02125708
	mov     r0, r7
	bl      _ZN5Actor13DistToCPlayerEv
	cmp     r0, #0x3e8000
	bge     LAB_02125708
	mov     r0, r7
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	ldrsh   r1, [r7, #0x8e]
	bl      AngleDiff
	cmp     r0, #0x2800
	bge     LAB_02125708
	mov     r6, #0x0
	mov     r5, r6
	mov     r4, r6
	add     r8, r7, #0x4a0
LAB_0212566c:
	add     r0, r7, r6, lsl #0x2
	ldr     r0, [r0, #0x424]
	cmp     r0, #0x0
	beq     LAB_02125694
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r0, r7, r6, lsl #0x2
	streq   r4, [r0, #0x424]
	addeq   r0, r7, r6
	streqb  r4, [r0, #0x42c]
LAB_02125694:
	add     r0, r7, r6, lsl #0x2
	ldr     r0, [r0, #0x424]
	cmp     r0, #0x0
	bne     LAB_021256b8
	add     r5, r5, #0x1
	cmp     r5, #0x2
	ldreq   r0, [r8]
	eoreq   r0, r0, #0x3
	streq   r0, [r8]
LAB_021256b8:
	add     r6, r6, #0x1
	cmp     r6, #0x2
	blt     LAB_0212566c
	ldr     r1, [r7, #0x4a0]
	cmp     r1, #0x2
	bne     LAB_021256dc
	ldr     r0, [r7, #0x428]
	cmp     r0, #0x0
	beq     LAB_021256ec
LAB_021256dc:
	cmp     r1, #0x1
	bne     LAB_02125708
	cmp     r5, #0x2
	bne     LAB_02125708
LAB_021256ec:
	ldr     r1, =states + 0x050
	mov     r0, r7
	bl      FUN_02125c48
	add     r13, r13, #0x10
	mov     r0, #0x1
	pop     { r4-r8, r14 }
	bx      r14
LAB_02125708:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125734:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r2, #0x1
	mov     r1, #0x2000
	str     r2, [r0, #0x4fc]
	mov     r2, #0x5000
	str     r2, [r0, #0x98]
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x9c]
	mov     r1, #0x1000
	str     r1, [r13]
	mov     r3, #0x0
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x08
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r2, #0x8
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125790:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x2c
	mov     r4, r0
	bl      FUN_02123804
	cmp     r0, #0x1
	addeq   r13, r13, #0x2c
	moveq   r0, #0x1
	popeq   { r4, r5, r14 }
	bxeq    r14
	mov     r0, r4
	bl      _ZN5Actor18HorzAngleToCPlayerEv
	mov     r3, #0x500
	mov     r1, r0
	str     r3, [r13]
	add     r0, r4, #0x94
	mov     r2, #0x1
	bl      ApproachAngle
	ldrsh   r2, [r4, #0x94]
	add     r0, r4, #0x31c
	mov     r1, #0x46
	strh    r2, [r4, #0x8e]
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_021258b0
	mov     r0, r4
	mov     r1, #0x7d0000
	bl      FUN_02125c24
	add     r1, r4, #0x74
	mov     r0, #0x12c
	bl      0x02012694
	mov     r0, #0x0
	ldr     r14, =MATRIX_SCRATCH_PAPER
	add     r5, r4, #0x2e8
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	str     r0, [r13, #0x0c]
	mov     r12, r14
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r5, { r0-r3 }
	stmia   r14, { r0-r3 }
	ldr     r0, [r4, #0x2e0]
	mov     r1, r12
	add     r0, r0, #0x120
	mov     r2, r12
	bl      MulMat4x3Mat4x3
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r13, #0x10
	ldr     r2, [r1, #0x28]
	ldr     r3, [r1, #0x24]
	str     r2, [r13, #0x8]
	ldr     r2, [r1, #0x2c]
	add     r1, r13, #0x4
	str     r2, [r13, #0x0c]
	mov     r2, #0x3
	str     r3, [r13, #0x4]
	bl      Vec3_Lsl
	ldr     r1, [r13, #0x10]
	ldr     r0, [r13, #0x14]
	str     r1, [r13, #0x4]
	str     r1, [r13, #0x1c]
	ldr     r1, [r13, #0x18]
	str     r0, [r13, #0x8]
	str     r0, [r13, #0x20]
	mov     r0, r4
	str     r1, [r13, #0x0c]
	str     r1, [r13, #0x24]
	add     r1, r13, #0x1c
	mov     r2, #0x1
	bl      _ZN5Actor16BigLandingDustAtER7Vector3b
LAB_021258b0:
	add     r0, r4, #0x31c
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_021258cc
	ldr     r1, =states + 0x040
	mov     r0, r4
	bl      FUN_02125c48
LAB_021258cc:
	mov     r0, #0x1
	add     r13, r13, #0x2c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021258e4:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r1, #0x2000
	mov     r4, r0
	rsb     r0, r1, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x1000
	str     r0, [r13]
	mov     r1, #0x0
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x18
	str     r1, [r13, #0x4]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x2cc
	mov     r2, #0x8
	mov     r3, #0x40000000
	bl      0x020163e0
	ldrb    r0, [r4, #0x506]
	cmp     r0, #0x0
	moveq   r0, #0x1
	streqb  r0, [r4, #0x506]
	moveq   r0, #0x10000002
	streq   r0, [r4, #0x0b0]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125950:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	ldr     r5, [r4, #0x430]
	add     r1, r13, #0x0
	add     r3, r5, #0x5c
	ldr     r2, [r3]
	add     r0, r4, #0x5c
	str     r2, [r13]
	ldr     r2, [r3, #0x4]
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzAngle
	mov     r1, r0
	add     r0, r4, #0x8e
	mov     r2, #0x800
	bl      _Z14ApproachLinearRsss
	ldrsh   r1, [r4, #0x8e]
	mov     r0, r5
	strh    r1, [r4, #0x94]
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	bne     LAB_021259d0
	bl      _ZN7Message7EndTalkEv
	bl      0x02011d44
	mov     r0, #0x2d
	bl      _ZN5Sound22LoadAndSetMusic_Layer3Ej
	ldr     r1, =states + 0x020
	mov     r0, r4
	bl      FUN_02125c48
LAB_021259d0:
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021259e4:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_021259ec:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x24
	mov     r5, r0
	ldrb    r0, [r5, #0x506]
	cmp     r0, #0x1
	bne     LAB_02125a50
	ldr     r0, =#0x50a
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r5, #0x50a]
	cmp     r0, #0x0c8
	bls     LAB_02125a50
	mov     r0, #0x10000003
	str     r0, [r5, #0x0b0]
	mov     r0, #0x0
	strb    r0, [r5, #0x506]
	strb    r0, [r5, #0x50a]
	mov     r0, #0x3
	str     r0, [r5, #0x500]
	bl      _ZN5Sound22StopLoadedMusic_Layer3Ev
	bl      0x02011cfc
	mov     r0, #0x0
	strb    r0, [r5, #0x508]
LAB_02125a50:
	add     r0, r5, #0x400
	ldrsh   r1, [r0, #0x0f8]
	add     r0, r5, #0x8e
	mov     r2, #0x800
	bl      _Z14ApproachLinearRsss
	ldrsh   r1, [r5, #0x8e]
	mov     r0, r5
	strh    r1, [r5, #0x94]
	bl      FUN_02123804
	cmp     r0, #0x1
	addeq   r13, r13, #0x24
	moveq   r0, #0x1
	popeq   { r4, r5, r14 }
	bxeq    r14
	mov     r0, r5
	bl      _ZN5Actor13ClosestPlayerEv
	movs    r4, r0
	beq     LAB_02125ba4
	add     r0, r4, #0x5c
	add     r3, r13, #0x8
	ldmia   r0, { r0-r2 }
	stmia   r3, { r0-r2 }
	ldrb    r0, [r5, #0x508]
	cmp     r0, #0x0
	bne     LAB_02125b70
	mov     r1, r3
	add     r0, r5, #0x5c
	bl      Vec3_Dist
	cmp     r0, #0x12c000
	bge     LAB_02125ba4
	str     r4, [r5, #0x430]
	ldr     r0, [r5, #0x5c]
	mov     r1, r5
	str     r0, [r13, #0x14]
	ldr     r0, [r5, #0x60]
	mov     r2, #0x1
	str     r0, [r13, #0x18]
	ldr     r3, [r5, #0x64]
	add     r0, r0, #0x0c8000
	str     r3, [r13, #0x1c]
	str     r0, [r13, #0x18]
	ldr     r0, [r5, #0x430]
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_02125ba4
	bl      _ZN7Message11PrepareTalkEv
	ldr     r0, =STAR_ID
	mov     r12, #0x0
	ldrb    r0, [r0]
	add     r3, r13, #0x14
	mov     r1, r5
	cmp     r0, #0x1
	ldreq   r0, [r4, #0x8]
	movne   r2, #0x93
	addeq   r0, r0, #0x96
	moveq   r0, r0, lsl #0x10
	moveq   r2, r0, asr #0x10
	str     r12, [r13]
	mov     r0, r4
	str     r12, [r13, #0x4]
	bl      _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_02125ba4
	ldr     r0, =#0x12a
	add     r1, r5, #0x74
	bl      0x02012694
	mov     r2, #0x1
	ldr     r1, =states + 0x010
	mov     r0, r5
	strb    r2, [r5, #0x508]
	bl      FUN_02125c48
	b       LAB_02125ba4
LAB_02125b70:
	mov     r1, r3
	add     r0, r5, #0x5c
	bl      Vec3_Dist
	cmp     r0, #0x258000
	bge     LAB_02125ba4
	ldr     r1, [r5, #0x4d8]
	ldr     r0, [r13, #0x0c]
	sub     r1, r1, #0x0a000
	cmp     r1, r0
	bge     LAB_02125ba4
	ldr     r1, =states + 0x020
	mov     r0, r5
	bl      FUN_02125c48
LAB_02125ba4:
	mov     r0, #0x1
	add     r13, r13, #0x24
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125bc8:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r3, #0x0
	mov     r1, #0x2000
	str     r3, [r0, #0x98]
	mov     r2, #0x1
	str     r2, [r0, #0x4fc]
	rsb     r1, r1, #0x0
	str     r1, [r0, #0x9c]
	strb    r3, [r0, #0x50a]
	mov     r1, #0x1000
	str     r1, [r13]
	ldr     r1, =_ZN10KingBobOmb9animFilesE + 0x50
	str     r3, [r13, #0x4]
	ldr     r1, [r1, #0x4]
	add     r0, r0, #0x2cc
	mov     r2, #0x8
	bl      0x020163e0
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125c24:
	ldr     r2, =CAMERA
	mov     r3, r0
	ldr     r0, [r2]
	mov     r2, r1
	ldr     r12, =#0x200d8c8
	add     r1, r3, #0x5c
	bx      r12
.ltorg)");

asm(R"(
FUN_02125c48:
	push    { r14 }
	sub     r13, r13, #0x4
	str     r1, [r0, #0x420]
	ldr     r3, [r0, #0x420]
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
FUN_02125c98:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x58
	mov     r4, r0
	add     r0, r4, #0x110
	ldr     r5, [r4, #0x60]
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	bne     LAB_02125ce8
	add     r0, r13, #0x8
	bl      _ZN13RaycastGroundC1Ev
	add     r0, r13, #0x8
	add     r1, r4, #0x5c
	mov     r2, #0x0
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x8
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	add     r0, r13, #0x8
	ldrne   r5, [r13, #0x4c]
	bl      _ZN13RaycastGroundD1Ev
LAB_02125ce8:
	ldr     r0, [r4, #0x0b0]
	ands    r0, r0, #0x4000
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02125d0c
	ldr     r0, [r4, #0x494]
	cmp     r0, #0x0
	ldrne   r5, [r0, #0x60]
LAB_02125d0c:
	ldr     r0, [r4, #0x60]
	mov     r1, #0x0
	sub     r12, r0, r5
	cmp     r12, #0x1000
	movle   r12, #0x1000
	mov     r0, #0x180
	umull   r5, r3, r12, r0
	mla     r3, r12, r1, r3
	mov     r2, r12, asr #0x1f
	mla     r3, r2, r0, r3
	mov     r1, #0x800
	adds    r5, r5, r1
	adc     r1, r3, #0x0
	mov     r2, r5, lsr #0x0c
	ldr     r0, =#0x15e000
	orr     r2, r2, r1, lsl #0x14
	sub     r8, r0, r2
	ldr     r0, =#0x434
	ldr     r7, =_ZN9Matrix4x38IDENTITYE
	add     r6, r4, r0
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	ldr     r1, [r4, #0x5c]
	cmp     r8, #0x0a000
	mov     r1, r1, asr #0x3
	str     r1, [r4, #0x458]
	mov     r2, r5
	ldr     r5, [r4, #0x60]
	movlt   r8, #0x0a000
	mov     r5, r5, asr #0x3
	str     r5, [r4, #0x45c]
	ldr     r5, [r4, #0x64]
	add     r14, r12, #0x28000
	mov     r5, r5, asr #0x3
	str     r5, [r4, #0x460]
	mov     r12, #0x0f
	str     r14, [r13]
	mov     r3, r8
	mov     r0, r4
	add     r1, r4, #0x3f8
	str     r12, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r13, r13, #0x58
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125de0:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x14
	mov     r9, r0
	ldrsh   r1, [r9, #0x8e]
	add     r0, r9, #0x2e8
	bl      Matrix4x3_FromRotationY
	ldr     r1, [r9, #0x5c]
	ldr     r0, =#0x4a4
	mov     r1, r1, asr #0x3
	str     r1, [r9, #0x30c]
	ldr     r2, [r9, #0x60]
	add     r1, r9, #0x2e8
	mov     r2, r2, asr #0x3
	str     r2, [r9, #0x310]
	ldr     r3, [r9, #0x64]
	add     r2, r9, r0
	mov     r0, r3, asr #0x3
	str     r0, [r9, #0x314]
	ldr     r0, [r9, #0x2e0]
	add     r0, r0, #0x1e0
	bl      MulMat4x3Mat4x3
	ldr     r0, =#0x4a4
	mov     r1, #0x0
	add     r0, r9, r0
	str     r0, [r9, #0x0c8]
	str     r1, [r9, #0x4ec]
	str     r1, [r9, #0x4f0]
	str     r1, [r9, #0x4f4]
	ldr     r0, [r9, #0x4c8]
	ldr     r1, =#0x4ec
	str     r0, [r9, #0x4ec]
	ldr     r2, [r9, #0x4cc]
	add     r0, r13, #0x8
	str     r2, [r9, #0x4f0]
	ldr     r2, [r9, #0x4d0]
	add     r1, r9, r1
	str     r2, [r9, #0x4f4]
	mov     r2, #0x3
	bl      Vec3_Lsl
	ldr     r0, [r13, #0x8]
	mov     r1, #0x6000
	str     r0, [r9, #0x4ec]
	ldr     r0, [r13, #0x0c]
	mov     r2, #0x1000
	str     r0, [r9, #0x4f0]
	ldr     r0, [r13, #0x10]
	mov     r8, #0x0
	str     r0, [r9, #0x4f4]
	mov     r0, #0x7000
	rsb     r5, r0, #0x0
	rsb     r0, r2, #0x0
	str     r0, [r13]
	mov     r0, #0x2000
	rsb     r4, r1, #0x0
	mov     r6, #0x0b000
	mov     r11, #0x4000
	str     r0, [r13, #0x4]
LAB_02125ec4:
	add     r0, r9, r8
	ldrb    r0, [r0, #0x42c]
	cmp     r0, #0x0
	bne     LAB_02125f68
	add     r0, r9, r8, lsl #0x2
	ldr     r0, [r0, #0x424]
	cmp     r0, #0x0
	beq     LAB_02125f68
	bl      _ZN5Actor10FindWithIDEj
	movs    r7, r0
	beq     LAB_02125f68
	ldr     r0, =#0x4a4
	ldr     r12, =MATRIX_SCRATCH_PAPER
	add     r14, r9, r0
	mov     r10, r12
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	mov     r0, r10
	mov     r1, r6
	mov     r2, r5
	mov     r3, r4
	bl      Matrix4x3_ApplyInPlaceToTranslation
	ldr     r2, [r13]
	ldr     r3, [r13, #0x4]
	mov     r0, r10
	mov     r1, r11
	bl      0x0203c0b4
	ldr     r0, =#0x4a4
	add     r14, r9, r0
	mov     r12, r14
	ldmia   r10!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r10!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r10, { r0-r3 }
	stmia   r14, { r0-r3 }
	str     r12, [r7, #0x0c8]
LAB_02125f68:
	add     r8, r8, #0x1
	cmp     r8, #0x2
	blt     LAB_02125ec4
	add     r13, r13, #0x14
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125f8c:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, [r4, #0x494]
	mov     r3, #0x0
	cmp     r1, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, [r1, #0x8]
	ldr     r2, =CARRY_POSITION_OFFSET
	cmp     r0, #0x2
	moveq   r3, #0x1
	mov     r0, #0x0c
	mla     r2, r3, r0, r2
	mov     r0, r4
	bl      0x02010180
	mov     r14, r0
	add     r12, r4, #0x2e8
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02125ff4:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN10KingBobOmb9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x20
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x30
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x28
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x38
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x00
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x10
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x58
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x50
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x08
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x48
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x18
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021260a8:
	bx      r14
.ltorg)");

asm(R"(
FUN_021260ac:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, [r4, #0x494]
	cmp     r1, #0x0
	beq     LAB_021260ec
	ldr     r0, [r4, #0x0b0]
	ands    r0, r0, #0x4000
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_021260ec
	ldr     r0, [r1, #0x0c8]
	cmp     r0, #0x0
	beq     LAB_021260ec
	mov     r0, r4
	bl      FUN_02125f8c
LAB_021260ec:
	add     r0, r4, #0x2cc
	mov     r1, #0x0
	bl      _ZN5Model6RenderEPK7Vector3
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02126104:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	bl      _ZN5Actor13DistToCPlayerEv
	ldr     r1, =#0x1770000
	cmp     r0, r1
	ldrlt   r0, =CAMERA
	ldrlt   r0, [r0]
	strlt   r4, [r0, #0x114]
	ldr     r1, [r4, #0x420]
	ldr     r0, [r1, #0x8]
	cmp     r0, #0x0
	beq     LAB_0212615c
	add     r3, r1, #0x8
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
LAB_0212615c:
	ldr     r1, [r4, #0x4fc]
	add     r0, r4, #0x2cc
	mov     r1, r1, lsl #0x0c
	str     r1, [r4, #0x328]
	ldr     r1, [r0]
	ldr     r1, [r1, #0x0c]
	blx     r1
	add     r0, r4, #0x2cc
	bl      0x0201647c
	ldr     r1, [r4, #0x420]
	ldr     r0, =states + 0x080
	cmp     r1, r0
	bne     LAB_021261e0
	ldr     r1, [r4, #0x494]
	cmp     r1, #0x0
	beq     LAB_021261c0
	ldr     r0, [r4, #0x0b0]
	ands    r0, r0, #0x4000
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_021261c0
	ldr     r0, [r1, #0x0c8]
	cmp     r0, #0x0
	bne     LAB_021261c8
LAB_021261c0:
	mov     r0, r4
	bl      FUN_02125de0
LAB_021261c8:
	mov     r0, r4
	bl      FUN_02125c98
	add     r13, r13, #0x18
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_021261e0:
	add     r0, r4, #0x100
	bl      DecIfAbove0_Short
	ldr     r0, =#0x505
	add     r0, r4, r0
	bl      DecIfAbove0_Byte
	ldr     r0, =#0x504
	add     r0, r4, r0
	bl      DecIfAbove0_Byte
	ldr     r1, [r4, #0x420]
	ldr     r0, =states + 0x0c0
	cmp     r1, r0
	beq     LAB_02126220
	mov     r0, r4
	add     r1, r4, #0x33c
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	b       LAB_0212622c
LAB_02126220:
	mov     r0, r4
	add     r1, r4, #0x33c
	bl      _ZN5Actor22UpdatePosWithOnlySpeedEP12CylinderClsn
LAB_0212622c:
	ldr     r1, [r4, #0x420]
	ldr     r0, =states + 0x0c0
	cmp     r1, r0
	bne     LAB_02126248
	ldrb    r0, [r4, #0x499]
	cmp     r0, #0x1
	bne     LAB_02126258
LAB_02126248:
	mov     r0, r4
	add     r1, r4, #0x110
	mov     r2, #0x0
	bl      _ZN5Enemy12UpdateWMClsnER12WithMeshClsnj
LAB_02126258:
	ldr     r1, [r4, #0x420]
	ldr     r0, =states + 0x040
	cmp     r1, r0
	beq     LAB_02126274
	ldr     r0, =states + 0x100
	cmp     r1, r0
	bne     LAB_021262b4
LAB_02126274:
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn8IsOnWallEv
	cmp     r0, #0x0
	bne     LAB_021262a8
	add     r0, r4, #0x110
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_021262a8
	ldr     r1, [r4, #0x4d8]
	ldr     r0, [r4, #0x60]
	sub     r1, r1, #0x28000
	cmp     r1, r0
	ble     LAB_021262b4
LAB_021262a8:
	ldr     r1, =states + 0x0c0
	mov     r0, r4
	bl      FUN_02125c48
LAB_021262b4:
	ldr     r0, =UNK_02126e00
	add     r1, r13, #0x0
	ldr     r12, [r0]
	ldr     r3, [r0, #0x4]
	ldr     r2, [r0, #0x8]
	add     r0, r4, #0x33c
	str     r12, [r13]
	str     r3, [r13, #0x4]
	str     r2, [r13, #0x8]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	ldr     r0, =UNK_02126e00
	add     r1, r13, #0x0c
	ldr     r12, [r0]
	ldr     r3, [r0, #0x4]
	ldr     r2, [r0, #0x8]
	add     r0, r4, #0x37c
	str     r12, [r13, #0x0c]
	str     r3, [r13, #0x10]
	str     r2, [r13, #0x14]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	add     r0, r4, #0x33c
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x33c
	bl      _ZN12CylinderClsn6UpdateEv
	add     r0, r4, #0x37c
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r4, #0x37c
	bl      _ZN12CylinderClsn6UpdateEv
	mov     r0, r4
	bl      FUN_02125de0
	mov     r0, r4
	bl      FUN_02125c98
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02126368:
	push    { r4, r14 }
	sub     r13, r13, #0x28
	mov     r4, r0
	ldr     r0, =_ZN10KingBobOmb9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r2, #0x1
	mov     r1, r0
	mov     r3, r2
	add     r0, r4, #0x2cc
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	add     r0, r4, #0x3f8
	bl      _ZN11ShadowModel12InitCylinderEv
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x20
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x40
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x30
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x28
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x38
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x00
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x10
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x58
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x50
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x08
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x48
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN10KingBobOmb9animFilesE + 0x18
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	mov     r0, #0x2000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	mov     r0, #0x3c000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x0a0]
	ldr     r0, =UNK_02126e00
	mov     r1, #0x0c8000
	ldr     r2, [r0, #0x4]
	ldr     r3, [r0]
	str     r2, [r13, #0x10]
	ldr     r2, [r0, #0x8]
	str     r3, [r13, #0x0c]
	str     r2, [r13, #0x14]
	str     r1, [r13]
	ldr     r0, =#0x200004
	ldr     r1, =#0x206000
	str     r0, [r13, #0x4]
	str     r1, [r13, #0x8]
	add     r0, r4, #0x33c
	mov     r1, r4
	add     r2, r13, #0x0c
	mov     r3, #0x78000
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	ldr     r0, =UNK_02126e00
	mov     r3, #0x0c8000
	ldr     r1, [r0, #0x4]
	ldr     r2, [r0]
	str     r1, [r13, #0x1c]
	ldr     r1, [r0, #0x8]
	str     r2, [r13, #0x18]
	str     r1, [r13, #0x20]
	mov     r0, #0x200000
	str     r3, [r13]
	str     r0, [r13, #0x4]
	ldr     r1, =#0x207000
	add     r0, r4, #0x37c
	str     r1, [r13, #0x8]
	mov     r1, r4
	add     r2, r13, #0x18
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	mov     r0, #0x1f
	strb    r0, [r4, #0x498]
	ldr     r0, [r4, #0x5c]
	ldr     r2, =#0x0b1d000
	str     r0, [r4, #0x4e0]
	ldr     r0, [r4, #0x60]
	ldr     r1, =#0x1060000
	str     r0, [r4, #0x4e4]
	ldr     r3, [r4, #0x64]
	ldr     r0, =#0x0fee15000
	str     r3, [r4, #0x4e8]
	str     r2, [r4, #0x4d4]
	str     r1, [r4, #0x4d8]
	str     r0, [r4, #0x4dc]
	mov     r0, #0x0
	str     r0, [r13]
	mov     r2, #0x190000
	str     r0, [r13, #0x4]
	add     r0, r4, #0x110
	mov     r1, r4
	mov     r3, r2
	bl      _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_
	add     r0, r4, #0x110
	bl      0x02035550
	mov     r0, #0x1
	str     r0, [r4, #0x4fc]
	mov     r0, #0x3
	str     r0, [r4, #0x500]
	ldr     r1, [r4, #0x8]
	mov     r0, r4
	and     r1, r1, #0x0f
	strb    r1, [r4, #0x509]
	ldrb    r1, [r4, #0x509]
	mov     r2, #0x2
	bl      _ZN5Actor9TrackStarEjj
	mov     r3, #0x0
	strb    r0, [r4, #0x507]
	mov     r2, r3
LAB_02126534:
	add     r1, r4, r3, lsl #0x2
	add     r0, r4, r3
	str     r2, [r1, #0x424]
	add     r3, r3, #0x1
	strb    r2, [r0, #0x42c]
	cmp     r3, #0x2
	blt     LAB_02126534
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r0, lsr #0x1e
	and     r0, r0, #0x1
	str     r0, [r4, #0x4a0]
	add     r2, r4, #0x4a0
	ldr     r0, [r2]
	ldr     r1, =states + 0x110
	add     r0, r0, #0x1
	str     r0, [r2]
	ldrsh   r3, [r4, #0x8e]
	add     r2, r4, #0x400
	mov     r0, r4
	strh    r3, [r2, #0x0f8]
	bl      FUN_02125c48
	mov     r0, #0x1
	add     r13, r13, #0x28
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021265f4:
	mov     r0, #0x0fa000
	bx      r14
.ltorg)");

asm(R"(
FUN_021265fc:
	push    { r4, r14 }
	ldr     r0, =#0x50c
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_0212664c
	bl      _ZN5EnemyC2Ev
	ldr     r1, =VTable_KingBobOmb
	add     r0, r4, #0x110
	str     r1, [r4]
	bl      _ZN12WithMeshClsnC1Ev
	add     r0, r4, #0x2cc
	bl      _ZN14BlendModelAnimC1Ev
	add     r0, r4, #0x33c
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
	add     r0, r4, #0x37c
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
	add     r0, r4, #0x3bc
	bl      _ZN11CommonModelC1Ev
	add     r0, r4, #0x3f8
	bl      _ZN11ShadowModelC1Ev
LAB_0212664c:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14

@ FUN_02126660 is static init

.ltorg)");