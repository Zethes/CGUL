// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "Image.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A class for performing convolution filters on images.
        Filter rule: filter size must be odd (e.x 3x3, 5x5, etc)
        Note: Works similar to the method at: http://lodev.org/cgtutor/filtering.html
     *  @todo Add some default filters
     */
    class ImageFilter
    {
        UInt32 filterWidth, filterHeight;
        Float32 ** filter;
        Float32 factor;
        Float32 bias;
    public:
        _CGUL_EXPORT ImageFilter();
        _CGUL_EXPORT ImageFilter(UInt32 w, UInt32 h, Float32 ** filter, Float32 factor, Float32 bias);
        _CGUL_EXPORT ~ImageFilter();

        _CGUL_EXPORT void Set(UInt32 w, UInt32 h, Float32 ** filter, Float32 factor, Float32 bias);

        _CGUL_EXPORT void Apply(Image* src, Image* dst);
    };
}

#include "../External/Undefines.hpp"
