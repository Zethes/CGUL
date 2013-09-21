/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../../Utility/String.h"
#include "../Image.h"
#include "../../External/Defines.h"

namespace Jatta
{
    /** @brief Namespace containing every builtin image loader.
    */
    namespace ImageLoaders
    {
        /** @brief Class inherited from ImageLoader to support JPEG file formats.
         */
        class JPEG
        {
        public:
            _JATTA_EXPORT static bool CanLoad(const String& filename); 
            _JATTA_EXPORT static Jatta::Image* Load(const String& filename);
            _JATTA_EXPORT static void Save(const String& filename, Jatta::Image* image);
        };
    }
}

#include "../../External/Undefines.h"