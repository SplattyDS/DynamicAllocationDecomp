#pragma once

struct HUD : ActorDerived
{
	u32 unk50;
	u32 unk54;
	u32 unk58;
	u32 unk5c;
	u32 unk60;
	u32 unk64;
	s16 meterYOffset;		//y-offset, counts downwards to 0x19, if 0x19 > yOffset or yOffset > 0x7FFF, then it is immediately set to 0x19
	u16 unk6a;				//unknown counter
	u16 unk6c;				//unknown counter
	u16 lifeXOffset;		//life counter xPos (default: 0x10)
	u16 starXOffset;		//star counter xPos (default: 0xF0)
	u8 unk72;				//unknown
	u8 meterState;			//health meter state (0-6: 0=stopAnim, 1=update, 2=locked?, 4=disappear), read and updated at 0x020FD218 before the branch table
	s8 currNumInDecimal[3];
	u8 unk77;
	u32 unk78;
	
	HUD();
	virtual s32	InitResources() override;
	virtual s32 CleanupResources() override;
	virtual s32 Behavior() override;
	virtual s32 Render() override;
	virtual void OnPendingDestroy() override;
	virtual ~HUD() override;
};