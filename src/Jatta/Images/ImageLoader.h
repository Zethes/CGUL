/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "ImageInfo.h"
#include "Image.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief Base class for image file loaders.
     *
     *  A class inherits from this class for each file format (PNG, BMP, etc.)
     */
    class ImageLoader
    {
    protected:
        Jatta::String file;
    public:
        _JATTA_EXPORT ImageLoader(const String& filename);  
        _JATTA_EXPORT ~ImageLoader();

        _JATTA_EXPORT Jatta::String GetFile() const;

        _JATTA_EXPORT virtual void Free() = 0;

        _JATTA_EXPORT virtual bool CanLoad() = 0; 
        _JATTA_EXPORT virtual ImageInfo GetImageInfo() = 0;
        _JATTA_EXPORT virtual Jatta::Image* Load() = 0;
    };
}

#include "../External/Undefines.h"