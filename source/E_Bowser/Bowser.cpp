#include "SM64DS_2.h"
#include "Actors/Bowser.h"
#include "Actors/BowserShockwaves.h"

extern "C"
{
	ActorBase* FUN_02116428(); // Bowser constructor
	ActorBase* FUN_021163f0(); // BowserTail constructor
	
	// state function declarations for use below
	void FUN_021128c0(Bowser* bowser);
	void FUN_02112724(Bowser* bowser);
	void FUN_021125f0(Bowser* bowser);
	void FUN_021125f0(Bowser* bowser);
	void FUN_02114f88(Bowser* bowser);
	void FUN_02113b5c(Bowser* bowser);
	void FUN_02113740(Bowser* bowser);
	void FUN_02113710(Bowser* bowser);
	void FUN_02112ddc(Bowser* bowser);
	void FUN_021154e8(Bowser* bowser);
	void FUN_021153f8(Bowser* bowser);
	void FUN_02113d8c(Bowser* bowser);
	void FUN_02114858(Bowser* bowser);
	void FUN_021140c0(Bowser* bowser);
	void FUN_021142b4(Bowser* bowser);
	void FUN_02113fcc(Bowser* bowser);
	void FUN_021146d0(Bowser* bowser);
	void FUN_021143b8(Bowser* bowser);
	void FUN_02114d08(Bowser* bowser);
	void FUN_02114e9c(Bowser* bowser);
	void FUN_02114b60(Bowser* bowser);
	void FUN_02114300(Bowser* bowser);
	void FUN_02114ff8(Bowser* bowser);
	void FUN_02112bfc(Bowser* bowser);
	void FUN_02115d68(BowserTail* bowserTail);
	void FUN_02115d50(BowserTail* bowserTail);
	void FUN_02115c1c(BowserTail* bowserTail);
	
	// undocumented globals not in ov60:
	// 0x02132c50 (ov89, koopa_key.bmd SharedFilePtr)
	
	u8 LIFES[3] = { 1, 1, 3 }; // 0x02119264
	u8 UNK_02119268[16] = { 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1 }; // 0x02119268
	u16 MESSAGE_IDS[3] = { 0xcc, 0xce, 0xd0 }; // 0x0211a4e0
	
	s16 UNK_02119294[12][3] = // 0x02119294, 0x02119296, 0x02119298
	{
		{  0x0001,  0x000a, 0x0028 },
		{  0x0000,  0x0000, 0x004a },
		{ -0x0001, -0x000a, 0x0072 },
		{  0x0001, -0x0014, 0x0086 },
		{ -0x0001,  0x0014, 0x009a },
		{  0x0001,  0x0028, 0x00a4 },
		{ -0x0001, -0x0028, 0x00ae },
		{  0x0001, -0x0050, 0x00b3 },
		{ -0x0001,  0x0050, 0x00b8 },
		{  0x0001,  0x00a0, 0x00ba },
		{ -0x0001, -0x00a0, 0x00ba },
		{  0x0001,  0x0000, 0x0000 },
	};
	
	SharedFilePtr* TEX_SEQ_FILE_PTRS[6] = // 0x0211927c
	{
		&Bowser::texSeqFiles[0],
		&Bowser::texSeqFiles[1],
		&Bowser::texSeqFiles[2],
		&Bowser::texSeqFiles[3],
		&Bowser::texSeqFiles[4],
		&Bowser::texSeqFiles[5],
	};
	
	SharedFilePtr* ANIM_FILE_PTRS[28] = // 0x021192dc
	{
		&Bowser::animFiles[0],
		&Bowser::animFiles[1],
		&Bowser::animFiles[2],
		&Bowser::animFiles[3],
		&Bowser::animFiles[4],
		&Bowser::animFiles[5],
		&Bowser::animFiles[6],
		&Bowser::animFiles[7],
		&Bowser::animFiles[8],
		&Bowser::animFiles[9],
		&Bowser::animFiles[10],
		&Bowser::animFiles[11],
		&Bowser::animFiles[12],
		&Bowser::animFiles[13],
		&Bowser::animFiles[14],
		&Bowser::animFiles[15],
		&Bowser::animFiles[16],
		&Bowser::animFiles[17],
		&Bowser::animFiles[18],
		&Bowser::animFiles[19],
		&Bowser::animFiles[20],
		&Bowser::animFiles[21],
		&Bowser::animFiles[22],
		&Bowser::animFiles[23],
		&Bowser::animFiles[24],
		&Bowser::animFiles[25],
		&Bowser::animFiles[26],
		&Bowser::animFiles[27],
	};
	
	using StateFunc = void(*)(Bowser*);
	using TailStateFunc = void(*)(BowserTail*);
	
	struct State
	{
		StateFunc func;
		u32 unk04 = 0;
	};
	
	struct TailState
	{
		TailStateFunc func;
		u32 unk04 = 0;
	};
	
	State bowserStates1[4] = // 0x0211aeb4 (in FUN_02112434) Bowser
	{
		{ &FUN_021128c0 },
		{ &FUN_02112724 },
		{ &FUN_021125f0 },
		{ &FUN_021125f0 },
	};
	
	State bowserStates2[20] = // 0x0211aed4 (in FUN_021128c0) Bowser
	{
		{ &FUN_02114f88 },
		{ &FUN_02113b5c },
		{ &FUN_02113740 },
		{ &FUN_02113710 },
		{ &FUN_02112ddc },
		{ &FUN_021154e8 },
		{ &FUN_021153f8 },
		{ &FUN_02113d8c },
		{ &FUN_02114858 },
		{ &FUN_021140c0 },
		{ &FUN_021142b4 },
		{ &FUN_02113fcc },
		{ &FUN_021146d0 },
		{ &FUN_021143b8 },
		{ &FUN_02114d08 },
		{ &FUN_02114e9c },
		{ &FUN_02114b60 },
		{ &FUN_02114300 },
		{ &FUN_02114ff8 },
		{ &FUN_02112bfc },
	};
	
	TailState tailStates[3] = // 0x0211ae9c (in FUN_02115b84) BowserTail
	{
		{ &FUN_02115d68 },
		{ &FUN_02115d50 },
		{ &FUN_02115c1c },
	};
}

SharedFilePtr Bowser::modelFile;
SharedFilePtr Bowser::texSeqFiles[6];
SharedFilePtr Bowser::animFiles[28];

SpawnInfo Bowser::spawnData = 
{
	&FUN_02116428,
	0x0117,
	0x008f,
	Actor::UPDATE_DURING_STAR_CUTSCENE,
	100._f,
	100._f,
	4096._f,
	4096._f,
};

SpawnInfo BowserTail::spawnData = 
{
	&FUN_021163f0,
	0x0116,
	0x008e,
	Actor::GRABBABLE,
	100._f,
	100._f,
	4096._f,
	4096._f,
};

asm(".global FUN_02111c68");

