#include "File.h"
#include "../Exceptions/FatalException.h"
#include "../Exceptions/FileException.h"
#include "../Utility/Encryption.h"

#include <sys/stat.h>
#ifdef WINDOWS
#   include <direct.h>
#   ifdef DeleteFile
#       undef DeleteFile
#   endif
#else
#   include <unistd.h>
#endif

// Visual Studio doesn't have this file
// We'll remove it for now until someone musters up enough motivation to repla--ugh i dont want to type anymore
//#include <dirent.h>

_JATTA_EXPORT Jatta::Boolean Jatta::File::WriteText(const String& fileName, String string)
{
#   ifdef WINDOWS
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

    return true;
}

_JATTA_EXPORT Jatta::Boolean Jatta::File::WriteData(const Jatta::String& fileName, Byte* buffer, UInt32 size)
{
#   ifdef WINDOWS
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
_JATTA_EXPORT void Jatta::File::ReadText(const Jatta::String& fileName, Jatta::String* result)
{
#   ifdef WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
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
_JATTA_EXPORT void Jatta::File::ReadLines(const String& fileName, std::vector<Jatta::String>* vector)
{
#   ifdef WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"r");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
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
_JATTA_EXPORT void Jatta::File::ReadData(const Jatta::String& fileName, Byte* buffer, UInt32 size)
{
#   ifdef WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"rb");
#   else
    FILE* stream = fopen(fileName.GetCString(), "r");
#   endif
    if (stream == NULL)
    {
        if (!Exists(fileName))
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::FILE_DOESNT_EXIST);
        }
        else
        {
            throw Jatta::FileException(fileName, FileExceptionCode::FAILED_FILE_READ, FileExceptionReason::PERMISSION_DENIED);
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
_JATTA_EXPORT Jatta::Boolean Jatta::File::GetFileSize(const Jatta::String& fileName, UInt32* fileSize)
{
#   ifdef WINDOWS
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

    return true;
}

/** @param fileName The file to get the size of.
 *  @returns The size of the file, or 0 if the size could not be obtained.
 *  @note There is a conflict in logic if a file is empty or if it does not exist.  Both cases will
 *  return 0.  Consider using the other GetFileSize function which returns a boolean value if the
 *  size was successfully obtained.
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::File::GetFileSize(const Jatta::String& fileName)
{
#   ifdef WINDOWS
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

    return fileSize;
}

// TODO: File::FindFiles
_JATTA_EXPORT std::vector<Jatta::String> Jatta::File::FindFiles(Jatta::String dir)
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

// TODO: File::FindFolders
_JATTA_EXPORT std::vector<Jatta::String> Jatta::File::FindFolders(Jatta::String dir)
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

/** @param fileName The name of the file to check for.
 *  @returns True if the file exists, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::Exists(const Jatta::String& fileName)
{
#   ifdef WINDOWS
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
_JATTA_EXPORT Jatta::Enum Jatta::File::GetAccess(const Jatta::String& fileName)
{
#   ifdef WINDOWS
    return 7; // TODO: File::GetAccess for windows
#   else
    return ((access(fileName.GetCString(), R_OK) != -1) * Access::READ) | ((access(fileName.GetCString(), W_OK) != -1) * Access::WRITE) | ((access(fileName.GetCString(), X_OK) != -1) * Access::EXECUTE);
#   endif
}

_JATTA_EXPORT unsigned long long Jatta::File::CRC32(const Jatta::String& fileName)
{
    Jatta::String str;
    ReadText(fileName, &str);
    return Encryption::CRC32::String(str);
}

_JATTA_EXPORT Jatta::String Jatta::File::MD5(const Jatta::String& fileName)
{
    Jatta::String str;
    ReadText(fileName, &str);
    return Encryption::MD5::String(str);
}

/** @param fileName The filename to check.
 *  @returns True if the filename is a directory, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::IsFolder(const Jatta::String& fileName)
{
#   ifdef WINDOWS
    DWORD attributes = ::GetFileAttributesW(fileName._ToWideString().c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES)
    {
        return false;
    }
    return ((attributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
#   else
    struct stat fileStat;
    int err = stat(fileName.GetCString(), &fileStat);
    if (err != 0) return 0;

    return (fileStat.st_mode & S_IFMT) == S_IFDIR;
#   endif
}

/** @param fileName The filename to check.
 *  @returns True if the filename is a file, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::IsFile(const Jatta::String& fileName)
{
    return !IsFolder(fileName);
}

_JATTA_EXPORT Jatta::Boolean Jatta::File::CreateFolder(const Jatta::String& fileName, bool recursive)
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
    return 0 == _wmkdir(folderName._ToWideString().c_str());
#else
    return 0 == mkdir(folderName.GetData().c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#endif
}

_JATTA_EXPORT Jatta::Boolean Jatta::File::DeleteFolder(const Jatta::String& fileName, bool recursive)
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

#   ifdef WINDOWS
    return 0 == _wrmdir(fileName._ToWideString().c_str());
#   else
    return 0 == rmdir(fileName.GetCString());
#   endif
}

/** @param fileName The file to delete.
 *  @returns True if the file was successfully deleted, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::DeleteFile(const Jatta::String& fileName)
{
#   ifdef WINDOWS
    return ::DeleteFileW(fileName._ToWideString().c_str()) != 0;
#   else
    return 0 == unlink(fileName.GetCString());
#   endif
}

/** @param fileName The target file.
 *  @param fileTo The destination file.
 *  @returns True if the file was successfully copied, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::Copy(const Jatta::String& fileName, const Jatta::String& fileTo)
{
#   ifdef WINDOWS
    return ::CopyFileW(fileName._ToWideString().c_str(), fileTo._ToWideString().c_str(), false) != 0;
#   else
    std::ifstream f1( fileName.GetCString(), std::fstream::binary );
    if ( !f1.is_open() ) return false;
    std::ofstream f2( fileTo.GetCString(), std::fstream::trunc|std::fstream::binary );
    if ( !f2.is_open() ) return false;
    f2 << f1.rdbuf();
    return true;
#   endif
}

/** @param fileName The target file.
 *  @param fileTo The destination file.
 *  @returns True if the file was successfully moved, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::File::Move(const Jatta::String& fileName, const Jatta::String& fileTo)
{
    bool r = Copy(fileName, fileTo);
    if (r == false)
        return false;
    return DeleteFile(fileName);
}
