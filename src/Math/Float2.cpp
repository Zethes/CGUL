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

Jatta::Float2 Jatta::Float2::operator+(const Float2& operand) const
{
    return Float2(x + operand.x, y + operand.y);
}

Jatta::Float2 Jatta::Float2::operator*(float operand) const
{
    return Float2(this->x * operand, this->y * operand);
}

Jatta::Float2& Jatta::Float2::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    return *this;
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