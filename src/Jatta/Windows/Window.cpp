/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Window.h"
#include <cstdio>
#include <sstream>

#include <limits.h>

#ifdef MACOS
#   import "MacOS/Application.h"
#endif

#ifdef Jatta_USE_OPENGL
#   include "../OpenGL/Context.h"
#endif

#ifdef MSVC
    // Disable Warning C4355: 'this' : used in base member initializer list
    // How we're using 'this' will not cause any undefined behavior
    #pragma warning( disable : 4355 )
#endif

#ifdef WINDOWS
LRESULT CALLBACK Jatta::Window::WindowProcedure(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
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
            window->Close();
        }
        return 0;
        case WM_MOUSEMOVE:
        window->GetInput()->mousePos.x = LOWORD(lParam);
        window->GetInput()->mousePos.y = HIWORD(lParam);
        return 0;
        case WM_KEYDOWN:
        window->GetInput()->GetKeyData()[wParam].down = true;
        return 0;
        case WM_KEYUP:
        window->GetInput()->GetKeyData()[wParam].down = false;
        return 0;
        case WM_LBUTTONDOWN:
        window->GetInput()->GetMouseData()[0].down = true;
        return 0;
        case WM_LBUTTONUP:
        window->GetInput()->GetMouseData()[0].down = false;
        return 0;
        case WM_RBUTTONDOWN:
        window->GetInput()->GetMouseData()[2].down = true;
        return 0;
        case WM_RBUTTONUP:
        window->GetInput()->GetMouseData()[2].down = false;
        return 0;
        case WM_MBUTTONDOWN:
        window->GetInput()->GetMouseData()[1].down = true;
        return 0;
        case WM_MBUTTONUP:
        window->GetInput()->GetMouseData()[1].down = false;
        return 0;
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(handle, message, wParam, lParam);
}
#endif

#ifdef LINUX
std::map<Window, Jatta::Window*> Jatta::Window::windowMap;
Display* Jatta::Window::display;
bool Jatta::Window::initialized = false;

static int __jatta_windows_error_handler(Display* display, XErrorEvent* event)
{
    // TODO: something?
    return 0;
}
#endif

