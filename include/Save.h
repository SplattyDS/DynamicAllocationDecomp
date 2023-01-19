#pragma once

#include "SM64DS_Common.h"

struct FileSaveData
{
	u32 magic8000;			//8000 in ASCII
	u8 keysObtained;			/*	0x01: File saved //set when file is saved
									0x02: Basement key obtained
									0x04: Upper hall key obtained		//Removes sub from DDD
									0x08: Mario key obtained
									0x10: Luigi key obtained
									0x20: Wario key obtained
									0x40: Main hall key obtained
									0x80: White key obtained	//Triggers white room star */
	u8 keysUsed;				/*	0x01: Basement key used
									0x02: Upper hall key used	//Removes sub from DDD
									0x04: Mario key used
									0x08: Luigi key used
									0x10: Wario key used
									0x20: Main hall key used
									0x40: White key used	//Disables white room star
									0x80: WF star door open	*/
	u8 starDoorState;			/*	0x01: Character star door open
									0x02: JRB star door open
									0x04: CCM star door open
									0x08: Mario star door open
									0x10: Bowser 1 door open
									0x20: Bowser 2 door open
									0x40: Clock door open
									0x80: ??? //Unused */
	u8 miscStates1;				/*	0x01: Mario lost his cap
									0x02: Luigi lost his cap
									0x04: Wario lost his cap
									0x08: ??? //Unused
									0x10: ??? //Unused
									0x20: ??? //Unused
									0x40: Minigames activated //talked to minigame toad
									0x80: Red switch activated //if not set, the shine in main hall is rendered */
	u8 characterState;			/*	0x01: Mario intro
									0x02: Luigi intro
									0x04: Wario intro
									0x08: Always set, marks started save
									0x10: ???	//Unused
									0x20: ???	//Unused
									0x40: ???	//Unused
									0x80: Character control		//Getting control of character */
	u8 textState;				/*	0x01: ??? //Unused
									0x02: Bowser intro
									0x04: Feather intro
									0x08: Balloon intro
									0x10: Invisibility intro
									0x20: Metal cap intro
									0x40: Fire breath intro
									0x80: Bomb-omb intro */
	u8 miscStates2;				/*	0x01: Door text activated, Lakitu trigger
									0x02: Lakitu done
									0x04: DDD image moved  //set every frame if DDD star 1 is collected & player is in basement
									0x08: Water drained
									0x10: Glowing rabbit 1
									0x20: Glowing rabbit 2
									0x40: Glowing rabbit 3
									0x80: Glowing rabbit 4 */
	u8 miscStates3;				/*	0x01: Glowing rabbit 5
									0x02: Glowing rabbit 6
									0x04: Glowing rabbit 7
									0x08: Glowing rabbit 8
									0x10: Mario cap intro
									0x20: ??? //Unused
									0x40: ??? //Unused
									0x80: ??? //Unused */
	u8 minigameRabbits1;		/*	0x01: Left bridge (M)
									0x02: Backyard (L)
									0x04: Castle right (W)
									0x08: Castle 1 (Y)
									0x10: Aquarium room (M)
									0x20: Water drainage (L)
									0x40: TTM room (W)
									0x80: Castle 2 (Y)	*/
	u8 minigameRabbits2;		/*	0x01: Mirror room (M)
									0x02: Mario room (L)
									0x04: Basement (W)
									0x08: Castle 3 (Y)
									0x10: Basement 1 (M)
									0x20: BOB room (L)
									0x40: Backyard (W)
									0x80: Castle right (Y)	*/
	u8 minigameRabbits3;		/*	0x01: Basement 2 (M)
									0x02: Hedge maze (L)
									0x04: THI room (W)
									0x08: Hedge maze (Y)
									0x10: Moat (M)
									0x20: 2nd floor (L)
									0x40: 3rd floor 1 (W)
									0x80: Basement (Y)	*/
	u8 minigameRabbits4;		/*	0x01: Upper hall (M)
									0x02: Castle roof (L)
									0x04: 3rd floor 2 (W)
									0x08: Moat (Y)
									0x10: ??? //Unused
									0x20: ??? //Unused
									0x40: ??? //Unused
									0x80: ??? //Unused	*/
	u8 cannonUnlocked1;			/*	0x01: BOB
									0x02: WF
									0x04: JRB
									0x08: CCM
									0x10: ??? //Unused
									0x20: ??? //Unused
									0x40: ??? //Unused
									0x80: SSL	*/
	u8 cannonUnlocked2;			/*	0x01: ??? //Unused
									0x02: SL
									0x04: WDW
									0x08: TTM
									0x10: THI
									0x20: ??? //Unused
									0x40: RR
									0x80: ??? //Unused	*/
	u8 cannonUnlocked3;			/*	//Unused	*/
	u8 cannonUnlocked4;			/*	0x01: ??? //Unused
									0x02: ??? //Unused
									0x04: OTR
									0x08: ??? //Unused
									0x10: ??? //Unused
									0x20: ??? //Unused
									0x40: ??? //Unused
									0x80: ??? //Unused	*/
	u8 stars[NUM_MAIN_LEVELS + NUM_SECRET_LEVELS];	// Stars in each level
	u8 coinRecords[NUM_MAIN_LEVELS];		//Coin counts in each main level
	u8 currentCharacter;				/* (Mario: 0, Luigi: 1, Wario: 2, Yoshi: 3)	*/
	u8 unused_0x42[2];					//Always 0
	
