/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "ImageFormats.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct ImageInfo
    {
    public:
        ImageFormat Format;
        UInt32 Width;
        UInt32 Height;
        UInt32 MipmapCount;
    };
}
#include "../External/Undefines.h"