#pragma once

#include <Vector.h>
#include <cassert>

namespace Math
{
	template <typename T>
	class Matrix3x3
	{
	public:
		static const Matrix3x3<T> IDENTITY;

	public:
		Matrix3x3<T>()
		{
		}

		Matrix3x3<T>(const Vector3<T>& r0, const Vector3<T>& r1, const Vector3<T>& r2)
			: r{ r0, r1, r2 }
		{
		}

		Vector3<T>& operator[](const size_t element)
		{
			assert(element < 3);
			return r[element];
		}

		Vector3<T> operator[](const size_t element) const
		{
			assert(element < 3);
			return r[element];
		}
		
		bool operator==(const Matrix3x3<T>& rhs) const
		{
			return r[0] == rhs.r[0] && r[1] == rhs.r[1] && r[2] == rhs.r[2];
		}

		bool operator!=(const Matrix3x3<T>& rhs) const
		{
			return !(*this == rhs);
		}

		const Vector3<T>& GetRow(int i) const
		{
			assert(i < 3 && i >= 0);
			return  r[i];
		}

		Vector3<T> GetColumn(int i) const
		{
			assert(i < 3 && i >= 0);
			return { r[0].e[i], r[1].e[i], r[2].e[i] };
		}

		Matrix3x3<T> operator+(const Matrix3x3<T>& rhs) const
		{
			return {
				{ r[0] + rhs.r[0] },
				{ r[1] + rhs.r[1] },
				{ r[2] + rhs.r[2] }
			};
		}

		Matrix3x3<T> operator-(const Matrix3x3<T>& rhs) const
		{
			return {
				{ r[0] - rhs.r[0] },
				{ r[1] - rhs.r[1] },
				{ r[2] - rhs.r[2] }
			};
		}

		Matrix3x3<T> operator*(const Matrix3x3<T>& rhs) const
		{
			return
			{
				{
					(r[0].x * rhs.r[0].x) + (r[0].y * rhs.r[1].x) + (r[0].z * rhs.r[2].x),
					(r[0].x * rhs.r[0].y) + (r[0].y * rhs.r[1].y) + (r[0].z * rhs.r[2].y),
					(r[0].x * rhs.r[0].z) + (r[0].y * rhs.r[1].z) + (r[0].z * rhs.r[2].z)
				},
				{
					(r[1].x * rhs.r[0].x) + (r[1].y * rhs.r[1].x) + (r[1].z * rhs.r[2].x),
					(r[1].x * rhs.r[0].y) + (r[1].y * rhs.r[1].y) + (r[1].z * rhs.r[2].y),
					(r[1].x * rhs.r[0].z) + (r[1].y * rhs.r[1].z) + (r[1].z * rhs.r[2].z)
				},
				{
					(r[2].x * rhs.r[0].x) + (r[2].y * rhs.r[1].x) + (r[2].z * rhs.r[2].x),
					(r[2].x * rhs.r[0].y) + (r[2].y * rhs.r[1].y) + (r[2].z * rhs.r[2].y),
					(r[2].x * rhs.r[0].z) + (r[2].y * rhs.r[1].z) + (r[2].z * rhs.r[2].z)
				}
			};
		}

		Vector3<T> operator*(const Vector3<T>& rhs) const
		{
			return
			{
				r[0].x * rhs.x + r[0].y * rhs.y + r[0].z * rhs.z,
				r[1].x * rhs.x + r[1].y * rhs.y + r[1].z * rhs.z,
				r[2].x * rhs.x + r[2].y * rhs.y + r[2].z * rhs.z
			};
		}

		Matrix3x3<T>& operator+=(const Matrix3x3<T>& rhs)
		{
			r[0] += rhs.r[0];
			r[1] += rhs.r[1];
			r[2] += rhs.r[2];
			return *this;
		}

		Matrix3x3<T>& operator-=(const Matrix3x3<T>& rhs)
		{
			r[0] -= rhs.r[0];
			r[1] -= rhs.r[1];
			r[2] -= rhs.r[2];
			return *this;
		}

