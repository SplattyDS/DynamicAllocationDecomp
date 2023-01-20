#include "SM64DS_2.h"
#include "Actors/BowserFireSeaArena.h"

extern "C"
{
	ActorBase* FUN_02117cdc(); // constructor
	
	// undocumented globals not in ov60:
	// 0x0203929c
	
	OldFixedSizeCLPS_Block<2> clpsBlock =	// 0x021115bc
	{
		{'C', 'L', 'P', 'S'},
		0x0008,
		0x0001,
		{
			OldCLPS{ 0x00000fc0, 0x000000ff },
			OldCLPS{ 0x00038fc4, 0x000000ff },
        }
	};

	// 0x021115bc use this for decomp
	/* using clpsBlock = StaticCLPS_Block<
		{  },
		{ .textureID = CLPS::TX_ROCK, .camBehavID = CLPS::CA_GO_BEHIND_7, }
	>;*/
}

SharedFilePtr BowserFireSeaArena::modelFile;
SharedFilePtr BowserFireSeaArena::clsnFile;

SpawnInfo BowserFireSeaArena::spawnData = 
{
	&FUN_02117cdc,
	0x00a6,
	0x0091,
	0,
	0._f,
	5000._f,
	5000._f,
	5000._f,
};

asm(".global FUN_02117a3c");

asm(R"(
@ 0x0211a8b0
VTable_BowserFireSeaArena:
	.word FUN_02117c30
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02117b58
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02117bc8
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02117b9c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02117980
	.word FUN_021179d4
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
FUN_02117980:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserFireSeaArena
	add     r0, r4, #0x374
	str     r1, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	add     r0, r4, #0x324
	bl      _ZN5ModelD1Ev
	ldr     r1, =_ZTV8Platform
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
FUN_021179d4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserFireSeaArena
	add     r0, r4, #0x374
	str     r1, [r4]
	bl      _ZN18MovingMeshColliderD1Ev
	add     r0, r4, #0x324
	bl      _ZN5ModelD1Ev
	ldr     r1, =_ZTV8Platform
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
FUN_02117a3c:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r0, [r4, #0x56c]
	mov     r1, #0x3
	mov     r2, #0x95
	mov     r3, #0x0
	bl      0x020124c4
	str     r0, [r4, #0x56c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117a64:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	ldr     r1, [r5, #0x5c]
	ldr     r2, [r5, #0x60]
	ldr     r3, [r5, #0x64]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldrsh   r1, [r5, #0x8c]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldrsh   r1, [r5, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationZ
	ldr     r4, =MATRIX_SCRATCH_PAPER
	add     r14, r5, #0x2ec
	mov     r12, r14
	ldmia   r4!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r4!, { r0-r3 }
	stmia   r14!, { r0-r3 }
	ldmia   r4, { r0-r3 }
	stmia   r14, { r0-r3 }
	mov     r1, r12
	add     r0, r5, #0x374
	ldrsh   r2, [r5, #0x8e]
	bl      _ZN18MovingMeshCollider9TransformERK9Matrix4x3s
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117ae0:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	add     r0, r13, #0x0
	add     r1, r4, #0x5c
	mov     r2, #0x3
	bl      Vec3_Asr
	ldr     r1, [r13]
	ldr     r2, [r13, #0x4]
	ldr     r3, [r13, #0x8]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldrsh   r1, [r4, #0x8c]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldrsh   r1, [r4, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationZ
	ldr     r14, =MATRIX_SCRATCH_PAPER
	add     r12, r4, #0x340
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14!, { r0-r3 }
	stmia   r12!, { r0-r3 }
	ldmia   r14, { r0-r3 }
	stmia   r12, { r0-r3 }
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117b58:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x374
	bl      _ZN16MeshColliderBase9IsEnabledEv
	cmp     r0, #0x0
	beq     LAB_02117b78
	add     r0, r4, #0x374
	bl      _ZN16MeshColliderBase7DisableEv
LAB_02117b78:
	ldr     r0, =_ZN18BowserFireSeaArena9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN18BowserFireSeaArena8clsnFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117b9c:
	push    { r14 }
	sub     r13, r13, #0x4
	add     r0, r0, #0x324
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
FUN_02117bc8:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r4, r0
	add     r5, r4, #0x8c
	add     r1, r4, #0x300
	ldrsh   r12, [r5]
	ldrsh   r2, [r1, #0x1e]
	add     r14, r4, #0x8e
	add     r3, r4, #0x90
	add     r2, r12, r2
	strh    r2, [r5]
	ldrsh   r12, [r14]
	ldrsh   r2, [r1, #0x20]
	add     r2, r12, r2
	strh    r2, [r14]
	ldrsh   r2, [r3]
	ldrsh   r1, [r1, #0x22]
	add     r1, r2, r1
	strh    r1, [r3]
	bl      FUN_02117ae0
	mov     r0, r4
	bl      FUN_02117a64
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117c30:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, =_ZN18BowserFireSeaArena9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x324
	mov     r2, #0x1
	mvn     r3, #0x0
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	mov     r0, r4
	bl      FUN_02117a64
	ldr     r0, =_ZN18BowserFireSeaArena8clsnFileE
	bl      _ZN12MeshCollider8LoadFileER13SharedFilePtr
	mov     r1, r0
	ldrsh   r3, [r4, #0x8e]
	ldr     r2, =clpsBlock
	add     r0, r4, #0x374
	str     r3, [r13]
	str     r2, [r13, #0x4]
	add     r2, r4, #0x2ec
	mov     r3, #0x1000
	bl      _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block
	add     r0, r4, #0x374
	ldr     r1, =#0x203929c
	bl      0x020393d4
	add     r0, r4, #0x374
	mov     r1, r4
	bl      _ZN16MeshColliderBase6EnableEP5Actor
	mov     r1, #0x0
	add     r0, r4, #0x300
	strh    r1, [r0, #0x1e]
	strh    r1, [r0, #0x20]
	strh    r1, [r0, #0x22]
	str     r1, [r4, #0x56c]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02117cdc:
	push    { r4, r14 }
	mov     r0, #0x570
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02117d0c
	bl      _ZN8PlatformC2Ev
	ldr     r1, =VTable_BowserFireSeaArena
	add     r0, r4, #0x324
	str     r1, [r4]
	bl      _ZN5ModelC1Ev
	add     r0, r4, #0x374
	bl      _ZN18MovingMeshColliderC1Ev
LAB_02117d0c:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");