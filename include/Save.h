#pragma once

#include "SM64DS_Common.h"

struct FileSaveData
{
	u32 magic8000;			//8000 in ASCII
	u32 flags1;				/*	0x00000001: File saved //set when file is saved
								0x00000002: Basement key obtained
								0x00000004: Upper hall key obtained		//Removes sub from DDD
								0x00000008: Mario key obtained
								0x00000010: Luigi key obtained
								0x00000020: Wario key obtained
								0x00000040: Main hall key obtained
								0x00000080: White key obtained	//Triggers white room star
								0x00000100: Basement key used
								0x00000200: Upper hall key used	//Removes sub from DDD
								0x00000400: Mario key used
								0x00000800: Luigi key used
								0x00001000: Wario key used
								0x00002000: Main hall key used
								0x00004000: White key used	//Disables white room star
								0x00008000: WF star door open
								0x00010000: Character star door open
								0x00020000: JRB star door open
								0x00040000: CCM star door open
								0x00080000: Mario star door open
								0x00100000: Bowser 1 door open
								0x00200000: Bowser 2 door open
								0x00400000: Clock door open
								0x00800000: ??? //Unused
								0x01000000: Mario lost his cap
								0x02000000: Luigi lost his cap
								0x04000000: Wario lost his cap
								0x08000000: ??? //Unused
								0x10000000: ??? //Unused
								0x20000000: ??? //Unused
								0x40000000: Minigames activated //talked to minigame toad
								0x80000000: Red switch activated //if not set, the shine in main hall is rendered */
	u32 flags2;				/*	0x00000001: Mario intro
								0x00000002: Luigi intro
								0x00000004: Wario intro
								0x00000008: Always set, marks started save
								0x00000010: ???	//Unused
								0x00000020: ???	//Unused
								0x00000040: ???	//Unused
								0x00000080: Character control		//Getting control of character
								0x00000100: ??? //Unused
								0x00000200: Bowser intro
								0x00000400: Feather intro
								0x00000800: Balloon intro
								0x00001000: Invisibility intro
								0x00002000: Metal cap intro
								0x00004000: Fire breath intro
								0x00008000: Bomb-omb intro
								0x00010000: Door text activated, Lakitu trigger
								0x00020000: Lakitu done
								0x00040000: DDD image moved  //set every frame if DDD star 1 is collected & player is in basement
								0x00080000: Water drained
								0x00100000: Glowing rabbit 1
								0x00200000: Glowing rabbit 2
								0x00400000: Glowing rabbit 3
								0x00800000: Glowing rabbit 4
								0x01000000: Glowing rabbit 5
								0x02000000: Glowing rabbit 6
								0x04000000: Glowing rabbit 7
								0x08000000: Glowing rabbit 8
								0x10000000: Mario cap intro
								0x20000000: ??? //Unused
								0x40000000: ??? //Unused
								0x80000000: ??? //Unused */
	u32 minigameRabbits;	/*	0x00000001: Left bridge (M)
								0x00000002: Backyard (L)
								0x00000004: Castle right (W)
								0x00000008: Castle 1 (Y)
								0x00000010: Aquarium room (M)
								0x00000020: Water drainage (L)
								0x00000040: TTM room (W)
								0x00000080: Castle 2 (Y)
								0x00000100: Mirror room (M)
								0x00000200: Mario room (L)
								0x00000400: Basement (W)
								0x00000800: Castle 3 (Y)
								0x00001000: Basement 1 (M)
								0x00002000: BOB room (L)
								0x00004000: Backyard (W)
								0x00008000: Castle right (Y)
								0x00010000: Basement 2 (M)
								0x00020000: Hedge maze (L)
								0x00040000: THI room (W)
								0x00080000: Hedge maze (Y)
								0x00100000: Moat (M)
								0x00200000: 2nd floor (L)
								0x00400000: 3rd floor 1 (W)
								0x00800000: Basement (Y)
								0x01000000: Upper hall (M)
								0x02000000: Castle roof (L)
								0x04000000: 3rd floor 2 (W)
								0x08000000: Moat (Y)
								0x10000000: ??? //Unused
								0x20000000: ??? //Unused
								0x40000000: ??? //Unused
								0x80000000: ??? //Unused	*/
	u32 cannonUnlocked;		/*	0x00000001: BOB
								0x00000002: WF
								0x00000004: JRB
								0x00000008: CCM
								0x00000010: ??? //Unused
								0x00000020: ??? //Unused
								0x00000040: ??? //Unused
								0x00000080: SSL
								0x00000100: ??? //Unused
								0x00000200: SL
								0x00000400: WDW
								0x00000800: TTM
								0x00001000: THI
								0x00002000: ??? //Unused
								0x00004000: RR
								0x00008000: ??? //Unused
								0x00010000: ??? //Unused
								0x00020000: ??? //Unused
								0x00040000: ??? //Unused
								0x00080000: ??? //Unused
								0x00100000: ??? //Unused
								0x00200000: ??? //Unused
								0x00400000: ??? //Unused
								0x00800000: ??? //Unused
								0x00010000: ??? //Unused
								0x02000000: ??? //Unused
								0x04000000: OTR
								0x08000000: ??? //Unused
								0x10000000: ??? //Unused
								0x20000000: ??? //Unused
								0x40000000: ??? //Unused
								0x80000000: ??? //Unused	*/
	u8 stars[NUM_MAIN_LEVELS + NUM_SECRET_LEVELS];	// Stars in each level
	u8 coinRecords[NUM_MAIN_LEVELS];		//Coin counts in each main level
	u8 currentCharacter;				/* (Mario: 0, Luigi: 1, Wario: 2, Yoshi: 3)	*/
	u8 controllerMode;
	u8 unk43;
	
	[[gnu::always_inline]]
	inline void CollectStar(int levelID, int starID)
	{
		int courseID = SUBLEVEL_LEVEL_TABLE[levelID];
		stars[courseID] |= (u8)(1 << starID);
	}
	
	[[gnu::always_inline]]
	inline bool RemoveBowserSub()
	{
		return flags1 & 0x204;
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
	
	static u32  CountStarsCollectedInLevel(u32 courseID);
	static bool IsCharacterUnlocked(u32 characterID);
	static u8   GetCoinRecord(u32 courseID);
	static void SetCoinRecordIfHigher(s8 courseID, u8 coinCount);
	static u32 NumGlowingRabbitsFound();
	static void SetCharacterIntro(s32 keyID);
	
	static s32  CanPlayerHaveCap();
	static s32  HasPlayerLostCap();
	static void PlayerLoseCap();
};

extern "C"
{
	extern SaveData SAVE_DATA;
}