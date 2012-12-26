#include "String.h"

Jatta::String operator "" _jatta(const char* literal_string, unsigned int length)
{
    return Jatta::String(literal_string);
}

Jatta::String::String() : data()
{
}

Jatta::String::String(const String& copy) : data(copy.data)
{
}

Jatta::String::String(String&& move) : data(std::move(move.data))
{
}

Jatta::String::String(const char* data) : data(data)
{
}

Jatta::String::String(const std::string& data) : data(data)
{
}

Jatta::String& Jatta::String::operator=(const String& operand)
{
    this->data = operand.data;
    return *this;
}

bool Jatta::String::operator<(const String& operand) const
{
    return this->data < operand.data;
}

Jatta::Size Jatta::String::getSize() const
{
    return data.length();
}

Jatta::Size Jatta::String::getLength() const
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

Jatta::Byte Jatta::String::getByte(Size position) const
{
    return (Byte)data.at(position);
}

Jatta::Size Jatta::String::getCodePoint(Size start, UInt32* codePoint) const
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

#ifdef WINDOWS
std::wstring Jatta::String::_toWideString() const
{
    int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), -1, 0, 0);
    wchar_t* buffer = new wchar_t[size];
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data.c_str(), data.length(), buffer, size);
    buffer[size - 1] = 0;
    std::wstring wideString(buffer);
    delete[] buffer;
    return wideString;
}
#endif