/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

// TODO: research endian-ness and what of this will break on a big-endian system

namespace Jatta
{
    namespace Network
    {
        namespace IPAddressType
        {
            enum
            {
                INVALID, IPV4, IPV6
            };
        }
        class IPAddress
        {
            UInt32 type;
            UInt64 address[2];
        public:
            _JATTA_EXPORT static IPAddress CalculateBroadcast(const IPAddress& ip, const IPAddress& netmask);
            _JATTA_EXPORT static IPAddress CalculateNetwork(const IPAddress& ip, const IPAddress& netmask);

            _JATTA_EXPORT IPAddress();
            _JATTA_EXPORT IPAddress(UInt32 address); // ipv4
            _JATTA_EXPORT IPAddress(UInt64* address); // ipv6
            _JATTA_EXPORT IPAddress(const Jatta::String& ip);
            _JATTA_EXPORT IPAddress(const Jatta::String& ip, UInt32 type);

            _JATTA_EXPORT void Set(UInt32 address); // ipv4
            _JATTA_EXPORT void Set(UInt64* address); // ipv6
            _JATTA_EXPORT void Set(const Jatta::String& ip);
            _JATTA_EXPORT void Set(const Jatta::String& ip, UInt32 type);

            _JATTA_EXPORT friend std::ostream& operator<<(std::ostream& stream, const Jatta::Network::IPAddress& ip);

            _JATTA_EXPORT UInt32 GetType() const;
            _JATTA_EXPORT bool IsValid() const;

            _JATTA_EXPORT String ToString() const;
            _JATTA_EXPORT UInt32 ToUInt32() const;
            _JATTA_EXPORT void ToUInt128(UInt64* in) const;
        };
    }
}

#include "../External/Undefines.h"
