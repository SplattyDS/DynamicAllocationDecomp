#pragma once

#include "ostream.h"
#include <cstdint>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <numeric>
#include <limits>

// Note: vector and matrix structures defined in this file use
// attributes on lambda expressions as in proposal P2173R0

using s8  = int8_t;  using u8  = uint8_t;
using s16 = short;   using u16 = uint16_t;
using s32 = int;     using u32 = unsigned;
using s64 = int64_t; using u64 = uint64_t;

constexpr s32 NUM_LEVELS = 52;
constexpr s32 NUM_MAIN_LEVELS = 15;
constexpr s32 NUM_SECRET_LEVELS = 15;
constexpr s32 NUM_MINIGAMES = 36;

struct Actor;
struct Player;

namespace cstd
{
	s32 div(s32 numerator, s32 denominator);
	s32 mod(s32 numerator, s32 denominator);
	s32 fdiv(s32 numerator, s32 denominator); // returns a Q12 number
	s64 ldiv(s32 numerator, s32 denominator); // returns a Q32 number
}

extern "C"
{
	u16 DecIfAbove0_Short(u16& counter); // returns the counter's new value
	u8 DecIfAbove0_Byte(u8& counter);    // returns the counter's new value
}

// returns whether the counter reached its destination
bool ApproachLinear(s16& counter, s16 dest, s16 step);
bool ApproachLinear(s32& counter, s32 dest, s32 step);
bool ApproachLinear2(s16& counter, s16 dest, s16 step);
bool ApproachLinear2(s32& counter, s32 dest, s32 step);

struct AsRaw {} constexpr as_raw;

template<class T> // a valid underlying representation of a fixed-point number
concept FixUR = std::is_integral_v<T> && std::is_signed_v<T> && sizeof(T) <= sizeof(s32);

template<FixUR T, s32 q, template<FixUR> class CRTP>
struct Fix
{
	T val;

	using Promoted = CRTP<s32>;

	constexpr Fix() = default;
	constexpr Fix(T val) : val(val << q) {}
	constexpr Fix(T val, AsRaw) : val(val) {}
	// constexpr explicit Fix(long double val) : val(val * (1ll << q) + 0.5l) {}
	constexpr explicit Fix(long double val) : val(val * (1ll << q)) {} // SM64DS rounds down (0.1_f becomes 0x199, not 0x19a)

	template<FixUR U, s32 r, template<class> class CRTP2>
	constexpr Fix(Fix<U, r, CRTP2> f, AsRaw) : val(f.val) {}

	template<FixUR U>
	constexpr Fix(CRTP<U> f) : val(f.val) {}

	friend constexpr
	Promoted operator+ (CRTP<T> f) { return {f.val, as_raw}; }

	friend constexpr
	Promoted operator- (CRTP<T> f) { return {-f.val, as_raw}; }

	template<FixUR U> friend constexpr
	Promoted operator+ (CRTP<T> f0, CRTP<U> f1) { return {f0.val + f1.val, as_raw}; }

	template<FixUR U> friend constexpr
	Promoted operator- (CRTP<T> f0, CRTP<U> f1) { return {f0.val - f1.val, as_raw}; }

	template<FixUR U> friend constexpr
	CRTP<T>& operator+=(CRTP<T>& f0, CRTP<U> f1) { f0.val += f1.val; return f0; }
 
	template<FixUR U> friend constexpr
	CRTP<T>& operator-=(CRTP<T>& f0, CRTP<U> f1) { f0.val -= f1.val; return f0; }

	friend constexpr Promoted operator+ (s32 i,  CRTP<T> f) { return Promoted(i) + f; }
	friend constexpr Promoted operator- (s32 i,  CRTP<T> f) { return Promoted(i) - f; }
	friend constexpr Promoted operator+ (CRTP<T>  f, s32 i) { return f + Promoted(i); }
	friend constexpr Promoted operator- (CRTP<T>  f, s32 i) { return f - Promoted(i); }
	friend constexpr CRTP<T>& operator+=(CRTP<T>& f, s32 i) { return f += Promoted(i); }
	friend constexpr CRTP<T>& operator-=(CRTP<T>& f, s32 i) { return f -= Promoted(i); }

	friend constexpr Promoted operator* (s32 i,  CRTP<T> f) { return {i * f.val, as_raw}; }
	friend constexpr Promoted operator* (CRTP<T>  f, s32 i) { return {f.val * i, as_raw}; }
	friend constexpr Promoted operator/ (CRTP<T>  f, s32 i) { return {f.val / i, as_raw}; }
	friend constexpr CRTP<T>& operator*=(CRTP<T>& f, s32 i) { f.val *= i; return f; }
	friend constexpr CRTP<T>& operator/=(CRTP<T>& f, s32 i) { f.val /= i; return f; }

	friend constexpr Promoted operator<< (CRTP<T>  f, s32 i) { return {f.val << i, as_raw}; }
	friend constexpr Promoted operator>> (CRTP<T>  f, s32 i) { return {f.val >> i, as_raw}; }
	friend constexpr CRTP<T>& operator<<=(CRTP<T>& f, s32 i) { f.val <<= i; return f; }
	friend constexpr CRTP<T>& operator>>=(CRTP<T>& f, s32 i) { f.val >>= i; return f; }
	friend constexpr Promoted operator&  (CRTP<T>  f, s32 i) { return {f.val &  i, as_raw}; }
	friend constexpr CRTP<T>& operator&= (CRTP<T>& f, s32 i) { f.val &=  i; return f; }
	friend constexpr Promoted operator|  (CRTP<T>  f, s32 i) { return {f.val |  i, as_raw}; }
	friend constexpr CRTP<T>& operator|= (CRTP<T>& f, s32 i) { f.val |=  i; return f; }

	template<FixUR U> [[gnu::always_inline, nodiscard]] friend
	Promoted operator*(CRTP<T> f0, CRTP<U> f1)
	{
		const u64 product = static_cast<s64>(f0.val) * f1.val;
		Promoted result;
		
		asm(R"(
			movs %[rs], %[lo], lsr %[s0]
			adc  %[rs], %[rs], %[hi], lsl %[s1]
		)":
		[rs] "=&r" (result) :
		[lo] "r" (static_cast<u32>(product)),
		[hi] "r" (static_cast<u32>(product >> 32)),
		[s0] "I" (q),
		[s1] "I" (32 - q) : "cc");
		
