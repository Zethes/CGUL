#include "File.h"
#include <fstream>

bool Jatta::File::getText(const std::string& fileName, std::string* result)
{
    std::ifstream file;
    file.open(fileName.c_str(), std::ios::in);
    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    while (!file.eof())
    {
        getline(file, line);
        *result += line + "\n";
    }
    *result = result->substr(0, result->length() - 1);
    file.close();
    return true;
}

bool Jatta::File::getLines(const std::string& fileName, std::vector<std::string>* vector)
{
    std::ifstream file;
    file.open(fileName.c_str(), std::ios::in);
    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    while (!file.eof())
    {
        getline(file, line);
        vector->push_back(line);
    }
    file.close();
    return true;
}

bool Jatta::File::getFileSize(const std::string& fileName, unsigned int* fileSize)
{
    unsigned int begin, end;
    std::ifstream myfile(fileName);
    begin = myfile.tellg();
    myfile.seekg(0, std::ios::end);
    end = myfile.tellg();
    myfile.close();
    *fileSize = (end - begin);
    return true;
}

bool Jatta::File::getData(const std::string& fileName, char* buffer, unsigned int size)
{
    std::ifstream file;
    file.open(fileName.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        return false;
    }
    file.read(buffer, size);
    file.close();
    return true;
}