#include "Image.h"
#include "Color.h"

Jatta::Image::Image()
{
    this->colors = nullptr;
    this->width = 0;
    this->height = 0;
}

Jatta::Image::Image(Color* colors, unsigned int width, unsigned int height)
{
    this->colors = colors;
    this->width = width;
    this->height = height;
}

Jatta::Image::Image(const Image& copy)
{
    this->width = copy.width;
    this->height = copy.height;
    this->colors = (Color*)new char[this->width * this->height * 4];
    memcpy(this->colors, copy.colors, this->width * this->height * 4);
}

Jatta::Image::Image(Image&& move)
{
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

const unsigned char* Jatta::Image::getData()
{
    return (const unsigned char*)colors;
}

unsigned int Jatta::Image::getWidth()
{
    return width;
}

unsigned int Jatta::Image::getHeight()
{
    return height;
}