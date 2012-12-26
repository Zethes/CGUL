#include "Image.h"
#include "Color.h"

Jatta::Image::Image()
{
    _JATTA_DEBUG_LN("Image, Default");
    this->colors = nullptr;
    this->width = 0;
    this->height = 0;
}

Jatta::Image::Image(Color* colors, unsigned int width, unsigned int height)
{
    _JATTA_DEBUG_LN("Image, Parameterized " << width << ", " << height);
    this->colors = colors;
    this->width = width;
    this->height = height;
}

Jatta::Image::Image(const Image& copy)
{
    _JATTA_DEBUG_LN("Image, Copy");
    this->width = copy.width;
    this->height = copy.height;
    this->colors = (Color*)new char[this->width * this->height * 4];
    memcpy(this->colors, copy.colors, this->width * this->height * 4);
}

Jatta::Image::Image(Image&& move)
{
    _JATTA_DEBUG_LN("Image, Move");
    this->width = move.width;
    this->height = move.height;
    this->colors = move.colors;
    move.width = 0;
    move.height = 0;
    move.colors = nullptr;
}

Jatta::Image::~Image()
{
    //delete[] colors;
}

unsigned char* Jatta::Image::getData()
{
    return (unsigned char*)colors;
}

const unsigned char* Jatta::Image::getData() const
{
    return (const unsigned char*)colors;
}

unsigned int Jatta::Image::getWidth() const
{
    return width;
}

unsigned int Jatta::Image::getHeight() const
{
    return height;
}