		return result;
	}
	
	template<FixUR U> friend inline
	CRTP<T>& operator*=(CRTP<T>& f0, CRTP<U> f1) { return f0 = f0 * f1; }

	template<FixUR U> friend constexpr
	bool operator==(CRTP<T> f0, CRTP<U> f1) { return f0.val == f1.val; }

	template<FixUR U> friend constexpr
	bool operator< (CRTP<T> f0, CRTP<U> f1) { return f0.val <  f1.val; }

	template<FixUR U> friend constexpr
	bool operator<=(CRTP<T> f0, CRTP<U> f1) { return f0.val <= f1.val; }

	template<FixUR U> friend constexpr
	bool operator> (CRTP<T> f0, CRTP<U> f1) { return f0.val >  f1.val; }

	template<FixUR U> friend constexpr
	bool operator>=(CRTP<T> f0, CRTP<U> f1) { return f0.val >= f1.val; }
	
	static constexpr CRTP<T> max {std::numeric_limits<T>::max(), as_raw};
	static constexpr CRTP<T> min {std::numeric_limits<T>::min(), as_raw};
	
	static constexpr CRTP<T> pi = []
	{
		const int shift = 8 * static_cast<int>(sizeof(T)) - q;
		
		int64_t raw = 0x3243f6a89ll;
		
		if (q < 32)
			raw += 1 << (31 - q);
		
		return CRTP<T> {raw >> shift, as_raw};
	}();

	constexpr Promoted friend Abs(CRTP<T> f) { return f.val >= 0 ? f : -f; }
	constexpr explicit operator T() const { return val >> q; }
	constexpr explicit operator bool() const { return val != 0; }

	bool ApproachLinear(Promoted dest, Promoted step) & { return ::ApproachLinear(val, dest.val, step.val); }
};

template<FixUR T>
struct Fix12 : Fix<T, 12, Fix12>
{
	using Fix<T, 12, Fix12>::Fix;

	Fix12<s32> operator/ (Fix12 f) const { return {cstd::fdiv(this->val, f.val), as_raw}; }
	Fix12&     operator/=(Fix12 f) & { this->val = cstd::fdiv(this->val, f.val); return *this; }
};

using Fix12i = Fix12<s32>;
using Fix12s = Fix12<s16>;

consteval Fix12i operator""_f (u64 val) { return Fix12i(val, as_raw); }
consteval Fix12s operator""_fs(u64 val) { return Fix12s(val, as_raw); }

consteval Fix12i operator""_f (long double val) { return Fix12i(val); }
consteval Fix12s operator""_fs(long double val) { return Fix12s(val); }

consteval s32 operator""_deg(long double val) { return val * 32768.L / 180.L; }
consteval s32 operator""_deg(u64 val) { return operator""_deg(static_cast<long double>(val)); }

consteval s32 operator""_rad(long double val) { return val * 32768.L / 3.141592653589793238462643383279502884L; }
consteval s32 operator""_rad(u64 val) { return operator""_rad(static_cast<long double>(val)); }

namespace cstd
{
	Fix12i fdiv(Fix12i numerator, Fix12i denominator);
	Fix12i finv(Fix12i denominator); // inverse
	u32 sqrt(u64 x); // 64 bit unsigned sqrt
	inline Fix12i sqrt(Fix12i x) { return Fix12i(sqrt(static_cast<u64>(x.val) << 12), as_raw); }

	s16 atan2(Fix12i y, Fix12i x); //atan2 function, what about 0x020538b8?
	s32 abs(s32 x);

	s32 strcmp(const char* str1, const char* str2); //returns 0 if equal, a positive number if str1 comes after str2, and a negative number otherwise
	char* strncpy(char* dest, const char* src, u32 count);	//Copies n bytes from src to dest and returns a pointer to dest
	char* strchr(const char* str, char c); //Searches for c in str and returns a pointer to the first occurence, or 0 if c could not be found
	u32 strlen(const char* str); //Returns the length of the string or -1 if no null-terminator has been found
}

struct UnknownStruct
{
	u32 unk00;
	u32 unk04;
	u16 unk08;
	u16 buttonsHeld;
	u16 cameraAngleY;
	u16 unk0e;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
};

struct Vector3;
struct Vector3_16;
struct Matrix4x3;
struct Matrix3x3;
struct Quaternion;
struct SharedFilePtr;

// returns whether the pos reached its destination
bool ApproachLinear(Vector3& pos, const Vector3& dest, Fix12i step);

