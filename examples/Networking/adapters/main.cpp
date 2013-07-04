#include <Jatta.h>
using namespace Jatta;

#include <iostream>

int main()
{
    // Get all network adapters
    std::vector<Network::Adapter> adapters = Network::GetAdapters();

    // Iterate through each network adapter
    for (std::vector<Network::Adapter>::iterator adapter = adapters.begin(); adapter != adapters.end(); adapter++)
    {
        // Print out the description of the network interface
        std::cout << adapter->description << std::endl;

        // Print out if IPv4 or IPv6
        std::cout << "  Version  : " << (adapter->ip.GetType() == Network::IPAddressType::IPV4 ? "IPv4" : "IPv6") << std::endl;

        // Print the local address
        std::cout << "  Address  : " << adapter->ip << std::endl;

        // Print the netmask
        std::cout << "  Netmask  : " << adapter->netmask << std::endl;

        // Print out the broadcast address (ipv4 only)
        if (adapter->ip.GetType() == Network::IPAddressType::IPV4)
        {
            std::cout << "  Broadcast: " << Network::IPAddress::CalculateBroadcast(adapter->ip, adapter->netmask) << std::endl;
        }

        // Print out the network
        std::cout << "  Network  : " << Network::IPAddress::CalculateNetwork(adapter->ip, adapter->netmask) << std::endl;
    }
}
