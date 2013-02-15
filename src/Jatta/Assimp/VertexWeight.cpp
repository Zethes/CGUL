/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "VertexWeight.h"

_JATTA_EXPORT Jatta::Assimp::VertexWeight::VertexWeight(aiVertexWeight* weight)
{
	this->weight = weight;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::VertexWeight::GetVertexId()
{
	return weight->mVertexId;
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::VertexWeight::GetWeight()
{
	return weight->mWeight;
}
