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
        enum class Type
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
        SubMesh(Type type, UInt32 vertexCount);

        void addBuffer(Jatta::Float2* buffer, UInt32 index);
        void addBuffer(Jatta::Float3* buffer, UInt32 index);
        void addBuffer(Jatta::Float4* buffer, UInt32 index);

        void setIndexBuffer(UInt32* buffer, UInt32 size);

        void draw();
    };
}

#include "../External/Undefines.h"