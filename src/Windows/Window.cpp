#include "Window.h"
#include <cstdio>
#include <sstream>

#ifdef WINDOWS
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
#endif

#ifdef LINUX
bool Jatta::Window::initialized = false;

static int __jatta_windows_error_handler(Display* display, XErrorEvent* event)
{
    // TODO: something?
}
#endif

Jatta::Window::Window() : input(this)
{
#   ifdef LINUX
    if (!initialized)
    {
        XSetErrorHandler(__jatta_windows_error_handler);
        initialized = true;
    }
#   endif
}

Jatta::Window::~Window()
{
    close();
}

#ifdef WINDOWS
HWND Jatta::Window::_getHandle()
{
    return handle;
}
#endif

#ifdef LINUX
Display* Jatta::Window::_getDisplay()
{
    return display;
}

::Window Jatta::Window::_getHandle()
{
    return handle;
}
#endif

Jatta::Input* Jatta::Window::getInput()
{
    return &input;
}

void Jatta::Window::create(const WindowStyle& style)
{
#   ifdef WINDOWS
    // Generate a unique class name for this window
    std::wostringstream ss;
    static int windowCounter = 0;
    strcpy(className, "JATTA_");
    sprintf(className + 6, "%d", windowCounter++);
    ss << className;

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
    wc.lpszClassName = ss.str().c_str();
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    // Register the window class
    if (!RegisterClassEx(&wc))
    {
        // TODO: throw exception
    }

    this->style = WS_OVERLAPPEDWINDOW;
    if (!style.resizable)
    {
        this->style &= ~WS_MAXIMIZEBOX;
        this->style &= ~WS_THICKFRAME;
    }

    RECT windowRect = {0, 0, (long)style.width, (long)style.height};
    AdjustWindowRectEx(&windowRect, this->style, false, WS_EX_CLIENTEDGE);

    handle = CreateWindowEx(WS_EX_CLIENTEDGE, ss.str().c_str(), style.title._toWideString().c_str(), this->style, CW_USEDEFAULT, CW_USEDEFAULT, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, GetModuleHandle(nullptr), NULL);

    if (handle == NULL)
    {
        // TODO: throw exception
    }

    SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow(handle, SW_SHOW);
#   endif

#   ifdef LINUX
    std::cout << (int)style.backgroundColor.r << ", " << (int)style.backgroundColor.g << ", " << (int)style.backgroundColor.b << std::endl;
    this->display = XOpenDisplay(nullptr);
    int screen = DefaultScreen(this->display);
    Visual* visual = DefaultVisual(this->display, screen);
    int depth = DefaultDepth(this->display, screen);
    XSetWindowAttributes attributes;
    attributes.background_pixel = style.backgroundColor.b | (style.backgroundColor.g << 8) | (style.backgroundColor.r << 16);//XWhitePixel(display, screen);
    attributes.border_pixel = XBlackPixel(this->display, screen);
    attributes.override_redirect = 0;
    this->handle = XCreateWindow(this->display, XRootWindow(this->display, screen), 200, 200, style.width, style.height, 5, depth, InputOutput, visual, CWBackPixel | CWBorderPixel | CWOverrideRedirect, &attributes);
    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(this->display, this->handle, &wmDelete, 1);
    XSelectInput(this->display, this->handle, ExposureMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask);
    XMapWindow(this->display, this->handle);
    XFlush(this->display);
#   endif
}

void Jatta::Window::close()
{
#   ifdef WINDOWS
    if (IsWindow(handle))
    {
        DestroyWindow(handle);
    }
    handle = 0;
#   endif

#   ifdef LINUX
    if (isOpen())
    {
        XDestroyWindow(display, handle);
        XCloseDisplay(display);
    }
    handle = 0;
    display = nullptr;
#   endif
}

void Jatta::Window::update()
{
#   ifdef WINDOWS
    MSG Msg;
    while (PeekMessage(&Msg, handle, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
#   endif

#   ifdef LINUX
    if (display && handle)
    {
        while (XPending(display))
        {
            XEvent event;
            XNextEvent(display, &event);
            switch (event.type)
            {
                case 33:
                    XDestroyWindow(display, handle);
                case DestroyNotify:
                    close();
                    return;
                case KeyPress:
                    getInput()->getKeyData()[getInput()->getKeyFromLayout(event.xkey.keycode)] = true;
                    break;
                case KeyRelease:
                    bool released = true;
                    if (XEventsQueued(display, QueuedAfterReading))
                    {
                        XEvent nextEvent;
                        XPeekEvent(display, &nextEvent);
                        if (nextEvent.type == KeyPress && nextEvent.xkey.time == event.xkey.time && nextEvent.xkey.keycode == event.xkey.keycode)
                        {
                            released = false;
                        }
                    }
                    if (released)
                    {
                        getInput()->getKeyData()[getInput()->getKeyFromLayout(event.xkey.keycode)] = false;
                    }
                    break;
            }
        }
    }
#   endif
}

bool Jatta::Window::isOpen() const
{
#   ifdef WINDOWS
    return IsWindow(handle);
#   endif

#   ifdef LINUX
    return display && handle;
#   endif
}

unsigned int Jatta::Window::getWidth() const
{
#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.left + rect.right;
    GetWindowRect(handle, &rect);
    return rect.right - rect.left - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.width;
#   endif
}

unsigned int Jatta::Window::getHeight() const
{
#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return rect.bottom - rect.top - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.height;
#   endif
}

Jatta::Float2 Jatta::Window::getSize() const
{
    #   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return Float2(rect.right - rect.left - borders, rect.bottom - rect.top - borders);
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return Float2(attributes.height, attributes.width);
#   endif
}