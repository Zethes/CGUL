#pragma once

#include "Image.h"

namespace Jatta
{
    class Png : public Image
    {
    public:
        static bool isValid(const char* buffer, unsigned int length);
        static bool isValid(const std::string& fileName);

        bool load(const std::string& fileName);
    };
}