// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Node.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Math/Matrix.hpp"
#include "../Math/Vector3.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Node
        {
            _CGUL_AINODE node;
        public:
            _CGUL_EXPORT Node(_CGUL_AINODE node);

            _CGUL_EXPORT String GetName() const;

            _CGUL_EXPORT Matrix GetTransformation() const;

            _CGUL_EXPORT Node GetParent() const;
            _CGUL_EXPORT UInt32 GetChildrenCount() const;
            _CGUL_EXPORT UInt32 GetMeshesCount() const;

            _CGUL_EXPORT Node GetChild(UInt32 index) const;
            _CGUL_EXPORT UInt32 GetMesh(UInt32 index) const;

            _CGUL_EXPORT Node FindNode(String name);
        };
    }
}

#include "../External/Undefines.hpp"
