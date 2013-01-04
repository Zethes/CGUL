/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
	struct VertexBuffer
	{
		UInt32 index;
		UInt32 size;
		void* buffer;

		VertexBuffer();
	};
}

#include "../External/Undefines.h"
