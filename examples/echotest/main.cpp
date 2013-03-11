#include <Jatta.h>
using namespace Jatta;

#include <iostream>
using namespace std;

class StreamOut : public Jatta::PortAudio::Stream
{
private:
    int position;
    std::vector<Float32> inputL;
    std::vector<Float32> inputR;
public:
    StreamOut(Jatta::PortAudio::Device device, std::vector<Float32> inputL,  std::vector<Float32> inputR) : Jatta::PortAudio::Stream()
    {
        this->inputL = inputL;
        this->inputR = inputR;
        OpenStream(device);
        position = 0;
    }

    bool Update(Jatta::PortAudio::StreamData* data)
    {
        if (position >= inputL.size() || position >= inputR.size())
        {
            data->Channels[0] = data->Channels[1] = 0.0f;
        }
        else
        {
            data->Channels[0] = inputL[position];
            data->Channels[1] = inputR[position];
            position++;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    system("clear");

    Jatta::PortAudio::Initialize();

    cout << "Select an output device: " << endl;
    cout << "\t0. " << Jatta::PortAudio::GetDefaultOutputDevice().GetName() << " (default)" << endl;
    for (unsigned int i = 0; i < Jatta::PortAudio::GetDeviceCount(); i++)
    {
        cout << "\t" << i+1 << ". " << Jatta::PortAudio::GetDevice(i).GetName() << endl;
    }
    cout << endl << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice < 0 || choice >= Jatta::PortAudio::GetDeviceCount()+1)
    {
        Jatta::PortAudio::Terminate();
        cout << "Invalid choice!" << endl;
        return 1; 
    }

    Jatta::PortAudio::Device outputDevice = Jatta::PortAudio::GetDefaultOutputDevice();
    if (choice != 0)
    { outputDevice = Jatta::PortAudio::GetDevice(choice-1); }

    system("clear");

    cout << "Select an input device: " << endl;
    cout << "\t0. " << Jatta::PortAudio::GetDefaultInputDevice().GetName() << " (default)" << endl;
    for (unsigned int i = 0; i < Jatta::PortAudio::GetDeviceCount(); i++)
    {
        cout << "\t" << i+1 << ". " << Jatta::PortAudio::GetDevice(i).GetName() << endl;
    }
    cout << endl << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice < 0 || choice >= Jatta::PortAudio::GetDeviceCount()+1)
    {
        Jatta::PortAudio::Terminate();
        cout << "Invalid choice!" << endl;
        return 1; 
    }

    Jatta::PortAudio::Device inputDevice = Jatta::PortAudio::GetDefaultInputDevice();
    if (choice != 0)
    { inputDevice = Jatta::PortAudio::GetDevice(choice-1); }

    Jatta::PortAudio::InputStream inputStream(inputDevice);

    while (true)
    {
        inputStream.Start();
        cout << "Start talking." << endl;
        PortAudio::Sleep(5000);
        cout << "Now echoing... " << endl;
        inputStream.Stop();
        inputStream.WriteToRaw("output.raw");

        StreamOut outputStream(outputDevice, inputStream.GetInput(0), inputStream.GetInput(1));
        outputStream.Start();
        PortAudio::Sleep(5000);
        outputStream.Stop();
        outputStream.Close();
        inputStream.ClearInput();
    }

    inputStream.Close();
    Jatta::PortAudio::Terminate();
    return 0;
}