// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file String.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Containers/FixedList.hpp"
#include "../External/Defines.hpp"

#ifndef CGUL_NO_U8
#   ifdef CPP_HAS_U8
#       define U8(text) CGUL::String(u8##text)
#   else
#       ifdef CGUL_WINDOWS
#           define U8(text) CGUL::String(L##text)
#       else
#           define U8(text) CGUL::String(text)
#       endif
#   endif
#endif

namespace CGUL
{
#   ifdef CGUL_USE_REGEX
    class Regex;
#   endif

    /** @brief A Utf-8 compliant string.
     */
    class String
    {
        /** @brief A buffer for quick operations of strings under 2048 characters.
         */
        static char internalBuffer[2048];

        /** @brief Internal string object to manage the data.
         */
        std::string data;

        /** @brief Special case for a NULL string.
         */
        bool null;
    public:
        static const Size none = (Size)-1;

        _CGUL_EXPORT static String FromCodePoint(UInt32 codePoint);

        template< typename Type >
        static String From(Type value);

        //! @brief Initializes to "".
        _CGUL_EXPORT String();
        //! @brief Copies the contents of the string into a new string.
        _CGUL_EXPORT String(const String& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        //! @brief Moves the contents of one string to another.
        _CGUL_EXPORT String(String&& move);
#       endif
#       ifdef CGUL_WINDOWS
        //! @brief Converts a std::wstring object to a Utf-8 string.
        //! @warning Windows only!
        _CGUL_EXPORT String(const std::wstring& wideString);
#       endif
        //! @brief Copies raw character array data in a managed string object.
        _CGUL_EXPORT String(const char* data);
        //! @brief Copies a raw std::string object.
        _CGUL_EXPORT String(const std::string& data);

        //! @brief Copies the contents of a c string into this string.
        _CGUL_EXPORT String& operator=(const char* operand);
        //! @brief Copies the contents of another string into this string.
        _CGUL_EXPORT String& operator=(const String& operand);
        //! @brief Gets an individual byte from the string at the specified index.
        _CGUL_EXPORT char& operator[](Size operand);
        //! @brief Gets an individual byte from the string at the specified index.
        _CGUL_EXPORT const char operator[](Size operand) const;
        //! @brief Checks if two strings are equal.
        _CGUL_EXPORT bool operator==(const String& operand) const;
        //! @brief Checks if two strings are not equal.
        _CGUL_EXPORT bool operator!=(const String& operand) const;
        //! @brief Attempts to convert a data type to string and concatinate it to this string,
        //! returning the result.
        template <typename T>
        String operator+(const T& operand) const;
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        //! @brief Attempts to convert a data type to string and concatinate it to this string,
        //! returning the result.
        template <typename T>
        String operator+(const T&& operand) const;
#       endif
        //! @brief Attempts to convert a data type to string and concatinate it to this string.
        template <typename T>
        String& operator+=(const T& operand);
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        //! @brief Attempts to convert a data type to string and concatinate it to this string.
        template <typename T>
        String& operator+=(const T&& operand);
#       endif
        //! @brief Checks if this string is lexicographically less than another.
        _CGUL_EXPORT bool operator<(const String& operand) const;
        friend std::ostream& operator<<(std::ostream& stream, const String& string)
        {
            if (string.null)
            {
                stream << "[NULL]";
            }
            else
            {
                stream << string.data;
            }
            return stream;
        }

        //! @brief Gets the size of the string in bytes.
        _CGUL_EXPORT Size GetSize() const;
        //! @brief Counts the number of code points in the string.
        _CGUL_EXPORT Size GetLength() const;

        //! @brief Gets an individual character from the string.
        _CGUL_EXPORT char GetChar(Size position) const;
        //! @brief Gets an individual byte from the string.
        _CGUL_EXPORT Byte GetByte(Size position) const;
        //! @brief Gets an individual code point from the string.
        _CGUL_EXPORT Size GetCodePoint(Size start, UInt32* codePoint) const;
        //! @brief Checks if the string is empty.
        _CGUL_EXPORT Boolean IsEmpty() const;
        //! @brief Checks if the string is null.
        _CGUL_EXPORT Boolean IsNull() const;

        //! @brief An accessor to the wrapped std::string data.
        _CGUL_EXPORT std::string GetData() const;
        //! @brief Accesses the raw character data from the wrapped std::string object.
        _CGUL_EXPORT const char* GetCString() const;

        _CGUL_EXPORT UInt32 Count(const String& string) const;

        //! @brief Finds the first occurence of a string.
        _CGUL_EXPORT Size FindFirstOf(const String& string, Size offset = 0) const;
#       ifdef CGUL_USE_REGEX
        _CGUL_EXPORT Size FindFirstOf(const Regex& expression, Size offset = 0) const;
#       endif
        //! @brief Finds the last occurence of a string.
        _CGUL_EXPORT Size FindLastOf(const String& string, Size offset = 0) const;
#       ifdef CGUL_USE_REGEX
        _CGUL_EXPORT Size FindLastOf(const Regex& expression, Size offset = 0) const;
#       endif

        //! @brief Gets a part of the string.  Supports both Utf-8 and individual bytes.
        _CGUL_EXPORT String SubString(Size offset, Size count = none, bool bytes = false) const;

        //! @brief Checks if the string contains another string.
        _CGUL_EXPORT bool Contains(const String& string) const;
        //! @brief Checks if the string begins with another string.
        _CGUL_EXPORT bool BeginsWith(const String& string) const;
        //! @brief Checks if the string ends with another string.
        _CGUL_EXPORT bool EndsWith(const String& string) const;

        //! @brief Sets the value of the string given a c string.
        _CGUL_EXPORT String& Set(const char* str);
        //! @brief Sets the value of the string given another string.
        _CGUL_EXPORT String& Set(const String& str);

        //! @brief Sets to a printf like format.
        _CGUL_EXPORT String& SetFormat(const String& str, ...);

        //! @brief Trims whitespace at the beginning and end of the string.
        _CGUL_EXPORT void Trim();
        //! @brief Trims whitespace at the beginning of the string.
        _CGUL_EXPORT void TrimStart();
        //! @brief Trims whitespace at the end of the string.
        _CGUL_EXPORT void TrimEnd();
        _CGUL_EXPORT void Explode(const String& delimiter, FixedList< String >* debris) const;
        _CGUL_EXPORT void Explode(const String& delimiter, Size limit, FixedList< String >* debris) const;

        //! @brief Converts the entire string to uppercase letters.
        _CGUL_EXPORT void ToLower();
        //! @brief Converts the entire string to lowercase letters.
        _CGUL_EXPORT void ToUpper();
        //! @brief Gets the string as all lowercase letters.
        _CGUL_EXPORT String GetLower() const;
        //! @brief Gets the string as all uppercase letters.
        _CGUL_EXPORT String GetUpper() const;

        //! @brief Removes all whitespace from within a string.
        _CGUL_EXPORT void RemoveWhitespace();

        //! @brief Changes the string to empty if it is null.
        _CGUL_EXPORT void SetNullToEmpty();
        //! @brief Changes the string to null if it is empty.
        _CGUL_EXPORT void SetEmptyToNull();

        //! @brief Checks if the string can be converted to the given data type.
        template <typename T>
        bool Is() const;
        //! @brief Converts the string to the given data type.
        template <typename T>
        T To() const;
        //! @brief Converts the string to the given data type.
        template <typename T>
        T To(const T& fallback) const;
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        //! @brief Converts the string to the given data type.
        template <typename T>
        T To(const T&& fallback) const;
#       endif

#       ifdef CGUL_WINDOWS
        _CGUL_EXPORT std::wstring _ToWideString() const;
        _CGUL_EXPORT void _FromWideString(const std::wstring& wideString);
#       endif

        // TODO: add in some more common string functions (maybe reference php's string, C#'s string or std::string?)
    };
}

template< typename Type >
CGUL::String CGUL::String::From(Type value)
{
    std::ostringstream ss;
    ss << value;
    return CGUL::String(ss.str());
}

/** @param operand The value to concatenate.
 *  @returns The new string.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T>
CGUL::String CGUL::String::operator+(const T& operand) const
{
    std::ostringstream ss;
    ss << operand;
    return data + ss.str();
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
/** @param operand The value to concatenate.
 *  @returns The new string.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T>
CGUL::String CGUL::String::operator+(const T&& operand) const
{
    std::ostringstream ss;
    ss << operand;
    return data + ss.str();
}
#endif

/** @param operand The value to concatenate.
 *  @returns A reference to this object.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T>
CGUL::String& CGUL::String::operator+=(const T& operand)
{
    std::ostringstream ss;
    ss << operand;
    data += ss.str();
    return *this;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
/** @param operand The value to concatenate.
 *  @returns A reference to this object.
 *  @details Attempts to convert the value to a string using standard template library streams.
 */
template <typename T>
CGUL::String& CGUL::String::operator+=(const T&& operand)
{
    std::ostringstream ss;
    ss << operand;
    data += ss.str();
    return *this;
}
#endif

/** @returns True if the string can be converted, false otherwise.
 */
template <typename T>
bool CGUL::String::Is() const
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

/** @returns The string as the given type.
 */
template <typename T>
T CGUL::String::To() const
{
    std::istringstream convert;
    convert.str(data);
    T x;
    convert >> x;
    return x;
}

/** @param fallback The value to set to if the conversion failed.
 *  @returns The string as the given type.
 */
template <typename T>
T CGUL::String::To(const T& fallback) const
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
        x = fallback;
    }
    return x;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
/** @param fallback The value to set to if the conversion failed.
 *  @returns The string as the given type.
 */
template <typename T>
T CGUL::String::To(const T&& fallback) const
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
        x = fallback;
    }
    return x;
}
#endif

#include "../External/Undefines.hpp"
