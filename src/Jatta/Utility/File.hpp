/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

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
        namespace Access
        {
            enum
            {
                EXECUTE = 0x1, WRITE = 0x2, READ = 0x4
            };
        }

        _JATTA_EXPORT Boolean WriteText(const String& fileName, String string);
        _JATTA_EXPORT Boolean WriteData(const String& fileName, Byte* buffer, UInt32 size);

        //! @brief Puts the file contents into a string.
        _JATTA_EXPORT void ReadText(const String& fileName, String* result);
        //! @brief Reads the contents of the file line-by-line, putting each line into a vector
        //! one-by-one.
        _JATTA_EXPORT void ReadLines(const String& fileName, std::vector<String>* vector);
        //! @brief Reads the file into a byte buffer.
        _JATTA_EXPORT void ReadData(const String& fileName, Byte* buffer, UInt32 size);

        //_JATTA_EXPORT Boolean Touch(const String& fileName);

        //! @brief Obtains the size of a file.
        _JATTA_EXPORT Boolean GetFileSize(const Jatta::String& fileName, UInt32* fileSize);
        //! @brief Obtains the size of a file.
        _JATTA_EXPORT UInt32 GetFileSize(const Jatta::String& fileName);

        _JATTA_EXPORT std::vector<Jatta::String> FindFiles(Jatta::String dir);
        _JATTA_EXPORT std::vector<Jatta::String> FindFolders(Jatta::String dir);

        //! @brief Checks if a file exists.
        _JATTA_EXPORT Boolean Exists(const Jatta::String& fileName);
        //! @brief Checks the permissions on a file.
        _JATTA_EXPORT Enum GetAccess(const Jatta::String& fileName);

        _JATTA_EXPORT unsigned long long CRC32(const Jatta::String& fileName);
        _JATTA_EXPORT Jatta::String MD5(const Jatta::String& fileName);
        //! @brief Checks if the specified filename is a directory.
        _JATTA_EXPORT Boolean IsFolder(const Jatta::String& fileName);
        //! @brief Checks if the specified filename is a file.
        _JATTA_EXPORT Boolean IsFile(const Jatta::String& fileName);
        _JATTA_EXPORT Boolean CreateFolder(const Jatta::String& fileName, bool recursive = false);
        _JATTA_EXPORT Boolean DeleteFolder(const Jatta::String& fileName, bool recursive = false);
        //! @brief Deletes the specified file.
        _JATTA_EXPORT Boolean DeleteFile(const Jatta::String& fileName);
        //! @brief Copies a file from one location to another.
        _JATTA_EXPORT Boolean Copy(const Jatta::String& fileName, const Jatta::String& fileTo);
        //! @brief Moves a file from one location to another.
        _JATTA_EXPORT Boolean Move(const Jatta::String& fileName, const Jatta::String& fileTo);
    }
}

#include "../External/Undefines.h"