	[[gnu::always_inline]]
	inline void CollectStar(int levelID, int starID)
	{
		int actSelID = SUBLEVEL_LEVEL_TABLE[levelID];
		stars[actSelID] |= (u8)(1 << starID);
	}
	
	[[gnu::always_inline]]
	inline bool RemoveBowserSub()
	{
		// return (DAT_0209caa4 & 0x204);
		return (keysObtained & 0x04) || (keysUsed & 0x02);
	}
};

struct MinigameSaveData
{
	u32 magic5000;						//5000 in ASCII
	u8 minigamesUnlocked[4];			/*	Minigame bits: 0x1=Mario, 0x2=Luigi, 0x4=Wario, 0x8=Yoshi; minigame location: P=Page, R=Row, C=Column
												0: Minigames unlocked 1
												0x0n: P1R1C3
												0xn0: P1R2C1
												1: Minigames unlocked 2
												0x0n: P1R2C2
												0xn0: P1R2C3
												2: Minigames unlocked 3
												0x0n: P2R1C1
												0xn0: P2R1C2
												3: Minigames unlocked 4
												0x0n: P2R1C3
												0x10: ??? //Unused
												0x20: ??? //Unused
												0x40: ??? //Unused
												0x80: Always set, marks started minigame save	*/
	u8 minigamesPlayed[5];				/*	Minigames played 1-4 (exact same IDs like minigamesUnlocked, upper bits (4-7) of [3] are unused)	
												Minigames played 5:
													0x0n: P1R1C1
													0xn0: P1R1C2	*/
	u8 unused_0x51[3];						//Unused
	u32 minigameRecords[NUM_MINIGAMES][5];	/*	Minigame records 1-36; each minigame stores 5 scores */
	u8 unused_0x324[4];						//Unused
};

struct SaveData : FileSaveData, MinigameSaveData
{
	u32 currentFile; // 0, 1 or 2
	
	static bool SaveCurrentFile();
	static bool SaveFile(u32 fileID, FileSaveData* saveData);
	static bool SaveMinigames(MinigameSaveData* saveData);
	static s32  SaveDataToCart(char* saveData, u32 saveSize, u32 fileID);
	static u32  EraseAllSaveData();
	static bool EraseSaveFile(u32 saveFileID, char* saveArea);
	static void SetDefaultValues(FileSaveData* saveData);
	static void SetDefaultValuesMg(MinigameSaveData* saveData);
	
	static s32  ReadDataFromCart(char* saveData, u32 saveSize, u32 fileID);
	static bool ReadMinigameData(MinigameSaveData* saveData);
	static bool ReadFileData(u32 fileID, FileSaveData* saveData);
	
	static u32  CountStarsCollectedInLevel(u32 actSelectorID);
	static bool IsCharacterUnlocked(unsigned characterID);
	static u8   GetCoinCount(u32 actSelectorID);
	
	static s32  CanPlayerHaveCap();
	static s32  HasPlayerLostCap();
	static void PlayerLoseCap();
};

extern "C"
{
	extern SaveData SAVE_DATA;
}