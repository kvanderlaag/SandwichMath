#pragma once

#include <cmath>

#ifdef __GNUC__
namespace std
{
    inline float sqrtf(float f)
    {
        return ::sqrtf(f);
    }

    inline float fabsf(float f)
    {
        return ::fabsf(f);
    }

    inline float sinf(float f)
    {
        return ::sinf(f);
    }

    inline float cosf(float f)
    {
        return ::cosf(f);
    }

    inline float asinf(float f)
    {
        return ::asinf(f);
    }

    inline float acosf(float f)
    {
        return ::acosf(f);
    }

    inline float atanf(float f)
    {
        return ::atanf(f);
    }

    inline float atan2f(float f1, float f2)
    {
        return ::atan2f(f1, f2);
    }
}
#endif
