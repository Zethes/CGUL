#include "Png.h"

#include "../File/File.h"

#include <png.h>
#include <iostream>
#include <stdlib.h>

#define PNGSIGSIZE 8

static void pngReadData(png_structp pngPointer, png_bytep data, png_size_t length)
{
    char** fileData = (char**)png_get_io_ptr(pngPointer);
    memcpy(data, *fileData, length);
    *fileData += length;
}

bool Jatta::Png::isValid(const char* buffer, unsigned int length)
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
}

bool Jatta::Png::load(const std::string& fileName)
{
    unsigned int size;
    File::getFileSize(fileName, &size);
    char* buffer = new char[size];
    File::getData(fileName, buffer, size);

    if (!isValid(buffer, size))
    {
        return false;
    }

    //Here we create the png read struct. The 3 NULL's at the end can be used
    //for your own custom error handling functions, but we'll just use the default.
    //if the function fails, NULL is returned. Always check the return values!
    png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPtr) {
        std::cerr << "ERROR: Couldn't initialize png read struct" << std::endl;
        return false; //Do your own error recovery/handling here
    }

    //Here we create the png info struct.
    //Note that this time, if this function fails, we have to clean up the read struct!
    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr) {
        std::cerr << "ERROR: Couldn't initialize png info struct" << std::endl;
        png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
        return false; //Do your own error recovery/handling here
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

        std::cout << "ERROR: An error occured while reading the PNG file\n";

        //Make sure you return here. libPNG will jump to here if something
        //goes wrong, and if you continue with your normal code, you might
        //End up with an infinite loop.
        return false; // Do your own error handling here.
    }

    buffer += 8;
    png_set_read_fn(pngPtr, (png_voidp)&buffer, pngReadData);

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

    std::cout << imgWidth << "x" << imgHeight << std::endl;
    std::cout << "Bit Depth: " << bitdepth << std::endl;
    std::cout << "Channels: " << channels << std::endl;
    std::cout << "Color Type: " << color_type << std::endl;

    png_bytep* row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * imgHeight);
    for (int y = 0; y < imgHeight; y++)
    {
        row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(pngPtr,infoPtr));
    }

    delete[] buffer;

    png_read_image(pngPtr, row_pointers);

    if (png_get_color_type(pngPtr, infoPtr) == PNG_COLOR_TYPE_RGB)
    {
        colors = (Color*)new char[imgHeight * imgWidth * sizeof(Color)];

        for (int y=0; y<imgHeight; y++)
        {
            png_byte* row = row_pointers[y];
            for (int x=0; x<imgWidth; x++)
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

        for (int y=0; y<imgHeight; y++)
        {
            png_byte* row = row_pointers[y];
            for (int x=0; x<imgWidth; x++)
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

    std::cout << "[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (" << PNG_COLOR_TYPE_RGBA << ") (is " << png_get_color_type(pngPtr, infoPtr) << ")" << std::endl;
    return false;
}