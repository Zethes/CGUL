/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../../Utility/String.h"
#include "../ImageLoader.h"
#include "../../External/Defines.h"

namespace Jatta
{
    /** @brief Namespace containing every builtin image loader.
    */
    namespace ImageLoaders
    {
        namespace BMPCompressionMethods
        {
            enum
            {
                RGB = 0,
                RLE8,
                RLE4,
                BITFIELDS,
                JPEG,
                PNG,
                ALPHABITFIELDS
            };
        }

        /** @brief Class inherited from ImageLoader to support BMP file formats.
         */
        class BMP : ImageLoader
        {
        protected:
            Jatta::String file;
        public:
            _JATTA_EXPORT BMP(const String& filename);  
            _JATTA_EXPORT ~BMP();

            _JATTA_EXPORT virtual void Free();

            _JATTA_EXPORT virtual bool CanLoad(); 
            _JATTA_EXPORT virtual ImageInfo GetImageInfo();
            _JATTA_EXPORT virtual Jatta::Image* Load();
        };
    }
}

#include "../../External/Undefines.h"