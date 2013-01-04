/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "Group.h"
#include "VertexBuffer.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Model
    {
    protected:
    	std::vector<Group> groups;
    public:
        _JATTA_EXPORT Model();
        _JATTA_EXPORT ~Model();

        _JATTA_EXPORT void Setup(UInt32 vertexCount);
        _JATTA_EXPORT void Free();

        _JATTA_EXPORT void LoadObj(const std::string& fileName);

        _JATTA_EXPORT void AddGroup(const Group& group);

        _JATTA_EXPORT UInt32 GetGroupCount() const;
        _JATTA_EXPORT Group GetGroup(UInt32 index) const;
    };
};

#include "../External/Undefines.h"
