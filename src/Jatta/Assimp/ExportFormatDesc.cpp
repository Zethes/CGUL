/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "ExportFormatDesc.h"
 
_JATTA_EXPORT Jatta::Assimp::ExportFormatDesc::ExportFormatDesc(const ::aiExportFormatDesc* desc)
{
    this->desc = desc;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetID()
{
    return String(desc->id);
}
_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetDescription()
{
    return String(desc->description);
}
_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetFileExtension()
{
    return String(desc->fileExtension);
}