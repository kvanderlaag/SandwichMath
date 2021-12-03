#pragma once

#include <cassert>
#include <limits>

#include <MathUtil.h>
#include <MathTemplateUtil.h>
#include <Vector.h>

namespace Math
{
	template <typename T>
	class Quaternion
	{		
		public:
			Quaternion()
				: e{
					static_cast<T>(0.f),
					static_cast<T>(0.f),
					static_cast<T>(0.f),
					static_cast<T>(1.f)
				}
			{}

			Quaternion(const T x, const T y, const T z, const T w)
				: e{ x, y, z, w }
			{
			}

			// Axis-angle Constructor
			Quaternion(const Vector3<T>& axis, const T& angle)
			{
				SetRotation(axis, angle);
			}

			// Euler angle constructor
			Quaternion(const T& yaw, const T& pitch, const T& roll)
			{
				SetEuler(yaw, pitch, roll);
			}

			// Set rotation using axis-angle
			void SetRotation(const Vector3<T>& axis, const T& angle)
			{
				T d = axis.Length();
				assert(d != static_cast<T>(0.f));
				T s = Sin<T>(angle * static_cast<T>(0.5f)) / d;
				x = axis.x * s;
				y = axis.y * s;
				z = axis.z * s;
				w = Cos<T>(angle * static_cast<T>(0.5f));
			}

			// Set rotation using Euler angles - Yaw around Y, Pitch around X, Roll around Z
			void SetEuler(const T& yaw, const T& pitch, const T& roll)
			{
				const T halfYaw = yaw * static_cast<T>(0.5f);
				const T halfPitch = pitch * static_cast<T>(0.5f);
				const T halfRoll = roll * static_cast<T>(0.5f);
				const T cosYaw = std::cosf(halfYaw);
				const T sinYaw = std::sinf(halfYaw);
				const T cosPitch = std::cosf(halfPitch);
				const T sinPitch = std::sinf(halfPitch);
				const T cosRoll = std::cosf(halfRoll);
				const T sinRoll = std::sinf(halfRoll);
				x = cosRoll * sinPitch* cosYaw + sinRoll * cosPitch * sinYaw;
				y = cosRoll * cosPitch* sinYaw - sinRoll * sinPitch * cosYaw;
				z = sinRoll * cosPitch* cosYaw - cosRoll * sinPitch * sinYaw;
				w = cosRoll * cosPitch* cosYaw + sinRoll * sinPitch * sinYaw;
			}

			// Set rotation using Euler angles - Yaw around Z, Pitch around Y, Roll around X
			void SetEulerZYX(const T& yawZ, const T& pitchY, const T& rollX)
			{
				const T halfYaw = yawZ * static_cast<T>(0.5f);
				const T halfPitch = pitchY * static_cast<T>(0.5f);
				const T halfRoll = rollX * static_cast<T>(0.5f);
				const T cosYaw = std::cosf(halfYaw);
				const T sinYaw = std::sinf(halfYaw);
				const T cosPitch = std::cosf(halfPitch);
				const T sinPitch = std::sinf(halfPitch);
				const T cosRoll = std::cosf(halfRoll);
				const T sinRoll = std::sinf(halfRoll);
				x = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
				y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
				z =	cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
				w =	cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
			}

			// Get the euler angles represented by this quaternion into yaw, pitch, and roll
			// output references
			void GetEulerZYX(T& yawZ, T& pitchY, T& rollX) const
			{
				const T sqx = e[0] * e[0];
				const T sqy = e[1] * e[1];
				const T sqz = e[2] * e[2];
				const T squ = e[3] * e[3];
				const T sarg = static_cast<T>(-2.f) * (e[0] * e[2] - e[3] * e[1]);

				// If the pitch angle is PI/2 or -PI/2, we can only compute
				// the sum roll + yaw.  However, any combination that gives
				// the right sum will produce the correct orientation, so we
				// set rollX = 0 and compute yawZ.
				if (sarg <= static_cast<T>(-0.99999f))
				{
					pitchY = static_cast<T>(-0.5f) * static_cast<T>(k_fltPi);
					rollX = static_cast<T>(0.f);
					yawZ = static_cast<T>(2.f) * Atan2<T>(e[0], -e[1]);
				}
				else if (sarg >= static_cast<T>(0.99999f))
				{
					pitchY = static_cast<T>(0.5f) * static_cast<T>(k_fltPi);
					rollX = static_cast<T>(0.f);
					yawZ = static_cast<T>(2.f) * Atan2<T>(-e[0], e[1]);
				}
				else
				{
					pitchY = Asin<T>(sarg);
					rollX = Atan2<T>(2 * (e[1] * e[2] + e[3] * e[0]), squ - sqx - sqy + sqz);
					yawZ = Atan2<T>(2 * (e[0] * e[1] + e[3] * e[2]), squ + sqx - sqy - sqz);
				}
			}

