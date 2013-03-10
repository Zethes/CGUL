/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Texture.h"

_JATTA_EXPORT Jatta::Assimp::Texture::Texture(aiTexture* texture)
{
    this->texture = texture;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Texture::GetWidth() const
{
    return texture->mWidth;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Texture::GetHeight() const
{
    return texture->mHeight;
}

_JATTA_EXPORT Jatta::Image Jatta::Assimp::Texture::GetImage() const
{  
    //Image is stored as ARGB8888, convert it to RGBA8888
    Color*colors = new Jatta::Color[texture->mWidth*texture->mHeight];

    for (unsigned int i = 0; i < texture->mWidth*texture->mHeight; i++)
    {
        colors[i].r = texture->pcData[i].r;
        colors[i].g = texture->pcData[i].g;
        colors[i].b = texture->pcData[i].b;
        colors[i].a = texture->pcData[i].a;
    }

    return Image(colors, texture->mWidth, texture->mHeight);
}