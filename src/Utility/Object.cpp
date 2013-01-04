/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#include "Object.h"

static void* DefaultAllocator(Jatta::Size size)
{
    return malloc(size);
}

static void DefaultDestructor(void* address)
{
    free(address);
}

static void* (*allocator)(Jatta::Size) = DefaultAllocator;
static void (*destructor)(void*) = DefaultDestructor;

_JATTA_EXPORT void Jatta::Object::SetAllocator(void* (*func)(Size))
{
    ::allocator = func;
}

_JATTA_EXPORT void Jatta::Object::SetDestructor(void (*func)(void*))
{
    ::destructor = func;
}

_JATTA_EXPORT void* Jatta::Object::Allocate(Jatta::Size size)
{
    return ::allocator(size);
}

_JATTA_EXPORT void Jatta::Object::Destruct(void* address)
{
    ::destructor(address);
}
