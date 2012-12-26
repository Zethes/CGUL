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
        Texture();
        
        void create(const Jatta::Image& image);

        UInt32 getTexture() const;

        UInt32 getWidth() const;
        UInt32 getHeight() const;

        Float2 getSize() const;
    };
}

#include "../External/Undefines.h"