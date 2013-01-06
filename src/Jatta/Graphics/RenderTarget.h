/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../Images/Color.h"
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
            SInt32 vp[4];
        };
        static Viewport viewport;

        UInt32 textureCount;
        UInt32* textures;

        UInt32 frameBuffer;
        UInt32 renderBuffer;

        UInt32 width, height;
    public:
        _JATTA_EXPORT RenderTarget();
        _JATTA_EXPORT ~RenderTarget();

        _JATTA_EXPORT void Create(UInt32 width, UInt32 height, UInt32 textures);

        _JATTA_EXPORT void Begin();
        _JATTA_EXPORT void End();

        _JATTA_EXPORT UInt32 GetTexture(UInt32 index) const;
    };
}

#include "../External/Undefines.h"
