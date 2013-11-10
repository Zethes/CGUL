/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Matrix.h"
#include "Math.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Quaternion.h"

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::Identity()
{
	return Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeRotation(float angle)
{
    return Matrix(Math::Cos(angle),  Math::Sin(angle), 0, 0,
                  -Math::Sin(angle), Math::Cos(angle), 0, 0,
                  0,                0,                 1, 0,
                  0,                0,                 0, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeRotationX(float angle)
{
    return Matrix(1, 0,          0,           0,
                  0, Math::Cos(angle),  Math::Sin(angle), 0,
                  0, -Math::Sin(angle), Math::Cos(angle), 0,
                  0, 0,                0,                 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeRotationY(float angle)
{
    return Matrix(Math::Cos(angle), 0, -Math::Sin(angle), 0,
                  0,                1, 0,                 0,
                  Math::Sin(angle), 0, Math::Cos(angle),  0,
                  0,                0, 0,                 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeRotationZ(float angle)
{
    return Matrix(Math::Cos(angle),  Math::Sin(angle), 0, 0,
                  -Math::Sin(angle), Math::Cos(angle), 0, 0,
                  0,                0,                 1, 0,
                  0,                0,                 0, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeRotation(const Quaternion& quaternion)
{
    return Matrix(quaternion);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeScaling(Vector2 scale)
{
    return Matrix(scale.x, 0,       0, 0,
                  0,       scale.y, 0, 0,
                  0,       0,       1, 0,
                  0,       0,       0, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeScaling(Vector3 scale)
{
    return Matrix(scale.x, 0,       0,       0,
                  0,       scale.y, 0,       0,
                  0,       0,       scale.z, 0,
                  0,       0,       0,       1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeTranslation(Vector2 translation)
{
    return Matrix(1,             0,             0, 0,
                  0,             1,             0, 0,
                  0,             0,             1, 0,
                  translation.x, translation.y, 0, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeTranslation(Vector3 translation)
{
    return Matrix(1,             0,             0,             0,
                  0,             1,             0,             0,
                  0,             0,             1,             0,
                  translation.x, translation.y, translation.z, 1);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakePerspective(float fovY, float aspectRatio, float zNear, float zFar)
{
    float yScale = 1.0f / Math::Tan(Math::DegToRad(fovY / 2.0f));
    float xScale = yScale / aspectRatio;
    return Matrix(xScale, 0,      0,                              0,
                  0,      yScale, 0,                              0,
                  0,      0,      zFar / (zFar - zNear),          1,
                  0,      0,      -zNear * zFar / (zFar - zNear), 0);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeLookAt(const Vector3& eye, const Vector3& at, const Vector3& up)
{
    Vector3 zAxis = Vector3::Normalized(eye - at); // forward
    Vector3 xAxis = Vector3::Normalized(Vector3::CrossProduct(up, zAxis)); // right
    Vector3 yAxis = Vector3::CrossProduct(xAxis, zAxis); // up
    zAxis *= -1;
    yAxis *= -1;

    return Matrix(xAxis.x,                          yAxis.x,                          zAxis.x,                         0,
                  xAxis.y,                          yAxis.y,                          zAxis.y,                         0,
                  xAxis.z,                          yAxis.z,                          zAxis.z,                         0,
                  -Vector3::DotProduct(xAxis, eye),  -Vector3::DotProduct(yAxis, eye),  -Vector3::DotProduct(zAxis, eye), 1);
}

/*_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeOrtho(int left, int right, int bottom, int top)
{
  Vector3 t((right + left) / (float)(right - left), (top + bottom) / (float)(top - bottom), 0);

  return Matrix(2.0f / (right - left), 0,                     0,    0,
                0,                     2.0f / (top - bottom), 0,    0,
                0,                     0,                     -1,   0,
                -t.x,                  -t.y,                  -t.z, 1);// * Matrix::makeScaling(Vector3(1, -1, 1));
}*/

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::MakeOrtho(int left, int right, int bottom, int top)
{
  /*Vector3 t((right + left) / (float)(right - left), (top + bottom) / (float)(top - bottom), 0);

  return Matrix(2.0f / (right - left), 0,                     0,    -t.x,
                0,                     2.0f / (top - bottom), 0,    -t.y,
                0,                     0,                     -1,   -t.z,
                0,                     0,                      0,  1);// * Matrix::makeScaling(Vector3(1, -1, 1));*/

    Matrix ret = Identity();
    /*ret.m[0][0] = Float32(2) / (right - left);
    ret.m[1][1] = Float32(2) / (top - bottom);
    ret.m[2][2] = - Float32(2) / (1 - (-1));
    ret.m[3][0] = - (right + left) / (right - left);
    ret.m[3][1] = - (top + bottom) / (top - bottom);
    ret.m[3][2] = - (1 + (-1)) / (1 - (-1));*/
    ret.m[0][0] = Float32(2) / (right - left);
    ret.m[1][1] = Float32(2) / (top - bottom);
    ret.m[2][2] = - Float32(2) / ((1) - (-1));
    ret.m[3][0] = - Float32((right + left) / (right - left));
    ret.m[3][1] = - Float32((top + bottom) / (top - bottom));
    ret.m[3][2] = - Float32((1) + (-1)) / Float32((1) - (-1));
    return ret;
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::Inverse(const Matrix& matrix)
{
    Matrix result;
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

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::Transpose(const Matrix& matrix)
{
    Matrix result;
    result.m[0][0] = matrix.m[0][0]; result.m[1][0] = matrix.m[0][1]; result.m[2][0] = matrix.m[0][2]; result.m[3][0] = matrix.m[0][3];
    result.m[0][1] = matrix.m[1][0]; result.m[1][1] = matrix.m[1][1]; result.m[2][1] = matrix.m[1][2]; result.m[3][1] = matrix.m[1][3];
    result.m[0][2] = matrix.m[2][0]; result.m[1][2] = matrix.m[2][1]; result.m[2][2] = matrix.m[2][2]; result.m[3][2] = matrix.m[2][3];
    result.m[0][3] = matrix.m[3][0]; result.m[1][3] = matrix.m[3][1]; result.m[2][3] = matrix.m[3][2]; result.m[3][3] = matrix.m[3][3];
    return result;
}

_JATTA_EXPORT Jatta::Matrix::Matrix()
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

_JATTA_EXPORT Jatta::Matrix::Matrix(const Matrix& copy)
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
_JATTA_EXPORT Jatta::Matrix::Matrix(Matrix&& move)
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

_JATTA_EXPORT Jatta::Matrix::Matrix(float m11, float m12, float m21, float m22)
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

_JATTA_EXPORT Jatta::Matrix::Matrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
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

_JATTA_EXPORT Jatta::Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
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

_JATTA_EXPORT Jatta::Matrix::Matrix(const Quaternion& quaternion)
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

_JATTA_EXPORT Jatta::Matrix::~Matrix()
{
}

_JATTA_EXPORT Jatta::Matrix& Jatta::Matrix::operator=(const Matrix& operand)
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

_JATTA_EXPORT Jatta::Matrix& Jatta::Matrix::operator=(const Quaternion& operand)
{
    return *this = Matrix(operand);
}

_JATTA_EXPORT Jatta::Float32* Jatta::Matrix::operator[](UInt32 index)
{
    return m[index];
}

_JATTA_EXPORT const Jatta::Float32* Jatta::Matrix::operator[](UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::operator*(const Matrix& operand) const
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
_JATTA_EXPORT Jatta::Matrix Jatta::Matrix::operator*(Float32 operand) const
{
    return Matrix(  this->m[0][0]*operand, this->m[0][1]*operand, this->m[0][2]*operand, this->m[0][3]*operand,
                    this->m[1][0]*operand, this->m[1][1]*operand, this->m[1][2]*operand, this->m[1][3]*operand,
                    this->m[2][0]*operand, this->m[2][1]*operand, this->m[2][2]*operand, this->m[2][3]*operand,
                    this->m[3][0]*operand, this->m[3][1]*operand, this->m[3][2]*operand, this->m[3][3]*operand);
}

_JATTA_EXPORT Jatta::Matrix& Jatta::Matrix::operator*=(Float32 operand)
{
    m[0][0] *= operand; m[1][0] *= operand; m[2][0] *= operand; m[3][0] *= operand;
    m[0][1] *= operand; m[1][1] *= operand; m[2][1] *= operand; m[3][1] *= operand;
    m[0][2] *= operand; m[1][2] *= operand; m[2][2] *= operand; m[3][2] *= operand;
    m[0][3] *= operand; m[1][3] *= operand; m[2][3] *= operand; m[3][3] *= operand;
    return *this;
}

_JATTA_EXPORT Jatta::Matrix& Jatta::Matrix::operator/=(Float32 operand)
{
    Float32 inverse = 1 / operand;
    m[0][0] *= inverse; m[1][0] *= inverse; m[2][0] *= inverse; m[3][0] *= inverse;
    m[0][1] *= inverse; m[1][1] *= inverse; m[2][1] *= inverse; m[3][1] *= inverse;
    m[0][2] *= inverse; m[1][2] *= inverse; m[2][2] *= inverse; m[3][2] *= inverse;
    m[0][3] *= inverse; m[1][3] *= inverse; m[2][3] *= inverse; m[3][3] *= inverse;
    return *this;
}

_JATTA_EXPORT void Jatta::Matrix::Invert()
{
    *this = Inverse(*this);
}

_JATTA_EXPORT void Jatta::Matrix::Transpose()
{
    *this = Transpose(*this);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Matrix::GetDeterminant() const
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

_JATTA_EXPORT float* Jatta::Matrix::GetData() const
{
    return (float*)m;
}

_JATTA_EXPORT bool Jatta::Matrix::IsReflexive() const
{
    return (m[0][0] == m[1][1] && m[2][2] == m[3][3] && m[0][0] == m[2][2]);
}
_JATTA_EXPORT bool Jatta::Matrix::IsSymmetric() const
{
    //A = Transpose(A);

    return (*this == Transpose(*this));
}
_JATTA_EXPORT bool Jatta::Matrix::IsAntisymmetric() const
{
    //A = -Transpose(A);

    return (*this == Transpose(*this) * Float32(-1));
}
