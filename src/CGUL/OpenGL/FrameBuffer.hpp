// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FrameBuffer.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "OpenGL.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        class Texture;
        class RenderBuffer;

        class FrameBuffer
        {
            UInt32 frameBuffer;
            Enum type;
        public:
            DEPRECATED(_CGUL_EXPORT FrameBuffer(), "Use Raw GL wrappers instead.");
            DEPRECATED(_CGUL_EXPORT FrameBuffer(UInt32 frameBuffer), "Use Raw GL wrappers instead.");
            _CGUL_EXPORT ~FrameBuffer();

            _CGUL_EXPORT void Create(Enum type);
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID() const;

            _CGUL_EXPORT void Bind();
            _CGUL_EXPORT void Unbind();

            _CGUL_EXPORT void Texture2D(Enum attachment, Enum textureTarget, Texture texture, SInt32 level);
            _CGUL_EXPORT void AttachRenderBuffer(Enum attachment, Enum renderBufferTarget, RenderBuffer renderBuffer);
        };
    }
}

#include "../External/Undefines.hpp"
