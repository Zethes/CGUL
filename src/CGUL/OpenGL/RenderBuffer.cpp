// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file RenderBuffer.cpp
 */

#include "RenderBuffer.hpp"
#include "Texture.hpp"

_CGUL_EXPORT CGUL::OpenGL::RenderBuffer::RenderBuffer() :
    renderBuffer(0),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::RenderBuffer::RenderBuffer(UInt32 renderBuffer) :
    renderBuffer(renderBuffer),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::RenderBuffer::~RenderBuffer()
{
}

_CGUL_EXPORT void CGUL::OpenGL::RenderBuffer::Create(Enum type)
{
    glGenRenderbuffers(1, &renderBuffer);
    GLCHECK("Failed to generate render buffer.");
    this->type = type;
}

_CGUL_EXPORT void CGUL::OpenGL::RenderBuffer::Delete()
{
    glDeleteFramebuffers(1, &renderBuffer);
    GLCHECK("Failed to delete frame buffer.");
    renderBuffer = 0;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::RenderBuffer::GetID() const
{
    return renderBuffer;
}

_CGUL_EXPORT void CGUL::OpenGL::RenderBuffer::Bind()
{
    glBindRenderbuffer(type, renderBuffer);
    GLCHECK("Failed to bind frame buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::RenderBuffer::Unbind()
{
    glBindRenderbuffer(type, 0);
    GLCHECK("Failed to unbind frame buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::RenderBuffer::Storage(Enum internalFormat, Size width, Size height)
{
    glRenderbufferStorage(type, internalFormat, width, height);
    GLCHECK("Failed to attach texture 2D to frame buffer.");
}
