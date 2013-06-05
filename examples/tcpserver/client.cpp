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
        cout << "-- Connecting..." << endl;
        socket.Connect("127.0.0.1", 6363);
        cout << "-- Connected!" << endl;
        cout << "-- Type something!" << endl;

        while (true)
        {
            string message;
            cout << "> ";
            getline(cin, message);
            socket.Send(message.c_str(), message.length() + 1);
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
