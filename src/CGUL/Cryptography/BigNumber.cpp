// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file BigNumber.cpp
 */

#include "BigNumber.hpp"
#include "../Utility/Memory.hpp"
#include "../Math/Math.hpp"

CGUL::BigNumber::BigNumber()
{
    bn = BN_new();
    array = NULL;
}

CGUL::BigNumber::BigNumber(const BigNumber& copy)
{
    bn = BN_dup(copy.bn);
    array = NULL;
}  

CGUL::BigNumber::BigNumber(SInt64 v)
{
    bn = BN_new();
    SetQWord(v);
    array = NULL;
}

CGUL::BigNumber::~BigNumber()
{
    BN_free(bn);
    if (array)
        delete [] array;
}


void CGUL::BigNumber::SetDWord(SInt32 v)
{
    if (v < 0)
        BN_set_negative(bn, 1);
    v = Math::Abs(v);

    BN_set_word(bn, v);
}

void CGUL::BigNumber::SetQWord(SInt64 v)
{
    if (v < 0)
        BN_set_negative(bn, 1);
    v = Math::Abs(v);

    BN_set_word(bn, (UInt32)(v >> 32));
    BN_lshift(bn, bn, 32);
    BN_add_word(bn, (UInt32)(v & 0xFFFFFFFF));
}

void CGUL::BigNumber::SetBinary(const UInt8* bytes, int len)
{
    UInt8 tmp[1000];
    for (UInt32 i = 0; i < len; ++i)
    {
        tmp[i] = bytes[len-1-i];
    }
    BN_bin2bn(tmp, len, bn);
}

void CGUL::BigNumber::SetHexString(const String& str)
{
    BN_hex2bn(&bn, str.GetCString());
}

void CGUL::BigNumber::SetRandom(int numbits)
{
    BN_rand(bn, numbits, 0, 1);
}


CGUL::BigNumber CGUL::BigNumber::operator=(const BigNumber& obn)
{
    BN_copy(bn, obn.bn);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator+=(const BigNumber& obn)
{
    BN_add(bn, bn, obn.bn);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator*=(const BigNumber& obn)
{
    BN_CTX* bnctx = BN_CTX_new();
    BN_mul(bn, bn, obn.bn, bnctx);
    BN_CTX_free(bnctx);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator-=(const BigNumber& obn)
{
    BN_sub(bn, bn, obn.bn);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator/=(const BigNumber& obn)
{
    BN_CTX* bnctx = BN_CTX_new();
    BN_div(bn, NULL, bn, obn.bn, bnctx);
    BN_CTX_free(bnctx);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator%=(const BigNumber& obn)
{
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod(bn, bn, obn.bn, bnctx);
    BN_CTX_free(bnctx);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator=(SInt64 v)
{
    SetQWord(v);
}

CGUL::BigNumber CGUL::BigNumber::operator+=(SInt64 v)
{
    if (v < 0)
    {
        *this -= Math::Abs(v);
    }
    else
    {
        BN_add_word(bn, (UInt64)v);
    }
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator*=(SInt64 v)
{
    if (v < 0)
        BN_set_negative(bn, !BN_is_negative(bn));
    v = Math::Abs(v);

    BN_mul_word(bn, (UInt64)v);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator-=(SInt64 v)
{
    if (v < 0)
    {
        BN_add_word(bn, Math::Abs(v));
    }
    else
    {
        if (*this < v)
        {
            BN_set_negative(bn, !BN_is_negative(bn));
            BN_add_word(bn, (UInt64)(v - AsQWord()));
        }

        BN_sub_word(bn, (UInt64)v);
    }
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator/=(SInt64 v)
{
    if (v < 0)
        BN_set_negative(bn, !BN_is_negative(bn));
    v = Math::Abs(v);

    BN_div_word(bn, (UInt64)v);
    return *this;
}

CGUL::BigNumber CGUL::BigNumber::operator%=(UInt64 v)
{
    BN_mod_word(bn, (UInt64)v);
    return *this;
}

bool CGUL::BigNumber::operator==(BigNumber bn2)
{
    return (BN_cmp(bn, bn2.bn) == 0);
}

bool CGUL::BigNumber::operator==(const SInt64& v)
{
    BigNumber bn2(v);
    return (BN_cmp(bn, bn2.bn) == 0);
}

bool CGUL::BigNumber::operator<(BigNumber bn2)
{
    return (BN_cmp(bn, bn2.bn) == -1);
}

bool CGUL::BigNumber::operator>(BigNumber bn2)
{
    return (BN_cmp(bn, bn2.bn) == 1);
}

bool CGUL::BigNumber::operator<(const SInt64& v)
{
    BigNumber bn2(v);
    return (BN_cmp(bn, bn2.bn) == -1);
}

bool CGUL::BigNumber::operator>(const SInt64& v)
{
    BigNumber bn2(v);
    return (BN_cmp(bn, bn2.bn) == 1);
}


bool CGUL::BigNumber::IsZero() const
{
    return (UInt32)BN_is_zero(bn) != 0;
}

CGUL::BigNumber CGUL::BigNumber::ModAdd(const BigNumber& bn1, const BigNumber& bn2)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod_add(ret.bn, bn, bn1.bn, bn2.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::ModSub(const BigNumber& bn1, const BigNumber& bn2)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod_sub(ret.bn, bn, bn1.bn, bn2.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::ModMul(const BigNumber& bn1, const BigNumber& bn2)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod_mul(ret.bn, bn, bn1.bn, bn2.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::ModSqr(const BigNumber& bn1)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod_sqr(ret.bn, bn, bn1.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::ModExp(const BigNumber& bn1, const BigNumber& bn2)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_mod_exp(ret.bn, bn, bn1.bn, bn2.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::Exp(const BigNumber& obn)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_exp(ret.bn, bn, obn.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}

CGUL::BigNumber CGUL::BigNumber::GCD(const BigNumber& obn)
{
    BigNumber ret;
    BN_CTX* bnctx = BN_CTX_new();
    BN_gcd(ret.bn, bn, obn.bn, bnctx);
    BN_CTX_free(bnctx);
    return ret;
}


CGUL::UInt32 CGUL::BigNumber::GetNumBytes()
{
    return BN_num_bytes(bn);
}


CGUL::SInt32 CGUL::BigNumber::AsDWord()
{
    return (UInt32)BN_get_word(bn) * Sign();
}

CGUL::SInt64 CGUL::BigNumber::AsQWord()
{
    SInt64 r;
    ::bignum_st* copyBN = BN_dup(bn);

    BN_lshift(copyBN, copyBN, 32);
    r = (BN_get_word(copyBN) & 0xFFFFFFFF);
    BN_free(copyBN);

    r += AsDWord();
    return r * Sign();
}

CGUL::SInt32 CGUL::BigNumber::Sign()
{
    if (IsZero())
        return 0;

    return (BN_is_negative(bn) ? -1 : 1);
}

CGUL::Byte* CGUL::BigNumber::AsByteArray(int minsize, bool reverse)
{
    int len = (minsize >= GetNumBytes()) ? minsize : GetNumBytes();

    if (array)
        delete [] array;
    array = new UInt8[len];

    if (len > GetNumBytes())
        Memory::ZeroData((void*)array, len);
    BN_bn2bin(bn, (unsigned char*)array);

    if (reverse)
        std::reverse(array, array+len);
    return array;
}


CGUL::String CGUL::BigNumber::AsHexString()
{
    return String(BN_bn2hex(bn));
}

CGUL::String CGUL::BigNumber::AsDecimalString()
{
    return String(BN_bn2dec(bn));
}