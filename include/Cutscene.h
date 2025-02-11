#pragma once

#include "SM64DS_Common.h"
#include <cstdint>
#include <concepts>
#include <array>
#include <tuple>
#include <bit>

struct Camera;
struct FaderWipe;

enum InstructionType
{
	IT_PLAYER_INSTRUCTIONS_START = 0x0,
	IT_NUM_PLAYER_INSTRUCTIONS   = 0x4,
	IT_CAMERA                    = 0x4,
	IT_END_AFTER_TOUCH           = 0x5,
	IT_CHANGE_SCRIPT             = 0x6,
	IT_CHANGE_MUSIC              = 0x7,
	IT_PLAY_SEQARC_1             = 0x8,
	IT_PLAY_SEQARC_2             = 0x9,
	IT_DISPLAY_MESSAGE           = 0xa,
	IT_CHANGE_LEVEL              = 0xb,
	IT_FADE_TO_WHITE             = 0xc,
	IT_FADE_FROM_WHITE           = 0xd,
	IT_FADE_TO_BLACK             = 0xe,
	IT_FADE_FROM_WHITE_BROKEN    = 0xf,
	IT_FADE_TO_BLACK_AND_BACK    = 0x10,
	IT_ENABLE_WATERFALL_SFX      = 0x11,
};

extern "C"
{
	bool RunKuppaScript(char* address);
	void ProcessKuppaScript();
	void EndKuppaScript();
	void ResetKuppaScript();
	bool ContinueKuppaScriptIfNecessary();
	
	void StartIntroCutscene();
	void DisableSoundPlayersForCredits();
	
	using KS_CameraFunction = s32(Camera::*)(char* params, s16 minFrame, s16 maxFrame);
	
	extern KS_CameraFunction KS_CAMERA_FUNCTIONS[39];
	extern u32 KS_PLAYER_IDS[4];
	extern u32 CUTSCENE_OBJECT_IDS[16];
	extern u32 KS_FRAME_COUNTER;
	extern u8 KS_NUM_PLAYERS;
	extern FaderWipe* KS_FADER;
	
	extern char* RUNNING_KUPPA_SCRIPT; // nullptr if no script is running
	extern char* SAVED_KUPPA_SCRIPT;
	
	extern char INTRO_CUTSCENE;
	extern char FALL_IN_FRONT_OF_CASTLE_CUTSCENE;
	extern char BOB_CREDITS_CUTSCENE;
}

enum class CharacterID
{
	Mario,
	Luigi,
	Wario,
	Yoshi,
};

using enum CharacterID;

namespace KuppaScriptImpl { template<std::size_t scriptSize = 0> class Builder; }

template<std::size_t size = 0>
class KuppaScript
{
	std::array<char, size> data;
	
	friend class KuppaScriptImpl::Builder<size - 1>;
	
	consteval explicit KuppaScript(const decltype(data)& data) requires(size > 0):
		data(data)
	{}
	
public:
	bool Run() & requires(size > 0) { return RunKuppaScript(data.data()); }
	
	static void Stop() { EndKuppaScript(); }
	
	static constexpr std::size_t Size() { return size; }
	
	constexpr const char* Data() const requires(size > 0) { return data.data(); }
	constexpr       char* Data()       requires(size > 0) { return data.data(); }
	
	constexpr auto begin()       { return data.begin(); }
	constexpr auto begin() const { return data.begin(); }
	constexpr auto end()         { return data.end();   }
	constexpr auto end()   const { return data.end();   }
};

consteval KuppaScriptImpl::Builder<> NewScript();

namespace KuppaScriptImpl
{
	template<class T, std::size_t s1, std::size_t s2>
	consteval auto operator+(const std::array<T, s1>& a1, const std::array<T, s2>& a2)
	{
		return std::apply([&](auto... e1)
		{
			return std::apply([&](auto... e2)
			{
				return std::to_array({e1..., e2...});
			},
			a2);
		},
		a1);
	}
	
	consteval auto ToByteArray(auto... args)
	{
		return (std::bit_cast<std::array<char, sizeof(args)>>(args) + ...);
	}
	
	template<std::size_t scriptSize>
	class Builder
	{
		friend consteval Builder<>(::NewScript)();
		
		template<std::size_t numArgs>
		struct PendingCommand
		{
			Builder oldBuilder;
			u8 type;
			std::array<char, numArgs> data;
			
