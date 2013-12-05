// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file File.cpp
 */

#include "File.hpp"
#include "../Exceptions/FatalException.hpp"
#include "../Exceptions/FileException.hpp"
#include "../Utility/Encryption.hpp"
#include "../Containers/Vector.hpp"

#include <sys/stat.h>
#ifdef CGUL_WINDOWS
#   include <direct.h>
#   ifdef DeleteFile
#       undef DeleteFile
#   endif
#else
#   include <unistd.h>
#endif

#ifdef CPP_HEADER_DIRENT_H
#   include <dirent.h>
#endif

_CGUL_EXPORT CGUL::Boolean CGUL::File::WriteText(const String& fileName, String string)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"w");
#   else
    FILE* stream = fopen(fileName.GetCString(), "w");
#   endif
    if (stream == NULL)
    {
        return false;
    }

    char* buffer = new char[string.GetSize()];
    memcpy(buffer, string.GetCString(), string.GetSize());

    fwrite(buffer, 1, string.GetSize(), stream);
    fclose(stream);

    delete[] buffer;

    return true;
}

_CGUL_EXPORT CGUL::Boolean CGUL::File::WriteData(const CGUL::String& fileName, Byte* buffer, UInt32 size)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"w");
#   else
    FILE* stream = fopen(fileName.GetCString(), "w");
#   endif
    if (stream == NULL)
    {
        return false;
    }

    fwrite(buffer, 1, size, stream);
    fclose(stream);
    return true;
}

/** @param fileName The file to read.
 *  @param result A pointer to the string to append the data to.
 */
_CGUL_EXPORT void CGUL::File::ReadText(const CGUL::String& fileName, CGUL::String* result)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
        }
    }
    // obtain file size:
    fseek(stream, 0, SEEK_END);
    long fileSize = ftell(stream);
    rewind(stream);

    // allocate memory to contain the whole file:
    char* buffer = new char[fileSize + 1];
    buffer[fileSize] = 0;

    // copy the file into the buffer:
    size_t readResult = fread(buffer, 1, fileSize, stream);
    buffer[readResult] = 0;

    *result += buffer;

    fclose (stream);
    delete[] buffer;
}

/** @param fileName The file to read.
 *  @vector A pointer to the vector to append the lines to.
 */
_CGUL_EXPORT void CGUL::File::ReadLines(const String& fileName, std::vector<CGUL::String>* vector)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
        }
    }
    // obtain file size:
    fseek (stream, 0, SEEK_END);
    long fileSize = ftell(stream);
    rewind(stream);

    // allocate memory to contain the whole file:
    char* buffer = new char[fileSize + 1];

    // copy the file into the buffer:
    size_t readResult = fread(buffer, 1, fileSize, stream);
    buffer[readResult] = '\n';

    char* lineStart = buffer;
    for (size_t i = 0; i < readResult + 1; i++)
    {
        if (buffer[i] == '\n' || buffer[i] == '\r')
        {
            buffer[i++] = 0;
            vector->push_back(lineStart);
            while (buffer[i] == '\n' || buffer[i] == '\r')
            {
                i++;
            }
            lineStart = buffer + i;
        }
    }

    fclose (stream);
    delete[] buffer;
}

/** @param fileName The file to read.
 *  @param buffer The buffer to copy the bytes into.
 *  @param size The size of the buffer or the max amount of bytes to read.
 */
_CGUL_EXPORT void CGUL::File::ReadData(const CGUL::String& fileName, Byte* buffer, UInt32 size)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"rb");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw CGUL::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
        }
    }

    // copy the file into the buffer:
    fread(buffer, 1, size, stream);

    fclose (stream);
}

/** @param fileName The file to get the size of.
 *  @param fileSize A pointer to an integer to put the size into.
 *  @returns True if the size was successfully obtained, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::GetFileSize(const CGUL::String& fileName, UInt32* fileSize)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        return false;
    }
    // obtain file size:
    fseek(stream, 0, SEEK_END);
    if (fileSize != NULL)
    {
        *fileSize = ftell(stream);
    }
    rewind(stream);
    fclose(stream);

    return true;
}

/** @param fileName The file to get the size of.
 *  @returns The size of the file, or 0 if the size could not be obtained.
 *  @note There is a conflict in logic if a file is empty or if it does not exist.  Both cases will
 *  return 0.  Consider using the other GetFileSize function which returns a boolean value if the
 *  size was successfully obtained.
 */
