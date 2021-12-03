#pragma once

#include <cmath>
#include <cfloat>
#include <cinttypes>
#include <cassert>

#include <MathUtil.h>
#include <MathTemplateUtil.h>

namespace Math
{
    template<typename T>
    class Vector2;
    template<typename T>
    class Vector3;
    template<typename T>
    class Vector4;

    template<typename T>
    T Dot(const Vector2<T>& lhs, const Vector2<T>& rhs);
    template<typename T>
    T Dot(const Vector3<T>& lhs, const Vector3<T>& rhs);
    template<typename T>
    T Dot(const Vector4<T>& lhs, const Vector4<T>& rhs);

    template<typename T>
    Vector2<T> Cross(const Vector2<T>& lhs, const Vector2<T>& rhs);
    template<typename T>
	Vector2<T> Cross(const Vector3<T>& lhs, const Vector3<T>& rhs);
    template<typename T>
	Vector2<T> Cross(const Vector4<T>& lhs, const Vector4<T>& rhs);

	template <typename T>
	class Vector2
	{
	public:
		static const Vector2<T> UNIT_X;
		static const Vector2<T> UNIT_Y;

	public:
		Vector2<T>()
			: e{ static_cast<T>(0.f), static_cast<T>(0.f) }
		{
		}

		Vector2<T>(T e0, T e1)
			: e{ e0, e1 }
		{
		}

		~Vector2<T>() = default;
		Vector2<T>(Vector2<T>&& other) = default;
		Vector2<T>& operator=(const Vector2<T>& other) = default;
		Vector2<T>& operator=(Vector2<T>&& other) = default;

		Vector2<T>(const Vector2<T>& other)
			: e{ other.e[0], other.e[1] }
		{
		}

		T& operator[](const size_t element)
		{
			assert(element < 2);
			return e[element];
		}

		T operator[](const size_t element) const
		{
			assert(element < 2);
			return e[element];
		}

		bool operator==(const Vector2<T>& other) const
		{
			return (x == other.x) && (y == other.y);
		}

		bool operator!=(const Vector2<T>& other) const
		{
			return !((x == other.x) && (y == other.y));
		}

		Vector2<T> operator+(const Vector2<T>& other) const
		{
			return { x + other.x, y + other.y };
		}

		Vector2<T> operator-(const Vector2<T>& other) const
		{
			return { x - other.x, y - other.y };
		}

		Vector2<T> operator*(const Vector2<T>& other) const
		{
			return { x * other.x, y * other.y };
		}

		Vector2<T> operator/(const Vector2<T>& other) const
		{
			return { x / other.x, y / other.y };
		}

		Vector2<T> operator+(const T scalar) const
		{
			return { x + scalar, y + scalar };
		}

		Vector2<T> operator-(const T scalar) const
		{
			return { x - scalar, y - scalar };
		}

		Vector2<T> operator*(const T scalar) const
		{
			return { x * scalar, y * scalar };
		}

		Vector2<T> operator/(const T scalar) const
		{
			return { x / scalar, y / scalar };
		}

		Vector2<T> operator%(const Vector2<T>& other) const
		{
			return { x % other.x, y % other.y };
		}

