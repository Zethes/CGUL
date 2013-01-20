/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Math/Float4.h"
#include "../Images/Color.h"
#include "Texture.h"
#include "../External/Defines.h"

namespace Jatta
{
    class SubMesh
    {
    public:
        enum Type
        {
            POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON
        };
    private:
        UInt32 vertexArray;
        UInt32 vertexCount;
        Type type;
        UInt32* indices;
        UInt32 indexCount;
        Boolean hasTexture;
        Texture texture;
    public:
        _JATTA_EXPORT SubMesh();

        _JATTA_EXPORT void Setup(Type type, UInt32 vertexCount);

        _JATTA_EXPORT void AddBuffer(Float32* buffer, Byte count, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float2* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float3* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float4* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Color* buffer, UInt32 index);

        _JATTA_EXPORT void SetIndexBuffer(UInt32* buffer, UInt32 size);
        _JATTA_EXPORT void SetTexture(const Texture& texture);

        _JATTA_EXPORT Boolean HasTexture();
        _JATTA_EXPORT Texture GetTexture();

        _JATTA_EXPORT void Draw();
    };
}

#include "../External/Undefines.h"
