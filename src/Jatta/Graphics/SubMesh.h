/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Math/Float4.h"
#include "../Images/Color.h"
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
    public:
        _JATTA_EXPORT SubMesh();

        void Setup(Type type, UInt32 vertexCount);

        _JATTA_EXPORT void AddBuffer(Float32* buffer, Byte count, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float2* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float3* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Float4* buffer, UInt32 index);
        _JATTA_EXPORT void AddBuffer(Jatta::Color* buffer, UInt32 index);

        _JATTA_EXPORT void SetIndexBuffer(UInt32* buffer, UInt32 size);

        _JATTA_EXPORT void Draw();
    };
}

#include "../External/Undefines.h"
