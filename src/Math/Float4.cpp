#include "Float4.h"

#include <cmath>

Jatta::Float4::Float4()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Jatta::Float4::Float4(const Float4& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

Jatta::Float4::Float4(float value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

Jatta::Float4::Float4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

void Jatta::Float4::normalize()
{
    float inverseMagnitude = 1.0f / getMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
    z *= inverseMagnitude;
    w *= inverseMagnitude;
}

float Jatta::Float4::getMagnitude()
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}