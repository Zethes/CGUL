#include "Window.h"
#include <cstdio>

#include <iostream> // TODO: remove iostream

LRESULT CALLBACK Jatta::Window::windowProcedure(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    LONG_PTR ptr = GetWindowLongPtr(handle, GWLP_USERDATA);
    Window* window = (Window*)ptr;
    if (ptr != 0)
    {
        //window->getOnMessage()();
    }
    switch (message)
    {
        case WM_CLOSE:
        if (window != 0)
        {
            window->close();
        }
        return 0;
        case WM_KEYDOWN:
        window->getInput()->getKeyData()[wParam] = true;
        return 0;
        case WM_KEYUP:
        window->getInput()->getKeyData()[wParam] = false;
        return 0;
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(handle, message, wParam, lParam);
}

Jatta::Window::Window() : input(new Input(this))
{
}

Jatta::Window::~Window()
{
    close();
}

HWND Jatta::Window::getHandle()
{
    return handle;
}

std::shared_ptr<Jatta::Input> Jatta::Window::getInput()
{
    return input;
}

void Jatta::Window::create(const WindowStyle& style)
{
    // Generate a unique class name for this window
    static int windowCounter = 0;
    strcpy(className, "JATTA_");
    sprintf(className + 6, "%d", windowCounter++);

    // Create the window class
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = windowProcedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(style.backgroundColor.r, style.backgroundColor.g, style.backgroundColor.b));
    wc.lpszMenuName = NULL;
    wc.lpszClassName = className;
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    // Register the window class
    if (!RegisterClassEx(&wc))
    {
        // TODO: throw exception
    }

    this->style = WS_OVERLAPPEDWINDOW;

    RECT windowRect = {0, 0, (long)style.width, (long)style.height};
    AdjustWindowRectEx(&windowRect, this->style, false, WS_EX_CLIENTEDGE);

    handle = CreateWindowEx(WS_EX_CLIENTEDGE, className, style.title.c_str(), this->style, CW_USEDEFAULT, CW_USEDEFAULT, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, GetModuleHandle(nullptr), NULL);

    if (handle == NULL)
    {
        // TODO: throw exception
    }

    SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow(handle, SW_SHOW);
}

void Jatta::Window::close()
{
    if (IsWindow(handle))
    {
        DestroyWindow(handle);
    }
    handle = 0;
}

void Jatta::Window::update()
{
    MSG Msg;
    while (PeekMessage(&Msg, handle, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}

bool Jatta::Window::isOpen()
{
    return IsWindow(handle);
}

unsigned int Jatta::Window::getWidth()
{
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRect(&rect, style, false);
    int borders = -rect.left + rect.right;
    GetWindowRect(handle, &rect);
    return rect.right - rect.left - borders;
}

unsigned int Jatta::Window::getHeight()
{
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRect(&rect, style, false);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return rect.bottom - rect.top - borders;
}