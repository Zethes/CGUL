// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ExportFormatDesc.cpp
 */

#include "ExportFormatDesc.hpp"

_CGUL_EXPORT CGUL::Assimp::ExportFormatDesc::ExportFormatDesc(const ::aiExportFormatDesc* desc)
{
    this->desc = desc;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::ExportFormatDesc::GetID()
{
    return String(desc->id);
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::ExportFormatDesc::GetDescription()
{
    return String(desc->description);
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::ExportFormatDesc::GetFileExtension()
{
    return String(desc->fileExtension);
}
