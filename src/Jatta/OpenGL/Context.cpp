/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Context.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

static Jatta::OpenGL::Context* currentContext;

_JATTA_EXPORT Jatta::OpenGL::Context* Jatta::OpenGL::Context::GetCurrent()
{
    return currentContext;
}

_JATTA_EXPORT Jatta::OpenGL::Context::Context()
{
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Create(const Window* window)
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
        throw std::runtime_error("Failed to get device context.");
    }

    // set the pixel format
    pixelFormat = ChoosePixelFormat(deviceContext, &pfd);
    if (!SetPixelFormat(deviceContext, pixelFormat, &pfd))
    {
        throw std::runtime_error("Failed to choose pixel format.");
    }

    // create opengl render context and make it current
    renderContext = wglCreateContext(deviceContext);
    if (!renderContext)
    {
        throw std::runtime_error("Failed to create render context.");
    }
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(window->_GetDisplay(), window->_GetHandle(), &attributes);

    // TODO: remove this?
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
    glXQueryVersion(window->_GetDisplay(), &glxMajorVersion, &glxMinorVersion);
    if(glxMajorVersion == 1 && glxMinorVersion < 2)
    {
        // TODO: error handling
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
    this->context = glXCreateContext(window->_GetDisplay(), &info, 0, true);
    glXMakeCurrent(window->_GetDisplay(), window->_GetHandle(), this->context);
#   endif

#   ifdef MACOS
    view = [[OpenGLView alloc] init];

    // TODO: remove these?
    // Get the default content of the window
    //id content = [window contentView];

    // Set the content of the window to the OpenGL view we created
    //[window setContentView: view];
    [window->_GetHandle() SetContent: view];
#   endif

    if (currentContext == NULL)
    {
        MakeCurrent();

        GLenum glewResult = glewInit();
        if (glewResult != GLEW_OK)
        {
            throw std::runtime_error("Glew failed");
        }
    }

    // TODO: move these to their own methods
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    // Um... linux doesn't like these
    //glDrawBuffer(GL_FRONT_AND_BACK);
    //glReadBuffer(GL_FRONT_AND_BACK);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_CUBE_MAP);
    //glCullFace(GL_BACK);
    //glEnable(GL_CULL_FACE);

    // clears out errors... we're not actually checking for any!
    // TODO: check for errors dammit!
    glGetError();
}

_JATTA_EXPORT void Jatta::OpenGL::Context::MakeCurrent()
{
    // TODO: error checking

    #   ifdef WINDOWS
    if (!wglMakeCurrent(deviceContext, renderContext))
    {
        throw std::runtime_error("Failed to make device current.");
    }
#   endif

    // TODO: Context::MakeCurrent for Linux

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [view MakeCurrent];
    [pool drain];
#   endif

    currentContext = this;
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Enable(Enum capability)
{
    glEnable(capability);
}
_JATTA_EXPORT void Jatta::OpenGL::Context::Disable(Enum capability)
{
    glDisable(capability);
}

_JATTA_EXPORT void Jatta::OpenGL::Context::DepthMask(bool enabled)
{
    glDepthMask(enabled ? GL_TRUE : GL_FALSE);
}
_JATTA_EXPORT void Jatta::OpenGL::Context::StencilMask(bool enabled)
{
    glStencilMask(enabled ? GL_TRUE : GL_FALSE);
}
_JATTA_EXPORT void Jatta::OpenGL::Context::StencilMask(UInt32 mask)
{
    glStencilMask(mask);
}

_JATTA_EXPORT void Jatta::OpenGL::Context::StencilFunc(Enum func, SInt32 reference, UInt32 mask)
{
    glStencilFunc(func, reference, mask);
}
_JATTA_EXPORT void Jatta::OpenGL::Context::StencilOp(Enum sfail, Enum dpfail, Enum dppass)
{
    glStencilOp(sfail, dpfail, dppass);
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height)
{
    glViewport((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    // TODO: error checking
}

_JATTA_EXPORT void Jatta::OpenGL::Context::ClearColor(const Color& color)
{
    glClearColor((GLfloat)(color.r / 255.0f), (GLfloat)(color.g / 255.0f), (GLfloat)(color.b / 255.0f), (GLfloat)(color.a / 255.0f));
    GLCHECK("Failed to set clear color.");
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Clear(Enum mask)
{
    glClear((GLbitfield)mask);
    GLCHECK("Failed to clear context.");
}

_JATTA_EXPORT void Jatta::OpenGL::Context::SwapBuffers()
{
    // TODO: error checking

    if (GetCurrent() != this)
    {
        throw std::runtime_error("Graphics device not current");
    }

#   ifdef WINDOWS
    ::SwapBuffers(deviceContext);
#   endif

#   ifdef LINUX
    glXSwapBuffers(window->_GetDisplay(), window->_GetHandle());
#   endif

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [view SwapBuffers];
    [pool drain];
#   endif
}