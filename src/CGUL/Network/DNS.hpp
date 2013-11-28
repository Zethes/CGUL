// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file DNS.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Network
    {
        /** @brief Utility class used to perform DNS lookups.
         */
        class DNS
        {
        public:
            enum Filter
            {
                IPV4,
                IPV6,
                ANY
            };

            DNS();
            ~DNS();

            _CGUL_EXPORT static std::vector<CGUL::String> Lookup(const CGUL::String& host, Filter filter = ANY);
        };
    }
}

#include "../External/Undefines.hpp"
