/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Buffer.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::Buffer::Buffer()
{
    buffer = 0;
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Create()
{
    glGenBuffers(1, &buffer);
    GLCHECK("Failed to generate buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Delete()
{
    glDeleteBuffers(1, &buffer);
    GLCHECK("Failed to delete buffer.");
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::Buffer::GetID()
{
    return buffer;
}