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
        Network::SocketUDP socket;

        // Listen for incoming connections
        cout << "-- Binding..." << endl;
        socket.Bind(6363);
        cout << "-- Binded!" << endl;

        // Buffer for incoming messages
        char buffer[1024];

        // Loop to accept new clients and receive from existing ones
        while (true)
        {
            // Sleep for a bit to not thrash CPU
            Timer::Sleep(1);

            // Receive messages from clients
            Network::IPAddress ip;
            unsigned short port;
            if (socket.ReceiveFrom(&ip, &port, buffer, 1024))
            {
                cout << ip << "> " << buffer << endl;
            }
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