			Quaternion<T>& operator+=(const Quaternion<T>& q)
			{
				e[0] += q.x;
				e[1] += q.y;
				e[2] += q.z;
				e[3] += q.w;
				return *this;
			}

			Quaternion<T>& operator-=(const Quaternion<T>& q)
			{
				e[0] -= q.x;
				e[1] -= q.y;
				e[2] -= q.z;
				e[3] -= q.w;
				return *this;
			}

			bool operator==(const Quaternion<T>& q) const
			{
				return (x == q.x && y == q.y && z == q.z && w == q.w);
			}

			bool operator!=(const Quaternion<T>& q) const
			{
				return (x != q.x || y != q.y || z != q.z || w != q.w);
			}

			// Scale this quaternion
			Quaternion<T>& operator*=(const T& s)
			{
				e[0] *= s;
				e[1] *= s;
				e[2] *= s;
				e[3] *= s;
				return *this;
			}

			// Multiply this quaternion by q (i.e. this = this * q)
			Quaternion<T>& operator*=(const Quaternion<T>& q)
			{
				x = e[3] * q.x + e[0] * q.e[3] + e[1] * q.z - e[2] * q.y;
				y = e[3] * q.y + e[1] * q.e[3] + e[2] * q.x - e[0] * q.z;
				z = e[3] * q.z + e[2] * q.e[3] + e[0] * q.y - e[1] * q.x;
				w = e[3] * q.w - e[0] * q.x    - e[1] * q.y - e[2] * q.z;
				return *this;
			}

			// Dot product between this quaternion and q
			T Dot(const Quaternion<T>& q) const
			{
				return e[0] * q.x +
					e[1] * q.y +
					e[2] * q.z +
					e[3] * q.w;
			}

			// Squared length of this quaternion
			T LengthSq() const
			{
				return Dot(*this);
			}

			// Length of this quaternion
			T Length() const
			{
				return Sqrt<T>(LengthSq());
			}

			// Normalize this quaternion, avoiding division by 0
			Quaternion<T>& SafeNormalize()
			{
				T l2 = LengthSq();
				if (l2 > std::numeric_limits<T>::epsilon())
				{
					Normalize();
				}
				return *this;
			}

			// Normalize the quaternion, so that x^2 + y^2 + z^2 + w^2 = 1
			Quaternion<T>& Normalize()
			{
				return *this /= Length();
			}

			// Scaled copy
			Quaternion<T> operator*(const T& s) const
			{
				return Quaternion<T>(x * s, y * s, z * s, w * s);
			}

			// Inversely scaled copy
			Quaternion<T> operator/(const T& s) const
			{
				assert(s != static_cast<T>(0.f));
				return *this * (static_cast<T>(1.f) / s);
			}

			// Inversely scale this quaternion by a scalar
			Quaternion<T>& operator/=(const T& s)
			{
				assert(s != static_cast<T>(0.f));
				return *this *= static_cast<T>(1.f) / s;
			}

			// Normalized copy of this quaternion
			Quaternion<T> Normalized() const
			{
				return *this / Length();
			}

			// Half-angle between two quaternions
			T Angle(const Quaternion<T>& q) const
			{
				T s = Sqrt<T>(LengthSq() * q.LengthSq());
				assert(s != static_cast<T>(0.0f));
				return Cos<T>(Dot(q) / s);
			}

			// Get the shortest path angle between this quaternion and q.
			T AngleShortestPath(const Quaternion<T>& q) const
			{
				T s = Sqrt<T>(LengthSq() * q.LengthSq());
				assert(s != static_cast<T>(0.0f));
				if (Dot(q) < 0)  // Take care of long angle case see http://en.wikipedia.org/wiki/Slerp
					return Cos<T>(Dot(-q) / s) * static_cast<T>(2.0f);
				else
					return Cos<T>(Dot(q) / s) * static_cast<T>(2.0f);
			}

			// Get the angle of rotation represented by this quaternion, between 0 and 2 * Pi.
			T GetAngle() const
			{
				T s = static_cast<T>(2.f) * Cos<T>(e[3]);
				return s;
			}

