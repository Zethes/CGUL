// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FrameBuffer.cpp
 */

#include "FrameBuffer.hpp"
#include "Texture.hpp"
#include "RenderBuffer.hpp"

_CGUL_EXPORT CGUL::OpenGL::FrameBuffer::FrameBuffer() :
    frameBuffer(0),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::FrameBuffer::FrameBuffer(UInt32 frameBuffer) :
    frameBuffer(frameBuffer),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::FrameBuffer::~FrameBuffer()
{
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::Create(Enum type)
{
    glGenFramebuffers(1, &frameBuffer);
    GLCHECK("Failed to generate frame buffer.");
    this->type = type;
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::Delete()
{
    glDeleteFramebuffers(1, &frameBuffer);
    GLCHECK("Failed to delete frame buffer.");
    frameBuffer = 0;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::FrameBuffer::GetID() const
{
    return frameBuffer;
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::Bind()
{
    glBindFramebuffer(type, frameBuffer);
    GLCHECK("Failed to bind frame buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::Unbind()
{
    glBindFramebuffer(type, 0);
    GLCHECK("Failed to unbind frame buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::Texture2D(Enum attachment, Enum textureTarget, Texture texture, SInt32 level)
{
    glFramebufferTexture2D(type, attachment, textureTarget, texture.GetID(), level);
    GLCHECK("Failed to attach texture 2D to frame buffer.");
}

_CGUL_EXPORT void CGUL::OpenGL::FrameBuffer::AttachRenderBuffer(Enum attachment, Enum renderBufferTarget, RenderBuffer renderBuffer)
{
    glFramebufferRenderbuffer(type, attachment, renderBufferTarget, renderBuffer.GetID());
    GLCHECK("Failed to attach render buffer to frame buffer.");
}