			static constexpr std::size_t newCommandSize = numArgs + 6;
			static_assert(newCommandSize < 256, "A Kuppa Script command is too long");
			
			consteval auto operator()(s16 minFrame, s16 maxFrame) const
			{
				return Builder<scriptSize + newCommandSize>
				{
					oldBuilder.data
					+ std::to_array<char>({newCommandSize, type})
					+ ToByteArray(minFrame, maxFrame)
					+ data
				};
			}
			
			consteval auto operator()(s16 frame) const
			{
				return operator()(frame, frame);
			}
		};
		
		consteval Builder() requires(scriptSize == 0) = default;
		
	public:
		std::array<char, scriptSize> data;
		
		consteval explicit Builder(const decltype(data)& data) requires(scriptSize > 0):
			data(data)
		{}
		
		consteval auto End() const
		{
			return KuppaScript<scriptSize + 1>{data + std::to_array<char>({0})};
		}
		
		template<u8 type>
		consteval auto Instruction(auto... args) const -> PendingCommand<sizeof...(args)>
		{
			return {*this, type, {args...}};
		}
		
		template<u8 type, std::size_t size>
		consteval PendingCommand<size> Instruction(const std::array<char, size>& array) const
		{
			return {*this, type, array};
		}
		
		template<CharacterID character, u8 function>
		consteval auto PlayerInstruction(auto... args) const
		{
			return Instruction<static_cast<u8>(character)>(function, args...);
		}
		
		template<CharacterID character, u8 function, std::size_t size>
		consteval auto PlayerInstruction(const std::array<char, size>& array) const
		{
			return Instruction<static_cast<u8>(character)>(std::to_array<char>({function}) + array);
		}
		
		template<u8 function>
		consteval auto CamInstruction(auto... args) const
		{
			return Instruction<4>(function, args...);
		}
		
		template<u8 function, std::size_t size>
		consteval auto CamInstruction(std::array<char, size> array) const
		{
			return Instruction<4>(std::to_array<char>({function}) + array);
		}
		
		// Set camera target position (coordinates in fxu)
		consteval auto SetCamTarget(Vector3_16f target) const
		{
			return CamInstruction<0>(ToByteArray(target));
		}
		
		consteval auto SetCamTarget(Fix12s x, Fix12s y, Fix12s z) const
		{
			return SetCamTarget(Vector3_16f{x, y, z});
		}
		
		// Set camera position (coordinates in fxu)
		consteval auto SetCamPos(Vector3_16f pos) const
		{
			return CamInstruction<1>(ToByteArray(pos));
		}
		
		consteval auto SetCamPos(Fix12s x, Fix12s y, Fix12s z) const
		{
			return SetCamPos(Vector3_16f{x, y, z});
		}
		
		// Set camera target position and position (coordinates in fxu)
		consteval auto SetCamTargetAndPos(Vector3_16f target, Vector3_16f pos) const
		{
			return CamInstruction<2>(ToByteArray(target, pos));
		}
		
		consteval auto SetCamTargetAndPos(Fix12s tx, Fix12s ty, Fix12s tz, Fix12s px, Fix12s py, Fix12s pz) const
		{
			return SetCamTargetAndPos(Vector3_16f{tx, ty, tz}, Vector3_16f{px, py, pz});
		}
		
		// Set camera FOV modifier (not sure if it's exactly the FOV, might be FOV/2)
		consteval auto SetCamFOV(u16 fovModifier) const
		{
			return CamInstruction<3>(ToByteArray(fovModifier));
		}
		
		// Adjust camera FOV modifier
		consteval auto AdjustCamFOV(u16 targetModifier, u16 speed) const
		{
			return CamInstruction<4>(ToByteArray(targetModifier, speed));
		}
		
		// Adjust screen size from full size to target values (uses minFrame and maxFrame for gradient)
		consteval auto AdjustCamScreenSize(u8 left, u8 bottom, u8 right, u8 top) const
		{
			return CamInstruction<5>(ToByteArray(left, bottom, right, top));
		}
		
		// Weird cubic interpolation?
		consteval auto UnkCubicInterpolation(u32 unk0, u32 unk1) const // pointers?
		{
			return CamInstruction<6>(ToByteArray(unk0, unk1));
		}
		
		// Set a stored value presumably used by the camera
		consteval auto SetStoredFix12(Fix12i newValue) const
		{
			return CamInstruction<13>(ToByteArray(newValue));
		}
		
