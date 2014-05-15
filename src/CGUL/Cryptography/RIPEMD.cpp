// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file RIPEMD.cpp
 */

#include "RIPEMD.hpp"

CGUL::RIPEMD::RIPEMD()
{
    digest = new Byte[20];
    RIPEMD160_Init(ctx);
}

CGUL::RIPEMD::~RIPEMD()
{
    RIPEMD160_Init(ctx);
}


void CGUL::RIPEMD::UpdateBigNumbers(BigNumber * bn0, ...)
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

void CGUL::RIPEMD::UpdateData(const Byte* data, int len)
{
    RIPEMD160_Update(ctx, data, len);
}

void CGUL::RIPEMD::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::RIPEMD::Initialize()
{
    RIPEMD160_Init(ctx);
}

void CGUL::RIPEMD::Finalize()
{
    RIPEMD160_Final((UInt8*)digest, ctx);
}


CGUL::Byte * CGUL::RIPEMD::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::RIPEMD::GetLength()
{
    return 16;
}
