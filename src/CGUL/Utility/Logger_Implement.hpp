// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Logger_Implement.hpp
 */

template< typename Type >
CGUL::Logger CGUL::Logger::operator<<(const Type& operand)
{
    if (!callback)
    {
        return Logger(NULL, 0, NULL);
    }
    if (counter == 0)
    {
        std::ostringstream* newStream = new std::ostringstream;
        newStream->copyfmt(*stream);
        *newStream << operand;
        return Logger(newStream, counter + 1, callback);
    }
    else
    {
        *stream << operand;
        return Logger(stream, counter + 1, callback);
    }
}
