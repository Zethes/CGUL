#include "Random.h"
#include <ctime>
#include <cmath>

float Jatta::Random::uniformDist(float a, float b, float u)
{
    if (u < 0)
    {
        return a;
    }
    if (u > 1)
    {
        return b;
    }
    return u * (b - a) + a;
}

float Jatta::Random::exponentialDist(float beta, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u >= .99999)
    {
        u = .99999;
    }
    //return  -beta * std::log(u);
    return beta * std::log(-1 / (u - 1));
}

float Jatta::Random::weibullDist(float a, float b, float c, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u >= .99999)
    {
        u = .99999;
    }
    return b * std::pow(std::log(-1 / (u - 1)), 1 / c) + a;
}

float Jatta::Random::triangularDist(float xmin, float xmax, float c, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u > 1)
    {
        u = 1;
    }
    if (u < (c - xmin) / (xmax - xmin))
    {
        return sqrt(u * (xmin - xmax) * (xmin - c)) + xmin;
    }
    else
    {
        return xmax - std::sqrt((u - 1) * (xmin - xmax) * (xmax - c));
    }
}

float Jatta::Random::normal(float mean, float variance, float x)
{
    return (1 / std::sqrt(2 * 3.14159 * variance)) * std::exp(-(std::pow(x - mean, 2) / (2 * variance)));
}

Jatta::Random::Random()
{
    this->seed = (unsigned int)std::time(0);
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

Jatta::Random::Random(unsigned int seed)
{
    this->seed = seed;
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

Jatta::Random::Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus)
{
    this->seed = seed;
    this->multiplier = multiplier;
    this->addition = addition;
    this->modulus = modulus;
}

unsigned int Jatta::Random::getInteger()
{
    seed = (multiplier * seed + addition) % modulus;
    return seed;
}

float Jatta::Random::getDecimal()
{
    return getInteger() / float(modulus);
}

float Jatta::Random::getUniform(float a, float b)
{
    return getDecimal() * (b - a) + a;
}

float Jatta::Random::getExponential(float beta)
{
    return exponentialDist(beta, getDecimal());
}

float Jatta::Random::getWeibull(float a, float b, float c)
{
    return weibullDist(a, b, c, getDecimal());
}

float Jatta::Random::getNormal(float mean, float variance)
{
    float x;
    float u;
    do
    {
        x = Random::exponentialDist(1, getDecimal());
        u = getDecimal();
    }
    while (u < Random::normal(0, .2, x) / (2 * Random::exponentialDist(1, x)));
    return Random::normal(0, .2, x);
}