// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FileFinder.hpp
 */

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    class FileFinder
    {
#       ifdef CPP_HEADER_DIRENT_H
        void* directory;
        String fixedPath;
#       endif
    public:
        FileFinder();
        ~FileFinder();

        void Open(const String& path);
        void Close();

        bool Next(String* next);
        void Rewind();
    };
}

// Undefines
#include "../External/Undefines.hpp"
