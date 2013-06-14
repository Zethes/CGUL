#include <Jatta.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main() 
{
    //Test initalize.
    Jatta::SInt32 ret;
    if ((ret = Jatta::PortAudio::Initialize()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to initalize PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    //List devices
    printf("Using version (%d) %s.\n", Jatta::PortAudio::GetVersion(), Jatta::PortAudio::GetVersionText().GetCString());
    printf("Devices: \n");
    for (unsigned int i = 0; i < Jatta::PortAudio::GetDeviceCount(); i++)
    {
        std::cout << i << ". " << Jatta::PortAudio::GetDevice(i).GetName() << std::endl;
    }
    std::cout << "Default : " << Jatta::PortAudio::GetDefaultOutputDevice().GetName() << std::endl;

    //Test SineWave.
    std::vector<Jatta::Float32*> sine;
    sine.push_back(new Jatta::Float32[800]);
    sine.push_back(new Jatta::Float32[800]);
    for (unsigned int i = 0; i < 800; i++)
    {
        if (i < 400)
        {
            sine.at(0)[i] = (float)Jatta::Math::Sin(((double)i/400.0)*Jatta::Math::pi * 2.0);
            sine.at(1)[i] = 0.0f;
        }
        else
        {
            sine.at(0)[i] = 0.0f;
            sine.at(1)[i] = (float)Jatta::Math::Sin(((double)i/400.0)*Jatta::Math::pi * 2.0);
        }
    }

    Jatta::PortAudio::OutputStream sineWave(Jatta::PortAudio::GetDefaultOutputDevice(), sine, 800); //Create mono stream.
    sineWave.SetLooping(true);
    //sineWave.SetVolume(0.25f);
    if ((ret = sineWave.Start()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start sineWave. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    Jatta::PortAudio::Sleep(2000);
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