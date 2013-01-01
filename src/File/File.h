//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    namespace File
    {
        _JATTA_EXPORT bool getText(const std::string& fileName, std::string* result);
        _JATTA_EXPORT bool getLines(const std::string& fileName, std::vector<std::string>* vector);
        _JATTA_EXPORT bool getFileSize(const std::string& fileName, unsigned int* fileSize);
        _JATTA_EXPORT bool getData(const std::string& fileName, char* buffer, unsigned int size);
    }
}

#include "../External/Undefines.h"