extern "C"
{	
	extern u16 POWERS_OF_TEN[3]; //100, 10, 1
	extern char DIGIT_ENC_ARR[10];

	extern u16 HEALTH_ARR[4];
	extern s32 UNUSED_RAM[0xec00];
	
	extern s32 RNG_STATE; //x => x * 0x0019660d + 0x3c6ef35f
	
	extern Matrix4x3 MATRIX_SCRATCH_PAPER;
	extern u32 FRAME_COUNTER;

	extern const Fix12s SINE_TABLE[0x2000];
	extern const Fix12s ATAN_TABLE[0x400];
	
	void UnloadOverlay(s32 ovID);
	void LoadOverlay(s32 ovID);
	char* LoadFile(s32 ov0FileID);
	void LoadTextNarcs();
	bool LoadArchive(u32 archiveID);
	void UnloadArchive(s32 archiveID);
	
	[[noreturn]] void Crash();
	
	s16 ApproachAngle(s16& angle, s32 targetAngle, s32 invFactor, s32 maxDelta, s32 minDelta); // the old LeanPlayerForwardWhileRunning
	u16 AngleDiff(s16 ang0, s16 ang1) __attribute__((const)); // from 0 to 0x8000 inclusive (0° - 180°)
	void Vec3_RotateYAndTranslate(Vector3& res, const Vector3& translation, s16 angY, const Vector3& v); //res and v cannot alias.
	s16 Vec3_VertAngle(const Vector3& v1, const Vector3& v0) __attribute__((pure));
	s16 Vec3_HorzAngle(const Vector3& v0, const Vector3& v1) __attribute__((pure));
	s32 RandomIntInternal(s32* randomIntStatePtr);
	void Matrix3x3_FromQuaternion(const Quaternion& q, Matrix3x3& mF);
	void Matrix4x3_FromTranslation(Matrix4x3& mF, Fix12i x, Fix12i y, Fix12i z);
	void Matrix4x3_FromRotationZ(Matrix4x3& mF, s16 angZ);
	void Matrix4x3_FromRotationY(Matrix4x3& mF, s16 angY);
	void Matrix4x3_FromRotationX(Matrix4x3& mF, s16 angX);
	void Matrix4x3_FromRotationZXYExt(Matrix4x3& mF, s16 angX, s16 angY, s16 angZ); //yxz intrinsic = zxy extrinsic
	void Matrix4x3_FromRotationXYZExt(Matrix4x3& mF, s16 angX, s16 angY, s16 angZ); //zyx intrinsic = xyz extrinsic
	void Matrix4x3_FromQuaternion(const Quaternion& q, Matrix4x3& mF);
	void Matrix4x3_ApplyInPlaceToRotationZ(Matrix4x3& mF, s16 angZ); //transforms a rotation matrix using matrix mF.
	void Matrix4x3_ApplyInPlaceToRotationY(Matrix4x3& mF, s16 angY); //does not apply a rotation matrix.
	void Matrix4x3_ApplyInPlaceToRotationX(Matrix4x3& mF, s16 angX); //don't get the two confused.
	void Matrix4x3_ApplyInPlaceToRotationZXYExt(Matrix4x3& mF, s16 angX, s16 angY, s16 angZ);
	void Matrix4x3_ApplyInPlaceToRotationXYZExt(Matrix4x3& mF, s16 angX, s16 angY, s16 angZ);
	void Matrix4x3_ApplyInPlaceToTranslation(Matrix4x3& mF, Fix12i x, Fix12i y, Fix12i z);
	void Matrix4x3_ApplyInPlaceToScale(Matrix4x3& mF, Fix12i x, Fix12i y, Fix12i z);
	
	void Quaternion_FromVector3(Quaternion& qF, const Vector3& v0, const Vector3& v1);
	void Quaternion_Normalize(Quaternion& q);
	void Quaternion_SLerp(const Quaternion& q1, const Quaternion& q2, Fix12i weight, Quaternion& qF);
	
	Fix12i Vec3_HorzDist(const Vector3& v0, const Vector3& v1) __attribute__((pure));
	Fix12i Vec3_HorzLen(const Vector3& v0) __attribute__((pure));
	Fix12i Vec3_Dist(const Vector3& v0, const Vector3& v1) __attribute__((pure));
	bool Vec3_Equal(const Vector3& v0, const Vector3& v1) __attribute__((pure));
	void Vec3_LslInPlace(Vector3& v, s32 shift);
	void Vec3_Lsl(Vector3& res, const Vector3& v, s32 shift);
	void Vec3_AsrInPlace(Vector3& v, s32 shift);
	void Vec3_Asr(Vector3& res, const Vector3& v, s32 shift);
	void Vec3_DivScalarInPlace(Vector3& v, Fix12i scalar);
	void Vec3_MulScalarInPlace(Vector3& v, Fix12i scalar);
	void Vec3_MulScalar(Vector3& res, const Vector3& v, Fix12i scalar);
	void Vec3_Sub(Vector3& res, const Vector3& v0, const Vector3& v1); // not as efficient as SubVec3
	void Vec3_Add(Vector3& res, const Vector3& v0, const Vector3& v1); // not as efficient as AddVec3
	
	void Matrix3x3_LoadIdentity(Matrix3x3& mF);
	void MulVec3Mat3x3(const Vector3& v, const Matrix3x3& m, Vector3& res);
	void MulMat3x3Mat3x3(const Matrix3x3& m1, const Matrix3x3& m0, Matrix3x3& mF); //m0 is applied to m1, so it's m0*m1=mF
	void Matrix4x3_LoadIdentity(Matrix4x3& mF);
	 // long call to force gcc to actually call the off-by-one address and therefore set the mode to thumb.
	void Matrix4x3_FromScale(Matrix4x3& mF, Fix12i x, Fix12i y, Fix12i z) __attribute__((long_call, target("thumb")));
	void MulVec3Mat4x3(const Vector3& v, const Matrix4x3& m, Vector3& res);
	void MulMat4x3Mat4x3(const Matrix4x3& m1, const Matrix4x3& m0, Matrix4x3& mF); //m0 is applied to m1, so it's m0*m1=mF
	void InvMat4x3(const Matrix4x3& m0, Matrix4x3& mF);		//Loads inverse of m0 into mF
	void NormalizeVec3(const Vector3& v, Vector3& res);
	bool NormalizeVec3IfNonZero(Vector3& v); // returns whether non-zero
	void CrossVec3(const Vector3& v0, const Vector3& v1, Vector3& res);
	void AddVec3(const Vector3& v0, const Vector3& v1, Vector3& res);
	void SubVec3(const Vector3& v0, const Vector3& v1, Vector3& res);
	Fix12i LenVec3(const Vector3& v);
	Fix12i DotVec3(const Vector3& v0, const Vector3& v1) __attribute__((pure));
	
	void Matrix3x3_SetRotationX(Matrix3x3& m, Fix12i sinTheta, Fix12i cosTheta) __attribute__((long_call, target("thumb"))); //Resets m to an X rotation matrix
	void Matrix3x3_SetRotationY(Matrix3x3& m, Fix12i sinTheta, Fix12i cosTheta) __attribute__((long_call, target("thumb"))); //Resets m to a Y rotation matrix
	void Matrix3x3_SetRotationZ(Matrix3x3& m, Fix12i sinTheta, Fix12i cosTheta) __attribute__((long_call, target("thumb"))); //Resets m to a Z rotation matrix
	
	void MultiStore_Int(s32 val, void* dest, s32 byteSize);
	void MultiCopy_Int(void* source, void* dest, s32 byteSize);
	
	u16 Color_Interp(u16* dummyArg, u16 startColor, u16 endColor, Fix12i time) __attribute__((const));
	
	Fix12i Math_Function_0203b14c(Fix12i& arg1, Fix12i arg2, Fix12i arg3, Fix12i arg4, Fix12i arg5);
	void Math_Function_0203b0fc(Fix12i& arg1, Fix12i arg2, Fix12i arg3, Fix12i arg4);
}

[[gnu::always_inline]]
inline s32 RandomInt() { return RandomIntInternal(&RNG_STATE); }

[[gnu::always_inline]]
inline bool RandomBit(s32 bit)
{
	return RandomInt() & (1 << bit);
}

// returns an angle from 0 to maxAng - 1, if maxAng has a single set bit
[[gnu::always_inline]]
inline s16 RandomAng(s16 maxAng)
{
	return RandomInt() & (maxAng - 1);
}

consteval s32 CountSetBits(u32 num)
{
	s32 setBits = 0;
	
	for (s32 i = 0; i < 32; i++)
		if ((num & (1 << i)) != 0)
			setBits++;
	
	return setBits;
}

struct Vector2     { Fix12i x, y; };
struct Vector2_16  { s16  x, y; };
struct Vector3_16  { s16  x, y, z; };
struct Vector3_16f { Fix12s x, y, z; };

template<class T>
struct UnaliasedRef
{
	T& r;

	constexpr UnaliasedRef(T& r) [[gnu::always_inline]] : r(r) {}

	[[gnu::always_inline]]
	T& operator=(auto&& proxy)
	{
		proxy.template Eval<false>(r);

		return r;
	}
};

template<class T>
concept HasProxy = []() consteval
{
	using F = decltype([]<bool>(auto&){});

	if constexpr (requires { typename T::Proxy<F>; })
		return std::constructible_from<T, typename T::Proxy<F>>;
	else
		return false;
}();

