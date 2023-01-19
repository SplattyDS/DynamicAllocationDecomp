#pragma once

struct SharedFilePtr
{
	u16 fileID;
	u8 numRefs;
	char* filePtr;
	
	SharedFilePtr& Construct(u32 ov0FileID);
	char* Load();
	char* LoadFile(); // calls Load() and updates numRefs
	void Release();
	
	[[gnu::always_inline]]
	SharedFilePtr& Get()
	{
		return *this;
	}
	
	[[gnu::always_inline]]
	char* GetFilePtr() const { return filePtr; }
	
	[[gnu::always_inline]]
	BCA_File* BCA() const { return (BCA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMA_File* BMA() const { return (BMA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMD_File* BMD() const { return (BMD_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTA_File* BTA() const { return (BTA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTP_File* BTP() const { return (BTP_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTX_File* BTX() const { return (BTX_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	DYLB_File* DYLB() const { return (DYLB_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	KCL_File* KCL() const { return (KCL_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	MESG_File* MESG() const { return (MESG_File*)GetFilePtr(); }
};

struct GloballySharedFilePtr
{
    GloballySharedFilePtr* original; // null if this is the original
    GloballySharedFilePtr* nextUser;
    GloballySharedFilePtr* nextOwner;
    SharedFilePtr filePtr;
	
    static GloballySharedFilePtr* filePtrListStart;
	
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
		if (original)
			return original->filePtr;
		else
			return filePtr;
	}
	
	[[gnu::always_inline]]
	char* GetFilePtr() { return Get().filePtr; }
	
	[[gnu::always_inline]]
	BCA_File* BCA() { return (BCA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMA_File* BMA() { return (BMA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMD_File* BMD() { return (BMD_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTA_File* BTA() { return (BTA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTP_File* BTP() { return (BTP_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTX_File* BTX() { return (BTX_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	DYLB_File* DYLB() { return (DYLB_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	KCL_File* KCL() { return (KCL_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	MESG_File* MESG() { return (MESG_File*)GetFilePtr(); }
	
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
	BCA_File* BCA() { return (BCA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMA_File* BMA() { return (BMA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BMD_File* BMD() { return (BMD_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTA_File* BTA() { return (BTA_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTP_File* BTP() { return (BTP_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	BTX_File* BTX() { return (BTX_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	DYLB_File* DYLB() { return (DYLB_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	KCL_File* KCL() { return (KCL_File*)GetFilePtr(); }
	
	[[gnu::always_inline]]
	MESG_File* MESG() { return (MESG_File*)GetFilePtr(); }
	
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