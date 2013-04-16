/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Texture
        {
            UInt32 texture;
            Enum type;
        public:
            _JATTA_EXPORT static void Active(UInt32 active);

            _JATTA_EXPORT Texture();
            _JATTA_EXPORT Texture(UInt32 texture);
            _JATTA_EXPORT ~Texture();

            _JATTA_EXPORT void Create(Enum type);
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID() const;

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            // GL_DEPTH_STENCIL_TEXTURE_MODE
            // GL_TEXTURE_BASE_LEVEL
            // GL_TEXTURE_BORDER_COLOR
            // GL_TEXTURE_COMPARE_FUNC
            // GL_TEXTURE_COMPARE_MODE
            // GL_TEXTURE_LOD_BIAS
            _JATTA_EXPORT void SetMinFilter(Enum param);
            _JATTA_EXPORT void SetMagFilter(Enum param);
            // GL_TEXTURE_MIN_LOD
            // GL_TEXTURE_MAX_LOD
            // GL_TEXTURE_MAX_LEVEL
            // GL_TEXTURE_SWIZZLE_R
            // GL_TEXTURE_SWIZZLE_G
            // GL_TEXTURE_SWIZZLE_B
            // GL_TEXTURE_SWIZZLE_A
            // GL_TEXTURE_SWIZZLE_RGBA
            _JATTA_EXPORT void SetTextureWrapS(Enum param);
            _JATTA_EXPORT void SetTextureWrapT(Enum param);
            _JATTA_EXPORT void SetTextureWrapR(Enum param);

            _JATTA_EXPORT void Parameteri(Enum param, SInt32 value);
            _JATTA_EXPORT void Parameterf(Enum param, Float32 value);
            _JATTA_EXPORT void Parameterfv(Enum param, Float32* value);
            _JATTA_EXPORT void Parameteriv(Enum param, SInt32* value);
            _JATTA_EXPORT void ParameterIiv(Enum param, SInt32* value);
            _JATTA_EXPORT void ParameterIuiv(Enum param, UInt32* value);

            // glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            // glGenerateMipmap(GL_TEXTURE_2D);

            _JATTA_EXPORT void Image2D(SInt32 level, SInt32 internalFormat, Size width, Size height, SInt32 border, Enum format, Enum type, void* data);

            // TODO: finish importing opengl texture functions
        };
    }
}

#include "../External/Undefines.h"
