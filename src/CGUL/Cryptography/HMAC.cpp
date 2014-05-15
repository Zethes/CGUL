// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HMAC.cpp
 */

#include "HMAC.hpp"

CGUL::HMAC::HMAC(Byte* seed, UInt32 len, UInt32 method)
{
    digest = new Byte[20];
    Initialize(seed, len, method);
}

CGUL::HMAC::~HMAC()
{
    HMAC_CTX_cleanup(ctx);
}


void CGUL::HMAC::UpdateBigNumbers(BigNumber * bn0, ...)
{
    va_list v;
    BigNumber * bn;

    va_start(v, bn0);
    bn = bn0;
    while (bn)
    {
        UpdateData(bn->AsByteArray(), bn->GetNumBytes());
        bn = va_arg(v, BigNumber*);
    }
    va_end(v);
}   

void CGUL::HMAC::UpdateData(const Byte* data, int len)
{
    HMAC_Update(ctx, data, len);
}

void CGUL::HMAC::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::HMAC::Initialize(Byte* seed, UInt32 len, UInt32 method)
{
    md = method;
    HMAC_CTX_init(ctx);
    if (md == HMACMethods::RIPEMD)
    {
        HMAC_Init_ex(ctx, (const void*)seed, len, EVP_ripemd160(), NULL);
    }
    else //SHA by default
    {
        HMAC_Init_ex(ctx, (const void*)seed, len, EVP_sha1(), NULL);
    }
}

void CGUL::HMAC::Finalize()
{
    HMAC_Final(ctx, (UInt8*)digest, &length);
}


CGUL::Byte * CGUL::HMAC::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::HMAC::GetLength()
{
    return length;
}