		consteval auto AdjustStoredFix12(Fix12i target, Fix12i speed) const
		{
			return CamInstruction<14>(ToByteArray(target, speed));
		}
		
		// Adjust camera target position via exponential decay
		// dest: the destination vector of the target position
		// approach: approach factor(s)
		consteval auto AdjustCamTargetDec(Vector3_16f dest, Vector3_16f approach) const
		{
			return CamInstruction<15>(ToByteArray(dest, approach));
		}
		
		consteval auto AdjustCamTargetDec(Vector3_16f dest, Fix12s ax, Fix12s ay, Fix12s az) const
		{
			return AdjustCamTargetDec(dest, Vector3_16f{ax, ay, az});
		}
		
		consteval auto AdjustCamTargetDec(Vector3_16f dest, Fix12s approach) const
		{
			return AdjustCamTargetDec(dest, approach, approach, approach);
		}
		
		consteval auto AdjustCamTargetDec(Fix12s dx, Fix12s dy, Fix12s dz, Fix12s ax, Fix12s ay, Fix12s az) const
		{
			return AdjustCamTargetDec(Vector3_16f{dx, dy, dz}, Vector3_16f{ax, ay, az});
		}
		
		consteval auto AdjustCamTargetDec(Fix12s dx, Fix12s dy, Fix12s dz, Fix12s approach ) const
		{
			return AdjustCamTargetDec(Vector3_16f{dx, dy, dz}, approach);
		}
		
		// Adjust camera position via exponential decay
		// dest: the destination vector of the target position
		// approach: approach factor(s)
		consteval auto AdjustCamPosDec(Vector3_16f dest, Vector3_16f approach) const
		{
			return CamInstruction<16>(ToByteArray(dest, approach));
		}
		
		consteval auto AdjustCamPosDec(Vector3_16f dest, Fix12s ax, Fix12s ay, Fix12s az) const
		{
			return AdjustCamPosDec(dest, Vector3_16f{ax, ay, az});
		}
		
		consteval auto AdjustCamPosDec(Vector3_16f dest, Fix12s approach) const
		{
			return AdjustCamPosDec(dest, approach, approach, approach);
		}

		consteval auto AdjustCamPosDec(Fix12s dx, Fix12s dy, Fix12s dz, Fix12s ax, Fix12s ay, Fix12s az) const
		{
			return AdjustCamPosDec(Vector3_16f{dx, dy, dz}, Vector3_16f{ax, ay, az});
		}

		consteval auto AdjustCamPosDec(Fix12s dx, Fix12s dy, Fix12s dz, Fix12s approach) const
		{
			return AdjustCamPosDec(Vector3_16f{dx, dy, dz}, approach);
		}

		// Set stored angle toward pause view position and the stored s16s to 0
		consteval auto ResetCamToPause() const
		{
			return CamInstruction<17>();
		}

		// Adjust camera target position to offset from owner via exponential decay
		consteval auto SetCamTargetRelativeDec(Vector3_16f offset, u8 approachFactorLsl8) const
		{
			return CamInstruction<18>(ToByteArray(offset, approachFactorLsl8));
		}

		consteval auto SetCamTargetRelativeDec(Fix12s x, Fix12s y, Fix12s z, u8 approachFactorLsl8) const
		{
			return SetCamTargetRelativeDec(Vector3_16f{x, y, z}, approachFactorLsl8);
		}

		// Adjust camera target position to offset from owner rotated by owner's facing angle via exponential decay
		consteval auto AdjustCamByOwnerAngleDec(Vector3_16f offset, u8 approachFactorLsl8) const
		{
			return CamInstruction<19>(ToByteArray(offset, approachFactorLsl8));
		}

		consteval auto AdjustCamByOwnerAngleDec(Fix12s x, Fix12s y, Fix12s z, u8 approachFactorLsl8) const
		{
			return AdjustCamByOwnerAngleDec(Vector3_16f{x, y, z}, approachFactorLsl8);
		}

