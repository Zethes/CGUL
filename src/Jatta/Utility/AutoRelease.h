/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief An AutoRelease class to help be RAII compliant.
     *  @details It is beneficial for some classes to not automatically release on destruction.
     *  Such classes break the RAII scheme that an object will be cleaned up if it goes out of
     *  scope.  The purpose of this method is to release classes which are not automatically
     *  cleaned on destruction, but instead provide a method to be released.
     */
    template< class T > class AutoRelease : public T
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

#include "../External/Undefines.h"

#include "AutoRelease.ipp"
