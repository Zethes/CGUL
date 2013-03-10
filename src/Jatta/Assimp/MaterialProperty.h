 /* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../Assimp/Assimp.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class MaterialProperty
        {
            _JATTA_AIMATERIALPROPERTY matProp;
        public:
            _JATTA_EXPORT MaterialProperty(_JATTA_AIMATERIALPROPERTY matProp);

            _JATTA_EXPORT String GetKey();
            _JATTA_EXPORT UInt32 GetSemantic();
            _JATTA_EXPORT UInt32 GetIndex();

            _JATTA_EXPORT UInt32 GetDataLength();
            _JATTA_EXPORT UInt32 GetType();
            _JATTA_EXPORT char* GetData();
        };
    }
}

#include "../External/Undefines.h"