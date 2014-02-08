// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file File.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/FixedList.hpp"
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

// TODO: remove this hack, favor a "File" class with a "Delete" method
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
        _CGUL_EXPORT void ReadLines(const String& fileName, std::vector< String >* vector);
        //! @brief Reads the file into a byte buffer.
        _CGUL_EXPORT void ReadData(const String& fileName, Byte* buffer, UInt32 size);

        //_CGUL_EXPORT Boolean Touch(const String& fileName);

        //! @brief Obtains the size of a file.
        _CGUL_EXPORT Boolean GetFileSize(const String& fileName, UInt32* fileSize);
        //! @brief Obtains the size of a file.
        _CGUL_EXPORT UInt32 GetFileSize(const String& fileName);

        _CGUL_EXPORT void FindFiles(const String& path, FixedList< String >* files);
        _CGUL_EXPORT void FindDirectories(const String& path, FixedList< String >* directories);

        //! @brief Checks if a file exists.
        _CGUL_EXPORT Boolean Exists(const String& fileName);
        //! @brief Checks the permissions on a file.
        _CGUL_EXPORT Enum GetAccess(const String& fileName);

        _CGUL_EXPORT UInt32 CRC32(const String& fileName);
        _CGUL_EXPORT String MD5(const String& fileName);
        //! @brief Checks if the specified filename is a directory.
        _CGUL_EXPORT Boolean IsDirectory(const String& fileName);
        //! @brief Checks if the specified filename is a file.
        _CGUL_EXPORT Boolean IsFile(const String& fileName);
        _CGUL_EXPORT Boolean CreateDirectory(const String& fileName, bool recursive = false);
        _CGUL_EXPORT Boolean DeleteDirectory(const String& fileName, bool recursive = false);
        //! @brief Deletes the specified file.
        _CGUL_EXPORT Boolean DeleteFile(const String& fileName);
        //! @brief Copies a file from one location to another.
        _CGUL_EXPORT Boolean Copy(const String& fileName, const String& fileTo);
        //! @brief Moves a file from one location to another.
        _CGUL_EXPORT Boolean Move(const String& fileName, const String& fileTo);
    }
}

// Undefines
#include "../External/Undefines.hpp"
