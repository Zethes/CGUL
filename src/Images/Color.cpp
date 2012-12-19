#include "Color.h"

Jatta::Color::Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;
}

Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 255;
}

Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}