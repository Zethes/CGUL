/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Buffer.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::Buffer::Buffer()
{
    this->buffer = 0;
    this->type = 0;
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Create(Enum type)
{
    glGenBuffers(1, &this->buffer);
    this->type = type;
    GLCHECK("Failed to generate buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Delete()
{
    glDeleteBuffers(1, &this->buffer);
    GLCHECK("Failed to delete buffer.");
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::Buffer::GetID()
{
    return this->buffer;
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Bind()
{
    glBindBuffer(this->type, this->buffer);
    GLCHECK("Failed to bind buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Unbind()
{
    glBindBuffer(this->type, 0);
    GLCHECK("Failed to unbind buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::Buffer::Data(Size size, void* data, Enum usage)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    GLCHECK("Failed to set buffer data.");
}