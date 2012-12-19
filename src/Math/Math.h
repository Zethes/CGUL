#pragma once

namespace Jatta
{
    namespace Math
    {
        const float pi = 3.14159f;

        float cos(float x);
        float sin(float x);
        float tan(float x);

        float degToRad(float deg);

        float min(float a, float b);
        float max(float a, float b);
    }
}