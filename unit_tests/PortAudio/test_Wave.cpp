#include <Jatta.h>
#include <cstdio>
#include <cstdlib>

int main() 
{
    printf("Using version (%d) %s.\n", Jatta::PortAudio::GetVersion(), Jatta::PortAudio::GetVersionText().GetCString());

    //Test initalize.
    Jatta::SInt32 ret;
    if ((ret = Jatta::PortAudio::Initialize()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to initalize PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    //Test SawWave.
    Jatta::PortAudio::SawWave sawWave(Jatta::PortAudio::GetDefaultOutputDevice());
    if ((ret = sawWave.Start()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start sawwave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    Jatta::PortAudio::Sleep(1000);
    if ((ret = sawWave.Stop()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to stop sawwave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    if ((ret = sawWave.Close()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to close sawwave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    //Test SineWave.
    Jatta::PortAudio::SineWave sineWave(Jatta::PortAudio::GetDefaultOutputDevice());
    if ((ret = sineWave.Start()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    Jatta::PortAudio::Sleep(1000);
    if ((ret = sineWave.Stop()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to stop sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    if ((ret = sineWave.Close()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to close sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }


    //Test terminate.
    if ((ret = Jatta::PortAudio::Terminate()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to terminate PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}