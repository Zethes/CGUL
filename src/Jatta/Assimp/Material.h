/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Assimp/Assimp.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiMaterial
        class Material
        {
            _JATTA_AIMATERIAL material;
        public:
            _JATTA_EXPORT Material(_JATTA_AIMATERIAL material);

            _JATTA_EXPORT UInt32 GetTextureCount(Enum type);
            _JATTA_EXPORT Jatta::String GetTexturePath(Enum type, UInt32 index);
        };
    }
}

#include "../External/Undefines.h"