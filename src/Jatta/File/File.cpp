#include "File.h"
#include "../Utility/Encryption.h"

#include <sys/stat.h>
#ifdef WINDOWS
#   include <direct.h>
#   ifdef DeleteFile
#       undef DeletFile
#   endif
#else
#   include <unistd.h>
#endif

// Visual Studio doesn't have this file
// We'll remove it for now until someone musters up enough motivation to repla--ugh i dont want to type anymore
//#include <dirent.h>

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

_JATTA_EXPORT std::vector<Jatta::String> Jatta::File::FindFiles(std::string dir)
{
    std::vector<Jatta::String> ret;

    /*DIR *dp;
    struct dirent *ep;

    dp = opendir(dir.c_str());
    if (dp != NULL)
    {
        while (ep = readdir(dp))
        {
            String path = dir;
            std::string fileName = ep->d_name;
            path += "/" + fileName;
            if (IsFile(path.GetData()))
                ret.push_back(fileName);
        }
        closedir (dp);
    }*/

    return ret;
}
_JATTA_EXPORT std::vector<Jatta::String> Jatta::File::FindFolders(std::string dir)
{
    std::vector<Jatta::String> ret;

    /*DIR *dp;
    struct dirent *ep;

    dp = opendir(dir.c_str());
    if (dp != NULL)
    {
        while (ep = readdir(dp))
        {
            String path = dir;
            std::string fileName = ep->d_name;
            path += "/" + fileName;
            if (IsFolder(path.GetData()))
                ret.push_back(fileName);
        }
        closedir (dp);
    }*/

    return ret;
}

_JATTA_EXPORT bool Jatta::File::Exists(const std::string& fileName)
{
    struct stat fileStat;
    int err = stat(fileName.c_str(), &fileStat);
    if (err != 0) return 0;

    return fileStat.st_size;
}
_JATTA_EXPORT unsigned long long Jatta::File::CRC32(const std::string& fileName)
{
    Jatta::String str;
    GetText(fileName, &str);
    return Encryption::CRC32::String(str);
}
_JATTA_EXPORT Jatta::String Jatta::File::MD5(const std::string& fileName)
{
    Jatta::String str;
    GetText(fileName, &str);
    return Encryption::MD5::String(str);
}
_JATTA_EXPORT int Jatta::File::Size(const std::string& fileName)
{
    struct stat fileStat;
    int err = stat(fileName.c_str(), &fileStat);
    if (err != 0) return false;

    return true;
}
_JATTA_EXPORT bool Jatta::File::IsFolder(const std::string& fileName)
{
    struct stat fileStat;
    int err = stat(fileName.c_str(), &fileStat);
    if (err != 0) return 0;

    return (fileStat.st_mode & S_IFMT) == S_IFDIR;
}
_JATTA_EXPORT bool Jatta::File::IsFile(const std::string& fileName)
{
    return !IsFolder(fileName);
}
_JATTA_EXPORT bool Jatta::File::CreateFolder(const std::string& fileName, bool recursive)
{
    String folderName = fileName;

    if (IsFolder(folderName.GetData())) //Folder exists
        return false;

    if (recursive)
    {
        String up = folderName.SubString(0,folderName.FindLastOf("/"));
        if (up != folderName)
            CreateFolder(up.GetData(), recursive);
    }

#ifdef WINDOWS
    return 0 == mkdir(folderName.GetData().c_str());
#else
    return mkdir(folderName.GetData().c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#endif

    return false;
}
_JATTA_EXPORT bool Jatta::File::DeleteFolder(const std::string& fileName, bool recursive)
{
    if (!IsFolder(fileName))
        return false;

    if (recursive)
    {
        std::vector<Jatta::String> files = FindFiles(fileName);
        std::vector<Jatta::String> folders = FindFolders(fileName);

        //Delete each file.
        for (unsigned int i = 0; i < files.size(); i++)
        {
            String path = fileName;
            path += "/";
            path += files[i];
            if (DeleteFile(path.GetData()) == false)
                return false;
        }

        //Delete each folder.
        for (unsigned int i = 0; i < folders.size(); i++)
        {
            if (folders[i] != "." && folders[i] != "..")
            {
                String path = fileName;
                path += "/";
                path += folders[i];
                if (DeleteFolder(path.GetData(), true) == false)
                    return false;
            }
        }
    }

    rmdir(fileName.c_str());
    return true;
}
_JATTA_EXPORT bool Jatta::File::DeleteFile(const std::string& fileName)
{
    return 0 == unlink(fileName.c_str());
}
_JATTA_EXPORT bool Jatta::File::Copy(const std::string& fileName, const std::string& fileTo)
{
    std::ifstream f1( fileName.c_str(), std::fstream::binary );
    if ( !f1.is_open() ) return false;
    std::ofstream f2( fileTo.c_str(), std::fstream::trunc|std::fstream::binary );
    if ( !f2.is_open() ) return false;
    f2 << f1.rdbuf();
    return true;
}
_JATTA_EXPORT bool Jatta::File::Move(const std::string& fileName, const std::string& fileTo)
{
    bool r = Copy(fileName, fileTo);
    if (r == false)
        return false;
    return DeleteFile(fileName);
}
