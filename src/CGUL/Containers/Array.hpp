// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Array.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "FixedList.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    template< typename T >
    class Array : public FixedList< T >
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

#include "../External/Undefines.hpp"
#include "Array_Implement.hpp"
