// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Texture.cpp
 */

#include "Texture.hpp"
#include "../Images/Format.hpp"

_CGUL_EXPORT CGUL::Assimp::Texture::Texture(aiTexture* texture)
{
    this->texture = texture;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Texture::GetWidth() const
{
    return texture->mWidth;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Texture::GetHeight() const
{
    return texture->mHeight;
}

_CGUL_EXPORT CGUL::Image CGUL::Assimp::Texture::GetImage() const
{
    // Image is stored as ARGB8888, convert it to RGBA8888
    Color*colors = new CGUL::Color[texture->mWidth*texture->mHeight];

    for (unsigned int i = 0; i < texture->mWidth*texture->mHeight; i++)
    {
        colors[i].r = texture->pcData[i].r;
        colors[i].g = texture->pcData[i].g;
        colors[i].b = texture->pcData[i].b;
        colors[i].a = texture->pcData[i].a;
    }

    return Image(ImageFormats::RGBA8, texture->mWidth, texture->mHeight, colors);
}
