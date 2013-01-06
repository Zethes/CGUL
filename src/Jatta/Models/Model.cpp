/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#include "Model.h"

_JATTA_EXPORT Jatta::Model::Model()
{
}

_JATTA_EXPORT Jatta::Model::~Model()
{
	Free();
}

_JATTA_EXPORT void Jatta::Model::Free()
{
	for (auto it = groups.begin(); it != groups.end(); it++)
	{
		it->Free();
	}
	groups.clear();
}

_JATTA_EXPORT void Jatta::Model::AddGroup(const Group& group)
{
	groups.push_back(group);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Model::GetGroupCount() const
{
	return groups.size();
}

_JATTA_EXPORT Jatta::Group Jatta::Model::GetGroup(UInt32 index) const
{
	return groups.at(index);
}