		Matrix3x3<T>& operator*=(const Matrix3x3<T>& rhs)
		{
			r[0] =
			{
				(r[0].x * rhs.r[0].x) + (r[0].y * rhs.r[1].x) + (r[0].z * rhs.r[2].x),
				(r[0].x * rhs.r[0].y) + (r[0].y * rhs.r[1].y) + (r[0].z * rhs.r[2].y),
				(r[0].x * rhs.r[0].z) + (r[0].y * rhs.r[1].z) + (r[0].z * rhs.r[2].z)
			};

			r[1] = 
			{
				(r[1].x * rhs.r[0].x) + (r[1].y * rhs.r[1].x) + (r[1].z * rhs.r[2].x),
				(r[1].x * rhs.r[0].y) + (r[1].y * rhs.r[1].y) + (r[1].z * rhs.r[2].y),
				(r[1].x * rhs.r[0].z) + (r[1].y * rhs.r[1].z) + (r[1].z * rhs.r[2].z)
			};

			r[2] =
			{
				(r[2].x * rhs.r[0].x) + (r[2].y * rhs.r[1].x) + (r[2].z * rhs.r[2].x),
				(r[2].x * rhs.r[0].y) + (r[2].y * rhs.r[1].y) + (r[2].z * rhs.r[2].y),
				(r[2].x * rhs.r[0].z) + (r[2].y * rhs.r[1].z) + (r[2].z * rhs.r[2].z)
			};
			return *this;
		}

		Matrix3x3<T>& InverseSelf()
		{
			const Vector3<T> cofactorVector(Cofactor(1, 1, 2, 2), Cofactor(1, 2, 2, 0), Cofactor(1, 0, 2, 1));
			const T determinant = (*this)[0].Dot(cofactorVector);
			assert(determinant != static_cast<T>(0));
			const T s = static_cast<T>(1) / determinant;
			*this = Matrix3x3<T>({ cofactorVector.x * s, Cofactor(0, 2, 2, 1) * s, Cofactor(0, 1, 1, 2) * s },
				{ cofactorVector.y * s, Cofactor(0, 0, 2, 2) * s, Cofactor(0, 2, 1, 0) * s },
				{ cofactorVector.z * s, Cofactor(0, 1, 2, 0) * s, Cofactor(0, 0, 1, 1) * s });
			
			return *this;
		}

		Matrix3x3<T> InverseClone() const
		{
			const Vector3<T> cofactorVector(Cofactor(1, 1, 2, 2), Cofactor(1, 2, 2, 0), Cofactor(1, 0, 2, 1));
			const T determinant = (*this)[0].Dot(cofactorVector);
			assert(determinant != static_cast<T>(0));
			const T s = static_cast<T>(1) / determinant;
			return { { cofactorVector.x * s, Cofactor(0, 2, 2, 1) * s, Cofactor(0, 1, 1, 2) * s },
				{ cofactorVector.y * s, Cofactor(0, 0, 2, 2) * s, Cofactor(0, 2, 1, 0) * s },
				{ cofactorVector.z * s, Cofactor(0, 1, 2, 0) * s, Cofactor(0, 0, 1, 1) * s }
			};
		}


	private:
		T Cofactor(int r1, int c1, int r2, int c2) const
		{
			return r[r1][c1] * r[r2][c2] - r[r1][c2] * r[r2][c1];
		}
	private:
		Vector3<T> r[3];
	};



	template <typename T>
	class Matrix4x4
	{
	public:
		static const Matrix4x4<T> IDENTITY;

	public:
		Matrix4x4<T>()
		{
		}

		Matrix4x4<T>(const Vector4<T>& r0, const Vector4<T>& r1, const Vector4<T>& r2, const Vector4<T>& r3)
			: r{ r0, r1, r2, r3 }
		{
		}

		Vector4<T>& operator[](const size_t element)
		{
			assert(element < 4);
			return r[element];
		}

		Vector4<T> operator[](const size_t element) const
		{
			assert(element < 4);
			return r[element];
		}

		bool operator==(const Matrix4x4<T>& rhs) const
		{
			return r[0] == rhs.r[0] && r[1] == rhs.r[1] && r[2] == rhs.r[2] && r[3] == rhs.r[3];
		}

		bool operator!=(const Matrix4x4<T>& rhs) const
		{
			return !(*this == rhs);
		}

		const Vector4<T>& GetRow(int i) const
		{
			assert(i < 4 && i >= 0);
			return  r[i];
		}

		Vector4<T> GetColumn(int i) const
		{
			assert(i < 4 && i >= 0);
			return { r[0].e[i], r[1].e[i], r[2].e[i], r[3].e[i] };
		}

		Matrix4x4<T> operator+(const Matrix4x4<T>& rhs) const
		{
			return {
				{ r[0] + rhs.r[0] },
				{ r[1] + rhs.r[1] },
				{ r[2] + rhs.r[2] },
				{ r[3] + rhs.r[3] }
			};
		}

