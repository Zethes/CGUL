// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file File.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

#ifdef DeleteFile
#undef DeleteFile
#endif

namespace CGUL
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

        _CGUL_EXPORT Boolean WriteText(const String& fileName, String string);
        _CGUL_EXPORT Boolean WriteData(const String& fileName, Byte* buffer, UInt32 size);

        //! @brief Puts the file contents into a string.
        _CGUL_EXPORT void ReadText(const String& fileName, String* result);
        //! @brief Reads the contents of the file line-by-line, putting each line into a vector
        //! one-by-one.
        _CGUL_EXPORT void ReadLines(const String& fileName, std::vector<String>* vector);
        //! @brief Reads the file into a byte buffer.
        _CGUL_EXPORT void ReadData(const String& fileName, Byte* buffer, UInt32 size);

        //_CGUL_EXPORT Boolean Touch(const String& fileName);

        //! @brief Obtains the size of a file.
        _CGUL_EXPORT Boolean GetFileSize(const CGUL::String& fileName, UInt32* fileSize);
        //! @brief Obtains the size of a file.
        _CGUL_EXPORT UInt32 GetFileSize(const CGUL::String& fileName);

        _CGUL_EXPORT std::vector<CGUL::String> FindFiles(CGUL::String dir);
        _CGUL_EXPORT std::vector<CGUL::String> FindFolders(CGUL::String dir);

        //! @brief Checks if a file exists.
        _CGUL_EXPORT Boolean Exists(const CGUL::String& fileName);
        //! @brief Checks the permissions on a file.
        _CGUL_EXPORT Enum GetAccess(const CGUL::String& fileName);

        _CGUL_EXPORT unsigned long long CRC32(const CGUL::String& fileName);
        _CGUL_EXPORT CGUL::String MD5(const CGUL::String& fileName);
        //! @brief Checks if the specified filename is a directory.
        _CGUL_EXPORT Boolean IsFolder(const CGUL::String& fileName);
        //! @brief Checks if the specified filename is a file.
        _CGUL_EXPORT Boolean IsFile(const CGUL::String& fileName);
        _CGUL_EXPORT Boolean CreateFolder(const CGUL::String& fileName, bool recursive = false);
        _CGUL_EXPORT Boolean DeleteFolder(const CGUL::String& fileName, bool recursive = false);
        //! @brief Deletes the specified file.
        _CGUL_EXPORT Boolean DeleteFile(const CGUL::String& fileName);
        //! @brief Copies a file from one location to another.
        _CGUL_EXPORT Boolean Copy(const CGUL::String& fileName, const CGUL::String& fileTo);
        //! @brief Moves a file from one location to another.
        _CGUL_EXPORT Boolean Move(const CGUL::String& fileName, const CGUL::String& fileTo);
    }
}

#include "../External/Undefines.hpp"
