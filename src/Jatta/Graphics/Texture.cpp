/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#include "Texture.h"

#include <GL/glew.h>

_JATTA_EXPORT Jatta::Texture::Texture()
{
}

_JATTA_EXPORT void Jatta::Texture::Create(const Jatta::Image& image)
{
    _JATTA_DEBUG_LN(image.GetWidth() << ", " << image.GetHeight());
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetData());
    this->width = image.GetWidth();
    this->height = image.GetHeight();
    _JATTA_DEBUG_LN(image.GetWidth() << ", " << image.GetHeight());
}

_JATTA_EXPORT unsigned int Jatta::Texture::GetTexture() const
{
    return this->texture;
}

_JATTA_EXPORT unsigned int Jatta::Texture::GetWidth() const
{
    return width;
}

_JATTA_EXPORT unsigned int Jatta::Texture::GetHeight() const
{
    return height;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Texture::GetSize() const
{
    return Jatta::Float2((float)width, (float)height);
}
