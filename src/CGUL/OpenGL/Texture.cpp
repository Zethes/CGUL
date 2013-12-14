// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Texture.cpp
 */

#include "Texture.hpp"

_CGUL_EXPORT void CGUL::OpenGL::Texture::Active(UInt32 active)
{
    glActiveTexture(GL_TEXTURE0 + active);
    GLCHECK("Failed to set active texture.", glActiveTexture);
}

_CGUL_EXPORT CGUL::OpenGL::Texture::Texture() :
    texture(0),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::Texture::Texture(UInt32 texture) :
    texture(texture),
    type(0)
{
}

_CGUL_EXPORT CGUL::OpenGL::Texture::~Texture()
{
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Create(Enum type)
{
    glGenTextures(1, &texture);
    GLCHECK("Failed to generate texture.", glGenTextures);
    this->type = type;
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Delete()
{
    glDeleteTextures(1, &texture);
    GLCHECK("Failed to delete texture.", glDeleteTextures);
    texture = 0;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::Texture::GetID() const
{
    return texture;
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Bind()
{
    glBindTexture(type, texture);
    GLCHECK("Failed to bind texture.", glBindTexture);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Unbind()
{
    glBindTexture(type, 0);
    GLCHECK("Failed to unbind texture.", glBindTexture);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::SetMinFilter(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, param);
    GLCHECK("Failed to set min filter.", glTexParameteri);

    // TODO: move these to their own methods
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::SetMagFilter(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, param);
    GLCHECK("Failed to set mag filter.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::SetTextureWrapS(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_S, param);
    GLCHECK("Failed to set texture wrap S.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::SetTextureWrapT(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_T, param);
    GLCHECK("Failed to set texture wrap T.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::SetTextureWrapR(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_R, param);
    GLCHECK("Failed to set texture wrap R.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Parameteri(Enum param, SInt32 value)
{
    glTexParameteri(type, param, value);
}
_CGUL_EXPORT void CGUL::OpenGL::Texture::Parameterf(Enum param, Float32 value)
{
    glTexParameterf(type, param, value);
}
_CGUL_EXPORT void CGUL::OpenGL::Texture::Parameterfv(Enum param, Float32* value)
{
    glTexParameterfv(type, param, value);
}
_CGUL_EXPORT void CGUL::OpenGL::Texture::Parameteriv(Enum param, SInt32* value)
{
    glTexParameterIiv(type, param, value);
}
_CGUL_EXPORT void CGUL::OpenGL::Texture::ParameterIiv(Enum param, SInt32* value)
{
    glTexParameterIiv(type, param, value);
}
_CGUL_EXPORT void CGUL::OpenGL::Texture::ParameterIuiv(Enum param, UInt32* value)
{
    glTexParameterIuiv(type, param, value);
}

_CGUL_EXPORT void CGUL::OpenGL::Texture::Image2D(SInt32 level, SInt32 internalFormat, Size width, Size height, SInt32 border, Enum format, Enum type, void* data)
{
    glTexImage2D(this->type, level, internalFormat, width, height, border, format, type, data);
    GLCHECK("Failed to set texture 2D image.", glTexImage2D);
    // TODO: move these to their own methods
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    GLCHECK("Something borked", glTexEnvf);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    GLCHECK("Something borked", glPixelStorei);
}
