#pragma once
#include "Color.h"
#include <string>

namespace Jatta
{
    struct Image
    {
    protected:
        Color* colors;
        unsigned int width, height;
    public:
        static bool isPng(const std::string& fileName);

        virtual bool load(const std::string& fileName);

        const unsigned char* getData();
        unsigned int getWidth();
        unsigned int getHeight();
    };
}