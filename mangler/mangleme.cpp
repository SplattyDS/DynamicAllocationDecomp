#include "SM64DS_Common.h"

namespace
{
	struct TexSRTDef
	{
		int dummy;
	};
	
	struct TextureTransformer
	{
		int dummy;
		
		void SetTexSRT(TexSRTDef& texDef, int flags, Fix12i speed, unsigned startFrame);
	};
}

void TextureTransformer::SetTexSRT(TexSRTDef& texDef, int flags, Fix12i speed, unsigned startFrame)
{
	return;
}