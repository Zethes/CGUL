// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file JPEG.hpp
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
        /** @brief JPEG Loader
         */
        class JPEG : public ImageLoader
        {
        public:
            _CGUL_EXPORT JPEG();
            _CGUL_EXPORT ~JPEG();

            _CGUL_EXPORT bool CanLoad(const String& file);
            _CGUL_EXPORT void Load(const String& file, Image* image);

            _CGUL_EXPORT void Save(const String& file, const Image* image) const;
        };
    }
}

#include "../External/Undefines.hpp"
