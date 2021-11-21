#pragma once

#include <cmath>
#include <cfloat>
#include <cinttypes>
#include <cassert>

namespace Math
{
	template <typename T>
	class Vector2
	{
	public:
		static const Vector2<T> UNIT_X;
		static const Vector2<T> UNIT_Y;

	public:
		Vector2<T>()
			: e{ 0.f, 0.f }
		{
		}

		Vector2<T>(T e0, T e1)
			: e{ e0, e1 }
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
			return std::sqrtf((e[0] * e[0]) + (e[1] * e[1]));
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
			: e{ 0.f, 0.f, 0.f }
		{
		}

		Vector3<T>(T e0, T e1, T e2)
			: e{ e0, e1, e2 }
		{
		}

		Vector3<T>(const Vector2<T>& e01, T e2)
			: e{ e01.e[0], e01.e[1], e2 }
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
			return std::sqrtf((e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]));
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
			: e{ 0.f, 0.f, 0.f, 0.f }
		{
		}

		Vector4<T>(T e0, T e1, T e2, T e3)
			: e{ e0, e1, e2, e3 }
		{
		}

		Vector4<T>(const Vector3<T>& e012, T e3)
			: e{ e012.e[0], e012.e[1], e012.e[2], e3 }
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
			return std::sqrtf((e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]) + (e[3] * e[3]));
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
}