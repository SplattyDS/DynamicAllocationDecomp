#pragma once

struct BCA_File
{
	struct Animation
	{
		struct Descriptor
		{
			bool useInterpolation; // whether interpolation should be used to calculate odd frame values using the midpoint of the previous and next frames
			bool incrementOffset; // if false, only the value at startOffset is used
			u16 startOffset; // index of first value into the corresponding value section
		};
		
		Descriptor scaleX;
		Descriptor scaleY;
		Descriptor scaleZ;
		Descriptor rotationX;
		Descriptor rotationY;
		Descriptor rotationZ;
		Descriptor translationX;
		Descriptor translationY;
		Descriptor translationZ;
	};
	
	u16 numBones; // needs to match numBones in the BMD
	u16 numFrames;
	u32 unk04; // seems to be either 0 or 1
	Fix12i* scales;
	s16* rotations;
	Fix12i* translations;
	Animation* anims; // for each bone
};

static_assert(sizeof(BCA_File) == 0x18);
static_assert(sizeof(BCA_File::Animation) == 0x24);
static_assert(sizeof(BCA_File::Animation::Descriptor) == 0x4);