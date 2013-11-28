// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Texture.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "OpenGL.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        class Texture
        {
            UInt32 texture;
            Enum type;
        public:
            _CGUL_EXPORT static void Active(UInt32 active);

            DEPRECATED(_CGUL_EXPORT Texture(), "Use Raw GL wrappers instead.");
            DEPRECATED(_CGUL_EXPORT Texture(UInt32 texture), "Use Raw GL wrappers instead.");
            _CGUL_EXPORT ~Texture();

            _CGUL_EXPORT void Create(Enum type);
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID() const;

            _CGUL_EXPORT void Bind();
            _CGUL_EXPORT void Unbind();

            // GL_DEPTH_STENCIL_TEXTURE_MODE
            // GL_TEXTURE_BASE_LEVEL
            // GL_TEXTURE_BORDER_COLOR
            // GL_TEXTURE_COMPARE_FUNC
            // GL_TEXTURE_COMPARE_MODE
            // GL_TEXTURE_LOD_BIAS
            _CGUL_EXPORT void SetMinFilter(Enum param);
            _CGUL_EXPORT void SetMagFilter(Enum param);
            // GL_TEXTURE_MIN_LOD
            // GL_TEXTURE_MAX_LOD
            // GL_TEXTURE_MAX_LEVEL
            // GL_TEXTURE_SWIZZLE_R
            // GL_TEXTURE_SWIZZLE_G
            // GL_TEXTURE_SWIZZLE_B
            // GL_TEXTURE_SWIZZLE_A
            // GL_TEXTURE_SWIZZLE_RGBA
            _CGUL_EXPORT void SetTextureWrapS(Enum param);
            _CGUL_EXPORT void SetTextureWrapT(Enum param);
            _CGUL_EXPORT void SetTextureWrapR(Enum param);

            _CGUL_EXPORT void Parameteri(Enum param, SInt32 value);
            _CGUL_EXPORT void Parameterf(Enum param, Float32 value);
            _CGUL_EXPORT void Parameterfv(Enum param, Float32* value);
            _CGUL_EXPORT void Parameteriv(Enum param, SInt32* value);
            _CGUL_EXPORT void ParameterIiv(Enum param, SInt32* value);
            _CGUL_EXPORT void ParameterIuiv(Enum param, UInt32* value);

            // glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            // glGenerateMipmap(GL_TEXTURE_2D);

            _CGUL_EXPORT void Image2D(SInt32 level, SInt32 internalFormat, Size width, Size height, SInt32 border, Enum format, Enum type, void* data);

            // TODO: finish importing opengl texture functions
        };
    }
}

#include "../External/Undefines.hpp"
