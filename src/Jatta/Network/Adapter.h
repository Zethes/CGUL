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
        //! @brief Contains information about a network interface.
        struct Adapter
        {
            String description;
            IPAddress ip;
            IPAddress netmask;
        };

        //! @brief Queries all of the system's network adapters and returns them in a vector.
        std::vector<Adapter> GetAdapters();
    }
}

#include "../External/Undefines.h"
