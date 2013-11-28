/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Math.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Identity()
{
    return MatrixT(Type(1.0), Type(0.0), Type(0.0), Type(0.0),
                   Type(0.0), Type(1.0), Type(0.0), Type(0.0),
                   Type(0.0), Type(0.0), Type(1.0), Type(0.0),
                   Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotation(Type angle)
{
    return MatrixT(Math::Cos(angle), -Math::Sin(angle), Type(0.0), Type(0.0),
                   Math::Sin(angle), Math::Cos(angle),  Type(0.0), Type(0.0),
                   Type(0.0),        Type(0.0),         Type(1.0), Type(0.0),
                   Type(0.0),        Type(0.0),         Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationX(Type angle)
{
    return MatrixT(Type(1.0), Type(0.0),         Type(0.0),        Type(0.0),
                   Type(0.0), Math::Cos(angle),  Math::Sin(angle), Type(0.0),
                   Type(0.0), -Math::Sin(angle), Math::Cos(angle), Type(0.0),
                   Type(0.0), Type(0.0),         Type(0.0),        Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationY(Type angle)
{
    return MatrixT(Math::Cos(angle), Type(0), -Math::Sin(angle), Type(0),
                   Type(0),          Type(1),  Type(0),          Type(0),
                   Math::Sin(angle), Type(0),  Math::Cos(angle), Type(0),
                   Type(0),          Type(0),  Type(0),          Type(1));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotationZ(Type angle)
{
    return MatrixT( Math::Cos(angle),  Math::Sin(angle), Type(0.0), Type(0.0),
                    -Math::Sin(angle), Math::Cos(angle), Type(0.0), Type(0.0),
                    Type(0.0),         Type(0.0),        Type(1.0), Type(0.0),
                    Type(0.0),         Type(0.0),        Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeRotation(const QuaternionT< Type >& quaternion)
{
    return MatrixT(quaternion);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeScaling(const Vector2T< Type >& scale)
{
    return MatrixT(  scale.x,   Type(0.0), Type(0.0), Type(0.0),
                     Type(0.0), scale.y,   Type(0.0), Type(0.0),
                     Type(0.0), Type(0.0), Type(1.0), Type(0.0),
                     Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeScaling(const Vector3T< Type >& scale)
{
    return MatrixT(  scale.x,   Type(0.0), Type(0.0), Type(0.0),
                     Type(0.0), scale.y,   Type(0.0), Type(0.0),
                     Type(0.0), Type(0.0), scale.z,   Type(0.0),
                     Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeTranslation(const Vector2T< Type >& translation)
{
    return MatrixT(Type(1.0), Type(0.0), Type(0.0), translation.x,
                   Type(0.0), Type(1.0), Type(0.0), translation.y,
                   Type(0.0), Type(0.0), Type(1.0), Type(0.0),
                   Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeTranslation(const Vector3T< Type >& translation)
{
    return MatrixT(Type(1.0), Type(0.0), Type(0.0), translation.x,
                   Type(0.0), Type(1.0), Type(0.0), translation.y,
                   Type(0.0), Type(0.0), Type(1.0), translation.z,
                   Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakePerspective(Type fovY, Type aspectRatio, Type zNear, Type zFar)
{
    Type yScale = Type(1.0) / Math::Tan(Math::DegToRad(fovY / Type(2.0)));
    Type xScale = yScale / aspectRatio;

    return MatrixT(xScale,    Type(0.0), Type(0.0),             Type(0.0),
                   Type(0.0), yScale,    Type(0.0),             Type(0.0),
                   Type(0.0), Type(0.0), zFar / (zFar - zNear), -zNear * zFar / (zFar - zNear),
                   Type(0.0), Type(0.0), Type(1.0),             Type(0.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeLookAt(const Vector3T< Type >& eye, const Vector3T< Type >& at, const Vector3T< Type >& up)
{
    Vector3T< Type > zAxis = Vector3T< Type >::Normalized(eye - at); // forward
    Vector3T< Type > xAxis = Vector3T< Type >::Normalized(Vector3T< Type >::CrossProduct(up, zAxis)); // right
    Vector3T< Type > yAxis = Vector3T< Type >::CrossProduct(xAxis, zAxis); // up
    zAxis *= Type(-1.0);
    yAxis *= Type(-1.0);

    return MatrixT< Type >(   xAxis.x,   xAxis.y,   xAxis.z,   -Vector3T< Type >::DotProduct(xAxis, eye),
                              yAxis.x,   yAxis.y,   yAxis.z,   -Vector3T< Type >::DotProduct(yAxis, eye),
                              zAxis.x,   zAxis.y,   zAxis.z,   -Vector3T< Type >::DotProduct(zAxis, eye),
                              Type(0.0), Type(0.0), Type(0.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeOrtho(Type left, Type right, Type bottom, Type top, Type zNear, Type zFar)
{
    MatrixT< Type > result;
    result[0][0] = Type(2.0) / (right - left);
    result[1][1] = Type(2.0) / (top - bottom);
    result[2][2] = -Type(2.0) / (zFar - zNear);
    result[3][0] = -(right + left) / (right - left);
    result[3][1] = -(top + bottom) / (top - bottom);
    result[3][2] = -(zFar + zNear) / (zFar - zNear);
    return result;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::MakeOrtho2D(Type left, Type right, Type bottom, Type top)
{
    return MakeOrtho(left, right, bottom, top, Type(-1.0), Type(1.0));
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Inverse(const MatrixT& matrix)
{
    return matrix.GetInverse();
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::Transpose(const MatrixT& matrix)
{
    return matrix.GetTranspose();
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT()
{
    this->m[0][0] = Type(1); this->m[1][0] = Type(0); this->m[2][0] = Type(0); this->m[3][0] = Type(0);
    this->m[0][1] = Type(0); this->m[1][1] = Type(1); this->m[2][1] = Type(0); this->m[3][1] = Type(0);
    this->m[0][2] = Type(0); this->m[1][2] = Type(0); this->m[2][2] = Type(1); this->m[3][2] = Type(0);
    this->m[0][3] = Type(0); this->m[1][3] = Type(0); this->m[2][3] = Type(0); this->m[3][3] = Type(1);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(const MatrixT& copy)
{
    this->m[0][0] = copy.m[0][0]; this->m[1][0] = copy.m[1][0]; this->m[2][0] = copy.m[2][0]; this->m[3][0] = copy.m[3][0];
    this->m[0][1] = copy.m[0][1]; this->m[1][1] = copy.m[1][1]; this->m[2][1] = copy.m[2][1]; this->m[3][1] = copy.m[3][1];
    this->m[0][2] = copy.m[0][2]; this->m[1][2] = copy.m[1][2]; this->m[2][2] = copy.m[2][2]; this->m[3][2] = copy.m[3][2];
    this->m[0][3] = copy.m[0][3]; this->m[1][3] = copy.m[1][3]; this->m[2][3] = copy.m[2][3]; this->m[3][3] = copy.m[3][3];
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(MatrixT&& move)
{
    this->m[0][0] = move.m[0][0]; this->m[1][0] = move.m[1][0]; this->m[2][0] = move.m[2][0]; this->m[3][0] = move.m[3][0];
    this->m[0][1] = move.m[0][1]; this->m[1][1] = move.m[1][1]; this->m[2][1] = move.m[2][1]; this->m[3][1] = move.m[3][1];
    this->m[0][2] = move.m[0][2]; this->m[1][2] = move.m[1][2]; this->m[2][2] = move.m[2][2]; this->m[3][2] = move.m[3][2];
    this->m[0][3] = move.m[0][3]; this->m[1][3] = move.m[1][3]; this->m[2][3] = move.m[2][3]; this->m[3][3] = move.m[3][3];
}
#endif

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m00, Type m10, Type m01, Type m11)
{
    this->m[0][0] =       m00; this->m[1][0] =       m10; this->m[2][0] = Type(0.0); this->m[3][0] = Type(0.0);
    this->m[0][1] =       m01; this->m[1][1] =       m11; this->m[2][1] = Type(0.0); this->m[3][1] = Type(0.0);
    this->m[0][2] = Type(0.0); this->m[1][2] = Type(0.0); this->m[2][2] = Type(1.0); this->m[3][2] = Type(0.0);
    this->m[0][3] = Type(0.0); this->m[1][3] = Type(0.0); this->m[2][3] = Type(0.0); this->m[3][3] = Type(1.0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m00, Type m10, Type m20, Type m01, Type m11, Type m21, Type m02, Type m12, Type m22)
{
    this->m[0][0] =       m00; this->m[1][0] =       m10; this->m[2][0] =       m20; this->m[3][0] = Type(0.0);
    this->m[0][1] =       m01; this->m[1][1] =       m11; this->m[2][1] =       m21; this->m[3][1] = Type(0.0);
    this->m[0][2] =       m02; this->m[1][2] =       m12; this->m[2][2] =       m22; this->m[3][2] = Type(0.0);
    this->m[0][3] = Type(0.0); this->m[1][3] = Type(0.0); this->m[2][3] = Type(0.0); this->m[3][3] = Type(1.0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(Type m00, Type m10, Type m20, Type m30, Type m01, Type m11, Type m21, Type m31, Type m02, Type m12, Type m22, Type m32, Type m03, Type m13, Type m23, Type m33)
{
    this->m[0][0] = m00; this->m[1][0] = m10; this->m[2][0] = m20; this->m[3][0] = m30;
    this->m[0][1] = m01; this->m[1][1] = m11; this->m[2][1] = m21; this->m[3][1] = m31;
    this->m[0][2] = m02; this->m[1][2] = m12; this->m[2][2] = m22; this->m[3][2] = m32;
    this->m[0][3] = m03; this->m[1][3] = m13; this->m[2][3] = m23; this->m[3][3] = m33;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::MatrixT(const QuaternionT< Type >& quaternion)
{
    this->m[0][0] = Type(1.0) - (Type(2.0) * Math::Sqr(quaternion.y) + Type(2.0) * Math::Sqr(quaternion.z));
    this->m[1][0] = Type(2.0) * quaternion.x * quaternion.y - Type(2.0) * quaternion.z * quaternion.w;
    this->m[2][0] = Type(2.0) * quaternion.x * quaternion.z + Type(2.0) * quaternion.y * quaternion.w;
    this->m[3][0] = Type(0.0);
    this->m[0][1] = Type(2.0) * quaternion.x * quaternion.y + Type(2.0) * quaternion.z * quaternion.w;
    this->m[1][1] = Type(1.0) - (Type(2.0) * Math::Sqr(quaternion.x) + Type(2.0) * Math::Sqr(quaternion.z));
    this->m[2][1] = Type(2.0) * quaternion.y * quaternion.z - Type(2.0) * quaternion.x * quaternion.w;
    this->m[3][1] = Type(0.0);
    this->m[0][2] = Type(2.0) * quaternion.x * quaternion.z - Type(2.0) * quaternion.y * quaternion.w;
    this->m[1][2] = Type(2.0) * quaternion.y * quaternion.z + Type(2.0) * quaternion.x * quaternion.w;
    this->m[2][2] = Type(1.0) - (Type(2.0) * Math::Sqr(quaternion.x) + Type(2.0) * Math::Sqr(quaternion.y));
    this->m[3][2] = Type(0.0);
    this->m[0][3] = Type(0.0);
    this->m[1][3] = Type(0.0);
    this->m[2][3] = Type(0.0);
    this->m[3][3] = Type(1.0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >::~MatrixT()
{
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator=(const MatrixT& operand)
{
    this->m[0][0] = operand.m[0][0]; this->m[1][0] = operand.m[1][0]; this->m[2][0] = operand.m[2][0]; this->m[3][0] = operand.m[3][0];
    this->m[0][1] = operand.m[0][1]; this->m[1][1] = operand.m[1][1]; this->m[2][1] = operand.m[2][1]; this->m[3][1] = operand.m[3][1];
    this->m[0][2] = operand.m[0][2]; this->m[1][2] = operand.m[1][2]; this->m[2][2] = operand.m[2][2]; this->m[3][2] = operand.m[3][2];
    this->m[0][3] = operand.m[0][3]; this->m[1][3] = operand.m[1][3]; this->m[2][3] = operand.m[2][3]; this->m[3][3] = operand.m[3][3];
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type >& Jatta::MatrixT< Type >::operator=(const QuaternionT< Type >& operand)
{
    return *this = MatrixT(operand);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::MatrixT< Type >::operator==(const MatrixT& operand)
{
    return (m[0][0] == operand.m[0][0] &&
            m[1][0] == operand.m[1][0] &&
            m[2][0] == operand.m[2][0] &&
            m[3][0] == operand.m[3][0] &&
            m[0][1] == operand.m[0][1] &&
            m[1][1] == operand.m[1][1] &&
            m[2][1] == operand.m[2][1] &&
            m[3][1] == operand.m[3][1] &&
            m[0][2] == operand.m[0][2] &&
            m[1][2] == operand.m[1][2] &&
            m[2][2] == operand.m[2][2] &&
            m[3][2] == operand.m[3][2] &&
            m[0][3] == operand.m[0][3] &&
            m[1][3] == operand.m[1][3] &&
            m[2][3] == operand.m[2][3] &&
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
    return MatrixT(this->m[0][0] * operand.m[0][0] + this->m[0][1] * operand.m[1][0] + this->m[0][2] * operand.m[2][0] + this->m[0][3] * operand.m[3][0],
                   this->m[1][0] * operand.m[0][0] + this->m[1][1] * operand.m[1][0] + this->m[1][2] * operand.m[2][0] + this->m[1][3] * operand.m[3][0],
                   this->m[2][0] * operand.m[0][0] + this->m[2][1] * operand.m[1][0] + this->m[2][2] * operand.m[2][0] + this->m[2][3] * operand.m[3][0],
                   this->m[3][0] * operand.m[0][0] + this->m[3][1] * operand.m[1][0] + this->m[3][2] * operand.m[2][0] + this->m[3][3] * operand.m[3][0],
                   this->m[0][0] * operand.m[0][1] + this->m[0][1] * operand.m[1][1] + this->m[0][2] * operand.m[2][1] + this->m[0][3] * operand.m[3][1],
                   this->m[1][0] * operand.m[0][1] + this->m[1][1] * operand.m[1][1] + this->m[1][2] * operand.m[2][1] + this->m[1][3] * operand.m[3][1],
                   this->m[2][0] * operand.m[0][1] + this->m[2][1] * operand.m[1][1] + this->m[2][2] * operand.m[2][1] + this->m[2][3] * operand.m[3][1],
                   this->m[3][0] * operand.m[0][1] + this->m[3][1] * operand.m[1][1] + this->m[3][2] * operand.m[2][1] + this->m[3][3] * operand.m[3][1],
                   this->m[0][0] * operand.m[0][2] + this->m[0][1] * operand.m[1][2] + this->m[0][2] * operand.m[2][2] + this->m[0][3] * operand.m[3][2],
                   this->m[1][0] * operand.m[0][2] + this->m[1][1] * operand.m[1][2] + this->m[1][2] * operand.m[2][2] + this->m[1][3] * operand.m[3][2],
                   this->m[2][0] * operand.m[0][2] + this->m[2][1] * operand.m[1][2] + this->m[2][2] * operand.m[2][2] + this->m[2][3] * operand.m[3][2],
                   this->m[3][0] * operand.m[0][2] + this->m[3][1] * operand.m[1][2] + this->m[3][2] * operand.m[2][2] + this->m[3][3] * operand.m[3][2],
                   this->m[0][0] * operand.m[0][3] + this->m[0][1] * operand.m[1][3] + this->m[0][2] * operand.m[2][3] + this->m[0][3] * operand.m[3][3],
                   this->m[1][0] * operand.m[0][3] + this->m[1][1] * operand.m[1][3] + this->m[1][2] * operand.m[2][3] + this->m[1][3] * operand.m[3][3],
                   this->m[2][0] * operand.m[0][3] + this->m[2][1] * operand.m[1][3] + this->m[2][2] * operand.m[2][3] + this->m[2][3] * operand.m[3][3],
                   this->m[3][0] * operand.m[0][3] + this->m[3][1] * operand.m[1][3] + this->m[3][2] * operand.m[2][3] + this->m[3][3] * operand.m[3][3]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::operator*(Type operand) const
{
    return MatrixT(this->m[0][0] * operand, this->m[1][0] * operand, this->m[2][0] * operand, this->m[3][0] * operand,
                   this->m[0][1] * operand, this->m[1][1] * operand, this->m[2][1] * operand, this->m[3][1] * operand,
                   this->m[0][2] * operand, this->m[1][2] * operand, this->m[2][2] * operand, this->m[3][2] * operand,
                   this->m[0][3] * operand, this->m[1][3] * operand, this->m[2][3] * operand, this->m[3][3] * operand);
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
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Set(Type m00, Type m10, Type m01, Type m11)
{
    this->m[0][0] =       m00; this->m[1][0] =       m10; this->m[2][0] = Type(0.0); this->m[3][0] = Type(0.0);
    this->m[0][1] =       m01; this->m[1][1] =       m11; this->m[2][1] = Type(0.0); this->m[3][1] = Type(0.0);
    this->m[0][2] = Type(0.0); this->m[1][2] = Type(0.0); this->m[2][2] = Type(1.0); this->m[3][2] = Type(0.0);
    this->m[0][3] = Type(0.0); this->m[1][3] = Type(0.0); this->m[2][3] = Type(0.0); this->m[3][3] = Type(1.0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Set(Type m00, Type m10, Type m20, Type m01, Type m11, Type m21, Type m02, Type m12, Type m22)
{
    this->m[0][0] =       m00; this->m[1][0] =       m10; this->m[2][0] =       m20; this->m[3][0] = Type(0.0);
    this->m[0][1] =       m01; this->m[1][1] =       m11; this->m[2][1] =       m21; this->m[3][1] = Type(0.0);
    this->m[0][2] =       m02; this->m[1][2] =       m12; this->m[2][2] =       m22; this->m[3][2] = Type(0.0);
    this->m[0][3] = Type(0.0); this->m[1][3] = Type(0.0); this->m[2][3] = Type(0.0); this->m[3][3] = Type(1.0);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Set(Type m00, Type m10, Type m20, Type m30, Type m01, Type m11, Type m21, Type m31, Type m02, Type m12, Type m22, Type m32, Type m03, Type m13, Type m23, Type m33)
{
    this->m[0][0] = m00; this->m[1][0] = m10; this->m[2][0] = m20; this->m[3][0] = m30;
    this->m[0][1] = m01; this->m[1][1] = m11; this->m[2][1] = m21; this->m[3][1] = m31;
    this->m[0][2] = m02; this->m[1][2] = m12; this->m[2][2] = m22; this->m[3][2] = m32;
    this->m[0][3] = m03; this->m[1][3] = m13; this->m[2][3] = m23; this->m[3][3] = m33;
}

/** @details The below comment shows how the matrix is stored internally.
 *  @code
 *  // Matrix stored in memory as:
 *  // +--         --+
 *  // | 00 04 08 12 |
 *  // | 01 05 09 13 |
 *  // | 02 06 10 14 |
 *  // | 03 07 11 15 |
 *  // +--         --+
 *  //
 *  // 2D matrix mapping (column, row):
 *  // +--                   --+
 *  // | 0,0   1,0   2,0   3,0 |
 *  // | 0,1   1,1   2,1   3,1 |
 *  // | 0,2   1,2   2,2   3,2 |
 *  // | 0,3   1,3   2,3   3,3 |
 *  // +--                   --+
 *  @endcode
 *  @returns Pointer to raw data.
 */
template< typename Type >
_JATTA_INLINE_IMPLEMENT Type* Jatta::MatrixT< Type >::GetData() const
{
    return (Type*)m;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Invert()
{
    *this = GetInverse();
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::MatrixT< Type >::Transpose()
{
    *this = GetTranspose();
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::GetInverse() const
{
    MatrixT< Type > result;
    result.m[0][0] = m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] - m[1][3] * m[2][2] * m[3][1];
    result.m[0][1] = m[0][1] * m[2][3] * m[3][2] + m[0][2] * m[2][1] * m[3][3] + m[0][3] * m[2][2] * m[3][1] - m[0][1] * m[2][2] * m[3][3] - m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][1] * m[3][2];
    result.m[0][2] = m[0][1] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][1] + m[0][3] * m[1][1] * m[3][2] - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3] - m[0][3] * m[1][2] * m[3][1];
    result.m[0][3] = m[0][1] * m[1][3] * m[2][2] + m[0][2] * m[1][1] * m[2][3] + m[0][3] * m[1][2] * m[2][1] - m[0][1] * m[1][2] * m[2][3] - m[0][2] * m[1][3] * m[2][1] - m[0][3] * m[1][1] * m[2][2];
    result.m[1][0] = m[1][0] * m[2][3] * m[3][2] + m[1][2] * m[2][0] * m[3][3] + m[1][3] * m[2][2] * m[3][0] - m[1][0] * m[2][2] * m[3][3] - m[1][2] * m[2][3] * m[3][0] - m[1][3] * m[2][0] * m[3][2];
    result.m[1][1] = m[0][0] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][2] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] - m[0][3] * m[2][2] * m[3][0];
    result.m[1][2] = m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] + m[0][3] * m[1][2] * m[3][0] - m[0][0] * m[1][2] * m[3][3] - m[0][2] * m[1][3] * m[3][0] - m[0][3] * m[1][0] * m[3][2];
    result.m[1][3] = m[0][0] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][2] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] - m[0][3] * m[1][2] * m[2][0];
    result.m[2][0] = m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] - m[1][3] * m[2][1] * m[3][0];
    result.m[2][1] = m[0][0] * m[2][3] * m[3][1] + m[0][1] * m[2][0] * m[3][3] + m[0][3] * m[2][1] * m[3][0] - m[0][0] * m[2][1] * m[3][3] - m[0][1] * m[2][3] * m[3][0] - m[0][3] * m[2][0] * m[3][1];
    result.m[2][2] = m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][1] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] - m[0][3] * m[1][1] * m[3][0];
    result.m[2][3] = m[0][0] * m[1][3] * m[2][1] + m[0][1] * m[1][0] * m[2][3] + m[0][3] * m[1][1] * m[2][0] - m[0][0] * m[1][1] * m[2][3] - m[0][1] * m[1][3] * m[2][0] - m[0][3] * m[1][0] * m[2][1];
    result.m[3][0] = m[1][0] * m[2][2] * m[3][1] + m[1][1] * m[2][0] * m[3][2] + m[1][2] * m[2][1] * m[3][0] - m[1][0] * m[2][1] * m[3][2] - m[1][1] * m[2][2] * m[3][0] - m[1][2] * m[2][0] * m[3][1];
    result.m[3][1] = m[0][0] * m[2][1] * m[3][2] + m[0][1] * m[2][2] * m[3][0] + m[0][2] * m[2][0] * m[3][1] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] - m[0][2] * m[2][1] * m[3][0];
    result.m[3][2] = m[0][0] * m[1][2] * m[3][1] + m[0][1] * m[1][0] * m[3][2] + m[0][2] * m[1][1] * m[3][0] - m[0][0] * m[1][1] * m[3][2] - m[0][1] * m[1][2] * m[3][0] - m[0][2] * m[1][0] * m[3][1];
    result.m[3][3] = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] - m[0][2] * m[1][1] * m[2][0];
    result /= GetDeterminant();
    return result;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::MatrixT< Type > Jatta::MatrixT< Type >::GetTranspose() const
{
    MatrixT< Type > result;
    result.m[0][0] = m[0][0]; result.m[1][0] = m[0][1]; result.m[2][0] = m[0][2]; result.m[3][0] = m[0][3];
    result.m[0][1] = m[1][0]; result.m[1][1] = m[1][1]; result.m[2][1] = m[1][2]; result.m[3][1] = m[1][3];
    result.m[0][2] = m[2][0]; result.m[1][2] = m[2][1]; result.m[2][2] = m[2][2]; result.m[3][2] = m[2][3];
    result.m[0][3] = m[3][0]; result.m[1][3] = m[3][1]; result.m[2][3] = m[3][2]; result.m[3][3] = m[3][3];
    return result;
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
