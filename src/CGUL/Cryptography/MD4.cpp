// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MD4.cpp
 */

#include "MD4.hpp"

CGUL::String CGUL::MD4::Hash(String in)
{
    MD4 MD4;
    MD4.UpdateData(in);
    MD4.Finalize();

    Byte * data = MD4.GetDigest();
    String ret = "";
    for (UInt32 i = 0; i < MD4.GetLength(); ++i)
    {
        ret += data[i];
    }

    return ret;
}

CGUL::MD4::MD4()
{
    digest = new Byte[16];
    MD4_Init(ctx);
}

CGUL::MD4::~MD4()
{
    MD4_Init(ctx);
}


void CGUL::MD4::UpdateBigNumbers(BigNumber * bn0, ...)
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

void CGUL::MD4::UpdateData(const Byte* data, int len)
{
    MD4_Update(ctx, data, len);
}

void CGUL::MD4::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::MD4::Initialize()
{
    MD4_Init(ctx);
}

void CGUL::MD4::Finalize()
{
    MD4_Final((UInt8*)digest, ctx);
}


CGUL::Byte * CGUL::MD4::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::MD4::GetLength()
{
    return 16;
}
