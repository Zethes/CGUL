// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Filter.cpp
 */

#include "Filter.hpp"
#include "../Math/Math.hpp"
#include "../Utility/Memory.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT CGUL::ImageFilter::ImageFilter()
{
    filterWidth = filterHeight = 0;
    factor = bias = 0;
}

_CGUL_EXPORT CGUL::ImageFilter::ImageFilter(UInt32 w, UInt32 h, Float32 ** filter, Float32 factor, Float32 bias)
{
    Set(w, h, filter, factor, bias);
    
}
_CGUL_EXPORT CGUL::ImageFilter::~ImageFilter()
{

}

_CGUL_EXPORT void CGUL::ImageFilter::Set(UInt32 w, UInt32 h, Float32 ** f, Float32 fa, Float32 b)
{
    filter = new Float32*[w];
    for (UInt32 i = 0; i < w; ++i)
    {
        filter[i] = new Float32[h];
    }

    filterWidth = w;
    filterHeight = h;
    Memory::Copy(filter, f, w * h * sizeof(Float32));
    factor = fa;
    bias = b;
}

_CGUL_EXPORT void CGUL::ImageFilter::Apply(Image* src, Image* dst)
{
    UInt32 w = src->GetWidth();
    UInt32 h = src->GetHeight();
    UInt32 ps = src->GetPixelSize();
    Byte* data = new Byte[src->GetDataSize()];
    data = src->GetData<Byte>();

    Byte* out = new Byte[src->GetDataSize()];
    Memory::Copy(out, data, src->GetDataSize());

    for (UInt32 x = 0; x < w; x++)
    {
        for (UInt32 y = 0; y < h; y++)
        {
            Float32 * components = new Float32[ps];
            for (UInt32 i = 0; i < ps; ++i)
            { components[i] = 0; }

            for (UInt32 filterX = 0; filterX < filterWidth; filterX++)
            {
                for (UInt32 filterY = 0; filterY < filterHeight; filterY++)
                {
                    int imgX = (x - filterWidth / 2 + filterX + w) % w;
                    int imgY = (y - filterHeight / 2 + filterY + h) % h;

                    for (UInt32 i = 0; i < ps; ++i)
                    {
                        components[i] += data[imgY*w*ps + imgX*ps + i] * filter[filterX][filterY];
                    }
                }
            }

            for (UInt32 i = 0; i < ps; ++i)
            {
                out[y*w*ps + x*ps + i] = (Byte)Math::Min(Math::Max(int(factor * components[i] + bias), 0), 255);
            }
        }
    }

    dst->Setup(src->GetFormat(), UCoord32(w, h), out);
}
