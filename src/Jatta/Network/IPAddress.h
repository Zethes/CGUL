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
        //! @brief A list of supported IP address types.
        namespace IPAddressType
        {
            enum
            {
                //! @brief An invalid IP address.
                INVALID,
                //! @brief An IPv4 address, defined as a 32 bit unsigned integer.
                IPV4,
                //! @brief An IPv6 address, defined as a 128 bit unsigned integer.
                IPV6
            };
        }
        /** @brief Utility class to handle IPv4 or IPv6 addresses.
         */
        class IPAddress
        {
            UInt32 type;
            UInt64 address[2];
        public:
            //! @brief Calculates the broadcast address of a network given an address and netmask.
            _JATTA_EXPORT static IPAddress CalculateBroadcast(const IPAddress& ip, const IPAddress& netmask);
            //! @brief Calculates the network address given an address and netmask.
            _JATTA_EXPORT static IPAddress CalculateNetwork(const IPAddress& ip, const IPAddress& netmask);

            //! @brief Initializes an invalid IP address.
            _JATTA_EXPORT IPAddress();
            //! @brief Creates an IPv4 address from a 32 bit unsigned integer.
            _JATTA_EXPORT IPAddress(UInt32 address); // ipv4
            //! @brief Creates an IPv6 address from a 128 bit unsigned integer, defined as an array
            //! of two 64 bit unsigned integers.
            _JATTA_EXPORT IPAddress(UInt64* address); // ipv6
            //! @brief Parses a string creating an IPv4 address, an IPv6 address, or an invalid
            //! address.
            _JATTA_EXPORT IPAddress(const Jatta::String& ip);
            //! @brief Attempts to parse a string based on the given type but may result in invalid.
            _JATTA_EXPORT IPAddress(const Jatta::String& ip, UInt32 type);

            //! @brief Creates an IPv4 address from a 32 bit unsigned integer.
            _JATTA_EXPORT void Set(UInt32 address); // ipv4
            //! @brief Creates an IPv6 address from a 128 bit unsigned integer, defined as an array
            //! of two 64 bit unsigned integers.
            _JATTA_EXPORT void Set(UInt64* address); // ipv6
            //! @brief Parses a string creating an IPv4 address, an IPv6 address, or an invalid
            //! address.
            _JATTA_EXPORT void Set(const Jatta::String& ip);
            //! @brief Attempts to parse a string based on the given type but may result in invalid.
            _JATTA_EXPORT void Set(const Jatta::String& ip, UInt32 type);

            //! @brief An operator to output the IP address as a string on an output stream.
            _JATTA_EXPORT friend std::ostream& operator<<(std::ostream& stream, const Jatta::Network::IPAddress& ip);

            //! @brief Accessor for the IP address type, resulting in one of the
            //! Network::IPAddressType values.
            _JATTA_EXPORT UInt32 GetType() const;
            //! @brief Checks if the IP address type is not IPAddressType::INVALID.
            _JATTA_EXPORT bool IsValid() const;

            //! @brief Attempts to convert the IP address to a human readable string.
            _JATTA_EXPORT String ToString() const;
            //! @brief Gets a 32 bit unsigned integer from the address, only valid for IPv4
            //! addresses.
            _JATTA_EXPORT UInt32 ToUInt32() const;
            //! @brief Gets a 128 bit unsigned integer from the address defined as an array of two
            //! 64 bit unsigned integer values.
            _JATTA_EXPORT void ToUInt128(UInt64* in) const;
        };
    }
}

#include "../External/Undefines.h"
