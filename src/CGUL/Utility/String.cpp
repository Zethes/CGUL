// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file String.cpp
 */

#include "String.hpp"
#include "Regex.hpp"
#include "../Math/Math.hpp"
#include <cstring>

char CGUL::String::internalBuffer[2048];

_CGUL_EXPORT CGUL::String CGUL::String::FromCodePoint(UInt32 codePoint)
{
    CGUL::String result;
    if ((codePoint & 0xFC000000) > 0) // 27 - 31 bits (6 bytes)
    {
        result = "      ";
        result[0] = ((codePoint >> 30) & 0x1) | 0xFC;
        result[1] = ((codePoint >> 24) & 0x3F) | 0x80;
        result[2] = ((codePoint >> 18) & 0x3F) | 0x80;
        result[3] = ((codePoint >> 12) & 0x3F) | 0x80;
        result[4] = ((codePoint >> 6) & 0x3F) | 0x80;
        result[5] = (codePoint & 0x3F) | 0x80;
    }
    else if ((codePoint & 0xFFE00000) > 0) // 22 - 26 bits (5 bytes)
    {
        result = "     ";
        result[0] = ((codePoint >> 24) & 0x3) | 0xF8;
        result[1] = ((codePoint >> 18) & 0x3F) | 0x80;
        result[2] = ((codePoint >> 12) & 0x3F) | 0x80;
        result[3] = ((codePoint >> 6) & 0x3F) | 0x80;
        result[4] = (codePoint & 0x3F) | 0x80;
    }
    else if ((codePoint & 0xFFFF0000) > 0) // 17 - 21 bits (4 bytes)
    {
        result = "    ";
        result[0] = ((codePoint >> 18) & 0x7) | 0xF0;
        result[1] = ((codePoint >> 12) & 0x3F) | 0x80;
        result[2] = ((codePoint >> 6) & 0x3F) | 0x80;
        result[3] = (codePoint & 0x3F) | 0x80;
    }
    else if ((codePoint & 0xFFFFF800) > 0) // 12 - 16 bits (3 bytes)
    {
        result = "   ";
        result[0] = ((codePoint >> 12) & 0xF) | 0xE0;
        result[1] = ((codePoint >> 6) & 0x3F) | 0x80;
        result[2] = (codePoint & 0x3F) | 0x80;
    }
    else if ((codePoint & 0xFFFFFF80) > 0) // 8 - 11 bits (2 bytes)
    {
        result = "  ";
        result[0] = ((codePoint >> 6) & 0x1F) | 0xC0;
        result[1] = (codePoint & 0x3F) | 0x80;
    }
    else // 0 - 7 bits (1 byte)
    {
        result = " ";
        result[0] = codePoint & 0x7F;
    }
    return result;
}

/**
 */
_CGUL_EXPORT CGUL::String::String() : data()
{
    null = false;
}

/** @param copy The string to copy.
 */
