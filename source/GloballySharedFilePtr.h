#ifndef GLOBALLY_SHARED_FILE_PTR_INCLUDED
#define GLOBALLY_SHARED_FILE_PTR_INCLUDED

#include "SM64DS_2.h"

/*struct GloballySharedFilePtr
{
	static GloballySharedFilePtr* filePtrListStart;
	
	SharedFilePtr* original;     // null if this is the original
	GloballySharedFilePtr* next; // next in the linked list
	SharedFilePtr filePtr;
	
	SharedFilePtr& Get()
	{
		if (original != nullptr)
			return *original;
		else
			return filePtr;
	}

	void Construct(u32 ov0FileID)
	{
		for (auto ptr = filePtrListStart; ptr != nullptr; ptr = ptr->next)
		{
			if (ptr->filePtr.fileID == this->filePtr.fileID)
			{
				// the file already has a GloballySharedFilePtr, set the original
				this->original = &ptr->filePtr;
				this->next = nullptr;
				return;
			}
		}
		
		// the file doesn't have a GloballySharedFilePtr yet, add the GloballySharedFilePtr to the start of the linked list
		this->filePtr.Construct(ov0FileID);
		this->original = nullptr;
		this->next = filePtrListStart;
		filePtrListStart = this;
	}
	
	void Release()
	{
		
	}
};

GloballySharedFilePtr MyActor::modelFile;

s32 MyActor::InitResources()
{
	Model::LoadFile(modelFile.Get());
	return 1;
}

s32 MyActor::CleanupResources()
{
	modelFile.Get()->Release();
	return 1;
}*/

struct GloballySharedFilePtr
{
    static GloballySharedFilePtr* filePtrListStart;

    GloballySharedFilePtr* original; // null if this is the original
    GloballySharedFilePtr* nextUser;
    GloballySharedFilePtr* nextOwner;
    SharedFilePtr filePtr;
	
    void Construct(u32 ov0FileID)
    {
        this->filePtr.Construct(ov0FileID);

        for (auto ptr = filePtrListStart; ptr; ptr = ptr->nextOwner)
        {
            if (ptr->filePtr.fileID == this->filePtr.fileID)
            {
                this->original = ptr;
                this->nextUser = ptr->nextUser;
                ptr->nextUser = this;
                this->nextOwner = nullptr;
                return;
            }
        }

        this->original = nullptr;
        this->nextUser = nullptr;
        this->nextOwner = filePtrListStart;
        filePtrListStart = this;
    }
	
    void Destroy()
    {
        if (this->original)
        {
            GloballySharedFilePtr* prev = this->original;
            while (prev->nextUser != this) prev = prev->nextUser;
            prev->nextUser = this->nextUser;
        }
        else
        {
            GloballySharedFilePtr** ptrToThis = &filePtrListStart;
            while (*ptrToThis != this) ptrToThis = &(**ptrToThis).nextOwner;
            
            if (this->nextUser)
            {
                *ptrToThis = this->nextUser;
                this->nextUser->original = nullptr;
                this->nextUser->nextOwner = this->nextOwner;

                for (auto user = this->nextUser->nextUser; user; user = user->nextUser)
                    user->original = this->nextUser;

                this->nextUser->filePtr = this->filePtr;
            }
            else
                *ptrToThis = this->nextOwner;
        }
    }
	
	[[gnu::always_inline]]
    SharedFilePtr& Get()
    {
        if (this->original)
            return this->original->filePtr;
        else
            return this->filePtr;
    }
	
	[[gnu::always_inline]]
	char* GetFilePtr() { return Get().filePtr; }
	
	[[gnu::always_inline]]
	void Release() { Get().Release(); }
};

asm(R"(
.weak _ZN21GloballySharedFilePtr16filePtrListStartE
_ZN21GloballySharedFilePtr16filePtrListStartE = 0x023feff4
)");

/*
// the version of this that would be used if you don't want this code to be duplicated in multiple DLs, you'd need a build system that allows custom functions in arm9.bin to be called from DLs / overlays
class GloballySharedFilePtr
{
	static void DoConstruct(GloballySharedFilePtr& self, u32 ov0FileID)
	{
		  self.filePtr.Construct(ov0FileID);
		
		for (auto ptr = control.first; ptr; ptr = ptr->nextOwner)
		{
			if (ptr->filePtr.fileID == self.filePtr.fileID)
			{
				self.original = ptr;
				self.nextUser = ptr->nextUser;
				ptr->nextUser = &self;
				self.nextOwner = nullptr;
				return;
			}
		}

		self.original = nullptr;
		self.nextUser = nullptr;
		self.nextOwner = control.first;
		control.first = &self;
	}
	
	static void DoDestroy(GloballySharedFilePtr& self)
	{
		if (self.original)
		{
			GloballySharedFilePtr* prev = self.original;
			while (prev->nextUser != &self) prev = prev->nextUser;
			prev->nextUser = self.nextUser;
		}
		else
		{
			GloballySharedFilePtr** ptrToThis = &control.first;
			while (*ptrToThis != &self) ptrToThis = &(**ptrToThis).nextOwner;
			
			if (self.nextUser)
			{
				*ptrToThis = self.nextUser;
				self.nextUser->original = nullptr;
				self.nextUser->nextOwner = self.nextOwner;

				for (auto user = self.nextUser->nextUser; user; user = user->nextUser)
					user->original = self.nextUser;

				self.nextUser->filePtr = self.filePtr;
			}
			else
				*ptrToThis = self.nextOwner;
		}
	}

	struct Control
	{
		GloballySharedFilePtr* first;
		decltype(DoConstruct)* construct;
		decltype(DoDestroy)* destroy;

		void Init()
		{
			first = nullptr;
			construct = &DoConstruct;
			destroy = &DoDestroy;
		}
	}
	static control;

	GloballySharedFilePtr* original; // null if this is the original
	GloballySharedFilePtr* nextUser;
	GloballySharedFilePtr* nextOwner;
	SharedFilePtr filePtr;

public:
	[[gnu::always_inline]]
	SharedFilePtr& Get()
	{
		if (original)
			return original->filePtr;
		else
			return filePtr;
	}
	
	[[gnu::always_inline]]
	char* GetFilePtr() { return Get().filePtr; }
	
	[[gnu::always_inline]]
	void Release() { Get().Release(); }
	
	[[gnu::always_inline]]
	void Construct(u32 ov0FileID) { control.construct(*this, ov0FileID); }
	
	[[gnu::always_inline]]
	void Destroy() { control.destroy(*this); }
};

asm(R"(
.weak _ZN21GloballySharedFilePtr7controlE
_ZN21GloballySharedFilePtr7controlE = 0x023feff4
)");*/

#endif