// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MD2.cpp
 */

#include "MD2.hpp"

CGUL::String CGUL::MD2::Hash(String in)
{
    MD2 md2;
    md2.UpdateData(in);
    md2.Finalize();

    Byte * data = md2.GetDigest();
    String ret = "";
    for (UInt32 i = 0; i < md2.GetLength(); ++i)
    {
        ret += data[i];
    }

    return ret;
}

CGUL::MD2::MD2()
{
    digest = new Byte[16];
    MD2_Init(ctx);
}

CGUL::MD2::~MD2()
{
    MD2_Init(ctx);
}


void CGUL::MD2::UpdateBigNumbers(BigNumber * bn0, ...)
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

void CGUL::MD2::UpdateData(const Byte* data, int len)
{
    MD2_Update(ctx, data, len);
}

void CGUL::MD2::UpdateData(const String& str)
{
    UpdateData((Byte const*)str.GetCString(), str.GetLength());
}


void CGUL::MD2::Initialize()
{
    MD2_Init(ctx);
}

void CGUL::MD2::Finalize()
{
    MD2_Final((UInt8*)digest, ctx);
}


CGUL::Byte * CGUL::MD2::GetDigest()
{
    return digest;
}

CGUL::UInt32 CGUL::MD2::GetLength()
{
    return 16;
}
