#include <CGUL.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>

bool callback(std::vector<CGUL::Float32*> input, CGUL::UInt32 length, CGUL::PortAudio::Stream* stream)
{
    CGUL::PortAudio::OutputStream echo(CGUL::PortAudio::GetDefaultOutputDevice(), input, length);

    CGUL::SInt32 ret;
    if ((ret = echo.Start()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start echo. Error %d.\n", ret);
    }

    CGUL::PortAudio::Sleep(length);
    echo.Stop();
    echo.Close();

    return true;
}

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
    std::cout << "Default Output: " << CGUL::PortAudio::GetDefaultOutputDevice().GetName() << std::endl;
    std::cout << "Default Input: " << CGUL::PortAudio::GetDefaultInputDevice().GetName() << std::endl;

    //Create input stream.
    CGUL::PortAudio::InputStream input(CGUL::PortAudio::GetDefaultInputDevice(), callback);
    if ((ret = input.Start()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to start input stream. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }
    while (true) {};
    //CGUL::PortAudio::Sleep(5000);
    input.Stop();
    input.Close();

    //Test terminate.
    if ((ret = CGUL::PortAudio::Terminate()) != CGUL::PortAudio::Errors::NO_ERROR)
    {
        printf("Failed to terminate PortAudio. Error %d.\n", ret);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}
