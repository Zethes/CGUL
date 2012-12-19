#include "Matrix.h"
#include "Math.h"
#include "Float2.h"
#include "Float3.h"

const Jatta::Matrix Jatta::Matrix::identity(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

Jatta::Matrix Jatta::Matrix::makeRotation(float angle)
{
    return Matrix(Math::cos(angle),  Math::sin(angle), 0, 0,
                  -Math::sin(angle), Math::cos(angle), 0, 0,
                  0,                0,                 1, 0,
                  0,                0,                 0, 1);
}

Jatta::Matrix Jatta::Matrix::makeRotationX(float angle)
{
    return Matrix(1, 0,          0,           0,
                  0, Math::cos(angle),  Math::sin(angle), 0,
                  0, -Math::sin(angle), Math::cos(angle), 0,
                  0, 0,                0,                 1);
}

Jatta::Matrix Jatta::Matrix::makeRotationY(float angle)
{
    return Matrix(Math::cos(angle), 0, -Math::sin(angle), 0,
                  0,                1, 0,                 0,
                  Math::sin(angle), 0, Math::cos(angle),  0,
                  0,                0, 0,                 1);
}

Jatta::Matrix Jatta::Matrix::makeRotationZ(float angle)
{
    return Matrix(Math::cos(angle),  Math::sin(angle), 0, 0,
                  -Math::sin(angle), Math::cos(angle), 0, 0,
                  0,                0,                 1, 0,
                  0,                0,                 0, 1);
}

Jatta::Matrix Jatta::Matrix::makeScaling(Float2 scale)
{
    return Matrix(scale.x, 0,       0, 0,
                  0,       scale.y, 0, 0,
                  0,       0,       1, 0,
                  0,       0,       0, 1);
}

Jatta::Matrix Jatta::Matrix::makeScaling(Float3 scale)
{
    return Matrix(scale.x, 0,       0,       0,
                  0,       scale.y, 0,       0,
                  0,       0,       scale.z, 0,
                  0,       0,       0,       1);
}

Jatta::Matrix Jatta::Matrix::makeTranslation(Float2 translation)
{
    return Matrix(1,             0,             0, 0,
                  0,             1,             0, 0,
                  0,             0,             1, 0,
                  translation.x, translation.y, 0, 1);
}

Jatta::Matrix Jatta::Matrix::makeTranslation(Float3 translation)
{
    return Matrix(1,             0,             0,             0,
                  0,             1,             0,             0,
                  0,             0,             1,             0,
                  translation.x, translation.y, translation.z, 1);
}

Jatta::Matrix Jatta::Matrix::makePerspective(float fovY, float aspectRatio, float zNear, float zFar)
{
    float yScale = 1.0f / Math::tan(Math::degToRad(fovY / 2.0f));
    float xScale = yScale / aspectRatio;
    return Matrix(xScale, 0,      0,                              0,
                  0,      yScale, 0,                              0,
                  0,      0,      zFar / (zFar - zNear),          1,
                  0,      0,      -zNear * zFar / (zFar - zNear), 0);
}

Jatta::Matrix Jatta::Matrix::makeLookAt(const Float3& eye, const Float3& at, const Float3& up)
{
    Float3 zAxis = Float3::normalized(eye - at); // forward
    Float3 xAxis = Float3::normalized(Float3::crossProduct(up, zAxis)); // right
    Float3 yAxis = Float3::crossProduct(xAxis, zAxis); // up
    zAxis *= -1;
    yAxis *= -1;

    return Matrix(xAxis.x,                          yAxis.x,                          zAxis.x,                         0,
                  xAxis.y,                          yAxis.y,                          zAxis.y,                         0,
                  xAxis.z,                          yAxis.z,                          zAxis.z,                         0,
                  -Float3::dotProduct(xAxis, eye),  -Float3::dotProduct(yAxis, eye),  -Float3::dotProduct(zAxis, eye), 1);
}

Jatta::Matrix Jatta::Matrix::makeOrtho(int right, int top, int left, int bottom)
{
  Float3 t((left + right) / (float)(left - right), (top + bottom) / (float)(top - bottom), 0);

  return Matrix(2.0f / (left - right), 0,                     0,    0,
                0,                     2.0f / (top - bottom), 0,    0,
                0,                     0,                     -1,   0,
                -t.x,                  -t.y,                  -t.z, 1);// * Matrix::makeScaling(Vector3(1, -1, 1));
}

Jatta::Matrix::Matrix()
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

Jatta::Matrix::Matrix(const Matrix& copy)
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

Jatta::Matrix::Matrix(Matrix&& move)
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

Jatta::Matrix::Matrix(float m11, float m12, float m21, float m22)
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

Jatta::Matrix::Matrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
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

Jatta::Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
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

Jatta::Matrix::~Matrix()
{
}

Jatta::Matrix& Jatta::Matrix::operator=(const Matrix& operand)
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
}

Jatta::Matrix Jatta::Matrix::operator*(const Matrix& operand) const
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

float* Jatta::Matrix::getData() const
{
    return (float*)m;
}

#include <iostream> // TODO: remove iostream
void Jatta::Matrix::debug() const
{
    for (const float* herp = (float*)m; herp <= &m[3][3]; herp++)
    {
        std::cout << *herp << std::endl;
    }
}