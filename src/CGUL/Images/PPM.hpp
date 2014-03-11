// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PPM.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Images/Image.hpp"
#include "../Images/Format.hpp"
#include "../Images/Loader.hpp"
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace ImageLoaders
    {
        /** @brief PPM Loader
         */
        class PPM : public ImageLoader
        {
            UInt32 type;
        public:
            _CGUL_EXPORT PPM();
            _CGUL_EXPORT ~PPM();

            _CGUL_EXPORT bool CanLoad(const String& file);
            _CGUL_EXPORT void Load(const String& file, Image* image);

            _CGUL_EXPORT void Save(const String& file, const Image* image) const;
        };
    }
}

// Undefines
#include "../External/Undefines.hpp"