		Matrix4x4<T> operator-(const Matrix4x4<T>& rhs) const
		{
			return {
				{ r[0] - rhs.r[0] },
				{ r[1] - rhs.r[1] },
				{ r[2] - rhs.r[2] },
				{ r[3] - rhs.r[3] }
			};
		}

		Matrix4x4<T> operator*(const Matrix4x4<T>& rhs) const
		{
			return
			{
				{
					(r[0].x * rhs.r[0].x) + (r[0].y * rhs.r[1].x) + (r[0].z * rhs.r[2].x) + (r[0].w * rhs.r[3].x),
					(r[0].x * rhs.r[0].y) + (r[0].y * rhs.r[1].y) + (r[0].z * rhs.r[2].y) + (r[0].w * rhs.r[3].y),
					(r[0].x * rhs.r[0].z) + (r[0].y * rhs.r[1].z) + (r[0].z * rhs.r[2].z) + (r[0].w * rhs.r[3].z),
					(r[0].x * rhs.r[0].w) + (r[0].y * rhs.r[1].w) + (r[0].z * rhs.r[2].w) + (r[0].w * rhs.r[3].w)
				},
				{
					(r[1].x * rhs.r[0].x) + (r[1].y * rhs.r[1].x) + (r[1].z * rhs.r[2].x) + (r[1].w * rhs.r[3].x),
					(r[1].x * rhs.r[0].y) + (r[1].y * rhs.r[1].y) + (r[1].z * rhs.r[2].y) + (r[1].w * rhs.r[3].y),
					(r[1].x * rhs.r[0].z) + (r[1].y * rhs.r[1].z) + (r[1].z * rhs.r[2].z) + (r[1].w * rhs.r[3].z),
					(r[1].x * rhs.r[0].w) + (r[1].y * rhs.r[1].w) + (r[1].z * rhs.r[2].w) + (r[1].w * rhs.r[3].w)
				},
				{
					(r[2].x * rhs.r[0].x) + (r[2].y * rhs.r[1].x) + (r[2].z * rhs.r[2].x) + (r[2].w * rhs.r[3].x),
					(r[2].x * rhs.r[0].y) + (r[2].y * rhs.r[1].y) + (r[2].z * rhs.r[2].y) + (r[2].w * rhs.r[3].y),
					(r[2].x * rhs.r[0].z) + (r[2].y * rhs.r[1].z) + (r[2].z * rhs.r[2].z) + (r[2].w * rhs.r[3].z),
					(r[2].x * rhs.r[0].w) + (r[2].y * rhs.r[1].w) + (r[2].z * rhs.r[2].w) + (r[2].w * rhs.r[3].w)
				},
				{
					(r[3].x * rhs.r[0].x) + (r[3].y * rhs.r[1].x) + (r[3].z * rhs.r[2].x) + (r[3].w * rhs.r[3].x),
					(r[3].x * rhs.r[0].y) + (r[3].y * rhs.r[1].y) + (r[3].z * rhs.r[2].y) + (r[3].w * rhs.r[3].y),
					(r[3].x * rhs.r[0].z) + (r[3].y * rhs.r[1].z) + (r[3].z * rhs.r[2].z) + (r[3].w * rhs.r[3].z),
					(r[3].x * rhs.r[0].w) + (r[3].y * rhs.r[1].w) + (r[3].z * rhs.r[2].w) + (r[3].w * rhs.r[3].w)
				}
			};
		}

		Vector4<T> operator*(const Vector4<T>& rhs) const
		{
			return
			{
				r[0].x * rhs.x + r[0].y * rhs.y + r[0].z * rhs.z,
				r[1].x * rhs.x + r[1].y * rhs.y + r[1].z * rhs.z,
				r[2].x * rhs.x + r[2].y * rhs.y + r[2].z * rhs.z,
				r[3].x * rhs.x + r[3].y * rhs.y + r[3].z * rhs.z
			};
		}

		Matrix4x4<T>& operator+=(const Matrix4x4<T>& rhs)
		{
			r[0] += rhs.r[0];
			r[1] += rhs.r[1];
			r[2] += rhs.r[2];
			r[3] += rhs.r[3];
			return *this;
		}

		Matrix4x4<T>& operator-=(const Matrix4x4<T>& rhs)
		{
			r[0] -= rhs.r[0];
			r[1] -= rhs.r[1];
			r[2] -= rhs.r[2];
			r[3] -= rhs.r[3];
			return *this;
		}

