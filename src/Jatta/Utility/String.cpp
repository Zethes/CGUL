/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "String.h"
#include "Regex.h"
#include "../Math/Math.h"
#include <cstring>

/**
 */
_JATTA_EXPORT Jatta::String::String() : data()
{
}

/** @param copy The string to copy.
 */
_JATTA_EXPORT Jatta::String::String(const String& copy) : data(copy.data)
{
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
/** @param move The string to move.
 */
_JATTA_EXPORT Jatta::String::String(String&& move) : data(std::move(move.data))
{
}
#endif

#ifdef WINDOWS
_JATTA_EXPORT Jatta::String::String(const std::wstring& wideString)
{
    _FromWideString(wideString);
}
#endif

/** @param data A character pointer to a null-terminated string.
 */
_JATTA_EXPORT Jatta::String::String(const char* data) : data(data)
{
}

/** @param An std::string value.
 */
_JATTA_EXPORT Jatta::String::String(const std::string& data) : data(data)
{
}

/** @param operand The other string.
 *  @returns A reference to this object.
 */
_JATTA_EXPORT Jatta::String& Jatta::String::operator=(const String& operand)
{
    this->data = operand.data;
    return *this;
}

/**
 */
_JATTA_EXPORT char& Jatta::String::operator[](Size operand)
{
    return data[operand];
}

/**
 */
_JATTA_EXPORT const char Jatta::String::operator[](Size operand) const
{
    return data[operand];
}

/** @param operand The other string.
 *  @returns True if they're equal, false otherwise.
 */
_JATTA_EXPORT bool Jatta::String::operator==(const String& operand) const
{
    return data == operand.data;
}

/** @param operand The other string.
 *  @returns False if they're equal, true otherwise.
 */
_JATTA_EXPORT bool Jatta::String::operator!=(const String& operand) const
{
    return data != operand.data;
}

/** @param operand The other string.
 *  @returns True if this string is lexicographically less than the other, false otherwise.
 */
_JATTA_EXPORT bool Jatta::String::operator<(const String& operand) const
{
    return this->data < operand.data;
}

/** @returns Numbers of bytes.
 */
_JATTA_EXPORT Jatta::Size Jatta::String::GetSize() const
{
    return data.length();
}

/** @returns Numbers of code points.
 */
_JATTA_EXPORT Jatta::Size Jatta::String::GetLength() const
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

/** @param position The index of the byte.
 *  @returns The byte in the string.
 */
_JATTA_EXPORT Jatta::Byte Jatta::String::GetByte(Size position) const
{
    return (Byte)data.at(position);
}

/** @param start The first byte of the code point.
 *  @param codePoint A pointer to the UInt32 variable to store the code point.
 *  @details
 *  @b Example
 *  @code
 *  #include <Jatta.h>
 *  #include <iostream>
 *  using namespace Jatta;
 *
 *  int main()
 *  {
 *      String str;
 *      UInt32 codePoint;
 *      Size i = 0;
 *      str = "çŒ«ã�Œã�‹ã‚�ã�„ã�„ã�§ã�™";
 *      while (i < str.GetSize())
 *      {
 *          i += str.GetCodePoint(i, &codePoint);
 *          std::cout << std::hex << codePoint << std::endl;
 *      }
 *
 *      // outputs:
 *      // 732b
 *      // 304c
 *      // 304b
 *      // 308f
 *      // 3044
 *      // 3044
 *      // 3067
 *      // 3059
 *  }
 *  @endcode
 */
_JATTA_EXPORT Jatta::Size Jatta::String::GetCodePoint(Size start, UInt32* codePoint) const
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
_JATTA_EXPORT Jatta::Boolean Jatta::String::Empty() const
{
    return data.empty();
}

/** @returns The std::string variable.
 */
_JATTA_EXPORT std::string Jatta::String::GetData() const
{
    return data;
}

/** @returns A constant character pointer of the data.
 */
_JATTA_EXPORT const char* Jatta::String::GetCString() const
{
    return data.c_str();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::String::Count(const String& string) const
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
_JATTA_EXPORT Jatta::Size Jatta::String::FindFirstOf(const String& string, Size offset) const
{
    Jatta::Size result = offset;
    for (std::string::const_iterator i = data.begin() + offset; i != data.end(); i++)
    {
        std::string::const_iterator k = i;
        bool found = true;
        for (std::string::const_iterator j = string.data.begin(); j != string.data.end() && k != data.end(); j++, k++)
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

_JATTA_EXPORT Jatta::Size Jatta::String::FindFirstOf(const Regex& expression, Size offset) const
{
    // TODO: this
    return none;
}

/** @param string The string to look for.
 *  @param offset A backwards offset to start looking for the string.
 *  @returns The index of the first character of the string.
 */
_JATTA_EXPORT Jatta::Size Jatta::String::FindLastOf(const String& string, Size offset) const
{
    Jatta::Size result = offset;
    for (std::string::const_reverse_iterator i = data.rbegin() + offset; i != data.rend(); i++)
    {
        std::string::const_reverse_iterator k = i;
        bool found = true;
        for (std::string::const_reverse_iterator j = string.data.rbegin(); j != string.data.rend() && k != data.rend(); j++, k++)
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

_JATTA_EXPORT Jatta::Size Jatta::String::FindLastOf(const Regex& expression, Size offset) const
{
    // TODO: this
    return none;
}

/** @param start The first character to grab.
 *  @param count The number of characters to grab.
 *  @param bytes If true, this method will grab @p count number of bytes. If false, this method will grab @p count number of codepoints.
 *  @details This method does not support backwards counting (supplying a negative start) like php's substr() and others.
 *  @n@n@b Example
 *  @code
 *  #include <Jatta.h>
 *  #include <iostream>
 *  using namespace Jatta;
 *
 *  int main()
 *  {
 *      String str;
 *
 *      str = "çŒ«ã�Œã�‹ã‚�ã�„ã�„ã�§ã�™"; UGH THIS IS WHY WE CANT HAVE NICE THINGS
 *      str = str.SubString(3, 3);
 *      std::cout << str << std::endl;
 *
 *      // outputs: ã‚�ã�„ã�„
 *
 *      str = "çŒ«ã�Œã�‹ã‚�ã�„ã�„ã�§ã�™";
 *      str = str.SubString(3, 3, true);
 *      std::cout << str << std::endl;
 *
 *      // outputs: ã�Œ
 *  }
 *  @endcode
 */
_JATTA_EXPORT Jatta::String Jatta::String::SubString(Size start, Size count, bool bytes) const
{
    if (bytes)
    {
       return Jatta::String(data.substr(start, count));
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
        return Jatta::String(data.substr(offset, size));
    }
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <Jatta.h>
 *  #include <iostream>
 *  using namespace Jatta;
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
_JATTA_EXPORT void Jatta::String::Trim()
{
    unsigned int trimStart = 0;
    for (std::string::iterator i = data.begin(); i != data.end() && isspace(*i); i++, trimStart++);
    unsigned int trimEnd = 0;
    for (std::string::reverse_iterator i = data.rbegin(); i != data.rend() && isspace(*i); i++, trimEnd++);
    data = data.substr(trimStart, data.length() - (trimStart + trimEnd));
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <Jatta.h>
 *  #include <iostream>
 *  using namespace Jatta;
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
_JATTA_EXPORT void Jatta::String::TrimStart()
{
    unsigned int trimStart = 0;
    for (std::string::iterator i = data.begin(); i != data.end() && isspace(*i); i++, trimStart++);
    data = data.substr(trimStart);
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 *  @n@n@b Example
 *  @code
 *  #include <Jatta.h>
 *  #include <iostream>
 *  using namespace Jatta;
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
_JATTA_EXPORT void Jatta::String::TrimEnd()
{
    unsigned int trimEnd = 0;
    for (std::string::reverse_iterator i = data.rbegin(); i != data.rend() && isspace(*i); i++, trimEnd++);
    data = data.substr(0, data.length() - trimEnd);
}

_JATTA_EXPORT std::vector<Jatta::String> Jatta::String::Explode(const String& delimiter, Size limit) const
{
    std::vector<Jatta::String> result;
    Size find = 0;
    Size from = 0;
    do
    {
        if (limit-- == 0)
        {
            result.push_back(SubString(from));
            break;
        }
        find = FindFirstOf(delimiter, from);
        result.push_back(SubString(from, find - from, true));
        from = find + 1;
    } while (find != none);
    return result;
}

/**
 */
_JATTA_EXPORT void Jatta::String::ToLower()
{
    for (std::string::iterator it = data.begin(); it != data.end(); it++)
    {
        *it = tolower(*it);
    }
}

/**
 */
_JATTA_EXPORT void Jatta::String::ToUpper()
{
    for (std::string::iterator it = data.begin(); it != data.end(); it++)
    {
        *it = toupper(*it);
    }
}

/** @details Removes spaces, tabs and the following whitespaces: \\n \\v \\f \\r
 */
_JATTA_EXPORT void Jatta::String::RemoveWhitespace()
{
    data.erase(std::remove_if(data.begin(), data.end(), (int(*)(int))isspace), data.end());
}

#ifdef WINDOWS
_JATTA_EXPORT std::wstring Jatta::String::_ToWideString() const
{
    int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), -1, 0, 0);
    wchar_t* buffer = new wchar_t[size];
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), -1, buffer, size);
    buffer[size - 1] = 0;
    std::wstring wideString(buffer);
    delete[] buffer;
    return wideString;
}

_JATTA_EXPORT void Jatta::String::_FromWideString(const std::wstring& wideString)
{
    int size = WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, 0, 0, NULL, NULL);
    char* buffer = new char[size];
    WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, buffer, size, NULL, NULL);
    buffer[size - 1] = 0;
    data = buffer;
    delete[] buffer;
}
#endif
