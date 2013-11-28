// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file VertexWeight.cpp
 */

#include "VertexWeight.hpp"

_CGUL_EXPORT CGUL::Assimp::VertexWeight::VertexWeight(aiVertexWeight* weight)
{
    this->weight = weight;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::VertexWeight::GetVertexId()
{
    return weight->mVertexId;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::VertexWeight::GetWeight()
{
    return weight->mWeight;
}
