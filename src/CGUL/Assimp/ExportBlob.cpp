// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ExportBlog.cpp
 */

#include "ExportBlob.hpp"

_CGUL_EXPORT CGUL::Assimp::ExportBlob::ExportBlob(const ::aiExportDataBlob* blob)
{
    this->blob = blob;
    if (this->blob->next == NULL)
    {
        next = NULL;
    }
    else
    {
        next = new ExportBlob(this->blob->next);
    }
}

_CGUL_EXPORT void* CGUL::Assimp::ExportBlob::GetData()
{
    return (void*)blob->data;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::ExportBlob::GetName()
{
    return String(blob->name.C_Str());
}

_CGUL_EXPORT CGUL::Assimp::ExportBlob* CGUL::Assimp::ExportBlob::GetNext()
{
    return next;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::ExportBlob::GetSize()
{
    return (UInt32)blob->size;
}

_CGUL_EXPORT void CGUL::Assimp::ExportBlob::Free()
{
    if (next != NULL)
    {
        next->Free();
        delete next;
        next = NULL;
    }
}
