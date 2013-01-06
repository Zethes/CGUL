/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "VertexBuffer.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
	struct Group
	{
		String name;
		VertexBuffer buffers[16];
		UInt32 vertexCount;
		UInt32* indices;

		_JATTA_EXPORT Group();

		_JATTA_EXPORT void Free();

		_JATTA_EXPORT void AddBuffer(VertexBuffer buffer);
		_JATTA_EXPORT void AddIndexBuffer(UInt32* indices);

		VertexBuffer GetBuffer(UInt32 index) const;
	};
}

#include "../External/Undefines.h"