_CGUL_EXPORT CGUL::UInt32 CGUL::File::GetFileSize(const CGUL::String& fileName)
{
#   ifdef CGUL_WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        return 0;
    }
    // obtain file size:
    fseek(stream, 0, SEEK_END);
    UInt32 fileSize = ftell(stream);
    rewind(stream);
    fclose(stream);

    return fileSize;
}

#include <iostream>
_CGUL_EXPORT void CGUL::File::FindFiles(const String& path, FixedList< String >* files)
{
#   ifdef CPP_HEADER_DIRENT_H
    String fixedPath = path;
    if (!fixedPath.EndsWith("/") && !fixedPath.BeginsWith("\\"))
    {
        // Prefer unix style paths, since windows accepts it (for the most part)
        if (fixedPath.Contains("/"))
        {
            fixedPath += "/";
        }
        else
        {
            fixedPath += "\\";
        }
    }
    struct dirent* entry = NULL;
    DIR* directory = NULL;
    directory = opendir(fixedPath.GetCString());
    if (directory == NULL)
    {
        return;
    }
    Size count = 0;
    while (entry = readdir(directory))
    {
        String entryName(entry->d_name);
        if (IsFile(fixedPath + entryName))
        {
            count++;
        }
    }
    files->SetSize(count);
    rewinddir(directory);
    count = 0;
    while (entry = readdir(directory))
    {
        String entryName(entry->d_name);
        if (IsFile(fixedPath + entryName))
        {
            files->Set(count++, entryName);
        }
    }
    closedir(directory);
#   elif CGUL_WINDOWS
    // TODO: handle FindFiles on windows without dirent
#   else
    // TODO: panic?
#   endif
}

_CGUL_EXPORT void CGUL::File::FindDirectories(const String& path, FixedList< String >* directories)
{
#   ifdef CPP_HEADER_DIRENT_H
    String fixedPath = path;
    if (!fixedPath.EndsWith("/") && !fixedPath.BeginsWith("\\"))
    {
        // Prefer unix style paths, since windows accepts it (for the most part)
        if (fixedPath.Contains("/"))
        {
            fixedPath += "/";
        }
        else
        {
            fixedPath += "\\";
        }
    }
    struct dirent* entry = NULL;
    DIR* directory = NULL;
    directory = opendir(path.GetCString());
    if (directory == NULL)
    {
        return;
    }
    Size count = 0;
    while (entry = readdir(directory))
    {
        String entryName(entry->d_name);
        if (IsDirectory(fixedPath + entryName) && entryName != "." && entryName != "..")
        {
            count++;
        }
    }
    directories->SetSize(count);
    rewinddir(directory);
    count = 0;
    while (entry = readdir(directory))
    {
        String entryName(entry->d_name);
        if (IsDirectory(fixedPath + entryName) && entryName != "." && entryName != "..")
        {
            directories->Set(count++, entryName);
        }
    }
    closedir(directory);
#   elif CGUL_WINDOWS
    // TODO: handle FindFiles on windows without dirent
#   else
    // TODO: panic?
#   endif
}

/** @param fileName The name of the file to check for.
 *  @returns True if the file exists, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::Exists(const CGUL::String& fileName)
{
#   ifdef CGUL_WINDOWS
    DWORD attributes = ::GetFileAttributesW(fileName._ToWideString().c_str());
    return (attributes != INVALID_FILE_ATTRIBUTES);
#   else
    return access(fileName.GetCString(), F_OK) != -1;
#   endif
}

/** @details Determines the READ, WRITE, and EXECUTE permissions of the current user for the given
 *  file.  Simply checking if a file exists is not enough information to know if that file can be
 *  operated on.
 */
_CGUL_EXPORT CGUL::Enum CGUL::File::GetAccess(const CGUL::String& fileName)
{
#   ifdef CGUL_WINDOWS
    return 7; // TODO: File::GetAccess for windows
#   else
    return ((access(fileName.GetCString(), R_OK) != -1) * Access::READ) | ((access(fileName.GetCString(), W_OK) != -1) * Access::WRITE) | ((access(fileName.GetCString(), X_OK) != -1) * Access::EXECUTE);
#   endif
}

