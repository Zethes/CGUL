//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Math/Float4.h"
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

        std::forward_list<UInt32> vertexBuffers;
    public:
        _JATTA_EXPORT SubMesh(Type type, UInt32 vertexCount);

        _JATTA_EXPORT void addBuffer(Jatta::Float2* buffer, UInt32 index);
        _JATTA_EXPORT void addBuffer(Jatta::Float3* buffer, UInt32 index);
        _JATTA_EXPORT void addBuffer(Jatta::Float4* buffer, UInt32 index);

        _JATTA_EXPORT void setIndexBuffer(UInt32* buffer, UInt32 size);

        _JATTA_EXPORT void draw();
    };
}

#include "../External/Undefines.h"