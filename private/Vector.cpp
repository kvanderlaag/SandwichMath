#include <Vector.h>
#include <MathTemplateUtil.h>

namespace Math
{
	    template<>
    const Vector2f Vector2f::UNIT_X = Vector2f(1.f, 0.f);
    template<>
    const Vector2f Vector2f::UNIT_Y = Vector2f(0.f, 1.f);

    template<>
    const Vector3f Vector3f::UNIT_X = Vector3f(1.f, 0.f, 0.f);
    template<>
    const Vector3f Vector3f::UNIT_Y = Vector3f(0.f, 1.f, 0.f);
    template<>
    const Vector3f Vector3f::UNIT_Z = Vector3f(0.f, 0.f, 1.f);

    template<>
    const Vector4f Vector4f::UNIT_X = Vector4f(1.f, 0.f, 0.f, 0.f);
    template<>
    const Vector4f Vector4f::UNIT_Y = Vector4f(0.f, 1.f, 0.f, 0.f);
    template<>
    const Vector4f Vector4f::UNIT_Z = Vector4f(0.f, 0.f, 1.f, 0.f);
    template<>
    const Vector4f Vector4f::UNIT_W = Vector4f(0.f, 0.f, 0.f, 1.f);

    template<>
    const Vector2d Vector2d::UNIT_X = Vector2d(1.0, 0.0);
    template<>
    const Vector2d Vector2d::UNIT_Y = Vector2d(0.0, 1.0);

    template<>
    const Vector3d Vector3d::UNIT_X = Vector3d(1.0, 0.0, 0.0);
    template<>
    const Vector3d Vector3d::UNIT_Y = Vector3d(0.0, 1.0, 0.0);
    template<>
    const Vector3d Vector3d::UNIT_Z = Vector3d(0.0, 0.0, 1.0);

    template<>
    const Vector4d Vector4d::UNIT_X = Vector4d(1.0, 0.0, 0.0, 0.0);
    template<>
    const Vector4d Vector4d::UNIT_Y = Vector4d(0.0, 1.0, 0.0, 0.0);
    template<>
    const Vector4d Vector4d::UNIT_Z = Vector4d(0.0, 0.0, 1.0, 0.0);
    template<>
    const Vector4d Vector4d::UNIT_W = Vector4d(0.0, 0.0, 0.0, 1.0);

    template<>
    const Vector2i Vector2i::UNIT_X = Vector2i(1, 0);
    template<>
    const Vector2i Vector2i::UNIT_Y = Vector2i(0, 1);

    template<>
    const Vector3i Vector3i::UNIT_X = Vector3i(1, 0, 0);
    template<>
    const Vector3i Vector3i::UNIT_Y = Vector3i(0, 1, 0);
    template<>
    const Vector3i Vector3i::UNIT_Z = Vector3i(0, 0, 1);

    template<>
    const Vector4i Vector4i::UNIT_X = Vector4i(1, 0, 0, 0);
    template<>
    const Vector4i Vector4i::UNIT_Y = Vector4i(0, 1, 0, 0);
    template<>
    const Vector4i Vector4i::UNIT_Z = Vector4i(0, 0, 1, 0);
    template<>
    const Vector4i Vector4i::UNIT_W = Vector4i(0, 0, 0, 1);
	
	void VectorTest()
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

            Vector2f lerpTest = Lerp(Vector2f::UNIT_X, Vector2f::UNIT_Y, 0.5f);
		}
		
	}
}