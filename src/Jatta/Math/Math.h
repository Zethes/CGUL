/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    namespace Math
    {
        const Float32 pi = 3.14159f;

        _JATTA_EXPORT Float32 Abs(Float32 x);

        _JATTA_EXPORT Float32 Cos(Float32 x);
        _JATTA_EXPORT Float32 Sin(Float32 x);
        _JATTA_EXPORT Float32 Tan(Float32 x);

        _JATTA_EXPORT Float32 DegToRad(Float32 deg);

        _JATTA_EXPORT Float32 Min(Float32 a, Float32 b);
        _JATTA_EXPORT Float32 Max(Float32 a, Float32 b);

        _JATTA_EXPORT Float32 Floor(Float32 x);

        _JATTA_EXPORT Float32 Mod(Float32 x, Float32 div);

        _JATTA_EXPORT Float32 Sqrt(Float32 x);

        _JATTA_EXPORT bool InEpsilon(Float32 value, Float32 compare, Float32 epsilon);
    }
}

#include "../External/Undefines.h"
