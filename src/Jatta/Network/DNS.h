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
    namespace Network
    {
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

            _JATTA_EXPORT static std::vector<Jatta::String> Lookup(const Jatta::String& host, Filter filter = ANY);
        };
    }
}

#include "../External/Undefines.h"