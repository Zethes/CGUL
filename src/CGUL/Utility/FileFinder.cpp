// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FileFinder.cpp
 */

// Header
#include "FileFinder.hpp"

// System Includes
#include <sys/stat.h>
#ifdef CGUL_WINDOWS
#   include <direct.h>
#   ifdef DeleteFile
#       undef DeleteFile
#   endif
#else
#   include <unistd.h>
#endif
#ifdef CPP_HEADER_DIRENT_H
#   include <dirent.h>
#endif

#   ifdef CPP_HEADER_DIRENT_H
CGUL::FileFinder::FileFinder() :
    directory(NULL)
{
}
#   else
CGUL::FileFinder::FileFinder()
{
}
#   endif

CGUL::FileFinder::~FileFinder()
{
}

void CGUL::FileFinder::Open(const String& path)
{
#   ifdef CPP_HEADER_DIRENT_H
    if (directory != NULL)
    {
        throw std::runtime_error("File finder is already open.");
    }

    fixedPath = path;
    if (!fixedPath.EndsWith("/") && !fixedPath.EndsWith("\\"))
    {
        // Prefer unix style paths, since windows accepts it (for the most part)
        if (fixedPath.Contains("/"))
        {
            fixedPath += "/";
        }
        else
        {
            fixedPath += "\\";
        }
    }

    directory = (void*)opendir(fixedPath.GetCString());
    if (directory == NULL)
    {
        throw std::runtime_error("Could not open directory.");
    }
#else
    throw std::runtime_error("CGUL was not built with FileFinder support.");
#   endif
}

void CGUL::FileFinder::Close()
{
#   ifdef CPP_HEADER_DIRENT_H
    if (directory == NULL)
    {
        throw std::runtime_error("File finder not open.");
    }

    closedir((DIR*)directory);
#   endif
}

bool CGUL::FileFinder::Next(String* next)
{
#   ifdef CPP_HEADER_DIRENT_H
    if (directory == NULL)
    {
        throw std::runtime_error("File finder not open.");
    }

    struct dirent* entry = NULL;
    entry = readdir((DIR*)directory);
    if (entry == NULL)
    {
        return false;
    }
    *next = fixedPath + String(entry->d_name);
    return true;
#   endif
    return "";
}

void CGUL::FileFinder::Rewind()
{
#   ifdef CPP_HEADER_DIRENT_H
    if (directory == NULL)
    {
        throw std::runtime_error("File finder not open.");
    }

    rewinddir((DIR*)directory);
#   endif
}
