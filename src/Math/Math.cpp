#include "Math.h"
#include <cmath>

float Jatta::Math::cos(float x)
{
    return std::cos(x);
}

float Jatta::Math::sin(float x)
{
    return std::sin(x);
}

float Jatta::Math::tan(float x)
{
    return std::tan(x);
}

float Jatta::Math::degToRad(float deg)
{
    return deg / 180.0f * pi;
}

float Jatta::Math::min(float a, float b)
{
    return (a < b ? a : b);
}

float Jatta::Math::max(float a, float b)
{
    return (a > b ? a : b);
}

float Jatta::Math::floor(float x)
{
    return std::floor(x);
}
