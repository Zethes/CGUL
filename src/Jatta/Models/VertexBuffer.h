/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct VertexBuffer
    {
        // TODO: remove this, replaced by Assimp
        
        UInt32 index;
        UInt32 size;
        void* buffer;

        VertexBuffer();
    };
}

#include "../External/Undefines.h"
