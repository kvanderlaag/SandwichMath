#pragma once

#include <cmath>
#include <MathUtil.h>

namespace Math
{
	static constexpr float k_invSqrt2f = 0.7071067811865475244008443621048490f;
	static constexpr float k_fltPi = 3.14159265358979323846264338327950288f;

	template <typename T>
	inline T Sqrt(const T arg);

	template <typename T>
	T Abs(const T arg);

	template <typename T>
	T Sin(const T arg);

	template <typename T>
	T Cos(const T arg);

	template <typename T>
	T Tan(const T arg);

	template <typename T>
	T Asin(const T arg);

	template <typename T>
	T Acos(const T arg);

	template <typename T>
	T Atan(const T arg);

	template <typename T>
	T Atan2(const T arg1, const T arg2);	

// Sqrt specializations
	template <>
	inline float Sqrt<float>(const float arg)
	{
		return std::sqrtf(arg);
	}

	template <>
	inline double Sqrt<double>(const double arg)
	{
		return std::sqrt(arg);
	}

// Abs specializations
	template <>
	inline float Abs<float>(const float arg)
	{
		return std::fabsf(arg);
	}

	template <>
	inline double Abs<double>(const double arg)
	{
		return std::abs(arg);
	}

// Trig specializations: float
	template <>
	inline float Sin<float>(const float arg)
	{
		return std::sin(arg);
	}

	template <>
	inline float Cos<float>(const float arg)
	{
		return std::cos(arg);
	}

	template <>
	inline float Tan<float>(const float arg)
	{
		return std::tan(arg);
	}

	template <>
	inline float Asin<float>(const float arg)
	{
		return std::asinf(arg);
	}

	template <>
	inline float Acos<float>(const float arg)
	{
		return std::acosf(arg);
	}

	template <>
	inline float Atan<float>(const float arg)
	{
		return std::atanf(arg);
	}

	template <>
	inline float Atan2<float>(const float arg1, const float arg2)
	{
		return std::atan2f(arg1, arg2);
	}

// Trig specializations: double
	template <>
	inline double Sin<double>(const double arg)
	{
		return std::sin(arg);
	}

	template <>
	inline double Cos<double>(const double arg)
	{
		return std::cos(arg);
	}

	template <>
	inline double Tan<double>(const double arg)
	{
		return std::tan(arg);
	}

	template <>
	inline double Asin<double>(const double arg)
	{
		return std::asin(arg);
	}

	template <>
	inline double Acos<double>(const double arg)
	{
		return std::acos(arg);
	}

	template <>
	inline double Atan<double>(const double arg)
	{
		return std::atan(arg);
	}

	template <>
	inline double Atan2<double>(const double arg1, const double arg2)
	{
		return std::atan2(arg1, arg2);
	}
}