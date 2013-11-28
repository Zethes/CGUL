// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Context.cpp
 */

#include "Context.hpp"

static CGUL::OpenGL::Context* currentContext;

_CGUL_EXPORT CGUL::OpenGL::Context* CGUL::OpenGL::Context::GetCurrent()
{
    return currentContext;
}

_CGUL_EXPORT CGUL::OpenGL::Context::Context() :
    window(NULL)
{
#    ifdef CGUL_LINUX
    context = NULL;
#    endif
}

_CGUL_EXPORT CGUL::OpenGL::Context::~Context()
{
    Destroy();
}

_CGUL_EXPORT void CGUL::OpenGL::Context::Create(Window* window)
{
    this->window = window;

#   ifdef CGUL_WINDOWS
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

#   ifdef CGUL_LINUX
    this->display = window->_GetDisplay();

    XWindowAttributes attributes;
    XGetWindowAttributes(this->display, window->_GetHandle(), &attributes);

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
    glXQueryVersion(display, &glxMajorVersion, &glxMinorVersion);
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
    this->context = glXCreateContext(this->display, &info, 0, true);
    glXMakeCurrent(this->display, window->_GetHandle(), this->context);
#   endif

#   ifdef CGUL_MACOS
    view = [[OpenGLView alloc] init];

    // TODO: remove these?
    // Get the default content of the window
    //id content = [window contentView];

    // Set the content of the window to the OpenGL view we created
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
    /*glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_CUBE_MAP);
    //glCullFace(GL_BACK);
    //glEnable(GL_CULL_FACE);*/

    // clears out errors... we're not actually checking for any!
    // TODO: check for errors dammit!
    glGetError();

    window->context = this;
}

_CGUL_EXPORT void CGUL::OpenGL::Context::MakeCurrent()
{
    // TODO: error checking

#   ifdef CGUL_WINDOWS
    if (!wglMakeCurrent(deviceContext, renderContext))
    {
        throw std::runtime_error("Failed to make device current.");
    }
#   endif

    // TODO: Context::MakeCurrent for Linux

#   ifdef CGUL_MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [view MakeCurrent];
    [pool drain];
#   endif

    currentContext = this;
}

_CGUL_EXPORT void CGUL::OpenGL::Context::Destroy()
{
    // Check if this is a valid context first.
    if (this->window == NULL)
    {
        return;
    }

    // TODO: Context::Destroy

#   ifdef CGUL_LINUX
    if (this->context != NULL)
    {
        // Release the current context from this thread before deleting it
        glXMakeCurrent(this->display, None, NULL);

        // Delete the context
        glXDestroyContext(this->display, this->context);
        this->context = NULL;
    }
#   endif

    this->window->context = NULL;
    this->window = NULL;
}

_CGUL_EXPORT bool CGUL::OpenGL::Context::IsValid() const
{
    return this->window != NULL;
}

_CGUL_EXPORT void CGUL::OpenGL::Context::Enable(Enum capability)
{
    glEnable(capability);
}
_CGUL_EXPORT void CGUL::OpenGL::Context::Disable(Enum capability)
{
    glDisable(capability);
}

_CGUL_EXPORT void CGUL::OpenGL::Context::DepthMask(bool enabled)
{
    glDepthMask(enabled ? GL_TRUE : GL_FALSE);
}
_CGUL_EXPORT void CGUL::OpenGL::Context::StencilMask(bool enabled)
{
    glStencilMask(enabled ? GL_TRUE : GL_FALSE);
}
_CGUL_EXPORT void CGUL::OpenGL::Context::StencilMask(UInt32 mask)
{
    glStencilMask(mask);
}

_CGUL_EXPORT void CGUL::OpenGL::Context::StencilFunc(Enum func, SInt32 reference, UInt32 mask)
{
    glStencilFunc(func, reference, mask);
}
_CGUL_EXPORT void CGUL::OpenGL::Context::StencilOp(Enum sfail, Enum dpfail, Enum dppass)
{
    glStencilOp(sfail, dpfail, dppass);
}

_CGUL_EXPORT void CGUL::OpenGL::Context::Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height)
{
    glViewport((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    // TODO: error checking
}

_CGUL_EXPORT void CGUL::OpenGL::Context::ClearColor(const Color& color)
{
    glClearColor((GLfloat)(color.r / 255.0f), (GLfloat)(color.g / 255.0f), (GLfloat)(color.b / 255.0f), (GLfloat)(color.a / 255.0f));
    GLCHECK("Failed to set clear color.");
}

_CGUL_EXPORT void CGUL::OpenGL::Context::Clear(Enum mask)
{
    glClear((GLbitfield)mask);
    GLCHECK("Failed to clear context.");
}

_CGUL_EXPORT void CGUL::OpenGL::Context::SwapBuffers()
{
    // TODO: error checking

    if (GetCurrent() != this)
    {
        throw std::runtime_error("Graphics device not current");
    }

#   ifdef CGUL_WINDOWS
    ::SwapBuffers(deviceContext);
#   endif

#   ifdef CGUL_LINUX
    glXSwapBuffers(this->display, this->window->_GetHandle());
#   endif

#   ifdef CGUL_MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [view SwapBuffers];
    [pool drain];
#   endif
}
