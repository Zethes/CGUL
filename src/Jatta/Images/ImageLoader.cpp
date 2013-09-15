/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "ImageLoader.h"

_JATTA_EXPORT Jatta::ImageLoader::ImageLoader(const String& filename)
{
    file = filename; 
} 
_JATTA_EXPORT Jatta::ImageLoader::~ImageLoader()
{
}

_JATTA_EXPORT Jatta::String Jatta::ImageLoader::GetFile() const
{
    return file;
}