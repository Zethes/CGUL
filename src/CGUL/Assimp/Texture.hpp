// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Texture.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Texture
        {
            _CGUL_AITEXTURE texture;
        public:
            _CGUL_EXPORT Texture(_CGUL_AITEXTURE texture);

            _CGUL_EXPORT UInt32 GetWidth() const;
            _CGUL_EXPORT UInt32 GetHeight() const;

            _CGUL_EXPORT Image GetImage() const;
        };
    }
}

#include "../External/Undefines.hpp"
