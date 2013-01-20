/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#if defined(JATTA_BUILDS) && defined(MACOS)
#   import "MacOS/OpenGLView.h"
#endif
#include "../Windows/Window.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Graphics
    {
        static Graphics* current;

        Window* window;

#       ifdef WINDOWS
        _JATTA_PIXELFORMATDESCRIPTOR pfd;
        _JATTA_HDC deviceContext;
        UInt32 pixelFormat;
        _JATTA_HGLRC renderContext;
#       endif

#       ifdef LINUX
        _JATTA_GLXCONTEXT context;
#       endif

#       if defined(MACOS) && defined(__OBJC__)
        OpenGLView* view;
#       elif defined(MACOS)
        void* view;
#       endif
    public:
        _JATTA_EXPORT static const UInt32 position1 =  0, position2 =  1, position3 =  2, position4 =  3;
        _JATTA_EXPORT static const UInt32 color1    =  4, color2    =  5, color3    =  6, color4    =  7;
        _JATTA_EXPORT static const UInt32 texCoord1 =  8, texCoord2 =  9, texCoord3 = 10, texCoord4 = 11;
        _JATTA_EXPORT static const UInt32 normal1   = 12, normal2   = 13, normal3   = 14, normal4   = 15;

        _JATTA_EXPORT static Graphics* GetCurrent();

        _JATTA_EXPORT Graphics();
        _JATTA_EXPORT ~Graphics();

        _JATTA_EXPORT void Create(Window* window);

        _JATTA_EXPORT Window* GetWindow();

        _JATTA_EXPORT void MakeCurrent();

        _JATTA_EXPORT void Clear(const Jatta::Color& color);

        _JATTA_EXPORT void Present();

        _JATTA_EXPORT void SetViewPort(UInt32 x, UInt32 y, UInt32 width, UInt32 height);

        _JATTA_EXPORT void EnableDepthTest();
        _JATTA_EXPORT void DisableDepthTest();
        _JATTA_EXPORT void EnableCulling();
        _JATTA_EXPORT void DisableCulling();
        _JATTA_EXPORT void EnableScissoring(int x, int y, int w, int h);
        _JATTA_EXPORT void DisableScissoring();
    };
}

#include "../External/Undefines.h"
