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

_CGUL_EXPORT CGUL::ImageHandler::ImageHandler()
{
    // Add default image loaders
#   ifdef PNG_FOUND
    Register(new ImageLoaders::PNG());
#   endif
}

_CGUL_EXPORT CGUL::ImageHandler::~ImageHandler()
{
    for (Vector< ImageLoader* >::iterator itr = loaders.begin(), itrEnd = loaders.end(); itr != itrEnd; itr++)
    {
        delete *itr;
    }
}

_CGUL_EXPORT CGUL::ImageHandler* CGUL::ImageHandler::GetInstance()
{
    static CGUL::ImageHandler instance;
    return &instance;
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
        {
            return loaders[i];
        }
    }
    return NULL;
}

_CGUL_EXPORT CGUL::ImageLoader* CGUL::ImageHandler::GetLoaderByExtension(const String& ext)
{
    for (UInt32 i = 0; i < loaders.size(); i++)
    {
        if (loaders[i]->GetExtension().GetLower() == ext.GetLower())
        {
            return loaders[i];
        }
    }
    return NULL;
}

_CGUL_EXPORT CGUL::ImageLoader* CGUL::ImageHandler::GetLoaderByFile(const String& file)
{
    for (UInt32 i = 0; i < loaders.size(); i++)
    {
        if (loaders[i]->CanLoad(file))
        {
            return loaders[i];
        }
    }
    return NULL;
}

_CGUL_EXPORT void CGUL::ImageHandler::GetAllLoaders(FixedList< ImageLoader* >* loaders)
{
    loaders->SetSize(this->loaders.size());
    Size count = 0;
    for (Vector< ImageLoader* >::iterator itr = this->loaders.begin(), itrEnd = this->loaders.end(); itr != itrEnd; itr++)
    {
        loaders->Set(count++, *itr);
    }
}
