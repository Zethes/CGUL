#include <Jatta.h>
using namespace Jatta;

#include <iostream>

int main()
{
    WindowStyle style;
    style.title = JSTR("Jatta Window");
    style.width = 640;
    style.height = 480;
    style.backgroundColor = Colors::red;
    style.resizable = false;

    Window window;
    window.Create(style);

    std::cout << window.GetStyle() << std::endl;

    float hue = 0;
    while (window.IsOpen())
    {
        Window::Update();

        hue += 0.001f;
        window.SetBackgroundColor(Color::MakeHSL(hue, 255, 255));
        if (hue >= 360)
        {
            hue -= 360;
        }
    }
}