/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Texture.h"

_JATTA_EXPORT Jatta::Assimp::Texture::Texture(aiTexture* texture)
{
    this->texture = texture;
}

_JATTA_EXPORT void Jatta::Assimp::Texture::DoStuff() const
{
}