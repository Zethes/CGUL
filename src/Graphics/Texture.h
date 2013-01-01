//        JATTA        //
// by Joshua Brookover //

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
        
        _JATTA_EXPORT void create(const Jatta::Image& image);

        _JATTA_EXPORT UInt32 getTexture() const;

        _JATTA_EXPORT UInt32 getWidth() const;
        _JATTA_EXPORT UInt32 getHeight() const;

        _JATTA_EXPORT Float2 getSize() const;
    };
}

#include "../External/Undefines.h"