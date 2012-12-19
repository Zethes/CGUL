#pragma once

struct VertexBuffer
{
    enum class Type
    {
        POSITION, TEXCOORD, NORMAL, COLOR
    } type;
    unsigned int size;
    float* buffer;
};