#pragma once

#include "SM64DS_Common.h"

//0xfd is new line
//0xff is end of text
/*0xfe is special
	Next byte is length of structure
	Next comes where to branch
	if 0:
		Next halfword ???
		if 0:
			Next byte is what to do
			Last byte (L)
			if 0:
				str = L - numStars
*/

struct Message
{
	// static wchar_t chars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
							// 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
							// 'W', 'X', 'Y', 'Z', '「', '」', '?', '!', '~', ',', '“', '”', '•', 'a', 'b', 'c',
							// 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
							// 't', 'u', 'v', 'w', 'x', 'y', 'z', '-', '.','\'', ':', ';', '&', ' ', '/', ' ',
							// '€', ' ', '‚', 'ƒ', '„', '…', '†', '‡', '^', '‰', 'Š', '<', 'Œ', ' ', 'Ž', ' ',
							// ' ', '‘', '’', ' ', ' ', '•', '–', '—', '˜', '™', 'š', '>', 'œ', ' ', 'ž', 'Ÿ',
							// ' ', '¡', '¢', '£', '¤', '¥', '¦', '§', '¨', '©', 'ª', '«', '¬', '­', '®', '¯',
							// '°', '±', '²', '³', '´', 'µ', '¶', '•', '¸', '¹', 'º', '»', '¼', '½', '¾', '¿',
							// 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï',
							// 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß'};
	
	u32 textOffset;
	s16 textBoxWidth;
	s16 textBoxHeight; // in lines
	
	static void PrepareTalk();
	static void EndTalk();
	
	static void AddChar(char charInFontEncoding);
	static void Display(u32 msgID);
	
	static void DisplayCourseNameForStarSelect(u32 actSelectorID);
	static void DisplayStarNameForStarSelect(u32 starID);
};

struct MESG_File;

struct MsgIDCharEntry
{
	u16 perCharID;
	u16 msgID;
};

extern "C"
{	
	extern s32 MSG_LINE_HEIGHT;
	extern s32 CURR_MSG_ID;
	extern Message* CURR_MSG_PTR;
	extern char* CURR_MSG_TEXT_CHAR;
	extern Message* MSG_ARR_PTR;
	extern MESG_File* MSG_FILE_PTR;
	extern MsgIDCharEntry MSG_ID_CHAR_MAP[0x62];
	extern u16 UTF16_TO_FONT_TABLE[0x100];
	extern u8 TALK_FONT_CHAR_WIDTHS[0x100];
}

using MsgGenTextFunc = void(*)();