_JATTA_EXPORT Jatta::Window::Window(const Window& copy) : input(this)
{
    /* deleted */
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
_JATTA_EXPORT Jatta::Window::Window(Window&& move) : input(this)
{
    /* deleted */
}
#endif

/** @brief Updates all windows in the current application.
 *  @details The operating system usually handles windows under the same application in bulk.  For
 *  this reason, it is only necessary to call update once for every window.  It is still important
 *  to update a window's input manually, however.
 *  @see UpdateInput
 */
_JATTA_EXPORT void Jatta::Window::Update()
{
#   ifdef WINDOWS
    MSG Msg;
    while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
#   endif

#   ifdef LINUX
    if (display)
    {
        while (XPending(display))
        {
            XEvent event;
            XNextEvent(display, &event);
            ::Window handle = event.xany.window;
            std::map< ::Window, Window* >::iterator it = windowMap.find(handle);
            if (it == windowMap.end())
            {
                break;
            }
            Window* window = it->second;
            switch (event.type)
            {
                case 33:
                    XDestroyWindow(display, handle);
                case DestroyNotify:
                    window->Close();
                    return;
                case KeyPress:
                    window->GetInput()->GetKeyData()[window->GetInput()->GetKeyFromLayout(event.xkey.keycode)].down = true;
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
                        window->GetInput()->GetKeyData()[window->GetInput()->GetKeyFromLayout(event.xkey.keycode)].down = false;
                    }
                    break;
            }
        }
    }
#   endif

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    //[[Application sharedApplication] updateWindows];
    [[Application sharedApplication] update];

    // Free anything we've autoreleased on the Obj-C side
    [pool drain];
#   endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////

_JATTA_EXPORT Jatta::Window::Window() : input(this)
{
#   ifdef Jatta_USE_OPENGL
    context = NULL;
#   endif

#   ifdef LINUX
    if (!initialized)
    {
        XSetErrorHandler(__jatta_windows_error_handler);
        display = XOpenDisplay(NULL);
        initialized = true;
    }
#   endif

#   ifdef MACOS
    handle = [WindowDelegate alloc];
#   endif
}

_JATTA_EXPORT Jatta::Window::~Window()
{
    Close();
#   ifdef MACOS
    //[handle release];
#   endif
}

#ifdef WINDOWS
_JATTA_EXPORT HWND Jatta::Window::_GetHandle() const
{
    return handle;
}
#endif

#ifdef LINUX
_JATTA_EXPORT Display* Jatta::Window::_GetDisplay() const
{
    return display;
}

_JATTA_EXPORT ::Window Jatta::Window::_GetHandle() const
{
    return handle;
}
#endif

#if defined(JATTA_BUILD) && defined(MACOS)
WindowDelegate* Jatta::Window::_GetHandle() const
{
    return handle;
}
#endif

_JATTA_EXPORT Jatta::Input* Jatta::Window::GetInput()
{
    return &input;
}

/** @brief Creates a window based on the given style.
 *  @details See the tutorial on @ref create_window.
 */
_JATTA_EXPORT void Jatta::Window::Create(const WindowStyle& style)
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
    wc.lpfnWndProc = WindowProcedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    //wc.hbrBackground = CreateSolidBrush(RGB(style.backgroundColor.r, style.backgroundColor.g, style.backgroundColor.b)); // TODO: createsolidbrush leaks, needs to be deleted with DeleteObject
    wc.lpszMenuName = NULL;
    wc.lpszClassName = new wchar_t[ss.str().length() + 1];
    memcpy((void*)wc.lpszClassName, ss.str().c_str(), sizeof(wchar_t) * (ss.str().length() + 1));
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    backgroundBrush = CreateSolidBrush(RGB(style.backgroundColor.r, style.backgroundColor.g, style.backgroundColor.b)); // TODO: createsolidbrush leaks, needs to be deleted with DeleteObject
    wc.hbrBackground = (HBRUSH)backgroundBrush;

    // Register the window class
    if (!RegisterClassEx(&wc))
    {
        throw std::runtime_error("Failed to register the window class.");
    }

    // Setup the window style
    DWORD windowStyle = WS_TILEDWINDOW;//WS_OVERLAPPEDWINDOW;

    // Adjust the window rectangle to account for border sizes
    RECT windowRect = {0, 0, (long)style.width, (long)style.height};
    AdjustWindowRectEx(&windowRect, windowStyle, false, WS_EX_CLIENTEDGE);

    // Create the window
    handle = CreateWindowEx(WS_EX_CLIENTEDGE, wc.lpszClassName, style.title._ToWideString().c_str(), windowStyle, GetSystemMetrics(SM_CXSCREEN)/2-style.width/2,  GetSystemMetrics(SM_CYSCREEN)/2-style.height/2, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, GetModuleHandle(NULL), NULL);

    // Check for errors
    if (handle == NULL)
    {
        throw std::runtime_error("Failed to create the window!");
    }

    // Set the window's user-data to a pointer to this object
    SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)this);

    // Present the window onto the screen
    ShowWindow(handle, SW_SHOW);
#   endif

#   ifdef LINUX
    int screen = DefaultScreen(display);
    Visual* visual = DefaultVisual(display, screen);
    int depth = DefaultDepth(display, screen);
    XSetWindowAttributes attributes;
    attributes.background_pixel = style.backgroundColor.b | (style.backgroundColor.g << 8) | (style.backgroundColor.r << 16);//XWhitePixel(display, screen);
    attributes.border_pixel = XBlackPixel(display, screen);
    attributes.override_redirect = 0;
    this->handle = XCreateWindow(display, XRootWindow(display, screen), 200, 200, style.width, style.height, 5, depth, InputOutput, visual, CWBackPixel | CWBorderPixel | CWOverrideRedirect, &attributes);
    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(display, this->handle, &wmDelete, 1);
    XSelectInput(display, this->handle, ExposureMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask);
    XMapWindow(display, this->handle);
    XFlush(display);
    windowMap.insert(std::make_pair(this->handle, this));

