// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mipmap.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "ImageFormats.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A container containing the image data of a certain mipmap
     */
    class Mipmap
    {
        void* data;
        ImageFormat format;

        UInt32 width;
        UInt32 height;

        // TODO: remove this? it's not used
        //_CGUL_EXPORT bool IsValid();
    public:
        _CGUL_EXPORT Mipmap();
        _CGUL_EXPORT Mipmap(ImageFormat format, UInt32 width, UInt32 height, void* data);
        _CGUL_EXPORT ~Mipmap();

        _CGUL_EXPORT void Free();

        _CGUL_EXPORT const void* GetData();
        _CGUL_EXPORT ImageFormat GetFormat() const;
    };
}

#include "../External/Undefines.hpp"
