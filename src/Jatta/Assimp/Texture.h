/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiTexture
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