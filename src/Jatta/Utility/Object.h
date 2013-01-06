/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Object
    {
    public:
        _JATTA_EXPORT static void SetAllocator(void* (*func)(Jatta::Size));
        _JATTA_EXPORT static void SetDestructor(void (*func)(void*));

        _JATTA_EXPORT static void* Allocate(Jatta::Size size);
        _JATTA_EXPORT static void Destruct(void* address);

        _JATTA_EXPORT virtual void Dispose();
    };
}

// TODO: inherit each object from this & link STL allocators to allocate function

#include "../External/Undefines.h"
