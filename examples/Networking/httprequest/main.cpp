#include <iostream>
#include <vector>
#include <Jatta.h>
using namespace std;
using namespace Jatta;

int main()
{
	try
    {
        Network::HTTPRequest http;

        cout << "-- Connecting..." << endl;
        http.Http("api.tumblr.com");

        if (!http.IsConnected())
        {
            cout << "-- Failed to connect..." << endl;
            return 1;
        }

        cout << "-- Connected!" << endl;

        cout << "-- Performing basic GET..." << endl;
        http.Get("/v2/blog/good.tumblr.com/info?api_key=fuiKNFp9vQFvjLNvx4sUwti4Yb5yGutBN4Xh10LXZhhRKjWlV4", 5000);
        cout << "Request: " << endl << "---------------\n" << http.GetRequest() << "---------------" << endl << endl;
        cout << "Response Head: " << endl << "---------------\n" << http.GetResponseHead() << "---------------" << endl << endl;
        cout << "Response Body: " << endl << "---------------\n" << http.GetResponseBody() << "\n---------------" << endl << endl;

        if (!http.IsConnected())
        {
            std::cout << "-- The connection was closed, reconnecting for next request..." << std::endl;
            http.Http("api.tumblr.com");
        }

        cout << "-- Performing basic POST..." << endl;
        if (!http.Post("/v2/user/follow?url=good.tumblr.com", "", 5000))
            cout << "Failed to perform POST." << endl;
        cout << "Request: " << endl << "---------------\n" << http.GetRequest() << "---------------" << endl << endl;
        cout << "Response Head: " << endl << "---------------\n" << http.GetResponseHead() << "---------------" << endl << endl;
        cout << "Response Body: " << endl << "---------------\n" << http.GetResponseBody() << "\n---------------" << endl << endl;

        http.Close();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
	
	return 0;
}
