#include <string>
#include "../Images/Color.h"

using std::string;

namespace Jatta
{
    struct WindowStyle
    {
        string title;
        Color backgroundColor;
        unsigned int width;
        unsigned int height;
    };
}