// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Context.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "OpenGL.hpp"
#if defined(CGUL_BUILD) && defined(CGUL_MACOS)
#   import "MacOS/OpenGLView.hpp"
#endif
#include "../Windows/Window.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        class Context
        {
            Window* window;

#           ifdef CGUL_WINDOWS
            _CGUL_PIXELFORMATDESCRIPTOR pfd;
            _CGUL_HDC deviceContext;
            UInt32 pixelFormat;
            _CGUL_HGLRC renderContext;
#           endif

#           ifdef CGUL_LINUX
            _CGUL_DISPLAY display;
            _CGUL_GLXCONTEXT context;
#           endif

#           if defined(CGUL_BUILD) && defined(CGUL_MACOS)
            OpenGLView* view;
#           elif defined(CGUL_MACOS)
            void* view;
#           endif
        public:
            _CGUL_EXPORT Context* GetCurrent();

            _CGUL_EXPORT Context();
            _CGUL_EXPORT ~Context();

            _CGUL_EXPORT void Create(Window* window);
            _CGUL_EXPORT void MakeCurrent();
            _CGUL_EXPORT void Destroy();
            _CGUL_EXPORT bool IsValid() const;

            _CGUL_EXPORT void Enable(Enum capability);
            _CGUL_EXPORT void Disable(Enum capability);

            _CGUL_EXPORT void DepthMask(bool enabled);
            _CGUL_EXPORT void StencilMask(bool enabled);
            _CGUL_EXPORT void StencilMask(UInt32 mask);

            _CGUL_EXPORT void StencilFunc(Enum func, SInt32 reference, UInt32 mask = ~0);
            _CGUL_EXPORT void StencilOp(Enum sfail, Enum dpfail, Enum dppass);

            _CGUL_EXPORT void Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height);

            _CGUL_EXPORT void ClearColor(const Color& color);
            _CGUL_EXPORT void Clear(Enum mask);

            _CGUL_EXPORT void SwapBuffers();

            // TODO: finish importing opengl context functions
        };
    }
}
#include "../External/Undefines.h"
