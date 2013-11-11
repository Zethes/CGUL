/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template< typename Type >
    struct Vector2T;
    template< typename Type >
    struct Vector3T;
    template< typename Type >
    struct QuaternionT;

    /** @brief A 4v4 matrix.
     *  @details At the moment the 4x4 matrix is the only matrix supported.  Variable sized
     *  matrices are not ideal for most applications and other NxN matrices can be mimicked with a
     *  4x4 matrix by setting the other elements to that of the identity matrix.
     */
    template< typename Type >
    struct MatrixT
    {
        union
        {
            //! @brief Direct access to a two dimensional array containing the matrix.
            Type m[4][4];
            //! @brief Direct access to the internal values as a single array.
            Type data[16];
        };

        _JATTA_INLINE_DEFINE static MatrixT< Type > Identity();

        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotation(Type angle);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationX(Type angle);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationY(Type angle);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationZ(Type angle);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotation(const QuaternionT< Type >& quaternion);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeScaling(const Vector2T< Type >& scale);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeScaling(const Vector3T< Type >& scale);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeTranslation(const Vector2T< Type >& translation);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeTranslation(const Vector3T< Type >& translation);

        _JATTA_INLINE_DEFINE static MatrixT< Type > MakePerspective(Type fovY, Type aspectRatio, Type zNear, Type zFar);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeLookAt(const Vector3T< Type >& eye, const Vector3T< Type >& at, const Vector3T< Type >& up);
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeOrtho(SInt left, SInt right, SInt bottom, SInt top);

        _JATTA_INLINE_DEFINE static MatrixT< Type > Inverse(const MatrixT& matrix);
        _JATTA_INLINE_DEFINE static MatrixT< Type > Transpose(const MatrixT& matrix);

        _JATTA_INLINE_DEFINE MatrixT();
        _JATTA_INLINE_DEFINE MatrixT(const MatrixT& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _JATTA_INLINE_DEFINE MatrixT(MatrixT&& move);
#       endif
        _JATTA_INLINE_DEFINE MatrixT(Type m11, Type m12, Type m21, Type m22);
        _JATTA_INLINE_DEFINE MatrixT(Type m11, Type m12, Type m13, Type m21, Type m22, Type m23, Type m31, Type m32, Type m33);
        _JATTA_INLINE_DEFINE MatrixT(Type m11, Type m12, Type m13, Type m14, Type m21, Type m22, Type m23, Type m24, Type m31, Type m32, Type m33, Type m34, Type m41, Type m42, Type m43, Type m44);
        _JATTA_INLINE_DEFINE MatrixT(const QuaternionT< Type >& quaternion);
        _JATTA_INLINE_DEFINE ~MatrixT();

        _JATTA_INLINE_DEFINE MatrixT& operator=(const MatrixT& operand);
        _JATTA_INLINE_DEFINE MatrixT& operator=(const QuaternionT< Type >& operand);
        _JATTA_INLINE_DEFINE Type* operator[](UInt32 index);
        _JATTA_INLINE_DEFINE const Type* operator[](UInt32 index) const;
        _JATTA_INLINE_DEFINE bool operator==(const MatrixT& operand);
        _JATTA_INLINE_DEFINE bool operator!=(const MatrixT& operand);
        _JATTA_INLINE_DEFINE MatrixT operator*(const MatrixT& operand) const;
        _JATTA_INLINE_DEFINE MatrixT operator*(Type operand) const;
        _JATTA_INLINE_DEFINE MatrixT& operator*=(Type operand);
        _JATTA_INLINE_DEFINE MatrixT& operator/=(Type operand);
        friend std::ostream& operator<<(std::ostream& stream, const MatrixT& matrix)
        {
            stream << "[" << matrix.data[0] << ", " << matrix.data[4] << ", " << matrix.data[ 8] << ", " << matrix.data[12] << "]" << std::endl;
            stream << "|" << matrix.data[1] << ", " << matrix.data[5] << ", " << matrix.data[ 9] << ", " << matrix.data[13] << "|" << std::endl;
            stream << "|" << matrix.data[2] << ", " << matrix.data[6] << ", " << matrix.data[10] << ", " << matrix.data[14] << "|" << std::endl;
            stream << "[" << matrix.data[3] << ", " << matrix.data[7] << ", " << matrix.data[11] << ", " << matrix.data[15] << "]";
            return stream;
        }

        _JATTA_INLINE_DEFINE Type* GetData() const;

        _JATTA_INLINE_DEFINE void Invert();
        _JATTA_INLINE_DEFINE void Transpose();
        _JATTA_INLINE_DEFINE Type GetDeterminant() const;

        _JATTA_INLINE_DEFINE void Debug() const;

        _JATTA_INLINE_DEFINE bool IsReflexive() const;
        _JATTA_INLINE_DEFINE bool IsSymmetric() const;
        _JATTA_INLINE_DEFINE bool IsAntisymmetric() const;

        // TODO: finish the matrix class, we're missing some important functionality here
    };

    typedef MatrixT<Float32> Matrix;
    typedef MatrixT<Float64> MatrixD;
}

#include "../External/Undefines.h"
#include "Matrix.ipp"
