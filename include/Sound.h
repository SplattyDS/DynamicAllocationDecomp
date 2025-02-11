#pragma once

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
		struct Data
		{
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
			};
			
			char magic[4]; //"DATA"
			u32 size;
			u32 sampleDefSize;
			u32 numSamples;
			SampleDef sampleDefs[];
		};
		
		char magic[4]; //"SSAR"
		u16 endianCode; //0xfeff
		u16 unk6;
		u32 size; //includes header
		u32 dataOffset; //0x10
		u32 unke;
		Data data;
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
		
		static void SetPlayableSeqCount(s32 playerID, s32 maxSequences);
	};
	
	extern Player PLAYERS[]; //size not known, but greater than 9.
	
	u32 PlayLong(u32 uniqueID, u32 soundArchiveID, u32 soundID, const Vector3& camSpacePos, u32 arg4); //first arg = guess
	
	void PlayCharVoice(u32 charID, u32 soundID, const Vector3& camSpacePos);
	
	void Play(u32 archiveID, u32 soundID, const Vector3& camSpacePos);
	u32 Play2D(u32 archiveID, u32 soundID);
	// void PlayBank0(u32 soundID, const Vector3& camSpacePos); // deprecated, use Sound::Play
	// void PlayBank3(u32 soundID, const Vector3& camSpacePos); // deprecated, use Sound::Play
	// void PlayBank2_2D(u32 soundID); // deprecated, use Sound::Play2D
	// void PlayBank3_2D(u32 soundID); // deprecated, use Sound::Play2D
	
	//volume goes up to 0x7f
	bool PlaySub(u32 soundID, u32 musicVolume, u32 volume, Fix12i timeInv, bool starting); //return value: did it finish?
	
	bool PlaySmallSecretSound(Actor* actor, u16* timer); // returns whether finished playing sound
	bool PlaySecretSound(Actor* actor, u16* timer); // returns whether finished playing sound
	
	void LoadGroupAndSetBank(s32 groupID, s32 bankID);
	void LoadInitialGroup(s32 groupID);
	void UnsetPlayerVoiceGroup(); // only sets a variable to 0
	void ResetPlayerVoiceGroup(); // actually unloads the group
	
	void LoadAndSetMusic_Layer1(s32 musicID);
	void StopLoadedMusic_Layer1(u32 fade);
	void LoadAndSetMusic_Layer2(u32 musicID);
	void StopLoadedMusic_Layer2();
	void LoadAndSetMusic_Layer3(u32 musicID);
	void StopLoadedMusic_Layer3();
	void SetMusic(u32 arg0, u32 musicID);
	void EndMusic(u32 arg0, u32 musicID);
	void PauseMusic();
	void UnpauseMusic();
	
	bool ChangeMusicVolume(u32 newVolume, Fix12i changeSpeed);
	
	void Func_02048eb4();
	void Func_02048ec4();
	void Func_02048ee4();
}

extern "C"
{
	extern s32 MUSIC_VOLUME_LSL_12;
	extern s32 MESSAGE_SOUND_VOLUME_LSL_12;
	
	extern s32 JRB_SOUND_SPECIFICS; // copied to SOUND_SPECIFICS if (JRB_SOUND_SPECIFICS > 0 && JRB_SOUND_SPECIFICS != SOUND_SPECIFICS)
	extern s32 SOUND_SPECIFICS;
}