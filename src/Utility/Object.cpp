#include "Object.h"

static void* defaultAllocator(Jatta::Size size)
{
    return malloc(size);
}

static void defaultDestructor(void* address)
{
    free(address);
}

static void* (*allocator)(Jatta::Size) = defaultAllocator;
static void (*destructor)(void*) = defaultDestructor;

_JATTA_EXPORT void Jatta::Object::setAllocator(void* (*func)(Size))
{
    ::allocator = func;
}

_JATTA_EXPORT void Jatta::Object::setDestructor(void (*func)(void*))
{
    ::destructor = func;
}

_JATTA_EXPORT void* Jatta::Object::allocate(Jatta::Size size)
{
    return ::allocator(size);
}

_JATTA_EXPORT void Jatta::Object::destruct(void* address)
{
    ::destructor(address);
}