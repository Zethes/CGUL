#pragma once
#include <string>
#include <vector>

namespace Jatta
{
    namespace File
    {
        bool getText(const std::string& fileName, std::string* result);
        bool getLines(const std::string& fileName, std::vector<std::string>* vector);
        bool getFileSize(const std::string& fileName, unsigned int* fileSize);
        bool getData(const std::string& fileName, char* buffer, unsigned int size);
    }
}