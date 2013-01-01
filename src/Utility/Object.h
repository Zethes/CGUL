//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Object
    {
    public:
        _JATTA_EXPORT static void setAllocator(void* (*func)(Jatta::Size));
        _JATTA_EXPORT static void setDestructor(void (*func)(void*));

        _JATTA_EXPORT static void* allocate(Jatta::Size size);
        _JATTA_EXPORT static void destruct(void* address);

        _JATTA_EXPORT virtual void dispose();
    };
}

// TODO: inherit each object from this & link STL allocators to allocate function

#include "../External/Undefines.h"
