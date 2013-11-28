// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file IPAddress.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

// TODO: research endian-ness and what of this will break on a big-endian system

namespace CGUL
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
            _CGUL_EXPORT static IPAddress CalculateBroadcast(const IPAddress& ip, const IPAddress& netmask);
            //! @brief Calculates the network address given an address and netmask.
            _CGUL_EXPORT static IPAddress CalculateNetwork(const IPAddress& ip, const IPAddress& netmask);

            //! @brief Initializes an invalid IP address.
            _CGUL_EXPORT IPAddress();
            //! @brief Creates an IPv4 address from a 32 bit unsigned integer.
            _CGUL_EXPORT IPAddress(UInt32 address); // ipv4
            //! @brief Creates an IPv6 address from a 128 bit unsigned integer, defined as an array
            //! of two 64 bit unsigned integers.
            _CGUL_EXPORT IPAddress(UInt64* address); // ipv6
            //! @brief Parses a string creating an IPv4 address, an IPv6 address, or an invalid
            //! address.
            _CGUL_EXPORT IPAddress(const CGUL::String& ip);
            //! @brief Attempts to parse a string based on the given type but may result in invalid.
            _CGUL_EXPORT IPAddress(const CGUL::String& ip, UInt32 type);

            //! @brief Creates an IPv4 address from a 32 bit unsigned integer.
            _CGUL_EXPORT void Set(UInt32 address); // ipv4
            //! @brief Creates an IPv6 address from a 128 bit unsigned integer, defined as an array
            //! of two 64 bit unsigned integers.
            _CGUL_EXPORT void Set(UInt64* address); // ipv6
            //! @brief Parses a string creating an IPv4 address, an IPv6 address, or an invalid
            //! address.
            _CGUL_EXPORT void Set(const CGUL::String& ip);
            //! @brief Attempts to parse a string based on the given type but may result in invalid.
            _CGUL_EXPORT void Set(const CGUL::String& ip, UInt32 type);

            //! @brief An operator to output the IP address as a string on an output stream.
            _CGUL_EXPORT friend std::ostream& operator<<(std::ostream& stream, const CGUL::Network::IPAddress& ip);

            //! @brief Accessor for the IP address type, resulting in one of the
            //! Network::IPAddressType values.
            _CGUL_EXPORT UInt32 GetType() const;
            //! @brief Checks if the IP address type is not IPAddressType::INVALID.
            _CGUL_EXPORT bool IsValid() const;

            //! @brief Attempts to convert the IP address to a human readable string.
            _CGUL_EXPORT String ToString() const;
            //! @brief Gets a 32 bit unsigned integer from the address, only valid for IPv4
            //! addresses.
            _CGUL_EXPORT UInt32 ToUInt32() const;
            //! @brief Gets a 128 bit unsigned integer from the address defined as an array of two
            //! 64 bit unsigned integer values.
            _CGUL_EXPORT void ToUInt128(UInt64* in) const;
        };
    }
}

#include "../External/Undefines.hpp"
