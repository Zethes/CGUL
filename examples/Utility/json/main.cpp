#include <Jatta.h>
using namespace Jatta;
#include <iostream>

int main(int argc, char* argv[])
{
    JSON::Object object;
    object["firstName"] = U8("John");
    object["lastName"] = U8("Smith");
    object["age"] = (SInt32)25;

    JSON::Object address;
    address["streetAddress"] = U8("21 2nd Street");
    address["city"] = U8("New York");
    address["state"] = U8("NY");
    address["postalCode"] = (SInt32)10021;

    JSON::Array numbers;
    JSON::Object number1;
    JSON::Object number2;

    number1["type"] = U8("home");
    number1["number"] = U8("212 555-1234");
    number2["type"] = U8("fax");
    number2["number"] = U8("646 555-4567");

    numbers.PushBack(number1);
    numbers.PushBack(number2);
    object["address"] = address;
    object["phoneNumbers"] = numbers;

    std::cout << object.ToString() << std::endl;

    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << Jatta::JSON::Parse(object.ToString()).ToString() << std::endl;

    return 0;
}
