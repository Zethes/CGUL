// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Logger.cpp
 */

// Header
#include "Logger.hpp"

CGUL::Logger::Logger() :
    stream(new std::ostringstream),
    counter(0),
    callback(NULL)
{
}

CGUL::Logger::Logger(Callback callback) :
    stream(new std::ostringstream),
    counter(0),
    callback(callback)
{
}

CGUL::Logger::~Logger()
{
    if (stream != NULL && counter == 1)
    {
        if (callback)
        {
            // The order here is important. The callback could throw an exception, and we
            // need to make sure the stream pointer gets deleted. Transfer the string to a
            // stack object so it can be deleted by RAII if needed.
            String result = stream->str();
            delete stream;
            (*callback)(result);
        }
        else
        {
            delete stream;
        }
    }
    else if (counter == 0)
    {
        delete stream;
    }
}

void CGUL::Logger::SetCallback(Callback callback)
{
    this->callback = callback;
}

void CGUL::Logger::CopyFormat(const std::ostream& stream)
{
    if (counter == 0)
    {
        this->stream->copyfmt(stream);
    }
}

void CGUL::Logger::CopyFormat(const Logger& logger)
{
    if (counter == 0 && logger.counter == 0)
    {
        this->stream->copyfmt(*logger.stream);
    }
}

void CGUL::Logger::Manipulate(std::ios_base& (*manipulator)(std::ios_base&))
{
    if (counter == 0)
    {
        *stream << manipulator;
    }
}

CGUL::Logger CGUL::Logger::operator<<(std::ostream& (*manipulator)(std::ostream&))
{
    if (!callback)
    {
        return Logger(NULL, 0, NULL);
    }
    if (counter == 0)
    {
        std::ostringstream* newStream = new std::ostringstream;
        newStream->copyfmt(*stream);
        *newStream << manipulator;
        return Logger(newStream, counter + 1, callback);
    }
    else
    {
        *stream << manipulator;
        return Logger(stream, counter + 1, callback);
    }
}

CGUL::Logger::Logger(std::ostringstream* stream, int counter, Callback callback) :
    stream(stream),
    counter(counter),
    callback(callback)
{
}
