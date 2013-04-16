/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Texture;

        class FrameBuffer
        {
            UInt32 frameBuffer;
            Enum type;
        public:
            _JATTA_EXPORT FrameBuffer();
            _JATTA_EXPORT FrameBuffer(UInt32 frameBuffer);
            _JATTA_EXPORT ~FrameBuffer();

            _JATTA_EXPORT void Create(Enum type);
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID() const;

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            _JATTA_EXPORT void Texture2D(Enum attachment, Enum textureTarget, Texture texture, SInt32 level);
        };
    }
}

#include "../External/Undefines.h"