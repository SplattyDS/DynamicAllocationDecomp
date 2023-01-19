#pragma once

struct PathPtr
{
	const LVL_Overlay::PathObj* ptr;
	
	// originally contains this second member, but none of the documented
	// functions use it so it's commented out for better performance
	u32 unk04;
	
	PathPtr() : ptr(nullptr) {}
	PathPtr(const LVL_Overlay::PathObj* path) : ptr(path) {}
	PathPtr(const LVL_Overlay::PathObj& path) : ptr(&path) {}
	explicit PathPtr(u32 pathID) { FromID(pathID); }
	explicit PathPtr(s32 pathID) : PathPtr((u32)pathID) {}
	
	void FromID(u32 pathID);
	void GetNode(Vector3& vF, u32 index) const;
	u32 NumNodes() const;
	bool Loops() const;
	
	[[gnu::always_inline, nodiscard]]
	auto GetNode(const u32& index) const
	{
		return Vector3::Proxy([this, &index]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			GetNode(res, index);
		});
	}
	
	[[gnu::always_inline, nodiscard]]
	auto operator[](const std::integral auto& index) const { return GetNode(index); }
	
	inline const LVL_Overlay::PathObj& operator* () const { return *ptr; }
	inline const LVL_Overlay::PathObj* operator->() const { return ptr; }
	
	inline explicit operator bool() const { return ptr != nullptr; }
	
	inline bool operator==(const PathPtr& other) const { return this->ptr == other.ptr; }
	
	inline operator const LVL_Overlay::PathObj*      &()       { return ptr; }
	inline operator const LVL_Overlay::PathObj* const&() const { return ptr; }
};