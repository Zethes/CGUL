/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"

#include "../File/File.h"

#include "Color.h"
#define XMD_H
#include <jpeglib.h>
#include <stdlib.h>

_JATTA_EXPORT bool Jatta::Image::IsJpg(const Jatta::String& fileName)
{
    return false;
}

_JATTA_EXPORT bool Jatta::Image::LoadJpg(const Jatta::String& fileName, UInt32 flags)
{
    //TODO: Loading JPGs
    return false;
}

_JATTA_EXPORT bool Jatta::Image::SaveJpg(const Jatta::String& fileName)
{
    // TODO: Saving JPGS
    return false;
}
