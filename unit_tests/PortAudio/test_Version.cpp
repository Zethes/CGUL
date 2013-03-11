#include <Jatta.h>
#include <cstdio>
#include <cstdlib>

int main() 
{
    printf("Using version (%d) %s.\n", Jatta::PortAudio::GetVersion(), Jatta::PortAudio::GetVersionText().GetCString());

    //Test GetVersion
    if (Jatta::PortAudio::GetVersion() < 1899)
    { 
        printf("Version is too old.  Expected >=1899.\n");
        return EXIT_FAILURE; 
    }

    //Test initalize and terminate.
    Jatta::SInt32 ret;
    if ((ret = Jatta::PortAudio::Initialize()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to initalize PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    if ((ret = Jatta::PortAudio::Terminate()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to terminate PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}