		// Adjust camera position and angles relative to owner position via exponential decay
		// targetDist:            target distance (in fxu)
		// approachFactorLsl8:    approach factor multiplied by 256
		// targetVertAngle:       target vertical angle
		// invVertAngleApproach:  1 divided by the vertical angle's approach factor (Set to 0 to not change vertical angle)
		// targetHorzAngle:       Target horizontal angle (Set to -1 to use CAMERA->targetAngle),
		// invHorzAngleApproach:  1 divided by the horizontal angle's approach factor (Set to 0 to not change horizontal angle)
		consteval auto CamPosAngleRelativeDec(u16 targetDist, u8 approachFactorLsl8, s16 targetVertAngle, u8 invVertAngleApproach, s16 targetHorzAngle, u8 invHorzAngleApproach ) const
		{
			return CamInstruction<20>(ToByteArray(
				targetDist, approachFactorLsl8,
				targetVertAngle, invVertAngleApproach,
				targetHorzAngle, invHorzAngleApproach
			));
		}

		// Spin camera target position around camera position
		// Sets a stored vector to the target position on the first frame
		consteval auto SpinCamTarget(s16 vertAngularSpeed, s16 horzAngularSpeed) const
		{
			return CamInstruction<21>(ToByteArray(vertAngularSpeed, horzAngularSpeed));
		}

		// Spin the camera position around its owner position
		consteval auto SpinCamAroundOwnerPos(s32 speed, s16 vertAngularSpeed, s16 horzAngularSpeed) const
		{
			return CamInstruction<22>(ToByteArray(speed, vertAngularSpeed, horzAngularSpeed));
		}

		// Adjust FOV modifier via exponential decay (invApproachFactor = 1 / approachFactor)
		consteval auto AdjustCamFOVDec(u16 targetModifier, u8 invApproachFactor) const
		{
			return CamInstruction<23>(ToByteArray(targetModifier, invApproachFactor));
		}

		// Adjust camera FOV if new value is greater than the old value
		consteval auto AdjustCamFOVIfBigger(u16 newModifier, s16 fovSpeedTowards0, s16 fovOscillationAngularSpeed) const
		{
			return CamInstruction<24>(ToByteArray(newModifier, fovSpeedTowards0, fovOscillationAngularSpeed));
		}

		// This probably isn't actually a nop but it's here for backwards compatibility
		consteval auto NopCam() const
		{
			return CamInstruction<25>();
		}

		// Approach a distance of 800 fxu (approach factor = 1/20),
		// 33.75° above the player (approach factor = 1/16), with the
		// horizontal angle being the stored angle (approach factor = 1/8)
		consteval auto CamApproachPlayerFromTop() const
		{
			return CamInstruction<26>();
		}

		// Set camera target position and position to rotated offset from owner (in fxu)
		consteval auto SetCamTargetAndPosRotatedFromOwner(Vector3_16f target, Vector3_16f pos) const
		{
			return CamInstruction<27>(ToByteArray(target, pos));
		}

		consteval auto SetCamTargetAndPosRotatedFromOwner(Fix12s tx, Fix12s ty, Fix12s tz, Fix12s px, Fix12s py, Fix12s pz) const
		{
			return SetCamTargetAndPosRotatedFromOwner(Vector3_16f{tx, ty, tz}, Vector3_16f{px, py, pz});
		}

		// Wifi Related
		consteval auto Wifi() const { return Instruction<5>(); }

		// Change cutscene script (by raw address)
		consteval auto ChangeScript(u32 newScriptAddress) const
		{
			return Instruction<6>(ToByteArray(newScriptAddress));
		}

		// Change music
		consteval auto ChangeMusic(u32 NewMusicID) const
		{
			return Instruction<7>(ToByteArray(NewMusicID));
		}

		// Play sound from SSAR 1 (player voices). [].
		consteval auto PlaySoundSSAR1(u32 soundID) const
		{
			return Instruction<8>(ToByteArray(soundID));
		}
		
		// Play sound from SSAR 2 (system)
		consteval auto PlaySoundSSAR2(u32 soundID) const
		{
			return Instruction<9>(ToByteArray(soundID));
		}
		
		// Display a message
		consteval auto DisplayMessage(u16 messageID) const
		{
			return Instruction<10>(ToByteArray(messageID));
		}
		
		// Change level (with raw cutscene address)
		consteval auto ChangeLevel(u8 newLevelID, u8 entranceID, u8 starID, u32 cutsceneAddress) const
		{
			return Instruction<11>(ToByteArray(newLevelID, entranceID, starID, cutsceneAddress));
		}
		
		// Fade to white
		consteval auto FadeToWhite() const { return Instruction<12>(); }
		
		// Fade from white
		consteval auto FadeFromWhite() const { return Instruction<13>(); }
		
		// Fade to black
		consteval auto FadeToBlack() const { return Instruction<14>(); }
		
