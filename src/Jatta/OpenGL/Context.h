/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Graphics/Graphics.h"
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Context
        {
            Graphics graphics;
        public:
            _JATTA_EXPORT Context();

            _JATTA_EXPORT void Create(Window* window);
            _JATTA_EXPORT void MakeCurrent();

            _JATTA_EXPORT void Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height);

            _JATTA_EXPORT void ClearColor(const Color& color);
            _JATTA_EXPORT void Clear(Enum mask);

            _JATTA_EXPORT void SwapBuffers();
        };
    }
}
#include "../External/Undefines.h"