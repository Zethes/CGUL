/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef _CPP_HEADER_THREAD

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    class Thread
    {
    private:
        std::thread* thread;
    public:
        _JATTA_EXPORT Thread();
        _JATTA_EXPORT virtual ~Thread();

        _JATTA_EXPORT void Run();

        _JATTA_EXPORT void Join();
        _JATTA_EXPORT void Detach();

        _JATTA_EXPORT virtual void Main() = 0;
    };
}

#include "../External/Undefines.h"

#endif