			// Get the angle of rotation of the quaternion along the shortest path, between 0 and Pi.
			T GetAngleShortestPath() const
			{
				T s;
				if (e[3] >= 0)
					s = static_cast<T>(2.f) * Cos<T>(e[3]);
				else
					s = static_cast<T>(2.f) * Cos<T>(-e[3]);
				return s;
			}

			// Get the quaternion's axis of rotation
			Vector3<T> GetAxis() const
			{
				const T sSquared = static_cast<T>(1.f) - e[3] * e[3];

				// Check for divide by zero; return arbitrary value
				if (sSquared < static_cast<T>(10.f) * std::numeric_limits<T>::epsilon())
				{ 
					return Vector3<T>(static_cast<T>(1.f), static_cast<T>(0.f), static_cast<T>(0.f));
				}
				const T s = static_cast<T>(1.f) / Sqrt<T>(sSquared);
				return Vector3<T>(e[0] * s, e[1] * s, e[2] * s);
			}

			Quaternion<T> Inverse() const
			{
				return Quaternion<T>(-e[0], -e[1], -e[2], e[3]);
			}

			Quaternion<T> operator+(const Quaternion<T>& q2) const
			{
				const Quaternion<T>& q1 = *this;
				return Quaternion<T>(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.e[3] + q2.e[3]);
			}

			Quaternion<T> operator-(const Quaternion<T>& q2) const
			{
				const Quaternion<T>& q1 = *this;
				return Quaternion<T>(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.e[3] - q2.e[3]);
			}

			Quaternion<T> operator-() const
			{
				const Quaternion<T>& q2 = *this;
				return Quaternion<T>(-q2.x, -q2.y, -q2.z, -q2.e[3]);
			}

			Quaternion<T> Farthest(const Quaternion<T>& qd) const
			{
				Quaternion<T> diff, sum;
				diff = *this - qd;
				sum = *this + qd;
				if (diff.Dot(diff) > sum.Dot(sum))
					return qd;
				return (-qd);
			}

			Quaternion<T> Nearest(const Quaternion<T>& qd) const
			{
				Quaternion<T> diff, sum;
				diff = *this - qd;
				sum = *this + qd;
				if (diff.Dot(diff) < sum.Dot(sum))
					return qd;
				return (-qd);
			}

			Quaternion<T> Slerp(const Quaternion<T>& q, const T& t) const
			{
				const T magnitude = Sqrt<T>(LengthSq() * q.LengthSq());
				assert(magnitude > 0.f);

				const T product = Dot(q) / magnitude;
				const T absProduct = Abs<T>(product);

				if (absProduct < 1.0f - std::numeric_limits<T>::epsilon())
				{
					// Long angle case (see http://en.wikipedia.org/wiki/Slerp)
					const T theta = Cos<T>(absProduct);
					const T d = Sin<T>(theta);
					assert(d > static_cast<T>(0.f));

					const T sign = (product < static_cast<T>(0.f)) ? static_cast<T>(-1.f) : static_cast<T>(1.f);
					const T s0 = Sin<T>((1.0f - t) * theta) / d;
					const T s1 = Sin<T>(sign * t * theta) / d;

					return {
						(e[0] * s0 + q.x * s1),
						(e[1] * s0 + q.y * s1),
						(e[2] * s0 + q.z * s1),
						(e[3] * s0 + q.w * s1)
					};
				}
				else
				{
					return *this;
				}
			}

			static const Quaternion<T>& GetIdentity()
			{
				static const Quaternion<T> identityQuat(
					static_cast<T>(0.f), 
					static_cast<T>(0.f), 
					static_cast<T>(0.f), 
					static_cast<T>(1.f)
				);
				return identityQuat;
			}

			inline const T& GetX() const { return e[0]; }
			inline const T& GetY() const { return e[1]; }
			inline const T& GetZ() const { return e[2]; }
			inline const T& GetW() const { return e[3]; }

		private:
			union
			{
				struct
				{
					T x;
					T y;
					T z;
					T w;
				};
				T e[4];
			};
	};

	// Binary scalar operators
	template <typename T>
	Quaternion<T> operator*(const Quaternion<T>& q, const T s)
	{
		return q.operator*(s);
	}

	template <typename T>
	Quaternion<T> operator*(const T s, const Quaternion<T>& q)
	{
		return q.operator*(s);
	}

	template <typename T>
	Quaternion<T> operator/(const Quaternion<T>& q, const T s)
	{
		return q.operator/(s);
	}

	template <typename T>
	Quaternion<T> operator/(const T s, const Quaternion<T>& q)
	{
		return q.operator/(s);
	}
	
