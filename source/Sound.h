#ifndef SM64DS_SOUND_INCLUDED
#define SM64DS_SOUND_INCLUDED

#include "SM64DS_Common.h"

struct ROM_Info;
namespace Sound
{
	enum RecordType
	{
		RC_SEQUENCE,
		RC_SEQUENCE_ARCHIVE,
		RC_INSTRUMENT_BANK,
		RC_WAVE_ARCHIVE,
		RC_PLAYER, //???
		RC_GROUP,
		RC_PLAYER2, //???
		RC_STREAM //D.N.E. (Does Not Exist) for SM64DS
	};
	
	struct SDAT_Header
	{
		struct Block
		{
			u32 offset;
			u32 size;
		};
		char magic[4]; //"SDAT"
		u32 x0100feff;
		u32 fileSize;
		u16 headerSize;
		u16 numBlocks;
		Block symbolBlock;
		Block infoBlock;
		Block fat;
		Block fileBlock;		
	};
		
	struct SymbolBlock
	{
		
	};
	
	struct InfoSequenceEntry
	{
		u32 fileID;
		u16 bank;
		u8 volume;
		u8 channelPressure; //???
		u8 polyphonicPressure; //???
		u8 play; //???
		u16 padding;
		
		static InfoSequenceEntry* GetWithID(u32 seqID);
	};
	
	struct InfoInstrumentBankEntry
	{
		u32 fileID;
		u16 waveArchiveIDs[4];
		
		static InfoInstrumentBankEntry* GetWithID(u32 bankID);
	};
	
	struct InfoBlockRecord
	{
		u32 count;
		u32 entryOffsets[]; //size = count
	};
	
	struct InfoBlock
	{
		char magic[4]; //"INFO"
		u32 size;
		u32 recordOffsets[8];
		char padding[0x18];
	};
	
	struct FAT
	{
		
	};
	
	struct FileBlock
	{
		
	};
	
	struct Sequence
	{
		
	};
	
	struct InstrumentBank
	{
		
	};
	
	struct WaveArchive
	{
		char magic[4]; //"SWAR"
		u32 x0100feff;
		u32 fileSize;
		u16 headerSize;
		u16 one;
	};
	
	struct SDAT_RAM
	{
		SDAT_Header header;
		u32 unk30;
		u32 unk34;
		ROM_Info* rom;
		u32 unk3c;
		u32 unk40;
		u32 unk44;
		u32 unk48;
		u32 unk4c;
		u32 unk50;
		u32 unk54;
		u32 unk58;
		WaveArchive* waveArchive;
		u32 waveArchiveSize;
		u32 unk64; //waveArchiveSize copy?
		u32 unk68;
		u32 unk6c;
		u32 unk70;
		u32 unk74; //ROM?
		u32 unk78;
		FAT* fileAllocTable;
		u32 unk80;
		InfoBlock* infoBlock;
		
		static SDAT_RAM* PTR;
		
	};

	
	struct SequenceArchive
	{
		char magic[4]; //"SSAR"
		u16 endianCode; //0xfeff
		u16 unk6;
		u32 size; //includes header
		u32 dataOffset; //0x10
		u32 unke;
		
		struct Data
		{
			char magic[4]; //"DATA"
			u32 size;
			u32 sampleDefSize;
			u32 numSamples;
			
			struct SampleDef
			{
				u32 unk0;
				u16 bankID;
				u8 volume;
				u8 unk7;
				u8 unk8;
				u8 unk9;
				u8 unka;
				u8 unkb;
			} sampleDefs[];
			
		} data;
	};
	
	struct FileRef //guess
	{
		FileRef** unk0;
		Player* soundPlayer;
		char* file;
		u32 unk0c;
		u32 unk10;
		u32 unk14;
		u32 unk18;
		u32 unk1c;
		u32 unk20;
		u32 unk24;
		u32 unk28;
		u32 unk2c;
		u32 unk30;
		u32 unk34;
		u32 unk38;
		u8 unk3c;
		u8 unk3d;
		u8 unk3e;
		u8 unk3f;
		
		static FileRef* PTR_0; //there's one after it, but it's, as far as I know, not referred to exactly.
	};
	
	struct Player //not to be confused with ::Player
	{
		FileRef* fileRef;
		FileRef* fileRefCopy;
		u16 unk08;
		u16 unk0a;
		char* unk0c;
		char* unk10;
		u32 unk14;
		u32 unk18;
	};
	
	enum MusicID
	{
		MU_STAR_SELECT = 0x16,
		MU_SILVER_STAR_GET_1 = 0x19,
		MU_SILVER_STAR_GET_2 = 0x1a,
		MU_SILVER_STAR_GET_3 = 0x1b,
		MU_SILVER_STAR_GET_4 = 0x1c,
		MU_SILVER_STAR_GET_5 = 0x1d,
		MU_SILVER_STAR_LOSE = 0x1e,
		MU_CORRECT_SOLUTION = 0x20,
		MU_STAR_APPEAR = 0x21,
		MU_STAR_GET = 0x22,
		MU_TOAD_TALK = 0x25,
		MU_KEY_GET = 0x28,
		MU_KEY_GET_2 = 0x29,
		MU_CLASSIC_MARIO_JINGLE = 0x2a,
		MU_BOSS = 0x2d,
		MU_ENDLESS_STAIRS = 0x2e,
		MU_MEGA = 0x31,
		MU_FIRE_YOSHI = 0x32,
		MU_POWERFUL = 0x33,
		MU_LULLABY = 0x36,
		MU_BOB_OMB_BATTLEFIELD = 0x3a,
	};
	
	extern Player PLAYERS[]; //size not known, but greater than 9.
	
	u32 PlayLong(u32 uniqueID, u32 soundArchiveID, u32 soundID, const Vector3& camSpacePos, u32 arg4); //first arg = guess
	
	void PlayCharVoice(u32 charID, u32 soundID, const Vector3& camSpacePos);
	
	void Play(u32 archiveID, u32 soundID, const Vector3& camSpacePos);
	void PlayBank0(u32 soundID, const Vector3& camSpacePos);
	void PlayBank3(u32 soundID, const Vector3& camSpacePos);
	void PlayBank2_2D(u32 soundID);
	void PlayBank3_2D(u32 soundID);
	
	//volume goes up to 0x7f
	bool PlayMsgSound(u32 soundID, u32 arg1, u32 volume, Fix12i timeInv, bool starting); //return value: did it finish?
	
	void LoadAndSetMusic_Layer2(u32 musicID);
	void StopLoadedMusic_Layer2();
	void LoadAndSetMusic_Layer3(u32 musicID);
	void StopLoadedMusic_Layer3();
	void SetMusic(u32 arg0, u32 musicID);
	void EndMusic(u32 arg0, u32 musicID);
	void UnkPlaySoundFunc(u32 soundID);
	
	void ChangeMusicVolume(u32 newVolume, Fix12i changeSpeed);
	
	void Func_02048ee4();
	void Func_02048eb4();
	void Func_0201277c(u32 arg1);
}

#endif