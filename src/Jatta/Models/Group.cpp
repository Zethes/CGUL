/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Group.h"

Jatta::Group::Group()
{
	name = "";
	for (UInt32 i = 0; i < 16; i++)
	{
		buffers[i].index = -1;
	}
	vertexCount = 0;
	indices = nullptr;
}

_JATTA_EXPORT void Jatta::Group::Free()
{
	for (UInt32 i = 0; i < 16; i++)
	{
		if (buffers[i].index != -1)
		{
			delete[] (char*)buffers[i].buffer;
			buffers[i].index = -1;
		}
	}
	delete[] this->indices;
	this->indices = nullptr;
}

_JATTA_EXPORT void Jatta::Group::AddBuffer(VertexBuffer buffer)
{
	if (buffer.index >= 16)
	{
		throw std::runtime_error("VertexBuffer index is out of bounds (must be 0-15).");
	}

	buffers[buffer.index] = buffer;
}

_JATTA_EXPORT void Jatta::Group::AddIndexBuffer(UInt32* indices)
{
	this->indices = indices;
}

Jatta::VertexBuffer Jatta::Group::GetBuffer(UInt32 index) const
{
	return buffers[index];
}
