/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Matrix.h"
#include "../Math/Quaternion.h"
#include "../Math/Vector3.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        struct MeshKey
        {
            double time;
            Jatta::UInt32 index;
        };
    }
}

#include "../External/Undefines.h"
