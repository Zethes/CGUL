/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "VertexWeight.h"
#include "../Math/Float3.h"
#include "../Math/Matrix.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiMesh
        class Bone
        {
        private:
            _JATTA_AIBONE bone;
        public:
            _JATTA_EXPORT Bone(_JATTA_AIBONE bone);

			_JATTA_EXPORT Jatta::String GetName();
			
			_JATTA_EXPORT Jatta::UInt32 GetWeightCount();
			_JATTA_EXPORT Jatta::Assimp::VertexWeight GetWeight(Jatta::UInt32 id);
			
			_JATTA_EXPORT Jatta::Matrix GetOffsetMatrix();
        };
    }
}

#include "../External/Undefines.h"
