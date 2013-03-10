/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../Math/Matrix.h"
#include "../Math/Float3.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class Node
        {
            _JATTA_AINODE node;
        public:
            _JATTA_EXPORT Node(_JATTA_AINODE node);

            _JATTA_EXPORT String GetName() const;

            _JATTA_EXPORT Matrix GetTransformation() const;

            _JATTA_EXPORT Node GetParent() const;
            _JATTA_EXPORT UInt32 GetChildrenCount() const;
            _JATTA_EXPORT UInt32 GetMeshesCount() const;

            _JATTA_EXPORT Node GetChild(UInt32 index) const;
            _JATTA_EXPORT UInt32 GetMesh(UInt32 index) const;

            _JATTA_EXPORT Node FindNode(String name);
        };
    }
}

#include "../External/Undefines.h"
