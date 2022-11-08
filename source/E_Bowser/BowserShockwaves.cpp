#include "BowserShockwaves.h"

extern "C"
{
	ActorBase* FUN_021191f4(); // constructor
	
	// undocumented globals not in ov60:
	// 0x021115e4 (ov48, .bma file)
	// 0x021115f4 (ov48, .bta file)
	
	Fix12i UNK_0211ab20[4] = { 0x787_f, 0x800_f, 0xf0f_f, 0x1000_f }; // 0x0211ab20
}

SharedFilePtr BowserShockwaves::modelFile;
SharedFilePtr BowserShockwaves::texSeqFile;
SharedFilePtr BowserShockwaves::animFile;

SpawnInfo BowserShockwaves::spawnData = 
{
	&FUN_021191f4,
	0x0119,
	0x0094,
	0x00000000,
	0x00064000_f,
	0x00064000_f,
	0x01000000_f,
	0x01000000_f,
};

asm(R"(
@ 0x0211ab54
VTable_BowserShockwaves:
	.word FUN_02119004
	.word _ZN5Actor19BeforeInitResourcesEv
	.word _ZN5Actor18AfterInitResourcesEj
	.word FUN_02118de0
	.word _ZN5Actor22BeforeCleanupResourcesEv
	.word _ZN5Actor21AfterCleanupResourcesEj
	.word FUN_02118eb8
	.word _ZN5Actor14BeforeBehaviorEv
	.word _ZN5Actor13AfterBehaviorEj
	.word FUN_02118e1c
	.word _ZN5Actor12BeforeRenderEv
	.word _ZN5Actor11AfterRenderEj
	.word _ZN9ActorBase16OnPendingDestroyEv
	.word _ZN9ActorBase9Virtual34Ejj
	.word _ZN9ActorBase9Virtual38Ejj
	.word _ZN9ActorBase13OnHeapCreatedEv
	.word FUN_02118cfc
	.word FUN_02118d64
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
FUN_02118cfc:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserShockwaves
	add     r0, r4, #0x200
	str     r1, [r4]
	bl      _ZN18TextureTransformerD1Ev
	add     r0, r4, #0x1ec
	bl      _ZN15MaterialChangerD1Ev
	add     r0, r4, #0x1d8
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x174
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x160
	bl      _ZN18TextureTransformerD1Ev
	add     r0, r4, #0x14c
	bl      _ZN15MaterialChangerD1Ev
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
FUN_02118d64:
	push    { r4, r14 }
	mov     r4, r0
	ldr     r1, =VTable_BowserShockwaves
	add     r0, r4, #0x200
	str     r1, [r4]
	bl      _ZN18TextureTransformerD1Ev
	add     r0, r4, #0x1ec
	bl      _ZN15MaterialChangerD1Ev
	add     r0, r4, #0x1d8
	bl      _ZN15TextureSequenceD1Ev
	add     r0, r4, #0x174
	bl      _ZN9ModelAnimD1Ev
	add     r0, r4, #0x160
	bl      _ZN18TextureTransformerD1Ev
	add     r0, r4, #0x14c
	bl      _ZN15MaterialChangerD1Ev
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
FUN_02118de0:
	push    { r14 }
	sub     r13, r13, #0x4
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN16BowserShockwaves8animFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	ldr     r0, =_ZN16BowserShockwaves10texSeqFileE
	bl      _ZN13SharedFilePtr7ReleaseEv
	mov     r0, #0x1
	add     r13, r13, #0x4
	pop     { r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118e1c:
	push    { r4, r14 }
	sub     r13, r13, #0x10
	mov     r4, r0
	add     r0, r4, #0x138
	add     r1, r4, #0x0dc
	bl      _ZN15TextureSequence6UpdateER15ModelComponents
	add     r0, r4, #0x1d8
	add     r1, r4, #0x17c
	bl      _ZN15TextureSequence6UpdateER15ModelComponents
	add     r0, r4, #0x14c
	add     r1, r4, #0x0dc
	bl      _ZN15MaterialChanger6UpdateER15ModelComponents
	add     r0, r4, #0x1ec
	add     r1, r4, #0x17c
	bl      _ZN15MaterialChanger6UpdateER15ModelComponents
	add     r0, r4, #0x160
	add     r1, r4, #0x0dc
	bl      _ZN18TextureTransformer6UpdateER15ModelComponents
	add     r0, r4, #0x200
	add     r1, r4, #0x17c
	bl      _ZN18TextureTransformer6UpdateER15ModelComponents
	add     r0, r4, #0x0d4
	ldr     r2, [r0]
	mov     r1, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r1, #0x800
	add     r0, r4, #0x174
	str     r1, [r13]
	str     r1, [r13, #0x4]
	str     r1, [r13, #0x8]
	ldr     r2, [r0]
	add     r1, r13, #0x0
	ldr     r2, [r2, #0x14]
	blx     r2
	mov     r0, #0x1
	add     r13, r13, #0x10
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02118eb8:
	push    { r4-r6, r14 }
	mov     r6, r0
	add     r2, r6, #0x214
	ldrh    r1, [r2]
	add     r1, r1, #0x1
	strh    r1, [r2]
	bl      _ZN5Actor13ClosestPlayerEv
	add     r1, r6, #0x200
	ldrh    r2, [r1, #0x14]
	mov     r1, #0x22
	movs    r5, r0
	mul     r4, r2, r1
	beq     LAB_02118f5c
	cmp     r2, #0x46
	bcs     LAB_02118f5c
	ldrb    r0, [r5, #0x6de]
	cmp     r0, #0x0
	bne     LAB_02118f5c
	add     r0, r6, #0x5c
	add     r1, r5, #0x5c
	bl      Vec3_HorzDist
	ldr     r1, =UNK_0211ab20
	ldr     r2, [r1]
	ldr     r12, [r1, #0x4]
	mul     r2, r4, r2
	ldr     r3, [r1, #0x8]
	ldr     r1, [r1, #0x0c]
	mul     r12, r4, r12
	mul     r3, r4, r3
	mul     r1, r4, r1
	cmp     r2, r0
	bge     LAB_02118f40
	cmp     r0, r12
	blt     LAB_02118f50
LAB_02118f40:
	cmp     r3, r0
	bge     LAB_02118f5c
	cmp     r0, r1
	bge     LAB_02118f5c
LAB_02118f50:
	mov     r0, r5
	mov     r1, #0x1
	bl      _ZN6Player5ShockEj
LAB_02118f5c:
	add     r0, r6, #0x138
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x1d8
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x14c
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x1ec
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x160
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x200
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x124
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x1c4
	bl      _ZN9Animation7AdvanceEv
	add     r0, r6, #0x0f0
	ldr     r1, [r6, #0x5c]
	ldr     r2, [r6, #0x60]
	mov     r1, r1, asr #0x3
	mov     r2, r2, asr #0x3
	ldr     r3, [r6, #0x64]
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	add     r0, r6, #0x190
	ldr     r1, [r6, #0x5c]
	ldr     r2, [r6, #0x60]
	mov     r1, r1, asr #0x3
	mov     r2, r2, asr #0x3
	ldr     r3, [r6, #0x64]
	mov     r3, r3, asr #0x3
	bl      Matrix4x3_FromTranslation
	add     r0, r6, #0x124
	bl      _ZN9Animation8FinishedEv
	cmp     r0, #0x0
	beq     LAB_02118ff4
	mov     r0, r6
	bl      _ZN9ActorBase18MarkForDestructionEv
LAB_02118ff4:
	mov     r0, #0x1
	pop     { r4-r6, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_02119004:
	push    { r4, r14 }
	sub     r13, r13, #0x8
	mov     r4, r0
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	bl      _ZN5Model8LoadFileER13SharedFilePtr
	mov     r1, r0
	add     r0, r4, #0x0d4
	mov     r2, #0x1
	mov     r3, #0x13
	bl      _ZN9ModelBase7SetFileEPcii
	ldr     r1, =_ZN16BowserShockwaves9modelFileE
	add     r0, r4, #0x174
	ldr     r1, [r1, #0x4]
	mov     r2, #0x1
	mov     r3, #0x13
	bl      _ZN9ModelBase7SetFileEPcii
	ldr     r0, =_ZN16BowserShockwaves8animFileE
	bl      _ZN9Animation8LoadFileER13SharedFilePtr
	ldr     r0, =_ZN16BowserShockwaves10texSeqFileE
	bl      _ZN15TextureSequence8LoadFileER13SharedFilePtr
	add     r0, r4, #0x0d4
	mov     r1, #0x4000
	bl      0x02016b24
	add     r0, r4, #0x174
	mov     r1, #0x4000
	bl      0x02016b24
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x0d4
	ldr     r1, =_ZN16BowserShockwaves8animFileE
	mov     r2, #0x40000000
	ldr     r1, [r1, #0x4]
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x174
	ldr     r1, =_ZN16BowserShockwaves8animFileE
	mov     r2, #0x40000000
	ldr     r1, [r1, #0x4]
	mov     r3, #0x1000
	bl      _ZN9ModelAnim7SetAnimEPci5Fix12IiEj
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =_ZN16BowserShockwaves10texSeqFileE
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareEPcS0_
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =_ZN16BowserShockwaves10texSeqFileE
	ldr     r0, [r0, #0x4]
	ldr     r1, [r1, #0x4]
	bl      _ZN15TextureSequence7PrepareEPcS0_
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x138
	ldr     r1, =_ZN16BowserShockwaves10texSeqFileE
	mov     r2, #0x40000000
	ldr     r1, [r1, #0x4]
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileEPci5Fix12IiEj
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x1d8
	ldr     r1, =_ZN16BowserShockwaves10texSeqFileE
	mov     r2, #0x40000000
	ldr     r1, [r1, #0x4]
	mov     r3, #0x1000
	bl      _ZN15TextureSequence7SetFileEPci5Fix12IiEj
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =#0x21115e4
	ldr     r0, [r0, #0x4]
	bl      _ZN15MaterialChanger7PrepareEPcR11MaterialDef
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =#0x21115e4
	ldr     r0, [r0, #0x4]
	bl      _ZN15MaterialChanger7PrepareEPcR11MaterialDef
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x14c
	ldr     r1, =#0x21115e4
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15MaterialChanger11SetMaterialER11MaterialDefi5Fix12IiEj
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x1ec
	ldr     r1, =#0x21115e4
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN15MaterialChanger11SetMaterialER11MaterialDefi5Fix12IiEj
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =#0x21115f4
	ldr     r0, [r0, #0x4]
	bl      _ZN18TextureTransformer7PrepareEPcR9TexSRTDef
	ldr     r0, =_ZN16BowserShockwaves9modelFileE
	ldr     r1, =#0x21115f4
	ldr     r0, [r0, #0x4]
	bl      _ZN18TextureTransformer7PrepareEPcR9TexSRTDef
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x160
	ldr     r1, =#0x21115f4
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN18TextureTransformer9SetTexSRTER9TexSRTDefi5Fix12IiEj
	mov     r0, #0x0
	str     r0, [r13]
	add     r0, r4, #0x200
	ldr     r1, =#0x21115f4
	mov     r2, #0x40000000
	mov     r3, #0x1000
	bl      _ZN18TextureTransformer9SetTexSRTER9TexSRTDefi5Fix12IiEj
	add     r0, r4, #0x200
	mov     r1, #0x0
	strh    r1, [r0, #0x14]
	mov     r0, #0x1
	add     r13, r13, #0x8
	pop     { r4, r14 }
	bx      r14
.ltorg)");

asm(R"(
FUN_021191f4:
	push    { r4, r14 }
	mov     r0, #0x218
	bl      _ZN9ActorBasenwEj
	movs    r4, r0
	beq     LAB_02119254
	bl      _ZN5ActorC2Ev
	ldr     r1, =VTable_BowserShockwaves
	add     r0, r4, #0x0d4
	str     r1, [r4]
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x138
	bl      _ZN15TextureSequenceC1Ev
	add     r0, r4, #0x14c
	bl      _ZN15MaterialChangerC1Ev
	add     r0, r4, #0x160
	bl      _ZN18TextureTransformerC1Ev
	add     r0, r4, #0x174
	bl      _ZN9ModelAnimC1Ev
	add     r0, r4, #0x1d8
	bl      _ZN15TextureSequenceC1Ev
	add     r0, r4, #0x1ec
	bl      _ZN15MaterialChangerC1Ev
	add     r0, r4, #0x200
	bl      _ZN18TextureTransformerC1Ev
LAB_02119254:
	mov     r0, r4
	pop     { r4, r14 }
	bx      r14
.ltorg)");