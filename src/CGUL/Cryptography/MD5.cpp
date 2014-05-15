// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MD5.cpp
 */

#include "MD5.hpp"

CGUL::String CGUL::MD5::Hash(String in)
{
    MD5 MD5;
    MD5.UpdateData(in);
    MD5.Finalize();

    Byte * data = MD5.GetDigest();
    String ret = "";
    for (UInt32 i = 0; i < MD5.GetLength(); ++i)
    {
        ret += data[i];
    }

    return ret;
}

CGUL::MD5::MD5()
{
    digest = new Byte[16];
    MD5_Init(ctx);
}

CGUL::MD5::~MD5()
{
    MD5_Init(ctx);
}


void CGUL::MD5::UpdateBigNumbers(BigNumber * bn0, ...)
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

void CGUL::MD5::UpdateData(const Byte* data, int len)
{
    MD5_Update(ctx, data, len);
}

void CGUL::MD5::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::MD5::Initialize()
{
    MD5_Init(ctx);
}

void CGUL::MD5::Finalize()
{
    MD5_Final((UInt8*)digest, ctx);
}


CGUL::Byte * CGUL::MD5::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::MD5::GetLength()
{
    return 16;
}
