#include "Image.h"

bool Jatta::Image::isPng(const std::string& fileName)
{
}

bool Jatta::Image::load(const std::string& fileName)
{
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