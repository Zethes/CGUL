//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "VertexBuffer.h"
#include "../External/Defines.h"

struct Group
{
    std::string name;
    std::vector<std::shared_ptr<VertexBuffer>> buffers;
};

#include "../External/Undefines.h"