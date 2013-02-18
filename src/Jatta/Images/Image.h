/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
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
        static const UInt32 UPSIDE_DOWN = 1;

        _JATTA_EXPORT Image();
        _JATTA_EXPORT Image(Color* colors, unsigned int width, unsigned int height);
        _JATTA_EXPORT Image(const Image& copy);
        _JATTA_EXPORT Image(Image&& move);
        _JATTA_EXPORT ~Image();

        _JATTA_EXPORT Jatta::Image& operator=(const Image& copy);
        _JATTA_EXPORT Jatta::Image& operator=(Image&& move);

        _JATTA_EXPORT bool Load(const Jatta::String& fileName, UInt32 flags = 0);
        _JATTA_EXPORT bool LoadFromMemory(const char* data, Jatta::UInt32 size, UInt32 flags = 0);

        _JATTA_EXPORT static bool IsBmp(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT static bool IsPng(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT static bool IsJpg(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT static bool IsDds(const char* data, Jatta::UInt32 size);

        _JATTA_EXPORT bool LoadPng(const char* data, Jatta::UInt32 size, UInt32 flags = 0);
        _JATTA_EXPORT bool SavePng(const Jatta::String& fileName);

        _JATTA_EXPORT bool LoadJpg(const char* data, Jatta::UInt32 size, UInt32 flags = 0);
        _JATTA_EXPORT bool SaveJpg(const Jatta::String& fileName);

        _JATTA_EXPORT bool LoadBmp(const char* data, Jatta::UInt32 size, UInt32 flags = 0);
        _JATTA_EXPORT bool SaveBmp(const Jatta::String& fileName, int bpp = 24, int hRes = 2835, int vRes = 2835);

        _JATTA_EXPORT bool LoadDds(const char* data, Jatta::UInt32 size, UInt32 flags);
        _JATTA_EXPORT bool SaveDds(const Jatta::String& fileName);

        _JATTA_EXPORT unsigned char* GetData();
        _JATTA_EXPORT const unsigned char* GetData() const;
        _JATTA_EXPORT unsigned int GetWidth() const;
        _JATTA_EXPORT unsigned int GetHeight() const;

        _JATTA_EXPORT void Free();
    };
}

#include "../External/Undefines.h"
