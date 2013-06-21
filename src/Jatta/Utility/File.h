//        JATTA        //
// by Joshua Brookover //

/** @file File.h
 *  @brief Blurga.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

#ifdef DeleteFile
#undef DeleteFile
#endif

namespace Jatta
{
    /** @brief A simple file utility.
     */
    namespace File
    {
        // TODO: make a better file utility library

        _JATTA_EXPORT Boolean WriteText(const String& fileName, String string);
        _JATTA_EXPORT Boolean WriteData(const Jatta::String& fileName, Byte* buffer, UInt32 size);

        _JATTA_EXPORT Boolean ReadText(const String& fileName, String* result);
        _JATTA_EXPORT Boolean ReadLines(const String& fileName, std::vector<String>* vector);
        _JATTA_EXPORT Boolean ReadData(const Jatta::String& fileName, Byte* buffer, UInt32 size);

        //_JATTA_EXPORT Boolean Touch(const String& fileName);

        _JATTA_EXPORT Boolean GetFileSize(const Jatta::String& fileName, UInt32* fileSize);
        _JATTA_EXPORT UInt32 GetFileSize(const Jatta::String& fileName);

        _JATTA_EXPORT std::vector<Jatta::String> FindFiles(Jatta::String dir);
        _JATTA_EXPORT std::vector<Jatta::String> FindFolders(Jatta::String dir);

        _JATTA_EXPORT Boolean Exists(const Jatta::String& fileName);
        _JATTA_EXPORT unsigned long long CRC32(const Jatta::String& fileName);
        _JATTA_EXPORT Jatta::String MD5(const Jatta::String& fileName);
        _JATTA_EXPORT Boolean IsFolder(const Jatta::String& fileName);
        _JATTA_EXPORT Boolean IsFile(const Jatta::String& fileName);
        _JATTA_EXPORT Boolean CreateFolder(const Jatta::String& fileName, bool recursive = false);
        _JATTA_EXPORT Boolean DeleteFolder(const Jatta::String& fileName, bool recursive = false);
        _JATTA_EXPORT Boolean DeleteFile(const Jatta::String& fileName);
        _JATTA_EXPORT Boolean Copy(const Jatta::String& fileName, const Jatta::String& fileTo);
        _JATTA_EXPORT Boolean Move(const Jatta::String& fileName, const Jatta::String& fileTo);
    }
}

#include "../External/Undefines.h"
