#include "Float2.h"

#include <cmath>

Jatta::Float2::Float2()
{
    this->x = 0;
    this->y = 0;
}

Jatta::Float2::Float2(const Float2& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

Jatta::Float2::Float2(float value)
{
    this->x = value;
    this->y = value;
}

Jatta::Float2::Float2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Jatta::Float2::normalize()
{
    float inverseMagnitude = 1.0f / getMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
}

float Jatta::Float2::getMagnitude()
{
    return std::sqrt(x * x + y * y);
}