	// Quaternion product; "quat-product" if you will
	template <typename T>
	Quaternion<T> operator*(const Quaternion<T>& q1, const Quaternion<T>& q2)
	{
		return Quaternion<T>(
			q1.GetW() * q2.GetX() + q1.GetX() * q2.GetW() + q1.GetY() * q2.GetZ() - q1.GetZ() * q2.GetY(),
			q1.GetW() * q2.GetY() + q1.GetY() * q2.GetW() + q1.GetZ() * q2.GetX() - q1.GetX() * q2.GetZ(),
			q1.GetW() * q2.GetZ() + q1.GetZ() * q2.GetW() + q1.GetX() * q2.GetY() - q1.GetY() * q2.GetX(),
			q1.GetW() * q2.GetW() - q1.GetX() * q2.GetX() - q1.GetY() * q2.GetY() - q1.GetZ() * q2.GetZ());
	}

	// Quaternion (rotation) * vector (heading)
	template <typename T>
	Quaternion<T> operator*(const Quaternion<T>& q, const Vector3<T>& w)
	{
		return Quaternion<T>(
			q.GetW() * w.x + q.GetY() * w.z - q.GetZ() * w.y,
			q.GetW() * w.y + q.GetZ() * w.x - q.GetX() * w.z,
			q.GetW() * w.z + q.GetX() * w.y - q.GetY() * w.x,
			-q.GetX() * w.x - q.GetY() * w.y - q.GetZ() * w.z);
	}

	template <typename T>
	Quaternion<T> operator*(const Vector3<T>& w, const Quaternion<T>& q)
	{
		return Quaternion<T>(
			+w.x * q.GetW() + w.y * q.GetZ() - w.z * q.GetY(),
			+w.y * q.GetW() + w.z * q.GetX() - w.x * q.GetZ(),
			+w.z * q.GetW() + w.x * q.GetY() - w.y * q.GetX(),
			-w.x * q.GetX() - w.y * q.GetY() - w.z * q.GetZ());
	}

	// Quaternion dot product
	template <typename T>
	T Dot(const Quaternion<T>& q1, const Quaternion<T>& q2)
	{
		return q1.Dot(q2);
	}

	// Quaternion length
	template <typename T>
	T Length(const Quaternion<T>& q)
	{
		return q.Length();
	}

	// Angle between two quaternions
	template <typename T>
	T AngleBetween(const Quaternion<T>& q1, const Quaternion<T>& q2)
	{
		return q1.Angle(q2);
	}

	// Quaternion inverse
	template <typename T>
	Quaternion<T> Inverse(const Quaternion<T>& q)
	{
		return q.Inverse();
	}

	// Spherical linear interpolation between q1 and q2 for t=[0,1]
	template <typename T>
	Quaternion<T> Slerp(const Quaternion<T>& q1, const Quaternion<T>& q2, const T& t)
	{
		return q1.Slerp(q2, t);
	}

	template <typename T>
	Vector3<T> RotateQuaternion(const Quaternion<T>& rotation, const Vector3<T>& v)
	{
		Quaternion<T> q = rotation * v;
		q *= rotation.Inverse();
		return Vector3<T>(q.GetX(), q.GetY(), q.GetZ());
	}

	// Get the rotation from one vector orientation to another, with the shortest arc length.
	// Assumes v0 and v1 are both normalized.
	template <typename T>
	Quaternion<T> ShortestArcQuat(const Vector3<T>& v0, const Vector3<T>& v1)
	{
		const Vector3<T> cross = v0.Cross(v1);
		const T dot = v0.Dot(v1);

		// If v0 == -v1, literally any rotation will have the shortest arc,
		// so we pick any vector that's orthogonal to v0 and use that to avoid
		// division by zero in the regular case.
		if (dot < static_cast<T>(-1.f) + std::numeric_limits<T>::epsilon())
		{
			Vector3<T> n, dummy;
			GetOrthogonal(v0, n, dummy);
			return Quaternion<T>(n.x, n.y, n.z, static_cast<T>(0.0f));
		}

		const T s = Sqrt<T>((static_cast<T>(1.0f) + dot) * static_cast<T>(2.0f));
		const T rs = static_cast<T>(1.0f) / s;

		return Quaternion<T>(cross.x * rs, cross.y * rs, cross.z * rs, s * static_cast<T>(0.5f));
	}

	template <typename T>
	Quaternion<T> ShortestArcQuatNormalize2(Vector3<T>& v0, Vector3<T>& v1)
	{
		return ShortestArcQuat(v0.Normalized(), v1.Normalized());
	}

	// Convenience Aliases
	using Quaternionf = Quaternion<float>;
	using Quaterniond = Quaternion<double>;
}