#include <Jatta.h>
using namespace Jatta;

int main()
{
    WindowStyle style;
    style.title = "Jatta Window";
    style.width = 320;
    style.height = 240;
    style.backgroundColor = Colors::red;
    style.resizable = true;

    Window window;
    window.Create(style);

    while (window.IsOpen())
    {
        Window::Update();
    }
}