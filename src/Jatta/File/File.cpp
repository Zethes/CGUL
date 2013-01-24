#include "File.h"

_JATTA_EXPORT bool Jatta::File::GetText(const std::string& fileName, std::string* result)
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

_JATTA_EXPORT bool Jatta::File::GetText(const String& fileName, String* result)
{
    std::ifstream file;
    file.open(fileName.GetData().c_str(), std::ios::in);
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
    *result = result->SubString(0, result->GetSize() - 1, true);
    file.close();
    return true;
}

_JATTA_EXPORT bool Jatta::File::GetLines(const std::string& fileName, std::vector<std::string>* vector)
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

_JATTA_EXPORT bool Jatta::File::GetLines(const String& fileName, std::vector<String>* vector)
{
    std::ifstream file;
    file.open(fileName.GetData().c_str(), std::ios::in);
    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    while (!file.eof())
    {
        getline(file, line);
        vector->push_back(String(std::move(line)));
    }
    file.close();
    return true;
}

_JATTA_EXPORT bool Jatta::File::GetFileSize(const std::string& fileName, UInt32* fileSize)
{
    std::streamoff begin, end;
    std::ifstream myfile(fileName.c_str());
    begin = myfile.tellg();
    myfile.seekg(0, std::ios::end);
    end = myfile.tellg();
    myfile.close();
    *fileSize = (unsigned int)(end - begin);
    return true;
}

_JATTA_EXPORT bool Jatta::File::GetData(const std::string& fileName, Byte* buffer, UInt32 size)
{
    std::ifstream file;
    file.open(fileName.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        return false;
    }
    file.read((char*)buffer, size);
    file.close();
    return true;
}
