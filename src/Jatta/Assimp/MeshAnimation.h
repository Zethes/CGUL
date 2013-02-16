/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float3.h"
#include "../Math/Matrix.h"
#include "../Math/Quaternion.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        struct MeshKey
        {
            double time;
            Jatta::UInt32 index;
        };

        class MeshAnimation
        {
        private:
            _JATTA_AIMESHANIM meshAnim;
        public:
            _JATTA_EXPORT MeshAnimation(_JATTA_AIMESHANIM meshAnim);
    
            _JATTA_EXPORT Jatta::String GetName();
            _JATTA_EXPORT Jatta::UInt32 GetKeyCount();
            _JATTA_EXPORT MeshKey* GetKeys();
        };
    }
}

#include "../External/Undefines.h"
