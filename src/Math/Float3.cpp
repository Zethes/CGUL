#include "Float3.h"

#include <cmath>

float Jatta::Float3::dotProduct(const Float3& valueA, const Float3& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z);
}

Jatta::Float3 Jatta::Float3::crossProduct(const Float3& valueA, const Float3& valueB)
{
    return Float3(valueA.y * valueB.z - valueA.z * valueB.y, valueA.z * valueB.x - valueA.x * valueB.z, valueA.x * valueB.y - valueA.y * valueB.x);
}

Jatta::Float3 Jatta::Float3::normalized(const Float3& value)
{
    float inverseMagnitude = 1.0f / value.getMagnitude();
    return Float3(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude);
}

Jatta::Float3::Float3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Jatta::Float3::Float3(const Float3& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

Jatta::Float3::Float3(float value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

Jatta::Float3::Float3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Jatta::Float3::normalize()
{
    float inverseMagnitude = 1.0f / getMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
}

Jatta::Float3 Jatta::Float3::operator-() const
{
    return Float3(-this->x, -this->y, -this->z);
}

Jatta::Float3 Jatta::Float3::operator+(const Float3& operand) const
{
    return Float3(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

Jatta::Float3& Jatta::Float3::operator+=(const Float3& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    return *this;
}

Jatta::Float3 Jatta::Float3::operator-(const Float3& operand) const
{
    return Float3(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

Jatta::Float3& Jatta::Float3::operator-=(const Float3& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    return *this;
}

Jatta::Float3 Jatta::Float3::operator*(float operand) const
{
    return Float3(this->x * operand, this->y * operand, this->z * operand);
}

Jatta::Float3& Jatta::Float3::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    return *this;
}

float Jatta::Float3::getMagnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}