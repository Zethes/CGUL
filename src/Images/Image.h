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
        Image();
        Image(Color* colors, unsigned int width, unsigned int height);
        Image(const Image& copy);
        Image(Image&& move);
        ~Image();

        static bool isPng(const std::string& fileName);

        bool loadPng(const std::string& fileName);
        bool savePng(const std::string& fileName);

        const unsigned char* getData();
        unsigned int getWidth();
        unsigned int getHeight();
    };
}

#include "../External/Undefines.h"