_CGUL_EXPORT CGUL::String::String(const String& copy) : data(copy.data)
{
    null = false;
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
/** @param move The string to move.
 */
_CGUL_EXPORT CGUL::String::String(String&& move) : data(std::move(move.data))
{
    null = false;
}
#endif

#ifdef CGUL_WINDOWS
_CGUL_EXPORT CGUL::String::String(const std::wstring& wideString)
{
    _FromWideString(wideString);
    null = false;
}
#endif

/** @param data A character pointer to a null-terminated string.
 */
_CGUL_EXPORT CGUL::String::String(const char* data)
{
    if (data == NULL)
    {
        this->data = "";
        this->null = true;
    }
    else
    {
        this->data = data;
        this->null = false;
    }
}

/** @param An std::string value.
 */
_CGUL_EXPORT CGUL::String::String(const std::string& data) :
    data(data)
{
    null = false;
}

/** @param operand The c string or null.
 *  @returns A reference to this object.
 */
_CGUL_EXPORT CGUL::String& CGUL::String::operator=(const char* operand)
{
    if (operand == NULL)
    {
        null = true;
    }
    else
    {
        data = operand;
        null = false;
    }
    return *this;
}

/** @param operand The other string.
 *  @returns A reference to this object.
 */
_CGUL_EXPORT CGUL::String& CGUL::String::operator=(const String& operand)
{
    this->data = operand.data;
    this->null = operand.null;
    return *this;
}

/**
 */
_CGUL_EXPORT char& CGUL::String::operator[](Size operand)
{
    return data[operand];
}

/**
 */
_CGUL_EXPORT const char CGUL::String::operator[](Size operand) const
{
    return data[operand];
}

/** @param operand The other string.
 *  @returns True if they're equal, false otherwise.
 */
_CGUL_EXPORT bool CGUL::String::operator==(const String& operand) const
{
    return (data == operand.data) && (null == operand.null);
}

/** @param operand The other string.
 *  @returns False if they're equal, true otherwise.
 */
_CGUL_EXPORT bool CGUL::String::operator!=(const String& operand) const
{
    return (data != operand.data) || (null != operand.null);
}

/** @param operand The other string.
 *  @returns True if this string is lexicographically less than the other, false otherwise.
 */
_CGUL_EXPORT bool CGUL::String::operator<(const String& operand) const
{
    return this->data < operand.data;
}

/** @returns Number of bytes.
 */
_CGUL_EXPORT CGUL::Size CGUL::String::GetSize() const
{
    return data.length();
}

/** @returns Number of code points.
 */
_CGUL_EXPORT CGUL::Size CGUL::String::GetLength() const
{
    Size len = 0;
    const char* str = this->data.c_str();
    while (*str)
    {
        if ((*str++ & 0xc0) != 0x80)
        {
            len++;
        }
    }
    return len;
}

/** @param position The index of the character.
 *  @returns The character in the string.
 */
_CGUL_EXPORT char CGUL::String::GetChar(Size position) const
{
    return (char)data.at(position);
}

/** @param position The index of the byte.
 *  @returns The byte in the string.
 */
_CGUL_EXPORT CGUL::Byte CGUL::String::GetByte(Size position) const
{
    return (Byte)data.at(position);
}

/** @param start The first byte of the code point.
 *  @param codePoint A pointer to the UInt32 variable to store the code point.
 *  @details
 *  @b Example
 *  @code
 *  #include <CGUL.hpp>
 *  #include <iostream>
 *  using namespace CGUL;
 *
 *  int main()
 *  {
 *      String str = "\u3053\u3093\u306b\u3061\u306f";
 *      //            ko    n     ni    chi   ha
 *
 *      UInt32 codePoint;
 *      Size i = 0;
 *      while (i < str.GetSize())
 *      {
 *          i += str.GetCodePoint(i, &codePoint);
 *          std::cout << std::hex << codePoint << std::endl;
 *      }
 *
 *      // outputs:
 *      // 3053
 *      // 3093
 *      // 306b
 *      // 3061
 *      // 306f
 *  }
 *  @endcode
 */
_CGUL_EXPORT CGUL::Size CGUL::String::GetCodePoint(Size start, UInt32* codePoint) const
{
    if (codePoint)
    {
        *codePoint = 0;
        if (((Byte)(data[start]) & 0xFC) == 0xFC)
        {
            *codePoint |= (data[start + 0] & 0x01) << 30;
            *codePoint |= (data[start + 1] & 0x3F) << 24;
            *codePoint |= (data[start + 2] & 0x3F) << 18;
            *codePoint |= (data[start + 3] & 0x3F) << 12;
            *codePoint |= (data[start + 4] & 0x3F) << 6;
            *codePoint |= (data[start + 5] & 0x3F) << 0;
            return 6;
        }
        if (((Byte)(data[start]) & 0xF8) == 0xF8)
        {
            *codePoint |= (data[start + 0] & 0x03) << 24;
            *codePoint |= (data[start + 1] & 0x3F) << 18;
            *codePoint |= (data[start + 2] & 0x3F) << 12;
            *codePoint |= (data[start + 3] & 0x3F) << 6;
            *codePoint |= (data[start + 4] & 0x3F) << 0;
            return 5;
        }
        if (((Byte)(data[start]) & 0xF0) == 0xF0)
        {
            *codePoint |= (data[start + 0] & 0x07) << 18;
            *codePoint |= (data[start + 1] & 0x3F) << 12;
            *codePoint |= (data[start + 2] & 0x3F) << 6;
            *codePoint |= (data[start + 3] & 0x3F) << 0;
            return 4;
        }
        if (((Byte)(data[start]) & 0xE0) == 0xE0)
        {
            *codePoint |= (data[start + 0] & 0x0F) << 12;
            *codePoint |= (data[start + 1] & 0x3F) << 6;
            *codePoint |= (data[start + 2] & 0x3F) << 0;
            return 3;
        }
        if (((Byte)(data[start]) & 0xC0) == 0xC0)
        {
            *codePoint |= (data[start + 0] & 0x1F) << 6;
            *codePoint |= (data[start + 1] & 0x3F) << 0;
            return 2;
        }
        *codePoint |= (data[start + 0] & 0x7F) << 0;
        return 1;
    }
    else
    {
        if (((Byte)(data[start]) & 0xFC) == 0xFC)
        {
            return 6;
        }
        if (((Byte)(data[start]) & 0xF8) == 0xF8)
        {
            return 5;
        }
        if (((Byte)(data[start]) & 0xF0) == 0xF0)
        {
            return 4;
        }
        if (((Byte)(data[start]) & 0xE0) == 0xE0)
        {
            return 3;
        }
        if (((Byte)(data[start]) & 0xC0) == 0xC0)
        {
            return 2;
        }
        return 1;
    }
}


/** @returns True if the string is empty, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::String::IsEmpty() const
{
    return data.empty();
}

/** @returns True if the string is null, false otherwise.
 */
_CGUL_EXPORT CGUL::Boolean CGUL::String::IsNull() const
{
    return null;
}

/** @returns The std::string variable.
 */
_CGUL_EXPORT std::string CGUL::String::GetData() const
{
    return data;
}

/** @returns A constant character pointer of the data.
 */
_CGUL_EXPORT const char* CGUL::String::GetCString() const
{
    if (null)
    {
        return NULL;
    }
    return data.c_str();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::String::Count(const String& string) const
{
    UInt32 count = 0;
    Size offset = 0;
    while ((offset = FindFirstOf(string, offset)) != none)
    {
        count++;
        offset++;
    }
    return count;
}

/** @param string The string to look for.
 *  @param offset An offset to start looking for the string.
 *  @returns The index of the first character of the string.
 */
_CGUL_EXPORT CGUL::Size CGUL::String::FindFirstOf(const String& string, Size offset) const
{
    CGUL::Size result = offset;
    for (std::string::const_iterator i = data.begin() + offset; i != data.end(); ++i)
    {
        std::string::const_iterator k = i;
        bool found = true;
        for (std::string::const_iterator j = string.data.begin(); j != string.data.end() && k != data.end(); ++j, ++k)
        {
            if (*k != *j)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return result;
        }
        result += 1;
    }
    return none;
}

#ifdef CGUL_USE_REGEX
_CGUL_EXPORT CGUL::Size CGUL::String::FindFirstOf(const Regex& expression, Size offset) const
{
    // TODO: this
    return none;
}
#endif

/** @param string The string to look for.
 *  @param offset A backwards offset to start looking for the string.
 *  @returns The index of the first character of the string.
 */
_CGUL_EXPORT CGUL::Size CGUL::String::FindLastOf(const String& string, Size offset) const
{
    CGUL::Size result = offset;
    for (std::string::const_reverse_iterator i = data.rbegin() + offset; i != data.rend(); ++i)
    {
        std::string::const_reverse_iterator k = i;
        bool found = true;
        for (std::string::const_reverse_iterator j = string.data.rbegin(); j != string.data.rend() && k != data.rend(); ++j, ++k)
        {
            if (*k != *j)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return GetSize() - (result + string.GetSize());
        }
        result += 1;
    }
    return none;
}

#ifdef CGUL_USE_REGEX
_CGUL_EXPORT CGUL::Size CGUL::String::FindLastOf(const Regex& expression, Size offset) const
{
    // TODO: this
    return none;
}
#endif

/** @param start The first character to grab.
 *  @param count The number of characters to grab.
 *  @param bytes If true, this method will grab @p count number of bytes. If false, this method will grab @p count number of codepoints.
 *  @details This method does not support backwards counting (supplying a negative start) like php's substr() and others.
 *  @n@n@b Example
 *  @code
 *  #include <CGUL.hpp>
 *  #include <iostream>
 *  using namespace CGUL;
 *
 *  // Note: this example only works in terminals with unicode support
 *  int main()
 *  {
 *      String str = "\u3053\u3093\u306b\u3061\u306f";
 *      //            ko    n     ni    chi   ha
 *
 *      std::cout << str.SubString(2, 2) << std::endl;
 *      // outputs: \u306b\u3061
 *      //          ni    chi
 *
 *      std::cout << str.SubString(3, 3, true) << std::endl;
 *      // outputs: \u3093
 *      //          n
 *  }
 *  @endcode
 */
_CGUL_EXPORT CGUL::String CGUL::String::SubString(Size start, Size count, bool bytes) const
{
    if (bytes)
    {
        return CGUL::String(data.substr(start, count));
    }
    else
    {
        Size offset = 0;
        for (Size i = 0; i < start; i++)
        {
            offset += GetCodePoint(offset, NULL);
        }
        Size size = 0;
        if (count == none)
        {
            size = none;
        }
        else
        {
            //count = Math::Min(count, data.length() - offset);
            for (; offset < data.length() && count > 0; count--)
            {
                Size codePointSize = GetCodePoint(offset,  NULL);
                size += codePointSize;
            }
        }
        return CGUL::String(data.substr(offset, size));
    }
}

/** @param string String to check for.
 *  @returns True if the string was found.
 */
_CGUL_EXPORT bool CGUL::String::Contains(const String& string) const
{
    return (FindFirstOf(string) != none);
}

/** @param string String to check for.
 *  @returns True if the string was found at the beginning.
 */
_CGUL_EXPORT bool CGUL::String::BeginsWith(const String& string) const
{
    std::string::const_iterator i = data.begin();
    for (std::string::const_iterator k = string.data.begin(); k != string.data.end(); ++k, ++i)
    {
        if (i == data.end() || *i != *k)
        {
            return false;
        }
    }
    return true;
}

/** @param string String to check for.
 *  @returns True if the string was found at the end.
 */
_CGUL_EXPORT bool CGUL::String::EndsWith(const String& string) const
{
    std::string::const_reverse_iterator i = data.rbegin();
    for (std::string::const_reverse_iterator k = string.data.rbegin(); k != string.data.rend(); ++k, ++i)
    {
        if (i == data.rend() || *i != *k)
        {
            return false;
        }
    }
    return true;
}

/** @param str The c string.
 *  @returns A reference to this object.
 */
_CGUL_EXPORT CGUL::String& CGUL::String::Set(const char* str)
{
    if (str == NULL)
    {
        null = true;
    }
    else
    {
        data = str;
        null = false;
    }
    return *this;
}

/** @param str The c string.
 *  @returns A reference to this object.
 */
_CGUL_EXPORT CGUL::String& CGUL::String::Set(const String& str)
{
    this->data = str.data;
    this->null = str.null;
    return *this;
}

/** @param str Printf-like string.
 *  @param ... Values.
 *  @returns A reference to this object.
 */
_CGUL_EXPORT CGUL::String& CGUL::String::SetFormat(const String& str, ...)
{
    va_list argptr;
    va_start(argptr, str);
    int length = vsnprintf(NULL, 0, str.GetCString(), argptr);
    if (length < 0)
    {
        throw std::runtime_error("Invalid string format.");
    }
    length += 1; // One for null terminator
    char* buffer = internalBuffer;
    if (length > sizeof(internalBuffer))
    {
        buffer = new char[length];
    }
    vsnprintf(buffer, length, str.GetCString(), argptr);
    data = buffer;
    if (buffer != internalBuffer)
    {
        delete[] buffer;
    }
    va_end(argptr);
    null = false;
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <CGUL.hpp>
 *  #include <iostream>
 *  using namespace CGUL;
 *
 *  int main()
 *  {
 *      String str;
 *
 *      str = " \t this is a test \t ";
 *      str.Trim();
 *      std::cout << "|" << str << "|" << std::endl;
 *
 *      // outputs: |this is a test|
 *  }
 *  @endcode
 */
_CGUL_EXPORT void CGUL::String::Trim()
{
    unsigned int trimStart = 0;
    for (std::string::iterator i = data.begin(); i != data.end() && isspace(*i); ++i, ++trimStart);
    unsigned int trimEnd = 0;
    for (std::string::reverse_iterator i = data.rbegin(); i != data.rend() && isspace(*i); ++i, ++trimEnd);
    data = data.substr(trimStart, data.length() - (trimStart + trimEnd));
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <CGUL.hpp>
 *  #include <iostream>
 *  using namespace CGUL;
 *
 *  int main()
 *  {
 *      String str;
 *
 *      str = " \t this is a test \t ";
 *      str.TrimStart();
 *      std::cout << "|" << str << "|" << std::endl;
 *
 *      // outputs: |this is a test      |
 *  }
 *  @endcode
 */
_CGUL_EXPORT void CGUL::String::TrimStart()
{
    unsigned int trimStart = 0;
    for (std::string::iterator i = data.begin(); i != data.end() && isspace(*i); ++i, ++trimStart);
    data = data.substr(trimStart);
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <CGUL.hpp>
 *  #include <iostream>
 *  using namespace CGUL;
 *
 *  int main()
 *  {
 *      String str;
 *
 *      str = " \t this is a test \t ";
 *      str.TrimEnd();
 *      std::cout << "|" << str << "|" << std::endl;
 *
 *      // outputs: |      this is a test|
 *  }
 *  @endcode
 */
_CGUL_EXPORT void CGUL::String::TrimEnd()
{
    unsigned int trimEnd = 0;
    for (std::string::reverse_iterator i = data.rbegin(); i != data.rend() && isspace(*i); ++i, ++trimEnd);
    data = data.substr(0, data.length() - trimEnd);
}

_CGUL_EXPORT void CGUL::String::Explode(const String& delimiter, FixedList< String >* debris) const
{
    Explode(delimiter, none, debris);
}

_CGUL_EXPORT void CGUL::String::Explode(const String& delimiter, Size limit, FixedList< String >* debris) const
{
    Size find = 0;
    Size from = 0;
    Size count = 0;
    do
    {
        if (limit-- == 0)
        {
            break;
        }
        find = FindFirstOf(delimiter, from);
        count++;
        from = find + 1;
    }
    while (find != none);
    debris->SetSize(count);
    find = 0;
    from = 0;
    count = 0;
    do
    {
        if (limit-- == 0)
        {
            debris->Set(count++, SubString(from));
            break;
        }
        find = FindFirstOf(delimiter, from);
        debris->Set(count++, SubString(from, find - from, true));
        from = find + 1;
    }
    while (find != none);
}

/**
 */
_CGUL_EXPORT void CGUL::String::ToLower()
{
    for (std::string::iterator it = data.begin(); it != data.end(); ++it)
    {
        *it = tolower(*it);
    }
}

/**
 */
_CGUL_EXPORT void CGUL::String::ToUpper()
{
    for (std::string::iterator it = data.begin(); it != data.end(); ++it)
    {
        *it = toupper(*it);
    }
}

//! @brief Gets the string as all lowercase letters.
_CGUL_EXPORT CGUL::String CGUL::String::GetLower() const
{
    String ret(*this);
    ret.ToLower();
    return ret;
}

//! @brief Gets the string as all uppercase letters.
_CGUL_EXPORT CGUL::String CGUL::String::GetUpper() const
{
    String ret(*this);
    ret.ToUpper();
    return ret;
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 */
_CGUL_EXPORT void CGUL::String::RemoveWhitespace()
{
    data.erase(std::remove_if(data.begin(), data.end(), (int(*)(int))isspace), data.end());
}

/**
 */
_CGUL_EXPORT void CGUL::String::SetNullToEmpty()
{
    if (IsNull())
    {
        null = false;
    }
}

/**
 */
_CGUL_EXPORT void CGUL::String::SetEmptyToNull()
{
    if (IsEmpty())
    {
        null = true;
    }
}

#ifdef CGUL_WINDOWS
_CGUL_EXPORT std::wstring CGUL::String::_ToWideString() const
{
    int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), -1, 0, 0);
    wchar_t* buffer = new wchar_t[size];
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), -1, buffer, size);
    buffer[size - 1] = 0;
    std::wstring wideString(buffer);
    delete[] buffer;
    return wideString;
}

_CGUL_EXPORT void CGUL::String::_FromWideString(const std::wstring& wideString)
{
    int size = WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, 0, 0, NULL, NULL);
    char* buffer = new char[size];
    WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, buffer, size, NULL, NULL);
    buffer[size - 1] = 0;
    data = buffer;
    delete[] buffer;
}
#endif
