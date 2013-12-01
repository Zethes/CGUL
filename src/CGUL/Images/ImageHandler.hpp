// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ImageHandler.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "Loader.hpp"
#include "../Containers/Vector.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    class ImageLoader;

    /** @brief Singleton class that holds the registers loaders/writers.
     */
    class ImageHandler
    {
        Vector<ImageLoader*> loaders;
        static ImageHandler* instance;

        _CGUL_EXPORT ImageHandler();
        _CGUL_EXPORT ImageHandler(ImageHandler const&);
        _CGUL_EXPORT void operator=(ImageHandler const&);
    public:
        _CGUL_EXPORT static ImageHandler* GetInstance();

        _CGUL_EXPORT void Register(ImageLoader* loader);
        _CGUL_EXPORT ImageLoader* GetLoaderByName(const String& name);
        _CGUL_EXPORT ImageLoader* GetLoaderByExtension(const String& ext);
        _CGUL_EXPORT ImageLoader* GetLoaderByFile(const String& file);

        _CGUL_EXPORT Vector<ImageLoader*> GetAllLoaders();
    };
}

#include "../External/Undefines.hpp"