		// Fade from white, but broken
		consteval auto FadeFromWhiteBroken() const { return Instruction<15>(); }
		
		// Fade to black, then fade from black
		consteval auto FadeToBlackAndBack() const { return Instruction<16>(); }
		
		// Store 0 at 0x02110AEC
		consteval auto STZ() const { return Instruction<17>(); }

		// Set position and Y-angle (both model and motion angle)
		template<CharacterID character>
		consteval auto SetPlayerPosAndAngleY(Vector3_16f pos, s16 yAngle) const
		{
			return PlayerInstruction<character, 0>(ToByteArray(pos, yAngle));
		}

		template<CharacterID character>
		consteval auto SetPlayerPosAndAngleY(Fix12s xPos, Fix12s yPos, Fix12s zPos, s16 yAngle) const
		{
			return SetPlayerPosAndAngleY<character>(Vector3_16f{xPos, yPos, zPos}, yAngle);
		}

		// Send input to move the player to a target position (full magnitude: 0x1000_fs)
		template<CharacterID character>
		consteval auto SendPlayerInput(Vector3_16f pos, Fix12s inputMagnitude) const
		{
			return PlayerInstruction<character, 1>(ToByteArray(pos, inputMagnitude));
		}

		template<CharacterID character>
		consteval auto SendPlayerInput(Fix12s xPos, Fix12s yPos, Fix12s zPos, Fix12s inputMagnitude) const
		{
			return SendPlayerInput<character>(Vector3_16f{xPos, yPos, zPos}, inputMagnitude);
		}

		// Orr player flags with 0x24000000
		template<CharacterID character>
		consteval auto OrrPlayerFlags() const
		{
			return PlayerInstruction<character, 2>();
		}

		// Make a player lie down
		template<CharacterID character>
		consteval auto MakePlayerLieDown() const
		{
			return PlayerInstruction<character, 3>();
		}

		// Player character voice
		template<CharacterID character>
		consteval auto PlayPlayerVoice(u32 soundID) const
		{
			return PlayerInstruction<character, 4>(ToByteArray(soundID));
		}

		// Play sound from SSAR0
		template<CharacterID character>
		consteval auto PlayerPlaySoundSSAR0(u32 soundID) const
		{
			return PlayerInstruction<character, 5>(ToByteArray(soundID));
		}

		// Play sound from SSAR3
		template<CharacterID character>
		consteval auto PlayerPlaySoundSSAR3(u32 soundID) const
		{
			return PlayerInstruction<character, 6>(ToByteArray(soundID));
		}

		// Press and hold buttons
		template<CharacterID character>
		consteval auto PlayerHoldButtons(u16 buttons) const
		{
			return PlayerInstruction<character, 7>(ToByteArray(buttons));
		}

		// Drop the player with a speed of 32 fxu/frame and give him wings for 408 frames
		template<CharacterID character>
		consteval auto GivePlayerWingsAndDrop() const
		{
			return PlayerInstruction<character, 8>();
		}

		// Hurt the player with an imaginary source 80 fxu away
		// If the player is Luigi, spawn ouch stars as well. [sourceDir].
		template<CharacterID character>
		consteval auto HurtPlayer(s16 sourceDir) const
		{
			return PlayerInstruction<character, 9>(ToByteArray(sourceDir));
		}

		// A weird cap animation
		template<CharacterID character>
		consteval auto AnimatePlayerCap(u8 state) const
		{
			return PlayerInstruction<character, 10>(state);
		}

		// Turn the player via exponential decay. [NewAngle].
		template<CharacterID character>
		consteval auto TurnPlayerDec(s16 newAngleY) const
		{
			return PlayerInstruction<character, 11>(ToByteArray(newAngleY));
		}

		// Make the player move forward at a certain speed (does not change animation)
		template<CharacterID character>
		consteval auto MovePlayerForward() const
		{
			return PlayerInstruction<character, 12>();
		}
		
		// Kill the player
		template<CharacterID character>
		consteval auto KillPlayer() const
		{
			return PlayerInstruction<character, 13>();
		}
	};
}

consteval KuppaScriptImpl::Builder<> NewScript() { return {}; }

template<const auto builder> requires (
	std::same_as<decltype(builder),
	const KuppaScriptImpl::Builder<builder.data.size()>>
)
inline bool Run()
{
	static constinit auto script = builder.End();
	return script.Run();
}