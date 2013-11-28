#include <CGUL.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main() 
{
    //Test initalize.
    CGUL::SInt32 ret;
    if ((ret = CGUL::PortAudio::Initialize()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to initalize PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    //List devices
    printf("Using version (%d) %s.\n", CGUL::PortAudio::GetVersion(), CGUL::PortAudio::GetVersionText().GetCString());
    printf("Devices: \n");
    for (unsigned int i = 0; i < CGUL::PortAudio::GetDeviceCount(); i++)
    {
        std::cout << i << ". " << CGUL::PortAudio::GetDevice(i).GetName() << std::endl;
    }
    std::cout << "Default : " << CGUL::PortAudio::GetDefaultOutputDevice().GetName() << std::endl;

    //Test SineWave.
    std::vector<CGUL::Float32*> sine;
    sine.push_back(new CGUL::Float32[800]);
    sine.push_back(new CGUL::Float32[800]);
    for (unsigned int i = 0; i < 800; i++)
    {
        if (i < 400)
        {
            sine.at(0)[i] = (float)CGUL::Math::Sin(((double)i/400.0)*CGUL::Math::pi * 2.0);
            sine.at(1)[i] = 0.0f;
        }
        else
        {
            sine.at(0)[i] = 0.0f;
            sine.at(1)[i] = (float)CGUL::Math::Sin(((double)i/400.0)*CGUL::Math::pi * 2.0);
        }
    }

    CGUL::PortAudio::OutputStream sineWave(CGUL::PortAudio::GetDefaultOutputDevice(), sine, 800); //Create mono stream.
    sineWave.SetLooping(true);
    //sineWave.SetVolume(0.25f);
    if ((ret = sineWave.Start()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    CGUL::PortAudio::Sleep(2000);
    if ((ret = sineWave.Stop()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to stop sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    if ((ret = sineWave.Close()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to close sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }


    //Test terminate.
    if ((ret = CGUL::PortAudio::Terminate()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to terminate PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}