template<HasProxy T> [[gnu::always_inline, nodiscard]]
constexpr UnaliasedRef<T> AssureUnaliased(T& t) { return t; }

template<class T> [[gnu::always_inline, nodiscard]]
constexpr T& AssureUnaliased(T& t) { return t; }

[[nodiscard]]
constexpr s32 Lerp(s32 a, s32 b, Fix12i t)
{
	return static_cast<s32>(t * (b - a)) + a;
}

struct Vector3
{
	template<class F>
	class Proxy
	{
		F eval;

		template<class G>
		using NewProxy = Proxy<G>;

	public:
		[[gnu::always_inline]]
		constexpr explicit Proxy(F&& eval) : eval(eval) {}

		template<bool resMayAlias> [[gnu::always_inline]]
		void Eval(Vector3& res) { eval.template operator()<resMayAlias>(res); }

		[[gnu::always_inline, nodiscard]]
		Fix12i Dist(const Vector3& v) && { return static_cast<Vector3>(std::move(*this)).Dist(v); }

		[[gnu::always_inline, nodiscard]]
		Fix12i HorzDist(const Vector3& v) && { return static_cast<Vector3>(std::move(*this)).HorzDist(v); }

		[[gnu::always_inline, nodiscard]]
		Fix12i Len() && { return static_cast<Vector3>(std::move(*this)).Len(); }

		[[gnu::always_inline, nodiscard]]
		Fix12i HorzLen() && { return static_cast<Vector3>(std::move(*this)).HorzLen(); }

		[[gnu::always_inline, nodiscard]]
		Fix12i Dot (const Vector3& v) && { return static_cast<Vector3>(std::move(*this)).Dot(v); }

		[[gnu::always_inline, nodiscard]]
		s16  HorzAngle(const Vector3& v) && { return static_cast<Vector3>(std::move(*this)).HorzAngle(v); }

		[[gnu::always_inline, nodiscard]]
		s16  VertAngle(const Vector3& v) && { return static_cast<Vector3>(std::move(*this)).VertAngle(v); }

