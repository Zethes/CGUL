/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#pragma once
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        class Texture
        {
            _JATTA_AITEXTURE texture;
        public:
            _JATTA_EXPORT Texture(_JATTA_AITEXTURE texture);

            _JATTA_EXPORT void DoStuff() const;
        };
    }
}

#include "../External/Undefines.h"
#endif
