// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file AutoRelease.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief An AutoRelease class to help be RAII compliant.
     *  @details It is beneficial for some classes to not automatically release on destruction.
     *  Such classes break the RAII scheme that an object will be cleaned up if it goes out of
     *  scope.  The purpose of this method is to release classes which are not automatically
     *  cleaned on destruction, but instead provide a method to be released.
     */
    template< class T >
    class AutoRelease : public T
    {
        typedef void (T::*Release)();
        Release release;
    public:
        AutoRelease();
        ~AutoRelease();

        //! @brief Sets the automatic release method for a class.
        void SetRelease(Release release);

    };
}

#include "../External/Undefines.hpp"
#include "AutoRelease_Implement.hpp"
