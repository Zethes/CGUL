// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PNG.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../../Utility/String.hpp"
#include "../Image.hpp"
#include "../../External/Defines.hpp"

namespace CGUL
{
    /** @brief Namespace containing every builtin image loader.
    */
    namespace ImageLoaders
    {
        /** @brief Class inherited from ImageLoader to support PNG file formats.
         */
        class PNG
        {
        protected:
            CGUL::String file;
        public:
            _CGUL_EXPORT static bool CanLoad(const String& filename);
            _CGUL_EXPORT static CGUL::Image* Load(const String& filename);
            _CGUL_EXPORT static void Save(const String& filename, CGUL::Image* image);
        };
    }
}

#include "../../External/Undefines.hpp"
