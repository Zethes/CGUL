/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Graphics.h"

#include <GL/glew.h>
#include <stdexcept>

#ifdef LINUX
#include <GL/glxew.h>
#endif

Jatta::Graphics* Jatta::Graphics::current = nullptr;

_JATTA_EXPORT Jatta::Graphics* Jatta::Graphics::GetCurrent()
{
    return current;
}

_JATTA_EXPORT Jatta::Graphics::Graphics()
{
}

_JATTA_EXPORT Jatta::Graphics::~Graphics()
{
    // TODO: delete graphics stuff
}

_JATTA_EXPORT void Jatta::Graphics::Create(Window* window)
{
    this->window = window;

#   ifdef WINDOWS
    // setup the pixel format descriptor
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 0;
    pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cRedBits = 0;
    pfd.cRedShift = 0;
    pfd.cGreenBits = 0;
    pfd.cGreenShift = 0;
    pfd.cBlueBits = 0;
    pfd.cBlueShift = 0;
    pfd.cAlphaBits = 0;
    pfd.cAlphaShift = 0;
    pfd.cAccumBits = 0;
    pfd.cAccumRedBits = 0;
    pfd.cAccumGreenBits = 0;
    pfd.cAccumBlueBits = 0;
    pfd.cAccumAlphaBits = 0;
    pfd.cDepthBits = 32;
    pfd.cStencilBits = 0;
    pfd.cAuxBuffers = 0;
    pfd.iLayerType = PFD_MAIN_PLANE;
    pfd.bReserved = 0;
    pfd.dwLayerMask = 0;
    pfd.dwVisibleMask = 0;
    pfd.dwDamageMask = 0;

    // get the device handle for the window
    deviceContext = GetDC(window->_GetHandle());
    if (!deviceContext)
    {
        // @TODO error handling
    }

    // set the pixel format
    pixelFormat = ChoosePixelFormat(deviceContext, &pfd);
    if (!SetPixelFormat(deviceContext, pixelFormat, &pfd))
    {
        // @TODO error handling
    }

    // create opengl render context and make it current
    renderContext = wglCreateContext(deviceContext);
    if (!renderContext)
    {
        // @TODO error handling
    }
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(window->_getDisplay(), window->_getHandle(), &attributes);
    /*attributes->visual = blah blah;
    // also create a new GL context for rendering
    GLint attribs[] = { GLX_CONTEXT_MAJOR_VERSION_ARB, 3, GLX_CONTEXT_MINOR_VERSION_ARB, 0, 0 };
    context = glXCreateContextAttribsARB(window->_getDisplay, window->config[0], 0, true, attribs);
    glXMakeCurrent(window->display, window->handle, context);
    // glXCreateContext() using this visual
    // glXMakeCurrent() using this context and the window id*/

    int glxMajorVersion = 0;
    int glxMinorVersion = 0;
    // Get Version info
    glXQueryVersion(window->_getDisplay(), &glxMajorVersion, &glxMinorVersion);
    if(glxMajorVersion == 1 && glxMinorVersion < 2)
    {
        // @TODO error handling
        _JATTA_DEBUG_LN("error");
    }

    /*XSizeHints hints;
    hints.flags = PMinSize | PMaxSize;
    hints.min_width = 800; hints.min_height = 600;
    hints.max_width = 800; hints.max_height = 600;
    XSetWMNormalHints(display, handle, &hints);*/

    XVisualInfo info;
    info.visual = attributes.visual;
    info.visualid = XVisualIDFromVisual(attributes.visual);
    info.screen = 0;
    info.depth = attributes.depth;
    info.c_class = InputOutput;
    info.red_mask = 0;
    info.green_mask = 0;
    info.blue_mask = 0;
    info.colormap_size = 0;
    info.bits_per_rgb = 0;

    // also create a new GL context for rendering
    this->context = glXCreateContext(window->_getDisplay(), &info, 0, true);
    glXMakeCurrent(window->_getDisplay(), window->_getHandle(), this->context);
#   endif

    if (current == nullptr)
    {
        MakeCurrent();

        GLenum glewResult = glewInit();
        if (glewResult != GLEW_OK)
        {
            throw std::runtime_error("Glew failed");
        }
        _JATTA_DEBUG_LN("Glew initiated!");
    }

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawBuffer(GL_FRONT_AND_BACK);
    glReadBuffer(GL_FRONT_AND_BACK);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_CUBE_MAP);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);

    // clears out errors... we're not actually checking for any!
    // TODO: check for errors dammit!
    glGetError();
}

_JATTA_EXPORT Jatta::Window* Jatta::Graphics::GetWindow()
{
    return window;
}

_JATTA_EXPORT void Jatta::Graphics::MakeCurrent()
{
#   ifdef WINDOWS
    if (!wglMakeCurrent(deviceContext, renderContext))
    {
        throw std::runtime_error("Failed to make device current.");
    }
#   endif

    current = this;
}

_JATTA_EXPORT void Jatta::Graphics::Clear(const Jatta::Color& color)
{
    if (GetCurrent() != this)
    {
        throw std::runtime_error("Graphics device not current");
    }

    glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

_JATTA_EXPORT void Jatta::Graphics::Present()
{
    if (GetCurrent() != this)
    {
        throw std::runtime_error("Graphics device not current");
    }

#   ifdef WINDOWS
    SwapBuffers(deviceContext);
#   endif

#   ifdef LINUX
    glXSwapBuffers(window->_getDisplay(), window->_getHandle());
#   endif
}

_JATTA_EXPORT void Jatta::Graphics::SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    if (GetCurrent() != this)
    {
        throw std::runtime_error("Graphics device not current");
    }

    glViewport(x, y, width, height);
}

_JATTA_EXPORT void Jatta::Graphics::EnableDepthTest()
{
	glEnable(GL_DEPTH_TEST);
}

_JATTA_EXPORT void Jatta::Graphics::DisableDepthTest()
{
	glDisable(GL_DEPTH_TEST);
}

_JATTA_EXPORT void Jatta::Graphics::EnableCulling()
{
	glEnable(GL_CULL_FACE);
}
_JATTA_EXPORT void Jatta::Graphics::DisableCulling()
{
	glDisable(GL_CULL_FACE);
}
