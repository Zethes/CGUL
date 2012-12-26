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
        String();
        String(const String& copy);
        String(String&& move);
        String(const char* data);
        String(const std::string& data);

        String& operator=(const String& operand);
        template <typename T> String operator+(const T& value) const;
        template <typename T> String operator+(const T&& value) const;
        template <typename T> String& operator+=(const T& value);
        template <typename T> String& operator+=(const T&& value);
        bool operator<(const String& operand) const;

        Size getSize() const;
        Size getLength() const;

        Byte getByte(Size position) const;
        Size getCodePoint(Size start, UInt32* codePoint) const;

#       ifdef WINDOWS
        std::wstring _toWideString() const;
#       endif
    };
}

Jatta::String operator "" _jatta(const char* literal_string, unsigned int length);

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