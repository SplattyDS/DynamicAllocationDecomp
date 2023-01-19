#pragma once

#include "../Message.h"

struct INF1_Header
{
	char magic3[4]; // "INF1"
	u32 size;      // of inf1
	u16 numMsgs;
	u16 unk0a;
	u32 unk0c;
	
	Message& message(u16 id) {return *(Message*)((char*)this + sizeof(INF1_Header) + 0x08 * id);}
	char* rawMsgText(u16 id) {return *(char**)((char*)this + 0x08 + size + message(id).textOffset);}
};

struct MESG_File
{
	char magic1[4]; // "MESG"
	char magic2[4]; // "bmgl"
	u32 fileSize;
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	INF1_Header inf1;
	
	Message& message(u16 id) {return *(Message*)((char*)this + sizeof(MESG_File) + 0x08 * id);}
	char* rawMsgText(u16 id) {return *(char**)((char*)this + 0x08 + inf1.size + message(id).textOffset);}
};