#   endif

#   ifdef MACOS
    // Create an autorelease pool
    // There won't be many things in it from start to finish (since most everything is C++ side),
    // but it's still here for those few things that should be autoreleased!
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    // Create the Cocoa application
    [[Application sharedApplication] run];

    handle = [handle init: style];

    // Create our delegate as defined earlier in this file!
    //AppDelegate* appDelegate = [[[AppDelegate alloc] init] autorelease];

    // Set the application delegate and run the application
    //[application setDelegate: appDelegate];

    //[application run];

    /*while (true)
    {
        [[Application sharedApplication] update];
    }*/

    // Free anything we've autoreleased on the Obj-C side
    [pool drain];
#   endif

    SetStyle(style);
}

/** @brief Destroys the window.
 */
_JATTA_EXPORT void Jatta::Window::Close()
{
    if (context)
    {
        context->Destroy();
    }

#   ifdef WINDOWS
    if (IsWindow(handle))
    {
        DestroyWindow(handle);
    }
    handle = 0;
#   endif

#   ifdef LINUX
    if (IsOpen())
    {
        XDestroyWindow(display, handle);
        XCloseDisplay(display);
    }
    handle = 0;
    display = NULL;
#   endif

#   ifdef MACOS
    if (IsOpen())
    {
        [handle close];
    }
#   endif
    // TODO: Window::Close on MacOS(?)
}

/** @brief Updates a window's input handler.
 *  @details This method acts a little bit differently on each operating system.  It is important to
 *  call this every tick for every window.
 */
_JATTA_EXPORT void Jatta::Window::UpdateInput()
{
    if (!IsOpen())
    {
        return;
    }

#   ifdef LINUX
    ::Window root, child;
    int rootX, rootY, winX, winY;
    unsigned int mask;

    XQueryPointer(display, handle, &root, &child, &rootX, &rootY, &winX, &winY, &mask);
    GetInput()->mousePos.x = winX;
    GetInput()->mousePos.y = winY;
#   endif

    this->GetInput()->AnalyzeKeyData();
    this->GetInput()->AnalyzeMouseData();
}

/** @brief Updates a window's style.
 *  @param style The style structure.
 *  @details This method will reset all elements within the WindowStyle, not only those which have
 *  changed.  It can be used to "backup" a window at a given state and then reset to it later.
 *  Alternatively, it is possible to grab the current style with GetStyle and then modify individual
 *  elements, and pass it back into SetStyle.
 */
_JATTA_EXPORT void Jatta::Window::SetStyle(const WindowStyle& style)
{
    if (!IsOpen())
    {
        return;
    }

    SetTitle(style.title);
    SetBackgroundColor(style.backgroundColor);
    SetWidth(style.width);
    SetHeight(style.height);
    SetResizable(style.resizable);
}

/** @brief Gets some information about the window.
 *  @returns A WindowStyle structure.
 */
_JATTA_EXPORT Jatta::WindowStyle Jatta::Window::GetStyle() const
{
    WindowStyle style;
    style.title = GetTitle();
    style.backgroundColor = GetBackgroundColor();
    style.width = GetWidth();
    style.height = GetHeight();
    style.resizable = GetResizable();
    return style;
}

