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
        static const Matrix identity;

        static Matrix makeRotation(float angle);
        static Matrix makeRotationX(float angle);
        static Matrix makeRotationY(float angle);
        static Matrix makeRotationZ(float angle);
        static Matrix makeScaling(Float2 scale);
        static Matrix makeScaling(Float3 scale);
        static Matrix makeTranslation(Float2 translation);
        static Matrix makeTranslation(Float3 translation);

        static Matrix makePerspective(float fovY, float aspectRatio, float zNear, float zFar);
        static Matrix makeLookAt(const Float3& eye, const Float3& at, const Float3& up);
        static Matrix makeOrtho(int right, int top, int left, int bottom);

        Matrix();
        Matrix(const Matrix& copy);
        Matrix(Matrix&& move);
        Matrix(float m11, float m12, float m21, float m22);
        Matrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
        Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
        ~Matrix();

        Matrix& operator=(const Matrix& operand);
        Matrix operator*(const Matrix& operand) const;

        float* getData() const;

        void debug() const;
    };
}

#include "../External/Undefines.h"