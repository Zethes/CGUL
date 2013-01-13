/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Buffer
        {
            UInt32 buffer;
        public:
            _JATTA_EXPORT Buffer();

            _JATTA_EXPORT void Create();
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID();

            _JATTA_EXPORT void Bind(Enum target);
            _JATTA_EXPORT void Unbind(Enum target);
        };
    }
}
#include "../External/Undefines.h"