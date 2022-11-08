#include "LightBeam.h"

namespace
{
	constexpr Vector3 LOOK_AT_OFFSET  = Vector3{ -0x3b0000_f, 0x200000_f, 0x120000_f };
	constexpr Vector3 POSITION_OFFSET = Vector3{ -0x3b0000_f, 0x0_f,      0x320000_f };
}

SharedFilePtr LightBeam::modelFile;

SpawnInfo LightBeam::spawnData =
{
	[]() -> ActorBase* { return new LightBeam; },
	0x0025,
	0x0144,
	0x00000003,
	0x00000000_f,
	0x007d0000_f,
	0x00fa0000_f,
	0x00000000_f
};

int LightBeam::InitResources()
{
	Model::LoadFile(modelFile);
	
	if (NumStars() < 14)
		return 0;
	
	if ((SAVE_DATA.miscStates1 & 0x80) != 0) // red switch active?
		return 0;
	
	model.SetFile(modelFile.filePtr, 1, 0x13);
	cylClsn.Init(*this, pos, 0xf0000_f, 0x8c000_f, (CylinderClsn::INTANGIBLE | CylinderClsn::INTERACT_WITH_PLAYER | CylinderClsn::SIGN), 0);
	
	UpdateModelTransform();
	
	return 1;
}

int LightBeam::CleanupResources()
{
	modelFile.Release();
	return 1;
}

int LightBeam::Behavior()
{
	Player* player;
	
	if (listener == nullptr)
	{
		if ((cylClsn.hitFlags & CylinderClsn::HIT_BY_PLAYER) != 0 && (player = (Player*)Actor::FindWithID(otherObjID), player != nullptr) && player->actorID == PLAYER_ACTOR_ID
			&& AngleDiff(pos.HorzAngle(player->pos), ang.y) < 0x4000 && player->floorBehavID == CLPS::BH_SWITCH_LEVEL_ENTRANCE && player->StartTalk(*this, false))
		{
			listener = player;
			soundTimer = 0;
		}
	}
	else
	{
		if (!PlaySmallSecretSound(*this, soundTimer); // 0x0200f874 (returns whether finished playing sound)
			return 1;
		
		player = listener;
		
		Matrix4x3_FromRotationY(MATRIX_SCRATCH_PAPER, ang.y);
		Vector3 lookAt = MATRIX_SCRATCH_PAPER(LOOK_AT_OFFSET) + pos;
		
		s32 talkState = player->GetTalkState();
		
		if (talkState == Player::TK_START)
		{
			if (ApproachLinear(player->ang.y, (s16)(ang.y + 0x8000), 0x800) != 0)
			{
				Message::PrepareTalk();
				player->ShowMessage(*this, 0x192, lookAt, 0, 0);
			}
		}
		else if (talkState != Player::TK_TALKING)
		{
			Message::EndTalk();
			listener = nullptr;
		}
	}
	
	Matrix4x3_FromRotationY(MATRIX_SCRATCH_PAPER, ang.y);
	
	cylClsn.pos = MATRIX_SCRATCH_PAPER(POSITION_OFFSET) + pos;
	cylClsn.radius = 0xf0000_f;
	
	cylClsn.Clear();
	cylClsn.Update();
	
	return 1;
}


int LightBeam::Render()
{
	model.Render(nullptr);
	return 1;
}

void LightBeam::UpdateModelTransform()
{
	Matrix4x3_FromRotationY(model.mat4x3, ang.y);
	model.mat4x3.c3 = pos >> 3;
}