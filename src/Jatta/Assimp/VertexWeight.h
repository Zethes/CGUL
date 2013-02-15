/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float3.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiMesh
        class VertexWeight
        {
        private:
            _JATTA_AIVERTEXWEIGHT weight;
        public:
            _JATTA_EXPORT VertexWeight(_JATTA_AIVERTEXWEIGHT weight);

			_JATTA_EXPORT Jatta::UInt32 GetVertexId();
			_JATTA_EXPORT Jatta::Float32 GetWeight();
        };
    }
}

#include "../External/Undefines.h"
