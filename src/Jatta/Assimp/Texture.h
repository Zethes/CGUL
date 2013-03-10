/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Images/Image.h"
 #include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class Texture
        {
            _JATTA_AITEXTURE texture;
        public:
            _JATTA_EXPORT Texture(_JATTA_AITEXTURE texture);

            _JATTA_EXPORT UInt32 GetWidth() const;
            _JATTA_EXPORT UInt32 GetHeight() const;

            _JATTA_EXPORT Image GetImage() const; 
        };
    }
}

#include "../External/Undefines.h"