_CGUL_EXPORT unsigned long long CGUL::File::CRC32(const CGUL::String& fileName)
{
    CGUL::String str;
    ReadText(fileName, &str);
    return Encryption::CRC32::String(str);
}

_CGUL_EXPORT CGUL::String CGUL::File::MD5(const CGUL::String& fileName)
{
    CGUL::String str;
    ReadText(fileName, &str);
    return Encryption::MD5::String(str);
}

/** @param fileName The filename to check.
 *  @returns True if the filename is a directory, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::IsDirectory(const CGUL::String& fileName)
{
#   ifdef CGUL_WINDOWS
    DWORD attributes = ::GetFileAttributesW(fileName._ToWideString().c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES)
    {
        return false;
    }
    return ((attributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
#   else
    struct stat fileStat;
    int err = stat(fileName.GetCString(), &fileStat);
    if (err != 0)
    {
        return false;
    }

    return (fileStat.st_mode & S_IFMT) == S_IFDIR;
#   endif
}

/** @param fileName The filename to check.
 *  @returns True if the filename is a file, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::IsFile(const CGUL::String& fileName)
{
    return !IsDirectory(fileName);
}

_CGUL_EXPORT CGUL::Boolean CGUL::File::CreateDirectory(const CGUL::String& fileName, bool recursive)
{
    String directoryName = fileName;

    if (IsDirectory(directoryName.GetData())) //Directory exists
    {
        return false;
    }

    if (recursive)
    {
        String up = directoryName.SubString(0, directoryName.FindLastOf("/"));
        if (up != directoryName)
        {
            CreateDirectory(up.GetData(), recursive);
        }
    }

#ifdef CGUL_WINDOWS
    return 0 == _wmkdir(directoryName._ToWideString().c_str());
#else
    return 0 == mkdir(directoryName.GetData().c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#endif
}

_CGUL_EXPORT CGUL::Boolean CGUL::File::DeleteDirectory(const CGUL::String& fileName, bool recursive)
{
    if (!IsDirectory(fileName))
    {
        return false;
    }

    if (recursive)
    {
        Vector< CGUL::String > files;
        FindFiles(fileName, &files);
        Vector< CGUL::String > directories;
        FindDirectories(fileName, &directories);

        //Delete each file.
        for (unsigned int i = 0; i < files.size(); i++)
        {
            String path = fileName;
            path += "/";
            path += files[i];
            if (DeleteFile(path.GetData()) == false)
            {
                return false;
            }
        }

        //Delete each directory.
        for (unsigned int i = 0; i < directories.size(); i++)
        {
            if (directories[i] != "." && directories[i] != "..")
            {
                String path = fileName;
                path += "/";
                path += directories[i];
                if (DeleteDirectory(path.GetData(), true) == false)
                {
                    return false;
                }
            }
        }
    }

#   ifdef CGUL_WINDOWS
    return 0 == _wrmdir(fileName._ToWideString().c_str());
#   else
    return 0 == rmdir(fileName.GetCString());
#   endif
}

/** @param fileName The file to delete.
 *  @returns True if the file was successfully deleted, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::DeleteFile(const CGUL::String& fileName)
{
#   ifdef CGUL_WINDOWS
    return ::DeleteFileW(fileName._ToWideString().c_str()) != 0;
#   else
    return 0 == unlink(fileName.GetCString());
#   endif
}

/** @param fileName The target file.
 *  @param fileTo The destination file.
 *  @returns True if the file was successfully copied, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::Copy(const CGUL::String& fileName, const CGUL::String& fileTo)
{
#   ifdef CGUL_WINDOWS
    return ::CopyFileW(fileName._ToWideString().c_str(), fileTo._ToWideString().c_str(), false) != 0;
#   else
    std::ifstream f1(fileName.GetCString(), std::fstream::binary);
    if (!f1.is_open())
    {
        return false;
    }
    std::ofstream f2(fileTo.GetCString(), std::fstream::trunc|std::fstream::binary);
    if (!f2.is_open())
    {
        return false;
    }
    f2 << f1.rdbuf();
    return true;
#   endif
}

/** @param fileName The target file.
 *  @param fileTo The destination file.
 *  @returns True if the file was successfully moved, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::File::Move(const CGUL::String& fileName, const CGUL::String& fileTo)
{
    bool r = Copy(fileName, fileTo);
    if (r == false)
    {
        return false;
    }
    return DeleteFile(fileName);
}
