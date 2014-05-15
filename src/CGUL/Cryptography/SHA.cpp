// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SHA.cpp
 */

#include "SHA.hpp"

CGUL::SHA::SHA()
{
    SHA1_Init(ctx);
}

CGUL::SHA::~SHA()
{
    SHA_Init(ctx);
}


void CGUL::SHA::UpdateBigNumbers(BigNumber * bn0, ...)
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

void CGUL::SHA::UpdateData(const Byte* data, int len)
{
    SHA1_Update(ctx, data, len);
}

void CGUL::SHA::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::SHA::Initialize()
{
    SHA1_Init(ctx);
}

void CGUL::SHA::Finalize()
{
    SHA1_Final(digest, ctx);
}


CGUL::Byte * CGUL::SHA::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::SHA::GetLength()
{
    return 20;
}