_JATTA_EXPORT void Jatta::Window::SetTitle(const String& title)
{
    if (!IsOpen())
    {
        return;
    }

#   ifdef WINDOWS
    SetWindowText(handle, title._ToWideString().c_str());
#   endif

#   ifdef LINUX
    XChangeProperty(display, handle, XInternAtom(display, "_NET_WM_NAME", false), XInternAtom(display, "UTF8_STRING", false), 8, PropModeReplace, (unsigned char*)title.GetData().c_str(), title.GetSize());
#   endif

#   ifdef MACOS
    [handle setTitle: title];
#   endif
}

_JATTA_EXPORT Jatta::String Jatta::Window::GetTitle() const
{
    if (!IsOpen())
    {
        return "";
    }

#   ifdef WINDOWS
    int size = GetWindowTextLength(this->handle) + 1;
    wchar_t* buffer = new wchar_t[size];
    GetWindowText(this->handle, buffer, size);
    Jatta::String title;
    title._FromWideString(buffer);
    delete[] buffer;
    return title;
#   endif

#   ifdef LINUX
    Atom nameAtom = XInternAtom(display, "_NET_WM_NAME", false);
    Atom utf8Atom = XInternAtom(display, "UTF8_STRING", false);
    Atom type;
    int format;
    unsigned long nitems, after;
    unsigned char* data = 0;

    if (Success == XGetWindowProperty(display, this->handle, nameAtom, 0, 65536, false, utf8Atom, &type, &format, &nitems, &after, &data))
    {
        if (data)
        {
            Jatta::String title((char*)data);
            XFree(data);
            return title;
        }
    }
    return "";
#   endif

#   ifdef MACOS
    return [handle getTitle];
#   endif

    return "";
}

_JATTA_EXPORT void Jatta::Window::SetBackgroundColor(const Color& color)
{
    if (!IsOpen())
    {
        return;
    }

    // TODO: Jatta::Window::SetBackgroundColor

#   ifdef WINDOWS
    if (backgroundBrush)
    {
        DeleteObject(backgroundBrush);
        backgroundBrush = NULL;
    }
    backgroundBrush = CreateSolidBrush(RGB(color.r, color.g, color.b));
    SetClassLongPtr(handle, GCLP_HBRBACKGROUND, (LONG)backgroundBrush);

    // Redraw the window
    InvalidateRect(handle, NULL, true);
    UpdateWindow(handle);
#   endif

#   ifdef LINUX
    XSetWindowBackground(display, this->handle, color.b | (color.g << 8) | (color.r << 16));
    XClearWindow(display, this->handle);
    XFlush(display);
    backgroundColor = color;
#   endif

#   ifdef MACOS
    [handle setBackgroundColor: color];
#   endif
}

_JATTA_EXPORT Jatta::Color Jatta::Window::GetBackgroundColor() const
{
    if (!IsOpen())
    {
        return Jatta::Color(0, 0, 0, 0);
    }

#   ifdef WINDOWS
    HGDIOBJ brush = (HGDIOBJ)GetClassLongPtr(handle, GCLP_HBRBACKGROUND);
    LOGBRUSH lb;
    GetObject(brush, sizeof(LOGBRUSH), &lb);
    return Color((lb.lbColor & 255), ((lb.lbColor >> 8) & 255), ((lb.lbColor >> 16) & 255), 255);
#   endif

#   ifdef LINUX
    return backgroundColor;
#   endif

#   ifdef MACOS
    return [handle getBackgroundColor];
#   endif
    return Color(0, 0, 0);
}

