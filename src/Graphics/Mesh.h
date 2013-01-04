/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "SubMesh.h"
#include "Graphics.h"
#include "../Models/Model.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Mesh
    {
    private:
    	std::vector<SubMesh*> meshes;
    public:
    	_JATTA_EXPORT static Mesh MakeBox(Float2 size, Color color, Float2 uv1, Float2 uv2, Float2 uv3, Float2 uv4);
    	_JATTA_EXPORT static Mesh MakeBox(Float2 size, Color color1, Color color2, Color color3, Color color4, Float2 uv1, Float2 uv2, Float2 uv3, Float2 uv4);
    	_JATTA_EXPORT static Mesh MakeCube(Float3 size);
    	_JATTA_EXPORT static Mesh MakeSphere(Float32 radius, UInt32 slices, UInt32 stacks);
    	_JATTA_EXPORT static Mesh MakeTorus(Float32 innerRadius, Float32 outerRadius, UInt32 nsides, UInt32 rings);
    	_JATTA_EXPORT static Mesh MakeTeapot(Float3 size, Color color);

        _JATTA_EXPORT Mesh();

        //_JATTA_EXPORT void operator=(const Mesh& operand); // TODO: this

        _JATTA_EXPORT void Create(const Model& model);

        _JATTA_EXPORT void AddMesh(SubMesh*mesh);
        _JATTA_EXPORT void Draw();
    };
}

#include "../External/Undefines.h"
