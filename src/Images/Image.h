/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

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

        _JATTA_EXPORT Jatta::Image& operator=(const Image& copy);
        _JATTA_EXPORT Jatta::Image& operator=(Image&& move);

        _JATTA_EXPORT static bool IsPng(const std::string& fileName);
        _JATTA_EXPORT static bool IsJpg(const std::string& fileName);

        _JATTA_EXPORT bool LoadPng(const std::string& fileName);
        _JATTA_EXPORT bool SavePng(const std::string& fileName);

        _JATTA_EXPORT bool LoadJpg(const std::string& fileName);
        _JATTA_EXPORT bool SaveJpg(const std::string& fileName);

        _JATTA_EXPORT unsigned char* GetData();
        _JATTA_EXPORT const unsigned char* GetData() const;
        _JATTA_EXPORT unsigned int GetWidth() const;
        _JATTA_EXPORT unsigned int GetHeight() const;

        _JATTA_EXPORT void Free();
    };
}

#include "../External/Undefines.h"
