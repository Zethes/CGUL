#include <iostream>
#include <vector>
#include <Jatta.h>
using namespace std;
using namespace Jatta;

int main()
{
    try
    {
        Network::SocketTCP socket;
        cout << "-- Binding..." << endl;
        socket.Listen(6363);
        cout << "-- Listening!" << endl;

        vector<Network::SocketTCP> clients;
        while (true)
        {
            Timer::Sleep(1);

            Network::SocketTCP dummy;
            if (socket.Accept(&dummy))
            {
                cout << "-- Client connected: " << dummy.GetIP() << endl;
                clients.push_back(dummy);
            }

            for (vector<Network::SocketTCP>::iterator client = clients.begin(); client != clients.end();)
            {
                char buffer[1024];
                if (!client->IsConnected())
                {
                    cout << "-- Client disconnected: " << dummy.GetIP() << endl;
                    clients.erase(client);
                    break;
                }
                else if (client->Receive(buffer, 1024))
                {
                    cout << "> " << buffer << endl;
                }
                client++;
            }
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
