/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "ImageFormats.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A container containing the image data of a certain mipmap
     */
    class Mipmap
    {
        void* data;
        ImageFormat format;

        UInt32 width;
        UInt32 height;

        _JATTA_EXPORT bool IsValid();
    public:
        _JATTA_EXPORT Mipmap();
        _JATTA_EXPORT Mipmap(ImageFormat format, UInt32 width, UInt32 height, void* data);
        _JATTA_EXPORT ~Mipmap();

        _JATTA_EXPORT void Free();

        _JATTA_EXPORT const void* GetData();
        _JATTA_EXPORT ImageFormat GetFormat() const;
    };
}

#include "../External/Undefines.h"