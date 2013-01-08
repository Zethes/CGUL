/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Images/Image.h"
#include "../Math/Float2.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Texture
    {
        UInt32 texture;
        UInt32 width;
        UInt32 height;
    public:
        _JATTA_EXPORT Texture();
        
        _JATTA_EXPORT void Create(const Jatta::Image& image);
        _JATTA_EXPORT void CreateCubeMap(const Jatta::Image& negX, const Jatta::Image& posX, const Jatta::Image& negY, const Jatta::Image& posY, const Jatta::Image& negZ, const Jatta::Image& posZ);

        _JATTA_EXPORT UInt32 GetTexture() const;

        _JATTA_EXPORT UInt32 GetWidth() const;
        _JATTA_EXPORT UInt32 GetHeight() const;

        _JATTA_EXPORT Float2 GetSize() const;
    };
}

#include "../External/Undefines.h"