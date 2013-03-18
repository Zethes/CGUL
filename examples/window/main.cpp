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

        hue += 0.01f;
        if (window.IsFocused())
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 255, 255));
        }
        else
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 150, 150));
        }
        if (hue >= 360)
        {
            hue -= 360;
        }

        Jatta::Timer::Sleep(1);
    }
}