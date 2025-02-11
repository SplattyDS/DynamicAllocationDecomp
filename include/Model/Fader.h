#pragma once

struct Fader		//internal name: dFader
{
	Fix12i currInterp; // 0x4
	Fix12i speed;      // 0x8
	
	virtual ~Fader();
	
	void AdvanceInterp();
};

struct FaderBrightness : Fader		//internal name: dFdBrightness
{
	virtual ~FaderBrightness();
	virtual void AdvanceFade();
	virtual bool SetBackwardTime(u32 frames); // sets the speed so that the fader goes from end to start in `frames` frames
	virtual bool SetForwardTime(u32 frames);  // sets the speed so that the fader goes from start to end in `frames` frames
	virtual bool IsAtStart();
	virtual bool IsAtEnd();
	virtual bool IsBetweenStartAndEnd();
	virtual void SetToEnd();
	virtual void SetToStart();
};

struct FaderColor : FaderBrightness	//internal name: dFdColor
{
	enum Color
	{
		BLACK = 0x0000,
		WHITE = 0x7fff,
	};
	
	u16 color; // 0xc (only black and white work)
	
	virtual ~FaderColor();
	virtual void AdvanceFade() override;
};

struct FaderWipe : FaderColor		//internal name: dFdWipe
{
	u16 unk0e;   // 0xe
	Model model; // 0x10
	
	FaderWipe();
	virtual ~FaderWipe();
	virtual void AdvanceFade() override;
	
	void LoadAndSetFile(u16 ov0ID);
};

extern "C"
{
	extern FaderColor* GLOBAL_FADER;
}