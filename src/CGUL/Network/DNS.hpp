// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file DNS.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/List.hpp"
#include "../Network/IPAddress.hpp"
#include "../Utility/String.hpp"

// Defines
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
                UNSPECIFIED
            };

            DNS();
            ~DNS();

            _CGUL_EXPORT static void Lookup(const CGUL::String& host, List< IPAddress >* addresses);
            _CGUL_EXPORT static void Lookup(const CGUL::String& host, Filter filter, List< IPAddress >* addresses);
        };
    }
}

// Undefines
#include "../External/Undefines.hpp"
