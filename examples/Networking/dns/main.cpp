#include <CGUL.hpp>
using namespace CGUL;

#include <iostream>

int main(int argc, char** argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Usage: " << argv[0] << " <hostname>" << std::endl;
            return 1;
        }

        Vector< Network::IPAddress > addresses;
        Network::DNS::Lookup(String(argv[1]), Network::DNS::UNSPECIFIED, &addresses);

        for (Vector< Network::IPAddress >::iterator itr = addresses.begin(); itr != addresses.end(); itr++)
        {
            std::cout << *itr << std::endl;
        }

        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
