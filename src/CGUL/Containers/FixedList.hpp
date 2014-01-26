// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FixedList.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/Container.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A fixed list interface to set a fixed amount of data and fill in the slots of data.
     *  @details This interface creates the assumption that the child data type can be dynamically
     *  resized and filled with a type of data.  The purpose of this class is to let a user decide
     *  the container that data will be put into, so long as that container inherits from this
     *  class.
     */
    template< typename T >
    class FixedList : public Container< T >
    {
    public:
        virtual void SetSize(Size size) = 0;
        virtual void Set(Size index, const T& value) = 0;
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        virtual void Set(Size index, const T&& value) = 0;
#       endif
        virtual Size GetSize() const = 0;
        virtual T& Get(Size index) = 0;
        virtual const T& Get(Size index) const = 0;
    };
}

// Undefines
#include "../External/Undefines.hpp"
