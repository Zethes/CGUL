//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class String
    {
        std::string data;
    public:
        _JATTA_EXPORT String();
        _JATTA_EXPORT String(const String& copy);
        _JATTA_EXPORT String(String&& move);
        _JATTA_EXPORT String(const char* data);
        _JATTA_EXPORT String(const std::string& data);

        _JATTA_EXPORT String& operator=(const String& operand);
        template <typename T> String operator+(const T& value) const;
        template <typename T> String operator+(const T&& value) const;
        template <typename T> String& operator+=(const T& value);
        template <typename T> String& operator+=(const T&& value);
        _JATTA_EXPORT bool operator<(const String& operand) const;

        _JATTA_EXPORT Size getSize() const;
        _JATTA_EXPORT Size getLength() const;

        _JATTA_EXPORT Byte getByte(Size position) const;
        _JATTA_EXPORT Size getCodePoint(Size start, UInt32* codePoint) const;

#       ifdef WINDOWS
        _JATTA_EXPORT std::wstring _toWideString() const;
#       endif
    };
}

template <typename T> Jatta::String Jatta::String::operator+(const T& value) const
{
    std::ostringstream ss;
    ss << value;
    return data + ss.str();
}

template <typename T> Jatta::String Jatta::String::operator+(const T&& value) const
{
    std::ostringstream ss;
    ss << value;
    return data + ss.str();
}

template <typename T> Jatta::String& Jatta::String::operator+=(const T& value)
{
    std::ostringstream ss;
    ss << value;
    data += ss.str();
    return *this;
}

template <typename T> Jatta::String& Jatta::String::operator+=(const T&& value)
{
    std::ostringstream ss;
    ss << value;
    data += ss.str();
    return *this;
}

#include "../External/Undefines.h"