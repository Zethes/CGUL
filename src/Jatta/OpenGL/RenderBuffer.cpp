/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "RenderBuffer.h"
#include "Texture.h"

_JATTA_EXPORT Jatta::OpenGL::RenderBuffer::RenderBuffer()
{
    renderBuffer = 0;
}

_JATTA_EXPORT Jatta::OpenGL::RenderBuffer::RenderBuffer(UInt32 renderBuffer)
{
    this->renderBuffer = renderBuffer;
}

_JATTA_EXPORT Jatta::OpenGL::RenderBuffer::~RenderBuffer()
{
}

_JATTA_EXPORT void Jatta::OpenGL::RenderBuffer::Create(Enum type)
{
    glGenRenderbuffers(1, &renderBuffer);
    GLCHECK("Failed to generate render buffer.");
    this->type = type;
}

_JATTA_EXPORT void Jatta::OpenGL::RenderBuffer::Delete()
{
    glDeleteFramebuffers(1, &renderBuffer);
    GLCHECK("Failed to delete frame buffer.");
    renderBuffer = 0;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::RenderBuffer::GetID() const
{
    return renderBuffer;
}

_JATTA_EXPORT void Jatta::OpenGL::RenderBuffer::Bind()
{
    glBindRenderbuffer(type, renderBuffer);
    GLCHECK("Failed to bind frame buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::RenderBuffer::Unbind()
{
    glBindRenderbuffer(type, 0);
    GLCHECK("Failed to unbind frame buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::RenderBuffer::Storage(Enum internalFormat, Size width, Size height)
{
    glRenderbufferStorage(type, internalFormat, width, height);
    GLCHECK("Failed to attach texture 2D to frame buffer.");
}
