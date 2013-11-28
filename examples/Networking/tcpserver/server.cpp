#include <iostream>
#include <vector>
#include <CGUL.hpp>
using namespace std;
using namespace CGUL;

int main()
{
    // Catch exceptions
    try
    {
        // Create a socket
        Network::SocketTCP socket;

        // Listen for incoming connections
        cout << "-- Binding..." << endl;
        socket.Listen(6363);
        cout << "-- Listening!" << endl;

        // Containers for clients and client data
        vector<Network::SocketTCP> clients;
        char buffer[1024];

        // Loop to accept new clients and receive from existing ones
        while (true)
        {
            // Sleep for a bit to not thrash CPU
            Timer::Sleep(1);

            // Accept new clients
            Network::SocketTCP dummy;
            if (socket.Accept(&dummy))
            {
                cout << "-- Client connected: " << dummy.GetIP() << endl;
                clients.push_back(dummy);
            }

            // For each client...
            for (vector<Network::SocketTCP>::iterator client = clients.begin(); client != clients.end();)
            {
                // Check if the client is still connected, if not remove it
                if (!client->IsConnected())
                {
                    cout << "-- Client disconnected!" << endl;
                    clients.erase(client);
                    break;
                }
                // Receive messages from the client
                else if (client->Receive(buffer, 1024))
                {
                    cout << client->GetIP() << "> " << buffer << endl;
                }

                // Next client
                client++;
            }
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
