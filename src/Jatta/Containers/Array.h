/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "FixedList.h"
#include "../External/Defines.h"

namespace Jatta
{
    template< typename T > class Array : public FixedList< T >
    {
        T* data;
        Size size;
    public:
        Array();
        ~Array();

        T* GetData();
        Size GetSize() const;

        void SetData(void* data, Size size = 0);

        void Free();

        // FixedList
        void SetSize(Size size);
        void Set(Size index, const T& value);
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        void Set(Size index, const T&& value);
#       endif
    };
}

#include "../External/Undefines.h"
#include "Array.ipp"