asm(R"(
@ 0x0211a6b8
VTable_Bowser:
	.word FUN_02116130
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02115e80
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02115f64
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02115f0c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word FUN_02115f08
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02111900
	.word FUN_02111950
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
@ 0x0211a634
VTable_BowserTail:
	.word FUN_021163b4
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02115f00
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02116078
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02115f5c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_021119b4
	.word FUN_021119e4
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
FUN_02111900:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_Bowser
	add     r0, r4, #0x360
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x308
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x14c
	bl      _ZN12WithMeshClsnD1Ev
	add     r0, r4, #0x138
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN9ModelAnimD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111950:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_Bowser
	add     r0, r4, #0x360
	str     r1, [r4]
	bl      _ZN25MovingCylinderClsnWithPosD1Ev
	add     r0, r4, #0x308
	bl      _ZN11ShadowModelD1Ev
	add     r0, r4, #0x14c
	bl      _ZN12WithMeshClsnD1Ev
	add     r0, r4, #0x138
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x0d4
	bl      _ZN9ModelAnimD1Ev
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
FUN_021119b4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserTail
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN18MovingCylinderClsnD1Ev
	mov     r0, r4
	bl      _ZN5ActorD1Ev
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021119e4:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserTail
	add     r0, r4, #0x0d4
	str     r1, [r4]
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
FUN_02111a28:
	push    { r4, r14 }
	sub     r13, r13, #0x28
	mov     r4, r0
	ldr     r0, [r4, #0x12c]
	ldrb    r1, [r4, #0x446]
	mov     r0, r0, lsl #0x4
	mov     r2, r0, lsr #0x10
	cmp     r1, #0x0
	ldr     r0, [r4, #0x134]
	mov     r1, #0x0
	movne   r3, #0x1
	ldr     r12, =_ZN6Bowser9animFilesE + 0x88
	strb    r1, [r4, #0x446]
	ldr     r12, [r12, #0x4]
	moveq   r3, #0x0
	cmp     r0, r12
	bne     LAB_02111a98
	cmp     r2, #0x14
	blt     LAB_02111a80
	cmp     r2, #0x17
	movle   r1, #0x2
	ble     LAB_02111b88
LAB_02111a80:
	cmp     r2, #0x29
	beq     LAB_02111a90
	cmp     r2, #0x2
	bge     LAB_02111b88
LAB_02111a90:
	mov     r1, #0x1
	b       LAB_02111b88
LAB_02111a98:
	ldr     r12, =_ZN6Bowser9animFilesE + 0x90
	ldr     r12, [r12, #0x4]
	cmp     r0, r12
	bne     LAB_02111abc
	cmp     r2, #0x0f
	blt     LAB_02111b88
	cmp     r2, #0x12
	movle   r1, #0x2
	b       LAB_02111b88
LAB_02111abc:
	ldr     r12, =_ZN6Bowser9animFilesE + 0xc0
	ldr     r12, [r12, #0x4]
	cmp     r0, r12
	bne     LAB_02111ad8
	cmp     r2, #0x1c
	movge   r1, #0x1
	b       LAB_02111b88
LAB_02111ad8:
	ldr     r12, =_ZN6Bowser9animFilesE + 0xc8
	ldr     r12, [r12, #0x4]
	cmp     r0, r12
	bne     LAB_02111b08
	cmp     r2, #0x6
	blt     LAB_02111afc
	cmp     r2, #0x9
	movle   r1, #0x2
	ble     LAB_02111b88
LAB_02111afc:
	cmp     r2, #0x0f
	movge   r1, #0x1
	b       LAB_02111b88
LAB_02111b08:
	ldr     r12, =_ZN6Bowser9animFilesE + 0x78
	ldr     r12, [r12, #0x4]
	cmp     r0, r12
	bne     LAB_02111b54
	cmp     r2, #0x10
	blt     LAB_02111b2c
	cmp     r2, #0x13
	movle   r1, #0x1
	ble     LAB_02111b88
LAB_02111b2c:
	cmp     r2, #0x1e
	blt     LAB_02111b40
	cmp     r2, #0x21
	movle   r1, #0x2
	ble     LAB_02111b88
LAB_02111b40:
	cmp     r2, #0x2d
	blt     LAB_02111b88
	cmp     r2, #0x30
	movle   r1, #0x1
	b       LAB_02111b88
LAB_02111b54:
	ldr     r12, =_ZN6Bowser9animFilesE + 0x68
	ldr     r12, [r12, #0x4]
	cmp     r0, r12
	bne     LAB_02111b88
	cmp     r2, #0x0a
	blt     LAB_02111b78
	cmp     r2, #0x0d
	movle   r1, #0x1
	ble     LAB_02111b88
LAB_02111b78:
	cmp     r2, #0x18
	blt     LAB_02111b88
	cmp     r2, #0x1b
	movle   r1, #0x2
LAB_02111b88:
	cmp     r1, #0x0
	addeq   r13, r13, #0x28
	popeq   { r4, r14 }
	bxeq    r14
	mov     r0, #0x1
	cmp     r3, #0x0
	addne   r13, r13, #0x28
	strb    r0, [r4, #0x446]
	popne   { r4, r14 }
	bxne    r14
	cmp     r1, #0x1
	bne     LAB_02111be4
	ldr     r0, [r4, #0x3d4]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r4, #0x3d8]
	mov     r0, r4
	str     r2, [r13, #0x4]
	ldr     r3, [r4, #0x3dc]
	mov     r2, #0x0
	str     r3, [r13, #0x8]
	bl      _ZN5Actor16BigLandingDustAtER7Vector3b
	b       LAB_02111c0c
LAB_02111be4:
	ldr     r0, [r4, #0x3e0]
	add     r1, r13, #0x0c
	str     r0, [r13, #0x0c]
	ldr     r2, [r4, #0x3e4]
	mov     r0, r4
	str     r2, [r13, #0x10]
	ldr     r3, [r4, #0x3e8]
	mov     r2, #0x0
	str     r3, [r13, #0x14]
	bl      _ZN5Actor16BigLandingDustAtER7Vector3b
LAB_02111c0c:
	add     r2, r4, #0x74
	mov     r0, #0x3
	mov     r1, #0x0b0
	bl      _ZN5Sound4PlayEjjRK7Vector3
	ldr     r0, [r4, #0x5c]
	add     r1, r13, #0x18
	str     r0, [r13, #0x18]
	ldr     r2, [r4, #0x60]
	mov     r0, r4
	str     r2, [r13, #0x1c]
	ldr     r3, [r4, #0x64]
	mov     r2, #0x320000
	str     r3, [r13, #0x20]
	bl      _ZN5Actor10EarthquakeERK7Vector35Fix12IiE
	add     r13, r13, #0x28
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111c68:
	ldr     r1, =_ZN6Bowser9animFilesE + 0x40
	ldr     r2, [r0, #0x134]
	ldr     r1, [r1, #0x4]
	cmp     r2, r1
	bne     LAB_02111c94
	ldr     r1, [r0, #0x12c]
	mov     r1, r1, lsl #0x4
	mov     r1, r1, lsr #0x10
	cmp     r1, #0x31
	subcs   r0, r1, #0x31
	bxcs    r14
LAB_02111c94:
	ldr     r1, =_ZN6Bowser9animFilesE + 0x30
	ldr     r1, [r1, #0x4]
	cmp     r2, r1
	ldreq   r0, [r0, #0x12c]
	moveq   r0, r0, lsl #0x4
	moveq   r0, r0, lsr #0x10
	addeq   r0, r0, #0x0b
	mvnne   r0, #0x0
	bx      r14
.ltorg)");

asm(R"(
FUN_02111cc0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r4, #0x0
	str     r4, [r13]
	ldr     r3, =ANIM_FILE_PTRS
	mov     r5, r1
	ldr     r1, [r3, r5, lsl #0x2]
	mov     r4, r0
	ldr     r1, [r1, #0x4]
	add     r0, r4, #0x0d4
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj
	cmp     r5, #0x0e
	addls   r15, r15, r5, lsl #0x2
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111d38
	b       LAB_02111d80
	b       LAB_02111dc8
	b       LAB_02111ea0
	b       LAB_02111dc8
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111e58
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111ea0
	b       LAB_02111e10
LAB_02111d38:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x00
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x00
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x40000000
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02111d80:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x08
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x08
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x40000000
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02111dc8:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x10
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x10
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x0
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02111e10:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x18
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x18
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x0
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02111e58:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x28
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x28
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x40000000
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02111ea0:
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x20
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x20
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x0
	bl      _ZN9Animation8SetFlagsEi
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02111f08:
	push    { r4-r11, r14 }
	sub     r13, r13, #0x0c
	ldr     r1, =CAMERA
	mov     r5, r0
	ldr     r6, [r1]
	bl      _ZN5Actor13ClosestPlayerEv
	movs    r4, r0
	addeq   r13, r13, #0x0c
	moveq   r0, #0x1
	popeq   { r4-r11, r14 }
	bxeq    r14
	ldrb    r0, [r5, #0x444]
	cmp     r0, #0x4
	addls   r15, r15, r0, lsl #0x2
	b       LAB_02112324
	b       LAB_02111f58
	b       LAB_02112098
	b       LAB_021120f8
	b       LAB_02112268
	b       LAB_02112314
LAB_02111f58:
	mov     r0, r6
	bl      _ZN6Camera9SetFlag_3Ev
	add     r3, r4, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	mov     r0, r6
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	ldr     r2, [r5, #0x60]
	str     r2, [r13, #0x4]
	bl      _ZN6Camera9SetLookAtERK7Vector3
	ldr     r0, [r13]
	add     r1, r13, #0x0
	str     r0, [r5, #0x42c]
	ldr     r2, [r13, #0x4]
	add     r0, r5, #0x5c
	str     r2, [r5, #0x430]
	ldr     r2, [r13, #0x8]
	str     r2, [r5, #0x434]
	bl      Vec3_HorzDist
	mov     r4, r0
	add     r1, r13, #0x0
	add     r0, r5, #0x5c
	bl      Vec3_HorzAngle
	mov     r2, #0x0a00
	sub     r0, r0, #0x2000
	mov     r0, r0, lsl #0x10
	mov     r0, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r1, r0, lsl #0x1
	mov     r0, r6
	mov     r6, r1, lsl #0x1
	ldr     r11, =SINE_TABLE
	add     r1, r1, #0x1
	mov     r14, r1, lsl #0x1
	mov     r12, #0x0
	umull   r10, r9, r4, r2
	ldr     r1, =#0x438
	mla     r9, r4, r12, r9
	mov     r8, r4, asr #0x1f
	mla     r9, r8, r2, r9
	mov     r3, #0x800
	adds    r2, r10, r3
	ldrsh   r6, [r11, r6]
	adc     r4, r9, #0x0
	mov     r2, r2, lsr #0x0c
	orr     r2, r2, r4, lsl #0x14
	smull   r6, r4, r2, r6
	adds    r6, r6, r3
	ldr     r7, [r5, #0x5c]
	adc     r4, r4, #0x0
	mov     r6, r6, lsr #0x0c
	orr     r6, r6, r4, lsl #0x14
	add     r4, r7, r6
	str     r4, [r5, #0x438]
	ldr     r4, [r5, #0x60]
	add     r1, r5, r1
	add     r4, r4, #0x0c8000
	str     r4, [r5, #0x43c]
	ldrsh   r4, [r11, r14]
	ldr     r7, [r5, #0x64]
	smull   r6, r4, r2, r4
	adds    r3, r6, r3
	adc     r2, r4, #0x0
	mov     r3, r3, lsr #0x0c
	orr     r3, r3, r2, lsl #0x14
	add     r2, r7, r3
	str     r2, [r5, #0x440]
	bl      _ZN6Camera6SetPosERK7Vector3
	ldr     r0, =#0x444
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02112324
LAB_02112098:
	ldr     r2, =#0x42c
	mov     r0, r6
	add     r1, r6, #0x80
	add     r2, r5, r2
	bl      0x020092c4
	mov     r0, r4
	bl      0x020c2f3c
	cmp     r0, #0x0
	movne   r0, #0x0
	strneb  r0, [r5, #0x445]
	ldreq   r0, =#0x445
	addeq   r1, r5, r0
	ldreqb  r0, [r1]
	addeq   r0, r0, #0x1
	streqb  r0, [r1]
	ldrb    r0, [r5, #0x445]
	cmp     r0, #0x1e
	bls     LAB_02112324
	ldr     r0, =#0x444
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02112324
LAB_021120f8:
	add     r3, r4, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	add     r0, r5, #0x5c
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzDist
	mov     r1, #0x600
	mov     r3, #0x0
	umull   r7, r4, r0, r1
	mla     r4, r0, r3, r4
	mov     r0, r0, asr #0x1f
	mla     r4, r0, r1, r4
	mov     r2, #0x800
	adds    r2, r7, r2
	adc     r0, r4, #0x0
	mov     r4, r2, lsr #0x0c
	orr     r4, r4, r0, lsl #0x14
	cmp     r4, #0x1f4000
	add     r1, r13, #0x0
	add     r0, r5, #0x5c
	movlt   r4, #0x1f4000
	bl      Vec3_HorzAngle
	sub     r0, r0, #0x1000
	mov     r0, r0, lsl #0x10
	mov     r0, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r2, r0, lsl #0x1
	add     r0, r2, #0x1
	ldr     r1, =SINE_TABLE
	mov     r2, r2, lsl #0x1
	ldrsh   r2, [r1, r2]
	mov     r0, r0, lsl #0x1
	ldrsh   r1, [r1, r0]
	smull   r2, r7, r4, r2
	mov     r0, #0x800
	adds    r8, r2, r0
	smull   r1, r3, r4, r1
	adc     r7, r7, #0x0
	adds    r4, r1, r0
	mov     r0, r8, lsr #0x0c
	ldr     r1, [r5, #0x5c]
	orr     r0, r0, r7, lsl #0x14
	add     r1, r1, r0
	adc     r0, r3, #0x0
	mov     r3, r4, lsr #0x0c
	str     r1, [r13]
	ldr     r4, [r5, #0x64]
	orr     r3, r3, r0, lsl #0x14
	add     r0, r4, r3
	ldr     r2, =#0x438
	str     r0, [r13, #0x8]
	add     r0, r5, r2
	mov     r2, #0x4000
	bl      _Z14ApproachLinearRiii
	ldr     r1, [r13, #0x8]
	add     r0, r5, #0x440
	mov     r2, #0x4000
	bl      _Z14ApproachLinearRiii
	ldr     r0, =#0x42c
	ldr     r1, [r5, #0x5c]
	add     r0, r5, r0
	mov     r2, #0x1e000
	bl      _Z14ApproachLinearRiii
	ldr     r0, =#0x434
	ldr     r1, [r5, #0x64]
	add     r0, r5, r0
	mov     r2, #0x1e000
	bl      _Z14ApproachLinearRiii
	ldr     r2, =#0x438
	mov     r0, r6
	add     r1, r6, #0x8c
	add     r2, r5, r2
	bl      0x020092c4
	ldr     r2, =#0x42c
	mov     r0, r6
	add     r1, r6, #0x80
	add     r2, r5, r2
	bl      0x020092c4
	cmp     r0, #0x0
	beq     LAB_02112324
	ldr     r0, =#0x444
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02112324
LAB_02112268:
	ldrh    r0, [r5, #0x8e]
	ldr     r4, [r5, #0x60]
	ldr     r2, =#0x42c
	mov     r0, r0, asr #0x4
	mov     r7, r0, lsl #0x1
	add     r0, r7, #0x1
	ldr     r1, =SINE_TABLE
	mov     r3, r0, lsl #0x1
	mov     r0, r7, lsl #0x1
	ldrsh   r7, [r1, r3]
	ldrsh   r1, [r1, r0]
	ldr     r8, [r5, #0x64]
	mov     r0, #0x0c0
	ldr     r3, [r5, #0x5c]
	smlabb  r7, r7, r0, r8
	add     r4, r4, #0x0fa000
	smlabb  r1,r1,r0,r3
	str     r4, [r13, #0x4]
	add     r0, r5, r2
	mov     r2, #0x0a000
	str     r1, [r13]
	str     r7, [r13, #0x8]
	bl      _Z14ApproachLinearRiii
	ldr     r1, [r13, #0x4]
	add     r0, r5, #0x430
	mov     r2, #0x0a000
	bl      _Z14ApproachLinearRiii
	ldr     r0, =#0x434
	ldr     r1, [r13, #0x8]
	add     r0, r5, r0
	mov     r2, #0x0a000
	bl      _Z14ApproachLinearRiii
	ldr     r2, =#0x42c
	mov     r0, r6
	add     r1, r6, #0x80
	add     r2, r5, r2
	bl      0x020092c4
	cmp     r0, #0x0
	beq     LAB_02112324
	add     r13, r13, #0x0c
	mov     r0, #0x1
	pop     { r4-r11, r14 }
	bx      r14
LAB_02112314:
	add     r1, r6, #0x154
	ldr     r0, [r1]
	bic     r0, r0, #0x8
	str     r0, [r1]
LAB_02112324:
	mov     r0, #0x0
	add     r13, r13, #0x0c
	pop     { r4-r11, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112350:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x124
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =_ZN6Bowser9animFilesE + 0x28
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	popne   { r4, r14 }
	bxne    r14
	mov     r0, r4
	mov     r1, #0x3
	mov     r2, #0x0
	bl      FUN_02111cc0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021123a0:
	cmp     r1, #0x0
	addne   r1, r0, #0x378
	ldrne   r0, [r1]
	bicne   r0, r0, #0x1
	strne   r0, [r1]
	addeq   r1, r0, #0x378
	ldreq   r0, [r1]
	orreq   r0, r0, #0x1
	streq   r0, [r1]
	bx      r14
.ltorg)");

asm(R"(
FUN_021123c8:
	mov     r1, #0x1
	strb    r1, [r0, #0x427]
	mov     r1, #0x0
	str     r1, [r0, #0x3a4]
	bx      r14
.ltorg)");

asm(R"(
FUN_021123dc:
	mov     r1, #0x1
	strb    r1, [r0, #0x415]
	mov     r1, #0x0ff
	strb    r1, [r0, #0x41c]
	strb    r1, [r0, #0x41d]
	ldrb    r1, [r0, #0x414]
	mov     r3, #0x5
	cmp     r1, #0x3
	moveq   r1, #0x0
	streqb  r1, [r0, #0x414]
	ldrb    r2, [r0, #0x414]
	ldr     r1, =LIFES
	ldrb    r12, [r1, r2]
	mov     r2, #0x0
	add     r1, r0, #0x400
	strb    r12, [r0, #0x41e]
	str     r3, [r0, #0x40c]
	str     r2, [r0, #0x410]
	strh    r2, [r1, #0x20]
	strb    r2, [r0, #0x422]
	bx      r14
.ltorg)");

asm(R"(
FUN_02112434:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r2, #0x0
	mov     r4, r0
	add     r1, r13, #0x0
	add     r0, r4, #0x5c
	str     r2, [r13]
	str     r2, [r13, #0x4]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzDist
	str     r0, [r4, #0x3f4]
	add     r1, r13, #0x0
	add     r0, r4, #0x5c
	bl      Vec3_HorzAngle
	add     r2, r4, #0x400
	strh    r0, [r2, #0x8]
	ldrsh   r1, [r4, #0x8e]
	ldrsh   r2, [r2, #0x6]
	mov     r0, r4
	bl      0x020103f4
	add     r2, r4, #0x400
	mov     r5, r0
	ldrsh   r1, [r4, #0x8e]
	ldrsh   r2, [r2, #0x8]
	mov     r0, r4
	bl      0x020103f4
	ldr     r1, =#0x418
	cmp     r5, #0x2000
	add     r2, r4, r1
	ldr     r1, [r2]
	bic     r1, r1, #0x0ff
	str     r1, [r2]
	ldrlt   r1, [r2]
	orrlt   r1, r1, #0x2
	strlt   r1, [r2]
	cmp     r0, #0x3800
	ldrlt   r0, =#0x418
	addlt   r1, r4, r0
	ldrlt   r0, [r1]
	orrlt   r0, r0, #0x4
	strlt   r0, [r1]
	ldr     r0, [r4, #0x3f4]
	cmp     r0, #0x3e8000
	ldrlt   r0, =#0x418
	addlt   r1, r4, r0
	ldrlt   r0, [r1]
	orrlt   r0, r0, #0x10
	strlt   r0, [r1]
	ldr     r1, [r4, #0x3ec]
	ldr     r0, =#0x352000
	cmp     r1, r0
	ldrlt   r0, =#0x418
	addlt   r1, r4, r0
	ldrlt   r0, [r1]
	orrlt   r0, r0, #0x8
	strlt   r0, [r1]
	ldr     r0, [r4, #0x410]
	ldr     r1, =bowserStates1
	add     r3, r1, r0, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r4, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	ldr     r0, [r4, #0x40c]
	cmp     r0, #0x4
	addeq   r13, r13, #0x0c
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldrb    r1, [r4, #0x41c]
	ldrb    r0, [r4, #0x41d]
	cmp     r0, r1
	addeq   r13, r13, #0x0c
	popeq   { r4, r5, r14 }
	bxeq    r14
	cmp     r0, r1
	bls     LAB_021125b0
	add     r0, r1, #0x14
	cmp     r0, #0x0ff
	movge   r0, #0x0ff
	addge   r13, r13, #0x0c
	strgeb  r0, [r4, #0x41c]
	popge   { r4, r5, r14 }
	bxge    r14
	ldr     r0, =#0x41c
	add     r13, r13, #0x0c
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x14
	strb    r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_021125b0:
	sub     r0, r1, #0x14
	cmp     r0, #0x0
	movle   r0, #0x0
	strleb  r0, [r4, #0x41c]
	ldrgt   r0, =#0x41c
	addgt   r1, r4, r0
	ldrgtb  r0, [r1]
	subgt   r0, r0, #0x14
	strgtb  r0, [r1]
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021125f0:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x0e
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldr     r0, [r4, #0x410]
	cmp     r0, #0x3
	bne     LAB_02112624
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
LAB_02112624:
	mov     r0, #0x0
	strb    r0, [r4, #0x425]
	str     r0, [r4, #0x410]
	add     r2, r4, #0x378
	ldr     r1, [r2]
	mov     r0, #0x1
	bic     r1, r1, #0x1
	str     r1, [r2]
	str     r0, [r4, #0x40c]
	ldr     r1, [r4, #0x3f0]
	mov     r0, #0x46
	cmp     r1, #0x0
	rsblt   r1, r1, #0x0
	mul     r0, r1, r0
	ldr     r3, =#0x57619f1
	mov     r1, r0, lsr #0x1f
	smull   r2, r0, r3, r0
	mov     r0, r0, asr #0x7
	add     r0, r1, r0
	cmp     r0, #0x2d
	ble     LAB_02112694
	mov     r1, #0x19
	mul     r2, r0, r1
	ldr     r3, =#0x66666667
	mov     r1, r2, lsr #0x1f
	smull   r2, r0, r3, r2
	mov     r0, r0, asr #0x2
	add     r0, r1, r0
LAB_02112694:
	ldrh    r2, [r4, #0x8c]
	ldr     r3, =SINE_TABLE
	rsb     r1, r0, #0x0
	mov     r2, r2, asr #0x4
	mov     r2, r2, lsl #0x1
	add     r2, r2, #0x1
	mov     r2, r2, lsl #0x1
	ldrsh   r2, [r3, r2]
	mul     r2, r0, r2
	str     r2, [r4, #0x98]
	ldrh    r0, [r4, #0x8c]
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x2
	ldrsh   r0, [r3, r0]
	mul     r0, r1, r0
	str     r0, [r4, #0x0a8]
	ldr     r0, [r4, #0x3a8]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	movne   r1, #0x1
	strne   r1, [r0, #0x110]
	addne   r0, r0, #0x100
	movne   r1, #0x0
	strneh  r1, [r0, #0x14]
	mov     r1, #0x0
	strh    r1, [r4, #0x8c]
	add     r0, r4, #0x300
	strh    r1, [r0, #0x0fc]
	add     r0, r4, #0x14c
	strb    r1, [r4, #0x423]
	bl      _ZN12WithMeshClsn15ClearGroundFlagEv
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112724:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	ldr     r1, =#0x418
	mov     r4, r0
	add     r2, r4, r1
	ldr     r1, [r2]
	bic     r1, r1, #0x20000
	str     r1, [r2]
	ldrb    r1, [r4, #0x425]
	cmp     r1, #0x0
	beq     LAB_02112760
	cmp     r1, #0x1
	beq     LAB_021127b4
	cmp     r1, #0x2
	b       LAB_021127e4
LAB_02112760:
	add     r3, r4, #0x378
	ldr     r0, [r3]
	add     r1, r4, #0x74
	orr     r2, r0, #0x1
	mov     r0, #0x0b2
	str     r2, [r3]
	bl      0x02012694
	mov     r3, #0x1
	mov     r0, r4
	mov     r1, #0x0a
	mov     r2, #0x0
	str     r3, [r4, #0x40c]
	bl      FUN_02111cc0
	ldr     r0, =#0x425
	mov     r1, #0x1000
	str     r1, [r4, #0x3f8]
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_021127e4
LAB_021127b4:
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_021127e4
	mov     r0, r4
	mov     r1, #0x9
	mov     r2, #0x0
	bl      FUN_02111cc0
	ldr     r0, =#0x425
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
LAB_021127e4:
	ldr     r0, [r4, #0x3a4]
	add     r12, r4, #0x5c
	add     r0, r0, #0x600
	ldrsh   r0, [r0, #0x9c]
	add     r14, r4, #0x60
	str     r0, [r4, #0x3f0]
	ldr     r0, [r4, #0x3a4]
	ldr     r1, [r4, #0x3f0]
	ldrsh   r2, [r0, #0x8e]
	cmp     r1, #0x0
	rsblt   r1, r1, #0x0
	rsb     r0, r1, #0x0
	strh    r0, [r4, #0x8c]
	strh    r2, [r4, #0x8e]
	mov     r0, r2, lsl #0x10
	ldr     r1, [r4, #0x3a4]
	mov     r0, r0, lsr #0x10
	add     r2, r1, #0x5c
	ldr     r1, [r2]
	mov     r0, r0, asr #0x4
	str     r1, [r4, #0x5c]
	ldr     r1, [r2, #0x4]
	mov     r5, r0, lsl #0x1
	str     r1, [r4, #0x60]
	ldr     r1, [r2, #0x8]
	ldr     r0, =SINE_TABLE
	str     r1, [r4, #0x64]
	mov     r1, r5, lsl #0x1
	ldrsh   r2, [r0, r1]
	ldr     r3, [r12]
	mov     r1, #0x0a0
	smlabb  r2, r2, r1, r3
	str     r2, [r12]
	ldrh    r3, [r4, #0x8c]
	add     r2, r5, #0x1
	ldr     r12, [r14]
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x2
	ldrsh   r3, [r0, r3]
	mov     r2, r2, lsl #0x1
	smulbb  r3, r3, r1
	rsb     r3, r3, #0x18000
	add     r3, r12, r3
	str     r3, [r14]
	add     r3, r4, #0x64
	ldrsh   r0, [r0, r2]
	ldr     r2, [r3]
	smlabb  r0, r0, r1, r2
	str     r0, [r3]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021128c0:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x1c
	mov     r5, r0
	mov     r0, #0x0
	strb    r0, [r5, #0x425]
	ldr     r0, [r5, #0x40c]
	cmp     r0, #0x4
	beq     LAB_0211294c
	ldr     r0, [r5, #0x384]
	cmp     r0, #0x0
	beq     LAB_0211294c
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	beq     LAB_0211294c
	ldrh    r1, [r0, #0x0c]
	cmp     r1, #0x0bf
	moveq   r1, #0x1
	movne   r1, #0x0
	cmp     r1, #0x0
	beq     LAB_0211294c
	ldr     r1, [r5, #0x5c]
	mov     r4, #0x1
	str     r1, [r13, #0x0c]
	ldr     r1, [r5, #0x60]
	mov     r2, #0x0
	str     r1, [r13, #0x10]
	ldr     r3, [r5, #0x64]
	add     r1, r13, #0x0c
	str     r3, [r13, #0x14]
	str     r4, [r13]
	str     r2, [r13, #0x4]
	mov     r2, #0x2
	mov     r3, #0x8000
	str     r4, [r13, #0x8]
	bl      _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj
LAB_0211294c:
	ldr     r4, [r5, #0x40c]
	ldr     r0, =bowserStates2
	add     r3, r0, r4, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r5, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	add     r1, r5, #0x3fc
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	ldr     r0, [r5, #0x40c]
	cmp     r0, r4
	movne   r1, #0x0
	strneb  r1, [r5, #0x423]
	addne   r0, r5, #0x300
	strneh  r1, [r0, #0x0fc]
	mov     r0, r5
	add     r1, r5, #0x360
	bl      _ZN5Actor9UpdatePosEP12CylinderClsn
	ldrb    r0, [r5, #0x414]
	cmp     r0, #0x1
	bne     LAB_021129c4
	add     r0, r5, #0x14c
	bl      0x02038408
	b       LAB_021129cc
LAB_021129c4:
	add     r0, r5, #0x14c
	bl      0x020383fc
LAB_021129cc:
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02112ab8
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn14GetFloorResultEv
	add     r0, r0, #0x4
	add     r1, r5, #0x3bc
	bl      _ZNK11SurfaceInfo12CopyNormalToER7Vector3
	ldr     r0, [r5, #0x5c]
	str     r0, [r5, #0x3c8]
	ldr     r0, [r5, #0x60]
	str     r0, [r5, #0x3cc]
	ldr     r0, [r5, #0x64]
	str     r0, [r5, #0x3d0]
	ldrb    r0, [r5, #0x427]
	cmp     r0, #0x0
	beq     LAB_02112a5c
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	beq     LAB_02112a5c
	ldr     r1, [r5, #0x0a8]
	mvn     r0, #0x3b
	mul     r3, r1, r0
	ldr     r2, =#0x51eb851f
	mov     r0, r3, lsr #0x1f
	smull   r1, r3, r2, r3
	mov     r3, r3, asr #0x5
	add     r3, r0, r3
	str     r3, [r5, #0x0a8]
	ldr     r0, [r5, #0x0a8]
	cmp     r0, #0x14000
	movge   r0, #0x14000
	strge   r0, [r5, #0x0a8]
	b       LAB_02112ab8
LAB_02112a5c:
	ldr     r1, [r5, #0x3c0]
	cmp     r1, #0x0
	beq     LAB_02112ab8
	ldr     r12, [r5, #0x3bc]
	ldr     r0, [r5, #0x0a4]
	ldr     r3, [r5, #0x3c4]
	ldr     r2, [r5, #0x0ac]
	smull   r6, r14, r12, r0
	mov     r0, #0x800
	adds    r7, r6, r0
	smull   r12, r2, r3, r2
	adc     r6, r14, #0x0
	adds    r3, r12, r0
	mov     r7, r7, lsr #0x0c
	adc     r0, r2, #0x0
	mov     r2, r3, lsr #0x0c
	orr     r7, r7, r6, lsl #0x14
	orr     r2, r2, r0, lsl #0x14
	add     r0, r7, r2
	bl      _ZN4cstd4fdivEii
	add     r0, r0, #0x8000
	rsb     r0, r0, #0x0
	str     r0, [r5, #0x0a8]
LAB_02112ab8:
	ldr     r0, =UNK_02119268
	ldrb    r0, [r0, r4]
	cmp     r0, #0x0
	beq     LAB_02112b5c
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	bne     LAB_02112b44
	ldr     r1, [r5, #0x3c8]
	add     r0, r5, #0x400
	str     r1, [r5, #0x5c]
	ldr     r1, [r5, #0x3cc]
	ldr     r3, =SINE_TABLE
	str     r1, [r5, #0x60]
	ldr     r1, [r5, #0x3d0]
	add     r12, r5, #0x5c
	str     r1, [r5, #0x64]
	ldrh    r1, [r0, #0x8]
	ldr     r4, [r12]
	add     r2, r5, #0x64
	mov     r1, r1, asr #0x4
	mov     r1, r1, lsl #0x2
	ldrsh   r1, [r3, r1]
	add     r1, r4, r1, lsl #0x3
	str     r1, [r12]
	ldrh    r0, [r0, #0x8]
	ldr     r1, [r2]
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x1
	add     r0, r0, #0x1
	mov     r0, r0, lsl #0x1
	ldrsh   r0, [r3, r0]
	add     r0, r1, r0, lsl #0x3
	str     r0, [r2]
	b       LAB_02112b5c
LAB_02112b44:
	ldr     r0, [r5, #0x5c]
	str     r0, [r5, #0x3c8]
	ldr     r0, [r5, #0x60]
	str     r0, [r5, #0x3cc]
	ldr     r0, [r5, #0x64]
	str     r0, [r5, #0x3d0]
LAB_02112b5c:
	mov     r0, r5
	bl      FUN_02112ba8
	cmp     r0, #0x0
	addeq   r13, r13, #0x1c
	popeq   { r4-r7, r14 }
	bxeq    r14
	mov     r0, #0x2
	str     r0, [r5, #0x40c]
	mov     r1, #0x0
	strb    r1, [r5, #0x423]
	add     r0, r5, #0x300
	strh    r1, [r0, #0x0fc]
	add     r13, r13, #0x1c
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112ba8:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r1, [r0, #0x40c]
	cmp     r1, #0x2
	beq     LAB_02112bec
	cmp     r1, #0x13
	beq     LAB_02112bec
	ldr     r1, [r0, #0x3b4]
	ldr     r2, [r0, #0x60]
	sub     r1, r1, #0x3e8000
	cmp     r2, r1
	addlt   r13, r13, #0x4
	movlt   r0, #0x1
	poplt   { r14 }
	bxlt    r14
	add     r0, r0, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
LAB_02112bec:
	mov     r0, #0x0
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112bfc:
	push    { r4-r6, r14 }
	mov     r5, r0
	ldr     r0, [r5, #0x0a0]
	str     r0, [r5, #0x0a8]
	ldr     r0, [r5, #0x3ac]
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	moveq   r0, #0x0
	streq   r0, [r5, #0x40c]
	popeq   { r4-r6, r14 }
	bxeq    r14
	ldr     r3, =UNK_02119294 + 0
	mov     r2, #0x0
	ldrsh   r0, [r3, #0x4]
	mov     r6, #0x1
	cmp     r0, #0x0
	beq     LAB_02112cfc
	add     r0, r5, #0x300
	ldrh    r1, [r0, #0x0fc]
LAB_02112c48:
	ldrsh   r0, [r3, #0x4]
	cmp     r1, r0
	bge     LAB_02112ce8
	mov     r3, #0x6
	mul     r6, r2, r3
	ldr     r0, =UNK_02119294 + 0
	ldr     r14, =UNK_02119294 + 2
	ldrsh   r12, [r0, r6]
	ldrsh   r0, [r14, r6]
	cmp     r12, #0x0
	ble     LAB_02112c94
	ldr     r2, =UNK_02119294 + 4
	ldrsh   r2, [r2, r6]
	sub     r2, r2, #0x1
	sub     r1, r2, r1
	mul     r1, r0, r1
	mov     r0, r1, lsl #0x10
	mov     r6, r0, asr #0x10
	b       LAB_02112cb4
LAB_02112c94:
	sub     r2, r2, #0x1
	mul     r3, r2, r3
	ldr     r2, =UNK_02119294 + 4
	ldrsh   r2, [r2, r3]
	sub     r1, r1, r2
	mul     r1, r0, r1
	mov     r0, r1, lsl #0x10
	mov     r6, r0, asr #0x10
LAB_02112cb4:
	mov     r0, r5
	mov     r1, r6
	bl      FUN_02112d48
	cmp     r6, #0x0
	beq     LAB_02112ce0
	add     r0, r5, #0x300
	ldrh    r0, [r0, #0x0fc]
	ands    r0, r0, #0x1
	beq     LAB_02112ce0
	mov     r0, r4
	bl      FUN_02117a3c
LAB_02112ce0:
	mov     r6, #0x0
	b       LAB_02112cfc
LAB_02112ce8:
	add     r3, r3, #0x6
	ldrsh   r0, [r3, #0x4]
	add     r2, r2, #0x1
	cmp     r0, #0x0
	bne     LAB_02112c48
LAB_02112cfc:
	cmp     r6, #0x0
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r1, #0x0
	str     r1, [r5, #0x40c]
	add     r0, r4, #0x300
	strh    r1, [r0, #0x1e]
	strh    r1, [r0, #0x20]
	strh    r1, [r0, #0x22]
	add     r0, r4, #0x8c
	strh    r1, [r0]
	strh    r1, [r0, #0x2]
	strh    r1, [r0, #0x4]
	str     r1, [r5, #0x0a8]
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112d48:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	ldr     r0, [r5, #0x3ac]
	mov     r4, r1
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r13, r13, #0x4
	popeq   { r4, r5, r14 }
	bxeq    r14
	add     r1, r5, #0x400
	ldrsh   r2, [r1, #0x8]
	ldr     r3, =SINE_TABLE
	add     r1, r0, #0x300
	add     r0, r2, #0x8000
	mov     r0, r0, lsl #0x10
	mov     r0, r0, asr #0x10
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r12, r0, lsl #0x1
	add     r0, r12, #0x1
	mov     r0, r0, lsl #0x1
	ldrsh   r2, [r3, r0]
	mov     r0, r12, lsl #0x1
	mul     r2, r4, r2
	mov     r2, r2, asr #0x0c
	strh    r2, [r1, #0x1e]
	ldrsh   r0, [r3, r0]
	rsb     r0, r0, #0x0
	mul     r0, r4, r0
	mov     r0, r0, asr #0x0c
	strh    r0, [r1, #0x22]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112ddc:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r1, [r4, #0x423]
	cmp     r1, #0x0b
	addls   r15, r15, r1, lsl #0x2
	b       LAB_02112ed4
	b       LAB_02112e24
	b       LAB_02112e30
	b       LAB_02112e3c
	b       LAB_02112e8c
	b       LAB_02112ed4
	b       LAB_02112ed4
	b       LAB_02112ed4
	b       LAB_02112ed4
	b       LAB_02112ed4
	b       LAB_02112ed4
	b       LAB_02112eb8
	b       LAB_02112ed4
LAB_02112e24:
	bl      FUN_02113564
	pop     { r4, r14 }
	bx      r14
LAB_02112e30:
	bl      FUN_021134ac
	pop     { r4, r14 }
	bx      r14
LAB_02112e3c:
	bl      FUN_02113404
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	add     r0, r4, #0x300
	mov     r1, #0x0
	strh    r1, [r0, #0x0fe]
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x2
	moveq   r0, #0x0a
	streqb  r0, [r4, #0x423]
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_02112e8c:
	bl      FUN_021130c0
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_02112eb8:
	bl      FUN_02112ee0
	cmp     r0, #0x0
	ldrne   r0, =#0x423
	addne   r1, r4, r0
	ldrneb  r0, [r1]
	addne   r0, r0, #0x1
	strneb  r0, [r1]
LAB_02112ed4:
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02112ee0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x1c
	mov     r5, r0
	add     r1, r5, #0x300
	ldrh    r1, [r1, #0x0fe]
	mov     r4, #0x0
	cmp     r1, #0x1
	bhi     LAB_02113034
	cmp     r1, #0x0
	bne     LAB_02112f20
	ldr     r0, =#0x3fe
	add     r1, r5, r0
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	strb    r4, [r5, #0x424]
LAB_02112f20:
	ldrb    r0, [r5, #0x424]
	cmp     r0, #0x0
	beq     LAB_02112f40
	cmp     r0, #0x1
	beq     LAB_02112f70
	cmp     r0, #0x2
	beq     LAB_02112fd4
	b       LAB_021130a4
LAB_02112f40:
	ldr     r0, [r5, #0x3a0]
	mov     r1, r5
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_021130a4
	ldr     r0, =#0x424
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_021130a4
LAB_02112f70:
	ldr     r0, [r5, #0x3a0]
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	bne     LAB_021130a4
	bl      NumStars
	cmp     r0, #0x96
	mov     r0, #0x0
	str     r0, [r13]
	mov     r0, #0x2
	movne   r2, #0x0d1
	str     r0, [r13, #0x4]
	ldr     r0, [r5, #0x3a0]
	moveq   r2, #0x0d2
	mov     r1, r5
	add     r3, r5, #0x5c
	bl      _ZN6Player11ShowMessageER9ActorBasejRK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_021130a4
	ldr     r0, =#0x424
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	bl      _ZN7Message11PrepareTalkEv
	b       LAB_021130a4
LAB_02112fd4:
	ldr     r0, [r5, #0x3a0]
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	bne     LAB_021130a4
	mov     r0, #0x3c
	bl      _ZN5Sound22StopLoadedMusic_Layer1Ej
	mov     r0, r5
	bl      FUN_021135fc
	ldr     r0, =#0x3fe
	ldr     r1, =#0x424
	add     r3, r5, r0
	ldrh    r2, [r3]
	add     r12, r5, r1
	mov     r0, r5
	add     r1, r2, #0x1
	strh    r1, [r3]
	ldrb    r3, [r12]
	mov     r1, #0x4
	mov     r2, #0x40000000
	add     r3, r3, #0x1
	strb    r3, [r12]
	bl      FUN_02111cc0
	b       LAB_021130a4
LAB_02113034:
	ldrb    r1, [r5, #0x41c]
	cmp     r1, #0x4
	bls     LAB_0211309c
	ldr     r0, =#0x41c
	mov     r1, #0x99
	add     r2, r5, r0
	ldrb    r0, [r2]
	sub     r0, r0, #0x4
	strb    r0, [r2]
	ldr     r0, [r5, #0x5c]
	str     r0, [r13, #0x0c]
	ldr     r0, [r5, #0x60]
	str     r0, [r13, #0x10]
	ldr     r2, [r5, #0x64]
	add     r0, r0, #0x32000
	str     r2, [r13, #0x14]
	str     r0, [r13, #0x10]
	str     r2, [r13]
	str     r4, [r13, #0x4]
	str     r4, [r13, #0x8]
	ldr     r0, [r5, #0x448]
	ldr     r2, [r13, #0x0c]
	ldr     r3, [r13, #0x10]
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r5, #0x448]
	b       LAB_021130a4
LAB_0211309c:
	bl      FUN_02113260
	mov     r4, #0x1
LAB_021130a4:
	mov     r0, r4
	add     r13, r13, #0x1c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021130c0:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r5, r0
	add     r1, r5, #0x300
	ldrh    r1, [r1, #0x0fe]
	mov     r4, #0x0
	cmp     r1, #0x1
	bhi     LAB_02113220
	cmp     r1, #0x0
	bne     LAB_02113100
	ldr     r0, =#0x3fe
	add     r1, r5, r0
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	strb    r4, [r5, #0x424]
LAB_02113100:
	ldrb    r0, [r5, #0x424]
	cmp     r0, #0x0
	beq     LAB_02113120
	cmp     r0, #0x1
	beq     LAB_0211315c
	cmp     r0, #0x2
	beq     LAB_021131bc
	b       LAB_02113240
LAB_02113120:
	ldr     r0, [r5, #0x3a0]
	mov     r1, r5
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	beq     LAB_02113240
	ldr     r1, =#0x15666
	mov     r0, #0x14
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
	ldr     r0, =#0x424
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02113240
LAB_0211315c:
	ldr     r0, [r5, #0x3a0]
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	bne     LAB_02113240
	ldrb    r0, [r5, #0x414]
	mov     r1, r5
	add     r3, r5, #0x5c
	cmp     r0, #0x0
	mov     r0, #0x0
	str     r0, [r13]
	mov     r0, #0x2
	moveq   r2, #0x0cd
	str     r0, [r13, #0x4]
	ldr     r0, [r5, #0x3a0]
	movne   r2, #0x0cf
	bl      _ZN6Player11ShowMessageER9ActorBasejRK7Vector3jj
	cmp     r0, #0x0
	beq     LAB_02113240
	ldr     r0, =#0x424
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_02113240
LAB_021131bc:
	ldr     r0, [r5, #0x3a0]
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	bne     LAB_02113240
	ldr     r0, =#0x3fe
	ldr     r1, =#0x424
	add     r3, r5, r0
	ldrh    r2, [r3]
	add     r12, r5, r1
	mov     r0, r5
	add     r1, r2, #0x1
	strh    r1, [r3]
	ldrb    r3, [r12]
	mov     r1, #0x4
	mov     r2, #0x40000000
	add     r3, r3, #0x1
	strb    r3, [r12]
	bl      FUN_02111cc0
	mov     r0, #0x3c
	bl      _ZN5Sound22StopLoadedMusic_Layer1Ej
	ldr     r1, =#0x7222
	mov     r0, #0x7f
	bl      _ZN5Sound17ChangeMusicVolumeEj5Fix12IiE
	b       LAB_02113240
LAB_02113220:
	bl      FUN_021132a4
	cmp     r0, #0x0
	beq     LAB_02113240
	mov     r0, r5
	bl      FUN_02113260
	mov     r0, r5
	bl      FUN_021135fc
	mov     r4, #0x1
LAB_02113240:
	mov     r0, r4
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113260:
	ldr     r2, [r0, #0x60]
	mov     r1, #0x0
	str     r1, [r0, #0x5c]
	str     r2, [r0, #0x60]
	str     r1, [r0, #0x64]
	str     r1, [r0, #0x80]
	str     r1, [r0, #0x84]
	str     r1, [r0, #0x88]
	str     r1, [r0, #0x98]
	str     r1, [r0, #0x0a8]
	str     r1, [r0, #0x9c]
	strb    r1, [r0, #0x426]
	add     r1, r0, #0x378
	ldr     r0, [r1]
	orr     r0, r0, #0x1
	str     r0, [r1]
	bx      r14
.ltorg)");

asm(R"(
FUN_021132a4:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x1c
	mov     r5, r0
	ldr     r0, [r5, #0x5c]
	mov     r4, #0x0
	str     r0, [r13, #0x0c]
	ldr     r0, [r5, #0x60]
	mov     r1, #0x99
	str     r0, [r13, #0x10]
	ldr     r2, [r5, #0x64]
	add     r0, r0, #0x32000
	str     r2, [r13, #0x14]
	str     r0, [r13, #0x10]
	str     r2, [r13]
	str     r4, [r13, #0x4]
	str     r4, [r13, #0x8]
	ldr     r0, [r5, #0x448]
	ldr     r2, [r13, #0x0c]
	ldr     r3, [r13, #0x10]
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r5, #0x448]
	ldr     r1, [r5, #0x80]
	ldr     r0, =#0x0ccc
	cmp     r1, r0
	ldrlt   r0, =#0x402
	addlt   r1, r5, r0
	ldrltsh r0, [r1]
	addlt   r0, r0, #0x80
	strlth  r0, [r1]
	ldr     r0, [r5, #0x80]
	cmp     r0, #0x334
	ble     LAB_02113348
	add     r2, r5, #0x80
	ldr     r0, [r2]
	add     r1, r5, #0x88
	sub     r0, r0, #0x52
	str     r0, [r2]
	ldr     r0, [r1]
	sub     r0, r0, #0x52
	str     r0, [r1]
	b       LAB_02113368
LAB_02113348:
	add     r2, r5, #0x84
	ldr     r1, [r2]
	mov     r0, #0x0a000
	sub     r1, r1, #0x29
	str     r1, [r2]
	str     r0, [r5, #0x0a8]
	mov     r0, #0x0
	str     r0, [r5, #0x9c]
LAB_02113368:
	ldr     r0, [r5, #0x84]
	add     r2, r5, #0x8e
	cmp     r0, #0x800
	add     r0, r5, #0x400
	ldrsh   r1, [r2]
	ldrsh   r0, [r0, #0x2]
	movlt   r4, #0x1
	add     r0, r1, r0
	strh    r0, [r2]
	ldrb    r0, [r5, #0x41c]
	cmp     r0, #0x2
	ldrhi   r0, =#0x41c
	addhi   r1, r5, r0
	ldrhib  r0, [r1]
	subhi   r0, r0, #0x2
	strhib  r0, [r1]
	cmp     r4, #0x0
	bne     LAB_021133e8
	ldr     r0, [r5, #0x450]
	add     r3, r5, #0x74
	cmp     r0, #0x0ba
	movne   r0, #0x0
	strne   r0, [r5, #0x44c]
	mov     r0, #0x0ba
	str     r0, [r5, #0x450]
	mov     r0, #0x0
	str     r0, [r13]
	ldr     r0, [r5, #0x44c]
	ldr     r2, [r5, #0x450]
	mov     r1, #0x3
	bl      _ZN5Sound8PlayLongEjjjRK7Vector3j
	str     r0, [r5, #0x44c]
LAB_021133e8:
	mov     r0, r4
	add     r13, r13, #0x1c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113404:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x10
	mov     r5, r0
	mov     r4, #0x0
	bl      FUN_02112350
	ldr     r0, =_ZN6Bowser9animFilesE + 0x18
	ldr     r1, [r5, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_0211348c
	ldr     r0, [r5, #0x3a0]
	cmp     r0, #0x0
	beq     LAB_0211348c
	add     r3, r0, #0x5c
	ldr     r0, [r3]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r3, #0x4]
	add     r0, r5, #0x5c
	str     r2, [r13, #0x4]
	ldr     r2, [r3, #0x8]
	str     r2, [r13, #0x8]
	ldr     r2, [r5, #0x3a0]
	ldrsh   r6, [r2, #0x8e]
	bl      Vec3_HorzDist
	cmp     r0, #0x258000
	bge     LAB_0211348c
	add     r0, r5, #0x400
	ldrsh   r2, [r0, #0x6]
	mov     r0, r5
	mov     r1, r6
	bl      0x020103f4
	cmp     r0, #0x6000
	movgt   r4, #0x1
LAB_0211348c:
	add     r1, r5, #0x300
	mov     r2, #0x0
	mov     r0, r4
	strh    r2, [r1, #0x0fe]
	add     r13, r13, #0x10
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021134ac:
	push    { r4, r14 }
	ldr     r1, =#0x3fe
	mov     r4, r0
	mov     r2, #0x1
	add     r1, r4, r1
	strb    r2, [r4, #0x422]
	bl      FUN_02115a84
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	beq     LAB_0211350c
	ldr     r0, =_ZN6Bowser9animFilesE + 0x00
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_021134fc
	mov     r0, r4
	mov     r1, #0x5
	mov     r2, #0x40000000
	bl      FUN_02111cc0
LAB_021134fc:
	add     r1, r4, #0x98
	ldr     r0, [r1]
	mov     r0, r0, asr #0x1
	str     r0, [r1]
LAB_0211350c:
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02113548
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	bne     LAB_02113548
	ldr     r0, =#0x423
	mov     r1, #0x0
	str     r1, [r4, #0x98]
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
LAB_02113548:
	mov     r0, r4
	bl      FUN_02112350
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113564:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x0
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldrb    r0, [r4, #0x414]
	mov     r1, #0x50000
	cmp     r0, #0x2
	moveq   r0, #0x1c000
	rsbeq   r0, r0, #0x0
	streq   r0, [r4, #0x98]
	movne   r0, #0x19000
	rsbne   r0, r0, #0x0
	strne   r0, [r4, #0x98]
	mov     r0, #0x2000
	str     r1, [r4, #0x0a8]
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x9c]
	add     r0, r4, #0x400
	ldrsh   r2, [r0, #0x8]
	ldr     r1, =#0x423
	add     r0, r4, #0x300
	add     r2, r2, #0x8000
	strh    r2, [r4, #0x8e]
	mov     r2, #0x0
	add     r3, r4, r1
	strh    r2, [r0, #0x0fe]
	ldrb    r0, [r3]
	add     r1, r4, #0x74
	mov     r2, #0x0b4000
	add     r0, r0, #0x1
	strb    r0, [r3]
	mov     r0, #0x0b1
	str     r2, [r4, #0x364]
	bl      0x02012694
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021135fc:
	push    { r4, r14 }
	sub     r13, r13, #0x20
	mov     r4, r0
	ldr     r0, [r4, #0x5c]
	add     r1, r4, #0x378
	str     r0, [r13, #0x8]
	ldr     r0, [r4, #0x60]
	str     r0, [r13, #0x0c]
	ldr     r2, [r4, #0x64]
	add     r0, r0, #0x32000
	str     r2, [r13, #0x10]
	str     r0, [r13, #0x0c]
	ldr     r0, [r1]
	orr     r0, r0, #0x1
	str     r0, [r1]
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x2
	bne     LAB_02113694
	ldr     r1, [r4, #0x5c]
	ldr     r0, =#0x11b
	str     r1, [r13, #0x14]
	ldr     r1, [r4, #0x60]
	add     r2, r13, #0x14
	str     r1, [r13, #0x18]
	ldr     r3, [r4, #0x64]
	add     r1, r1, #0x0a0000
	str     r1, [r13, #0x18]
	str     r3, [r13, #0x1c]
	ldrsb   r3, [r4, #0x0cc]
	mvn     r4, #0x0
	mov     r1, #0x7
	str     r3, [r13]
	mov     r3, #0x0
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	add     r13, r13, #0x20
	pop     { r4, r14 }
	bx      r14
LAB_02113694:
	ldr     r1, [r13, #0x8]
	ldr     r2, [r13, #0x0c]
	ldr     r3, [r13, #0x10]
	mov     r0, #0x0ad
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldr     r1, [r13, #0x8]
	ldr     r2, [r13, #0x0c]
	ldr     r3, [r13, #0x10]
	mov     r0, #0x0ae
	bl      _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_
	ldrsb   r2, [r4, #0x0cc]
	mvn     r1, #0x0
	ldr     r0, =#0x11a
	str     r2, [r13]
	str     r1, [r13, #0x4]
	ldrb    r1, [r4, #0x414]
	add     r2, r4, #0x5c
	mov     r3, #0x0
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	add     r1, r4, #0x400
	add     r2, r0, #0x400
	ldrsh   r3, [r1, #0x2]
	add     r1, r4, #0x74
	mov     r0, #0x0bb
	strh    r3, [r2, #0x40]
	bl      0x02012694
	add     r13, r13, #0x20
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113710:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x0f
	mov     r2, #0x0
	bl      FUN_02111cc0
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113740:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x60
	mov     r6, r0
	ldr     r1, [r6, #0x3b4]
	ldr     r0, [r6, #0x60]
	sub     r4, r1, #0x7d0000
	cmp     r0, r1
	mov     r5, #0x0
	blt     LAB_021137c8
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGroundC1Ev
	ldr     r0, [r6, #0x3b4]
	ldr     r14, [r6, #0x64]
	ldr     r3, [r6, #0x5c]
	add     r12, r0, #0x96000
	add     r0, r13, #0x0c
	add     r1, r13, #0x0
	mov     r2, r6
	str     r3, [r13]
	str     r12, [r13, #0x4]
	str     r14, [r13, #0x8]
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	beq     LAB_021137c0
	add     r0, r13, #0x1c
	ldr     r4, [r13, #0x50]
	bl      _ZNK10ClsnResult9GetClsnIDEv
	mvn     r1, #0x0
	cmp     r0, r1
	movne   r5, #0x1
LAB_021137c0:
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGroundD1Ev
LAB_021137c8:
	ldr     r0, =#0x418
	add     r1, r6, r0
	ldr     r0, [r1]
	orr     r0, r0, #0x10000
	str     r0, [r1]
	ldrb    r0, [r6, #0x423]
	cmp     r0, #0x3
	addls   r15, r15, r0, lsl #0x2
	b       LAB_02113a74
	b       LAB_021137fc
	b       LAB_0211386c
	b       LAB_02113904
	b       LAB_02113a34
LAB_021137fc:
	add     r0, r6, #0x300
	ldrh    r0, [r0, #0x0fc]
	add     r3, r6, #0x8c
	add     r2, r6, #0x90
	cmp     r0, #0x0
	moveq   r0, #0x0
	streqh  r0, [r6, #0x90]
	ldreqsh r0, [r6, #0x90]
	streqh  r0, [r6, #0x8c]
	ldrsh   r1, [r3]
	ldr     r0, =#0x0ffff
	add     r1, r1, #0x800
	strh    r1, [r3]
	ldrsh   r1, [r2]
	add     r1, r1, #0x800
	strh    r1, [r2]
	ldrsh   r1, [r6, #0x8c]
	ands    r0, r1, r0
	ldreq   r0, =#0x423
	addeq   r1, r6, r0
	ldreqb  r0, [r1]
	addeq   r0, r0, #0x1
	streqb  r0, [r1]
	mov     r0, r6
	bl      FUN_02113a94
	add     r13, r13, #0x60
	pop     { r4-r6, r14 }
	bx      r14
LAB_0211386c:
	mov     r0, r6
	mov     r1, #0x0b
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldr     r0, [r6, #0x12c]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x20
	bcc     LAB_021138f0
	add     r0, r6, #0x400
	ldrsh   r0, [r0, #0x8]
	add     r1, r6, #0x74
	mov     r2, #0x28000
	strh    r0, [r6, #0x8e]
	ldrsh   r3, [r6, #0x8e]
	mov     r0, #0x0b1
	strh    r3, [r6, #0x94]
	str     r2, [r6, #0x0a8]
	bl      0x02012694
	mov     r2, #0x0
	ldr     r1, =#0x423
	str     r2, [r6, #0x9c]
	mov     r0, #0x0ff
	strb    r0, [r6, #0x41d]
	add     r0, r6, #0x300
	add     r1, r6, r1
	strh    r2, [r0, #0x0fe]
	ldrb    r0, [r1]
	add     r13, r13, #0x60
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4-r6, r14 }
	bx      r14
LAB_021138f0:
	mov     r0, r6
	bl      FUN_02113a94
	add     r13, r13, #0x60
	pop     { r4-r6, r14 }
	bx      r14
LAB_02113904:
	ldrb    r0, [r6, #0x414]
	ldr     r1, [r6, #0x60]
	cmp     r0, #0x1
	ldreq   r2, =#0x8fc000
	ldr     r0, [r6, #0x3b4]
	ldrne   r2, =#0x9c4000
	cmp     r1, r0
	blt     LAB_02113988
	mov     r0, #0x1000
	rsb     r0, r0, #0x0
	str     r0, [r6, #0x9c]
	ldr     r0, [r6, #0x3f4]
	cmp     r0, r2
	bge     LAB_02113978
	ldr     r0, [r6, #0x3b4]
	subs    r0, r4, r0
	rsbmi   r0, r0, #0x0
	cmp     r0, #0x64000
	bge     LAB_02113964
	add     r0, r6, #0x98
	mov     r1, #0x0
	mov     r2, #0x5000
	bl      _Z14ApproachLinearRiii
	b       LAB_02113988
LAB_02113964:
	add     r0, r6, #0x98
	mov     r1, #0x4b000
	mov     r2, #0x2000
	bl      _Z14ApproachLinearRiii
	b       LAB_02113988
LAB_02113978:
	add     r0, r6, #0x98
	mov     r1, #0x4b000
	mov     r2, #0x2000
	bl      _Z14ApproachLinearRiii
LAB_02113988:
	mov     r0, r6
	bl      FUN_021145d4
	cmp     r0, #0x0
	beq     LAB_02113a20
	ldr     r0, =#0x423
	cmp     r5, #0x0
	add     r1, r6, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	bne     LAB_021139c0
	mov     r0, r6
	bl      FUN_02115b0c
	b       LAB_021139e8
LAB_021139c0:
	ldrb    r0, [r6, #0x414]
	cmp     r0, #0x2
	bne     LAB_021139e8
	mov     r1, #0x0d
	mov     r0, #0x2000
	str     r1, [r6, #0x40c]
	mov     r1, #0x4000
	str     r1, [r6, #0x3f8]
	rsb     r0, r0, #0x0
	str     r0, [r6, #0x9c]
LAB_021139e8:
	ldrb    r0, [r6, #0x414]
	cmp     r0, #0x1
	bne     LAB_02113a20
	mov     r2, #0x13
	mov     r0, #0x0a6
	mov     r1, #0x0
	str     r2, [r6, #0x40c]
	bl      _ZN5Actor15FindWithActorIDEjPS_
	cmp     r0, #0x0
	ldrne   r0, [r0, #0x4]
	strne   r0, [r6, #0x3ac]
	mov     r0, #0x2000
	rsb     r0, r0, #0x0
	str     r0, [r6, #0x9c]
LAB_02113a20:
	mov     r0, r6
	bl      FUN_02115018
	add     r13, r13, #0x60
	pop     { r4-r6, r14 }
	bx      r14
LAB_02113a34:
	mov     r0, r6
	bl      FUN_02115a30
	cmp     r0, #0x0
	addeq   r13, r13, #0x60
	popeq   { r4-r6, r14 }
	bxeq    r14
	ldr     r0, =#0x418
	mov     r1, #0x0
	str     r1, [r6, #0x40c]
	add     r2, r6, r0
	ldr     r1, [r2]
	mov     r0, #0x2000
	bic     r1, r1, #0x10000
	str     r1, [r2]
	rsb     r0, r0, #0x0
	str     r0, [r6, #0x9c]
LAB_02113a74:
	add     r13, r13, #0x60
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113a94:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	mov     r1, #0x0
	strb    r1, [r4, #0x41d]
	ldrb    r0, [r4, #0x41c]
	cmp     r0, #0x0
	addne   r13, r13, #0x10
	popne   { r4, r14 }
	bxne    r14
	str     r1, [r4, #0x98]
	str     r1, [r4, #0x0a8]
	ldr     r1, [r4, #0x3b4]
	add     r0, r4, #0x5c
	sub     r1, r1, #0x3e8000
	str     r1, [r4, #0x60]
	bl      Vec3_HorzLen
	ldr     r1, =#0x0ed8000
	cmp     r0, r1
	addlt   r13, r13, #0x10
	poplt   { r4, r14 }
	bxlt    r14
	mov     r2, #0x0
	add     r0, r13, #0x0
	add     r1, r4, #0x5c
	str     r2, [r13]
	str     r2, [r13, #0x4]
	str     r2, [r13, #0x8]
	bl      Vec3_HorzAngle
	mov     r0, r0, lsl #0x10
	mov     r0, r0, lsr #0x10
	mov     r0, r0, asr #0x4
	mov     r0, r0, lsl #0x1
	add     r1, r0, #0x1
	ldr     r3, =SINE_TABLE
	mov     r0, r0, lsl #0x1
	ldrsh   r2, [r3, r0]
	ldr     r0, =#0x0ed8
	mov     r1, r1, lsl #0x1
	smulbb  r2, r2, r0
	str     r2, [r4, #0x5c]
	ldrsh   r1, [r3, r1]
	smulbb  r0, r1, r0
	str     r0, [r4, #0x64]
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113b5c:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x5c
	mov     r5, r0
	add     r0, r5, #0x300
	ldrh    r1, [r0, #0x0fc]
	cmp     r1, #0x2
	movcc   r1, #0x0
	strcch  r1, [r0, #0x0fe]
	ldr     r4, [r5, #0x60]
	ldr     r0, [r5, #0x3b4]
	cmp     r4, r0
	ble     LAB_02113bec
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGroundC1Ev
	ldr     r0, [r5, #0x3b4]
	ldr     r14, [r5, #0x64]
	ldr     r3, [r5, #0x5c]
	add     r12, r0, #0x96000
	add     r0, r13, #0x0c
	add     r1, r13, #0x0
	mov     r2, r5
	str     r3, [r13]
	str     r12, [r13, #0x4]
	str     r14, [r13, #0x8]
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	beq     LAB_02113be4
	ldr     r0, [r5, #0x3b4]
	ldr     r1, [r13, #0x50]
	sub     r0, r0, #0x64000
	cmp     r1, r0
	movge   r4, r1
LAB_02113be4:
	add     r0, r13, #0x0c
	bl      _ZN13RaycastGroundD1Ev
LAB_02113bec:
	ldrb    r0, [r5, #0x423]
	cmp     r0, #0x0
	bne     LAB_02113ca8
	mov     r0, r5
	mov     r1, #0x9
	mov     r2, #0x0
	bl      FUN_02111cc0
	ldr     r0, [r5, #0x60]
	sub     r0, r0, r4
	cmp     r0, #0x0c8000
	bgt     LAB_02113c28
	ldr     r1, [r5, #0x3f4]
	ldr     r0, =#0x0dac000
	cmp     r1, r0
	ble     LAB_02113c44
LAB_02113c28:
	ldr     r0, [r5, #0x98]
	cmp     r0, #0x1e000
	blt     LAB_02113c44
	add     r0, r5, #0x98
	mov     r1, #0x1e000
	mov     r2, #0x4000
	bl      _Z14ApproachLinearRiii
LAB_02113c44:
	ldr     r1, =#0x3fe
	mov     r0, r5
	add     r1, r5, r1
	bl      FUN_02115a84
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02113cbc
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	bne     LAB_02113cbc
	mov     r1, #0x0
	ldr     r0, =#0x423
	str     r1, [r5, #0x98]
	strb    r1, [r5, #0x427]
	add     r4, r5, r0
	ldrb    r2, [r4]
	mov     r0, r5
	mov     r1, #0x0d
	add     r3, r2, #0x1
	mov     r2, #0x40000000
	strb    r3, [r4]
	bl      FUN_02111cc0
	b       LAB_02113cbc
LAB_02113ca8:
	mov     r0, r5
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r5, #0x40c]
LAB_02113cbc:
	mov     r0, r5
	bl      FUN_02113d20
	cmp     r0, #0x0
	addeq   r13, r13, #0x5c
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, =#0x41e
	add     r1, r5, #0x400
	add     r2, r5, r0
	ldrsb   r0, [r2]
	sub     r0, r0, #0x1
	strb    r0, [r2]
	ldrsb   r0, [r1, #0x1e]
	cmp     r0, #0x0
	movle   r0, #0x4
	strle   r0, [r5, #0x40c]
	movgt   r0, #0x0c
	strgt   r0, [r5, #0x40c]
	add     r13, r13, #0x5c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113d20:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r1, #0x11c
	mov     r5, r0
	bl      0x020108c4
	movs    r4, r0
	beq     LAB_02113d7c
	ldr     r2, [r5, #0x5c]
	add     r1, r13, #0x0
	str     r2, [r13]
	ldr     r2, [r5, #0x60]
	str     r2, [r13, #0x4]
	ldr     r2, [r5, #0x64]
	str     r2, [r13, #0x8]
	bl      FUN_02118544
	cmp     r0, #0x0
	beq     LAB_02113d7c
	mov     r0, r4
	bl      FUN_021185c4
	add     r13, r13, #0x0c
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02113d7c:
	mov     r0, #0x0
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113d8c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fc]
	cmp     r0, #0x0
	moveq   r0, #0x0
	streq   r0, [r4, #0x98]
	ldrb    r0, [r4, #0x423]
	cmp     r0, #0x3
	addls   r15, r15, r0, lsl #0x2
	b       LAB_02113f78
	b       LAB_02113dcc
	b       LAB_02113e00
	b       LAB_02113f0c
	b       LAB_02113ea0
LAB_02113dcc:
	mov     r0, r4
	mov     r1, #0x18
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r0, r4
	add     r1, r4, #0x300
	mov     r2, #0x0
	strh    r2, [r1, #0x0fe]
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x1
	strneb  r0, [r4, #0x423]
	b       LAB_02113f78
LAB_02113e00:
	mov     r0, r4
	mov     r1, #0x19
	mov     r2, #0x0
	bl      FUN_02111cc0
	mov     r1, #0x2a000
	mov     r0, r4
	str     r1, [r4, #0x98]
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_02113e88
	ldr     r0, =#0x3fe
	add     r1, r4, #0x300
	add     r2, r4, r0
	ldrh    r0, [r2]
	add     r0, r0, #0x1
	strh    r0, [r2]
	ldrh    r0, [r1, #0x0fe]
	cmp     r0, #0x0a
	movhi   r0, #0x3
	strhib  r0, [r4, #0x423]
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fe]
	cmp     r0, #0x2
	bcc     LAB_02113e88
	add     r0, r4, #0x400
	ldrsh   r1, [r0, #0x6]
	ldrsh   r2, [r4, #0x8e]
	mov     r0, r4
	bl      0x020103f4
	cmp     r0, #0x2000
	movgt   r0, #0x3
	strgtb  r0, [r4, #0x423]
	movgt   r0, #0x0
	strgt   r0, [r4, #0x448]
LAB_02113e88:
	add     r0, r4, #0x400
	ldrsh   r1, [r0, #0x6]
	add     r0, r4, #0x8e
	mov     r2, #0x200
	bl      _Z14ApproachLinearRsss
	b       LAB_02113f78
LAB_02113ea0:
	add     r1, r4, #0x300
	mov     r2, #0x0
	strh    r2, [r1, #0x0fe]
	mov     r0, r4
	mov     r1, #0x1a
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldr     r1, [r4, #0x64]
	mov     r0, #0x0
	str     r1, [r13]
	str     r0, [r13, #0x4]
	str     r0, [r13, #0x8]
	ldr     r3, [r4, #0x60]
	ldr     r0, [r4, #0x448]
	ldr     r2, [r4, #0x5c]
	ldr     r1, =#0x101
	add     r3, r3, #0x32000
	bl      _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE
	str     r0, [r4, #0x448]
	add     r0, r4, #0x98
	mov     r1, #0x0
	mov     r2, #0x1000
	bl      _Z14ApproachLinearRiii
	cmp     r0, #0x0
	movne   r0, #0x2
	strneb  r0, [r4, #0x423]
	b       LAB_02113f78
LAB_02113f0c:
	mov     r1, #0x0
	mov     r0, r4
	str     r1, [r4, #0x98]
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_02113f78
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x2
	addeq   r0, r4, #0x300
	moveq   r1, #0x0a
	streqh  r1, [r0, #0x0fc]
	addne   r0, r4, #0x300
	movne   r1, #0x1e
	strneh  r1, [r0, #0x0fc]
	add     r0, r4, #0x300
	ldrh    r1, [r0, #0x0fe]
	ldrh    r0, [r0, #0x0fc]
	cmp     r1, r0
	movhi   r0, #0x0
	strhi   r0, [r4, #0x40c]
	movhi   r0, #0x1000
	strhi   r0, [r4, #0x3f8]
	ldr     r0, =#0x3fe
	add     r1, r4, r0
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
LAB_02113f78:
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	addne   r13, r13, #0x10
	popne   { r4, r14 }
	bxne    r14
	mov     r0, #0x0a
	str     r0, [r4, #0x40c]
	ldr     r1, [r4, #0x3c8]
	mov     r0, #0x0
	str     r1, [r4, #0x5c]
	ldr     r1, [r4, #0x3cc]
	str     r1, [r4, #0x60]
	ldr     r1, [r4, #0x3d0]
	str     r1, [r4, #0x64]
	str     r0, [r4, #0x98]
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113fcc:
	push    { r4, r14 }
	mov     r1, #0x3e
	mov     r2, #0x200
	mov     r4, r0
	bl      FUN_02113ff4
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02113ff4:
	push    { r4-r6, r14 }
	mov     r6, r0
	ldrb    r3, [r6, #0x423]
	mov     r5, r1
	mov     r4, r2
	cmp     r3, #0x0
	bne     LAB_02114044
	mov     r1, #0x13
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r0, r6
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_0211408c
	ldr     r0, =#0x423
	add     r1, r6, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_0211408c
LAB_02114044:
	cmp     r3, #0x1
	bne     LAB_02114080
	mov     r1, #0x12
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r0, r6
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_0211408c
	ldr     r0, =#0x423
	add     r1, r6, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	b       LAB_0211408c
LAB_02114080:
	mov     r1, #0x10
	mov     r2, #0x0
	bl      FUN_02111cc0
LAB_0211408c:
	mov     r0, #0x0
	str     r0, [r6, #0x98]
	add     r3, r6, #0x8e
	ldrsh   r2, [r3]
	add     r1, r6, #0x300
	add     r2, r2, r4
	strh    r2, [r3]
	ldrh    r1, [r1, #0x0fc]
	cmp     r1, r5
	movcs   r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021140c0:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x20
	mov     r4, r0
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fc]
	cmp     r0, #0x0
	bne     LAB_02114144
	ldr     r0, [r4, #0x3a0]
	cmp     r0, #0x0
	beq     LAB_021140f4
	bl      0x020bf548
	cmp     r0, #0x4
	ble     LAB_0211413c
LAB_021140f4:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r5, r3, r1
	ldr     r2, =#0x0a
	mov     r5, r5, lsr #0x3
	umull   r0, r1, r2, r5
	ldr     r1, =#0x0aaaaaaab
	sub     r5, r3, r0
	umull   r0, r1, r5, r1
	ldr     r2, =#0x3
	mov     r1, r1, lsr #0x1
	umull   r0, r1, r2, r1
	sub     r1, r5, r0
	add     r0, r1, #0x1
	strb    r0, [r4, #0x428]
	b       LAB_02114144
LAB_0211413c:
	mov     r0, #0x3
	strb    r0, [r4, #0x428]
LAB_02114144:
	ldr     r0, =_ZN6Bowser9animFilesE + 0xa0
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02114214
	add     r0, r4, #0x124
	mov     r1, #0x5
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_02114214
	ldr     r3, [r4, #0x5c]
	ldr     r8, =SINE_TABLE
	str     r3, [r13, #0x10]
	ldr     r0, [r4, #0x60]
	mov     r12, #0x0e8
	str     r0, [r13, #0x14]
	ldr     r1, [r4, #0x64]
	add     r6, r0, #0x58000
	str     r1, [r13, #0x18]
	ldrh    r7, [r4, #0x8c]
	ldrh    r0, [r4, #0x8e]
	mov     r14, #0x1000
	add     r2, r13, #0x8
	strh    r0, [r13, #0x0a]
	ldrh    r5, [r13, #0x0a]
	strh    r7, [r13, #0x8]
	ldrh    r0, [r4, #0x90]
	mov     r5, r5, asr #0x4
	mov     r7, r5, lsl #0x1
	add     r5, r7, #0x1
	mov     r7, r7, lsl #0x1
	mov     r5, r5, lsl #0x1
	ldrsh   r7, [r8, r7]
	ldrsh   r5, [r8, r5]
	strh    r0, [r13, #0x0c]
	smlabb  r3, r7, r12, r3
	smlabb  r0, r5, r12, r1
	str     r3, [r13, #0x10]
	str     r0, [r13, #0x18]
	str     r6, [r13, #0x14]
	strh    r14, [r13, #0x8]
	mov     r3, #0x0a000
	str     r3, [r13]
	mov     r12, #0x0
	add     r1, r13, #0x10
	mov     r0, r4
	mov     r3, #0x1e000
	str     r12, [r13, #0x4]
	bl      0x020102b0
	ldr     r0, =#0x122
	add     r1, r4, #0x74
	bl      0x02012694
LAB_02114214:
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	addeq   r13, r13, #0x20
	popeq   { r4-r8, r14 }
	bxeq    r14
	ldr     r0, =_ZN6Bowser9animFilesE + 0xa0
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_0211426c
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r1, [r4, #0x423]
	ldrb    r0, [r4, #0x428]
	cmp     r1, r0
	movcs   r0, #0x0
	strcs   r0, [r4, #0x40c]
	b       LAB_0211427c
LAB_0211426c:
	mov     r0, r4
	mov     r1, #0x14
	mov     r2, #0x0
	bl      FUN_02111cc0
LAB_0211427c:
	mov     r0, #0x0
	str     r0, [r4, #0x12c]
	add     r13, r13, #0x20
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021142b4:
	push    { r4, r14 }
	mov     r4, r0
	mov     r2, #0x0
	str     r2, [r4, #0x98]
	add     r0, r4, #0x300
	ldrh    r1, [r0, #0x0fc]
	cmp     r1, #0x0
	streqh  r2, [r0, #0x0fe]
	mov     r0, r4
	mov     r1, #0x1b
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0b
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114300:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r1, [r4, #0x423]
	cmp     r1, #0x0
	bne     LAB_02114368
	bl      FUN_0211469c
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	mov     r0, #0x32000
	ldr     r1, =#0x423
	str     r0, [r4, #0x0a8]
	mov     r0, #0x19000
	str     r0, [r4, #0x98]
	add     r3, r4, r1
	add     r0, r4, #0x300
	mov     r2, #0x0
	strh    r2, [r0, #0x0fe]
	ldrb    r2, [r3]
	add     r1, r4, #0x74
	mov     r0, #0x0b1
	add     r2, r2, #0x1
	strb    r2, [r3]
	bl      0x02012694
	pop     { r4, r14 }
	bx      r14
LAB_02114368:
	cmp     r1, #0x1
	bne     LAB_0211439c
	bl      FUN_021145d4
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_0211439c:
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021143b8:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldrb    r1, [r4, #0x423]
	cmp     r1, #0x0
	bne     LAB_02114470
	bl      FUN_0211469c
	cmp     r0, #0x0
	addeq   r13, r13, #0x10
	popeq   { r4, r14 }
	bxeq    r14
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x2
	bne     LAB_02114404
	ldr     r0, [r4, #0x418]
	ands    r0, r0, #0x10000
	movne   r0, #0x28000
	strne   r0, [r4, #0x0a8]
	bne     LAB_0211440c
LAB_02114404:
	mov     r0, #0x32000
	str     r0, [r4, #0x0a8]
LAB_0211440c:
	add     r1, r4, #0x74
	mov     r0, #0x0b1
	bl      0x02012694
	add     r0, r4, #0x300
	mov     r1, #0x0
	strh    r1, [r0, #0x0fe]
	mov     r0, r4
	str     r1, [r4, #0x98]
	bl      FUN_021145a8
	ldr     r0, [r4, #0x98]
	mov     r1, #0x1000
	cmp     r0, #0x0
	ldreq   r0, [r4, #0x3c8]
	add     r13, r13, #0x10
	streq   r0, [r4, #0x5c]
	ldreq   r0, [r4, #0x3d0]
	streq   r0, [r4, #0x64]
	ldr     r0, =#0x423
	add     r2, r4, r0
	ldrb    r0, [r2]
	add     r0, r0, #0x1
	strb    r0, [r2]
	str     r1, [r4, #0x3f8]
	pop     { r4, r14 }
	bx      r14
LAB_02114470:
	cmp     r1, #0x1
	bne     LAB_02114584
	ldrb    r1, [r4, #0x414]
	cmp     r1, #0x2
	bne     LAB_02114494
	ldr     r1, [r4, #0x418]
	ands    r1, r1, #0x10000
	beq     LAB_02114494
	bl      FUN_02115018
LAB_02114494:
	mov     r0, r4
	bl      FUN_021145d4
	cmp     r0, #0x0
	bne     LAB_021144bc
	ldr     r1, [r4, #0x60]
	ldr     r0, [r4, #0x3cc]
	cmp     r1, r0
	addge   r13, r13, #0x10
	popge   { r4, r14 }
	bxge    r14
LAB_021144bc:
	ldr     r0, [r4, #0x0a8]
	cmp     r0, #0x0
	beq     LAB_02114500
	ldr     r0, [r4, #0x5c]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r4, #0x60]
	mov     r0, r4
	str     r2, [r13, #0x4]
	ldr     r3, [r4, #0x64]
	mov     r2, #0x0
	str     r3, [r13, #0x8]
	bl      0x0200fa04
	mov     r0, r4
	mov     r1, #0x0c
	mov     r2, #0x40000000
	bl      FUN_02111cc0
LAB_02114500:
	ldr     r0, =#0x418
	ldr     r1, =#0x423
	add     r3, r4, r0
	ldr     r2, [r3]
	mov     r0, #0x0
	bic     r2, r2, #0x10000
	str     r2, [r3]
	str     r0, [r4, #0x98]
	str     r0, [r4, #0x0a8]
	ldr     r0, [r4, #0x3cc]
	add     r2, r4, r1
	str     r0, [r4, #0x60]
	ldrb    r1, [r2]
	mov     r0, r4
	add     r1, r1, #0x1
	strb    r1, [r2]
	bl      FUN_02115b0c
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x1
	addne   r13, r13, #0x10
	popne   { r4, r14 }
	bxne    r14
	mov     r2, #0x13
	mov     r0, #0x0a6
	mov     r1, #0x0
	str     r2, [r4, #0x40c]
	bl      _ZN5Actor15FindWithActorIDEjPS_
	cmp     r0, #0x0
	ldrne   r0, [r0, #0x4]
	add     r13, r13, #0x10
	strne   r0, [r4, #0x3ac]
	pop     { r4, r14 }
	bx      r14
LAB_02114584:
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021145a8:
	ldrb    r1, [r0, #0x414]
	cmp     r1, #0x2
	bxne    r14
	ldr     r1, [r0, #0x418]
	ands    r1, r1, #0x10000
	bxeq    r14
	ldr     r1, [r0, #0x3f4]
	cmp     r1, #0x3e8000
	movgt   r1, #0x1e000
	strgt   r1, [r0, #0x98]
	bx      r14
.ltorg)");

asm(R"(
FUN_021145d4:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_02114688
	mov     r2, #0x0
	str     r2, [r4, #0x98]
	str     r2, [r4, #0x0a8]
	ldr     r0, [r4, #0x5c]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r3, [r4, #0x60]
	mov     r0, r4
	str     r3, [r13, #0x4]
	ldr     r3, [r4, #0x64]
	str     r3, [r13, #0x8]
	bl      0x0200fa04
	mov     r0, r4
	mov     r1, #0x0c
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	add     r1, r4, #0x74
	mov     r0, #0x0b6
	bl      0x02012694
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x0
	bne     LAB_02114678
	ldr     r1, [r4, #0x3ec]
	ldr     r0, =#0x352000
	cmp     r1, r0
	movge   r5, #0x1
	ldr     r0, [r4, #0x3a0]
	movlt   r5, #0x0
	bl      0x020c2f3c
	cmp     r0, #0x0
	bne     LAB_02114678
	ldr     r0, [r4, #0x3a0]
	mov     r1, r5
	bl      0x020c56f0
LAB_02114678:
	add     r13, r13, #0x0c
	mov     r0, #0x1
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114688:
	mov     r0, #0x0
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211469c:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x0b
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	add     r0, r4, #0x124
	mov     r1, #0x20
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	movne   r0, #0x1
	moveq   r0, #0x0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021146d0:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fc]
	cmp     r0, #0x0
	bne     LAB_02114730
	mov     r0, #0x1c000
	rsb     r0, r0, #0x0
	str     r0, [r4, #0x98]
	mov     r0, #0x50000
	str     r0, [r4, #0x0a8]
	add     r0, r4, #0x400
	ldrsh   r2, [r0, #0x8]
	mov     r0, #0x0c00
	mov     r1, #0x1
	add     r2, r2, #0x8000
	strh    r2, [r4, #0x8e]
	strb    r1, [r4, #0x422]
	rsb     r2, r0, #0x0
	add     r1, r4, #0x74
	mov     r0, #0x0b1
	strh    r2, [r4, #0x8c]
	bl      0x02012694
	b       LAB_02114750
LAB_02114730:
	ldrh    r0, [r4, #0x8c]
	cmp     r0, #0x0c00
	addhi   r1, r4, #0x8c
	ldrhish r0, [r1]
	subhi   r0, r0, #0x0c00
	strhih  r0, [r1]
	movls   r0, #0x0
	strlsh  r0, [r4, #0x8c]
LAB_02114750:
	ldrb    r0, [r4, #0x423]
	cmp     r0, #0x0
	bne     LAB_02114794
	mov     r0, r4
	mov     r1, #0x1
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldr     r0, =#0x423
	add     r1, r4, #0x300
	add     r3, r4, r0
	ldrb    r2, [r3]
	mov     r0, #0x0
	add     r2, r2, #0x1
	strb    r2, [r3]
	strh    r0, [r1, #0x0fe]
	pop     { r4, r14 }
	bx      r14
LAB_02114794:
	cmp     r0, #0x1
	bne     LAB_02114808
	ldr     r1, =#0x3fe
	mov     r0, r4
	add     r1, r4, r1
	bl      FUN_02115a84
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fe]
	cmp     r0, #0x1
	bne     LAB_021147cc
	mov     r0, r4
	mov     r1, #0x2
	mov     r2, #0x40000000
	bl      FUN_02111cc0
LAB_021147cc:
	add     r0, r4, #0x300
	ldrh    r0, [r0, #0x0fe]
	cmp     r0, #0x3
	popcc   { r4, r14 }
	bxcc    r14
	mov     r1, #0x0
	str     r1, [r4, #0x0a8]
	ldr     r0, =#0x423
	str     r1, [r4, #0x98]
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_02114808:
	cmp     r0, #0x2
	popne   { r4, r14 }
	bxne    r14
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	beq     LAB_02114840
	add     r0, r4, #0x400
	ldrsb   r0, [r0, #0x1e]
	cmp     r0, #0x1
	moveq   r0, #0x3
	streq   r0, [r4, #0x40c]
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
LAB_02114840:
	mov     r0, #0x0
	strb    r0, [r4, #0x422]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114858:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x14
	ldr     r1, =_ZN6Bowser9animFilesE + 0xa8
	mov     r5, r0
	ldr     r2, [r5, #0x134]
	ldr     r0, [r1, #0x4]
	cmp     r2, r0
	beq     LAB_0211489c
	ldr     r0, =_ZN6Bowser9animFilesE + 0xb0
	ldr     r0, [r0, #0x4]
	cmp     r2, r0
	bne     LAB_02114a28
	ldr     r0, [r5, #0x12c]
	mov     r0, r0, lsl #0x4
	mov     r0, r0, lsr #0x10
	cmp     r0, #0x2a
	bls     LAB_02114a28
LAB_0211489c:
	ldr     r0, [r5, #0x12c]
	ldr     r1, [r5, #0x450]
	mov     r0, r0, lsl #0x4
	cmp     r1, #0x180
	mov     r4, r0, lsr #0x10
	movne   r0, #0x0
	strne   r0, [r5, #0x44c]
	mov     r0, #0x180
	str     r0, [r5, #0x450]
	mov     r0, #0x0
	str     r0, [r13]
	ldr     r0, [r5, #0x44c]
	ldr     r2, [r5, #0x450]
	add     r3, r5, #0x74
	mov     r1, #0x3
	bl      _ZN5Sound8PlayLongEjjjRK7Vector3j
	str     r0, [r5, #0x44c]
	add     r0, r5, #0x400
	ldrh    r3, [r0]
	ldr     r1, =#0x66666667
	ldr     r2, =#0x5
	smull   r0, r12, r1, r3
	mov     r12, r12, asr #0x1
	mov     r0, r3, lsr #0x1f
	add     r12, r0, r12
	smull   r0, r1, r2, r12
	subs    r12, r3, r0
	bne     LAB_02114a18
	ldr     r14, [r5, #0x5c]
	ldr     r12, =SINE_TABLE
	str     r14, [r13, #0x8]
	ldr     r2, [r5, #0x60]
	mov     r1, #0x0c8
	str     r2, [r13, #0x0c]
	ldr     r0, [r5, #0x64]
	add     r2, r2, #0x0b4000
	str     r0, [r13, #0x10]
	ldrh    r3, [r5, #0x94]
	mov     r3, r3, asr #0x4
	mov     r3, r3, lsl #0x2
	ldrsh   r3, [r12, r3]
	str     r2, [r13, #0x0c]
	smlabb  r2, r3, r1, r14
	str     r2, [r13, #0x8]
	ldrh    r2, [r5, #0x94]
	mov     r2, r2, asr #0x4
	mov     r2, r2, lsl #0x1
	add     r2, r2, #0x1
	mov     r2, r2, lsl #0x1
	ldrsh   r2, [r12, r2]
	smlabb  r0, r2, r1, r0
	str     r0, [r13, #0x10]
	cmp     r4, #0x0f
	blt     LAB_021149cc
	cmp     r4, #0x14
	bge     LAB_021149cc
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	ldrsb   r4, [r5, #0x0cc]
	mov     r0, r1, lsl #0x0a
	orr     r1, r0, #0x11
	str     r4, [r13]
	mvn     r4, #0x0
	add     r2, r13, #0x8
	add     r3, r5, #0x92
	mov     r0, #0x118
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	b       LAB_02114a18
LAB_021149cc:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	ldrsb   r4, [r5, #0x0cc]
	mov     r0, r1, lsl #0x0a
	orr     r1, r0, #0x1
	str     r4, [r13]
	mvn     r4, #0x0
	add     r2, r13, #0x8
	add     r3, r5, #0x92
	mov     r0, #0x118
	str     r4, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
LAB_02114a18:
	add     r1, r5, #0x400
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
LAB_02114a28:
	ldr     r1, =#0x418
	mov     r0, r5
	add     r2, r5, r1
	ldr     r1, [r2]
	orr     r1, r1, #0x20000
	str     r1, [r2]
	bl      FUN_02115a30
	cmp     r0, #0x0
	addeq   r13, r13, #0x14
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldrb    r0, [r5, #0x423]
	cmp     r0, #0x3
	addls   r15, r15, r0, lsl #0x2
	b       LAB_02114b2c
	b       LAB_02114a74
	b       LAB_02114ab0
	b       LAB_02114ae0
	b       LAB_02114b10
LAB_02114a74:
	mov     r0, r5
	mov     r1, #0x16
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	add     r1, r5, #0x74
	mov     r0, #0x0b5
	bl      0x02012694
	ldr     r0, =#0x423
	add     r13, r13, #0x14
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114ab0:
	mov     r0, r5
	mov     r1, #0x15
	mov     r2, #0x0
	bl      FUN_02111cc0
	ldr     r0, =#0x423
	add     r13, r13, #0x14
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114ae0:
	mov     r0, r5
	mov     r1, #0x17
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	ldr     r0, =#0x423
	add     r13, r13, #0x14
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114b10:
	ldr     r0, =#0x418
	mov     r1, #0x0
	str     r1, [r5, #0x40c]
	add     r1, r5, r0
	ldr     r0, [r1]
	bic     r0, r0, #0x20000
	str     r0, [r1]
LAB_02114b2c:
	add     r13, r13, #0x14
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114b60:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	add     r2, r5, #0x378
	ldr     r0, [r2]
	orr     r0, r0, #0x1
	str     r0, [r2]
	ldrb    r0, [r5, #0x423]
	cmp     r0, #0x0
	beq     LAB_02114ba4
	cmp     r0, #0x1
	beq     LAB_02114c10
	cmp     r0, #0x2
	beq     LAB_02114ccc
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114ba4:
	mov     r0, #0x0
	strb    r0, [r5, #0x41d]
	add     r0, r5, #0x300
	mov     r1, #0x1e
	strh    r1, [r0, #0x0fe]
	ldrh    r0, [r0, #0x0fc]
	cmp     r0, #0x0
	bne     LAB_02114bd0
	add     r1, r5, #0x74
	mov     r0, #0x0b9
	bl      0x02012694
LAB_02114bd0:
	ldrb    r0, [r5, #0x41c]
	cmp     r0, #0x0
	addne   r13, r13, #0x4
	popne   { r4, r5, r14 }
	bxne    r14
	ldr     r0, =#0x423
	add     r1, r5, #0x400
	add     r2, r5, r0
	ldrb    r0, [r2]
	add     r13, r13, #0x4
	add     r0, r0, #0x1
	strb    r0, [r2]
	ldrsh   r0, [r1, #0x6]
	strh    r0, [r5, #0x8e]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114c10:
	ldr     r1, =#0x3fe
	add     r0, r5, #0x300
	add     r2, r5, r1
	ldrh    r1, [r2]
	ldrh    r3, [r0, #0x0fe]
	mov     r4, #0x0
	sub     r0, r1, #0x1
	cmp     r3, #0x0
	strh    r0, [r2]
	movne   r0, #0x64000
	strne   r0, [r5, #0x98]
	add     r0, r5, #0x400
	ldrsh   r2, [r0, #0x6]
	ldrsh   r1, [r5, #0x8e]
	mov     r0, r5
	moveq   r4, #0x1
	bl      0x020103f4
	cmp     r0, #0x4000
	ble     LAB_02114c68
	ldr     r0, [r5, #0x3ec]
	cmp     r0, #0x1f4000
	movgt   r4, #0x1
LAB_02114c68:
	add     r0, r5, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	bne     LAB_02114c9c
	ldr     r1, [r5, #0x3c8]
	mov     r0, #0x0
	str     r1, [r5, #0x5c]
	ldr     r1, [r5, #0x3cc]
	mov     r4, #0x1
	str     r1, [r5, #0x60]
	ldr     r1, [r5, #0x3d0]
	str     r1, [r5, #0x64]
	str     r0, [r5, #0x98]
LAB_02114c9c:
	cmp     r4, #0x0
	addeq   r13, r13, #0x4
	popeq   { r4, r5, r14 }
	bxeq    r14
	mov     r0, #0x2
	strb    r0, [r5, #0x423]
	add     r0, r5, #0x400
	ldrsh   r0, [r0, #0x6]
	add     r13, r13, #0x4
	strh    r0, [r5, #0x8e]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114ccc:
	mov     r1, #0x0
	str     r1, [r5, #0x98]
	mov     r0, #0x0ff
	strb    r0, [r5, #0x41d]
	ldrb    r0, [r5, #0x41c]
	cmp     r0, #0x0ff
	streq   r1, [r5, #0x40c]
	ldreq   r0, [r2]
	biceq   r0, r0, #0x1
	streq   r0, [r2]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114d08:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	add     r2, r5, #0x400
	ldrsh   r1, [r5, #0x8e]
	ldrsh   r2, [r2, #0x6]
	bl      0x020103f4
	ldrb    r1, [r5, #0x414]
	mov     r4, r0
	cmp     r1, #0x1
	moveq   r2, #0x400
	beq     LAB_02114d58
	add     r0, r5, #0x400
	ldrsb   r0, [r0, #0x1e]
	cmp     r0, #0x2
	movgt   r2, #0x400
	bgt     LAB_02114d58
	cmp     r0, #0x2
	moveq   r2, #0x300
	movne   r2, #0x200
LAB_02114d58:
	add     r0, r5, #0x400
	ldrsh   r1, [r0, #0x6]
	add     r0, r5, #0x8e
	bl      _Z14ApproachLinearRsss
	ldrb    r0, [r5, #0x423]
	cmp     r0, #0x0
	bne     LAB_02114db8
	mov     r0, r5
	add     r1, r5, #0x300
	mov     r2, #0x0
	strh    r2, [r1, #0x0fe]
	bl      FUN_02115744
	cmp     r0, #0x0
	addeq   r13, r13, #0x4
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r13, r13, #0x4
	add     r1, r5, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114db8:
	cmp     r0, #0x2
	bhi     LAB_02114e70
	mov     r0, r5
	bl      FUN_02115718
	cmp     r0, #0x0
	addeq   r13, r13, #0x4
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldr     r0, =#0x3fe
	add     r1, r5, r0
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	ldr     r0, [r5, #0x418]
	ands    r0, r0, #0x20000
	beq     LAB_02114e30
	add     r0, r5, #0x300
	ldrh    r0, [r0, #0x0fe]
	cmp     r0, #0x5
	addcc   r13, r13, #0x4
	popcc   { r4, r5, r14 }
	bxcc    r14
	ldr     r0, =#0x418
	add     r13, r13, #0x4
	add     r1, r5, r0
	ldr     r0, [r1]
	bic     r0, r0, #0x20000
	str     r0, [r1]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114e30:
	cmp     r4, #0x2000
	addge   r13, r13, #0x4
	popge   { r4, r5, r14 }
	bxge    r14
	ldr     r0, =#0x423
	mov     r3, #0x0
	add     r2, r5, r0
	str     r3, [r5, #0x12c]
	ldrb    r1, [r2]
	add     r0, r5, #0x300
	add     r13, r13, #0x4
	add     r1, r1, #0x1
	strb    r1, [r2]
	strh    r3, [r0, #0x0fe]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02114e70:
	mov     r0, r5
	bl      FUN_021156ec
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r5, #0x40c]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114e9c:
	push    { r4, r14 }
	mov     r4, r0
	mov     r0, #0x0
	str     r0, [r4, #0x98]
	ldr     r0, =_ZN6Bowser9animFilesE + 0x40
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02114ee0
	add     r0, r4, #0x124
	mov     r1, #0x8
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_02114ee0
	add     r1, r4, #0x74
	mov     r0, #0x0b5
	bl      0x02012694
LAB_02114ee0:
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =_ZN6Bowser9animFilesE + 0x40
	ldr     r1, [r4, #0x134]
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02114f20
	mov     r0, r4
	mov     r1, #0x6
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	pop     { r4, r14 }
	bx      r14
LAB_02114f20:
	ldr     r0, =_ZN6Bowser9animFilesE + 0x30
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	bne     LAB_02114f48
	mov     r0, r4
	mov     r1, #0x7
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	pop     { r4, r14 }
	bx      r14
LAB_02114f48:
	ldr     r0, =_ZN6Bowser9animFilesE + 0x38
	ldr     r0, [r0, #0x4]
	cmp     r1, r0
	moveq   r0, #0x0
	streq   r0, [r4, #0x40c]
	popeq   { r4, r14 }
	bxeq    r14
	mov     r0, r4
	mov     r1, #0x8
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114f88:
	push    { r4, r14 }
	mov     r4, r0
	mov     r2, #0x0
	mov     r1, #0x10
	strb    r2, [r4, #0x422]
	bl      FUN_02111cc0
	add     r0, r4, #0x400
	mov     r1, #0x0
	strh    r1, [r0, #0x2]
	str     r1, [r4, #0x98]
	str     r1, [r4, #0x0a8]
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x0
	bne     LAB_02114fd0
	mov     r0, r4
	bl      FUN_02115314
	pop     { r4, r14 }
	bx      r14
LAB_02114fd0:
	cmp     r0, #0x1
	bne     LAB_02114fe8
	mov     r0, r4
	bl      FUN_021151d4
	pop     { r4, r14 }
	bx      r14
LAB_02114fe8:
	mov     r0, r4
	bl      FUN_02115060
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02114ff8:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115018:
	ldr     r1, [r0, #0x0a8]
	cmp     r1, #0x0
	bxge    r14
	ldr     r1, [r0, #0x3b4]
	ldr     r2, [r0, #0x60]
	sub     r1, r1, #0x12c000
	cmp     r2, r1
	bxge    r14
	mov     r2, #0x0
	str     r2, [r0, #0x64]
	ldr     r1, [r0, #0x64]
	str     r1, [r0, #0x5c]
	ldr     r1, [r0, #0x3b4]
	add     r1, r1, #0x7d0000
	str     r1, [r0, #0x60]
	str     r2, [r0, #0x0a8]
	str     r2, [r0, #0x98]
	bx      r14
.ltorg)");

asm(R"(
FUN_02115060:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r1, [r4, #0x415]
	cmp     r1, #0x0
	bne     LAB_021150a8
	ldrb    r1, [r4, #0x416]
	cmp     r1, #0x0
	bne     LAB_02115088
	bl      FUN_021150d0
	b       LAB_0211508c
LAB_02115088:
	bl      FUN_021150c4
LAB_0211508c:
	ldr     r0, =#0x415
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_021150a8:
	mov     r0, #0x0
	strb    r0, [r4, #0x415]
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021150c4:
	mov     r1, #0x0d
	str     r1, [r0, #0x40c]
	bx      r14
.ltorg)");

asm(R"(
FUN_021150d0:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, [r4, #0x418]
	ands    r1, r1, #0x2
	beq     LAB_021151b8
	bl      _ZN5Actor13DistToCPlayerEv
	cmp     r0, #0x3e8000
	bge     LAB_02115178
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x4
	movcc   r0, #0x9
	strcc   r0, [r4, #0x40c]
	bcc     LAB_0211515c
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x8
	movcc   r0, #0x8
	strcc   r0, [r4, #0x40c]
	movcs   r0, #0x0f
	strcs   r0, [r4, #0x40c]
LAB_0211515c:
	add     r0, r4, #0x400
	mov     r1, #0x0
	strh    r1, [r0]
	mov     r0, #0x1000
	str     r0, [r4, #0x3f8]
	pop     { r4, r14 }
	bx      r14
LAB_02115178:
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x5
	movcc   r0, #0x0d
	strcc   r0, [r4, #0x40c]
	movcs   r0, #0x7
	strcs   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
LAB_021151b8:
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021151d4:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r1, [r4, #0x415]
	cmp     r1, #0x0
	bne     LAB_021152e4
	ldr     r1, [r4, #0x418]
	ands    r1, r1, #0x2
	beq     LAB_021152c0
	bl      _ZN5Actor13DistToCPlayerEv
	ldr     r1, =#0x514000
	cmp     r0, r1
	bge     LAB_0211526c
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r12, r3, r1
	ldr     r2, =#0x0a
	mov     r12, r12, lsr #0x3
	umull   r0, r1, r2, r12
	ldrb    r1, [r4, #0x42a]
	sub     r12, r3, r0
	cmp     r12, r1
	bcs     LAB_02115258
	mov     r0, #0x10
	str     r0, [r4, #0x40c]
	ldrb    r0, [r4, #0x42a]
	cmp     r0, #0x3
	movhi   r0, #0x3
	strhib  r0, [r4, #0x42a]
	movls   r0, #0x1
	strlsb  r0, [r4, #0x42a]
	b       LAB_021152c8
LAB_02115258:
	mov     r0, #0x9
	str     r0, [r4, #0x40c]
	mov     r0, #0x5
	strb    r0, [r4, #0x42a]
	b       LAB_021152c8
LAB_0211526c:
	mov     r0, #0x7
	str     r0, [r4, #0x40c]
	ldr     r1, [r4, #0x3f4]
	cmp     r1, #0x1f4000
	ble     LAB_021152c8
	ldr     r0, =#0x5dc000
	cmp     r1, r0
	bge     LAB_021152c8
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	sub     r1, r3, r0
	cmp     r1, #0x5
	movcc   r0, #0x0d
	strcc   r0, [r4, #0x40c]
	b       LAB_021152c8
LAB_021152c0:
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
LAB_021152c8:
	ldr     r0, =#0x415
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_021152e4:
	mov     r0, #0x0
	strb    r0, [r4, #0x415]
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115314:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r0, [r4, #0x415]
	cmp     r0, #0x0
	bne     LAB_02115380
	ldr     r0, [r4, #0x418]
	ands    r0, r0, #0x2
	beq     LAB_02115354
	ldr     r1, [r4, #0x3ec]
	ldr     r0, =#0x5dc000
	cmp     r1, r0
	movlt   r0, #0x0f
	strlt   r0, [r4, #0x40c]
	movge   r0, #0x11
	strge   r0, [r4, #0x40c]
	b       LAB_0211535c
LAB_02115354:
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
LAB_0211535c:
	ldr     r0, =#0x415
	mov     r1, #0x1000
	add     r2, r4, r0
	ldrb    r0, [r2]
	add     r0, r0, #0x1
	strb    r0, [r2]
	str     r1, [r4, #0x3f8]
	pop     { r4, r14 }
	bx      r14
LAB_02115380:
	mov     r1, #0x0
	strb    r1, [r4, #0x415]
	ldrb    r0, [r4, #0x429]
	cmp     r0, #0x0
	bne     LAB_021153d0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	ldr     r1, =#0x0cccccccd
	mov     r3, r0, lsr #0x10
	umull   r0, r1, r3, r1
	ldr     r2, =#0x0a
	mov     r1, r1, lsr #0x3
	umull   r0, r1, r2, r1
	subs    r1, r3, r0
	moveq   r0, #0x3
	streq   r0, [r4, #0x40c]
	movne   r0, #0x0e
	strne   r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
LAB_021153d0:
	strb    r1, [r4, #0x429]
	mov     r0, #0x0e
	str     r0, [r4, #0x40c]
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021153f8:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_02111f08
	ldrb    r0, [r4, #0x423]
	cmp     r0, #0x0
	bne     LAB_02115440
	mov     r0, r4
	bl      FUN_02115744
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_02115440:
	cmp     r0, #0x2
	bhi     LAB_0211548c
	mov     r0, r4
	bl      FUN_02115718
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	ldrb    r0, [r4, #0x414]
	cmp     r0, #0x2
	ldreqb  r0, [r1]
	addeq   r0, r0, #0x1
	streqb  r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_0211548c:
	cmp     r0, #0x3
	bne     LAB_021154d4
	mov     r0, r4
	bl      FUN_021156ec
	cmp     r0, #0x0
	popeq   { r4, r14 }
	bxeq    r14
	mov     r0, r4
	mov     r1, #0x10
	mov     r2, #0x0
	bl      FUN_02111cc0
	ldr     r0, =#0x423
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4, r14 }
	bx      r14
LAB_021154d4:
	mov     r0, r4
	bl      FUN_02115518
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021154e8:
	push    { r4, r14 }
	mov     r4, r0
	bl      FUN_02111f08
	mov     r2, #0x0
	mov     r0, r4
	mov     r1, #0x10
	str     r2, [r4, #0x98]
	bl      FUN_02111cc0
	mov     r0, r4
	bl      FUN_02115518
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115518:
	push    { r4-r8, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldr     r0, [r4, #0x3a0]
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4-r8, r14 }
	bxeq    r14
	ldrb    r1, [r4, #0x424]
	cmp     r1, #0x0
	beq     LAB_02115560
	cmp     r1, #0x1
	beq     LAB_021155a4
	cmp     r1, #0x2
	beq     LAB_02115680
	add     r13, r13, #0x18
	pop     { r4-r8, r14 }
	bx      r14
LAB_02115560:
	mov     r1, r4
	mov     r2, #0x1
	bl      _ZN6Player9StartTalkER9ActorBaseb
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4-r8, r14 }
	bxeq    r14
	ldr     r0, =#0x424
	mov     r1, #0x6
	str     r1, [r4, #0x40c]
	add     r1, r4, r0
	ldrb    r0, [r1]
	add     r13, r13, #0x18
	add     r0, r0, #0x1
	strb    r0, [r1]
	pop     { r4-r8, r14 }
	bx      r14
LAB_021155a4:
	bl      _ZN6Player12GetTalkStateEv
	cmp     r0, #0x0
	addne   r13, r13, #0x18
	popne   { r4-r8, r14 }
	bxne    r14
	ldr     r12, [r4, #0x5c]
	ldr     r0, =SINE_TABLE
	str     r12, [r13, #0x8]
	ldr     r1, [r4, #0x60]
	mov     r14, #0x0c8
	str     r1, [r13, #0x0c]
	ldr     r2, [r4, #0x64]
	add     r7, r1, #0x0c8000
	str     r2, [r13, #0x10]
	ldrh    r1, [r4, #0x8e]
	mov     r6, #0x0
	ldr     r5, =MESSAGE_IDS
	mov     r1, r1, asr #0x4
	mov     r1, r1, lsl #0x2
	ldrsh   r8, [r0, r1]
	add     r3, r13, #0x8
	mov     r1, r4
	smlabb  r8, r8, r14, r12
	str     r8, [r13, #0x8]
	ldrh    r12, [r4, #0x8e]
	mov     r12, r12, asr #0x4
	mov     r12, r12, lsl #0x1
	add     r12, r12, #0x1
	mov     r12, r12, lsl #0x1
	ldrsh   r0, [r0, r12]
	str     r7, [r13, #0x0c]
	smlabb  r0, r0, r14, r2
	str     r0, [r13, #0x10]
	str     r6, [r13]
	str     r6, [r13, #0x4]
	ldrb    r2, [r4, #0x414]
	ldr     r0, [r4, #0x3a0]
	mov     r2, r2, lsl #0x1
	ldrsh   r2, [r5, r2]
	bl      _ZN6Player11ShowMessageER9ActorBasejRK7Vector3jj
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	popeq   { r4-r8, r14 }
	bxeq    r14
	ldr     r0, =#0x424
	add     r1, r4, #0x74
	add     r3, r4, r0
	ldrb    r2, [r3]
	mov     r0, #0x0b7
	add     r2, r2, #0x1
	strb    r2, [r3]
	bl      0x02012694
	add     r13, r13, #0x18
	pop     { r4-r8, r14 }
	bx      r14
LAB_02115680:
	bl      _ZN6Player12GetTalkStateEv
	mvn     r1, #0x0
	cmp     r0, r1
	addne   r13, r13, #0x18
	popne   { r4-r8, r14 }
	bxne    r14
	ldrb    r0, [r4, #0x414]
	ldr     r1, =#0x424
	cmp     r0, #0x1
	moveq   r0, #0x0d
	streq   r0, [r4, #0x40c]
	movne   r0, #0x0
	strne   r0, [r4, #0x40c]
	add     r3, r4, r1
	ldrb    r2, [r3]
	mov     r0, r4
	mov     r1, #0x4
	add     r2, r2, #0x1
	strb    r2, [r3]
	strb    r1, [r4, #0x444]
	bl      FUN_02111f08
	add     r13, r13, #0x18
	pop     { r4-r8, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021156ec:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x12
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r1, #0x0
	mov     r0, r4
	str     r1, [r4, #0x98]
	bl      FUN_02115a30
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115718:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x11
	mov     r2, #0x0
	bl      FUN_02111cc0
	mov     r1, #0x3000
	mov     r0, r4
	str     r1, [r4, #0x98]
	bl      FUN_02115a30
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115744:
	push    { r4, r14 }
	mov     r4, r0
	mov     r1, #0x13
	mov     r2, #0x40000000
	bl      FUN_02111cc0
	mov     r0, r4
	bl      FUN_02115a30
	cmp     r0, #0x0
	movne   r0, #0x3000
	strne   r0, [r4, #0x98]
	movne   r0, #0x1
	moveq   r0, #0x0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_0211577c:
	push    { r4-r7, r14 }
	sub     r13, r13, #0x0ac
	mov     r4, r0
	add     r0, r4, #0x14c
	bl      _ZNK12WithMeshClsn10IsOnGroundEv
	cmp     r0, #0x0
	beq     LAB_021157d8
	ldr     r0, [r4, #0x410]
	cmp     r0, #0x0
	bne     LAB_021157d8
	ldrsh   r2, [r4, #0x8e]
	mov     r0, r4
	add     r1, r4, #0x3bc
	bl      0x02010844
	strh    r0, [r4, #0x8c]
	ldrsh   r2, [r4, #0x8e]
	mov     r0, r4
	add     r1, r4, #0x3bc
	sub     r2, r2, #0x4000
	mov     r2, r2, lsl #0x10
	mov     r2, r2, asr #0x10
	bl      0x02010844
	strh    r0, [r4, #0x90]
LAB_021157d8:
	add     r0, r13, #0x44
	add     r1, r4, #0x5c
	mov     r2, #0x3
	bl      Vec3_Asr
	ldr     r1, [r13, #0x44]
	ldr     r2, [r13, #0x48]
	ldr     r3, [r13, #0x4c]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldrsh   r1, [r4, #0x8e]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationY
	ldrsh   r1, [r4, #0x8c]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationX
	ldrsh   r1, [r4, #0x90]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_ApplyInPlaceToRotationZ
	ldr     r6, =MATRIX_SCRATCH_PAPER
	add     r5, r4, #0x0f0
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6!, { r0-r3 }
	stmia   r5!, { r0-r3 }
	ldmia   r6, { r0-r3 }
	stmia   r5, { r0-r3 }
	ldrb    r1, [r4, #0x41c]
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mov     r1, r1, asr #0x3
	and     r1, r1, #0x0ff
	bl      _ZN9ModelBase12ApplyOpacityEj
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r13, #0x8
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	mov     r5, #0x0
	str     r5, [r4, #0x3e0]
	str     r5, [r4, #0x3e4]
	str     r5, [r4, #0x3e8]
	ldr     r0, [r4, #0x0e8]
	ldr     r1, =MATRIX_SCRATCH_PAPER
	add     r0, r0, #0x90
	mov     r2, r1
	bl      MulMat4x3Mat4x3
	ldr     r2, =MATRIX_SCRATCH_PAPER
	add     r0, r4, #0x3e0
	ldr     r3, [r2, #0x24]
	mov     r1, #0x3
	str     r3, [r4, #0x3e0]
	ldr     r3, [r2, #0x28]
	str     r3, [r4, #0x3e4]
	ldr     r2, [r2, #0x2c]
	str     r2, [r4, #0x3e8]
	bl      Vec3_LslInPlace
	ldr     r1, [r4, #0x60]
	mov     r0, r5
	str     r1, [r4, #0x3e4]
	str     r0, [r4, #0x3d4]
	str     r0, [r4, #0x3d8]
	ldr     r6, =MATRIX_SCRATCH_PAPER
	str     r0, [r4, #0x3dc]
	add     r7, r13, #0x8
	ldmia   r7!, { r0-r3 }
	mov     r5, r6
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	ldr     r0, [r4, #0x0e8]
	mov     r1, r5
	add     r0, r0, #0x120
	mov     r2, r5
	bl      MulMat4x3Mat4x3
	mov     r2, r5
	ldr     r3, [r2, #0x24]
	add     r0, r4, #0x3d4
	str     r3, [r4, #0x3d4]
	ldr     r3, [r2, #0x28]
	mov     r1, #0x3
	str     r3, [r4, #0x3d8]
	ldr     r2, [r2, #0x2c]
	str     r2, [r4, #0x3dc]
	bl      Vec3_LslInPlace
	ldr     r0, [r4, #0x60]
	str     r0, [r4, #0x3d8]
	ldrb    r0, [r4, #0x426]
	cmp     r0, #0x0
	addeq   r13, r13, #0x0ac
	popeq   { r4-r7, r14 }
	bxeq    r14
	add     r0, r13, #0x5c
	bl      _ZN13RaycastGroundC1Ev
	ldr     r1, [r4, #0x5c]
	add     r0, r13, #0x5c
	str     r1, [r13, #0x38]
	ldr     r2, [r4, #0x60]
	add     r1, r13, #0x38
	str     r2, [r13, #0x3c]
	ldr     r5, [r4, #0x64]
	add     r3, r2, #0x32000
	mov     r2, #0x0
	str     r5, [r13, #0x40]
	str     r3, [r13, #0x3c]
	bl      _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor
	add     r0, r13, #0x5c
	bl      _ZN13RaycastGround10DetectClsnEv
	cmp     r0, #0x0
	ldrne   r0, [r13, #0x0a0]
	add     r1, r13, #0x38
	strne   r0, [r13, #0x3c]
	ldreq   r0, [r4, #0x60]
	mov     r2, #0x3
	streq   r0, [r13, #0x3c]
	add     r0, r13, #0x50
	bl      Vec3_Asr
	ldr     r1, [r13, #0x50]
	ldr     r2, [r13, #0x54]
	ldr     r3, [r13, #0x58]
	ldr     r0, =MATRIX_SCRATCH_PAPER
	bl      Matrix4x3_FromTranslation
	ldr     r7, =MATRIX_SCRATCH_PAPER
	add     r6, r4, #0x330
	mov     r5, r6
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7!, { r0-r3 }
	stmia   r6!, { r0-r3 }
	ldmia   r7, { r0-r3 }
	stmia   r6, { r0-r3 }
	mov     r14, #0x64000
	mov     r12, #0x0f
	str     r14, [r13]
	mov     r2, r5
	mov     r0, r4
	add     r1, r4, #0x308
	mov     r3, #0x140000
	str     r12, [r13, #0x4]
	bl      _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j
	add     r0, r13, #0x5c
	bl      _ZN13RaycastGroundD1Ev
	add     r13, r13, #0x0ac
	pop     { r4-r7, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115a30:
	push    { r4, r14 }
	mov     r4, r0
	add     r0, r4, #0x124
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	bne     LAB_02115a6c
	add     r0, r4, #0x124
	bl      _ZNK9Animation13GetFrameCountEv
	sub     r0, r0, #0x1
	mov     r1, r0, lsl #0x10
	add     r0, r4, #0x124
	mov     r1, r1, lsr #0x10
	bl      _ZNK9Animation12WillHitFrameEi
	cmp     r0, #0x0
	beq     LAB_02115a78
LAB_02115a6c:
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
LAB_02115a78:
	mov     r0, #0x0
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115a84:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x0c
	mov     r4, r0
	add     r0, r4, #0x14c
	mov     r5, r1
	bl      _ZNK12WithMeshClsn13JustHitGroundEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x0c
	popeq   { r4, r5, r14 }
	bxeq    r14
	ldrh    r0, [r5]
	add     r0, r0, #0x1
	strh    r0, [r5]
	ldrh    r0, [r5]
	cmp     r0, #0x4
	addcs   r13, r13, #0x0c
	popcs   { r4, r5, r14 }
	bxcs    r14
	ldr     r0, [r4, #0x5c]
	add     r1, r13, #0x0
	str     r0, [r13]
	ldr     r2, [r4, #0x60]
	mov     r0, r4
	str     r2, [r13, #0x4]
	ldr     r3, [r4, #0x64]
	mov     r2, #0x0
	str     r3, [r13, #0x8]
	bl      _ZN5Actor13LandingDustAtER7Vector3b
	add     r1, r4, #0x74
	mov     r0, #0x0bd
	bl      0x02012694
	add     r13, r13, #0x0c
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115b0c:
	push    { r4, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldrb    r1, [r4, #0x414]
	cmp     r1, #0x2
	addne   r13, r13, #0x18
	popne   { r4, r14 }
	bxne    r14
	ldr     r2, [r4, #0x5c]
	add     r1, r13, #0x8
	str     r2, [r13, #0x8]
	ldr     r3, [r4, #0x60]
	mov     r2, #0x7d0000
	str     r3, [r13, #0x0c]
	ldr     r3, [r4, #0x64]
	str     r3, [r13, #0x10]
	bl      _ZN5Actor10EarthquakeERK7Vector35Fix12IiE
	ldrsb   r2, [r4, #0x0cc]
	mov     r1, #0x0
	ldr     r0, =#0x119
	str     r2, [r13]
	mvn     r12, #0x0
	mov     r3, r1
	add     r2, r4, #0x5c
	str     r12, [r13, #0x4]
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	add     r13, r13, #0x18
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115b84:
	push    { r4-r6, r14 }
	mov     r6, r0
	ldr     r0, [r6, #0x108]
	bl      _ZN5Actor10FindWithIDEj
	ldr     r4, [r6, #0x110]
	ldr     r1, =tailStates
	mov     r5, r0
	add     r3, r1, r4, lsl #0x3
	ldr     r1, [r3, #0x4]
	add     r0, r6, r1, asr #0x1
	ands    r1, r1, #0x1
	ldrne   r2, [r0]
	ldrne   r1, [r3]
	ldrne   r1, [r2, r1]
	ldreq   r1, [r3]
	blx     r1
	ldr     r0, [r5, #0x40c]
	cmp     r0, #0x4
	addeq   r1, r6, #0x0ec
	ldreq   r0, [r1]
	orreq   r0, r0, #0x1
	streq   r0, [r1]
	add     r1, r6, #0x114
	ldrh    r0, [r1]
	add     r0, r0, #0x1
	strh    r0, [r1]
	ldr     r0, [r6, #0x110]
	cmp     r4, r0
	addne   r0, r6, #0x100
	movne   r1, #0x0
	strneh  r1, [r0, #0x14]
	add     r0, r6, #0x0d4
	bl      _ZN12CylinderClsn5ClearEv
	add     r0, r6, #0x0d4
	bl      _ZN12CylinderClsn6UpdateEv
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115c1c:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	mov     r5, r0
	ldr     r0, [r5, #0x108]
	bl      _ZN5Actor10FindWithIDEj
	mov     r4, r0
	ldr     r1, [r4, #0x40c]
	cmp     r1, #0x13
	bne     LAB_02115c50
	mov     r1, #0x1
	bl      FUN_021123a0
	mov     r0, #0x0
	str     r0, [r5, #0x110]
LAB_02115c50:
	ldr     r0, [r5, #0x0b0]
	ands    r0, r0, #0x400
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02115c94
	mov     r1, #0x1
	str     r1, [r5, #0x110]
	mov     r1, #0x0
	mov     r0, r4
	str     r1, [r5, #0x10c]
	bl      FUN_021123c8
	mov     r0, #0x2
	add     r13, r13, #0x4
	str     r0, [r4, #0x410]
	pop     { r4, r5, r14 }
	bx      r14
LAB_02115c94:
	ldr     r1, [r5, #0x10c]
	cmp     r1, #0x0
	beq     LAB_02115d30
	ldr     r0, [r1, #0x358]
	cmp     r0, #0x0
	movne   r0, #0x1
	moveq   r0, #0x0
	cmp     r0, #0x0
	beq     LAB_02115cf8
	add     r0, r1, #0x600
	ldrsh   r0, [r0, #0x9c]
	cmp     r0, #0x0
	bne     LAB_02115d24
	add     r1, r5, #0x100
	ldrh    r0, [r1, #0x16]
	cmp     r0, #0x0
	beq     LAB_02115d30
	ldr     r0, =#0x116
	add     r2, r5, r0
	ldrh    r0, [r2]
	sub     r0, r0, #0x1
	strh    r0, [r2]
	ldrh    r0, [r1, #0x16]
	cmp     r0, #0x0
	bne     LAB_02115d30
LAB_02115cf8:
	mov     r0, #0x1
	str     r0, [r5, #0x110]
	ldr     r0, [r5, #0x10c]
	bl      0x020da7f4
	mov     r1, #0x0
	mov     r0, r4
	str     r1, [r5, #0x10c]
	bl      FUN_021123c8
	mov     r0, #0x3
	str     r0, [r4, #0x410]
	b       LAB_02115d30
LAB_02115d24:
	add     r0, r5, #0x100
	mov     r1, #0x96
	strh    r1, [r0, #0x16]
LAB_02115d30:
	add     r1, r5, #0x0ec
	ldr     r0, [r1]
	orr     r0, r0, #0x1
	str     r0, [r1]
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115d50:
	add     r1, r0, #0x100
	ldrh    r1, [r1, #0x14]
	cmp     r1, #0x1e
	movhi   r1, #0x0
	strhi   r1, [r0, #0x110]
	bx      r14
.ltorg)");

asm(R"(
FUN_02115d68:
	push    { r4-r6, r14 }
	mov     r6, r0
	ldr     r0, [r6, #0x108]
	bl      _ZN5Actor10FindWithIDEj
	add     r2, r6, #0x0ec
	ldr     r1, [r2]
	mov     r5, r0
	bic     r1, r1, #0x1
	str     r1, [r2]
	ldr     r1, [r5, #0x40c]
	cmp     r1, #0x13
	bne     LAB_02115da8
	mov     r1, #0x1
	bl      FUN_021123a0
	pop     { r4-r6, r14 }
	bx      r14
LAB_02115da8:
	cmp     r1, #0x4
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r1, #0x1
	bl      FUN_021123a0
	ldr     r0, [r6, #0x0f8]
	cmp     r0, #0x0
	popeq   { r4-r6, r14 }
	bxeq    r14
	ldr     r1, [r6, #0x0f4]
	ands    r1, r1, #0x1000
	popeq   { r4-r6, r14 }
	bxeq    r14
	bl      _ZN5Actor10FindWithIDEj
	movs    r4, r0
	popeq   { r4-r6, r14 }
	bxeq    r14
	bl      _ZN6Player15IsCollectingCapEv
	cmp     r0, #0x0
	popne   { r4-r6, r14 }
	bxne    r14
	mov     r0, r4
	mov     r1, r6
	bl      0x020daba0
	cmp     r0, #0x0
	popeq   { r4-r6, r14 }
	bxeq    r14
	add     r12, r5, #0x8c
	ldrsh   r1, [r12]
	mov     r2, #0x2
	mov     r0, r5
	strh    r1, [r4, #0x8c]
	ldrsh   r3, [r12, #0x2]
	mov     r1, #0x0
	strh    r3, [r4, #0x8e]
	ldrsh   r3, [r12, #0x4]
	strh    r3, [r4, #0x90]
	ldrsh   r3, [r12]
	strh    r3, [r4, #0x92]
	ldrsh   r3, [r12, #0x2]
	strh    r3, [r4, #0x94]
	ldrsh   r3, [r12, #0x4]
	strh    r3, [r4, #0x96]
	str     r2, [r6, #0x110]
	str     r4, [r6, #0x10c]
	bl      FUN_021123a0
	mov     r0, #0x1
	str     r0, [r5, #0x410]
	str     r4, [r5, #0x3a4]
	add     r0, r6, #0x100
	mov     r1, #0x96
	strh    r1, [r0, #0x16]
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115e80:
	push    { r4, r5, r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN6Bowser9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r5, #0x0
	ldr     r4, =ANIM_FILE_PTRS
LAB_02115e98:
	ldr     r0, [r4, r5, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	add     r5, r5, #0x1
	cmp     r5, #0x1c
	blt     LAB_02115e98
	ldr     r4, =TEX_SEQ_FILE_PTRS
	mov     r5, #0x0
LAB_02115eb4:
	ldr     r0, [r4, r5, lsl #0x2]
	bl      _ZN13SharedFilePtr7ReleaseEv
	add     r5, r5, #0x1
	cmp     r5, #0x6
	blt     LAB_02115eb4
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =#0x2132c50
	bl      _ZN13SharedFilePtr7ReleaseEv
	bl      0x02011cfc
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r4, r5, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115f00:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02115f08:
	bx      r14
.ltorg)");

asm(R"(
FUN_02115f0c:
	push    { r4, r14 }
	mov     r4, r0
	ldrb    r0, [r4, #0x41c]
	cmp     r0, #0x8
	movcc   r0, #0x1
	popcc   { r4, r14 }
	bxcc    r14
	add     r0, r4, #0x138
	bl      _ZN9Animation7AdvanceEv
	add     r0, r4, #0x138
	add     r1, r4, #0x0dc
	bl      _ZN15TextureSequence6UpdateER15ModelComponents
	add     r0, r4, #0x0d4
	ldr     r2, [r0]
	add     r1, r4, #0x80
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r0, #0x1
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02115f5c:
	mov     r0, #0x1
	bx      r14
.ltorg)");

asm(R"(
FUN_02115f64:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldr     r0, =RNG_STATE
	bl      RandomIntInternal
	mov     r0, r4
	bl      _ZN5Actor13ClosestPlayerEv
	str     r0, [r4, #0x3a0]
	ldr     r1, [r4, #0x3a0]
	cmp     r1, #0x0
	ldreqsh r2, [r4, #0x8e]
	addeq   r0, r4, #0x400
	mvneq   r1, #0x80000000
	streqh  r2, [r0, #0x6]
	streq   r1, [r4, #0x3ec]
	beq     LAB_02115fcc
	add     r0, r4, #0x5c
	add     r1, r1, #0x5c
	bl      Vec3_HorzAngle
	add     r1, r4, #0x400
	strh    r0, [r1, #0x6]
	ldr     r1, [r4, #0x3a0]
	add     r0, r4, #0x5c
	add     r1, r1, #0x5c
	bl      Vec3_HorzDist
	str     r0, [r4, #0x3ec]
LAB_02115fcc:
	mov     r0, r4
	bl      FUN_02112434
	mov     r0, r4
	bl      FUN_02111a28
	ldrsh   r1, [r4, #0x8e]
	add     r0, r4, #0x124
	strh    r1, [r4, #0x94]
	ldr     r1, [r4, #0x3f8]
	str     r1, [r4, #0x130]
	bl      _ZN9Animation7AdvanceEv
	mov     r0, r4
	bl      FUN_0211577c
	ldr     r1, =CAMERA
	add     r0, r4, #0x360
	ldr     r1, [r1]
	str     r4, [r1, #0x114]
	bl      _ZN12CylinderClsn5ClearEv
	mov     r2, #0x0
	mov     r0, #0x50000
	str     r0, [r13, #0x8]
	add     r1, r13, #0x0
	add     r0, r4, #0x360
	str     r2, [r13]
	str     r2, [r13, #0x4]
	bl      _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3
	add     r0, r4, #0x360
	bl      _ZN12CylinderClsn6UpdateEv
	ldrb    r0, [r4, #0x42b]
	cmp     r0, #0x0
	beq     LAB_0211605c
	ldr     r0, =#0x10d
	mov     r1, #0x0
	bl      _ZN5Actor15FindWithActorIDEjPS_
	cmp     r0, #0x0
	moveq   r0, #0x0
	streqb  r0, [r4, #0x42b]
LAB_0211605c:
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116078:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	ldr     r0, [r4, #0x108]
	bl      _ZN5Actor10FindWithIDEj
	cmp     r0, #0x0
	addeq   r13, r13, #0x10
	moveq   r0, #0x1
	popeq   { r4, r14 }
	bxeq    r14
	ldrsh   r1, [r0, #0x94]
	add     r14, r0, #0x5c
	ldr     r0, [r14]
	add     r1, r1, #0x8000
	mov     r1, r1, lsl #0x10
	mov     r1, r1, asr #0x10
	mov     r1, r1, lsl #0x10
	mov     r1, r1, lsr #0x10
	mov     r1, r1, asr #0x4
	mov     r2, r1, lsl #0x1
	str     r0, [r13]
	ldr     r3, [r14, #0x4]
	ldr     r12, =SINE_TABLE
	mov     r1, r2, lsl #0x1
	str     r3, [r13, #0x4]
	ldr     r14, [r14, #0x8]
	ldrsh   r3, [r12, r1]
	mov     r1, #0x8c
	add     r2, r2, #0x1
	smlabb  r0, r3, r1, r0
	str     r14, [r13, #0x8]
	str     r0, [r4, #0x5c]
	ldr     r3, [r13, #0x4]
	mov     r0, r2, lsl #0x1
	str     r3, [r4, #0x60]
	ldrsh   r2, [r12, r0]
	ldr     r3, [r13, #0x8]
	mov     r0, r4
	smlabb  r1, r2, r1, r3
	str     r1, [r4, #0x64]
	bl      FUN_02115b84
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116130:
	push    { r4-r6, r14 }
	sub     r13, r13, #0x18
	mov     r4, r0
	ldr     r0, =_ZN6Bowser9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mov     r3, #0x16
	bl      _ZN9ModelBase7SetFileEP8BMD_Fileii
	mov     r6, #0x0
	ldr     r5, =ANIM_FILE_PTRS
LAB_02116160:
	ldr     r0, [r5, r6, lsl #0x2]
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	add     r6, r6, #0x1
	cmp     r6, #0x1c
	blt     LAB_02116160
	ldr     r5, =TEX_SEQ_FILE_PTRS
	mov     r6, #0x0
LAB_0211617c:
	ldr     r0, [r5, r6, lsl #0x2]
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	add     r6, r6, #0x1
	cmp     r6, #0x6
	blt     LAB_0211617c
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	ldr     r0, =#0x2132c50
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	add     r0, r4, #0x308
	bl      _ZN11ShadowModel12InitCylinderEv
	cmp     r0, #0x0
	addeq   r13, r13, #0x18
	moveq   r0, #0x0
	popeq   { r4-r6, r14 }
	bxeq    r14
	mov     r0, r4
	mov     r1, #0x10
	mov     r2, #0x0
	bl      FUN_02111cc0
	ldr     r0, =_ZN6Bowser9modelFileE
	ldr     r1, =_ZN6Bowser11texSeqFilesE + 0x20
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareER8BMD_FileR8BTP_File
	mov     r2, #0x0
	ldr     r0, =_ZN6Bowser11texSeqFilesE + 0x20
	str     r2, [r13]
	ldr     r1, [r0, #0x4]
	add     r0, r4, #0x138
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj
	add     r0, r4, #0x138
	mov     r1, #0x40000000
	bl      _ZN9Animation8SetFlagsEi
	mov     r2, #0x0
	str     r2, [r13, #0x0c]
	str     r2, [r13, #0x10]
	str     r2, [r13, #0x14]
	mov     r0, #0x118000
	str     r0, [r13]
	ldr     r1, =#0x200004
	add     r0, r4, #0x360
	str     r1, [r13, #0x4]
	str     r2, [r13, #0x8]
	mov     r1, r4
	add     r2, r13, #0x0c
	mov     r3, #0x78000
	bl      _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj
	ldr     r1, [r4, #0x5c]
	mov     r0, #0x2000
	str     r1, [r4, #0x3b0]
	ldr     r1, [r4, #0x60]
	rsb     r2, r0, #0x0
	str     r1, [r4, #0x3b4]
	ldr     r3, [r4, #0x64]
	mov     r0, #0x3c000
	str     r3, [r4, #0x3b8]
	rsb     r1, r0, #0x0
	str     r2, [r4, #0x9c]
	str     r1, [r4, #0x0a0]
	mov     r0, #0x0
	str     r0, [r4, #0x3a0]
	str     r0, [r13]
	mov     r2, #0x50000
	str     r0, [r13, #0x4]
	add     r0, r4, #0x14c
	mov     r1, r4
	mov     r3, r2
	bl      _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_
	add     r0, r4, #0x14c
	bl      _ZN12WithMeshClsn13SetLimMovFlagEv
	mov     r3, #0x0
	str     r3, [r4, #0x40c]
	ldr     r1, [r4, #0x8]
	add     r0, r4, #0x300
	and     r1, r1, #0x3
	strb    r1, [r4, #0x414]
	ldr     r2, [r4, #0x8]
	mov     r1, #0x1
	mov     r2, r2, lsr #0x2
	and     r2, r2, #0x1
	strb    r2, [r4, #0x416]
	strh    r3, [r0, #0x0fc]
	strb    r3, [r4, #0x423]
	strb    r1, [r4, #0x426]
	strb    r3, [r4, #0x427]
	mov     r0, #0x1000
	str     r0, [r4, #0x80]
	str     r0, [r4, #0x84]
	str     r0, [r4, #0x88]
	str     r0, [r4, #0x3f8]
	mov     r0, r4
	strb    r1, [r4, #0x429]
	bl      FUN_021123dc
	mov     r1, #0x0
	strb    r1, [r4, #0x424]
	strb    r1, [r4, #0x444]
	ldrsb   r3, [r4, #0x0cc]
	mvn     r2, #0x0
	mov     r0, #0x118
	str     r3, [r13]
	str     r2, [r13, #0x4]
	add     r2, r4, #0x5c
	mov     r3, r1
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	ldr     r1, [r4, #0x4]
	mvn     r2, #0x0
	str     r1, [r0, #0x2cc]
	ldrsb   r3, [r4, #0x0cc]
	ldr     r0, =#0x116
	mov     r1, #0x0
	str     r3, [r13]
	str     r2, [r13, #0x4]
	add     r2, r4, #0x5c
	mov     r3, r1
	bl      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii
	ldr     r1, [r0, #0x4]
	mov     r2, #0x5
	str     r1, [r4, #0x3a8]
	ldr     r3, [r4, #0x4]
	mov     r1, #0x0
	str     r3, [r0, #0x108]
	strb    r2, [r4, #0x42a]
	strb    r1, [r4, #0x42b]
	str     r1, [r4, #0x448]
	strb    r1, [r4, #0x446]
	str     r1, [r4, #0x44c]
	str     r1, [r4, #0x450]
	bl      0x02011d50
	mov     r0, #0x1
	add     r13, r13, #0x18
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021163b4:
	push    { r14 }
	sub     r13, r13, #0x0c
	mov     r1, r0
	mov     r0, #0x800000
	str     r0, [r13]
	mov     r12, #0x1000
	add     r0, r1, #0x0d4
	mov     r2, #0x32000
	mov     r3, #0x50000
	str     r12, [r13, #0x4]
	bl      _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj
	mov     r0, #0x1
	add     r13, r13, #0x0c
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021163f0:
	push    { r4, r14 }
	mov     r0, #0x118
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02116418
	bl      _ZN5ActorC2Ev
	ldr     r1, =VTable_BowserTail
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN18MovingCylinderClsnC1Ev
LAB_02116418:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02116428:
	push    { r4, r14 }
	ldr     r0, =#0x454
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02116470
	bl      _ZN5ActorC2Ev
	ldr     r1, =VTable_Bowser
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x138
	bl      _ZN15TextureSequenceC1Ev
	add     r0, r4, #0x14c
	bl      _ZN12WithMeshClsnC1Ev
	add     r0, r4, #0x308
	bl      _ZN11ShadowModelC1Ev
	add     r0, r4, #0x360
	bl      _ZN25MovingCylinderClsnWithPosC1Ev
LAB_02116470:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");