//        JATTA        //
// by Joshua Brookover //

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
            float m[4][4];
            float data[16];
        };
    public:
        _JATTA_EXPORT static const Matrix identity;

        _JATTA_EXPORT static Matrix makeRotation(float angle);
        _JATTA_EXPORT static Matrix makeRotationX(float angle);
        _JATTA_EXPORT static Matrix makeRotationY(float angle);
        _JATTA_EXPORT static Matrix makeRotationZ(float angle);
        _JATTA_EXPORT static Matrix makeScaling(Float2 scale);
        _JATTA_EXPORT static Matrix makeScaling(Float3 scale);
        _JATTA_EXPORT static Matrix makeTranslation(Float2 translation);
        _JATTA_EXPORT static Matrix makeTranslation(Float3 translation);

        _JATTA_EXPORT static Matrix makePerspective(float fovY, float aspectRatio, float zNear, float zFar);
        _JATTA_EXPORT static Matrix makeLookAt(const Float3& eye, const Float3& at, const Float3& up);
        _JATTA_EXPORT static Matrix makeOrtho(int right, int top, int left, int bottom);

        _JATTA_EXPORT Matrix();
        _JATTA_EXPORT Matrix(const Matrix& copy);
        _JATTA_EXPORT Matrix(Matrix&& move);
        _JATTA_EXPORT Matrix(float m11, float m12, float m21, float m22);
        _JATTA_EXPORT Matrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
        _JATTA_EXPORT Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
        _JATTA_EXPORT ~Matrix();

        _JATTA_EXPORT Matrix& operator=(const Matrix& operand);
        _JATTA_EXPORT Matrix operator*(const Matrix& operand) const;

        _JATTA_EXPORT float* getData() const;

        _JATTA_EXPORT void debug() const;
    };
}

#include "../External/Undefines.h"