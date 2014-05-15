// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file BigNumber.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief Large numbers which may be greater than 8 bytes.
     */
    class BigNumber
    {
        _CGUL_BIGNUM bn;
        Byte * array;
    public:
        _CGUL_EXPORT BigNumber();
        _CGUL_EXPORT BigNumber(const BigNumber& copy);
        _CGUL_EXPORT BigNumber(SInt64 v);
        _CGUL_EXPORT ~BigNumber();

        _CGUL_EXPORT void SetDWord(SInt32 v);
        _CGUL_EXPORT void SetQWord(SInt64 v);
        _CGUL_EXPORT void SetBinary(const UInt8* bytes, int len);
        _CGUL_EXPORT void SetHexString(const String& str);
        _CGUL_EXPORT void SetRandom(int numbits);

        _CGUL_EXPORT BigNumber operator=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator+=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator+(const BigNumber& obn)
        {
            BigNumber tmp(*this);
            return tmp += obn;
        }
        _CGUL_EXPORT BigNumber operator*=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator*(const BigNumber& obn)
        {
            BigNumber tmp(*this);
            return tmp *= obn;
        }
        _CGUL_EXPORT BigNumber operator-=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator-(const BigNumber& obn)
        {
            BigNumber tmp(*this);
            return tmp -= obn;
        }
        _CGUL_EXPORT BigNumber operator/=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator/(const BigNumber& obn)
        {
            BigNumber tmp(*this);
            return tmp /= obn;
        }
        _CGUL_EXPORT BigNumber operator%=(const BigNumber& obn);
        _CGUL_EXPORT BigNumber operator%(const BigNumber& obn)
        {
            BigNumber tmp(*this);
            return tmp %= obn;
        }

        _CGUL_EXPORT BigNumber operator=(SInt64 v);
        _CGUL_EXPORT BigNumber operator+=(SInt64 v);
        _CGUL_EXPORT BigNumber operator+(SInt64 v)
        {
            BigNumber tmp(*this);
            return tmp += v;
        }
        _CGUL_EXPORT BigNumber operator*=(SInt64 v);
        _CGUL_EXPORT BigNumber operator*(SInt64 v)
        {
            BigNumber tmp(*this);
            return tmp *= v;
        }
        _CGUL_EXPORT BigNumber operator-=(SInt64 v);
        _CGUL_EXPORT BigNumber operator-(SInt64 v)
        {
            BigNumber tmp(*this);
            return tmp -= v;
        }
        _CGUL_EXPORT BigNumber operator/=(SInt64 v);
        _CGUL_EXPORT BigNumber operator/(SInt64 v)
        {
            BigNumber tmp(*this);
            return tmp /= v;
        }
        _CGUL_EXPORT BigNumber operator%=(UInt64 v);
        _CGUL_EXPORT BigNumber operator%(UInt64 v)
        {
            BigNumber tmp(*this);
            return tmp %= v;
        }

        _CGUL_EXPORT bool operator==(BigNumber bn2);
        _CGUL_EXPORT bool operator!=(BigNumber bn2)
        {
            return !(*this == bn2);
        }
        _CGUL_EXPORT bool operator==(const SInt64& v);
        _CGUL_EXPORT bool operator!=(const SInt64& v)
        {
            return !(*this == v);
        }
        _CGUL_EXPORT bool operator<=(BigNumber bn2)
        {
            return ((*this == bn2) || (*this < bn2));
        }
        _CGUL_EXPORT bool operator<(BigNumber bn2);
        _CGUL_EXPORT bool operator>=(BigNumber bn2)
        {
            return ((*this == bn2) || (*this > bn2));
        }
        _CGUL_EXPORT bool operator>(BigNumber bn2);

        _CGUL_EXPORT bool operator<=(const SInt64& v)
        {
            return ((*this == v) || (*this < v));
        }
        _CGUL_EXPORT bool operator<(const SInt64& v);
        _CGUL_EXPORT bool operator>=(const SInt64& v)
        {
            return ((*this == v) || (*this > v));
        }
        _CGUL_EXPORT bool operator>(const SInt64& v);

        _CGUL_EXPORT bool IsZero() const;

        _CGUL_EXPORT BigNumber ModAdd(const BigNumber& bn1, const BigNumber& bn2);
        _CGUL_EXPORT BigNumber ModSub(const BigNumber& bn1, const BigNumber& bn2);
        _CGUL_EXPORT BigNumber ModMul(const BigNumber& bn1, const BigNumber& bn2);
        _CGUL_EXPORT BigNumber ModSqr(const BigNumber& bn1);
        _CGUL_EXPORT BigNumber ModExp(const BigNumber& bn1, const BigNumber& bn2);
        _CGUL_EXPORT BigNumber Exp(const BigNumber& obn);
        _CGUL_EXPORT BigNumber GCD(const BigNumber& obn);
        _CGUL_EXPORT UInt32 GetNumBytes();

        _CGUL_EXPORT SInt32 AsDWord();
        _CGUL_EXPORT SInt64 AsQWord();
        _CGUL_EXPORT SInt32 Sign();
        _CGUL_EXPORT Byte* AsByteArray(int minsize = 0, bool reverse = true);

        _CGUL_EXPORT String AsHexString();
        _CGUL_EXPORT String AsDecimalString();
    };
}

// Undefines
#include "../External/Undefines.hpp"