		[[gnu::always_inline, nodiscard]]
		auto Cross(const Vector3& v) &&
		{
			return NewProxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				if constexpr (resMayAlias)
				{
					const Vector3 temp = v;
					Eval<resMayAlias>(res);
					CrossVec3(res, temp, res);
				}
				else
				{
					Eval<resMayAlias>(res);
					CrossVec3(res, v, res);	
				}
			});
		}

		template<class G>
		[[gnu::always_inline, nodiscard]]
		auto Cross(Proxy<G>&& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				CrossVec3(res, std::move(other), res);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto Normalized() &&
		{
			return NewProxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res.Normalize();
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto NormalizedTwice() &&
		{
			return NewProxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res.NormalizeTwice();
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto AngleTo(const Vector3& other) &&
		{
			return static_cast<Vector3>(std::move(*this)).AngleTo(other);
		}

		[[gnu::always_inline, nodiscard]]
		auto operator-() &&
		{
			return NewProxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res.x = -res.x;
				res.y = -res.y;
				res.z = -res.z;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator+(const Vector3& v) && { return v + std::move(*this); }

		[[gnu::always_inline, nodiscard]]
		auto operator-(const Vector3& v) &&
		{
			return NewProxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				if constexpr (resMayAlias)
				{
					const Vector3 temp = v;
					Eval<resMayAlias>(res);
					res -= temp;
				}
				else
				{
					Eval<resMayAlias>(res);
					res -= v;
				}
			});
		}

		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator+(Proxy<G>&& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res += static_cast<Vector3>(std::move(other));
			});
		}

		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator-(Proxy<G>&& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res -= static_cast<Vector3>(std::move(other));
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator*(const Fix12i& scalar) &&
		{
			return NewProxy([this, &scalar]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res *= scalar;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator/(const Fix12i& scalar) &&
		{
			return NewProxy([this, &scalar]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res /= scalar;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator<<(const s32& shift) &&
		{
			return NewProxy([this, &shift]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res <<= shift;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator>>(const s32& shift) &&
		{
			return NewProxy([this, &shift]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				Eval<resMayAlias>(res);
				res >>= shift;
			});
		}
	};

	Fix12i x, y, z;

	constexpr Vector3() = default;
	constexpr Vector3(auto x, auto y, auto z) : x(x), y(y), z(z) {}

	[[gnu::noinline, gnu::noclone]]
	constexpr Vector3(const Vector3_16& v): x(v.x), y(v.y), z(v.z) {}

	template<class F> [[gnu::always_inline]]
	Vector3(Proxy<F>&& proxy) { proxy.template Eval<false>(*this); }

	template<class F> [[gnu::always_inline]]
	Vector3& operator=(Proxy<F>&& proxy) & { proxy.template Eval<true>(*this); return *this; }

	[[gnu::always_inline, nodiscard]]
	static constexpr auto Temp(const auto& x, const auto& y, const auto& z)
	{
		return Proxy([&x, &y, &z]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			res.x = x;
			res.y = y;
			res.z = z;
		});
	}

	[[gnu::always_inline, nodiscard]]
	static constexpr auto Raw(const auto& x, const auto& y, const auto& z)
	{
		return Proxy([&x, &y, &z]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			res.x.val = x.val;
			res.y.val = y.val;
			res.z.val = z.val;
		});
	}

	[[gnu::always_inline, nodiscard]]
	static constexpr auto Raw(const auto& v)
	{
		return Proxy([&v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			const auto& [x, y, z] = v;

			res.x.val = x.val;
			res.y.val = y.val;
			res.z.val = z.val;
		});
	}

	Vector3& operator+= (const Vector3& v) &     { AddVec3(*this, v, *this); return *this; }
	Vector3& operator-= (const Vector3& v) &     { SubVec3(*this, v, *this); return *this; }
	Vector3& operator*= (Fix12i scalar)    &     { Vec3_MulScalarInPlace(*this, scalar); return *this; }
	Vector3& operator/= (Fix12i scalar)    &     { Vec3_DivScalarInPlace(*this, scalar); return *this; }
	Vector3& operator<<=(s32 shift)        &     { Vec3_LslInPlace(*this, shift); return *this; }
	Vector3& operator>>=(s32 shift)        &     { Vec3_AsrInPlace(*this, shift); return *this; }
	Fix12i   Dist       (const Vector3& v) const { return Vec3_Dist(*this, v); }
	Fix12i   HorzDist   (const Vector3& v) const { return Vec3_HorzDist(*this, v); }
	Fix12i   Len        ()                 const { return LenVec3(*this); }
	Fix12i   HorzLen    ()                 const { return Vec3_HorzLen(*this); }
	Fix12i   Dot        (const Vector3& v) const { return DotVec3(*this, v); }
	s16      HorzAngle  (const Vector3& v) const { return Vec3_HorzAngle(*this, v); }
	s16      VertAngle  (const Vector3& v) const { return Vec3_VertAngle(*this, v); }

	Vector3& operator*=(const auto& m) & { return *this = m * *this; }

	[[gnu::always_inline]]
	bool operator== (const Vector3& other) const& { return Vec3_Equal(*this, other); }

	// use an inlinable version if either operand is a proxy
	template<class T, class F> [[gnu::always_inline]] friend
	bool operator== (T&& any, Proxy<F>&& proxy)
	{
		const Vector3& v0 = std::forward<T>(any);
		const Vector3& v1 = std::move(proxy);

		return v0.x == v1.x && v0.y == v1.y && v0.z == v1.z;
	}

	[[gnu::always_inline, nodiscard]]
	auto operator-() const
	{
		return Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			res.x = -x;
			res.y = -y;
			res.z = -z;
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator+(const Vector3& v) const
	{
		return Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			AddVec3(*this, v, res);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator-(const Vector3& v) const
	{
		return Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			SubVec3(*this, v, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator+(Proxy<F>&& proxy) const
	{
		return Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				res += temp;
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				res += *this;
			}
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator-(Proxy<F>&& proxy) const
	{
		return Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				SubVec3(temp, res, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				SubVec3(*this, res, res);
			}
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator* (const Fix12i& scalar) const
	{
		return Proxy([this, &scalar]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			Vec3_MulScalar(res, *this, scalar);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator/ (const Fix12i& scalar) const
	{
		return Proxy([this, &scalar]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			res = *this; // no DivScalar exists.
			res /= scalar;
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator<<(const s32& shift) const
	{
		return Proxy([this, &shift]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			Vec3_Lsl(res, *this, shift);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator>>(const s32& shift) const
	{
		return Proxy([this, &shift]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			Vec3_Asr(res, *this, shift);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto Normalized() const
	{
		return Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			NormalizeVec3(*this, res);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto NormalizedTwice() const
	{
		return Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			NormalizeVec3(*this, res);
			res.Normalize();
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto Cross(const Vector3& v) const
	{
		return Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			CrossVec3(*this, v, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto Cross(Proxy<F>&& proxy)
	{
		return Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				CrossVec3(temp, res, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				CrossVec3(*this, res, res);	
			}
		});
	}

	[[gnu::always_inline]]
	void Normalize() & { NormalizeVec3(*this, *this); }
	void NormalizeTwice() & { Normalize(); Normalize(); }
	
	[[gnu::always_inline]]
	bool NormalizeIfNonZero() & { return NormalizeVec3IfNonZero(*this); }

	[[gnu::always_inline, nodiscard]]
	auto RotateYAndTranslate(const Vector3& translation, const s16& angY) const
	{
		return Proxy([this, &translation, &angY]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			Vec3_RotateYAndTranslate(res, translation, angY, *this);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto RotateYAndTranslate(Proxy<F>&& proxy, const s16& angY) const
	{
		return Proxy([this, &proxy, &angY]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				Vec3_RotateYAndTranslate(res, res, angY, temp);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				Vec3_RotateYAndTranslate(res, res, angY, *this);
			}
		});
	}

	s32 AngleTo(const Vector3& other) const
	{
		return cstd::atan2(this->Cross(other).Len(), this->Dot(other)) & 0xffff;
	}

	[[gnu::always_inline, nodiscard]]
	friend auto Lerp(const Vector3& a, const Vector3& b, const auto& t)
	{
		return Proxy([&a, &b, &t]<bool resMayAlias> [[gnu::always_inline]] (auto& res)
		{
			if constexpr (resMayAlias)
				res = t * (b - a) + a;
			else
				AssureUnaliased(res) = t * (b - a) + a;
		});
	}

	template<class Rotator> requires(sizeof(Rotator) > 4) [[gnu::noinline, gnu::noclone]]
	Vector3& RotateAround(const Vector3& pivot, const Rotator& rotator)
	{
		return *this = Lerp(pivot, *this, rotator);
	}

	template<class Rotator> requires(sizeof(Rotator) <= 4) [[gnu::noinline, gnu::noclone]]
	Vector3& RotateAround(const Vector3& pivot, Rotator rotator)
	{
		return *this = Lerp(pivot, *this, rotator);
	}
};

[[gnu::always_inline, nodiscard]]
inline auto operator* (const Fix12i& scalar, const Vector3& v) { return v * scalar; }

template<class F> [[gnu::always_inline, nodiscard]]
inline auto operator* (const Fix12i& scalar, Vector3::Proxy<F>&& proxy) { return std::move(proxy) * scalar; }

struct Matrix2x2 // Matrix is column-major!
{
	Vector2 c0;
	Vector2 c1;
};

struct Matrix3x3 // Matrix is column-major!
{
	Vector3 c0, c1, c2;

	template<class F>
	class Proxy
	{
		F eval;

		template<class G>
		using NewProxy = Proxy<G>;

	public:

		[[gnu::always_inline]]
		constexpr explicit Proxy(F&& eval) : eval(eval) {}

		template<bool resMayAlias> [[gnu::always_inline]]
		void Eval(Matrix3x3& res) { eval.template operator()<resMayAlias>(res); }

		[[gnu::always_inline, nodiscard]]
		auto operator()(const Matrix3x3& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
			{
				if constexpr (resMayAlias)
				{
					const Matrix3x3 temp = other;
					Eval<resMayAlias>(res);
					MulMat3x3Mat3x3(temp, res, res);
				}
				else
				{
					Eval<resMayAlias>(res);
					MulMat3x3Mat3x3(other, res, res);
				}
			});
		}

		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator()(Proxy<G>&& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
			{
				const Matrix3x3 temp = std::move(other);
				Eval<resMayAlias>(res);
				MulMat3x3Mat3x3(temp, res, res);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator()(const Vector3& v) &&
		{
			return Vector3::Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				if constexpr (resMayAlias)
				{
					const Vector3 temp = v; // v may be altered while the second argument is calculated
					MulVec3Mat3x3(temp, std::move(*this), res);
				}
				else
					MulVec3Mat3x3(v, std::move(*this), res);
			});
		}
		
		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator()(Vector3::Proxy<G>&& proxy) &&
		{
			return Vector3::Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				const Matrix3x3 matrix = std::move(*this);
				proxy.template Eval<resMayAlias>(res);
				MulVec3Mat3x3(res, matrix, res);
			});
		}

		template<class T> [[gnu::always_inline, nodiscard]]
		auto operator*(T&& x) &&
		{
			return std::move(*this)(std::forward<T>(x));
		}
	};

	constexpr Matrix3x3() = default;
	constexpr Matrix3x3(const Vector3& c0, const Vector3& c1, const Vector3& c2) : c0(c0), c1(c1), c2(c2) {}

	constexpr Matrix3x3 (
		Fix12i c0x, Fix12i c1x, Fix12i c2x,
		Fix12i c0y, Fix12i c1y, Fix12i c2y,
		Fix12i c0z, Fix12i c1z, Fix12i c2z
	):
		c0(c0x, c0y, c0z),
		c1(c1x, c1y, c1z),
		c2(c2x, c2y, c2z)
	{}

	template<class F> [[gnu::always_inline]]
	Matrix3x3(Proxy<F>&& proxy) { proxy.template Eval<false>(*this); }

	template<class F> [[gnu::always_inline]]
	Matrix3x3& operator=(Proxy<F>&& proxy) & { proxy.template Eval<true>(*this); return *this; }
	
	static const Matrix3x3 IDENTITY;

	[[gnu::always_inline, nodiscard]]
	static auto Identity()
	{
		return Proxy([]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
		{
			Matrix3x3_LoadIdentity(res);
		});
	}

	template<class C0, class C1, class C2> [[gnu::always_inline, nodiscard]]
	static auto Temp(C0&& c0, C1&& c1, C2&& c2)
	{
		return Proxy([&]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
		{
			if constexpr (resMayAlias)
			{
				res.c0 = std::forward<C0>(c0);
				res.c1 = std::forward<C1>(c1);
				res.c2 = std::forward<C2>(c2);
			}
			else
			{
				AssureUnaliased(res.c0) = std::forward<C0>(c0);
				AssureUnaliased(res.c1) = std::forward<C1>(c1);
				AssureUnaliased(res.c2) = std::forward<C2>(c2);
			}
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator()(const Matrix3x3& other) const
	{
		return Proxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
		{
			MulMat3x3Mat3x3(other, *this, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator()(Proxy<F>& proxy) const
	{
		return Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
		{
			if constexpr (resMayAlias)
			{
				const Matrix3x3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				MulMat3x3Mat3x3(res, temp, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				MulMat3x3Mat3x3(res, *this, res);	
			}
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator()(const Vector3& v) const
	{
		return Vector3::Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			MulVec3Mat3x3(v, *this, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator()(Vector3::Proxy<F>&& proxy) const
	{
		return Vector3::Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = std::move(proxy);
				MulVec3Mat3x3(temp, *this, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				MulVec3Mat3x3(res, *this, res);
			}
		});
	}

	template<class T> [[gnu::always_inline, nodiscard]]
	auto operator*(T&& x) const
	{
		return operator()(std::forward<T>(x));
	}
	
	class TransposeProxy
	{
		const Matrix3x3& original;

	public:
		constexpr TransposeProxy(const Matrix3x3& original) : original(original) {}

		[[gnu::noinline, gnu::noclone]]
		friend Vector3& operator*=(Vector3& v, TransposeProxy t)
		{
			return v = Vector3::Temp(v.Dot(t.original.c0), v.Dot(t.original.c1), v.Dot(t.original.c2));
		}

		[[gnu::always_inline, nodiscard]]
		auto operator()(const Vector3& v) const
		{
			return Vector3::Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				res *= *this;
			});
		}

		template<class F> [[gnu::always_inline, nodiscard]]
		auto operator()(Vector3::Proxy<F>&& proxy) const
		{
			return Vector3::Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				proxy.template Eval<resMayAlias>(res);
				res = operator()(res);
			});
		}

		template<class T> [[gnu::always_inline, nodiscard]]
		auto operator*(T&& x) const { return operator()(std::forward<T>(x)); }

		[[gnu::always_inline, nodiscard]]
		auto C0() const
		{
			return Vector3::Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				res.x = original.c0.x;
				res.y = original.c1.x;
				res.z = original.c2.x;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto C1() const
		{
			return Vector3::Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				res.x = original.c0.y;
				res.y = original.c1.y;
				res.z = original.c2.y;
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto C2() const
		{
			return Vector3::Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				res.x = original.c0.z;
				res.y = original.c1.z;
				res.z = original.c2.z;
			});
		}

		const Matrix3x3& GetOriginal() const { return original; }
	};

	TransposeProxy Transpose() const { return *this; }

	void TransposeInPlace() &
	{
		void* trash; // input operands can't be clobbers

		asm volatile (R"(
			ldmib  %0,  {r1-r7}
			stmib  %0!, {r3, r6}
			stmib  %0!, {r1, r4, r7}
			stmib  %0,  {r2, r5}
		)"
		: "=r" (trash) : "0" (this) : "r1", "r2", "r3", "r4", "r5", "r6", "r7");
	}
	
	[[gnu::always_inline, nodiscard]]
	static auto Quat(const Quaternion& quaternion)
	{
		return Proxy([&quaternion]<bool resMayAlias> [[gnu::always_inline]] (Matrix3x3& res)
		{
			Matrix3x3_FromQuaternion(quaternion, res);
		});
	}
};


// Actually a 4x4 matrix with (0, 0, 0, 1) as the last row
struct Matrix4x3 : private Matrix3x3 // Matrix is column-major!
{
	using Matrix3x3::c0;
	using Matrix3x3::c1;
	using Matrix3x3::c2;
	Vector3 c3;

	static const Matrix4x3 IDENTITY;

	template<class F>
	class Proxy
	{
		F eval;

		template<class G>
		using NewProxy = Proxy<G>;

	public:
		[[gnu::always_inline]]
		constexpr explicit Proxy(F&& eval) : eval(eval) {}

		template<bool resMayAlias> [[gnu::always_inline]]
		void Eval(Matrix4x3& res) { eval.template operator()<resMayAlias>(res); }

		[[gnu::always_inline, nodiscard]]
		auto Inverse() const
		{
			return NewProxy([this]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				Eval<resMayAlias>(res);
				InvMat4x3(res, res);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto RotateZ(const s16& angZ) &&
		{
			return NewProxy([this, &angZ]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				Eval<resMayAlias>(res);
				res.RotateZ(angZ);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto RotateY(const s16& angY) &&
		{
			return NewProxy([this, &angY]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				Eval<resMayAlias>(res);
				res.RotateY(angY);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto RotateX(const s16& angX) &&
		{
			return NewProxy([this, &angX]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				Eval<resMayAlias>(res);
				res.RotateX(angX);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator()(const Matrix4x3& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				if constexpr (resMayAlias)
				{
					const Matrix4x3 temp = other;
					Eval<resMayAlias>(res);
					MulMat4x3Mat4x3(temp, res, res);
				}
				else
				{
					Eval<resMayAlias>(res);
					MulMat4x3Mat4x3(other, res, res);
				}
			});
		}

		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator()(Proxy<G>&& other) &&
		{
			return NewProxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
			{
				const Matrix4x3 temp = std::move(other);
				Eval<resMayAlias>(res);
				MulMat4x3Mat4x3(temp, res, res);
			});
		}

		[[gnu::always_inline, nodiscard]]
		auto operator()(const Vector3& v) &&
		{
			return Vector3::Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				if constexpr (resMayAlias)
				{
					const Vector3 temp = v; // v may be altered while the second argument is calculated
					MulVec3Mat4x3(temp, std::move(*this), res);
				}
				else
					MulVec3Mat4x3(v, std::move(*this), res);
			});
		}
		
		template<class G> [[gnu::always_inline, nodiscard]]
		auto operator()(Vector3::Proxy<G>&& proxy) &&
		{
			return Vector3::Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
			{
				const Matrix4x3 matrix = std::move(*this);
				proxy.template Eval<resMayAlias>(res);
				MulVec3Mat4x3(res, matrix, res);
			});
		}

		template<class T> [[gnu::always_inline, nodiscard]]
		auto operator*(T&& x) &&
		{
			return std::move(*this)(std::forward<T>(x));
		}
	};

	constexpr Matrix4x3() = default;
	constexpr Matrix4x3(const Vector3& c0, const Vector3& c1, const Vector3& c2, const Vector3& c3):
		Matrix3x3(c0, c1, c2),
		c3(c3)
	{}

	constexpr Matrix4x3 (
		Fix12i c0x, Fix12i c1x, Fix12i c2x, Fix12i c3x,
		Fix12i c0y, Fix12i c1y, Fix12i c2y, Fix12i c3y,
		Fix12i c0z, Fix12i c1z, Fix12i c2z, Fix12i c3z
	):
		Matrix3x3 (
			c0x, c1x, c2x,
			c0y, c1y, c2y,
			c0z, c1z, c2z
		),
		c3(c3x, c3y, c3z)
	{}

	constexpr explicit Matrix4x3(const Matrix3x3& linear):
		Matrix3x3(linear),
		c3{}
	{}

	template<class F>
	constexpr explicit Matrix4x3(Matrix3x3::Proxy<F>&& proxy):
		Matrix3x3(std::move(proxy)),
		c3{}
	{}

	template<class F> [[gnu::always_inline]]
	Matrix4x3(Proxy<F>&& proxy) { proxy.template Eval<false>(*this); }

	template<class F> [[gnu::always_inline]]
	Matrix4x3& operator=(Proxy<F>&& proxy) & { proxy.template Eval<true>(*this); return *this; }

	      Matrix3x3& Linear()       { return *this; }
	const Matrix3x3& Linear() const { return *this; }

	Matrix4x3& RotateZ(s16 angZ) & { Matrix4x3_ApplyInPlaceToRotationZ(*this, angZ); return *this; }
	Matrix4x3& RotateY(s16 angY) & { Matrix4x3_ApplyInPlaceToRotationY(*this, angY); return *this; }
	Matrix4x3& RotateX(s16 angX) & { Matrix4x3_ApplyInPlaceToRotationX(*this, angX); return *this; }
	Matrix4x3& RotateZXY(s16 angX, s16 angY, s16 angZ) & { Matrix4x3_ApplyInPlaceToRotationZXYExt(*this, angX, angY, angZ); return *this; }
	Matrix4x3& RotateXYZ(s16 angX, s16 angY, s16 angZ) & { Matrix4x3_ApplyInPlaceToRotationXYZExt(*this, angX, angY, angZ); return *this; }
	Matrix4x3& Translate(Fix12i x, Fix12i y, Fix12i z) & { Matrix4x3_ApplyInPlaceToTranslation(*this, x, y, z); return *this; }
	Matrix4x3& ApplyScale(Fix12i x, Fix12i y, Fix12i z) & { Matrix4x3_ApplyInPlaceToScale(*this, x, y, z); return *this; }
	
	[[gnu::always_inline, nodiscard]]
	auto Inverse() const
	{
		return Proxy([this]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			InvMat4x3(*this, res);
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator()(const Matrix4x3& other) const
	{
		return Proxy([this, &other]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			MulMat4x3Mat4x3(other, *this, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator()(Proxy<F>& proxy) const
	{
		return Proxy([this, &proxy]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			if constexpr (resMayAlias)
			{
				const Matrix4x3 temp = *this;
				proxy.template Eval<resMayAlias>(res);
				MulMat4x3Mat4x3(res, temp, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				MulMat4x3Mat4x3(res, *this, res);
			}
		});
	}

	[[gnu::always_inline, nodiscard]]
	auto operator()(const Vector3& v) const
	{
		return Vector3::Proxy([this, &v]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			MulVec3Mat4x3(v, *this, res);
		});
	}

	template<class F> [[gnu::always_inline, nodiscard]]
	auto operator()(Vector3::Proxy<F>&& proxy) const
	{
		return Vector3::Proxy([&proxy, this]<bool resMayAlias> [[gnu::always_inline]] (Vector3& res)
		{
			if constexpr (resMayAlias)
			{
				const Vector3 temp = std::move(proxy);
				MulVec3Mat4x3(temp, *this, res);
			}
			else
			{
				proxy.template Eval<resMayAlias>(res);
				MulVec3Mat4x3(res, *this, res);
			}
		});
	}

	template<class T> [[gnu::always_inline, nodiscard]]
	auto operator*(T&& x) const
	{
		return operator()(std::forward<T>(x));
	}

	[[gnu::always_inline, nodiscard]]
	static auto Identity()
	{
		return Proxy([]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_LoadIdentity(res);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto Translation(const Fix12i& x, const Fix12i& y, const Fix12i& z)
	{
		return Proxy([&x, &y, &z]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromTranslation(res, x, y, z);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto Translation(const Vector3& translation)
	{
		return Proxy([&translation]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromTranslation(res, translation.x, translation.y, translation.z);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto Scale(const Fix12i& x, const Fix12i& y, const Fix12i& z)
	{
		return Proxy([&x, &y, &z]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromScale(res, x, y, z);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto Scale(const Vector3& scale)
	{
		return Proxy([&scale]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromScale(res, scale.x, scale.y, scale.z);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto RotationX(const s16& angX)
	{
		return Proxy([&angX]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromRotationX(res, angX);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto RotationY(const s16& angY)
	{
		return Proxy([&angY]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromRotationY(res, angY);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto RotationZ(const s16& angZ)
	{
		return Proxy([&angZ]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromRotationZ(res, angZ);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto RotationZXY(const s16& angX, const s16& angY, const s16& angZ)
	{
		return Proxy([&angX, &angY, &angZ]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromRotationZXYExt(res, angX, angY, angZ);
		});
	}

	[[gnu::always_inline, nodiscard]]
	static auto RotationXYZ(const s16& angX, const s16& angY, const s16& angZ)
	{
		return Proxy([&angX, &angY, &angZ]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromRotationXYZExt(res, angX, angY, angZ);
		});
	}
	
	[[gnu::always_inline, nodiscard]]
	static auto Quat(const Quaternion& quaternion)
	{
		return Proxy([&quaternion]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			Matrix4x3_FromQuaternion(quaternion, res);
		});
	}

	template<class C0, class C1, class C2, class C3> [[gnu::always_inline, nodiscard]]
	static auto Temp(C0&& c0, C1&& c1, C2&& c2, C3&& c3)
	{
		return Proxy([&]<bool resMayAlias> [[gnu::always_inline]] (Matrix4x3& res)
		{
			if constexpr (resMayAlias)
			{
				res.c0 = std::forward<C0>(c0);
				res.c1 = std::forward<C1>(c1);
				res.c2 = std::forward<C2>(c2);
				res.c3 = std::forward<C3>(c3);
			}
			else
			{
				AssureUnaliased(res.c0) = std::forward<C0>(c0);
				AssureUnaliased(res.c1) = std::forward<C1>(c1);
				AssureUnaliased(res.c2) = std::forward<C2>(c2);
				AssureUnaliased(res.c3) = std::forward<C3>(c3);	
			}
		});
	}
};

struct Quaternion
{
	Fix12i x;
	Fix12i y;
	Fix12i z;
	Fix12i w;
	
	template<class F>
	class Proxy
	{
		F eval;

		template<class G>
		using NewProxy = Proxy<G>;

	public:
		[[gnu::always_inline]]
		constexpr explicit Proxy(F&& eval) : eval(eval) {}

		template<bool resMayAlias> [[gnu::always_inline]]
		void Eval(Quaternion& res) { eval.template operator()<resMayAlias>(res); }
	};
	
	constexpr Quaternion() = default;
	constexpr Quaternion(auto x, auto y, auto z, auto w) : x(x), y(y), z(z), w(w) {}

	template<class F> [[gnu::always_inline]]
	Quaternion(Proxy<F>&& proxy) { proxy.template Eval<false>(*this); }

	template<class F> [[gnu::always_inline]]
	Quaternion& operator=(Proxy<F>&& proxy) & { proxy.template Eval<true>(*this); return *this; }
	
	[[gnu::always_inline, nodiscard]]
	static auto Vec3(const Vector3& v0, const Vector3& v1)
	{
		return Proxy([&v0, &v1]<bool resMayAlias> [[gnu::always_inline]] (Quaternion& res)
		{
			Quaternion_FromVector3(res, v0, v1);
		});
	}
	
	[[gnu::always_inline]]
	void Normalize() & { Quaternion_Normalize(*this); }
	
	[[gnu::always_inline]]
	void SLerp(const Quaternion& q1, const Quaternion& q2, Fix12i weight)
	{
		Quaternion_SLerp(q1, q2, weight, *this);
	}
	
	[[gnu::always_inline]]
	void SExpDecay(const Quaternion& q, Fix12i weight)
	{
		Quaternion_SLerp(*this, q, weight, *this);
	}
};

template<class T, T zero = static_cast<T>(0)>
constexpr s32 Sgn(T val)
{
    return (val > zero) - (val < zero);
}

[[gnu::always_inline]]
inline const Fix12s& Sin(s16 angle)
{
	return SINE_TABLE[static_cast<u16>(angle + 8) >> 4 << 1];
}

[[gnu::always_inline]]
inline const Fix12s& Cos(s16 angle)
{
	return SINE_TABLE[1 + (static_cast<u16>(angle + 8) >> 4 << 1)];
}

[[gnu::always_inline]]
constexpr u16 Color5Bit(u8 r, u8 g, u8 b) //0x00 to 0xff each
{
	return (u16)r >> 3 << 0 |
		   (u16)g >> 3 << 5 |
		   (u16)b >> 3 << 10;
}

[[gnu::always_inline]]
constexpr u16 Arr3_5Bit(u8 val0, u8 val1, u8 val2)
{
	return (u16)val0 << 0 |
		   (u16)val1 << 5 |
		   (u16)val2 << 10;
}

template<FixUR T>
inline const ostream& operator<<(const ostream& os, Fix12<T> fix)
{
	if (fix >= Fix12<T>(0, as_raw))
	{
		os.set_buffer("0x%r0%_f");
		os.flush(fix.val);
	}
	else
	{
		os.set_buffer("-0x%r0%_f");
		os.flush(-fix.val); 
	}

	return os;
}

inline const ostream& operator<<(const ostream& os, const Vector3& vec)
{
	os.set_buffer("{0x%r0%_f, 0x%r1%_f, 0x%r2%_f}");
	os.flush(vec.x.val, vec.y.val, vec.z.val);

	return os;
}

inline const ostream& operator<<(const ostream& os, const Vector3_16f& vec)
{
	os.set_buffer("{0x%r0%_fs, 0x%r1%_fs, 0x%r2%_fs}");
	os.flush(vec.x.val, vec.y.val, vec.z.val);

	return os;
}

inline const ostream& operator<<(const ostream& os, const Vector3_16& vec)
{
	os.set_buffer("{0x%r0%, 0x%r1%, 0x%r2%}");
	os.flush(vec.x, vec.y, vec.z);

	return os;
}

inline const ostream& operator<<(const ostream& os, const Matrix4x3& m)
{
	os.set_buffer("[ 0x%r0%_f  0x%r1%_f  0x%r2%_f  0x%r3%_f ]\n");

	os.flush(m.c0.x.val, m.c1.x.val, m.c2.x.val, m.c3.x.val);
	os.flush(m.c0.y.val, m.c1.y.val, m.c2.y.val, m.c3.y.val);
	os.flush(m.c0.z.val, m.c1.z.val, m.c2.z.val, m.c3.z.val);

	return os;
}

inline const ostream& operator<<(const ostream& os, const Matrix3x3& m)
{
	os.set_buffer("[ 0x%r0%_f  0x%r1%_f  0x%r2%_f ]\n");

	os.flush(m.c0.x.val, m.c1.x.val, m.c2.x.val);
	os.flush(m.c0.y.val, m.c1.y.val, m.c2.y.val);
	os.flush(m.c0.z.val, m.c1.z.val, m.c2.z.val);

	return os;
}

[[gnu::always_inline]]
inline void AddPointers(void** p1, void* p2)
{
	*p1 = (void*)((u32)*p1 + (u32)p2);
}