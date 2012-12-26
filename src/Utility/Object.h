//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Object
    {
    public:
        static void setAllocator(void* (*func)(Jatta::Size));
        static void setDestructor(void (*func)(void*));

        static void* allocate(Jatta::Size size);
        static void destruct(void* address);
    };
}

// TODO: inherit each object from this & link STL allocators to allocate function

#include "../External/Undefines.h"
