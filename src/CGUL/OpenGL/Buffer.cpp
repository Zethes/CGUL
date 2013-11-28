// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Buffer.cpp
 */

#include "Buffer.hpp"

_CGUL_EXPORT CGUL::OpenGL::Buffer::Buffer()
{
    this->buffer = 0;
    this->type = 0;
}

_CGUL_EXPORT void CGUL::OpenGL::Buffer::Create(Enum type)
{
    glGenBuffers(1, &this->buffer);
    this->type = type;
    GLCHECK("Failed to generate buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::Buffer::Delete()
{
    glDeleteBuffers(1, &this->buffer);
    GLCHECK("Failed to delete buffer.");
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::Buffer::GetID()
{
    return this->buffer;
}

_CGUL_EXPORT void CGUL::OpenGL::Buffer::Bind()
{
    glBindBuffer(this->type, this->buffer);
    GLCHECK("Failed to bind buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::Buffer::Unbind()
{
    glBindBuffer(this->type, 0);
    GLCHECK("Failed to unbind buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::Buffer::Data(Size size, void* data, Enum usage)
{
    glBufferData(this->type, size, data, usage);
    GLCHECK("Failed to set buffer data.");
}
