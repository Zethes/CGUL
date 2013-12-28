#include <CGUL.hpp>
using namespace CGUL;

#include <iostream>

void KeyButtonEvent(const WindowKeyButtonEvent& event, void* userData)
{
    char* input = (char*)userData;
    if (event.pressed && event.key < 255)
    {
        *input = (char)event.key;
    }
}

void PrintWindowInformation(Window* window)
{
    std::cout << "== Style ==" << std::endl;
    std::cout << window->GetStyle() << std::endl;
    std::cout << std::endl;

    URect32 frameExtents = window->GetFrameSize();
    std::cout << "== Frame Extents ==" << std::endl;
    std::cout << "Left Border:      " << frameExtents.x << std::endl;
    std::cout << "Top Border:       " << frameExtents.y << std::endl;
    std::cout << "Right Border:     " << frameExtents.z << std::endl;
    std::cout << "Bottom Border:    " << frameExtents.w << std::endl;

    std::cout << std::endl;
}

int main()
{
    WindowStyle style;
    style.title = U8("CGUL Window");
    style.size = UCoord32(640, 480);
    style.backgroundColor = Colors::red;
    style.resizable = false;

    Window window;
    window.Create(style);

    char input;
    window.onKeyButton.AddEvent(KeyButtonEvent, &input);

    std::cout << "Controls:" << std::endl;
    std::cout << "P - Print window information" << std::endl;
    std::cout << "R - Toggle window resizability" << std::endl;
    std::cout << "T - Give window a random title" << std::endl;
    std::cout << "U - Set the title to a unicode string" << std::endl;
    std::cout << std::endl;

    float hue = 0;
    Timer timer;
    while (window.IsOpen())
    {
        Window::Update();

        hue += timer.GetDeltaTime() * 45;
        if (window.IsFocused())
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 1, 0.5f));
        }
        else
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 0.5f, 0.3f));
        }
        if (hue >= 360)
        {
            hue -= 360;
        }

        if (input != 0)
        {
            switch (input)
            {
                case 'P':
                {
                    PrintWindowInformation(&window);
                    break;
                }
                case 'R':
                {
                    window.SetResizable(!window.GetResizable());
                    break;
                }
                case 'T':
                {
                    Random random;
                    window.SetTitle(random.GetString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", 64));
                    break;
                }
                case 'U':
                {
                    String unicode;
                    unicode += String::FromCodePoint(0x3053); // ko
                    unicode += String::FromCodePoint(0x3093); // n
                    unicode += String::FromCodePoint(0x306b); // ni
                    unicode += String::FromCodePoint(0x3061); // chi
                    unicode += String::FromCodePoint(0x306f); // ha
                    window.SetTitle(unicode);
                    break;
                }
            }
            input = 0;
        }

        CGUL::Timer::Sleep(1);
    }
}
