/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2;
    struct Float3;
    struct Quaternion;
    
    struct Matrix
    {
        union
        {
            Float32 m[4][4];
            Float32 data[16];
        };
    public:
        _JATTA_EXPORT static Matrix Identity();

        _JATTA_EXPORT static Matrix MakeRotation(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationX(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationY(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotationZ(Float32 angle);
        _JATTA_EXPORT static Matrix MakeRotation(const Quaternion& quaternion);
        _JATTA_EXPORT static Matrix MakeScaling(Float2 scale);
        _JATTA_EXPORT static Matrix MakeScaling(Float3 scale);
        _JATTA_EXPORT static Matrix MakeTranslation(Float2 translation);
        _JATTA_EXPORT static Matrix MakeTranslation(Float3 translation);

        _JATTA_EXPORT static Matrix MakePerspective(Float32 fovY, Float32 aspectRatio, Float32 zNear, Float32 zFar);
        _JATTA_EXPORT static Matrix MakeLookAt(const Float3& eye, const Float3& at, const Float3& up);
        _JATTA_EXPORT static Matrix MakeOrtho(int left, int right, int bottom, int top);

        _JATTA_EXPORT Matrix();
        _JATTA_EXPORT Matrix(const Matrix& copy);
        _JATTA_EXPORT Matrix(Matrix&& move);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m21, Float32 m22);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m13, Float32 m21, Float32 m22, Float32 m23, Float32 m31, Float32 m32, Float32 m33);
        _JATTA_EXPORT Matrix(Float32 m11, Float32 m12, Float32 m13, Float32 m14, Float32 m21, Float32 m22, Float32 m23, Float32 m24, Float32 m31, Float32 m32, Float32 m33, Float32 m34, Float32 m41, Float32 m42, Float32 m43, Float32 m44);
        _JATTA_EXPORT ~Matrix();

        _JATTA_EXPORT Matrix& operator=(const Matrix& operand);
        _JATTA_EXPORT Float32* operator[](UInt32 index);
        _JATTA_EXPORT const Float32* operator[](UInt32 index) const;
        _JATTA_EXPORT Matrix operator*(const Matrix& operand) const;
        friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
        {
            stream << "[" << matrix.m[0][0] << ", " << matrix.m[1][0] << ", " << matrix.m[2][0] << ", " << matrix.m[3][0] << "]" << std::endl;
            stream << "|" << matrix.m[0][1] << ", " << matrix.m[1][1] << ", " << matrix.m[2][1] << ", " << matrix.m[3][1] << "|" << std::endl;
            stream << "|" << matrix.m[0][2] << ", " << matrix.m[1][2] << ", " << matrix.m[2][2] << ", " << matrix.m[3][2] << "|" << std::endl;
            stream << "[" << matrix.m[0][3] << ", " << matrix.m[1][3] << ", " << matrix.m[2][3] << ", " << matrix.m[3][3] << "]";
            return stream;
        }

        _JATTA_EXPORT Float32* GetData() const;

        _JATTA_EXPORT void Debug() const;

        // TODO: finish the matrix class, we're missing some important functionality here
        // TODO: add a cout for matrices
    };
}

#include "../External/Undefines.h"
