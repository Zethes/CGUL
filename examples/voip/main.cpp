#include <Jatta.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

bool callback(std::vector<Jatta::Float32*> input, Jatta::UInt32 length, Jatta::PortAudio::Stream* stream)
{
    Jatta::PortAudio::OutputStream echo(Jatta::PortAudio::GetDefaultOutputDevice(), input, length);

    Jatta::SInt32 ret;
    if ((ret = echo.Start()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start echo. Error %d.\n", ret);
    }

    Jatta::PortAudio::Sleep(length);
    echo.Stop();
    echo.Close();

    return true;
}

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
    std::cout << "Default Output: " << Jatta::PortAudio::GetDefaultOutputDevice().GetName() << std::endl;
    std::cout << "Default Input: " << Jatta::PortAudio::GetDefaultInputDevice().GetName() << std::endl;

    //Create input stream.
    Jatta::PortAudio::InputStream input(Jatta::PortAudio::GetDefaultInputDevice(), callback);
    if ((ret = input.Start()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start input stream. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    while (true) {};
    //Jatta::PortAudio::Sleep(5000);
    input.Stop();
    input.Close();

    //Test terminate.
    if ((ret = Jatta::PortAudio::Terminate()) != Jatta::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to terminate PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}