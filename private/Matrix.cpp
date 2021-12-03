#include <Matrix.h>
#include <Vector.h>

namespace Math
{
    template<>
	const Matrix3x3<float> Matrix3x3<float>::IDENTITY =
		Matrix3x3<float>(
			Vector3<float>(1.f, 0.f, 0.f),
			Vector3<float>(0.f, 1.f, 0.f),
			Vector3<float>(0.f, 0.f, 1.f)
		);

    template<>
	const Matrix3x3<int> Matrix3x3<int>::IDENTITY =
		Matrix3x3<int>(
			Vector3<int>(1.f, 0.f, 0.f),
			Vector3<int>(0.f, 1.f, 0.f),
			Vector3<int>(0.f, 0.f, 1.f)
			);

    template<>
	const Matrix4x4<float> Matrix4x4<float>::IDENTITY =
		Matrix4x4<float>(
			Vector4<float>(1.f, 0.f, 0.f, 0.f),
			Vector4<float>(0.f, 1.f, 0.f, 0.f),
			Vector4<float>(0.f, 0.f, 1.f, 0.f),
			Vector4<float>(0.f, 0.f, 0.f, 1.f)
			);

    template<>
	const Matrix4x4<int> Matrix4x4<int>::IDENTITY =
		Matrix4x4<int>(
			Vector4<int>(1.f, 0.f, 0.f, 0.f),
			Vector4<int>(0.f, 1.f, 0.f, 0.f),
			Vector4<int>(0.f, 0.f, 1.f, 0.f),
			Vector4<int>(0.f, 0.f, 0.f, 1.f)
			);

	const Matrix3x3f TestMatrixRotationX =
	{
		{ 1.f,  0.f,  0.f },
		{ 0.f,  0.f, -1.f },
		{ 0.f,  1.f,  0.f }
	};

	const Matrix3x3f TestMatrixRotationY =
	{
		{  0.f,  0.f,  1.f },
		{  0.f,  1.f,  0.f },
		{ -1.f,  0.f,  0.f }
	};

	const Matrix3x3f TestMatrixRotationZ =
	{
		{ 0.f,	-1.f,  0.f },
		{ 1.f,   0.f,  0.f },
		{ 0.f,	 0.f,  1.f }
	};

	const Matrix3x3f TestMatrixRotationXYZ =
	{
		{ -0.f,  0.f,  1.f },
		{  0.f, -1.f,  0.f },
		{  1.f,  0.f, -0.f}
	};

	bool TestMatrixMultiplication()
	{
		if (Matrix3x3f::IDENTITY * Matrix3x3f::IDENTITY != Matrix3x3f::IDENTITY)
		{
			bool* retVal = 0;
			return *retVal;
		}
		if (Matrix3x3f::IDENTITY * TestMatrixRotationXYZ != TestMatrixRotationXYZ)
		{
			bool* retVal = 0;
			return *retVal;
		}
		Matrix3x3f TestRotationMult = TestMatrixRotationX * TestMatrixRotationY * TestMatrixRotationZ;
		if (TestRotationMult != TestMatrixRotationXYZ)
		{
			bool* retVal = 0;
			return *retVal;
		}

		return true;
	}
}