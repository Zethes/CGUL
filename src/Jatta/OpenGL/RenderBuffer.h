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
        class RenderBuffer
        {
            UInt32 renderBuffer;
            Enum type;
        public:
            _JATTA_EXPORT RenderBuffer();
            _JATTA_EXPORT RenderBuffer(UInt32 renderBuffer);
            _JATTA_EXPORT ~RenderBuffer();

            _JATTA_EXPORT void Create(Enum type);
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID() const;

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            _JATTA_EXPORT void Storage(Enum internalFormat, Size width, Size height);
        };
    }
}

#include "../External/Undefines.h"