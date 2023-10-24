#pragma once

#include <Vector.h>
#include <Matrix.h>
#include <cassert.h>
#include <limits>

namespace Math
{
	
	template<typename T>
	Matrix4x4<T> MakePerspective(T yFoV, T aspectRatio, T nearZ, T farZ)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		const T tanHalfFoV = tan(yFoV / static_cast<T>(2));

		Matrix4x4<T> perspectiveMat();
		perspectiveMat[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFoV);
		perspectiveMat[1][1] = static_cast<T>(1) / (tanHalfFoV);
		perspectiveMat[2][2] = farZ / (farZ - nearZ);
		perspectiveMat[2][3] = static_cast<T>(1);
		perspectiveMat[3][2] = -(farZ * nearZ) / (farZ - nearZ);
		return perspectiveMat;
	}

	template<typename T>
	Matrix4x4<T> MakeFrustumProjection(T left, T right, T bottom, T top, T nearZ, T farZ)
	{
		Matrix4x4<T> projectionMat();
		projectionMat[0][0] = (static_cast<T>(2) * nearZ) / (right - left);
		projectionMat[1][1] = (static_cast<T>(2) * nearZ) / (top - bottom);
		projectionMat[2][0] = -(right + left) / (right - left);
		projectionMat[2][1] = -(top + bottom) / (top - bottom);
		projectionMat[2][2] = farZ / (farZ - nearZ);
		projectionMat[2][3] = static_cast<T>(1);
		projectionMat[3][2] = -(farZ * nearZ) / (farZ - nearZ);
		return projectionMat;
	}

}