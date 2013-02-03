/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_OPENGL
#include "Context.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::Context::Context()
{
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Create(const Window* window)
{
    graphics.Create(window);
}

_JATTA_EXPORT void Jatta::OpenGL::Context::MakeCurrent()
{
    graphics.MakeCurrent();
}

_JATTA_EXPORT void Jatta::OpenGL::Context::Viewport(SInt32 x, SInt32 y, UInt32 width, UInt32 height)
{
    glViewport((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
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
    graphics.Present();
}

#endif