		Matrix4x4<T>& operator*=(const Matrix4x4<T>& rhs)
		{			
			/*
			 * [a11b11 + a12b21 + a13b31 + a14b41]   [a11b12 + a12b22 + a13b32 + a14b42]   [a11b13 + a12b23 + a13b33 + a14b43]   [a11b14 + a12b24 + a13b34 + a14b44]
			 * [a21b11 + a22b21 + a23b31 + a24b41]   [a21b12 + a22b22 + a23b32 + a24b42]   [a21b13 + a22b23 + a23b33 + a24b43]   [a21b14 + a22b24 + a23b34 + a24b44]
			 * [a31b11 + a32b21 + a33b31 + a34b41]   [a31b12 + a32b22 + a33b32 + a34b42]   [a31b13 + a32b23 + a33b33 + a34b43]   [a31b14 + a32b24 + a33b34 + a34b44]
			 * [a41b11 + a42b21 + a43b31 + a44b41]   [a41b12 + a42b22 + a43b32 + a44b42]   [a41b13 + a42b23 + a43b33 + a44b43]   [a41b14 + a42b24 + a43b34 + a44b44]
			 */
			r[0] =
			{
				(r[0].x * rhs.r[0].x) + (r[0].y * rhs.r[1].x) + (r[0].z * rhs.r[2].x) + (r[0].w * rhs.r[3].x),
				(r[0].x * rhs.r[0].y) + (r[0].y * rhs.r[1].y) + (r[0].z * rhs.r[2].y) + (r[0].w * rhs.r[3].y),
				(r[0].x * rhs.r[0].z) + (r[0].y * rhs.r[1].z) + (r[0].z * rhs.r[2].z) + (r[0].w * rhs.r[3].z),
				(r[0].x * rhs.r[0].w) + (r[0].y * rhs.r[1].w) + (r[0].z * rhs.r[2].w) + (r[0].w * rhs.r[3].w)
			};

			r[1] =
			{
				(r[1].x * rhs.r[0].x) + (r[1].y * rhs.r[1].x) + (r[1].z * rhs.r[2].x) + (r[1].w * rhs.r[3].x),
				(r[1].x * rhs.r[0].y) + (r[1].y * rhs.r[1].y) + (r[1].z * rhs.r[2].y) + (r[1].w * rhs.r[3].y),
				(r[1].x * rhs.r[0].z) + (r[1].y * rhs.r[1].z) + (r[1].z * rhs.r[2].z) + (r[1].w * rhs.r[3].z),
				(r[1].x * rhs.r[0].w) + (r[1].y * rhs.r[1].w) + (r[1].z * rhs.r[2].w) + (r[1].w * rhs.r[3].w)
			};

			r[2] =
			{
				(r[2].x * rhs.r[0].x) + (r[2].y * rhs.r[1].x) + (r[2].z * rhs.r[2].x) + (r[2].w * rhs.r[3].x),
				(r[2].x * rhs.r[0].y) + (r[2].y * rhs.r[1].y) + (r[2].z * rhs.r[2].y) + (r[2].w * rhs.r[3].y),
				(r[2].x * rhs.r[0].z) + (r[2].y * rhs.r[1].z) + (r[2].z * rhs.r[2].z) + (r[2].w * rhs.r[3].z),
				(r[2].x * rhs.r[0].w) + (r[2].y * rhs.r[1].w) + (r[2].z * rhs.r[2].w) + (r[2].w * rhs.r[3].w)
			};

			r[3] =
			{
				(r[3].x * rhs.r[0].x) + (r[3].y * rhs.r[1].x) + (r[3].z * rhs.r[2].x) + (r[3].w * rhs.r[3].x),
				(r[3].x * rhs.r[0].y) + (r[3].y * rhs.r[1].y) + (r[3].z * rhs.r[2].y) + (r[3].w * rhs.r[3].y),
				(r[3].x * rhs.r[0].z) + (r[3].y * rhs.r[1].z) + (r[3].z * rhs.r[2].z) + (r[3].w * rhs.r[3].z),
				(r[3].x * rhs.r[0].w) + (r[3].y * rhs.r[1].w) + (r[3].z * rhs.r[2].w) + (r[3].w * rhs.r[3].w)
			};
			return *this;
		}

		Matrix4x4<T>& InverseSelf()
		{
			return *this;
		}

		Matrix4x4<T> InverseClone() const
		{
			return *this;
		}
	private:
		Vector4<T> r[4];
	};

	using Matrix3x3f = Matrix3x3<float>;
	using Matrix4x4f = Matrix4x4<float>;

	using Matrix3x3i = Matrix3x3<int>;
	using Matrix4x4i = Matrix4x4<int>;

	bool TestMatrixMultiplication();
}