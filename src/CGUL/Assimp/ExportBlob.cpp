/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "ExportBlob.h"

_JATTA_EXPORT Jatta::Assimp::ExportBlob::ExportBlob(const ::aiExportDataBlob* blob)
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

_JATTA_EXPORT void* Jatta::Assimp::ExportBlob::GetData()
{
    return (void*)blob->data;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportBlob::GetName()
{
    return String(blob->name.C_Str());
}

_JATTA_EXPORT Jatta::Assimp::ExportBlob* Jatta::Assimp::ExportBlob::GetNext()
{
    return next;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::ExportBlob::GetSize()
{
    return (UInt32)blob->size;
}

_JATTA_EXPORT void Jatta::Assimp::ExportBlob::Free()
{
    if (next != NULL)
    {
        next->Free();
        delete next;
        next = NULL;
    }
}
