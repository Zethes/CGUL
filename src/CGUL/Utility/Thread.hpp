// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Thread.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

#ifdef CPP_HAS_STD_THREAD

namespace CGUL
{
    class Thread
    {
    private:
        std::thread* thread;
    public:
        _CGUL_EXPORT Thread();
        _CGUL_EXPORT virtual ~Thread();

        _CGUL_EXPORT void Run();

        _CGUL_EXPORT void Join();
        _CGUL_EXPORT void Detach();

        _CGUL_EXPORT virtual void Main() = 0;
    };
}

#endif

#include "../External/Undefines.hpp"
