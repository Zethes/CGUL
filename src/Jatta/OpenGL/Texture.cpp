/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Texture.h"

_JATTA_EXPORT void Jatta::OpenGL::Texture::Active(UInt32 active)
{
    glActiveTexture(GL_TEXTURE0 + active);
    GLCHECK("Failed to set active texture.");
}

_JATTA_EXPORT Jatta::OpenGL::Texture::Texture() :
    texture(0),
    type(0)
{
}

_JATTA_EXPORT Jatta::OpenGL::Texture::Texture(UInt32 texture) :
    texture(texture),
    type(0)
{
}

_JATTA_EXPORT Jatta::OpenGL::Texture::~Texture()
{
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Create(Enum type)
{
    glGenTextures(1, &texture);
    GLCHECK("Failed to generate texture.");
    this->type = type;
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Delete()
{
    glDeleteTextures(1, &texture);
    GLCHECK("Failed to delete texture.");
    texture = 0;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::Texture::GetID() const
{
    return texture;
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Bind()
{
    glBindTexture(type, texture);
    GLCHECK("Failed to bind texture.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Unbind()
{
    glBindTexture(type, 0);
    GLCHECK("Failed to unbind texture.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::SetMinFilter(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, param);
    GLCHECK("Failed to set min filter.");

    // TODO: move these to their own methods
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::SetMagFilter(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, param);
    GLCHECK("Failed to set mag filter.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::SetTextureWrapS(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_S, param);
    GLCHECK("Failed to set texture wrap S.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::SetTextureWrapT(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_T, param);
    GLCHECK("Failed to set texture wrap T.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::SetTextureWrapR(Enum param)
{
    glTexParameteri(type, GL_TEXTURE_WRAP_R, param);
    GLCHECK("Failed to set texture wrap R.");
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Parameteri(Enum param, SInt32 value)
{
    glTexParameteri(type, param, value);
}
_JATTA_EXPORT void Jatta::OpenGL::Texture::Parameterf(Enum param, Float32 value)
{
    glTexParameterf(type, param, value);
}
_JATTA_EXPORT void Jatta::OpenGL::Texture::Parameterfv(Enum param, Float32* value)
{
    glTexParameterfv(type, param, value);
}
_JATTA_EXPORT void Jatta::OpenGL::Texture::Parameteriv(Enum param, SInt32* value)
{
    glTexParameterIiv(type, param, value);
}
_JATTA_EXPORT void Jatta::OpenGL::Texture::ParameterIiv(Enum param, SInt32* value)
{
    glTexParameterIiv(type, param, value);
}
_JATTA_EXPORT void Jatta::OpenGL::Texture::ParameterIuiv(Enum param, UInt32* value)
{
    glTexParameterIuiv(type, param, value);
}

_JATTA_EXPORT void Jatta::OpenGL::Texture::Image2D(SInt32 level, SInt32 internalFormat, Size width, Size height, SInt32 border, Enum format, Enum type, void* data)
{
    glTexImage2D(this->type, level, internalFormat, width, height, border, format, type, data);
    GLCHECK("Failed to set texture 2D image.");
    // TODO: move these to their own methods
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    GLCHECK("Something borked");
}
