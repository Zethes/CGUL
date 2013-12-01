// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PNG.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "Image.hpp"
#include "Format.hpp"
#include "Loader.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace ImageLoaders
    {
        /** @brief PNG Loader
         */
        class PNG : public ImageLoader
        {
        public:
            _CGUL_EXPORT PNG();
            _CGUL_EXPORT ~PNG();

            _CGUL_EXPORT bool CanLoad(const String& file);
            _CGUL_EXPORT Image* Load(const String& file);
        };
    }
}

#include "../External/Undefines.hpp"
