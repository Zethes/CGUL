/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"

#include "Color.h"
#include <png.h>
#include <stdlib.h>

#define PNGSIGSIZE 8

static void PngReadData(png_structp pngPtr, png_bytep data, png_size_t length)
{
    char** fileData = (char**)png_get_io_ptr(pngPtr);
    memcpy(data, *fileData, length);
    *fileData += length;
}

/** @brief Checks if the given file is a valid Png image.
 *  @param fileName The file to load.
 *  @returns True if the file is a valid Png image, false otherwise.
 *  @details This method checks the magic number inside the Png and nothing more.
 *  @todo Will this method crash if the file's size is less than PNGSIGSIZE?
 */
_JATTA_EXPORT bool Jatta::Image::IsPng(const char* data, Jatta::UInt32 size)
{
    return png_sig_cmp((png_bytep)data, 0, PNGSIGSIZE) == 0;
}

/** @brief Loads a png image.
 *  @param buffer A png image loaded into memory.
 *  @param size Size of the buffer.
 *  @param flags Image flags.
 *  @note Only supports RGBA and RGB 8 bit-depth images.
 */
_JATTA_EXPORT bool Jatta::Image::LoadPng(const char* buffer, Jatta::UInt32 size)
{
    // Create the png read structure to begin reading data.
    png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPtr)
    {
        throw std::runtime_error("Couldn't initialize png read struct");
    }

    // Create the png info struct.
    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr)
    {
        png_destroy_read_struct(&pngPtr, NULL, NULL);
        throw std::runtime_error("Couldn't initialize png info struct");
    }

    // Create some arrays used in loading, to be deleted if things go wrong.
    png_bytep* rows = NULL;
    char* data = NULL;

    // Setup an error handler for libpng errors.  If anything goes wrong, it'll jump into here.
    if (setjmp(png_jmpbuf(pngPtr)))
    {
        // Clean up
        png_destroy_read_struct(&pngPtr, &infoPtr,NULL);
        delete[] rows;
        delete[] data;

        // Throw an error
        throw std::runtime_error("An error occured while reading the PNG file");
    }

    // Skip over the png file signature.
    buffer += PNGSIGSIZE;
    png_set_sig_bytes(pngPtr, PNGSIGSIZE);

    // Create a specialized read function to allow reading from memory.
    png_set_read_fn(pngPtr, (png_voidp)&buffer, PngReadData);

    // Read the png's info (size, type, bit depth, etc).
    png_read_info(pngPtr, infoPtr);

    // Store the image size.
    width = (UInt32)png_get_image_width(pngPtr, infoPtr);
    height = (UInt32)png_get_image_height(pngPtr, infoPtr);

    // Only 8 bit-depth images are supported.
    if (png_get_bit_depth(pngPtr, infoPtr) != 8)
    {
        throw std::runtime_error("Only 8 bit-depth png images are supported.");
    }

    // Calculate image size.
    UInt32 imageSize = width * height;

    // Determine the type of png we're reading.
    switch (png_get_color_type(pngPtr, infoPtr))
    {
        // A standard RGBA image, we can read this one-to-one so it's super fast.
        case PNG_COLOR_TYPE_RGBA:
        {
            // Create the color array.
            colors = (Color*)new char[imageSize * sizeof(Color)];

            // Create an array of rows needed by libpng.
            rows = new png_bytep[height];
            for (UInt32 r = 0; r < height; r++)
            {
                rows[r] = (png_bytep)(colors + width * r);
            }

            // Read the png into our image.
            png_read_image(pngPtr, rows);

            // Clean up.
            delete[] rows;
            break;
        }
        // RGB image, we need to do some memory-moving to account for the alpha value.
        case PNG_COLOR_TYPE_RGB:
        {
            // Create the color array.
            colors = (Color*)new char[imageSize * sizeof(Color)];

            // Create a temporary array to store the RGB values.
            data = new char[imageSize * 3];

            // Create an array of rows needed by libpng.
            rows = new png_bytep[height];
            for (UInt32 r = 0; r < height; r++)
            {
                rows[r] = (png_bytep)(data + width * r * 3);
            }

            // Read the png into our image.
            png_read_image(pngPtr, rows);

            // Copy over the data into our color.
            for (UInt32 i = 0; i < imageSize; i++)
            {
                memcpy(colors + i, data + i * 3, 3);
                colors[i].a = 255;
            }

            // Clean up.
            delete[] data;
            delete[] rows;
            break;
        }
        default:
        {
            throw std::runtime_error("The png image type is not supported.");
            break;
        }
    }

    return false;
}

/** @brief Saves the current image as a png.
 *  @param fileName Name of the file to write to.
 *  @note Saves as a 32bit RGBA image.
 */
_JATTA_EXPORT void Jatta::Image::SavePng(const Jatta::String& fileName, Boolean alpha)
{
    // Create the file to write to.
#   ifdef WINDOWS
    std::wstring file = fileName._ToWideString();
    FILE* stream = _wfopen(file.c_str(), L"wb");
#   else
    FILE* stream = fopen(fileName.GetCString(), "wb");
#endif
    if (!stream)
    {
        std::runtime_error("File could not be opened for writing");
    }

    // Initialize a png struct for writing.
    png_structp pngPtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPtr)
    {
        std::runtime_error("png_create_write_struct failed");
    }

    // Create an info struct to setup the png image.
    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr)
    {
        png_destroy_read_struct(&pngPtr, NULL, NULL);
        std::runtime_error("png_create_info_struct failed");
    }

    // Create arrays used later, to be deleted if things go wrong.
    png_bytep* rows = NULL;
    char* data = NULL;

    // Setup an error handler for libpng errors.  If anything goes wrong, it'll jump into here.
    if (setjmp(png_jmpbuf(pngPtr)))
    {
        delete[] rows;
        delete[] data;
        png_destroy_read_struct(&pngPtr, &infoPtr,NULL);
        std::runtime_error("Failed to write png image.");
    }

    // Setup png to use our file stream.
    png_init_io(pngPtr, stream);

    // Write the png header.
    int colorType = (alpha ? PNG_COLOR_TYPE_RGBA : PNG_COLOR_TYPE_RGB);
    png_set_IHDR(pngPtr, infoPtr, width, height, 8, colorType, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(pngPtr, infoPtr);

    // Calculate image size.
    UInt32 imageSize = width * height;

    // Create an array of rows needed by libpng.
    if (alpha) // 32bit RGBA
    {
        // Image is already 32bit RGBA, so it's a one-to-one save
        rows = new png_bytep[height];
        for (UInt32 r = 0; r < height; r++)
        {
            rows[r] = (png_bytep)(colors + width * r);
        }
    }
    else // 24bit RGB
    {
        // Create a temporary array to store the RGB values.
        data = new char[imageSize * 3];

        // Copy over just the RGB values of our color.
        for (UInt32 i = 0; i < imageSize; i++)
        {
            memcpy(data + i * 3, colors + i, 3);
        }

        // Set the rows.
        rows = new png_bytep[height];
        for (UInt32 r = 0; r < height; r++)
        {
            rows[r] = (png_bytep)(data + width * r * 3);
        }
    }
    

    // Write the image data.
    png_write_image(pngPtr, rows);
    png_write_end(pngPtr, NULL);

    // Clean up.
    delete[] rows;
    delete[] data;
    fclose(stream);
}
