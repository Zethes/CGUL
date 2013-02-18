/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "OpenGL.h"
 #if defined(JATTA_BUILDS) && defined(MACOS)
#   import "MacOS/OpenGLView.h"
#endif
#include "../Windows/Window.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Context
        {
            const Window* window;

#           ifdef WINDOWS
            _JATTA_PIXELFORMATDESCRIPTOR pfd;
            _JATTA_HDC deviceContext;
            UInt32 pixelFormat;
            _JATTA_HGLRC renderContext;
#           endif

#           ifdef LINUX
            _JATTA_GLXCONTEXT context;
#           endif

#           if defined(MACOS) && defined(__OBJC__)
            OpenGLView* view;
#           elif defined(MACOS)
            void* view;
#           endif
        public:
            _JATTA_EXPORT Context* GetCurrent();

            _JATTA_EXPORT Context();

            _JATTA_EXPORT void Create(const Window* window);
            _JATTA_EXPORT void MakeCurrent();

            _JATTA_EXPORT void Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height);

            _JATTA_EXPORT void ClearColor(const Color& color);
            _JATTA_EXPORT void Clear(Enum mask);

            _JATTA_EXPORT void SwapBuffers();

            // TODO: finish importing opengl context functions
        };
    }
}
#include "../External/Undefines.h"