/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Network/IPAddress.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Network
    {
        struct Adapter
        {
            String description;
            IPAddress ip;
            IPAddress netmask;
        };

        std::vector<Adapter> GetAdapters();
    }
}

#include "../External/Undefines.h"
