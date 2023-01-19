#pragma once

struct ActorDerived : public ActorBase //internal name: dBase
{
	virtual void AfterInitResources(u32 vfSuccess) override; //Destroys Actor (ActorBase::Destroy) on vfunc failure, then calls ActorBase::AfterInitResources(u32)
	virtual ~ActorDerived() override;
	
	static ActorDerived* Spawn(u32 actorID, ActorBase* parent, s32 arg3, s32 arg4); // parent is often the scene
};

static_assert(sizeof(ActorDerived) == 0x50);