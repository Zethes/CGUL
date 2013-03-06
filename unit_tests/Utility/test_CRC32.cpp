#include <Jatta.h>
#include <cstdio>
#include <cstdlib>

int main() 
{
    //Testing string:
    if (Jatta::Encryption::CRC32::String("jatta") != 21320642)
    { 
        printf("Failed on CRC32::String.  Expected %f.\n", Jatta::Encryption::CRC32::String("jatta"));
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}