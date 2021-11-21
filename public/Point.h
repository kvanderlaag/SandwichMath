#pragma once

namespace Math
{
	template <typename T>
	class Point
	{
	public:
		Point<T>()
			: e{0, 0}
		{
		}

		Point<T>(const T x, const T y)
			: e{x, y}
		{
		}

		Point<T>(const Point<T>& other)
			: e{other.e[0], other.e[1]}
		{
		}

		Point<T>& operator=(const Point<T>& other)
		{
			e[0] = other.e[0];
			e[1] = other.e[1];
			return *this;
		}

		Point<T>& operator=(const T ex, const T ey)
		{
			e[0] = ex;
			e[1] = ey;
			return *this;
		}

		bool operator==(const Point<T>& other)
		{
			return e[0] == other.e[0] && e[1] == other.e[1];
		}

		bool operator!=(const Point<T>& other)
		{
			return e[0] != other.e[0] || e[1] != other.e[1];
		}

		Point<T> operator+(const Point<T>& other)
		{
			return Point<T>(e[0] + other.e[0], e[1] + other.e[1]);
		}

		Point<T> operator-(const Point<T>& other)
		{
			return Point<T>(e[0] - other.e[0], e[1] - other.e[1]);
		}

		Point<T> operator*(const T other)
		{
			return Point<T>(e[0] * other, e[1] * other);
		}

		Point<T> operator/(const T other)
		{
			return Point<T>(e[0] / other, e[1] / other);
		}

	private:
		union
		{
			struct
			{
				T x;
				T y;
			};
			T e[2];
		};
	};

	using Pointf = Point<float>;
	using Point2i
}