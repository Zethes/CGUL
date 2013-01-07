/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
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
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetData());
    glGenerateMipmap(GL_TEXTURE_2D);
    this->width = image.GetWidth();
    this->height = image.GetHeight();
    _JATTA_DEBUG_LN(image.GetWidth() << ", " << image.GetHeight());
}

_JATTA_EXPORT void Jatta::Texture::CreateCubeMap(const Jatta::Image& negX, const Jatta::Image& posX, const Jatta::Image& negY, const Jatta::Image& posY, const Jatta::Image& negZ, const Jatta::Image& posZ)
{
	glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->texture);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    GLenum cubes[6] = {
    		GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
    };

    const Jatta::Image* images[6] = {
    		&posX, &negX,
    		&posY, &negY,
    		&posZ, &negZ
    };

    for (int i = 0; i < 6; i++)
    {
    	glTexImage2D(cubes[i], 0, GL_RGBA, images[i]->GetWidth(), images[i]->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, images[i]->GetData());
    }
    this->width = 0;
    this->height = 0;
    glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
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
