/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "MeshAnimation.h"
#include "NodeAnimation.h"
#include "../Math/Float3.h"
#include "../Math/Matrix.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class Animation
        {
        private:
            _JATTA_AIANIMATION animation;
        public:
            _JATTA_EXPORT Animation(_JATTA_AIANIMATION animation);
    
            _JATTA_EXPORT Jatta::String GetName();
            _JATTA_EXPORT double GetDuration();
            _JATTA_EXPORT double GetTicksPerSecond();
            _JATTA_EXPORT Jatta::UInt32 GetChannelCount();
            _JATTA_EXPORT Jatta::UInt32 GetMeshChannelCount();

            _JATTA_EXPORT NodeAnimation* GetChannels();
            _JATTA_EXPORT MeshAnimation* GetMeshChannels();
        };
    }
}

#include "../External/Undefines.h"
