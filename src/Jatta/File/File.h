//        JATTA        //
// by Joshua Brookover //

/** @file File.h
 *  @brief Blurga.
 */

#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A simple file utility.
     */
    namespace File
    {
        // TODO: make a better file utility library
        _JATTA_EXPORT bool GetText(const std::string& fileName, std::string* result);
        _JATTA_EXPORT bool GetText(const String& fileName, String* result);
        _JATTA_EXPORT bool GetLines(const std::string& fileName, std::vector<std::string>* vector);
        _JATTA_EXPORT bool GetLines(const String& fileName, std::vector<String>* vector);
        _JATTA_EXPORT bool GetFileSize(const std::string& fileName, UInt32* fileSize);
        _JATTA_EXPORT bool GetData(const std::string& fileName, Byte* buffer, UInt32 size);
    }
}

#include "../External/Undefines.h"
