//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Color;
    
    struct Image
    {
    protected:
        Color* colors;
        unsigned int width, height;
    public:
        _JATTA_EXPORT Image();
        _JATTA_EXPORT Image(Color* colors, unsigned int width, unsigned int height);
        _JATTA_EXPORT Image(const Image& copy);
        _JATTA_EXPORT Image(Image&& move);
        _JATTA_EXPORT ~Image();

        _JATTA_EXPORT static bool isPng(const std::string& fileName);

        _JATTA_EXPORT bool loadPng(const std::string& fileName);
        _JATTA_EXPORT bool savePng(const std::string& fileName);

        _JATTA_EXPORT unsigned char* getData();
        _JATTA_EXPORT const unsigned char* getData() const;
        _JATTA_EXPORT unsigned int getWidth() const;
        _JATTA_EXPORT unsigned int getHeight() const;
    };
}

#include "../External/Undefines.h"