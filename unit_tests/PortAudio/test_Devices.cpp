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

    //Test GetDeviceCount
    if ((ret = Jatta::PortAudio::GetDeviceCount()) <= 0)
    { 
        printf("Not enough devices to perform test. %d\n", ret);
        return EXIT_FAILURE; 
    }

    //Test GetHostApiCount
    if ((ret = Jatta::PortAudio::GetHostApiCount()) <= 0)
    { 
        printf("Not enough host apis to perform test. %d\n", ret);
        return EXIT_FAILURE; 
    }

    //Test GetDefaultOutputDevice
    Jatta::PortAudio::Device defaultOutput = Jatta::PortAudio::GetDefaultOutputDevice();
    Jatta::PortAudio::Device other = Jatta::PortAudio::GetDevice(Jatta::PortAudio::GetDefaultOutputDeviceIndex());
    if (defaultOutput.GetName() != other.GetName())
    { 
        printf("GetDefaultOutputDevice failed.\n");
        return EXIT_FAILURE; 
    }

    //Test GetDefaultInputDevice
    Jatta::PortAudio::Device defaultInput = Jatta::PortAudio::GetDefaultInputDevice();
    other = Jatta::PortAudio::GetDevice(Jatta::PortAudio::GetDefaultInputDeviceIndex());
    if (defaultInput.GetName() != other.GetName())
    { 
        printf("GetDefaultInputDevice failed.\n");
        return EXIT_FAILURE; 
    }

    //Test GetDefaultHostApi
    Jatta::PortAudio::HostApi defaultApi = Jatta::PortAudio::GetDefaultHostApi();
    Jatta::PortAudio::HostApi otherApi = Jatta::PortAudio::GetHostApi(Jatta::PortAudio::GetDefaultHostApiIndex());
    if (defaultApi.GetName() != otherApi.GetName())
    { 
        printf("GetDefaultOutputDevice failed.\n");
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