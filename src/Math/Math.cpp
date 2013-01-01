#include "Math.h"
#include <cmath>

_JATTA_EXPORT float Jatta::Math::cos(float x)
{
    return std::cos(x);
}

_JATTA_EXPORT float Jatta::Math::sin(float x)
{
    return std::sin(x);
}

_JATTA_EXPORT float Jatta::Math::tan(float x)
{
    return std::tan(x);
}

_JATTA_EXPORT float Jatta::Math::degToRad(float deg)
{
    return deg / 180.0f * pi;
}

_JATTA_EXPORT float Jatta::Math::min(float a, float b)
{
    return (a < b ? a : b);
}

_JATTA_EXPORT float Jatta::Math::max(float a, float b)
{
    return (a > b ? a : b);
}

_JATTA_EXPORT float Jatta::Math::floor(float x)
{
    return std::floor(x);
}

_JATTA_EXPORT float Jatta::Math::mod(float x, float div)
{
    return x - Math::floor(x / 360.0f) * 360.0f;
}