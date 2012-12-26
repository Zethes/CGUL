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

void Jatta::Object::setAllocator(void* (*func)(Size))
{
    ::allocator = func;
}

void Jatta::Object::setDestructor(void (*func)(void*))
{
    ::destructor = func;
}

void* Jatta::Object::allocate(Jatta::Size size)
{
    return ::allocator(size);
}

void Jatta::Object::destruct(void* address)
{
    ::destructor(address);
}