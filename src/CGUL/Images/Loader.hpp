// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Loader.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Images/Image.hpp"
#include "../Images/Format.hpp"
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    class Image;

    /** @brief Base class for image loaders.
     *  @todo Support PNG, TIF, DDS, BMP, JPEG, ICO, PPM
     */
    class ImageLoader
    {
        String name;
        String extension;
    public:
        _CGUL_EXPORT ImageLoader();
        _CGUL_EXPORT ImageLoader(const String& name, const String& extension);
        _CGUL_EXPORT virtual ~ImageLoader();

        _CGUL_EXPORT virtual bool CanLoad(const String& file) = 0;
        _CGUL_EXPORT virtual void Load(const String& file, Image* image) = 0;

        _CGUL_EXPORT virtual void Save(const String& file, const Image* image) const = 0;

        _CGUL_EXPORT String GetName();
        _CGUL_EXPORT String GetExtension();
    };
}

// Undefines
#include "../External/Undefines.hpp"
