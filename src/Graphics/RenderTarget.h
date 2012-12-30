//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class RenderTarget
    {
        union Viewport
        {
            struct
            {
                SInt32 x, y;
                SInt32 width, height;
            };
        };
        static Viewport viewport;

        UInt32 textureCount;
        UInt32* textures;

        UInt32 frameBuffer;

        UInt32 width, height;
    public:
        RenderTarget();
        ~RenderTarget();

        void create(UInt32 width, UInt32 height, UInt32 textures);

        void begin();
        void end();

        UInt32 getTexture(UInt32 index);
    };
}

#include "../External/Undefines.h"