		Vector2<T>& operator+=(const Vector2<T>& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2<T>& operator-=(const Vector2<T>& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Vector2<T>& operator*=(const Vector2<T>& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		Vector2<T>& operator/=(const Vector2<T>& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		Vector2<T>& operator%=(const Vector2<T> other)
		{
			x %= other.x;
			y %= other.y;
			return *this;
		}

		Vector2<T>& operator+=(const T scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		Vector2<T>& operator-=(const T scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		Vector2<T>& operator*=(const T scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		Vector2<T>& operator/=(const T scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		Vector2<T>& operator%=(const T scalar)
		{
			x %= scalar;
			y %= scalar;
			return *this;
		}

		T Length() const
		{
			return Sqrt<T>((e[0] * e[0]) + (e[1] * e[1]));
		}

		T LengthSq() const
		{
			return (e[0] * e[0]) + (e[1] * e[1]);
		}

		T Dot(const Vector2<T>& other) const
		{
			return Math::Dot(*this, other);
		}

		Vector2<T> Normalized() const
		{
			return *this / Length();
		}

		Vector2<T>& Normalize()
		{
			*this /= Length();
			return *this;
		}

		// Vector2 -> Vector2 swizzle, xy
		inline Vector2<T> xx()
		{
			return { x, x };
		}

		inline Vector2<T> yx()
		{
			return { y, x };
		}

		inline Vector2<T> yy()
		{
			return { y, y };
		}

		// Vector2 -> Vector2 swizzle, ra
		inline Vector2<T> rr()
		{
			return { r, r };
		}

		inline Vector2<T> ar()
		{
			return { a, r };
		}

		inline Vector2<T> aa()
		{
			return { a, a };
		}

		// Vector2 -> Vector2 swizzle, uv
		inline Vector2<T> uu()
		{
			return { u, u };
		}

		inline Vector2<T> vu()
		{
			return { v, u };
		}

		inline Vector2<T> vv()
		{
			return { v, v };
		}



		union
		{
			struct
			{
				T x, y;
			};
			struct
			{
				T r, a;
			};
			struct
			{
				T u, v;
			};
			T e[2];
		};
	};

	template <typename T>
	class Vector3
	{
	public:
		static const Vector3<T> UNIT_X;
		static const Vector3<T> UNIT_Y;
		static const Vector3<T> UNIT_Z;
		
	public:
		Vector3<T>()
			: e{ static_cast<T>(0.f), static_cast<T>(0.f), static_cast<T>(0.f) }
		{
		}

		Vector3<T>(T e0, T e1, T e2)
			: e{ e0, e1, e2 }
		{
		}

		Vector3<T>(const Vector2<T>& e01, T e2 = static_cast<T>(0))
			: e{ e01.e[0], e01.e[1], e2 }
		{
		}

		~Vector3<T>() = default;
		Vector3<T>(Vector3<T> && other) = default;
		Vector3<T>& operator=(const Vector3<T>&other) = default;
		Vector3<T>& operator=(Vector3<T> && other) = default;

		Vector3<T>(const Vector3<T>& other)
			: e{ other.e[0], other.e[1], other.e[2] }
		{
		}

		T& operator[](const size_t element)
		{
			assert(element < 3);
			return e[element];
		}

		T operator[](const size_t element) const
		{
			assert(element < 3);
			return e[element];
		}

		bool operator==(const Vector3<T>& other) const
		{
			return (x == other.x) && (y == other.y) && (z == other.z);
		}

		bool operator!=(const Vector3<T>& other) const
		{
			return !((x == other.x) && (y == other.y) && (z == other.z));
		}

		Vector3<T> operator+(const Vector3<T>& other) const
		{
			return { x + other.x, y + other.y, z + other.z };
		}

		Vector3<T> operator-(const Vector3<T>& other) const
		{
			return { x - other.x, y - other.y, z - other.z };
		}

		Vector3<T> operator*(const Vector3<T>& other) const
		{
			return { x * other.x, y * other.y, z * other.z };
		}

		Vector3<T> operator/(const Vector3<T>& other) const
		{
			return { x / other.x, y / other.y, z / other.z };
		}

		Vector3<T> operator+(const T scalar) const
		{
			return { x + scalar, y + scalar, z + scalar };
		}

		Vector3<T> operator-(const T scalar) const
		{
			return { x - scalar, y - scalar, z - scalar };
		}

		Vector3<T> operator*(const T scalar) const
		{
			return { x * scalar, y * scalar, z * scalar };
		}

		Vector3<T> operator/(const T scalar) const
		{
			return { x / scalar, y / scalar, z / scalar };
		}

		Vector3<T> operator%(const Vector3<T>& other) const
		{
			return { x % other.x, y % other.y, z % other.z };
		}

		Vector3<T>& operator+=(const Vector3<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Vector3<T>& operator-=(const Vector3<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		Vector3<T>& operator*=(const Vector3<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		Vector3<T>& operator/=(const Vector3<T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		Vector3<T>& operator%=(const Vector3<T> other)
		{
			x %= other.x;
			y %= other.y;
			z %= other.z;
			return *this;
		}

		Vector3<T>& operator+=(const T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		Vector3<T>& operator-=(const T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		Vector3<T>& operator*=(const T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		Vector3<T>& operator/=(const T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		Vector3<T>& operator%=(const T scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			return *this;
		}

		T Length() const
		{
			return Sqrt<T>((e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]));
		}

		T LengthSq() const
		{
			return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
		}

		Vector3<T> Normalized() const
		{
			return *this / Length();
		}

		Vector3<T>& Normalize()
		{
			*this /= Length();
			return *this;
		}

		T Dot(const Vector3<T>& other) const
		{
			return Math::Dot(*this, other);
		}

		Vector3<T> Cross(const Vector3<T>& other) const
		{
			return Math::Cross(*this, other);
		}

		// Vector3 -> Vector3 swizzle, xyz
		inline Vector3<T> xxx()
		{
			return { x, x, x };
		}

		inline Vector3<T> xxy()
		{
			return { x, x, y };
		}

		inline Vector3<T> xxz()
		{
			return { x, x, z };
		}

		inline Vector3<T> xyx()
		{
			return { x, y, x };
		}

		inline Vector3<T> xyy()
		{
			return { x, y, y };
		}

		inline Vector3<T> xzx()
		{
			return { x, z, x };
		}

		inline Vector3<T> xzy()
		{
			return { x, z, y };
		}

		inline Vector3<T> xzz()
		{
			return { x, z, z };
		}

		inline Vector3<T> yxx()
		{
			return { y, x, x };
		}

		inline Vector3<T> yxy()
		{
			return { y, x, y };
		}

		inline Vector3<T> yxz()
		{
			return { y, x, z };
		}

		inline Vector3<T> yyx()
		{
			return { y, y, x };
		}

		inline Vector3<T> yyy()
		{
			return { y, y, y };
		}

		inline Vector3<T> yyz()
		{
			return { y, y, z };
		}

		inline Vector3<T> yzx()
		{
			return { y, z, x };
		}

		inline Vector3<T> yzy()
		{
			return { y, z, y };
		}

		inline Vector3<T> yzz()
		{
			return { y, z, z };
		}

		inline Vector3<T> zxx()
		{
			return { z, x, x };
		}

		inline Vector3<T> zxy()
		{
			return { z, x, y };
		}

		inline Vector3<T> zxz()
		{
			return { z, x, z };
		}

		inline Vector3<T> zyx()
		{
			return { z, y, x };
		}

		inline Vector3<T> zyy()
		{
			return { z, y, y };
		}

		inline Vector3<T> zyz()
		{
			return { z, y, z };
		}

		inline Vector3<T> zzx()
		{
			return { z, z, x };
		}

		inline Vector3<T> zzy()
		{
			return { z, z, y };
		}

		inline Vector3<T> zzz()
		{
			return { z, z, z };
		}

		// Vector3 -> Vector2 swizzle, xyz
		inline Vector2<T> xx()
		{
			return { x, x };
		}

		inline Vector2<T> xy()
		{
			return { x, y };
		}

		inline Vector2<T> xz()
		{
			return { x, z };
		}

		inline Vector2<T> yx()
		{
			return { y, x };
		}

		inline Vector2<T> yy()
		{
			return { y, y };
		}

		inline Vector2<T> yz()
		{
			return { y, z };
		}

		inline Vector2<T> zx()
		{
			return { z, x };
		}

		inline Vector2<T> zy()
		{
			return { z, y };
		}

		inline Vector2<T> zz()
		{
			return { z, z };
		}

		// Vector3 -> Vector3 swizzle, rgb
		inline Vector3<T> rrr()
		{
			return { r, r, r };
		}

		inline Vector3<T> rrg()
		{
			return { r, r, g };
		}

		inline Vector3<T> rrb()
		{
			return { r, r, b };
		}

		inline Vector3<T> rgr()
		{
			return { r, g, r };
		}

		inline Vector3<T> rgg()
		{
			return { r, g, g };
		}

		inline Vector3<T> rbr()
		{
			return { r, b, r };
		}

		inline Vector3<T> rbg()
		{
			return { r, b, g };
		}

		inline Vector3<T> rbb()
		{
			return { r, b, b };
		}

		inline Vector3<T> grr()
		{
			return { g, r, r };
		}

		inline Vector3<T> grg()
		{
			return { g, r, g };
		}

		inline Vector3<T> grb()
		{
			return { g, r, b };
		}

		inline Vector3<T> ggr()
		{
			return { g, g, r };
		}

		inline Vector3<T> ggg()
		{
			return { g, g, g };
		}

		inline Vector3<T> ggb()
		{
			return { g, g, b };
		}

		inline Vector3<T> gbr()
		{
			return { g, b, r };
		}

		inline Vector3<T> gbg()
		{
			return { g, b, g };
		}

		inline Vector3<T> gbb()
		{
			return { g, b, b };
		}

		inline Vector3<T> brr()
		{
			return { b, r, r };
		}

		inline Vector3<T> brg()
		{
			return { b, r, g };
		}

		inline Vector3<T> brb()
		{
			return { b, r, b };
		}

		inline Vector3<T> bgr()
		{
			return { b, g, r };
		}

		inline Vector3<T> bgg()
		{
			return { b, g, g };
		}

		inline Vector3<T> bgb()
		{
			return { b, g, b };
		}

		inline Vector3<T> bbr()
		{
			return { b, b, r };
		}

		inline Vector3<T> bbg()
		{
			return { b, b, g };
		}

		inline Vector3<T> bbb()
		{
			return { b, b, b };
		}

		// Vector3 -> Vector2 swizzle, rgb
		inline Vector2<T> rr()
		{
			return { r, r };
		}

		inline Vector2<T> rg()
		{
			return { r, g };
		}

		inline Vector2<T> rb()
		{
			return { r, b };
		}

		inline Vector2<T> gr()
		{
			return { g, r };
		}

		inline Vector2<T> gg()
		{
			return { g, g };
		}

		inline Vector2<T> gb()
		{
			return { g, b };
		}

		inline Vector2<T> br()
		{
			return { b, r };
		}

		inline Vector2<T> bg()
		{
			return { b, g };
		}

		inline Vector2<T> bb()
		{
			return { b, b };
		}



		union
		{
			struct
			{
				T x, y, z;
			};
			struct
			{
				T r, g, b;
			};
			T e[3];
		};
	};

	template <typename T>
	class Vector4
	{
	public:
		static const Vector4<T> UNIT_X;
		static const Vector4<T> UNIT_Y;
		static const Vector4<T> UNIT_Z;
		static const Vector4<T> UNIT_W;
		
	public:
		Vector4<T>()
			: e{ static_cast<T>(0.f), static_cast<T>(0.f), static_cast<T>(0.f), static_cast<T>(0.f) }
		{
		}

		Vector4<T>(T e0, T e1, T e2, T e3)
			: e{ e0, e1, e2, e3 }
		{
		}

		Vector4<T>(const Vector2<T>& e01, T e2 = static_cast<T>(0), T e3 = static_cast<T>(0))
			: e{ e01.e[0], e01.e[1], e2, e3 }
		{
		}

		Vector4<T>(const Vector3<T>& e012, T e3 = static_cast<T>(0))
			: e{ e012.e[0], e012.e[1], e012.e[2], e3 }
		{
		}

		~Vector4<T>() = default;
		Vector4<T>(Vector4<T> && other) = default;
		Vector4<T>& operator=(const Vector4<T>&other) = default;
		Vector4<T>& operator=(Vector4<T> && other) = default;

		Vector4<T>(const Vector4<T>& other)
			: e{ other.e[0], other.e[1], other.e[2], other.e[3] }
		{
		}

		T& operator[](const size_t element)
		{
			assert(element < 4);
			return e[element];
		}

		T operator[](const size_t element) const
		{
			assert(element < 4);
			return e[element];
		}

		bool operator==(const Vector4<T>& other) const
		{
			return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
		}

		bool operator!=(const Vector4<T>& other) const
		{
			return !((x == other.x) && (y == other.y) && (z == other.z) && (w == other.w));
		}

		Vector4<T> operator+(const Vector4<T>& other) const
		{
			return { x + other.x, y + other.y, z + other.z, w + other.w };
		}

		Vector4<T> operator-(const Vector4<T>& other) const
		{
			return { x - other.x, y - other.y, z - other.z, w - other.w };
		}

		Vector4<T> operator*(const Vector4<T>& other) const
		{
			return { x * other.x, y * other.y, z * other.z, w * other.w };
		}

		Vector4<T> operator/(const Vector4<T>& other) const
		{
			return { x / other.x, y / other.y, z / other.z, w / other.w };
		}

		Vector4<T> operator+(const T scalar) const
		{
			return { x + scalar, y + scalar, z + scalar, w + scalar };
		}

		Vector4<T> operator-(const T scalar) const
		{
			return { x - scalar, y - scalar, z - scalar, w - scalar };
		}

		Vector4<T> operator*(const T scalar) const
		{
			return { x * scalar, y * scalar, z * scalar, w * scalar };
		}

		Vector4<T> operator/(const T scalar) const
		{
			return { x / scalar, y / scalar, z / scalar, w / scalar };
		}

		Vector4<T> operator%(const Vector4<T>& other) const
		{
			return { x % other.x, y % other.y, z % other.z, w % other.w };
		}

		Vector4<T>& operator+=(const Vector4<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		Vector4<T>& operator-=(const Vector4<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		Vector4<T>& operator*=(const Vector4<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			z *= other.w;
			return *this;
		}

		Vector4<T>& operator/=(const Vector4<T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		Vector4<T>& operator%=(const Vector4<T> other)
		{
			x %= other.x;
			y %= other.y;
			z %= other.z;
			w %= other.w;
			return *this;
		}

		Vector4<T>& operator+=(const T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		Vector4<T>& operator-=(const T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		Vector4<T>& operator*=(const T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		Vector4<T>& operator/=(const T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		Vector4<T>& operator%=(const T scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		T Length() const
		{
			return Sqrt<T>((e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]) + (e[3] * e[3]));
		}

		T LengthSq() const
		{
			return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]) + (e[3] * e[3]);
		}

		Vector4<T> Normalized() const
		{
			return *this / Length();
		}

		Vector4<T>& Normalize()
		{
			*this /= Length();
			return *this;
		}

		T Dot(const Vector4<T>& other) const
		{
			return Math::Dot(*this, other);
		}

		// Vector4 -> Vector4 swizzle, xyzw
		inline Vector4<T> xxxx()
		{
			return { x, x, x, x };
		}

		inline Vector4<T> xxxy()
		{
			return { x, x, x, y };
		}

		inline Vector4<T> xxxz()
		{
			return { x, x, x, z };
		}

		inline Vector4<T> xxxw()
		{
			return { x, x, x, w };
		}

		inline Vector4<T> xxyx()
		{
			return { x, x, y, x };
		}

		inline Vector4<T> xxyy()
		{
			return { x, x, y, y };
		}

		inline Vector4<T> xxyz()
		{
			return { x, x, y, z };
		}

		inline Vector4<T> xxyw()
		{
			return { x, x, y, w };
		}

		inline Vector4<T> xxzx()
		{
			return { x, x, z, x };
		}

		inline Vector4<T> xxzy()
		{
			return { x, x, z, y };
		}

		inline Vector4<T> xxzz()
		{
			return { x, x, z, z };
		}

		inline Vector4<T> xxzw()
		{
			return { x, x, z, w };
		}

		inline Vector4<T> xxwx()
		{
			return { x, x, w, x };
		}

		inline Vector4<T> xxwy()
		{
			return { x, x, w, y };
		}

		inline Vector4<T> xxwz()
		{
			return { x, x, w, z };
		}

		inline Vector4<T> xxww()
		{
			return { x, x, w, w };
		}

		inline Vector4<T> xyxx()
		{
			return { x, y, x, x };
		}

		inline Vector4<T> xyxy()
		{
			return { x, y, x, y };
		}

		inline Vector4<T> xyxz()
		{
			return { x, y, x, z };
		}

		inline Vector4<T> xyxw()
		{
			return { x, y, x, w };
		}

		inline Vector4<T> xyyx()
		{
			return { x, y, y, x };
		}

		inline Vector4<T> xyyy()
		{
			return { x, y, y, y };
		}

		inline Vector4<T> xyyz()
		{
			return { x, y, y, z };
		}

		inline Vector4<T> xyyw()
		{
			return { x, y, y, w };
		}

		inline Vector4<T> xyzx()
		{
			return { x, y, z, x };
		}

		inline Vector4<T> xyzy()
		{
			return { x, y, z, y };
		}

		inline Vector4<T> xyzz()
		{
			return { x, y, z, z };
		}

		inline Vector4<T> xywx()
		{
			return { x, y, w, x };
		}

		inline Vector4<T> xywy()
		{
			return { x, y, w, y };
		}

		inline Vector4<T> xywz()
		{
			return { x, y, w, z };
		}

		inline Vector4<T> xyww()
		{
			return { x, y, w, w };
		}

		inline Vector4<T> xzxx()
		{
			return { x, z, x, x };
		}

		inline Vector4<T> xzxy()
		{
			return { x, z, x, y };
		}

		inline Vector4<T> xzxz()
		{
			return { x, z, x, z };
		}

		inline Vector4<T> xzxw()
		{
			return { x, z, x, w };
		}

		inline Vector4<T> xzyx()
		{
			return { x, z, y, x };
		}

		inline Vector4<T> xzyy()
		{
			return { x, z, y, y };
		}

		inline Vector4<T> xzyz()
		{
			return { x, z, y, z };
		}

		inline Vector4<T> xzyw()
		{
			return { x, z, y, w };
		}

		inline Vector4<T> xzzx()
		{
			return { x, z, z, x };
		}

		inline Vector4<T> xzzy()
		{
			return { x, z, z, y };
		}

		inline Vector4<T> xzzz()
		{
			return { x, z, z, z };
		}

		inline Vector4<T> xzzw()
		{
			return { x, z, z, w };
		}

		inline Vector4<T> xzwx()
		{
			return { x, z, w, x };
		}

		inline Vector4<T> xzwy()
		{
			return { x, z, w, y };
		}

		inline Vector4<T> xzwz()
		{
			return { x, z, w, z };
		}

		inline Vector4<T> xzww()
		{
			return { x, z, w, w };
		}

		inline Vector4<T> xwxx()
		{
			return { x, w, x, x };
		}

		inline Vector4<T> xwxy()
		{
			return { x, w, x, y };
		}

		inline Vector4<T> xwxz()
		{
			return { x, w, x, z };
		}

		inline Vector4<T> xwxw()
		{
			return { x, w, x, w };
		}

		inline Vector4<T> xwyx()
		{
			return { x, w, y, x };
		}

		inline Vector4<T> xwyy()
		{
			return { x, w, y, y };
		}

		inline Vector4<T> xwyz()
		{
			return { x, w, y, z };
		}

		inline Vector4<T> xwyw()
		{
			return { x, w, y, w };
		}

		inline Vector4<T> xwzx()
		{
			return { x, w, z, x };
		}

		inline Vector4<T> xwzy()
		{
			return { x, w, z, y };
		}

		inline Vector4<T> xwzz()
		{
			return { x, w, z, z };
		}

		inline Vector4<T> xwzw()
		{
			return { x, w, z, w };
		}

		inline Vector4<T> xwwx()
		{
			return { x, w, w, x };
		}

		inline Vector4<T> xwwy()
		{
			return { x, w, w, y };
		}

		inline Vector4<T> xwwz()
		{
			return { x, w, w, z };
		}

		inline Vector4<T> xwww()
		{
			return { x, w, w, w };
		}

		inline Vector4<T> yxxx()
		{
			return { y, x, x, x };
		}

		inline Vector4<T> yxxy()
		{
			return { y, x, x, y };
		}

		inline Vector4<T> yxxz()
		{
			return { y, x, x, z };
		}

		inline Vector4<T> yxxw()
		{
			return { y, x, x, w };
		}

		inline Vector4<T> yxyx()
		{
			return { y, x, y, x };
		}

		inline Vector4<T> yxyy()
		{
			return { y, x, y, y };
		}

		inline Vector4<T> yxyz()
		{
			return { y, x, y, z };
		}

		inline Vector4<T> yxyw()
		{
			return { y, x, y, w };
		}

		inline Vector4<T> yxzx()
		{
			return { y, x, z, x };
		}

		inline Vector4<T> yxzy()
		{
			return { y, x, z, y };
		}

		inline Vector4<T> yxzz()
		{
			return { y, x, z, z };
		}

		inline Vector4<T> yxzw()
		{
			return { y, x, z, w };
		}

		inline Vector4<T> yxwx()
		{
			return { y, x, w, x };
		}

		inline Vector4<T> yxwy()
		{
			return { y, x, w, y };
		}

		inline Vector4<T> yxwz()
		{
			return { y, x, w, z };
		}

		inline Vector4<T> yxww()
		{
			return { y, x, w, w };
		}

		inline Vector4<T> yyxx()
		{
			return { y, y, x, x };
		}

		inline Vector4<T> yyxy()
		{
			return { y, y, x, y };
		}

		inline Vector4<T> yyxz()
		{
			return { y, y, x, z };
		}

		inline Vector4<T> yyxw()
		{
			return { y, y, x, w };
		}

		inline Vector4<T> yyyx()
		{
			return { y, y, y, x };
		}

		inline Vector4<T> yyyy()
		{
			return { y, y, y, y };
		}

		inline Vector4<T> yyyz()
		{
			return { y, y, y, z };
		}

		inline Vector4<T> yyyw()
		{
			return { y, y, y, w };
		}

		inline Vector4<T> yyzx()
		{
			return { y, y, z, x };
		}

		inline Vector4<T> yyzy()
		{
			return { y, y, z, y };
		}

		inline Vector4<T> yyzz()
		{
			return { y, y, z, z };
		}

		inline Vector4<T> yyzw()
		{
			return { y, y, z, w };
		}

		inline Vector4<T> yywx()
		{
			return { y, y, w, x };
		}

		inline Vector4<T> yywy()
		{
			return { y, y, w, y };
		}

		inline Vector4<T> yywz()
		{
			return { y, y, w, z };
		}

		inline Vector4<T> yyww()
		{
			return { y, y, w, w };
		}

		inline Vector4<T> yzxx()
		{
			return { y, z, x, x };
		}

		inline Vector4<T> yzxy()
		{
			return { y, z, x, y };
		}

		inline Vector4<T> yzxz()
		{
			return { y, z, x, z };
		}

		inline Vector4<T> yzxw()
		{
			return { y, z, x, w };
		}

		inline Vector4<T> yzyx()
		{
			return { y, z, y, x };
		}

		inline Vector4<T> yzyy()
		{
			return { y, z, y, y };
		}

		inline Vector4<T> yzyz()
		{
			return { y, z, y, z };
		}

		inline Vector4<T> yzyw()
		{
			return { y, z, y, w };
		}

		inline Vector4<T> yzzx()
		{
			return { y, z, z, x };
		}

		inline Vector4<T> yzzy()
		{
			return { y, z, z, y };
		}

		inline Vector4<T> yzzz()
		{
			return { y, z, z, z };
		}

		inline Vector4<T> yzzw()
		{
			return { y, z, z, w };
		}

		inline Vector4<T> yzwx()
		{
			return { y, z, w, x };
		}

		inline Vector4<T> yzwy()
		{
			return { y, z, w, y };
		}

		inline Vector4<T> yzwz()
		{
			return { y, z, w, z };
		}

		inline Vector4<T> yzww()
		{
			return { y, z, w, w };
		}

		inline Vector4<T> ywxx()
		{
			return { y, w, x, x };
		}

		inline Vector4<T> ywxy()
		{
			return { y, w, x, y };
		}

		inline Vector4<T> ywxz()
		{
			return { y, w, x, z };
		}

		inline Vector4<T> ywxw()
		{
			return { y, w, x, w };
		}

		inline Vector4<T> ywyx()
		{
			return { y, w, y, x };
		}

		inline Vector4<T> ywyy()
		{
			return { y, w, y, y };
		}

		inline Vector4<T> ywyz()
		{
			return { y, w, y, z };
		}

		inline Vector4<T> ywyw()
		{
			return { y, w, y, w };
		}

		inline Vector4<T> ywzx()
		{
			return { y, w, z, x };
		}

		inline Vector4<T> ywzy()
		{
			return { y, w, z, y };
		}

		inline Vector4<T> ywzz()
		{
			return { y, w, z, z };
		}

		inline Vector4<T> ywzw()
		{
			return { y, w, z, w };
		}

		inline Vector4<T> ywwx()
		{
			return { y, w, w, x };
		}

		inline Vector4<T> ywwy()
		{
			return { y, w, w, y };
		}

		inline Vector4<T> ywwz()
		{
			return { y, w, w, z };
		}

		inline Vector4<T> ywww()
		{
			return { y, w, w, w };
		}

		inline Vector4<T> zxxx()
		{
			return { z, x, x, x };
		}

		inline Vector4<T> zxxy()
		{
			return { z, x, x, y };
		}

		inline Vector4<T> zxxz()
		{
			return { z, x, x, z };
		}

		inline Vector4<T> zxxw()
		{
			return { z, x, x, w };
		}

		inline Vector4<T> zxyx()
		{
			return { z, x, y, x };
		}

		inline Vector4<T> zxyy()
		{
			return { z, x, y, y };
		}

		inline Vector4<T> zxyz()
		{
			return { z, x, y, z };
		}

		inline Vector4<T> zxyw()
		{
			return { z, x, y, w };
		}

		inline Vector4<T> zxzx()
		{
			return { z, x, z, x };
		}

		inline Vector4<T> zxzy()
		{
			return { z, x, z, y };
		}

		inline Vector4<T> zxzz()
		{
			return { z, x, z, z };
		}

		inline Vector4<T> zxzw()
		{
			return { z, x, z, w };
		}

		inline Vector4<T> zxwx()
		{
			return { z, x, w, x };
		}

		inline Vector4<T> zxwy()
		{
			return { z, x, w, y };
		}

		inline Vector4<T> zxwz()
		{
			return { z, x, w, z };
		}

		inline Vector4<T> zxww()
		{
			return { z, x, w, w };
		}

		inline Vector4<T> zyxx()
		{
			return { z, y, x, x };
		}

		inline Vector4<T> zyxy()
		{
			return { z, y, x, y };
		}

		inline Vector4<T> zyxz()
		{
			return { z, y, x, z };
		}

		inline Vector4<T> zyxw()
		{
			return { z, y, x, w };
		}

		inline Vector4<T> zyyx()
		{
			return { z, y, y, x };
		}

		inline Vector4<T> zyyy()
		{
			return { z, y, y, y };
		}

		inline Vector4<T> zyyz()
		{
			return { z, y, y, z };
		}

		inline Vector4<T> zyyw()
		{
			return { z, y, y, w };
		}

		inline Vector4<T> zyzx()
		{
			return { z, y, z, x };
		}

		inline Vector4<T> zyzy()
		{
			return { z, y, z, y };
		}

		inline Vector4<T> zyzz()
		{
			return { z, y, z, z };
		}

		inline Vector4<T> zyzw()
		{
			return { z, y, z, w };
		}

		inline Vector4<T> zywx()
		{
			return { z, y, w, x };
		}

		inline Vector4<T> zywy()
		{
			return { z, y, w, y };
		}

		inline Vector4<T> zywz()
		{
			return { z, y, w, z };
		}

		inline Vector4<T> zyww()
		{
			return { z, y, w, w };
		}

		inline Vector4<T> zzxx()
		{
			return { z, z, x, x };
		}

		inline Vector4<T> zzxy()
		{
			return { z, z, x, y };
		}

		inline Vector4<T> zzxz()
		{
			return { z, z, x, z };
		}

		inline Vector4<T> zzxw()
		{
			return { z, z, x, w };
		}

		inline Vector4<T> zzyx()
		{
			return { z, z, y, x };
		}

		inline Vector4<T> zzyy()
		{
			return { z, z, y, y };
		}

		inline Vector4<T> zzyz()
		{
			return { z, z, y, z };
		}

		inline Vector4<T> zzyw()
		{
			return { z, z, y, w };
		}

		inline Vector4<T> zzzx()
		{
			return { z, z, z, x };
		}

		inline Vector4<T> zzzy()
		{
			return { z, z, z, y };
		}

		inline Vector4<T> zzzz()
		{
			return { z, z, z, z };
		}

		inline Vector4<T> zzzw()
		{
			return { z, z, z, w };
		}

		inline Vector4<T> zzwx()
		{
			return { z, z, w, x };
		}

		inline Vector4<T> zzwy()
		{
			return { z, z, w, y };
		}

		inline Vector4<T> zzwz()
		{
			return { z, z, w, z };
		}

		inline Vector4<T> zzww()
		{
			return { z, z, w, w };
		}

		inline Vector4<T> zwxx()
		{
			return { z, w, x, x };
		}

		inline Vector4<T> zwxy()
		{
			return { z, w, x, y };
		}

		inline Vector4<T> zwxz()
		{
			return { z, w, x, z };
		}

		inline Vector4<T> zwxw()
		{
			return { z, w, x, w };
		}

		inline Vector4<T> zwyx()
		{
			return { z, w, y, x };
		}

		inline Vector4<T> zwyy()
		{
			return { z, w, y, y };
		}

		inline Vector4<T> zwyz()
		{
			return { z, w, y, z };
		}

		inline Vector4<T> zwyw()
		{
			return { z, w, y, w };
		}

		inline Vector4<T> zwzx()
		{
			return { z, w, z, x };
		}

		inline Vector4<T> zwzy()
		{
			return { z, w, z, y };
		}

		inline Vector4<T> zwzz()
		{
			return { z, w, z, z };
		}

		inline Vector4<T> zwzw()
		{
			return { z, w, z, w };
		}

		inline Vector4<T> zwwx()
		{
			return { z, w, w, x };
		}

		inline Vector4<T> zwwy()
		{
			return { z, w, w, y };
		}

		inline Vector4<T> zwwz()
		{
			return { z, w, w, z };
		}

		inline Vector4<T> zwww()
		{
			return { z, w, w, w };
		}

		inline Vector4<T> wxxx()
		{
			return { w, x, x, x };
		}

		inline Vector4<T> wxxy()
		{
			return { w, x, x, y };
		}

		inline Vector4<T> wxxz()
		{
			return { w, x, x, z };
		}

		inline Vector4<T> wxxw()
		{
			return { w, x, x, w };
		}

		inline Vector4<T> wxyx()
		{
			return { w, x, y, x };
		}

		inline Vector4<T> wxyy()
		{
			return { w, x, y, y };
		}

		inline Vector4<T> wxyz()
		{
			return { w, x, y, z };
		}

		inline Vector4<T> wxyw()
		{
			return { w, x, y, w };
		}

		inline Vector4<T> wxzx()
		{
			return { w, x, z, x };
		}

		inline Vector4<T> wxzy()
		{
			return { w, x, z, y };
		}

		inline Vector4<T> wxzz()
		{
			return { w, x, z, z };
		}

		inline Vector4<T> wxzw()
		{
			return { w, x, z, w };
		}

		inline Vector4<T> wxwx()
		{
			return { w, x, w, x };
		}

		inline Vector4<T> wxwy()
		{
			return { w, x, w, y };
		}

		inline Vector4<T> wxwz()
		{
			return { w, x, w, z };
		}

		inline Vector4<T> wxww()
		{
			return { w, x, w, w };
		}

		inline Vector4<T> wyxx()
		{
			return { w, y, x, x };
		}

		inline Vector4<T> wyxy()
		{
			return { w, y, x, y };
		}

		inline Vector4<T> wyxz()
		{
			return { w, y, x, z };
		}

		inline Vector4<T> wyxw()
		{
			return { w, y, x, w };
		}

		inline Vector4<T> wyyx()
		{
			return { w, y, y, x };
		}

		inline Vector4<T> wyyy()
		{
			return { w, y, y, y };
		}

		inline Vector4<T> wyyz()
		{
			return { w, y, y, z };
		}

		inline Vector4<T> wyyw()
		{
			return { w, y, y, w };
		}

		inline Vector4<T> wyzx()
		{
			return { w, y, z, x };
		}

		inline Vector4<T> wyzy()
		{
			return { w, y, z, y };
		}

		inline Vector4<T> wyzz()
		{
			return { w, y, z, z };
		}

		inline Vector4<T> wyzw()
		{
			return { w, y, z, w };
		}

		inline Vector4<T> wywx()
		{
			return { w, y, w, x };
		}

		inline Vector4<T> wywy()
		{
			return { w, y, w, y };
		}

		inline Vector4<T> wywz()
		{
			return { w, y, w, z };
		}

		inline Vector4<T> wyww()
		{
			return { w, y, w, w };
		}

		inline Vector4<T> wzxx()
		{
			return { w, z, x, x };
		}

		inline Vector4<T> wzxy()
		{
			return { w, z, x, y };
		}

		inline Vector4<T> wzxz()
		{
			return { w, z, x, z };
		}

		inline Vector4<T> wzxw()
		{
			return { w, z, x, w };
		}

		inline Vector4<T> wzyx()
		{
			return { w, z, y, x };
		}

		inline Vector4<T> wzyy()
		{
			return { w, z, y, y };
		}

		inline Vector4<T> wzyz()
		{
			return { w, z, y, z };
		}

		inline Vector4<T> wzyw()
		{
			return { w, z, y, w };
		}

		inline Vector4<T> wzzx()
		{
			return { w, z, z, x };
		}

		inline Vector4<T> wzzy()
		{
			return { w, z, z, y };
		}

		inline Vector4<T> wzzz()
		{
			return { w, z, z, z };
		}

		inline Vector4<T> wzzw()
		{
			return { w, z, z, w };
		}

		inline Vector4<T> wzwx()
		{
			return { w, z, w, x };
		}

		inline Vector4<T> wzwy()
		{
			return { w, z, w, y };
		}

		inline Vector4<T> wzwz()
		{
			return { w, z, w, z };
		}

		inline Vector4<T> wzww()
		{
			return { w, z, w, w };
		}

		inline Vector4<T> wwxx()
		{
			return { w, w, x, x };
		}

		inline Vector4<T> wwxy()
		{
			return { w, w, x, y };
		}

		inline Vector4<T> wwxz()
		{
			return { w, w, x, z };
		}

		inline Vector4<T> wwxw()
		{
			return { w, w, x, w };
		}

		inline Vector4<T> wwyx()
		{
			return { w, w, y, x };
		}

		inline Vector4<T> wwyy()
		{
			return { w, w, y, y };
		}

		inline Vector4<T> wwyz()
		{
			return { w, w, y, z };
		}

		inline Vector4<T> wwyw()
		{
			return { w, w, y, w };
		}

		inline Vector4<T> wwzx()
		{
			return { w, w, z, x };
		}

		inline Vector4<T> wwzy()
		{
			return { w, w, z, y };
		}

		inline Vector4<T> wwzz()
		{
			return { w, w, z, z };
		}

		inline Vector4<T> wwzw()
		{
			return { w, w, z, w };
		}

		inline Vector4<T> wwwx()
		{
			return { w, w, w, x };
		}

		inline Vector4<T> wwwy()
		{
			return { w, w, w, y };
		}

		inline Vector4<T> wwwz()
		{
			return { w, w, w, z };
		}

		inline Vector4<T> wwww()
		{
			return { w, w, w, w };
		}

		// Vector4 -> Vector3 swizzle, xyzw
		inline Vector3<T> xxx()
		{
			return { x, x, x };
		}

		inline Vector3<T> xxy()
		{
			return { x, x, y };
		}

		inline Vector3<T> xxz()
		{
			return { x, x, z };
		}

		inline Vector3<T> xxw()
		{
			return { x, x, w };
		}

		inline Vector3<T> xyx()
		{
			return { x, y, x };
		}

		inline Vector3<T> xyy()
		{
			return { x, y, y };
		}

		inline Vector3<T> xyz()
		{
			return { x, y, z };
		}

		inline Vector3<T> xyw()
		{
			return { x, y, w };
		}

		inline Vector3<T> xzx()
		{
			return { x, z, x };
		}

		inline Vector3<T> xzy()
		{
			return { x, z, y };
		}

		inline Vector3<T> xzz()
		{
			return { x, z, z };
		}

		inline Vector3<T> xzw()
		{
			return { x, z, w };
		}

		inline Vector3<T> xwx()
		{
			return { x, w, x };
		}

		inline Vector3<T> xwy()
		{
			return { x, w, y };
		}

		inline Vector3<T> xwz()
		{
			return { x, w, z };
		}

		inline Vector3<T> xww()
		{
			return { x, w, w };
		}

		inline Vector3<T> yxx()
		{
			return { y, x, x };
		}

		inline Vector3<T> yxy()
		{
			return { y, x, y };
		}

		inline Vector3<T> yxz()
		{
			return { y, x, z };
		}

		inline Vector3<T> yxw()
		{
			return { y, x, w };
		}

		inline Vector3<T> yyx()
		{
			return { y, y, x };
		}

		inline Vector3<T> yyy()
		{
			return { y, y, y };
		}

		inline Vector3<T> yyz()
		{
			return { y, y, z };
		}

		inline Vector3<T> yyw()
		{
			return { y, y, w };
		}

		inline Vector3<T> yzx()
		{
			return { y, z, x };
		}

		inline Vector3<T> yzy()
		{
			return { y, z, y };
		}

		inline Vector3<T> yzz()
		{
			return { y, z, z };
		}

		inline Vector3<T> yzw()
		{
			return { y, z, w };
		}

		inline Vector3<T> ywx()
		{
			return { y, w, x };
		}

		inline Vector3<T> ywy()
		{
			return { y, w, y };
		}

		inline Vector3<T> ywz()
		{
			return { y, w, z };
		}

		inline Vector3<T> yww()
		{
			return { y, w, w };
		}

		inline Vector3<T> zxx()
		{
			return { z, x, x };
		}

		inline Vector3<T> zxy()
		{
			return { z, x, y };
		}

		inline Vector3<T> zxz()
		{
			return { z, x, z };
		}

		inline Vector3<T> zxw()
		{
			return { z, x, w };
		}

		inline Vector3<T> zyx()
		{
			return { z, y, x };
		}

		inline Vector3<T> zyy()
		{
			return { z, y, y };
		}

		inline Vector3<T> zyz()
		{
			return { z, y, z };
		}

		inline Vector3<T> zyw()
		{
			return { z, y, w };
		}

		inline Vector3<T> zzx()
		{
			return { z, z, x };
		}

		inline Vector3<T> zzy()
		{
			return { z, z, y };
		}

		inline Vector3<T> zzz()
		{
			return { z, z, z };
		}

		inline Vector3<T> zzw()
		{
			return { z, z, w };
		}

		inline Vector3<T> zwx()
		{
			return { z, w, x };
		}

		inline Vector3<T> zwy()
		{
			return { z, w, y };
		}

		inline Vector3<T> zwz()
		{
			return { z, w, z };
		}

		inline Vector3<T> zww()
		{
			return { z, w, w };
		}

		inline Vector3<T> wxx()
		{
			return { w, x, x };
		}

		inline Vector3<T> wxy()
		{
			return { w, x, y };
		}

		inline Vector3<T> wxz()
		{
			return { w, x, z };
		}

		inline Vector3<T> wxw()
		{
			return { w, x, w };
		}

		inline Vector3<T> wyx()
		{
			return { w, y, x };
		}

		inline Vector3<T> wyy()
		{
			return { w, y, y };
		}

		inline Vector3<T> wyz()
		{
			return { w, y, z };
		}

		inline Vector3<T> wyw()
		{
			return { w, y, w };
		}

		inline Vector3<T> wzx()
		{
			return { w, z, x };
		}

		inline Vector3<T> wzy()
		{
			return { w, z, y };
		}

		inline Vector3<T> wzz()
		{
			return { w, z, z };
		}

		inline Vector3<T> wzw()
		{
			return { w, z, w };
		}

		inline Vector3<T> wwx()
		{
			return { w, w, x };
		}

		inline Vector3<T> wwy()
		{
			return { w, w, y };
		}

		inline Vector3<T> wwz()
		{
			return { w, w, z };
		}

		inline Vector3<T> www()
		{
			return { w, w, w };
		}

		// Vector4 -> Vector2 swizzle, xyzw
		inline Vector2<T> xx()
		{
			return { x, x };
		}

		inline Vector2<T> xy()
		{
			return { x, y };
		}

		inline Vector2<T> xz()
		{
			return { x, z };
		}

		inline Vector2<T> xw()
		{
			return { x, w };
		}

		inline Vector2<T> yx()
		{
			return { y, x };
		}

		inline Vector2<T> yy()
		{
			return { y, y };
		}

		inline Vector2<T> yz()
		{
			return { y, z };
		}

		inline Vector2<T> yw()
		{
			return { y, w };
		}

		inline Vector2<T> zx()
		{
			return { z, x };
		}

		inline Vector2<T> zy()
		{
			return { z, y };
		}

		inline Vector2<T> zz()
		{
			return { z, z };
		}

		inline Vector2<T> zw()
		{
			return { z, w };
		}

		inline Vector2<T> wx()
		{
			return { w, x };
		}

		inline Vector2<T> wy()
		{
			return { w, y };
		}

		inline Vector2<T> wz()
		{
			return { w, z };
		}

		inline Vector2<T> ww()
		{
			return { w, w };
		}

		// Vector4 -> Vector4 swizzle, rgba
		inline Vector4<T> rrrr()
		{
			return { r, r, r, r };
		}

		inline Vector4<T> rrrg()
		{
			return { r, r, r, g };
		}

		inline Vector4<T> rrrb()
		{
			return { r, r, r, b };
		}

		inline Vector4<T> rrra()
		{
			return { r, r, r, a };
		}

		inline Vector4<T> rrgr()
		{
			return { r, r, g, r };
		}

		inline Vector4<T> rrgg()
		{
			return { r, r, g, g };
		}

		inline Vector4<T> rrgb()
		{
			return { r, r, g, b };
		}

		inline Vector4<T> rrga()
		{
			return { r, r, g, a };
		}

		inline Vector4<T> rrbr()
		{
			return { r, r, b, r };
		}

		inline Vector4<T> rrbg()
		{
			return { r, r, b, g };
		}

		inline Vector4<T> rrbb()
		{
			return { r, r, b, b };
		}

		inline Vector4<T> rrba()
		{
			return { r, r, b, a };
		}

		inline Vector4<T> rrar()
		{
			return { r, r, a, r };
		}

		inline Vector4<T> rrag()
		{
			return { r, r, a, g };
		}

		inline Vector4<T> rrab()
		{
			return { r, r, a, b };
		}

		inline Vector4<T> rraa()
		{
			return { r, r, a, a };
		}

		inline Vector4<T> rgrr()
		{
			return { r, g, r, r };
		}

		inline Vector4<T> rgrg()
		{
			return { r, g, r, g };
		}

		inline Vector4<T> rgrb()
		{
			return { r, g, r, b };
		}

		inline Vector4<T> rgra()
		{
			return { r, g, r, a };
		}

		inline Vector4<T> rggr()
		{
			return { r, g, g, r };
		}

		inline Vector4<T> rggg()
		{
			return { r, g, g, g };
		}

		inline Vector4<T> rggb()
		{
			return { r, g, g, b };
		}

		inline Vector4<T> rgga()
		{
			return { r, g, g, a };
		}

		inline Vector4<T> rgbr()
		{
			return { r, g, b, r };
		}

		inline Vector4<T> rgbg()
		{
			return { r, g, b, g };
		}

		inline Vector4<T> rgbb()
		{
			return { r, g, b, b };
		}

		inline Vector4<T> rgar()
		{
			return { r, g, a, r };
		}

		inline Vector4<T> rgag()
		{
			return { r, g, a, g };
		}

		inline Vector4<T> rgab()
		{
			return { r, g, a, b };
		}

		inline Vector4<T> rgaa()
		{
			return { r, g, a, a };
		}

		inline Vector4<T> rbrr()
		{
			return { r, b, r, r };
		}

		inline Vector4<T> rbrg()
		{
			return { r, b, r, g };
		}

		inline Vector4<T> rbrb()
		{
			return { r, b, r, b };
		}

		inline Vector4<T> rbra()
		{
			return { r, b, r, a };
		}

		inline Vector4<T> rbgr()
		{
			return { r, b, g, r };
		}

		inline Vector4<T> rbgg()
		{
			return { r, b, g, g };
		}

		inline Vector4<T> rbgb()
		{
			return { r, b, g, b };
		}

		inline Vector4<T> rbga()
		{
			return { r, b, g, a };
		}

		inline Vector4<T> rbbr()
		{
			return { r, b, b, r };
		}

		inline Vector4<T> rbbg()
		{
			return { r, b, b, g };
		}

		inline Vector4<T> rbbb()
		{
			return { r, b, b, b };
		}

		inline Vector4<T> rbba()
		{
			return { r, b, b, a };
		}

		inline Vector4<T> rbar()
		{
			return { r, b, a, r };
		}

		inline Vector4<T> rbag()
		{
			return { r, b, a, g };
		}

		inline Vector4<T> rbab()
		{
			return { r, b, a, b };
		}

		inline Vector4<T> rbaa()
		{
			return { r, b, a, a };
		}

		inline Vector4<T> rarr()
		{
			return { r, a, r, r };
		}

		inline Vector4<T> rarg()
		{
			return { r, a, r, g };
		}

		inline Vector4<T> rarb()
		{
			return { r, a, r, b };
		}

		inline Vector4<T> rara()
		{
			return { r, a, r, a };
		}

		inline Vector4<T> ragr()
		{
			return { r, a, g, r };
		}

		inline Vector4<T> ragg()
		{
			return { r, a, g, g };
		}

		inline Vector4<T> ragb()
		{
			return { r, a, g, b };
		}

		inline Vector4<T> raga()
		{
			return { r, a, g, a };
		}

		inline Vector4<T> rabr()
		{
			return { r, a, b, r };
		}

		inline Vector4<T> rabg()
		{
			return { r, a, b, g };
		}

		inline Vector4<T> rabb()
		{
			return { r, a, b, b };
		}

		inline Vector4<T> raba()
		{
			return { r, a, b, a };
		}

		inline Vector4<T> raar()
		{
			return { r, a, a, r };
		}

		inline Vector4<T> raag()
		{
			return { r, a, a, g };
		}

		inline Vector4<T> raab()
		{
			return { r, a, a, b };
		}

		inline Vector4<T> raaa()
		{
			return { r, a, a, a };
		}

		inline Vector4<T> grrr()
		{
			return { g, r, r, r };
		}

		inline Vector4<T> grrg()
		{
			return { g, r, r, g };
		}

		inline Vector4<T> grrb()
		{
			return { g, r, r, b };
		}

		inline Vector4<T> grra()
		{
			return { g, r, r, a };
		}

		inline Vector4<T> grgr()
		{
			return { g, r, g, r };
		}

		inline Vector4<T> grgg()
		{
			return { g, r, g, g };
		}

		inline Vector4<T> grgb()
		{
			return { g, r, g, b };
		}

		inline Vector4<T> grga()
		{
			return { g, r, g, a };
		}

		inline Vector4<T> grbr()
		{
			return { g, r, b, r };
		}

		inline Vector4<T> grbg()
		{
			return { g, r, b, g };
		}

		inline Vector4<T> grbb()
		{
			return { g, r, b, b };
		}

		inline Vector4<T> grba()
		{
			return { g, r, b, a };
		}

		inline Vector4<T> grar()
		{
			return { g, r, a, r };
		}

		inline Vector4<T> grag()
		{
			return { g, r, a, g };
		}

		inline Vector4<T> grab()
		{
			return { g, r, a, b };
		}

		inline Vector4<T> graa()
		{
			return { g, r, a, a };
		}

		inline Vector4<T> ggrr()
		{
			return { g, g, r, r };
		}

		inline Vector4<T> ggrg()
		{
			return { g, g, r, g };
		}

		inline Vector4<T> ggrb()
		{
			return { g, g, r, b };
		}

		inline Vector4<T> ggra()
		{
			return { g, g, r, a };
		}

		inline Vector4<T> gggr()
		{
			return { g, g, g, r };
		}

		inline Vector4<T> gggg()
		{
			return { g, g, g, g };
		}

		inline Vector4<T> gggb()
		{
			return { g, g, g, b };
		}

		inline Vector4<T> ggga()
		{
			return { g, g, g, a };
		}

		inline Vector4<T> ggbr()
		{
			return { g, g, b, r };
		}

		inline Vector4<T> ggbg()
		{
			return { g, g, b, g };
		}

		inline Vector4<T> ggbb()
		{
			return { g, g, b, b };
		}

		inline Vector4<T> ggba()
		{
			return { g, g, b, a };
		}

		inline Vector4<T> ggar()
		{
			return { g, g, a, r };
		}

		inline Vector4<T> ggag()
		{
			return { g, g, a, g };
		}

		inline Vector4<T> ggab()
		{
			return { g, g, a, b };
		}

		inline Vector4<T> ggaa()
		{
			return { g, g, a, a };
		}

		inline Vector4<T> gbrr()
		{
			return { g, b, r, r };
		}

		inline Vector4<T> gbrg()
		{
			return { g, b, r, g };
		}

		inline Vector4<T> gbrb()
		{
			return { g, b, r, b };
		}

		inline Vector4<T> gbra()
		{
			return { g, b, r, a };
		}

		inline Vector4<T> gbgr()
		{
			return { g, b, g, r };
		}

		inline Vector4<T> gbgg()
		{
			return { g, b, g, g };
		}

		inline Vector4<T> gbgb()
		{
			return { g, b, g, b };
		}

		inline Vector4<T> gbga()
		{
			return { g, b, g, a };
		}

		inline Vector4<T> gbbr()
		{
			return { g, b, b, r };
		}

		inline Vector4<T> gbbg()
		{
			return { g, b, b, g };
		}

		inline Vector4<T> gbbb()
		{
			return { g, b, b, b };
		}

		inline Vector4<T> gbba()
		{
			return { g, b, b, a };
		}

		inline Vector4<T> gbar()
		{
			return { g, b, a, r };
		}

		inline Vector4<T> gbag()
		{
			return { g, b, a, g };
		}

		inline Vector4<T> gbab()
		{
			return { g, b, a, b };
		}

		inline Vector4<T> gbaa()
		{
			return { g, b, a, a };
		}

		inline Vector4<T> garr()
		{
			return { g, a, r, r };
		}

		inline Vector4<T> garg()
		{
			return { g, a, r, g };
		}

		inline Vector4<T> garb()
		{
			return { g, a, r, b };
		}

		inline Vector4<T> gara()
		{
			return { g, a, r, a };
		}

		inline Vector4<T> gagr()
		{
			return { g, a, g, r };
		}

		inline Vector4<T> gagg()
		{
			return { g, a, g, g };
		}

		inline Vector4<T> gagb()
		{
			return { g, a, g, b };
		}

		inline Vector4<T> gaga()
		{
			return { g, a, g, a };
		}

		inline Vector4<T> gabr()
		{
			return { g, a, b, r };
		}

		inline Vector4<T> gabg()
		{
			return { g, a, b, g };
		}

		inline Vector4<T> gabb()
		{
			return { g, a, b, b };
		}

		inline Vector4<T> gaba()
		{
			return { g, a, b, a };
		}

		inline Vector4<T> gaar()
		{
			return { g, a, a, r };
		}

		inline Vector4<T> gaag()
		{
			return { g, a, a, g };
		}

		inline Vector4<T> gaab()
		{
			return { g, a, a, b };
		}

		inline Vector4<T> gaaa()
		{
			return { g, a, a, a };
		}

		inline Vector4<T> brrr()
		{
			return { b, r, r, r };
		}

		inline Vector4<T> brrg()
		{
			return { b, r, r, g };
		}

		inline Vector4<T> brrb()
		{
			return { b, r, r, b };
		}

		inline Vector4<T> brra()
		{
			return { b, r, r, a };
		}

		inline Vector4<T> brgr()
		{
			return { b, r, g, r };
		}

		inline Vector4<T> brgg()
		{
			return { b, r, g, g };
		}

		inline Vector4<T> brgb()
		{
			return { b, r, g, b };
		}

		inline Vector4<T> brga()
		{
			return { b, r, g, a };
		}

		inline Vector4<T> brbr()
		{
			return { b, r, b, r };
		}

		inline Vector4<T> brbg()
		{
			return { b, r, b, g };
		}

		inline Vector4<T> brbb()
		{
			return { b, r, b, b };
		}

		inline Vector4<T> brba()
		{
			return { b, r, b, a };
		}

		inline Vector4<T> brar()
		{
			return { b, r, a, r };
		}

		inline Vector4<T> brag()
		{
			return { b, r, a, g };
		}

		inline Vector4<T> brab()
		{
			return { b, r, a, b };
		}

		inline Vector4<T> braa()
		{
			return { b, r, a, a };
		}

		inline Vector4<T> bgrr()
		{
			return { b, g, r, r };
		}

		inline Vector4<T> bgrg()
		{
			return { b, g, r, g };
		}

		inline Vector4<T> bgrb()
		{
			return { b, g, r, b };
		}

		inline Vector4<T> bgra()
		{
			return { b, g, r, a };
		}

		inline Vector4<T> bggr()
		{
			return { b, g, g, r };
		}

		inline Vector4<T> bggg()
		{
			return { b, g, g, g };
		}

		inline Vector4<T> bggb()
		{
			return { b, g, g, b };
		}

		inline Vector4<T> bgga()
		{
			return { b, g, g, a };
		}

		inline Vector4<T> bgbr()
		{
			return { b, g, b, r };
		}

		inline Vector4<T> bgbg()
		{
			return { b, g, b, g };
		}

		inline Vector4<T> bgbb()
		{
			return { b, g, b, b };
		}

		inline Vector4<T> bgba()
		{
			return { b, g, b, a };
		}

		inline Vector4<T> bgar()
		{
			return { b, g, a, r };
		}

		inline Vector4<T> bgag()
		{
			return { b, g, a, g };
		}

		inline Vector4<T> bgab()
		{
			return { b, g, a, b };
		}

		inline Vector4<T> bgaa()
		{
			return { b, g, a, a };
		}

		inline Vector4<T> bbrr()
		{
			return { b, b, r, r };
		}

		inline Vector4<T> bbrg()
		{
			return { b, b, r, g };
		}

		inline Vector4<T> bbrb()
		{
			return { b, b, r, b };
		}

		inline Vector4<T> bbra()
		{
			return { b, b, r, a };
		}

		inline Vector4<T> bbgr()
		{
			return { b, b, g, r };
		}

		inline Vector4<T> bbgg()
		{
			return { b, b, g, g };
		}

		inline Vector4<T> bbgb()
		{
			return { b, b, g, b };
		}

		inline Vector4<T> bbga()
		{
			return { b, b, g, a };
		}

		inline Vector4<T> bbbr()
		{
			return { b, b, b, r };
		}

		inline Vector4<T> bbbg()
		{
			return { b, b, b, g };
		}

		inline Vector4<T> bbbb()
		{
			return { b, b, b, b };
		}

		inline Vector4<T> bbba()
		{
			return { b, b, b, a };
		}

		inline Vector4<T> bbar()
		{
			return { b, b, a, r };
		}

		inline Vector4<T> bbag()
		{
			return { b, b, a, g };
		}

		inline Vector4<T> bbab()
		{
			return { b, b, a, b };
		}

		inline Vector4<T> bbaa()
		{
			return { b, b, a, a };
		}

		inline Vector4<T> barr()
		{
			return { b, a, r, r };
		}

		inline Vector4<T> barg()
		{
			return { b, a, r, g };
		}

		inline Vector4<T> barb()
		{
			return { b, a, r, b };
		}

		inline Vector4<T> bara()
		{
			return { b, a, r, a };
		}

		inline Vector4<T> bagr()
		{
			return { b, a, g, r };
		}

		inline Vector4<T> bagg()
		{
			return { b, a, g, g };
		}

		inline Vector4<T> bagb()
		{
			return { b, a, g, b };
		}

		inline Vector4<T> baga()
		{
			return { b, a, g, a };
		}

		inline Vector4<T> babr()
		{
			return { b, a, b, r };
		}

		inline Vector4<T> babg()
		{
			return { b, a, b, g };
		}

		inline Vector4<T> babb()
		{
			return { b, a, b, b };
		}

		inline Vector4<T> baba()
		{
			return { b, a, b, a };
		}

		inline Vector4<T> baar()
		{
			return { b, a, a, r };
		}

		inline Vector4<T> baag()
		{
			return { b, a, a, g };
		}

		inline Vector4<T> baab()
		{
			return { b, a, a, b };
		}

		inline Vector4<T> baaa()
		{
			return { b, a, a, a };
		}

		inline Vector4<T> arrr()
		{
			return { a, r, r, r };
		}

		inline Vector4<T> arrg()
		{
			return { a, r, r, g };
		}

		inline Vector4<T> arrb()
		{
			return { a, r, r, b };
		}

		inline Vector4<T> arra()
		{
			return { a, r, r, a };
		}

		inline Vector4<T> argr()
		{
			return { a, r, g, r };
		}

		inline Vector4<T> argg()
		{
			return { a, r, g, g };
		}

		inline Vector4<T> argb()
		{
			return { a, r, g, b };
		}

		inline Vector4<T> arga()
		{
			return { a, r, g, a };
		}

		inline Vector4<T> arbr()
		{
			return { a, r, b, r };
		}

		inline Vector4<T> arbg()
		{
			return { a, r, b, g };
		}

		inline Vector4<T> arbb()
		{
			return { a, r, b, b };
		}

		inline Vector4<T> arba()
		{
			return { a, r, b, a };
		}

		inline Vector4<T> arar()
		{
			return { a, r, a, r };
		}

		inline Vector4<T> arag()
		{
			return { a, r, a, g };
		}

		inline Vector4<T> arab()
		{
			return { a, r, a, b };
		}

		inline Vector4<T> araa()
		{
			return { a, r, a, a };
		}

		inline Vector4<T> agrr()
		{
			return { a, g, r, r };
		}

		inline Vector4<T> agrg()
		{
			return { a, g, r, g };
		}

		inline Vector4<T> agrb()
		{
			return { a, g, r, b };
		}

		inline Vector4<T> agra()
		{
			return { a, g, r, a };
		}

		inline Vector4<T> aggr()
		{
			return { a, g, g, r };
		}

		inline Vector4<T> aggg()
		{
			return { a, g, g, g };
		}

		inline Vector4<T> aggb()
		{
			return { a, g, g, b };
		}

		inline Vector4<T> agga()
		{
			return { a, g, g, a };
		}

		inline Vector4<T> agbr()
		{
			return { a, g, b, r };
		}

		inline Vector4<T> agbg()
		{
			return { a, g, b, g };
		}

		inline Vector4<T> agbb()
		{
			return { a, g, b, b };
		}

		inline Vector4<T> agba()
		{
			return { a, g, b, a };
		}

		inline Vector4<T> agar()
		{
			return { a, g, a, r };
		}

		inline Vector4<T> agag()
		{
			return { a, g, a, g };
		}

		inline Vector4<T> agab()
		{
			return { a, g, a, b };
		}

		inline Vector4<T> agaa()
		{
			return { a, g, a, a };
		}

		inline Vector4<T> abrr()
		{
			return { a, b, r, r };
		}

		inline Vector4<T> abrg()
		{
			return { a, b, r, g };
		}

		inline Vector4<T> abrb()
		{
			return { a, b, r, b };
		}

		inline Vector4<T> abra()
		{
			return { a, b, r, a };
		}

		inline Vector4<T> abgr()
		{
			return { a, b, g, r };
		}

		inline Vector4<T> abgg()
		{
			return { a, b, g, g };
		}

		inline Vector4<T> abgb()
		{
			return { a, b, g, b };
		}

		inline Vector4<T> abga()
		{
			return { a, b, g, a };
		}

		inline Vector4<T> abbr()
		{
			return { a, b, b, r };
		}

		inline Vector4<T> abbg()
		{
			return { a, b, b, g };
		}

		inline Vector4<T> abbb()
		{
			return { a, b, b, b };
		}

		inline Vector4<T> abba()
		{
			return { a, b, b, a };
		}

		inline Vector4<T> abar()
		{
			return { a, b, a, r };
		}

		inline Vector4<T> abag()
		{
			return { a, b, a, g };
		}

		inline Vector4<T> abab()
		{
			return { a, b, a, b };
		}

		inline Vector4<T> abaa()
		{
			return { a, b, a, a };
		}

		inline Vector4<T> aarr()
		{
			return { a, a, r, r };
		}

		inline Vector4<T> aarg()
		{
			return { a, a, r, g };
		}

		inline Vector4<T> aarb()
		{
			return { a, a, r, b };
		}

		inline Vector4<T> aara()
		{
			return { a, a, r, a };
		}

		inline Vector4<T> aagr()
		{
			return { a, a, g, r };
		}

		inline Vector4<T> aagg()
		{
			return { a, a, g, g };
		}

		inline Vector4<T> aagb()
		{
			return { a, a, g, b };
		}

		inline Vector4<T> aaga()
		{
			return { a, a, g, a };
		}

		inline Vector4<T> aabr()
		{
			return { a, a, b, r };
		}

		inline Vector4<T> aabg()
		{
			return { a, a, b, g };
		}

		inline Vector4<T> aabb()
		{
			return { a, a, b, b };
		}

		inline Vector4<T> aaba()
		{
			return { a, a, b, a };
		}

		inline Vector4<T> aaar()
		{
			return { a, a, a, r };
		}

		inline Vector4<T> aaag()
		{
			return { a, a, a, g };
		}

		inline Vector4<T> aaab()
		{
			return { a, a, a, b };
		}

		inline Vector4<T> aaaa()
		{
			return { a, a, a, a };
		}

		// Vector4 -> Vector3 swizzle, rgba
		inline Vector3<T> rrr()
		{
			return { r, r, r };
		}

		inline Vector3<T> rrg()
		{
			return { r, r, g };
		}

		inline Vector3<T> rrb()
		{
			return { r, r, b };
		}

		inline Vector3<T> rra()
		{
			return { r, r, a };
		}

		inline Vector3<T> rgr()
		{
			return { r, g, r };
		}

		inline Vector3<T> rgg()
		{
			return { r, g, g };
		}

		inline Vector3<T> rgb()
		{
			return { r, g, b };
		}

		inline Vector3<T> rga()
		{
			return { r, g, a };
		}

		inline Vector3<T> rbr()
		{
			return { r, b, r };
		}

		inline Vector3<T> rbg()
		{
			return { r, b, g };
		}

		inline Vector3<T> rbb()
		{
			return { r, b, b };
		}

		inline Vector3<T> rba()
		{
			return { r, b, a };
		}

		inline Vector3<T> rar()
		{
			return { r, a, r };
		}

		inline Vector3<T> rag()
		{
			return { r, a, g };
		}

		inline Vector3<T> rab()
		{
			return { r, a, b };
		}

		inline Vector3<T> raa()
		{
			return { r, a, a };
		}

		inline Vector3<T> grr()
		{
			return { g, r, r };
		}

		inline Vector3<T> grg()
		{
			return { g, r, g };
		}

		inline Vector3<T> grb()
		{
			return { g, r, b };
		}

		inline Vector3<T> gra()
		{
			return { g, r, a };
		}

		inline Vector3<T> ggr()
		{
			return { g, g, r };
		}

		inline Vector3<T> ggg()
		{
			return { g, g, g };
		}

		inline Vector3<T> ggb()
		{
			return { g, g, b };
		}

		inline Vector3<T> gga()
		{
			return { g, g, a };
		}

		inline Vector3<T> gbr()
		{
			return { g, b, r };
		}

		inline Vector3<T> gbg()
		{
			return { g, b, g };
		}

		inline Vector3<T> gbb()
		{
			return { g, b, b };
		}

		inline Vector3<T> gba()
		{
			return { g, b, a };
		}

		inline Vector3<T> gar()
		{
			return { g, a, r };
		}

		inline Vector3<T> gag()
		{
			return { g, a, g };
		}

		inline Vector3<T> gab()
		{
			return { g, a, b };
		}

		inline Vector3<T> gaa()
		{
			return { g, a, a };
		}

		inline Vector3<T> brr()
		{
			return { b, r, r };
		}

		inline Vector3<T> brg()
		{
			return { b, r, g };
		}

		inline Vector3<T> brb()
		{
			return { b, r, b };
		}

		inline Vector3<T> bra()
		{
			return { b, r, a };
		}

		inline Vector3<T> bgr()
		{
			return { b, g, r };
		}

		inline Vector3<T> bgg()
		{
			return { b, g, g };
		}

		inline Vector3<T> bgb()
		{
			return { b, g, b };
		}

		inline Vector3<T> bga()
		{
			return { b, g, a };
		}

		inline Vector3<T> bbr()
		{
			return { b, b, r };
		}

		inline Vector3<T> bbg()
		{
			return { b, b, g };
		}

		inline Vector3<T> bbb()
		{
			return { b, b, b };
		}

		inline Vector3<T> bba()
		{
			return { b, b, a };
		}

		inline Vector3<T> bar()
		{
			return { b, a, r };
		}

		inline Vector3<T> bag()
		{
			return { b, a, g };
		}

		inline Vector3<T> bab()
		{
			return { b, a, b };
		}

		inline Vector3<T> baa()
		{
			return { b, a, a };
		}

		inline Vector3<T> arr()
		{
			return { a, r, r };
		}

		inline Vector3<T> arg()
		{
			return { a, r, g };
		}

		inline Vector3<T> arb()
		{
			return { a, r, b };
		}

		inline Vector3<T> ara()
		{
			return { a, r, a };
		}

		inline Vector3<T> agr()
		{
			return { a, g, r };
		}

		inline Vector3<T> agg()
		{
			return { a, g, g };
		}

		inline Vector3<T> agb()
		{
			return { a, g, b };
		}

		inline Vector3<T> aga()
		{
			return { a, g, a };
		}

		inline Vector3<T> abr()
		{
			return { a, b, r };
		}

		inline Vector3<T> abg()
		{
			return { a, b, g };
		}

		inline Vector3<T> abb()
		{
			return { a, b, b };
		}

		inline Vector3<T> aba()
		{
			return { a, b, a };
		}

		inline Vector3<T> aar()
		{
			return { a, a, r };
		}

		inline Vector3<T> aag()
		{
			return { a, a, g };
		}

		inline Vector3<T> aab()
		{
			return { a, a, b };
		}

		inline Vector3<T> aaa()
		{
			return { a, a, a };
		}

		// Vector4 -> Vector2 swizzle, rgba
		inline Vector2<T> rr()
		{
			return { r, r };
		}

		inline Vector2<T> rg()
		{
			return { r, g };
		}

		inline Vector2<T> rb()
		{
			return { r, b };
		}

		inline Vector2<T> ra()
		{
			return { r, a };
		}

		inline Vector2<T> gr()
		{
			return { g, r };
		}

		inline Vector2<T> gg()
		{
			return { g, g };
		}

		inline Vector2<T> gb()
		{
			return { g, b };
		}

		inline Vector2<T> ga()
		{
			return { g, a };
		}

		inline Vector2<T> br()
		{
			return { b, r };
		}

		inline Vector2<T> bg()
		{
			return { b, g };
		}

		inline Vector2<T> bb()
		{
			return { b, b };
		}

		inline Vector2<T> ba()
		{
			return { b, a };
		}

		inline Vector2<T> ar()
		{
			return { a, r };
		}

		inline Vector2<T> ag()
		{
			return { a, g };
		}

		inline Vector2<T> ab()
		{
			return { a, b };
		}

		inline Vector2<T> aa()
		{
			return { a, a };
		}

		union
		{
			struct
			{
				T x, y, z, w;
			};
			struct
			{
				T r, g, b, a;
			};
			T e[4];
		};
	};

// Dot products
	template <typename T>
	T Dot(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		
		return (lhs.x * rhs.x) + (lhs.y * rhs.y);
	}

	template <typename T>
	T Dot(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
	}

	template <typename T>
	T Dot(const Vector4<T>& lhs, const Vector4<T>& rhs)
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
	}

// Cross product
	template <typename T>
	Vector3<T> Cross(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return {
			(lhs.y * rhs.z) - (lhs.z * rhs.y),
			(lhs.z * rhs.x) - (lhs.x * rhs.z),
			(lhs.x * rhs.y) - (lhs.y * rhs.x)
		};
	}

	// Vector2
	template <typename T>
	static Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector2<T> operator+(const Vector2<T>& lhs, const T rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector2<T> operator+(const T lhs, const Vector2<T>& rhs)
	{
		return rhs.operator+(lhs);
	}

	template <typename T>
	static Vector2<T> operator-(const Vector2<T>& lhs, const T& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector2<T> operator-(const T& lhs, const Vector2<T>& rhs)
	{
		return rhs.operator-(lhs);
	}

	template <typename T>
	static Vector2<T> operator*(const Vector2<T>& lhs, const T rhs)
	{
		return lhs.operator*(rhs);
	}

	template <typename T>
	static Vector2<T> operator*(const T lhs, const Vector2<T>& rhs)
	{
		return rhs.operator*(lhs);
	}

	template <typename T>
	static Vector2<T> operator/(const Vector2<T>& lhs, const T rhs)
	{
		return lhs.operator/(rhs);
	}

	template <typename T>
	static Vector2<T>& Rotate(Vector2<T>& vec, const T radians)
	{
		const T x2 = Cos<T>(radians) * vec.x - Sin<T>(radians) * vec.y;
		const T y2 = Sin<T>(radians) * vec.x + Cos<T>(radians) * vec.y;
		vec.x = x2;
		vec.y = y2;
		return vec;
	}

	template <typename T>
	static Vector2<T> RotateCopy(const Vector2<T>& vec, const T radians)
	{
		const T x2 = Cos<T>(radians) * vec.x - Sin<T>(radians) * vec.y;
		const T y2 = Sin<T>(radians) * vec.x + Cos<T>(radians) * vec.y;
		return { x2, y2 };
	}

	// Vector3
	template <typename T>
	static Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector3<T> operator+(const Vector3<T>& lhs, const T rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector3<T> operator+(const T lhs, const Vector3<T>& rhs)
	{
		return rhs.operator+(lhs);
	}

	template <typename T>
	static Vector3<T> operator-(const Vector3<T>& lhs, const T& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector3<T> operator-(const T& lhs, const Vector3<T>& rhs)
	{
		return rhs.operator-(lhs);
	}

	template <typename T>
	static Vector3<T> operator*(const Vector3<T>& lhs, const T rhs)
	{
		return lhs.operator*(rhs);
	}

	template <typename T>
	static Vector3<T> operator*(const T lhs, const Vector3<T>& rhs)
	{
		return rhs.operator*(lhs);
	}

	template <typename T>
	static Vector3<T> operator/(const Vector3<T>& lhs, const T rhs)
	{
		return lhs.operator/(rhs);
	}

	// Vector4
	template <typename T>
	static Vector4<T> operator+(const Vector4<T>& lhs, const Vector4<T>& rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector4<T> operator-(const Vector4<T>& lhs, const Vector4<T>& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector4<T> operator+(const Vector4<T>& lhs, const T rhs)
	{
		return lhs.operator+(rhs);
	}

	template <typename T>
	static Vector4<T> operator+(const T lhs, const Vector4<T>& rhs)
	{
		return rhs.operator+(lhs);
	}

	template <typename T>
	static Vector4<T> operator-(const Vector4<T>& lhs, const T& rhs)
	{
		return lhs.operator-(rhs);
	}

	template <typename T>
	static Vector4<T> operator-(const T& lhs, const Vector4<T>& rhs)
	{
		return rhs.operator-(lhs);
	}

	template <typename T>
	static Vector4<T> operator*(const Vector4<T>& lhs, const T rhs)
	{
		return lhs.operator*(rhs);
	}

	template <typename T>
	static Vector4<T> operator*(const T lhs, const Vector4<T>& rhs)
	{
		return rhs.operator*(lhs);
	}

	template <typename T>
	static Vector4<T> operator/(const Vector4<T>& lhs, const T rhs)
	{
		return lhs.operator/(rhs);
	}

	// Distance
	
	template <typename T>
	inline T Distance(const Vector2<T>& p1, const Vector2<T>& p2)
	{
		return (p2 - p1).Length();
	}

	template <typename T>
	inline T Distance(const Vector3<T>& p1, const Vector3<T>& p2)
	{
		return (p2 - p1).Length();
	}

	template <typename T>
	inline T Distance(const Vector4<T>& p1, const Vector4<T>& p2)
	{
		return (p2 - p1).Length();
	}

	// Normalize
	template <typename T>
	inline Vector2<T> Normalized(const Vector2<T>& vec)
	{
		return vec.Normalized();
	}

	template <typename T>
	inline Vector3<T> Normalized(const Vector3<T>& vec)
	{
		return vec.Normalized();
	}

	template <typename T>
	inline Vector4<T> Normalized(const Vector4<T>& vec)
	{
		return vec.Normalized();
	}

	template <typename T>
	inline Vector2<T>& Normalize(Vector2<T>& vec)
	{
		return vec.Normalize();
	}

    template <typename T>
    inline Vector2<T> Normalize(const Vector2<T>& vec)
    {
        Vector2<T> temp = vec;
        return temp.Normalize();
    }

	template <typename T>
	inline Vector3<T>& Normalize(Vector3<T>& vec)
	{
		return vec.Normalize();
	}

    template <typename T>
    inline Vector3<T> Normalize(const Vector3<T>& vec)
    {
        Vector3<T> temp = vec;
        return temp.Normalize();
    }

	template <typename T>
	inline Vector4<T>& Normalize(Vector4<T>& vec)
	{
		return vec.Normalize();
	}

    template <typename T>
    inline Vector4<T> Normalize(const Vector4<T>& vec)
    {
        Vector4<T> temp = vec;
        return temp.Normalize();
    }

	// Get orthogonal vector specializations	
	template <typename T>
	void GetOrthogonal(const Math::Vector3<T>& n, Math::Vector3<T>& p, Math::Vector3<T>& q)
	{
		if (Abs<T>(n.z) > static_cast<T>(k_invSqrt2f))
		{
			// p -> y/z plane
			const T a = n.y * n.y + n.z * n.z;
			const T k = static_cast<T>(1.f) / Sqrt<T>(a);
			p.x = static_cast<T>(0.f);
			p.y = -n.z * k;
			p.z = n.y * k;
			// q -> n x p
			q.x = a * k;
			q.y = -n.x * p.z;
			q.z = n.x * p.y;
		}
		else
		{
			// p -> x/y plane
			const T a = n.x * n.x + n.y * n.y;
			const T k = static_cast<T>(1.f) / Sqrt<T>(a);
			p.x = -n.y * k;
			p.y = n.x * k;
			p.z = static_cast<T>(0.f);
			// q -> n x p
			q.x = -n.z * p.y;
			q.y = n.z * p.x;
			q.z = a * k;
		}
	}

    // Lerp
    template <typename T>
    inline Vector2<T> Lerp(const Vector2<T>& v1, const Vector2<T>& v2, T t)
    {
        return v1 + t * (v2 - v1);
    }

	template <typename T>
    inline Vector3<T> Lerp(const Vector3<T>& v1, const Vector3<T>& v2, T t)
    {
        return v1 + t * (v2 - v1);
    }

	template <typename T>
    inline Vector4<T> Lerp(const Vector4<T>& v1, const Vector4<T>& v2, T t)
    {
        return v1 + t * (v2 - v1);
    }

// Convenience Aliases
	using Vector2f = Vector2<float>;
	using Vector3f = Vector3<float>;
	using Vector4f = Vector4<float>;

	using Vector2d = Vector2<double>;
	using Vector3d = Vector3<double>;
	using Vector4d = Vector4<double>;

	using Vector2i = Vector2<int>;
	using Vector3i = Vector3<int>;
	using Vector4i = Vector4<int>;

	// 32bpp Float colour
	using Colour3f = Vector3<float>;
	using Color3f = Vector3<float>; // Americans
	using Colour4f = Vector4<float>;
	using Color4f = Vector4<float>; // Americans

	// 8bpp uint colour
	using Colour3b = Vector3<uint8_t>;
	using Color3b  = Vector3<uint8_t>; // Americans
	using Colour4b = Vector4<uint8_t>;
	using Color4b  = Vector4<uint8_t>; // Americans

	// 16bpp uint colour
	using Colour3s = Vector3<uint16_t>;
	using Color3s  = Vector3<uint16_t>; // Americans
	using Colour4s = Vector4<uint16_t>;
	using Color4s  = Vector4<uint16_t>; // Americans

	// 32bpp uint colour
	using Colour3i = Vector3<uint32_t>;
	using Color3i  = Vector3<uint32_t>; // Americans
	using Colour4i = Vector4<uint32_t>;
	using Color4ib = Vector4<uint32_t>; // Americans

    void VectorTest();
}