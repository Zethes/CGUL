/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_NETWORK
#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Network
    {
        class DNS
        {
        public:
            enum class Filter
            {
                IPV4,
                IPV6,
                ANY
            };

            DNS();
            ~DNS();

            _JATTA_EXPORT static std::vector<Jatta::String> Lookup(const Jatta::String& host, Filter filter = Filter::ANY);
        };
    }
}

#include "../External/Undefines.h"
#endif