_JATTA_EXPORT void Jatta::Window::SetWidth(UInt32 width)
{
#   ifdef WINDOWS
    RECT rect = {0, 0, width, GetHeight()};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    SetWindowPos(handle, 0, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE);
#   endif

#   ifdef LINUX
    if (GetResizable())
    {
        XResizeWindow(display, this->handle, width, GetHeight());
    }
    else
    {
        XSizeHints hints;
        hints.flags = PMinSize | PMaxSize;
        hints.min_width = width; hints.min_height = GetHeight();
        hints.max_width = width; hints.max_height = GetHeight();
        XSetWMNormalHints(display, this->handle, &hints);
    }
#   endif

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [handle setWidth: width];
    [pool drain];
#   endif
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Window::GetWidth() const
{
    if (!IsOpen())
    {
        return 0;
    }

#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    int borders = -rect.left + rect.right;
    GetWindowRect(handle, &rect);
    return rect.right - rect.left - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.width;
#   endif

#   ifdef MACOS
    return [handle getWidth];
#   endif
}

_JATTA_EXPORT void Jatta::Window::SetHeight(UInt32 height)
{
#   ifdef WINDOWS
    RECT rect = {0, 0, GetWidth(), height};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    SetWindowPos(handle, 0, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE);
#   endif

#   ifdef LINUX
    if (GetResizable())
    {
        XResizeWindow(display, this->handle, GetWidth(), height);
    }
    else
    {
        XSizeHints hints;
        hints.flags = PMinSize | PMaxSize;
        hints.min_width = GetWidth(); hints.min_height = height;
        hints.max_width = GetWidth(); hints.max_height = height;
        XSetWMNormalHints(display, this->handle, &hints);
    }
#   endif

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [handle setHeight: height];
    [pool drain];
#   endif
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Window::GetHeight() const
{
    if (!IsOpen())
    {
        return 0;
    }

#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return rect.bottom - rect.top - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.height;
#   endif

#   ifdef MACOS
    return [handle getHeight];
#   endif
}

_JATTA_EXPORT void Jatta::Window::SetSize(const Vector2& size) const
{
#   ifdef WINDOWS
    RECT rect = {0, 0, size.x, size.y};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    SetWindowPos(handle, 0, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE);
#   endif

#   ifdef LINUX
    if (GetResizable())
    {
        XResizeWindow(display, this->handle, size.x, size.y);
    }
    else
    {
        XSizeHints hints;
        hints.flags = PMinSize | PMaxSize;
        hints.min_width = size.x; hints.min_height = size.y;
        hints.max_width = size.x; hints.max_height = size.y;
        XSetWMNormalHints(display, this->handle, &hints);
    }
#   endif

#   ifdef MACOS
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [handle setSize: size];
    [pool drain];
#   endif
}

_JATTA_EXPORT Jatta::Vector2 Jatta::Window::GetSize() const
{
    if (!IsOpen())
    {
        return Jatta::Vector2(0, 0);
    }

#   ifdef WINDOWS
    return Vector2(GetWidth(), GetHeight());
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return Vector2(attributes.height, attributes.width);
#   endif

#   ifdef MACOS
    return Vector2([[[handle Window] contentView] frame].size.width, [[[handle Window] contentView] frame].size.height);
#   endif
}

_JATTA_EXPORT void Jatta::Window::SetResizable(Boolean resizable)
{
    if (!IsOpen())
    {
        return;
    }

#   ifdef WINDOWS
    // Capture the current size of the window
    RECT windowRect = {0, 0, GetWidth(), GetHeight()};

    // Turn on or off the bits for a resizable window
    LONG_PTR style = GetWindowLongPtr(this->handle, GWL_STYLE);
    if (resizable)
    {
        style |= WS_THICKFRAME;
        style |= WS_MAXIMIZEBOX;
    }
    else
    {
        style &= ~WS_THICKFRAME;
        style &= ~WS_MAXIMIZEBOX;
    }

    // Change the window style
    SetWindowLongPtr(this->handle, GWL_STYLE, style);

    // Update the window size
    AdjustWindowRectEx(&windowRect, style, false, WS_EX_CLIENTEDGE);
    SetWindowPos(handle, 0, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);
#   endif

#   ifdef LINUX
    XSizeHints hints;
    hints.flags = PMinSize | PMaxSize;
    if (resizable)
    {
        hints.min_width = 1;       hints.min_height = 1;
        hints.max_width = INT_MAX; hints.max_height = INT_MAX;
    }
    else
    {
        hints.min_width = GetWidth(); hints.min_height = GetHeight();
        hints.max_width = GetWidth(); hints.max_height = GetHeight();
    }
    XSetWMNormalHints(display, handle, &hints);
#   endif

#   ifdef MACOS
    [handle setResizable: resizable];
#   endif
}

_JATTA_EXPORT Jatta::Boolean Jatta::Window::GetResizable() const
{
    if (!IsOpen())
    {
        return false;
    }

#   ifdef WINDOWS
    return ((GetWindowLongPtr(this->handle, GWL_STYLE) & WS_THICKFRAME) || (GetWindowLongPtr(this->handle, GWL_STYLE) & WS_MAXIMIZEBOX));
#   endif

#   ifdef LINUX
    XSizeHints hints;
    long hintsSupplied;
    XGetWMNormalHints(display, this->handle, &hints, &hintsSupplied);
    if (((hintsSupplied & PMinSize) == 0) || ((hintsSupplied & PMaxSize) == 0))
    {
        return false;
    }
    return (hints.min_width != hints.max_width || hints.min_height != hints.max_height);
#   endif

#   ifdef MACOS
    return [handle getResizable];
#   endif
    return false;
}

_JATTA_EXPORT Jatta::Vector4 Jatta::Window::GetFrameSize() const
{
    if (!IsOpen())
    {
        return Jatta::Vector4(0, 0, 0, 0);
    }

#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, GetWindowLongPtr(this->handle, GWL_STYLE), false, WS_EX_CLIENTEDGE);
    return Vector4((float)-rect.left, (float)-rect.top, (float)rect.right, (float)rect.bottom);
#   endif

#   ifdef LINUX
    Atom netFrameExtents = XInternAtom(display, "_NET_FRAME_EXTENTS", False);
    Atom actualType;
    int actualFormat;
    unsigned long items, bytesAfter;
    long* data = NULL;
    if (Success == XGetWindowProperty(display, handle, netFrameExtents, 0L, 4, False, AnyPropertyType, &actualType, &actualFormat, &items, &bytesAfter, (unsigned char**)&data) && data)
    {
        Vector4 result(data[0], data[2], data[1], data[3]);
        XFree(data);
        return result;
    }
    return Vector4(0, 0, 0, 0);
#   endif

#   ifdef MACOS
    return [handle getFrameSize];
#   endif
}

_JATTA_EXPORT bool Jatta::Window::IsOpen() const
{
#   ifdef WINDOWS
    return IsWindow(handle) == TRUE;
#   endif

#   ifdef LINUX
    return display && handle;
#   endif

#   ifdef MACOS
    if (handle == nil)
    {
        return false;
    }
    if (![[Application sharedApplication] keepRunning])
    {
        return false;
    }
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    bool result = [handle IsOpen] == 1;
    [pool drain];
    return result;
#   endif
}

_JATTA_EXPORT Jatta::Boolean Jatta::Window::IsFocused() const
{
    if (!IsOpen())
    {
        return false;
    }

#   ifdef WINDOWS
    return (handle == GetForegroundWindow());
#   endif

#   ifdef LINUX
    Atom netActiveWindow = XInternAtom(display, "_NET_ACTIVE_WINDOW", False);

    ::Window activeWindow = None;
    Atom actualType;
    int actualFormat;
    unsigned long items, bytesAfter;
    unsigned char *propReturn = NULL;

    if (Success == XGetWindowProperty(display, XRootWindow(display, 0), netActiveWindow, 0L, sizeof(Window), False, XA_WINDOW, &actualType, &actualFormat, &items, &bytesAfter, &propReturn) && propReturn)
    {
        activeWindow = *(::Window*)propReturn;
        XFree(propReturn);
    }

    return activeWindow == handle;
#   endif

#   ifdef MACOS
    return [handle isFocused];
#   endif
}
