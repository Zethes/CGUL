#include <iostream>
#include <vector>
#include <CGUL.hpp>
using namespace std;
using namespace CGUL;

int main()
{
    try
    {
        // Create a socket
        Network::SocketUDP socket;

        // Connect to the server
        cout << "-- Connecting..." << endl;
        socket.Connect(Network::IPAddress("127.0.0.1"), 6363);

        // All went well if we got this far
        cout << "-- Connected!" << endl;
        cout << "-- Type something (or \"quit\" to quit)!" << endl;

        // Loop to send multiple messages
        while (true)
        {
            // Get a message from the console
            string message;
            cout << "> ";
            getline(cin, message);

            // Check for our end case
            if (message == "quit")
            {
                break;
            }

            // Send the message to the socket (the server)
            socket.Send(message.c_str(), message.length() + 1);
        }

        // Gracefully close the connection
        socket.Close();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
