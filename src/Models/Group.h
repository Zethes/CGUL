#pragma once
#include "VertexBuffer.h"
#include <string>
#include <vector>
#include <memory>

struct Group
{
    std::string name;
    std::vector<std::shared_ptr<VertexBuffer>> buffers;
};