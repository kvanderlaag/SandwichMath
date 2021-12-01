#include <Vector.h>
#include <MathTemplateUtil.h>

namespace Math
{
	const Vector2f Vector2f::UNIT_X = { 1.f, 0.f };
	const Vector2f Vector2f::UNIT_Y = { 0.f, 1.f };
	
	const Vector3f Vector3f::UNIT_X = { 1.f, 0.f, 0.f };
	const Vector3f Vector3f::UNIT_Y = { 0.f, 1.f, 0.f };
	const Vector3f Vector3f::UNIT_Z = { 0.f, 0.f, 1.f };

	const Vector4f Vector4f::UNIT_X = { 1.f, 0.f, 0.f, 0.f };
	const Vector4f Vector4f::UNIT_Y = { 0.f, 1.f, 0.f, 0.f };
	const Vector4f Vector4f::UNIT_Z = { 0.f, 0.f, 1.f, 0.f };
	const Vector4f Vector4f::UNIT_W = { 0.f, 0.f, 0.f, 1.f };

	const Vector2i Vector2i::UNIT_X = { 1, 0 };
	const Vector2i Vector2i::UNIT_Y = { 0, 1 };

	const Vector3i Vector3i::UNIT_X = { 1, 0, 0 };
	const Vector3i Vector3i::UNIT_Y = { 0, 1, 0 };
	const Vector3i Vector3i::UNIT_Z = { 0, 0, 1 };

	const Vector4i Vector4i::UNIT_X = { 1, 0, 0, 0 };
	const Vector4i Vector4i::UNIT_Y = { 0, 1, 0, 0 };
	const Vector4i Vector4i::UNIT_Z = { 0, 0, 1, 0 };
	const Vector4i Vector4i::UNIT_W = { 0, 0, 0, 1 };

	const Vector2d Vector2d::UNIT_X = { 1.0, 0.0};
	const Vector2d Vector2d::UNIT_Y = { 0.0, 1.0 };

	const Vector3d Vector3d::UNIT_X = { 1.0, 0.0, 0.0 };
	const Vector3d Vector3d::UNIT_Y = { 0.0, 1.0, 0.0 };
	const Vector3d Vector3d::UNIT_Z = { 0.0, 0.0, 1.0 };

	const Vector4d Vector4d::UNIT_X = { 1.0, 0.0, 0.0, 0.0 };
	const Vector4d Vector4d::UNIT_Y = { 0.0, 1.0, 0.0, 0.0 };
	const Vector4d Vector4d::UNIT_Z = { 0.0, 0.0, 1.0, 0.0 };
	const Vector4d Vector4d::UNIT_W = { 0.0, 0.0, 0.0, 1.0 };

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

	static void VectorTest()
	{
		{
			Vector2d normalizeTest = Normalize((Vector2d(5, 5) + Vector2d(6, 6)));
			normalizeTest = (Vector2d(6, 7) + Vector2d(2, 0)).Normalized();
			normalizeTest = (Vector2d(1, 6) - Vector2d(-3, 12.2)).Normalize();

			double distanceTest = Distance(Vector2d(12, 13), Vector2d(6, 5));

			Vector2d swizzleTest = normalizeTest.xx();
		}

		{
			Vector3d normalizeTest = Normalize((Vector3d(5, 5, 5) + Vector3d(6, 6, 6)));
			normalizeTest = (Vector3d(6, 7, 8) + Vector3d(2, 0, -2)).Normalized();
			normalizeTest = (Vector3d(1, 6, 3) - Vector3d(-3, 12.2, 24.6)).Normalize();

			double distanceTest = Distance(Vector3d(12, 13, 6), Vector3d(6, 5, 1));

			Vector3d swizzleTest = normalizeTest.xx();
		}

		{
			Vector4d normalizeTest = Normalize((Vector4d(5, 5, 5, 5) + Vector4d(6, 6, 6, 6)));
			normalizeTest = (Vector4d(6, 7, 8, 9) + Vector4d(2, 0, 4, 1)).Normalized();
			normalizeTest = (Vector4d(1, 6, 5, 1) - Vector4d(-3, 12.2, 17.5, 6)).Normalize();

			double distanceTest = Distance(Vector4d(12, 13, 199, -300), Vector4d(6, 5, 500, 17.1));

			Vector4d swizzleTest = normalizeTest.xx();
		}
		
	}
}