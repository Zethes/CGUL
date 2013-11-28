// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file RenderBuffer.hpp
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
        class RenderBuffer
        {
            UInt32 renderBuffer;
            Enum type;
        public:
            DEPRECATED(_CGUL_EXPORT RenderBuffer(), "Use Raw GL wrappers instead.");
            DEPRECATED(_CGUL_EXPORT RenderBuffer(UInt32 renderBuffer), "Use Raw GL wrappers instead.");
            _CGUL_EXPORT ~RenderBuffer();

            _CGUL_EXPORT void Create(Enum type);
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID() const;

            _CGUL_EXPORT void Bind();
            _CGUL_EXPORT void Unbind();

            _CGUL_EXPORT void Storage(Enum internalFormat, Size width, Size height);
        };
    }
}

#include "../External/Undefines.hpp"
