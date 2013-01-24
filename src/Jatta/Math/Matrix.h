/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2;
    struct Float3;
    
    struct Matrix
    {
        union
        {
            Float32 m[4][4];
            Float32 data[16];
        };
    public:
        _JATTA_EXPORT static const Matrix identity;

        _JATTA_EXPORT static Matrix MakeRotation(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationX(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationY(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationZ(Float32 angle);
        _JATTA_EXPORT static Matrix MakeScaling(Float2 scale);
        _JATTA_EXPORT static Matrix MakeScaling(Float3 scale);
        _JATTA_EXPORT static Matrix MakeTranslation(Float2 translation);
        _JATTA_EXPORT static Matrix MakeTranslation(Float3 translation);

        _JATTA_EXPORT static Matrix MakePerspective(Float32 fovY, Float32 aspectRatio, Float32 zNear, Float32 zFar);
        _JATTA_EXPORT static Matrix MakeLookAt(const Float3& eye, const Float3& at, const Float3& up);
        _JATTA_EXPORT static Matrix MakeOrtho(int right, int top, int left, int bottom);

        _JATTA_EXPORT Matrix();
        _JATTA_EXPORT Matrix(const Matrix& copy);
        _JATTA_EXPORT Matrix(Matrix&& move);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m21, Float32 m22);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m13, Float32 m21, Float32 m22, Float32 m23, Float32 m31, Float32 m32, Float32 m33);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m13, Float32 m14, Float32 m21, Float32 m22, Float32 m23, Float32 m24, Float32 m31, Float32 m32, Float32 m33, Float32 m34, Float32 m41, Float32 m42, Float32 m43, Float32 m44);
        _JATTA_EXPORT ~Matrix();

        _JATTA_EXPORT Matrix& operator=(const Matrix& operand);
        _JATTA_EXPORT Matrix operator*(const Matrix& operand) const;

        _JATTA_EXPORT Float32* GetData() const;

        _JATTA_EXPORT void Debug() const;
    };
}

#include "../External/Undefines.h"
