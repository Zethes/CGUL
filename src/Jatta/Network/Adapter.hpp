/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Containers/FixedList.h"
#include "../Network/IPAddress.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Network
    {
        //! @brief Contains information about a network interface.
        //! @brief Obtain all network interfaces on the local machine by using Network::GetAdapters.
        struct Adapter
        {
            //! @brief A brief description of the network interface, differing from each operating
            //! system and network interface.  Not reliable beyond outputting to the user.  May be
            //! the same between interfaces.
            String description;
            //! @brief The local ip address for this machine on the network.  The adapter cannot be
            //! used to effectively obtain an IP address on an outside network when the machine is
            //! behind a router or network switch.
            IPAddress ip;
            //! @brief The netmask defining the local network range for this interface.
            IPAddress netmask;
        };

        void GetAdapters(FixedList<Adapter>* adapters);
    }
}

#include "../External/Undefines.h"
