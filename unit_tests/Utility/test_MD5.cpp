#include <Jatta.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() 
{
    char* data = "jatta-data";
    //Testing data:
    if (Jatta::Encryption::MD5::Data(data, strlen(data)) != Jatta::String("87cdceaf3938c5ba71e49370b2d9fbb1"))
    { 
        printf("Failed on MD5::Data.  Expected %s.\n", Jatta::Encryption::MD5::Data(data, strlen(data)).GetCString());
        return EXIT_FAILURE; 
    }

    //Testing string:
    if (Jatta::Encryption::MD5::String("jatta") != Jatta::String("be6118832289fd42f0c8215757d75afe"))
    { 
        printf("Failed on MD5::String.  Expected %s.\n", Jatta::Encryption::MD5::String("jatta").GetCString());
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}