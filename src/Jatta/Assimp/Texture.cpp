/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#include "Texture.h"

_JATTA_EXPORT Jatta::Assimp::Texture::Texture(aiTexture* texture)
{
    this->texture = texture;
}

#include <iostream> // TODO: remove iostream
_JATTA_EXPORT void Jatta::Assimp::Texture::DoStuff() const
{
	std::cout << "texture->mHeight: " << texture->mHeight << std::endl;
	std::cout << "texture->mWidth: " << texture->mWidth<< std::endl;
	std::cout << "texture->achFormatHint: " << texture->achFormatHint << std::endl;
}

#endif
