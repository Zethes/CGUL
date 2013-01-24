/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"

#include "../File/File.h"

#include "Color.h"
#include <png.h>
#include <stdlib.h>

#define PNGSIGSIZE 8

static void PngReadData(png_structp pngPointer, png_bytep data, png_size_t length)
{
    char** fileData = (char**)png_get_io_ptr(pngPointer);
    memcpy(data, *fileData, length);
    *fileData += length;
}

/*bool Jatta::Png::isValid(const char* buffer, unsigned int length)
{
    return png_sig_cmp((png_bytep)buffer, 0, PNGSIGSIZE) == 0;
}

bool Jatta::Png::isValid(const std::string& fileName)
{
    // TODO: clean this up / check for errors
    unsigned int size;
    File::getFileSize(fileName, &size);
    char* buffer = new char[size];
    File::getData(fileName, buffer, size);
    bool valid = isValid(buffer, size);
    delete[] buffer;
    return valid;
}*/

/** @brief Checks if the given file is a valid Png image.
 *  @param fileName The file to load.
 *  @returns True if the file is a valid Png image, false otherwise.
 *  @details This method checks the magic number inside the Png and nothing more.
 *  @todo Will this method crash if the file's size is less than PNGSIGSIZE?
 */
_JATTA_EXPORT bool Jatta::Image::IsPng(const Jatta::String& fileName)
{
    unsigned int size = PNGSIGSIZE;
    Byte* buffer = new Byte[size];
    File::GetData(fileName.GetData(), buffer, size);

    return png_sig_cmp((png_bytep)buffer, 0, PNGSIGSIZE) == 0;
}

_JATTA_EXPORT bool Jatta::Image::LoadPng(const Jatta::String& fileName)
{
    unsigned int size;
    File::GetFileSize(fileName.GetData(), &size);
    Byte* buffer = new Byte[size];
    File::GetData(fileName.GetData(), buffer, size);

    //if (!isValid(buffer, size))
    //{
        //return false;
    //}

    //Here we create the png read struct. The 3 NULL's at the end can be used
    //for your own custom error handling functions, but we'll just use the default.
    //if the function fails, NULL is returned. Always check the return values!
    png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPtr)
    {
        throw std::runtime_error("Couldn't initialize png read struct");
    }

    //Here we create the png info struct.
    //Note that this time, if this function fails, we have to clean up the read struct!
    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr)
    {
        png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
        throw std::runtime_error("Couldn't initialize png info struct");
    }

    //Here I've defined 2 pointers up front, so I can use them in error handling.
    //I will explain these 2 later. Just making sure these get deleted on error.
    png_bytep* rowPtrs = NULL;
    char* data = NULL;

    if (setjmp(png_jmpbuf(pngPtr))) {
        //An error occured, so clean up what we have allocated so far...
        png_destroy_read_struct(&pngPtr, &infoPtr,(png_infopp)0);
        if (rowPtrs != NULL) delete [] rowPtrs;
        if (data != NULL) delete [] data;

        //Make sure you return here. libPNG will jump to here if something
        //goes wrong, and if you continue with your normal code, you might
        //End up with an infinite loop.
        throw std::runtime_error("An error occured while reading the PNG file");
    }

    buffer += 8;
    png_set_read_fn(pngPtr, (png_voidp)&buffer, PngReadData);

    //Set the amount signature bytes we've already read:
    //We've defined PNGSIGSIZE as 8;
    png_set_sig_bytes(pngPtr, PNGSIGSIZE);

    //Now call png_read_info with our pngPtr as image handle, and infoPtr to receive the file info.
    png_read_info(pngPtr, infoPtr);


    png_uint_32 imgWidth =  png_get_image_width(pngPtr, infoPtr);
    png_uint_32 imgHeight = png_get_image_height(pngPtr, infoPtr);

    //bits per CHANNEL! note: not per pixel!
    png_uint_32 bitdepth   = png_get_bit_depth(pngPtr, infoPtr);
    //Number of channels
    png_uint_32 channels   = png_get_channels(pngPtr, infoPtr);
    //Color type. (RGB, RGBA, Luminance, luminance alpha... palette... etc)
    png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);

    width = imgWidth;
    height = imgHeight;

    /*_JATTA_DEBUG_LN(imgWidth << "x" << imgHeight);
    _JATTA_DEBUG_LN("Bit Depth: " << bitdepth);
    _JATTA_DEBUG_LN("Channels: " << channels);
    _JATTA_DEBUG_LN("Color Type: " << color_type);*/

    png_bytep* row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * imgHeight);
    for (unsigned int y = 0; y < imgHeight; y++)
    {
        row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(pngPtr,infoPtr));
    }

    //delete[] buffer;

    png_read_image(pngPtr, row_pointers);

    if (png_get_color_type(pngPtr, infoPtr) == PNG_COLOR_TYPE_RGB)
    {
        colors = (Color*)new char[imgHeight * imgWidth * sizeof(Color)];

        for (unsigned int y = 0; y < imgHeight; y++)
        {
            png_byte* row = row_pointers[y];
            for (unsigned int x = 0; x < imgWidth; x++)
            {
                png_byte* ptr = &(row[x*3]);
                colors[x + y * imgWidth].r = ptr[0];
                colors[x + y * imgWidth].g = ptr[1];
                colors[x + y * imgWidth].b = ptr[2];
                colors[x + y * imgWidth].a = 255;
            }
        }
        return true;
    }

    if (png_get_color_type(pngPtr, infoPtr) == PNG_COLOR_TYPE_RGBA)
    {
        colors = (Color*)new char[imgHeight * imgWidth * sizeof(Color)];

        for (unsigned int y = 0; y < imgHeight; y++)
        {
            png_byte* row = row_pointers[y];
            for (unsigned int x = 0; x < imgWidth; x++)
            {
                png_byte* ptr = &(row[x*4]);
                colors[x + y * imgWidth].r = ptr[0];
                colors[x + y * imgWidth].g = ptr[1];
                colors[x + y * imgWidth].b = ptr[2];
                colors[x + y * imgWidth].a = ptr[3];
            }
        }
        return true;
    }

    _JATTA_DEBUG_LN("[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (" << PNG_COLOR_TYPE_RGBA << ") (is " << png_get_color_type(pngPtr, infoPtr) << ")");
    return false;
}

_JATTA_EXPORT bool Jatta::Image::SavePng(const Jatta::String& fileName)
{
    // TODO: STUFF
    return true;
}
