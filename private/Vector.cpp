#include <Vector.h>

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
}