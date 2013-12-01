// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ImageHandler.cpp
 */

#include "ImageHandler.hpp"
#include "../Exceptions/ImageException.hpp"

#ifdef PNG_FOUND
#   include "PNG.hpp"
#endif

CGUL::ImageHandler* CGUL::ImageHandler::instance = 0;

_CGUL_EXPORT CGUL::ImageHandler::ImageHandler()
{

}

_CGUL_EXPORT CGUL::ImageHandler* CGUL::ImageHandler::GetInstance()
{
    if (instance == NULL)
    {
        instance = new ImageHandler();
#       ifdef PNG_FOUND
        instance->Register(new ImageLoaders::PNG());
#       endif
    }
    return instance;
}

_CGUL_EXPORT void CGUL::ImageHandler::Register(ImageLoader* loader)
{
    loaders.push_back(loader);
}

_CGUL_EXPORT CGUL::ImageLoader* CGUL::ImageHandler::GetLoaderByName(const String& name)
{
    for (UInt32 i = 0; i < loaders.size(); i++)
    {
        if (loaders[i]->GetName() == name)
            return loaders[i];
    }
    return NULL;
}

_CGUL_EXPORT CGUL::ImageLoader* CGUL::ImageHandler::GetLoaderByExtension(const String& ext)
{
    for (UInt32 i = 0; i < loaders.size(); i++)
    {
        if (loaders[i]->GetExtension() == ext)
            return loaders[i];
    }
    return NULL;
}


_CGUL_EXPORT CGUL::ImageLoader* CGUL::ImageHandler::GetLoaderByFile(const String& file)
{
    for (UInt32 i = 0; i < loaders.size(); i++)
    {
        if (loaders[i]->CanLoad(file))
            return loaders[i];
    }
    return NULL;
}

_CGUL_EXPORT CGUL::Vector<CGUL::ImageLoader*> CGUL::ImageHandler::GetAllLoaders()
{
    return loaders;
}
