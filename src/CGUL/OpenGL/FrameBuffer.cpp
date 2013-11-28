/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "FrameBuffer.h"
#include "Texture.h"
#include "RenderBuffer.h"

_JATTA_EXPORT Jatta::OpenGL::FrameBuffer::FrameBuffer() :
    frameBuffer(0),
    type(0)
{
}

_JATTA_EXPORT Jatta::OpenGL::FrameBuffer::FrameBuffer(UInt32 frameBuffer) :
    frameBuffer(frameBuffer),
    type(0)
{
}

_JATTA_EXPORT Jatta::OpenGL::FrameBuffer::~FrameBuffer()
{
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::Create(Enum type)
{
    glGenFramebuffers(1, &frameBuffer);
    GLCHECK("Failed to generate frame buffer.");
    this->type = type;
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::Delete()
{
    glDeleteFramebuffers(1, &frameBuffer);
    GLCHECK("Failed to delete frame buffer.");
    frameBuffer = 0;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::FrameBuffer::GetID() const
{
    return frameBuffer;
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::Bind()
{
    glBindFramebuffer(type, frameBuffer);
    GLCHECK("Failed to bind frame buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::Unbind()
{
    glBindFramebuffer(type, 0);
    GLCHECK("Failed to unbind frame buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::Texture2D(Enum attachment, Enum textureTarget, Texture texture, SInt32 level)
{
    glFramebufferTexture2D(type, attachment, textureTarget, texture.GetID(), level);
    GLCHECK("Failed to attach texture 2D to frame buffer.");
}

_JATTA_EXPORT void Jatta::OpenGL::FrameBuffer::AttachRenderBuffer(Enum attachment, Enum renderBufferTarget, RenderBuffer renderBuffer)
{
    glFramebufferRenderbuffer(type, attachment, renderBufferTarget, renderBuffer.GetID());
    GLCHECK("Failed to attach render buffer to frame buffer.");
}
