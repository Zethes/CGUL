/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Math.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Quaternion.h"

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Identity()
{
    return MatrixT(Type(1), Type(0), Type(0), Type(0),
                   Type(0), Type(1), Type(0), Type(0),
                   Type(0), Type(0), Type(1), Type(0),
                   Type(0), Type(0), Type(0), Type(1));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotation(Type angle)
{
    return MatrixT(Math::Cos(angle),  Math::Sin(angle), 0, 0,
                   -Math::Sin(angle), Math::Cos(angle), 0, 0,
                   0,                0,                 1, 0,
                   0,                0,                 0, 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationX(Type angle)
{
    return MatrixT(1, 0,          0,           0,
                   0, Math::Cos(angle),  Math::Sin(angle), 0,
                   0, -Math::Sin(angle), Math::Cos(angle), 0,
                   0, 0,                0,                 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationY(Type angle)
{
    return MatrixT(Math::Cos(angle), 0, -Math::Sin(angle), 0,
                   0,                1, 0,                 0,
                   Math::Sin(angle), 0, Math::Cos(angle),  0,
                   0,                0, 0,                 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationZ(Type angle)
{
    return MatrixT(Math::Cos(angle),  Math::Sin(angle), 0, 0,
                   -Math::Sin(angle), Math::Cos(angle), 0, 0,
                   0,                0,                 1, 0,
                   0,                0,                 0, 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotation(const QuaternionT< Type >& quaternion)
{
    return MatrixT(quaternion);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeScaling(const Vector2T< Type >& scale)
{
    return MatrixT(scale.x, 0,       0, 0,
                   0,       scale.y, 0, 0,
                   0,       0,       1, 0,
                   0,       0,       0, 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeScaling(const Vector3T< Type >& scale)
{
    return MatrixT(scale.x, 0,       0,       0,
                   0,       scale.y, 0,       0,
                   0,       0,       scale.z, 0,
                   0,       0,       0,       1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeTranslation(const Vector2T< Type >& translation)
{
    return MatrixT(1,             0,             0, 0,
                   0,             1,             0, 0,
                   0,             0,             1, 0,
                   translation.x, translation.y, 0, 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeTranslation(const Vector3T< Type >& translation)
{
    return MatrixT(1,             0,             0,             0,
                   0,             1,             0,             0,
                   0,             0,             1,             0,
                   translation.x, translation.y, translation.z, 1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakePerspective(Type fovY, Type aspectRatio, Type zNear, Type zFar)
{
    Type yScale = Type(1.0) / Math::Tan(Math::DegToRad(fovY / Type(2.0)));
    Type xScale = yScale / aspectRatio;
    return Matrix(xScale, 0,      0,                              0,
                  0,      yScale, 0,                              0,
                  0,      0,      zFar / (zFar - zNear),          1,
                  0,      0,      -zNear * zFar / (zFar - zNear), 0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeLookAt(const Vector3T< Type >& eye, const Vector3T< Type >& at, const Vector3T< Type >& up)
{
    Vector3T< Type > zAxis = Vector3T< Type >::Normalized(eye - at); // forward
    Vector3T< Type > xAxis = Vector3T< Type >::Normalized(Vector3T< Type >::CrossProduct(up, zAxis)); // right
    Vector3T< Type > yAxis = Vector3T< Type >::CrossProduct(xAxis, zAxis); // up
    zAxis *= -1;
    yAxis *= -1;

    return MatrixT< Type >(xAxis.x,                                    yAxis.x,                                    zAxis.x,                                   0,
                           xAxis.y,                                    yAxis.y,                                    zAxis.y,                                   0,
                           xAxis.z,                                    yAxis.z,                                    zAxis.z,                                   0,
                           -Vector3T< Type >::DotProduct(xAxis, eye),  -Vector3T< Type >::DotProduct(yAxis, eye),  -Vector3T< Type >::DotProduct(zAxis, eye), 1);
}

//template< typename Type >
/*_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeOrtho(int left, int right, int bottom, int top)
{
  Vector3 t((right + left) / (Type)(right - left), (top + bottom) / (Type)(top - bottom), 0);

  return Matrix(Type(2.0) / (right - left), 0,                          0,    0,
                0,                          Type(2.0) / (top - bottom), 0,    0,
                0,                          0,                         -1,   0,
                -t.x,                      -t.y,                       -t.z, 1);// * Matrix::makeScaling(Vector3(1, -1, 1));
}*/

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeOrtho(SInt left, SInt right, SInt bottom, SInt top)
{
  /*Vector3 t((right + left) / (Type)(right - left), (top + bottom) / (Type)(top - bottom), 0);

  return Matrix(Type(2.0) / (right - left), 0,                          0,    -t.x,
                0,                          Type(2.0) / (top - bottom), 0,    -t.y,
                0,                          0,                          -1,   -t.z,
                0,                          0,                          0,  1);// * Matrix::makeScaling(Vector3(1, -1, 1));*/

    MatrixT< Type > ret = Identity();
    /*ret.m[0][0] = Type(2) / (right - left);
    ret.m[1][1] = Type(2) / (top - bottom);
    ret.m[2][2] = - Type(2) / (1 - (-1));
    ret.m[3][0] = - (right + left) / (right - left);
    ret.m[3][1] = - (top + bottom) / (top - bottom);
    ret.m[3][2] = - (1 + (-1)) / (1 - (-1));*/
    ret.m[0][0] = Type(2) / (right - left);
    ret.m[1][1] = Type(2) / (top - bottom);
    ret.m[2][2] = - Type(2) / ((1) - (-1));
    ret.m[3][0] = - Type((right + left) / (right - left));
    ret.m[3][1] = - Type((top + bottom) / (top - bottom));
    ret.m[3][2] = - Type((1) + (-1)) / Type((1) - (-1));
    return ret;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Inverse(const MatrixT& matrix)
{
    MatrixT< Type > result;
    result.m[0][0] = matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2] - matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2] - matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1];
    result.m[0][1] = matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][2] + matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][2];
    result.m[0][2] = matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][1] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][2] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][2] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][3] - matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][1];
    result.m[0][3] = matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] + matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2];
    result.m[1][0] = matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2] + matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2];
    result.m[1][1] = matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][2] - matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][2] - matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][0];
    result.m[1][2] = matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][2] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][3] + matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][0] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][2];
    result.m[1][3] = matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] - matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0];
    result.m[2][0] = matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1] - matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0];
    result.m[2][1] = matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][1];
    result.m[2][2] = matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][1] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][1] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][3] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][0];
    result.m[2][3] = matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1];
    result.m[3][0] = matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1] + matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2] + matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2] - matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1];
    result.m[3][1] = matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][2] + matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][1] - matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][2] - matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][0];
    result.m[3][2] = matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][1] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][2] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][0] - matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][2] - matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][1];
    result.m[3][3] = matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0];
    result /= matrix.GetDeterminant();
    return result;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Transpose(const MatrixT& matrix)
{
    MatrixT< Type > result;
    result.m[0][0] = matrix.m[0][0]; result.m[1][0] = matrix.m[0][1]; result.m[2][0] = matrix.m[0][2]; result.m[3][0] = matrix.m[0][3];
    result.m[0][1] = matrix.m[1][0]; result.m[1][1] = matrix.m[1][1]; result.m[2][1] = matrix.m[1][2]; result.m[3][1] = matrix.m[1][3];
    result.m[0][2] = matrix.m[2][0]; result.m[1][2] = matrix.m[2][1]; result.m[2][2] = matrix.m[2][2]; result.m[3][2] = matrix.m[2][3];
    result.m[0][3] = matrix.m[3][0]; result.m[1][3] = matrix.m[3][1]; result.m[2][3] = matrix.m[3][2]; result.m[3][3] = matrix.m[3][3];
    return result;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT()
{
    this->m[0][0] = 1;
    this->m[0][1] = 0;
    this->m[0][2] = 0;
    this->m[0][3] = 0;
    this->m[1][0] = 0;
    this->m[1][1] = 1;
    this->m[1][2] = 0;
    this->m[1][3] = 0;
    this->m[2][0] = 0;
    this->m[2][1] = 0;
    this->m[2][2] = 1;
    this->m[2][3] = 0;
    this->m[3][0] = 0;
    this->m[3][1] = 0;
    this->m[3][2] = 0;
    this->m[3][3] = 1;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(const MatrixT& copy)
{
    this->m[0][0] = copy.m[0][0];
    this->m[0][1] = copy.m[0][1];
    this->m[0][2] = copy.m[0][2];
    this->m[0][3] = copy.m[0][3];
    this->m[1][0] = copy.m[1][0];
    this->m[1][1] = copy.m[1][1];
    this->m[1][2] = copy.m[1][2];
    this->m[1][3] = copy.m[1][3];
    this->m[2][0] = copy.m[2][0];
    this->m[2][1] = copy.m[2][1];
    this->m[2][2] = copy.m[2][2];
    this->m[2][3] = copy.m[2][3];
    this->m[3][0] = copy.m[3][0];
    this->m[3][1] = copy.m[3][1];
    this->m[3][2] = copy.m[3][2];
    this->m[3][3] = copy.m[3][3];
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(MatrixT&& move)
{
    this->m[0][0] = move.m[0][0];
    this->m[0][1] = move.m[0][1];
    this->m[0][2] = move.m[0][2];
    this->m[0][3] = move.m[0][3];
    this->m[1][0] = move.m[1][0];
    this->m[1][1] = move.m[1][1];
    this->m[1][2] = move.m[1][2];
    this->m[1][3] = move.m[1][3];
    this->m[2][0] = move.m[2][0];
    this->m[2][1] = move.m[2][1];
    this->m[2][2] = move.m[2][2];
    this->m[2][3] = move.m[2][3];
    this->m[3][0] = move.m[3][0];
    this->m[3][1] = move.m[3][1];
    this->m[3][2] = move.m[3][2];
    this->m[3][3] = move.m[3][3];
}
#endif

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m11, Type m12, Type m21, Type m22)
{
    this->m[0][0] = m11;
    this->m[0][1] = m12;
    this->m[0][2] = 0;
    this->m[0][3] = 0;
    this->m[1][0] = m21;
    this->m[1][1] = m22;
    this->m[1][2] = 0;
    this->m[1][3] = 0;
    this->m[2][0] = 0;
    this->m[2][1] = 0;
    this->m[2][2] = 1;
    this->m[2][3] = 0;
    this->m[3][0] = 0;
    this->m[3][1] = 0;
    this->m[3][2] = 0;
    this->m[3][3] = 1;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m11, Type m12, Type m13, Type m21, Type m22, Type m23, Type m31, Type m32, Type m33)
{
    this->m[0][0] = m11;
    this->m[0][1] = m12;
    this->m[0][2] = m13;
    this->m[0][3] = 0;
    this->m[1][0] = m21;
    this->m[1][1] = m22;
    this->m[1][2] = m23;
    this->m[1][3] = 0;
    this->m[2][0] = m31;
    this->m[2][1] = m32;
    this->m[2][2] = m33;
    this->m[2][3] = 0;
    this->m[3][0] = 0;
    this->m[3][1] = 0;
    this->m[3][2] = 0;
    this->m[3][3] = 1;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m11, Type m12, Type m13, Type m14, Type m21, Type m22, Type m23, Type m24, Type m31, Type m32, Type m33, Type m34, Type m41, Type m42, Type m43, Type m44)
{
    this->m[0][0] = m11;
    this->m[0][1] = m12;
    this->m[0][2] = m13;
    this->m[0][3] = m14;
    this->m[1][0] = m21;
    this->m[1][1] = m22;
    this->m[1][2] = m23;
    this->m[1][3] = m24;
    this->m[2][0] = m31;
    this->m[2][1] = m32;
    this->m[2][2] = m33;
    this->m[2][3] = m34;
    this->m[3][0] = m41;
    this->m[3][1] = m42;
    this->m[3][2] = m43;
    this->m[3][3] = m44;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(const QuaternionT< Type >& quaternion)
{
    this->m[0][0] = 1 - (2 * Math::Sqr(quaternion.y) + 2 * Math::Sqr(quaternion.z));
    this->m[0][1] = 2 * quaternion.x * quaternion.y + 2 * quaternion.z * quaternion.w;
    this->m[0][2] = 2 * quaternion.x * quaternion.z - 2 * quaternion.y * quaternion.w;
    this->m[0][3] = 0;
    this->m[1][0] = 2 * quaternion.x * quaternion.y - 2 * quaternion.z * quaternion.w;
    this->m[1][1] = 1 - (2 * Math::Sqr(quaternion.x) + 2 * Math::Sqr(quaternion.z));
    this->m[1][2] = 2 * quaternion.y * quaternion.z + 2 * quaternion.x * quaternion.w;
    this->m[1][3] = 0;
    this->m[2][0] = 2 * quaternion.x * quaternion.z + 2 * quaternion.y * quaternion.w;
    this->m[2][1] = 2 * quaternion.y * quaternion.z - 2 * quaternion.x * quaternion.w;
    this->m[2][2] = 1 - (2 * Math::Sqr(quaternion.x) + 2 * Math::Sqr(quaternion.y));
    this->m[2][3] = 0;
    this->m[3][0] = 0;
    this->m[3][1] = 0;
    this->m[3][2] = 0;
    this->m[3][3] = 1;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::~MatrixT()
{
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator=(const MatrixT& operand)
{
    this->m[0][0] = operand.m[0][0];
    this->m[0][1] = operand.m[0][1];
    this->m[0][2] = operand.m[0][2];
    this->m[0][3] = operand.m[0][3];
    this->m[1][0] = operand.m[1][0];
    this->m[1][1] = operand.m[1][1];
    this->m[1][2] = operand.m[1][2];
    this->m[1][3] = operand.m[1][3];
    this->m[2][0] = operand.m[2][0];
    this->m[2][1] = operand.m[2][1];
    this->m[2][2] = operand.m[2][2];
    this->m[2][3] = operand.m[2][3];
    this->m[3][0] = operand.m[3][0];
    this->m[3][1] = operand.m[3][1];
    this->m[3][2] = operand.m[3][2];
    this->m[3][3] = operand.m[3][3];
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator=(const QuaternionT< Type >& operand)
{
    return *this = Matrix(operand);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::MatrixT< Type >::operator==(const MatrixT& operand)
{
    return (m[0][0] == operand.m[0][0] &&
            m[0][1] == operand.m[0][1] &&
            m[0][2] == operand.m[0][2] &&
            m[0][3] == operand.m[0][3] &&
            m[1][0] == operand.m[1][0] &&
            m[1][1] == operand.m[1][1] &&
            m[1][2] == operand.m[1][2] &&
            m[1][3] == operand.m[1][3] &&
            m[2][0] == operand.m[2][0] &&
            m[2][1] == operand.m[2][1] &&
            m[2][2] == operand.m[2][2] &&
            m[2][3] == operand.m[2][3] &&
            m[3][0] == operand.m[3][0] &&
            m[3][1] == operand.m[3][1] &&
            m[3][2] == operand.m[3][2] &&
            m[3][3] == operand.m[3][3]);
}

template< typename Type >
_JATTA_INLINE_DEFINE bool Jatta::MatrixT< Type >::operator!=(const MatrixT& operand)
{
    return !(*this == operand);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type* Jatta::MatrixT< Type >::operator[](UInt32 index)
{
    return m[index];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT const Type* Jatta::MatrixT< Type >::operator[](UInt32 index) const
{
    return m[index];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::operator*(const MatrixT& operand) const
{
    return Matrix(this->m[0][0] * operand.m[0][0] + this->m[0][1] * operand.m[1][0] + this->m[0][2] * operand.m[2][0] + this->m[0][3] * operand.m[3][0],
                  this->m[0][0] * operand.m[0][1] + this->m[0][1] * operand.m[1][1] + this->m[0][2] * operand.m[2][1] + this->m[0][3] * operand.m[3][1],
                  this->m[0][0] * operand.m[0][2] + this->m[0][1] * operand.m[1][2] + this->m[0][2] * operand.m[2][2] + this->m[0][3] * operand.m[3][2],
                  this->m[0][0] * operand.m[0][3] + this->m[0][1] * operand.m[1][3] + this->m[0][2] * operand.m[2][3] + this->m[0][3] * operand.m[3][3],
                  this->m[1][0] * operand.m[0][0] + this->m[1][1] * operand.m[1][0] + this->m[1][2] * operand.m[2][0] + this->m[1][3] * operand.m[3][0],
                  this->m[1][0] * operand.m[0][1] + this->m[1][1] * operand.m[1][1] + this->m[1][2] * operand.m[2][1] + this->m[1][3] * operand.m[3][1],
                  this->m[1][0] * operand.m[0][2] + this->m[1][1] * operand.m[1][2] + this->m[1][2] * operand.m[2][2] + this->m[1][3] * operand.m[3][2],
                  this->m[1][0] * operand.m[0][3] + this->m[1][1] * operand.m[1][3] + this->m[1][2] * operand.m[2][3] + this->m[1][3] * operand.m[3][3],
                  this->m[2][0] * operand.m[0][0] + this->m[2][1] * operand.m[1][0] + this->m[2][2] * operand.m[2][0] + this->m[2][3] * operand.m[3][0],
                  this->m[2][0] * operand.m[0][1] + this->m[2][1] * operand.m[1][1] + this->m[2][2] * operand.m[2][1] + this->m[2][3] * operand.m[3][1],
                  this->m[2][0] * operand.m[0][2] + this->m[2][1] * operand.m[1][2] + this->m[2][2] * operand.m[2][2] + this->m[2][3] * operand.m[3][2],
                  this->m[2][0] * operand.m[0][3] + this->m[2][1] * operand.m[1][3] + this->m[2][2] * operand.m[2][3] + this->m[2][3] * operand.m[3][3],
                  this->m[3][0] * operand.m[0][0] + this->m[3][1] * operand.m[1][0] + this->m[3][2] * operand.m[2][0] + this->m[3][3] * operand.m[3][0],
                  this->m[3][0] * operand.m[0][1] + this->m[3][1] * operand.m[1][1] + this->m[3][2] * operand.m[2][1] + this->m[3][3] * operand.m[3][1],
                  this->m[3][0] * operand.m[0][2] + this->m[3][1] * operand.m[1][2] + this->m[3][2] * operand.m[2][2] + this->m[3][3] * operand.m[3][2],
                  this->m[3][0] * operand.m[0][3] + this->m[3][1] * operand.m[1][3] + this->m[3][2] * operand.m[2][3] + this->m[3][3] * operand.m[3][3]);
}
template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::operator*(Type operand) const
{
    return Matrix(  this->m[0][0]*operand, this->m[0][1]*operand, this->m[0][2]*operand, this->m[0][3]*operand,
                    this->m[1][0]*operand, this->m[1][1]*operand, this->m[1][2]*operand, this->m[1][3]*operand,
                    this->m[2][0]*operand, this->m[2][1]*operand, this->m[2][2]*operand, this->m[2][3]*operand,
                    this->m[3][0]*operand, this->m[3][1]*operand, this->m[3][2]*operand, this->m[3][3]*operand);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator*=(Type operand)
{
    m[0][0] *= operand; m[1][0] *= operand; m[2][0] *= operand; m[3][0] *= operand;
    m[0][1] *= operand; m[1][1] *= operand; m[2][1] *= operand; m[3][1] *= operand;
    m[0][2] *= operand; m[1][2] *= operand; m[2][2] *= operand; m[3][2] *= operand;
    m[0][3] *= operand; m[1][3] *= operand; m[2][3] *= operand; m[3][3] *= operand;
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator/=(Type operand)
{
    Type inverse = 1 / operand;
    m[0][0] *= inverse; m[1][0] *= inverse; m[2][0] *= inverse; m[3][0] *= inverse;
    m[0][1] *= inverse; m[1][1] *= inverse; m[2][1] *= inverse; m[3][1] *= inverse;
    m[0][2] *= inverse; m[1][2] *= inverse; m[2][2] *= inverse; m[3][2] *= inverse;
    m[0][3] *= inverse; m[1][3] *= inverse; m[2][3] *= inverse; m[3][3] *= inverse;
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Invert()
{
    *this = Inverse(*this);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Transpose()
{
    *this = Transpose(*this);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type Jatta::MatrixT< Type >::GetDeterminant() const
{
    return m[0][0] * m[1][1] * m[2][2] * m[3][3] + m[0][0] * m[1][2] * m[2][3] * m[3][1] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
           m[0][1] * m[1][0] * m[2][3] * m[3][2] + m[0][1] * m[1][2] * m[2][0] * m[3][3] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
           m[0][2] * m[1][0] * m[2][1] * m[3][3] + m[0][2] * m[1][1] * m[2][3] * m[3][0] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
           m[0][3] * m[1][0] * m[2][2] * m[3][1] + m[0][3] * m[1][1] * m[2][0] * m[3][2] + m[0][3] * m[1][2] * m[2][1] * m[3][0] -
           m[0][0] * m[1][1] * m[2][3] * m[3][2] - m[0][0] * m[1][2] * m[2][1] * m[3][3] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
           m[0][1] * m[1][0] * m[2][2] * m[3][3] - m[0][1] * m[1][2] * m[2][3] * m[3][0] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
           m[0][2] * m[1][0] * m[2][3] * m[3][1] - m[0][2] * m[1][1] * m[2][0] * m[3][3] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
           m[0][3] * m[1][0] * m[2][1] * m[3][2] - m[0][3] * m[1][1] * m[2][2] * m[3][0] - m[0][3] * m[1][2] * m[2][0] * m[3][1];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type* Jatta::MatrixT< Type >::GetData() const
{
    return (Type*)m;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::MatrixT< Type >::IsReflexive() const
{
    return (m[0][0] == m[1][1] && m[2][2] == m[3][3] && m[0][0] == m[2][2]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::MatrixT< Type >::IsSymmetric() const
{
    //A = Transpose(A);

    return (*this == Transpose(*this));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::MatrixT< Type >::IsAntisymmetric() const
{
    //A = -Transpose(A);

    return (*this == Transpose(*this) * Type(-1));
}
