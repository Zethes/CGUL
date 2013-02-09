/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Regex;

    /** @brief A Utf-8 compliant string.
     */
    class String
    {
        std::string data;
    public:
        static const Size none = (Size)-1;

        _JATTA_EXPORT String();
        _JATTA_EXPORT String(const String& copy);
        _JATTA_EXPORT String(String&& move);
        _JATTA_EXPORT String(const char* data);
        _JATTA_EXPORT String(const std::string& data);

        _JATTA_EXPORT String& operator=(const String& operand);
        _JATTA_EXPORT bool operator==(const String& operand) const;
        _JATTA_EXPORT bool operator!=(const String& operand) const;
        template <typename T> String operator+(const T& operand) const;
        template <typename T> String operator+(const T&& operand) const;
        template <typename T> String& operator+=(const T& operand);
        template <typename T> String& operator+=(const T&& operand);
        _JATTA_EXPORT bool operator<(const String& operand) const;
        friend std::ostream& operator<<(std::ostream& stream, const String& string)
        {
            stream << string.data;
            return stream;
        }

        _JATTA_EXPORT Size GetSize() const;
        _JATTA_EXPORT Size GetLength() const;

        _JATTA_EXPORT Byte GetByte(Size position) const;
        _JATTA_EXPORT Size GetCodePoint(Size start, UInt32* codePoint) const;
        _JATTA_EXPORT Boolean Empty() const;

        _JATTA_EXPORT std::string GetData() const;
        _JATTA_EXPORT const char* GetCString() const;

        _JATTA_EXPORT UInt32 Count(const String& string) const;

        _JATTA_EXPORT Size FindFirstOf(const String& string, Size offset = 0) const;
        _JATTA_EXPORT Size FindFirstOf(const Regex& expression, Size offset = 0) const;
        _JATTA_EXPORT Size FindLastOf(const String& string, Size offset = 0) const;
        _JATTA_EXPORT Size FindLastOf(const Regex& expression, Size offset = 0) const;

        _JATTA_EXPORT String SubString(Size offset, Size count = none, bool bytes = false) const;

        _JATTA_EXPORT void Trim();
        _JATTA_EXPORT void TrimStart();
        _JATTA_EXPORT void TrimEnd();
        _JATTA_EXPORT std::vector<String> Explode(const String& delimiter, Size limit = none) const;

        _JATTA_EXPORT void ToLower();
        _JATTA_EXPORT void ToUpper();

        _JATTA_EXPORT void RemoveWhitespace();

        template <typename T> bool Is() const;
        template <typename T> T To() const;

#       ifdef WINDOWS
        _JATTA_EXPORT std::wstring _ToWideString() const;
#       endif

        // TODO: add in some more common string functions (maybe reference php's string, C#'s string or std::string?)
    };
}

/** @brief Overloaded + operator.  Concatenates this string with a value.
 *  @param operand The value to concatenate.
 *  @returns The new string.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T> Jatta::String Jatta::String::operator+(const T& operand) const
{
    std::ostringstream ss;
    ss << operand;
    return data + ss.str();
}

/** @brief Overloaded + operator.  Concatenates this string with a value.
 *  @param operand The value to concatenate.
 *  @returns The new string.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T> Jatta::String Jatta::String::operator+(const T&& operand) const
{
    std::ostringstream ss;
    ss << operand;
    return data + ss.str();
}

/** @brief Overloaded += operator.  Concatenates a value onto this string.
 *  @param operand The value to concatenate.
 *  @returns A reference to this object.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T> Jatta::String& Jatta::String::operator+=(const T& operand)
{
    std::ostringstream ss;
    ss << operand;
    data += ss.str();
    return *this;
}

/** @brief Overloaded += operator.  Concatenates a value onto this string.
 *  @param operand The value to concatenate.
 *  @returns A reference to this object.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T> Jatta::String& Jatta::String::operator+=(const T&& operand)
{
    std::ostringstream ss;
    ss << operand;
    data += ss.str();
    return *this;
}

/** @brief Checks if the string can be converted to the given data type.
 *  @returns True if the string can be converted, false otherwise.
 */
template <typename T> bool Jatta::String::Is() const
{
    std::istringstream test;
    test.str(data);
    if (!test.good())
    {
        return false;
    }
    T x;
    test >> x;
    if (test.fail() || test.good())
    {
        return false;
    }
    return true;
}

/** @brief Converts the string to the given data type.
 *  @returns The string as the given type.
 */
template <typename T> T Jatta::String::To() const
{
    std::istringstream convert;
    convert.str(data);
    T x;
    convert >> x;
    return x;
}

#include "../External/Undefines.h"
